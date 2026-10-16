// effectservice.h - the effect data cache (CEffectData, EffectDataManager) and the effect param factory of
// client\ms2\effectservice.cpp. CEffect / CEffectParam (the runtime effect and the param base) are in effectparam.h.
// Header name assumed; member names are invented from use.
//
// Effect files live in ./Data/Xml/Effect/<name>.xml: <ms2><effect type="nif" .../>...</ms2>. Each <effect> becomes one
// CEffectParam subclass (FUN_1411a04e0 by the "type" attribute, FUN_1411a0f80); the params of one file form a CEffectData,
// which EffectDataManager caches by lower-case path.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"            // MS2Ptr<T>
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/client/ms2/effectparam.h"

// Effect param kinds (the "type" attribute; CEffectParam::m_nType).
enum
{
    kEffectNone = 0,
    kEffectNif = 1,
    kEffectSoundEvent = 2,
    kEffectSoundMusic = 3,
    kEffectMonochrome = 4,
    kEffectRadialBlur = 5,
    kEffectWeather = 6,
    kEffectSwoosh = 7,
    kEffectStatus = 8,
    kEffectLight = 9,
    kEffectFog = 10,
    kEffectRandom = 11,
    kEffectVibrate = 12,
    kEffectRibbon = 13,
    kEffectChaosLight = 14,
    kEffectTextureOverride = 15,
    kEffectLightning = 16,
    kEffectCameraMove = 17,
    kEffectScreenMasking = 18,
    kEffectGaussianBlur = 19,
    kEffectPostShimmer = 20,
    kEffectBeam = 21,
    kEffectAfterImage = 22,
};

int FUN_1411a0f80(const CString& strType);                  // 0x1411a0f80 type name -> kind (case-insensitive)
CString FUN_1411a12f0(int nType);                           // 0x1411a12f0 kind -> display name ("NULL" if unknown)
int FUN_1411a16c0(Unk_140165cf0* pNode, const char* pszName, int& nType);   // 0x1411a16c0 read a type attribute
MS2Ptr<CEffectParam> FUN_1411a04e0(const CString& strName, Unk_140165cf0* pNode);   // 0x1411a04e0 create + load one param
CEffectPtr FUN_14119eae0(CEffectParam* pParam, Unk_EffectTarget* pTarget);  // 0x14119eae0 create the runtime effect

typedef MS2Ptr<CEffectParam> CEffectParamPtr;

// 0x58 bytes, vftable 0x142eba0e8 (1 slot, ??_G 0x1411a1d70). The params of one effect file.
class CEffectData : public CCacheData
{
public:
    CEffectData();                                          // 0x14119f4b0
    virtual ~CEffectData();                                 // 0x14119f500

    ATL::CAtlList<CEffectParamPtr>& FUN_14119f540();        // 0x14119f540 the param list
    void FUN_14119f560(CEffectParam* pParam);               // 0x14119f560 append
    bool FUN_14119f5c0();                                   // 0x14119f5c0 no params
    bool FUN_14119f5f0();                                   // 0x14119f5f0 some param has ignoreOptimize
    bool FUN_14119f680();                                   // 0x14119f680 every param is ready (vfunc_3)
    void FUN_14119f710();                                   // 0x14119f710 vfunc_4 on each param that is not ready

public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<CEffectParamPtr> m_params;                // +0x28
};
MS2_CHECK_SIZE(CEffectData, 0x58);
MS2_CHECK_OFFSET(CEffectData, m_params, 0x28);
typedef MS2Ptr<CEffectData> CEffectDataPtr;

// 0x68 bytes, vftable 0x142eba108 (1 slot, ??_G 0x1411a1e70). Effect file cache.
class EffectDataManager : public TSingleton<EffectDataManager>
{
public:
    EffectDataManager();                                    // 0x14119f7b0
    virtual ~EffectDataManager();                           // 0x14119f820

    CEffectDataPtr FUN_14119f870(CString strPath);          // 0x14119f870 cached load
    void FUN_14119fa60();                                   // 0x14119fa60 load every file of ./Data/Xml/Effect
    CEffectDataPtr FUN_14119fc50(const CString& strPath);   // 0x14119fc50 parse one file

public:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x08
    ATL::CRBMap<CString, CEffectDataPtr> m_map;             // +0x38 path -> data
};
MS2_CHECK_SIZE(EffectDataManager, 0x68);
MS2_CHECK_OFFSET(EffectDataManager, m_map, 0x38);

// ---- second CU: EffectNode and CEffectService ----
#include "ms2/client/ms2/lightunaffectednode.h"
class CEffectDummy;

// INodeMovement (RTTI name; 0x60 bytes, vftable 0x142f45cd8, 3 slots, dtor 0x141626240): the base of the effect
// node movements (CBirdMovement, COrbMovement) an EffectNode applies to its world transform.
class INodeMovement : public CPtred
{
public:
    virtual ~INodeMovement();                                   // 0x141626240
    virtual INodeMovement* Clone() = 0;                         // slot 1
    NiTransform FUN_141625430(double dTime, const NiTransform& kWorld);     // moved world transform

    char m_pad_18[0x48];
};
MS2_CHECK_SIZE(INodeMovement, 0x60);

// EffectNode (RTTI name; 400 bytes, vftable 0x142eba238, ms_RTTI 0x143ad1588): the root node of a runtime effect.
// Follows its parent's world transform (optionally without the parent scale, or keeping only the parent's position
// and an own rotation turned by a target object), applies an optional movement and can snap to the ground.
class EffectNode : public LightUnaffectedNode
{
public:
    EffectNode(bool bUpdateEffects, bool bTemplate);            // 0x1411a34b0
    explicit EffectNode(const CEffectDummy& kDummy);            // 0x1411a35b0 (named after the dummy, 3cb0)
    virtual ~EffectNode();                                      // 0x1411a36b0, ??_G 0x1411a3f40
    virtual const NiRTTI* GetRTTI() const;                      // slot 2, 0x1411a3fc0
    virtual NiObject* CreateClone(NiCloningProcess& kCloning);  // slot 3, 0x1411a32c0
    virtual void UpdateWorldData();                             // slot 32, 0x1411a3720
    void CopyMembers(EffectNode* pkDest, NiCloningProcess& kCloning);   // 0x1411a3380

    void FUN_1411a3cb0(const CEffectDummy& kDummy);             // transform and attach flags from a dummy
    void FUN_1411a3db0(INodeMovement* pMovement);               // set the movement
    void FUN_1411a3fa0(int bOnGround);                          // snap to the ground
    void FUN_1411a3fd0(NiAVObject* pTarget);                    // rotation target (ignored if this)
    void FUN_1411a4000(const NiMatrix3& kRot);                  // local + own rotation
    void FUN_1411a4040(const NiPoint3& kPos);                   // local + own translation

    static const NiRTTI ms_RTTI;

    MS2_LAYOUT_FRIEND;
    NiAVObject* m_pTarget;                                      // +0x138
    int m_bApplyWorldTransform;                                 // +0x140 keep only the parent position
    int m_bApplyLocalScale;                                     // +0x144 keep the parent scale
    int m_bOnGround;                                            // +0x148
    NiPoint3 m_kTranslate;                                      // +0x14c
    NiMatrix3 m_kRotate;                                        // +0x158
    int m_unk_17c;                                              // +0x17c 1, 2 when made from a dummy
    MS2Ptr<INodeMovement> m_spMovement;                         // +0x180
};
MS2_CHECK_SIZE(EffectNode, 400);
MS2_CHECK_OFFSET(EffectNode, m_pTarget, 0x138);
MS2_CHECK_OFFSET(EffectNode, m_kTranslate, 0x14c);
MS2_CHECK_OFFSET(EffectNode, m_kRotate, 0x158);
MS2_CHECK_OFFSET(EffectNode, m_spMovement, 0x180);
