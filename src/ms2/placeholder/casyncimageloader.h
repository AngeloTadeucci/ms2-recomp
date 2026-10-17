// casyncimageloader.h - PLACEHOLDER for CAsyncImageLoader (RTTI .?AVCAsyncImageLoader@@, 0x98 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CAsyncImageLoader> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class CAsyncImageLoader : public CThread, public TSingleton<CAsyncImageLoader>
{
public:
    CAsyncImageLoader();                                    // 0x140a58820
    virtual ~CAsyncImageLoader();
    void FUN_140a58b90();                                    // starts the loader thread
    void FUN_140a58b10();                                    // stops it
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x98 - 0x20];
};
MS2_CHECK_SIZE(CAsyncImageLoader, 0x98);
