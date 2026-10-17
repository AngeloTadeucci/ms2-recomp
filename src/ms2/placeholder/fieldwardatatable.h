// fieldwardatatable.h - PLACEHOLDER for FieldWarDataTable (RTTI .?AVFieldWarDataTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<FieldWarDataTable> at +0x0, CValidData<FieldWarDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class FieldWarDataTable : public TSingleton<FieldWarDataTable>, public CValidData<FieldWarDataTable>
{
public:
    FieldWarDataTable();                                    // 0x1403825b0
    virtual ~FieldWarDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(FieldWarDataTable, 0x40);
