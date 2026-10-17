// cusermaidmanager.h - PLACEHOLDER for CUserMaidManager (RTTI .?AVCUserMaidManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<CUserMaidManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CUserMaidManager : public TSingleton<CUserMaidManager>
{
public:
    CUserMaidManager();                                     // 0x14127e4b0
    virtual ~CUserMaidManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(CUserMaidManager, 0x38);
