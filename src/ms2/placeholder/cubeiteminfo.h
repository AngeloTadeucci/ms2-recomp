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
    CString FUN_140892ec0();                // 0x140892ec0 the name as an ansi string (ugccubepalette.cpp)
    __int64 ugcId;
    CString name;
    CStringW title;
    int unknown30, unknown34;
    __int64 unknown38, unknown40;
    CStringW description;
    __int64 unknown50;
    CString resourcePath;
    int unknown60;                          // +0x60 (scenestategame 0x14173b220 sets it from the packet)
    int unknown64;
};
MS2_CHECK_SIZE(CUgcItemLook, 0x68);
MS2_CHECK_OFFSET(CUgcItemLook, resourcePath, 0x58);

class CInPacket;
class CubeItemInfo : public CPtred {
public:
    CubeItemInfo();
    CubeItemInfo(const CubeItemInfo& src);                                              // 0x1408b34b0
    CubeItemInfo(int itemId, __int64 instanceId, __int64 count, CUgcItemLook* pLook);   // 0x1408b3520
    CubeItemInfo(CInPacket& packet);                                                     // 0x1408b3630 (reads the item)
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
