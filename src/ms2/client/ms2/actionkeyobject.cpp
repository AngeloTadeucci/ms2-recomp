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
#include "ms2/placeholder/mypc.h"
#include "ms2/placeholder/fishingmanager.h"
#include "ms2/placeholder/cube.h"
#include "functioncubeobject.h"
#include "interactobject.h"
#include "reactor.h"
#include "ms2/placeholder/uiheadupdisplay.h"
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

// A field object of the world service (portals, ...); only the members read here.
class Unk_AkoFieldObj : public CPtred
{
public:
    Unk_StreamPoint FUN_14169d2f0();                        // the object's position
    egf::EntityID m_entityId;                               // +0x18 id of the egf entity
    char m_pad_20[0x160 - 0x20];
    int m_nType;                                            // +0x160
};
MS2_CHECK_OFFSET(Unk_AkoFieldObj, m_entityId, 0x18);
MS2_CHECK_OFFSET(Unk_AkoFieldObj, m_nType, 0x160);

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
    int FUN_141adc940(int nUiId);                           // is open
    int FUN_141adc890(int nUiId);                           // is shown
    void FUN_141adc5d0(int nUiId);                          // hide
    void FUN_141adc530(int nUiId);                          // close
};
Unk_AkoUIMgr* FUN_1403ed2b0();
UIObject* FUN_1403ed9e0(Unk_AkoUIRef&);

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

// @0x1409537f0
UIActionTooltip* FUN_1409537f0(int nUiId)
{
    if (FUN_1403ed2b0() != 0)
    {
        Unk_AkoUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nUiId);
        if (ref.FUN_1403e8a70() != 0)
            return dynamic_cast<UIActionTooltip*>(FUN_1403ed9e0(ref));
    }
    return 0;
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
    else if (UIActionTooltip* pTooltip = FUN_1409537f0(0x4e5c))
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
        if (UIActionTooltip* pTooltip = FUN_1409537f0(0x4e5c))
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
    if (UIActionTooltip* pTooltip = FUN_1409537f0(0x4e5c))
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
// @0x140954fe0
void ActionKeyObject::vfunc_2() {}
// @0x140954ff0
void ActionKeyObject::vfunc_3() {}
// @0x140955000
int ActionKeyObject::vfunc_4() { return 1; }
// @0x140955020
int ActionKeyObject::vfunc_5() { return 0x1e; }
// @0x140955040
CStringW ActionKeyObject::vfunc_6() { return L""; }
// @0x140955090
CStringW ActionKeyObject::vfunc_7() { return L""; }
// @0x1409550e0
CStringW ActionKeyObject::vfunc_8() { return L"key"; }
// @0x140955130
void ActionKeyObject::vfunc_9() {}
// @0x140955140
int ActionKeyObject::vfunc_10() { return 0; }
// @0x140954140
bool ActionKeyObject::vfunc_11() { return false; }
// @0x140955150
Unk_AkoTarget ActionKeyObject::vfunc_12() { return Unk_AkoTarget(); }

// ---- TaxiStationAction ----------------------------------------------------------------------------------------------
// @0x140953a80
TaxiStationAction::TaxiStationAction() {}
// @0x14095bf90
int TaxiStationAction::vfunc_5() { return 8; }
// @0x14095bfb0
CStringW TaxiStationAction::vfunc_6() { return FUN_14028de60(0x64a); }

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
// @0x14095d000
CStringW FishingAction::vfunc_6() { return FUN_14028de60(0x658); }

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
// @0x140955a80
int PortalAction::vfunc_5() { return 0x13; }

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
// @0x140957140
int BuyCubeAction::vfunc_5() { return 0x16; }
// @0x140957160
CStringW BuyCubeAction::vfunc_6() { return FUN_14028de60(0x635); }

// ---- LiftCubeAction --------------------------------------------------------------------------------------------------
// @0x140957230
LiftCubeAction::LiftCubeAction() {}
// @0x140957280
LiftCubeAction::~LiftCubeAction() {}
// @0x140957720
int LiftCubeAction::vfunc_5() { return 0x15; }

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
// @0x140958c50
CStringW InteractAction::vfunc_7() { return FUN_14016a730(m_strObjectId, 0); }
// @0x140958e20
int InteractAction::vfunc_13(CInteractObject* pObject)
{
    int nKind = pObject->vfunc_5();
    if (nKind == 6 || nKind == 8)
        return 0;
    return 1;
}

// ---- InteractNpcAction -----------------------------------------------------------------------------------------------
// @0x140958f90
InteractNpcAction::InteractNpcAction() : m_n18(0), m_n20(0) {}
// @0x140958fe0
InteractNpcAction::~InteractNpcAction()
{
    m_n18 = 0;
}
// @0x140959220
int InteractNpcAction::vfunc_5() { return 0x12; }
// @0x1409592e0
void InteractNpcAction::vfunc_9() { vfunc_3(); }
// @0x140959310
void InteractNpcAction::vfunc_3() { m_n20 = 0; }
// @0x140967a50
bool InteractNpcAction::vfunc_11() { return true; }

// ---- ViewCubeMapProfileAction ----------------------------------------------------------------------------------------
// @0x1409596a0
ViewCubeMapProfileAction::ViewCubeMapProfileAction() {}
// @0x1409596e0
ViewCubeMapProfileAction::~ViewCubeMapProfileAction() {}
// @0x140959710
int ViewCubeMapProfileAction::vfunc_1() { return 0; }
// @0x1409597b0
int ViewCubeMapProfileAction::vfunc_5() { return 9; }
// @0x1409597d0
CStringW ViewCubeMapProfileAction::vfunc_6() { return FUN_14028de60(0x648); }

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

// ---- PullObjectWeaponAction ------------------------------------------------------------------------------------------
// @0x140959df0
PullObjectWeaponAction::PullObjectWeaponAction() : m_spCube(0), m_spCube28(0) {}
// @0x140959e60
PullObjectWeaponAction::~PullObjectWeaponAction() {}
// @0x14095a920
int PullObjectWeaponAction::vfunc_5() { return 0xd; }
// @0x14095a940
CStringW PullObjectWeaponAction::vfunc_6() { return FUN_14028de60(0x63c); }

// ---- PutDownLiftableAction -------------------------------------------------------------------------------------------
// @0x14095aa00
PutDownLiftableAction::PutDownLiftableAction() {}
// @0x14095aa40
PutDownLiftableAction::~PutDownLiftableAction() {}
// @0x14095adb0
int PutDownLiftableAction::vfunc_5() { return 0xc; }
// @0x14095add0
CStringW PutDownLiftableAction::vfunc_6() { return FUN_14028de60(0x63d); }

// ---- FunctionCubeAction ----------------------------------------------------------------------------------------------
// @0x14095ae10
FunctionCubeAction::FunctionCubeAction() : m_n20(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095b470
int FunctionCubeAction::vfunc_5() { return 1; }
// @0x14095b690
int FunctionCubeAction::vfunc_10() { return m_n20; }

// ---- FittingDollAction -----------------------------------------------------------------------------------------------
// @0x14095b760
FittingDollAction::FittingDollAction() : m_n18(0), m_id(egf::kENTITY_INVALID) {}
// @0x14095ba40
int FittingDollAction::vfunc_5() { return 0xe; }
// @0x14095bbf0
int FittingDollAction::vfunc_10() { return m_n18; }

// ---- HoldAction ------------------------------------------------------------------------------------------------------
// @0x14095bff0
HoldAction::HoldAction() : m_n18(0), m_n1c(0), m_nNpcId(0), m_f24(0.0f) {}
// @0x14095c540
int HoldAction::vfunc_5() { return 6; }
// @0x14095c6b0
int HoldAction::vfunc_10() { return m_n18; }

// ---- HoldPCAction ----------------------------------------------------------------------------------------------------
// @0x14095c6d0
HoldPCAction::HoldPCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cab0
int HoldPCAction::vfunc_5() { return 0x1b; }
// @0x14095cb70
int HoldPCAction::vfunc_10() { return 0; }

// ---- ReleasePCAction -------------------------------------------------------------------------------------------------
// @0x14095cb80
ReleasePCAction::ReleasePCAction() : m_n18(0), m_f1c(0.0f) {}
// @0x14095cea0
int ReleasePCAction::vfunc_5() { return 0; }
// @0x14095cf70
int ReleasePCAction::vfunc_10() { return 0; }

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
// @0x14095d480
int GatheringAction::vfunc_5() { return 4; }

// ---- BillBoardInteractAction -----------------------------------------------------------------------------------------
// @0x14095d910
BillBoardInteractAction::BillBoardInteractAction() {}
// @0x14095d950
BillBoardInteractAction::~BillBoardInteractAction() {}
// @0x14095d980
int BillBoardInteractAction::vfunc_5() { return 0x18; }
// @0x14095dc90
int BillBoardInteractAction::vfunc_13(CInteractObject* pObject)
{
    int nType = pObject->vfunc_5();
    if (nType == 8)
        return 1;
    return 0;
}

// ---- HomemadeCubeAction ----------------------------------------------------------------------------------------------
// @0x14095dcd0
HomemadeCubeAction::HomemadeCubeAction() {}
// @0x14095e0d0
void HomemadeCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
// @0x14095e0f0
int HomemadeCubeAction::vfunc_5() { return 2; }
// @0x14095e3d0
CStringW HomemadeCubeAction::vfunc_8() { return L"key"; }
// @0x14095e420
int HomemadeCubeAction::vfunc_10() { return 0; }
// @0x14095e430
void HomemadeCubeAction::vfunc_3() {}

// ---- NurturingCubeAction ---------------------------------------------------------------------------------------------
// @0x14095e490
NurturingCubeAction::NurturingCubeAction() : m_n30(0) {}
// @0x14095e830
void NurturingCubeAction::vfunc_2() { FunctionCubeAction::vfunc_2(); }
// @0x14095e850
int NurturingCubeAction::vfunc_5() { return 3; }
// @0x14095ea60
CStringW NurturingCubeAction::vfunc_8() { return L"key"; }
// @0x14095eab0
int NurturingCubeAction::vfunc_10() { return 0; }
// @0x14095eac0
void NurturingCubeAction::vfunc_3()
{
    m_str18 = "";
    m_n30 = 0;
}

// ---- BannerAction ----------------------------------------------------------------------------------------------------
// @0x14095eb00
BannerAction::BannerAction() : m_n18(0), m_n1c(0) {}
// @0x14095eb50
BannerAction::~BannerAction() {}
// @0x14095ed00
int BannerAction::vfunc_5() { return 0x19; }

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
// @0x14095faa0
CStringW ReactorAction::vfunc_7() { return FUN_14016a730("reactor", 0); }
// @0x14095fc40
int ReactorAction::vfunc_13(efd::SmartPointer<CReactor> spReactor)
{
    if (!spReactor)
        return 0;
    return spReactor->FUN_140b79c30();
}

// ---- QuestUserFindAction ---------------------------------------------------------------------------------------------
// @0x14095fd90
QuestUserFindAction::QuestUserFindAction() : m_n18(0), m_n20(0) {}
// @0x14095fde0
QuestUserFindAction::~QuestUserFindAction() {}
// @0x140960020
int QuestUserFindAction::vfunc_5() { return 7; }

// ---- TreeWateringAction ----------------------------------------------------------------------------------------------
// @0x140960250
TreeWateringAction::TreeWateringAction() {}
// @0x140960290
TreeWateringAction::~TreeWateringAction() {}
// @0x1409609f0
int TreeWateringAction::vfunc_5() { return 0x1c; }
