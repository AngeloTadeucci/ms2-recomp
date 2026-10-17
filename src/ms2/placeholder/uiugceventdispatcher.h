// uiugceventdispatcher.h - PLACEHOLDER for UIUGCEventDispatcher (RTTI .?AVUIUGCEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIUGCEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIUGCEventDispatcher : public TSingleton<UIUGCEventDispatcher>
{
public:
    UIUGCEventDispatcher();                                 // 0x141b38b40
    virtual ~UIUGCEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIUGCEventDispatcher, 0x28);
