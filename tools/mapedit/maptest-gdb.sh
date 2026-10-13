#!/usr/bin/env bash
# Launcher for tools/mapedit/maptest.sh (MAPTEST_LAUNCH=tools/mapedit/maptest-gdb.sh): runs the unhooked client under gdb and
# dumps registers + 4 KiB of stack to work/maptest/av-stack.txt when the baseline access violation at 0x14160E608 hits
# (null global 0x143ABF528 read by FUN_140c78cf0 -> FUN_14160e5f0, see NOTES "Edited-map client test"), then continues
# (the game's SEH handler shows its blank "error" dialog). Diagnostic only; maptest.sh works without it.
R=$(cd "$(dirname "$0")/../.." && pwd)
mkdir -p "$R/work/maptest"
cat > "$R/work/maptest/av.gdb" <<G
set pagination off
set confirm off
handle SIGUSR1 nostop noprint pass
handle SIGUSR2 nostop noprint pass
handle SIGCHLD nostop noprint pass
handle SIGALRM nostop noprint pass
handle SIGPIPE nostop noprint pass
handle SIG34 nostop noprint pass
handle SIG35 nostop noprint pass
handle SIG36 nostop noprint pass
catch signal SIGSEGV
condition 1 \$rip == 0x14160e608
run
set logging file $R/work/maptest/av-stack.txt
set logging overwrite on
set logging enabled on
info registers
x/512gx \$rsp
set logging enabled off
continue
G
docker start ms2-xvfb >/dev/null 2>&1
export DISPLAY=:99 WAYLAND_DISPLAY= LANG=ko_KR.utf8 WINEPREFIX=$R/work/wineprefix-client WINEARCH=win64 WINEDEBUG=-all
export WINEDLLOVERRIDES="dinput8=b;concrt140,msvcp140,vcruntime140,vccorlib140,mfc140,mfc140u,mfcm140,mfcm140u,d3dx9_42,d3dx9_43,d3dx10_42,d3dx11_42,d3dcompiler_42,d3dcompiler_43,d3dcompiler_46,d3dcompiler_47=n,b;mscoree,mshtml="
cd "$R/work/client-kms2dev" && exec gdb -q -batch -x "$R/work/maptest/av.gdb" --args wine x64/MapleStory2.exe
