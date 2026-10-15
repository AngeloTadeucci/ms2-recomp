// timer.h - PLACEHOLDER for the exe's poll Timer (CPtred-derived, 0x38 bytes; ctor 0x1408686b0, dtor 0x140868720).
// NOT an original header. gpumanager.h and uidungeonrewarddialog.h carry private copies of the same class.
#pragma once

#include "ms2/ms2layout.h"

class Timer {
public:
    Timer();                                    // 0x1408686b0
    ~Timer();                                   // 0x140868720
    void FUN_140868750(unsigned int ms);        // arm: expires ms from now
    void FUN_1408687f0();                       // reset
    int FUN_140868c00();                        // expired?
    int FUN_140868a70();                        // elapsed milliseconds
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30;
};
MS2_CHECK_SIZE(Timer, 0x38);
