// uientityeventdispatcher.h - PLACEHOLDER for UIEntityEventDispatcher (RTTI .?AVUIEntityEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIEntityEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIEntityEventDispatcher : public TSingleton<UIEntityEventDispatcher>
{
public:
    UIEntityEventDispatcher();                              // 0x141930820
    virtual ~UIEntityEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIEntityEventDispatcher, 0x28);
