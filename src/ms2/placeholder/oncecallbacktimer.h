// oncecallbacktimer.h - PLACEHOLDER for OnceCallbackTimer (RTTI .?AVOnceCallbackTimer@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<OnceCallbackTimer> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class OnceCallbackTimer : public TSingleton<OnceCallbackTimer>
{
public:
    OnceCallbackTimer();                                    // 0x140ca7030
    virtual ~OnceCallbackTimer();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x20 - 0x8];
};
MS2_CHECK_SIZE(OnceCallbackTimer, 0x20);
