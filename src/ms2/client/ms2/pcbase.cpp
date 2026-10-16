// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See pcbase.h.
// This file covers the PCBase translation unit only. The PC TU (0x14164dfd0-0x14166a650, .text$di 0x1400fb010-0x1400fb4d0)
// and the buff-tracker TU at 0x141682e90 (.text$di 0x1400fb790-) share the unit name but are separate objects.
// MS2-UNIT: client\ms2\pcbase.cpp
// MS2-RANGE: 0x14166a650-0x141682e90 .text$mn
// MS2-RANGE: 0x1400fb4d0-0x1400fb790 .text$di
// MS2-RANGE: 0x142cb4000-0x142cb40e0 .text$yd
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\pcbase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "pcbase.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/animationmanager.h"
#include "ms2/placeholder/state.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Matrix3.h>
#include <NiMatrix3.h>
#include <NiFixedString.h>

// ---- unit-local placeholders ----

// The lazily created per-actor components (vfunc_80..87, 103/104); only reset here.
class Unk_PCBaseComp_a58 : public CPtred {};
class Unk_PCBaseComp_a68 : public CPtred {};
class Unk_PCBaseComp_a78 : public CPtred {};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred {};
class Unk_PCBaseComp_ab8 : public CPtred {};
class Unk_PCBaseComp_ac8 : public CPtred {};
class Unk_PCBaseComp_b18 : public CPtred {};

// The physics/controller body of an actor (0xf8; gameobject unit 0x14123f2d0..0x141241300).
class GameObjectControllerHitReport;
class Unk_PCBaseBody
{
public:
    Unk_PCBaseBody();                                               // 0x14123f2d0
    ~Unk_PCBaseBody();                                              // 0x14123f460
    void FUN_14123f5b0(PCBase* pOwner, void* pEntity, efd::Point3 kPos, float fHeight, float fRadius);
    void FUN_14123fd30(int nGroup);
    void FUN_14123fe70(NiPoint3 kPos);
    NiPoint3 FUN_14123fd90();
private:
    char m_pad[0xf8];
};

// The object a GameObject carries along (vfunc_26; gameobject.cpp).
class Unk_GoAttachment
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();                                        // height
};

// The actor's buffs as other units see them (FUN_1416749a0 returns &m_unk_748).
class Unk_PCBaseBuffs : public Unk_PCBaseBuffList
{
};

// The weak reference at +0x628 (ctor 0x140ae13b0, dtor 0x140a00490).
Unk_GoAttachment* FUN_140a006f0(void* pWeak);

// The node smart pointers at +0xbe8 / +0xc38 / +0xc40.
void FUN_1409fabf0(void* pNodePtr, void* pNode);

// The shadow mesh (efd::SmartPointer at GameObject +0x58; unit_14160fb10).
class CObjectShadow : public NiRefObject
{
public:
    void FUN_14160fe50(bool b);
    void FUN_14160feb0(int n, const NiPoint3& kPos, const efd::Point3& kUp, float f, bool b);
};

// An effect request handed to the effect manager (0x70; ctor 0x140a52ef0 / dtor 0x1405a89e0, same functions as
// effectquery.h's Unk_EffectQuery whose placeholder layout is only 0x10 bytes).
class Unk_PCBaseFxQuery
{
public:
    Unk_PCBaseFxQuery();                                            // 0x140a52ef0
    ~Unk_PCBaseFxQuery();                                           // 0x1405a89e0
    void FUN_140a53190(int nObject);

    CString m_strName;                                              // +0x00
    int m_nPlayer;                                                  // +0x08 = 9
    int m_n0c;
    void* m_p10;                                                    // +0x10 node pointer (0x14097eba0)
    void* m_p18;
    void* m_p20;
    void* m_p28;
    bool m_b30;
    bool m_b31;
    bool m_b32;
    bool m_bEmotion;                                                // +0x33
    bool m_b34;                                                     // = 1
    void* m_p38;
    void* m_p40;                                                    // (0x140a53660)
    int m_n48;                                                      // = 6
    int m_n4c;
    int m_n50;
    int m_n54;
    void* m_p58;
    int m_n60;
    void* m_p68;
};
MS2_CHECK_SIZE(Unk_PCBaseFxQuery, 0x70);
MS2_CHECK_OFFSET(Unk_PCBaseFxQuery, m_bEmotion, 0x33);

class Unk_PCBaseFxMgr
{
public:
    int FUN_1411a49c0(Unk_PCBaseFxQuery* pQuery);                   // spawn, returns the handle
    void FUN_1411a4a00(Unk_PCBaseFxQuery* pQuery);                  // play once
};
Unk_PCBaseFxMgr* FUN_1403ed280();

class Unk_PCBaseWorld
{
public:
    int FUN_141bd1a10(PCBase* pActor);
};
Unk_PCBaseWorld* FUN_1403ed2d0();

// The sound manager (footsteps).
class Unk_PCBaseSound
{
public:
    void FUN_141377420(PCBase* pOwner, CString strKey);
};
Unk_PCBaseSound* FUN_141475cf0();

// The animation service (model cache).
class Unk_PCBaseAnimSvc
{
public:
    efd::utf8string FUN_140b7cc50(const egf::EntityID& kId);         // current animation name
};
Unk_PCBaseAnimSvc* FUN_141b6f910();

// Free helpers of other units.
CString FUN_1409a2360(const char* psz, int n);                      // text conversion
void FUN_140ae1240(void* pEntity, unsigned uHash, const efd::utf8string& str);   // set an entity string property
NiAVObject* FUN_141b6efc0(void* pEntity);
void FUN_141567330(NiAVObject* pNode, bool bShadow);
const char* FUN_142087e50(const NiFixedString& kFixed);            // NiFixedString -> c string
int FUN_1409a1a00(NiActorManager* pkManager);                       // the current sequence id
void FUN_140291b70(float* pfAngle);                                 // wrap degrees into [0, 360)
void FUN_140291bc0(efd::Point3* pkAngles);
void FUN_1419929f0(int nActorId);                                   // hp bar
void FUN_140e863f0(int nActorId);                                   // shield bar
void FUN_141a60ec0(int nActorId);                                   // name tag
void FUN_14192fdc0(int nActorId);                                   // emoticon
void FUN_14128eff0(int nActorId);
void FUN_1418fbe30(int nActorId);                                   // chat balloon
void FUN_141a8fbd0(int nActorId);                                   // profile image
void FUN_140ba8d70(int nActorId);                                   // banner

// ---- class info and statics ----

EE_IMPLEMENT_CONCRETE_CLASS_INFO(PCBase);

static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static CString s_partNames[] = {"Head", "Body", "Back", "RHand", "LHand", "RFoot", "LFoot", "Tail", "Hold_Point"};
static egf::EntityID s_kNoEntity(0ull);
static ATL::CAtlMap<unsigned int, CString> s_conditions(17, .75f, .25f, 2.25f, 10);
static CString s_strNotice("system_notice_error_warningNotThisPlace");

// ---- PCBase ----

// @0x14166b470
// MS2-FUNCTIONAL: the exe keeps two extra pointer temporaries around the utf8string argument (frame 0x88).
void PCBase::vfunc_9(void* p)
{
    GameObject::vfunc_9(p);
    CString strIdle = FUN_1409a2360("Idle_A", 0);
    FUN_140ae1240(p, 0x3ff293c8, (const char*)strIdle);
}
MS2_REPLACE_METHOD(0x14166b470, PCBase, vfunc_9, 203, 0x4ACEA6A0);

// @0x14166b810
void PCBase::vfunc_12()
{
    GameObject::vfunc_12();
    NiAVObject* pNode = FUN_141b6efc0(FUN_14123c410());
    if (pNode)
        FUN_141567330(pNode, true);
    vfunc_119();
    FUN_141675980();
}
MS2_REPLACE_METHOD(0x14166b810, PCBase, vfunc_12, 96, 0x7E2C6D08);

// @0x14166b880
void PCBase::vfunc_14()
{
    FUN_1409fabf0(&m_unk_c38, 0);
    if (FUN_1416764a0())
        vfunc_121(MS2Ptr<RideOffAction>(0));
    if (m_spStateMgr.get() ? true : false) {
        if (m_spStateMgr->FUN_1417db1c0())
            m_spStateMgr->FUN_1417db1c0()->vfunc_5(0);
    }
    m_unk_b88.RemoveAll();
    GameObject::vfunc_14();
}
MS2_REPLACE_METHOD(0x14166b880, PCBase, vfunc_14, 257, 0x75887CFA);

// @0x14166b990
void PCBase::vfunc_15()
{
    GameObject::vfunc_15();
    m_unk_748.FUN_140970490();
    vfunc_16();
}
MS2_REPLACE_METHOD(0x14166b990, PCBase, vfunc_15, 62, 0xB1BD862D);

// @0x14166b9e0
void PCBase::vfunc_16()
{
    m_spA58 = 0;
    m_spA68 = 0;
    m_spA78 = 0;
    m_spA88 = 0;
    m_spA98 = 0;
    m_spAA8 = 0;
    m_spAB8 = 0;
    m_spAC8 = 0;
    FUN_1419929f0(m_unk_70);
    FUN_140e863f0(m_unk_70);
    FUN_141a60ec0(m_unk_70);
    FUN_14192fdc0(m_unk_70);
    FUN_14128eff0(m_unk_70);
    FUN_1418fbe30(m_unk_70);
    FUN_141a8fbd0(m_unk_70);
    FUN_140ba8d70(m_unk_70);
}
MS2_REPLACE_METHOD(0x14166b9e0, PCBase, vfunc_16, 286, 0x096137A0);

// @0x14166bb10
void PCBase::vfunc_19(efd::Point3 kPos)
{
    GameObject::vfunc_19(kPos);
    FUN_14166d260();
}
MS2_REPLACE_METHOD(0x14166bb10, PCBase, vfunc_19, 68, 0x8E98DEA5);

// @0x14166bb60
void PCBase::vfunc_21(efd::Point3 kDir)
{
    float fZ = 0;
    if (FUN_1416749a0()->FUN_140970eb0(fZ))
        kDir.z = fZ;
    GameObject::vfunc_21(kDir);
}
MS2_REPLACE_METHOD(0x14166bb60, PCBase, vfunc_21, 110, 0xD1F026CA);

// @0x14166bbe0
NiPoint3 PCBase::vfunc_18()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_18();
    return GameObject::vfunc_18();
}
MS2_REPLACE_METHOD(0x14166bbe0, PCBase, vfunc_18, 99, 0x024B508D);

// @0x14166bc50
NiPoint3 PCBase::vfunc_20()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_20();
    return GameObject::vfunc_20();
}
MS2_REPLACE_METHOD(0x14166bc50, PCBase, vfunc_20, 99, 0xA554E806);

// @0x14166bcc0
// MS2-FUNCTIONAL: the exe returns the efd::Point3 local with a plain 12-byte copy (its return type is efd::Point3); the
// NiPoint3 return of the GameObject slot converts through NiPoint3(const efd::Point3&).
NiPoint3 PCBase::vfunc_37()
{
    efd::Point3 kOffset(0, 0, 0);
    vfunc_51(&kOffset);
    if (Unk_GoAttachment* pAttach = vfunc_26())
        kOffset.z += pAttach->vfunc_6() * 0.5f;
    return kOffset;
}
MS2_REPLACE_METHOD(0x14166bcc0, PCBase, vfunc_37, 166, 0x76F42DDD);

// @0x14166bd70
Unk_GoAttachment* PCBase::vfunc_26()
{
    if (FUN_1416764d0())
        return FUN_1416764a0()->vfunc_26();
    return FUN_140a006f0(&m_unk_628);
}
MS2_REPLACE_METHOD(0x14166bd70, PCBase, vfunc_26, 83, 0x28C24E0F);

// @0x14166bdd0
// MS2-FUNCTIONAL: the exe materialises the distance test as an int temporary before narrowing it to the bool argument.
void PCBase::vfunc_32(bool b)
{
    if (m_spShadow) {
        m_spShadow->FUN_14160fe50(FUN_140f4a450() < 200000.0f);
        m_spShadow->FUN_14160feb0(m_unk_9a8, m_pos9ac, m_pos9b8, m_f9c8, b);
    }
}
MS2_REPLACE_METHOD(0x14166bdd0, PCBase, vfunc_32, 233, 0x2951F41F);

// @0x14166bec0
void PCBase::AnimActivated(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    m_spStateMgr->FUN_1417dbef0(pkManager, eSequenceID, pkSeq, fEventTime);
    if (m_unk_d20 != eSequenceID)
        FUN_141679e90();
}

// @0x14166bf40
// MS2-FUNCTIONAL: same calls and branches; the exe frame is 0x20 smaller (temporaries shared between the branches).
void PCBase::TextKeyEvent(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    const NiFixedString& kTextKey, const NiTextKeyMatch* pkMatchObject,
    NiControllerSequence* pkSeq, float fEventTime)
{
    if (strncmp(FUN_142087e50(kTextKey), "run", 3) == 0) {
        if (FUN_14166c930() != 0 && GetClassID() != 0x6200028)
            FUN_141475cf0()->FUN_141377420(this, CString(FUN_142087e50(kTextKey)));
    }
    else if (strncmp(FUN_142087e50(kTextKey), "walk", 4) == 0) {
        if (FUN_14166c930() != 0 && GetClassID() != 0x6200028)
            FUN_141475cf0()->FUN_141377420(this, CString(FUN_142087e50(kTextKey)));
    }
    else if (strncmp(FUN_142087e50(kTextKey), "effect_", 7) == 0) {
        CString strName(FUN_142087e50(kTextKey) + 7);
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = strName;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        kQuery.m_bEmotion = FUN_14166c930() == 0x35;
        FUN_1403ed280()->FUN_1411a4a00(&kQuery);
    }
    else if (strncmp(FUN_142087e50(kTextKey), "ani_eff_", 8) == 0) {
        CString strName(FUN_142087e50(kTextKey) + 8);
        Unk_PCBaseFxQuery kQuery;
        kQuery.m_strName = strName;
        kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
        kQuery.FUN_140a53190(FUN_14123c580());
        kQuery.m_bEmotion = FUN_14166c930() == 0x35;
        unsigned int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
        if (nHandle != 0) {
            m_unk_d20 = eSequenceID;
            m_vecD28.push_back(nHandle);
        }
    }
    if (eSequenceID == FUN_1409a1a00(pkManager) && m_b9d1 && kTextKey.GetLength() > 4) {
        if (strncmp(FUN_142087e50(kTextKey), "emo_", 4) == 0) {
            int nState = FUN_14166c930();
            FUN_14166ef10(CString(FUN_142087e50(kTextKey) + 4), true, 0, nState == 0x35);
        }
    }
    m_spStateMgr->FUN_1417dbf50(pkManager, eSequenceID, kTextKey, pkMatchObject, pkSeq, fEventTime);
}

// @0x14166c550
void PCBase::EndOfSequence(NiActorManager* pkManager, NiActorManager::SequenceID eSequenceID,
    NiControllerSequence* pkSeq, float fEventTime)
{
    m_spStateMgr->FUN_1417dbfc0(pkManager, eSequenceID, pkSeq, fEventTime);
}

// @0x14166c5b0
void PCBase::vfunc_23(int n)
{
    GameObject::vfunc_23(n);
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee != 0)
        spRidee->vfunc_23(n);
}
MS2_REPLACE_METHOD(0x14166c5b0, PCBase, vfunc_23, 133, 0x138B180B);

// @0x14166c640
void PCBase::vfunc_52(double fTime)
{
    if (GetClassID() != 0x6200016)
        FUN_14123c330(m_unk_748.FUN_1409705d0());
    float fScale = FUN_14123c260() / FUN_14123c2e0();
    if (fScale != m_fScaleA8) {
        BOOL bDown = m_fScaleA8 - fScale > 0.0f ? FALSE : TRUE;
        float fStep = 3.0f * (float)fTime;
        if (bDown)
            fStep = -fStep;
        fScale += fStep;
        if (bDown) {
            if (fScale < m_fScaleA8)
                fScale = m_fScaleA8;
        }
        else if (fScale > m_fScaleA8) {
            fScale = m_fScaleA8;
        }
        FUN_14123c280(fScale * FUN_14123c2e0());
    }
}
MS2_REPLACE_METHOD(0x14166c640, PCBase, vfunc_52, 392, 0xFE6B5ABE);

// @0x14166c7d0
int PCBase::vfunc_57()
{
    return 0;
}

// @0x14166c7e0
int PCBase::vfunc_58()
{
    return 3;
}

// @0x14166c800
void PCBase::vfunc_59(int nState, StateData* pData, int nSub, int bForce)
{
    if (m_unk_b4 == 0) {
        m_unk_c48 = nState;
        m_unk_c50.AssignRaw(pData);
        m_unk_c60 = nSub;
        m_unk_c64 = bForce;
    }
    else {
        if (m_spStateMgr->FUN_1417db270() == 0x21 && m_spB10 != 0) {
            m_spB10->vfunc_59(nState, pData, nSub, bForce);
            return;
        }
        m_spStateMgr->FUN_1417dafa0(nState, pData, nSub, bForce);
    }
}
MS2_REPLACE_METHOD(0x14166c800, PCBase, vfunc_59, 292, 0xAA88E2C6);

// @0x14166c930
int PCBase::FUN_14166c930()
{
    return m_spStateMgr->FUN_1417db270();
}
MS2_REPLACE_METHOD(0x14166c930, PCBase, FUN_14166c930, 41, 0xB1D51893);

// @0x14166c960
int PCBase::FUN_14166c960()
{
    return m_unk_c48;
}

// @0x14166c980
int PCBase::FUN_14166c980()
{
    return m_spStateMgr->FUN_1417db2c0();
}
MS2_REPLACE_METHOD(0x14166c980, PCBase, FUN_14166c980, 41, 0x7E67C403);

// @0x14166c9b0
CString PCBase::vfunc_60()
{
    return "";
}

// @0x14166ca00
int PCBase::vfunc_61()
{
    return 0;
}

// @0x14166ca10
bool PCBase::vfunc_62()
{
    return false;
}

// @0x14166ca20
void PCBase::FUN_14166ca20(unsigned int nReason)
{
    if (FUN_14166cb00(nReason) == true)
        return;
    m_unk_c08.FUN_140d75120(nReason, true);
    FUN_14166cb30();
}
MS2_REPLACE_METHOD(0x14166ca20, PCBase, FUN_14166ca20, 78, 0x7DD9BEF0);

// @0x14166ca80
void PCBase::FUN_14166ca80(unsigned int nReason)
{
    if (!FUN_14166cb00(nReason))
        return;
    m_unk_c08.Reset(nReason);
    FUN_14166cb30();
}
MS2_REPLACE_METHOD(0x14166ca80, PCBase, FUN_14166ca80, 74, 0x9A398081);

// @0x14166cad0
bool PCBase::FUN_14166cad0()
{
    return m_unk_c08.Any();
}

// @0x14166cb00
bool PCBase::FUN_14166cb00(unsigned int nReason)
{
    return m_unk_c08.FUN_140d75240(nReason);
}
MS2_REPLACE_METHOD(0x14166cb00, PCBase, FUN_14166cb00, 41, 0x8EEE3358);

// @0x14166cb30
void PCBase::FUN_14166cb30()
{
    if (FUN_14166cad0()) {
        vfunc_23(1);
        FUN_14123cb20(false);
        efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
        if (spRidee != 0) {
            if (m_unk_c08.Count() == 1 && m_unk_c08.FUN_140d75240(2))
                spRidee->vfunc_23(0);
        }
    }
    else {
        vfunc_23(0);
        FUN_14123cb20(true);
    }
}
MS2_REPLACE_METHOD(0x14166cb30, PCBase, FUN_14166cb30, 260, 0x3EF2F43D);

// @0x14166cc40
void PCBase::FUN_14166cc40(int nValue)
{
    m_spStateMgr->FUN_1417db230(nValue);
}
MS2_REPLACE_METHOD(0x14166cc40, PCBase, FUN_14166cc40, 49, 0x3714E64A);

// @0x14166cc80
int PCBase::FUN_14166cc80()
{
    return m_spStateMgr->FUN_1417db290();
}
MS2_REPLACE_METHOD(0x14166cc80, PCBase, FUN_14166cc80, 41, 0x305EC96C);

// @0x14166ccb0
State* PCBase::FUN_14166ccb0()
{
    return m_spStateMgr->FUN_1417db1c0();
}
MS2_REPLACE_METHOD(0x14166ccb0, PCBase, FUN_14166ccb0, 41, 0x7B781849);

// @0x14166cce0
void PCBase::FUN_14166cce0(unsigned int nFlags)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_14166cce0(nFlags);
    m_unk_158 |= nFlags;
}
MS2_REPLACE_METHOD(0x14166cce0, PCBase, FUN_14166cce0, 126, 0xFCEF1179);

// @0x14166cd70
void PCBase::FUN_14166cd70(unsigned int nFlags)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_14166cd70(nFlags);
    m_unk_158 &= ~nFlags;
}
MS2_REPLACE_METHOD(0x14166cd70, PCBase, FUN_14166cd70, 130, 0xF904541E);

// @0x14166ce00
int PCBase::vfunc_63()
{
    if (m_unk_158 != 0)
        return 0;
    return 1;
}

// @0x14166ce30
int PCBase::FUN_14166ce30()
{
    return m_unk_15c;
}

// @0x14166ce50
void PCBase::FUN_14166ce50(int n)
{
    m_unk_15c = n;
}

// @0x14166ce70
void PCBase::FUN_14166ce70(int nEmotion)
{
    if (m_unk_160 != nEmotion) {
        m_unk_160 = nEmotion;
        vfunc_66(nEmotion);
    }
}
MS2_REPLACE_METHOD(0x14166ce70, PCBase, FUN_14166ce70, 73, 0xEEB9D1DF);

// @0x14166cec0
int PCBase::vfunc_64()
{
    return 0;
}

// @0x14166ced0
int PCBase::vfunc_65()
{
    return m_unk_160;
}

// @0x14166cef0
void PCBase::vfunc_66(int n)
{
    if (m_spStateMgr.get())
        m_spStateMgr->FUN_1417dc020(n);
}
MS2_REPLACE_METHOD(0x14166cef0, PCBase, vfunc_66, 73, 0x590E688A);

// @0x14166d220
Unk_PCBaseBody* PCBase::FUN_14166d220()
{
    return m_unk_150;
}

// @0x14166d240
void* PCBase::FUN_14166d240()
{
    return m_unk_6d8;
}

// @0x14166d260
void PCBase::FUN_14166d260()
{
    if (Unk_PCBaseBody* pBody = FUN_14166d220())
        pBody->FUN_14123fe70(vfunc_18());
}
MS2_REPLACE_METHOD(0x14166d260, PCBase, FUN_14166d260, 98, 0x6C91CBAE);

// @0x14166d2d0
// MS2-FUNCTIONAL: temporaries of the mount branch are laid out differently (frame 0x70).
void PCBase::FUN_14166d2d0(const efd::Point3& kTarget, int bTurn)
{
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee != 0)
        spRidee->FUN_14166d430(kTarget - spRidee->vfunc_18(), bTurn, 1);
    else
        FUN_14166d430(kTarget - vfunc_18(), bTurn, 1);
}
MS2_REPLACE_METHOD(0x14166d2d0, PCBase, FUN_14166d2d0, 331, 0xBA911878);

// @0x14166d430
void PCBase::FUN_14166d430(efd::Point3 kDir, int bTurn, int bResetTilt)
{
    kDir = -kDir;
    kDir.z = 0;
    kDir.Unitize();
    efd::Point3 kRight = kDir.Cross(efd::Point3::UNIT_Z);
    efd::Point3 kUp = kRight.Cross(efd::Point3::UNIT_Z);
    NiMatrix3 kRot;
    kRot.SetCol(0, kRight);
    kRot.SetCol(1, kUp);
    kRot.SetCol(2, efd::Point3::UNIT_Z);
    float fX, fY, fZ;
    kRot.ToEulerAnglesXYZ(fX, fY, fZ);
    efd::Point3 kAngles(0, 0, fZ * 180.0f / 3.1415927f);
    FUN_140291b70(&kAngles.z);
    FUN_14166d8b0(kAngles.z);
    if (bResetTilt) {
        efd::Point3 kZero = efd::Point3::ZERO;
        vfunc_22(kZero);
    }
    if (bTurn)
        vfunc_21(kAngles);
}
MS2_REPLACE_METHOD(0x14166d430, PCBase, FUN_14166d430, 493, 0x7EEA4855);

// @0x14166d630
// MS2-FUNCTIONAL: the exe passes the NiPoint3 local to slot 21 with a single 12-byte copy (one temporary less).
void PCBase::FUN_14166d630(float fTime)
{
    NiPoint3 kRot = vfunc_20();
    if (kRot.z == m_f934)
        return;
    FUN_140291b70(&m_f934);
    if (kRot.z < m_f934) {
        if (m_f934 - kRot.z > 180.0f)
            kRot.z -= FUN_14166dab0() * fTime;
        else
            kRot.z += FUN_14166dab0() * fTime;
        if (kRot.z > m_f934)
            kRot.z = m_f934;
    }
    else if (kRot.z > m_f934) {
        if (kRot.z - m_f934 > 180.0f)
            kRot.z += FUN_14166dab0() * fTime;
        else
            kRot.z -= FUN_14166dab0() * fTime;
        if (kRot.z < m_f934)
            kRot.z = m_f934;
    }
    FUN_140291bc0(&kRot);
    vfunc_21(kRot);
}
MS2_REPLACE_METHOD(0x14166d630, PCBase, FUN_14166d630, 480, 0x758C90FC);

// @0x14166d820
void PCBase::FUN_14166d820()
{
    NiPoint3 kLook = FUN_14123c360();
    if (kLook != efd::Point3::ZERO) {
        efd::Point3 kA;
        efd::Point3 kB;
        vfunc_67(&kA, &kB);
        FUN_14166d8b0(FUN_14166dad0(kLook, kB));
    }
}
MS2_REPLACE_METHOD(0x14166d820, PCBase, FUN_14166d820, 135, 0xF230AF85);

// @0x14166d8b0
void PCBase::FUN_14166d8b0(float fAngle)
{
    m_f934 = fAngle;
}

// @0x14166d8e0
// MS2-FUNCTIONAL: the exe copies kTilt into a local before the slot-22 call.
void PCBase::FUN_14166d8e0(efd::Point3 kTilt)
{
    vfunc_22(kTilt);
    FUN_14166d820();
    NiPoint3 kRot = vfunc_20();
    kRot.z = FUN_14166da40();
    FUN_14166d970(kRot);
}
MS2_REPLACE_METHOD(0x14166d8e0, PCBase, FUN_14166d8e0, 132, 0x81D98B51);

// @0x14166d970
void PCBase::FUN_14166d970(efd::Point3 kRot)
{
    FUN_14166d8b0(kRot.z);
    vfunc_21(kRot);
}
MS2_REPLACE_METHOD(0x14166d970, PCBase, FUN_14166d970, 87, 0x4BF2CA41);

// @0x14166d9d0
void PCBase::FUN_14166d9d0(const NiPoint3& kPos)
{
    m_pos920 = kPos;
}
MS2_REPLACE_METHOD(0x14166d9d0, PCBase, FUN_14166d9d0, 43, 0x3F019449);

// @0x14166da10
void PCBase::FUN_14166da10(float fSpeed)
{
    m_fTurnSpeed = fSpeed;
}

// @0x14166da40
float PCBase::FUN_14166da40()
{
    return m_f934;
}

// @0x14166da60
float PCBase::FUN_14166da60()
{
    return m_f930 * ((float)m_unk_1c0[2][0x16] / 100.0f);
}

// @0x14166dab0
float PCBase::FUN_14166dab0()
{
    return m_fTurnSpeed;
}

// @0x14166dad0
// MS2-FUNCTIONAL: the exe spills the second degree term to a temporary before the add.
float PCBase::FUN_14166dad0(const efd::Point3& kLook, const efd::Point3& kDir)
{
    float fA = atan2f(kDir.y, kDir.x);
    float fB = atan2f(kLook.x, kLook.y);
    float fAngle = fA * 180.0f / 3.1415927f + fB * 180.0f / 3.1415927f;
    if (fAngle < 0.0f)
        fAngle += 360.0f;
    if (fAngle >= 360.0f)
        fAngle -= 360.0f;
    return fAngle;
}
MS2_REPLACE_METHOD(0x14166dad0, PCBase, FUN_14166dad0, 210, 0x20A23D56);

// @0x14166dbb0
NiPoint3 PCBase::FUN_14166dbb0()
{
    return m_pos920;
}

// @0x14166dbf0
CString PCBase::FUN_14166dbf0(const efd::utf8string& kName)
{
    return m_spAnimMgr->FUN_14099ddb0(kName);
}
MS2_REPLACE_METHOD(0x14166dbf0, PCBase, FUN_14166dbf0, 83, 0xADE5A5FD);

// @0x14166dc50
CString PCBase::FUN_14166dc50()
{
    return CString(FUN_141b6f910()->FUN_140b7cc50(FUN_14123c460()).c_str());
}
MS2_REPLACE_METHOD(0x14166dc50, PCBase, FUN_14166dc50, 190, 0x36C8CC31);

// @0x14166dd20
bool PCBase::FUN_14166dd20(const efd::utf8string& strAnim, float fSpeed, bool bA, bool bB)
{
    m_unk_968 = bB;
    if (m_unk_968 != 0)
        fSpeed = 1.0f;
    return m_spAnimMgr->FUN_14099e050(const_cast<efd::utf8string&>(strAnim), fSpeed, bA);
}
MS2_REPLACE_METHOD(0x14166dd20, PCBase, FUN_14166dd20, 116, 0x26C26AF1);

// @0x14166dda0
bool PCBase::FUN_14166dda0(int nId)
{
    return FUN_14166dd20(vfunc_123(nId), FUN_1416713c0(), false, false);
}

// @0x14166de50
void PCBase::FUN_14166de50(float fOffset)
{
    m_spAnimMgr->FUN_14099e710(fOffset);
}
MS2_REPLACE_METHOD(0x14166de50, PCBase, FUN_14166de50, 51, 0x1292505D);
