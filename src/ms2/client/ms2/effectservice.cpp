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
};
Unk_EsClock* FUN_14086d260();

// World service (singleton 0x1403ed2d0): the local player.
class Unk_EsWorld
{
public:
    GameObject* FUN_141bd0cc0();
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
