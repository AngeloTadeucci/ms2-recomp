// cugcgetcosttable.h - PLACEHOLDER for CUgcGetCostTable (RTTI .?AVCUgcGetCostTable@@, 0x68 bytes). NOT an original header.
// Bases: TSingleton<CUgcGetCostTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CUgcGetCostTable : public TSingleton<CUgcGetCostTable>
{
public:
    CUgcGetCostTable();                                     // 0x140898000
    virtual ~CUgcGetCostTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x68 - 0x8];
};
MS2_CHECK_SIZE(CUgcGetCostTable, 0x68);
