#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

// Heap layouts: CUgcItemLook ctor 140892b50 and deleting dtor;
// CubeItemInfo ctor 1408b3450, Clear 1408b3810 and Copy 1408b3700.
class CUgcItemLook : public CPtred {
public:
    CUgcItemLook();
    virtual ~CUgcItemLook();
    __int64 ugcId;
    CString name;
    CStringW title;
    int unknown30, unknown34;
    __int64 unknown38, unknown40;
    CStringW description;
    __int64 unknown50;
    CString resourcePath;
    __int64 unknown60;
};
MS2_CHECK_SIZE(CUgcItemLook, 0x68);
MS2_CHECK_OFFSET(CUgcItemLook, resourcePath, 0x58);

class CubeItemInfo : public CPtred {
public:
    CubeItemInfo();
    virtual ~CubeItemInfo();
    void FUN_1408b3700(const CubeItemInfo*);
    int FUN_1408b3860();
    int itemId;
    __int64 instanceId;
    int count;
    MS2Ptr<CUgcItemLook> look;
};
MS2_CHECK_SIZE(CubeItemInfo, 0x40);
MS2_CHECK_OFFSET(CubeItemInfo, look, 0x30);
