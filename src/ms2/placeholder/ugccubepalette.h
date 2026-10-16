// Heap-only palette records, from 140df19b0/140def070 and their deleting destructors.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cubeiteminfo.h"
#include "ms2/placeholder/citemdata.h"

struct Unk_CubePaletteFilter {
    Unk_CubePaletteFilter(); // 140df0030
    ~Unk_CubePaletteFilter(); // 140ef04a0
    bool FUN_140df00d0();                                                         // 0x140df00d0 (uiugccubepalettedialog.cpp)
    void FUN_140df0140(int);                                                      // 0x140df0140
    void FUN_140df0180(int);                                                      // 0x140df0180
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
        // uiugccubepalettedialog.cpp
        __int64 FUN_140defba0();
        int FUN_140def420();
        __int64 FUN_140def620();
        __int64 FUN_140def6c0();
        CStringW FUN_140def710();
        CStringW FUN_140def880();
        CStringW FUN_140defd20();
        int FUN_140defcd0();
        int FUN_140defe70();
        int FUN_140defed0();
        int FUN_140def4f0();
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
    // uiugccubepalettedialog.cpp
    CubePtr FUN_1410b57f0(int);
    CubePtr FUN_1410b57a0();
    CubePtr FUN_1410b5930(int);
    CubePtr FUN_1410b5a70(unsigned __int64);
    MS2Ptr<CubeItemInfo> FUN_1410b55b0();
    void FUN_1410b54d0(unsigned __int64);
    void FUN_1410b5030(CubeArray&);
    void FUN_1410b4f60(Unk_CubePaletteFilter*);
    int FUN_1410b5460(int);
    int FUN_1410b5d70();
    int FUN_1410b6060(int);
    int FUN_1410b5bc0();
    void FUN_1410b6210();
    void FUN_1410b6260();
    void FUN_1410b62d0();
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
