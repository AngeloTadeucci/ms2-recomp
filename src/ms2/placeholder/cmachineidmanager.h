// cmachineidmanager.h - PLACEHOLDER for CMachineIDManager (RTTI .?AVCMachineIDManager@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<CMachineIDManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMachineIDManager : public TSingleton<CMachineIDManager>
{
public:
    CMachineIDManager();                                    // 0x140d4fcd0
    virtual ~CMachineIDManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x20 - 0x8];
};
MS2_CHECK_SIZE(CMachineIDManager, 0x20);
