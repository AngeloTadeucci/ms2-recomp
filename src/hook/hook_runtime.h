// Internal interface of the hook runtime (used by the loader entry point, not by recovered code).
#pragma once

namespace ms2::hook {
void OpenLog();            // ms2hook.log next to the exe
int InstallAll();          // validate + install all registered replacements; returns the number installed
void StartStatsThread();   // logs call counters every 5 s when they change
void LogFinalStats();
}  // namespace ms2::hook

namespace ms2::difftest {
void RunAll();             // runs every MS2_DIFFTEST, results to ms2hook.log
}
