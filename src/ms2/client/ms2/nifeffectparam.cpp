// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "Nif" effect (param + runtime effect), the duplicated
// alpha controller used to fade it out, and the nif cache/loader service. See nifeffectparam.h.
// MS2-UNIT: ?\nifeffectparam.cpp
// MS2-RANGE: 0x1400fa2f0-0x1400fa540 .text$di
// MS2-RANGE: 0x141548790-0x141562ee0 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nifeffectparam.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "nifeffectparam.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <algorithm>
#include <new>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiMesh.h>
#include <NiFixedString.h>
#include <NiCloningProcess.h>
#include <NiTimeController.h>
#include <NiInterpolator.h>
#include <NiStream.h>
#include <NiSearchPath.h>
#include <NiMaterialProperty.h>
#include <NiStringExtraData.h>
#include <NiFloatData.h>
#include <NiLinFloatKey.h>
#include <NiFloatInterpolator.h>
#include <efd/ServiceManager.h>
#include "ms2/client/ms2/effectobject.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
// Game TinyXML element.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement(name)
};
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_140874670(Unk_140165cf0* pNode, const char* pszName, Unk_StreamPoint& kOut);

// The nif / texture cache service (CNifLoadingService::s_instance).
CNifLoadingService* FUN_140a0afd0();
class Unk_ModelCache { public: void FUN_141210ac0(CString strPath); };           // release by path
Unk_ModelCache* FUN_140ab7a10();
CString FUN_140cc2ba0(const CString& strDir, const CString& strName);

bool FUN_140afc5a0(const Unk_LightUpdateBits* pBits);               // all bits set
bool FUN_140314790(Unk_LightUpdateBits* pBits, unsigned nPos);
void FUN_14154fda0(void* pObj);
void FUN_1411ff180(Unk_LightUpdateBits* pBits);                      // set every bit

// Attach type name -> 0 none, 1 Node, 2 Mesh, 3 WeaponL, 4 WeaponR (0x14154d880).
// @0x14154d880
static int ParseAttachType(CString& strType)
{
    if (strType.CompareNoCase("Node") == 0)
        return 1;
    if (strType.CompareNoCase("Mesh") == 0)
        return 2;
    if (strType.CompareNoCase("WeaponL") == 0)
        return 3;
    if (strType.CompareNoCase("WeaponR") == 0)
        return 4;
    return 0;
}

// @0x14154e0e0
static int FUN_14154e0e0(Unk_140165cf0* pNode, const char* pszName, int& nOut)
{
    CString strType;
    int nResult = FUN_1408733e0(pNode, pszName, strType);
    if (nResult == 0)
        nOut = ParseAttachType(strType);
    return nResult;
}

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CNifEffect::ms_RTTI("CNifEffect", &CEffect::ms_RTTI);                              // @0x1400fa2f0
const NiRTTI DuplicatedAlphaController::ms_RTTI("DuplicatedAlphaController", &NiAlphaController::ms_RTTI);  // @0x1400fa320
#else
const NiRTTI CNifEffect::ms_RTTI("CNifEffect", &CEffect::ms_RTTI);
const NiRTTI DuplicatedAlphaController::ms_RTTI("DuplicatedAlphaController", &NiAlphaController::ms_RTTI);
#endif
#include "ms2/placeholder/header_statics_a.h"       // @0x1400fa350-0x1400fa470

// @0x141548790
// Copies pkSource (exact copy; the clone map maps its target to itself so the copy keeps the same target).
DuplicatedAlphaController::DuplicatedAlphaController(NiSingleInterpController* pkSource)
{
    NiCloningProcess kCloning(0x25);
    NiObject* pkTarget = pkSource->GetTarget();
    kCloning.m_pkCloneMap->SetAt(pkTarget, pkTarget);
    kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
    kCloning.m_eDynamicEffectRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;
    kCloning.m_eAffectedNodeRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;
    static_cast<DuplicatedAlphaController*>(pkSource)->NiSingleInterpController::CopyMembers(this, kCloning);
    m_fScale = 1.0f;
}

// @0x141548880
void DuplicatedAlphaController::Update(float fTime)
{
    if (GetManagerControlled())
        return;
    if (DontDoUpdate(fTime) && (!m_spInterpolator || !m_spInterpolator->AlwaysUpdate()))
        return;
    if (m_spInterpolator)
    {
        float fValue;
        if (m_spInterpolator->Update(m_fScaledTime, m_pkTarget, fValue))
            ((NiMaterialProperty*)m_pkTarget)->SetAlpha(m_fScale * fValue);
    }
}

// @0x141548990
CNifEffectParam::CNifEffectParam()
    : CEffectParam(1), m_strFilePath(""), m_ptTranslate(0.0f, 0.0f, 0.0f), m_ptRotation(0.0f, 0.0f, 0.0f),
      m_fScale(1.0f), m_bApplyNodeTransform(false), m_bOnGround(false), m_bUseLighting(true), m_bUseShadow(false),
      m_nAttachType(0), m_strParentNode(""), m_nMyReferCount(0), m_nOtherReferCount(0), m_fMaxLength(500.0f),
      m_fMinLength(1.0f), m_fStep(0.01f), m_fVelocity(300.0f), m_bNotForceStop(false), m_bOffFadeOut(false),
      m_fViewDistance(-1.0f), m_bBipedLoop(false)
{
    FUN_1411ff180(&m_bitsApply);
}

// @0x141548b90
void CNifEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    bool bUpdateTranslate = true, bUpdateRotation = true, bUpdateScale = true;
    bool bApplyTranslate = true, bApplyRotation = true, bApplyScale = true;
    FUN_1408733e0(pNode, "filePath", m_strFilePath);
    if (!m_strFilePath.IsEmpty())
    {
        m_strFilePath.TrimLeft();
        m_strFilePath.TrimRight();
    }
    FUN_1408733e0(pNode, "effectObjectKfmName", m_strEffectObjectKfm);
    FUN_1408730a0(pNode, "notForceStop", m_bNotForceStop);
    FUN_1408730a0(pNode, "bipedLoop", m_bBipedLoop);
    FUN_140873360(pNode, "viewDistance", m_fViewDistance);
    FUN_1408730a0(pNode, "offFadeOut", m_bOffFadeOut);
    FUN_1408731e0(pNode, "myReferCount", m_nMyReferCount);
    FUN_1408731e0(pNode, "otherReferCount", m_nOtherReferCount);
    Unk_140165cf0* pTransform = pNode->FUN_140165cf0("transform");
    if (pTransform != 0)
    {
        FUN_140874670(pTransform, "translate", m_ptTranslate);
        FUN_140874670(pTransform, "rotation", m_ptRotation);
        FUN_140873360(pTransform, "scale", m_fScale);
    }
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach != 0)
    {
        FUN_14154e0e0(pAttach, "attachType", m_nAttachType);
        FUN_1408730a0(pAttach, "applyNodeTransform", m_bApplyNodeTransform);
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
        FUN_1408730a0(pAttach, "onGround", m_bOnGround);
        FUN_1408730a0(pAttach, "useLighting", m_bUseLighting);
        FUN_1408730a0(pAttach, "useShadow", m_bUseShadow);
        bool bAttachToNode = false;
        FUN_1408730a0(pAttach, "attachToNode", bAttachToNode);
        if (bAttachToNode)
            m_nAttachType = 1;
    }
    Unk_140165cf0* pUpdate = pNode->FUN_140165cf0("update");
    if (pUpdate != 0)
    {
        FUN_1408730a0(pUpdate, "translate", bUpdateTranslate);
        FUN_1408730a0(pUpdate, "rotation", bUpdateRotation);
        FUN_1408730a0(pUpdate, "scale", bUpdateScale);
    }
    Unk_140165cf0* pApply = pNode->FUN_140165cf0("applyNodeTransform");
    if (pApply != 0)
    {
        FUN_1408730a0(pApply, "translate", bApplyTranslate);
        FUN_1408730a0(pApply, "rotation", bApplyRotation);
        FUN_1408730a0(pApply, "scale", bApplyScale);
    }
    Unk_140165cf0* pLerp = pNode->FUN_140165cf0("lerp");
    if (pLerp != 0)
    {
        FUN_1408733e0(pLerp, "type", m_strLerpType);
        FUN_140873360(pLerp, "MaxLength", m_fMaxLength);
        FUN_140873360(pLerp, "MinLength", m_fMinLength);
        FUN_140873360(pLerp, "Step", m_fStep);
        FUN_140873360(pLerp, "Velocity", m_fVelocity);
    }
    if (bUpdateTranslate)
        m_bitsUpdate[0] = true;
    if (bUpdateRotation)
        m_bitsUpdate[1] = true;
    if (bUpdateScale)
        m_bitsUpdate[2] = true;
    if (!bApplyTranslate)
        m_bitsApply[0] = false;
    if (!bApplyRotation)
        m_bitsApply[1] = false;
    if (!bApplyScale)
        m_bitsApply[2] = false;
}

// @0x1415491c0
bool CNifEffectParam::vfunc_2()
{
    return CEffectParam::vfunc_2() ? true : false;
}

// @0x1415491f0
bool CNifEffectParam::vfunc_3()
{
    if (m_strFilePath.IsEmpty())
        return true;
    CString strDir("Effect");
    return FUN_140a0afd0()->IsCached(FUN_140cc2ba0(strDir, m_strFilePath));
}

// @0x1415492a0
void CNifEffectParam::vfunc_4()
{
    if (!m_strFilePath.IsEmpty())
    {
        CString strDir("Effect");
        FUN_140ab7a10()->FUN_141210ac0(FUN_140cc2ba0(strDir, m_strFilePath));
    }
}

// @0x141549340
bool CNifEffectParam::vfunc_5(int n)
{
    if (!m_strFilePath.IsEmpty())
    {
        if (FUN_140a0afd0() != 0)
        {
            CString strDir("Effect");
            if (!FUN_140a0afd0()->Preload(FUN_140cc2ba0(strDir, m_strFilePath), false, n))
                return false;
        }
    }
    return true;
}

// @0x141549430
// Not hooked: constructs CNifEffect with its (exe) constructor.
CEffectPtr CNifEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CNifEffect;
}

// ---- CNifEffect: out-of-unit types and callees ----
// The effect target (CEffect::vfunc_3's second argument), the part this unit reads.
struct Unk_NifTarget
{
    char m_pad_00[0x10];
    NiAVObjectPtr m_hNode;          // +0x10 handle of the owner's scene node
    const NiTransform* m_pPre;      // +0x18 transform before the animation
    const NiTransform* m_pPost;     // +0x20 transform after the animation
    char m_pad_28[8];
    bool m_bNoCull;                 // +0x30
    char m_pad_31;
    bool m_bTagLod;                 // +0x32 tag the loaded model with the Eff_LOD extra data
};
MS2_CHECK_OFFSET(Unk_NifTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_NifTarget, m_pPre, 0x18);
MS2_CHECK_OFFSET(Unk_NifTarget, m_bTagLod, 0x32);

double FUN_140a53420(Unk_EffectTarget* pTarget);                    // start time of the target
int FUN_140a53390(Unk_EffectTarget* pTarget);                       // the target's owner id
NiNode* FUN_140a533d0(Unk_EffectTarget* pTarget);                   // the target's owner node
void* FUN_140a53440(Unk_EffectTarget* pTarget);                     // the target's attach object
int FUN_140a53480(Unk_EffectTarget* pTarget);                       // the target's slot kind (6 = any)
double FUN_14119f3a0(CEffect* pEffect);                             // start time
bool FUN_14028d470(float a, float b);                               // nearly equal
class Unk_GameClock { public: double FUN_141473280(); };
Unk_GameClock* FUN_14086d260();
efd::ServiceManager* FUN_1413f9850();

// Handles (NiAVObjectPtr) and node pointers.
NiAVObject* FUN_1409849b0(NiAVObjectPtr* pHandle);                  // handle -> node pointer
NiAVObject* FUN_14098d0f0(NiAVObjectPtr* pHandle);                  // handle -> node pointer (non-const)
bool FUN_1409a7f70(NiAVObjectPtr* pHandle, int nNull);              // handle == NULL?
void FUN_1409fabf0(NiAVObjectPtr* pHandle, NiAVObject* pObj);       // handle = object
bool FUN_1411b02b0(NiAVObjectPtr* pA, NiAVObjectPtr* pB);
bool FUN_140aac3e0(Unk_NodePtr* pPtr, void* pOther);                // node pointer != pOther
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
void FUN_141d16040(void* pNode, float fTime, bool bUpdateControllers);    // NiAVObject::Update
void FUN_140a0b2a0(void* pNode);                                    // detach from the parent
void FUN_140a0b300(void* pNode, bool bCulled);                      // SetAppCulled
void* FUN_140a0b000(void* pNode);                                   // parent node
bool FUN_14098dad0(NiAVObject* pObj);                               // object is app-culled
efd::FixedString* FUN_1409a8b90(NiAVObject* pNode);                 // node name
const char* FUN_142087e50(const void* kFixed);
bool FUN_141068d50(efd::FixedString* pName, const char* pszName);
void FUN_140a0b330(void* pObj, bool bOn, short sFlags);

// Transforms (the exe's NiTransform helpers) and node transforms.
void* FUN_140a33f90(void* pObj);                                    // local transform
void* FUN_1409478e0(void* pObj);                                    // world transform
void FUN_140aacb60(void* pObj, const void* pXform);                 // SetLocalTransform
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
void* FUN_141024c90(void* pNode);                                   // world rotation
void FUN_140a0b1f0(void* pRotation, float* pDirection);             // rotation -> facing direction
void FUN_1402bd040(float* p);                                       // NiPoint3()
void FUN_140194470(void* pDst, const void* pSrc);                   // point assign

// The effect manager (singleton 0x1403ed280) and the world.
class Unk_EffectMgr
{
public:
    void* FUN_1411a6b10();                          // scene root
    unsigned FUN_1411a88c0();                       // quality level (1..3)
};
Unk_EffectMgr* FUN_1403ed280();
void* FUN_1403ed2d0();                                              // the world
void FUN_141bbb1e0(void* pWorld, GameObject* pObj, int nA, int nB); // add the object
void FUN_141bbb7f0(void* pWorld, GameObject* pObj, int nA);         // remove the object
void* FUN_14119f490();                                              // the effect culler
int FUN_1411b86e0(void* pCuller, void* pQuery);                     // 0 when visible
void FUN_1411a3db0(void* pEffectNode, CBirdMovement* pMovement);
void FUN_1411a3fa0(void* pEffectNode, bool bOnGround);
void FUN_141567a10(void* pNode);
void FUN_141567330(void* pNode, bool bShadow);
void FUN_141851f90(void* pNode, float fTime);                       // seek the node's animations
float FUN_141852010(void* pNode);                                   // duration of the node's animations
void* FUN_1409a8b00();
void* FUN_1409a5160(void* p);
void FUN_141773a90(void* pRegistry, void* pNode);                   // register a model
void FUN_141773cc0(void* pRegistry, void* pNode);                   // unregister a model
void FUN_141550050(void* pNode, const char* pszPath);               // remember the nif path of the node (0x141550050)

// Query passed to the culler (ctor 0x1411b8570: kind 9, default position).
struct Unk_NifCullQuery
{
    int m_nMode;                    // +0x00
    int m_nKind;                    // +0x04
    float m_aPos[4];                // +0x08
    float m_fViewDistance;          // +0x18
    char m_pad_1c[4];
};
MS2_CHECK_SIZE(Unk_NifCullQuery, 0x20);
void FUN_1411b8570(Unk_NifCullQuery* pQuery);

// Scene nodes of the effect system (see swoosheffectparam.cpp / lighteffectparam.cpp).
class Unk_EffectNode : public NiNode
{
public:
    Unk_EffectNode(int nA, int nB);                                 // 0x1411a34b0
    char m_pad_node[400 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_EffectNode, 400);
class Unk_SeparateNode : public NiNode
{
public:
    Unk_SeparateNode(unsigned char nBits);                          // 0x141751470
    char m_pad_node[0x138 - sizeof(NiNode)];
};
MS2_CHECK_SIZE(Unk_SeparateNode, 0x138);

// Depth-first walker over a scene graph (0x38 bytes; unrecovered class).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);

// Controllers and extra data of a node.
NiTimeController* FUN_14098dc80(NiObjectNET* pObj);                 // first controller
NiTimeController* FUN_14098de40(NiTimeController* pCtrl);           // next controller
void* FUN_141d17b40(void* pObj, const void* pKey);                  // extra data by key
const efd::FixedString* FUN_141168130(NiStringExtraData* pExtra);   // string value
extern char DAT_143ae51b8;                                          // NiFixedString: the Eff_LOD tag key
extern char DAT_143ae50e8;                                          // NiFixedString: the tag text
extern char DAT_143ae5198;                                          // NiFixedString: the nif path key

// Players, their equipment and the equipped item's model.
typedef efd::SmartPointer<GameObject> Unk_NifPCPtr;
GameObject* FUN_14099eef0(GameObject* pObj);                        // object -> player (0 if it is not one)
bool FUN_140c206b0(Unk_NifPCPtr* pPtr, int nNull);                  // pointer == NULL?
GameObject* FUN_140aac420(Unk_NifPCPtr* pPtr);
GameObject* FUN_140aac440(Unk_NifPCPtr* pPtr);
class Unk_NifEquipSet
{
public:
    MS2Ptr<CEquipItem> FUN_1411e2610(NiAVObject* pNode, int nA, int nKind, bool bB);   // equipped item owning the node
    MS2Ptr<CEquipItem> FUN_1411e1860(int nSlot, int nA, int nB);                        // equipped item of the slot
    NiAVObjectPtr FUN_1411e2a60(void* pAttach, const CString& strName, bool bA);       // model node of the item by name
};
Unk_NifEquipSet* FUN_1416561a0(GameObject* pPC);
Unk_NodePtr FUN_1411dd700(CEquipItem* pEquip);                      // the item's model node
int FUN_14052a170(CItem* pItem);                                    // the item's slot kind
int FUN_1411dc670(CEquipItem* pEquip);
int FUN_1411dc820(CEquipItem* pEquip);                              // the item id

// Strings of the log lines.
CString FUN_140741200(const char* pszFormat, const CString& strA, const CString& strB);
CString FUN_140536a50(const char* pszFormat, const CString& strA);
class Unk_NifStrings { public: CStringW FUN_141811980(int nA, int nId); };
Unk_NifStrings* FUN_1401a9d70();
CLogString* FUN_140166440();                                         // the game log, or 0

// 3-argument fmt log helper (log, level, category, "format", a, b, c).
// @0x14154da00
template<class T, class U, class V> inline void Unk_NifLog3(CLogString* log, int level, int category, const wchar_t* format,
                                                            const T& first, const U& second, const V& third) {
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// @0x14154f4b0
Unk_BitRef::operator bool() const
{
    return FUN_140314790(m_pBits, m_nPos);
}

// @0x1415494d0
CNifEffect::CNifEffect()
    : m_bSplit(false), m_spTarget(0), m_spModel(0), m_spSplit(0), m_spRoot(0), m_fFadeStart(FLT_MAX),
      m_fFadeTime(1.0f), m_nLodLevel(0), m_fStartTime(0.0f), m_spEffectObject(0), m_spParam(0)
{
    m_kXform.MakeIdentity();
}

// @0x141549620
CNifEffect::~CNifEffect()
{
    vfunc_7();
}

// MS2-FUNCTIONAL: big function: codegen (temporaries / branch layout) not byte-identical to the exe
// @0x1415496f0
// Builds the nif instance: an EffectNode root holding the loaded model (and the kfm effect object / bird movement),
// placed by the param's transform composed with the target's, and hung on the node selected by the attach type.
bool CNifEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    m_spParam.AssignRaw(static_cast<CNifEffectParam*>(const_cast<CEffectParam*>(pParam)));
    if (m_spParam.IsNull())
        return false;
    if (m_unk_18 == 1 && m_spParam->m_nMyReferCount == -1)
        return false;
    if (m_unk_18 != 1 && m_spParam->m_nOtherReferCount == -1)
        return false;

    NiPointer<Unk_EffectNode> spRoot = new (efd::MemHint(efd::MemHint::NONE)) Unk_EffectNode(m_spParam->m_bUseLighting, m_spParam->m_bUseShadow);
    spRoot->SetName("Effect Root");
    FUN_1409f76f0(&m_spRoot, spRoot);
    m_fStartTime = (float)FUN_140a53420(pTarget);

    if (!m_spParam->m_strEffectObjectKfm.IsEmpty())
    {
        CEffectObject* pObject = new (efd::MemHint(efd::MemHint::NONE)) CEffectObject;
        m_spEffectObject = pObject;
        CString strKfm(m_spParam->m_strEffectObjectKfm);
        int nOwner = FUN_140a53390(pTarget);
        m_spEffectObject->FUN_140a53880(nOwner, strKfm, m_spParam->m_fScale);
        FUN_141bbb1e0(FUN_1403ed2d0(), m_spEffectObject.operator->(), 0, 1);
    }

    if (m_spParam->m_strLerpType.CompareNoCase("bird") == 0)
    {
        MS2Ptr<CBirdMovement> spBird(new CBirdMovement);
        spBird->SetMaxLength(m_spParam->m_fMaxLength);
        spBird->SetMinLength(m_spParam->m_fMinLength);
        spBird->FUN_141207fb0(m_spParam->m_fStep);
        spBird->SetVelocity(m_spParam->m_fVelocity);
        FUN_1411a3db0(spRoot, spBird.get());
    }

    m_kXform.m_Translate = NiPoint3(m_spParam->m_ptTranslate.x, m_spParam->m_ptTranslate.y, m_spParam->m_ptTranslate.z);
    float fRadZ = (m_spParam->m_ptRotation.z * 3.1415927f) / 180.0f;
    float fRadY = (m_spParam->m_ptRotation.y * 3.1415927f) / 180.0f;
    m_kXform.m_Rotate.FromEulerAnglesXYZ((m_spParam->m_ptRotation.x * 3.1415927f) / 180.0f, fRadY, fRadZ);
    m_kXform.m_fScale = m_spParam->m_fScale;
    if (pT->m_pPre != 0)
        m_kXform = *pT->m_pPre * m_kXform;
    if (pT->m_pPost != 0)
        m_kXform = m_kXform * *pT->m_pPost;
    spRoot->SetLocalTransform(m_kXform);
    FUN_1411a3fa0(spRoot, m_spParam->m_bOnGround);

    switch (m_spParam->m_nAttachType)
    {
    case 0:
        FUN_14154ba40(pTarget);
        break;
    case 1:
        FUN_14154bdd0(pTarget);
        break;
    case 2:
        FUN_14154c260(pTarget);
        break;
    case 3:
        FUN_14154c440(pTarget, 4);
        break;
    case 4:
        FUN_14154c440(pTarget, 5);
        break;
    }
    if (m_spTarget.FUN_1409f77a0(0))
        return false;

    FUN_141550050(FUN_1409475d0(&m_spRoot), m_spParam->m_strFilePath);
    if (FUN_14028d470(m_fDuration, 0.0f))
    {
        if (m_spParam->m_bBipedLoop)
            return false;
        m_fDuration = FUN_14154b470();
    }
    float fNow = (float)FUN_14086d260()->FUN_141473280();
    static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
    NiAVObject* pTop = static_cast<NiAVObject*>(FUN_1409475d0(&m_spTarget));
    while (pTop->GetParent() != 0)
        pTop = pTop->GetParent();
    NiNode* pOwnerNode = FUN_140a533d0(pTarget);
    if (pTop == pOwnerNode && FUN_140aac3e0(&m_spTarget, pOwnerNode))
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spTarget))->Update(fNow, false);
    else
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update(fNow, false);
    FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));

    Unk_NifCullQuery kQuery;
    FUN_1411b8570(&kQuery);
    kQuery.m_nMode = 1;
    kQuery.m_nKind = m_unk_18;
    kQuery.m_fViewDistance = m_spParam->m_fViewDistance;
    vfunc_8(kQuery.m_aPos);
    if (!pT->m_bNoCull && !m_spParam->m_bOffSkip)
    {
        if (FUN_1411b86e0(FUN_14119f490(), &kQuery) != 0)
            return false;
    }
    if (0 < m_spParam->m_nLodSkipLevel)
    {
        if ((int)FUN_1403ed280()->FUN_1411a88c0() < m_spParam->m_nLodSkipLevel)
            return false;
    }

    if (!m_spEffectObject || !m_spParam->m_strFilePath.IsEmpty())
    {
        int nMyRefer = (m_unk_18 == 1) * m_spParam->m_nMyReferCount;
        int nOtherRefer = (m_unk_18 != 1) * m_spParam->m_nOtherReferCount;
        CString strDir("Effect");
        Unk_NodePtr kLoaded = FUN_14154d0d0(FUN_140cc2ba0(strDir, m_spParam->m_strFilePath), nMyRefer, nOtherRefer);
        static_cast<NiNode*>(FUN_1409475d0(&m_spRoot))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&kLoaded)), false);
        if (pT->m_bTagLod)
        {
            NiAVObject* pLoaded = static_cast<NiAVObject*>(FUN_1409475f0(&kLoaded));
            NiStringExtraData* pTag = static_cast<NiStringExtraData*>(FUN_14098d8d0(&NiStringExtraData::ms_RTTI, FUN_141d17b40(pLoaded, &DAT_143ae51b8)));
            if (pTag == 0)
            {
                pTag = new (efd::MemHint(efd::MemHint::NONE)) NiStringExtraData(*(NiFixedString*)&DAT_143ae50e8);
                static_cast<NiAVObject*>(FUN_1409475f0(&kLoaded))->AddExtraData(*(NiFixedString*)&DAT_143ae51b8, pTag);
            }
            else
            {
                efd::utf8string strTag(FUN_142087e50(FUN_141168130(pTag)));
                strTag += FUN_142087e50(&DAT_143ae50e8);
                pTag->SetValue(NiFixedString(strTag.c_str()));
            }
        }
        FUN_141773a90(FUN_1409a5160(FUN_1409a8b00()), FUN_1409475d0(&kLoaded));
        FUN_14154cf20(static_cast<NiAVObject*>(FUN_1409475d0(&kLoaded)));
    }

    if (FUN_14028d470(m_spParam->m_fStartDelay, 0.0f))
        vfunc_4();
    FUN_141567a10(FUN_1409475d0(&m_spRoot));
    FUN_141567330(FUN_1409475d0(&m_spRoot), m_spParam->m_bUseShadow);
    return true;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154a7e0
bool CNifEffect::vfunc_9()
{
    float fNow = (float)FUN_1413f9850()->GetTime(0xe001001b);
    if (m_fFadeStart <= fNow && fNow != m_fFadeStart)
    {
        float fScale = 0.0f;
        if (!FUN_14028d470(m_fFadeTime, 0.0f))
            fScale = ((m_fFadeStart + m_fFadeTime) - fNow) / m_fFadeTime;
        else
            fScale = 0.0f;
        bool bDone = fScale <= 0.0f;
        if (bDone)
            fScale = 0.0f;
        for (unsigned i = 0; i < m_aAlphaCtrls.GetCount(); ++i)
            m_aAlphaCtrls[i]->SetScale(fScale);
        if (bDone)
            m_b2d = true;
    }
    if (m_b2e)
    {
        if (m_spParam->m_bBipedLoop && m_fStartTime != 0.0f)
        {
            double dNow = FUN_14086d260()->FUN_141473280();
            float fElapsed = (float)(dNow - (double)m_fStartTime);
            if (m_fDuration <= fElapsed)
            {
                for (; m_fDuration <= fElapsed; fElapsed = fElapsed - m_fDuration)
                {
                }
                FUN_141851f90(FUN_1409475d0(&m_spRoot), fElapsed);
                m_fStartTime = (float)(dNow - (double)fElapsed);
            }
        }
    }
    if (FUN_1409849b0(&m_spModel) != 0)
    {
        NiTransform kModel = *static_cast<NiTransform*>(FUN_140a33f90(FUN_14098d0f0(&m_spModel)));
        NiTransform kLocal = kModel * m_kXform;
        FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kLocal);
    }
    if (m_spEffectObject)
    {
        if (FUN_140aac3e0(&m_spRoot, 0))
        {
            const Unk_StreamPoint& rPos = FUN_140947900(FUN_1409475f0(&m_spRoot));
            efd::Point3 kPos(rPos.x, rPos.y, rPos.z);
            m_spEffectObject->vfunc_19(kPos);
            float aDir[4];
            FUN_1402bd040(aDir);
            float aRot[9];
            memcpy(aRot, FUN_141024c90(FUN_1409475f0(&m_spRoot)), sizeof(aRot));
            FUN_140a0b1f0(aRot, aDir);
            m_spEffectObject->vfunc_21(efd::Point3(aDir[0], aDir[1], aDir[2]));
        }
    }
    if (!CEffect::vfunc_9())
        return false;
    if ((int)FUN_1403ed280()->FUN_1411a88c0() != m_nLodLevel)
    {
        if (FUN_14028d470(m_fDuration, 0.0f))
            FUN_14154cf20(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)));
    }
    return true;
}

// @0x14154acf0
// Hangs the root on the target (or on the split node) and runs the first update, as if it had started on time.
void CNifEffect::vfunc_4()
{
    if (FUN_1409475d0(&m_spTarget) != 0)
    {
        double dNow = FUN_14086d260()->FUN_141473280();
        double dNowF = (double)(float)dNow;
        double dStart = FUN_14119f3a0(this);
        float fElapsed = (float)(dNowF - dStart);
        if (!m_bSplit || FUN_1409475d0(&m_spSplit) == 0)
            static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        else
            static_cast<NiNode*>(FUN_1409475f0(&m_spSplit))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        FUN_141851f90(FUN_1409475d0(&m_spRoot), fElapsed);
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update((float)dNow, true);
        m_fStartTime = (float)(dNowF - (double)fElapsed);
    }
    m_b2e = true;
}

// @0x14154aef0
void CNifEffect::vfunc_5()
{
    if (!FUN_14154b5e0() || vfunc_11() == 0)
        CEffect::vfunc_5();
}

// @0x14154af40
// Fades the model out over fFadeTime: every material alpha gets a duplicated controller (or a new fade controller).
void CNifEffect::vfunc_6(float fFadeTime)
{
    if (!m_spParam->m_bOffFadeOut)
    {
        m_fFadeStart = (float)FUN_1413f9850()->GetTime(0xe001001b);
        m_fFadeTime = fFadeTime;
        m_aAlphaCtrls.RemoveAll();
        Unk_SceneWalker kWalker(static_cast<NiObject*>(FUN_1409475d0(&m_spRoot)));
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            NiProperty* pProp = pObj->GetProperty(NiProperty::MATERIAL);
            if (pProp != 0 && !FUN_14154b4a0(pProp))
                FUN_14154b630(pProp, fFadeTime);
        }
    }
}

// @0x14154b080
void CNifEffect::vfunc_7()
{
    FUN_141773cc0(FUN_1409a5160(FUN_1409a8b00()), FUN_1409475d0(&m_spRoot));
    FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));
    FUN_140a0b2a0(FUN_1409475d0(&m_spSplit));
    if (m_spEffectObject)
    {
        FUN_141bbb7f0(FUN_1403ed2d0(), m_spEffectObject.operator->(), 0);
        m_spEffectObject = 0;
    }
}

// @0x14154b160
int CNifEffect::vfunc_8(void* p)
{
    FUN_140194470(p, &FUN_140947900(FUN_1409475f0(&m_spRoot)));
    return 1;
}

// @0x14154b1b0
// A Node-attached effect that is still running is re-parented onto the effect scene root (keeping its world
// transform) when the owner goes away, so it can finish playing.
int CNifEffect::vfunc_11()
{
    if (m_b2c)
        return 0;
    if (m_spParam->m_nAttachType == 1)
    {
        if (!m_bSplit)
        {
            double dNow = FUN_14086d260()->FUN_141473280();
            if (dNow < m_dStartTime + (double)m_fDuration)
            {
                m_bSplit = true;
                NiNode* pSplit = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
                FUN_1409f76f0(&m_spSplit, pSplit);
                FUN_140aacb60(FUN_1409475f0(&m_spSplit), FUN_1409478e0(FUN_1409475f0(&m_spTarget)));
                FUN_1409f76f0(&m_spTarget, FUN_1403ed280()->FUN_1411a6b10());
                FUN_140a0b2a0(FUN_1409475d0(&m_spRoot));
                static_cast<NiNode*>(FUN_1409475f0(&m_spSplit))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
                static_cast<NiNode*>(FUN_1409475f0(&m_spTarget))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spSplit)), true);
            }
        }
    }
    return 1;
}

// @0x14154b420
void CNifEffect::vfunc_10(bool bVisible)
{
    FUN_140a0b300(FUN_1409475f0(&m_spRoot), !bVisible);
}

// @0x14154b470
float CNifEffect::FUN_14154b470()
{
    return FUN_141852010(FUN_1409475d0(&m_spRoot));
}

// @0x14154b4a0
// Replaces every NiAlphaController of the node by a DuplicatedAlphaController (kept in m_aAlphaCtrls).
bool CNifEffect::FUN_14154b4a0(NiObjectNET* pkNode)
{
    bool bAny = false;
    NiTimeController* pCtrl = FUN_14098dc80(pkNode);
    while (pCtrl != 0)
    {
        NiAlphaController* pAlpha = static_cast<NiAlphaController*>(FUN_14098d8d0(&NiAlphaController::ms_RTTI, pCtrl));
        pCtrl = FUN_14098de40(pCtrl);
        if (pAlpha != 0)
        {
            DuplicatedAlphaControllerPtr spDup = new (efd::MemHint(efd::MemHint::NONE)) DuplicatedAlphaController(pAlpha);
            pkNode->PrependController(spDup);
            pkNode->RemoveController(pAlpha);
            m_aAlphaCtrls.Add(spDup);
            bAny = true;
        }
    }
    return bAny;
}

// @0x14154b5e0
bool CNifEffect::FUN_14154b5e0()
{
    if (m_spParam.IsNull())
        return false;
    return m_spParam->m_bNotForceStop;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154b630
// Adds an alpha controller to the material that fades its current alpha to 0 over fTime.
void CNifEffect::FUN_14154b630(NiObjectNET* pkNode, float fTime)
{
    NiFloatDataPtr spData = new (efd::MemHint(efd::MemHint::NONE)) NiFloatData;
    NiLinFloatKey* pKeys = NiNew NiLinFloatKey[2];
    pKeys[0].SetTime(0.0f);
    pKeys[0].SetValue(((NiMaterialProperty*)pkNode)->GetAlpha());
    pKeys[1].SetTime(fTime);
    pKeys[1].SetValue(0.0f);
    spData->SetAnim(pKeys, 2, NiAnimationKey::LINKEY);
    NiAlphaControllerPtr spCtrl = new (efd::MemHint(efd::MemHint::NONE)) NiAlphaController;
    NiFloatInterpolatorPtr spInterp = new (efd::MemHint(efd::MemHint::NONE)) NiFloatInterpolator(spData);
    spCtrl->SetInterpolator(spInterp, 0);
    spCtrl->SetTarget(pkNode);
    spCtrl->ResetTimeExtrema();
    spCtrl->SetCycleType(NiTimeController::CLAMP);
    spCtrl->Start(0.0f);
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154ba40
// Attach type 0: hang the effect on the target's owner node, placed relative to the named parent node.
void CNifEffect::FUN_14154ba40(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    FUN_1409f76f0(&m_spTarget, FUN_140a533d0(pTarget));
    NiNode* pParent = 0;
    if (FUN_1409849b0(&pT->m_hNode) != 0)
    {
        NiFixedString kName((const char*)m_spParam->m_strParentNode);
        NiAVObject* pFound = FUN_14098d0f0(&pT->m_hNode)->GetObjectByName(kName);
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, pFound));
    }
    if (pParent == 0)
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
    if (m_spParam->m_bApplyNodeTransform && pParent != 0)
    {
        NiTransform kLocal = *static_cast<NiTransform*>(FUN_140a33f90(FUN_1409475f0(&m_spRoot)));
        if (!FUN_140afc5a0(&m_spParam->m_bitsApply))
        {
            NiTransform kParent = *static_cast<NiTransform*>(FUN_1409478e0(pParent));
            if (!m_spParam->m_bitsApply[0])
                kParent.m_Translate = NiPoint3(0.0f, 0.0f, 0.0f);
            if (!m_spParam->m_bitsApply[1])
                kParent.m_Rotate.MakeIdentity();
            if (!m_spParam->m_bitsApply[2])
                kParent.m_fScale = 1.0f;
            NiTransform kResult = kParent * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
        else
        {
            NiTransform kResult = *static_cast<NiTransform*>(FUN_1409478e0(pParent)) * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154bdd0
// Attach type 1: hang the effect on the named node of the target's model (or the equipped item's node).
void CNifEffect::FUN_14154bdd0(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (FUN_1409a7f70(&pT->m_hNode, 0))
        return;
    const char* pszParent = m_spParam->m_strParentNode;
    NiAVObjectPtr spFound;
    {
        NiFixedString kName(pszParent);
        spFound = FUN_14098d0f0(&pT->m_hNode)->GetObjectByName(kName);
    }
    bool bFlag = FUN_1411b02b0(&pT->m_hNode, &spFound);
    if (FUN_1409849b0(&spFound) != 0)
    {
        if (!bFlag && FUN_140a53480(pTarget) != 6)
        {
            Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
            if (FUN_140aac420(&spPC) != 0)
            {
                MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(FUN_1409849b0(&spFound), 0, 6, true);
                bool bHasItem = false;
                if (spEquip.get() != 0)
                {
                    MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
                    bHasItem = spItem.get() != 0;
                }
                if (bHasItem)
                {
                    bool bMismatch;
                    if (FUN_1411dc670(spEquip.get()) == 0)
                    {
                        bMismatch = true;
                    }
                    else
                    {
                        MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
                        bMismatch = FUN_14052a170(spItem.get()) != FUN_140a53480(pTarget);
                    }
                    if (bMismatch)
                    {
                        NiAVObjectPtr spOther = FUN_14154d410(pTarget, pszParent, true);
                        if (FUN_1409a7f70(&spOther, 0))
                            return;
                        spFound = spOther;
                    }
                }
            }
        }
        FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&spFound)));
    }
    if (m_spTarget.FUN_1409f77a0(0))
        FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
    FUN_14154c580();
}

// @0x14154c260
// Attach type 2: hang the effect on the parent of the named mesh node.
void CNifEffect::FUN_14154c260(Unk_EffectTarget* pTarget)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (!FUN_1409a7f70(&pT->m_hNode, 0))
    {
        const char* pszParent = m_spParam->m_strParentNode;
        if (pszParent != 0)
        {
            m_spModel = FUN_14154d410(pTarget, pszParent, false);
            if (FUN_1409849b0(&m_spModel) == 0)
            {
                if (FUN_140a53480(pTarget) != 6)
                    return;
            }
            else
            {
                if (FUN_140a0b000(FUN_14098d0f0(&m_spModel)) != 0)
                    FUN_1409f76f0(&m_spTarget, FUN_140a0b000(FUN_14098d0f0(&m_spModel)));
            }
            if (m_spTarget.FUN_1409f77a0(0))
                FUN_1409f76f0(&m_spTarget, FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pT->m_hNode)));
            FUN_14154c580();
            if (FUN_1409849b0(&m_spModel) != 0)
                FUN_140aacb60(FUN_1409475f0(&m_spRoot), FUN_140a33f90(FUN_14098d0f0(&m_spModel)));
        }
    }
}

// @0x14154c440
// Attach types 3 / 4: hang the effect on the model of the weapon in equip slot nSlot.
void CNifEffect::FUN_14154c440(Unk_EffectTarget* pTarget, int nSlot)
{
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (!FUN_140c206b0(&spPC, 0))
    {
        MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e1860(nSlot, 6, 0);
        if (!spEquip.IsNull())
        {
            m_spTarget = FUN_1411dd700(spEquip.get());
            FUN_14154c580();
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154c580
// Wraps the root in a SeparateNode when only some parts of the parent's transform are followed, and makes the root
// relative to the target when the node transform is not applied.
void CNifEffect::FUN_14154c580()
{
    if (!FUN_140afc5a0(&m_spParam->m_bitsUpdate))
    {
        NiPointer<Unk_SeparateNode> spSep = new (efd::MemHint(efd::MemHint::NONE)) Unk_SeparateNode(m_spParam->m_bitsUpdate.m_bits);
        spSep->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), false);
        FUN_1409f76f0(&m_spRoot, spSep);
    }
    if (!m_spParam->m_bApplyNodeTransform)
    {
        if (FUN_1409475d0(&m_spTarget) != 0)
        {
            NiTransform kInverse;
            static_cast<NiTransform*>(FUN_1409478e0(FUN_1409475f0(&m_spTarget)))->Invert(kInverse);
            NiTransform kLocal = *static_cast<NiTransform*>(FUN_140a33f90(FUN_1409475f0(&m_spRoot)));
            NiTransform kResult = kInverse * kLocal;
            FUN_140aacb60(FUN_1409475f0(&m_spRoot), &kResult);
        }
    }
}

// MS2-FUNCTIONAL: diagnostic only: builds the same log text with the exe's string-format helpers
// @0x14154c7f0
// Logs the "LOD level" line with a description of the target node / equipped item.
void CNifEffect::FUN_14154c7f0(Unk_EffectTarget* pTarget)
{
    CString strWhere;
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (FUN_140aac420(&spPC) != 0 && FUN_1409475d0(&m_spTarget) != 0)
    {
        Unk_NodePtr kTarget(m_spTarget.m_p);
        MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(static_cast<NiAVObject*>(FUN_1409475d0(&kTarget)), 0, 6, false);
        if (spEquip.get() == 0)
        {
            if (FUN_1409849b0(&m_spModel) == 0)
            {
                CString strParent;
                if (FUN_140a0b000(FUN_1409475f0(&kTarget)) == 0)
                    strParent = "empty";
                else
                    strParent = FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget))));
                CString strNode(FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget)))));
                strWhere = FUN_140741200("targetNode:{0}, parent:{1}", strNode, strParent);
            }
            else
            {
                NiAVObjectPtr spModel = m_spModel;
                MS2Ptr<CEquipItem> spModelEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(FUN_1409849b0(&spModel), 0, 6, false);
                if (spModelEquip.get() == 0)
                {
                    CString strNode(FUN_142087e50(FUN_1409a8b90(FUN_14098d0f0(&spModel))));
                    strWhere = FUN_140536a50("targetNode:{0} in character", strNode);
                }
                else
                {
                    int nItemId = FUN_1411dc820(spModelEquip.get());
                    CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
                    strWhere = StringFormat("targetNode:{0}, itemID:{1}({2})", CString(FUN_142087e50(FUN_1409a8b90(FUN_14098d0f0(&spModel)))), nItemId, CString((const wchar_t*)strName));
                }
            }
        }
        else
        {
            int nItemId = FUN_1411dc820(spEquip.get());
            CStringW strName = FUN_1401a9d70()->FUN_141811980(1, nItemId);
            strWhere = StringFormat("targetNode:{0}, itemID:{1}({2})", CString(FUN_142087e50(FUN_1409a8b90(static_cast<NiAVObject*>(FUN_1409475f0(&kTarget))))), nItemId, CString((const wchar_t*)strName));
        }
    }
    if (FUN_140166440() != 0)
        Unk_NifLog3(FUN_140166440(), 0xc, 0x133, L"LOD level [{0}] [{1}] [{2}]", m_nLodLevel, m_spParam->m_strFilePath, strWhere);
}

// @0x14154cf20
// Re-applies the "Eff_LOD=<n>" extra-data levels of the model: parts above the current quality level are culled.
void CNifEffect::FUN_14154cf20(NiAVObject* pkRoot)
{
    int nLevel = (int)FUN_1403ed280()->FUN_1411a88c0();
    if (m_nLodLevel != nLevel)
    {
        m_nLodLevel = nLevel;
        Unk_SceneWalker kWalker(pkRoot);
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            if (FUN_14098dad0(pObj) != true)
            {
                NiStringExtraData* pTag = static_cast<NiStringExtraData*>(FUN_14098d8d0(&NiStringExtraData::ms_RTTI, FUN_141d17b40(pObj, &DAT_143ae51b8)));
                if (pTag != 0)
                {
                    int nLod = 0;
                    std::string strTag(FUN_142087e50(FUN_141168130(pTag)));
                    size_t nPos = strTag.find("Eff_LOD=", 0);
                    if (nPos != std::string::npos)
                    {
                        nLod = atoi(strTag.c_str() + 8 + nPos);
                        if (m_nLodLevel < nLod)
                            FUN_140a0b300(pObj, true);
                    }
                }
            }
        }
    }
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154d0d0
// Loads the nif (cache) and returns a plain NiNode wrapping it; the model remembers its path in extra data.
Unk_NodePtr CNifEffect::FUN_14154d0d0(const CString& strPath, int nA, int nB)
{
    Unk_NodePtr kWrapper(new (efd::MemHint(efd::MemHint::NONE)) NiNode(0));
    NiAVObjectPtr spModel = FUN_140a0afd0()->Load(CString(strPath), false, 5, nA, nB);
    Unk_NodePtr kNode(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&spModel)));
    if (FUN_1409475d0(&kNode) != 0)
    {
        NiAVObject* pNode = static_cast<NiAVObject*>(FUN_1409475f0(&kNode));
        if (FUN_141d17b40(pNode, &DAT_143ae5198) == 0)
        {
            NiStringExtraData* pPath = new (efd::MemHint(efd::MemHint::NONE)) NiStringExtraData(NiFixedString((const char*)strPath));
            static_cast<NiAVObject*>(FUN_1409475f0(&kNode))->AddExtraData(*(NiFixedString*)&DAT_143ae5198, pPath);
        }
        FUN_14154fda0(FUN_1409475f0(&kNode));
        static_cast<NiNode*>(FUN_1409475f0(&kWrapper))->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&kNode)), false);
    }
    return kWrapper;
}

// MS2-FUNCTIONAL: behaviour-equivalent; codegen (temporaries / branch layout) not byte-identical to the exe
// @0x14154d410
// Finds the model node pszName of the target: through the equipment of the owning player, else by walking the
// owner's scene graph for a node of that name worn in the right slot.
NiAVObjectPtr CNifEffect::FUN_14154d410(Unk_EffectTarget* pTarget, const char* pszName, bool bFlag)
{
    Unk_NifTarget* pT = reinterpret_cast<Unk_NifTarget*>(pTarget);
    if (pTarget == 0 || FUN_1409a7f70(&pT->m_hNode, 0) || pszName == 0)
        return NiAVObjectPtr(0);
    Unk_NifPCPtr spPC(FUN_14099eef0(pTarget->FUN_140a533b0()));
    if (FUN_140c206b0(&spPC, 0))
        return NiAVObjectPtr(0);
    NiAVObjectPtr spFound(0);
    if (FUN_140a53440(pTarget) != 0)
    {
        CString strName(pszName);
        spFound = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2a60(FUN_140a53440(pTarget), strName, bFlag);
    }
    if (FUN_1409a7f70(&spFound, 0))
    {
        int nKind = FUN_140a53480(pTarget);
        Unk_SceneWalker kWalker(FUN_1409849b0(&pT->m_hNode));
        while (NiAVObject* pObj = kWalker.Next(true))
        {
            if (!FUN_141068d50(FUN_1409a8b90(pObj), pszName))
            {
                MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(FUN_140aac440(&spPC))->FUN_1411e2610(pObj, 1, nKind, bFlag);
                bool bSkip;
                if (spEquip.IsNull())
                {
                    bSkip = true;
                }
                else
                {
                    MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
                    bSkip = spItem.get() == 0;
                }
                if (!bSkip)
                {
                    bool bOther;
                    if (nKind == 6)
                    {
                        bOther = false;
                    }
                    else
                    {
                        MS2Ptr<CItem> spItem = spEquip->FUN_1411dc7a0();
                        bOther = FUN_14052a170(spItem.get()) != nKind;
                    }
                    if (!bOther)
                    {
                        FUN_1409fabf0(&spFound, pObj);
                        break;
                    }
                }
            }
        }
    }
    return spFound;
}

// ============================================================================================================
// CNiStreamLoadThread / CNifLoadingService (0x1415509b0-0x141556920)
// ============================================================================================================
class Unk_NifFileMgr
{
public:
    // Reads a file of the data tree into a buffer (freed by the caller); pstrDir receives its directory.
    int FUN_1403972f0(const char* pszPath, void** ppBuf, int* pnSize, std::string* pstrDir);
};
Unk_NifFileMgr* FUN_140166420();
class Unk_NifGate { public: bool FUN_1406af080(); };                 // the loader should read on the caller's thread
Unk_NifGate* FUN_1406aeee0();
void FUN_140659080(Unk_140659080& kStartup, unsigned nError);        // record the start-up error
unsigned FUN_140869420();                                            // random seed
void FUN_14028e7c0(CString& strPath);                                // normalize a path in place
void FUN_1403a1280(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const char* const& pszArg);

CNiStreamLoadThread* TSingleton<CNiStreamLoadThread>::s_instance = 0;
inline TSingleton<CNiStreamLoadThread>::TSingleton() { s_instance = static_cast<CNiStreamLoadThread*>(this); }

// @0x1415509b0
CNiStreamLoadThread::CNiStreamLoadThread() : m_mapQueued(10), m_lstQueue(10), m_mapDone(10), m_spPalette(0)
{
    m_nPause = 0;
    m_hStop = 0;
    m_nStop = 0;
    m_hWork = CreateSemaphoreA(0, 0, 0x7fffffff, 0);
    m_pParam = 0;
}

// MS2-FUNCTIONAL: map walk / lock scope temporaries differ from the exe
// @0x141550af0
CNiStreamLoadThread::~CNiStreamLoadThread()
{
    if (Unk_LockGuard kGuard = m_kDoneLock)
    {
    }
    else
    {
        POSITION pos = m_mapDone.GetHeadPosition();
        while (pos != 0)
        {
            NiStream* pStream = m_mapDone.GetValueAt(pos);
            delete pStream;
            m_mapDone.GetNext(pos);
        }
        m_mapDone.RemoveAll();
    }
    if (m_hWork != 0)
        CloseHandle(m_hWork);
    if (m_hStop != 0)
        CloseHandle(m_hStop);
    m_spPalette = 0;
}

// MS2-FUNCTIONAL: the wait loop is restructured
// @0x141550cf0
unsigned CNiStreamLoadThread::vfunc_1(void* pParam, Unk_140659080& kStartup)
{
    m_pParam = pParam;
    m_hStop = CreateEventA(0, 0, 0, 0);
    if (m_hStop == 0)
    {
        FUN_140659080(kStartup, 0x80004005);
        return 0xffffffff;
    }
    kStartup.FUN_1401d42d0();
    srand(FUN_140869420());
    for (;;)
    {
        if (m_nPause == 0)
        {
            WaitForSingleObject(m_hWork, 0xffffffff);
            if (m_nStop != 0)
                break;
            CString strPath;
            if (Unk_LockGuard kGuard = m_kQueueLock)
            {
            }
            else
            {
                if (m_lstQueue.IsEmpty())
                    continue;
                strPath = m_lstQueue.RemoveHead();
                m_mapQueued.RemoveKey(strPath);
            }
            Load(CString(strPath), 1);
        }
        if (WaitForSingleObject(m_hStop, 10) == 0)
            break;
    }
    return 0;
}

// @0x141550f20
void CNiStreamLoadThread::Stop()
{
    if (m_hStop != 0)
        SetEvent(m_hStop);
    if (m_hWork != 0)
    {
        m_nStop = 1;
        ReleaseSemaphore(m_hWork, 1, 0);
        FUN_1401d3510(0xffffffff);
    }
}

// MS2-FUNCTIONAL: lock scope and list/map call order differ from the exe
// @0x141550f90
void CNiStreamLoadThread::Enqueue(CString strPath)
{
    if (!strPath.IsEmpty())
    {
        FUN_14028e7c0(strPath);
        if (Unk_LockGuard kGuard = m_kQueueLock)
        {
        }
        else
        {
            if (FUN_1406aeee0()->FUN_1406af080())
            {
                Load(CString(strPath), 1);
                return;
            }
            if (m_mapQueued.Lookup(strPath) == 0)
            {
                POSITION pos = m_lstQueue.AddTail(strPath);
                m_mapQueued.SetAt(strPath, pos);
                ReleaseSemaphore(m_hWork, 1, 0);
            }
        }
    }
}

// @0x1415510f0
void CNiStreamLoadThread::SetTexturePalette(NiPointer<NiTexturePalette> spPalette)
{
    m_spPalette = spPalette;
}

// MS2-FUNCTIONAL: lock scope and temporaries differ from the exe
// @0x141551140
NiStream* CNiStreamLoadThread::Get(CString strPath)
{
    FUN_14028e7c0(strPath);
    Dequeue(CString(strPath));
    NiStream* pStream = 0;
    if (Unk_LockGuard kGuard = m_kDoneLock)
    {
    }
    else if (m_mapDone.Lookup(strPath, pStream))
    {
        m_mapDone.RemoveKey(strPath);
        return pStream;
    }
    return Load(CString(strPath), 0);
}

// @0x1415512c0
void CNiStreamLoadThread::Pause() { m_nPause = 1; }
// @0x1415512e0
void CNiStreamLoadThread::Resume() { m_nPause = 0; }

// @0x141551300
void CNiStreamLoadThread::Dequeue(CString strPath)
{
    if (!strPath.IsEmpty())
    {
        FUN_14028e7c0(strPath);
        if (Unk_LockGuard kGuard = m_kQueueLock)
        {
        }
        else
        {
            ATL::CRBMap<CString, POSITION>::CPair* pPair = m_mapQueued.Lookup(strPath);
            if (pPair != 0)
            {
                m_lstQueue.RemoveAt(pPair->m_value);
                m_mapQueued.RemoveAt(pPair);
            }
        }
    }
}

// MS2-FUNCTIONAL: big function: codegen (temporaries / branch layout) not byte-identical to the exe
// @0x1415513e0
NiStream* CNiStreamLoadThread::Load(CString strPath, int bKeep)
{
    FUN_14028e7c0(strPath);
    NiStream* pStream = EE_NEW NiStream;
    pStream->SetTexturePalette(m_spPalette);
    std::string strDir;
    void* pBuf;
    int nSize;
    if (FUN_140166420()->FUN_1403972f0(strPath, &pBuf, &nSize, &strDir))
    {
        pStream->GetSearchPath()->SetReferencePath(strDir.c_str());
        if (!pStream->Load(static_cast<char*>(pBuf), nSize))
        {
            delete pStream;
            const char* pszPath = strDir.c_str();
            FUN_1403a1280(FUN_140166440(), 1, 0x13, L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[{0}]", pszPath);
            return 0;
        }
        NiFree(pBuf);
    }
    NiStream* pFound = 0;
    if (pStream != 0 && pStream->GetObjectCount() != 0)
    {
        if (bKeep == 0)
            return pStream;
        if (Unk_LockGuard kGuard = m_kDoneLock)
        {
        }
        else if (!m_mapDone.Lookup(strPath, pFound))
        {
            m_mapDone.SetAt(strPath, pStream);
            return pStream;
        }
    }
    delete pStream;
    return pFound;
}
