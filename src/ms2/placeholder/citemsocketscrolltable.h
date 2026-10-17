// citemsocketscrolltable.h - PLACEHOLDER for CItemSocketScrollTable (RTTI .?AVCItemSocketScrollTable@@, 0xb0 bytes). NOT an original header.
// Bases: TSingleton<CItemSocketScrollTable> at +0x0, CCacheData at +0x8, CValidData<CItemSocketScrollTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemSocketScrollTable : public TSingleton<CItemSocketScrollTable>,
                               public CCacheData,
                               public CValidData<CItemSocketScrollTable>
{
public:
    CItemSocketScrollTable();                               // 0x140624b30
    virtual ~CItemSocketScrollTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0xb0 - 0x38];
};
MS2_CHECK_SIZE(CItemSocketScrollTable, 0xb0);
