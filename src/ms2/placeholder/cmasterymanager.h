// cmasterymanager.h - PLACEHOLDER for CMasteryManager (RTTI .?AVCMasteryManager@@, 0x8 bytes). NOT an original header.
// Bases: TSingleton<CMasteryManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMasteryManager : public TSingleton<CMasteryManager>
{
public:
    CMasteryManager();                                      // 0x140b6d070
    virtual ~CMasteryManager();
};
MS2_CHECK_SIZE(CMasteryManager, 0x8);
