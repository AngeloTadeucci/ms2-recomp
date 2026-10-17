// ccontentshutdownmanager.h - PLACEHOLDER for CContentShutdownManager (RTTI .?AVCContentShutdownManager@@, 0x1e0 bytes). NOT an original header.
// Bases: TSingleton<CContentShutdownManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CContentShutdownManager : public TSingleton<CContentShutdownManager>
{
public:
    CContentShutdownManager();                              // 0x140cca6a0
    virtual ~CContentShutdownManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x1e0 - 0x8];
};
MS2_CHECK_SIZE(CContentShutdownManager, 0x1e0);
