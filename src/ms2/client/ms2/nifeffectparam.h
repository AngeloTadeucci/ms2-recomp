// nifeffectparam.h - the "Nif" effect (effect XML type 1): plays a .nif model as an effect, optionally attached to a
// node/bone of the target. CNifEffectParam (param, CEffectParam), CNifEffect (runtime effect, CEffect),
// DuplicatedAlphaController (alpha controller clone used to fade a nif out) and the nif cache/loader service
// CNifLoadingService + CNiStreamLoadThread. Owning unit: ?\nifeffectparam.cpp (0x141548790-0x141562ee0, .text$di
// 0x1400fa2f0). Header name assumed from the unit path. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiNode.h>
#include <NiAlphaController.h>
#include <NiTransform.h>
#include <NiRTTI.h>
#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/lighteffectparam.h"        // Unk_LightUpdateBits (bitset<3>)
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T>
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

class CEffectObject;
class CBirdMovement;

// 0x58 bytes (operator delete size in the deleting dtor). A NiAlphaController copied from an existing controller
// (CopyMembers with the clone map target -> target) whose output is scaled by m_fScale. vftable = NiAlphaController's
// 0x? slots with Update replaced; dtor 0x14154f230, ??_G 0x14154f790, GetRTTI 0x14154fa00, RTTI "DuplicatedAlphaController"
// 0x143ae1ef8.
class DuplicatedAlphaController : public NiAlphaController
{
    NiDeclareRTTI;
public:
    explicit DuplicatedAlphaController(NiSingleInterpController* pkSource);        // 0x141548790
    virtual ~DuplicatedAlphaController();                                   // 0x14154f230
    virtual void Update(float fTime);                                       // 0x141548880
    // @0x141548850
    void SetScale(float fScale) { m_fScale = fScale; }

    float m_fScale;                 // +0x50 multiplies the interpolated alpha
    char m_pad_54[4];
};
MS2_CHECK_SIZE(DuplicatedAlphaController, 0x58);
MS2_CHECK_OFFSET(DuplicatedAlphaController, m_fScale, 0x50);

typedef efd::SmartPointer<DuplicatedAlphaController> DuplicatedAlphaControllerPtr;

// 0xc0 bytes. Overrides vfuncs 1-6. Implicit-style dtor 0x14154f1c0, ??_G 0x14154f750.
class CNifEffectParam : public CEffectParam
{
public:
    CNifEffectParam();                                          // 0x141548990
    virtual ~CNifEffectParam();                                 // 0x14154f1c0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141548b90 parse the <nif> element
    virtual bool vfunc_2();                                     // 2 0x1415491c0 validate
    virtual bool vfunc_3();                                     // 3 0x1415491f0 preload the nif (true when none)
    virtual void vfunc_4();                                     // 4 0x1415492a0 release the nif cache entry
    virtual bool vfunc_5(int n);                                // 5 0x141549340 load the nif into the cache
    virtual CEffectPtr vfunc_6();                               // 6 0x141549430 new CNifEffect
public:
    MS2_LAYOUT_FRIEND;
    CString m_strFilePath;              // +0x48 "filePath" (relative to "Effect")
    Unk_StreamPoint m_ptTranslate;      // +0x50 <transform translate>
    Unk_StreamPoint m_ptRotation;       // +0x5c <transform rotation> (degrees)
    float m_fScale;                     // +0x68 <transform scale> = 1
    bool m_bApplyNodeTransform;         // +0x6c <attachInfo applyNodeTransform>
    bool m_bOnGround;                   // +0x6d <attachInfo onGround>
    bool m_bUseLighting;                // +0x6e <attachInfo useLighting> = true
    bool m_bUseShadow;                  // +0x6f <attachInfo useShadow>
    int m_nAttachType;                  // +0x70 <attachInfo attachType>: 0 none, 1 Node, 2 Mesh, 3 WeaponL, 4 WeaponR
    CString m_strParentNode;            // +0x78 <attachInfo parentNode>
    Unk_LightUpdateBits m_bitsUpdate;   // +0x80 <update translate/rotation/scale>, all set by default
    Unk_LightUpdateBits m_bitsApply;    // +0x81 <applyNodeTransform ...>, set when the element says false
    int m_nMyReferCount;                // +0x84 "myReferCount"
    int m_nOtherReferCount;             // +0x88 "otherReferCount"
    CString m_strLerpType;              // +0x90 <lerp type> ("bird" selects CBirdMovement)
    float m_fMaxLength;                 // +0x98 <lerp MaxLength> = 500
    float m_fMinLength;                 // +0x9c <lerp MinLength> = 1
    float m_fStep;                      // +0xa0 <lerp Step> = 0.01
    float m_fVelocity;                  // +0xa4 <lerp Velocity> = 300
    bool m_bNotForceStop;               // +0xa8 "notForceStop"
    bool m_bOffFadeOut;                 // +0xa9 "offFadeOut"
    float m_fViewDistance;              // +0xac "viewDistance" = -1
    bool m_bBipedLoop;                  // +0xb0 "bipedLoop"
    CString m_strEffectObjectKfm;       // +0xb8 "effectObjectKfmName"
};
MS2_CHECK_SIZE(CNifEffectParam, 0xc0);
MS2_CHECK_OFFSET(CNifEffectParam, m_strFilePath, 0x48);
MS2_CHECK_OFFSET(CNifEffectParam, m_fScale, 0x68);
MS2_CHECK_OFFSET(CNifEffectParam, m_nAttachType, 0x70);
MS2_CHECK_OFFSET(CNifEffectParam, m_strParentNode, 0x78);
MS2_CHECK_OFFSET(CNifEffectParam, m_bitsApply, 0x81);
MS2_CHECK_OFFSET(CNifEffectParam, m_nOtherReferCount, 0x88);
MS2_CHECK_OFFSET(CNifEffectParam, m_strLerpType, 0x90);
MS2_CHECK_OFFSET(CNifEffectParam, m_fVelocity, 0xa4);
MS2_CHECK_OFFSET(CNifEffectParam, m_fViewDistance, 0xac);
MS2_CHECK_OFFSET(CNifEffectParam, m_strEffectObjectKfm, 0xb8);

// CBirdMovement (0x60 bytes, CPtred-based): the bird-like lerp movement of the "bird" lerp type. Constructed by the
// exe (0x1411a3...); only the members this unit sets are named.
class CBirdMovement : public CPtred
{
public:
    CBirdMovement();                                            // out of unit
    void FUN_141207fb0(float f);                                // out of unit (step)
    char m_pad_18[0x38];
    float m_fVelocity;                                          // +0x50 (setter 0x141550030)
    float m_fMaxLength;                                         // +0x54 (setter 0x14154ff50)
    float m_fMinLength;                                         // +0x58 (setter 0x14154ff70)
    char m_pad_5c[4];
    void SetMaxLength(float f) { m_fMaxLength = f; }            // @0x14154ff50
    void SetMinLength(float f) { m_fMinLength = f; }            // @0x14154ff70
    void SetVelocity(float f) { m_fVelocity = f; }              // @0x141550030
};
MS2_CHECK_SIZE(CBirdMovement, 0x60);
MS2_CHECK_OFFSET(CBirdMovement, m_fMinLength, 0x58);

// 0xd8 bytes. vftable 13 slots. dtor 0x141549620, ??_G 0x14154f6f0. RTTI "CNifEffect" 0x143ae1f08.
class CNifEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14154f9f0
public:
    CNifEffect();                                               // 0x1415494d0
    virtual ~CNifEffect();                                      // 0x141549620
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x1415496f0 build the nif instance
    virtual void vfunc_4();                                     // 4 0x14154acf0 start (re-parent, first update)
    virtual void vfunc_5();                                     // 5 0x14154aef0
    virtual void vfunc_6(float fFadeTime);                      // 6 0x14154af40 fade out
    virtual void vfunc_7();                                     // 7 0x14154b080 detach
    virtual int vfunc_8(void* p);                               // 8 0x14154b160 world position of the root
    virtual bool vfunc_9();                                     // 9 0x14154a7e0 per-update
    virtual void vfunc_10(bool bVisible);                       // 10 0x14154b420
    virtual int vfunc_11();                                     // 11 0x14154b1b0
    virtual int vfunc_12();                                     // 12 0x14154f9d0 effect type 1

    float FUN_14154b470();                                      // duration of the nif animation
    bool FUN_14154b4a0(NiObjectNET* pkNode);                    // swap the alpha controllers for duplicates
    bool FUN_14154b5e0();                                       // fade out allowed (param not "notForceStop")
    void FUN_14154b630(NiObjectNET* pkNode, float fTime);       // add a fade-out controller
    void FUN_14154ba40(Unk_EffectTarget* pTarget);              // attach type 0
    void FUN_14154bdd0(Unk_EffectTarget* pTarget);              // attach type 1
    void FUN_14154c260(Unk_EffectTarget* pTarget);              // attach type 2
    void FUN_14154c440(Unk_EffectTarget* pTarget, int nSlot);   // attach type 3/4
    void FUN_14154c580();                                       // wrap in a SeparateNode / make relative
    void FUN_14154c7f0(Unk_EffectTarget* pTarget);              // log "LOD level"
    void FUN_14154cf20(NiAVObject* pkRoot);                     // apply the "Eff_LOD" level
    Unk_NodePtr FUN_14154d0d0(const CString& strPath, int nA, int nB);     // load the nif
    NiAVObjectPtr FUN_14154d410(Unk_EffectTarget* pTarget, const char* pszName, bool b);

public:
    MS2_LAYOUT_FRIEND;
    bool m_bSplit;                          // +0x30 the model was split off a parent (type 1 after the duration)
    char m_pad_31[7];
    Unk_NodePtr m_spTarget;                 // +0x38 the node the effect hangs on
    NiAVObjectPtr m_spModel;                // +0x40 the attach model/bone object
    NiTransform m_kXform;                   // +0x48 local transform (0x34)
    char m_pad_7c[4];
    Unk_NodePtr m_spSplit;                  // +0x80 plain NiNode created for the split
    Unk_NodePtr m_spRoot;                   // +0x88 "Effect Root" EffectNode
    float m_fFadeStart;                     // +0x90
    float m_fFadeTime;                      // +0x94
    int m_nLodLevel;                        // +0x98
    float m_fStartTime;                     // +0x9c
    ATL::CAtlArray<DuplicatedAlphaControllerPtr> m_aAlphaCtrls;     // +0xa0
    efd::SmartPointer<CEffectObject> m_spEffectObject;              // +0xc0 kfm effect object
    MS2Ptr<CNifEffectParam> m_spParam;      // +0xc8
};
MS2_CHECK_SIZE(CNifEffect, 0xd8);
MS2_CHECK_OFFSET(CNifEffect, m_spTarget, 0x38);
MS2_CHECK_OFFSET(CNifEffect, m_kXform, 0x48);
MS2_CHECK_OFFSET(CNifEffect, m_spRoot, 0x88);
MS2_CHECK_OFFSET(CNifEffect, m_aAlphaCtrls, 0xa0);
MS2_CHECK_OFFSET(CNifEffect, m_spParam, 0xc8);
