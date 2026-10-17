// weddingtable.h - PLACEHOLDER for WeddingTable (RTTI .?AVWeddingTable@@, 0x60 bytes). NOT an original header.
// Bases: TSingleton<WeddingTable> at +0x0, CValidData<WeddingTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class WeddingTable : public TSingleton<WeddingTable>, public CValidData<WeddingTable>
{
public:
    WeddingTable();                                         // 0x140907bd0
    virtual ~WeddingTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x60 - 0x10];
};
MS2_CHECK_SIZE(WeddingTable, 0x60);
