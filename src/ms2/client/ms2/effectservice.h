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
