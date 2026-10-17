// cstorybooktable.h - PLACEHOLDER for CStoryBookTable (RTTI .?AVCStoryBookTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CStoryBookTable> at +0x0, CValidData<CStoryBookTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CStoryBookTable : public TSingleton<CStoryBookTable>, public CValidData<CStoryBookTable>
{
public:
    CStoryBookTable();                                      // 0x14180bc30
    virtual ~CStoryBookTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CStoryBookTable, 0x58);
