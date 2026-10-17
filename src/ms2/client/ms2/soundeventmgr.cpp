// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Sound events: the effect XML type 2 "SoundEvent" (param +
// runtime effect), the FMOD event wrapper CSoundEvent and the event manager CSoundEventMgr. See soundeventmgr.h.
// MS2-UNIT: client\ms2\soundeventmgr.cpp
// MS2-RANGE: 0x140101560-0x140101680 .text$di
// MS2-RANGE: 0x141775810-0x14178fd20 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\soundeventmgr.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "soundeventmgr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/soundservice.h"
#include <new>
#include <efd/MemoryDefines.h>
#include <NiNode.h>
#include <NiFixedString.h>
#include <NiTransform.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
int FUN_140873ad0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);      // string attribute
class Unk_GameClock { public: double FUN_141473280(); float FUN_141473210(); };
Unk_GameClock* FUN_14086d260();
CLogString* FUN_140166440();                                        // the logger
WorldService* FUN_1403ed2d0();
void FUN_1401d3700(CString& str);
int FUN_140718170(const CString& str);                              // parses an int
float FUN_140718450(const CString& str);                            // parses a float
void FUN_14015eb90(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);
CString FUN_1411a8ae0(int n);                                       // int to string
CSoundService* FUN_140c9cb10();                                     // the sound service                                   // normalises a sound path
// The application object: the sound switch byte and the session.
class Unk_SmSession { public: int FUN_141260470(); };
class Unk_SmApp
{
public:
    char* FUN_140d13c70();                                          // the sound off switch
    Unk_SmSession* FUN_1411b1f30();
};
Unk_SmApp* FUN_1409a8b10();
void* FUN_1409849b0(void* pHandle);                                 // handle -> node pointer
void* FUN_14098d8d0(const void* pRtti, void* pObj);                 // dynamic cast through an NiRTTI
const Unk_StreamPoint& FUN_140947900(void* pNode);                  // world translate
void FUN_140a0b2a0(NiAVObject* pObj);                               // detach from the parent
bool FUN_14028d470(float a, float b);                               // nearly equal
void FUN_140194470(void* pDst, const Unk_StreamPoint& vSrc);        // NiPoint3 assignment
void FUN_140a332d0(NiTransform* pXform);                            // NiTransform default constructor
NiTransform* FUN_140a33de0(const NiTransform* pThis, void* pOut, const NiTransform* pOther);   // NiTransform::operator*
void FUN_140a35bd0(NiTransform* pDst, const NiTransform* pSrc);     // NiTransform assignment
void FUN_140aacb60(void* pNode, const NiTransform* pXf);            // sets the node's local transform
NiTransform* FUN_1409478e0(void* pNode);                            // the node's world transform
// Effect manager (singleton 0x1403ed280): scene root.
class Unk_SmEffectMgr { public: NiNode* FUN_1411a6b10(); };
Unk_SmEffectMgr* FUN_1403ed280();
// Sound property / voice pitch table.
// The 2-int pitch record (pitch, FMOD pitch units) of a voice event.
struct Unk_SoundPitch
{
    Unk_SoundPitch() : m_fPitch(0.0f), m_nUnits(FMOD_EVENT_PITCHUNITS_RAW) {}   // 0x1417781e0
    float m_fPitch;
    FMOD_EVENT_PITCHUNITS m_nUnits;
};
MS2_CHECK_SIZE(Unk_SoundPitch, 8);
class Unk_SmVoiceTable { public: void FUN_141793340(int nObjectId, Unk_SoundPitch* pPitchOut); };
Unk_SmVoiceTable* FUN_1411b1de0();
// Cooltime table of the local player.
class Unk_SmCooltimes { public: bool FUN_140a40ca0(unsigned nId); };
Unk_SmCooltimes* FUN_1411b1dc0();
// The unit's log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0): one COMDAT per argument list.
// @0x1417775f0
template <class A> inline void Unk_SoundLog(CLogString* log, int level, int category, const wchar_t* format, const A& a)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a), args));
}
template <class A, class B> inline void Unk_SoundLog(CLogString* log, int level, int category, const wchar_t* format,
                                                      const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b), args));
}
template <class A, class B, class C> inline void Unk_SoundLog(CLogString* log, int level, int category,
                                                               const wchar_t* format, const A& a, const B& b, const C& c)
{
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b),
                                                   fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(c)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(a, b, c), args));
}

#ifndef MS2_HOOK_DLL
// File statics of this TU (initialised by the .text$di entries).
const NiRTTI CSoundEventEffect::ms_RTTI("CSoundEventEffect", &CEffect::ms_RTTI);    // @0x140101560
static CString s_str143aea238("skill");                                              // @0x140101590
static CString s_str143aea230("stun");                                               // @0x1401015c0
static CString s_str143aea258("skill");                                              // @0x1401015f0
static CString s_str143aea250("stun");                                               // @0x140101620
#else
const NiRTTI CSoundEventEffect::ms_RTTI("CSoundEventEffect", &CEffect::ms_RTTI);
#endif

// @0x141775810
CSoundEventEffectParam::CSoundEventEffectParam()
    : CEffectParam(2), m_bAttachToNode(false), m_bApplyNodeTransform(false), m_bDoNotStop(false), m_fVolume(1.0f),
      m_fViewDistance(0.0f), m_strExtra(""), m_bByJob(false), m_bSkipMusicConcert(false), m_nCooltimeId(0)
{
}

// @0x141775980
MS2Ptr<CSoundEventEffectParam> FUN_141775980(CString strName, CString strCategory, float fVolume, CString strExtra)
{
    MS2Ptr<CSoundEventEffectParam> spParam(new CSoundEventEffectParam);
    spParam->m_strEvent = strName;
    spParam->m_strGroup = strCategory;
    spParam->m_fVolume = fVolume;
    spParam->m_strExtra = strExtra;
    spParam->m_str20 = "SoundEvent";
    return spParam;
}

// @0x141775af0
void CSoundEventEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "event", m_strEvent);
    FUN_1408733e0(pNode, "group", m_strGroup);
    if (!m_strGroup.IsEmpty())
        FUN_1401d3700(m_strGroup);
    FUN_1408730a0(pNode, "byJob", m_bByJob);
    FUN_1408730a0(pNode, "isSkipMusicConcert", m_bSkipMusicConcert);
    if (m_bByJob)
    {
        FUN_141776330(pNode);
        FUN_1417764c0(pNode);
    }
    FUN_140873360(pNode, "forceHearDistance", m_fViewDistance);
    FUN_1408730a0(pNode, "doNotStop", m_bDoNotStop);
    FUN_140873220(pNode, "cooltimeID", m_nCooltimeId);
    Unk_140165cf0* pAttach = pNode->FUN_140165cf0("attachInfo");
    if (pAttach != 0)
    {
        FUN_1408730a0(pAttach, "attachToNode", m_bAttachToNode);
        FUN_1408730a0(pAttach, "applyNodeTransform", m_bApplyNodeTransform);
        FUN_1408733e0(pAttach, "parentNode", m_strParentNode);
    }
}

// @0x141775cb0
bool CSoundEventEffectParam::vfunc_2()
{
    if (!CEffectParam::vfunc_2())
        return false;
    if (!m_strGroup.IsEmpty())
    {
        const char* pszGroup = m_strGroup;
        FMOD::EventGroup* pGroup = FUN_140d13c40()->FUN_14177d6e0(pszGroup, 0);
        if (pGroup == 0)
        {
            Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event group을 찾을 수 없습니다[{0}] [{1}]", m_strGroup, m_str20);
            return false;
        }
        FMOD::Event* pEvent;
        if (!m_bByJob)
        {
            if (pGroup->getEvent(m_strEvent, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK)
            {
                Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event ID를 찾을 수 없습니다[{0}] [{1}] [{2}]", m_strGroup,
                             m_strEvent, m_str20);
                return false;
            }
        }
        else
        {
            for (POSITION pos = m_mapJobEvent.GetStartPosition(); pos != 0; m_mapJobEvent.GetNext(pos))
            {
                CString strEvent(m_mapJobEvent.GetValueAt(pos));
                if (pGroup->getEvent(strEvent, FMOD_EVENT_INFOONLY, &pEvent) != FMOD_OK)
                {
                    Unk_SoundLog(FUN_140166440(), 1, 0x13, L"Sound event ID를 찾을 수 없습니다[{0}] [{1}]", strEvent, m_str20);
                    return false;
                }
            }
        }
    }
    return true;
}

// @0x141775fc0
CEffectPtr CSoundEventEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) CSoundEventEffect;
}

// @0x141776060
bool CSoundEventEffectParam::vfunc_7(Unk_EffectTarget* pTarget)
{
    if (pTarget->m_b33)
        return true;
    if (CEffectParam::vfunc_7(pTarget))
        return true;
    if (m_bSkipMusicConcert && FUN_1403ed2d0()->FUN_141bcb150())
        return true;
    return false;
}

// @0x1417760d0
bool CSoundEventEffectParam::FUN_1417760d0() const
{
    if (m_nCooltimeId == 0)
        return true;
    if (FUN_1411b1dc0() == 0)
        return true;
    return FUN_1411b1dc0()->FUN_140a40ca0(m_nCooltimeId);
}

// @0x141776120
CString CSoundEventEffectParam::FUN_141776120(int nJob) const
{
    if (FUN_1409a8b10()->FUN_1411b1f30()->FUN_141260470() != 0)
        return m_strEvent;
    if (!m_bByJob)
        return m_strEvent;
    if (nJob == 0)
        return m_strEvent;
    CString strEvent;
    int nKey = nJob;
    m_mapJobEvent.Lookup(nKey, strEvent);
    return strEvent;
}

// @0x1417762a0
float CSoundEventEffectParam::FUN_1417762a0(int nJob) const
{
    float fDelay;
    if (!m_bByJob)
    {
        fDelay = m_fStartDelay;
    }
    else if (nJob == 0)
    {
        fDelay = m_fStartDelay;
    }
    else
    {
        fDelay = 0;
        int nKey = nJob;
        if (!m_mapJobDelay.Lookup(nKey, fDelay))
            fDelay = m_fStartDelay;
    }
    return fDelay;
}

// @0x141776330
// "jobEvent" = "job:event;job:event"
void CSoundEventEffectParam::FUN_141776330(Unk_140165cf0* pNode)
{
    CString strList;
    FUN_140873ad0(pNode, "jobEvent", strList);
    ATL::CAtlArray<CString> arrList;
    FUN_14015f050(strList, arrList, ";");
    for (unsigned i = 0; i < arrList.GetCount(); i++)
    {
        CString strItem(arrList[i]);
        ATL::CAtlArray<CString> arrPair;
        FUN_14015f050(strItem, arrPair, ":");
        if (arrPair.GetCount() == 2)
        {
            int nJob = atoi(arrPair[0]);
            m_mapJobEvent.SetAt(nJob, arrPair[1]);
        }
    }
}

// @0x1417764c0
// "byJobStartDelay" = "job:delay;job:delay"
void CSoundEventEffectParam::FUN_1417764c0(Unk_140165cf0* pNode)
{
    CString strList;
    FUN_140873ad0(pNode, "byJobStartDelay", strList);
    ATL::CAtlArray<CString> arrList;
    FUN_14015f050(strList, arrList, ";");
    for (unsigned i = 0; i < arrList.GetCount(); i++)
    {
        ATL::CAtlArray<CString> arrPair;
        FUN_14015f050(arrList[i], arrPair, ":");
        if (arrPair.GetCount() == 2)
        {
            int nJob = FUN_140718170(arrPair[0]);
            float fDelay = FUN_140718450(arrPair[1]);
            m_mapJobDelay.SetAt(nJob, fDelay);
        }
    }
}

// @0x141776630
CSoundEventEffect::CSoundEventEffect()
    : m_spRoot(0), m_fVolume(1.0f), m_spSound(0), m_bDoNotStop(false), m_bStopRequested(false), m_strExtra("")
{
}

// @0x1417766e0
CSoundEventEffect::~CSoundEventEffect()
{
    vfunc_7();
}

// @0x141776760
bool CSoundEventEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    if (!CEffect::vfunc_3(pParam, pTarget))
        return false;
    if (*FUN_1409a8b10()->FUN_140d13c70() != 0)
        return false;
    const CSoundEventEffectParam* pSound = static_cast<const CSoundEventEffectParam*>(pParam);
    if (!pSound->FUN_1417760d0())
        return false;

    MS2Ptr<CSoundEvent> spSound(0);
    const CString& strGroup = pSound->FUN_141776260();
    NiNode* pOwner = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI, FUN_1409849b0(&pTarget->m_spObject)));
    FMOD::EventGroup* pGroup = 0;
    if (!strGroup.IsEmpty())
    {
        pGroup = FUN_140d13c40()->FUN_14177d6e0(strGroup, 0);
        if (pGroup == 0)
            return false;
    }
    if (pSound->m_bOnlyCasterMyPC && m_unk_18 != 1)
        return false;

    int nJob = pTarget->FUN_140a53050();
    CString strEvent = pSound->FUN_141776120(nJob);
    if (pGroup == 0)
    {
        if (!strEvent.IsEmpty())
            spSound = FUN_140d13c40()->FUN_14177b6a0(strEvent);
    }
    else if (!strEvent.IsEmpty())
    {
        Unk_SoundPitch kPitch;
        if (pTarget->FUN_140a53090() != 0 && strGroup.Find("ms2sound/sound/voice", 0) != -1)
            FUN_1411b1de0()->FUN_141793340(pTarget->FUN_140a53090(), &kPitch);
        spSound = FUN_140d13c40()->FUN_14177b3d0(pGroup, strEvent, kPitch.m_fPitch, kPitch.m_nUnits);
    }
    if (spSound == (CSoundEvent*)0)
        return false;

    m_dStartTime = FUN_14086d260()->FUN_141473280() + (double)pSound->FUN_1417762a0(pTarget->FUN_140a53050());
    m_dStopTime = m_dStartTime + 10.0;
    m_spSound = spSound;
    m_b2c = false;
    m_bDoNotStop = pSound->m_bDoNotStop;
    m_strExtra = pSound->m_strExtra;

    NiNode* pRootNode = new (efd::MemHint(efd::MemHint::NONE)) NiNode(0);
    Unk_NodePtr spRoot(pRootNode);
    pRootNode->SetName("Effect Root");
    m_spRoot = spRoot;

    NiTransform kXform;
    FUN_140a332d0(&kXform);
    kXform.MakeIdentity();
    NiTransform kTemp;
    if (pTarget->m_pXform != 0)
        FUN_140a35bd0(&kXform, FUN_140a33de0(pTarget->m_pXform, &kTemp, &kXform));
    if (pTarget->m_unk_20 != 0)
        FUN_140a35bd0(&kXform, FUN_140a33de0(&kXform, &kTemp, (NiTransform*)pTarget->m_unk_20));

    NiNode* pParent = 0;
    if (!pSound->m_bAttachToNode)
    {
        pParent = FUN_1403ed280()->FUN_1411a6b10();
        if (!pSound->m_bApplyNodeTransform)
        {
            FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
        }
        else
        {
            if (pOwner == 0)
            {
                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - applyNodeTransform = true 인데, RootNode가 NULL입니다.[{0}]", strEvent);
                return false;
            }
            NiNode* pNode = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI,
                pOwner->GetObjectByName(NiFixedString((const char*)pSound->FUN_141776280()))));
            if (pNode == 0)
            {
                FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
            }
            else
            {
                FUN_140aacb60(FUN_1409475f0(&spRoot), FUN_140a33de0(FUN_1409478e0(pNode), &kTemp, &kXform));
            }
        }
    }
    else
    {
        if (pOwner == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - attachToNode = true 인데, RootNode가 NULL입니다.[{0}]", strEvent);
            return false;
        }
        pParent = static_cast<NiNode*>(FUN_14098d8d0(&NiNode::ms_RTTI,
            pOwner->GetObjectByName(NiFixedString((const char*)pSound->FUN_141776280()))));
        if (pParent == 0)
            pParent = pOwner;
        if (!pSound->m_bApplyNodeTransform && pParent != 0)
        {
            NiTransform kInverse;
            FUN_140a332d0(&kInverse);
            FUN_1409478e0(pParent)->Invert(kInverse);
            FUN_140aacb60(FUN_1409475f0(&spRoot), FUN_140a33de0(&kInverse, &kTemp, &kXform));
        }
        else
        {
            FUN_140aacb60(FUN_1409475f0(&spRoot), &kXform);
        }
    }
    if (pParent != 0)
    {
        pParent->AttachChild(static_cast<NiAVObject*>(FUN_1409475d0(&m_spRoot)), true);
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateEffects();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->UpdateProperties();
        static_cast<NiAVObject*>(FUN_1409475f0(&m_spRoot))->Update((float)FUN_14086d260()->FUN_141473280(), true);
    }
    m_fVolume = pSound->m_fVolume;
    m_spSound->FUN_14177abc0(FUN_1417775b0, this);
    if (FUN_14028d470(pSound->FUN_1417762a0(pTarget->FUN_140a53050()), 0.0f))
        vfunc_4();
    return true;
}

// @0x1417771a0
bool CSoundEventEffect::vfunc_9()
{
    if (!m_b2d)
    {
        double dNow = FUN_14086d260()->FUN_141473280();
        if (!FUN_14119f3c0() && m_dStartTime <= dNow)
            vfunc_4();
        if (FUN_14119f3c0() && m_spSound.get() != 0)
            m_spSound->FUN_14177a990(FUN_140947900(FUN_1409475f0(&m_spRoot)));
        if (m_bStopRequested && m_dStopTime <= dNow)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"sound event - doNotStop이 True 이며, Stop 메시지 이후 10초 경과[{0}]",
                          m_spSound->FUN_14177aca0());
            m_bDoNotStop = false;
            vfunc_5();
        }
    }
    return !m_b2d;
}

// @0x141777370
void CSoundEventEffect::vfunc_4()
{
    if (m_spSound.get() != 0)
    {
        if (FUN_140166440() != 0)
            Unk_SoundLog(FUN_140166440(), 0xc, 0x12f, L"Start SoundID {0} volume {1} {2}", m_spSound->FUN_14177aca0(),
                         m_fVolume, FUN_1411a8ae0(m_unk_18));
        m_spSound->FUN_14177a990(FUN_140947900(FUN_1409475f0(&m_spRoot)));
        m_spSound->FUN_14177acf0(m_fVolume);
        if (!m_spSound->FUN_14177a8d0())
            m_b2d = true;
    }
    m_b2e = true;
}

// @0x141777520
void CSoundEventEffect::vfunc_5()
{
    if (!m_bDoNotStop)
    {
        if (m_spSound.get() != 0)
            m_spSound->FUN_14177a920(0);
        m_b2d = true;
    }
    else
    {
        m_bStopRequested = true;
        m_dStopTime = FUN_14086d260()->FUN_141473280() + 10.0;
    }
}

// @0x1417775b0
// FMOD event callback: 4 = event finished, 6 = sound def created.
FMOD_RESULT F_CALLBACK FUN_1417775b0(FMOD_EVENT* pEvent, FMOD_EVENT_CALLBACKTYPE eType, void* pParam1, void* pParam2,
                                     void* pUserData)
{
    CSoundEventEffect* pEffect = static_cast<CSoundEventEffect*>(pUserData);
    if (eType == FMOD_EVENT_CALLBACKTYPE_EVENTFINISHED)
    {
        if (pEffect != 0)
            pEffect->FUN_141777770();
    }
    else if (eType == FMOD_EVENT_CALLBACKTYPE_SOUNDDEF_CREATE && pEffect != 0)
    {
        FUN_140c9cb10()->FUN_1417b0560(pEffect->FUN_141777700(), (FMOD::Sound**)pParam2);
    }
    return FMOD_OK;
}

// @0x141777670
void CSoundEventEffect::vfunc_7()
{
    m_b2e = false;
    FUN_140a0b2a0((NiAVObject*)FUN_1409475d0(&m_spRoot));
}

// @0x1417776b0
int CSoundEventEffect::vfunc_8(void* p)
{
    FUN_140194470(p, FUN_140947900(FUN_1409475f0(&m_spRoot)));
    return 1;
}

// @0x141777720
MS2Ptr<CSoundEvent> CSoundEventEffect::FUN_141777720()
{
    return m_spSound;
}

// @0x141778980
int CSoundEventEffect::vfunc_12()
{
    return 2;
}

// ---- CSoundEvent ----
// NiPoint3 built from coordinates / from an efd::Point3 (out-of-line copies 0x14097f250 / 0x14027dcf0).
struct Unk_SmPoint3 : public Unk_StreamPoint
{
    Unk_SmPoint3(float fX, float fY, float fZ);                     // 0x14097f250
    Unk_SmPoint3(const Unk_StreamPoint& pt);                        // 0x14027dcf0
};
// @0x14177a590
CSoundEvent::CSoundEvent(FMOD::Event* pEvent, CString strName)
    : m_pRange(0), m_pEvent(pEvent), m_nStarted(0), m_nStopped(0), m_strName(strName)
{
    float fMin;
    float fMax;
    if (m_pEvent->getProperty("3DMinDistance", &fMin, true) == FMOD_OK)
    {
        if (m_pEvent->getProperty("3DMaxDistance", &fMax, true) == FMOD_OK)
        {
            CTwoCircleCollision* pRange = new CTwoCircleCollision;
            pRange->FUN_1416c4b60(fMin);
            pRange->FUN_1416c4bf0(fMax);
            m_pRange = pRange;
        }
    }
    else
    {
        FMOD::EventGroup* pGroup;
        if (m_pEvent->getParentGroup(&pGroup) == FMOD_OK && pGroup->getProperty("3DMinDistance", &fMin) == FMOD_OK &&
            pGroup->getProperty("3DMaxDistance", &fMax) == FMOD_OK)
        {
            CTwoCircleCollision* pRange = new CTwoCircleCollision;
            pRange->FUN_1416c4b60(fMin);
            pRange->FUN_1416c4bf0(fMax);
            m_pRange = pRange;
        }
    }
}

// @0x14177a800
CSoundEvent::~CSoundEvent()
{
    m_pEvent->stop(true);
    m_pEvent->release(true, true);
    m_pEvent = 0;
    if (m_pRange != 0)
        delete m_pRange;
}

// @0x14177a8d0
bool CSoundEvent::FUN_14177a8d0()
{
    m_nStarted = 1;
    return m_pEvent->start() == FMOD_OK;
}

// @0x14177a920
void CSoundEvent::FUN_14177a920(int bFadeOut)
{
    if (bFadeOut == 0)
    {
        m_nStopped = 1;
        if (FUN_14177ab80())
            m_pEvent->stop(true);
    }
    else
    {
        m_nStarted = 0;
        m_nStopped = 0;
    }
}

// @0x14177a990
void CSoundEvent::FUN_14177a990(const Unk_StreamPoint& vPos)
{
    FMOD_VECTOR kPos = {vPos.x, vPos.z, vPos.y};
    m_pEvent->set3DAttributes(&kPos, 0, 0);
    if (m_pRange != 0)
        m_pRange->vfunc_3(Unk_SmPoint3(vPos), Unk_SmPoint3(0.0f, 0.0f, 0.0f), 1.0f);
}

// @0x14177aac0
void CSoundEvent::FUN_14177aac0(const Unk_StreamPoint& vPos, const Unk_StreamPoint& vVel)
{
    FMOD_VECTOR kPos = {vPos.x, vPos.z, vPos.y};
    FMOD_VECTOR kVel = {vVel.x, vVel.z, vVel.y};
    m_pEvent->set3DAttributes(&kPos, &kVel, 0);
}

// @0x14177ab80
int CSoundEvent::FUN_14177ab80()
{
    FMOD_EVENT_STATE nState = 0;
    m_pEvent->getState(&nState);
    return nState & FMOD_EVENT_STATE_PLAYING;
}

// @0x14177abc0
void CSoundEvent::FUN_14177abc0(FMOD_EVENT_CALLBACK pfnCallback, void* pUserData)
{
    m_pEvent->setCallback(pfnCallback, pUserData);
}

// @0x14177ac00
bool CSoundEvent::FUN_14177ac00()
{
    bool bMute;
    return m_pEvent->getMute(&bMute) == FMOD_OK;
}

// @0x14177ac50
void CSoundEvent::FUN_14177ac50(bool bMute)
{
    m_pEvent->setMute(bMute);
}

// @0x14177ac80
int CSoundEvent::FUN_14177ac80()
{
    return m_nStarted | m_nStopped;
}

// @0x14177aca0
CString CSoundEvent::FUN_14177aca0()
{
    return m_strName;
}

// @0x14177acf0
void CSoundEvent::FUN_14177acf0(float fVolume)
{
    m_pEvent->setVolume(fVolume);
}
