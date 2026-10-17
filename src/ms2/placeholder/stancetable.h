// stancetable.h - PLACEHOLDER for StanceTable (RTTI .?AVStanceTable@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<StanceTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class StanceTable : public TSingleton<StanceTable>
{
public:
    StanceTable();                                          // 0x140829650
    virtual ~StanceTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(StanceTable, 0x38);
