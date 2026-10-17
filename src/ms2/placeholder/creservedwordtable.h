// creservedwordtable.h - PLACEHOLDER for CReservedWordTable (RTTI .?AVCReservedWordTable@@, 0x170 bytes). NOT an original header.
// Bases: TSingleton<CReservedWordTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CReservedWordTable : public TSingleton<CReservedWordTable>
{
public:
    CReservedWordTable();                                   // 0x1416fa4b0
    virtual ~CReservedWordTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x170 - 0x8];
};
MS2_CHECK_SIZE(CReservedWordTable, 0x170);
