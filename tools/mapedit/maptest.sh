#!/usr/bin/env bash
# Headless in-game screenshot of a map in the KMS2_DEV client copy (Wine, Xvfb :99 in container ms2-xvfb).
#   tools/mapedit/maptest.sh <out.png> [load_wait_seconds=90]
# Prerequisites: servers running (server/run-servers.sh), account hooktest/test1234 with one character whose DB
# row has MapId set to the map to test (see NOTES "Edited-map client test"). Uses the unhooked client launcher,
# logs in and presses Start by xdotool clicks (1280x720 window), waits, screenshots, then kills ONLY this
# prefix's wine processes (wineserver -k on work/wineprefix-client). MAPTEST_LAUNCH=<script> replaces server/run-client.sh
# (e.g. tools/mapedit/maptest-gdb.sh). Timings: title ~60 s, login ~30 s, then <load_wait> after Start. Extra env: WINEDEBUG=+debugstr to capture the game's OutputDebugString to $R/work/maptest_client.log
set -u
R=$(cd "$(dirname "$0")/../.." && pwd)
OUT=${1:?out.png}; WAIT=${2:-90}
X() { docker exec ms2-xvfb sh -c "DISPLAY=:99 xdotool $*"; }
docker start ms2-xvfb >/dev/null
(nohup bash "${MAPTEST_LAUNCH:-$R/server/run-client.sh}" > "$R/work/maptest_client.log" 2>&1 &)
sleep 60                                   # title screen
X "mousemove 680 581 click 1"; sleep 1; X "type --delay 80 hooktest"
X "mousemove 680 609 click 1"; sleep 1; X "type --delay 80 test1234"
X "mousemove 638 675 click 1"; sleep 30    # login -> character select
X "mousemove 1120 644 click 1"             # Start
sleep "$WAIT"
docker exec ms2-xvfb sh -c 'DISPLAY=:99 import -window root /tmp/s.png' && docker cp ms2-xvfb:/tmp/s.png "$OUT"
echo "screenshot: $OUT"
WINEPREFIX=$R/work/wineprefix-client wineserver -k; sleep 2
