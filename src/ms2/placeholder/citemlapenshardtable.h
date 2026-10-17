// citemlapenshardtable.h - PLACEHOLDER for CItemLapenshardTable (RTTI .?AVCItemLapenshardTable@@, 0x1b8 bytes). NOT an original header.
// Bases: TSingleton<CItemLapenshardTable> at +0x0, CCacheData at +0x8, CValidData<CItemLapenshardTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemLapenshardTable : public TSingleton<CItemLapenshardTable>,
                             public CCacheData,
                             public CValidData<CItemLapenshardTable>
{
public:
    CItemLapenshardTable();                                 // 0x1405b44b0
    virtual ~CItemLapenshardTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0x1b8 - 0x38];
};
MS2_CHECK_SIZE(CItemLapenshardTable, 0x1b8);
