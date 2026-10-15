#!/usr/bin/env python3
"""tplpin: pair template-heavy COMDATs (std::_Tree/map/vector, CAtl*, tuple/pair helpers, ??_G ...) with exe functions.

    .venv/bin/python tools/tplpin.py <unit-substr> [--global] [--apply] [--hints] [--ignore-pins] [-v]

What it does (docs/RECOVERY.md section 6, "Template-heavy units"):
  1. compiles/loads the unit's obj (build/progress-$MS2_AGENT/, else build/progress-tplpin/) and runs progress.py's own
     pairing. Everything paired by tag, pin, auto or auto-ref is an ANCHOR; auto-order guesses are re-solved.
  2. for every other obj function (unpaired or ambiguous): candidates = exe functions in the unit's MS2-RANGEs
     (with --global: the whole exe, for COMDATs shared with other units) that are byte-identical modulo relocations
     and have an equal UNWIND_INFO/FuncInfo.
  3. constraint propagation over the call graph: a rel32 field of the obj function to another obj function must hit
     the exe candidate of that function (and vice versa); anchors, exe-side vftable slots (obj vftables paired by RTTI),
     symbols.tsv and the pairs found so far all constrain callees. One exe function = one name.
  4. mangled-name order: the linker lays a unit's COMDAT tail out sorted by mangled name (initializers/atexit thunks
     by obj symbol order). Used as a constraint only when the anchored COMDATs of the unit are consistent with it
     (reported as `order check`); otherwise it is ignored.
  5. prints proposed `// MS2-PIN: <mangled> 0x<va> ; <confidence>: <reason>` lines. Confidence:
        unique   one byte-identical candidate (or one left after anchors/vftable/symbols.tsv constraints)
        prop     reduced to one by call-graph propagation (not needing name order)
        order    needs the mangled-name order constraint
        probe    only one candidate survives a trial assignment of the others (singleton arc consistency)
        guess    identical look-alike group resolved by name order alone, order check not clean (not applied)
     Names left with several candidates are listed with their candidates. Names with no candidate are reported
     as `elsewhere` (an identical exe copy exists outside the unit's ranges: shared COMDAT of another unit) or
     `none`, and for `none` with --hints the closest exe function (the caller-implied partner when an anchored
     caller names it) is diffed instruction by instruction: it shows which constant or callee differs, which usually
     means a wrong key/value/template argument type in the unit source.
  6. --apply writes the pins (confidence unique/prop/order/probe) into the unit source between
        // MS2-PINS-BEGIN tplpin ... // MS2-PINS-END tplpin
     (inserted after the last MS2-RANGE line if absent) and touches nothing else. Refuses a unit file with
     uncommitted changes unless --allow-dirty (other agents' files).

Pins in the block are ignored as anchors when solving (the block is regenerated); pins elsewhere in the file stay anchors.
"""
import argparse
import bisect
import collections
import contextlib
import io
import os
import re
import struct
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import bytematch as bm  # noqa: E402
import progress as P  # noqa: E402

BEGIN = "// MS2-PINS-BEGIN tplpin"
END = "// MS2-PINS-END tplpin"
RANK = {"unique": 0, "prop": 1, "order": 2, "probe": 3, "guess": 4}
HOOK_RE = re.compile(r"ms2_thunk|ms2_registered|ms2_replacement|MemberToVoid|FnToVoid|hook@ms2|^__(catch|dtor|filt|fin)\$")
APPLY_OK = ("unique", "prop", "order", "probe")


class Contradiction(Exception):
    pass


# ----------------------------------------------------------------------------------------------------------------
# unit loading

def load_unit(filt, cache_dir, compile_ok, force_obj=None):
    P.CACHE = cache_dir
    us = [u for u in P.find_units([filt]) if filt in u.rel or filt in u.name]
    exact = [u for u in us if os.path.splitext(os.path.basename(u.rel))[0] == filt or u.rel == filt or u.name == filt]
    if exact:
        us = exact
    return us


def block_pins(text):
    """(set of pin names inside the tplpin block, (start line, end line) or None)"""
    lines = text.split("\n")
    b = e = None
    for i, l in enumerate(lines):
        if l.strip() == BEGIN:
            b = i
        elif l.strip() == END and b is not None:
            e = i
            break
    if b is None or e is None:
        return set(), None
    names = set()
    for l in lines[b + 1:e]:
        m = re.match(r"\s*//\s*MS2-PIN:\s*(\S+)\s+0x([0-9a-fA-F]+)", l)
        if m:
            names.add(m.group(1))
    return names, (b, e)


# ----------------------------------------------------------------------------------------------------------------

class Ctx:
    def __init__(self, args):
        self.a = args
        self.exe = bm.Exe(bm.EXE)
        self.starts, self.finfo = P.load_functions()
        self.bases, self.vft = P.load_vftables()
        bm.load_symbols(bm.SYMBOLS_TSV)
        self._size = {}
        self._by_size = None
        self.owner = None

    def fsize(self, va):
        s = self._size.get(va)
        if s is None:
            rva = va - self.exe.base
            s = self.exe.rf[rva][0] - rva if rva in self.exe.rf else self.finfo[va][0]
            self._size[va] = s
        return s

    def by_size(self):
        if self._by_size is None:
            d = collections.defaultdict(list)
            for va in self.starts:
                d[self.fsize(va)].append(va)
            self._by_size = d
        return self._by_size

    def owner_of(self, va):
        """unit name owning an exe VA (work/map/units.tsv)"""
        if self.owner is None:
            rows = []
            for l in open(P.UNITS):
                if l.startswith("#"):
                    continue
                p = l.rstrip("\n").split("\t")
                rows.append((int(p[0], 16), int(p[1], 16), p[2]))
            rows.sort()
            self.owner = ([r[0] for r in rows], rows)
        i = bisect.bisect_right(self.owner[0], va) - 1
        if i >= 0 and self.owner[1][i][0] <= va < self.owner[1][i][1]:
            return self.owner[1][i][2]
        return "?"


class Fn:
    """obj function, with everything needed to compare it against exe functions"""
    __slots__ = ("name", "si", "data", "fields", "unw", "size", "mask", "want", "refs", "own", "value", "secnum", "init")

    def __init__(self, obj, si):
        self.si = si
        self.name, self.value, self.secnum = obj.syms[si][0], obj.syms[si][1], obj.syms[si][2]
        self.data, self.fields, self.unw = obj.function(si)
        self.size = len(self.data)
        m = bytearray(b"\xff" * self.size)
        self.refs = []
        for off, ln, tname, ty, inner, tsi in self.fields:
            for k in range(off, min(off + ln, self.size)):
                m[k] = 0
            if ln == 4 and bm.REL_REL32 <= ty <= bm.REL_REL32 + 5 and inner is None and off + 4 <= self.size:
                add = struct.unpack_from("<i", self.data, off)[0]
                self.refs.append((off, ty - bm.REL_REL32, tname, add))
        self.mask = int.from_bytes(bytes(m), "little")
        self.want = int.from_bytes(self.data, "little") & self.mask
        self.own = obj.own(si)
        self.init = self.name.startswith(P.INITS)


class UnitState:
    def __init__(self, ctx, u, res, obj, args):
        self.c, self.u, self.res, self.obj, self.a = ctx, u, res, obj, args
        exe = ctx.exe
        self.fn = {}
        for si in obj.func_symbols():
            n = obj.syms[si][0]
            if n.startswith(bm.FUNCLET_PREFIXES) or HOOK_RE.search(n):
                continue        # unwind funclets; MS2_REPLACE hook thunks (not game code)
            self.fn[n] = Fn(obj, si)
        pairs = res["pairs"]
        # anchors: tag/pin/auto/auto-ref (ok pairs, and tagged/pinned ones even when not ok); auto-order is re-solved
        self.AN = {}
        for n, p in pairs.items():
            if n not in self.fn:
                continue
            if p["how"] in ("tag", "pin") or (p["ok"] and p["how"] in ("auto", "auto-ref")):
                self.AN[n] = p["va"]
        self.prior = {n: p["va"] for n, p in pairs.items() if p["how"] == "auto-order"}
        for spec in args.anchor:
            sub, va = spec.rsplit("=", 1)
            hits = [n for n in self.fn if sub in n]
            if len(hits) != 1:
                sys.exit(f"--anchor {sub}: {len(hits)} symbols match")
            self.AN[hits[0]] = int(va, 16)
        self.anvas = set(self.AN.values())
        # known symbol -> VA for non-variable references
        self.EK = dict(bm.SYMBOLS)
        # NOT res["harvest"]: it includes callees of progress's own name-order (auto-order) guesses, which would feed back as facts
        for n, v in res["vft"].items():
            if v["va"] is not None:
                self.EK[n] = v["va"]
        self.EK.update(self.AN)
        self.ranges = u.ranges
        self.rng_of = lambda va: next((i for i, (a, b) in enumerate(self.ranges) if a <= va < b), -1)
        self.scope_lo = 0
        self.unwind_cache = {}

    # ---- candidates
    def unwind_ok(self, f, va):
        key = (f.name, va)
        r = self.unwind_cache.get(key)
        if r is None:
            rep = bm.Report()
            try:
                with contextlib.redirect_stdout(io.StringIO()):
                    bm.compare_unwind(self.obj, f.unw, self.c.exe, va, f.value, f.secnum, rep, False)
                r = rep.ok
            except Exception:
                r = False
            self.unwind_cache[key] = r
        return r

    def exe_int(self, va, size):
        o = va - self.c.exe.base
        return int.from_bytes(self.c.exe.img[o:o + size], "little")

    def cand_pool(self, global_scope):
        if global_scope:
            return self.c.by_size()
        pool = collections.defaultdict(list)
        for lo, hi in self.ranges:
            i = bisect.bisect_left(self.c.starts, lo)
            while i < len(self.c.starts) and self.c.starts[i] < hi:
                va = self.c.starts[i]
                pool[self.c.fsize(va)].append(va)
                i += 1
        return pool

    def candidates(self, f, pool):
        out = []
        for va in pool.get(f.size, ()):
            if va in self.anvas:
                continue
            if self.exe_int(va, f.size) & f.mask != f.want:
                continue
            if not self.unwind_ok(f, va):
                continue
            out.append(va)
        return out

    def targets(self, f, va):
        """[(tname, exe target va)] of the rel32 fields of f placed at exe va"""
        img, base = self.c.exe.img, self.c.exe.base
        out = []
        for off, k, tname, add in f.refs:
            o = va - base + off
            disp = struct.unpack_from("<i", img, o)[0]
            out.append((tname, va + off + 4 + k + disp - add))
        return out


# ----------------------------------------------------------------------------------------------------------------
# solver

class Solver:
    def __init__(self, st, V, D0, why0, global_scope, use_symtab=True):
        self.st = st
        self.V = V
        self.D0 = D0
        self.use_symtab = use_symtab
        self.global_scope = global_scope
        self.tgc = {}
        self.callers = collections.defaultdict(set)
        self.callees = collections.defaultdict(set)
        for n in V:
            for off, k, tn, add in st.fn[n].refs:
                if tn in V and tn != n:
                    self.callers[tn].add(n)
                    self.callees[n].add(tn)
        self.why0 = why0
        self.universe = None

    def tg(self, n, a):
        k = (n, a)
        r = self.tgc.get(k)
        if r is None:
            r = self.tgc[k] = self.st.targets(self.st.fn[n], a)
        return r

    # name order -------------------------------------------------------------------------------------------------
    # Look-alike groups (obj functions with identical masked bytes) are laid out in mangled-name order, per range,
    # for pairs whose first differing character comes before any invented (stand-in) name part.
    def order_pairs(self):
        st = self.st
        if getattr(self, "_op", None) is not None:
            return self._op
        grp = collections.defaultdict(list)
        for n, f in st.fn.items():
            if not f.own and not f.init:
                grp[(f.size, f.want, f.mask)].append(n)
        before = collections.defaultdict(set)      # n -> names that must precede n
        for names in grp.values():
            if len(names) < 2:
                continue
            for x in names:
                for y in names:
                    if x < y and name_order_decided(x, y):
                        before[y].add(x)
        self._op = before
        return before

    def run(self, order, sac, budget, label=""):
        st = self.st
        V = self.V
        t0 = time.time()
        D = {n: list(d) for n, d in self.D0.items()}
        why = dict(self.why0)
        relaxed = set()
        before = self.order_pairs() if order else {}
        vaidx = collections.defaultdict(set)
        for n, d in D.items():
            for a in d:
                vaidx[a].add(n)
        state = dict(D=D, why=why, relaxed=relaxed, vaidx=vaidx)

        def setdom(S, n, nd, cause):
            d = S["D"][n]
            if len(nd) == len(d):
                return False
            for a in d:
                if a not in nd:
                    S["vaidx"][a].discard(n)
            S["D"][n] = nd
            S["why"][n] = cause
            return True

        def ok(S, n, a):
            for tn, tva in self.tg(n, a):
                if tn in S["D"] and tn not in S["relaxed"] and tn != n:
                    dd = S["D"][tn]
                    if tva not in dd and (self.global_scope or tva in self.inrange_starts):
                        if self.D0[tn]:
                            if tva in self.starts_set:
                                return False, "callee " + short(tn)
                elif tn in st.EK and self.use_symtab and tn not in S["D"]:
                    if st.EK[tn] != tva:
                        return False, "symbol " + short(tn)
            return True, ""

        def revise(S, n, strict, queue):
            d = S["D"][n]
            if n in S["relaxed"]:
                nd = d
            else:
                nd, cause = [], ""
                for a in d:
                    o, c = ok(S, n, a)
                    if o:
                        nd.append(a)
                    else:
                        cause = c
                if not nd:
                    if strict:
                        raise Contradiction(n)
                    S["relaxed"].add(n)
                    nd = d
                    cause = ""
                elif len(nd) != len(d):
                    setdom(S, n, nd, cause)
                    queue.update(self.callers[n] | self.callees[n] | {n})
            d = S["D"][n]
            # restrict callees to the targets of our candidates
            if n not in S["relaxed"]:
                for off, k, tn, add in st.fn[n].refs:
                    if tn in S["D"] and tn != n and tn not in S["relaxed"]:
                        T = set()
                        for a in d:
                            for tn2, tva in self.tg(n, a):
                                if tn2 == tn:
                                    T.add(tva)
                        if all((tva in self.starts_set and (self.global_scope or tva in self.inrange_starts)) for tva in T):
                            nd = [x for x in S["D"][tn] if x in T]
                            if nd and len(nd) != len(S["D"][tn]):
                                setdom(S, tn, nd, "caller " + short(n))
                                queue.update(self.callers[tn] | self.callees[tn] | {tn})
                            elif not nd and strict and S["D"][tn]:
                                raise Contradiction(tn)
            if len(d) == 1:
                a = d[0]
                for m in list(S["vaidx"][a]):
                    if m != n and len(S["D"][m]) > 1:
                        nd = [x for x in S["D"][m] if x != a]
                        setdom(S, m, nd, f"0x{a:x} taken by {short(n)}")
                        queue.update(self.callers[m] | self.callees[m] | {m})
                    elif m != n and len(S["D"][m]) == 1 and strict and m not in S["relaxed"] and n not in S["relaxed"]:
                        raise Contradiction(m)

        def dom(S, n):
            return S["D"][n] if n in S["D"] else [st.AN[n]]

        def order_pass(S, strict):
            changed = set()
            cache = {}

            def info(x):
                r = cache.get(x)
                if r is None:
                    dx = dom(S, x)
                    rs = set(st.rng_of(v) for v in dx)
                    r = (rs.pop() if len(rs) == 1 else -2, min(dx), max(dx))
                    cache[x] = r
                return r

            for y, xs in before.items():
                if y not in S["D"] or y in S["relaxed"]:
                    continue
                dy = S["D"][y]
                xl = [info(x) for x in xs if x in S["D"] or x in st.AN]
                zl = [info(z) for z in later.get(y, ()) if z in S["D"] or z in st.AN]
                if not xl and not zl:
                    continue
                keep = []
                for a in dy:
                    r = st.rng_of(a)
                    good = True
                    if r >= 0:
                        for (xr, xmin, xmax) in xl:
                            if xr == r and xmin >= a:
                                good = False
                                break
                        if good:
                            for (zr, zmin, zmax) in zl:
                                if zr == r and zmax <= a:
                                    good = False
                                    break
                    if good:
                        keep.append(a)
                if keep and len(keep) != len(dy):
                    if setdom(S, y, keep, "name order"):
                        changed.add(y)
                        cache.clear()
            return changed

        later = collections.defaultdict(set)
        for y, xs in before.items():
            for x in xs:
                later[x].add(y)

        def fix(S, strict, seeds=None):
            queue = set(seeds if seeds is not None else V)
            while True:
                while queue:
                    n = queue.pop()
                    revise(S, n, strict, queue)
                if order:
                    ch = order_pass(S, strict)
                    if ch:
                        for y in ch:
                            queue.update(self.callers[y] | self.callees[y] | {y})
                        continue
                break

        if self.universe is None:
            self.starts_set = set(st.c.starts)
            self.inrange_starts = set(v for v in st.c.starts if st.rng_of(v) >= 0)
        # symbols.tsv knows the variable itself
        if self.use_symtab:
            for n in V:
                va = bm.SYMBOLS.get(n)
                if va is not None and va in D[n] and len(D[n]) > 1:
                    setdom(state, n, [va], "symbols.tsv")
        fix(state, False)
        # singleton arc consistency
        if sac:
            changed = True
            while changed and time.time() - t0 < budget:
                changed = False
                amb = sorted((n for n in V if len(state["D"][n]) > 1), key=lambda n: (len(state["D"][n]), n))
                for n in amb:
                    if time.time() - t0 > budget:
                        break
                    if len(state["D"][n]) < 2:
                        continue
                    keep = []
                    for a in list(state["D"][n]):
                        S2 = dict(D={k: list(v) for k, v in state["D"].items()}, why=dict(state["why"]),
                                  relaxed=set(state["relaxed"]),
                                  vaidx=collections.defaultdict(set, {k: set(v) for k, v in state["vaidx"].items()}))
                        setdom(S2, n, [a], "")
                        try:
                            fix(S2, True, seeds={n} | self.callers[n] | self.callees[n])
                            keep.append(a)
                        except Contradiction:
                            pass
                    if len(keep) < len(state["D"][n]) and keep:
                        setdom(state, n, keep, "probe")
                        if len(keep) == 1:
                            state["why"][n] = "probe"
                        fix(state, False, seeds={n} | self.callers[n] | self.callees[n])
                        changed = True
        return state


def short(n):
    return n if len(n) < 70 else n[:66] + "..."


# ----------------------------------------------------------------------------------------------------------------

def sidx(n):
    """index from which the characters of a mangled name are (partly) invented by us (Unk_ stand-ins, FUN_/vfunc_ names)"""
    if re.match(r'^\?(FUN_|vfunc_|Unk_|sub_)', n):
        return 1
    if re.match(r'^\?\??\$?[^@]*@\??\$?Unk_', n) or re.match(r'^\?\?_?[A-Z0-9]\??\$?Unk_', n):
        return 1
    i = n.find("Unk_")
    if i < 0:
        return 1 << 30
    # the struct/class/union/enum keyword in front of an invented type name is invented too (U/V/T vs W4)
    if n[max(0, i - 2):i] == "W4":
        return i - 2
    if i > 0 and n[i - 1] in "UVT":
        return i - 1
    if n[max(0, i - 3):i] == "V?$":
        return i - 3
    return i


def name_order_decided(a, b):
    """True when a < b is decided by characters that are real (before any invented name part)"""
    i, n = 0, min(len(a), len(b))
    while i < n and a[i] == b[i]:
        i += 1
    return i < n and i < min(sidx(a), sidx(b))


def order_check(st):
    """evidence for the look-alike name order: decided pairs of byte-identical anchored COMDATs in the same range"""
    grp = collections.defaultdict(list)
    for n, va in st.AN.items():
        f = st.fn.get(n)
        if f is not None and not f.own and not f.init:
            grp[(f.size, f.want, f.mask)].append((n, va))
    tot = inv = 0
    for v in grp.values():
        for i in range(len(v)):
            for j in range(i + 1, len(v)):
                (a, va), (b, vb) = v[i], v[j]
                if st.rng_of(va) < 0 or st.rng_of(va) != st.rng_of(vb) or not name_order_decided(*sorted((a, b))):
                    continue
                tot += 1
                if (a < b) != (va < vb):
                    inv += 1
    return tot, inv




def demangle_map(names):
    return P.demangle_all(sorted(names))


# ----------------------------------------------------------------------------------------------------------------
# hints for functions without candidates

def disasm(code, base, mask_fields):
    """[(offset, text)] with relocated fields zeroed (so masked operands compare equal)"""
    b = bytearray(code)
    for off, ln in mask_fields:
        for k in range(off, min(off + ln, len(b))):
            b[k] = 0
    out = []
    for i in bm.MD.disasm(bytes(b), 0):
        out.append((i.address, f"{i.mnemonic} {i.op_str}".strip(), i.size))
    return out


def hint_for(st, f, partner, nm):
    """diff of obj function f against exe function at `partner`"""
    exe = st.c.exe
    size = st.c.fsize(partner)
    xb = exe.read(partner, size)
    fo = [(off, ln) for off, ln, *_ in f.fields]
    # exe fields: the same offsets when sizes agree, else rel32 of calls found by decoding
    xf = list(fo) if size == f.size else []
    if size != f.size:
        for i in bm.MD.disasm(xb, 0):
            for k in range(1, i.size - 3):
                pass
        # call/jmp/lea rip rel32: mask by decoding
        for i in bm.MD.disasm(xb, 0):
            if i.mnemonic in ("call", "jmp") and i.size == 5:
                xf.append((i.address + 1, 4))
            elif "rip" in i.op_str and i.disp_offset:
                xf.append((i.address + i.disp_offset, 4))
    A = disasm(f.data, 0, fo)
    B = disasm(xb, 0, xf)
    import difflib
    sm = difflib.SequenceMatcher(None, [t for _, t, _ in A], [t for _, t, _ in B], autojunk=False)
    lines = [f"   obj {f.size} bytes, exe 0x{partner:x} {size} bytes ({exe.name(partner)}), similarity {sm.ratio():.2f}"]
    shown = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        for k in range(max(i2 - i1, j2 - j1)):
            if shown >= 14:
                break
            l = A[i1 + k][1] if i1 + k < i2 else "-"
            r = B[j1 + k][1] if j1 + k < j2 else "-"
            lines.append(f"     +{A[i1 + k][0]:#05x}  obj: {l:<44} exe: {r}" if i1 + k < i2 else
                         f"     +{B[j1 + k][0]:#05x}  obj: {l:<44} exe: {r}")
            shown += 1
    if shown >= 14:
        lines.append("     ...")
    if size == f.size:       # relocation targets
        for off, k, tn, add in f.refs:
            disp = struct.unpack_from("<i", xb, off)[0]
            tva = partner + off + 4 + k + disp - add
            want = st.EK.get(tn)
            xn = exe.name(tva)
            mark = ""
            if want is not None and want != tva:
                mark = f"   <-- obj {short(tn)} is 0x{want:x}"
            elif want is None:
                mark = f"   (obj {short(tn)})"
            if mark:
                lines.append(f"     reloc +{off:#x}: exe 0x{tva:x} {xn[:60]}{mark}")
    return lines


def similar_candidates(st, f, free, exclude, n=2):
    """closest unclaimed exe functions by mnemonic sequence"""
    import difflib
    A = [t.split()[0] for _, t, _ in disasm(f.data, 0, [(o, l) for o, l, *_ in f.fields])]
    best = []
    for va in free:
        sz = st.c.fsize(va)
        if sz < f.size * 0.6 or sz > f.size * 1.6 or va in exclude:
            continue
        B = [i.mnemonic for i in bm.MD.disasm(st.c.exe.read(va, sz), 0)]
        sm = difflib.SequenceMatcher(None, A, B, autojunk=False)
        if sm.real_quick_ratio() < 0.6 or sm.quick_ratio() < 0.6:
            continue
        best.append((sm.ratio(), va))
    best.sort(reverse=True)
    return best[:n]


# ----------------------------------------------------------------------------------------------------------------

def solve_unit(ctx, u, args):
    exe = ctx.exe
    text = open(u.path, encoding="latin1").read()
    inblock, _ = block_pins(text)
    # pins in the generated block do not count; pins elsewhere do (unless --ignore-pins)
    keep = {}
    blk_names = set()
    if args.ignore_pins:
        u.pins = {}
    else:
        lines = text.split("\n")
        _, span = block_pins(text)
        for i, l in enumerate(lines):
            if span and span[0] < i < span[1]:
                continue
            m = re.match(r"\s*//\s*MS2-PIN:\s*(\S+)\s+0x([0-9a-fA-F]+)", l)
            if m:
                keep[m.group(1)] = int(m.group(2), 16)
        u.pins = keep
    bm.HARVEST.clear()
    t0 = time.time()
    res = P.process_unit(u, exe, ctx.starts, ctx.finfo, ctx.bases, ctx.vft, False)
    print(f"[{u.name}] progress pairing: {len(res['pairs'])} pairs "
          f"({sum(1 for p in res['pairs'].values() if p['ok'])} byte-exact), {len(res['vft'])} vftables "
          f"({time.time() - t0:.0f}s)")
    obj = bm.Obj(u.obj)
    st = UnitState(ctx, u, res, obj, args)
    pool = st.cand_pool(False)
    gpool = ctx.by_size() if args.glob else pool
    V = [n for n in st.fn if n not in st.AN]
    oc = order_check(st)
    order_ok = oc[1] == 0 and (oc[0] >= args.order_min or args.force_order)
    print(f"  order check (look-alike groups, decided pairs, same range): {oc[0]} anchored pairs, {oc[1]} inversions"
          + ("" if order_ok else f"  -> name order NOT used (needs >= {args.order_min} anchored pairs and 0 inversions; --force-order)"))
    # candidates
    t0 = time.time()
    D0, why0, nocand = {}, {}, []
    for n in V:
        f = st.fn[n]
        d = st.candidates(f, gpool)
        if d:
            D0[n] = d
            if len(d) == 1:
                why0[n] = "unique"
        else:
            nocand.append(n)
    print(f"  {len(st.fn)} obj functions: {len(st.AN)} anchored, {len(V)} to solve "
          f"({len(D0)} with candidates, {len(nocand)} without) ({time.time() - t0:.0f}s)")
    # forced by anchors (callers) and vftable slots
    forced = collections.defaultdict(dict)       # var -> {exe va: cause}
    partner = collections.defaultdict(collections.Counter)    # var -> expected exe partner (for the hints)
    for n, va in st.AN.items():
        f = st.fn.get(n)
        if f is None or not (res["pairs"].get(n, {}).get("ok") or True):
            continue
        p = res["pairs"].get(n)
        if p is not None and not p["ok"] and p["how"] not in ("tag", "pin"):
            continue
        for tn, tva in st.targets(f, va):
            if tn in D0 or tn in nocand:
                partner[tn][tva] += 1
                if tn in D0 and tva in D0[tn]:
                    forced[tn][tva] = "caller " + short(n)
    for sname, v in res["vft"].items():
        if v["va"] is None or sname not in obj.by_name:
            continue
        vsi = obj.by_name[sname]
        nm, val, secnum = obj.syms[vsi][:3]
        sec = obj.sec(secnum)
        rel = {off: (si2, ty) for off, si2, ty in sec["relocs"]}
        k = 0
        while (val + 8 * k) in rel and rel[val + 8 * k][1] == bm.REL_ADDR64:
            tn = obj.syms[rel[val + 8 * k][0]][0]
            xa = struct.unpack_from("<Q", exe.img, v["va"] - exe.base + 8 * k)[0]
            if tn in D0 or tn in nocand:
                partner[tn][xa] += 1
                if tn in D0 and xa in D0[tn]:
                    forced[tn][xa] = f"vftable slot {k} of {short(sname)}"
            k += 1
    for tn, fm in forced.items():
        if len(fm) >= 1 and tn in D0:
            # all forcings must agree for a restriction
            vas = set(fm)
            if len(vas) == 1:
                a = next(iter(vas))
                D0[tn] = [a]
                why0[tn] = next(iter(fm.values()))
    # solve
    inrange = lambda a: st.rng_of(a) >= 0
    tiers = {}
    passes = [("A", False, False), ("B", True, False), ("C", True, True)]
    states = {}
    for tag, order, sac in passes:
        if order and not order_ok:
            continue
        s = Solver(st, [n for n in D0], D0, why0, args.glob)
        t0 = time.time()
        states[tag] = s.run(order, sac, args.budget)
        print(f"  pass {tag} (order={'on' if order else 'off'}{', probe' if sac else ''}): "
              f"{sum(1 for n in D0 if len(states[tag]['D'][n]) == 1)} resolved of {len(D0)} ({time.time() - t0:.0f}s, "
              f"{len(states[tag]['relaxed'])} relaxed)")
    last = states[max(states)]
    sol = {}
    for n in D0:
        d = None
        for tag, label in (("A", None), ("B", "order"), ("C", "probe")):
            if tag in states and len(states[tag]["D"][n]) == 1 and states[tag]["D"][n][0] not in (d or []):
                d = states[tag]["D"][n][0]
                if tag == "A":
                    conf = "unique" if why0.get(n) == "unique" else ("prop" if True else "prop")
                    reason = states["A"]["why"].get(n) or "unique"
                    if why0.get(n) == "unique":
                        conf, reason = "unique", "single byte-identical candidate"
                    elif reason.startswith(("symbols.tsv", "vftable", "caller ")) and n in forced:
                        conf = "unique"
                    elif reason.startswith("0x"):
                        conf = "prop"
                    else:
                        conf = "prop"
                elif tag == "B":
                    conf, reason = "order", states["B"]["why"].get(n) or "name order"
                else:
                    conf, reason = "probe", "only candidate surviving trial assignment"
                sol[n] = (d, conf, reason)
                break
    # remaining ambiguous: identical-domain groups, name order
    amb = {n: list(last["D"][n]) for n in D0 if len(last["D"][n]) > 1}
    guess = {}
    groups = collections.defaultdict(list)
    for n, d in amb.items():
        groups[tuple(sorted(d))].append(n)
    for vas, names in groups.items():
        cand_names = [n for n in names if not st.fn[n].own]
        if len(names) == len(vas):
            for n, a in zip(sorted(names, key=lambda n: st.fn[n].si if st.fn[n].init else 0 if False else (n if not st.fn[n].init else "")), sorted(vas)):
                guess[n] = a
    # report
    allnames = list(D0)
    resolved = {n: sol[n] for n in sol}
    # discard duplicates (two names, same VA)
    byva = collections.defaultdict(list)
    for n, (a, c, r) in resolved.items():
        byva[a].append(n)
    for a, ns in byva.items():
        if len(ns) > 1:
            for n in ns:
                resolved.pop(n, None)
                amb[n] = [a]
    # outside the unit's ranges (shared with others)
    elsewhere = {n: v for n, v in resolved.items() if not inrange(v[0])}
    resolved = {n: v for n, v in resolved.items() if inrange(v[0])}
    # name collisions: an exe VA already used by an anchor never appears in D0 (excluded)
    prior_diff = {n: (st.prior[n], resolved[n][0]) for n in resolved if n in st.prior and st.prior[n] != resolved[n][0]}
    # nocand classification
    free = [va for va in ctx.starts if inrange(va) and va not in st.anvas and va not in {v[0] for v in resolved.values()}]
    return dict(st=st, res=res, D0=D0, why0=why0, nocand=nocand, resolved=resolved, amb=amb, guess=guess,
                elsewhere=elsewhere, states=states, partner=partner, prior_diff=prior_diff, oc=oc, order_ok=order_ok,
                free=free, V=V, pool=pool, last=last, forced=forced)


def report(ctx, u, R, args):
    st = R["st"]
    obj = st.obj
    names = list(R["resolved"]) + list(R["amb"]) + R["nocand"] + list(R["elsewhere"])
    dem = demangle_map(names) if (args.verbose or args.hints) else {}
    out = []
    pins = []
    for n, (a, c, r) in sorted(R["resolved"].items(), key=lambda kv: kv[1][0]):
        line = f"// MS2-PIN: {n} 0x{a:x} ; {c}: {r}"
        pins.append((n, a, c, r))
        out.append(line)
    print(f"\n== {u.name}: {len(pins)} proposed pins "
          f"({collections.Counter(c for _, _, c, _ in pins).most_common()})")
    if args.show_pins or not args.apply:
        for l in out:
            print(l)
    if R["prior_diff"]:
        print(f"-- {len(R['prior_diff'])} name-order guesses of progress.py that the solver contradicts:")
        for n, (old, new) in list(R["prior_diff"].items())[:10]:
            print(f"   {short(n)}: progress 0x{old:x}, solver 0x{new:x}")
    if R["elsewhere"]:
        print(f"-- {len(R['elsewhere'])} resolved to exe copies OUTSIDE the unit's ranges (shared COMDATs, not pinnable):")
        for n, (a, c, r) in list(R["elsewhere"].items())[:15 if not args.verbose else 1000]:
            print(f"   0x{a:x} ({ctx.owner_of(a)}) {short(n)}")
    amb = R["amb"]
    if amb:
        print(f"-- {len(amb)} AMBIGUOUS (several candidates survive); `guess` = name order of identical groups:")
        for n, d in sorted(amb.items())[:args.max_list]:
            g = R["guess"].get(n)
            print(f"   {short(dem.get(n, n))}\n      candidates {[hex(x) for x in d[:6]]}{'...' if len(d) > 6 else ''}"
                  + (f"  guess 0x{g:x}" if g else ""))
        if len(amb) > args.max_list:
            print(f"   ... {len(amb) - args.max_list} more (--max-list)")
    # no candidates
    nc = R["nocand"]
    if nc:
        # global lookup (identical function elsewhere in the exe?)
        gpool = ctx.by_size()
        where, none = {}, []
        for n in nc:
            f = st.fn[n]
            g = st.candidates(f, gpool)
            if g:
                where[n] = g
            else:
                none.append(n)
        print(f"-- {len(nc)} obj functions without a candidate in the unit's ranges: "
              f"{len(where)} have an identical exe copy elsewhere (not this unit's, fine), {len(none)} have none at all")
        if where and args.verbose:
            for n, g in list(where.items())[:args.max_list]:
                print(f"   elsewhere: {short(n)} -> " + ", ".join(f"0x{x:x} ({ctx.owner_of(x)})" for x in g[:3]))
        R["none"] = none
        used = {v[0] for v in R["resolved"].values()}
        if none:
            print(f"-- NO CANDIDATE ANYWHERE ({len(none)}): usually a wrong key/value/template-argument type or helper")
            shown = 0
            for n in sorted(none):
                if shown >= args.max_list:
                    print(f"   ... {len(none) - shown} more (--max-list)")
                    break
                f = st.fn[n]
                print(f"   {short(dem.get(n, n)) if dem else short(n)}   [{f.size} bytes]")
                shown += 1
                if args.hints:
                    pc = R["partner"].get(n)
                    cand = None
                    why = ""
                    if pc:
                        va = pc.most_common(1)[0][0]
                        if va in ctx.finfo:
                            cand, why = va, "implied by an anchored caller/vftable"
                    sim = []
                    if cand is None:
                        sim = similar_candidates(st, f, R["free"], used)
                        if sim:
                            cand, why = sim[0][1], f"closest by instruction sequence ({sim[0][0]:.2f})"
                    if cand is None:
                        print("      no similar exe function in the unit ranges")
                    else:
                        print(f"      hint: {why}")
                        for l in hint_for(st, f, cand, n):
                            print("   " + l)
    # exe side
    inr = sum(1 for va in ctx.starts if any(a <= va < b for a, b in u.ranges))
    claimed = len(st.AN) + len(R["resolved"])
    print(f"-- exe functions in ranges: {inr}; anchored {len(st.AN)}, proposed {len(R['resolved'])}, "
          f"left unclaimed {inr - claimed if inr >= claimed else 0}")
    if args.list_exe:
        used = set(st.AN.values()) | {v[0] for v in R["resolved"].values()}
        for va in ctx.starts:
            if any(a <= va < b for a, b in u.ranges) and va not in used:
                print(f"   unclaimed 0x{va:x} {ctx.fsize(va)} {ctx.finfo[va][1]}")
    return pins


def apply_pins(u, pins, args):
    rel = os.path.relpath(u.path, ROOT)
    st = subprocess.run(["git", "status", "--porcelain", "--", rel], cwd=ROOT, capture_output=True, text=True).stdout
    if st.strip() and not args.allow_dirty:
        print(f"{rel}: has uncommitted changes ({st.strip()[:2]}); refusing --apply (use --allow-dirty for your own file)")
        return False
    text = open(u.path, encoding="latin1").read()
    pins = [(n, a, c, r) for n, a, c, r in pins if c in APPLY_OK]
    lines = text.split("\n")
    # pins outside the block (kept as they are): do not duplicate, warn on a different VA
    _, span = block_pins(text)
    outside = {}
    for i, l in enumerate(lines):
        if span and span[0] <= i <= span[1]:
            continue
        m = re.match(r"\s*//\s*MS2-PIN:\s*(\S+)\s+0x([0-9a-fA-F]+)", l)
        if m:
            outside[m.group(1)] = int(m.group(2), 16)
    body = []
    for n, a, c, r in sorted(pins, key=lambda p: p[1]):
        if n in outside:
            if outside[n] != a:
                print(f"  note: {short(n)} pinned outside the block at 0x{outside[n]:x}, solver says 0x{a:x}")
            continue
        body.append(f"// MS2-PIN: {n} 0x{a:x} ; {c}")
    block = [BEGIN] + body + [END]
    if span:
        new = lines[:span[0]] + block + lines[span[1] + 1:]
    else:
        last = max((i for i, l in enumerate(lines) if re.match(r"\s*//\s*MS2-RANGE:", l)), default=None)
        if last is None:
            print(f"{rel}: no MS2-RANGE line, cannot place the block")
            return False
        new = lines[:last + 1] + block + lines[last + 1:]
    open(u.path, "w", encoding="latin1").write("\n".join(new))
    print(f"{rel}: wrote {len(body)} pins into the tplpin block")
    return True


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("unit", help="unit substring (path or MS2-UNIT name); every match is processed")
    ap.add_argument("--global", dest="glob", action="store_true",
                    help="candidates over the whole exe (COMDATs shared with other units), pins only inside the ranges")
    ap.add_argument("--apply", action="store_true", help="write the pins block into the unit source")
    ap.add_argument("--allow-dirty", action="store_true", help="--apply even if the file has uncommitted changes")
    ap.add_argument("--hints", action="store_true", help="diff functions without candidates against the closest exe function")
    ap.add_argument("--force-order", action="store_true", help="use the name-order model even with too little evidence")
    ap.add_argument("--order-min", type=int, default=6, help="anchored decided pairs needed before name order is trusted")
    ap.add_argument("--ignore-pins", action="store_true", help="ignore all existing MS2-PIN lines (solve from scratch)")
    ap.add_argument("--anchor", action="append", default=[], metavar="SUBSTR=0xVA",
                    help="extra anchor: obj symbol containing SUBSTR (must be unique) is at VA")
    ap.add_argument("--cache", help="progress cache dir (default build/progress-$MS2_AGENT, else build/progress-tplpin)")
    ap.add_argument("--obj", help="use this obj instead of compiling (read-only inspection)")
    ap.add_argument("--no-compile", action="store_true")
    ap.add_argument("--budget", type=float, default=240, help="seconds for the probing pass (default 240)")
    ap.add_argument("--max-list", type=int, default=40)
    ap.add_argument("--show-pins", action="store_true", help="with --apply: also print the pin lines")
    ap.add_argument("--list-exe", action="store_true", help="list exe functions in the ranges nobody claims")
    ap.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args()
    cache = a.cache or os.path.join(ROOT, "build", "progress-" + (os.environ.get("MS2_AGENT") or "tplpin"))
    os.makedirs(cache, exist_ok=True)
    units = load_unit(a.unit, cache, not a.no_compile)
    if not units:
        sys.exit(f"no unit matches {a.unit!r}")
    ctx = Ctx(a)
    for u in units:
        if a.obj:
            u.obj = a.obj
        elif not a.no_compile and P.needs_compile(u):
            print(f"compiling {u.rel} ...", flush=True)
            ok, msgs, dt = P.compile_unit(u)
            if not ok:
                print("\n".join(msgs[:30]))
                print(f"{u.rel}: compile FAILED; skipped")
                continue
        if not os.path.exists(u.obj):
            print(f"{u.rel}: no obj at {u.obj}; skipped")
            continue
        R = solve_unit(ctx, u, a)
        st = R["st"]
        pins = report(ctx, u, R, a)
        if a.apply:
            apply_pins(u, pins, a)


if __name__ == "__main__":
    main()
