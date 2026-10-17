// cinstrumentdatatable.h - PLACEHOLDER for CInstrumentDataTable (RTTI .?AVCInstrumentDataTable@@, 0xa0 bytes). NOT an original header.
// Bases: TSingleton<CInstrumentDataTable> at +0x0, CValidData<CInstrumentDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CInstrumentDataTable : public TSingleton<CInstrumentDataTable>, public CValidData<CInstrumentDataTable>
{
public:
    CInstrumentDataTable();                                 // 0x14072c520
    virtual ~CInstrumentDataTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0xa0 - 0x10];
};
MS2_CHECK_SIZE(CInstrumentDataTable, 0xa0);
