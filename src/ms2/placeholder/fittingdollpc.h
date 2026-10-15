#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>
class CItem;

// Heap-only views. PC derives PCBase (ctor 14164dfd0), and FittingDollPC
// derives PC (ctor 14121b350). No constructors or vftables are emitted here.
// The additional PC virtual interface is not used by the cube guide wrappers;
// calls through these pointers use the inherited GameObject slots only.
// PC vftable 0x142f4ae28 (147 slots). Slots 124..132 are the first PC-introduced virtuals (PCBase ends at 123);
// types from the base bodies' register homing and the AvatarPC/ClonePC/MyPC overrides (sb2, work/sb2/pc_slots.txt).
// Out-of-line in the unrecovered PC unit: symbols-manual rows. Slots 133..146 are not declared yet.
class Unk_PCArg125;   // MS2Ptr<T> by value (MyPC override destroys it with 0x1409f74e0)
class Unk_PCArg126;   // MS2Ptr<T> by value (get 0x1409f7930, ICF generic dtor 0x1401bfde0)
class PC : public PCBase {
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
