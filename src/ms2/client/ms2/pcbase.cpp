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
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/fielddatacli.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/animationmanager.h"
#include "ms2/placeholder/state.h"
#include "ms2/commonfiles/rideonaction.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <efd/Matrix3.h>
#include <algorithm>
#include <NiMatrix3.h>
#include <NiFixedString.h>

// ---- unit-local placeholders ----

// The lazily created per-actor components (vfunc_80..87, 103/104). Their exe types are UI entities:
// a58 UIHpBar, a68 UIShieldBar, a78 UINameTag, a88 UIEmoticon, a98 UIBuffBalloon, aa8 UIChatBalloon,
// ab8 UIPopupProfileImage, ac8 UIBanner (::Entity each).
class Unk_PCBaseComp_a58 : public CPtred
{
public:
    void FUN_141992140(int bShow);
    int FUN_141992160();
    void FUN_141992180(__int64 nCur, __int64 nMax);
    void FUN_141992230(__int64 nCur, __int64 nMax);                 // UIHpBar::Entity, set hp
};
class Unk_PCBaseComp_a68 : public CPtred
{
public:
    void FUN_140e85fc0(__int64 nCur, __int64 nMax);                 // UIShieldBar::Entity, set shield
    void FUN_140e85ed0(int bShow);
    void FUN_140e85f10(__int64 nCur, __int64 nMax);
};
class Unk_PCBaseComp_a78 : public CPtred {};
class Unk_PCBaseComp_a88 : public CPtred {};
class Unk_PCBaseComp_a98 : public CPtred {};
class Unk_PCBaseComp_aa8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // refresh
    void FUN_1418fb730(const CStringW& strText);                    // UIChatBalloon::Entity, set the text
};
class Unk_PCBaseTextFilter
{
public:
    void FUN_1416fb340(CStringW& strText);
};
Unk_PCBaseTextFilter* FUN_1403b4750();
class Unk_PCBaseComp_ab8 : public CPtred {};
class Unk_PCBaseComp_ac8 : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();                                         // show
    virtual void vfunc_3();                                         // hide
    void FUN_140ba8720(int nType);                                  // UIBanner::Entity
};
class Unk_PCBaseComp_b18 : public CPtred
{
public:
    int FUN_141759960();
    int FUN_141759e40();

    char m_pad_10[0x28 - sizeof(CPtred)];
    __int64 m_nTagId;                                               // +0x28
    char m_pad_30[0x8c - 0x30];
    int m_n8c;                                                      // +0x8c
};
void FUN_1417ea750(PCBase* pActor, MS2Ptr<Unk_PCBaseComp_b18> spItem);

// CColorBoostData (0x20; ?\colorboostdata.cpp).
class CColorBoostData
{
public:
    CColorBoostData(float a, float b, float c);                     // 0x14109b6b0
    virtual ~CColorBoostData();                                     // 0x14109b750
private:
    bool m_b08;
    float m_f0c;                                                    // start time
    float m_f10;
    float m_f14;                                                    // duration
    float m_f18;
    float m_f1c;
};

// The buffs' extra members (FUN_141674bc0 / FUN_141675240).
class Unk_PCBaseBuffsEx : public Unk_PCBaseBuffList
{
public:
    int FUN_140970990();
    unsigned int FUN_140970bf0();                                   // skill-use disable mask
    void FUN_1409711c0();
};

int FUN_1417e9330(State* pState);                                 // the skill state's skill id

extern const NiRTTI DAT_143ad1588;                                  // EffectNode::ms_RTTI

// TSingleton<CBattleRecordManager> (vfunc_113).
class Unk_PCBaseBattleRecord
{
public:
    void FUN_140a04ef0(void* p);
};
Unk_PCBaseBattleRecord* FUN_140e09140();

// MS2Ptr members instantiated by other objs.
template <> MS2Ptr<CSkillRecord>::~MS2Ptr();                                            // 0x140975740
template <> MS2Ptr<Unk_RideeData>::~MS2Ptr();                                           // 0x140788ed0
template <> Unk_RideeData* MS2Ptr<Unk_RideeData>::operator->() const;                   // 0x1407895d0

// The argument of vfunc_71/73 (passed as MS2Ptr by value; the callee releases it).
class Unk_PCBaseFxSet : public CPtred
{
public:
    CString FUN_1411bd0c0(int n);
    char m_pad[0x28];
    CAtlArray<CString> m_arrEffects;                                // +0x40 effect names
};
MS2_CHECK_OFFSET(Unk_PCBaseFxSet, m_arrEffects, 0x40);
class Unk_PCBaseFxSource : public CPtred
{
public:
    virtual void vfunc_1();
    virtual MS2Ptr<Unk_PCBaseFxSet> vfunc_2(void* pKey);
};
class Unk_PCBaseEmoPlayer : public CPtred
{
public:
    void FUN_141848650();
    bool FUN_141848740(int nTime);
};
class Unk_PCBaseState0b : public State
{
public:
    int FUN_1417c4320();
};
class Unk_PCBaseState0f : public State
{
public:
    int FUN_1417c6a30();
};
class Unk_PCBaseSpawnMgr
{
public:
    void FUN_1411bf1b0();
};
Unk_PCBaseSpawnMgr* FUN_140a50010();

// The stat formula service (FUN_1401c0db0; blackmarketitemoption / usermail use other slices of it).
class Unk_PCBaseFormula
{
public:
    float FUN_140674100(__int64 nStat, int nBonus);                // move speed
    float FUN_140674290(__int64 nStat);                             // move speed of a 0x6200045 actor
    void FUN_140674420(__int64 nStat, float f);
};
Unk_PCBaseFormula* FUN_1401c0db0();

// An entity seen through its property getters.
class Unk_PCBaseEntity
{
public:
    int FUN_1408a2060(unsigned int uiPropId, efd::utf8string* pOut);   // string property
    void FUN_140ae1160(unsigned int uiPropId, unsigned short* pOut);  // short property
};
class Unk_PCBaseHitReport
{
public:
    Unk_PCBaseEntity* FUN_140cfaff0();                              // the entity stood on
};

// A physics ray query (physxhelper.h's Unk_RayCastInfo; 0x68).
struct Unk_PCBaseRayHit
{
    Unk_PCBaseRayHit();                                             // 0x140ad4440
    efd::Point3 m_origin;                                           // +0x00
    efd::Point3 m_dir;                                              // +0x0c
    float m_maxDist;                                                // +0x18
    int m_groups;                                                   // +0x1c
    void* m_20;
    void* m_28;
    void* m_hitEntity;                                              // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                                // +0x48
    efd::Point3 m_hitPoint;                                         // +0x4c
    efd::Point3 m_hitNormal;                                        // +0x58
};
MS2_CHECK_SIZE(Unk_PCBaseRayHit, 0x68);
class Unk_PCBasePhysX
{
public:
    int FUN_14168a310(const NiPoint3& kFrom, NiPoint3* pHit, Unk_PCBaseRayHit* pInfo, float fMaxDist, NiPoint3* pNormal, int nB);
};
Unk_PCBasePhysX* FUN_1409f7ca0();
float FUN_14028d380(float fValue);                                  // percent (x100)
int FUN_14082f1a0(int nType);                                       // stat kind: 0 = 32-bit value

// The physics/controller body of an actor (0xf8; gameobject unit 0x14123f2d0..0x141241300).
class GameObjectControllerHitReport;
class Unk_PCBaseBody
{
public:
    Unk_PCBaseBody();                                               // 0x14123f2d0
    ~Unk_PCBaseBody();                                              // 0x14123f460
    void FUN_14123f5b0(PCBase* pOwner, void* pEntity, efd::Point3 kPos, float fHeight, float fRadius);
    void FUN_14123fd30(int nGroup);
    void FUN_14123fbf0(short nMode);
    NiPoint3 FUN_141240df0();                                       // ground normal
    int FUN_141240ed0();                                            // collision flags
    int FUN_141240ef0();                                            // slope limit
    Unk_PCBaseHitReport* FUN_141240f20();
    int FUN_141240f40();                                            // grounded
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

// CString + const char* (the exe's out-of-line operator+; compiling it here needs the unresolvable MFC CopyChars import).
CString FUN_14038f6d0(const CString& str, const char* psz);

// The node smart pointers at +0xbe8 / +0xc38 / +0xc40.
// The entity manager (0x1409670f0) and its lookup / property getter.
class Unk_PCBaseEntMgr;
Unk_PCBaseEntMgr* FUN_1409670f0();
egf::Entity* FUN_1411cf440(Unk_PCBaseEntMgr* pMgr, const egf::EntityID& kId);
void FUN_1409618c0(egf::Entity* pEntity, unsigned int nPropId, NiPoint3& kValue);
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
    void FUN_1411a6060(int nHandle);                                // stop
};
Unk_PCBaseFxMgr* FUN_1403ed280();

class Unk_PCBaseWorld
{
public:
    int FUN_141bd1a10(PCBase* pActor);
    class Unk_PCBaseWorldActor* FUN_141bd13a0(int nId);
    PCBase* FUN_141bd0cc0();                                        // the local player
    class Unk_PCBaseWorldObj* FUN_141bd1200(int nId);
    MS2Ptr<CFieldDataCli> FUN_141bd30a0();                          // the current field data
};
Unk_PCBaseWorld* FUN_1403ed2d0();

// The action container at +0xd00 (?\actioncontainer.cpp).
class Unk_PCBaseActions : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int n);
    virtual CString vfunc_5(int n);
    virtual CString vfunc_6(int a, int b);
    virtual std::vector<CString>* vfunc_7(int nKey);                // sequence names
};
// The action containers (0x1414a5860).
class Unk_PCBaseActionsMgr
{
public:
    MS2Ptr<Unk_PCBaseActions> FUN_1409494e0(int nId);
};
Unk_PCBaseActionsMgr* FUN_1414a5860();

// The world object found by id (FUN_141676a10).
class Unk_PCBaseWorldObj
{
public:
    void* FUN_1409ffc60();
};

// The actor found by id (vfunc_111).
class Unk_PCBaseWorldActor
{
public:
    unsigned int FUN_141094f40();                                   // the owner's id
};

// The damage UIs (vfunc_111/112).
class Unk_PCBaseDamageUI
{
public:
    void FUN_141911e90(PCBase* pActor, __int64 nValue, int nType, int nTargetId, void* pPos);
};
Unk_PCBaseDamageUI* FUN_140b624b0(int nId);
class Unk_PCBaseDamageLog
{
public:
    int FUN_1419299e0();
    void FUN_141929a00(__int64 nValue, int nType);
};
Unk_PCBaseDamageLog* FUN_14167a900(int nId);
class Unk_PCBaseTargetUI
{
public:
    void FUN_1419df2a0(PCBase* pActor);
};
Unk_PCBaseTargetUI* FUN_141531aa0(int nId);
class Unk_PCBaseUpperHpBar
{
public:
    void FUN_141b4c510(PCBase* pActor, int nId);                    // UIUpperHpBar
};
Unk_PCBaseUpperHpBar* FUN_14096e340(int nId);

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
    unsigned int FUN_140999490(const egf::EntityID& kId, const efd::utf8string& strName);   // GetAnimationIdFromName
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
void FUN_141a60f00(int nActorId);                                   // name tag text
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
    m_spC38 = 0;
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

// @0x14166f6d0
int PCBase::FUN_14166f6d0()
{
    if (FUN_14166c930() == 0xb)
        return static_cast<Unk_PCBaseState0b*>(FUN_14166ccb0())->FUN_1417c4320();
    if (FUN_14166c930() == 0xf)
        return static_cast<Unk_PCBaseState0f*>(FUN_14166ccb0())->FUN_1417c6a30();
    return 0;
}
MS2_REPLACE_METHOD(0x14166f6d0, PCBase, FUN_14166f6d0, 100, 0xE80CDCB9);

// @0x14166f790
bool PCBase::FUN_14166f790(void* pKey, CString& strOut, int n)
{
    if (m_spD10 == 0) {
        MS2_ASSERT_AT(0x4c5, 0);
        return false;
    }
    MS2Ptr<Unk_PCBaseFxSet> spSet = m_spD10->vfunc_2(pKey);
    if (spSet == 0)
        return false;
    strOut = spSet->FUN_1411bd0c0(n);
    return strOut.IsEmpty() ? false : true;
}
MS2_REPLACE_METHOD(0x14166f790, PCBase, FUN_14166f790, 336, 0x1E9BA79D);

// @0x14166f940
void PCBase::FUN_14166f940()
{
    if (m_timer9e8.FUN_140868ba0() != 0) {
        int nTime = m_timer9e8.FUN_140868a70();
        bool bBusy = false;
        if (m_sp638.get() != 0 && m_sp638->FUN_141848740(nTime))
            bBusy = true;
        if (!bBusy)
            FUN_14166f8f0(0, 1);
    }
}
MS2_REPLACE_METHOD(0x14166f940, PCBase, FUN_14166f940, 159, 0x60041217);

// @0x14166f9f0
int PCBase::vfunc_69()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166f9f0, PCBase, vfunc_69, 8, 0x7F371472);

// @0x14166fa00
void PCBase::vfunc_70()
{
    FUN_140a50010()->FUN_1411bf1b0();
}
MS2_REPLACE_METHOD(0x14166fa00, PCBase, vfunc_70, 27, 0x7E5CDCB1);

// @0x14166fa30
void PCBase::vfunc_71(MS2Ptr<Unk_PCBaseFxSet> spSet)
{
}
MS2_REPLACE_METHOD(0x14166fa30, PCBase, vfunc_71, 29, 0x0BDFA7F1);

// @0x14166fa60
void PCBase::vfunc_72()
{
}

// @0x14166fa70
void PCBase::vfunc_73(MS2Ptr<Unk_PCBaseFxSet> spSet, int bFx)
{
    if (spSet == 0)
        return;
    if (m_unk_a50 != 0 && bFx != 0) {
        for (unsigned int i = 0; i < spSet->m_arrEffects.GetCount(); i++) {
            Unk_PCBaseFxQuery kQuery;
            kQuery.m_strName = spSet->m_arrEffects[i];
            kQuery.m_nPlayer = FUN_1403ed2d0()->FUN_141bd1a10(this);
            kQuery.FUN_140a53190(FUN_14123c580());
            unsigned int nHandle = FUN_1403ed280()->FUN_1411a49c0(&kQuery);
            m_arrA30.Add(nHandle);
        }
    }
}
MS2_REPLACE_METHOD(0x14166fa70, PCBase, vfunc_73, 376, 0xE3593D94);

// @0x14166fbf0
void PCBase::vfunc_74(__int64 nCur, __int64 nMax)
{
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0)
        spBar->FUN_141992230(nCur, nMax);
}
MS2_REPLACE_METHOD(0x14166fbf0, PCBase, vfunc_74, 112, 0x3B69713E);

// @0x14166fc70
void PCBase::vfunc_75(__int64 nCur, __int64 nMax)
{
    MS2Ptr<Unk_PCBaseComp_a68> spBar = vfunc_81();
    if (spBar.get() != 0)
        spBar->FUN_140e85fc0(nCur, nMax);
}
MS2_REPLACE_METHOD(0x14166fc70, PCBase, vfunc_75, 112, 0x44FD6E43);

// @0x14166fcf0
void PCBase::vfunc_76(CStringW str)
{
    m_strW918 = str;
    FUN_141a60f00(m_unk_70);
}
MS2_REPLACE_METHOD(0x14166fcf0, PCBase, vfunc_76, 78, 0x72F191E4);

// @0x14166fd50
CStringW PCBase::vfunc_77()
{
    return m_strW918;
}
MS2_REPLACE_METHOD(0x14166fd50, PCBase, vfunc_77, 68, 0x928E7FA5);

// @0x14166fff0
void PCBase::FUN_14166fff0(CStringW str)
{
    vfunc_94(0);
    FUN_1403b4750()->FUN_1416fb340(str);
    MS2Ptr<Unk_PCBaseComp_aa8> spBalloon = vfunc_85();
    if (spBalloon.get() != 0) {
        spBalloon->FUN_1418fb730(str);
        spBalloon->vfunc_2();
    }
}
MS2_REPLACE_METHOD(0x14166fff0, PCBase, FUN_14166fff0, 184, 0xF815B00C);

// @0x14166fda0
int PCBase::vfunc_78()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166fda0, PCBase, vfunc_78, 8, 0x7F371472);

// @0x14166fdb0
void PCBase::vfunc_79()
{
    vfunc_78();
}
MS2_REPLACE_METHOD(0x14166fdb0, PCBase, vfunc_79, 33, 0xAE300131);

// @0x14166fde0
MS2Ptr<Unk_PCBaseComp_a58> PCBase::vfunc_80()
{
    return MS2Ptr<Unk_PCBaseComp_a58>(0);
}
MS2_REPLACE_METHOD(0x14166fde0, PCBase, vfunc_80, 55, 0x634E2F19);

// @0x14166fe20
MS2Ptr<Unk_PCBaseComp_a68> PCBase::vfunc_81()
{
    return MS2Ptr<Unk_PCBaseComp_a68>(0);
}
MS2_REPLACE_METHOD(0x14166fe20, PCBase, vfunc_81, 55, 0x726A9F94);

// @0x14166fe60
MS2Ptr<Unk_PCBaseComp_a78> PCBase::vfunc_82()
{
    return MS2Ptr<Unk_PCBaseComp_a78>(0);
}
MS2_REPLACE_METHOD(0x14166fe60, PCBase, vfunc_82, 55, 0x8DF18BD0);

// @0x14166fea0
MS2Ptr<Unk_PCBaseComp_a88> PCBase::vfunc_83()
{
    return MS2Ptr<Unk_PCBaseComp_a88>(0);
}
MS2_REPLACE_METHOD(0x14166fea0, PCBase, vfunc_83, 55, 0x74036550);

// @0x14166fee0
MS2Ptr<Unk_PCBaseComp_a98> PCBase::vfunc_84()
{
    return MS2Ptr<Unk_PCBaseComp_a98>(0);
}
MS2_REPLACE_METHOD(0x14166fee0, PCBase, vfunc_84, 55, 0xCD6979FF);

// @0x14166ff20
MS2Ptr<Unk_PCBaseComp_aa8> PCBase::vfunc_85()
{
    return MS2Ptr<Unk_PCBaseComp_aa8>(0);
}
MS2_REPLACE_METHOD(0x14166ff20, PCBase, vfunc_85, 55, 0xB27808D8);

// @0x14166ff60
MS2Ptr<Unk_PCBaseComp_ab8> PCBase::vfunc_86()
{
    return MS2Ptr<Unk_PCBaseComp_ab8>(0);
}
MS2_REPLACE_METHOD(0x14166ff60, PCBase, vfunc_86, 55, 0x895D3E07);

// @0x14166ffa0
MS2Ptr<Unk_PCBaseComp_ac8> PCBase::vfunc_87()
{
    return MS2Ptr<Unk_PCBaseComp_ac8>(0);
}
MS2_REPLACE_METHOD(0x14166ffa0, PCBase, vfunc_87, 55, 0xEA2BBE0A);

// @0x14166ffe0
int PCBase::vfunc_88()
{
    return 0;
}
MS2_REPLACE_METHOD(0x14166ffe0, PCBase, vfunc_88, 8, 0x7F371472);

// @0x14166e0d0
efd::utf8string& PCBase::FUN_14166e0d0()
{
    return m_spAnimMgr->FUN_140a53f90();
}
MS2_REPLACE_METHOD(0x14166e0d0, PCBase, FUN_14166e0d0, 39, 0x04A60983);

// @0x14166e0a0
void PCBase::FUN_14166e0a0()
{
    m_spAnimMgr->FUN_14099e680();
}
MS2_REPLACE_METHOD(0x14166e0a0, PCBase, FUN_14166e0a0, 39, 0x4949AA37);

// @0x14166ed10
bool PCBase::FUN_14166ed10()
{
    return m_b9d0;
}
MS2_REPLACE_METHOD(0x14166ed10, PCBase, FUN_14166ed10, 18, 0x00EA9B7C);

// @0x14166ed30
void PCBase::FUN_14166ed30(bool b)
{
    m_b9d0 = b;
}
MS2_REPLACE_METHOD(0x14166ed30, PCBase, FUN_14166ed30, 26, 0xEF65E47C);

// @0x14166ed50
void PCBase::FUN_14166ed50(bool b)
{
    m_b9d1 = b;
}
MS2_REPLACE_METHOD(0x14166ed50, PCBase, FUN_14166ed50, 26, 0x97B64443);

// @0x14166f740
CString PCBase::FUN_14166f740()
{
    return m_str9e0;
}
MS2_REPLACE_METHOD(0x14166f740, PCBase, FUN_14166f740, 68, 0xC97EA0D3);

// @0x14166f8f0
void PCBase::FUN_14166f8f0(int nA, int nB)
{
    FUN_14166ed50(true);
    FUN_14166ef10(m_str9d8, nA, nB, false);
}
MS2_REPLACE_METHOD(0x14166f8f0, PCBase, FUN_14166f8f0, 74, 0x17B9A2EE);

// @0x141670330
void PCBase::FUN_141670330(float f)
{
    m_f170 = f;
}
MS2_REPLACE_METHOD(0x141670330, PCBase, FUN_141670330, 31, 0xF6772D25);

// @0x141670360
void PCBase::FUN_141670360(float f)
{
    m_f174 = f;
}
MS2_REPLACE_METHOD(0x141670360, PCBase, FUN_141670360, 31, 0x5BDAD799);

// @0x141670430
float PCBase::FUN_141670430()
{
    return m_f178;
}
MS2_REPLACE_METHOD(0x141670430, PCBase, FUN_141670430, 19, 0x040BA781);

// @0x141670500
float PCBase::FUN_141670500()
{
    return m_f168;
}
MS2_REPLACE_METHOD(0x141670500, PCBase, FUN_141670500, 19, 0x99972B51);

// @0x141670520
float PCBase::FUN_141670520()
{
    return m_f17c;
}
MS2_REPLACE_METHOD(0x141670520, PCBase, FUN_141670520, 19, 0x9EAB230D);

// @0x141670990
__int64 PCBase::FUN_141670990(int nKind, int nStat)
{
    return m_unk_1c0[nKind][nStat];
}
MS2_REPLACE_METHOD(0x141670990, PCBase, FUN_141670990, 49, 0xFF3D117E);

// @0x1416709d0
__int64 PCBase::FUN_1416709d0(int nStat)
{
    return m_unk_1c0[1][nStat];
}
MS2_REPLACE_METHOD(0x1416709d0, PCBase, FUN_1416709d0, 41, 0x1193CA91);

// @0x141670a00
__int64 PCBase::FUN_141670a00(int nStat)
{
    return m_unk_1c0[2][nStat];
}
MS2_REPLACE_METHOD(0x141670a00, PCBase, FUN_141670a00, 41, 0xE53E749A);

// @0x141670a30
__int64 PCBase::FUN_141670a30(int nStat)
{
    return m_unk_1c0[0][nStat];
}
MS2_REPLACE_METHOD(0x141670a30, PCBase, FUN_141670a30, 41, 0x740EAF44);

// @0x141670a60
__int64 PCBase::FUN_141670a60(int nStat)
{
    return m_unk_508[nStat];
}
MS2_REPLACE_METHOD(0x141670a60, PCBase, FUN_141670a60, 28, 0x0DFD3A6B);

// @0x141670d50
void PCBase::FUN_141670d50(efd::Point2 kSize)
{
    m_unk_620 = kSize;
}
MS2_REPLACE_METHOD(0x141670d50, PCBase, FUN_141670d50, 28, 0x9913344D);

// @0x141670d80
void PCBase::FUN_141670d80(float fSpeed)
{
    m_f938 = fSpeed;
}
MS2_REPLACE_METHOD(0x141670d80, PCBase, FUN_141670d80, 31, 0x98CE89D5);

// @0x141670db0
void PCBase::FUN_141670db0(CString str)
{
    m_str940 = str;
}
MS2_REPLACE_METHOD(0x141670db0, PCBase, FUN_141670db0, 65, 0x35877EDC);

// @0x141670e00
void PCBase::FUN_141670e00(CString str)
{
    m_str948 = str;
}
MS2_REPLACE_METHOD(0x141670e00, PCBase, FUN_141670e00, 65, 0x4B4FE054);

// @0x141670e50
void PCBase::FUN_141670e50(CString str)
{
    m_str960 = str;
}
MS2_REPLACE_METHOD(0x141670e50, PCBase, FUN_141670e50, 65, 0x796101FC);

// @0x141670ea0
void PCBase::FUN_141670ea0()
{
    m_str960.Empty();
}
MS2_REPLACE_METHOD(0x141670ea0, PCBase, FUN_141670ea0, 34, 0xB2735B13);

// @0x141671390
efd::Point2 PCBase::FUN_141671390()
{
    return m_unk_620;
}
MS2_REPLACE_METHOD(0x141671390, PCBase, FUN_141671390, 36, 0x977D29BC);

// @0x1416713c0
float PCBase::FUN_1416713c0()
{
    return m_f938;
}
MS2_REPLACE_METHOD(0x1416713c0, PCBase, FUN_1416713c0, 19, 0xD8D95139);

// @0x1416713e0
CString PCBase::FUN_1416713e0()
{
    return m_str940;
}
MS2_REPLACE_METHOD(0x1416713e0, PCBase, FUN_1416713e0, 68, 0xEF54CDE1);

// @0x141671430
CString PCBase::FUN_141671430()
{
    return m_str948;
}
MS2_REPLACE_METHOD(0x141671430, PCBase, FUN_141671430, 68, 0xD486A189);

// @0x1416715b0
CString PCBase::FUN_1416715b0()
{
    return m_str950;
}
MS2_REPLACE_METHOD(0x1416715b0, PCBase, FUN_1416715b0, 68, 0x981B8463);

// @0x141671600
float PCBase::FUN_141671600()
{
    return m_f1a0;
}
MS2_REPLACE_METHOD(0x141671600, PCBase, FUN_141671600, 19, 0x515C60A9);

// @0x141671920
float* PCBase::FUN_141671920()
{
    return m_unk_180;
}
MS2_REPLACE_METHOD(0x141671920, PCBase, FUN_141671920, 17, 0x87CF6FFA);

// @0x141671940
float PCBase::FUN_141671940()
{
    return m_f198;
}
MS2_REPLACE_METHOD(0x141671940, PCBase, FUN_141671940, 19, 0x31ACDCE1);

// @0x141671960
void PCBase::FUN_141671960(float fSpeed)
{
    m_f198 = fSpeed;
}
MS2_REPLACE_METHOD(0x141671960, PCBase, FUN_141671960, 31, 0xEEDFB76D);

// @0x141671990
void PCBase::FUN_141671990(float fScale)
{
    m_f92c = fScale;
}
MS2_REPLACE_METHOD(0x141671990, PCBase, FUN_141671990, 31, 0x10F8FD89);

// @0x141671b20
BOOL PCBase::FUN_141671b20()
{
    return GetClassID() == 0x6200050;
}
MS2_REPLACE_METHOD(0x141671b20, PCBase, FUN_141671b20, 59, 0xF6428016);

// @0x1416749a0
Unk_PCBaseBuffs* PCBase::FUN_1416749a0()
{
    return static_cast<Unk_PCBaseBuffs*>(&m_unk_748);
}
MS2_REPLACE_METHOD(0x1416749a0, PCBase, FUN_1416749a0, 17, 0xD57792A0);

// @0x141676020
NiPoint3 PCBase::FUN_141676020()
{
    return m_posC10;
}
MS2_REPLACE_METHOD(0x141676020, PCBase, FUN_141676020, 44, 0x0E0311C6);

// @0x141676980
void PCBase::FUN_141676980(int n)
{
    m_unk_b70 = n;
}
MS2_REPLACE_METHOD(0x141676980, PCBase, FUN_141676980, 25, 0x39A0BC30);

// @0x1416769a0
void PCBase::FUN_1416769a0(__int64 nUid)
{
    m_nUidB78 = nUid;
}
MS2_REPLACE_METHOD(0x1416769a0, PCBase, FUN_1416769a0, 28, 0x17093EA8);

// @0x1416769d0
int PCBase::FUN_1416769d0()
{
    return m_unk_b70;
}
MS2_REPLACE_METHOD(0x1416769d0, PCBase, FUN_1416769d0, 17, 0xCC36A574);

// @0x1416769f0
__int64 PCBase::FUN_1416769f0()
{
    return m_nUidB78;
}
MS2_REPLACE_METHOD(0x1416769f0, PCBase, FUN_1416769f0, 18, 0x5451CDDE);

// @0x141676b50
void PCBase::FUN_141676b50(int n)
{
    m_unk_b80 = n;
}
MS2_REPLACE_METHOD(0x141676b50, PCBase, FUN_141676b50, 25, 0xF9008D40);

// @0x141676b70
int PCBase::FUN_141676b70()
{
    return m_unk_b80;
}
MS2_REPLACE_METHOD(0x141676b70, PCBase, FUN_141676b70, 17, 0x3936E264);

// @0x1416781a0
void PCBase::FUN_1416781a0(int n)
{
    m_unk_c00 = n;
}
MS2_REPLACE_METHOD(0x1416781a0, PCBase, FUN_1416781a0, 25, 0xB8378DBB);

// @0x1416782e0
int PCBase::FUN_1416782e0()
{
    return m_unk_af4;
}
MS2_REPLACE_METHOD(0x1416782e0, PCBase, FUN_1416782e0, 17, 0x49054061);

// @0x141678300
void PCBase::FUN_141678300(int n)
{
    m_unk_af4 = n;
}
MS2_REPLACE_METHOD(0x141678300, PCBase, FUN_141678300, 25, 0x287B4905);

// @0x141678320
int PCBase::FUN_141678320()
{
    return m_unk_af8;
}
MS2_REPLACE_METHOD(0x141678320, PCBase, FUN_141678320, 17, 0xE0DF37DD);

// @0x141678340
void PCBase::FUN_141678340(int n)
{
    m_unk_af8 = n;
}
MS2_REPLACE_METHOD(0x141678340, PCBase, FUN_141678340, 25, 0x758EB519);

// @0x141678710
NiPoint3 PCBase::FUN_141678710()
{
    return m_pos9ac;
}
MS2_REPLACE_METHOD(0x141678710, PCBase, FUN_141678710, 44, 0xFCD0A4DB);

// @0x141679070
int PCBase::FUN_141679070()
{
    return m_unk_c0c;
}
MS2_REPLACE_METHOD(0x141679070, PCBase, FUN_141679070, 17, 0x6CCB6E73);

// @0x141679090
void PCBase::FUN_141679090(int n)
{
    m_unk_c0c = n;
}
MS2_REPLACE_METHOD(0x141679090, PCBase, FUN_141679090, 25, 0xCEB11FAF);

// @0x141670cd0
void PCBase::vfunc_91(void* p)
{
    vfunc_90(p);
}
MS2_REPLACE_METHOD(0x141670cd0, PCBase, vfunc_91, 43, 0x79C52993);

// @0x141670d10
void PCBase::vfunc_92(void* p)
{
    vfunc_90(p);
}
MS2_REPLACE_METHOD(0x141670d10, PCBase, vfunc_92, 43, 0x79C52993);

// @0x141671380
void PCBase::vfunc_94(int n)
{
}

// @0x141671620
float PCBase::vfunc_95()
{
    float fBase = FUN_141671940();
    float fRate = vfunc_96();
    return fBase * fRate * m_f92c;
}
MS2_REPLACE_METHOD(0x141671620, PCBase, vfunc_95, 80, 0x873F203D);

// @0x141674bf0
int PCBase::vfunc_108()
{
    return 0;
}
MS2_REPLACE_METHOD(0x141674bf0, PCBase, vfunc_108, 8, 0x7F371472);

// @0x141674c00
void PCBase::vfunc_109(int n)
{
    if (n != 0)
        m_unk_150->FUN_14123fbf0(2);
    else
        m_unk_150->FUN_14123fbf0(5);
}
MS2_REPLACE_METHOD(0x141674c00, PCBase, vfunc_109, 69, 0x460AC9D8);

// @0x141674c50
void PCBase::vfunc_110()
{
}

// @0x141671680
float PCBase::vfunc_96()
{
    if (GetClassID() == 0x6200045)
        return FUN_1401c0db0()->FUN_140674290(FUN_141670a00(0x20));
    return FUN_1401c0db0()->FUN_140674100(FUN_141670a00(0xe), FUN_1416787a0());
}
MS2_REPLACE_METHOD(0x141671680, PCBase, vfunc_96, 142, 0x5A4E0AB6);

// @0x1416718d0
void PCBase::vfunc_98(float f)
{
    FUN_1401c0db0()->FUN_140674420(FUN_141670a00(0xd), f);
}
MS2_REPLACE_METHOD(0x1416718d0, PCBase, vfunc_98, 67, 0x9F70B920);

// @0x1416700b0
void PCBase::FUN_1416700b0(int nType)
{
    MS2Ptr<Unk_PCBaseComp_ac8> spBanner = vfunc_87();
    if (spBanner == 0)
        return;
    if (nType == 0) {
        spBanner->vfunc_3();
        return;
    }
    spBanner->FUN_140ba8720(nType);
    spBanner->vfunc_2();
}
MS2_REPLACE_METHOD(0x1416700b0, PCBase, FUN_1416700b0, 198, 0xEB11A23B);

// @0x141670180
void PCBase::FUN_141670180(bool bShow)
{
    if (FUN_14166ce30() != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0) {
        spBar->FUN_141992180(FUN_141670a00(4), FUN_141670a30(4));
        if (bShow)
            spBar->FUN_141992140(bShow);
    }
}
MS2_REPLACE_METHOD(0x141670180, PCBase, FUN_141670180, 213, 0x5B144CC8);

// @0x141670260
void PCBase::FUN_141670260(int nShield, bool bShow)
{
    if (FUN_14166ce30() != 0)
        return;
    MS2Ptr<Unk_PCBaseComp_a68> spBar = vfunc_81();
    if (spBar.get() != 0) {
        spBar->FUN_140e85f10(nShield, nShield);
        if (bShow)
            spBar->FUN_140e85ed0(bShow);
    }
}
MS2_REPLACE_METHOD(0x141670260, PCBase, FUN_141670260, 198, 0x18291DE7);

// @0x141670390
float PCBase::FUN_141670390()
{
    float fMount = 0.0f;
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        fMount = spRidee->FUN_141707960();
    return m_f164 + m_f174 + fMount;
}
MS2_REPLACE_METHOD(0x141670390, PCBase, FUN_141670390, 153, 0xEF36227E);

// @0x141670450
float PCBase::vfunc_89()
{
    float fMount = 0.0f;
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        fMount = spRidee->vfunc_89();
    return m_f16c + m_f170 + fMount;
}
MS2_REPLACE_METHOD(0x141670450, PCBase, vfunc_89, 169, 0x56B885A2);

// @0x141670540
void PCBase::FUN_141670540(int nKind, int nStat, __int64 nValue)
{
    if (nKind == 1)
        FUN_1416705c0(nStat, nValue);
    else if (nKind == 2)
        FUN_141670700(nStat, nValue);
    else if (nKind == 0)
        FUN_1416708a0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670540, PCBase, FUN_141670540, 110, 0xF9DEC14D);

// @0x1416705c0
void PCBase::FUN_1416705c0(int nStat, __int64 nValue)
{
    m_unk_1c0[1][nStat] = nValue;
    if (m_unk_1c0[1][nStat] < 0)
        m_unk_1c0[1][nStat] = 0;
    if (m_unk_1c0[1][nStat] > m_unk_1c0[0][nStat])
        m_unk_1c0[1][nStat] = m_unk_1c0[0][nStat];
    if (m_spB10)
        m_spB10->FUN_1416705c0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x1416705c0, PCBase, FUN_1416705c0, 314, 0xA07389F9);

// @0x141670700
void PCBase::FUN_141670700(int nStat, __int64 nValue)
{
    if (nValue != m_unk_1c0[2][nStat])
        FUN_141670920(nStat, m_unk_1c0[2][nStat]);
    m_unk_1c0[2][nStat] = nValue;
    if (m_unk_1c0[2][nStat] < 0)
        m_unk_1c0[2][nStat] = 0;
    if (m_unk_1c0[2][nStat] > m_unk_1c0[0][nStat])
        m_unk_1c0[2][nStat] = m_unk_1c0[0][nStat];
    if (m_spB10)
        m_spB10->FUN_141670700(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670700, PCBase, FUN_141670700, 397, 0xDF9AE4CF);

// @0x1416708a0
void PCBase::FUN_1416708a0(int nStat, __int64 nValue)
{
    m_unk_1c0[0][nStat] = nValue;
    if (m_spB10)
        m_spB10->FUN_1416708a0(nStat, nValue);
}
MS2_REPLACE_METHOD(0x1416708a0, PCBase, FUN_1416708a0, 119, 0x0F9E58B8);

// @0x141670920
void PCBase::FUN_141670920(int nStat, __int64 nValue)
{
    m_unk_508[nStat] = nValue;
    if (m_spB10)
        m_spB10->FUN_141670920(nStat, nValue);
}
MS2_REPLACE_METHOD(0x141670920, PCBase, FUN_141670920, 106, 0x9D769AB6);

// @0x141670a90
// MS2-FUNCTIONAL: slot 90 takes void* in the shared PCBase/PC declarations (as in MyPC::vfunc_90).
void PCBase::vfunc_90(void* p)
{
    CInPacket* pPacket = static_cast<CInPacket*>(p);
    unsigned char nCount = pPacket->vfunc_o8_1();
    if (nCount == 0x23) {
        for (int nType = 0; nType < 0x23; nType++) {
            for (int i = 0; i < 3; i++) {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)pPacket->vfunc_o8_3();
                else
                    nValue = pPacket->vfunc_o8_4();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
    else {
        for (int n = 0; n < nCount; n++) {
            unsigned char nType = pPacket->vfunc_o8_1();
            for (int i = 0; i < 3; i++) {
                __int64 nValue;
                if (FUN_14082f1a0(nType) == 0)
                    nValue = (unsigned)pPacket->vfunc_o8_3();
                else
                    nValue = pPacket->vfunc_o8_4();
                FUN_141670540(i, nType, nValue);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141670a90, PCBase, vfunc_90, 569, 0xAFACA969);

// @0x141670ed0
void PCBase::FUN_141670ed0(Unk_PCBaseEntity* pEntity)
{
    m_str958 = "default";
    if (m_unk_9a8 != 0 && pEntity != 0) {
        efd::utf8string strMaterial;
        pEntity->FUN_1408a2060(0xde5dd580, &strMaterial);
        unsigned short nKind = 0;
        pEntity->FUN_140ae1160(0xada5c5d2, &nKind);
        if (!strMaterial.empty()) {
            m_unk_9c4 = nKind;
            m_str958 = strMaterial.c_str();
        }
    }
}
MS2_REPLACE_METHOD(0x141670ed0, PCBase, FUN_141670ed0, 247, 0xF98BBCFA);

// @0x141671130
// MS2-FUNCTIONAL: the exe assigns efd::Point3::ZERO to the NiPoint3 member directly; here it goes through a temporary.
void PCBase::vfunc_93(bool bMaterial)
{
    if (FUN_141671a30() != 0) {
        m_unk_9a8 = 1;
        m_f9c8 = 0;
        m_pos9ac = vfunc_18();
        m_pos9b8 = FUN_14166d220()->FUN_141240df0();
    }
    else {
        Unk_PCBaseRayHit kHit;
        m_unk_9a8 = FUN_1409f7ca0()->FUN_14168a310(vfunc_18(), &m_pos9ac, &kHit, 0.0f, &m_pos9b8, 0);
        if (m_unk_9a8 == 0) {
            m_pos9ac = NiPoint3::ZERO;
            m_f9c8 = FLT_MAX;
        }
        else {
            m_f9c8 = kHit.m_hitDist;
        }
    }
    if (bMaterial) {
        m_unk_9c4 = 0;
        m_str958.Empty();
        Unk_PCBaseEntity* pEntity = FUN_14166d220()->FUN_141240f20()->FUN_140cfaff0();
        if (pEntity != 0)
            FUN_141670ed0(pEntity);
    }
}
MS2_REPLACE_METHOD(0x141671130, PCBase, vfunc_93, 576, 0x9C628E51);

// @0x141671480
CString PCBase::FUN_141671480()
{
    if (!m_str960.IsEmpty()) {
        BOOL bUse = FALSE;
        if (vfunc_62() == false)
            bUse = m_unk_9c4 != 8;
        else
            bUse = m_unk_9c4 != 8 && vfunc_61() == 2;
        if (bUse)
            return m_str960;
    }
    return m_str958;
}
MS2_REPLACE_METHOD(0x141671480, PCBase, FUN_141671480, 295, 0xCA524CA6);

// @0x141671720
float PCBase::vfunc_97()
{
    float fRate = 1.0f;
    if (m_fScaleA8 != m_fScaleAC) {
        if (m_fScaleAC / 2.0f > m_fScaleA8)
            fRate = 1.5f;
        else if (m_fScaleAC / 2.0f <= m_fScaleA8 && m_fScaleA8 < m_fScaleAC)
            fRate = 2.0f - m_fScaleA8 / m_fScaleAC;
        else if (m_fScaleA8 > m_fScaleAC && m_fScaleAC * 2.0f >= m_fScaleA8)
            fRate = 1.0f - (m_fScaleA8 - m_fScaleAC) / (m_fScaleAC * 2.0f);
        else if (m_fScaleAC * 2.0f < m_fScaleA8)
            fRate = 0.5f;
    }
    return fRate;
}
MS2_REPLACE_METHOD(0x141671720, PCBase, vfunc_97, 412, 0xA3371C75);

// @0x1416719c0
BOOL PCBase::FUN_1416719c0()
{
    CString strModel = FUN_14166dc50();
    if (strModel.Find("Dash", 0) != -1)
        return TRUE;
    return FALSE;
}
MS2_REPLACE_METHOD(0x1416719c0, PCBase, FUN_1416719c0, 103, 0xCE9ED2D7);

// @0x141671a30
int PCBase::FUN_141671a30()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0 && FUN_14166c930() == 0x21)
        return spRidee->FUN_141671a30();
    if (FUN_14166d220() == 0)
        return 0;
    return FUN_14166d220()->FUN_141240f40() != 0;
}
MS2_REPLACE_METHOD(0x141671a30, PCBase, FUN_141671a30, 220, 0x9D9E0C20);

// @0x141671b70
int PCBase::vfunc_99(int nSlope)
{
    if (m_unk_150 == 0)
        return 0;
    if (nSlope < 0)
        nSlope = 0;
    if (nSlope == 0)
        nSlope = 100;
    int nLimit = m_unk_150->FUN_141240ef0();
    if (nLimit > nSlope && FUN_14028d380(0.3f) < m_f9c8 && (FUN_14166d220()->FUN_141240ed0() & 4) == 0)
        return 1;
    else
        return 0;
}
MS2_REPLACE_METHOD(0x141671b70, PCBase, vfunc_99, 159, 0x1EE7592B);

// @0x141673890
bool PCBase::vfunc_102(MS2Ptr<CSkillRecord> skill)
{
    return true;
}
MS2_REPLACE_METHOD(0x141673890, PCBase, vfunc_102, 39, 0xDCF00779);

// @0x1416738c0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::vfunc_103()
{
    if (m_unk_8e8.IsEmpty())
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    MS2Ptr<Unk_PCBaseComp_b18> spItem = m_unk_8e8.GetHead();
    if (spItem->FUN_141759e40() != 0)
        return MS2Ptr<Unk_PCBaseComp_b18>(0);
    else
        return spItem;
}
MS2_REPLACE_METHOD(0x1416738c0, PCBase, vfunc_103, 233, 0xF71E697F);

// @0x1416739c0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::vfunc_104(bool a, bool b, bool c)
{
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x1416739c0, PCBase, vfunc_104, 65, 0x3097854B);

// @0x1416749c0
bool PCBase::FUN_1416749c0()
{
    NiPoint3 kPos = FUN_14123c360();
    if (kPos != efd::Point3::ZERO)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1416749c0, PCBase, FUN_1416749c0, 59, 0x3D7C4A38);

// @0x141674ec0
void PCBase::vfunc_113(void* p)
{
    FUN_140e09140()->FUN_140a04ef0(p);
}
MS2_REPLACE_METHOD(0x141674ec0, PCBase, vfunc_113, 37, 0x2955B135);

// @0x141675270
float PCBase::vfunc_115(float a, float b, float c, float d, int nFlag, int* pOut)
{
    return 0;
}
MS2_REPLACE_METHOD(0x141675270, PCBase, vfunc_115, 27, 0x2EA3D17C);

// @0x1416752a0
int PCBase::vfunc_117()
{
    return !m_unk_b88.IsEmpty();
}
MS2_REPLACE_METHOD(0x1416752a0, PCBase, vfunc_117, 62, 0x58D030AC);

// @0x141676410
int PCBase::FUN_141676410()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->FUN_141707750()->m_nNameId;
}
MS2_REPLACE_METHOD(0x141676410, PCBase, FUN_141676410, 133, 0x8F2137E9);

// @0x1416764a0
Ridee* PCBase::FUN_1416764a0()
{
    return m_spB10;
}
MS2_REPLACE_METHOD(0x1416764a0, PCBase, FUN_1416764a0, 33, 0x3B108532);

// @0x1416764d0
int PCBase::FUN_1416764d0()
{
    return m_spB10 != 0;
}
MS2_REPLACE_METHOD(0x1416764d0, PCBase, FUN_1416764d0, 38, 0x78397EF1);

// @0x141676930
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141676930()
{
    return m_spB18;
}
MS2_REPLACE_METHOD(0x141676930, PCBase, FUN_141676930, 67, 0xDAC1A857);

// @0x1416781c0
int PCBase::vfunc_122(void* p)
{
    if (p == 0)
        return 0;
    return vfunc_116() != static_cast<PCBase*>(p)->vfunc_116();
}
MS2_REPLACE_METHOD(0x1416781c0, PCBase, vfunc_122, 113, 0xCFF8EA1D);

// @0x1416752f0
int PCBase::vfunc_118(const NiPoint3& kPos, float* pDist, CString* pName)
{
    if (vfunc_117() == 0)
        return 0;
    *pDist = FLT_MAX;
    for (POSITION pos = m_unk_b88.GetHeadPosition(); pos != 0; m_unk_b88.GetNext(pos)) {
        CString strName = m_unk_b88.GetKeyAt(pos);
        NiAVObject* pNode = m_unk_b88.GetValueAt(pos);
        float fDist = (pNode->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist) {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416752f0, PCBase, vfunc_118, 346, 0x49F5AB68);

// @0x141673a10
// MS2-FUNCTIONAL: the exe moves the saved z pointer through rcx into rdx for FUN_140970eb0; the source loads rdx directly (register choice only).
void PCBase::vfunc_105(efd::Point3 kPos, void* b, void* c, int d)
{
    float fYaw = 0;
    *static_cast<efd::Point3*>(b) = FUN_141674a10(kPos, &fYaw);
    *static_cast<efd::Point3*>(c) = vfunc_20();
    if (d != 0) {
        static_cast<efd::Point3*>(c)->y = 0;
        static_cast<efd::Point3*>(c)->x = 0;
    }
    if (*static_cast<efd::Point3*>(b) != efd::Point3::ZERO)
        static_cast<efd::Point3*>(c)->z = fYaw;
    float* pRotZ = &static_cast<efd::Point3*>(c)->z;
    FUN_1416749a0()->FUN_140970eb0(*pRotZ);
}
MS2_REPLACE_METHOD(0x141673a10, PCBase, vfunc_105, 288, 0xE5649AD4);

// @0x141674a10
efd::Point3 PCBase::FUN_141674a10(efd::Point3 kDir, float* pYaw)
{
    efd::Point3 kRet = efd::Point3::ZERO;
    if (kDir != efd::Point3::ZERO) {
        efd::Point3 kSide;
        efd::Point3 kFront;
        vfunc_67(&kSide, &kFront);
        kRet = kDir.y * kSide + kDir.x * kFront;
        kRet.Unitize();
        *pYaw = FUN_14166dad0(kDir, kFront);
    }
    return kRet;
}
MS2_REPLACE_METHOD(0x141674a10, PCBase, FUN_141674a10, 323, 0xCA310BE2);

// @0x141674c60
void PCBase::vfunc_111(void* p, int a, int b, void* q)
{
    __int64 nValue = abs(reinterpret_cast<__int64>(p));
    Unk_PCBaseDamageUI* pDamage = FUN_140b624b0(0x4e32);
    if (pDamage != 0)
        pDamage->FUN_141911e90(this, nValue, a, b, q);
    int nOwnerId = b;
    Unk_PCBaseWorldActor* pTarget = FUN_1403ed2d0()->FUN_141bd13a0(nOwnerId);
    if (pTarget != 0)
        nOwnerId = pTarget->FUN_141094f40();
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0) {
        if (nOwnerId == pLocal->FUN_14123c580()) {
            Unk_PCBaseDamageLog* pLog = FUN_14167a900(0x4e44);
            if (pLog != 0) {
                if (pLog->FUN_1419299e0() != 0)
                    pLog->FUN_141929a00(nValue, a);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141674c60, PCBase, vfunc_111, 276, 0xDD2381FF);

// @0x141674d80
void PCBase::vfunc_112(void* p, int n)
{
    PCBase* pLocal = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pLocal != 0 && n == pLocal->FUN_14123c580()) {
        Unk_PCBaseTargetUI* pTargetUI = FUN_141531aa0(0x4e51);
        if (pTargetUI != 0)
            pTargetUI->FUN_1419df2a0(this);
    }
    Unk_PCBaseUpperHpBar* pUpper = FUN_14096e340(0x4e3d);
    if (pUpper != 0)
        pUpper->FUN_141b4c510(this, n);
    MS2Ptr<Unk_PCBaseComp_a58> spBar = vfunc_80();
    if (spBar.get() != 0) {
        if (spBar->FUN_141992160() == 0 && pLocal != 0)
            spBar->FUN_141992140(pLocal->FUN_14123c580() == n);
    }
}
MS2_REPLACE_METHOD(0x141674d80, PCBase, vfunc_112, 302, 0x0D7211D8);

// @0x141673b40
int PCBase::FUN_141673b40(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    if (spItem.IsNull() || spItem->FUN_141759960() == 0)
        return 0;
    FUN_1417ea750(this, spItem);
    return 1;
}
MS2_REPLACE_METHOD(0x141673b40, PCBase, FUN_141673b40, 158, 0x65CBAB49);

// @0x141673bf0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673bf0(__int64 nTagId, int nKind)
{
    for (POSITION pos = m_unk_8e8.GetHeadPosition(); pos != 0; m_unk_8e8.GetNext(pos)) {
        Unk_PCBaseComp_b18* pItem = m_unk_8e8.GetAt(pos).get();
        if (pItem->m_nTagId == nTagId && pItem->m_n8c == nKind)
            return MS2Ptr<Unk_PCBaseComp_b18>(pItem);
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673bf0, PCBase, FUN_141673bf0, 231, 0x8DC370DA);

// @0x141673ce0
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673ce0(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    if (FUN_141673bf0(spItem->m_nTagId, spItem->m_n8c).IsNull()) {
        m_unk_8e8.RemoveAll();
        m_unk_8e8.AddTail(spItem);
        return spItem;
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673ce0, PCBase, FUN_141673ce0, 287, 0x81523824);

// @0x141673e10
MS2Ptr<Unk_PCBaseComp_b18> PCBase::FUN_141673e10(__int64 nTagId)
{
    for (POSITION pos = m_unk_8e8.GetHeadPosition(); pos != 0; m_unk_8e8.GetNext(pos)) {
        Unk_PCBaseComp_b18* pItem = m_unk_8e8.GetAt(pos).get();
        if (pItem->m_nTagId == nTagId)
            return MS2Ptr<Unk_PCBaseComp_b18>(pItem);
    }
    return MS2Ptr<Unk_PCBaseComp_b18>(0);
}
MS2_REPLACE_METHOD(0x141673e10, PCBase, FUN_141673e10, 206, 0x44C1FD7A);

// @0x141673ef0
int PCBase::FUN_141673ef0()
{
    if (m_spStateMgr.get() != 0) {
        if (m_spStateMgr->FUN_1417db270() == 0x10) {
            State* pState = m_spStateMgr->FUN_1417db1c0();
            return FUN_1417e9330(pState);
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141673ef0, PCBase, FUN_141673ef0, 116, 0xAEB0C93F);

// @0x141673f70
void PCBase::FUN_141673f70(float a, float b, float c)
{
    CColorBoostData kData(a, b, c);
    m_colorBoost.FUN_14109be00(kData);
    Ridee* pRidee = FUN_1416764a0();
    if (pRidee != 0)
        pRidee->FUN_141673f70(a, b, c);
}
MS2_REPLACE_METHOD(0x141673f70, PCBase, FUN_141673f70, 156, 0xA481120A);

// @0x141674b60
efd::Point3 PCBase::FUN_141674b60(efd::Point3 kDir)
{
    float fYaw = 0;
    return FUN_141674a10(kDir, &fYaw);
}
MS2_REPLACE_METHOD(0x141674b60, PCBase, FUN_141674b60, 87, 0x56E1EF6F);

// @0x141674bc0
int PCBase::FUN_141674bc0()
{
    return static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_140970990();
}
MS2_REPLACE_METHOD(0x141674bc0, PCBase, FUN_141674bc0, 33, 0xD3B461DE);

// @0x141675150
NiAVObject* PCBase::FUN_141675150(const CString& strNode)
{
    Ridee* pRidee;
    if (FUN_14123c660() != 0 && (pRidee = FUN_1416764a0()) != 0)
        return pRidee->FUN_141675150(strNode);
    NiNode* pRoot = NiDynamicCast(NiNode, FUN_141b6efc0(FUN_14123c410()));
    if (pRoot != 0) {
        NiFixedString kName((const char*)strNode);
        return static_cast<NiAVObject*>(NiObject::DynamicCast(&DAT_143ad1588, pRoot->GetObjectByName(kName)));
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141675150, PCBase, FUN_141675150, 219, 0x54BDAE33);

// @0x141675240
void PCBase::FUN_141675240()
{
    static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_1409711c0();
}
MS2_REPLACE_METHOD(0x141675240, PCBase, FUN_141675240, 33, 0x084A2064);

// @0x1416757c0
efd::SmartPointer<NiAVObject> PCBase::FUN_1416757c0(CString strName)
{
    efd::SmartPointer<NiAVObject> spNode(0);
    if (m_unk_b88.IsEmpty())
        return spNode;
    m_unk_b88.Lookup(strName, spNode);
    return spNode;
}
MS2_REPLACE_METHOD(0x1416757c0, PCBase, FUN_1416757c0, 217, 0xE4622531);

// @0x1416758a0
efd::SmartPointer<NiAVObject> PCBase::FUN_1416758a0(CString strName)
{
    efd::SmartPointer<NiAVObject> spNode(0);
    m_unk_bb8.Lookup(strName, spNode);
    return spNode;
}
MS2_REPLACE_METHOD(0x1416758a0, PCBase, FUN_1416758a0, 136, 0xA990BF2D);

// @0x141675930
efd::SmartPointer<NiAVObject> PCBase::FUN_141675930()
{
    return m_spBE8;
}
MS2_REPLACE_METHOD(0x141675930, PCBase, FUN_141675930, 67, 0x12297BF2);

// @0x141675cd0
int PCBase::FUN_141675cd0(const NiPoint3& kPos, CString strUnused, CString* pName, float* pDist)
{
    if (FUN_141675e60() == 0)
        return 0;
    *pDist = FLT_MAX;
    for (POSITION pos = m_unk_bb8.GetHeadPosition(); pos != 0; m_unk_bb8.GetNext(pos)) {
        CString strName = m_unk_bb8.GetKeyAt(pos);
        NiAVObject* pNode = m_unk_bb8.GetValueAt(pos);
        float fDist = (pNode->GetWorldTranslate() - kPos).Length();
        if (fDist < *pDist) {
            *pDist = fDist;
            *pName = strName;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141675cd0, PCBase, FUN_141675cd0, 382, 0x94FD3298);

// @0x141675e60
int PCBase::FUN_141675e60()
{
    return !m_unk_bb8.IsEmpty();
}
MS2_REPLACE_METHOD(0x141675e60, PCBase, FUN_141675e60, 62, 0xF082B080);

// @0x141675eb0
void* PCBase::FUN_141675eb0()
{
    return &m_pushControl;
}
MS2_REPLACE_METHOD(0x141675eb0, PCBase, FUN_141675eb0, 17, 0xEE253D79);

// @0x141676320
void PCBase::FUN_141676320(MS2Ptr<RideOnAction> spAction)
{
    m_spB00 = spAction;
}
MS2_REPLACE_METHOD(0x141676320, PCBase, FUN_141676320, 63, 0x5F552001);

// @0x141676370
MS2Ptr<RideOnAction> PCBase::FUN_141676370()
{
    return m_spB00;
}
MS2_REPLACE_METHOD(0x141676370, PCBase, FUN_141676370, 67, 0x77B23705);

// @0x1416763c0
int PCBase::FUN_1416763c0()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->FUN_14123c580();
}
MS2_REPLACE_METHOD(0x1416763c0, PCBase, FUN_1416763c0, 73, 0x9715FB89);

// @0x141676500
int PCBase::FUN_141676500()
{
    if (m_spB10 == 0)
        return 0;
    return m_spB10->FUN_141707750()->m_nType == 1;
}
MS2_REPLACE_METHOD(0x141676500, PCBase, FUN_141676500, 158, 0x9A8E329D);

// @0x141676670
void PCBase::FUN_141676670(unsigned int nKey, int nValue)
{
    m_mapB28.SetAt(nKey, nValue);
}
MS2_REPLACE_METHOD(0x141676670, PCBase, FUN_141676670, 51, 0x3464AB17);

// @0x1416766b0
void PCBase::FUN_1416766b0(MS2Ptr<Unk_PCBaseComp_b18> spItem)
{
    m_spB18 = spItem;
}
MS2_REPLACE_METHOD(0x1416766b0, PCBase, FUN_1416766b0, 63, 0x3B963751);

// @0x141676700
void PCBase::FUN_141676700()
{
    m_mapB28.RemoveAll();
}
MS2_REPLACE_METHOD(0x141676700, PCBase, FUN_141676700, 33, 0x8B35E0E0);

// @0x141676730
void PCBase::FUN_141676730(unsigned int nKey)
{
    m_mapB28.RemoveKey(nKey);
}
MS2_REPLACE_METHOD(0x141676730, PCBase, FUN_141676730, 41, 0x5ACF4772);

// @0x141676760
int PCBase::FUN_141676760()
{
    return (int)m_mapB28.GetCount();
}
MS2_REPLACE_METHOD(0x141676760, PCBase, FUN_141676760, 33, 0xCAABD8C0);

// @0x141676790
int PCBase::FUN_141676790(unsigned int nKey)
{
    int nValue = 0;
    m_mapB28.Lookup(nKey, nValue);
    return nValue;
}
MS2_REPLACE_METHOD(0x141676790, PCBase, FUN_141676790, 58, 0xC1A3BF59);

// @0x1416767d0
NiPoint3 PCBase::FUN_1416767d0()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        return spRidee->vfunc_18();
    return vfunc_18();
}
MS2_REPLACE_METHOD(0x1416767d0, PCBase, FUN_1416767d0, 168, 0x794ABE09);

// @0x141676880
NiPoint3 PCBase::FUN_141676880()
{
    efd::SmartPointer<Ridee> spRidee = FUN_1416764a0();
    if (spRidee != 0)
        return spRidee->vfunc_20();
    return vfunc_20();
}
MS2_REPLACE_METHOD(0x141676880, PCBase, FUN_141676880, 168, 0xF147A9F0);

// @0x141676a10
void* PCBase::FUN_141676a10()
{
    return FUN_1403ed2d0()->FUN_141bd1200(m_unk_b70)->FUN_1409ffc60();
}
MS2_REPLACE_METHOD(0x141676a10, PCBase, FUN_141676a10, 46, 0xB9F2C777);

// @0x141676a50
void PCBase::FUN_141676a50(__int64 nUid, int n)
{
    FUN_141676980(n);
    FUN_1416769a0(nUid);
    m_mapCA8.SetAt(nUid, n);
}
MS2_REPLACE_METHOD(0x141676a50, PCBase, FUN_141676a50, 82, 0x230F5B7A);

// @0x141676ab0
void PCBase::FUN_141676ab0(__int64 nUid)
{
    FUN_141676980(0);
    FUN_1416769a0(0);
    m_mapCA8.RemoveKey(nUid);
}
MS2_REPLACE_METHOD(0x141676ab0, PCBase, FUN_141676ab0, 67, 0x8D619E4A);

// @0x141676b00
int PCBase::FUN_141676b00(__int64 nUid)
{
    return m_mapCA8.Lookup(nUid) != 0;
}
MS2_REPLACE_METHOD(0x141676b00, PCBase, FUN_141676b00, 70, 0xA2EC986C);

// @0x141678160
void PCBase::FUN_141678160(const NiPoint3& kPos)
{
    m_posBF4 = kPos;
}
MS2_REPLACE_METHOD(0x141678160, PCBase, FUN_141678160, 43, 0x6EE29682);

// @0x141678240
void PCBase::FUN_141678240(egf::EntityID& kId, NiPoint3& kPos)
{
    kId = m_unk_ae0;
    kPos = m_posAE8;
}
MS2_REPLACE_METHOD(0x141678240, PCBase, FUN_141678240, 72, 0x119736F1);

// @0x141678290
void PCBase::FUN_141678290(egf::EntityID kId, NiPoint3 kPos)
{
    m_posAE8 = kPos;
    m_unk_ae0 = kId;
}
MS2_REPLACE_METHOD(0x141678290, PCBase, FUN_141678290, 72, 0xE8669FA0);

// @0x141678680
unsigned int PCBase::FUN_141678680()
{
    unsigned int nMask = static_cast<Unk_PCBaseBuffsEx*>(&m_unk_748)->FUN_140970bf0();
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField.get() != 0)
        nMask |= spField->m_nSkillUseDisableMask;
    return nMask;
}
MS2_REPLACE_METHOD(0x141678680, PCBase, FUN_141678680, 130, 0x482C383A);

// @0x1416787a0
int PCBase::FUN_1416787a0()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    return spField->m_nMapType;
}
MS2_REPLACE_METHOD(0x1416787a0, PCBase, FUN_1416787a0, 116, 0xE689F429);

// @0x141678820
int PCBase::FUN_141678820()
{
    MS2Ptr<CFieldDataCli> spField = FUN_1403ed2d0()->FUN_141bd30a0();
    if (spField == 0)
        return 0;
    if (spField->m_nCheckClimb == 0)
        return 0;
    return m_unk_c68;
}
MS2_REPLACE_METHOD(0x141678820, PCBase, FUN_141678820, 157, 0xB74623DA);

// @0x1416790b0
const char* PCBase::vfunc_123(int n)
{
    return m_spD00->vfunc_5(n);
}
MS2_REPLACE_METHOD(0x1416790b0, PCBase, vfunc_123, 105, 0x3D3A5EA7);

// @0x141679120
void PCBase::FUN_141679120(int n)
{
    m_spD00->vfunc_4(n);
}
MS2_REPLACE_METHOD(0x141679120, PCBase, FUN_141679120, 62, 0x06B74A69);

// @0x141679170
efd::utf8string PCBase::FUN_141679170(int a, int b)
{
    return efd::utf8string((const char*)m_spD00->vfunc_6(a, b));
}
MS2_REPLACE_METHOD(0x141679170, PCBase, FUN_141679170, 167, 0x25DB4066);

// @0x14166de90
bool PCBase::FUN_14166de90(int nKey, unsigned int nSeq)
{
    Unk_PCBaseAnimSvc* pSvc = FUN_141b6f910();
    if (pSvc == 0)
        return false;
    std::map<CString, std::vector<unsigned int> >& kByName = m_mapCF0[nKey];
    CString strPrefix = vfunc_60();
    std::vector<unsigned int>& kIds = kByName[strPrefix];
    if (kIds.empty()) {
        std::vector<CString>* pNames = m_spD00->vfunc_7(nKey);
        if (pNames->empty())
            return false;
        for (size_t i = 0; i < pNames->size(); ++i) {
            unsigned int nId = FUN_141679270((*pNames)[i]);
            if (nId != NiActorManager::INVALID_SEQUENCE_ID)
                kIds.push_back(nId);
        }
    }
    return std::find(kIds.begin(), kIds.end(), nSeq) != kIds.end();
}
MS2_REPLACE_METHOD(0x14166de90, PCBase, FUN_14166de90, 511, 0xCC0FDC50);

// @0x141679270
unsigned int PCBase::FUN_141679270(const char* szName)
{
    Unk_PCBaseAnimSvc* pSvc = FUN_141b6f910();
    if (pSvc == 0)
        return NiActorManager::INVALID_SEQUENCE_ID;
    CString strPrefix = vfunc_60();
    CString strName;
    if (!strPrefix.IsEmpty())
        strName = FUN_14038f6d0(strPrefix, szName);
    else
        strName = szName;
    unsigned int nId = pSvc->FUN_140999490(FUN_14123c460(), (const char*)strName);
    if (nId == NiActorManager::INVALID_SEQUENCE_ID && !strPrefix.IsEmpty())
        nId = pSvc->FUN_140999490(FUN_14123c460(), szName);
    return nId;
}
MS2_REPLACE_METHOD(0x141679270, PCBase, FUN_141679270, 463, 0x55F4C7F1);

// @0x1416795e0
void PCBase::FUN_1416795e0()
{
    if (m_unk_c48 == 0)
        return;
    if (m_spStateMgr->FUN_1417db270() == 0x21 && m_spB10 != 0)
        m_spB10->vfunc_59(m_unk_c48, m_unk_c50.get(), m_unk_c60, m_unk_c64);
    else
        m_spStateMgr->FUN_1417dafa0(m_unk_c48, m_unk_c50.get(), m_unk_c60, m_unk_c64);
    m_unk_c48 = 0;
    m_unk_c50 = 0;
    m_unk_c60 = 0;
    m_unk_c64 = 0;
}
MS2_REPLACE_METHOD(0x1416795e0, PCBase, FUN_1416795e0, 373, 0xA091CF77);

// @0x141679760
void PCBase::FUN_141679760()
{
    m_spD00 = FUN_1414a5860()->FUN_1409494e0(vfunc_57());
    m_mapCF0.clear();
}
MS2_REPLACE_METHOD(0x141679760, PCBase, FUN_141679760, 140, 0xB20F089E);

// @0x141679e00
void PCBase::FUN_141679e00()
{
    for (unsigned int i = 0; i < m_arrA30.GetCount(); ++i)
    {
        unsigned int nHandle = m_arrA30[i];
        FUN_1403ed280()->FUN_1411a6060(nHandle);
    }
    m_arrA30.RemoveAll();
}
MS2_REPLACE_METHOD(0x141679e00, PCBase, FUN_141679e00, 137, 0x85FE2DC4);

// @0x141679e90
void PCBase::FUN_141679e90()
{
    for (size_t i = 0; i < m_vecD28.size(); ++i)
        FUN_1403ed280()->FUN_1411a6060(m_vecD28[i]);
    m_vecD28.clear();
    m_unk_d20 = 0;
}
MS2_REPLACE_METHOD(0x141679e90, PCBase, FUN_141679e90, 149, 0xC892B3AB);

// @0x141679f30
void PCBase::FUN_141679f30()
{
    if (m_sp638.get() != 0)
        m_sp638->FUN_141848650();
    m_timer9e8.FUN_1408687f0();
    FUN_141679e00();
}
MS2_REPLACE_METHOD(0x141679f30, PCBase, FUN_141679f30, 94, 0x69BC8436);

// @0x141676310
void PCBase::FUN_141676310(int n)
{
}
MS2_REPLACE_METHOD(0x141676310, PCBase, FUN_141676310, 10, 0x96F6F902);

// @0x141678750
MS2Ptr<CStateManager> PCBase::FUN_141678750()
{
    return m_spStateMgr;
}
MS2_REPLACE_METHOD(0x141678750, PCBase, FUN_141678750, 67, 0xE1DD1C3D);

// @0x141679220
bool PCBase::FUN_141679220(const char* szName)
{
    unsigned int nId = FUN_141679270(szName);
    return nId != NiActorManager::INVALID_SEQUENCE_ID;
}
MS2_REPLACE_METHOD(0x141679220, PCBase, FUN_141679220, 73, 0x7A70E4CC);

// @0x1416765b0
int PCBase::FUN_1416765b0()
{
    if (FUN_1416764a0() != 0)
        return (int)m_mapB28.GetCount() < FUN_1416764a0()->FUN_141707750()->m_seats.FUN_140784180();
    else
        return 0;
}
MS2_REPLACE_METHOD(0x1416765b0, PCBase, FUN_1416765b0, 181, 0x26DE6170);

// @0x141676060
void PCBase::FUN_141676060(NiPoint3 kPos)
{
    if (kPos != efd::Point3::ZERO && m_posC10 != efd::Point3::ZERO)
        return;
    efd::SmartPointer<Ridee> spRidee(FUN_1416764a0());
    if (spRidee)
        spRidee->FUN_141676060(kPos);
    else
        m_posC10 = kPos;
}
MS2_REPLACE_METHOD(0x141676060, PCBase, FUN_141676060, 210, 0xAEE43850);

// @0x14166ebf0
void PCBase::FUN_14166ebf0(PCBase* pOther)
{
    if (pOther == 0)
        return;
    NiPoint3 kPos = pOther->m_posAE8;
    egf::EntityID kId = pOther->m_unk_ae0;
    if (kId != egf::kENTITY_INVALID) {
        egf::Entity* pEntity = FUN_1411cf440(FUN_1409670f0(), m_unk_ae0);
        if (pEntity == 0)
            return;
        FUN_1409618c0(pEntity, 0xfd95ca52, kPos);
        FUN_141678290(kId, kPos);
    }
}
MS2_REPLACE_METHOD(0x14166ebf0, PCBase, FUN_14166ebf0, 268, 0x8CB8826E);

// @0x141678f50
// MS2-FUNCTIONAL: the exe keeps the NiNode smart pointer's ctor result in three extra slots (frame 0x78 vs 0x58); same calls and order.
void PCBase::FUN_141678f50()
{
    if (m_spC40 == 0)
        return;
    efd::SmartPointer<NiNode> spRoot = (NiNode*)FUN_141675150("Eff_UI");
    if (spRoot)
        spRoot->DetachChild(m_spC40);
    m_spC40 = 0;
}
MS2_REPLACE_METHOD(0x141678f50, PCBase, FUN_141678f50, 279, 0x6D1CA468);
