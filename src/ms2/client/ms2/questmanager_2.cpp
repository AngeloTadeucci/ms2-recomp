// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest manager object.
// MS2-UNIT: client\ms2\questmanager.cpp#2
// MS2-RANGE: 0x1416c7fd0-0x1416e3800 .text$mn
// MS2-RANGE: 0x1400fe8a0-0x1400feaa0 .text$di
// MS2-RANGE: 0x142cb5990-0x142cb5aa0 .text$yd
// MS2-PIN: ?FUN_1416d2910@CQuestManager@@QEAAHIAEAV?$list@V?$list@IV?$allocator@I@std@@@std@@V?$allocator@V?$list@IV?$allocator@I@std@@@std@@@2@@std@@H@Z 0x1416d2910
// MS2-PIN: ??0<lambda_6d510819a8f69a3a4b14e1326e882a6b>@@QEAA@I@Z 0x1416dbb80
// MS2-PIN: ??R<lambda_6d510819a8f69a3a4b14e1326e882a6b>@@QEBA_NAEBUUnk_QmNpcQuestEntry@@0@Z 0x1416dcda0
// MS2-PIN: ??R<lambda_ffd9fd9b7ed9f8dca7c54b6016c3fa67>@@QEBAXV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x1416dcb40
// MS2-PIN: ??R<lambda_bff28b45a42954530307e5b624f5a235>@@QEBAXAEBV?$list@IV?$allocator@I@std@@@std@@@Z 0x1416dcb90
// MS2-PIN: ??R<lambda_832e90266cbc1c25f66c2f4ce9c7fe9e>@@QEBAXH@Z 0x1416dcd40
// MS2-PIN: ??0<lambda_832e90266cbc1c25f66c2f4ce9c7fe9e>@@QEAA@AEAV?$list@IV?$allocator@I@std@@@std@@AEAV?$list@V?$list@IV?$allocator@I@std@@@std@@V?$allocator@V?$list@IV?$allocator@I@std@@@std@@@2@@2@AEBQEAV32@@Z 0x1416dad60
// MS2-PIN: ??0<lambda_ffd9fd9b7ed9f8dca7c54b6016c3fa67>@@QEAA@AEBH@Z 0x1416dad20
// MS2-PIN: ??0<lambda_bff28b45a42954530307e5b624f5a235>@@QEAA@AEBH@Z 0x1416dad40
// MS2-PIN: ??_7CQuestManager@@6B?$TSingleton@VCQuestManager@@@@@ 0x142f57498
// MS2-PIN: ??R<lambda_ec77cf7c45e6dcfdc158975356cf22e0>@@QEBA_NH@Z 0x1416dcd00
// MS2-PIN: ?FUN_1416cb4d0@CQuestManager@@QEAAXAEAV?$vector@IV?$allocator@I@std@@@std@@V?$vector@HV?$allocator@H@std@@@3@HH@Z 0x1416cb4d0
// MS2-PIN: ?_Unchecked_begin@?$vector@IV?$allocator@I@std@@@std@@QEBAPEBIXZ 0x1416e1dd0
// MS2-PIN: ?_Unchecked_end@?$vector@IV?$allocator@I@std@@@std@@QEBAPEBIXZ 0x1416e1e70
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "questmanager_2.h"
#include "questmanager_1.h"
#include "pcbase.h"
#include "guildmanager.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "worldservice.h"
#include "statemanager.h"
#include "achievemanager.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/notifychange.h"
#include "ms2/placeholder/questkinds.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/learningquesttable.h"
#include "ms2/commonfiles/chapterbooktable.h"
#include "ms2/commonfiles/contentshutdown.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/cequipitem.h"

// These instances belong to earlier objects, not the look-alike destructors
// for other quest pointer types in this object's COMDAT tail.
template<> Unk_PayloadPtr<CQuest>::~Unk_PayloadPtr();
template<> bool Unk_PayloadPtr<CQuest>::IsNull() const;
template<> ATL::CAtlArray<unsigned>::CAtlArray() throw();
template<> ATL::CAtlArray<unsigned>::~CAtlArray() throw();
template<> size_t ATL::CAtlArray<unsigned>::GetCount() const throw();


static UICommon::CMyPCKeyInputController s_keyController;
static CString s_completeSound = "quest_complete";
static CString s_progressSound = "quest_progress";

// External services use declarations until their classes are recovered.
CAchieveManager* FUN_1406c7600();
void FUN_140936640(void*, int, int);
// The npc talk manager.
class Unk_QmTalkManager {
public:
    int FUN_141b213f0(class Unk_QmTalkScriptPtr script, int npcId, int mode, int n);   // open the talk
};
Unk_QmTalkManager* FUN_140967100();
void FUN_141b217e0(void*, int);
void* FUN_140d738f0();
int FUN_14037c510(void*, int);
int FUN_14037c610(void*);
int FUN_140408410(const ATL::CAtlArray<unsigned>*, const int&);
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
WorldService* FUN_1403ed2d0();
void* FUN_141bd0cc0(void*);
int FUN_141654700(PCBase*);
int FUN_141654730(PCBase*);
__int64 FUN_141658eb0(PCBase*);
int FUN_141662de0(PCBase*);
int FUN_140931210(int);
void* FUN_140764010();
int FUN_14035a870(void*, int, int);
unsigned FUN_141662750(PCBase*, int);
void* FUN_1409670c0();
int FUN_14066af60(void*, int, unsigned);
CQuestManager* FUN_140764020();
void* FUN_140764010();
unsigned FUN_14035b590(void*, int);
CStateService* FUN_140aa6d30();
unsigned FUN_141472bc0();
unsigned FUN_140869420();
int FUN_14074bc90(int questId);
int FUN_1409312f0();
void* FUN_1409331e0();
void FUN_14138d7e0(void*, int, int);
CStringW FUN_1416e4df0(int);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_14028b8e0(const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
void FUN_1410943b0(Unk_WsC_GameObj*, int);
// Shared quest-id list handle returned by the quest table (16 bytes, list pointer at +8).
class Unk_QmQuestIdList {
public:
    ~Unk_QmQuestIdList();                               // 0x1401c5790
    bool IsNull() const;                                // 0x140356720
    ATL::CAtlArray<unsigned>* operator->() const;       // 0x140356870
private:
    void* m_0;
    ATL::CAtlArray<unsigned>* m_p;
};
class Unk_QgQuestTable {
public:
    std::vector<unsigned>& FUN_14074e0d0();   // returns this+0x360
    void FUN_14074d080(int mapId, ATL::CAtlArray<unsigned>& out);
    void FUN_14074d410(ATL::CAtlArray<unsigned>& out);   // quests that open a talk on entering a map
    void FUN_14074cfd0(int group, ATL::CAtlArray<unsigned>& out);
    Unk_QmQuestIdList FUN_14074df70(int itemId, int kind);   // quests started (0) / advanced (1) by an item
    int FUN_14074e510(unsigned questId);
    void FUN_14074d360(int id, ATL::CAtlArray<unsigned>& out);
    const std::vector<unsigned>* FUN_14074e0f0(int npcId);   // quests of an npc (null when none)
};
Unk_QgQuestTable* FUN_1407476c0();
class Unk_QuestDungeonRecord {
public:
    int FUN_140b22890(int);
    bool FUN_140b223d0(int);
};
template<> Unk_PayloadPtr<Unk_QuestDungeonRecord>::~Unk_PayloadPtr();
class Unk_QuestNotifyState {
public:
    Unk_PayloadPtr<Unk_QuestDungeonRecord> FUN_140d9f2c0();
};
Unk_QuestNotifyState* FUN_140931510();
int FUN_140d9f880(void*, int);
void* FUN_140c70240();
int FUN_140b71580(void*);
class CGuildManager;
CGuildManager* FUN_1403ed290();
int FUN_1413b6160(CGuildManager*);
extern __int64 DAT_143ab2828;
class CMsgBoxData;
unsigned FUN_141a02e90(const CMsgBoxData*, int, unsigned);
int FUN_141a02e50(const CMsgBoxData*, int, int);

class Unk_QuestNotices {
public:
    void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>);
    void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>);
};
Unk_QuestNotices* FUN_140939a10();
class Unk_QuestPacketHandlers {
public:
    void FUN_140da5180(int, Delegate<void(CInPacket&)>);
    void FUN_140da51e0(int, Delegate<void(CInPacket&)>);
};
Unk_QuestPacketHandlers* FUN_140bccd50();
class Unk_QuestUIListeners {
public:
    void FUN_1419cae20(UIItemEventListener*);
    void FUN_1419caeb0(UIItemEventListener*);
};
Unk_QuestUIListeners* FUN_140a6a840();

// Unit-local stand-ins for exe systems reached only from here.
class Unk_QmGameEvent {
public:
    int FUN_1403fd660(int questId);             // quest allowed by this event
};
// 16-byte handle returned by the game-event manager (ptr at +8).
class Unk_QmGameEventRef {
public:
    ~Unk_QmGameEventRef();                      // 0x1403e5510
    bool IsNull() const;                        // 0x1403e84c0
    Unk_QmGameEvent* Get() const;               // 0x1403e8cd0
private:
    void* m_0;
    void* m_p;
};
class Unk_GmEvtKey;
extern Unk_GmEvtKey DAT_143ab2fc0;
class Unk_QmGameEventMgr {
public:
    Unk_QmGameEventRef FUN_14047ca40(const Unk_GmEvtKey& key);
};
Unk_QmGameEventMgr* FUN_1401c0d90();
class Unk_QmWorld {
public:
    MS2Ptr<CProxyGameObject> FUN_141bc9be0(unsigned id);   // proxy object by id
    PCBase* FUN_141bd1530(__int64 id);                     // player by user id
};
int FUN_14123c580(PCBase* pc);
MS2Ptr<CQuestData> FUN_14074bc40(int questId);
int FUN_14074b050(CQuestData* data);
int FUN_14074b030(CQuestData* data);
float FUN_140966f00(NiPoint3 a, NiPoint3 b);   // distance
void FUN_1412751b0(const CStringW& text, int type);   // system chat line
int FUN_1418fd280();
void FUN_1411e1b80(Unk_PCEquipSet* equipSet, ATL::CAtlList<MS2Ptr<CEquipItem>>& out);   // the worn items
int FUN_14074b070(CQuestData* data);
CFieldMetaTable* FUN_140700390();
CLearningQuestTable* FUN_140ea4060();
CChapterBookTable* FUN_140e0a9f0();
bool FUN_140764040(CQuestData*);
bool FUN_140764080(CQuestData*);
bool FUN_1407640c0(CQuestData*);
// Field object handle filled by WorldService::FUN_141bc2800 (16 bytes, Unk_WsP16 layout).
class Unk_QmFieldObject { public: Unk_StreamPoint FUN_14169d2f0() const; };
struct Unk_QmFieldHandle : Unk_WsP16 {
    ~Unk_QmFieldHandle();                       // 0x140964a70
    bool IsNull() const;                        // 0x140965190
    Unk_QmFieldObject* operator->() const;      // 0x140965960
};
extern Unk_StreamPoint DAT_143b01a60;           // NiPoint3::ZERO
class Unk_QmClientConfig { public: void* m_0; CContentShutdown m_shutdown; };
Unk_QmClientConfig* FUN_14025e7b0();
void FUN_141275260(int stringId, int, int);
class Unk_QmNpcTable { public: int FUN_140764e40(int group, unsigned npcId); };
Unk_QmNpcTable* FUN_14109a710();
class Unk_QmQuestFilter { public: int FUN_141261b90(unsigned questId); };
class Unk_QmOptions { public: Unk_QmQuestFilter* FUN_140c9b8b0(); };
Unk_QmOptions* FUN_1409a8b10();
CStringW FUN_140763550(unsigned questId, int state);     // one tooltip line of a quest
CStringW FUN_14052bd00(int stringId, const CStringW& arg);
PCBase* FUN_140aac420(Unk_WsV118* user);              // the user's object (CComPtrBase::operator T*)
// CRBTree<unsigned, Unk_WsV118> members belong to other objects (0x140c20a10, 0x14112e170, 0x14112e2b0).
template<> POSITION ATL::CRBTree<unsigned, Unk_WsV118, ATL::CElementTraits<unsigned>, ATL::CElementTraits<Unk_WsV118>>::GetHeadPosition() const throw();
template<> ATL::CRBTree<unsigned, Unk_WsV118, ATL::CElementTraits<unsigned>, ATL::CElementTraits<Unk_WsV118>>::CPair*
    ATL::CRBTree<unsigned, Unk_WsV118, ATL::CElementTraits<unsigned>, ATL::CElementTraits<Unk_WsV118>>::GetNext(POSITION&) throw();
template<> Unk_WsV118& ATL::CRBTree<unsigned, Unk_WsV118, ATL::CElementTraits<unsigned>, ATL::CElementTraits<Unk_WsV118>>::GetValueAt(POSITION) throw();
int FUN_14074b210(CQuestData* data);
int FUN_1407474d0(const ATL::CAtlArray<int>* values, const int* value);   // index of value, or -1
void FUN_140d73bc0(int id, int a, void* b, CStringW text);
void FUN_140d73aa0(CStringW text, int type, void* data, CStringW tag);
class Unk_QmStrings {
public:
    CStringW FUN_141811980(int table, int index);
};
Unk_QmStrings* FUN_1401a9d70();
class Unk_IngTable;
Unk_IngTable* FUN_140281980();
unsigned FUN_1405575b0(Unk_IngTable* table, int itemId);   // the item's name id
void FUN_141b1feb0(void*);
class Unk_QmTalkScript;
// Boxed talk-script handle (16 bytes), as used by cubespawnobject.cpp.
class Unk_QmTalkScriptPtr {
public:
    Unk_QmTalkScriptPtr(const Unk_QmTalkScriptPtr& o);  // 0x140859bc0
    ~Unk_QmTalkScriptPtr();                             // 0x14078f140
    bool IsNull() const;                                // 0x14085a420
    Unk_QmTalkScript* FUN_14078f3a0() const;            // get
private:
    void* m_0;
    Unk_QmTalkScript* m_p;
};
Unk_QmTalkScriptPtr FUN_1408564b0(int questId, int n);
int FUN_14074b0e0(CQuestData* data, int value, int n);
int IsConditionTypeCounted(int nType);
extern Unk_Inventory DAT_143ab2a90;
extern __int64 DAT_143ab2898;
UIQuestEventDispatcher* FUN_140bfc4b0();
int FUN_141276180(const CString& sound, const CString& arg);
void FUN_14138bf00(void*, int, int, int);
// The dungeon room record looked up by room id (+0x1c: the room's dungeon).
class Unk_QmRoom {
public:
    char m_pad_00[0x1c];
    int m_1c;
};
class Unk_QmRoomPtr {
public:
    ~Unk_QmRoomPtr();                                   // 0x14031c0f0
    bool operator!() const;                             // 0x140e36ca0
    Unk_QmRoom* operator->() const;                     // 0x1403347d0
private:
    void* m_0;
    Unk_QmRoom* m_p;
};
class Unk_QmRoomTable {
public:
    Unk_QmRoomPtr FUN_1403206b0(int roomId);
};
Unk_QmRoomTable* FUN_14031c2a0();
int FUN_1402178b0(int roomKind);
class UIPopupNpcTalkDialog : public UIDialog {
public:
    void FUN_140e771e0(int questId);
};
class Unk_QmUIManager {
public:
    MS2Ptr<UIObject> FUN_141adcea0(int id);
};
Unk_QmUIManager* FUN_1403ed2b0();
// @0x1416d4e40 (UIPopupNpcTalkDialog instance)
template <class T> T* Unk_QmFindDialog(int id)
{
    if (FUN_1403ed2b0()) {
        MS2Ptr<UIObject> ui = FUN_1403ed2b0()->FUN_141adcea0(id);
        if (ui.get())
            return dynamic_cast<T*>((UIObject*)ui);
    }
    return 0;
}
// Instances of other objects.
template<> size_t ATL::CAtlArray<__int64>::GetCount() const throw();
template<> __int64& ATL::CAtlArray<__int64>::operator[](size_t) throw();
// These array instances were first emitted by astooltip.cpp.
template<> ATL::CAtlArray<Unk_QuestItemLink>::CAtlArray() throw();
template<> ATL::CAtlArray<Unk_QuestItemLink>::~CAtlArray() throw();
template<> size_t ATL::CAtlArray<Unk_QuestItemLink>::GetCount() const throw();
template<> Unk_QuestItemLink& ATL::CAtlArray<Unk_QuestItemLink>::operator[](size_t) throw();
// CAtlArray<MS2Ptr<CLearningQuestData>> members live with the learning quest UI (0x140ea3c70..0x140ea4040).
template<> ATL::CAtlArray<CLearningQuestTable::DataPtr>::CAtlArray() throw();
template<> ATL::CAtlArray<CLearningQuestTable::DataPtr>::~CAtlArray() throw();
template<> size_t ATL::CAtlArray<CLearningQuestTable::DataPtr>::GetCount() const throw();
template<> CLearningQuestTable::DataPtr& ATL::CAtlArray<CLearningQuestTable::DataPtr>::operator[](size_t) throw();

// @0x1416c7fd0
CQuestManager::CQuestManager()
{
    m_levelDirty = 0;
    FUN_140a6a840()->FUN_1419cae20(this);
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca730));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeMyJob", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca760));
    FUN_140939a10()->FUN_140da4e40(L"NotifyClearAchieve", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca780));
    FUN_140939a10()->FUN_140da4e40(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca7a0));
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca7c0));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeLevel", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeJob", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeEquipment", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangeTitle", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChangePcRidee", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140bccd50()->FUN_140da5180(0x10b, Delegate<void(CInPacket&)>(this, &CQuestManager::FUN_1416ca830));
    m_group = 0;
    m_refreshCount = 0;
    m_field178 = 0;
    m_targetObject = 0;
    m_field190 = 0;
    m_requestTick = 0;
    m_availableDirty = 0;
    m_itemsDirty = 0;
}

// @0x1416c8c70
CQuestManager::~CQuestManager()
{
    m_quests20.RemoveAll();
    m_quests50.RemoveAll();
    m_quests80.RemoveAll();
    m_questsb0.RemoveAll();
    m_questse0.RemoveAll();
    m_quests110.RemoveAll();
    m_quests140.RemoveAll();
    FUN_140a6a840()->FUN_1419caeb0(this);
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeMyLevel", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca730));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeMyJob", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca760));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyClearAchieve", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca780));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca7a0));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyGameEventChanged", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca7c0));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeLevel", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeJob", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeEquipment", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangeTitle", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChangePcRidee", Delegate<void(NotifyObject*)>(this, &CQuestManager::FUN_1416ca850));
    FUN_140bccd50()->FUN_140da51e0(0x10b, Delegate<void(CInPacket&)>(this, &CQuestManager::FUN_1416ca830));
}

// @0x1416c9760
int CQuestManager::vfunc_o10_1(int id)
{
    MS2Ptr<CAchieve> achieve = FUN_1406c7600()->Find(id);
    if (achieve.IsNull()) return 0;
    if (achieve->GetState() != 3) return 0;
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x1416c9760, CQuestManager, CQuestManagerCommon, vfunc_o10_1, 161, 0xA6A22EE1);

// @0x1416c9810
void CQuestManager::vfunc_o10_0(int id, int state)
{
    FUN_140936640(FUN_1406c7600(), id, state);
}
MS2_REPLACE_METHOD_VIA(0x1416c9810, CQuestManager, CQuestManagerCommon, vfunc_o10_0, 45, 0x8953D5C2);

// @0x1416c9850
int CQuestManager::vfunc_o10_2(int id)
{
    return FUN_140408410(&m_pinnedQuests, id) != -1;
}
MS2_REPLACE_METHOD_VIA(0x1416c9850, CQuestManager, CQuestManagerCommon, vfunc_o10_2, 69, 0x2B0D9F09);

// @0x1416c98a0
int CQuestManager::vfunc_o10_4()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return player->vfunc_78();
}
MS2_REPLACE_METHOD_VIA(0x1416c98a0, CQuestManager, CQuestManagerCommon, vfunc_o10_4, 63, 0x739B8DCC);

// @0x1416c98f0
int CQuestManager::vfunc_o10_5()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    MS2Ptr<CProxyGameObject> proxy = reinterpret_cast<Unk_QmWorld*>(FUN_1403ed2d0())->FUN_141bc9be0(FUN_14123c580(player));
    if (proxy.IsNull()) return 0;
    return proxy->m_c8;
}
MS2_REPLACE_METHOD_VIA(0x1416c98f0, CQuestManager, CQuestManagerCommon, vfunc_o10_5, 168, 0xB42E5FC9);

// @0x1416c99a0
int CQuestManager::vfunc_o10_6()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141654700(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c99a0, CQuestManager, CQuestManagerCommon, vfunc_o10_6, 54, 0x5D718A31);

// @0x1416c99e0
int CQuestManager::vfunc_o10_7()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141654730(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c99e0, CQuestManager, CQuestManagerCommon, vfunc_o10_7, 54, 0x0C542E91);

// @0x1416c9a20
int CQuestManager::vfunc_o10_9()
{
    return FUN_1413b6160(FUN_1403ed290());
}
MS2_REPLACE_METHOD_VIA(0x1416c9a20, CQuestManager, CQuestManagerCommon, vfunc_o10_9, 27, 0x11B98314);

// @0x1416c9a50
int CQuestManager::vfunc_o10_10()
{
    return static_cast<CGuildInfo&>(*FUN_1403ed290()).FUN_1404d1a80();
}
MS2_REPLACE_METHOD_VIA(0x1416c9a50, CQuestManager, CQuestManagerCommon, vfunc_o10_10, 31, 0xEF9C0B93);

// @0x1416c9a80
int CQuestManager::vfunc_o10_11()
{
    return static_cast<CGuildInfo&>(*FUN_1403ed290()).FUN_1404d2990(6);
}
MS2_REPLACE_METHOD_VIA(0x1416c9a80, CQuestManager, CQuestManagerCommon, vfunc_o10_11, 36, 0xA08F10BC);

// @0x1416c9ab0
__int64 CQuestManager::vfunc_o10_12()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    MS2Ptr<CGuildMember> member = FUN_1403ed290()->FUN_1404cf9f0(player->vfunc_77());
    if (member == 0) return 0;
    return member->fc8;
}
MS2_REPLACE_METHOD_VIA(0x1416c9ab0, CQuestManager, CQuestManagerCommon, vfunc_o10_12, 215, 0x15F7F369);

// @0x1416c9b90
__int64 CQuestManager::vfunc_o10_8()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141658eb0(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c9b90, CQuestManager, CQuestManagerCommon, vfunc_o10_8, 54, 0x0EE23A1E);

// @0x1416c9bd0
int CQuestManager::vfunc_o10_13(int id)
{
    int value = FUN_140931210(id);
    return FUN_14035a870(FUN_140764010(), id, value);
}
MS2_REPLACE_METHOD_VIA(0x1416c9bd0, CQuestManager, CQuestManagerCommon, vfunc_o10_13, 53, 0xB7DAED80);

// @0x1416c9c10
int CQuestManager::vfunc_o10_14(int id)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_14066af60(FUN_1409670c0(), id, FUN_141662750(player, id));
}
MS2_REPLACE_METHOD_VIA(0x1416c9c10, CQuestManager, CQuestManagerCommon, vfunc_o10_14, 90, 0x7C542213);

// @0x1416c9c70
int CQuestManager::vfunc_o10_15(int id)
{
    return FUN_140931510()->FUN_140d9f2c0()->FUN_140b22890(id);
}
MS2_REPLACE_METHOD_VIA(0x1416c9c70, CQuestManager, CQuestManagerCommon, vfunc_o10_15, 100, 0xC93D21FB);

// @0x1416c9ce0
int CQuestManager::vfunc_o10_16(int id)
{
    return FUN_140d9f880(FUN_140931510(), id);
}
MS2_REPLACE_METHOD_VIA(0x1416c9ce0, CQuestManager, CQuestManagerCommon, vfunc_o10_16, 35, 0xF17E0AF2);

// @0x1416c9d10
int CQuestManager::vfunc_o10_17(int id)
{
    return FUN_140931510()->FUN_140d9f2c0()->FUN_140b223d0(id) != 0;
}
MS2_REPLACE_METHOD_VIA(0x1416c9d10, CQuestManager, CQuestManagerCommon, vfunc_o10_17, 129, 0xBEDFE2F6);

// @0x1416c9da0
int CQuestManager::vfunc_o10_18()
{
    return FUN_140b71580(FUN_140c70240());
}
MS2_REPLACE_METHOD_VIA(0x1416c9da0, CQuestManager, CQuestManagerCommon, vfunc_o10_18, 27, 0x8D6AF085);

// @0x1416c9dd0
int CQuestManager::vfunc_o10_19()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141662de0(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c9dd0, CQuestManager, CQuestManagerCommon, vfunc_o10_19, 54, 0xA0BC4C64);

// @0x1416c9e10
int CQuestManager::vfunc_1(int questId, int flag)
{
    if (CQuestManagerCommon::vfunc_o10_21(questId, flag, 0) == 0) return 0;
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (!data) return 0;
    {
        if (FUN_14074b050(data.operator->()) == 4) {
            int mapId = FUN_1403ed2d0()->FUN_141bd3060();
            if (data->m_fields.GetCount() == 0) return 0;
            int field = data->m_fields[0];
            if (field != mapId) {
                unsigned parent = 0;
                if (FUN_140700390()->FUN_1406fc110(mapId, &parent) == 0) return 0;
                if (field != parent) return 0;
            }
        } else if (FUN_14074b050(data.operator->()) == 5) {
            if (data->m_350 == 2) {
                Unk_QmGameEventRef event = FUN_1401c0d90()->FUN_14047ca40(DAT_143ab2fc0);
                if (event.IsNull()) return 0;
                if (event.Get()->FUN_1403fd660(questId) == 0) return 0;
            }
        } else if (FUN_14074b050(data.operator->()) == 9) {
            if (FUN_14074b070(data.operator->()) == 2) {
                int count = 0;
                if (m_dailyCounts.Lookup(questId, count)) return count;
                return 0;
            } else if (FUN_14074b070(data.operator->()) == 3 && data->m_require.m_groupId == 0) {
                int count = 0;
                if (m_weeklyCounts.Lookup(questId, count)) return count;
                return 0;
            }
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416c9e10, CQuestManager, vfunc_1, 921, 0x96684B95);

// @0x1416ca1c0
Unk_PayloadPtr<CQuest> CQuestManager::vfunc_o10_3(int id)
{
    Unk_PayloadPtr<CQuest> quest(0);
    m_quests140.Lookup(id, quest);
    return quest;
}
MS2_REPLACE_METHOD_VIA(0x1416ca1c0, CQuestManager, CQuestManagerCommon, vfunc_o10_3, 123, 0xADCEE0AD);

// @0x1416ca250
int CQuestManager::vfunc_o10_20(const ATL::CAtlArray<unsigned>& ids)
{
    return FUN_1416d3af0(ids) != 0;
}
MS2_REPLACE_METHOD_VIA(0x1416ca250, CQuestManager, CQuestManagerCommon, vfunc_o10_20, 67, 0x6059D7CE);

// @0x1416ca2a0
__int64 CQuestManager::vfunc_o10_22()
{
    return DAT_143ab2828;
}
MS2_REPLACE_METHOD_VIA(0x1416ca2a0, CQuestManager, CQuestManagerCommon, vfunc_o10_22, 13, 0xBA20E7DE);

// @0x1416ca2c0
unsigned CQuestManager::vfunc_o10_23(const Unk_QuestCondition& condition)
{
    return CQuestManagerCommon::vfunc_o10_23(condition);
}
MS2_REPLACE_METHOD_VIA(0x1416ca2c0, CQuestManager, CQuestManagerCommon, vfunc_o10_23, 37, 0xD2BCEFDD);

// @0x1416ca2f0
void CQuestManager::FUN_1416ca2f0()
{
    m_itemsDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca2f0, CQuestManager, FUN_1416ca2f0, 21, 0x923ABA4D);

// @0x1416ca310
void CQuestManager::vfunc_2(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca310, CQuestManager, UIItemEventListener, vfunc_2, 36, 0xFD0C761F);

// @0x1416ca340
void CQuestManager::vfunc_3(void*, bool)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca340, CQuestManager, UIItemEventListener, vfunc_3, 41, 0x5B133A72);

// @0x1416ca370
void CQuestManager::vfunc_4(void*, int)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca370, CQuestManager, UIItemEventListener, vfunc_4, 41, 0x89D45B7F);

// @0x1416ca3a0
void CQuestManager::vfunc_21(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca3a0, CQuestManager, UIItemEventListener, vfunc_21, 36, 0xAF7DFFEF);

// @0x1416ca3d0
void CQuestManager::vfunc_22(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca3d0, CQuestManager, UIItemEventListener, vfunc_22, 36, 0xB5DE9CDF);

// @0x1416ca400
void CQuestManager::vfunc_33(int type, int)
{
    if (type == 0x6200004) {
        FUN_1416ca2f0();
    }
}
MS2_REPLACE_METHOD_VIA(0x1416ca400, CQuestManager, UIItemEventListener, vfunc_33, 50, 0x790979EE);

// @0x1416ca440
void CQuestManager::FUN_1416ca440()
{
    if (m_counter198.FUN_140268870(1000)) {
        FUN_1416d3010();
        FUN_1416d3430();
        POSITION pos = m_quests20.GetHeadPosition();
        while (pos != 0) {
            Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
            quest->FUN_140d73960();
            m_quests20.GetNext(pos);
        }
    }
    if (m_levelDirty != 0) {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d) {
            m_levelDirty = 0;
            FUN_1416d3510();
        }
    }
    if (m_itemsDirty != 0) {
        m_itemsDirty = 0;
        FUN_1416cef90(0);
    }
    if (m_availableDirty != 0) {
        m_availableDirty = 0;
        FUN_1416d3250();
    }
    if (m_field178 != 0) {
        Unk_WsC_GameObj* target = FUN_1403ed2d0()->FUN_141bd1320(m_targetObject);
        if (target == 0) return;
        FUN_1410943b0(target, 10);
        m_field178 = 0;
    }
    if (m_requestTick != 0) {
        unsigned now = FUN_140869420();
        if (m_requestTick + *FUN_1401d3200()->QuestPortalSummonTime.Get() < now) {
            m_requestTick = 0;
            m_targetObject = 0;
            m_field190 = 0;
        }
    }
}
MS2_REPLACE_METHOD(0x1416ca440, CQuestManager, FUN_1416ca440, 544, 0x39656FEB);

// @0x1416ca670
void CQuestManager::FUN_1416ca670()
{
    m_field180 = 0;
    POSITION pos = m_quests20.GetHeadPosition();
    while (pos != 0) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        quest->FUN_140d73950();
        m_quests20.GetNext(pos);
    }
    FUN_1416d3220();
}
MS2_REPLACE_METHOD(0x1416ca670, CQuestManager, FUN_1416ca670, 182, 0x5F112B69);

// @0x1416ca730
void CQuestManager::FUN_1416ca730(NotifyObject*)
{
    m_levelDirty = 1;
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca730, CQuestManager, FUN_1416ca730, 41, 0x3A2CD5A4);

// @0x1416ca760
void CQuestManager::FUN_1416ca760(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca760, CQuestManager, FUN_1416ca760, 26, 0x3D36B1A4);

// @0x1416ca780
void CQuestManager::FUN_1416ca780(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca780, CQuestManager, FUN_1416ca780, 26, 0x3D36B1A4);

// @0x1416ca7a0
void CQuestManager::FUN_1416ca7a0(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca7a0, CQuestManager, FUN_1416ca7a0, 26, 0x3D36B1A4);

// @0x1416ca7c0
void CQuestManager::FUN_1416ca7c0(NotifyObject* pNotify)
{
    NotifyGameEventChanged* ev = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (ev != 0 && ev->m_type != 1) {
        m_availableDirty = 1;
    }
}
MS2_REPLACE_METHOD(0x1416ca7c0, CQuestManager, FUN_1416ca7c0, 96, 0xF957FBFF);

// @0x1416ca830
void CQuestManager::FUN_1416ca830(CInPacket&)
{
    m_refreshCount = 0;
}
MS2_REPLACE_METHOD(0x1416ca830, CQuestManager, FUN_1416ca830, 26, 0x5A297EAB);

// @0x1416ca850
void CQuestManager::FUN_1416ca850(NotifyObject* pNotify)
{
    NotifyChangeJob* job = dynamic_cast<NotifyChangeJob*>(pNotify);
    if (job != 0) {
        FUN_1416d1d00(job->m_pc);
    } else {
        NotifyChangeEquipment* equip = dynamic_cast<NotifyChangeEquipment*>(pNotify);
        if (equip != 0) {
            FUN_1416d1d00(equip->m_pc);
        } else {
            NotifyChangeLevel* level = dynamic_cast<NotifyChangeLevel*>(pNotify);
            if (level != 0) {
                FUN_1416d1d00(level->m_pc);
            } else {
                NotifyChangeTitle* title = dynamic_cast<NotifyChangeTitle*>(pNotify);
                if (title != 0) {
                    FUN_1416d1d00(title->m_pc);
                } else {
                    NotifyChangePcRidee* ridee = dynamic_cast<NotifyChangePcRidee*>(pNotify);
                    if (ridee != 0) {
                        FUN_1416d1d00(ridee->m_pc);
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416ca850, CQuestManager, FUN_1416ca850, 366, 0x15773725);

// @0x1416ca9d0
CQuest* CQuestManager::FUN_1416ca9d0(int questId)
{
    CQuest* quest;
    int type = FUN_14074bc90(questId);
    if (type == 0) {
        quest = new CEpicQuest();
    } else if (type == 1) {
        quest = new CWorldQuest();
    } else if (type == 2) {
        quest = new CEventQuest();
    } else if (type == 6) {
        quest = new CGuildQuest();
    } else if (type == 8) {
        quest = new CFieldQuest();
    } else if (type == 9) {
        quest = new CAllianceQuest();
    } else if (type == 3) {
        quest = new CDailyMission();
    } else if (type == 4) {
        quest = new CFieldMission();
    } else if (type == 5) {
        quest = new CEventMission();
    } else if (type == 7) {
        quest = new CMentoringMission();
    } else if (type == 10) {
        quest = new CWeddingMission();
    } else {
        quest = 0;
    }
    return quest;
}
MS2_REPLACE_METHOD(0x1416ca9d0, CQuestManager, FUN_1416ca9d0, 1049, 0x486EE340);

// @0x1416cae20
int CQuestManager::FUN_1416cae20(int id)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(id);
    if (quest.IsNull()) return 0;
    return quest->FUN_1407476d0();
}
MS2_REPLACE_METHOD(0x1416cae20, CQuestManager, FUN_1416cae20, 149, 0x7D595639);

// @0x1416caec0
void CQuestManager::FUN_1416caec0(Unk_PayloadPtr<CQuest> quest)
{
    if (quest.IsNull()) return;
    int type = quest->GetQuestType();
    switch (type) {
    case 4: m_quests80.SetAt(quest->FUN_140bfc580(), quest); break;
    case 3: m_quests50.SetAt(quest->FUN_140bfc580(), quest); break;
    case 5: m_questsb0.SetAt(quest->FUN_140bfc580(), quest); break;
    case 7: m_questse0.SetAt(quest->FUN_140bfc580(), quest); break;
    case 10: m_quests110.SetAt(quest->FUN_140bfc580(), quest); break;
    default: m_quests20.SetAt(quest->FUN_140bfc580(), quest); break;
    }
    m_quests140.SetAt(quest->FUN_140bfc580(), quest);
    FUN_1416d3d50(quest);
}
MS2_REPLACE_METHOD(0x1416caec0, CQuestManager, FUN_1416caec0, 511, 0x74E17A65);

// @0x1416cb0d0
void CQuestManager::FUN_1416cb0d0(int questId, int force)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (!quest.IsNull()) {
        FUN_14138d7e0(FUN_1409331e0(), 7, 0);
        FUN_14138d7e0(FUN_1409331e0(), 8, 0);
        if (FUN_140745590(questId) == 0 || force != 0) {
            m_quests20.RemoveKey(questId);
            m_quests140.RemoveKey(questId);
            m_quests50.RemoveKey(questId);
            m_questsb0.RemoveKey(questId);
            m_questse0.RemoveKey(questId);
            m_quests80.RemoveKey(questId);
            m_quests110.RemoveKey(questId);
        } else {
            quest->SetState(2);
        }
    }
}
MS2_REPLACE_METHOD(0x1416cb0d0, CQuestManager, FUN_1416cb0d0, 390, 0x79B0B7B3);

// MS2-FUNCTIONAL: equivalent short-circuit filters; temporary lifetime differs.
// @0x1416cb260
void CQuestManager::FUN_1416cb260(ATL::CAtlArray<unsigned>& ids, int state, int type, int group)
{
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (state != 4 && state != quest->FUN_1407476d0()) continue;
        if (type != 11 && type != quest->GetData()->m_type) continue;
        if (group != -1 && group != quest->GetData()->m_28) continue;
        ids.Add(quest->FUN_140bfc580());
    }
}
MS2_REPLACE_METHOD(0x1416cb260, CQuestManager, FUN_1416cb260, 618, 0x631E6AA7);

// @0x1416cb4d0
void CQuestManager::FUN_1416cb4d0(std::vector<unsigned>& ids, std::vector<int> states, int type, int group)
{
    bool all = false;
    if (states.empty() ||
        std::find_if(states.begin(), states.end(), [](int state) { return state == 4 || state == 5; }) != states.end())
        all = true;
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (!all) {
            int state = quest->FUN_1407476d0();
            if (std::find(states.begin(), states.end(), state) == states.end()) continue;
        }
        if (type != 11 && FUN_14074b050(quest->GetData().operator->()) != type) continue;
        if (group != -1 && quest->GetData()->m_28 != group) continue;
        ids.emplace_back(quest->FUN_140bfc580());
    }
}
MS2_REPLACE_METHOD(0x1416cb4d0, CQuestManager, FUN_1416cb4d0, 976, 0x80ADF2C6);

// @0x1416cb8b0
void CQuestManager::FUN_1416cb8b0(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out, int state, int type, int group)
{
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (state != 4 && state != quest->FUN_1407476d0()) continue;
        if (type != 11 && FUN_14074b050(quest->GetData().operator->()) != type) continue;
        if (group != -1 && quest->GetData()->m_28 != group) continue;
        out.Add(quest);
    }
}
MS2_REPLACE_METHOD(0x1416cb8b0, CQuestManager, FUN_1416cb8b0, 603, 0x59020450);

// @0x1416cbb20
void CQuestManager::FUN_1416cbb20(std::vector<Unk_PayloadPtr<CQuest>>& out, int state, int type, int group)
{
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (state != 4 && state != quest->FUN_1407476d0()) continue;
        if (type != 11 && FUN_14074b050(quest->GetData().operator->()) != type) continue;
        if (group != -1 && quest->GetData()->m_28 != group) continue;
        out.push_back(quest);
    }
}
MS2_REPLACE_METHOD(0x1416cbb20, CQuestManager, FUN_1416cbb20, 603, 0x95FC889F);

// @0x1416cde50
void CQuestManager::FUN_1416cde50(int error)
{
    if (error == 1) {
        FUN_140d73bc0(0x5ee, 0, 0, L"");
    } else if (error == 2) {
        FUN_140d73bc0(0x5ef, 0, 0, L"");
    } else if (error == 3) {
        FUN_140d73bc0(0x5f0, 0, 0, L"");
    } else if (error == 4) {
        FUN_140d73bc0(0x5f2, 0, 0, L"");
    } else if (error == 5) {
        FUN_140d73aa0(FUN_14028b8e0(L"s_quest_error_fail_complete_by_dead"), 0, 0, CStringW(L""));
    } else if (error == 7) {
        unsigned name = FUN_1405575b0(FUN_140281980(), 0xd1);
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_alliance_quest_completion_ticket_error"),
                                    FUN_1401a9d70()->FUN_141811980(1, name)),
                      1, 1);
    }
    FUN_141b1feb0(FUN_140967100());
}
MS2_REPLACE_METHOD(0x1416cde50, CQuestManager, FUN_1416cde50, 744, 0x7BF47F0A);

// @0x1416ce140
void CQuestManager::FUN_1416ce140(int questId, int)
{
    FUN_141b217e0(FUN_140967100(), questId);
}
MS2_REPLACE_METHOD(0x1416ce140, CQuestManager, FUN_1416ce140, 40, 0x655404CF);

// @0x1416ce170
int CQuestManager::FUN_1416ce170(MS2Ptr<CItem> item)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    ATL::CAtlArray<Unk_QuestItemLink> links;
    FUN_1416ce860(item, links);
    return links.GetCount() != 0;
}
MS2_REPLACE_METHOD(0x1416ce170, CQuestManager, FUN_1416ce170, 226, 0x29125101);

// @0x1416ce260
int CQuestManager::FUN_1416ce260(int group)
{
    if (FUN_1416ce340(group) != 0) return 0;
    if (FUN_1416ce3d0(group) != 0) return 0;
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074cfd0(group, ids);
    if (ids.GetCount() == 0) return 0;
    return vfunc_1(ids[0], 0);
}
MS2_REPLACE_METHOD(0x1416ce260, CQuestManager, FUN_1416ce260, 210, 0x59D15EBC);

// @0x1416ce340
int CQuestManager::FUN_1416ce340(int value)
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1416cb260(ids, 4, 11, value);
    return ids.GetCount() != 0;
}
MS2_REPLACE_METHOD(0x1416ce340, CQuestManager, FUN_1416ce340, 128, 0xCDCFD910);

// @0x1416ce3d0
int CQuestManager::FUN_1416ce3d0(int group)
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074cfd0(group, ids);
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> data = FUN_14074bc40(ids[i]);
        if (!data) continue;
        if (data->m_2f != 0) continue;
        Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(ids[i]);
        if (quest.IsNull()) return 0;
        if (quest->FUN_1407476d0() != 2) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416ce3d0, CQuestManager, FUN_1416ce3d0, 445, 0xAF1814FF);

// @0x1416ce5a0
int CQuestManager::FUN_1416ce5a0()
{
    int count = 0;
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (quest->FUN_1407476d0() != 1) continue;
        if (quest->GetTrackingState() == 0) continue;
        count++;
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416ce5a0, CQuestManager, FUN_1416ce5a0, 239, 0x59C2EDCA);

// @0x1416ce6a0
int CQuestManager::FUN_1416ce6a0(MS2Ptr<CItem> item)
{
    int best = 0;
    ATL::CAtlArray<Unk_QuestItemLink> links;
    FUN_1416ce860(item, links);
    for (size_t i = 0; i < links.GetCount(); i++) {
        int rank = 0;
        switch (links[i].m_state) {
        case 0: rank = 2; break;
        case 1: rank = 3; break;
        case 2: rank = 1; break;
        }
        if (rank > best) best = rank;
    }
    switch (best) {
    case 2: return 0;
    case 3: return 1;
    case 1: return 2;
    }
    return 4;
}
MS2_REPLACE_METHOD(0x1416ce6a0, CQuestManager, FUN_1416ce6a0, 438, 0xCC2D1DC6);

// @0x1416ce860
void CQuestManager::FUN_1416ce860(MS2Ptr<CItem> item, ATL::CAtlArray<Unk_QuestItemLink>& out)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return;
    if (item.IsNull()) return;
    for (size_t kind = 0; kind < 2; kind++) {
        Unk_QmQuestIdList list = FUN_1407476c0()->FUN_14074df70(item->FUN_1405276c0(), static_cast<int>(kind));
        if (list.IsNull()) continue;
        for (size_t i = 0; i < list->GetCount(); i++) {
            unsigned questId = list->GetAt(i);
            MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
            if (!data) continue;
            if (data->m_30 != 0) continue;
            if (FUN_1407476c0()->FUN_14074e510(questId) != 0) continue;
            if (FUN_14074b210(data.operator->()) == 0) continue;
            if (data->m_require.m_job.GetCount() != 0) {
                int job = FUN_141654700(player);
                if (FUN_1407474d0(&data->m_require.m_job, &job) == -1) continue;
            }
            if (kind == 1 && item->FUN_140529620()) continue;
            Unk_QuestItemLink link;
            link.m_questId = questId;
            link.m_kind = static_cast<int>(kind);
            Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
            if (quest.IsNull()) {
                link.m_state = 0;
            } else if (quest->FUN_1407476d0() == 2) {
                if (FUN_14074b070(data.operator->()) != 0) link.m_state = 0;
            } else if (quest->FUN_1407476d0() == 1) {
                link.m_state = 1;
            }
            if (link.m_state != 4) out.Add(link);
        }
    }
}
MS2_REPLACE_METHOD(0x1416ce860, CQuestManager, FUN_1416ce860, 896, 0x5366C6FA);

// @0x1416cebf0
int CQuestManager::FUN_1416cebf0(int npcId)
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cb8b0(quests, 1, 11, -1);
    for (size_t i = 0; i < quests.GetCount(); i++) {
        Unk_PayloadPtr<CQuest> quest = quests[i];
        if (quest->GetData()->m_2e8 == npcId) {
            Unk_QmTalkScript* script = FUN_1408564b0(quest->FUN_140bfc580(), 200).FUN_14078f3a0();
            if (script != 0) return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416cebf0, CQuestManager, FUN_1416cebf0, 480, 0x0CA9A6FA);

// @0x1416cede0
int CQuestManager::FUN_1416cede0(int value, unsigned* questId)
{
    *questId = 0;
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_1416cb8b0(quests, 1, 11, -1);
    FUN_1416cfc70(quests, 1, 0);
    for (size_t i = 0; i < quests.GetCount(); i++) {
        Unk_PayloadPtr<CQuest> quest = quests[i];
        int found = FUN_14074b0e0(quest->GetData().operator->(), value, 1);
        if (found != 0) {
            *questId = quest->FUN_140bfc580();
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416cede0, CQuestManager, FUN_1416cede0, 417, 0xCADF5D79);

// @0x1416cef90
void CQuestManager::FUN_1416cef90(int silent)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return;
    if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001b) return;
    for (POSITION pos = m_quests140.GetHeadPosition(); pos != 0; m_quests140.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests140.GetValueAt(pos);
        if (quest->FUN_1407476d0() != 1) continue;
        MS2Ptr<CQuestData> data = quest->GetData();
        for (size_t i = 0; i < data->m_conditions.GetCount(); i++) {
            MS2Ptr<CConditionCommonData> cond = data->m_conditions[i];
            if (cond.IsNull()) {
                MS2_ASSERT_AT(0x36e, 0);
                continue;
            }
            if (IsConditionTypeCounted(cond->m_nType) != 0) continue;
            int code = static_cast<int>(cond->m_code.GetFirstValue());
            __int64 have = 0;
            switch (cond->m_nType) {
            case 3:
            case 4:
                have = DAT_143ab2a90.FUN_140a5f180(code, 0);
                break;
            case 0x49:
                have = DAT_143ab2898;
                break;
            case 0xad: {
                ATL::CAtlArray<unsigned> ids;
                for (size_t j = 0; j < cond->m_code.m_ids.GetCount(); j++)
                    ids.Add(static_cast<unsigned>(cond->m_code.m_ids[j]));
                have = FUN_1416d3af0(ids);
                break;
            }
            }
            if (quest->GetProgress(static_cast<int>(i)) != have) {
                if (quest->IsConditionComplete(static_cast<int>(i)) != 0 && have > quest->GetProgress(static_cast<int>(i)))
                    continue;
                int increased = have > quest->GetProgress(static_cast<int>(i));
                quest->SetProgress(static_cast<int>(i), have);
                FUN_140bfc4b0()->vfunc_3(quest.get());
                FUN_1403ed2d0()->FUN_141bd3860();
                if (silent == 0 && increased != 0) {
                    quest->ShowProgress(static_cast<int>(i));
                    {
                        CString arg("");
                        FUN_141276180(quest->IsComplete() ? s_completeSound : s_progressSound, arg);
                    }
                    FUN_14138bf00(FUN_1409331e0(), 0x1d, quest->FUN_140bfc580(), static_cast<int>(have));
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416cef90, CQuestManager, FUN_1416cef90, 1381, 0x06014A2F);

// MS2-FUNCTIONAL: nested-if EH state map and payload-ptr temporaries differ from the exe's per-branch dtor calls.
// @0x1416cf510
void CQuestManager::FUN_1416cf510(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (!quest.IsNull()) {
        if (quest->FUN_1407441f0(FUN_1403ed2d0()->FUN_141bd3060()) != 0) {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(0xc);
            packet.vfunc_o10_3(questId);
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x1416cf510, CQuestManager, FUN_1416cf510, 275, 0x1A371415);

// MS2-FUNCTIONAL: nested-if EH state map and payload-ptr temporaries differ from the exe's per-branch dtor calls.
// @0x1416cf630
void CQuestManager::FUN_1416cf630(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (!quest.IsNull()) {
        if (quest->FUN_1407443e0(FUN_1403ed2d0()->FUN_141bd3060()) != 0) {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(0xd);
            packet.vfunc_o10_3(questId);
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x1416cf630, CQuestManager, FUN_1416cf630, 275, 0x5B9A8BE1);

// MS2-FUNCTIONAL: nested-if EH state map and payload-ptr temporaries differ from the exe's per-branch dtor calls.
// @0x1416cf750
void CQuestManager::FUN_1416cf750(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (!quest.IsNull()) {
        if (quest->FUN_140744670(FUN_1403ed2d0()->FUN_141bd3060()) != 0) {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(0x13);
            packet.vfunc_o10_3(questId);
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x1416cf750, CQuestManager, FUN_1416cf750, 275, 0x3F46AE05);

// @0x1416cf870
void CQuestManager::FUN_1416cf870(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull()) return;
    if (quest->FUN_140d738d0() != 0) {
        UIPopupNpcTalkDialog* dialog = Unk_QmFindDialog<UIPopupNpcTalkDialog>(0x4f4d);
        if (dialog != 0) dialog->FUN_140e771e0(questId);
    } else if (quest->FUN_140d738c0() != 0) {
        quest->FUN_140d738e0();
    }
}
MS2_REPLACE_METHOD(0x1416cf870, CQuestManager, FUN_1416cf870, 255, 0x3C816F04);

// @0x1416cf980
void CQuestManager::FUN_1416cf980(int questId, int leave)
{
    Unk_PayloadPtr<CQuest> quest = FUN_140764020()->vfunc_o10_3(questId);
    if (quest.IsNull()) return;
    if (quest->HasMultiUserRoom(FUN_1403ed2d0()->FUN_141bd3060()) == 0) return;
    MS2Ptr<CQuestData> data = quest->GetData();
    if (!data) return;
    Unk_QmRoomPtr room = FUN_14031c2a0()->FUN_1403206b0(data->m_roomId);
    if (!room) return;
    if (leave != 0) {
        COutPacket packet(0x2c, 0);
        packet.vfunc_o10_1(0x22);
        packet.vfunc_o10_1(FUN_1402178b0(room->m_1c));
        FUN_140710590(packet);
    } else {
        COutPacket packet(0x2c, 0);
        packet.vfunc_o10_1(0x20);
        packet.vfunc_o10_1(FUN_1402178b0(room->m_1c));
        packet.vfunc_o10_3(1);
        packet.vfunc_o10_3(data->m_roomId);
        packet.vfunc_o10_0(false);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1416cf980, CQuestManager, FUN_1416cf980, 642, 0xE6BF41EF);

// @0x1416cfc10
int CQuestManager::FUN_1416cfc10(int id)
{
    return FUN_140408410(&m_pinnedQuests, id) != -1;
}
MS2_REPLACE_METHOD(0x1416cfc10, CQuestManager, FUN_1416cfc10, 69, 0x04E4AE45);

// @0x1416cfc60
void CQuestManager::FUN_1416cfc60(int)
{
}
MS2_REPLACE_METHOD(0x1416cfc60, CQuestManager, FUN_1416cfc60, 10, 0x96F6F902);

// @0x1416cfc70
void CQuestManager::FUN_1416cfc70(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out, int state, int grade)
{
    for (POSITION pos = m_quests50.GetHeadPosition(); pos != 0; m_quests50.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests50.GetValueAt(pos);
        if (state != 4 && state != quest->FUN_1407476d0()) continue;
        if (grade != 0 && quest->GetData()->m_338.m_value != grade) continue;
        out.Add(quest);
    }
}
MS2_REPLACE_METHOD(0x1416cfc70, CQuestManager, FUN_1416cfc70, 415, 0x2680E591);

// @0x1416cfe20
int CQuestManager::FUN_1416cfe20()
{
    int count = 0;
    for (POSITION pos = m_quests50.GetHeadPosition(); pos != 0; m_quests50.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests50.GetValueAt(pos);
        if (quest->IsComplete() == 0) continue;
        switch (quest->GetData()->m_338.m_value) {
        case 3: case 4: case 5:
            count++;
            break;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416cfe20, CQuestManager, FUN_1416cfe20, 328, 0x5CA6FBBD);

// @0x1416cff70
int CQuestManager::FUN_1416cff70()
{
    int count = 0;
    for (POSITION pos = m_quests50.GetHeadPosition(); pos != 0; m_quests50.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests50.GetValueAt(pos);
        if (quest->IsComplete() == 0) continue;
        switch (quest->GetData()->m_338.m_value) {
        case 1: case 2:
            count++;
            break;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416cff70, CQuestManager, FUN_1416cff70, 328, 0x568D72E6);

// @0x1416d00c0
int CQuestManager::FUN_1416d00c0()
{
    int count = FUN_14037c510(FUN_140d738f0(), m_group);
    return count;
}
MS2_REPLACE_METHOD(0x1416d00c0, CQuestManager, FUN_1416d00c0, 46, 0x43BD140E);

// @0x1416d0100
int CQuestManager::FUN_1416d0100()
{
    int required = FUN_1416d00c0();
    int completed = FUN_1416d0150();
    return completed >= required;
}
MS2_REPLACE_METHOD(0x1416d0100, CQuestManager, FUN_1416d0100, 74, 0x2A623423);

// @0x1416d0150
int CQuestManager::FUN_1416d0150()
{
    int count = 0;
    for (POSITION pos = m_quests80.GetHeadPosition(); pos != 0; m_quests80.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests80.GetValueAt(pos);
        if (quest->FUN_1407476d0() == 2) {
            count = count + 1;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416d0150, CQuestManager, FUN_1416d0150, 176, 0xAC60CD7D);

// @0x1416d0210
int CQuestManager::FUN_1416d0210()
{
    return m_group == FUN_14037c610(FUN_140d738f0());
}
MS2_REPLACE_METHOD(0x1416d0210, CQuestManager, FUN_1416d0210, 62, 0xD8B73C66);

// @0x1416d0260
int CQuestManager::FUN_1416d0260(MS2Ptr<CLearningQuestData> learning, int checkRequirements)
{
    if (!learning) return 0;
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    if (checkRequirements != 0) {
        if (learning->m_nReqField != 0 && learning->m_nReqField != FUN_1403ed2d0()->FUN_141bd3060()) return 0;
        if (learning->m_nReqLevel > static_cast<unsigned short>(player->vfunc_78())) return 0;
    }
    MS2Ptr<CQuestData> data = FUN_14074bc40(learning->m_nReqQuest);
    if (data.IsNull()) return 0;
    if (FUN_140745630(learning->m_nReqQuest) != 0 || FUN_140745590(learning->m_nReqQuest) != 0) {
        if (FUN_1416ce3d0(data->m_28) != 0) return 0;
    } else if (vfunc_1(learning->m_nReqQuest, 0) == 0) {
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416d0260, CQuestManager, FUN_1416d0260, 701, 0x0FE8655A);

// @0x1416d0530
int CQuestManager::FUN_1416d0530()
{
    ATL::CAtlArray<CLearningQuestTable::DataPtr> rows;
    FUN_140ea4060()->GetAll(rows);
    int count = 0;
    for (size_t i = 0; i < rows.GetCount(); i++) {
        if (FUN_1416d0260(rows[i], 0) != 0) count++;
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416d0530, CQuestManager, FUN_1416d0530, 209, 0x315C3DCF);

// @0x1416d0610
int CQuestManager::FUN_1416d0610()
{
    if (m_requestTick == 0) return 0;
    unsigned now = FUN_141472bc0();
    if (m_requestTick + *FUN_1401d3200()->QuestPortalSummonTime.Get() < now) return 0;
    if (now < m_requestTick) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1416d0610, CQuestManager, FUN_1416d0610, 111, 0x70EBE08B);

// MS2-FUNCTIONAL: the exe receives the field object handle as a by-value return (EH state starts after the
// call); worldservice.h declares FUN_141bc2800 with an out parameter, so the handle is live from its declaration.
// @0x1416d0690
Unk_StreamPoint CQuestManager::FUN_1416d0690()
{
    Unk_QmFieldHandle target;
    FUN_1403ed2d0()->FUN_141bc2800(&target, m_targetObject);
    if (target.IsNull()) return DAT_143b01a60;
    return target->FUN_14169d2f0();
}
MS2_REPLACE_METHOD(0x1416d0690, CQuestManager, FUN_1416d0690, 158, 0x580CD80D);

// @0x1416d0740
void CQuestManager::FUN_1416d0740()
{
    m_field180 = 1;
}
MS2_REPLACE_METHOD(0x1416d0740, CQuestManager, FUN_1416d0740, 21, 0xDA904E61);

// @0x1416d0760
int CQuestManager::FUN_1416d0760()
{
    return m_field180;
}
MS2_REPLACE_METHOD(0x1416d0760, CQuestManager, FUN_1416d0760, 17, 0xDC2CA4CA);

// @0x1416d0780
int CQuestManager::FUN_1416d0780(int id)
{
    int count;
    m_dailyCounts.Lookup(id, count);
    return count;
}
MS2_REPLACE_METHOD(0x1416d0780, CQuestManager, FUN_1416d0780, 50, 0xD13FF482);

// @0x1416d07c0
int CQuestManager::FUN_1416d07c0(int id)
{
    int count;
    m_weeklyCounts.Lookup(id, count);
    return count;
}
MS2_REPLACE_METHOD(0x1416d07c0, CQuestManager, FUN_1416d07c0, 50, 0x10DEA3FA);

// MS2-FUNCTIONAL: std::vector iterator COMDATs differ from the exe's raw _Myfirst/_Mylast reads.
// @0x1416d0920
void CQuestManager::FUN_1416d0920(ATL::CAtlArray<unsigned>& out)
{
    std::vector<unsigned>& ids = FUN_1407476c0()->FUN_14074e0d0();
    for (std::vector<unsigned>::iterator it = ids.begin(); it != ids.end(); ++it) {
        unsigned id = *it;
        if (vfunc_1(id, 0) != 0) {
            out.Add(id);
        }
    }
}
MS2_REPLACE_METHOD(0x1416d0920, CQuestManager, FUN_1416d0920, 161, 0xFE6413A2);

// @0x1416d0800
int CQuestManager::FUN_1416d0800(int id)
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d360(id, ids);
    for (size_t i = 0; i < ids.GetCount(); i++) {
        unsigned questId = ids[i];
        if (FUN_140745630(questId) == 0) continue;
        MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
        if (data.IsNull()) continue;
        return data->m_4c;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416d0800, CQuestManager, FUN_1416d0800, 272, 0x289A6E7D);

// @0x1416d09d0
int CQuestManager::FUN_1416d09d0(int mapId, int warn)
{
    unsigned questId = FUN_14035b590(FUN_140764010(), 1);
    if (FUN_140764020()->FUN_140745590(questId) == 0) {
        if (warn != 0) {
            FUN_1412751f0(FUN_1405c2690(CStringW(L"s_sky_fortress_warn_quest"), FUN_1416e4df0(questId)), 1, 1);
        }
        return 0;
    }
    if (FUN_1403ed2d0()->FUN_141bd3060() == mapId) {
        if (warn != 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_sky_fortress_warn_field")), 1, 1);
        }
        return 0;
    }
    if (FUN_1403ed2d0()->FUN_141bd3060() != 62000000 && FUN_1409312f0() == 0) {
        if (warn != 0) {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_sky_fortress_warn_field")), 1, 1);
        }
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1416d09d0, CQuestManager, FUN_1416d09d0, 570, 0xAE4283FA);

// @0x1416d0c10
void CQuestManager::FUN_1416d0c10()
{
    if (FUN_1416d09d0(*FUN_1401d3200()->FameContentsSkyFortressGotoMapID.Get(), 1) != 0) {
        COutPacket packet(0x29, 0);
        packet.vfunc_o10_1(0xe);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1416d0c10, CQuestManager, FUN_1416d0c10, 118, 0xAC4E24C6);

// @0x1416d0e20
int CQuestManager::FUN_1416d0e20()
{
    return *FUN_1401d3200()->FameContentsMissionAttackCount.Get() - m_refreshCount;
}
MS2_REPLACE_METHOD(0x1416d0e20, CQuestManager, FUN_1416d0e20, 48, 0x5BDD4442);

// @0x1416d0c90
void CQuestManager::FUN_1416d0c90(int id)
{
    if (FUN_14025e7b0()->m_shutdown.Get(static_cast<CContentShutdown::Content>(0x53)) != 0) {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (FUN_1416d09d0(id, 1) == 0) return;
    if (FUN_1416d0e60(id) == 0) return;
    if (m_refreshCount >= *FUN_1401d3200()->FameContentsMissionAttackCount.Get()) {
        CStringW key(L"s_sky_fortress_warn_attack");
        FUN_1412751f0(FUN_14028b8e0(key), 1, 1);
        return;
    }
    m_refreshCount++;
    COutPacket packet(0x29, 0);
    packet.vfunc_o10_1(0xf);
    packet.vfunc_o10_3(id);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1416d0c90, CQuestManager, FUN_1416d0c90, 381, 0x1C198416);

// @0x1416d0e60
int CQuestManager::FUN_1416d0e60(int id)
{
    return FUN_1416d0800(id) != 0;
}
MS2_REPLACE_METHOD(0x1416d0e60, CQuestManager, FUN_1416d0e60, 58, 0xBEE746D6);

// @0x1416d0ea0
bool CQuestManager::FUN_1416d0ea0(int result, const CMsgBoxData& message)
{
    if (result != 0) return true;
    unsigned id = FUN_141a02e90(&message, 0, 0);
    int count = FUN_141a02e50(&message, 1, 0);
    COutPacket packet(0x29, 0);
    packet.vfunc_o10_1(0x14);
    packet.vfunc_o10_3(id);
    packet.vfunc_o10_2(static_cast<short>(count));
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1416d0ea0, CQuestManager, FUN_1416d0ea0, 186, 0x7E1A7D4B);

// @0x1416d0f60
int CQuestManager::FUN_1416d0f60(int epilogue)
{
    ATL::CAtlArray<CChapterBookTable::DataPtr> books;
    FUN_140e0a9f0()->GetByEpilogue(epilogue, books);
    for (size_t i = 0; i < books.GetCount(); i++) {
        CChapterBookTable::DataPtr book = books[i];
        if (FUN_140745590(book->m_nPrologue) != 0) return book->m_nId;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416d0f60, CQuestManager, FUN_1416d0f60, 248, 0xB2F5179C);

// @0x1416d1100
unsigned CQuestManager::FUN_1416d1100(int npcId, int questId, int* state)
{
    unsigned flags = 0;
    if (FUN_140764020()->vfunc_1(questId, npcId) != 0) {
        *state = 0;
        flags |= 0x20;
    } else if (FUN_140764020()->FUN_140746850(questId, npcId, 0) != 0) {
        *state = 1;
        flags |= 0x10;
    } else if (FUN_140764020()->FUN_140746ba0(questId, npcId, 0) == 0) {
        *state = 2;
        flags |= 0x30;
    } else {
        *state = 4;
        return 0;
    }
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.IsNull()) return 0;
    if (FUN_140764040(data.operator->()))
        flags |= 4;
    else if (FUN_140764080(data.operator->()))
        flags |= 3;
    else if (FUN_1407640c0(data.operator->()))
        flags |= 1;
    else
        flags |= 2;
    return flags;
}
MS2_REPLACE_METHOD(0x1416d1100, CQuestManager, FUN_1416d1100, 449, 0x7A2F3290);

// @0x1416d1060
void CQuestManager::FUN_1416d1060(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out)
{
    for (POSITION pos = m_quests110.GetHeadPosition(); pos != 0; m_quests110.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests110.GetValueAt(pos);
        out.Add(quest);
    }
}
MS2_REPLACE_METHOD(0x1416d1060, CQuestManager, FUN_1416d1060, 152, 0xCE32F7F4);

// @0x1416d12d0
int CQuestManager::FUN_1416d12d0(int npcId, Unk_QmNpcQuestState* state, int all)
{
    const std::vector<unsigned>* quests = FUN_1407476c0()->FUN_14074e0f0(npcId);
    if (quests == 0) return 0;
    state->FUN_1409669c0();
    state->m_npcId = npcId;
    std::vector<Unk_QmNpcQuestEntry> entries;
    int best = 0;
    for (unsigned questId : *quests) {
        int questState = 4;
        if (all == 0 && FUN_1409a8b10()->FUN_140c9b8b0()->FUN_141261b90(questId) == 0) continue;
        int score = FUN_1416d1100(npcId, questId, &questState);
        if (score > best) {
            best = score;
            state->m_state = questState;
            state->m_questId = questId;
            state->m_icon = FUN_14074bc90(questId);
        }
        if (score != 0 && state->m_wantText != 0) {
            Unk_QmNpcQuestEntry entry;
            entry.m_score = score;
            entry.m_questId = questId;
            entry.m_state = questState;
            entries.push_back(entry);
        }
    }
    if (state->m_wantText != 0) {
        std::sort(entries.begin(), entries.end(), [bestQuest = state->m_questId](const Unk_QmNpcQuestEntry& a, const Unk_QmNpcQuestEntry& b) {
            if (a.m_questId == bestQuest) return true;
            if (b.m_questId == bestQuest) return false;
            if (a.m_score == b.m_score) {
                MS2Ptr<CQuestData> dataA = FUN_14074bc40(a.m_questId);
                MS2Ptr<CQuestData> dataB = FUN_14074bc40(b.m_questId);
                if (dataA.IsNull() || dataB.IsNull()) return false;
                return dataA->m_level > dataB->m_level;
            }
            return a.m_score > b.m_score;
        });
        CStringW text;
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it != entries.begin()) text.Append(L"\n");
            text.Append(FUN_140763550(it->m_questId, it->m_state));
        }
        state->m_text = FUN_14052bd00(0x73f, text);
    }
    return state->m_state != 4;
}
MS2_REPLACE_METHOD(0x1416d12d0, CQuestManager, FUN_1416d12d0, 987, 0x181F2CD6);

// @0x1416d16c0
void CQuestManager::FUN_1416d16c0(int group, ATL::CAtlList<unsigned>& out)
{
    Unk_FieldIdList npcs(10);
    FUN_140700390()->FUN_1406fb900(FUN_1403ed2d0()->FUN_141bd3060(), group, npcs);
    ATL::CAtlArray<Unk_QmNpcQuestState> states;
    for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
        unsigned npcId = npcs.GetAt(pos);
        if (FUN_14109a710()->FUN_140764e40(group, npcId) == 0) continue;
        Unk_QmNpcQuestState state;
        if (FUN_1416d12d0(npcId, &state, 0) != 0) out.AddTail(npcId);
    }
}
MS2_REPLACE_METHOD(0x1416d16c0, CQuestManager, FUN_1416d16c0, 306, 0x0FAF77D9);

// @0x1416d1800
void CQuestManager::FUN_1416d1800(int group, Unk_QmNpcQuestState* best)
{
    Unk_FieldIdList npcs(10);
    FUN_140700390()->FUN_1406fb900(FUN_1403ed2d0()->FUN_141bd3060(), group, npcs);
    ATL::CAtlArray<Unk_QmNpcQuestState> states;
    for (POSITION pos = npcs.GetHeadPosition(); pos != 0; npcs.GetNext(pos)) {
        unsigned npcId = npcs.GetAt(pos);
        if (FUN_14109a710()->FUN_140764e40(group, npcId) == 0) continue;
        Unk_QmNpcQuestState state;
        if (FUN_1416d12d0(npcId, &state, 0) != 0) states.Add(state);
    }
    int bestScore = 0;
    for (size_t i = 0; i < states.GetCount(); i++) {
        int npcId = states[i].m_npcId;
        unsigned questId = states[i].m_questId;
        int state = states[i].m_state;
        int score = FUN_1416d1100(npcId, questId, &state);
        if (score > bestScore) {
            bestScore = score;
            best->m_npcId = npcId;
            best->m_state = state;
            best->m_questId = questId;
            best->m_icon = FUN_14074bc90(questId);
        }
    }
}
MS2_REPLACE_METHOD(0x1416d1800, CQuestManager, FUN_1416d1800, 553, 0x44156FC6);

// @0x1416d1a30
void CQuestManager::FUN_1416d1a30(int questId)
{
    WorldService* world = FUN_1403ed2d0();
    if (world == 0) return;
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull()) {
        MS2_ASSERT_AT(0x963, 0);
        return;
    }
    if (quest->IsActive() == 0) return;
    if (quest->IsComplete() == 1) return;
    if (m_targets250.end() == m_targets250.find(questId))
        m_targets250[questId] = std::set<__int64>();
    ATL::CRBMap<unsigned, Unk_WsV118>* users = world->FUN_141bd36b0();
    for (POSITION pos = users->GetHeadPosition(); pos != 0; users->GetNext(pos)) {
        PCBase* pc = FUN_140aac420(&users->GetValueAt(pos));
        if (pc == 0) continue;
        if (world->FUN_141bd0cc0() == pc) continue;
        if (quest->CheckUserFind(pc) == 0) continue;
        m_targets250[questId].insert(pc->FUN_141656a80());
    }
}
MS2_REPLACE_METHOD(0x1416d1a30, CQuestManager, FUN_1416d1a30, 699, 0x9270EB9B);

// @0x1416d1d00
void CQuestManager::FUN_1416d1d00(PCBase* pc)
{
    if (pc != 0) {
        for (std::map<int, std::set<__int64> >::iterator it = m_targets250.begin(); it != m_targets250.end(); ++it) {
            int questId = it->first;
            Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
            if (!quest.IsNull()) {
                if (quest->CheckUserFind(pc) != 0) {
                    m_targets250[questId].insert(pc->FUN_141656a80());
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1416d1d00, CQuestManager, FUN_1416d1d00, 389, 0x1360BBF1);

// @0x1416d1e90
std::pair<unsigned, __int64> CQuestManager::FUN_1416d1e90()
{
    std::pair<unsigned, __int64> best(0, 0);
    WorldService* world = FUN_1403ed2d0();
    if (world == 0) return best;
    if (CFieldData::FUN_1403744a0(world->FUN_141bd3060())) return best;
    PCBase* player = static_cast<PCBase*>(world->FUN_141bd0cc0());
    if (player == 0) return best;
    float bestDistance = FLT_MAX;
    const NiPoint3& playerPos = player->vfunc_18();
    std::list<unsigned> stale;
    for (std::map<int, std::set<__int64>>::iterator it = m_targets250.begin(); it != m_targets250.end(); ++it) {
        const unsigned questId = it->first;
        Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
        if (quest.IsNull()) {
            stale.push_back(questId);
            continue;
        }
        if (quest->IsActive() == 0) {
            stale.push_back(questId);
            continue;
        }
        if (quest->IsComplete() != 0) {
            stale.push_back(questId);
            continue;
        }
        std::list<__int64> gone;
        std::set<__int64>& users = it->second;
        for (std::set<__int64>::iterator user = users.begin(); user != users.end(); ++user) {
            const __int64 userId = *user;
            if (userId == player->FUN_141656a80()) {
                gone.push_back(questId);
                continue;
            }
            PCBase* pc = reinterpret_cast<Unk_QmWorld*>(world)->FUN_141bd1530(userId);
            if (pc == 0) {
                gone.push_back(questId);
                continue;
            }
            if (quest->CheckUserFind(pc) == 0) {
                gone.push_back(questId);
                continue;
            }
            if (pc->FUN_141670a00(4) <= 0) continue;
            if (pc->FUN_141674bc0() != 0) continue;
            float distance = FUN_140966f00(playerPos, pc->vfunc_18());
            if (distance < bestDistance) {
                bestDistance = distance;
                best = std::pair<unsigned, __int64>(questId, userId);
            }
        }
        MS2_FOR_EACH(__int64 id, gone) users.erase(id);
    }
    MS2_FOR_EACH(int id, stale) m_targets250.erase(id);
    return best;
}
MS2_REPLACE_METHOD(0x1416d1e90, CQuestManager, FUN_1416d1e90, 1657, 0x68DA91B1);

// @0x1416d2510
const std::set<__int64>& CQuestManager::FUN_1416d2510(int questId)
{
    static std::set<__int64> s_empty;
    if (m_targets250.find(questId) == m_targets250.end()) return s_empty;
    return m_targets250[questId];
}
MS2_REPLACE_METHOD(0x1416d2510, CQuestManager, FUN_1416d2510, 234, 0xD6DE581E);

// @0x1416d2600
unsigned CQuestManager::FUN_1416d2600(int questId, int checkAccept)
{
    std::list<unsigned> next;
    if (FUN_1416d26c0(questId, next, checkAccept) == 0) return 0;
    return next.empty() ? 0 : *next.begin();
}
MS2_REPLACE_METHOD(0x1416d2600, CQuestManager, FUN_1416d2600, 173, 0x8B7C30EA);

// @0x1416d26c0
int CQuestManager::FUN_1416d26c0(int questId, std::list<unsigned>& out, int checkAccept)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    int job = FUN_141654700(player);
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data == 0) return 0;
    std::list<unsigned> found;
    for (size_t i = 0; i < data->m_require.m_followingQuests.GetCount(); i++) {
        unsigned next = data->m_require.m_followingQuests[i];
        MS2Ptr<CQuestData> nextData = FUN_14074bc40(next);
        if (FUN_1416d3ed0(nextData, checkAccept, job) == 0) continue;
        found.push_back(next);
    }
    if (!found.empty()) out.insert(out.end(), found.begin(), found.end());
    return 1;
}
MS2_REPLACE_METHOD(0x1416d26c0, CQuestManager, FUN_1416d26c0, 583, 0xE822ACDB);
// @0x1416d2910
// Debug trace of the follow-up quest paths from each progressing epic quest to toQuestId.
int CQuestManager::FUN_1416d2910(unsigned toQuestId, std::list<std::list<unsigned>>& paths, int verbose)
{
    if (toQuestId == 0) return 0;
    auto log = [verbose](CStringW text) {
        if (verbose) FUN_1412751b0(text, 0x14);
    };
    auto logPath = [verbose](const std::list<unsigned>& path) {
        if (verbose) {
            CStringW text(L"[S]");
            for (__int64 questId : path) {
                int level = -1;
                MS2Ptr<CQuestData> data = FUN_14074bc40(static_cast<int>(questId));
                if (data.get()) level = data->m_28;
                text += StringFormat(L" -> [{0}] {1}", level, questId);
            }
            text += L"-> [E]";
            FUN_1412751b0(text, 0x14);
        }
    };
    std::vector<unsigned> epics;
    FUN_140764020()->FUN_1416cb4d0(epics, {0, 1, 3}, 0, -1);
    if (epics.empty()) {
        log(L"There is none progressEpicQuest.");
        return 0;
    }
    int found = 0;
    for (unsigned fromQuestId : epics) {
        std::list<unsigned> path;
        path.emplace_back(fromQuestId);
        log(StringFormat(L"Start trace fromQuestID({0}) toQuestID({1})", fromQuestId, toQuestId));
        std::list<std::list<unsigned>> reached;
        std::list<std::list<unsigned>> notReached;
        int result = FUN_1416d40a0(0, fromQuestId, toQuestId, path, reached, &notReached);
        if (found == 0 && result == 1) found = result;
        log(StringFormat(L"-- Reached path count({0})) --", reached.size()));
        if (!reached.empty()) {
            for (const std::list<unsigned>& p : reached) logPath(p);
            paths.insert(paths.end(), reached.begin(), reached.end());
        }
        log(StringFormat(L"-- Not reached path count({0})) --", notReached.size()));
        if (!notReached.empty()) {
            for (const std::list<unsigned>& p : notReached) logPath(p);
        }
        log(StringFormat(L"End trace fromQuestID({0}) toQuestID({1})", fromQuestId, toQuestId));
    }
    return found;
}
MS2_REPLACE_METHOD(0x1416d2910, CQuestManager, FUN_1416d2910, 1561, 0xD75123E5);

// @0x1416d3010
void CQuestManager::FUN_1416d3010()
{
    if (FUN_140aa6d30()->FUN_1417e2610() == 0x620000c) {
        ATL::CAtlArray<unsigned> changed;
        POSITION pos = m_quests140.GetHeadPosition();
        while (pos != 0) {
            Unk_PayloadPtr<CQuest> quest = m_quests140.GetValueAt(pos);
            if (quest->FUN_1407476d0() == 1) {
                CQuestCommon* common = quest.operator->();
                int tracked = common->FUN_1407447c0();
                if (tracked != 0) {
                    if (quest->GetTrackedValue() != tracked) {
                        quest->SetTrackedValue(tracked);
                        changed.Add(quest->FUN_140bfc580());
                    }
                }
            }
            m_quests140.GetNext(pos);
        }
        if (changed.GetCount() != 0) {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(7);
            packet.vfunc_o10_3(static_cast<int>(changed.GetCount()));
            for (size_t i = 0; i < changed.GetCount(); i = i + 1) {
                packet.vfunc_o10_3(changed[i]);
            }
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x1416d3010, CQuestManager, FUN_1416d3010, 521, 0x13087605);

// @0x1416d3220
void CQuestManager::FUN_1416d3220()
{
    if (FUN_1416d3430() != 0) return;
    FUN_1416d3510();
}
MS2_REPLACE_METHOD(0x1416d3220, CQuestManager, FUN_1416d3220, 40, 0xAE052B5E);

// @0x1416d3250
void CQuestManager::FUN_1416d3250()
{
    if (FUN_140aa6d30()->FUN_1417e2610() == 0x620000c) {
        ATL::CAtlArray<unsigned> candidates;
        FUN_1407476c0()->FUN_14074d080(FUN_1403ed2d0()->FUN_141bd3060(), candidates);
        ATL::CAtlArray<unsigned> available;
        for (size_t i = 0; i < candidates.GetCount(); i = i + 1) {
            unsigned questId = candidates[i];
            if (vfunc_o10_1(questId) != 0 && FUN_140746e60(questId) != 0) {
                available.Add(questId);
            }
        }
        if (available.GetCount() != 0) {
            COutPacket packet(0x29, 0);
            packet.vfunc_o10_1(8);
            packet.vfunc_o10_3(static_cast<int>(available.GetCount()));
            for (size_t i = 0; i < available.GetCount(); i = i + 1) {
                packet.vfunc_o10_3(available[i]);
            }
            FUN_140710590(packet);
        }
    }
}
MS2_REPLACE_METHOD(0x1416d3250, CQuestManager, FUN_1416d3250, 469, 0x108875E9);

// @0x1416d3430
int CQuestManager::FUN_1416d3430()
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d) return 0;
    {
        for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
            Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
            CQuest* current = quest.operator->();
            if (current->FUN_140d73970() != 0) {
                return 1;
            }
            }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416d3430, CQuestManager, FUN_1416d3430, 216, 0x2CD58E85);

// @0x1416d3510
// Opens the start talk of the first acceptable quest that auto-talks on this map (m_320: 1, map id or 0 for any).
int CQuestManager::FUN_1416d3510()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1407476c0()->FUN_14074d410(ids);
    int mapId = FUN_1403ed2d0()->FUN_141bd3060();
    for (size_t i = 0; i < ids.GetCount(); i++) {
        MS2Ptr<CQuestData> data = FUN_14074bc40(ids[i]);
        if (!data) continue;
        if (data->m_320.m_0 != 1) continue;
        if (data->m_320.m_4 != 0 && data->m_320.m_4 != mapId) continue;
        if (data->m_320.m_4 == 62000000 && FUN_1418fd280() == 0) continue;
        if (vfunc_1(FUN_14074b030(data.operator->()), 0) == 0) continue;
        Unk_QmTalkScriptPtr script = FUN_1408564b0(FUN_14074b030(data.operator->()), 100);
        if (script.IsNull()) continue;
        FUN_140967100()->FUN_141b213f0(script, data->m_2e8, 4, 0);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416d3510, CQuestManager, FUN_1416d3510, 668, 0x62D747D2);

// @0x1416d3af0
// Number of distinct worn item ids that are in itemIds.
int CQuestManager::FUN_1416d3af0(const ATL::CAtlArray<unsigned>& itemIds)
{
    PC* player = static_cast<PC*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    ATL::CAtlList<MS2Ptr<CEquipItem>> equips(10);
    FUN_1411e1b80(player->FUN_1416561a0(), equips);
    std::set<unsigned> found;
    int count = 0;
    for (POSITION pos = equips.GetHeadPosition(); pos != 0; equips.GetNext(pos)) {
        MS2Ptr<CEquipItem> equip = equips.GetAt(pos);
        MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
        if (item->FUN_140529620()) continue;
        if (FUN_140408410(&itemIds, item->FUN_1405276c0()) == -1) continue;
        if (found.find(item->FUN_1405276c0()) != found.end()) continue;
        found.insert(item->FUN_1405276c0());
        count++;
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416d3af0, CQuestManager, FUN_1416d3af0, 596, 0x3F41CBCE);

// @0x1416d3ed0
int CQuestManager::FUN_1416d3ed0(MS2Ptr<CQuestData> data, int checkAccept, int job)
{
    if (data == 0) return 0;
    if (FUN_14074b050(data.operator->()) != 0) return 0;
    if (data->m_30 != 0) return 0;
    if (data->m_require.m_job.GetCount() != 0) {
        if (job == 200) {
            PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
            if (player == 0) return 0;
            job = FUN_141654700(player);
        }
        if (FUN_1407474d0(&data->m_require.m_job, &job) == -1) return 0;
    }
    if (checkAccept != 0) return vfunc_1(FUN_14074b030(data.operator->()), 0);
    return 1;
}
MS2_REPLACE_METHOD(0x1416d3ed0, CQuestManager, FUN_1416d3ed0, 456, 0x455541D4);

// @0x1416d40a0
// Depth-first walk of the follow-up quests; each finished path goes to reached (toQuestId hit) or notReached.
int CQuestManager::FUN_1416d40a0(int depth, unsigned fromQuestId, unsigned toQuestId, std::list<unsigned>& path,
    std::list<std::list<unsigned>>& reached, std::list<std::list<unsigned>>* notReached)
{
    auto finish = [&path, &reached, notReached](int ok) {
        if (ok == 1) reached.push_back(path);
        else if (notReached != 0) notReached->push_back(path);
    };
    if (++depth >= 30000) {
        finish(0);
        return 0;
    }
    if (fromQuestId == toQuestId) {
        finish(1);
        return 1;
    }
    int result = 0;
    std::list<unsigned> next;
    if (FUN_1416d26c0(fromQuestId, next, 0) == 0 || next.empty()) {
        finish(0);
        return 0;
    }
    int found = 0;
    for (unsigned questId : next) {
        std::list<unsigned> branch(path);
        branch.emplace_back(questId);
        int r = FUN_1416d40a0(depth, questId, toQuestId, branch, reached, notReached);
        if (found == 0 && r == 1) found = 1;
    }
    return found;
}
MS2_REPLACE_METHOD(0x1416d40a0, CQuestManager, FUN_1416d40a0, 574, 0x977F811D);

// @0x1416dbb50
CQuestManagerCommon::CQuestManagerCommon() : m_selector(0) {}

MS2_EMIT_CRT_MEMMOVE_S();
