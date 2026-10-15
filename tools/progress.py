#!/usr/bin/env python3
"""Recovery progress: compile every recovered unit with the game flags, pair its functions with exe VAs, byte-match.

    .venv/bin/python tools/progress.py                 # incremental: only units whose obj/deps changed are re-matched
    .venv/bin/python tools/progress.py --force         # everything
    .venv/bin/python tools/progress.py md5checksum     # only units whose path contains this (others keep cached rows)
    .venv/bin/python tools/progress.py -v uicutscene   # print the bytematch report of every non-matching function

A unit is a src/ms2/**/*.cpp with a header block (docs/RECOVERY.md):
    // MS2-UNIT: client\\ms2\\uicutscenemovie.cpp          original CU (path below ms2code\\)
    // MS2-RANGE: 0x14190eac0-0x141910480 .text$mn         exe address ranges owned by the unit (any number;
    // MS2-RANGE: 0x140111d60-0x140111f00 .text$di         .text$mn, the dynamic initializers, the atexit thunks)
and `// @0x<va>` tags on the line(s) directly above function definitions (in the .cpp or in headers for inline
member functions). Pairing obj symbol -> exe VA:
  1. tag: the function's first line (CodeView line table of the /Z7 obj) has a tag at most 6 lines above it;
  2. auto: a function symbol without tag whose bytes (relocations masked) equal exactly one exe function of the same
     length inside the unit's ranges (COMDATs: STL/ATL instantiations, dynamic initializers, atexit thunks);
  3. vftables ??_7Class@@6B...@ are paired through RTTI (work/classes/rtti_*.tsv) and checked slot by slot.
Every paired function is byte-matched (tools/bytematch.py, incl. unwind/EH data and the symbol map).

Outputs (committed):
  progress/status.tsv    va, name, unit, state, size   for every exe function inside a unit range;
                         state = matched | functional (paired, compiles, not byte-identical) | stub (not recovered)
  progress/symbols.tsv   symbol -> VA map harvested from matched functions/vftables (bytematch --symbols/--harvest,
                         tools/ms2symobj.py for the hook DLL link)
  progress/summary.txt   per unit and overall: functions and bytes matched
Cache: build/progress/ (objs, /showIncludes deps, per-unit results keyed by obj mtime).

Parallel agents (docs/RECOVERY.md section 12): `--agent NAME` or MS2_AGENT=NAME selects a private cache
build/progress-NAME/ and REPORT MODE: progress/* is never written. status.tsv / summary.txt go to the agent dir, and
build/progress-NAME/symbols.tsv = committed progress/symbols.tsv + the harvest of the units in the agent's cache (the
symbol table of the agent's hook build, tools/unit-check.sh). `--report` gives report mode without an agent name
(cache build/progress-report/). Only the merge step (no agent, no --report) writes progress/*.
"""
import argparse
import bisect
import contextlib
import io
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import bytematch as bm  # noqa: E402

SRC = os.path.join(ROOT, "src")
GAME = os.path.join(SRC, "ms2")
OUT = os.path.join(ROOT, "progress")
CACHE = os.path.join(ROOT, "build", "progress")
CL = os.path.join(ROOT, "third_party", "msvc", "bin", "x64", "cl")
FUNCS = os.path.join(ROOT, "work", "map", "functions.tsv")
UNITS = os.path.join(ROOT, "work", "map", "units.tsv")
RTTI_CLASSES = os.path.join(ROOT, "work", "classes", "rtti_classes.tsv")
RTTI_VFTABLES = os.path.join(ROOT, "work", "classes", "rtti_vftables.tsv")

# cmake/ms2-game-flags.cmake (MS2_GAME_COMPILE_OPTIONS + _DEFINITIONS + C++14) + /MD /Z7 + the ms2game include dirs.
GAME_FLAGS = ["/nologo", "/c", "/Od", "/Ob0", "/Oi", "/EHsc", "/GS", "/GR", "/Gy", "/fp:fast", "/Zc:wchar_t",
              "/Zc:threadSafeInit", "/std:c++14", "/MD", "/Z7", "/W3", "/D_MBCS", "/D_AFXDLL",
              "/I" + SRC, "/I" + os.path.join(SRC, "hook")]
FLAGS_KEY = " ".join(GAME_FLAGS) + " v3"
TAG_RE = re.compile(r"//\s*@0x([0-9a-fA-F]+)\b")
TAG_WINDOW = 6


# ----------------------------------------------------------------------------------------------------------------
# units

class Unit:
    def __init__(self, path):
        self.path = path
        self.rel = os.path.relpath(path, GAME).replace("\\", "/")
        self.name = None
        self.ranges = []
        for line in open(path, encoding="latin1"):
            m = re.match(r"\s*//\s*MS2-UNIT:\s*(\S+)", line)
            if m:
                self.name = m.group(1)
            m = re.match(r"\s*//\s*MS2-RANGE:\s*0x([0-9a-fA-F]+)\s*-\s*0x([0-9a-fA-F]+)", line)
            if m:
                self.ranges.append((int(m.group(1), 16), int(m.group(2), 16)))
        self.obj = os.path.join(CACHE, "obj", self.rel[:-4] + ".obj")
        self.deps = self.obj[:-4] + ".deps"

    def in_range(self, va):
        return any(a <= va < b for a, b in self.ranges)


def find_units(filters):
    out = []
    for d, _, files in os.walk(GAME):
        for f in sorted(files):
            if f.endswith(".cpp"):
                u = Unit(os.path.join(d, f))
                if not u.name:
                    continue
                if filters and not any(x in u.rel or x in u.name for x in filters):
                    continue
                out.append(u)
    return sorted(out, key=lambda u: u.rel)


def winpath(p):
    return p


_case = {}


def unixpath(p):
    """Wine cl reports paths as z:\\... and (in CodeView) lowercased: map back to the real file under ROOT."""
    p = p.strip()
    if re.match(r"^[zZ]:", p):
        p = p[2:]
    p = os.path.normpath(p.replace("\\", "/"))
    if os.path.exists(p):
        return p
    if not _case:
        for top in (SRC, os.path.join(ROOT, "engine")):
            for d, _, files in os.walk(top):
                for f in files:
                    q = os.path.join(d, f)
                    _case[q.lower()] = q
    return _case.get(p.lower(), p)


def needs_compile(u):
    if not os.path.exists(u.obj) or not os.path.exists(u.deps):
        return True
    try:
        meta = json.load(open(u.deps))
    except Exception:
        return True
    if meta.get("flags") != FLAGS_KEY:
        return True
    t = os.path.getmtime(u.obj)
    for f in [u.path] + meta.get("deps", []):
        if not os.path.exists(f) or os.path.getmtime(f) > t:
            return True
    return False


def compile_unit(u):
    os.makedirs(os.path.dirname(u.obj), exist_ok=True)
    env = dict(os.environ, WINEPREFIX=os.path.join(ROOT, "work", "wineprefix-msvc"), WINEDEBUG="-all")
    cmd = [CL] + GAME_FLAGS + ["/showIncludes", "/Fo" + u.obj, u.path]
    t0 = time.time()
    r = subprocess.run(cmd, capture_output=True, text=True, env=env, encoding="latin1")
    deps, msgs = [], []
    for line in (r.stdout + r.stderr).splitlines():
        if line.startswith("Note: including file:"):
            f = unixpath(line.split(":", 2)[2])
            if f.startswith(SRC) or f.startswith(os.path.join(ROOT, "engine")):
                deps.append(f)
        elif line.strip() and line.strip() != os.path.basename(u.path) and "_WIN32_WINNT not defined" not in line:
            msgs.append(line)
    ok = r.returncode == 0 and os.path.exists(u.obj)
    if ok:
        json.dump({"flags": FLAGS_KEY, "deps": sorted(set(deps))}, open(u.deps, "w"))
    elif os.path.exists(u.obj):
        os.remove(u.obj)
    return ok, msgs, time.time() - t0


# ----------------------------------------------------------------------------------------------------------------
# CodeView line tables (C13: .debug$S subsections 0xf2 lines, 0xf4 file checksums, 0xf3 strings)

def cv_first_lines(obj):
    """{function symbol name: (source path, first line)}"""
    strings, checks, pending = {}, {}, []
    for sn, s in enumerate(obj.sections, 1):
        if s["name"] != ".debug$S":
            continue
        d = s["data"]
        if len(d) < 4 or struct.unpack_from("<I", d, 0)[0] != 4:
            continue
        rel = {va: si for va, si, ty in s["relocs"]}
        o = 4
        while o + 8 <= len(d):
            typ, ln = struct.unpack_from("<II", d, o)
            body = o + 8
            if typ == 0xF3:
                strings[sn] = d[body:body + ln]
            elif typ == 0xF4:
                checks[sn] = d[body:body + ln]
            elif typ == 0xF2 and ln >= 12:
                si = rel.get(body)
                fb = body + 12
                if si is not None and fb + 12 <= body + ln:
                    fileid, nlines, _ = struct.unpack_from("<III", d, fb)
                    if nlines:
                        off, val = struct.unpack_from("<II", d, fb + 12)
                        pending.append((obj.syms[si][0], fileid, val & 0xFFFFFF))
            o = body + ln
            o = (o + 3) & ~3
    if not checks or not strings:
        return {}
    ck = next(iter(checks.values()))
    st = next(iter(strings.values()))
    out = {}
    for name, fileid, line in pending:
        if fileid + 4 > len(ck):
            continue
        so = struct.unpack_from("<I", ck, fileid)[0]
        e = st.index(b"\0", so)
        out.setdefault(name, (unixpath(st[so:e].decode("latin1")), line))
    return out


_tag_cache = {}


def tags_of(path):
    if path not in _tag_cache:
        tags = {}
        try:
            for i, line in enumerate(open(path, encoding="latin1"), 1):
                m = TAG_RE.search(line)
                if m:
                    tags[i] = int(m.group(1), 16)
        except OSError:
            pass
        _tag_cache[path] = tags
    return _tag_cache[path]


def tag_for(path, line):
    tags = tags_of(path)
    for k in range(line, max(0, line - TAG_WINDOW) - 1, -1):
        if k in tags:
            return tags[k]
    return None


# ----------------------------------------------------------------------------------------------------------------
# exe-side tables

def load_functions():
    starts, info = [], {}
    for line in open(FUNCS):
        p = line.rstrip("\n").split("\t")
        if not p[0] or p[0].startswith("#"):
            continue
        va = int(p[0], 16)
        info[va] = (int(p[1]), p[3] if len(p) > 3 else "")
        starts.append(va)
    starts.sort()
    return starts, info


def load_vftables():
    bases = {}       # class -> {base: mdisp}
    for line in open(RTTI_CLASSES):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 6:
            continue
        bases[p[2]] = {}
        for b in p[5].split(";"):
            q = b.split("|")
            if len(q) >= 2:
                bases[p[2]].setdefault(q[0], int(q[1]))
    vft = {}         # (class, offset) -> va
    for line in open(RTTI_VFTABLES):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 4:
            continue
        vft[(p[2], int(p[3]))] = int(p[0], 16)
    return bases, vft


def vftable_va(sym, bases, vft):
    m = re.match(r"^\?\?_7(.+?)@@6B(.*)@$", sym)
    if not m:
        return None
    cls = m.group(1)
    if "@" in cls:          # nested / namespaced: Ghidra/RTTI names use '::' in reverse order
        cls = "::".join(reversed(cls.split("@")))
    rest = m.group(2)
    if rest == "":
        off = 0
    else:
        base = rest.rstrip("@").split("@")[0]
        off = bases.get(cls, {}).get(base)
        if off is None:
            return None
    return vft.get((cls, off))


# ----------------------------------------------------------------------------------------------------------------

def quiet_match(obj, sym, va, exe, verbose):
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        ok = bm.match_one(obj, sym, va, exe, verbose=verbose, check_unwind=True, quiet=not verbose)
    return ok, buf.getvalue()


def demangle_all(names):
    if not names:
        return {}
    try:
        r = subprocess.run(["llvm-undname"], input="\n".join(names) + "\n", capture_output=True, text=True)
        out = [l for l in r.stdout.splitlines()]
        res, i = {}, 0
        # llvm-undname echoes "<mangled>\n<demangled>\n\n" per input line
        for n in names:
            while i < len(out) and out[i].strip() != n:
                i += 1
            if i + 1 < len(out):
                res[n] = out[i + 1].strip()
            i += 2
        return res
    except Exception:
        return {}


def short_name(dem):
    """'public: void __cdecl A::B(int)' -> 'A::B'"""
    s = re.sub(r"^(public|protected|private): ", "", dem)
    s = re.sub(r"^(static |virtual )", "", s)
    s = re.sub(r"\(.*$", "", s)
    s = s.split(" __cdecl ")[-1].split(" __ptr64")[0]
    return s.strip()


INITS = ("??__E", "??__F")    # dynamic initializers and their atexit thunks
GENERATED = ("??_G", "??_E", "??__E", "??__F", "??__J", "??_H", "??_I", "??_L", "??_M",
             "?__empty_global_delete@")    # the last: compiler-emitted at end of file, carries the last line


def process_unit(u, exe, starts, finfo, bases, vft, verbose):
    obj = bm.Obj(u.obj)
    lines = cv_first_lines(obj)
    syms = [si for si in obj.func_symbols() if not obj.syms[si][0].startswith(bm.FUNCLET_PREFIXES)]
    res = {"pairs": {}, "vft": {}, "notes": [], "harvest": {}}
    known = bm.LOCAL_KNOWN
    known.clear()
    how = {}

    def trial(name, va):
        snap, nconf = dict(bm.HARVEST), len(bm.CONFLICTS)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            ok = bm.match_one(obj, name, va, exe, verbose=False, check_unwind=True, quiet=True)
        bm.HARVEST.clear()
        bm.HARVEST.update(snap)
        del bm.CONFLICTS[nconf:]
        return ok

    def refs(name, va):
        """{obj symbol: exe va} referenced by `name` paired with `va` (empty unless it matches)."""
        snap, nconf = dict(bm.HARVEST), len(bm.CONFLICTS)
        with contextlib.redirect_stdout(io.StringIO()):
            bm.match_one(obj, name, va, exe, verbose=False, check_unwind=False, quiet=True)
        out = dict(bm.LAST_TARGETS)
        bm.HARVEST.clear()
        bm.HARVEST.update(snap)
        del bm.CONFLICTS[nconf:]
        return out

    # 1. tags (authoritative). Compiler-generated functions (??_G, ??__E ...) inherit the line of the declaration they
    # belong to, so a tag claimed by several symbols goes to the non-generated one, else to the one that matches.
    by_tag = {}
    for si in syms:
        name = obj.syms[si][0]
        fl = lines.get(name)
        va = tag_for(*fl) if fl else None
        if va is not None:
            by_tag.setdefault(va, []).append(name)
    for va, names in sorted(by_tag.items()):
        if len(names) > 1:
            names = [n for n in names if not n.startswith(GENERATED)] or names
        if len(names) > 1:      # MS2_REPLACE* thunks sit right after short functions, inside their tag window
            names = [n for n in names if "@ms2_thunk_" not in n] or names
        if len(names) > 1:
            names = [n for n in names if trial(n, va)] or names
        if len(names) != 1:
            res["notes"].append(f"tag 0x{va:x} claimed by {len(names)} functions: " + ", ".join(names[:4]))
            continue
        known[names[0]] = va
        how[names[0]] = "tag"
    # 2. auto: untagged functions (COMDATs, initializers) whose masked bytes equal exe functions in the unit ranges.
    used = set(known.values())
    cands = {}
    for lo, hi in u.ranges:
        i = bisect.bisect_left(starts, lo)
        while i < len(starts) and starts[i] < hi:
            va = starts[i]
            rva = va - exe.base
            size = exe.rf[rva][0] - rva if rva in exe.rf else finfo[va][0]
            cands.setdefault(size, []).append(va)
            i += 1
    hits = {}
    for si in syms:
        name = obj.syms[si][0]
        if name in known:
            continue
        data, fields, _ = obj.function(si)
        mask = bytearray(len(data))
        for off, ln, *_ in fields:
            mask[off:off + ln] = b"\1" * len(mask[off:off + ln])
        keep = [k for k in range(len(data)) if not mask[k]]
        want = bytes(data[k] for k in keep)
        h = [va for va in cands.get(len(data), []) if va not in used and
             bytes(exe.img[va - exe.base + k] for k in keep) == want]
        if h:
            hits[name] = h
    # resolve: a candidate must be consistent with the pairs known so far (call targets, unwind, EH); iterate
    # because each accepted pair constrains the others. Several obj functions can fit one exe function (tiny
    # look-alikes: a 24-byte dtor vs. _Allocate, an initializer of the unit's static vs. of a selectany ATL global):
    # prefer the unit's own code (score), then the COMDAT tail order (the linker emits the selectany functions an obj
    # contributes sorted by mangled name, after its own functions).
    si_of = {obj.syms[si][0]: si for si in syms}

    def score(name):
        si = si_of[name]
        if obj.own(si):
            return 2
        _, fields, _ = obj.function(si)
        for f in fields:
            t = f[5]
            tn, tv, tsec, _, tcl = obj.syms[t]
            if tsec > 0 and not obj.is_code(t) and not tn.startswith(("$", "??_C@", "__real@", "__xmm@", "??_R")) \
                    and (obj.own(t) or tcl == 3 and not obj.sec(tsec)["chars"] & 0x1000):
                return 1
        return 0

    def range_of(va):
        return next((r for r in u.ranges if r[0] <= va < r[1]), None)

    def order_ok(name, va):
        if obj.own(si_of[name]) or name.startswith(INITS):
            return True
        r = range_of(va)
        lo = hi = None
        for n2, v2 in known.items():
            if n2 == name or n2 not in si_of or obj.own(si_of[n2]):
                continue
            if range_of(v2) != r:
                continue
            if v2 < va and (lo is None or v2 > lo[1]):
                lo = (n2, v2)
            if v2 > va and (hi is None or v2 < hi[1]):
                hi = (n2, v2)
        return (lo is None or lo[0] < name) and (hi is None or name < hi[0])

    def order_key(name):
        # initializers/atexit thunks (static symbols, COMDATs under /Gy) follow definition order = obj section order;
        # selectany COMDATs are emitted sorted by mangled name
        return (1, si_of[name], "") if name.startswith(INITS) else (0, 0, name)

    # references from tagged functions decide look-alikes as well (a function-local static's atexit thunk is named
    # only by the `lea rcx, ??__F...` inside the function that owns the static)
    # (to a fixpoint: a function decided by reference names its own callees in turn, e.g. an STL operator-> and the
    # 11-byte _Const_cast it calls)
    expanded = set()
    while True:
        todo = [(n, v) for n, v in sorted(known.items(), key=lambda kv: kv[1]) if n not in expanded]
        if not todo:
            break
        for name, va in todo:
            expanded.add(name)
            for n2, v2 in refs(name, va).items():
                if n2 in hits and n2 not in known and v2 not in used and v2 in hits[n2] and trial(n2, v2):
                    known[n2] = v2
                    how[n2] = "auto-ref"
                    used.add(v2)
    hits = {n: h for n, h in hits.items() if n not in known}

    ok_hits = {}
    while hits:
        good = {}
        for name in sorted(hits):
            g = [va for va in hits[name] if va not in used and order_ok(name, va) and trial(name, va)]
            if g:
                good[name] = g
        claims = {}
        for name, g in good.items():
            for va in g:
                claims.setdefault(va, []).append(name)
        accepted = []
        for name, g in good.items():
            if len(g) != 1:
                continue
            cl = claims[g[0]]
            if len(cl) > 1:
                top = max(score(n) for n in cl)
                cl = [n for n in cl if score(n) == top]
            if cl == [name]:
                accepted.append((name, g[0]))
        ok_hits = good
        if not accepted:
            break
        for name, va in accepted:
            if va in used:
                continue
            known[name] = va
            how[name] = "auto"
            used.add(va)
        # references from accepted functions to look-alike candidates decide those (an initializer's
        # `lea rcx, ??__F<static>` names its atexit thunk; a ctor names its vftable's functions)
        for name, va in accepted:
            for n2, v2 in refs(name, va).items():
                if n2 in hits and n2 not in known and v2 not in used and v2 in hits[n2] and trial(n2, v2):
                    known[n2] = v2
                    how[n2] = "auto-ref"
                    used.add(v2)
        hits = {n: h for n, h in hits.items() if n not in known and n in good}
    # identical functions left over (same bytes, unknown callees): COMDAT tail order = sorted by mangled name
    groups = {}
    for name in hits:
        groups.setdefault(tuple(va for va in ok_hits.get(name, []) if va not in used), []).append(name)
    for vas, names in groups.items():
        if vas and len(vas) == len(names):
            for name, va in zip(sorted(names, key=order_key), sorted(vas)):
                known[name] = va
                how[name] = "auto-order"
                used.add(va)
        elif vas:
            res["notes"].append(f"ambiguous: {len(names)} look-alike functions for {len(vas)} exe candidates: "
                                + ", ".join(names[:3]))
    # 3. match everything paired (harvests the symbol map)
    funclets = {}
    for name, va in sorted(known.items(), key=lambda kv: kv[1]):
        bm.FUNCLET_PAIRS.clear()
        ok, text = quiet_match(obj, name, va, exe, verbose)
        res["pairs"][name] = {"va": va, "how": how[name], "ok": ok, "report": "" if ok else text}
        if ok:
            funclets.update(bm.FUNCLET_PAIRS)
    # unwind funclets of matched functions (?dtor$N@...: not in the unit ranges, not counted) are matched only to
    # harvest their callees: a destructor reached only on the exception path is otherwise missing from the symbol map
    for name, va in sorted(funclets.items(), key=lambda kv: kv[1]):
        ok, _ = quiet_match(obj, name, va, exe, False)
        if not ok:
            res["notes"].append(f"funclet {name} @0x{va:x} does not match")
    # 4. vftables (paired via RTTI, every slot checked against the pairs and the symbol map)
    for si, (name, value, secnum, typ, sclass) in obj.syms.items():
        if secnum > 0 and name.startswith("??_7") and sclass == 2:
            va = vftable_va(name, bases, vft)
            if va is None:
                res["notes"].append(f"{name}: no exe vftable found via RTTI")
                continue
            ok, text = quiet_match(obj, name, va, exe, verbose)
            res["vft"][name] = {"va": va, "ok": ok, "report": "" if ok else text}
    res["harvest"] = dict(bm.HARVEST)
    known.clear()
    return res


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("filters", nargs="*", help="only units whose path/name contains one of these")
    ap.add_argument("--force", action="store_true", help="recompile and re-match everything")
    ap.add_argument("-j", type=int, default=4, help="parallel compiles (default 4)")
    ap.add_argument("-v", "--verbose", action="store_true", help="print bytematch reports of non-matching functions")
    ap.add_argument("--agent", default=os.environ.get("MS2_AGENT") or None,
                    help="private cache build/progress-AGENT/, report mode (default: $MS2_AGENT)")
    ap.add_argument("--report", action="store_true", help="report mode: never write progress/* (implied by --agent)")
    ap.add_argument("--check", action="store_true",
                    help="exit 1 unless every selected unit compiles and is 100%% matched with all vftables OK")
    a = ap.parse_args()

    global CACHE, OUT
    if a.agent and not re.fullmatch(r"[A-Za-z0-9_.-]+", a.agent):
        sys.exit(f"bad agent name {a.agent!r}")
    if a.agent or a.report:
        CACHE = os.path.join(ROOT, "build", "progress-" + (a.agent or "report"))
        OUT = CACHE
    symbols_out = os.path.join(OUT, "symbols.tsv")

    t0 = time.time()
    os.makedirs(CACHE, exist_ok=True)
    os.makedirs(OUT, exist_ok=True)
    all_units = find_units([])
    units = [u for u in all_units if not a.filters or any(x in u.rel or x in u.name for x in a.filters)]
    cache_path = os.path.join(CACHE, "results.json")
    cache = json.load(open(cache_path)) if os.path.exists(cache_path) else {}

    # compile
    todo = [u for u in units if a.force or needs_compile(u)]
    failed = set()
    if todo:
        print(f"compiling {len(todo)} unit(s) with cl 19.16 ...", flush=True)
        with ThreadPoolExecutor(max_workers=max(1, a.j)) as ex:
            for u, (ok, msgs, dt) in zip(todo, ex.map(compile_unit, todo)):
                print(f"  {'ok  ' if ok else 'FAIL'} {u.rel} ({dt:.1f}s)")
                for m in msgs:
                    print("      " + m)
                if not ok:
                    failed.add(u.rel)

    exe = bm.Exe(bm.EXE)
    starts, finfo = load_functions()
    bases, vft = load_vftables()
    bm.load_symbols(bm.SYMBOLS_TSV)

    for u in units:
        if u.rel in failed or not os.path.exists(u.obj):
            cache[u.rel] = {"key": None, "failed": True, "res": None}
            continue
        key = [os.path.getmtime(u.obj), os.path.getsize(u.obj), u.ranges]
        c = cache.get(u.rel)
        if not a.force and c and c.get("key") == json.loads(json.dumps(key)) and not a.verbose:
            continue
        bm.HARVEST.clear()
        print(f"matching {u.rel} ...", flush=True)
        res = process_unit(u, exe, starts, finfo, bases, vft, a.verbose)
        cache[u.rel] = {"key": key, "failed": False, "res": res}
        if a.verbose:
            for n, p in res["pairs"].items():
                if not p["ok"]:
                    print(p["report"])
            for n, p in res["vft"].items():
                if not p["ok"]:
                    print(p["report"])
    # drop cache entries of units that no longer exist
    live = {u.rel for u in all_units}
    cache = {k: v for k, v in cache.items() if k in live}
    json.dump(cache, open(cache_path, "w"))

    # symbols: union of all units' harvests (existing file entries win; conflicts reported)
    bm.HARVEST.clear()
    for rel, c in sorted(cache.items()):
        if c.get("res"):
            for n, va in c["res"]["harvest"].items():
                prev = bm.HARVEST.get(n)
                if prev is not None and prev != va:
                    bm.CONFLICTS.append((n, prev, va))
                bm.HARVEST[n] = va
    if symbols_out != bm.SYMBOLS_TSV:
        # report mode: the committed table plus this cache's harvest (rebuilt every run, nothing stale survives)
        os.makedirs(OUT, exist_ok=True)
        shutil.copyfile(bm.SYMBOLS_TSV, symbols_out + ".tmp")
        os.replace(symbols_out + ".tmp", symbols_out)
    added = bm.write_harvest(symbols_out, exe)

    # status rows
    unit_by_rel = {u.rel: u for u in all_units}
    rows = []
    summary = []
    tot = dict(n=0, m=0, f=0, b=0, bm=0)
    names_to_demangle = []
    for rel, c in cache.items():
        if c.get("res"):
            names_to_demangle += list(c["res"]["pairs"].keys())
    dem = demangle_all(sorted(set(names_to_demangle)))
    for rel in sorted(cache):
        u = unit_by_rel[rel]
        c = cache[rel]
        byva = {}
        if c.get("res"):
            for n, p in c["res"]["pairs"].items():
                byva[p["va"]] = (n, p["ok"])
        n = m = f = b = bmt = 0
        for lo, hi in u.ranges:
            i = bisect.bisect_left(starts, lo)
            while i < len(starts) and starts[i] < hi:
                va = starts[i]
                size, gname = finfo[va]
                if va in byva:
                    sym, ok = byva[va]
                    state = "matched" if ok else "functional"
                    nm = short_name(dem.get(sym, sym))
                else:
                    state, nm = "stub", gname
                rows.append((va, nm, u.name, state, size))
                n += 1
                b += size
                if state == "matched":
                    m += 1
                    bmt += size
                elif state == "functional":
                    f += 1
                i += 1
        vt = c["res"]["vft"] if c.get("res") else {}
        vok = sum(1 for v in vt.values() if v["ok"])
        summary.append((u.name, n, m, f, b, bmt, len(vt), vok, c.get("failed")))
        for k, v in zip("nmfb", (n, m, f, b)):
            tot[k] += v
        tot["bm"] += bmt
    rows.sort()
    with open(os.path.join(OUT, "status.tsv"), "w") as fo:
        fo.write("#va\tname\tunit\tstate\tsize\n")
        for va, nm, un, st, sz in rows:
            fo.write(f"{va:x}\t{nm}\t{un}\t{st}\t{sz}\n")

    # overall game-code denominator: functions inside work/map/units.tsv ranges
    game_n = game_b = 0
    for line in open(UNITS):
        p = line.rstrip("\n").split("\t")
        if p[0].startswith("#") or len(p) < 6:
            continue
        lo, hi = int(p[0], 16), int(p[1], 16)
        i = bisect.bisect_left(starts, lo)
        while i < len(starts) and starts[i] < hi:
            game_n += 1
            game_b += finfo[starts[i]][0]
            i += 1
    out = []
    out.append(f"# tools/progress.py  {time.strftime('%Y-%m-%d %H:%M')}")
    out.append(f"{'unit':<45} {'funcs':>6} {'match':>6} {'func.':>6} {'stub':>5} {'bytes':>8} {'matched':>8}  vftables")
    for name, n, m, f, b, bmt, nv, vok, fail in summary:
        pct = 100.0 * bmt / b if b else 0
        out.append(f"{name:<45} {n:6} {m:6} {f:6} {n - m - f:5} {b:8} {bmt:8} {pct:5.1f}%  {vok}/{nv}"
                   + ("  COMPILE FAILED" if fail else ""))
    out.append(f"{'total (' + str(len(summary)) + ' units)':<45} {tot['n']:6} {tot['m']:6} {tot['f']:6} "
               f"{tot['n'] - tot['m'] - tot['f']:5} {tot['b']:8} {tot['bm']:8}")
    out.append(f"game code (work/map/units.tsv): {game_n} functions, {game_b} bytes; matched "
               f"{tot['m']} ({100.0 * tot['m'] / game_n:.3f}%) functions, {100.0 * tot['bm'] / game_b:.3f}% of bytes")
    text = "\n".join(out) + "\n"
    open(os.path.join(OUT, "summary.txt"), "w").write(text)
    print(text, end="")
    for rel in sorted(cache):
        r = cache[rel].get("res")
        if r:
            for nline in r["notes"]:
                print(f"note {rel}: {nline}")
    for n, x, y in bm.CONFLICTS:
        print(f"CONFLICT symbol {n}: 0x{x:x} vs 0x{y:x}")
    bad = []
    if a.check:
        sel = {u.name for u in units}
        for name, n, m, f, b, bmt, nv, vok, fail in summary:
            if name in sel and (fail or n == 0 or m != n or vok != nv):
                bad.append(f"{name}: " + ("COMPILE FAILED" if fail else
                                          f"{m}/{n} functions matched ({f} functional, {n - m - f} stub), "
                                          f"vftables {vok}/{nv}"))
        if not units:
            bad.append("no unit matches " + " ".join(a.filters))
    where = os.path.relpath(OUT, ROOT)
    print(f"{where}/symbols.tsv: {added} new; {where}/status.tsv, summary.txt written; {time.time() - t0:.1f}s")
    if a.check:
        for line in bad:
            print("CHECK FAILED " + line)
        if bad or bm.CONFLICTS:
            sys.exit(1)
        print("CHECK OK: " + ", ".join(u.name for u in units))


if __name__ == "__main__":
    main()
