// uistatuseventdispatcher.h - PLACEHOLDER for UIStatusEventDispatcher (RTTI .?AVUIStatusEventDispatcher@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<UIStatusEventDispatcher> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UIStatusEventDispatcher : public TSingleton<UIStatusEventDispatcher>
{
public:
    UIStatusEventDispatcher();                              // 0x141b0cc60
    virtual ~UIStatusEventDispatcher();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(UIStatusEventDispatcher, 0x28);
