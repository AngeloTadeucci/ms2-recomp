// citemloader.h - PLACEHOLDER for CItemLoader (RTTI .?AVCItemLoader@@, 0x58 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CItemLoader> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

class CItemLoader : public CThread, public TSingleton<CItemLoader>
{
public:
    CItemLoader();                                          // 0x140d317a0
    virtual ~CItemLoader();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x58 - 0x20];
};
MS2_CHECK_SIZE(CItemLoader, 0x58);
