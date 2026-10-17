// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ms2.cpp
// MS2-RANGE: 0x1400f82a0-0x1400f8710 .text$di
// MS2-RANGE: 0x141489aa0-0x14149fd50 .text$mn
// MS2-RANGE: 0x142cb2a50-0x142cb2bf0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <shlwapi.h>
#include <io.h>
#include <direct.h>
#include <sys/stat.h>
#include <map>
#include <efd/Logger.h>
#include <efd/File.h>
#include <efd/Category.h>
#include <efd/AssetID.h>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <efdPhysX/PhysXSDKManager.h>
#include <efdPhysX/PhysXTypes.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
#include <egf/EntityID.h>
#include <egf/Scheduler.h>
#include <egf/FlatModelManager.h>
#include <egfLua/EntityProxyLua.h>
#include <ecr/RenderService.h>
#include <ecr/RenderSurface.h>
#include <ecr/SceneGraphService.h>
#include <ecr/LightService.h>
#include <ecr/ShaderService.h>
#include <egmAnimation/AnimationService.h>
#include <NiShadowManager.h>
#include <NiMaterialLibrary.h>
#include <NiViewRenderClick.h>
#include <NiDX9Renderer.h>
#include "ms2/ms2format.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/commonfiles/crashmanager.h"
#include "ms2/placeholder/coptimizer.h"
#include "ms2/placeholder/physxerror.h"
#include "ms2/placeholder/cms2defaultsurfacecreator.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2physxallocator.h"
#include "ms2shadowclickgenerator.h"
#include "networkservice.h"

// The single-instance marker: a named auto-reset event "<base>_<n>" for the first n that does not exist yet. The index
// numbers the log file ("MapleStory2_<n>.log"). Name invented (inline in the exe; dtor also folded into engine code).
class Unk_InstanceEvent
{
public:
    explicit Unk_InstanceEvent(const efd::utf8string& strBase) : m_hEvent(0), m_nIndex(0) { Create(strBase); }
    ~Unk_InstanceEvent() { FUN_1414a5a80(); }
    bool Create(const efd::utf8string& strBase);
    void FUN_1414a5a80();                                       // Close: CloseHandle, index 0
    int FUN_1414a56b0() const;                                  // m_nIndex

    HANDLE m_hEvent;
    int m_nIndex;
    efd::utf8string m_strName;
};
MS2_CHECK_SIZE(Unk_InstanceEvent, 0x30);

// The scoped lock of CLockCriticalSection (ctor 0x140203610, dtor 0x1401b5120).
struct Unk_EngineLogLock { Unk_EngineLogLock(CLockCriticalSection& cs, int n); ~Unk_EngineLogLock(); void* p; };
MS2_CHECK_SIZE(Unk_EngineLogLock, 8);

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };     // ctor 0x1401cd100

// The UI scenes: UISceneEntity subclasses registered with the UISwfEntityManager (?\uiscene*.cpp, not recovered).
class UISceneEntity : public UISwfEntity { };
class UISceneLogo : public UISceneEntity { public: UISceneLogo(); char m_pad68[0x40]; };
class UISceneModeSelect : public UISceneEntity { public: UISceneModeSelect(); char m_pad68[0x40]; };
class UISceneLogin : public UISceneEntity { public: UISceneLogin(); char m_pad68[0x90]; };
class UISceneLobby : public UISceneEntity { public: UISceneLobby(); char m_pad68[0x40]; };
class UISceneGame : public UISceneEntity { public: UISceneGame(); char m_pad68[0x40]; };
MS2_CHECK_SIZE(UISceneLogo, 0xa8);
MS2_CHECK_SIZE(UISceneLogin, 0xf8);

// Stand-ins for unrecovered singletons MS2 drives.
class Unk_Ms2Window { public: HWND FUN_14209c720(); };                       // efd::Win32PlatformService::GetWindowRef
Unk_Ms2Window* FUN_140aadf80();
class Unk_Ms2SceneState { public: void FUN_1417e25a0(int nScene); };
Unk_Ms2SceneState* FUN_140aa6d30();
CCrashManager* FUN_140a44830();
class Unk_Ms2Input
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void vfunc_19(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // sees every message before dispatch
};
Unk_Ms2Input* FUN_1414a56c0();
CNetworkService* FUN_140714f90();
COptimizer* FUN_1409f7c90();
void FUN_14161c360(COptimizer* pOptimizer);
class Unk_Ms2PhysXHelper;
Unk_Ms2PhysXHelper* FUN_1409f7ca0();
void FUN_1414a2a10();                                           // TSingleton delete of FUN_1409f7ca0()
void FUN_1414a3f10();                                           // TSingleton delete of FUN_140a44830()
void FUN_140cca840(int n);                                      // crash on purpose (the /crash command)
class Unk_Ms2Recoder { public: void FUN_140c9bc00(); void FUN_140c9bb20(); };
Unk_Ms2Recoder* FUN_140c9cb20();
class Unk_Ms2ImageLoader { public: void FUN_140a58b90(); void FUN_140a58b10(); };
Unk_Ms2ImageLoader* FUN_140a5af70();
class Unk_Ms2GameOption { public: void FUN_141243850(); void FUN_141243860(); void FUN_1412438d0(); void FUN_1412438e0(); };
Unk_Ms2GameOption* FUN_1409a8b10();
class Unk_Ms2PrecacheOption;
Unk_Ms2PrecacheOption* FUN_1406aeee0();
bool FUN_1406af0a0(Unk_Ms2PrecacheOption* p);
ecr::RenderService* FUN_1413f9890();
NiCullingProcess* FUN_141753990();                              // the shadow culling process factory
void FUN_14150baf0(NiAVObject* pkObject);                       // excludes an object from the shadow casters
extern void (*DAT_143afbfc8)(NiAVObject*);
extern const NiFixedString DAT_143ae5290, DAT_143ae5298, DAT_143ae52a0;   // the dir / point / spot shadow materials
extern char DAT_143afc8d0, DAT_143afc898, DAT_143afc8e8, DAT_143afc900, DAT_143afcb90, DAT_143afcba8, DAT_143b08a3c;
extern int DAT_143ab0248;                                       // the service locale
CString FUN_14028dc80(int nId);                                 // a string table text
class Unk_Ms2Features { public: int FUN_14036d8b0(); CString FUN_14036d8e0(); };
Unk_Ms2Features* FUN_140166410();
int FUN_1414a5a40(CStringW sPath);                              // _wmkdir
// Clears a ServiceManager flag (+0x119) before the shutdown request: an MS2 engine addition missing from the SDK
// headers (the exe calls it through SmartPointer::operator->).
void FUN_1414a6180(efd::ServiceManager* pServiceManager);

// ---- statics (.text$di 0x1400f82a0..)
// @0x1400f82a0
static Unk_InstanceEvent s_instanceEvent("MapleStory2");
// @0x1400f8310
EE_IMPLEMENT_CONCRETE_CLASS_INFO(MS2);
// @0x1400f8330
static CString s_strEngineLogFile;
// @0x1400f8360
static CLockCriticalSection s_engineLogLock;
static FILE* s_pEngineLogFile = 0;
// @0x1400f8390
static egfLua::EntityProxy s_entityProxy;
// @0x1400f83b0
static CString s_marketSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
// @0x1400f8480
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400f8540
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NiPhysXParticle.h>
#pragma pop_macro("max")
#pragma pop_macro("min")
// @0x1400f8560
static CString s_strSkill = "skill";
// @0x1400f8590
static CString s_strStun = "stun";
// @0x1400f85c0
static efd::Category s_kPrecacheCategory(0);
// @0x1400f85f0
static Unk_1401cd100 s_pointer(NULL);
// @0x1400f8610
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400f8660
CGameApp theApp;
// @0x1400f8690
static CString s_strSkill2 = "skill";
// @0x1400f86c0
static CString s_strStun2 = "stun";
// @0x1400f86f0
static Unk_1401cd100 s_pointer2(NULL);

// ---- MS2
// @0x141489aa0
MS2::MS2()
{
    ResetTickBase();
    m_spServiceManager = 0;
    m_spFileDest = 0;
    m_spDebugOutDest = 0;
    m_pPhysXManager = 0;
    m_bQuit = 0;
    m_pSurfaceCreator = 0;
    m_pPhysXOutput = 0;
    m_uiLastTickTime = 0;
    m_bCrashOnShutdown = 0;
    efd::Srand(efd::GetPerformanceCounter());
}
// @0x141489c40
MS2::~MS2()
{
}
// @0x141489d10
bool MS2::Run(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    m_pPhysXAllocator = EE_NEW MS2PhysXAllocator;
    m_pPhysXManager = efdPhysX::PhysXSDKManager::GetManager();
    NxPhysicsSDKDesc kDesc = efdPhysX::PhysXTypes::ms_kDefaultPhysicsSDKDesc;
    m_pPhysXOutput = new CPhysXError;
    m_pPhysXManager->Initialize(m_pPhysXAllocator, m_pPhysXOutput, kDesc, 0);
    const wchar_t* pszConfig = L"./Config";
    if (!PathIsDirectoryW(pszConfig))
        CreateDirectoryW(pszConfig, NULL);
    PrepareShaderCache();
    RegisterServices(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
    DAT_143afc8d0 = 0;
    DAT_143afc898 = 0;
    DAT_143afc8e8 = 0;
    DAT_143afc900 = 0;
    DAT_143afcb90 = 0;
    DAT_143afcba8 = 0;
    DAT_143b08a3c = 0;
    FUN_14161c360(FUN_1409f7c90());
    MessageLoop();
    Shutdown();
    return true;
}
MS2_REPLACE_METHOD(0x141489D10, MS2, Run, 518, 0x31115BD9);
// @0x141489f20
void MS2::Quit()
{
    m_bQuit = 1;
}
MS2_REPLACE_METHOD(0x141489F20, MS2, Quit, 18, 0xE74CD770);
// @0x141489f40
void MS2::Tick()
{
    m_uiLastTickTime = GetTickCountMs2();
    FUN_140714f90()->FUN_141538f80();
    if (m_spServiceManager)
        m_spServiceManager->RunOnce();
}
MS2_REPLACE_METHOD(0x141489F40, MS2, Tick, 106, 0xE042105E);
// @0x141489fb0
unsigned int MS2::GetLastTickTime()
{
    return m_uiLastTickTime;
}
MS2_REPLACE_METHOD(0x141489FB0, MS2, GetLastTickTime, 17, 0xB518FD33);
// @0x141489fd0
MS2PhysXAllocator* MS2::GetPhysXAllocator()
{
    return m_pPhysXAllocator;
}
MS2_REPLACE_METHOD(0x141489FD0, MS2, GetPhysXAllocator, 15, 0x5AEB0F79);
// @0x141489ff0
void MS2::SetBackgroundColor(const NiColorA& kColor)
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    if (pSurface) {
        NiViewRenderClick* pkClick = pSurface->GetSceneRenderClick();
        if (pkClick)
            pkClick->SetBackgroundColor(kColor);
    }
}
MS2_REPLACE_METHOD(0x141489FF0, MS2, SetBackgroundColor, 83, 0x677C5834);
// @0x14148a050
NiColorA MS2::GetBackgroundColor()
{
    ecr::RenderSurface* pSurface = FUN_1413f9890()->GetActiveRenderSurface();
    NiViewRenderClick* pkClick;
    if (pSurface != 0 && (pkClick = pSurface->GetSceneRenderClick()) != 0) {
        NiColorA kColor;
        pkClick->GetBackgroundColor(kColor);
        return kColor;
    }
    return NiColorA(efd::ColorA::BLACK);
}
MS2_REPLACE_METHOD(0x14148A050, MS2, GetBackgroundColor, 146, 0x385D2E95);
// @0x14148a0f0
const char* MS2::GetLogFileName()
{
    return m_strLogFile.c_str();
}
MS2_REPLACE_METHOD(0x14148A0F0, MS2, GetLogFileName, 31, 0x6EAC146D);
// @0x14148a120
void MS2::SetWorkingDirectory(bool bParent)
{
    char szModule[MAX_PATH];
    char szPath[MAX_PATH];
    char* pszFilePart;
    GetModuleFileNameA(NULL, szModule, MAX_PATH);
    GetFullPathNameA(szModule, MAX_PATH, szPath, &pszFilePart);
    if (pszFilePart)
        *pszFilePart = 0;
    if (bParent) {
        int nLen = (int)strlen(szPath);
        for (int i = nLen - 2; i > 0; i--) {
            if (szPath[i] == '\\' || szPath[i] == '/') {
                szPath[i + 1] = 0;
                break;
            }
        }
    }
    SetCurrentDirectoryA(szPath);
}
MS2_REPLACE(0x14148A120, MS2::SetWorkingDirectory, 301, 0x956F153E);
// @0x14148a260
void MS2::Precache()
{
    efd::vector<ecr::SceneGraphCache::SceneGraphCacheHandle> kSceneGraphHandles;
    efd::SmartPointer<ecr::SceneGraphService> spSceneGraphService =
        m_spServiceManager->GetSystemServiceAs<ecr::SceneGraphService>();
    if (!spSceneGraphService->Cache("urn:Precache", 0, s_kPrecacheCategory, kSceneGraphHandles))
        spSceneGraphService->UnCacheHandles(kSceneGraphHandles);

    efd::vector<egmAnimation::KFMCache::KFMCacheHandle> kKFMHandles;
    egmAnimation::AnimationService* pAnimationService =
        m_spServiceManager->GetSystemServiceAs<egmAnimation::AnimationService>();
    if (!pAnimationService->Cache("urn:Precache", 0, s_kPrecacheCategory, kKFMHandles))
        pAnimationService->UnCacheHandles(kKFMHandles);

    efd::SmartPointer<egf::FlatModelManager> spFlatModelManager =
        m_spServiceManager->GetSystemServiceAs<egf::FlatModelManager>();
    spFlatModelManager->PreloadModels("urn:emergent-flat-model:Precache", s_kPrecacheCategory);
}
// @0x14148a530
void MS2::RegisterUIScenes()
{
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(new UISceneLogo));
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(new UISceneModeSelect));
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(new UISceneLogin));
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(new UISceneLobby));
    FUN_140b632f0()->FUN_1422d0cd0(MS2Ptr<UISwfEntity>(new UISceneGame));
}
MS2_REPLACE_METHOD(0x14148A530, MS2, RegisterUIScenes, 745, 0x75D64F29);
// @0x14148a820
void MS2::MessageLoop()
{
    m_bQuit = 0;
    MSG msg;
    msg.message = 0;
    PeekMessageW(&msg, NULL, 0, 0, PM_NOREMOVE);
    while (msg.message != WM_QUIT && !m_bQuit) {
        BOOL bMessage = PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) != 0;
        if (bMessage) {
            if (FUN_1414a56c0())
                FUN_1414a56c0()->vfunc_19(msg.hwnd, msg.message, msg.wParam, msg.lParam);
            if (!AfxPreTranslateMessage(&msg)) {
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
        } else {
            Tick();
            int nFrameTime = FUN_1409f7c90()->FUN_1414a5910();
            if (nFrameTime) {
                DWORD dwNow = GetTickCountMs2();
                int nElapsed = dwNow - m_uiLastTickTime;
                if (nElapsed < nFrameTime)
                    Sleep(nFrameTime - nElapsed);
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14148A820, MS2, MessageLoop, 372, 0x6165E8A6);
// @0x14148b090
void MS2::SetCrashOnShutdown()
{
    m_bCrashOnShutdown = 1;
}
MS2_REPLACE_METHOD(0x14148B090, MS2, SetCrashOnShutdown, 21, 0x28735968);
// @0x14148b0b0
// MS2-FUNCTIONAL: the exe calls FUN_1414a6180 (an MS2 engine addition to efd::ServiceManager, not in the SDK headers) through SmartPointer::operator->; here the pointer goes through operator T*
void MS2::Shutdown()
{
    if (FUN_140aadf80() && FUN_140aadf80()->FUN_14209c720())
        KillTimer(FUN_140aadf80()->FUN_14209c720(), 1000);
    if (FUN_140aa6d30())
        FUN_140aa6d30()->FUN_1417e25a0(0);
    if (FUN_140a44830())
        FUN_140a44830()->FUN_1401ce420();
    if (m_spServiceManager) {
        FUN_1414a6180(m_spServiceManager);
        m_spServiceManager->Shutdown(false);
        int nState = m_spServiceManager->GetCurrentState();
        while (nState != efd::ServiceManager::kSysServState_Complete) {
            m_spServiceManager->RunOnce();
            nState = m_spServiceManager->GetCurrentState();
        }
        if (FUN_1409f7ca0())
            FUN_1414a2a10();
        m_spServiceManager = 0;
    }
    if (m_pPhysXManager) {
        m_pPhysXManager->Shutdown();
        delete m_pPhysXAllocator;
        m_pPhysXAllocator = 0;
    }
    if (m_pPhysXOutput) {
        delete m_pPhysXOutput;
        m_pPhysXOutput = 0;
    }
    if (m_bCrashOnShutdown)
        FUN_140cca840(0);
    if (FUN_140a44830())
        FUN_1414a3f10();
}
// @0x14148b340
bool MS2::OnLostDevice(void* pvData)
{
    FUN_140c9cb20()->FUN_140c9bc00();
    return true;
}
MS2_REPLACE(0x14148B340, MS2::OnLostDevice, 29, 0x4B7A9898);
// @0x14148e860
efd::Logger* MS2::CreateLogger()
{
    efd::SmartPointer<efd::Logger> spLogger = EE_NEW efd::Logger;
    efd::LoggerSingleton::Initialize(spLogger);
    efd::utf8string strLogFile(efd::Formatted, "%s_%d.log", "MapleStory2", s_instanceEvent.FUN_1414a56b0());
    m_strLogFile = strLogFile;
    efd::FileDestination::FileOption eOption = efd::FileDestination::kFileOverwrite;
    eOption = efd::FileDestination::kFileAppend;
    m_spFileDest = EE_NEW efd::FileDestination("default", m_strLogFile, eOption, false, true, false);
    spLogger->AddDest(m_spFileDest, false, false);
    m_spDebugOutDest = EE_NEW efd::DebugOutDestination("DebugOut", false, false);
    spLogger->AddDest(m_spDebugOutDest, false, false);
    return spLogger;
}
// @0x14148ec40
void MS2::RemoveLogDestinations()
{
    efd::ILogger* pLogger = efd::GetLogger();
    if (pLogger) {
        if (m_spFileDest) {
            pLogger->RemoveDest(m_spFileDest);
            m_spFileDest = 0;
        }
        if (m_spDebugOutDest) {
            pLogger->RemoveDest(m_spDebugOutDest);
            m_spDebugOutDest = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x14148EC40, MS2, RemoveLogDestinations, 216, 0xA4F1B2B3);
// @0x14148ed20
const char* MS2::GetDisplayName() const
{
    return "MapleStory2";
}
MS2_REPLACE_METHOD(0x14148ED20, MS2, GetDisplayName, 13, 0x0E2EFA1E);
// @0x14148ed40
efd::ClassID MS2::GetClassID() const
{
    return CLASS_ID;
}
MS2_REPLACE_METHOD(0x14148ED40, MS2, GetClassID, 11, 0x29A60EE2);
// @0x14148ed60
efd::SyncResult MS2::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    pDependencyRegistrar->AddDependency<egf::Scheduler>(1);
    pDependencyRegistrar->AddDependency<ecr::ShaderService>(1);
    pDependencyRegistrar->AddDependency<ecr::SceneGraphService>(1);
    pDependencyRegistrar->AddDependency<egmAnimation::AnimationService>(1);
    pDependencyRegistrar->AddDependency<egf::FlatModelManager>(1);
    pDependencyRegistrar->AddDependency<ecr::RenderService>(1);
    pDependencyRegistrar->AddDependency<ecr::LightService>(1);
    FUN_1409a8b10()->FUN_141243850();
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x14148ED60, MS2, OnPreInit, 142, 0xA3212BCD);
// @0x14148ee00
efd::AsyncResult MS2::OnInit()
{
    NiMaterial* pkDirMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5290);
    NiMaterial* pkPointMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5298);
    NiMaterial* pkSpotMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae52a0);
    NiShadowManager::SetShadowRenderCullingProcessFactory(FUN_141753990);
    NiShadowManager::SetShadowVisitorFactory(MS2ShadowVisitor::CreateMS2ShadowVisitor);
    NiShadowManager::SetShadowRenderClickValidatorFactory(MS2ShadowClickValidator::CreateMS2ShadowClickValidator);
    DAT_143afbfc8 = FUN_14150baf0;

    NiMaterialSwapProcessorPtr spSwapProcessor = NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_DIR);
    if (spSwapProcessor) {
        m_spDirShadowMaterial = spSwapProcessor->GetMaterial();
        spSwapProcessor->SetMaterial(pkDirMaterial, NiMaterialInstance::DEFAULT_EXTRA_DATA);
    }
    spSwapProcessor = NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_POINT);
    if (spSwapProcessor) {
        m_spPointShadowMaterial = spSwapProcessor->GetMaterial();
        spSwapProcessor->SetMaterial(pkPointMaterial, NiMaterialInstance::DEFAULT_EXTRA_DATA);
    }
    spSwapProcessor = NiShadowManager::GetMaterialSwapProcessor(NiStandardMaterial::LIGHT_SPOT);
    if (spSwapProcessor) {
        m_spSpotShadowMaterial = spSwapProcessor->GetMaterial();
        spSwapProcessor->SetMaterial(pkSpotMaterial, NiMaterialInstance::DEFAULT_EXTRA_DATA);
    }

    NiShadowClickGeneratorPtr spGenerator = EE_NEW MS2ShadowClickGenerator;
    NiShadowManager::RegisterShadowClickGenerator(spGenerator);
    NiShadowManager::SetActiveShadowClickGenerator(spGenerator);

    efd::SmartPointer<ecr::RenderService> spRenderService = m_spServiceManager->GetSystemServiceAs<ecr::RenderService>();
    if (FUN_1406af0a0(FUN_1406aeee0()))
        Precache();
    FUN_1409a8b10()->FUN_141243860();
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer)
        pkRenderer->AddLostDeviceNotificationFunc(OnLostDevice, this);
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x14148EE00, MS2, OnInit, 880, 0x26CD498D);
// @0x14148f180
efd::AsyncResult MS2::OnTick()
{
    FUN_1409a8b10()->FUN_1412438d0();
    if (FUN_140a5af70())
        FUN_140a5af70()->FUN_140a58b90();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x14148F180, MS2, OnTick, 55, 0xFB1E44E9);
// @0x14148f1c0
efd::AsyncResult MS2::OnShutdown()
{
    FUN_140c9cb20()->FUN_140c9bc00();
    FUN_140c9cb20()->FUN_140c9bb20();
    if (FUN_140a5af70())
        FUN_140a5af70()->FUN_140a58b10();
    efd::AsyncResult eResult = efd::AsyncResult_Complete;
    FUN_1409a8b10()->FUN_1412438e0();
    m_spDirShadowMaterial = 0;
    m_spPointShadowMaterial = 0;
    m_spSpotShadowMaterial = 0;
    if (m_pSurfaceCreator) {
        delete m_pSurfaceCreator;
        m_pSurfaceCreator = 0;
    }
    RemoveLogDestinations();
    return eResult;
}
MS2_REPLACE_METHOD(0x14148F1C0, MS2, OnShutdown, 264, 0x260E0DAC);

// ---- CGameApp
// @0x14148f2d0
CGameApp::CGameApp() : CWinApp(NULL), m_nExitCode(0), m_profiler(CString("Loading"))
{
}
// @0x141491d00
int CGameApp::ExitInstance()
{
    if (m_nExitCode != 0) {
        CWinApp::ExitInstance();
        return m_nExitCode;
    }
    return CWinApp::ExitInstance();
}
MS2_REPLACE_METHOD(0x141491D00, CGameApp, ExitInstance, 61, 0x9C90861C);

// ---- EngineLog
// @0x141491d70
EngineLog::EngineLog()
{
    s_strEngineLogFile = "MS2Log.txt";
    if (!efd::File::DirectoryExists("ms2log"))
        FUN_1414a5a40(CStringW(L"ms2log"));
    Unk_EngineLogLock lock(s_engineLogLock, 1);
    if (s_pEngineLogFile == 0) {
        CString strName;
        bool bAllExist = false;
        if (_access("ms2log/MS2Log9.txt", 0) == 0)
            bAllExist = true;
        if (!bAllExist) {
            for (int i = 0; i < 10; i++) {
                strName.Format("ms2log/MS2Log%d.txt", i);
                if (_access(strName, 0) != 0) {
                    s_strEngineLogFile = strName;
                    break;
                }
            }
        } else {
            // Every slot is used: reuse the oldest one (or one that vanished meanwhile).
            std::map<__time64_t, CString> kFiles;
            for (int i = 0; i < 10; i++) {
                strName.Format("ms2log/MS2Log%d.txt", i);
                if (_access(strName, 2) != 0)
                    continue;
                struct _stat64i32 st;
                int nResult = _stat64i32(strName, &st);
                if (nResult == -1) {
                    if (errno == ENOENT) {
                        s_strEngineLogFile = strName;
                        kFiles.clear();
                        break;
                    } else {
                        errno;
                    }
                } else {
                    kFiles.insert(std::pair<__time64_t, CString>(st.st_mtime, strName));
                }
            }
            if (!kFiles.empty()) {
                s_strEngineLogFile = kFiles.begin()->second;
                kFiles.clear();
            }
        }
        CString strLine;
        s_pEngineLogFile = fopen(s_strEngineLogFile, "w");
        if (s_pEngineLogFile) {
            SYSTEMTIME st;
            GetLocalTime(&st);
            strLine.Format("[Start] %04d-%02d-%02d %02d:%02d:%02d.%03d\n", st.wYear, st.wMonth, st.wDay, st.wHour,
                           st.wMinute, st.wSecond, st.wMilliseconds);
            fwrite(strLine, strLine.GetLength(), 1, s_pEngineLogFile);
            fclose(s_pEngineLogFile);
            s_pEngineLogFile = 0;
        }
    }
}
// @0x1414921b0
EngineLog::~EngineLog()
{
    Unk_EngineLogLock lock(s_engineLogLock, 1);
    if (s_pEngineLogFile) {
        fclose(s_pEngineLogFile);
        s_pEngineLogFile = 0;
    }
}
// @0x141492230
void EngineLog::Write(efd::UInt16 uiModule, efd::UInt8 uiLevel, const char* pszMessage)
{
    Unk_EngineLogLock lock(s_engineLogLock, 1);
    if (s_pEngineLogFile == 0)
        s_pEngineLogFile = fopen(s_strEngineLogFile, "a");
    if (s_pEngineLogFile) {
        CString strTime;
        SYSTEMTIME st;
        GetLocalTime(&st);
        strTime.Format("%04d-%02d-%02d %02d:%02d:%02d.%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute,
                       st.wSecond, st.wMilliseconds);
        CString strLine;
        strLine.Format("[Engine][%s] %s\n", (const char*)strTime, pszMessage);
        fwrite(strLine, strLine.GetLength(), 1, s_pEngineLogFile);
        OutputDebugStringA(strLine);
        fclose(s_pEngineLogFile);
        s_pEngineLogFile = 0;
    }
}

// The client window title: "<name> (x64) [PID:<pid>] (Ver.<ver>) - S:<server>, <locale> Build Time : <date> <time>".
// @0x141492410
efd::utf8string MakeWindowTitle()
{
    CString strPid("");
    strPid.Format(" [PID:%u]", GetCurrentProcessId());
    CString strVersion;
    efd::utf8string strTitle(FUN_14028dc80(0xc3b));
    CString strServer = StringFormat(" - S:{0}, {1}", FUN_140166410()->FUN_14036d8b0(), FUN_140166410()->FUN_14036d8e0());
    strTitle += " (x64)";
    strVersion.Format(" (Ver.%X)", 0x9dd);
    if (DAT_143ab0248 == 1 || DAT_143ab0248 == 2 || DAT_143ab0248 == 3)
        strVersion.Format(" (Ver.%d.%02d.%d)", 1, 0x13, 0x9dd);
    strTitle += strPid;
    strTitle += strVersion;
    strTitle += strServer;
    CString strBuild;
    strBuild.Format(" Build Time : %s %s", (const char*)FormatCompileDate(CString("Apr 13 2022")), "17:38:18");
    strTitle += strBuild;
    return strTitle;
}
MS2_REPLACE(0x141492410, MakeWindowTitle, 779, 0x9C281391);

// ---- inline COMDATs
// @0x141498cb0
inline bool Unk_InstanceEvent::Create(const efd::utf8string& strBase)
{
    FUN_1414a5a80();
    for (unsigned int n = 1; n != 0; n++) {
        m_strName.sprintf("%s_%d", strBase.c_str(), n);
        HANDLE hEvent = CreateEventA(NULL, FALSE, TRUE, m_strName.c_str());
        if (hEvent && GetLastError() != ERROR_ALREADY_EXISTS) {
            m_hEvent = hEvent;
            m_nIndex = n;
            return true;
        } else {
            CloseHandle(hEvent);
        }
    }
    return false;
}
