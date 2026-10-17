// cstringtable.h - PLACEHOLDER for CStringTable (RTTI .?AVCStringTable@@, 0x2a0 bytes). NOT an original header.
// Bases: TSingleton<CStringTable> at +0x0, CValidData<CStringTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CStringTable : public TSingleton<CStringTable>, public CValidData<CStringTable>
{
public:
    CStringTable();                                         // 0x141810bf0
    virtual ~CStringTable();
    CStringW FUN_141811980(int nTable, int nId);            // the string of a table row
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x2a0 - 0x10];
};
MS2_CHECK_SIZE(CStringTable, 0x2a0);
