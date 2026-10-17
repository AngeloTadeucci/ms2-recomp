// citemenchantlimittable.h - PLACEHOLDER for CItemEnchantLimitTable (RTTI .?AVCItemEnchantLimitTable@@, 0x58 bytes). NOT an original header.
// Bases: TSingleton<CItemEnchantLimitTable> at +0x0, CValidData<CItemEnchantLimitTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CItemEnchantLimitTable : public TSingleton<CItemEnchantLimitTable>,
                               public CValidData<CItemEnchantLimitTable>
{
public:
    CItemEnchantLimitTable();                               // 0x14058db50
    virtual ~CItemEnchantLimitTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x58 - 0x10];
};
MS2_CHECK_SIZE(CItemEnchantLimitTable, 0x58);
