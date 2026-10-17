// uibuddyeventdispatcher.h - PLACEHOLDER for UIBuddyEventDispatcher (RTTI .?AVUIBuddyEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIBuddyEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIBuddyEventDispatcher : public TSingleton<UIBuddyEventDispatcher>
{
public:
    UIBuddyEventDispatcher();                               // 0x1418d93b0
    virtual ~UIBuddyEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIBuddyEventDispatcher, 0x28);
