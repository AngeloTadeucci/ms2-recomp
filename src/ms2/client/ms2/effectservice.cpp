// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The effect system: the runtime effect / param bases
// (effectparam.h), the effect param factory and the effect file cache (effectservice.h).
// The exe range holds two CUs (two copies of the header_statics_a.h initializers, .text$di 0x1400e7870.. and
// 0x1400e7a00..): CEffect/CEffectParam/CEffectData/EffectDataManager up to 0x1411a32c0, then EffectNode and
// CEffectService. Only the first part is recovered so far. The first CU's own assert names
// client\ms2\effectdatamanager.cpp (FUN_1411a0f80), so it is probably effectdatamanager.cpp.
// MS2-UNIT: client\ms2\effectservice.cpp
// MS2-RANGE: 0x1400e7870-0x1400e7d30 .text$di
// MS2-RANGE: 0x14119e920-0x1411b8510 .text$mn
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400e7890
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e7950
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e7980
// MS2-PIN: ??__Es_unk1402a9d70@@YAXXZ 0x1400e79b0
// MS2-PIN: ??8?$SmartPointer@VCEffect@@@efd@@QEBA_NPEAVCEffect@@@Z 0x14119f440
// MS2-PIN: ??C?$SmartPointer@VCEffect@@@efd@@QEBAPEAVCEffect@@XZ 0x14119f480
// MS2-PIN: ?GetInstance@?$TSingleton@VEffectSkipMgr@@@@SAPEAVEffectSkipMgr@@XZ 0x14119f490
// MS2-PIN: ?GetRTTI@CEffect@@UEBAPEBVNiRTTI@@XZ 0x14119f4a0
// MS2-PIN: ?GetAt@?$CAtlList@V?$MS2Ptr@VCEffectParam@@@@V?$CElementTraits@V?$MS2Ptr@VCEffectParam@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCEffectParam@@@@PEAU__POSITION@@@Z 0x1411a2130
// MS2-PIN: ?GetNext@?$CAtlList@V?$MS2Ptr@VCEffectParam@@@@V?$CElementTraits@V?$MS2Ptr@VCEffectParam@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCEffectParam@@@@AEAPEAU__POSITION@@@Z 0x1411a2280
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "effectservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/client/ms2/effectskipmgr.h"
#include "ms2/client/ms2/gameobject.h"
#include <NiAVObject.h>
#include <NiTransform.h>
#include <efd/ClassInfo.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The concrete params the factory creates (own units).
#include "nifeffectparam.h"
#include "monochromeeffectparam.h"
#include "radialblureffectparam.h"
#include "weathereffectparam.h"
#include "swoosheffectparam.h"
#include "statuseffectparam.h"
#include "lighteffectparam.h"
#include "fogeffectparam.h"
#include "randomeffectparam.h"
#include "vibrateeffectparam.h"
#include "chaoslighteffect.h"
#include "textureoverrideeffectparam.h"
#include "lightningeffectparam.h"
#include "cameramoveeffectparam.h"
#include "screenmaskingeffectparam.h"
#include "gaussianblureffectparam.h"
#include "postprocessing/postshimmerrenderstep.h"
#include "beameffectparam.h"
#include "afterimageeffectparam.h"

#include "ms2/placeholder/header_statics_a.h"

// Params whose units are not recovered yet: only the constructor and the size are known here.
class CSoundEventEffectParam : public CEffectParam      // ?\soundeventeffectparam.cpp, vftable 0x142f64130
{
public:
    CSoundEventEffectParam();                           // 0x141775810
    char m_unk_48[8];
    float m_fViewDistance;                              // +0x50 skip distance for kinds 5/6 (0 = use the table)
    char m_unk_54[0x110 - 0x54];
};
MS2_CHECK_SIZE(CSoundEventEffectParam, 0x110);
MS2_CHECK_OFFSET(CSoundEventEffectParam, m_fViewDistance, 0x50);

class CSoundMusicEffectParam : public CEffectParam      // ?\soundmusiceffectparam.cpp, vftable 0x142f67b50
{
public:
    CSoundMusicEffectParam();                           // 0x14178fd20
    char m_unk_48[0x68 - 0x48];
};
MS2_CHECK_SIZE(CSoundMusicEffectParam, 0x68);

class CRibbonEffectParam : public CEffectParam          // ?\ribboneffectparam.cpp, vftable 0x142f5b228
{
public:
    CRibbonEffectParam();                               // 0x141701380
    char m_unk_48[0x68 - 0x48];
};
MS2_CHECK_SIZE(CRibbonEffectParam, 0x68);

// Game TinyXML element: FirstChildElement / NextSiblingElement by name.
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);
    Unk_140165cf0* FUN_140168650(const char* pszName);
};

// TinyXML attribute helpers (commonfiles\tinyxmlhelper.cpp).
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_140873220(Unk_140165cf0* pNode, const char* pszName, int& nOut);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);

// String / path helpers (commonfiles).
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);  // path combine
void FUN_1401d3700(CString& strPath);                                   // normalize (lower case)

bool FUN_14028d470(float a, float b);                   // nearly equal

// Game log (commonfiles singleton 0x140166440).
void* FUN_140166440();
void FUN_14015eb90(void* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& strArg);

// Game clock (commonfiles singleton 0x14086d260, mainsystem.cpp 0x141473280: current time in seconds).
class Unk_EsClock
{
public:
    double FUN_141473280();
    double FUN_141473260();                         // elapsed seconds
};
Unk_EsClock* FUN_14086d260();

// World service (singleton 0x1403ed2d0): the local player.
class Unk_EsWorld
{
public:
    GameObject* FUN_141bd0cc0();
    GameObject* FUN_141bd0fa0(egf::EntityID id);                // the object of an entity
    void FUN_141bbae40(IWorldServiceCallback* pCallback);       // add a map callback
};
Unk_EsWorld* FUN_1403ed2d0();
NiAVObject* FUN_141b6ef70(egf::EntityID id);            // scene node of an entity

extern int DAT_1439ed00c;                               // effect cache enabled (reload when the file changed)

// ---------------------------------------------------------------------------------------------------------------
// CEffectParam

// @0x14119e920
bool CEffectParam::vfunc_3()
{
    return true;
}

// @0x14119e930
void CEffectParam::vfunc_4()
{
}

// @0x14119e940
bool CEffectParam::vfunc_7(Unk_EffectTarget* p)
{
    if (!m_bIgnoreOptimize && p->FUN_140a53110())
        return true;
    if (m_nGender != 2 && m_nGender != p->FUN_140a53010())
        return true;
    if (m_nJobCode != 0 && m_nJobCode != p->FUN_140a53050())
        return true;
    if (m_bOnlyCasterMyPC && p->m_nKind != 1)
        return true;
    if (m_bOnlyTargetMyPC && !p->FUN_140a530d0())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x14119e940, CEffectParam, vfunc_7, 190, 0x83F8550E);

// ---------------------------------------------------------------------------------------------------------------
// CEffect

NiImplementRootRTTI(CEffect);   // .text$di 0x1400e7870

// @0x14119ea10
CEffect::CEffect()
{
    m_unk_18 = 0;
    m_dStartTime = 0;
    m_fDuration = 0;
    m_b2c = false;
    m_b2d = false;
    m_b2e = false;
    m_b2f = true;
}

// @0x14119eaa0
CEffect::~CEffect()
{
}

// @0x14119eae0
// MS2-FUNCTIONAL: the exe spills the world object pointer before the entity id return buffer (one extra 8-byte temp, frame 0x10 larger); not reproduced
CEffectPtr FUN_14119eae0(CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    pTarget->FUN_140a534a0();
    if (pParam->vfunc_7(pTarget))
        return 0;
    Unk_SkipCheck kCheck;
    kCheck.m_nRow = pParam->m_nType;
    kCheck.m_nCaster = pTarget->m_nKind;
    kCheck.m_n14 = pTarget->m_b30;
    kCheck.m_fViewDistance = -1.0f;
    switch (pParam->m_nType)
    {
    case kEffectNif:
        kCheck.m_fViewDistance = static_cast<CNifEffectParam*>(pParam)->m_fViewDistance;
        break;
    case kEffectSoundEvent:
    {
        float fDistance = static_cast<CSoundEventEffectParam*>(pParam)->m_fViewDistance;
        if (!FUN_14028d470(fDistance, 0) && (pTarget->m_nKind == 5 || pTarget->m_nKind == 6))
            kCheck.m_fViewDistance = fDistance;
        GameObject* pOwner = pTarget->FUN_140a533b0();
        if (efd::ClassInfo::IsKindOf(pOwner ? pOwner->GetClassDesc() : NULL, 0x6200044))
            pTarget->m_spObject = FUN_141b6ef70(FUN_1403ed2d0()->FUN_141bd0cc0()->FUN_14123c460());
        break;
    }
    }
    // Unk_SkipPoint is effectskipmgr's view of the NiPoint3 it is copied from.
    if (pTarget->m_spObject)
        kCheck.m_pos = reinterpret_cast<const Unk_SkipPoint&>(pTarget->m_spObject->GetTranslate());
    else if (pTarget->m_pXform)
        kCheck.m_pos = reinterpret_cast<const Unk_SkipPoint&>(pTarget->m_pXform->m_Translate);
    switch (pParam->m_nType)
    {
    case kEffectSoundEvent:
    case kEffectMonochrome:
    case kEffectRadialBlur:
    case kEffectVibrate:
    case kEffectCameraMove:
    case kEffectScreenMasking:
    case kEffectGaussianBlur:
    case kEffectPostShimmer:
        if (!pParam->m_bOffSkip && TSingleton<EffectSkipMgr>::GetInstance()->IsOutOfView(&kCheck))
            return 0;
    }
    CEffectPtr spEffect = pParam->vfunc_6();
    if (spEffect == 0)
        return 0;
    if (!spEffect->vfunc_3(pParam, pTarget))
        return 0;
    NiPoint3 kPos;
    if (spEffect->vfunc_8(&kPos) != 0)
    {
        kCheck.m_pos = reinterpret_cast<const Unk_SkipPoint&>(kPos);
        if (!pParam->m_bOffSkip && TSingleton<EffectSkipMgr>::GetInstance()->IsOutOfView(&kCheck))
        {
            spEffect->vfunc_7();
            return 0;
        }
    }
    if (spEffect->FUN_14119f400() && spEffect->IsLoop())
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x133,
            L"Loop가 걸린 이펙트의 경우 명시적으로 해당 이펙트를 비활성화 시켜주어야 합니다[{0}]", spEffect->GetName());
        return 0;
    }
    return spEffect;
}
MS2_REPLACE(0x14119eae0, FUN_14119eae0, 1452, 0x3B421B55);

// @0x14119f0b0
bool CEffect::vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget)
{
    m_unk_18 = pTarget->m_nKind;
    m_b2f = pTarget->m_b34;
    double dStart = pTarget->FUN_140a53420();
    if (dStart == 0.0)
        dStart = FUN_14086d260()->FUN_141473280();
    m_dStartTime = dStart + pParam->m_fStartDelay;
    m_fDuration = pParam->m_fDuration;
    m_b2c = pParam->m_b30;
    m_str10 = pParam->m_str20;
    return true;
}
MS2_REPLACE_METHOD(0x14119f0b0, CEffect, vfunc_3, 207, 0xBC10ED60);

// @0x14119f190
void CEffect::vfunc_4()
{
    m_b2e = true;
    m_b2d = false;
}

// @0x14119f1b0
void CEffect::vfunc_5()
{
    m_b2d = true;
}

// @0x14119f1d0
void CEffect::vfunc_6(float f)
{
    vfunc_5();
}

// @0x14119f200
void CEffect::vfunc_7()
{
    m_b2e = false;
}

// @0x14119f220
int CEffect::vfunc_8(void* p)
{
    return 0;
}

// @0x14119f240
bool CEffect::vfunc_9()
{
    if (m_b2d)
        return false;
    double dNow = FUN_14086d260()->FUN_141473280();
    if (!FUN_14119f3c0() && m_dStartTime <= dNow)
        vfunc_4();
    bool bAlive;
    if (dNow > m_dStartTime + m_fDuration)
        bAlive = m_b2c;
    else
        bAlive = true;
    return bAlive;
}
MS2_REPLACE_METHOD(0x14119f240, CEffect, vfunc_9, 168, 0x62DB4484);

// @0x14119f2f0
void CEffect::vfunc_10(bool b)
{
}

// @0x14119f300
int CEffect::vfunc_11()
{
    if (m_b2c)
        return 0;
    return 1;
}

// @0x14119f330
CString CEffect::GetName() const
{
    return m_str10;
}

// @0x14119f380
float CEffect::GetDuration() const
{
    return m_fDuration;
}

// @0x14119f3a0
double CEffect::GetStartTime() const
{
    return m_dStartTime;
}

// @0x14119f3c0
bool CEffect::FUN_14119f3c0() const
{
    return m_b2e;
}

// @0x14119f3e0
bool CEffect::IsLoop() const
{
    return m_b2c;
}

// @0x14119f400
bool CEffect::FUN_14119f400() const
{
    return m_b2f;
}

// ---------------------------------------------------------------------------------------------------------------
// CEffectData

// @0x14119f4b0
CEffectData::CEffectData()
    : m_params(10)
{
}

// @0x14119f500
CEffectData::~CEffectData()
{
}

// @0x14119f540
ATL::CAtlList<CEffectParamPtr>& CEffectData::FUN_14119f540()
{
    return m_params;
}

// @0x14119f560
void CEffectData::FUN_14119f560(CEffectParam* pParam)
{
    CEffectParamPtr spParam(pParam);
    m_params.AddTail(spParam);
}

// @0x14119f5c0
bool CEffectData::FUN_14119f5c0()
{
    return m_params.IsEmpty();
}

// @0x14119f5f0
bool CEffectData::FUN_14119f5f0()
{
    for (POSITION pos = m_params.GetHeadPosition(); pos != 0; m_params.GetNext(pos))
    {
        CEffectParam* pParam = m_params.GetAt(pos).get();
        if (pParam != 0 && pParam->m_bIgnoreOptimize)
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14119f5f0, CEffectData, FUN_14119f5f0, 132, 0xF758D01F);

// @0x14119f680
bool CEffectData::FUN_14119f680()
{
    for (POSITION pos = m_params.GetHeadPosition(); pos != 0; m_params.GetNext(pos))
    {
        CEffectParam* pParam = m_params.GetAt(pos).get();
        if (!pParam->vfunc_3())
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14119f680, CEffectData, FUN_14119f680, 134, 0x915D2990);

// @0x14119f710
void CEffectData::FUN_14119f710()
{
    for (POSITION pos = m_params.GetHeadPosition(); pos != 0; m_params.GetNext(pos))
    {
        CEffectParam* pParam = m_params.GetAt(pos).get();
        if (!pParam->vfunc_3())
            pParam->vfunc_4();
    }
}
MS2_REPLACE_METHOD(0x14119f710, CEffectData, FUN_14119f710, 144, 0xB9EA62CB);

// ---------------------------------------------------------------------------------------------------------------
// EffectDataManager

// @0x14119f7b0
EffectDataManager::EffectDataManager()
    : m_map(10)
{
}

// @0x14119f820
EffectDataManager::~EffectDataManager()
{
}

// @0x14119f870
CEffectDataPtr EffectDataManager::FUN_14119f870(CString strPath)
{
    CEffectDataPtr spData;
    FUN_1401d3700(strPath);
    strPath.Replace("\\", "/");
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (DAT_1439ed00c != 0 && m_map.Lookup(strPath, spData))
        {
            if (!FUN_1401d1320(spData.operator->()))
                return spData;
        }
        spData = FUN_14119fc50(strPath);
        if (spData.get() != 0)
            m_map.SetAt(strPath, spData);
    }
    return spData;
}
MS2_REPLACE_METHOD(0x14119f870, EffectDataManager, FUN_14119f870, 482, 0xBC6A47F9);

// @0x14119fa60
void EffectDataManager::FUN_14119fa60()
{
    ATL::CAtlArray<CString> files;
    FUN_140399100(".xml", "./Data/Xml/Effect", files, "", false);
    __int64 nPrefix = CString("./data/xml/effect/").GetLength();
    for (unsigned int i = 0; i < files.GetCount(); i++)
    {
        const char* pszFile = files[i];
        FUN_14119f870(CString(pszFile + nPrefix));
    }
}
MS2_REPLACE_METHOD(0x14119fa60, EffectDataManager, FUN_14119fa60, 489, 0x37B27AE7);

// @0x14119fc50
CEffectDataPtr EffectDataManager::FUN_14119fc50(const CString& strPath)
{
    CString strFile;
    strFile = FUN_14071a5b0("Effect", strPath);
    strFile.TrimLeft();
    strFile.TrimRight();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strFile, 0, true, false) == 0)
    {
        FUN_14015eb90(FUN_140166440(), 2, 0x13, L"파일을 읽을 수 없습니다 CEffectDataMgr[{0}]", strFile);
        return CEffectDataPtr(0);
    }
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strFile);
        return CEffectDataPtr(0);
    }
    CEffectDataPtr spData(new CEffectData());
    spData->FUN_1401d1160(strFile);
    Unk_140165cf0* pNode = pRoot->FUN_140165cf0("effect");
    if (pNode == 0)
        return CEffectDataPtr(0);
    for (; pNode != 0; pNode = pNode->FUN_140168650("effect"))
    {
        CEffectParamPtr spParam = FUN_1411a04e0(strPath, pNode);
        if (spParam == 0)
        {
            FUN_14015eb90(FUN_140166440(), 1, 0x133, L"Effect Fail CreateParam:{0}", strFile);
            return CEffectDataPtr(0);
        }
        spData->FUN_14119f560(spParam.get());
    }
    return spData->FUN_14119f5c0() ? CEffectDataPtr(0) : spData;
}
MS2_REPLACE_METHOD(0x14119fc50, EffectDataManager, FUN_14119fc50, 1389, 0x6E663D40);

// ---------------------------------------------------------------------------------------------------------------
// CEffectParam (load) and the factory

// @0x1411a01d0
CEffectParam::CEffectParam(int nType)
    : m_nType(nType)
{
    m_fStartDelay = 0;
    m_fDuration = 0;
    m_b30 = false;
    m_bOffSkip = false;
    m_bOnlyCasterMyPC = false;
    m_bOnlyTargetMyPC = false;
    m_nLodSkipLevel = 0;
    m_nGender = 2;
    m_nJobCode = 0;
    m_bIgnoreOptimize = false;
}

// @0x1411a0290
void CEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    FUN_140873360(pNode, "startDelay", m_fStartDelay);
    FUN_140873360(pNode, "duration", m_fDuration);
    FUN_1408731e0(pNode, "lodSkipLevel", m_nLodSkipLevel);
    FUN_1408730a0(pNode, "loop", m_b30);
    FUN_1408731e0(pNode, "gender", m_nGender);
    FUN_140873220(pNode, "jobCode", m_nJobCode);
    FUN_1408730a0(pNode, "offSkip", m_bOffSkip);
    FUN_1408730a0(pNode, "onlyCasterMyPC", m_bOnlyCasterMyPC);
    FUN_1408730a0(pNode, "onlyTargetMyPC", m_bOnlyTargetMyPC);
    FUN_1408730a0(pNode, "ignoreOptimize", m_bIgnoreOptimize);
}
MS2_REPLACE_METHOD(0x1411a0290, CEffectParam, vfunc_1, 309, 0x17F2709B);

// @0x1411a03d0
bool CEffectParam::vfunc_2()
{
    if (!m_b30 && FUN_14028d470(m_fDuration, 0))
    {
        switch (m_nType)
        {
        case kEffectMonochrome:
        case kEffectSwoosh:
        case kEffectStatus:
        case kEffectLight:
        case kEffectFog:
        case kEffectVibrate:
        case kEffectTextureOverride:
            FUN_14015eb90(FUN_140166440(), 1, 0x13, L"Loop가 False이고, Duration이 0 입니다[{0}]", m_str20);
            return false;
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x1411a03d0, CEffectParam, vfunc_2, 166, 0x0BBEBCDC);

// @0x1411a0480
bool CEffectParam::vfunc_5(int n)
{
    return true;
}

// @0x1411a04a0
CEffectPtr CEffectParam::vfunc_6()
{
    return 0;
}

// @0x1411a04e0
CEffectParamPtr FUN_1411a04e0(const CString& strName, Unk_140165cf0* pNode)
{
    int nType = 0;
    FUN_1411a16c0(pNode, "type", nType);
    CEffectParamPtr spParam;
    switch (nType)
    {
    case kEffectNif: spParam.AssignRaw(new CNifEffectParam()); break;
    case kEffectSoundEvent: spParam.AssignRaw(new CSoundEventEffectParam()); break;
    case kEffectSoundMusic: spParam.AssignRaw(new CSoundMusicEffectParam()); break;
    case kEffectMonochrome: spParam.AssignRaw(new MonochromeEffectParam()); break;
    case kEffectRadialBlur: spParam.AssignRaw(new RadialBlurEffectParam()); break;
    case kEffectWeather: spParam.AssignRaw(new WeatherEffectParam()); break;
    case kEffectSwoosh: spParam.AssignRaw(new CSwooshEffectParam()); break;
    case kEffectStatus: spParam.AssignRaw(new CStatusEffectParam()); break;
    case kEffectLight: spParam.AssignRaw(new CLightEffectParam()); break;
    case kEffectFog: spParam.AssignRaw(new CFogEffectParam()); break;
    case kEffectRandom: spParam.AssignRaw(new CRandomEffectParam()); break;
    case kEffectVibrate: spParam.AssignRaw(new CVibrateEffectParam()); break;
    case kEffectRibbon: spParam.AssignRaw(new CRibbonEffectParam()); break;
    case kEffectChaosLight: spParam.AssignRaw(new ChaosLightEffectParam()); break;
    case kEffectTextureOverride: spParam.AssignRaw(new TextureOverrideEffectParam()); break;
    case kEffectLightning: spParam.AssignRaw(new LightningEffectParam()); break;
    case kEffectCameraMove: spParam.AssignRaw(new CCameraMoveEffectParam()); break;
    case kEffectScreenMasking: spParam.AssignRaw(new ScreenMaskingEffectParam()); break;
    case kEffectGaussianBlur: spParam.AssignRaw(new GaussianBlurEffectParam()); break;
    case kEffectPostShimmer: spParam.AssignRaw(new PostShimmerEffectParam()); break;
    case kEffectBeam: spParam.AssignRaw(new CBeamEffectParam()); break;
    case kEffectAfterImage: spParam.AssignRaw(new CAfterImageEffectParam()); break;
    }
    if (spParam == 0)
        return CEffectParamPtr(0);
    spParam->m_str20 = strName;
    spParam->vfunc_1(pNode);
    if (!spParam->vfunc_2())
        return CEffectParamPtr(0);
    return spParam;
}
MS2_REPLACE(0x1411a04e0, FUN_1411a04e0, 2620, 0x309C5D75);

// @0x1411a0f80
int FUN_1411a0f80(const CString& strType)
{
    if (strType.IsEmpty())
        return kEffectNone;
    if (strType.CompareNoCase("nif") == 0)
        return kEffectNif;
    else if (strType.CompareNoCase("soundEvent") == 0)
        return kEffectSoundEvent;
    else if (strType.CompareNoCase("soundMusic") == 0)
        return kEffectSoundMusic;
    else if (strType.CompareNoCase("monochrome") == 0)
        return kEffectMonochrome;
    else if (strType.CompareNoCase("radialBlur") == 0)
        return kEffectRadialBlur;
    else if (strType.CompareNoCase("weather") == 0)
        return kEffectWeather;
    else if (strType.CompareNoCase("swoosh") == 0)
        return kEffectSwoosh;
    else if (strType.CompareNoCase("status") == 0)
        return kEffectStatus;
    else if (strType.CompareNoCase("light") == 0)
        return kEffectLight;
    else if (strType.CompareNoCase("fog") == 0)
        return kEffectFog;
    else if (strType.CompareNoCase("random") == 0)
        return kEffectRandom;
    else if (strType.CompareNoCase("vibrate") == 0)
        return kEffectVibrate;
    else if (strType.CompareNoCase("ribbon") == 0)
        return kEffectRibbon;
    else if (strType.CompareNoCase("chaoslight") == 0)
        return kEffectChaosLight;
    else if (strType.CompareNoCase("textureoverride") == 0)
        return kEffectTextureOverride;
    else if (strType.CompareNoCase("lightning") == 0)
        return kEffectLightning;
    else if (strType.CompareNoCase("cameraMove") == 0)
        return kEffectCameraMove;
    else if (strType.CompareNoCase("screenMasking") == 0)
        return kEffectScreenMasking;
    else if (strType.CompareNoCase("gaussianBlur") == 0)
        return kEffectGaussianBlur;
    else if (strType.CompareNoCase("postShimmer") == 0)
        return kEffectPostShimmer;
    else if (strType.CompareNoCase("beam") == 0)
        return kEffectBeam;
    else if (strType.CompareNoCase("afterImage") == 0)
        return kEffectAfterImage;
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectdatamanager.cpp"
    MS2_ASSERT_AT(0x50, 0);
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.cpp"
    return kEffectNone;
}
MS2_REPLACE(0x1411a0f80, FUN_1411a0f80, 770, 0x21CB09DD);

// @0x1411a12f0
CString FUN_1411a12f0(int nType)
{
    switch (nType)
    {
    case kEffectNif: return "nif";
    case kEffectSoundEvent: return "SoundEvent";
    case kEffectSoundMusic: return "SoundMusic";
    case kEffectMonochrome: return "Monochrome";
    case kEffectRadialBlur: return "RadialBlur";
    case kEffectWeather: return "Weather";
    case kEffectSwoosh: return "Swoosh";
    case kEffectStatus: return "Status";
    case kEffectLight: return "Light";
    case kEffectFog: return "Fog";
    case kEffectRandom: return "Random";
    case kEffectVibrate: return "Vibrate";
    case kEffectRibbon: return "Ribbon";
    case kEffectChaosLight: return "ChaosLight";
    case kEffectTextureOverride: return "TextureOverride";
    case kEffectLightning: return "Lightning";
    case kEffectCameraMove: return "CameraMove";
    case kEffectScreenMasking: return "ScreenMasking";
    case kEffectBeam: return "Beam";
    case kEffectAfterImage: return "AfterImage";
    default: return "NULL";
    }
}
MS2_REPLACE(0x1411a12f0, FUN_1411a12f0, 884, 0x97B11DA4);

// @0x1411a16c0
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h"
int FUN_1411a16c0(Unk_140165cf0* pNode, const char* pszName, int& nType)
{
    if (FALSE)
    {
        MS2_ASSERT_AT(0xfa, FALSE);
        return 2;
    }
    CString strType;
    int nResult = FUN_1408733e0(pNode, pszName, strType);
    if (nResult != 0)
        return nResult;
    nType = FUN_1411a0f80(strType);
    return nResult;
}
MS2_REPLACE(0x1411a16c0, FUN_1411a16c0, 188, 0x12156597);
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.cpp"

// ======== second CU: EffectNode ========
#include "effectdummy.h"

// The ground probe: physxhelper.h's Unk_RayCastInfo / CPhysXHelper::FUN_14168a310 with efd::Point3 points.
struct Unk_EffNodeRayHit
{
    Unk_EffNodeRayHit();                                        // 0x140ad4440
    efd::Point3 m_origin;                                       // +0x00
    efd::Point3 m_dir;                                          // +0x0c
    float m_maxDist;                                            // +0x18
    int m_groups;                                               // +0x1c
    void* m_20;
    void* m_28;
    class Unk_EffNodeEntity* m_hitEntity;                       // +0x30
    void* m_hitActor;
    void* m_hitShape;
    float m_hitDist;                                            // +0x48
    efd::Point3 m_hitPoint;                                     // +0x4c
    efd::Point3 m_hitNormal;                                    // +0x58
};
MS2_CHECK_SIZE(Unk_EffNodeRayHit, 0x68);
class Unk_EffNodeEntity
{
public:
    void FUN_140ae1160(unsigned int uiPropId, unsigned short* pOut);    // short property
};
class Unk_EffNodePhysX
{
public:
    int FUN_14168a310(const efd::Point3& kFrom, efd::Point3& kHit, Unk_EffNodeRayHit* pInfo, float fMaxDist,
                      efd::Point3* pNormal, int nMask);
};
Unk_EffNodePhysX* FUN_1409f7ca0();

const NiRTTI EffectNode::ms_RTTI("EffectNode", &LightUnaffectedNode::ms_RTTI);

// @0x1411a32c0
NiObject* EffectNode::CreateClone(NiCloningProcess& kCloning)
{
    EffectNode* pkClone = new (efd::MemHint(efd::MemHint::NONE)) EffectNode(m_bUpdateEffects, m_bTemplate);
    CopyMembers(pkClone, kCloning);
    return pkClone;
}

// @0x1411a3380
void EffectNode::CopyMembers(EffectNode* pkDest, NiCloningProcess& kCloning)
{
    if (pkDest == 0)
        return;
    LightUnaffectedNode::CopyMembers(pkDest, kCloning);
    if (m_spMovement.get())
        pkDest->FUN_1411a3db0(m_spMovement->Clone());
    pkDest->m_unk_17c = m_unk_17c;
    pkDest->m_bApplyLocalScale = m_bApplyLocalScale;
    pkDest->m_bApplyWorldTransform = m_bApplyWorldTransform;
    pkDest->FUN_1411a3fd0(m_pTarget);
    pkDest->FUN_1411a4040(m_kTranslate);
    pkDest->FUN_1411a4000(m_kRotate);
    pkDest->FUN_1411a3fa0(m_bOnGround);
}
MS2_REPLACE_METHOD(0x1411a3380, EffectNode, CopyMembers, 291, 0xCB6031CB);

// @0x1411a34b0
EffectNode::EffectNode(bool bUpdateEffects, bool bTemplate)
    : LightUnaffectedNode(bUpdateEffects, bTemplate), m_pTarget(0), m_bApplyWorldTransform(0), m_bApplyLocalScale(1),
      m_bOnGround(0), m_kTranslate(0.0f, 0.0f, 0.0f), m_unk_17c(1), m_spMovement(0)
{
    m_kRotate.MakeIdentity();
}

// @0x1411a35b0
EffectNode::EffectNode(const CEffectDummy& kDummy)
    : LightUnaffectedNode(true, false), m_pTarget(0), m_bOnGround(0), m_unk_17c(2), m_spMovement(0)
{
    {
        NiFixedString kName(kDummy.GetName());
        SetName(kName);
    }
    FUN_1411a3cb0(kDummy);
}

// @0x1411a36b0
EffectNode::~EffectNode()
{
    m_spMovement = 0;
}

// @0x1411a3720
void EffectNode::UpdateWorldData()
{
    if (m_pkParent != 0) {
        NiTransform kParent = m_pkParent->GetWorldTransform();
        if (!m_bApplyLocalScale)
            kParent.m_fScale = 1.0f;
        if (m_bApplyWorldTransform) {
            NiPoint3 kUp(0.0f, 0.0f, m_kTranslate.z);
            NiPoint3 kPlane(m_kTranslate.x, m_kTranslate.y, 0.0f);
            NiMatrix3 kInv;
            m_pkParent->GetWorldRotate().Inverse(kInv);
            m_kLocal.m_Translate = kInv * kUp;
            m_kWorld = kParent * m_kLocal;
            m_kWorld.m_Rotate = m_kRotate;
            if (m_pTarget != 0) {
                m_kWorld.m_Rotate = m_pTarget->GetWorldRotate() * m_kWorld.m_Rotate;
                NiPoint3 kOffset = m_pTarget->GetWorldRotate() * kPlane;
                m_kWorld.m_Translate.x += kOffset.x;
                m_kWorld.m_Translate.y += kOffset.y;
            }
        } else {
            m_kWorld = kParent * m_kLocal;
        }
    } else {
        m_kWorld = m_kLocal;
    }
    if (m_spMovement.get()) {
        double dTime = FUN_14086d260()->FUN_141473260();
        m_kWorld = m_spMovement->FUN_141625430(dTime, m_kWorld);
    }
    if (m_bOnGround) {
        Unk_EffNodeRayHit kInfo;
        efd::Point3 kHit;
        if (FUN_1409f7ca0()->FUN_14168a310(m_kWorld.m_Translate + NiPoint3(0.0f, 0.0f, 60.0f), kHit, &kInfo, 0, 0, 0)) {
            m_kWorld.m_Translate = kHit;
            m_kWorld.m_Translate.z += 1.0f;
            if (kInfo.m_hitEntity != 0) {
                unsigned short nKind = 0;
                kInfo.m_hitEntity->FUN_140ae1160(0xada5c5d2, &nKind);
                if (nKind == 8)
                    m_kWorld.m_Translate.z += 50.0f;
            }
        }
    }
    if (m_spCollisionObject)
        m_spCollisionObject->UpdateWorldData();
}
MS2_REPLACE_METHOD(0x1411a3720, EffectNode, UpdateWorldData, 1407, 0xA6E76FBE);

// @0x1411a3cb0
void EffectNode::FUN_1411a3cb0(const CEffectDummy& kDummy)
{
    m_bApplyWorldTransform = kDummy.m_bApplyWorldTransform;
    m_bApplyLocalScale = kDummy.m_bApplyLocalScale;
    FUN_1411a4040(reinterpret_cast<const NiPoint3&>(kDummy.GetTranslate()));
    SetScale(kDummy.m_fScale);
    m_kRotate.FromEulerAnglesXYZ(kDummy.m_vRotation.x * 3.1415927f / 180.0f, kDummy.m_vRotation.y * 3.1415927f / 180.0f,
                                 kDummy.m_vRotation.z * 3.1415927f / 180.0f);
    FUN_1411a4000(m_kRotate);
}
MS2_REPLACE_METHOD(0x1411a3cb0, EffectNode, FUN_1411a3cb0, 244, 0x5441C62C);

// @0x1411a3db0
void EffectNode::FUN_1411a3db0(INodeMovement* pMovement) { m_spMovement.AssignRaw(pMovement); }
MS2_REPLACE_METHOD(0x1411a3db0, EffectNode, FUN_1411a3db0, 43, 0x3153449B);

// @0x1411a3fa0
void EffectNode::FUN_1411a3fa0(int bOnGround) { m_bOnGround = bOnGround; }
MS2_REPLACE_METHOD(0x1411a3fa0, EffectNode, FUN_1411a3fa0, 25, 0xA75DD37E);

// @0x1411a3fc0
const NiRTTI* EffectNode::GetRTTI() const { return &ms_RTTI; }

// @0x1411a3fd0
void EffectNode::FUN_1411a3fd0(NiAVObject* pTarget)
{
    if (pTarget != this)
        m_pTarget = pTarget;
}
MS2_REPLACE_METHOD(0x1411a3fd0, EffectNode, FUN_1411a3fd0, 40, 0xF6CFED15);

// @0x1411a4000
void EffectNode::FUN_1411a4000(const NiMatrix3& kRot)
{
    m_kLocal.m_Rotate = kRot;
    m_kRotate = m_kLocal.m_Rotate;
}
MS2_REPLACE_METHOD(0x1411a4000, EffectNode, FUN_1411a4000, 64, 0x244D07F7);

// @0x1411a4040
void EffectNode::FUN_1411a4040(const NiPoint3& kPos) { m_kLocal.m_Translate = m_kTranslate = kPos; }
MS2_REPLACE_METHOD(0x1411a4040, EffectNode, FUN_1411a4040, 60, 0xFFB13170);

// ======== second CU: CEffectService ========
#include "ms2/commonfiles/timeutil.h"
#include "pendingeffect.h"
#include "raindroponcubeemitter.h"
#include "afterimageitem.h"
#include <efd/MessageService.h>
#include <egf/EntityChangeMessage.h>
#include <egf/EntityManager.h>
#include <ecr/SceneGraphService.h>
#include <ecr/RenderService.h>
#include <ecr/LightService.h>
#include <NiRenderObject.h>
#include "ms2/client/ms2/gameobject.h"

extern int DAT_143ae2b30;                                       // 1: the scene is split over several effect roots
efd::MessageService* FUN_1413f9830();
int FUN_140ad0d60(int n, int nMin, int nMax);                  // clamp
struct Unk_EsOptionData
{
    char m_pad_00[0x12];
    bool m_bHide12;                                             // +0x12 hides type-4 effects
    bool m_bHide13;                                             // +0x13 hides type-2 effects
};
class Unk_EsOption { public: Unk_EsOptionData* FUN_140b123b0(); };
Unk_EsOption* FUN_1409a8b10();
// The client config (FUN_1401d31f0, declared void* in postprocesseffect.h): sky object files at +0x208, area effect files at +0x3c0.
struct Unk_EsConfig
{
    char m_pad_000[0x208];
    CString m_astrSky[7];                                       // +0x208
    char m_pad_240[0x180];
    CString m_strArea3c0;                                       // +0x3c0
    CString m_strArea3c8;
    CString m_strArea3d0;
    CString m_strArea3d8;
    CString m_strArea3e0;
    CString m_strArea3e8;
    CString m_strArea3f0;
};
// The camera (FUN_1409478c0) and its target.
class Unk_EsCamera
{
public:
    int FUN_140a18070();
    GameObject* FUN_140a38d60();
};
Unk_EsCamera* FUN_1409478c0();
// The field data of a map (MS2Ptr<CFieldDataCli>, FUN_140a55460).
struct Unk_EsFieldData
{
    char m_pad_000[0x1a0];
    CString m_strEffect1a0;                                     // +0x1a0 the field effect
    char m_pad_1a8[0x28];
    CString m_strAreaEffect;                                    // +0x1d0 the area (weather) effect
};
class Unk_EsFieldPtr
{
public:
    ~Unk_EsFieldPtr();                                          // 0x1408850f0
    Unk_EsFieldData* FUN_1409657a0() const;                     // get
    Unk_EsFieldData* FUN_140885340() const;                     // operator->
private:
    void* m_pad_00;
    Unk_EsFieldData* m_p;
};
Unk_EsFieldPtr FUN_140a55460(int nMapId);
// A map override row (FUN_140302b00()->FUN_1403ed1d0()->FUN_140428a90()).
struct Unk_EsMapRow
{
    int FUN_1404054d0(int nMapId);                              // applies to the map
    char m_pad_00[0x38];
    CStringW m_strAreaEffect;                                   // +0x38
};
class Unk_EsMapRowPtr
{
public:
    ~Unk_EsMapRowPtr();                                         // 0x1403e5330
    void* FUN_1403e8a60() const;                                // get
    Unk_EsMapRow* FUN_1403e8c40() const;                        // operator->
private:
    void* m_pad_00;
    void* m_p;
};
class Unk_EsMapTable { public: Unk_EsMapRowPtr FUN_140428a90(); };
class Unk_EsMapMgr { public: Unk_EsMapTable* FUN_1403ed1d0(); };
Unk_EsMapMgr* FUN_140302b00();
CString FUN_1401d4330(const wchar_t* psz, int n);              // wide to multi-byte
void* FUN_1409ffd30(GameObject* pObject);                       // the actor of an object
// Depth-first walker over a scene graph (0x38 bytes; unrecovered class, same as util.cpp).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);                          // 0x14098cb80
    ~Unk_SceneWalker();                                         // 0x14098cf00
    NiAVObject* Next(bool bDescend);                            // 0x14098e0d0
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x38);
// Objects with a "fade" virtual (slot 41).
class Unk_EsFadeObject
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void SetFadeValue(float fValue);                    // slot 41
};
extern char DAT_143afbfb8;                                      // RTTI descriptor of Unk_EsFadeObject
Unk_EsFadeObject* FUN_14098d8d0(char* pRtti, NiAVObject* pObject);
void FUN_141d2c900(NiAVObject* pObject, bool bFlag);

// The application service (class id 0x06100001, physxhelper.cpp); only its dependency id is used here.
struct Unk_EsAppService { static const efd::ClassID CLASS_ID = 0x06100001; };
// egfPhysX::SceneService (kCLASSID_SceneService; its header pulls in PhysX).
struct Unk_EsSceneService { static const efd::ClassID CLASS_ID = 0x07001008; };

// @0x1400e7a30
EE_IMPLEMENT_CONCRETE_CLASS_INFO(CEffectService);
#ifndef MS2_HOOK_DLL
// @0x1400e7a50
EE_HANDLER_WRAP(CEffectService, FUN_1411a7330, egf::EntityChangeMessage, 8196);
// @0x1400e7ab0
EE_HANDLER_WRAP(CEffectService, FUN_1411a7000, egf::EntityChangeMessage, 8253);
// @0x1400e7b10
EE_HANDLER_WRAP(CEffectService, FUN_1411a7070, egf::EntityChangeMessage, 8254);
#endif
// @0x1400e7c90
static const efd::Category s_catEffectChannel(efd::UniversalID::ECU_Any, 0xfff, 0x07f00004);

int Unk_EsEffectGroup::m_sTotalEffectCount = 0;

// @0x1411a42b0
void Unk_EsEffectGroup::FUN_1411a42b0()
{
    EffectSkipMgr* pSkip = TSingleton<EffectSkipMgr>::GetInstance();
    for (std::list<CEffectPtr>::iterator it = m_listEffects.begin(); it != m_listEffects.end(); ++it) {
        pSkip->RemoveCount((*it)->GetName());
        (*it)->vfunc_7();
    }
    m_sTotalEffectCount -= m_listEffects.size();
    MS2_ASSERT_AT(0x5b, m_sTotalEffectCount >= 0);
    m_listEffects.clear();
}
MS2_REPLACE_METHOD(0x1411a42b0, Unk_EsEffectGroup, FUN_1411a42b0, 325, 0x1C4B21DE);

inline TSingleton<CEffectService>::TSingleton() { s_instance = static_cast<CEffectService*>(this); }

// @0x1411a4400
CEffectService::CEffectService()
    : m_spRoot(0), m_bEnabled(true), m_listTracked(10), m_listLooping(10), m_spF8(0), m_spRain(0), m_unk_128(1),
      m_bAreaEffect(false), m_unk_130(0), m_list140(10), m_unk_170(0), m_unk_188(3)
{
    m_nTick = GetTickCountMs2();
}

// @0x1411a4650
CEffectService::~CEffectService()
{
}

// @0x1411a47e0
const char* CEffectService::GetDisplayName() const
{
    return "EffectService";
}
MS2_REPLACE_METHOD(0x1411a47e0, CEffectService, GetDisplayName, 13, 0x9D4B06A7);

// @0x1411a4800
bool FUN_1411a4800(const CString& strName, int nArg)
{
    if (strName.IsEmpty())
        return true;
    CEffectDataPtr spData = TSingleton<EffectDataManager>::GetInstance()->FUN_14119f870(strName);
    if (spData == 0)
        return false;
    bool bError = false;
    for (POSITION pos = spData->FUN_14119f540().GetHeadPosition(); pos != 0; spData->FUN_14119f540().GetNext(pos)) {
        if (!spData->FUN_14119f540().GetAt(pos)->vfunc_5(nArg))
            bError = true;
    }
    if (bError)
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"CEffectService::PreLoad Found Error effectID:{0}", strName);
    return true;
}
MS2_REPLACE(0x1411a4800, FUN_1411a4800, 405, 0x3BC9D76A);

// @0x1411a49c0
unsigned CEffectService::FUN_1411a49c0(Unk_EffectTarget& kTarget)
{
    kTarget.m_b34 = false;
    return FUN_1411a4a00(kTarget);
}
MS2_REPLACE_METHOD(0x1411a49c0, CEffectService, FUN_1411a49c0, 43, 0xA316FB5D);

// @0x1411a6060
void CEffectService::FUN_1411a6060(unsigned nId)
{
    if (nId == 0)
        return;
    FUN_1411a66d0(nId);
    Unk_EsGroupMap::iterator it = m_mapGroups.find(nId);
    if (it == m_mapGroups.end())
        return;
    Unk_EsEffectGroup* pGroup = it->second;
    for (std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect) {
        CEffectPtr& spEffect = *itEffect;
        spEffect->vfunc_5();
    }
}
MS2_REPLACE_METHOD(0x1411a6060, CEffectService, FUN_1411a6060, 247, 0x8944F06E);

// @0x1411a66d0
void CEffectService::FUN_1411a66d0(unsigned nId)
{
    std::list<MS2Ptr<PendingEffect> >::iterator it = m_listPending.begin();
    while (it != m_listPending.end()) {
        MS2Ptr<PendingEffect> spPending = *it;
        if (spPending->GetId() == nId)
            it = m_listPending.erase(it);
        else
            it++;
    }
}
MS2_REPLACE_METHOD(0x1411a66d0, CEffectService, FUN_1411a66d0, 224, 0xC6448A04);

// @0x1411a67c0
void CEffectService::FUN_1411a67c0() { m_listPending.clear(); }
MS2_REPLACE_METHOD(0x1411a67c0, CEffectService, FUN_1411a67c0, 31, 0x55C7EEBD);

// @0x1411a67f0
void CEffectService::FUN_1411a67f0(unsigned nId, float f)
{
    FUN_1411a66d0(nId);
    Unk_EsGroupMap::iterator it = m_mapGroups.find(nId);
    if (it == m_mapGroups.end())
        return;
    Unk_EsEffectGroup* pGroup = it->second;
    for (std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect) {
        CEffectPtr& spEffect = *itEffect;
        spEffect->vfunc_6(f);
    }
}
MS2_REPLACE_METHOD(0x1411a67f0, CEffectService, FUN_1411a67f0, 250, 0xE419866B);

// @0x1411a68f0
void CEffectService::FUN_1411a68f0(unsigned nId, bool b)
{
    Unk_EsGroupMap::iterator it = m_mapGroups.find(nId);
    if (it == m_mapGroups.end())
        return;
    Unk_EsEffectGroup* pGroup = it->second;
    for (std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect) {
        CEffectPtr& spEffect = *itEffect;
        spEffect->vfunc_10(b);
    }
}
MS2_REPLACE_METHOD(0x1411a68f0, CEffectService, FUN_1411a68f0, 234, 0x3612B374);

// @0x1411a69e0
void CEffectService::FUN_1411a69e0(unsigned nId)
{
    if (nId != 0) {
        FUN_1411a66d0(nId);
        int bDone = 1;
        Unk_EsGroupMap::iterator it = m_mapGroups.find(nId);
        if (it == m_mapGroups.end())
            return;
        Unk_EsEffectGroup* pGroup = it->second;
        for (std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect) {
            CEffectPtr& spEffect = *itEffect;
            bDone = spEffect->vfunc_11();
            if (bDone == 0)
                break;
        }
        if (bDone == 0)
            FUN_1411a6060(nId);
    }
}
MS2_REPLACE_METHOD(0x1411a69e0, CEffectService, FUN_1411a69e0, 288, 0x15C3A538);

#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.h"
// @0x1411b2df0
inline std::list<CEffectPtr>::iterator Unk_EsEffectGroup::FUN_1411b2df0(std::list<CEffectPtr>::iterator it)
{
    --m_sTotalEffectCount;
    MS2_ASSERT_AT(0x28, m_sTotalEffectCount >= 0);
    return m_listEffects.erase(it);
}

// @0x1411b2720
inline bool Unk_EsEffectGroup::FUN_1411b2720() { return m_listEffects.empty(); }
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\effectservice.cpp"

// @0x1411a6490
void CEffectService::FUN_1411a6490()
{
    EffectSkipMgr* pSkip = TSingleton<EffectSkipMgr>::GetInstance();
    Unk_EsGroupMap::iterator it = m_mapGroups.begin();
    Unk_EsGroupMap::iterator itEnd = m_mapGroups.end();
    while (it != itEnd) {
        Unk_EsEffectGroup* pGroup = it->second;
        std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280();
        std::list<CEffectPtr>::iterator itEffectEnd = pGroup->FUN_1410443f0();
        while (itEffect != itEffectEnd) {
            CEffectPtr spEffect = *itEffect;
            if (spEffect->FUN_14119f400()) {
                pSkip->RemoveCount(spEffect->GetName());
                spEffect->vfunc_7();
                itEffect = pGroup->FUN_1411b2df0(itEffect);
            } else {
                ++itEffect;
            }
        }
        if (pGroup->FUN_1411b2720()) {
            it = m_mapGroups.erase(it);
            delete pGroup;
        } else {
            ++it;
        }
    }
}
MS2_REPLACE_METHOD(0x1411a6490, CEffectService, FUN_1411a6490, 556, 0x40B935F8);

// @0x1411a6b10
NiNode* CEffectService::FUN_1411a6b10()
{
    if (DAT_143ae2b30 != 0) {
        unsigned nBest = 0;
        unsigned nMin = m_ppRoots[0]->GetChildCount();
        for (unsigned i = 0; i < m_nRoots; i++) {
            unsigned nCount = m_ppRoots[i]->GetChildCount();
            if (nMin > nCount) {
                nBest = i;
                nMin = nCount;
            }
        }
        return m_ppRoots[nBest];
    }
    return m_spRoot;
}
MS2_REPLACE_METHOD(0x1411a6b10, CEffectService, FUN_1411a6b10, 193, 0x5DC1F652);

// @0x1411a6be0
void CEffectService::FUN_1411a6be0()
{
    if (DAT_143ae2b30 != 0) {
        for (unsigned i = 0; i < m_nRoots; i++) {
            for (unsigned n = m_ppRoots[i]->GetArrayCount(); n > 0; n--)
                m_ppRoots[i]->DetachChildAt(n - 1);
        }
    } else {
        if (m_spRoot) {
            for (unsigned n = m_spRoot->GetArrayCount(); n > 0; n--)
                m_spRoot->DetachChildAt(n - 1);
        }
    }
}
MS2_REPLACE_METHOD(0x1411a6be0, CEffectService, FUN_1411a6be0, 362, 0x5B05E66E);

// @0x1411a6d50
void CEffectService::FUN_1411a6d50(NiAVObject* pChild)
{
    if (DAT_143ae2b30 != 0) {
        for (unsigned i = 0; i < m_nRoots; i++) {
            for (unsigned n = m_ppRoots[i]->GetArrayCount(); n > 0; n--)
                m_ppRoots[i]->DetachChild(pChild);
        }
    } else {
        if (m_spRoot) {
            for (unsigned n = m_spRoot->GetArrayCount(); n > 0; n--)
                m_spRoot->DetachChild(pChild);
        }
    }
}
MS2_REPLACE_METHOD(0x1411a6d50, CEffectService, FUN_1411a6d50, 322, 0x64E3F501);

// @0x1411a6ea0
void CEffectService::FUN_1411a6ea0(Unk_EsTracked* p)
{
    if (p != 0) {
        Unk_EsTrackedPtr spTracked(p);
        m_listTracked.AddTail(spTracked);
    }
}
MS2_REPLACE_METHOD(0x1411a6ea0, CEffectService, FUN_1411a6ea0, 85, 0xBF19BC72);

// @0x1411a6f00
void CEffectService::FUN_1411a6f00(const egf::EntityID& id)
{
    POSITION pos = m_listTracked.GetHeadPosition();
    while (pos != NULL) {
        POSITION posCur = pos;
        Unk_EsTrackedPtr& spTracked = m_listTracked.GetNext(pos);
        if (spTracked->FUN_1411b1ee0() == id) {
            GameObject* pObject = FUN_1403ed2d0()->FUN_141bd0fa0(id);
            if (pObject != NULL)
                pObject->vfunc_39();
            m_listTracked.RemoveAt(posCur);
            return;
        }
    }
}
MS2_REPLACE_METHOD(0x1411a6f00, CEffectService, FUN_1411a6f00, 245, 0xD3ECCB7F);

// @0x1411a7000
void CEffectService::FUN_1411a7000(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    FUN_1411a7420(pMsg, targetChannel);
}
MS2_REPLACE_METHOD(0x1411a7000, CEffectService, FUN_1411a7000, 94, 0x625BA2B9);

// @0x1411a7070
void CEffectService::FUN_1411a7070(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    if (!m_mapLights.empty())
    {
        egf::Entity* pEntity = pMsg->GetEntity();
        const egf::EntityID& id = pEntity->GetEntityID();
        const egf::FlatModel* pModel = pEntity->GetModel();
        if (!pModel->ContainsModel(0x2c4767f5))
            return;
        std::map<egf::EntityID, NiLightPtr>::iterator it = m_mapLights.find(id);
        if (it != m_mapLights.end())
        {
            if (DAT_143ae2b30 != 0)
            {
                NiLightPtr spLight = it->second;
                if (spLight)
                {
                    for (unsigned i = 0; i < m_nRoots; i++)
                    {
                        if (m_ppRoots[i]->DetachEffect(spLight))
                            m_ppRoots[i]->UpdateEffects();
                    }
                }
            }
            else
            {
                NiLightPtr spLight = it->second;
                if (spLight && m_spRoot)
                {
                    if (m_spRoot->DetachEffect(spLight))
                        m_spRoot->UpdateEffects();
                }
            }
            m_mapLights.erase(it);
        }
    }
}
MS2_REPLACE_METHOD(0x1411a7070, CEffectService, FUN_1411a7070, 690, 0x516E4B1D);

// @0x1411a7330
void CEffectService::FUN_1411a7330(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    egf::Entity* pEntity = pMsg->GetEntity();
    const egf::FlatModel* pModel = pEntity->GetModel();
    if (!pModel->ContainsModel(0x2c4767f5))
        return;
    if (DAT_143ae2b30 != 0)
    {
        for (unsigned i = 0; i < m_nRoots; i++)
            m_ppRoots[i]->UpdateEffects();
    }
    else
    {
        if (m_spRoot)
            m_spRoot->UpdateEffects();
    }
}
MS2_REPLACE_METHOD(0x1411a7330, CEffectService, FUN_1411a7330, 230, 0xA7DD3079);

// @0x1411a7420
void CEffectService::FUN_1411a7420(const egf::EntityChangeMessage* pMsg, efd::Category targetChannel)
{
    FUN_1411a74a0(pMsg->GetEntity()->GetEntityID(), pMsg->GetEntity());
}
MS2_REPLACE_METHOD(0x1411a7420, CEffectService, FUN_1411a7420, 121, 0x829EF2EC);

// @0x1411a74a0
void CEffectService::FUN_1411a74a0(egf::EntityID id, egf::Entity* pEntity)
{
    if (pEntity != NULL)
    {
        const egf::FlatModel* pModel = pEntity->GetModel();
        if (!pModel->ContainsModel(0x2c4767f5))
            return;
        ecr::LightService* pLightService = GetServiceManager()->GetSystemServiceAs<ecr::LightService>();
        if (pLightService != NULL)
        {
            NiLight* pLight = pLightService->GetLightFromEntity(id);
            if (DAT_143ae2b30 != 0)
            {
                if (pLight != NULL)
                {
                    for (unsigned i = 0; i < m_nRoots; i++)
                    {
                        if (m_ppRoots[i]->AttachEffect(pLight))
                            m_ppRoots[i]->UpdateEffects();
                    }
                    m_mapLights.insert(std::make_pair(id, pLight));
                }
            }
            else
            {
                if (pLight != NULL && m_spRoot)
                {
                    if (m_spRoot->AttachEffect(pLight))
                        m_spRoot->UpdateEffects();
                    m_mapLights.insert(std::make_pair(id, pLight));
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1411a74a0, CEffectService, FUN_1411a74a0, 539, 0xEE8C2006);

// @0x1411a76d0
void CEffectService::FUN_1411a76d0()
{
    if (DAT_143ae2b30 != 0) {
        for (unsigned i = 0; i < m_nRoots; i++)
            m_ppRoots[i]->UpdateEffects();
    } else {
        if (m_spRoot)
            m_spRoot->UpdateEffects();
    }
}
MS2_REPLACE_METHOD(0x1411a76d0, CEffectService, FUN_1411a76d0, 133, 0xF7D68405);

// @0x1411a7760
void CEffectService::FUN_1411a7760(unsigned nId, std::vector<CEffectPtr>& vOut)
{
    Unk_EsGroupMap::iterator it = m_mapGroups.find(nId);
    if (it == m_mapGroups.end())
        return;
    Unk_EsEffectGroup* pGroup = it->second;
    for (std::list<CEffectPtr>::iterator itEffect = pGroup->FUN_141044280(); itEffect != pGroup->FUN_1410443f0(); ++itEffect)
        vOut.push_back(*itEffect);
}
MS2_REPLACE_METHOD(0x1411a7760, CEffectService, FUN_1411a7760, 200, 0x1C64A78D);

// @0x1411a7830
bool CEffectService::FUN_1411a7830() { return m_bEnabled; }
MS2_REPLACE_METHOD(0x1411a7830, CEffectService, FUN_1411a7830, 15, 0x43A40A0D);

// @0x1411a7850
void CEffectService::FUN_1411a7850(bool bEnabled) { m_bEnabled = bEnabled; }
MS2_REPLACE_METHOD(0x1411a7850, CEffectService, FUN_1411a7850, 23, 0x2A7F450D);

// @0x1411a7870
void CEffectService::FUN_1411a7870(int nIndex)
{
    if (m_spF8) {
        if (nIndex != 0)
            return;
        for (unsigned i = 0; i < m_aPreloaded.GetCount(); i++) {
            if (m_spF8 == m_aPreloaded[i])
                m_unk_130 = i;
        }
    }
    if (nIndex != 0)
        FUN_1411a7960(m_unk_130);
    else
        FUN_1411a7960(0);
}
MS2_REPLACE_METHOD(0x1411a7870, CEffectService, FUN_1411a7870, 223, 0x28EB4850);

// @0x1411a7960
void CEffectService::FUN_1411a7960(unsigned nIndex)
{
    unsigned nCount = m_aPreloaded.GetCount();
    if (nCount == 0 || nIndex >= nCount)
        return;
    if (m_spF8) {
        if (DAT_143ae2b30 != 0)
            m_ppRoots[0]->DetachChild(m_spF8);
        else
            m_spRoot->DetachChild(m_spF8);
    }
    m_spF8 = m_aPreloaded[nIndex];
    if (m_spF8) {
        Unk_SceneWalker kWalker(m_spF8);
        NiAVObject* pObject;
        while ((pObject = kWalker.Next(true)) != NULL) {
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
            if (pRender != NULL) {
                FUN_141d2c900(pRender, true);
                Unk_EsFadeObject* pFade = FUN_14098d8d0(&DAT_143afbfb8, pRender);
                if (pFade != NULL)
                    pFade->SetFadeValue(-FLT_MAX);
            }
        }
        if (DAT_143ae2b30 != 0)
            m_ppRoots[0]->AttachChild(m_spF8, true);
        else
            m_spRoot->AttachChild(m_spF8, true);
    }
    FUN_1411a7ce0(nIndex >= 3 && nIndex <= 4);
}
MS2_REPLACE_METHOD(0x1411a7960, CEffectService, FUN_1411a7960, 878, 0x67F5DF8E);

// @0x1411a7ce0
void CEffectService::FUN_1411a7ce0(bool bRain)
{
    m_spRain = 0;
    if (bRain) {
        m_spRain = new (efd::MemHint(efd::MemHint::NONE)) RainDropSystem();
        m_spRain->Create();
    }
}
MS2_REPLACE_METHOD(0x1411a7ce0, CEffectService, FUN_1411a7ce0, 195, 0xBA8FACC7);

// @0x1411a7db0
void CEffectService::FUN_1411a7db0()
{
    if (m_spRain)
        m_spRain->Destroy();
}
MS2_REPLACE_METHOD(0x1411a7db0, CEffectService, FUN_1411a7db0, 65, 0x253E07BD);

// @0x1411a7e00
void CEffectService::FUN_1411a7e00(const CString& strName)
{
    if (m_nAreaEffect != 0) {
        FUN_1411a6060(m_nAreaEffect);
        m_nAreaEffect = 0;
    }
    m_strAreaEffect = strName;
    m_strAreaEffectCur = strName;
}
MS2_REPLACE_METHOD(0x1411a7e00, CEffectService, FUN_1411a7e00, 119, 0xFEB155A4);

// @0x1411a7e80
void CEffectService::FUN_1411a7e80(int nType)
{
    if (m_nAreaEffect != 0) {
        FUN_1411a6060(m_nAreaEffect);
        m_nAreaEffect = 0;
        m_strAreaEffectNext.Empty();
    }
    m_bAreaEffect = nType != 0;
    switch (nType) {
    case 0:
        m_strAreaEffect = m_strAreaEffectCur;
        break;
    case 1:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3d0;
        break;
    case 2:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3d8;
        break;
    case 3:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3c0;
        break;
    case 4:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3c8;
        break;
    case 5:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3e0;
        break;
    case 6:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3e8;
        break;
    case 7:
        m_strAreaEffectNext = static_cast<Unk_EsConfig*>(FUN_1401d31f0())->m_strArea3f0;
        break;
    }
}
MS2_REPLACE_METHOD(0x1411a7e80, CEffectService, FUN_1411a7e80, 454, 0x4C74E821);

// @0x1411a8070
// MS2-FUNCTIONAL: same calls and control flow; the exe frame is 0x10 smaller (field/row ptrs above the temporaries)
void CEffectService::vfunc_1(int nMap)
{
    Unk_EsFieldPtr spField = FUN_140a55460(nMap);
    if (spField.FUN_1409657a0() != NULL) {
        CString strArea = spField.FUN_140885340()->m_strAreaEffect;
        Unk_EsMapRowPtr spRow = FUN_140302b00()->FUN_1403ed1d0()->FUN_140428a90();
        if (spRow.FUN_1403e8a60() != NULL) {
            if (spRow.FUN_1403e8c40()->FUN_1404054d0(nMap) != 0)
                strArea = FUN_1401d4330(spRow.FUN_1403e8c40()->m_strAreaEffect, 0);
        }
        FUN_1411a7e00(strArea);
        if (spField.FUN_140885340()->m_strEffect1a0.GetLength() > 0)
            FUN_1411a5a60(spField.FUN_140885340()->m_strEffect1a0, CString(""));
    }
}
MS2_REPLACE_METHOD_VIA(0x1411a8070, CEffectService, IWorldServiceCallback, vfunc_1, 0, 0);

// @0x1411a8210
void CEffectService::vfunc_3(int nMap)
{
    ecr::LightService* pLightService = GetServiceManager()->GetSystemServiceAs<ecr::LightService>();
    if (DAT_143ae2b30 != 0) {
        if (pLightService != NULL) {
            for (std::map<egf::EntityID, NiLightPtr>::iterator it = m_mapLights.begin(); it != m_mapLights.end(); ++it) {
                NiLight* pLight = pLightService->GetLightFromEntity(it->first);
                if (pLight != NULL) {
                    for (unsigned i = 0; i < m_nRoots; i++)
                        m_ppRoots[i]->DetachEffect(pLight);
                }
            }
            m_mapLights.clear();
            for (unsigned i = 0; i < m_nRoots; i++)
                m_ppRoots[i]->UpdateEffects();
        }
    } else {
        if (pLightService != NULL && m_spRoot) {
            for (std::map<egf::EntityID, NiLightPtr>::iterator it = m_mapLights.begin(); it != m_mapLights.end(); ++it) {
                NiLight* pLight = pLightService->GetLightFromEntity(it->first);
                if (pLight != NULL)
                    m_spRoot->DetachEffect(pLight);
            }
            m_mapLights.clear();
            m_spRoot->UpdateEffects();
        }
    }
    if (m_nAreaEffect != 0) {
        FUN_1411a6060(m_nAreaEffect);
        m_nAreaEffect = 0;
    }
    m_strAreaEffect.Empty();
    m_strAreaEffectCur.Empty();
    FUN_1411a7960(0);
    FUN_1411a67c0();
    FUN_1411a6490();
    FUN_1411a6be0();
}
MS2_REPLACE_METHOD_VIA(0x1411a8210, CEffectService, IWorldServiceCallback, vfunc_3, 0, 0);

// @0x1411a85a0
unsigned CEffectService::FUN_1411a85a0() { return Unk_EsEffectGroup::FUN_1411b1f50(); }
MS2_REPLACE_METHOD(0x1411a85a0, CEffectService, FUN_1411a85a0, 19, 0xAD1E06D6);

// @0x1411a85c0
unsigned CEffectService::FUN_1411a85c0()
{
    if (m_mapGroups.empty())
        return 0;
    return (unsigned)m_listLooping.GetCount();
}
MS2_REPLACE_METHOD(0x1411a85c0, CEffectService, FUN_1411a85c0, 61, 0xAC303898);

// @0x1411a88c0
int CEffectService::FUN_1411a88c0() { return m_unk_188; }
MS2_REPLACE_METHOD(0x1411a88c0, CEffectService, FUN_1411a88c0, 17, 0x116875E2);

// @0x1411a8880
void CEffectService::FUN_1411a8880(int n)
{
    m_unk_188 = FUN_140ad0d60(n, 1, 3);
}
MS2_REPLACE_METHOD(0x1411a8880, CEffectService, FUN_1411a8880, 49, 0x40BB776A);

// @0x1411a8cb0
void CEffectService::FUN_1411a8cb0(const CString& strName)
{
    if (strName.IsEmpty())
        return;
    if (FUN_1409478c0()->FUN_140a18070() == 0)
        return;
    GameObject* pTarget = FUN_1409478c0()->FUN_140a38d60();
    if (pTarget == NULL)
        return;
    Unk_EffectTarget kTarget;
    kTarget.m_strName = strName;
    kTarget.m_nKind = 0;
    kTarget.FUN_140a53190(pTarget->FUN_14123c580());
    void* pActor = FUN_1409ffd30(pTarget);
    if (pActor != NULL)
        kTarget.m_b30 = true;
    unsigned nId = FUN_1411a49c0(kTarget);
    m_list140.AddTail(nId);
}
MS2_REPLACE_METHOD(0x1411a8cb0, CEffectService, FUN_1411a8cb0, 260, 0x48703B45);

// @0x1411a8dc0
void CEffectService::FUN_1411a8dc0()
{
    for (POSITION pos = m_list140.GetHeadPosition(); pos != NULL; m_list140.GetNext(pos)) {
        unsigned nId = m_list140.GetAt(pos);
        FUN_1411a6060(nId);
    }
    m_list140.RemoveAll();
}
MS2_REPLACE_METHOD(0x1411a8dc0, CEffectService, FUN_1411a8dc0, 137, 0x2C9D2F1A);

// @0x1411a8e50
void CEffectService::FUN_1411a8e50(unsigned nTick) { m_nTick = nTick; }
MS2_REPLACE_METHOD(0x1411a8e50, CEffectService, FUN_1411a8e50, 25, 0xE801286E);

// @0x1411a8e70
unsigned CEffectService::FUN_1411a8e70() { return m_nTick; }
MS2_REPLACE_METHOD(0x1411a8e70, CEffectService, FUN_1411a8e70, 17, 0xFA964832);

// @0x1411a91d0
bool CEffectService::FUN_1411a91d0(int nType)
{
    if (FUN_1409a8b10()->FUN_140b123b0()->m_bHide12 == true && nType == 4)
        return false;
    if (FUN_1409a8b10()->FUN_140b123b0()->m_bHide13 == true && nType == 2)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1411a91d0, CEffectService, FUN_1411a91d0, 86, 0x70658B4B);

// @0x1411a9230
unsigned CEffectService::FUN_1411a9230()
{
    static unsigned s_nId;
    if (++s_nId == 0)
        s_nId = 1;
    return s_nId;
}

// @0x1411a9260
efd::SyncResult CEffectService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    pRegistrar->AddDependency<egf::EntityManager>(3);
    pRegistrar->AddDependency<ecr::RenderService>(1);
    pRegistrar->AddDependency<ecr::SceneGraphService>(1);
    pRegistrar->AddDependency<ecr::LightService>(1);
    pRegistrar->AddDependency<Unk_EsAppService>(1);
    pRegistrar->AddDependency<efd::MessageService>(1);
    pRegistrar->AddDependency<Unk_EsSceneService>(1);
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x1411a9260, CEffectService, OnPreInit, 129, 0xC8E52EC1);

// @0x1411aa690
efd::AsyncResult CEffectService::OnShutdown()
{
    m_ppRoots = 0;
    m_aPreloaded.RemoveAll();
    m_spF8 = 0;
    m_spRain = 0;
    for (Unk_EsGroupMap::iterator it = m_mapGroups.begin(); it != m_mapGroups.end(); ++it) {
        it->second->FUN_1411a42b0();
        delete it->second;
    }
    m_mapGroups.clear();
    m_listTracked.RemoveAll();
    FUN_1413f9830()->Unsubscribe(this, s_catEffectChannel, 0);
    if (TSingleton<CAfterImageEffectManager>::GetInstance())
        TSingleton<CAfterImageEffectManager>::DestroyInstance();
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x1411aa690, CEffectService, OnShutdown, 354, 0xA9225F85);

// @0x1411b0140
Unk_EsEffectGroup::~Unk_EsEffectGroup()
{
    FUN_1411a42b0();
}

// @0x1411b1f50
int Unk_EsEffectGroup::FUN_1411b1f50() { return m_sTotalEffectCount; }
