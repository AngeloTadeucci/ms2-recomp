// cusereventmanager.h - PLACEHOLDER for CUserEventManager (RTTI .?AVCUserEventManager@@, 0x450 bytes). NOT an original header.
// Bases: TSingleton<CUserEventManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CUserEventManager : public TSingleton<CUserEventManager>
{
public:
    CUserEventManager();                                    // 0x1408d6b30
    virtual ~CUserEventManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x450 - 0x8];
};
MS2_CHECK_SIZE(CUserEventManager, 0x450);
