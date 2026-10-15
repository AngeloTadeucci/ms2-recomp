#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>
class CItem;
class NiAVObject;
struct Unk_CharEquip;   // tcreatecharinfo.h (0xc)

// Heap-only views. PC derives PCBase (ctor 14164dfd0), and FittingDollPC
// derives PC (ctor 14121b350). No constructors or vftables are emitted here.
// The additional PC virtual interface is not used by the cube guide wrappers;
// calls through these pointers use the inherited GameObject slots only.
// PC vftable 0x142f4ae28 (147 slots). Slots 124..132 are the first PC-introduced virtuals (PCBase ends at 123);
// types from the base bodies' register homing and the AvatarPC/ClonePC/MyPC overrides (sb2, work/sb2/pc_slots.txt).
// Out-of-line in the unrecovered PC unit: symbols-manual rows. Slots 133..146 appended by sb4 (work/sb4/pc_slots_133.txt:
// prologue homing + PC/ClonePC/MyPC/FittingDollPC/PortraitPC overrides). ClonePC (clonepc.h) adds 147..152.
class Unk_PCArg125;   // MS2Ptr<T> by value (MyPC override destroys it with 0x1409f74e0)
class Unk_PCArg126;   // MS2Ptr<T> by value (get 0x1409f7930, ICF generic dtor 0x1401bfde0)
class PC : public PCBase {
    EE_DECLARE_CLASS1(PC, 0x06200003, PCBase);   // ClassInfo 0x143ae2e20 (setup COMDAT 0x1409f8020 in avatarpc; sb4)
public:
    virtual ~PC();
    virtual int vfunc_124(int a, int b);                    // 124 0x141653840 (1/0; homes edx and r8d)
    virtual void vfunc_125(MS2Ptr<Unk_PCArg125> p);         // 125 0x141654900 (MyPC 0x141522d40)
    virtual void vfunc_126(MS2Ptr<Unk_PCArg126> p, int n);  // 126 0x141655230 (n == 0: p.get() + 0x430)
    virtual void vfunc_127(CItem* pItem, int n);            // 127 0x1416563c0 (MS2Ptr<CItem>(pItem) into +0xde0)
    virtual void vfunc_128(CItem* pItem, int n);            // 128 0x1416564a0
    virtual void vfunc_129(const CStringW& str);            // 129 0x141656ba0: +0xdc8 = str
    virtual void vfunc_130(CStringA str);                   // 130 0x141656c00: +0xdd0 = str (by value)
    virtual void vfunc_131(short n);                        // 131 0x141657820: word +0xddc = n
    virtual int vfunc_132(CItem* pItem, int n, bool b);     // 132 0x141657e20
    virtual int vfunc_133(CItem* pItem, bool b);            // 133 0x141657dc0: vfunc_132(pItem, pItem->FUN_140527a20(), b)
    virtual CStringW vfunc_134();                           // 134 0x141658cd0 (hidden return; PC: L"")
    virtual void vfunc_135(int a, int b, void* p);          // 135 0x141659450
    virtual void vfunc_136(void* a, void* b, float f);      // 136 0x14165c240 (xmm3)
    virtual int vfunc_137();                                // 137 0x14165d6d0
    virtual void vfunc_138(NiAVObject* pRoot, int n, const Unk_CharEquip* pEquip);  // 138 0x14165f050
    virtual void vfunc_139();                               // 139 0x14165efa0
    virtual void vfunc_140(int n);                          // 140 0x1416600c0
    virtual int vfunc_141();                                // 141 0x141660100
    virtual void vfunc_142();                               // 142 0x141660740 (AvatarPC 0x1409f52e0)
    virtual void vfunc_143();                               // 143 0x141660920 (ClonePC/PortraitPC override)
    virtual void vfunc_144();                               // 144 0x141660f80
    virtual int vfunc_145();                                // 145 0x141661be0: return 1 (ClonePC: 0)
    virtual bool vfunc_146();                               // 146 0x141662e50
    unsigned char unknownD40[0x5a0];
};
MS2_CHECK_SIZE(PC, 0x12e0); // deleting dtor 1416678b0

class FittingDollPC : public PC {
public:
    virtual ~FittingDollPC();
    void FUN_14121c170(NiFixedString parentName);
    int type, index, unknown12e8;
    void* unknown12f0;
    NiFixedString parentName;
};
MS2_CHECK_SIZE(FittingDollPC, 0x1300); // deleting dtor 14121cca0
MS2_CHECK_OFFSET(FittingDollPC, parentName, 0x12f8);
