// cpvpmanager.h - PLACEHOLDER for CPVPManager (RTTI .?AVCPVPManager@@, 0x108 bytes). NOT an original header.
// Bases: TSingleton<CPVPManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CPVPManager : public TSingleton<CPVPManager>
{
public:
    CPVPManager();                                          // 0x141280b40
    virtual ~CPVPManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x108 - 0x8];
};
MS2_CHECK_SIZE(CPVPManager, 0x108);
