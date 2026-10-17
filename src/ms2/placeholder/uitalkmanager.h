// uitalkmanager.h - PLACEHOLDER for UITalkManager (RTTI .?AVUITalkManager@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<UITalkManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class UITalkManager : public TSingleton<UITalkManager>
{
public:
    UITalkManager();                                        // 0x141b1dc40
    virtual ~UITalkManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xe8 - 0x8];
};
MS2_CHECK_SIZE(UITalkManager, 0xe8);
