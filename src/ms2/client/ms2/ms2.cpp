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
#include <efd/ConfigManager.h>
#include <efd/AssetLocatorService.h>
#include <efd/AssetFactoryManager.h>
#include <efd/EnumManager.h>
#include <egf/RapidIterationService.h>
#include "ms2/placeholder/schedulerlua.h"
#include <NiSPWorkflowManager.h>
#include <ecr/TextureRapidIterationService.h>
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include "ms2/placeholder/physxwhiteboxservice.h"
#include "ms2/client/ms2/ms2propservice.h"
#include "ms2/client/ms2/ms2sceneservice.h"
#pragma pop_macro("max")
#pragma pop_macro("min")
#include "ms2/client/ms2/ms2messageservice.h"
#include "ms2/client/ms2/ms2entitymanagerservice.h"
#include "ms2/client/ms2/ms2flatmodelmanager.h"
#include "ms2/client/ms2/ms2entityloaderservice.h"
#include "ms2/client/ms2/ms2scenegraphservice.h"
#include "ms2/client/ms2/ms2renderservice.h"
#include "ms2/client/ms2/ms2lightservice.h"
#include "ms2/client/ms2/ms2animationservice.h"
#include "ms2/client/ms2/ms2cameraservice.h"
#include "ms2/client/ms2/ms2inputservice.h"
#include "ms2/client/ms2/ms2visualtrackermanager.h"
#include "ms2/client/ms2/ms2pickservice.h"
#include "ms2/client/ms2/windowservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/nifanimationservice.h"
#include "ms2/client/ms2/triggerservice.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/client/ms2/postprocessing/postprocessingservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/magicdata.h"
#include "ms2/client/ms2/soundservice.h"
#include "ms2/client/ms2/hardwareinstancingservice.h"
#include "ms2/client/ms2/entityworldmanager.h"
#include "ms2/client/ms2/cubemapinformationservice_3.h"
#include "ms2/client/ms2/decoeditservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/citemservice.h"
#include "ms2/placeholder/cwebbrowserservice.h"
#include "ms2/placeholder/gfxservice.h"
#include "ms2/placeholder/gfximageloader.h"
#include "ms2/placeholder/ms2propertyvisualizationservice.h"
#include "ms2/placeholder/tfunctor2.h"
// the manager singletons CGameApp::InitInstance creates
#include "ms2/client/ms2/achievemanager.h"
#include "ms2/client/ms2/animationcallbackmanager.h"
#include "ms2/client/ms2/autofindtaxistation.h"
#include "ms2/client/ms2/battlerecordmanager.h"
#include "ms2/client/ms2/bgtransparencymgr.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/camera.h"
#include "ms2/client/ms2/clubcli.h"
#include "ms2/client/ms2/commoneffectdummy.h"
#include "ms2/client/ms2/cubemapinformationservice_2.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/effectskipmgr.h"
#include "ms2/client/ms2/filepreload_1.h"
#include "ms2/client/ms2/gpumanager.h"
#include "ms2/client/ms2/groupchatmanager.h"
#include "ms2/client/ms2/guildmanager.h"
#include "ms2/client/ms2/homeblockmanager.h"
#include "ms2/client/ms2/multisceneupdater.h"
#include "ms2/client/ms2/nifeffectparam.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/reconnectionmanagercli.h"
#include "ms2/client/ms2/serverlisttable.h"
#include "ms2/client/ms2/soundeventmgr.h"
#include "ms2/client/ms2/stateeffectmgr.h"
#include "ms2/client/ms2/trademanagerex.h"
#include "ms2/client/ms2/uidungeoncategory.h"
#include "ms2/client/ms2/uiitemenchantdialog.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/adventureleveltablehelper.h"
#include "ms2/commonfiles/banktable.h"
#include "ms2/commonfiles/chapterbooktable.h"
#include "ms2/commonfiles/chatemoticontable.h"
#include "ms2/commonfiles/clubcommon.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/continentregiontable.h"
#include "ms2/commonfiles/dynamicbanwordmanager.h"
#include "ms2/commonfiles/enchantscrolldata.h"
#include "ms2/commonfiles/famegradedata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/itembreakmanager.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
#include "ms2/commonfiles/itemsocketsystemutil.h"
#include "ms2/commonfiles/localepath.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/portaltable.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/commonfiles/reactordata.h"
#include "ms2/commonfiles/sounddatatable.h"
#include "ms2/commonfiles/specialeffectfunctionmanager.h"
#include "ms2/commonfiles/taileffectdatatable.h"
#include "ms2/commonfiles/trafficoptimizer.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/commonfiles/ugcmapsetiteminfo.h"
#include "ms2/guess/usercommandcli.h"
#include "ms2/placeholder/applyeffect.h"
#include "ms2/placeholder/attendgiftdatatable.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/cadbannermanagercli.h"
#include "ms2/placeholder/carcadedatatable.h"
#include "ms2/placeholder/casyncimageloader.h"
#include "ms2/placeholder/cbigdatalogsystem.h"
#include "ms2/placeholder/cblackmarketman.h"
#include "ms2/placeholder/ccashcallmanager.h"
#include "ms2/placeholder/ccashmarketman.h"
#include "ms2/placeholder/cchangejobtable.h"
#include "ms2/placeholder/ccharacterabilitymanager.h"
#include "ms2/placeholder/ccharacterabilitytable.h"
#include "ms2/placeholder/ccontentshutdownmanager.h"
#include "ms2/placeholder/ccoupleemotiontable.h"
#include "ms2/placeholder/cdirwatcher.h"
#include "ms2/placeholder/cdpsmetersystem.h"
#include "ms2/placeholder/cexptable.h"
#include "ms2/placeholder/cfeaturemanager.h"
#include "ms2/placeholder/cfieldmaidmanager.h"
#include "ms2/placeholder/cfieldmissiontable.h"
#include "ms2/placeholder/cfishingtable.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/cgamerule.h"
#include "ms2/placeholder/cgfxlanguage.h"
#include "ms2/placeholder/cgloabalfactor.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/placeholder/cguidemanager.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/placeholder/cignorefile.h"
#include "ms2/placeholder/cindividualarenadatatable.h"
#include "ms2/placeholder/cinstrumentdatatable.h"
#include "ms2/placeholder/citemdatatable.h"
#include "ms2/placeholder/citemenchantlimittable.h"
#include "ms2/placeholder/citemenchanttransformtable.h"
#include "ms2/placeholder/citemenchantutil.h"
#include "ms2/placeholder/citemexchangescrolltable.h"
#include "ms2/placeholder/citemextractiontable.h"
#include "ms2/placeholder/citemgempropertytable.h"
#include "ms2/placeholder/citemgemstonedata.h"
#include "ms2/placeholder/citemlapenshardtable.h"
#include "ms2/placeholder/citemloader.h"
#include "ms2/placeholder/citemmergeoptiontable.h"
#include "ms2/placeholder/citemoptiontable.h"
#include "ms2/placeholder/citemremakescrolltable.h"
#include "ms2/placeholder/citemrepackingscrolltable.h"
#include "ms2/placeholder/citemsocketscrolltable.h"
#include "ms2/placeholder/cjobconditiontable.h"
#include "ms2/placeholder/ckeytable.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/clientlogmanager.h"
#include "ms2/placeholder/cloadingdescriptiontable.h"
#include "ms2/placeholder/cloadingimagetable.h"
#include "ms2/placeholder/cluaclient.h"
#include "ms2/placeholder/cmachineidmanager.h"
#include "ms2/placeholder/cmaiddesctable.h"
#include "ms2/placeholder/cmaidexptable.h"
#include "ms2/placeholder/cmaidinfotable.h"
#include "ms2/placeholder/cmaidmanufacturemsgtable.h"
#include "ms2/placeholder/cmaidrecipegrouptable.h"
#include "ms2/placeholder/cmaidrecipetable.h"
#include "ms2/placeholder/cmanufacturemanager.h"
#include "ms2/placeholder/cmasteryinteriortable.h"
#include "ms2/placeholder/cmasterymanager.h"
#include "ms2/placeholder/cmasterytable.h"
#include "ms2/placeholder/cmenteesearchmanager.h"
#include "ms2/placeholder/cmentoringmanager.h"
#include "ms2/placeholder/cmeratmarketman.h"
#include "ms2/placeholder/cmesomarketman.h"
#include "ms2/placeholder/cmicrogamemanagercli.h"
#include "ms2/placeholder/cnametagsymboltable.h"
#include "ms2/placeholder/cnpsman.h"
#include "ms2/placeholder/commonresource.h"
#include "ms2/placeholder/conlinepatchmanagercli.h"
#include "ms2/placeholder/cooltimemanager.h"
#include "ms2/placeholder/costumesettable.h"
#include "ms2/placeholder/cpceffectdummy.h"
#include "ms2/placeholder/cpetdatatable.h"
#include "ms2/placeholder/cpetmanager.h"
#include "ms2/placeholder/cpopupprofileimageman.h"
#include "ms2/placeholder/cpricetable.h"
#include "ms2/placeholder/cpvpmanager.h"
#include "ms2/placeholder/cquestmasktable.h"
#include "ms2/placeholder/cquestnavigationmap.h"
#include "ms2/placeholder/cquestnavigator.h"
#include "ms2/placeholder/cquesttable.h"
#include "ms2/placeholder/crankingarenadatatable.h"
#include "ms2/placeholder/crankviewer.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/placeholder/crewardpreviewtable.h"
#include "ms2/placeholder/cscripttable.h"
#include "ms2/placeholder/cseasondatatable.h"
#include "ms2/placeholder/cserverstring.h"
#include "ms2/placeholder/cshopeventmanager.h"
#include "ms2/placeholder/cskillcompactcontroltable.h"
#include "ms2/placeholder/cskillsettable.h"
#include "ms2/placeholder/csmartpushmanager.h"
#include "ms2/placeholder/csmartpushtable.h"
#include "ms2/placeholder/csmartrecommendshoptable.h"
#include "ms2/placeholder/csoapclient.h"
#include "ms2/placeholder/cspecialdungeondatatable.h"
#include "ms2/placeholder/cstorybooktable.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ctaximanager.h"
#include "ms2/placeholder/ctitletable.h"
#include "ms2/placeholder/cugcdesigntable.h"
#include "ms2/placeholder/cugcdownloaddown.h"
#include "ms2/placeholder/cugcdownloadload.h"
#include "ms2/placeholder/cugcgetcosttable.h"
#include "ms2/placeholder/cugcmanager.h"
#include "ms2/placeholder/cusereventmanager.h"
#include "ms2/placeholder/cusermaidmanager.h"
#include "ms2/placeholder/cviptable.h"
#include "ms2/placeholder/dungeonmissiondatatable.h"
#include "ms2/placeholder/dungeonroomtable.h"
#include "ms2/placeholder/fieldwardatatable.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/gamedictionarymanager.h"
#include "ms2/placeholder/gameeventmanagercli.h"
#include "ms2/placeholder/gameeventuservaluemanager.h"
#include "ms2/placeholder/gamerankingcli.h"
#include "ms2/placeholder/itemdroptable.h"
#include "ms2/placeholder/itempreviewmgr.h"
#include "ms2/placeholder/jobtable.h"
#include "ms2/placeholder/loginbgbgmtable.h"
#include "ms2/placeholder/mentoringdatatable.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/npcdatatablecli.h"
#include "ms2/placeholder/oncecallbacktimer.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/paybackmanagerclient.h"
#include "ms2/placeholder/paybacktable.h"
#include "ms2/placeholder/pcactiondatatable.h"
#include "ms2/placeholder/recodemgr.h"
#include "ms2/placeholder/rewardcontentstable.h"
#include "ms2/placeholder/setitemtable.h"
#include "ms2/placeholder/skilldatatablecli.h"
#include "ms2/placeholder/soundpropertymgr.h"
#include "ms2/placeholder/stancetable.h"
#include "ms2/placeholder/stringmanager.h"
#include "ms2/placeholder/termtagmanagercli.h"
#include "ms2/placeholder/ugchomeoptiondata.h"
#include "ms2/placeholder/uibottomcenteralignmanager.h"
#include "ms2/placeholder/uibuddyeventdispatcher.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#include "ms2/placeholder/uientityeventdispatcher.h"
#include "ms2/placeholder/uiservereventdispatcher.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/placeholder/uiworldshareinfoeventdispatcher.h"
#include "ms2/placeholder/webguidetable.h"
#include "ms2/placeholder/weddingemotiontable.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/worldmapmanager.h"
#include "ms2/unnamed/unit_1406125d0.h"
#include "ms2/unnamed/unit_140ad1860.h"

// The create-or-get step InitInstance runs for every manager singleton: the live instance if one exists, else a new
// one (its ctor registers it). One COMDAT per T (0x141498d90-0x14149fc10, sorted by T); the name is invented.
template <class T>
class Unk_SingletonCreator
{
public:
    static T* CreateInstance() { return TSingleton<T>::s_instance ? TSingleton<T>::GetInstance() : new T; }
};

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

// Unk_1401cd100 (ctor 0x1401cd100) comes from cubemapinformationservice_3.h.

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
CNetworkService* FUN_140714f90();
COptimizer* FUN_1409f7c90();
void FUN_14161c360(COptimizer* pOptimizer);
class Unk_Ms2PhysXHelper;
Unk_Ms2PhysXHelper* FUN_1409f7ca0();
void FUN_1414a2a10();                                           // TSingleton delete of FUN_1409f7ca0()
void FUN_1414a3f10();                                           // TSingleton delete of CrashManagerCli::GetInstance()
void FUN_140cca840(int n);                                      // crash on purpose (the /crash command)
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
int FUN_1414a5a40(CStringW sPath);                              // _wmkdir
// Clears a ServiceManager flag (+0x119) before the shutdown request: an MS2 engine addition missing from the SDK
// headers (the exe calls it through SmartPointer::operator->).
void FUN_1414a6180(efd::ServiceManager* pServiceManager);
efd::utf8string MakeWindowTitle();
namespace Scaleform { namespace Render { class Image; class TextureManager; } }
typedef TFunctor<Scaleform::Render::Image*, ParamList<const GFxImageLoader::Protocol&,
    ParamList<Scaleform::Render::TextureManager*, EmptyParam>>> Unk_GFxImageCallback;
// The Scaleform UI manager singleton (no RTTI; DAT_143aaccf8).
class Unk_GFxManager
{
public:
    void FUN_1422af0b0(BOOL bArchive, int n);                  // loads ./Data/Resource/gfx/fontconfig.txt
    void FUN_1414a61c0(Unk_GFxImageCallback fnCallback);        // the image creator callback (+0x138)
};
Unk_GFxManager* FUN_14025e7a0();
Scaleform::Render::Image* FUN_140a59830(const GFxImageLoader::Protocol& kProtocol,
    Scaleform::Render::TextureManager* pTextureManager);       // ?\asyncimageloader.cpp
int FUN_1406516b0();                                            // the service locale: 1 jp, 2 en, 3 cn, else kr
CString FUN_140652330(int nLocale);                             // the locale's UI font name
void FUN_1414a6230(efd::IBase* (*pfnFactory)());                // the KFM cache factory of egmAnimation
efd::IBase* FUN_1414a9a10();                                    // creates an MS2KFMCache
struct Unk_MCPPtr;
Unk_MCPPtr FUN_140d96230(NiVisibleArray* pVisibleSet, NiSPWorkflowManager* pWorkflowManager);  // MS2MeshCullingProcess
extern Unk_MCPPtr (*DAT_143afe6f8)(NiVisibleArray*, NiSPWorkflowManager*);   // the mesh culling process factory
extern void (*DAT_143b0d368)();
int luaopen_egmAnimation(lua_State* L);
int luaopen_ecr(lua_State* L);
int luaopen_bapiPhysXBase(lua_State* L);
int luaopen_PhysX(lua_State* L);

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
    if (CrashManagerCli::GetInstance())
        CrashManagerCli::GetInstance()->FUN_1401ce420();
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
    if (CrashManagerCli::GetInstance())
        FUN_1414a3f10();
}
// @0x14148b340
bool MS2::OnLostDevice(void* pvData)
{
    RecodeMgr::GetInstance()->FUN_140c9bc00();
    return true;
}
MS2_REPLACE(0x14148B340, MS2::OnLostDevice, 29, 0x4B7A9898);
// @0x14148b370
bool MS2::RegisterServices(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    bool bResult = true;
    m_spServiceManager = EE_NEW efd::ServiceManager;
    if (!m_spServiceManager)
        return false;
    m_spServiceManager->SetProgramType(efd::ServiceManager::kProgType_Client, true);
    m_spServiceManager->SetVirtualProcessName("MapleStory2");

    efd::IConfigManagerPtr spConfig = EE_NEW efd::ConfigManager("Config.ini", __argc, __argv);
    m_spServiceManager->RegisterSystemService(spConfig);
    efd::SmartPointer<efd::EnumManager> spEnumManager = NULL;
    CreateLogger()->ReadConfig(spConfig, spEnumManager, false);

    efd::SmartPointer<CMainSystem> spMainSystem = EE_NEW CMainSystem;
    spMainSystem->FUN_141473920(GetCurrentThreadId());
    spMainSystem->FUN_141472eb0(spConfig);
    m_spServiceManager->RegisterSystemService(spMainSystem, 9999);

    efd::MessageServicePtr spMessageService = EE_NEW MS2MessageService;
    spMessageService->SetOfflineMode(true);
    m_spServiceManager->RegisterSystemService(spMessageService);

    efd::SmartPointer<egf::RapidIterationSystemService> spRapidIteration = EE_NEW egf::RapidIterationSystemService;
    m_spServiceManager->RegisterSystemService(spRapidIteration);

    efd::utf8string strUrn("urn:kr");
    switch (FUN_1406516b0()) {
    case 1:
        strUrn = "urn:jp";
        break;
    case 2:
        strUrn = "urn:en";
        break;
    case 3:
        strUrn = "urn:cn";
        break;
    default:
        strUrn = "urn:kr";
        break;
    }
    efd::SmartPointer<efd::AssetLocatorService> spAssetLocator = EE_NEW efd::AssetLocatorService(m_spServiceManager, strUrn);
    m_spServiceManager->RegisterSystemService(spAssetLocator);
    efd::SmartPointer<efd::AssetFactoryManager> spAssetFactory = EE_NEW efd::AssetFactoryManager(0x10, 8, NULL);
    m_spServiceManager->RegisterSystemService(spAssetFactory);

    efd::SmartPointer<egf::EntityManager> spEntityManager = EE_NEW MS2EntityManagerService;
    m_spServiceManager->RegisterSystemService(spEntityManager);
    egf::SchedulerPtr spScheduler = EE_NEW egf::Scheduler;
    m_spServiceManager->RegisterSystemService(spScheduler);
    efd::SmartPointer<egf::SchedulerLua> spSchedulerLua = EE_NEW egf::SchedulerLua;
    spScheduler->RegisterScriptingRuntime("Lua", egf::BehaviorType_Lua, spSchedulerLua);
    bool bLua = false;
    bLua = spSchedulerLua->AddStaticBuiltinInitFunction(luaopen_egmAnimation);
    bLua &= spSchedulerLua->AddStaticBuiltinInitFunction(luaopen_ecr);
    bLua &= spSchedulerLua->AddStaticBuiltinInitFunction(luaopen_bapiPhysXBase);
    bLua &= spSchedulerLua->AddStaticBuiltinInitFunction(luaopen_PhysX);

    efd::SmartPointer<egf::FlatModelManager> spFlatModelManager = EE_NEW MS2FlatModelManager;
    spFlatModelManager->SetModelPath((const char*)CMainSystem::GetInstance()->FUN_1414736e0());
    m_spServiceManager->RegisterSystemService(spFlatModelManager);
    efd::SmartPointer<egf::EntityLoaderService> spEntityLoader = EE_NEW MS2EntityLoaderService;
    m_spServiceManager->RegisterSystemService(spEntityLoader);

    NiPointer<NiTexturePalette> spTexturePalette = EE_NEW MS2DefaultTexturePalette;
    CNiStreamLoadThread::GetInstance()->SetTexturePalette(spTexturePalette);
    NiSPWorkflowManager* pWorkflowManager = EE_NEW NiSPWorkflowManager(0x40, NiStreamProcessor::MEDIUM, 3);
    ecr::SceneGraphServicePtr spSceneGraph = EE_NEW MS2SceneGraphService(pWorkflowManager, spTexturePalette, false);
    spSceneGraph->SetDataPath(CMainSystem::GetInstance()->FUN_1414736e0());
    m_spServiceManager->RegisterSystemService(spSceneGraph, 1500);

    DAT_143afe6f8 = FUN_140d96230;
    ecr::RenderServicePtr spRender = EE_NEW MS2RenderService(0);
    m_pSurfaceCreator = new CMS2DefaultSurfaceCreator;
    spRender->SetDefaultSurfaceCreator(m_pSurfaceCreator);
    m_spServiceManager->RegisterSystemService(spRender, 1000);
    efd::SmartPointer<ecr::ShaderService> spShader = EE_NEW ecr::ShaderService(true);
    m_spServiceManager->RegisterSystemService(spShader);
    efd::SmartPointer<ecr::LightService> spLight = EE_NEW MS2LightService;
    m_spServiceManager->RegisterSystemService(spLight);
    efd::SmartPointer<ecr::TextureRapidIterationService> spTextureRapidIteration = EE_NEW ecr::TextureRapidIterationService;
    if (FUN_1409f7c90()->FUN_1414a5a30())
        FUN_1414a6230(FUN_1414a9a10);
    efd::SmartPointer<egmAnimation::AnimationService> spAnimation = EE_NEW MS2AnimationService;
    m_spServiceManager->RegisterSystemService(spAnimation, 1785);
    efd::SmartPointer<ecr::CameraService> spCamera = EE_NEW MS2CameraService;
    m_spServiceManager->RegisterSystemService(spCamera);
    efd::SmartPointer<ecrInput::InputService> spInput = EE_NEW MS2InputService;
    m_spServiceManager->RegisterSystemService(spInput);

    efd::SmartPointer<CWindowService> spWindow = EE_NEW CWindowService(hInstance, hPrevInstance, lpCmdLine, 1);
    efd::utf8string strTitle = MakeWindowTitle();
    spWindow->SetWindowTitle(strTitle);
    spWindow->SetWindowClass("MapleStory2");
    m_spServiceManager->RegisterSystemService(spWindow);

    bool bSyncPhysX = true;
    m_pPhysXManager->Configure(spConfig);
    efd::SmartPointer<MS2SceneService> spScene = EE_NEW MS2SceneService;
    m_spServiceManager->RegisterSystemService(spScene);
    efd::SmartPointer<MS2PropService> spProp = EE_NEW MS2PropService;
    spProp->SetAsynchronousSimulation(!bSyncPhysX);
    spProp->FUN_142064e10(spSceneGraph->GetSceneGraphCache());
    m_spServiceManager->RegisterSystemService(spProp);
    efd::SmartPointer<egmPhysXWhitebox::PhysXWhiteboxService> spWhitebox = EE_NEW egmPhysXWhitebox::PhysXWhiteboxService;
    m_spServiceManager->RegisterSystemService(spWhitebox);
    efd::SmartPointer<egmVisualTracker::VisualTrackerService> spVisualTracker = EE_NEW MS2VisualTrackerManager;
    m_spServiceManager->RegisterSystemService(spVisualTracker);

    efd::SmartPointer<WorldService> spWorld = EE_NEW WorldService;
    m_spServiceManager->RegisterSystemService(spWorld, 2001);
    efd::SmartPointer<CNifAnimationService> spNifAnimation = EE_NEW CNifAnimationService;
    m_spServiceManager->RegisterSystemService(spNifAnimation, 2001);
    efd::SmartPointer<CTriggerService> spTrigger = EE_NEW CTriggerService;
    m_spServiceManager->RegisterSystemService(spTrigger, 2001);
    efd::SmartPointer<CFunctionCubeService> spFunctionCube = EE_NEW CFunctionCubeService;
    m_spServiceManager->RegisterSystemService(spFunctionCube, 2001);
    efd::SmartPointer<CItemService> spItem = EE_NEW CItemService;
    m_spServiceManager->RegisterSystemService(spItem, 2001);
    m_spServiceManager->RegisterSystemService(this, 10000);

    efd::SmartPointer<PostProcessingService> spPostProcessing = EE_NEW PostProcessingService;
    m_spServiceManager->RegisterSystemService(spPostProcessing, 1998);
    efd::SmartPointer<CUIService> spUI = EE_NEW CUIService;
    m_spServiceManager->RegisterSystemService(spUI, 1997);
    efd::SmartPointer<CStateService> spState = EE_NEW CStateService;
    m_spServiceManager->RegisterSystemService(spState, 1996);
    efd::SmartPointer<CNetworkService> spNetwork = EE_NEW CNetworkService;
    m_spServiceManager->RegisterSystemService(spNetwork, 1995);
    efd::SmartPointer<CMagicService> spMagic = EE_NEW CMagicService;
    m_spServiceManager->RegisterSystemService(spMagic);
    efd::SmartPointer<CEffectService> spEffect = EE_NEW CEffectService;
    m_spServiceManager->RegisterSystemService(spEffect);
    efd::SmartPointer<CSoundService> spSound = EE_NEW CSoundService;
    m_spServiceManager->RegisterSystemService(spSound);
    efd::SmartPointer<ecr::PickService> spPick = EE_NEW MS2PickService();
    m_spServiceManager->RegisterSystemService(spPick);
    efd::SmartPointer<CNifLoadingService> spNifLoading = EE_NEW CNifLoadingService;
    m_spServiceManager->RegisterSystemService(spNifLoading);
    efd::SmartPointer<HardwareInstancingService> spHardwareInstancing = EE_NEW HardwareInstancingService;
    m_spServiceManager->RegisterSystemService(spHardwareInstancing);
    efd::SmartPointer<EntityWorldManager> spEntityWorld = EE_NEW EntityWorldManager;
    m_spServiceManager->RegisterSystemService(spEntityWorld);
    efd::SmartPointer<CubeMapInformationService> spCubeMapInformation = EE_NEW CubeMapInformationService;
    m_spServiceManager->RegisterSystemService(spCubeMapInformation);

    m_spServiceManager->RegisterSystemService(EE_NEW GFxService, 1997);
    m_spServiceManager->RegisterSystemService(EE_NEW GFxSceneService, 1997);
    DAT_143b0d368 = CUIService::FUN_141ade400;
    FUN_1414a56c0()->FUN_1422ea230(FUN_140652330(DAT_143ab0248));
    efd::SmartPointer<CWebBrowserService> spWebBrowser = EE_NEW CWebBrowserService(hInstance);
    spWebBrowser->FUN_141b77e10();
    m_spServiceManager->RegisterSystemService(spWebBrowser);
    efd::SmartPointer<MS2PropertyVisualizationService> spPropertyVisualization = EE_NEW MS2PropertyVisualizationService();
    m_spServiceManager->RegisterSystemService(spPropertyVisualization);

    int n = 0;
    FUN_14025e7a0()->FUN_1422af0b0(FUN_140166420()->FUN_140398190(), n);
    FUN_14025e7a0()->FUN_1414a61c0(Unk_GFxImageCallback(FUN_140a59830));
    RegisterUIScenes();
    efd::SmartPointer<DecoEditService> spDecoEdit = EE_NEW DecoEditService;
    m_spServiceManager->RegisterSystemService(spDecoEdit, 0x6100014);
    efdPhysX::PhysXSDKManager* pPhysXManager = efdPhysX::PhysXSDKManager::GetManager();
    pPhysXManager->m_pPhysXSDK->setParameter(NX_BOUNCE_THRESHOLD, -10.0f);
    return bResult;
}
MS2_REPLACE_METHOD(0x14148B370, MS2, RegisterServices, 13544, 0x09D796FF);
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
    CGameOption::GetInstance()->FUN_141243850();
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
    CGameOption::GetInstance()->FUN_141243860();
    NiDX9Renderer* pkRenderer = NiDynamicCast(NiDX9Renderer, NiRenderer::GetRenderer());
    if (pkRenderer)
        pkRenderer->AddLostDeviceNotificationFunc(OnLostDevice, this);
    return efd::AsyncResult_Complete;
}
MS2_REPLACE_METHOD(0x14148EE00, MS2, OnInit, 880, 0x26CD498D);
// @0x14148f180
efd::AsyncResult MS2::OnTick()
{
    CGameOption::GetInstance()->FUN_1412438d0();
    if (CAsyncImageLoader::GetInstance())
        CAsyncImageLoader::GetInstance()->FUN_140a58b90();
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x14148F180, MS2, OnTick, 55, 0xFB1E44E9);
// @0x14148f1c0
efd::AsyncResult MS2::OnShutdown()
{
    RecodeMgr::GetInstance()->FUN_140c9bc00();
    RecodeMgr::GetInstance()->FUN_140c9bb20();
    if (CAsyncImageLoader::GetInstance())
        CAsyncImageLoader::GetInstance()->FUN_140a58b10();
    efd::AsyncResult eResult = efd::AsyncResult_Complete;
    CGameOption::GetInstance()->FUN_1412438e0();
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
    CString strServer = StringFormat(" - S:{0}, {1}", CFeatureManager::GetInstance()->FUN_14036d8b0(), CFeatureManager::GetInstance()->FUN_14036d8e0());
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

template class Unk_SingletonCreator<AnimationCallbackManager>;
template class Unk_SingletonCreator<ApplyEffect>;
template class Unk_SingletonCreator<AttendGiftDataTable>;
template class Unk_SingletonCreator<BGTransparencyMgr>;
template class Unk_SingletonCreator<BlindManager>;
template class Unk_SingletonCreator<CAchieveManager>;
template class Unk_SingletonCreator<CAdBannerManagerCli>;
template class Unk_SingletonCreator<CAdventureLevelTable>;
template class Unk_SingletonCreator<CAdventureLevelTableHelper>;
template class Unk_SingletonCreator<CArcadeDataTable>;
template class Unk_SingletonCreator<CAsyncImageLoader>;
template class Unk_SingletonCreator<CAutoFindTaxiStation>;
template class Unk_SingletonCreator<CBankTable>;
template class Unk_SingletonCreator<CBattleRecordManager>;
template class Unk_SingletonCreator<CBigDataLogSystem>;
template class Unk_SingletonCreator<CBlackMarketMan>;
template class Unk_SingletonCreator<CBlockManager>;
template class Unk_SingletonCreator<CBuddyManager>;
template class Unk_SingletonCreator<CCashCallManager>;
template class Unk_SingletonCreator<CCashMarketMan>;
template class Unk_SingletonCreator<CChangeJobTable>;
template class Unk_SingletonCreator<CChapterBookTable>;
template class Unk_SingletonCreator<CCharacterAbilityManager>;
template class Unk_SingletonCreator<CCharacterAbilityTable>;
template class Unk_SingletonCreator<CChatEmoticonTable>;
template class Unk_SingletonCreator<CClubClientManager>;
template class Unk_SingletonCreator<CClubDataTable>;
template class Unk_SingletonCreator<CContentShutdownManager>;
template class Unk_SingletonCreator<CContinentRegionTable>;
template class Unk_SingletonCreator<CCoupleEmotionTable>;
template class Unk_SingletonCreator<CDPSMeterSystem>;
template class Unk_SingletonCreator<CDirWatcher>;
template class Unk_SingletonCreator<CDynamicBanWordManager>;
template class Unk_SingletonCreator<CEnchantScrollTable>;
template class Unk_SingletonCreator<CExpTable>;
template class Unk_SingletonCreator<CFameTable>;
template class Unk_SingletonCreator<CFeatureManager>;
template class Unk_SingletonCreator<CFieldMaidManager>;
template class Unk_SingletonCreator<CFieldMetaTable>;
template class Unk_SingletonCreator<CFieldMissionTable>;
template class Unk_SingletonCreator<CFilePreload>;
template class Unk_SingletonCreator<CFileSystem>;
template class Unk_SingletonCreator<CFishingManager>;
template class Unk_SingletonCreator<CFishingTable>;
template class Unk_SingletonCreator<CGFxLanguage>;
template class Unk_SingletonCreator<CGameEventValueManager>;
template class Unk_SingletonCreator<CGameOption>;
template class Unk_SingletonCreator<CGameRankingCli>;
template class Unk_SingletonCreator<CGameRule>;
template class Unk_SingletonCreator<CGloabalFactor>;
template class Unk_SingletonCreator<CGraphicOptionTable>;
template class Unk_SingletonCreator<CGroupChatManager>;
template class Unk_SingletonCreator<CGuideManager>;
template class Unk_SingletonCreator<CGuildManager>;
template class Unk_SingletonCreator<CGuildXmlData>;
template class Unk_SingletonCreator<CIgnoreFile>;
template class Unk_SingletonCreator<CIndividualArenaDataTable>;
template class Unk_SingletonCreator<CInstrumentDataTable>;
template class Unk_SingletonCreator<CItemBreakIngredientTable>;
template class Unk_SingletonCreator<CItemBreakManager>;
template class Unk_SingletonCreator<CItemDataTable>;
template class Unk_SingletonCreator<CItemEnchantLimitTable>;
template class Unk_SingletonCreator<CItemEnchantTransformTable>;
template class Unk_SingletonCreator<CItemEnchantUtil>;
template class Unk_SingletonCreator<CItemExchangeScrollTable>;
template class Unk_SingletonCreator<CItemExtractionTable>;
template class Unk_SingletonCreator<CItemGemPropertyTable>;
template class Unk_SingletonCreator<CItemGemStoneUpgradeTable>;
template class Unk_SingletonCreator<CItemLapenshardTable>;
template class Unk_SingletonCreator<CItemLoader>;
template class Unk_SingletonCreator<CItemLockManager>;
template class Unk_SingletonCreator<CItemMergeOptionTable>;
template class Unk_SingletonCreator<CItemOptionTable>;
template class Unk_SingletonCreator<CItemRePackingScrollTable>;
template class Unk_SingletonCreator<CItemRemakeScrollTable>;
template class Unk_SingletonCreator<CItemSocketScrollTable>;
template class Unk_SingletonCreator<CItemSocketTable>;
template class Unk_SingletonCreator<CJobConditionTable>;
template class Unk_SingletonCreator<CKeyTable>;
template class Unk_SingletonCreator<CLoadingDescriptionTable>;
template class Unk_SingletonCreator<CLoadingImageTable>;
template class Unk_SingletonCreator<CLocaleLanguage>;
template class Unk_SingletonCreator<CLogString>;
template class Unk_SingletonCreator<CLuaClient>;
template class Unk_SingletonCreator<CMachineIDManager>;
template class Unk_SingletonCreator<CMaidDescTable>;
template class Unk_SingletonCreator<CMaidExpTable>;
template class Unk_SingletonCreator<CMaidInfoTable>;
template class Unk_SingletonCreator<CMaidManufactureMsgTable>;
template class Unk_SingletonCreator<CMaidRecipeGroupTable>;
template class Unk_SingletonCreator<CMaidRecipeTable>;
template class Unk_SingletonCreator<CManufactureManager>;
template class Unk_SingletonCreator<CMasteryInteriorTable>;
template class Unk_SingletonCreator<CMasteryManager>;
template class Unk_SingletonCreator<CMasteryTable>;
template class Unk_SingletonCreator<CMenteeSearchManager>;
template class Unk_SingletonCreator<CMentoringManager>;
template class Unk_SingletonCreator<CMeratMarketMan>;
template class Unk_SingletonCreator<CMesoMarketMan>;
template class Unk_SingletonCreator<CMicroGameManagerCli>;
template class Unk_SingletonCreator<CMouseController>;
template class Unk_SingletonCreator<CNPSMan>;
template class Unk_SingletonCreator<CNametagSymbolTable>;
template class Unk_SingletonCreator<CNiStreamLoadThread>;
template class Unk_SingletonCreator<COSInfo>;
template class Unk_SingletonCreator<COnlinePatchManagerCli>;
template class Unk_SingletonCreator<COptimizer>;
template class Unk_SingletonCreator<CPCEffectDummy>;
template class Unk_SingletonCreator<CPVPManager>;
template class Unk_SingletonCreator<CPartyManager>;
template class Unk_SingletonCreator<CPetDataTable>;
template class Unk_SingletonCreator<CPetManager>;
template class Unk_SingletonCreator<CPopupProfileImageMan>;
template class Unk_SingletonCreator<CPortalTable>;
template class Unk_SingletonCreator<CPriceTable>;
template class Unk_SingletonCreator<CQuestManager>;
template class Unk_SingletonCreator<CQuestMaskTable>;
template class Unk_SingletonCreator<CQuestNavigationMap>;
template class Unk_SingletonCreator<CQuestNavigator>;
template class Unk_SingletonCreator<CQuestTable>;
template class Unk_SingletonCreator<CRankViewer>;
template class Unk_SingletonCreator<CRankingArenaDataTable>;
template class Unk_SingletonCreator<CReactorDataTable>;
template class Unk_SingletonCreator<CReconnectionManagerCli>;
template class Unk_SingletonCreator<CReservedWordTable>;
template class Unk_SingletonCreator<CRewardPreviewTable>;
template class Unk_SingletonCreator<CScriptTable>;
template class Unk_SingletonCreator<CSeasonDataTable>;
template class Unk_SingletonCreator<CServerListTable>;
template class Unk_SingletonCreator<CServerString>;
template class Unk_SingletonCreator<CShopEventManager>;
template class Unk_SingletonCreator<CSkillCompactControlTable>;
template class Unk_SingletonCreator<CSkillSetTable>;
template class Unk_SingletonCreator<CSmartPushManager>;
template class Unk_SingletonCreator<CSmartPushTable>;
template class Unk_SingletonCreator<CSmartRecommendShopTable>;
template class Unk_SingletonCreator<CSoapClient>;
template class Unk_SingletonCreator<CSoundDataTable>;
template class Unk_SingletonCreator<CSoundEventMgr>;
template class Unk_SingletonCreator<CSpecialDungeonDataTable>;
template class Unk_SingletonCreator<CSpecialEffectFunctionManager>;
template class Unk_SingletonCreator<CStoryBookTable>;
template class Unk_SingletonCreator<CStringTable>;
template class Unk_SingletonCreator<CTailEffectDataTable>;
template class Unk_SingletonCreator<CTaxiManager>;
template class Unk_SingletonCreator<CTitleTable>;
template class Unk_SingletonCreator<CTradeManagerEx>;
template class Unk_SingletonCreator<CTrafficOptimizer>;
template class Unk_SingletonCreator<CUGCDesignTable>;
template class Unk_SingletonCreator<CUGCMapSetItemTable>;
template class Unk_SingletonCreator<CUgcDownloadDown>;
template class Unk_SingletonCreator<CUgcDownloadLoad>;
template class Unk_SingletonCreator<CUgcGetCostTable>;
template class Unk_SingletonCreator<CUgcManager>;
template class Unk_SingletonCreator<CUserCommandCli>;
template class Unk_SingletonCreator<CUserEventManager>;
template class Unk_SingletonCreator<CUserMaidManager>;
template class Unk_SingletonCreator<CVIPTable>;
template class Unk_SingletonCreator<CameraMgr>;
template class Unk_SingletonCreator<ClientLogManager>;
template class Unk_SingletonCreator<CommonEffectDummy>;
template class Unk_SingletonCreator<CommonResource>;
template class Unk_SingletonCreator<CommonString>;
template class Unk_SingletonCreator<Client::Constants>;
template class Unk_SingletonCreator<CooltimeManager>;
template class Unk_SingletonCreator<CostumeSetTable>;
template class Unk_SingletonCreator<CrashManagerCli>;
template class Unk_SingletonCreator<CubeHolderManager>;
template class Unk_SingletonCreator<DungeonMissionDataTable>;
template class Unk_SingletonCreator<DungeonRoomTable>;
template class Unk_SingletonCreator<EffectDataManager>;
template class Unk_SingletonCreator<EffectSkipMgr>;
template class Unk_SingletonCreator<EngineLog>;
template class Unk_SingletonCreator<FieldWarDataTable>;
template class Unk_SingletonCreator<GPUManager>;
template class Unk_SingletonCreator<GameDictionaryManager>;
template class Unk_SingletonCreator<GameEventManagerCli>;
template class Unk_SingletonCreator<GameEventUserValueManager>;
template class Unk_SingletonCreator<HomeBlockManager>;
template class Unk_SingletonCreator<ItemDropTable>;
template class Unk_SingletonCreator<ItemGachaBoxTable>;
template class Unk_SingletonCreator<ItemPreviewMgr>;
template class Unk_SingletonCreator<JobTable>;
template class Unk_SingletonCreator<LoginBgBgmTable>;
template class Unk_SingletonCreator<MentoringDataTable>;
template class Unk_SingletonCreator<MultiSceneUpdater>;
template class Unk_SingletonCreator<NotifySystem>;
template class Unk_SingletonCreator<NpcDataTableCli>;
template class Unk_SingletonCreator<OnceCallbackTimer>;
template class Unk_SingletonCreator<PCActionDataTable>;
template class Unk_SingletonCreator<PacketHandlerManager>;
template class Unk_SingletonCreator<PaybackManagerClient>;
template class Unk_SingletonCreator<PaybackTable>;
template class Unk_SingletonCreator<QuestDataTable>;
template class Unk_SingletonCreator<RecodeMgr>;
template class Unk_SingletonCreator<RewardContentsTable>;
template class Unk_SingletonCreator<SetItemTable>;
template class Unk_SingletonCreator<SkillDataTableCli>;
template class Unk_SingletonCreator<SoundPropertyMgr>;
template class Unk_SingletonCreator<StanceTable>;
template class Unk_SingletonCreator<StateEffectMgr>;
template class Unk_SingletonCreator<StringManager>;
template class Unk_SingletonCreator<TermTagManagerCli>;
template class Unk_SingletonCreator<UGCCubeCategoryTable>;
template class Unk_SingletonCreator<UIBottomCenterAlignManager>;
template class Unk_SingletonCreator<UIBuddyEventDispatcher>;
template class Unk_SingletonCreator<UIDialogEventDispatcher>;
template class Unk_SingletonCreator<UIDungeonCategoryTable>;
template class Unk_SingletonCreator<UIEntityEventDispatcher>;
template class Unk_SingletonCreator<UIItemEventDispatcher>;
template class Unk_SingletonCreator<UIQuestEventDispatcher>;
template class Unk_SingletonCreator<UIServerEventDispatcher>;
template class Unk_SingletonCreator<UIStatusEventDispatcher>;
template class Unk_SingletonCreator<UITalkManager>;
template class Unk_SingletonCreator<UIUGCEventDispatcher>;
template class Unk_SingletonCreator<UIWorldShareInfoEventDispatcher>;
template class Unk_SingletonCreator<UgcHomeOptionData>;
template class Unk_SingletonCreator<WebGuideTable>;
template class Unk_SingletonCreator<WeddingEmotionTable>;
template class Unk_SingletonCreator<WeddingManager>;
template class Unk_SingletonCreator<WeddingTable>;
template class Unk_SingletonCreator<WorldMapManager>;
