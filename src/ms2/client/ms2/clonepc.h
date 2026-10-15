// clonepc.h - ClonePC (RTTI "ClonePC"): a PC that mirrors another PC's look for a UI model view (the "Mannequin").
// Base of AvatarPC (?\avatarpc.cpp) and PortraitPC (?\portraitpc.cpp), which put their listener base
// (IAvatarObjectEventListener / UIItemEventListener) at +0x1340. Owning unit: ?\clonepc.cpp (0x141086ae0-0x14108e1e0,
// not recovered). Header name assumed. Heap-only.
//
// Size 0x1340 (??_G 0x14108bbf0 frees 0x1340). vftable 0x142ea7b80 (153 slots: PC's 147 + 147..152), CallbackObject
// vftable 0x142ea8050 (dtor thunk 0x14108bb58). efd: TypeCast 0x14108c2b0 / 0x14108c260, GetClassDesc 0x14108be60.
// Ctor 0x141087420 (homes rcx/rdx only; calls PC::PC(this) 0x14164dfd0), dtor 0x141086ae0.
// Overrides (out of line in clonepc.cpp): 9 0x141086b70, 12 0x1410875f0, 14 0x1410876b0, 26 0x141086e60 (return 0),
// 49 0x141086cb0 (empty), 55 0x141087cd0 / 56 0x141087c90 (gated on m_b12fa), 68 0x141086ea0 (return false),
// 80/82/83/85/86/87 0x141086ce0/d20/d60/da0/de0/e20 (null MS2Ptr), 88 0x141086e70 (0), 93 0x141087290 (empty),
// 133 0x141086e80 (0), 139 0x141086c30, 143 0x141086cc0 (PC::vfunc_143), 145 0x1410872a0 (0).
// Only the overrides a derived unit needs are declared below; vfunc_24's COMDAT (0x1409f7f40) is in avatarpc.
#pragma once
#include <efd/List.h>
#include "ms2/placeholder/fittingdollpc.h"

class UIModelView;   // NiRefObject-derived (UIRenderView); smart pointer COMDATs: ctor 0x14108aea0, dtor 0x140cb1460
class NiAVObject;

class ClonePC : public PC
{
    EE_DECLARE_CLASS1(ClonePC, 0x0620004f, PC);   // ClassInfo 0x143acdbc0 (setup COMDAT 0x1409f7fc0 in avatarpc)

public:
    ClonePC(PC* pSource);                                   // 0x141087420 m_pSourcePC = pSource; copies its id
    virtual ~ClonePC();                                     // 0x141086ae0

    // @0x1409f7f40
    virtual void vfunc_24(int) { m_unk_40 = 0; }            // 24 (inline; COMDAT in avatarpc)
    // new virtuals
    virtual void vfunc_147(UIModelView* pView);             // 147 0x141086bc0 m_spModelView = pView
    virtual UIModelView* vfunc_148();                       // 148 0x141086c00
    virtual void vfunc_149();                               // 149 0x141086ec0 (PortraitPC 0x141699d60)
    virtual int vfunc_150();                                // 150 0x141087280 return 0
    virtual void vfunc_151();                               // 151 0x141087d20
    // pList: CAtlList of equip smart pointers; pEquip: 0x1416561a0(m_pSourcePC)'s result. Types unproven.
    virtual void vfunc_152(void* pList, void* pEquip);      // 152 0x1410884f0

public:
    MS2_LAYOUT_FRIEND;
    PC* m_pSourcePC;                                        // +0x12e0 ctor argument
    int m_nSourceId;                                        // +0x12e8 m_pSourcePC->FUN_14123c580()
    efd::SmartPointer<UIModelView> m_spModelView;           // +0x12f0
    bool m_b12f8;                                           // +0x12f8 = 0
    bool m_b12f9;                                           // +0x12f9 = 0
    bool m_b12fa;                                           // +0x12fa = 0 (gates vfunc_55/56)
    bool m_b12fb;                                           // +0x12fb = 1
    int m_unk_12fc;                                         // +0x12fc = 1
    efd::list<NiAVObject*> m_kList1300;                     // +0x1300 (ctor 0x141043710, dtor 0x141043950)
    void* m_pOwned1310;                                     // +0x1310 owned polymorphic object (dtor 0x14108b370 deletes it)
    int m_unk_1318[2];                                      // +0x1318 8-byte timer value (ctor 0x140517b00 zeroes it)
    void* m_unk_1320[3];                                    // +0x1320 std::vector<?> (ctor 0x14108b300, dtor 0x14108b4c0)
    bool m_b1338;                                           // +0x1338 = 0
};
MS2_CHECK_SIZE(ClonePC, 0x1340);
MS2_CHECK_OFFSET(ClonePC, m_pSourcePC, 0x12e0);
MS2_CHECK_OFFSET(ClonePC, m_spModelView, 0x12f0);
MS2_CHECK_OFFSET(ClonePC, m_b12fa, 0x12fa);
MS2_CHECK_OFFSET(ClonePC, m_unk_12fc, 0x12fc);
MS2_CHECK_OFFSET(ClonePC, m_kList1300, 0x1300);
MS2_CHECK_OFFSET(ClonePC, m_pOwned1310, 0x1310);
MS2_CHECK_OFFSET(ClonePC, m_unk_1320, 0x1320);
MS2_CHECK_OFFSET(ClonePC, m_b1338, 0x1338);
