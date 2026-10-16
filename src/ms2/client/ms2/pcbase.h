// pcbase.h - PCBase (efd RTTI "PCBase", class id 0x06200013): abstract base of every animated character actor
// (PC, MyPC, ClonePC, CNpc, CPet, Ridee, CubeSpawnObject ...). Derives GameObject. Owning unit:
// client\ms2\pcbase.cpp (0x14164dfd0-0x141682f80, 1159 funcs). Header name assumed from the unit path.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class X : public PCBase { EE_DECLARE_CLASS1(X, <id>, PCBase); ... };` - do not redeclare the refcount.
// - Virtual names are vfunc_N = slot N of PCBase's primary vftable 0x142f4c6f0 (124 slots: 0-56 from GameObject,
//   57-123 new here). To override, copy the exact declaration. Slot 116 is pure (_purecall) - every concrete
//   derived class must implement vfunc_116. Unproven param types are void*; refine them here (keep slot order)
//   and tell the coordinator.
// - vfunc_114 is inline (its only COMDAT 0x140a4ffb0 lives in the cubespawnobject unit); keep it inline.
// - vfunc_80..87/103/104 return lazily-created per-actor components as MS2Ptr<T> (hidden return pointer). Their
//   T is unproven: each uses a distinct MS2Ptr instantiation (null ctor VA noted), so each gets its own Unk_ type.
// - Members: proven types where known, otherwise pointer/int-aligned stand-ins of the right size (PCBase is
//   heap-only, never a local). MS2_CHECK_OFFSETs below pin the ones derived classes touch.
#pragma once
#include <vector>
#include <atlcoll.h>
#include <atlcomcli.h>

#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/timer.h"     // Timer (0x38)
#include <efd/utf8string.h>
#include <efd/Point2.h>

// Component types behind the MS2Ptr members/getters (names unknown; MS2Ptr null-ctor VA in brackets).
class CSkillRecord;        // slots 100-102 (RTTI CSkillRecord, 0x1c0; ?\skillrecord.cpp)
class Unk_PCBaseComp_a58;   // slot 80, +0xa58 [0x14108af40]
class Unk_PCBaseComp_a68;   // slot 81, +0xa68 [0x140e86b20] (null ctor COMDAT in uishieldbar)
class Unk_PCBaseComp_a78;   // slot 82, +0xa78 [0x14108af60]
class Unk_PCBaseComp_a88;   // slot 83, +0xa88 [0x14108af20]
class Unk_PCBaseComp_a98;   // slot 84, +0xa98 [0x14128f6f0]
class Unk_PCBaseComp_aa8;   // slot 85, +0xaa8 [0x140a4fc30] (CubeSpawnObject overrides slot 85)
class Unk_PCBaseComp_ab8;   // slot 86, +0xab8 [0x14108af80]
class Unk_PCBaseComp_ac8;   // slot 87, +0xac8 [0x140ba97e0]
class Unk_PCBaseComp_b18;   // slots 103/104, +0xb18 [0x141532140 / member init 0x141532470]
class CStateManager;        // +0x140 actor state machine (0x98 bytes, ctor(actor) 0x1417da7a0, AddState 0x1417daeb0)
class Unk_PCBaseEquipPart;  // element of the npc row's part list (+0x588), applied by FUN_141674ef0
class Unk_PCBaseBuffs;      // FUN_1416749a0 (ridee.cpp)
class State;                // state.h

// 0xd40 bytes. vftable 0x142f4c6f0 (124 slots); CallbackObject vftable @+8 0x142f4cad8 (dtor thunk 0x14167f518,
// overrides AnimActivated 0x14166bec0, TextKeyEvent 0x14166bf40, EndOfSequence 0x14166c550).
// efd: TypeCast 0x141680770/0x141680720, GetClassDesc 0x14167f940, ??_G 0x14167f670, ClassInfo 0x143ae32d0.
class PCBase : public GameObject
{
    EE_DECLARE_CLASS1(PCBase, 0x06200013, GameObject);

public:
    PCBase();                                               // 0x14166a650
    virtual ~PCBase();                                      // 0x14166af20

    // NiActorManager::CallbackObject overrides
    virtual void AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166bec0
    virtual void TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166bf40
    virtual void EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);                                   // 0x14166c550

    // GameObject overrides (slots 9..56)
    virtual void vfunc_9(void* p);                          // 9 0x14166b470
    virtual int vfunc_10();                                 // 10 0x14166b550
    virtual void vfunc_12();                                // 12 0x14166b810
    virtual void vfunc_14();                                // 14 0x14166b880
    virtual void vfunc_15();                                // 15 0x14166b990
    virtual void vfunc_16();                                // 16 0x14166b9e0
    virtual NiPoint3 vfunc_18();                            // 18 0x14166bbe0
    virtual void vfunc_19(efd::Point3 kPos);                // 19 0x14166bb10 (by value)
    virtual NiPoint3 vfunc_20();                            // 20 0x14166bc50
    virtual void vfunc_21(efd::Point3 kDir);                // 21 0x14166bb60 (by value)
    virtual void vfunc_23(int n);                           // 23 0x14166c5b0
    virtual Unk_GoAttachment* vfunc_26();                   // 26 0x14166bd70
    virtual void vfunc_32(bool b);                          // 32 0x14166bdd0
    virtual NiPoint3 vfunc_37();                            // 37 0x14166bcc0
    virtual void vfunc_52(double fTime);                    // 52 0x14166c640 (update)
    virtual void vfunc_53(float f);                         // 53 0x141679450

    // new virtuals, slots 57..123
    virtual int vfunc_57();                                 // 57  0x14166c7d0
    virtual int vfunc_58();                                 // 58  0x14166c7e0
    virtual void vfunc_59(int a, void* b, int c, int d);    // 59  0x14166c800
    virtual CString vfunc_60();                             // 60  0x14166c9b0 (returns a literal; PC overrides)
    virtual int vfunc_61();                                 // 61  0x14166ca00
    virtual bool vfunc_62();                                // 62  0x14166ca10
    virtual int vfunc_63();                                 // 63  0x14166ce00
    virtual int vfunc_64();                                 // 64  0x14166cec0
    virtual int vfunc_65();                                 // 65  0x14166ced0
    virtual void vfunc_66(int n);                           // 66  0x14166cef0
    virtual void vfunc_67(void* a, void* b);                // 67  0x14166cf40
    virtual bool vfunc_68(void* a, double t, int b, unsigned c, int d);  // 68 0x14166e100
    virtual int vfunc_69();                                 // 69  0x14166f9f0
    virtual void vfunc_70();                                // 70  0x14166fa00
    virtual void vfunc_71(void* p);                         // 71  0x14166fa30
    virtual void vfunc_72();                                // 72  0x14166fa60
    virtual void vfunc_73(void* p, int n);                  // 73  0x14166fa70
    virtual void vfunc_74(void* a, void* b);                // 74  0x14166fbf0
    virtual void vfunc_75(void* a, void* b);                // 75  0x14166fc70
    virtual void vfunc_76(CStringW str);                    // 76  0x14166fcf0 (by value: the callee destroys it)
    virtual CStringW vfunc_77();                            // 77  0x14166fd50
    virtual int vfunc_78();                                 // 78  0x14166fda0
    virtual void vfunc_79();                                // 79  0x14166fdb0
    virtual MS2Ptr<Unk_PCBaseComp_a58> vfunc_80();          // 80  0x14166fde0 (base: null; Ridee/PC override)
    virtual MS2Ptr<Unk_PCBaseComp_a68> vfunc_81();          // 81  0x14166fe20
    virtual MS2Ptr<Unk_PCBaseComp_a78> vfunc_82();          // 82  0x14166fe60
    virtual MS2Ptr<Unk_PCBaseComp_a88> vfunc_83();          // 83  0x14166fea0
    virtual MS2Ptr<Unk_PCBaseComp_a98> vfunc_84();          // 84  0x14166fee0
    virtual MS2Ptr<Unk_PCBaseComp_aa8> vfunc_85();          // 85  0x14166ff20
    virtual MS2Ptr<Unk_PCBaseComp_ab8> vfunc_86();          // 86  0x14166ff60
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();          // 87  0x14166ffa0
    virtual int vfunc_88();                                 // 88  0x14166ffe0
    virtual float vfunc_89();                               // 89  0x141670450
    virtual void vfunc_90(void* p);                         // 90  0x141670a90
    virtual void vfunc_91(void* p);                         // 91  0x141670cd0
    virtual void vfunc_92(void* p);                         // 92  0x141670d10
    virtual void vfunc_93(bool b);                          // 93  0x141671130
    virtual void vfunc_94(int n);                           // 94  0x141671380
    virtual float vfunc_95();                               // 95  0x141671620
    virtual void vfunc_96();                                // 96  0x141671680
    virtual float vfunc_97();                               // 97  0x141671720
    virtual void vfunc_98(float f);                         // 98  0x1416718d0
    virtual int vfunc_99(int n);                            // 99  0x141671b70
    // 100-102 take the skill record smart pointer BY VALUE (the callee destroys it: MS2Ptr<CSkillRecord> dtor
    // 0x140975740 on the homed rdx in 0x141672910 / 0x141672de0 / 0x141673890; callers copy it with 0x1409f71b0 first,
    // e.g. inventory 0x140a62d30 -> slot 102, skillslot 0x141765570 -> slot 100). CSkillRecord: RTTI, new(0x1c0).
    virtual void vfunc_100(MS2Ptr<CSkillRecord> skill, int n);           // 100 0x141672910
    virtual void vfunc_101(MS2Ptr<CSkillRecord> skill, int n, void* q);  // 101 0x141672de0
    virtual bool vfunc_102(MS2Ptr<CSkillRecord> skill);                  // 102 0x141673890 (base: return true)
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_103();         // 103 0x1416738c0 (checks +0x8e8 list)
    virtual MS2Ptr<Unk_PCBaseComp_b18> vfunc_104(bool a, bool b, bool c);  // 104 0x1416739c0 (base: null; 3 bools per Ridee)
    virtual void vfunc_105(efd::Point3 kPos, void* b, void* c, int d);   // 105 0x141673a10 (kPos by value per Ridee)
    virtual void vfunc_106(void* p, double t, int n);       // 106 0x141674750
    virtual void vfunc_107(void* p, float f);               // 107 0x141674020
    virtual int vfunc_108();                                // 108 0x141674bf0
    virtual void vfunc_109(int n);                          // 109 0x141674c00
    virtual void vfunc_110();                               // 110 0x141674c50
    virtual void vfunc_111(void* p, int a, int b, void* q); // 111 0x141674c60 (CNpc/CPet override)
    virtual void vfunc_112(void* p, int n);                 // 112 0x141674d80 (CNpc/CPet override)
    virtual void vfunc_113(void* p);                        // 113 0x141674ec0
    virtual void vfunc_114(void*) {}                        // 114 0x140a4ffb0 (inline; Ridee overrides)
    // 115: three register floats + stack float, int, int* (CGuideObject 0x1410a1240 / Ridee 0x141706490 forward all
    // six; CNpc/CPet 0x141090850 stores 0 to *pOut, tests nFlag == 0 and multiplies the result by d; PC 0x14165e500
    // stores 1/0 to *pOut). Base 0x141675270: return 0.0f.
    virtual float vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut);  // 115 0x141675270
    virtual int vfunc_116() = 0;                            // 116 _purecall (CubeSpawnObject 0x140a4efd0: return 1)
    virtual int vfunc_117();                                // 117 0x1416752a0
    virtual int vfunc_118(void* a, float* b, CString* c);   // 118 0x1416752f0
    virtual void vfunc_119();                               // 119 0x141675450
    virtual void vfunc_120(void* p);                        // 120 0x141676b90
    virtual void vfunc_121(void* p);                        // 121 0x1416773f0
    virtual int vfunc_122(void* p);                         // 122 0x1416781c0
    virtual const char* vfunc_123(int n);                   // 123 0x1416790b0 (looks up in +0xd00; a string per Ridee)

    // non-virtual helpers called by derived units
    void FUN_14166dd20(const efd::utf8string& strAnim, float fSpeed, bool bA, bool bB);   // 0x14166dd20 play animation
    void FUN_14166fff0(CStringW str);                       // 0x14166fff0 chat balloon text (by value)
    void FUN_141674ef0(const Unk_PCBaseEquipPart& part);    // 0x141674ef0 attach a model part
    MS2Ptr<CStateManager> FUN_141678750();                  // 0x141678750 copy of m_spStateMgr (w17)
    // clonepc.cpp (w69)
    bool FUN_14166ed10();                                   // 0x14166ed10 the value ClonePC copies into m_b9d0
    void FUN_14166ed70(int n);                              // 0x14166ed70
    void FUN_14166ef10(const CString& str, bool bA, int nB, int nC);   // 0x14166ef10
    int FUN_14166f6d0();                                    // 0x14166f6d0
    CString FUN_14166f740();                                // 0x14166f740 (returns a string)
    // uipvpguildteamdialog.cpp (w71)
    __int64 FUN_141670a00(int nStat);                       // 0x141670a00 current value of a stat (4 = hp)
    __int64 FUN_141670a30(int nStat);                       // 0x141670a30 max value of a stat
    // ridee.cpp (w67)
    ATL::CRBMap<CString, efd::SmartPointer<NiAVObject> >& FUN_141708b10() { return m_unk_b88; }   // COMDAT 0x141708b10
    int FUN_14166c930();                                    // 0x14166c930 current state id (0: none)
    int FUN_14166cc80();                                    // 0x14166cc80 current sub state
    State* FUN_14166ccb0();                                 // 0x14166ccb0 current state
    float FUN_14166da40();                                  // 0x14166da40
    void FUN_14166d820();                                   // 0x14166d820
    void FUN_14166e0a0();                                   // 0x14166e0a0
    void FUN_141670d50(efd::Point2 kSize);                  // 0x141670d50 (25, 105 for a Ridee)
    void FUN_141670fd0(efd::Point3 kSize, efd::Point3 kOffset);   // 0x141670fd0 collision box
    void FUN_141671960(float fSpeed);                       // 0x141671960
    Unk_PCBaseBuffs* FUN_1416749a0();                       // 0x1416749a0
    bool FUN_1416749c0();                                   // 0x1416749c0
    int FUN_141676410();                                    // 0x141676410 riding id
    MS2Ptr<Unk_PCBaseComp_b18> FUN_141676930();             // 0x141676930 ugc ridee item
    void FUN_141676b50(int bRun);                           // 0x141676b50
    int FUN_141676b70();                                    // 0x141676b70
    void FUN_141678240(const egf::EntityID& kId, const NiPoint3& kPos);   // 0x141678240
    void FUN_141678290(egf::EntityID kId, NiPoint3 kPos);   // 0x141678290
    void FUN_141678360();                                   // 0x141678360

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CStateManager> m_spStateMgr; // +0x140 (init 0x14167dfe0; CubeSpawnObject assigns via AssignRaw)
    void* m_unk_150;                    // +0x150 = 0
    int m_unk_158;                      // +0x158
    int m_unk_15c;                      // +0x15c
    int m_unk_160;                      // +0x160
    float m_f164;                       // +0x164 (not initialised by PCBase; derived ctors load config floats)
    float m_f168;                       // +0x168
    float m_f16c;                       // +0x16c
    float m_f170;                       // +0x170
    float m_f174;                       // +0x174
    float m_f178;                       // +0x178
    int m_unk_17c;                      // +0x17c
    float m_unk_180[4];                 // +0x180 (init 0x140266620; [0] = 1800.0)
    float m_unk_190[4];                 // +0x190 (init 0x140266620; [0] = 1800.0)
    float m_unk_1a0[7];                 // +0x1a0 (init 0x1402666f0; [0] = 50.0)
    int m_unk_1bc;                      // +0x1bc
    char m_unk_1c0[3][0x118];           // +0x1c0 zero-filled records
    char m_unk_508[0x118];              // +0x508 zero-filled record
    float m_unk_620[2];                 // +0x620 (init 0x140a0a600(p, 25.0, 105.0))
    void* m_unk_628[2];                 // +0x628 (init 0x140ae13b0)
    void* m_unk_638[2];                 // +0x638 (init 0x14167e030)
    void* m_colorBoost[9];              // +0x648 CColorBoostManager (0x48)
    void* m_pushControl[9];             // +0x690 CPushControl (0x48)
    void* m_unk_6d8[14];                // +0x6d8 (init 0x141682e90)
    void* m_unk_748[52];                // +0x748 (init 0x14096ef20(p, this))
    void* m_unk_8e8[6];                 // +0x8e8 CAtlList-like (init 0x14167de50(p,10)); probed by vfunc_103
    CStringW m_strW918;                 // +0x918
    NiPoint3 m_pos920;                  // +0x920 = ZERO
    float m_f92c;                       // +0x92c = 1.0
    float m_f930;                       // +0x930 = 1.0
    float m_f934;                       // +0x934 = 0
    float m_f938;                       // +0x938 = 1.0
    CString m_str940;                   // +0x940 = ""
    CString m_str948;                   // +0x948 = ""
    CString m_str950;                   // +0x950
    CString m_str958;                   // +0x958 = ""
    CString m_str960;                   // +0x960 = ""
    int m_unk_968;                      // +0x968
    Timer m_timer970;                   // +0x970
    int m_unk_9a8;                      // +0x9a8
    NiPoint3 m_pos9ac;                  // +0x9ac = ZERO
    NiPoint3 m_pos9b8;                  // +0x9b8 (init 0x1402bd040)
    short m_unk_9c4;                    // +0x9c4
    int m_unk_9c8;                      // +0x9c8
    int m_unk_9cc;                      // +0x9cc
    bool m_b9d0;                        // +0x9d0 = 1
    bool m_b9d1;                        // +0x9d1 = 1
    CString m_str9d8;                   // +0x9d8 = "default"
    CString m_str9e0;                   // +0x9e0
    Timer m_timer9e8;                   // +0x9e8
    void* m_unk_a20[2];                 // +0xa20 (not initialised by the ctor)
    CAtlArray<void*> m_arrA30;          // +0xa30
    int m_unk_a50;                      // +0xa50 = 1
    MS2Ptr<Unk_PCBaseComp_a58> m_spA58; // +0xa58
    MS2Ptr<Unk_PCBaseComp_a68> m_spA68; // +0xa68 (init 0x14167e0b0)
    MS2Ptr<Unk_PCBaseComp_a78> m_spA78; // +0xa78
    MS2Ptr<Unk_PCBaseComp_a88> m_spA88; // +0xa88
    MS2Ptr<Unk_PCBaseComp_a98> m_spA98; // +0xa98
    MS2Ptr<Unk_PCBaseComp_aa8> m_spAA8; // +0xaa8
    MS2Ptr<Unk_PCBaseComp_ab8> m_spAB8; // +0xab8
    MS2Ptr<Unk_PCBaseComp_ac8> m_spAC8; // +0xac8 (init 0x14167e090)
    void* m_unk_ad8;                    // +0xad8 = 0
    egf::EntityID m_unk_ae0;            // +0xae0 (init 0x1408995b0, then 0x140899bd0(p, 0x143ae3278)); EntityID per Ridee
    NiPoint3 m_posAE8;                  // +0xae8 (= ZERO)
    int m_unk_af4;                      // +0xaf4 = 0x7fffffff
    int m_unk_af8;                      // +0xaf8
    void* m_unk_b00[2];                 // +0xb00 (init 0x1407810b0(p,0))
    CComPtr<IUnknown> m_spB10;          // +0xb10 (CComPtrBase(0); interface type unproven)
    MS2Ptr<Unk_PCBaseComp_b18> m_spB18; // +0xb18
    void* m_mapB28[9];                  // +0xb28 CAtlMap (17 bins, .75/.25/2.25, block 10; init 0x140163400)
    int m_unk_b70;                      // +0xb70
    void* m_unk_b78;                    // +0xb78
    int m_unk_b80;                      // +0xb80
    ATL::CRBMap<CString, efd::SmartPointer<NiAVObject> > m_unk_b88;   // +0xb88 (init 0x14167deb0(p,10)); node map per Ridee
    void* m_unk_bb8[6];                 // +0xbb8 CAtlList-like (init 0x14167deb0(p,10))
    void* m_unk_be8;                    // +0xbe8 (init 0x14097eba0(p,0))
    int m_unk_bf0;                      // +0xbf0
    NiPoint3 m_posBF4;                  // +0xbf4 = ZERO
    int m_unk_c00;                      // +0xc00
    int m_unk_c04;                      // +0xc04 = 1
    int m_unk_c08;                      // +0xc08 (init 0x140d75040)
    int m_unk_c0c;                      // +0xc0c
    NiPoint3 m_posC10;                  // +0xc10 = ZERO
    NiPoint3 m_posC1C;                  // +0xc1c
    NiPoint3 m_posC28;                  // +0xc28
    void* m_unk_c38;                    // +0xc38 (init 0x14097eba0(p,0))
    void* m_unk_c40;                    // +0xc40 (init 0x14097eba0(p,0))
    int m_unk_c48;                      // +0xc48 = 5
    void* m_unk_c50[2];                 // +0xc50 (init 0x14167e100(p,0))
    int m_unk_c60;                      // +0xc60
    int m_unk_c64;                      // +0xc64
    int m_unk_c68;                      // +0xc68
    Timer m_timerC70;                   // +0xc70 (armed 1000 ms)
    void* m_mapCA8[9];                  // +0xca8 CAtlMap (init 0x140c69c80)
    void* m_unk_cf0[2];                 // +0xcf0 (init 0x14167e4b0)
    void* m_unk_d00[2];                 // +0xd00 (init 0x14094d440); vfunc_123 looks up here (0x14094e040)
    void* m_unk_d10[2];                 // +0xd10 (init 0x1411bf870)
    int m_unk_d20;                      // +0xd20
    std::vector<unsigned> m_vecD28;     // +0xd28 (init 0x140182ed0)
};
MS2_CHECK_SIZE(PCBase, 0xd40);
MS2_CHECK_OFFSET(PCBase, m_spStateMgr, 0x140);
MS2_CHECK_OFFSET(PCBase, m_f164, 0x164);
MS2_CHECK_OFFSET(PCBase, m_f178, 0x178);
MS2_CHECK_OFFSET(PCBase, m_unk_1c0, 0x1c0);
MS2_CHECK_OFFSET(PCBase, m_unk_620, 0x620);
MS2_CHECK_OFFSET(PCBase, m_unk_ae0, 0xae0);
MS2_CHECK_OFFSET(PCBase, m_unk_b88, 0xb88);
MS2_CHECK_OFFSET(PCBase, m_colorBoost, 0x648);
MS2_CHECK_OFFSET(PCBase, m_pushControl, 0x690);
MS2_CHECK_OFFSET(PCBase, m_unk_748, 0x748);
MS2_CHECK_OFFSET(PCBase, m_unk_8e8, 0x8e8);
MS2_CHECK_OFFSET(PCBase, m_strW918, 0x918);
MS2_CHECK_OFFSET(PCBase, m_str940, 0x940);
MS2_CHECK_OFFSET(PCBase, m_timer970, 0x970);
MS2_CHECK_OFFSET(PCBase, m_str9d8, 0x9d8);
MS2_CHECK_OFFSET(PCBase, m_timer9e8, 0x9e8);
MS2_CHECK_OFFSET(PCBase, m_arrA30, 0xa30);
MS2_CHECK_OFFSET(PCBase, m_spA58, 0xa58);
MS2_CHECK_OFFSET(PCBase, m_spAA8, 0xaa8);
MS2_CHECK_OFFSET(PCBase, m_spB18, 0xb18);
MS2_CHECK_OFFSET(PCBase, m_mapB28, 0xb28);
MS2_CHECK_OFFSET(PCBase, m_unk_be8, 0xbe8);
MS2_CHECK_OFFSET(PCBase, m_posC28, 0xc28);
MS2_CHECK_OFFSET(PCBase, m_timerC70, 0xc70);
MS2_CHECK_OFFSET(PCBase, m_mapCA8, 0xca8);
MS2_CHECK_OFFSET(PCBase, m_unk_d00, 0xd00);
MS2_CHECK_OFFSET(PCBase, m_vecD28, 0xd28);
