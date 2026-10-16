// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ActionKeyObject and its 26 subclasses (the context actions of
// the action key) and MyPC's action set (Unk_ActionKeyManager).
// MS2-UNIT: ?\actionkeyobject.cpp
// MS2-RANGE: 0x140951c70-0x14096b300 .text$mn
// MS2-RANGE: 0x1400bf670-0x1400bf7b0 .text$di
//
// The unit has no __FILE__ string; its name comes from the classes and its directory is assumed. Names are Ghidra's
// (vfunc_<slot> / FUN_<va>) unless the exe has one (RTTI). The COMDAT tail: the action maps (CRBMap<int,
// MS2Ptr<ActionKeyObject>>), the entity smart pointers, the UI lookups (dynamic_cast to the dialog types), the
// PortalAction message-box delegate and the singleton accessors.
// TaxiStationAction / FishingAction have byte-identical implicit destructors (two exe copies each):
// MS2-PIN: ??1TaxiStationAction@@UEAA@XZ 0x140953ba0
// MS2-PIN: ??1FishingAction@@UEAA@XZ 0x140953b80
// MS2-PIN: ??_GTaxiStationAction@@UEAAPEAXI@Z 0x140953ca0
// MS2-PIN: ??_GFishingAction@@UEAAPEAXI@Z 0x140953c60
// The UI lookup template's instances differ only in the RTTI they cast to:
// MS2-PIN: ??$Unk_GetUI@VUIActionTooltip@@@@YAPEAVUIActionTooltip@@H@Z 0x1409537f0
// MS2-PIN: ??$Unk_GetUI@VUIDungeonRoomDialog@@@@YAPEAVUIDungeonRoomDialog@@H@Z 0x140961550
// MS2-PIN: ??$Unk_GetUI@VUIWorldMapDialog@@@@YAPEAVUIWorldMapDialog@@H@Z 0x140961730
// MS2-PIN: ??$Unk_GetUI@VUIGuildFlagTooltip@@@@YAPEAVUIGuildFlagTooltip@@H@Z 0x1409615f0
// MS2-PIN: ??$Unk_GetUI@VUIRealEstateDialog@@@@YAPEAVUIRealEstateDialog@@H@Z 0x140961690
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\actionkeyobject.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

// ---- header statics (.text$di): a shared header's sort names and condition keys, then egf's kENTITY_INVALID --------
// @0x1400bf670
static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400bf730
static CString s_skill("skill");
// @0x1400bf760
static CString s_stun("stun");

#include "actionkeyobject.h"
#include "worldservice.h"
#include "mypc.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/cube.h"
#include "ms2/placeholder/clientconstants.h"
#include "statedata.h"
#include "functioncubeobject.h"
#include "entityworldmanager.h"
#include <efd/ServiceManager.h>
#include "interactobject.h"
#include "reactor.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "uidialog.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/unnamed/unit_140ad1860.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <atlcoll.h>

// ---- unrecovered neighbours ------------------------------------------------------------------------------------------
unsigned FUN_140869420();                                   // the frame tick (ms)
WorldService* FUN_1403ed2d0();
CStringW FUN_14028de60(int nStringId);                      // the client string table
CStringW FUN_14016a730(const char* psz, int nCodePage);      // multi-byte to wide

// A portal of the field (the world service's field objects; class of unit_14169afb0, unrecovered); only the members
// read here.
class Unk_AkoPortal : public CPtred
{
public:
    CStringW FUN_14169c3b0();                               // the portal's name
    int FUN_14169d280();                                    // moves to another field
    Unk_StreamPoint FUN_14169d2f0();                        // the portal's position
    egf::EntityID m_entityId;                               // +0x18 id of the egf entity
    char m_pad_20[0x14c - 0x20];
    int m_nFieldId;                                         // +0x14c the target field
    char m_pad_150[0x158 - 0x150];
    __int64 m_nOwnerId;                                     // +0x158 the house owner (house portals)
    int m_nType;                                            // +0x160
    char m_pad_164[0x18c - 0x164];
    bool m_bConfirm;                                        // +0x18c ask before moving
};
MS2_CHECK_OFFSET(Unk_AkoPortal, m_entityId, 0x18);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nFieldId, 0x14c);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nOwnerId, 0x158);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_nType, 0x160);
MS2_CHECK_OFFSET(Unk_AkoPortal, m_bConfirm, 0x18c);

// A cell of the cube map (the cube at a position); only the cube id is read here.
class Unk_AkoCell
{
public:
    char m_pad_00[0x50];
    int m_nCubeId;                                          // +0x50
};
MS2_CHECK_OFFSET(Unk_AkoCell, m_nCubeId, 0x50);

// The cube map service (efd class id 0x06100017; named as in buddy.cpp); FUN_1401cd040 looks it up in the framework's
// service manager.
class Unk_Service6100017 : public efd::ISystemService
{
public:
    Unk_StreamPoint FUN_1410b7ad0(PCBase* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap);  // the cell in front of the actor
    Unk_StreamPoint FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut);   // the cell position of a point
    Unk_AkoCell* FUN_1410b8ab0(Unk_StreamPoint pt);         // the cell at a cell position
    void FUN_1410ccc00(int nMapId, int nType, int nSize);   // show the map's owner profile
    int FUN_1410c8580(int nGroup);                          // the error code for buying a house group (0 = ok)
    CStringW FUN_1410d5d80(int nError);                     // the text of a house error code
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;                // the game framework
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* pFramework);

// The house service singleton (global 0x143ab3908).
class Unk_AkoHouseSvc : public TSingleton<Unk_AkoHouseSvc>
{
public:
    __int64 FUN_1410c3180();                                // the owner account of the current house
    bool FUN_1410cb920(int nCooldown);                      // the move cooldown is over
};

// The guide manager (global 0x143ab3330).
class Unk_AkoGuide
{
public:
    void FUN_14138bf00(int nGuide, int nA, int nB);         // a guide event
    int FUN_14138c900(int nGuide);                          // the guide is running
};
Unk_AkoGuide* FUN_1409331e0();

extern int DAT_143ab288c;                                   // the id of the last portal used
extern __int64 DAT_143ab2820;                               // the account id
void FUN_141b71e70(egf::EntityID id, bool bEnable, unsigned uColor, bool bSkipEffectRoot);   // highlight an entity
void FUN_140d73aa0(CStringW strText, int nType, int nArg, CStringW strArg);   // a system notice text
void FUN_140d73bc0(int nStringId, int nType, IMessageListener* pListener, CStringW strArg);   // a system notice
void FUN_1408a0890(int nMapId, int nCubeId, int* pnKind);   // the kind of the cube on a map
void FUN_140dff580(int nTarget, int nPortalId);             // the shop portal (type 0x10)

class UIActionTooltip : public UIHeadUpDisplay
{
public:
    ActionKeyObject* FUN_1418b17d0();                       // the action shown
    CStringW FUN_1418b17f0();                               // the title shown
    CStringW FUN_1418b1840();                               // the text shown
    void FUN_1418b16f0();                                   // refresh from the current action
};

class Unk_AkoUIRef
{
public:
    ~Unk_AkoUIRef();                                        // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* m_unk_00;
    UIObject* m_p;
};
MS2_CHECK_SIZE(Unk_AkoUIRef, 0x10);
class Unk_AkoUIMgr
{
public:
    Unk_AkoUIRef FUN_141adcea0(int nUiId);                  // the ui by id
    void FUN_141adc750(int nUiId);                          // toggle the ui by id
    int FUN_141adc940(int nUiId);                           // is open
    int FUN_141adc890(int nUiId);                           // is shown
    void FUN_141adc5d0(int nUiId);                          // hide
    void FUN_141adc530(int nUiId);                          // close
};
Unk_AkoUIMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_AkoUIRef&);

// The UI by id, cast to its class (a template: one COMDAT per class in first-use order, see the pins at the top).
template <class T> T* Unk_GetUI(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_AkoUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<T*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

class UIDungeonRoomDialog : public UIDialog
{
public:
    bool FUN_1412b8f00(int nPortalId);                      // the room list has the portal
    void FUN_1412b8ff0(int nArg);
    void FUN_1412b90d0(int nMode);
    void FUN_1412b90f0(int nPortalId);                      // select the portal's rooms
};
// The world service's lift / prop records (WorldService::FUN_141bc5a20 / FUN_141bc66b0); a prop is an interact object.
class Unk_WsB_Lift : public CPtred
{
public:
    int FUN_141447cc0();                                    // the lift's item id
};
class Unk_WsB_Prop : public CInteractObject
{
};
// The npc table row; only the talk script name is read here.
class Unk_AkoNpcData : public CPtred
{
public:
    unsigned char m_unk_18[0x448];
    CString m_strTalkScript;                                // +0x460
};
MS2_CHECK_OFFSET(Unk_AkoNpcData, m_strTalkScript, 0x460);
// The player's interact mode (PC +0x1240): while active it picks the kind of object to interact with.
class Unk_PCInteractMode : public CPtred
{
public:
    bool FUN_140743550();                                   // active
    int FUN_140743710();                                    // the target kind
};
// A world game object as WorldService returns it (an npc here); only the slots used here are named.
class Unk_WsC_GameObj
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual Unk_StreamPoint vfunc_18();                     // 18: the position
    CStringW FUN_141093310();                               // the npc name
    int FUN_14166ce30();                                    // dead (1)
    MS2Ptr<Unk_AkoNpcData> FUN_141093270();                 // the npc data
    int FUN_14123c580();                                    // the object id
    // @0x140967120
    bool FUN_140967120() { return m_bTalkable; }

    unsigned char m_unk_08[0xe48];
    bool m_bTalkable;                                       // +0xe50
};
MS2_CHECK_OFFSET(Unk_WsC_GameObj, m_bTalkable, 0xe50);
// The client string tables.
class Unk_AkoStrings
{
public:
    CStringW FUN_141811980(int nTable, int nId);            // a string of a table
};
Unk_AkoStrings* FUN_1401a9d70();
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);   // a formatted client string
// The cutscene service singleton (global 0x143ab3900).
class Unk_AkoCutscene : public TSingleton<Unk_AkoCutscene>
{
public:
    int FUN_141b21220();                                    // a cutscene is playing
};
class Unk_AkoSceneMgr
{
public:
    int FUN_1422b9e00();                                    // the current scene id
};
Unk_AkoSceneMgr* FUN_1408e57f0();
int FUN_141276980();                                        // npc talk is allowed

// @0x140960c30 an action caption: the string with the argument, cut at '-' when the argument is empty
CStringW FUN_140960c30(int nStringId, CStringW strArg)
{
    CStringW strText = FUN_14052bd00(nStringId, strArg);
    if (strArg.GetLength() == 0)
    {
        int nPos = strText.Find(L'-');
        if (nPos != -1)
            return strText.Left(nPos);
    }
    return strText;
}
MS2_REPLACE(0x140960C30, FUN_140960c30, 221, 0x7CEA45B7);

// The cube craft controller of the player (MyPC::FUN_141530290).
class Unk_PCCubeCraft
{
public:
    void FUN_1410aad50();                                   // put the lifted cube down
};
// The ugc manager singleton.
class Unk_AkoUgcMgr
{
public:
    void FUN_14187f590(efd::SmartPointer<egf::Entity> spEntity);   // open the ugc registration for the entity
};
Unk_AkoUgcMgr* FUN_14052d220();

class UIGuildFlagTooltip : public UIDialog
{
public:
    void FUN_1412c45a0();                                   // hide
    void FUN_1412c4050(const CString& strObjectId);         // show for the interact object
};
class UIRealEstateDialog : public UIDialog
{
public:
    void FUN_141ab4000(int nGroup, int nMapId);             // open on a group
};
class UIWorldMapDialog : public UIDialog
{
public:
    void FUN_141b5af80(int nMode);                          // the taxi mode
};

// The house privileges of the local player (MyPC +0x1628; commonfiles\homeprivilege.cpp).
class CHomePrivilege : public CPtred
{
public:
    int FUN_14050d6f0(int nPortalId);                       // the player may use the house portal
    MyPC* m_pOwner;                                         // +0x18
};

// ---- Unk_ActionKeyManager --------------------------------------------------------------------------------------------
// @0x140951c70
Unk_ActionKeyManager::Unk_ActionKeyManager()
{
    m_actions.SetAt(0x13, new PortalAction());
    m_actions.SetAt(0x16, new BuyCubeAction());
    m_actions.SetAt(0x15, new LiftCubeAction());
    m_actions.SetAt(0x14, new TalkAction());
    m_actions.SetAt(0xd, new PullObjectWeaponAction());
    m_actions.SetAt(0x12, new InteractAction());
    m_actions.SetAt(0x11, new InteractNpcAction());
    m_actions.SetAt(0x18, new BillBoardInteractAction());
    m_actions.SetAt(0x10, new RegistUgcAction());
    m_actions.SetAt(1, new FunctionCubeAction());
    m_actions.SetAt(0xe, new FittingDollAction());
    m_actions.SetAt(9, new ViewCubeMapProfileAction());
    m_actions.SetAt(8, new TaxiStationAction());
    m_actions.SetAt(6, new HoldAction());
    m_actions.SetAt(4, new GatheringAction());
    m_actions.SetAt(2, new HomemadeCubeAction());
    m_actions.SetAt(3, new NurturingCubeAction());
    m_actions.SetAt(0x19, new BannerAction());
    m_actions.SetAt(0x1a, new ReactorAction());
    m_actions.SetAt(0x1b, new HoldPCAction());
    m_actions.SetAt(0, new ReleasePCAction());
    m_actions.SetAt(7, new QuestUserFindAction());
    m_actions.SetAt(0x1c, new TreeWateringAction());
    m_actionsCubeMode.SetAt(0x13, new PortalAction());
    m_actionsCubeMode.SetAt(0x16, new BuyCubeAction());
    m_actionsCubeMode.SetAt(0x14, new TalkAction());
    m_actionsCubeMode.SetAt(0xc, new PutDownLiftableAction());
    m_actionsFishing.SetAt(5, new FishingAction());
    m_nCur = 0x1e;
    m_nNextTick = 0;
    m_bEnabled = 1;
}

// @0x140952e70
Unk_ActionKeyManager::~Unk_ActionKeyManager()
{
    m_actions.RemoveAll();
    m_actionsCubeMode.RemoveAll();
    m_actionsFishing.RemoveAll();
}

// @0x140952ef0
void Unk_ActionKeyManager::FUN_140952ef0()
{
    unsigned nNow = FUN_140869420();
    if (nNow - m_nNextTick < 100)
        return;
    if (!m_bEnabled)
        return;
    m_nNextTick = nNow;
    int bRefresh = 0;
    int nType = 0x1e;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    for (POSITION pos = pActions->GetHeadPosition(); pos; pActions->GetNext(pos))
    {
        MS2Ptr<ActionKeyObject> spAction = pActions->GetValueAt(pos);
        if (spAction->vfunc_1())
        {
            nType = pActions->GetKeyAt(pos);
            if (spAction->vfunc_10())
                bRefresh = 1;
            break;
        }
    }
    if (m_nCur != nType)
    {
        int bAccept = 1;
        MS2Ptr<ActionKeyObject> spOld(0);
        MS2Ptr<ActionKeyObject> spNew(0);
        if (pActions->Lookup(m_nCur, spOld))
            spOld->vfunc_3();
        if (pActions->Lookup(nType, spNew))
            bAccept = spNew->vfunc_4();
        if (bAccept)
        {
            m_nCur = nType;
            bRefresh = 1;
        }
    }
    else if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
    {
        if (ActionKeyObject* pCur = FUN_140953550())
        {
            if (pTooltip->FUN_1418b17d0() != pCur)
                bRefresh = 1;
            else if (pTooltip->FUN_1418b17f0() != pCur->vfunc_7())
                bRefresh = 1;
            else if (pTooltip->FUN_1418b1840() != pCur->vfunc_6())
                bRefresh = 1;
        }
    }
    if (bRefresh)
    {
        if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
            pTooltip->FUN_1418b16f0();
    }
}
MS2_REPLACE_METHOD(0x140952EF0, Unk_ActionKeyManager, FUN_140952ef0, 1042, 0x13A46E5D);

// @0x140953310
void Unk_ActionKeyManager::FUN_140953310()
{
    if (m_nCur == 0x1e)
        return;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14165f100())
        return;
    spAction->vfunc_2();
    if (TSingleton<CMouseController>::GetInstance()->FUN_140ad21b0())
        TSingleton<CMouseController>::GetInstance()->FUN_140ad22d0();
}
MS2_REPLACE_METHOD(0x140953310, Unk_ActionKeyManager, FUN_140953310, 248, 0x47B4C32E);

// @0x140953410
bool Unk_ActionKeyManager::FUN_140953410()
{
    if (m_nCur == 0x1e)
        return false;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return false;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return false;
    if (spAction->vfunc_11())
    {
        spAction->vfunc_2();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140953410, Unk_ActionKeyManager, FUN_140953410, 282, 0x61BC001A);

// @0x140953530
int Unk_ActionKeyManager::FUN_140953530()
{
    return m_nCur;
}
MS2_REPLACE_METHOD(0x140953530, Unk_ActionKeyManager, FUN_140953530, 13, 0xA5869133);

// @0x140953550
ActionKeyObject* Unk_ActionKeyManager::FUN_140953550()
{
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    pActions->Lookup(m_nCur, spAction);
    return spAction.get();
}
MS2_REPLACE_METHOD(0x140953550, Unk_ActionKeyManager, FUN_140953550, 104, 0x73B9BB61);

// @0x1409535c0
void Unk_ActionKeyManager::FUN_1409535c0()
{
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (pActions->Lookup(m_nCur, spAction))
        spAction->vfunc_3();
    m_nCur = 0x1e;
    m_nNextTick = FUN_140869420() + 2000;
    if (UIActionTooltip* pTooltip = Unk_GetUI<UIActionTooltip>(0x4e5c))
        pTooltip->FUN_1418b16f0();
}
MS2_REPLACE_METHOD(0x1409535C0, Unk_ActionKeyManager, FUN_1409535c0, 188, 0xEBB060BC);

// @0x140953690
int Unk_ActionKeyManager::FUN_140953690()
{
    return m_bEnabled;
}
MS2_REPLACE_METHOD(0x140953690, Unk_ActionKeyManager, FUN_140953690, 17, 0x444DCEE7);

// @0x1409536b0
void Unk_ActionKeyManager::FUN_1409536b0(int bEnable)
{
    m_bEnabled = bEnable;
}
MS2_REPLACE_METHOD(0x1409536B0, Unk_ActionKeyManager, FUN_1409536b0, 25, 0x79F379CB);

// @0x1409536d0
void Unk_ActionKeyManager::FUN_1409536d0()
{
    if (m_nCur == 0x1e)
        return;
    Unk_ActionKeyMap* pActions = FUN_140953770();
    MS2Ptr<ActionKeyObject> spAction(0);
    if (!pActions->Lookup(m_nCur, spAction))
        return;
    spAction->vfunc_9();
}
MS2_REPLACE_METHOD(0x1409536D0, Unk_ActionKeyManager, FUN_1409536d0, 147, 0xB05C022E);

// @0x140953770
Unk_ActionKeyMap* Unk_ActionKeyManager::FUN_140953770()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return &m_actions;
    if (pPlayer->FUN_1416595d0())
        return &m_actionsCubeMode;
    if (TSingleton<CFishingManager>::GetInstance()->FUN_140954150())
        return &m_actionsFishing;
    return &m_actions;
}
MS2_REPLACE_METHOD(0x140953770, Unk_ActionKeyManager, FUN_140953770, 113, 0xBF74575B);

// ---- ActionKeyObject -------------------------------------------------------------------------------------------------
// @0x140954f60
ActionKeyObject::ActionKeyObject() {}
// @0x140954fa0
ActionKeyObject::~ActionKeyObject() {}
// @0x140954fd0
int ActionKeyObject::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140954FD0, ActionKeyObject, vfunc_1, 8, 0x7F371472);
// @0x140954fe0
void ActionKeyObject::vfunc_2() {}
MS2_REPLACE_METHOD(0x140954FE0, ActionKeyObject, vfunc_2, 6, 0xA9AF6E37);
// @0x140954ff0
void ActionKeyObject::vfunc_3() {}
MS2_REPLACE_METHOD(0x140954FF0, ActionKeyObject, vfunc_3, 6, 0xA9AF6E37);
// @0x140955000
int ActionKeyObject::vfunc_4() { return 1; }
MS2_REPLACE_METHOD(0x140955000, ActionKeyObject, vfunc_4, 11, 0x30025ED0);
// @0x140955020
int ActionKeyObject::vfunc_5() { return 0x1e; }
MS2_REPLACE_METHOD(0x140955020, ActionKeyObject, vfunc_5, 11, 0x9C560DCD);
// @0x140955040
CStringW ActionKeyObject::vfunc_6() { return L""; }
MS2_REPLACE_METHOD(0x140955040, ActionKeyObject, vfunc_6, 61, 0x637B041B);
// @0x140955090
CStringW ActionKeyObject::vfunc_7() { return L""; }
MS2_REPLACE_METHOD(0x140955090, ActionKeyObject, vfunc_7, 61, 0x97EE3BD8);
// @0x1409550e0
CStringW ActionKeyObject::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x1409550E0, ActionKeyObject, vfunc_8, 61, 0x56AA9F80);
// @0x140955130
void ActionKeyObject::vfunc_9() {}
MS2_REPLACE_METHOD(0x140955130, ActionKeyObject, vfunc_9, 6, 0xA9AF6E37);
// @0x140955140
int ActionKeyObject::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x140955140, ActionKeyObject, vfunc_10, 8, 0x7F371472);
// @0x140954140
bool ActionKeyObject::vfunc_11() { return false; }
MS2_REPLACE_METHOD(0x140954140, ActionKeyObject, vfunc_11, 8, 0x41132FCD);
// @0x140955150
Unk_AkoTarget ActionKeyObject::vfunc_12() { return Unk_AkoTarget(); }
MS2_REPLACE_METHOD(0x140955150, ActionKeyObject, vfunc_12, 34, 0x5E6446D1);

// ---- TaxiStationAction ----------------------------------------------------------------------------------------------
// @0x140953a80
TaxiStationAction::TaxiStationAction() {}
// @0x14095bf90
int TaxiStationAction::vfunc_5() { return 8; }
MS2_REPLACE_METHOD(0x14095BF90, TaxiStationAction, vfunc_5, 11, 0x2093C54B);
// @0x14095bef0
void TaxiStationAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e42))
        FUN_1403ed2b0()->FUN_141adc530(0x4e42);
    if (UIWorldMapDialog* pDialog = Unk_GetUI<UIWorldMapDialog>(0x4e42))
        pDialog->FUN_141b5af80(1);
    FUN_1409331e0()->FUN_14138bf00(0x11, 0, 0);
}
MS2_REPLACE_METHOD(0x14095BEF0, TaxiStationAction, vfunc_2, 144, 0x65EC98D4);
// @0x14095bfb0
CStringW TaxiStationAction::vfunc_6() { return FUN_14028de60(0x64a); }
MS2_REPLACE_METHOD(0x14095BFB0, TaxiStationAction, vfunc_6, 58, 0x4AB33250);

// ---- FishingAction ---------------------------------------------------------------------------------------------------
// @0x140953a50
FishingAction::FishingAction() {}
// @0x14095cf80
int FishingAction::vfunc_1() { return TSingleton<CFishingManager>::GetInstance()->FUN_140cdb250(); }
MS2_REPLACE_METHOD(0x14095CF80, FishingAction, vfunc_1, 27, 0xB7D79C18);
// @0x14095cfb0
void FishingAction::vfunc_2() { TSingleton<CFishingManager>::GetInstance()->FUN_140cdb1e0(); }
MS2_REPLACE_METHOD(0x14095CFB0, FishingAction, vfunc_2, 27, 0x585EBA68);
// @0x14095cfe0
int FishingAction::vfunc_5() { return 5; }
MS2_REPLACE_METHOD(0x14095CFE0, FishingAction, vfunc_5, 11, 0xCA9EB45C);
// @0x14095d000
CStringW FishingAction::vfunc_6() { return FUN_14028de60(0x658); }
MS2_REPLACE_METHOD(0x14095D000, FishingAction, vfunc_6, 58, 0x6AB4AFF6);

// ---- PortalAction ----------------------------------------------------------------------------------------------------
// @0x140955180
PortalAction::PortalAction() : m_spPortal(0) {}
// @0x1409551f0
PortalAction::~PortalAction()
{
    m_spEntity = 0;
    m_spPortal = 0;
}
// @0x140955990
void PortalAction::vfunc_3()
{
    if (FUN_1403ed2b0()->FUN_141adc890(0x4ebd))
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ebd);
}
MS2_REPLACE_METHOD(0x140955990, PortalAction, vfunc_3, 54, 0xFD8A0CBF);
// @0x140955280
int PortalAction::vfunc_1()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    if (pPlayer->FUN_1416595d0())
        return 0;
    if (FUN_1409331e0()->FUN_14138c900(9))
        return 0;
    m_spEntity = 0;
    m_spPortal = 0;
    Unk_StreamPoint pos = pPlayer->FUN_1416767d0();
    ATL::CAtlArray<MS2Ptr<Unk_AkoPortal> > aPortals;
    FUN_1403ed2d0()->FUN_141bc2c90(pos, &aPortals);
    if (aPortals.GetCount() == 0)
    {
        DAT_143ab288c = 0;
        return 0;
    }
    for (size_t i = 0; i < aPortals.GetCount(); i++)
    {
        MS2Ptr<Unk_AkoPortal> spPortal = aPortals[i];
        efd::SmartPointer<egf::Entity> spEntity =
            TSingleton<EntityWorldManager>::GetInstance()->FUN_1411cf440(spPortal->m_entityId);
        if (!spEntity)
            continue;
        bool bVisible = false;
        spEntity->GetPropertyValue(0x14969c28, bVisible);
        if (bVisible)
        {
            int nPortalId;
            spEntity->GetPropertyValue(0x60f82816, nPortalId);
            if (DAT_143ab288c == nPortalId)
                return 1;
            m_spEntity = spEntity;
            m_spPortal = spPortal;
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140955280, PortalAction, vfunc_1, 753, 0x5083C8D8);
// @0x140955580
void PortalAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_1416595d0())
        return;
    if (m_spEntity == 0)
        return;
    if (m_spPortal == 0)
        return;
    int nPortalId;
    m_spEntity->GetPropertyValue(0x60f82816, nPortalId);
    DAT_143ab288c = nPortalId;
    int nTarget;
    m_spEntity->GetPropertyValue(0xa162d321, nTarget);
    bool bHousePortal = false;
    m_spEntity->GetPropertyValue(0xe725ea17, bHousePortal);
    bool bDenied = bHousePortal && !pPlayer->FUN_140967010()->FUN_14050d6f0(nPortalId);
    if (bDenied)
    {
        FUN_140d73bc0(0x656, 0, 0, L"");
        return;
    }
    efd::SmartPointer<Unk_Service6100017> spCubeMap = FUN_1401cd040(&DAT_143b059e8);
    if (m_spPortal->m_nOwnerId)
    {
        Unk_StreamPoint ptFront;
        spCubeMap->FUN_1410b7ad0(pPlayer, 0.0f, &ptFront, 1);
        Unk_StreamPoint ptCell;
        spCubeMap->FUN_1410b7a20(ptFront, &ptCell);
        Unk_AkoCell* pCell = spCubeMap->FUN_1410b8ab0(ptCell);
        if (m_spPortal->m_nType == 0xb)
        {
            pPlayer->FUN_141529c80(0, 0, 0, m_spPortal->m_nOwnerId, L"");
            return;
        }
        else if (pCell)
        {
            FUN_140956aa0(pCell, nTarget, nPortalId);
            return;
        }
    }
    FUN_140956160(nTarget, nPortalId);
}
MS2_REPLACE_METHOD(0x140955580, PortalAction, vfunc_2, 1021, 0xEB4CA627);
// @0x1409559d0
int PortalAction::vfunc_4()
{
    if (!m_spEntity)
        return 0;
    int nKind;
    m_spEntity->GetPropertyValue(0x1b8b1161, nKind);
    if (nKind == 1)
    {
        if (Unk_AkoHouseSvc::GetInstance()->FUN_1410c3180() == DAT_143ab2820
            && !Unk_AkoHouseSvc::GetInstance()->FUN_1410cb920(5000))
            return 1;
        vfunc_2();
        return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1409559D0, PortalAction, vfunc_4, 161, 0xD640D23E);
// @0x140955a80
int PortalAction::vfunc_5() { return 0x13; }
MS2_REPLACE_METHOD(0x140955A80, PortalAction, vfunc_5, 11, 0x112851C6);
// @0x140956060
Unk_AkoTarget PortalAction::vfunc_12()
{
    if (m_spPortal == 0)
        return Unk_AkoTarget();
    Unk_StreamPoint pos = m_spPortal->FUN_14169d2f0();
    if (m_spPortal->m_nType == 5)
        pos.z += 75.0f;
    return Unk_AkoTarget(pos);
}
MS2_REPLACE_METHOD(0x140956060, PortalAction, vfunc_12, 158, 0xC4C4B84D);
// @0x140956110
int PortalAction::FUN_140956110()
{
    if (m_spPortal == 0)
        return 0;
    return m_spPortal->FUN_14169d280();
}
MS2_REPLACE_METHOD(0x140956110, PortalAction, FUN_140956110, 69, 0x8E8EC06C);
// @0x140956160
void PortalAction::FUN_140956160(int nTarget, int nPortalId)
{
    switch (m_spPortal->m_nType)
    {
    case 8:
        FUN_140956290(nPortalId);
        break;
    case 9:
        FUN_140956310();
        break;
    case 0xc:
        FUN_1409569a0(nPortalId, 3);
        break;
    case 0xd:
        FUN_140956370(0, 1);
        break;
    case 0xe:
        FUN_1409569a0(nPortalId, 4);
        break;
    case 0x10:
        FUN_140dff580(nTarget, nPortalId);
        break;
    case 0x11:
        FUN_140956a20(nPortalId, nPortalId);
        break;
    default:
        FUN_140956370(nTarget, nPortalId);
        break;
    }
}
MS2_REPLACE_METHOD(0x140956160, PortalAction, FUN_140956160, 246, 0x0584F47B);
// @0x140956290
void PortalAction::FUN_140956290(int nPortalId)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        if (pDialog->FUN_1412b8f00(nPortalId))
        {
            pDialog->FUN_1412b90f0(nPortalId);
            pDialog->FUN_141924680();
        }
    }
}
MS2_REPLACE_METHOD(0x140956290, PortalAction, FUN_140956290, 119, 0x70B8578D);
// @0x140956310
void PortalAction::FUN_140956310()
{
    COutPacket packet(0x2b);
    packet.Encode1(9);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140956310, PortalAction, FUN_140956310, 75, 0xAAB9ED2B);
// @0x1409569a0
void PortalAction::FUN_1409569a0(int nPortalId, int nMode)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        pDialog->FUN_1412b90d0(nMode);
        pDialog->FUN_1412b90f0(nPortalId);
        pDialog->FUN_141924680();
    }
}
MS2_REPLACE_METHOD(0x1409569A0, PortalAction, FUN_1409569a0, 117, 0x7ED71136);
// @0x140956a20
void PortalAction::FUN_140956a20(int nPortalId, int nArg)
{
    if (UIDungeonRoomDialog* pDialog = Unk_GetUI<UIDungeonRoomDialog>(0x4ebd))
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_67();
        pDialog->FUN_1412b8ff0(nArg);
        pDialog->FUN_1412b90f0(nPortalId);
        pDialog->FUN_141924680();
    }
}
MS2_REPLACE_METHOD(0x140956A20, PortalAction, FUN_140956a20, 117, 0x78FA43EB);
// @0x140956aa0
void PortalAction::FUN_140956aa0(Unk_AkoCell* pCell, int nTarget, int nPortalId)
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (!pCell)
        return;
    int nCubeId = pCell->m_nCubeId;
    int nKind = 0;
    FUN_1408a0890(FUN_1403ed2d0()->FUN_141bd3060(), nCubeId, &nKind);
    int bInside = 0;
    if (nKind == 1)
        bInside = 1;
    pPlayer->FUN_14152a0c0(nTarget, nPortalId, nCubeId, bInside, L"", L"");
}
MS2_REPLACE_METHOD(0x140956AA0, PortalAction, FUN_140956aa0, 309, 0xFE6AA6E2);
// @0x140956e40
CStringW PortalAction::FUN_140956e40()
{
    return m_spPortal->FUN_14169c3b0();
}
MS2_REPLACE_METHOD(0x140956E40, PortalAction, FUN_140956e40, 73, 0x911E15E5);

// ---- BuyCubeAction ---------------------------------------------------------------------------------------------------
// @0x140956e90
BuyCubeAction::BuyCubeAction() : m_n18(0), m_id(egf::kENTITY_INVALID) {}
// @0x140956f00
BuyCubeAction::~BuyCubeAction()
{
    m_id = egf::kENTITY_INVALID;
}
// @0x140956f50
int BuyCubeAction::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140956F50, BuyCubeAction, vfunc_1, 8, 0x7F371472);
// @0x140956f60
void BuyCubeAction::vfunc_2()
{
    if (m_n18 == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    int nError = spHouse->FUN_1410c8580(m_n18);
    if (nError == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4e76);
        if (UIRealEstateDialog* pDialog = Unk_GetUI<UIRealEstateDialog>(0x4e76))
            pDialog->FUN_141ab4000(m_n18, FUN_1403ed2d0()->FUN_141bd3060());
    }
    else
    {
        FUN_140d73aa0(spHouse->FUN_1410d5d80(nError), 0, 0, L"");
    }
}
MS2_REPLACE_METHOD(0x140956F60, BuyCubeAction, vfunc_2, 342, 0x106CF696);
// @0x1409570c0
void BuyCubeAction::vfunc_3()
{
    if (m_id != egf::kENTITY_INVALID)
    {
        FUN_1409571a0(m_id, 0);
        m_id = egf::kENTITY_INVALID;
    }
}
MS2_REPLACE_METHOD(0x1409570C0, BuyCubeAction, vfunc_3, 117, 0xDB2B41EC);
// @0x140957140
int BuyCubeAction::vfunc_5() { return 0x16; }
MS2_REPLACE_METHOD(0x140957140, BuyCubeAction, vfunc_5, 11, 0x671D62B5);
// @0x140957160
CStringW BuyCubeAction::vfunc_6() { return FUN_14028de60(0x635); }
MS2_REPLACE_METHOD(0x140957160, BuyCubeAction, vfunc_6, 58, 0xE8BBC9CB);
// @0x1409571a0
void BuyCubeAction::FUN_1409571a0(egf::EntityID id, int bSelect)
{
    egf::EntityID idNone(0);
    if (id == idNone)
        return;
    FUN_141b71e70(id, bSelect != 0, 1, false);
}
MS2_REPLACE_METHOD(0x1409571A0, BuyCubeAction, FUN_1409571a0, 126, 0x67FAFAB3);

// ---- LiftCubeAction --------------------------------------------------------------------------------------------------
// @0x140957230
LiftCubeAction::LiftCubeAction() {}
// @0x140957280
LiftCubeAction::~LiftCubeAction() {}
// @0x140957720
int LiftCubeAction::vfunc_5() { return 0x15; }
MS2_REPLACE_METHOD(0x140957720, LiftCubeAction, vfunc_5, 11, 0xB512670C);
// @0x140957740
CStringW LiftCubeAction::vfunc_6()
{
    Unk_WsB_Lift* pLift = FUN_1403ed2d0()->FUN_141bc5a20(m_str18);
    if (!pLift)
        return L"";
    return FUN_140960c30(0x63a, FUN_1401a9d70()->FUN_141811980(1, pLift->FUN_141447cc0()));
}
MS2_REPLACE_METHOD(0x140957740, LiftCubeAction, vfunc_6, 315, 0x1C11A665);

// ---- TalkAction ------------------------------------------------------------------------------------------------------
// @0x140957b20
TalkAction::TalkAction()
{
    m_n18 = 0;
    m_nNpcId = 0;
    m_strName = "";
}
// @0x140957f10
int TalkAction::vfunc_5() { return 0x14; }
MS2_REPLACE_METHOD(0x140957F10, TalkAction, vfunc_5, 11, 0xF06BEBEF);
// @0x140957e80
void TalkAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_14166c930() == 0x16)
        return;
    if (Unk_AkoCutscene::GetInstance()->FUN_141b21220() != 0)
        return;
    if (FUN_1408e57f0()->FUN_1422b9e00() == 0x6200031)
        return;
    if (FUN_141276980() == 0)
        return;
    pPlayer->FUN_141529a50(m_nNpcId);
}
MS2_REPLACE_METHOD(0x140957E80, TalkAction, vfunc_2, 129, 0x6FD9FB8C);
// @0x140957f30
CStringW TalkAction::vfunc_6()
{
    if (m_n18 == 0)
        return L"";
    CStringW strText = FUN_1401a9d70()->FUN_141811980(0xe, m_n18);
    if (strText.GetLength() == 0)
        strText = FUN_14028de60(0x62d);
    CStringW strName = FUN_14052bd00(0x649, m_strName);
    if (strName.GetLength() != 0)
        strText.Append(strName);
    return strText;
}
MS2_REPLACE_METHOD(0x140957F30, TalkAction, vfunc_6, 307, 0xCFF13AE4);

// ---- InteractAction --------------------------------------------------------------------------------------------------
// @0x140958070
InteractAction::InteractAction() : m_n20(0) {}
// @0x1409580c0
InteractAction::~InteractAction()
{
    m_strObjectId.Empty();
}
// @0x140958a60
int InteractAction::vfunc_5() { return 0x12; }
MS2_REPLACE_METHOD(0x140958A60, InteractAction, vfunc_5, 11, 0xCC810D29);
// @0x140958120
int InteractAction::vfunc_1()
{
    CInteractObject* pOld = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    CInteractObject* pObject = FUN_140958e70();
    if (pOld && pOld != pObject)
    {
        if (UIGuildFlagTooltip* pTooltip = Unk_GetUI<UIGuildFlagTooltip>(0x4ea8))
            pTooltip->FUN_1412c45a0();
        pOld->FUN_1413fdca0(0);
    }
    if (pObject && vfunc_13(pObject) == 0)
        return 0;
    if (pObject)
    {
        pObject->FUN_1413fdca0(1);
        m_strObjectId = pObject->FUN_140967060();
        if (UIGuildFlagTooltip* pTooltip = Unk_GetUI<UIGuildFlagTooltip>(0x4ea8))
            pTooltip->FUN_1412c4050(m_strObjectId);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140958120, InteractAction, vfunc_1, 390, 0x2AE0A946);
// @0x140958e70
// MS2-FUNCTIONAL: the exe's WorldService::FUN_141bc6090 takes the point by value (a rep movsb copy into a temp);
// the shared header declares it const&.
CInteractObject* InteractAction::FUN_140958e70()
{
    if (FUN_1409331e0()->FUN_14138c900(3) != 0)
        return 0;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_StreamPoint pos = pPlayer->FUN_1416767d0();
    CInteractObject* pObject = FUN_1403ed2d0()->FUN_141bc6090(pos, 1);
    if (!pObject)
        return 0;
    if (pObject->FUN_1413fe040() == 0)
        return 0;
    if (pObject->FUN_1413fe120() == 0)
        return 0;
    if (pObject->FUN_1413fdfc0() == 0)
        return 0;
    return pObject;
}
MS2_REPLACE_METHOD(0x140958E70, InteractAction, FUN_140958e70, 273, 0xBA3636FF);
// @0x140958cb0
void InteractAction::vfunc_3()
{
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return;
    m_n20 = 0;
    m_strObjectId.Empty();
}
MS2_REPLACE_METHOD(0x140958CB0, InteractAction, vfunc_3, 143, 0xC0354D66);
// @0x140958d50
Unk_AkoTarget InteractAction::vfunc_12()
{
    Unk_WsB_Prop* pObject = FUN_1403ed2d0()->FUN_141bc66b0(m_strObjectId);
    if (!pObject)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(pObject->FUN_1409673c0());
}
MS2_REPLACE_METHOD(0x140958D50, InteractAction, vfunc_12, 189, 0x5E259EFC);
// @0x140958c50
CStringW InteractAction::vfunc_7() { return FUN_14016a730(m_strObjectId, 0); }
MS2_REPLACE_METHOD(0x140958C50, InteractAction, vfunc_7, 77, 0xDC203CB9);
// @0x140958e20
int InteractAction::vfunc_13(CInteractObject* pObject)
{
    int nKind = pObject->vfunc_5();
    if (nKind == 6 || nKind == 8)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140958E20, InteractAction, vfunc_13, 62, 0xA6B5DED9);

// ---- InteractNpcAction -----------------------------------------------------------------------------------------------
// @0x140958f90
InteractNpcAction::InteractNpcAction() : m_pNpc(0), m_n20(0) {}
// @0x140958fe0
InteractNpcAction::~InteractNpcAction()
{
    m_pNpc = 0;
}
// @0x140959020
int InteractNpcAction::vfunc_1()
{
    m_pNpc = FUN_140959330();
    if (m_pNpc != 0)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140959020, InteractNpcAction, vfunc_1, 54, 0x824E5B3A);
// @0x140959060
void InteractNpcAction::vfunc_2()
{
    if (m_pNpc == 0)
        return;
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (pPlayer->FUN_141527160(0x1a) == 0)
        return;
    if (m_pNpc->FUN_141093270()->m_strTalkScript.GetLength() > 0)
    {
        MS2Ptr<StateInteractNpcData> spData = new StateInteractNpcData();
        spData->m_nNpc = m_pNpc->FUN_14123c580();
        static_cast<PCBase*>(pPlayer)->vfunc_59(0x1a, spData, 0, 0);   // PC/MyPC re-declare slot 59 as a new virtual
    }
    else
    {
        m_n20 = 1;
    }
}
// @0x140959330
// MS2-FUNCTIONAL: the exe keeps one more pointer slot for the interact-mode temporary (all frame offsets +8).
Unk_WsC_GameObj* InteractNpcAction::FUN_140959330()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return 0;
    Unk_WsC_GameObj* pNpc = FUN_1403ed2d0()->FUN_141bd2170(2, FUN_1401d3200()->InteractionDistance.Read(), 1, 0);
    if (!pNpc)
    {
        int nKind = 1;
        if (pPlayer->FUN_140967420() != 0 && pPlayer->FUN_140967420()->FUN_140743550())
            nKind = pPlayer->FUN_140967420()->FUN_140743710();
        pNpc = FUN_1403ed2d0()->FUN_141bd2170(nKind, FUN_1401d3200()->InteractionDistance.Read(), 1, 0);
    }
    if (!pNpc)
        return 0;
    if (pNpc->FUN_14166ce30() == 1)
        return 0;
    if (pNpc->FUN_141093270()->m_strTalkScript.GetLength() < 1)
        return 0;
    if (!pNpc->FUN_140967120())
        return 0;
    return pNpc;
}
MS2_REPLACE_METHOD(0x140959330, InteractNpcAction, FUN_140959330, 755, 0xAE7C8382);
// @0x140959240
CStringW InteractNpcAction::vfunc_6()
{
    if (m_pNpc == 0)
        return L"";
    return FUN_140960c30(0x634, m_pNpc->FUN_141093310());
}
MS2_REPLACE_METHOD(0x140959240, InteractNpcAction, vfunc_6, 145, 0xD2B6814B);
// @0x140959630
Unk_AkoTarget InteractNpcAction::vfunc_12()
{
    if (m_pNpc == 0)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(m_pNpc->vfunc_18());
}
MS2_REPLACE_METHOD(0x140959630, InteractNpcAction, vfunc_12, 103, 0x45902D38);
// @0x140959220
int InteractNpcAction::vfunc_5() { return 0x12; }
MS2_REPLACE_METHOD(0x140959220, InteractNpcAction, vfunc_5, 11, 0xCC810D29);
// @0x1409592e0
void InteractNpcAction::vfunc_9() { vfunc_3(); }
MS2_REPLACE_METHOD(0x1409592E0, InteractNpcAction, vfunc_9, 30, 0x46DE6E41);
// @0x140959310
void InteractNpcAction::vfunc_3() { m_n20 = 0; }
MS2_REPLACE_METHOD(0x140959310, InteractNpcAction, vfunc_3, 18, 0x353540EB);
// @0x140967a50
bool InteractNpcAction::vfunc_11() { return true; }
MS2_REPLACE_METHOD(0x140967A50, InteractNpcAction, vfunc_11, 8, 0x71679366);

// ---- ViewCubeMapProfileAction ----------------------------------------------------------------------------------------
// @0x1409596a0
ViewCubeMapProfileAction::ViewCubeMapProfileAction() {}
// @0x1409596e0
ViewCubeMapProfileAction::~ViewCubeMapProfileAction() {}
// @0x140959710
int ViewCubeMapProfileAction::vfunc_1() { return 0; }
MS2_REPLACE_METHOD(0x140959710, ViewCubeMapProfileAction, vfunc_1, 8, 0x7F371472);
// @0x1409597b0
int ViewCubeMapProfileAction::vfunc_5() { return 9; }
MS2_REPLACE_METHOD(0x1409597B0, ViewCubeMapProfileAction, vfunc_5, 11, 0x653B09E8);
// @0x140959720
void ViewCubeMapProfileAction::vfunc_2()
{
    if (m_nMapId == 0)
        return;
    efd::SmartPointer<Unk_Service6100017> spHouse = FUN_1401cd040(&DAT_143b059e8);
    spHouse->FUN_1410ccc00(m_nMapId, 1, FUN_1401d3200()->DurationForBoundaryDisplay.Read());
}
MS2_REPLACE_METHOD(0x140959720, ViewCubeMapProfileAction, vfunc_2, 135, 0xF03EB00E);
// @0x1409597d0
CStringW ViewCubeMapProfileAction::vfunc_6() { return FUN_14028de60(0x648); }
MS2_REPLACE_METHOD(0x1409597D0, ViewCubeMapProfileAction, vfunc_6, 58, 0xEF3DA54E);

// ---- RegistUgcAction -------------------------------------------------------------------------------------------------
// @0x140959810
RegistUgcAction::RegistUgcAction() {}
// @0x140959860
RegistUgcAction::~RegistUgcAction()
{
    m_spEntity = 0;
}
// @0x140959ac0
int RegistUgcAction::vfunc_5() { return 0x10; }
MS2_REPLACE_METHOD(0x140959AC0, RegistUgcAction, vfunc_5, 11, 0x55CF9663);
// @0x1409599f0
void RegistUgcAction::vfunc_2()
{
    if (m_spEntity == 0)
        return;
    FUN_14052d220()->FUN_14187f590(m_spEntity);
}
MS2_REPLACE_METHOD(0x1409599F0, RegistUgcAction, vfunc_2, 117, 0x885DE4AF);
// @0x140959a70
void RegistUgcAction::vfunc_3()
{
    FUN_140959d70(m_spEntity, 0);
    m_spEntity = 0;
}
MS2_REPLACE_METHOD(0x140959A70, RegistUgcAction, vfunc_3, 66, 0x541E758C);
// @0x140959d70
void RegistUgcAction::FUN_140959d70(egf::Entity* pEntity, int bSelect)
{
    if (!pEntity)
        return;
    FUN_141b71e70(pEntity->GetEntityID(), bSelect != 0, 1, false);
}
MS2_REPLACE_METHOD(0x140959D70, RegistUgcAction, FUN_140959d70, 108, 0x9EED06A3);

// ---- PullObjectWeaponAction ------------------------------------------------------------------------------------------
// @0x140959df0
PullObjectWeaponAction::PullObjectWeaponAction() : m_spCube(0), m_spCube28(0) {}
// @0x140959e60
PullObjectWeaponAction::~PullObjectWeaponAction() {}
// @0x14095a920
int PullObjectWeaponAction::vfunc_5() { return 0xd; }
MS2_REPLACE_METHOD(0x14095A920, PullObjectWeaponAction, vfunc_5, 11, 0xFFD75F74);
// @0x14095a980
Unk_AkoTarget PullObjectWeaponAction::vfunc_12()
{
    if (m_spCube == 0)
        return ActionKeyObject::vfunc_12();
    return Unk_AkoTarget(m_spCube->FUN_1408b5370());
}
MS2_REPLACE_METHOD(0x14095A980, PullObjectWeaponAction, vfunc_12, 115, 0x730CB897);
// @0x14095a940
CStringW PullObjectWeaponAction::vfunc_6() { return FUN_14028de60(0x63c); }
MS2_REPLACE_METHOD(0x14095A940, PullObjectWeaponAction, vfunc_6, 58, 0xDC4D8F98);

// ---- PutDownLiftableAction -------------------------------------------------------------------------------------------
// @0x14095aa00
PutDownLiftableAction::PutDownLiftableAction() {}
// @0x14095aa40
PutDownLiftableAction::~PutDownLiftableAction() {}
// @0x14095adb0
int PutDownLiftableAction::vfunc_5() { return 0xc; }
MS2_REPLACE_METHOD(0x14095ADB0, PutDownLiftableAction, vfunc_5, 11, 0xBB301AD7);
// @0x14095ad50
void PutDownLiftableAction::vfunc_2()
{
    MyPC* pPlayer = static_cast<MyPC*>(FUN_1403ed2d0()->FUN_141bd0cc0());
    if (!pPlayer)
        return;
    if (Unk_PCCubeCraft* pCraft = pPlayer->FUN_141530290())
        pCraft->FUN_1410aad50();
}
MS2_REPLACE_METHOD(0x14095AD50, PutDownLiftableAction, vfunc_2, 75, 0xE574BACD);
// @0x14095add0
CStringW PutDownLiftableAction::vfunc_6() { return FUN_14028de60(0x63d); }
MS2_REPLACE_METHOD(0x14095ADD0, PutDownLiftableAction, vfunc_6, 58, 0x6B710DAF);

// ---- FunctionCubeAction ----------------------------------------------------------------------------------------------
// @0x14095ae10
FunctionCubeAction::FunctionCubeAction() : m_n20(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095b470
int FunctionCubeAction::vfunc_5() { return 1; }
MS2_REPLACE_METHOD(0x14095B470, FunctionCubeAction, vfunc_5, 11, 0x30025ED0);
// @0x14095b690
int FunctionCubeAction::vfunc_10() { return m_n20; }
MS2_REPLACE_METHOD(0x14095B690, FunctionCubeAction, vfunc_10, 14, 0xA25B27BF);

// ---- FittingDollAction -----------------------------------------------------------------------------------------------
// @0x14095b760
FittingDollAction::FittingDollAction() : m_n18(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095ba40
int FittingDollAction::vfunc_5() { return 0xe; }
MS2_REPLACE_METHOD(0x14095BA40, FittingDollAction, vfunc_5, 11, 0x31E1919D);
// @0x14095bbf0
int FittingDollAction::vfunc_10() { return m_n18; }
MS2_REPLACE_METHOD(0x14095BBF0, FittingDollAction, vfunc_10, 14, 0x72E52537);

// ---- HoldAction ------------------------------------------------------------------------------------------------------
// @0x14095bff0
HoldAction::HoldAction() : m_n18(0), m_n1c(0), m_nNpcId(0), m_f24(0.0f) {}
// @0x14095c540
int HoldAction::vfunc_5() { return 6; }
MS2_REPLACE_METHOD(0x14095C540, HoldAction, vfunc_5, 11, 0xFCA8E685);
// @0x14095c6b0
int HoldAction::vfunc_10() { return m_n18; }
MS2_REPLACE_METHOD(0x14095C6B0, HoldAction, vfunc_10, 14, 0x72E52537);

// ---- HoldPCAction ----------------------------------------------------------------------------------------------------
// @0x14095c6d0
HoldPCAction::HoldPCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cab0
int HoldPCAction::vfunc_5() { return 0x1b; }
MS2_REPLACE_METHOD(0x14095CAB0, HoldPCAction, vfunc_5, 11, 0x4660FCDE);
// @0x14095cb70
int HoldPCAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095CB70, HoldPCAction, vfunc_10, 8, 0x7F371472);

// ---- ReleasePCAction -------------------------------------------------------------------------------------------------
// @0x14095cb80
ReleasePCAction::ReleasePCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cea0
int ReleasePCAction::vfunc_5() { return 0; }
MS2_REPLACE_METHOD(0x14095CEA0, ReleasePCAction, vfunc_5, 8, 0x7F371472);
// @0x14095cf70
int ReleasePCAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095CF70, ReleasePCAction, vfunc_10, 8, 0x7F371472);

// ---- GatheringAction -------------------------------------------------------------------------------------------------
// @0x14095d040
GatheringAction::GatheringAction() {}
// @0x14095d090
GatheringAction::~GatheringAction()
{
    m_strObjectId.Empty();
}
// @0x14095d460
void GatheringAction::vfunc_2() { InteractAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095D460, GatheringAction, vfunc_2, 24, 0x5EBFE707);
// @0x14095d480
int GatheringAction::vfunc_5() { return 4; }
MS2_REPLACE_METHOD(0x14095D480, GatheringAction, vfunc_5, 11, 0x85F76FBF);

// ---- BillBoardInteractAction -----------------------------------------------------------------------------------------
// @0x14095d910
BillBoardInteractAction::BillBoardInteractAction() {}
// @0x14095d950
BillBoardInteractAction::~BillBoardInteractAction() {}
// @0x14095d980
int BillBoardInteractAction::vfunc_5() { return 0x18; }
MS2_REPLACE_METHOD(0x14095D980, BillBoardInteractAction, vfunc_5, 11, 0x8B08417B);
// @0x14095dc90
int BillBoardInteractAction::vfunc_13(CInteractObject* pObject)
{
    int nType = pObject->vfunc_5();
    if (nType == 8)
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14095DC90, BillBoardInteractAction, vfunc_13, 55, 0x64843525);

// ---- HomemadeCubeAction ----------------------------------------------------------------------------------------------
// @0x14095dcd0
HomemadeCubeAction::HomemadeCubeAction() {}
// @0x14095e0d0
void HomemadeCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095E0D0, HomemadeCubeAction, vfunc_2, 24, 0x33628DB0);
// @0x14095e0f0
int HomemadeCubeAction::vfunc_5() { return 2; }
MS2_REPLACE_METHOD(0x14095E0F0, HomemadeCubeAction, vfunc_5, 11, 0x620C90F9);
// @0x14095e3d0
CStringW HomemadeCubeAction::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x14095E3D0, HomemadeCubeAction, vfunc_8, 61, 0xEB07375E);
// @0x14095e420
int HomemadeCubeAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095E420, HomemadeCubeAction, vfunc_10, 8, 0x7F371472);
// @0x14095e430
void HomemadeCubeAction::vfunc_3() {}
MS2_REPLACE_METHOD(0x14095E430, HomemadeCubeAction, vfunc_3, 6, 0xA9AF6E37);

// ---- NurturingCubeAction ---------------------------------------------------------------------------------------------
// @0x14095e490
NurturingCubeAction::NurturingCubeAction() : m_n30(0) {}
// @0x14095e830
void NurturingCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
MS2_REPLACE_METHOD(0x14095E830, NurturingCubeAction, vfunc_2, 24, 0x45C50103);
// @0x14095e850
int NurturingCubeAction::vfunc_5() { return 3; }
MS2_REPLACE_METHOD(0x14095E850, NurturingCubeAction, vfunc_5, 11, 0xA6B3D596);
// @0x14095ea60
CStringW NurturingCubeAction::vfunc_8() { return L"key"; }
MS2_REPLACE_METHOD(0x14095EA60, NurturingCubeAction, vfunc_8, 61, 0xD42F286F);
// @0x14095eab0
int NurturingCubeAction::vfunc_10() { return 0; }
MS2_REPLACE_METHOD(0x14095EAB0, NurturingCubeAction, vfunc_10, 8, 0x7F371472);
// @0x14095eac0
void NurturingCubeAction::vfunc_3()
{
    m_str18 = "";
    m_n30 = 0;
}
MS2_REPLACE_METHOD(0x14095EAC0, NurturingCubeAction, vfunc_3, 51, 0x3E397E14);

// ---- BannerAction ----------------------------------------------------------------------------------------------------
// @0x14095eb00
BannerAction::BannerAction() : m_n18(0), m_n1c(0) {}
// @0x14095eb50
BannerAction::~BannerAction() {}
// @0x14095ed00
int BannerAction::vfunc_5() { return 0x19; }
MS2_REPLACE_METHOD(0x14095ED00, BannerAction, vfunc_5, 11, 0x4FAEBC98);

// ---- ReactorAction ---------------------------------------------------------------------------------------------------
// @0x14095f0a0
ReactorAction::ReactorAction() : m_nReactorId(0), m_n1c(0) {}
// @0x14095f0f0
ReactorAction::~ReactorAction()
{
    m_nReactorId = 0;
}
// @0x14095f850
int ReactorAction::vfunc_5() { return 0x1a; }
MS2_REPLACE_METHOD(0x14095F850, ReactorAction, vfunc_5, 11, 0x01B9B841);
// @0x14095faa0
CStringW ReactorAction::vfunc_7() { return FUN_14016a730("reactor", 0); }
MS2_REPLACE_METHOD(0x14095FAA0, ReactorAction, vfunc_7, 63, 0xDA1646EA);
// @0x14095fc40
int ReactorAction::vfunc_13(efd::SmartPointer<CReactor> spReactor)
{
    if (!spReactor)
        return 0;
    return spReactor->FUN_140b79c30();
}
MS2_REPLACE_METHOD(0x14095FC40, ReactorAction, vfunc_13, 106, 0xBDD2E157);

// ---- QuestUserFindAction ---------------------------------------------------------------------------------------------
// @0x14095fd90
QuestUserFindAction::QuestUserFindAction() : m_n18(0), m_n20(0) {}
// @0x14095fde0
QuestUserFindAction::~QuestUserFindAction() {}
// @0x140960020
int QuestUserFindAction::vfunc_5() { return 7; }
MS2_REPLACE_METHOD(0x140960020, QuestUserFindAction, vfunc_5, 11, 0x41502B22);

// ---- TreeWateringAction ----------------------------------------------------------------------------------------------
// @0x140960250
TreeWateringAction::TreeWateringAction() {}
// @0x140960290
TreeWateringAction::~TreeWateringAction() {}
// @0x1409609f0
int TreeWateringAction::vfunc_5() { return 0x1c; }
MS2_REPLACE_METHOD(0x1409609F0, TreeWateringAction, vfunc_5, 11, 0x25A49707);
