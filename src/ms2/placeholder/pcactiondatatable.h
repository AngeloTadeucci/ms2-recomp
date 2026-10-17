// pcactiondatatable.h - PLACEHOLDER for PCActionDataTable (RTTI .?AVPCActionDataTable@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<PCActionDataTable> at +0x0, DataTable<PCActionGroup> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/datatable.h"

class PCActionDataTable : public TSingleton<PCActionDataTable>, public DataTable<PCActionGroup>
{
public:
    PCActionDataTable();                                    // 0x140949170
    virtual ~PCActionDataTable();
};
MS2_CHECK_SIZE(PCActionDataTable, 0x60);
