// mctimer.h - Unk_McTimer, the 8-byte millisecond poll timer (descriptive name, not an original header). Shared by the
// mouse controller (unit_140ad1860.h), the nurturing state, NifEffectParam and CPet.
#pragma once
#include "ms2/ms2layout.h"

// ctor 0x140517b00, arm 0x140268840, "interval elapsed" test 0x140268870 re-arms.
struct Unk_McTimer
{
    Unk_McTimer();                          // 0x140517b00
    void FUN_140268840();                   // arm
    int FUN_140268870(int nInterval);       // true once the interval elapsed
    unsigned m_nInterval;                   // +0
    unsigned m_nLastTick;                   // +4
};
MS2_CHECK_SIZE(Unk_McTimer, 8);
