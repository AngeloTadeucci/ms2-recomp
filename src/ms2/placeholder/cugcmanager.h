// cugcmanager.h - PLACEHOLDER for CUgcManager (RTTI .?AVCUgcManager@@, 0x1c0 bytes). NOT an original header.
// Bases: TSingleton<CUgcManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CUgcManager : public TSingleton<CUgcManager>
{
public:
    CUgcManager();                                          // 0x14187ed30
    virtual ~CUgcManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x1c0 - 0x8];
};
MS2_CHECK_SIZE(CUgcManager, 0x1c0);
