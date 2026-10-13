#!/bin/bash
# Per-unit done check for one agent (docs/RECOVERY.md sections 10 and 12). Safe to run while other agents run theirs.
#
#   MS2_AGENT=<name> tools/unit-check.sh [--no-clang] [--no-dll] [-v] <unit-substr> [<unit-substr> ...]
#
# 1. tools/progress.py --agent <name> --check <unit>: compiles the unit with the game flags into build/progress-<name>/,
#    pairs and byte-matches it; fails unless every function in its MS2-RANGEs is matched and every vftable is OK.
#    Report mode: progress/* is never written (status/summary/symbols go to build/progress-<name>/).
# 2. Link check: builds build/hook-msvc-<name>/ (cl 19.16) and build/hook-clang-<name>/ (clang-cl) with ONLY this
#    unit's .cpp (+ its difftest, if any) as game code, linked against build/progress-<name>/symbols.tsv (committed
#    symbols + the unit's own harvest). Other agents' half-finished units are never compiled here. The post-link
#    `ms2symobj.py --check` must print ok.
# Exit 0 = the unit meets done criteria 1-3. The full shared build (build/hook-msvc, build/hook-clang) and progress/*
# are the merge step's job.
set -u
R=$(cd "$(dirname "$0")/.." && pwd)
PY="$R/.venv/bin/python"
export PATH="$R/.venv/bin:$PATH"

clang=1 dll=1 verbose=()
units=()
for a in "$@"; do
    case "$a" in
        --no-clang) clang=0 ;;
        --no-dll) dll=0 ;;
        -v) verbose=(-v) ;;
        -h|--help) sed -n '2,15p' "$0"; exit 0 ;;
        *) units+=("$a") ;;
    esac
done
AGENT="${MS2_AGENT:-}"
if [ -z "$AGENT" ]; then echo "unit-check: set MS2_AGENT=<your agent name>" >&2; exit 2; fi
if [ ${#units[@]} -eq 0 ]; then echo "usage: MS2_AGENT=<name> $0 <unit-substr>..." >&2; exit 2; fi

# Resolve the substrings to unit sources (files with an MS2-UNIT line), exactly like progress.py's filter.
mapfile -t srcs < <(cd "$R/src/ms2" && grep -rl --include='*.cpp' 'MS2-UNIT:' . | sed 's|^\./||' | sort |
    while read -r f; do
        u=$(grep -m1 -o 'MS2-UNIT: *[^ ]*' "$f" | sed 's/MS2-UNIT: *//')
        for s in "${units[@]}"; do
            case "$f|$u" in *"$s"*) echo "$f"; break ;; esac
        done
    done)
if [ ${#srcs[@]} -eq 0 ]; then echo "unit-check: no src/ms2 unit matches: ${units[*]}" >&2; exit 2; fi
echo "unit-check [$AGENT]: ${srcs[*]}"

# 1. compile + bytematch (one cl at a time per agent keeps the CPU moderate)
echo "== progress.py --agent $AGENT --check"
nice "$PY" "$R/tools/progress.py" --agent "$AGENT" --check -j1 "${verbose[@]}" "${units[@]}"
pst=$?

if [ $dll -eq 0 ]; then exit $pst; fi

# 2. link check in the agent's own build dirs
filter=""
for f in "${srcs[@]}"; do
    stem=$(basename "$f" .cpp)
    filter+="src/ms2/$f;hook/difftest/${stem}_difftest;"
done
filter=${filter%;}
syms="$R/build/progress-$AGENT/symbols.tsv"
[ -f "$syms" ] || cp "$R/progress/symbols.tsv" "$syms"

build() {   # build <dir> <toolchain> <ninja wrapper>
    local dir=$1 tc=$2 nj=$3
    if [ ! -f "$dir/build.ninja" ] || [ "$(grep -m1 '^MS2_GAME_FILTER:' "$dir/CMakeCache.txt" 2>/dev/null)" != "MS2_GAME_FILTER:STRING=$filter" ]; then
        cmake -G Ninja -S "$R/src" -B "$dir" -DCMAKE_TOOLCHAIN_FILE="$tc" \
            "-DMS2_GAME_FILTER=$filter" "-DMS2_SYMBOL_TSV=$syms" >"$dir.configure.log" 2>&1 ||
            { cat "$dir.configure.log"; return 1; }
    fi
    nice $nj -C "$dir" -j2
}
dst=0
echo "== build/hook-msvc-$AGENT (cl 19.16)"
mkdir -p "$R/build"
build "$R/build/hook-msvc-$AGENT" "$R/cmake/toolchain-msvc1416-wine.cmake" "$R/tools/ninja-msvc.sh" || dst=1
if [ $clang -eq 1 ]; then
    echo "== build/hook-clang-$AGENT (clang-cl)"
    build "$R/build/hook-clang-$AGENT" "$R/cmake/toolchain-clangcl-x64.cmake" ninja || dst=1
fi

echo
[ $pst -eq 0 ] && echo "bytematch: OK" || echo "bytematch: NOT DONE (see above; -v for diffs)"
[ $dst -eq 0 ] && echo "DLL link: OK" || echo "DLL link: FAILED"
[ $pst -eq 0 ] && [ $dst -eq 0 ]
