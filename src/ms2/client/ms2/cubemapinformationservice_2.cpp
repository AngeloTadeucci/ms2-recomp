// Cube palette selection and paging. Recovered from KMS2_DEV x64, 2022-04-13.
// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#2
// MS2-RANGE: 0x1410b4e80-0x1410b68a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??4?$MS2Ptr@VCubeItemInfo@@@@QEAAAEAV0@AEBV0@@Z 0x1410b6490 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VUGCCube@UGCCubePalette@@@@V?$CElementTraits@V?$MS2Ptr@VUGCCube@UGCCubePalette@@@@@ATL@@@ATL@@QEBA_NXZ 0x1410b6640 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#if defined(__clang__)
// The original SDK uses the pre-C++17 register keyword.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister"
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_2.h"
#include "inventory.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

extern Unk_Inventory DAT_143ab2a90;
class Unk_CubeFallbackInventory {
public: MS2Ptr<CItem> FUN_1408fbf90(__int64);
};
extern Unk_CubeFallbackInventory DAT_143ab2e20;
class PCBase;
class Unk_CubeCraftCore;
void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void*);
int FUN_1416595d0(PCBase*);
Unk_CubeCraftCore* FUN_141530290(PCBase*);
int FUN_1410a8a90(Unk_CubeCraftCore*);
class UIUGCCubePaletteDialog;
UIUGCCubePaletteDialog* FUN_140ef4a50(int);
void FUN_140eef560(UIUGCCubePaletteDialog*,int);

// @0x1410b4e80
CubeHolderManager::CubeHolderManager() : palette(0),selected(0) {}
// @0x1410b4f00
CubeHolderManager::~CubeHolderManager() {}

// Constructs a local RTTI object; not hooked.
// @0x1410b4f60
void CubeHolderManager::FUN_1410b4f60(const Unk_CubePaletteFilter& filter) {
    if(palette==0) palette.AssignRaw(new UGCCubePalette);
    cubes.RemoveAll();
    palette->FUN_140df1a40(cubes,filter);
}
// @0x1410b5030
bool CubeHolderManager::FUN_1410b5030(CubeArray& out) {
    for(unsigned i=0;i<cubes.GetCount();++i) out.Add(cubes[i]);
    return !cubes.IsEmpty();
}
MS2_REPLACE_METHOD(0x1410B5030, CubeHolderManager, FUN_1410b5030, 153, 0xA3D8AD39);
// MS2-FUNCTIONAL: equivalent scoped selection; original /Od locals differ.
// Calls the palette factory above; not hooked.
// @0x1410b50d0
int CubeHolderManager::FUN_1410b50d0(MS2Ptr<CubeItemInfo>& out) {
    selected=0;
    if(cubes.IsEmpty()) { Unk_CubePaletteFilter filter;FUN_1410b4f60(filter); }
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube!=0 && FUN_1410b5f10(cube->FUN_140def5a0())!=0) {
            out=cube->FUN_140def3d0();selected=cube;return 1;
        }
    }
    return 0;
}
// MS2-FUNCTIONAL: typed cube records preserve both identity comparisons and selection order.
// @0x1410b5280
void CubeHolderManager::FUN_1410b5280(MS2Ptr<CubeItemInfo> info) {
    selected=FUN_1410b5a70(info->instanceId);
    if(selected==0) {
        for(unsigned i=0;i<cubes.GetCount();++i) {
            CubePtr cube=cubes[i];
            if(cube!=0 && cube->FUN_140def5a0()==info->itemId && cube->FUN_140def5f0()==info->instanceId) {
                selected=cube;break;
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1410B5280, CubeHolderManager, FUN_1410b5280, 453, 0xEBE0474B);
// @0x1410b5460
void CubeHolderManager::FUN_1410b5460(int itemId) { selected=FUN_1410b5930(itemId); }
// @0x1410b54d0
void CubeHolderManager::FUN_1410b54d0(__int64 instanceId) { selected=FUN_1410b5a70(instanceId); }
MS2_REPLACE_METHOD(0x1410B5460, CubeHolderManager, FUN_1410b5460, 95, 0x0111D5C6);
// @0x1410b5540
void CubeHolderManager::FUN_1410b5540(int index) { selected=FUN_1410b57f0(index); }
MS2_REPLACE_METHOD(0x1410B54D0, CubeHolderManager, FUN_1410b54d0, 96, 0x00C47404);
// @0x1410b55b0
MS2Ptr<CubeItemInfo> CubeHolderManager::FUN_1410b55b0() {
    if(selected.get()==0) return MS2Ptr<CubeItemInfo>(0);
    return selected->FUN_140def3d0();
}
MS2_REPLACE_METHOD(0x1410B5540, CubeHolderManager, FUN_1410b5540, 95, 0x3B066F7B);
MS2_REPLACE_METHOD(0x1410B55B0, CubeHolderManager, FUN_1410b55b0, 125, 0xB63FE91C);
// @0x1410b5640
MS2Ptr<CubeItemInfo> CubeHolderManager::FUN_1410b5640(int index) {
    CubePtr cube=FUN_1410b57f0(index);
    if(cube.get()==0) return MS2Ptr<CubeItemInfo>(0);
    return cube->FUN_140def3d0();
}
MS2_REPLACE_METHOD(0x1410B5640, CubeHolderManager, FUN_1410b5640, 166, 0xB1C66128);
// @0x1410b56f0
MS2Ptr<CubeItemInfo> CubeHolderManager::FUN_1410b56f0(__int64 instanceId) {
    CubePtr cube=FUN_1410b5a70(instanceId);
    if(cube.get()==0) return MS2Ptr<CubeItemInfo>(0);
    return cube->FUN_140def3d0();
}
MS2_REPLACE_METHOD(0x1410B56F0, CubeHolderManager, FUN_1410b56f0, 166, 0xCC45B9C2);
// @0x1410b57a0
CubeHolderManager::CubePtr CubeHolderManager::FUN_1410b57a0() { return selected; }
// MS2-FUNCTIONAL: explicit move preserves the original stealing return constructor.
// @0x1410b57f0
CubeHolderManager::CubePtr CubeHolderManager::FUN_1410b57f0(int index) {
    if(index==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube!=0 && cube->FUN_140defff0()==index) return std::move(cube);
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B57A0, CubeHolderManager, FUN_1410b57a0, 65, 0xEB612B86);
MS2_REPLACE_METHOD(0x1410B57F0, CubeHolderManager, FUN_1410b57f0, 313, 0xD8172207);
// MS2-FUNCTIONAL: explicit move preserves the original stealing return constructor.
// @0x1410b5930
CubeHolderManager::CubePtr CubeHolderManager::FUN_1410b5930(int itemId) {
    if(itemId==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube!=0 && cube->FUN_140def5a0()==itemId) return std::move(cube);
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B5930, CubeHolderManager, FUN_1410b5930, 313, 0x7616A57C);
// MS2-FUNCTIONAL: explicit move preserves the original stealing return constructor.
// @0x1410b5a70
CubeHolderManager::CubePtr CubeHolderManager::FUN_1410b5a70(__int64 instanceId) {
    if(instanceId==0) return CubePtr(0);
    for(unsigned i=0;i<cubes.GetCount();++i) {
        CubePtr cube=cubes[i];
        if(cube!=0 && cube->FUN_140def5f0()==instanceId) return std::move(cube);
    }
    return CubePtr(0);
}
MS2_REPLACE_METHOD(0x1410B5A70, CubeHolderManager, FUN_1410b5a70, 315, 0xDAAB77E4);
// @0x1410b5bc0
int CubeHolderManager::FUN_1410b5bc0() {
    if(selected!=0) return selected->FUN_140def3d0()->itemId;
    return 0;
}
MS2_REPLACE_METHOD(0x1410B5BC0, CubeHolderManager, FUN_1410b5bc0, 129, 0x271D420E);
// @0x1410b5c50
int CubeHolderManager::FUN_1410b5c50(int index) {
    CubePtr cube=FUN_1410b57f0(index);
    if(cube!=0) return cube->FUN_140def5a0();
    return 0;
}
MS2_REPLACE_METHOD(0x1410B5C50, CubeHolderManager, FUN_1410b5c50, 127, 0x04DC8125);
// MS2-FUNCTIONAL: unsigned paging arithmetic and truncation preserved.
// @0x1410b5ce0
unsigned CubeHolderManager::FUN_1410b5ce0() {
    int index=FUN_1410b5d70();
    if(index==0) return 0;
    unsigned page=(static_cast<unsigned>(index)-1)/10;
    unsigned last=static_cast<unsigned>((cubes.GetCount()-1)/10);
    if(last<page) page=last;
    return page;
}
MS2_REPLACE_METHOD(0x1410B5CE0, CubeHolderManager, FUN_1410b5ce0, 124, 0x63B03BF7);
// @0x1410b5d70
int CubeHolderManager::FUN_1410b5d70() {
    if(selected!=0) return selected->FUN_140defff0();
    return 0;
}
MS2_REPLACE_METHOD(0x1410B5D70, CubeHolderManager, FUN_1410b5d70, 69, 0xA29D55F1);
// @0x1410b5dc0
MS2Ptr<CItem> CubeHolderManager::FUN_1410b5dc0(__int64 instanceId) {
    MS2Ptr<CItem> item=DAT_143ab2a90.FUN_140a5d680(instanceId);
    if(item.get()==0) return DAT_143ab2e20.FUN_1408fbf90(instanceId);
    return std::move(item);
}
MS2_REPLACE_METHOD(0x1410B5DC0, CubeHolderManager, FUN_1410b5dc0, 170, 0xC00EE4A8);
// @0x1410b5e70
int CubeHolderManager::FUN_1410b5e70() {
    PCBase* pc=FUN_141bd0cc0(FUN_1403ed2d0());
    if(pc==0) return 0;
    return FUN_1416595d0(pc);
}
MS2_REPLACE_METHOD(0x1410B5E70, CubeHolderManager, FUN_1410b5e70, 54, 0x2F3817D5);
// @0x1410b5eb0
int CubeHolderManager::FUN_1410b5eb0() {
    PCBase* pc=FUN_141bd0cc0(FUN_1403ed2d0());
    if(pc==0) return 0;
    Unk_CubeCraftCore* craft=FUN_141530290(pc);
    if(craft==0) return 0;
    return FUN_1410a8a90(craft);
}
MS2_REPLACE_METHOD(0x1410B5EB0, CubeHolderManager, FUN_1410b5eb0, 81, 0x1BD6028B);
// @0x1410b6210
void CubeHolderManager::FUN_1410b6210() {
    unsigned page=FUN_1410b5ce0();
    if(page!=0) FUN_1410b6340((page-1)*10+1);
}
MS2_REPLACE_METHOD(0x1410B6210, CubeHolderManager, FUN_1410b6210, 64, 0x5214C64F);
// MS2-FUNCTIONAL: preserves unsigned size_t subtraction before dividing the last page.
// @0x1410b6260
void CubeHolderManager::FUN_1410b6260() {
    unsigned page=FUN_1410b5ce0();
    if(page<static_cast<unsigned>((cubes.GetCount()-1)/10)) FUN_1410b6340((page+1)*10+1);
}
MS2_REPLACE_METHOD(0x1410B6260, CubeHolderManager, FUN_1410b6260, 101, 0xEA5CE1E2);
// @0x1410b62d0
void CubeHolderManager::FUN_1410b62d0() {
    unsigned next=static_cast<unsigned>(FUN_1410b5d70())+1;
    if(cubes.GetCount()<next) FUN_1410b6340(1);
    else FUN_1410b6340(next);
}
MS2_REPLACE_METHOD(0x1410B62D0, CubeHolderManager, FUN_1410b62d0, 94, 0xEFE7B3D8);
// @0x1410b6340
void CubeHolderManager::FUN_1410b6340(int index) {
    UIUGCCubePaletteDialog* dialog=FUN_140ef4a50(0x4f16);
    if(dialog!=0) FUN_140eef560(dialog,index);
}
MS2_REPLACE_METHOD(0x1410B6340, CubeHolderManager, FUN_1410b6340, 55, 0x4EA4BF9E);
MS2_EMIT_CRT_MEMMOVE_S();
