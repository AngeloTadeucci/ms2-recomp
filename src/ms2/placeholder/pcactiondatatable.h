// pcactiondatatable.h - PLACEHOLDER for PCActionDataTable (RTTI .?AVPCActionDataTable@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<PCActionDataTable> at +0x0, DataTable<PCActionGroup> at +0x8 (0x38 bytes: vftable + lock).
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members past the
// DataTable (+0x40..0x60) are not recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/datatable.h"

class PCActionGroup : public CPtred {};

class PCActionDataTable : public TSingleton<PCActionDataTable>, public DataTable<PCActionGroup>
{
public:
    PCActionDataTable();                                    // 0x140949170
    virtual ~PCActionDataTable();
    void Add(MS2Ptr<PCActionGroup> spRow);                  // not defined here (the unit is not recovered)
    MS2Ptr<PCActionGroup> Create(Unk_140165cf0* pNode);
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_40[0x60 - 0x40];
};
MS2_CHECK_SIZE(PCActionDataTable, 0x60);
