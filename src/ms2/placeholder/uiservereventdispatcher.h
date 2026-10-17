// uiservereventdispatcher.h - PLACEHOLDER for UIServerEventDispatcher (RTTI .?AVUIServerEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIServerEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIServerEventDispatcher : public TSingleton<UIServerEventDispatcher>
{
public:
    UIServerEventDispatcher();                              // 0x141347260
    virtual ~UIServerEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIServerEventDispatcher, 0x28);
