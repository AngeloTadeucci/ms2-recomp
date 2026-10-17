// crankingarenadatatable.h - PLACEHOLDER for CRankingArenaDataTable (RTTI .?AVCRankingArenaDataTable@@, 0x1d0 bytes). NOT an original header.
// Bases: TSingleton<CRankingArenaDataTable> at +0x0, CValidData<CRankingArenaDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CRankingArenaDataTable : public TSingleton<CRankingArenaDataTable>,
                               public CValidData<CRankingArenaDataTable>
{
public:
    CRankingArenaDataTable();                               // 0x140768b80
    virtual ~CRankingArenaDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x1d0 - 0x10];
};
MS2_CHECK_SIZE(CRankingArenaDataTable, 0x1d0);
