// uidialogeventdispatcher.h - PLACEHOLDER for UIDialogEventDispatcher (RTTI .?AVUIDialogEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIDialogEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIDialogEventDispatcher : public TSingleton<UIDialogEventDispatcher>
{
public:
    UIDialogEventDispatcher();                              // 0x141927fb0
    virtual ~UIDialogEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIDialogEventDispatcher, 0x28);
