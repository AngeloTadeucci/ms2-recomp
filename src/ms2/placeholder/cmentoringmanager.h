// cmentoringmanager.h - PLACEHOLDER for CMentoringManager (RTTI .?AVCMentoringManager@@, 0x78 bytes). NOT an original header.
// Bases: TSingleton<CMentoringManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMentoringManager : public TSingleton<CMentoringManager>
{
public:
    CMentoringManager();                                    // 0x140b71440
    virtual ~CMentoringManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x78 - 0x8];
};
MS2_CHECK_SIZE(CMentoringManager, 0x78);
