// cseasondatatable.h - PLACEHOLDER for CSeasonDataTable (RTTI .?AVCSeasonDataTable@@, 0x148 bytes). NOT an original header.
// Bases: TSingleton<CSeasonDataTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CSeasonDataTable : public TSingleton<CSeasonDataTable>
{
public:
    CSeasonDataTable();                                     // 0x140791740
    virtual ~CSeasonDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x148 - 0x8];
};
MS2_CHECK_SIZE(CSeasonDataTable, 0x148);
