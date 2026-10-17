// cnpcshopproductbase.h - CNpcShopProductBase (client npcshopproductbase.cpp), an NPC shop product slot. NOT an
// original header: only the members read outside its unit (gameeventcontext.cpp's give-point event) are named.
#pragma once
#include "ms2/placeholder/cptred.h"

class CNpcShopProductBase : public CPtred {
public:
    __int64 FUN_140db8180();        // 0x140db8180 price (+0xa0)
    char m_pad_18[0x88 - 0x18];
    int m_currencyType;             // +0x88 (a byte on the wire)
    char m_pad_8c[0xbc - 0x8c];
    int m_label;                    // +0xbc (a byte on the wire; 3 takes the special give-point percent)
};
