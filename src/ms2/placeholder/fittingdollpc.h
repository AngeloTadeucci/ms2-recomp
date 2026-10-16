#pragma once
#include "ms2/client/ms2/pcbase.h"
#include <NiFixedString.h>
class CItem;
class NiAVObject;
class NiColor;
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
class Unk_PCActionTimer;   // CPtred-derived, defined by the user unit (avatarpc.cpp)
class CEquipItem;
struct Unk_PCEquipSet { MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind); MS2Ptr<CEquipItem> FUN_1411e1580(__int64 nItemUid); void FUN_1411e4150(__int64 nItemUid, unsigned char nSlot, int nKind); unsigned char unknown0[0x1e8]; };   // FUN_1411e1780 (itemgem.cpp): the worn item of an equip slot   // the PC's equipment holder (+0xde0); methods FUN_1411e3de0/e3000/e22c0
class Unk_PCD88;      // +0xd88 target (ClonePC::vfunc_12 releases it via FUN_140a35900)
class Unk_PCArg126;   // MS2Ptr<T> by value (get 0x1409f7930, ICF generic dtor 0x1401bfde0)
class PC : public PCBase {
    EE_DECLARE_CLASS1(PC, 0x06200003, PCBase);   // ClassInfo 0x143ae2e20 (setup COMDAT 0x1409f8020 in avatarpc; sb4)
public:
    PC();                                                   // 0x14164dfd0 (called by ClonePC::ClonePC)
    virtual ~PC();
    virtual void vfunc_9(void* p);                          // 9 0x141651300 (PCBase 0x14166b470)
    virtual void vfunc_12();                                // 12 0x1416515a0 (PCBase 0x14166b810)
    virtual void vfunc_14();                                // 14 0x141651bb0 (PCBase 0x14166b880)
    virtual int vfunc_10();                                 // 10 0x141651370 (PCBase 0x14166b550)
    virtual void vfunc_53(float f);                         // 53 0x141660240
    virtual void vfunc_59(int a, void* b, int c, int d);    // 59 0x1416537d0
    virtual int vfunc_116();                                // 116 0x14165ebe0 (PCBase's is pure)
    // slots AvatarPC inherits from here (declared so the vftable resolves to the exe slots)
    virtual void vfunc_107(void* p, float f);               // 107 0x14165f720
    virtual void vfunc_113(void* p);                        // 113 0x14165fec0
    virtual void vfunc_114(void*);                          // 114 0x14165c4e0
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut);// 115 0x14165e500
    virtual int vfunc_118(void* a, float* b, CString* c);   // 118 0x141655a30
    virtual void vfunc_120(void* p);                        // 120 0x1416561e0
    virtual void vfunc_121(void* p);                        // 121 0x1416562d0
    virtual int vfunc_122(void* p);                         // 122 0x14165f5d0
    virtual void vfunc_15();                                // 15 0x141651d00
    virtual void vfunc_16();                                // 16 0x141651d40
    virtual void vfunc_23(int n);                           // 23 0x14165c320
    virtual void vfunc_31(bool b);                          // 31 0x141652030
    virtual void vfunc_33(void* a, void* b);                // 33 0x141652080
    virtual void vfunc_34(void* p);                         // 34 0x1416529f0
    virtual void vfunc_35(void* p);                         // 35 0x141652e20
    virtual void vfunc_40(float a, float b, float c, float d);   // 40 0x14165d8d0
    virtual void vfunc_42(float f, bool b);                 // 42 0x14165dad0
    virtual void vfunc_44(void* p);                         // 44 0x14165dd80
    virtual void vfunc_52(double fTime);                    // 52 0x141651d80
    virtual int vfunc_57();                                 // 57 0x141653ce0
    virtual CString vfunc_60();                             // 60 0x141658a30
    virtual int vfunc_61();                                 // 61 0x141658b80
    virtual bool vfunc_62();                                // 62 0x141658c40
    virtual void vfunc_66(int n);                           // 66 0x1416544f0
    virtual int vfunc_69();                                 // 69 0x14165f480
    virtual void vfunc_71(void* p);                         // 71 0x14165ff00
    virtual void vfunc_72();                                // 72 0x14165ff80
    virtual void vfunc_74(void* a, void* b);                // 74 0x141656af0
    virtual CStringW vfunc_77();                            // 77 0x141656c70
    virtual int vfunc_78();                                 // 78 0x1416578f0
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81 0x141656f80
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84();          // 84 0x1416572b0
    virtual void vfunc_90(void* p);                         // 90 0x141657910
    virtual float vfunc_95();                               // 95 0x14165e4a0 (PCBase 0x141671620)
    virtual int vfunc_99(int n);                            // 99 0x141654850
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
    // non-virtual members called by scenestategame.cpp (w86)
    MS2Ptr<CItem> FUN_141655b80(__int64 nItemUid);          // 0x141655b80 an owned item by uid
    MS2Ptr<CEquipItem> FUN_141655c30(__int64 nItemUid);     // 0x141655c30 a worn item by uid
    Unk_PCEquipSet* FUN_1416561a0();                        // 0x1416561a0 &m_kEquipDE0
    class Unk_PCItemCooldowns* FUN_1416561c0();             // 0x1416561c0
    int FUN_1416595d0();                                    // the cube craft mode (scenestategame 0x1417235a0)
    class Unk_PCCubeCraft* FUN_141659700();                 // the cube craft controller
    void FUN_141660000(__int64 nValue);
    void FUN_141661ba0(int n);                              // scenestategame packet (state reset flag)
    void FUN_141661dc0(unsigned short nA, int nB);          // scenestategame packet 0xb1
    void FUN_141658ed0(unsigned char n);                    // scenestategame packet 0xb2
    void FUN_141662d60(__int64 nValue);                     // scenestategame packet 0xe6
    int FUN_141661aa0();                                    // scenestategame packet 0x33 (pvp flag)
    void FUN_141661a60(int n);                              // scenestategame packet 0x33
    void FUN_1416619d0(int n);                              // scenestategame packet 0x33
    void FUN_141661370(int a, int b, int c);                // scenestategame packet 0x34 (also on MyPC)
    void FUN_1416591e0(int nSlot, const NiColor& kColor);   // +0xd98 + nSlot*0xc = kColor (scenestategame 0x30)
    const NiColor& FUN_141659220(int nSlot);                // the colour at +0xd98 + nSlot*0xc
    void FUN_141656780();                                   // re-apply the appearance (scenestategame 0x30)
    // 0xd40..0x12e0. The MS2Ptr at +0xfc8 (an action timer; AvatarPC::vfunc_142 pokes it) is exposed, the rest is opaque.
    // ClonePC (clonepc.cpp) uses the list at +0xd48, the MS2Ptr at +0xd88 and the equip holder at +0xde0.
    unsigned char unknownD40[8];
    unsigned char m_kListD48[0x40];                         // +0xd48 (reset by FUN_1408f3a80)
    MS2Ptr<Unk_PCD88> m_spD88;                              // +0xd88
    unsigned char unknownD98[0x48];
    Unk_PCEquipSet m_kEquipDE0;                             // +0xde0 equip holder (FUN_1411e3de0)
    MS2Ptr<Unk_PCActionTimer> m_spFC8;                      // +0xfc8
    unsigned char unknownFD8[0x308];
};
MS2_CHECK_OFFSET(PC, m_kListD48, 0xd48);
MS2_CHECK_OFFSET(PC, m_spD88, 0xd88);
MS2_CHECK_OFFSET(PC, m_kEquipDE0, 0xde0);
MS2_CHECK_OFFSET(PC, m_spFC8, 0xfc8);
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
