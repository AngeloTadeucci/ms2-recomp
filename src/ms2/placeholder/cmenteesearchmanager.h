// cmenteesearchmanager.h - PLACEHOLDER for CMenteeSearchManager (RTTI .?AVCMenteeSearchManager@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<CMenteeSearchManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMenteeSearchManager : public TSingleton<CMenteeSearchManager>
{
public:
    CMenteeSearchManager();                                 // 0x140b6e290
    virtual ~CMenteeSearchManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x60 - 0x8];
};
MS2_CHECK_SIZE(CMenteeSearchManager, 0x60);
