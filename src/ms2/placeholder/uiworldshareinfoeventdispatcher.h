// uiworldshareinfoeventdispatcher.h - PLACEHOLDER for UIWorldShareInfoEventDispatcher (RTTI .?AVUIWorldShareInfoEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIWorldShareInfoEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIWorldShareInfoEventDispatcher : public TSingleton<UIWorldShareInfoEventDispatcher>
{
public:
    UIWorldShareInfoEventDispatcher();                      // 0x14135fc80
    virtual ~UIWorldShareInfoEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIWorldShareInfoEventDispatcher, 0x28);
