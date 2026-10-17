// citemrepackingscrolltable.h - PLACEHOLDER for CItemRePackingScrollTable (RTTI .?AVCItemRePackingScrollTable@@, 0xb0 bytes). NOT an original header.
// Bases: TSingleton<CItemRePackingScrollTable> at +0x0, CCacheData at +0x8, CValidData<CItemRePackingScrollTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemRePackingScrollTable : public TSingleton<CItemRePackingScrollTable>,
                                  public CCacheData,
                                  public CValidData<CItemRePackingScrollTable>
{
public:
    CItemRePackingScrollTable();                            // 0x14061cfa0
    virtual ~CItemRePackingScrollTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0xb0 - 0x38];
};
MS2_CHECK_SIZE(CItemRePackingScrollTable, 0xb0);
