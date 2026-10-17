// ccontentshutdownmanager.h - PLACEHOLDER for CContentShutdownManager (RTTI .?AVCContentShutdownManager@@, 0x1e0 bytes). NOT an original header.
// Bases: TSingleton<CContentShutdownManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the rest of its members are not recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/contentshutdown.h"

class CContentShutdownManager : public TSingleton<CContentShutdownManager>
{
public:
    CContentShutdownManager();                              // 0x140cca6a0
    virtual ~CContentShutdownManager();
    void FUN_140cca720(Unk_ShutdownInput& in);              // 0x140cca720 decodes the flags
private:
    MS2_LAYOUT_FRIEND;
    CContentShutdown m_flags;                               // +0x8 (0x1d4 bytes)
    int m_pad_1dc;
};
MS2_CHECK_SIZE(CContentShutdownManager, 0x1e0);
