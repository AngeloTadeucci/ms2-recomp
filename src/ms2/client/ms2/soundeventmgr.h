// soundeventmgr.h - sound events: the effect XML type 2 "SoundEvent" (param + runtime effect), the FMOD event wrapper
// CSoundEvent and the event manager CSoundEventMgr. Owning unit: client\ms2\soundeventmgr.cpp
// (0x141775810-0x14178fd20 .text$mn, 0x140101560-0x140101680 .text$di). Header name assumed from the unit path.
// Member names are invented from use. Replaces the local stubs in effectservice.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiRTTI.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/placeholder/fmodwrap.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/effectparam.h"

#include "ms2/placeholder/ctwocirclecollision.h"

// The playing FMOD event (0x38 bytes, CPtred based). Owns the 3D attenuation shape built from the event's
// 3DMinDistance / 3DMaxDistance properties.
class CSoundEvent : public CPtred
{
public:
    CSoundEvent(FMOD::Event* pEvent, CString strName);          // 0x14177a590
    virtual ~CSoundEvent();                                     // 0x14177a800

    bool FUN_14177a8d0();                                       // start
    void FUN_14177a920(int bFadeOut);                           // stop (0 = request stop, else reset)
    void FUN_14177a990(const Unk_StreamPoint& vPos);            // 3D position (+ attenuation shape)
    void FUN_14177aac0(const Unk_StreamPoint& vPos, const Unk_StreamPoint& vVel);   // 3D position + velocity
    int FUN_14177ab80();                                        // the event is playing
    // @0x1411b1ba0
    CTwoCircleCollision* FUN_1411b1ba0() { return m_pRange; }
    void FUN_14177abc0(FMOD_EVENT_CALLBACK pfnCallback, void* pUserData);
    bool FUN_14177ac00();                                       // getMute succeeded
    void FUN_14177ac50(bool bMute);
    int FUN_14177ac80();                                        // started or stopped
    CString FUN_14177aca0();                                    // the event name
    void FUN_14177acf0(float fVolume);

public:
    MS2_LAYOUT_FRIEND;
    CTwoCircleCollision* m_pRange;  // +0x18 attenuation shape (null when the event has no 3D distances)
    FMOD::Event* m_pEvent;          // +0x20
    int m_nStarted;                 // +0x28
    int m_nStopped;                 // +0x2c
    CString m_strName;              // +0x30
};
MS2_CHECK_SIZE(CSoundEvent, 0x38);
MS2_CHECK_OFFSET(CSoundEvent, m_pRange, 0x18);
MS2_CHECK_OFFSET(CSoundEvent, m_pEvent, 0x20);
MS2_CHECK_OFFSET(CSoundEvent, m_strName, 0x30);
typedef MS2Ptr<CSoundEvent> CSoundEventPtr;

// Effect XML type 2 <SoundEvent event= group= byJob= .../> (0x110 bytes). vftable 0x142f64130.
class CSoundEventEffectParam : public CEffectParam
{
public:
    CSoundEventEffectParam();                                   // 0x141775810
    virtual ~CSoundEventEffectParam();                          // 0x1417782b0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141775af0
    virtual bool vfunc_2();                                     // 2 0x141775cb0 validate the event / group names
    virtual CEffectPtr vfunc_6();                               // 6 0x141775fc0 new CSoundEventEffect
    virtual bool vfunc_7(Unk_EffectTarget* pTarget);            // 7 0x141776060

    bool FUN_1417760d0() const;                                       // the cooltime is over (or none)
    CString FUN_141776120(int nJob) const;                            // the event name for the job
    const CString& FUN_141776260() const { return m_strGroup; }
    const CString& FUN_141776280() const { return m_strParentNode; }
    float FUN_1417762a0(int nJob) const;                              // the start delay for the job
    void FUN_141776330(Unk_140165cf0* pNode);                   // "jobEvent"  = job:event,...
    void FUN_1417764c0(Unk_140165cf0* pNode);                   // "byJobStartDelay" = job:delay,...

public:
    MS2_LAYOUT_FRIEND;
    bool m_bAttachToNode;           // +0x48 "attachToNode"
    bool m_bApplyNodeTransform;     // +0x49 "applyNodeTransform"
    bool m_bDoNotStop;              // +0x4a "doNotStop"
    float m_fVolume;                // +0x4c = 1
    float m_fViewDistance;          // +0x50 "forceHearDistance" (0 = use the table)
    CString m_strExtra;             // +0x58
    CString m_strEvent;             // +0x60 "event"
    CString m_strGroup;             // +0x68 "group"
    CString m_strParentNode;        // +0x70 "parentNode"
    bool m_bByJob;                  // +0x78 "byJob"
    bool m_bSkipMusicConcert;       // +0x79 "isSkipMusicConcert"
    unsigned m_nCooltimeId;         // +0x7c "cooltimeID"
    ATL::CAtlMap<int, CString> m_mapJobEvent;   // +0x80 job -> event
    ATL::CAtlMap<int, float> m_mapJobDelay;     // +0xc8 job -> start delay
};
MS2_CHECK_SIZE(CSoundEventEffectParam, 0x110);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_fViewDistance, 0x50);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_strParentNode, 0x70);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_mapJobEvent, 0x80);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_mapJobDelay, 0xc8);

// The runtime effect (CEffect::vfunc_12 == 2, 0x68 bytes). vftable 0x142f64178, RTTI "CSoundEventEffect" 0x143aea240.
class CSoundEventEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141778be0
public:
    CSoundEventEffect();                                        // 0x141776630
    virtual ~CSoundEventEffect();                               // 0x1417766e0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141776760
    virtual void vfunc_4();                                     // 4 0x141777370 start
    virtual void vfunc_5();                                     // 5 0x141777520 stop
    virtual void vfunc_7();                                     // 7 0x141777670 detach
    virtual int vfunc_8(void* p);                               // 8 0x1417776b0 world position of the root
    virtual bool vfunc_9();                                     // 9 0x1417771a0 per-update
    virtual int vfunc_12();                                     // 12 0x141778980 effect type 2

    CString& FUN_141777700() { return m_strExtra; }
    MS2Ptr<CSoundEvent> FUN_141777720();                        // the playing sound
    void FUN_141777770() { m_b2d = true; }                      // finished

public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spRoot;           // +0x30 "Effect Root" node
    float m_fVolume;                // +0x38
    MS2Ptr<CSoundEvent> m_spSound;  // +0x40
    bool m_bDoNotStop;              // +0x50
    bool m_bStopRequested;          // +0x51
    double m_dStopTime;             // +0x58 stop requested: the sound is released at this time
    CString m_strExtra;             // +0x60 param m_strExtra
};
MS2_CHECK_SIZE(CSoundEventEffect, 0x68);
MS2_CHECK_OFFSET(CSoundEventEffect, m_spRoot, 0x30);
MS2_CHECK_OFFSET(CSoundEventEffect, m_spSound, 0x40);
MS2_CHECK_OFFSET(CSoundEventEffect, m_dStopTime, 0x58);
MS2_CHECK_OFFSET(CSoundEventEffect, m_strExtra, 0x60);

// FMOD event callback of the effect (0x1417775b0): 4 = event finished, 6 = sound def created.
FMOD_RESULT F_CALLBACK FUN_1417775b0(FMOD_EVENT* pEvent, FMOD_EVENT_CALLBACKTYPE eType, void* pParam1, void* pParam2,
                                     void* pUserData);

template <class T> class TSingleton;
class CSoundEventMgr;
template <> class TSingleton<CSoundEventMgr>
{
public:
    TSingleton();                                   // 0x141786300
    virtual ~TSingleton() { s_instance = 0; }
    static CSoundEventMgr* s_instance;              // 0x143ac1928
};

// The FMOD event manager singleton (m_bReady at +0x8c gates every call).
class CSoundEventMgr : public TSingleton<CSoundEventMgr>
{
public:
    CSoundEventMgr();                                           // 0x14177ad20
    virtual ~CSoundEventMgr();                                  // 0x14177aea0

    void FUN_14177af40(FMOD::EventSystem* pSystem, void* pParam);   // attach the event system, fetch the categories
    MS2Ptr<CSoundEvent> FUN_14177b3d0(FMOD::EventGroup* pGroup, const char* pszName, float fPitch,
                                      FMOD_EVENT_PITCHUNITS eUnits);   // an event of the group with pitch
    MS2Ptr<CSoundEvent> FUN_14177b6a0(const char* pszName);     // the event by full name
    FMOD::EventGroup* FUN_14177d6e0(const char* pszName, int bLoad);   // the (cached) event group
    void FUN_14177dbe0(int nCategory, unsigned nMute);          // mute a category

public:
    MS2_LAYOUT_FRIEND;
    FMOD::EventSystem* m_pEventSystem;  // +0x08
    char m_pad_10[0x8c - 0x10];
    int m_bReady;                       // +0x8c
    char m_pad_90[0x120 - 0x90];
};

CSoundEventMgr* FUN_140d13c40();                                // TSingleton<CSoundEventMgr>::GetInstance

// 0x141775980 (called from effectservice.cpp): builds a param for a one-shot event.
MS2Ptr<CSoundEventEffectParam> FUN_141775980(CString strName, CString strCategory, float fVolume, CString strExtra);
