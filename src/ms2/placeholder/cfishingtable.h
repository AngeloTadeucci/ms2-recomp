// cfishingtable.h - PLACEHOLDER for CFishingTable (RTTI .?AVCFishingTable@@, 0x130 bytes). NOT an original header.
// Bases: TSingleton<CFishingTable> at +0x0, CValidData<CFishingTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CFishingTable : public TSingleton<CFishingTable>, public CValidData<CFishingTable>
{
public:
    CFishingTable();                                        // 0x1403b1d00
    virtual ~CFishingTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x130 - 0x10];
};
MS2_CHECK_SIZE(CFishingTable, 0x130);
