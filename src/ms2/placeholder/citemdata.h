// CItemData, RTTI and 0x390 allocation/layout from itemdata.cpp.
// Heap-only placeholder: inventory reads stack limit and function metadata.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/cobjectcount.h"
class CItemData : public CPtred, public CValidData<CItemData>, public CObjectCount<CItemData> {
public:
    virtual ~CItemData();
    unsigned char unknown20[0x68];
    unsigned stackLimit;
    unsigned char unknown8c[0x204];
    CStringW functionName;
    CStringW functionName2;
    int functionArg0, functionArg1, functionArg2;
    int unknown2ac;
    CStringW functionParameter;
    unsigned char unknown2b8[0xd8];
};
MS2_CHECK_SIZE(CItemData, 0x390);
MS2_CHECK_OFFSET(CItemData, stackLimit, 0x88);
MS2_CHECK_OFFSET(CItemData, functionName, 0x290);
MS2_CHECK_OFFSET(CItemData, functionParameter, 0x2b0);
