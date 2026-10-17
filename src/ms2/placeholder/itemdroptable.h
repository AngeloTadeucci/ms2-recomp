// itemdroptable.h - PLACEHOLDER for ItemDropTable (RTTI .?AVItemDropTable@@, 0x110 bytes). NOT an original header.
// Bases: TSingleton<ItemDropTable> at +0x0, CValidData<ItemDropTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class ItemDropTable : public TSingleton<ItemDropTable>, public CValidData<ItemDropTable>
{
public:
    ItemDropTable();                                        // 0x1402e9940
    virtual ~ItemDropTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x110 - 0x10];
};
MS2_CHECK_SIZE(ItemDropTable, 0x110);
