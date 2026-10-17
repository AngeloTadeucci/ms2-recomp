// cugcdownloadload.h - PLACEHOLDER for CUgcDownloadLoad (RTTI .?AVCUgcDownloadLoad@@, 0x98 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CUgcDownloadLoad> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class CUgcDownloadLoad : public CThread, public TSingleton<CUgcDownloadLoad>
{
public:
    CUgcDownloadLoad();                                     // 0x14186d1c0
    virtual ~CUgcDownloadLoad();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x98 - 0x20];
};
MS2_CHECK_SIZE(CUgcDownloadLoad, 0x98);
