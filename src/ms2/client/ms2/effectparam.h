// effectparam.h - CEffectParam: CPtred-based base of the ~28 effect parameter classes parsed from the effect XML
// (CPostEffectParam, CNifEffectParam, CSoundEventEffectParam, TransitionEffectParam ...). Owning unit:
// client\ms2\effectservice.cpp (0x14119e920-0x1411b8510, 873 funcs). Header name assumed.
//
// HOW TO USE THIS HEADER (for unit workers):
// - `class XEffectParam : public CEffectParam` (or CPostEffectParam, posteffectparam.h); copy the exact virtual
//   declarations to override. vfunc_N = slot N of vftable 0x142eba118 (8 slots, ??_G 0x1411a1db0).
// - The dtor is inline: its only COMDAT (0x140987960) was emitted by the first unit that destroyed a param
//   (unit_140987430, CAfterImageEffectParam), not by effectservice.
// - vfunc_6 creates the runtime effect object; it returns NiPointer<CEffect> (8 bytes, hidden return pointer;
//   NiPointer(T*) COMDAT 0x1409878c0). CEffect (the runtime effect, NiRefObject-based, 13 slots) is declared below.
// - The XML node type is the game's TinyXML element (Unk_140165cf0, see commonfiles/fielddata.h).
#pragma once
#include <afx.h>
#include <NiRefObject.h>
#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_140165cf0;     // game TinyXML element
class Unk_EffectTarget;  // vfunc_7 argument: int at +8 (1 = caster/target is MyPC?); getters 0x140a53110/53010/53050

// 0x30 bytes. Runtime effect base (CPostEffect 0x38 etc.). vftable 0x142eb9a50 (13 slots): slot 0 is _purecall
// (pure virtual destructor; dtor body 0x14119eaa0), slot 1 NiRefObject::DeleteThis, 12 pure.
class CEffect : public NiRefObject
{
public:
    CEffect();                                      // 0x14119ea10
    virtual ~CEffect() = 0;                         // 0x14119eaa0

    virtual const void* vfunc_2();                  // 2  0x14119f4a0 return static table (interface map?)
    virtual bool vfunc_3(void* a, void* b);         // 3  0x14119f0b0
    virtual void vfunc_4();                         // 4  0x14119f190
    virtual void vfunc_5();                         // 5  0x14119f1b0
    virtual void vfunc_6(float f);                  // 6  0x14119f1d0 calls vfunc_5
    virtual void vfunc_7();                         // 7  0x14119f200
    virtual int vfunc_8(void* p);                   // 8  0x14119f220 return 0
    virtual bool vfunc_9();                         // 9  0x14119f240
    virtual void vfunc_10(bool b);                  // 10 0x14119f2f0 {}
    virtual int vfunc_11();                         // 11 0x14119f300 return !m_b2c
    virtual int vfunc_12() = 0;                     // 12 pure (CPostEffect 0x140dbdc80: return +0x30)

public:
    MS2_LAYOUT_FRIEND;
    CString m_str10;                // +0x10
    int m_unk_18;                   // +0x18
    void* m_unk_20;                 // +0x20
    int m_unk_28;                   // +0x28
    bool m_b2c;                     // +0x2c
    bool m_b2d;                     // +0x2d
    bool m_b2e;                     // +0x2e
    bool m_b2f;                     // +0x2f = 1
};
MS2_CHECK_SIZE(CEffect, 0x30);
MS2_CHECK_OFFSET(CEffect, m_str10, 0x10);
MS2_CHECK_OFFSET(CEffect, m_unk_20, 0x20);
MS2_CHECK_OFFSET(CEffect, m_b2f, 0x2f);
typedef NiPointer<CEffect> CEffectPtr;

// 0x48 bytes.
class CEffectParam : public CPtred
{
public:
    explicit CEffectParam(int nType);                       // 0x1411a01d0
    virtual ~CEffectParam() {}                              // 0x140987960 (inline), ??_G 0x1411a1db0

    virtual void vfunc_1(Unk_140165cf0* pNode);             // 1 0x1411a0290 load startDelay/duration/lodSkipLevel/.../ignoreOptimize
    virtual bool vfunc_2();                                 // 2 0x1411a03d0 validate (warns for types 4,7-10,12,15 with no duration)
    virtual bool vfunc_3();                                 // 3 0x14119e920 return true
    virtual void vfunc_4();                                 // 4 0x14119e930 {}
    virtual bool vfunc_5(int n);                            // 5 0x1411a0480 return true
    virtual CEffectPtr vfunc_6();                           // 6 0x1411a04a0 base: null
    virtual bool vfunc_7(Unk_EffectTarget* p);              // 7 0x14119e940 filter: skip for this target?

public:
    MS2_LAYOUT_FRIEND;
    int m_nType;                    // +0x18 ctor arg
    CString m_str20;                // +0x20 (used in the vfunc_2 warning)
    float m_fStartDelay;            // +0x28 "startDelay"
    float m_fDuration;              // +0x2c "duration"
    bool m_b30;                     // +0x30 attribute name at 0x142eb9ee0
    bool m_bOffSkip;                // +0x31 "offSkip"
    bool m_bOnlyCasterMyPC;         // +0x32 "onlyCasterMyPC"
    bool m_bOnlyTargetMyPC;         // +0x33 "onlyTargetMyPC"
    int m_nLodSkipLevel;            // +0x34 "lodSkipLevel"
    int m_nGender;                  // +0x38 "gender" (= 2: any)
    int m_nJobCode;                 // +0x3c "jobCode"
    bool m_bIgnoreOptimize;         // +0x40 "ignoreOptimize"
};
MS2_CHECK_SIZE(CEffectParam, 0x48);
MS2_CHECK_OFFSET(CEffectParam, m_nType, 0x18);
MS2_CHECK_OFFSET(CEffectParam, m_str20, 0x20);
MS2_CHECK_OFFSET(CEffectParam, m_fDuration, 0x2c);
MS2_CHECK_OFFSET(CEffectParam, m_bOnlyTargetMyPC, 0x33);
MS2_CHECK_OFFSET(CEffectParam, m_nGender, 0x38);
MS2_CHECK_OFFSET(CEffectParam, m_bIgnoreOptimize, 0x40);
