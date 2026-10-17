// cmicrogamemanagercli.h - PLACEHOLDER for CMicroGameManagerCli (RTTI .?AVCMicroGameManagerCli@@, 0x8 bytes). NOT an original header.
// Bases: TSingleton<CMicroGameManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMicroGameManagerCli : public TSingleton<CMicroGameManagerCli>
{
public:
    CMicroGameManagerCli();                                 // 0x140b73c50
    virtual ~CMicroGameManagerCli();
};
MS2_CHECK_SIZE(CMicroGameManagerCli, 0x8);
