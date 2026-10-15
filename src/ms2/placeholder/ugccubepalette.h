// Heap-only palette records, from 140df19b0/140def070 and their deleting destructors.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citemdata.h"

struct Unk_CubePaletteFilter {
    Unk_CubePaletteFilter(); // 140df0030
    ~Unk_CubePaletteFilter(); // 140ef04a0
    bool includeOwned,flag1,flag2;
    int category;
    CStringW text;
    int field10,field14,field18;
};
MS2_CHECK_SIZE(Unk_CubePaletteFilter,0x20);
MS2_CHECK_OFFSET(Unk_CubePaletteFilter,text,8);

class UGCCubePalette : public CPtred {
public:
    class UGCCube : public CPtred {
    public:
        virtual ~UGCCube();
        MS2Ptr<CubeItemInfo> FUN_140def3d0();
        int FUN_140def5a0();
        __int64 FUN_140def5f0();
        int FUN_140defff0();
        int index;
        MS2Ptr<CItemData> itemData;
        void* unknown30;void* unknown38;
        MS2Ptr<CubeItemInfo> info;
    };
    typedef MS2Ptr<UGCCube> CubePtr;
    typedef ATL::CAtlArray<CubePtr> CubeArray;
    UGCCubePalette();
    virtual ~UGCCubePalette();
    unsigned FUN_140df1a40(CubeArray& out,const Unk_CubePaletteFilter& filter);
private:
    // CAtlMap-owned storage, not inspected by this unit.
    void* unknown18;void* unknown20;void* unknown28;
    void* unknown30;void* unknown38;void* unknown40;
    void* unknown48;void* unknown50;void* unknown58;
};
MS2_CHECK_SIZE(UGCCubePalette,0x60);
MS2_CHECK_SIZE(UGCCubePalette::UGCCube,0x50);
MS2_CHECK_OFFSET(UGCCubePalette::UGCCube,itemData,0x20);
MS2_CHECK_OFFSET(UGCCubePalette::UGCCube,info,0x40);
