// cugcdownloaddown.h - PLACEHOLDER for CUgcDownloadDown (RTTI .?AVCUgcDownloadDown@@, 0xf8 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CUgcDownloadDown> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class CUgcDownloadDown : public CThread, public TSingleton<CUgcDownloadDown>
{
public:
    CUgcDownloadDown();                                     // 0x141874a40
    virtual ~CUgcDownloadDown();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0xf8 - 0x20];
};
MS2_CHECK_SIZE(CUgcDownloadDown, 0xf8);
