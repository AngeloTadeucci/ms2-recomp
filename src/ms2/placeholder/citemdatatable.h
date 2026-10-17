// citemdatatable.h - PLACEHOLDER for CItemDataTable (RTTI .?AVCItemDataTable@@, 0x4f0 bytes). NOT an original header.
// Bases: CCacheData at +0x0, TSingleton<CItemDataTable> at +0x28, CValidData<CItemDataTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemDataTable : public CCacheData,
                       public TSingleton<CItemDataTable>,
                       public CValidData<CItemDataTable>
{
public:
    CItemDataTable();                                       // 0x140555ce0
    virtual ~CItemDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0x4f0 - 0x38];
};
MS2_CHECK_SIZE(CItemDataTable, 0x4f0);
