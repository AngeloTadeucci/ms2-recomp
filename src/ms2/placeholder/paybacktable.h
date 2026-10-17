// paybacktable.h - PLACEHOLDER for PaybackTable (RTTI .?AVPaybackTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<PaybackTable> at +0x0, CValidData<PaybackTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class PaybackTable : public TSingleton<PaybackTable>, public CValidData<PaybackTable>
{
public:
    PaybackTable();                                         // 0x14071af50
    virtual ~PaybackTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(PaybackTable, 0x40);
