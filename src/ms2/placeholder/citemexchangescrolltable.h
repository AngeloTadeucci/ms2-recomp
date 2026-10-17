// citemexchangescrolltable.h - PLACEHOLDER for CItemExchangeScrollTable (RTTI .?AVCItemExchangeScrollTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CItemExchangeScrollTable> at +0x0, CValidData<CItemExchangeScrollTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemExchangeScrollTable : public TSingleton<CItemExchangeScrollTable>,
                                 public CValidData<CItemExchangeScrollTable>
{
public:
    CItemExchangeScrollTable();                             // 0x1405950f0
    virtual ~CItemExchangeScrollTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CItemExchangeScrollTable, 0x58);
