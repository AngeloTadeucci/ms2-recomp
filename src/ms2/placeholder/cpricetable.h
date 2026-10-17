// cpricetable.h - PLACEHOLDER for CPriceTable (RTTI .?AVCPriceTable@@, 0xc8 bytes). NOT an original header.
// Bases: CCacheData at +0x0, TSingleton<CPriceTable> at +0x28, CValidData<CPriceTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CPriceTable : public CCacheData, public TSingleton<CPriceTable>, public CValidData<CPriceTable>
{
public:
    CPriceTable();                                          // 0x140738aa0
    virtual ~CPriceTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0xc8 - 0x38];
};
MS2_CHECK_SIZE(CPriceTable, 0xc8);
