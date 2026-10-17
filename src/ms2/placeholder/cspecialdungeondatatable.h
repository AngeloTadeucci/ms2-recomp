// cspecialdungeondatatable.h - PLACEHOLDER for CSpecialDungeonDataTable (RTTI .?AVCSpecialDungeonDataTable@@, 0x10 bytes). NOT an original header.
// Bases: TSingleton<CSpecialDungeonDataTable> at +0x0, CValidData<CSpecialDungeonDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CSpecialDungeonDataTable : public TSingleton<CSpecialDungeonDataTable>,
                                 public CValidData<CSpecialDungeonDataTable>
{
public:
    // @0x141496150
    CSpecialDungeonDataTable() {}
    // @0x1414975d0
    virtual ~CSpecialDungeonDataTable() {}
};
MS2_CHECK_SIZE(CSpecialDungeonDataTable, 0x10);
