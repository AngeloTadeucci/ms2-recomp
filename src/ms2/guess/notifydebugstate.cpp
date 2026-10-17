// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The CMyCharacter methods (the client's own character state
// singleton: dungeon record manager, room stage state, id -> time table, id -> state map, chat emoticon state, title
// bits), the notices they post (NotifyDebugState, NotifyDungeonEnterState), CChatEmoticonCli's ctor / dtor and the
// container / Delegate / MS2Ptr glue over those members. (The unit was first filed under chatemoticoncli.cpp; the name
// notifydebugstate is the filer's guess.)
// MS2-UNIT: ?\notifydebugstate.cpp
// MS2-RANGE: 0x140d9ee70-0x140da4da0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@H@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@H@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x140d9fac0 ; unique
// MS2-PIN: ??$?0V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N$0A@@?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@std@@QEAA@$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@$$QEA_N@Z 0x140d9fbe0 ; unique
// MS2-PIN: ??$?0V?$tuple@AEBH@std@@V?$tuple@$$V@1@$0A@$$Z$S@?$pair@$$CBHI@std@@QEAA@AEAV?$tuple@AEBH@1@AEAV?$tuple@$$V@1@U?$integer_sequence@_K$0A@@1@U?$integer_sequence@_K$S@1@@Z 0x140d9fc30 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140d9fd70 ; unique
// MS2-PIN: ??$_Insert_at@AEAU?$pair@$$CBHI@std@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@_NPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEAU?$pair@$$CBHI@1@1@Z 0x140d9fed0 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHI@std@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@AEAU?$pair@$$CBHI@1@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@@Z 0x140da0230 ; unique
// MS2-PIN: ??$_Insert_nohint@AEAU?$pair@$$CBHI@std@@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@1@_NAEAU?$pair@$$CBHI@1@PEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@@Z 0x140da0e70 ; unique
// MS2-PIN: ??$_Lbound@H@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@1@AEBH@Z 0x140da1290 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x140da1330 ; unique
// MS2-PIN: ??$addressof@U?$pair@$$CBHI@std@@@std@@YAPEAU?$pair@$$CBHI@0@AEAU10@@Z 0x140da1490 ; prop
// MS2-PIN: ??$addressof@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@YAPEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@0@AEAV10@@Z 0x140da14a0 ; prop
// MS2-PIN: ??$construct@U?$pair@$$CBHI@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@std@@@1@QEAU?$pair@$$CBHI@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140da1500 ; unique
// MS2-PIN: ??$emplace_hint@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x140da15d0 ; unique
// MS2-PIN: ??0?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAA@IMMMI@Z 0x140da1760 ; unique
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x140da1b30 ; unique
// MS2-PIN: ??0?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x140da1ba0 ; unique
// MS2-PIN: ??0?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA@XZ 0x140da1dc0 ; unique
// MS2-PIN: ??1?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAA@XZ 0x140da1f20 ; unique
// MS2-PIN: ??1?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAA@XZ 0x140da2100 ; unique
// MS2-PIN: ??1NotifyDungeonEnterState@@UEAA@XZ 0x140da21a0 ; order
// MS2-PIN: ??A?$map@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@@std@@QEAAAEAIAEBH@Z 0x140da22e0 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHI@1@XZ 0x140da2340 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHI@1@XZ 0x140da2380 ; prop
// MS2-PIN: ??0?$list@IV?$allocator@I@std@@@std@@QEAA@XZ 0x140da24c0 ; prop
// MS2-PIN: ??_GNotifyDungeonEnterState@@UEAAPEAXI@Z 0x140da2670 ; order
// MS2-PIN: ?GetNode@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x140da28c0 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEBA_NHAEA_J@Z 0x140da2b40 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXXZ 0x140da30d0 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140da31e0 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140da32d0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAPEAU__POSITION@@H_J@Z 0x140da3390 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@H_JV?$CElementTraits@H@ATL@@V?$CElementTraits@_J@2@@ATL@@QEAAXMMM_N@Z 0x140da3430 ; unique
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x140da37e0 ; unique
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@XZ 0x140da38a0 ; unique
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x140da3980 ; unique
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXXZ 0x140da39f0 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x140da3a20 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x140da3a70 ; unique
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x140da4120 ; prop
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@2@XZ 0x140da4180 ; prop
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEBAAEBU?$less@H@2@XZ 0x140da42e0 ; order
// MS2-PIN: ?_Key@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAAEBHPEAU?$_Tree_node@U?$pair@$$CBHI@std@@PEAX@2@@Z 0x140da4300 ; unique
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEBAAEBHAEBU?$pair@$$CBHI@2@@Z 0x140da4330 ; unique
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@IEAAXXZ 0x140da46b0 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@@Z 0x140da4a80 ; unique
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x140da4b30 ; unique
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HIU?$less@H@std@@V?$allocator@U?$pair@$$CBHI@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHI@std@@@std@@@std@@@2@AEBH@Z 0x140da4cd0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHI@std@@@std@@SAPEAU?$pair@$$CBHI@2@AEAU32@@Z 0x140da4d60 ; prop
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: ??0CChatEmoticonCli@@QEAA@XZ 0x140da1df0
// MS2-PIN: ??1CChatEmoticonCli@@UEAA@XZ 0x140da2120
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\notifydebugstate.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <list>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/dungeonrecordmanagercli.h"
#include "ms2/placeholder/roomstagedungeoncli.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/client/ms2/uimainplayerinfo.h"

// The notices CMyCharacter posts (the name virtual vfunc_1 is defined in unit_140db46d0).
class NotifyDebugState : public NotifyObject
{
public:
    NotifyDebugState();                         // 0x140da1ec0
    virtual CStringW vfunc_1();
};
MS2_CHECK_SIZE(NotifyDebugState, 0x18);

class NotifyDungeonEnterState : public NotifyObject
{
public:
    NotifyDungeonEnterState();                  // 0x140da1ef0
    virtual CStringW vfunc_1();
};
MS2_CHECK_SIZE(NotifyDungeonEnterState, 0x18);

// Out-of-unit helpers.
class Unk_McPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> handler);
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> handler);
};
Unk_McPackets* FUN_140bccd50();
class Unk_McNotices
{
public:
    void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify);
};
Unk_McNotices* FUN_140939a10();
UIMainPlayerInfo* FUN_140931900(int nUiId);
__int64 FUN_140869440();                        // server time
int FUN_141472bc0();                            // tick count
CInputStream& FUN_14070f480(CInputStream& in, int& value);
CInputStream& FUN_14070f500(CInputStream& in, __int64& value);

// @0x140da1ec0
NotifyDebugState::NotifyDebugState()
{
}

// @0x140da1ef0
NotifyDungeonEnterState::NotifyDungeonEnterState()
{
}

// @0x140da1df0
CChatEmoticonCli::CChatEmoticonCli()
{
}

// @0x140da2120
CChatEmoticonCli::~CChatEmoticonCli()
{
}

// @0x140d9ee70
CMyCharacter::CMyCharacter()
    : m_spRecord(new DungeonRecordManagerCli), m_spChatEmoticon(new CChatEmoticonCli)
{
    FUN_140d9f140();
}

// @0x140d9efd0
CMyCharacter::~CMyCharacter()
{
}

// @0x140d9f040
void CMyCharacter::FUN_140d9f040()
{
    FUN_140bccd50()->FUN_140da5180(0xd9, Delegate<void(CInPacket&)>(this, &CMyCharacter::FUN_140d9f200));
}

// @0x140d9f0c0
void CMyCharacter::FUN_140d9f0c0()
{
    FUN_140bccd50()->FUN_140da51e0(0xd9, Delegate<void(CInPacket&)>(this, &CMyCharacter::FUN_140d9f200));
}

// @0x140d9f140
void CMyCharacter::FUN_140d9f140()
{
    if (m_spRecord != 0)
        m_spRecord->Clear();
    m_nExpire = 0;
    m_times.RemoveAll();
    m_states.clear();
    FUN_140d9f4b0();
}

// @0x140d9fc80
CInputStream& FUN_140d9fc80(CInputStream& in, ATL::CAtlMap<int, __int64>& map)
{
    unsigned nCount = in.vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nKey;
        __int64 nValue;
        FUN_14070f500(FUN_14070f480(in, nKey), nValue);
        map.SetAt(nKey, nValue);
    }
    return in;
}

// @0x140d9f1c0
void CMyCharacter::FUN_140d9f1c0(CInPacket& packet)
{
    FUN_140d9fc80(packet, m_times);
}

// @0x140d9f200
void CMyCharacter::FUN_140d9f200(CInPacket& packet)
{
    m_titles.Decode(packet);
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyDebugState));
}

// @0x140d9f2c0
MS2Ptr<DungeonRecordManagerCli> CMyCharacter::FUN_140d9f2c0()
{
    return m_spRecord;
}

// @0x140d9f310
// MS2-FUNCTIONAL: stack temp slot order differs (exe keeps the int temps below pInfo)
void CMyCharacter::FUN_140d9f310(__int64 nExpire)
{
    m_nExpire = nExpire;
    UIMainPlayerInfo* pInfo = FUN_140931900(0x4e5f);
    if (pInfo != 0)
    {
        __int64 nNow = FUN_140869440();
        if (nNow < m_nExpire)
        {
            ATL::CTimeSpan span = CMsTime(m_nExpire) - CMsTime(nNow);
            pInfo->FUN_1419f1200(0x5f5e117, (int)(span.GetTotalSeconds() * 1000) + FUN_141472bc0());
        }
        else
            pInfo->FUN_1419f1370(0x5f5e117);
    }
}

// @0x140d9f400
void CMyCharacter::FUN_140d9f400(int nA, int nB, bool bFlag)
{
    m_spStage.AssignRaw(new RoomStageDungeonCli(nA, nB));
    m_spStage->FUN_140c9ce60(bFlag);
}

// @0x140d9f4b0
void CMyCharacter::FUN_140d9f4b0()
{
    m_spStage = 0;
}

// @0x140d9f4e0
MS2Ptr<RoomStageDungeonCli> CMyCharacter::FUN_140d9f4e0()
{
    return m_spStage;
}

// @0x140d9f530
bool CMyCharacter::FUN_140d9f530(int nId)
{
    return m_times.Lookup(nId) != 0;
}

// @0x140d9f580
__int64 CMyCharacter::FUN_140d9f580(int nId)
{
    __int64 nTime = 0;
    if (m_times.Lookup(nId, nTime))
        return nTime;
    return 0;
}

// @0x140d9f5d0
bool CMyCharacter::FUN_140d9f5d0(int nIndex)
{
    return m_titles[nIndex];
}

// @0x140d9f600
// MS2-FUNCTIONAL: CStringW literal temps/branch layout not matched
CStringW CMyCharacter::FUN_140d9f600(int nIndex)
{
    if (nIndex == 0)
        return CStringW(L"InNpc");
    else if (nIndex == 1)
        return CStringW(L"InAll");
    else if (nIndex == 2)
        return CStringW(L"Dp");
    else if (nIndex == 3)
        return CStringW(L"IgDun");
    else
        return CStringW(L"");
}

// @0x140d9f710
void CMyCharacter::FUN_140d9f710(CInPacket& packet)
{
    int nCount = packet.vfunc_o8_3();
    for (int i = 0; i < nCount; i++)
    {
        int nKey = packet.vfunc_o8_3();
        unsigned nState = packet.vfunc_o8_1();
        m_states[nKey] = nState;
    }
    FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new NotifyDungeonEnterState));
}

// @0x140d9f880
unsigned CMyCharacter::FUN_140d9f880(int nId)
{
    std::map<int, unsigned>::iterator it = m_states.find(nId);
    if (it == m_states.end())
        return 0;
    return it->second;
}

// @0x140d9f8f0
MS2Ptr<CChatEmoticonCli> CMyCharacter::FUN_140d9f8f0()
{
    return m_spChatEmoticon;
}
