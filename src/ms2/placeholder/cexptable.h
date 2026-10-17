// cexptable.h - PLACEHOLDER for CExpTable (RTTI .?AVCExpTable@@, 0x2450 bytes). NOT an original header.
// Bases: TSingleton<CExpTable> at +0x0, CValidData<CExpTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CExpTable : public TSingleton<CExpTable>, public CValidData<CExpTable>
{
public:
    CExpTable();                                            // 0x1403525e0
    virtual ~CExpTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x2450 - 0x10];
};
MS2_CHECK_SIZE(CExpTable, 0x2450);
