// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGuildManager: guild requests and packet handlers.
// MS2-UNIT: client\ms2\guildmanager.cpp
// MS2-RANGE: 0x1413b5a10-0x1413d3000 .text$mn
// MS2-RANGE: 0x1400f4800-0x1400f4b40 .text$di
// MS2-RANGE: 0x142cb1280-0x142cb1430 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBU?$less@U?$pair@HH@std@@@std@@U_Zero_then_variadic_args_t@1@@?$_Compressed_pair@U?$less@U?$pair@HH@std@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@HH@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@HH@std@@@std@@@2@$00@2@$00@std@@QEAA@U_One_then_variadic_args_t@1@AEBU?$less@U?$pair@HH@std@@@1@$$QEAU_Zero_then_variadic_args_t@1@@Z 0x1413c8280 ; unique
// MS2-PIN: ??$?8PEAVCGuildManager@@P80@EAAXPEAVNotifyObject@@@Z@std@@YA_NAEBU?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@0@0@Z 0x1413c8640 ; prop
// MS2-PIN: ??0?$CTraceCategoryEx@$00$0A@@ATL@@QEAA@PEBD@Z 0x1413c9040 ; order
// MS2-PIN: ??$forward@U_Zero_then_variadic_args_t@std@@@std@@YA$$QEAU_Zero_then_variadic_args_t@0@AEAU10@@Z 0x1413cb810 ; order
// MS2-PIN: ??$forward@_J@std@@YA$$QEA_JAEA_J@Z 0x1413cb830 ; order
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@QEAA@AEBV01@@Z 0x1413cba30 ; prop
// MS2-PIN: ??8?$MS2Ptr@VCGuildMember@@@@QEBA_NPEAVCGuildMember@@@Z 0x1413ccb70 ; order
// MS2-PIN: ??8?$MS2Ptr@VCGuildSkill@@@@QEBA_NPEAVCGuildSkill@@@Z 0x1413ccbb0 ; order
// MS2-PIN: ?AddRef@?$MS2Ptr@VCGuildMember@@@@AEBAXXZ 0x1413cf0c0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCGuildMember@@@@AEBAXPEAX@Z 0x1413cf2a0 ; prop
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1413d1ec0 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEAAXPEAVNotifyObject@@@Z 0x1413d25a0 ; unique
// MS2-PIN: ??$Call@VCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@CAXAEAU?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@PEAVNotifyObject@@@Z 0x1413d2610 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVCGuildManager@@P81@EAAXPEAVNotifyObject@@@Z@std@@@?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x1413d2690 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CGuildManager@@6B?$TSingleton@VCGuildManager@@@@@ 0x142f0a5d8
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@AEBV0@@Z 0x1404ec5b0
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@H@Z 0x1404ec5f0
// MS2-PIN: ??0?$MS2Ptr@VCGuildMember@@@@QEAA@$$QEAV0@@Z 0x1404ec580
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guildmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "guildmanager.h"
#include "pcbase.h"
#include "interactobject.h"
#include "worldservice.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Initializers retained in the .text$di range, in original order (names invented). The range after
// 0x1400f4b40 belongs to the next object (HardwareInstancingService message handlers).
static CStringW s_strGuildArenaJoin(L"guildArenaJoin");                        // @0x1400f4800
static CStringW s_strGuildInvite(L"guildinvite");                              // @0x1400f4830
#define MS2_STATICS_A_BEFORE_CONDITION "ms2/client/ms2/statemanager_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
// the sound / effect keys of the guild notices
static CString s_strSystemGuildInvitation = "System_GuildInvitation";         // @0x1400f49f0
static CString s_strPcGuildMake = "PC_GuildMake";                              // @0x1400f4a20
static CString s_strGuildBattleApply = "guildBattle_Apply";                    // @0x1400f4a50
static CString s_strGuildBattleMatchingFail = "guildBattle_MatchingFail";      // @0x1400f4a80
static CString s_strGuildBattleMatchingSuccess = "guildBattle_MatchingSuccess";   // @0x1400f4ab0
static CString s_strGuildBattleMatchingNotice = "system_notice_GuildBattleMatching01";   // @0x1400f4ae0
static CString s_strPcInviteSuccess = "PC_InviteSuccess";                      // @0x1400f4b10

// ---- callees in other units (names inferred) ----
// Game-wide constants table: only the slots read here.
struct Unk_GuildConstInt { char m_pad_00[0x58]; };
struct Unk_GuildConstTable {
    char m_pad_00[0x4998];
    Unk_GuildConstInt m_guildCreateMinLevel;                  // +0x4998
    char m_pad_49f0[0x4aa0 - 0x49f0];
    Unk_GuildConstInt m_guildDonationMeso;                    // +0x4aa0
    char m_pad_4af8[0x9d60 - 0x4af8];
    Unk_GuildConstInt m_guildNameMinLength;                   // +0x9d60
};
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildCreateMinLevel, 0x4998);
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildDonationMeso, 0x4aa0);
MS2_CHECK_OFFSET(Unk_GuildConstTable, m_guildNameMinLength, 0x9d60);
Unk_GuildConstTable* FUN_1401d3200();
int* FUN_1402056b0(Unk_GuildConstInt* slot);

class Unk_GuildEventMgr { public: bool FUN_14047e880(); };
Unk_GuildEventMgr* FUN_1401c0d90();
class Unk_GuildDialog4e28 { public: void FUN_1419381c0(); };
Unk_GuildDialog4e28* FUN_140938b90(int id);
class Unk_GuildDialog4e4f { public: void FUN_141973a70(); void FUN_141974240(); void FUN_141974640(); void FUN_1419729d0(); void FUN_14196cf80(); };
Unk_GuildDialog4e4f* FUN_14136f480(int id);
class Unk_GuildNotifyCenter {
public:
    void FUN_140da4e40(CStringW name, Delegate<void(NotifyObject*)> handler);
    void FUN_140da4eb0(CStringW name, Delegate<void(NotifyObject*)> handler);
};
Unk_GuildNotifyCenter* FUN_140939a10();
class Unk_GuildFieldMgr { public: void FUN_14161cd60(__int64 characterId); };
Unk_GuildFieldMgr* FUN_1409f7c90();
// Ban-word filter behind the string table manager.
class Unk_GuildBanWord {
public:
    int FUN_140225720(const CStringW& text, CStringW& message);
    int FUN_1402259b0(const CStringW& text, CStringW& message);
    int FUN_140225c90(const CStringW& text, CStringW& message);
    int FUN_140225de0(const CStringW& text, CStringW& message);
};
class Unk_GuildBanWordPtr { public: ~Unk_GuildBanWordPtr(); Unk_GuildBanWord* FUN_14025cea0() const; void* m_00; void* m_08; };
class Unk_GuildStringMgr { public: Unk_GuildBanWordPtr FUN_140229a50(); };
Unk_GuildStringMgr* FUN_14025e7d0();
WorldService* FUN_1403ed2d0();
CGuildManager* FUN_1403ed290();
CGuildXmlData* FUN_1404f4530();
// Game event bonus (guild donation bonus rate in 1/10000).
class Unk_GuildEventBonus { public: int FUN_140423780(); };
class Unk_GuildGameEventMgr { public: Unk_GuildEventBonus* FUN_1403eea90(); };
Unk_GuildGameEventMgr* FUN_140302b00();
// Party/field recall gate.
class Unk_GuildRecallGate { public: int FUN_140b040a0(int count); };
Unk_GuildRecallGate* FUN_140d294c0();
bool FUN_140841300(const CStringW& text, const char* value);
extern __int64 DAT_143ab2898;   // the local character's meso
extern int DAT_143ab2870;       // the local character's current map id
// A buff lookup result of the local character's buff list (PCBase::FUN_1416749a0).
class Unk_GuildBuffRef {
public:
    ~Unk_GuildBuffRef();                                       // 0x14096e5a0
    void* FUN_140975b90();                                     // the active buff, or 0
    void* m_00;
    void* m_08;
};
class Unk_PCBaseBuffs {
public:
    Unk_GuildBuffRef FUN_14096fe60(int buffId, unsigned short level, int a, bool b, int c);
};
CStringW FUN_14062b4f0(CStringW key, const int* value);
// The housing service, looked up from its registry cell.
class Unk_GuildHousingSvc { public: int FUN_1410d2f10(); };
class Unk_GuildHousingSvcPtr {
public:
    Unk_GuildHousingSvcPtr(Unk_GuildHousingSvc* p);           // 0x1401cd0b0
    ~Unk_GuildHousingSvcPtr();                                 // 0x1401cd150
    Unk_GuildHousingSvc* FUN_140885310() const;                // get
    Unk_GuildHousingSvc* FUN_1401cd1a0() const;                // operator->
    Unk_GuildHousingSvc* m_p;
};
Unk_GuildHousingSvc* FUN_1401cd040(char* cell);
extern char DAT_143b059e8;
// Content switches (feature ids).
class Unk_GuildFeatures { public: bool FUN_14036d570(int feature); };
Unk_GuildFeatures* FUN_140166410();
MS2Ptr<CItemData> FUN_14053f870(int itemId);
CStringW FUN_140938ae0(CStringW key, const int& value);
void FUN_140d73aa0(CStringW text, int type, void* data, CStringW tag);
void* FUN_1409613d0(PCBase* pc);
int FUN_140869470(int days);
CStringW FUN_14028de60(int id);
CStringW FUN_14028b8e0(const CStringW& key);
void FUN_1412751b0(const CStringW& text, int type);
void FUN_1412751f0(const CStringW& text, int type, int flag);
void FUN_141275260(int id, int type, int flag);
void FUN_141276180(const CString& name, const CString& arg);
void FUN_140d73bc0(int id, int a, void* b, CStringW text);
int FUN_141276c80(const CStringW& name, bool kind, CStringW& message);
int FUN_14086ace0(__int64 time);
bool FUN_1407105c0(COutPacket* packet, int key, int delay);
__int64 FUN_140869440();
// CGuildInfo containers reached through the guild chunk's COMDATs (see guilddef_1.cpp).
void* FUN_1404f4510(void* map);
MS2Ptr<CGuildMember>& FUN_1404f4f70(void* map, void* pos);
void FUN_1404f4700(void* map, void** pos);


// @0x1413b5a10
CGuildManager::CGuildManager()
{
    m_invite = 0;
    m_lastPvpHistoryId = 0;
    m_noticeAttendance = true;
    m_3e0 = false;
    m_400 = false;
    m_nextRefreshTime = 0;
    m_targetGuildId = 0;
    m_targetGuildName = L"";
    m_468 = 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CGuildManager::FUN_1413bd5c0));
}

// @0x1413b5ca0
CGuildManager::~CGuildManager()
{
    m_invite = 0;
    FUN_140939a10()->FUN_140da4eb0(L"NotifyCompleteMyPC", Delegate<void(NotifyObject*)>(this, &CGuildManager::FUN_1413bd5c0));
}

// @0x1413b5e80
void CGuildManager::FUN_1413b5e80()
{
    if (!FUN_1413b6160()) return;
    if (m_noticeAttendance) {
        if (FUN_1401c0d90()->FUN_14047e880()) {
            FUN_1412751f0(FUN_14028de60(0x3c4), 4, 1);
            m_noticeAttendance = false;
        }
    }
    if (FUN_14086ace0(m_nextRefreshTime) != 0) {
        if (Unk_GuildDialog4e28* dialog = FUN_140938b90(0x4e28))
            dialog->FUN_1419381c0();
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141973a70();
        m_nextRefreshTime = FUN_140869440();
    }
}
MS2_REPLACE_METHOD(0x1413B5E80, CGuildManager, FUN_1413b5e80, 257, 0x8AC759C9);

// @0x1413b5f90
void CGuildManager::FUN_1413b5f90()
{
    if (!FUN_1413b6160()) return;
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if (member.get() != 0)
                FUN_1409f7c90()->FUN_14161cd60(member->data.f08);
        }
    }
    FUN_1404cc900();
    m_lastPvpHistoryId = 0;
    m_pvpHistory.clear();
    m_pvpSeasonHistory.clear();
    m_3e0 = false;
    m_400 = false;
    m_nextRefreshTime = 0;
}
MS2_REPLACE_METHOD(0x1413B5F90, CGuildManager, FUN_1413b5f90, 369, 0x6E224306);

// @0x1413b6110
void CGuildManager::FUN_1413b6110()
{
    if (m_invite == 0) return;
    m_invite = 0;
}
MS2_REPLACE_METHOD(0x1413B6110, CGuildManager, FUN_1413b6110, 65, 0x1957DBAA);

// @0x1413b6160
int CGuildManager::FUN_1413b6160()
{
    if ((unsigned __int64)FUN_1404ccbd0() > 0) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x1413B6160, CGuildManager, FUN_1413b6160, 45, 0x88A95C3B);

// @0x1413b61a0
int CGuildManager::FUN_1413b61a0()
{
    if ((unsigned __int64)FUN_1404ccbd0() > 0) return 0;
    if (m_invite == 0) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1413B61A0, CGuildManager, FUN_1413b61a0, 77, 0x457B72EB);

// @0x1413b6200
MS2Ptr<CGuildMember> CGuildManager::FUN_1413b6200(__int64 characterId)
{
    MS2Ptr<CGuildMember> found(0);
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if ((member.get() ? true : false) && member->data.f08 == characterId) {
                found = member;
                break;
            }
        }
    }
    return found;
}
MS2_REPLACE_METHOD(0x1413B6200, CGuildManager, FUN_1413b6200, 350, 0x4A61614B);

// @0x1413b6370
void CGuildManager::FUN_1413b6370(CInPacket& packet)
{
    int type = static_cast<CInputStream&>(packet).vfunc_o8_1();
    switch (type) {
    case 0: return FUN_1413bd680(packet);
    case 1: return FUN_1413bd8a0(packet);
    case 2: return FUN_1413bda00(packet);
    case 3: return FUN_1413bdaf0(packet);
    case 4: return FUN_1413bdbb0(packet);
    case 5: return FUN_1413be020(packet);
    case 6: return FUN_1413be150(packet);
    case 7: return FUN_1413be350(packet);
    case 8: return FUN_1413be400(packet);
    case 9: return FUN_1413be460(packet);
    case 0xb: return FUN_1413be670(packet);
    case 0xa: return FUN_1413be7e0(packet);
    case 0xc: return FUN_1413be870(packet);
    case 0xe: return FUN_1413beb10(packet);
    case 0xf: return FUN_1413bebc0(packet);
    case 0x71: return FUN_1413bece0(packet);
    case 0x3f: return FUN_1413bee70(packet);
    case 0x40: return FUN_1413beed0(packet);
    case 0x41: return FUN_1413beff0(packet);
    case 0x42: return FUN_1413bf050(packet);
    case 0x43: return FUN_1413bf130(packet);
    case 0x44: return FUN_1413bf2a0(packet);
    case 0x5a: return FUN_1413bf340(packet);
    case 0x5b: return FUN_1413bf540(packet);
    case 0x61: return FUN_1413bf690(packet);
    case 0x63: return FUN_1413bf9a0(packet);
    case 0x12: return FUN_1413bfaf0(packet);
    case 0x13: return FUN_1413bfe50(packet);
    case 0x14: return FUN_1413c0030(packet);
    case 0x21: return FUN_1413c0250(packet);
    case 0x17: return FUN_1413c0430(packet);
    case 0x18: return FUN_1413c0630(packet);
    case 0x15: return FUN_1413c0880(packet);
    case 0x16: return FUN_1413c0be0(packet);
    case 0x24: return FUN_1413c0d30(packet);
    case 0x25: return FUN_1413c0e70(packet);
    case 0x19: return FUN_1413c0fe0(packet);
    case 0x1a: return FUN_1413c13d0(packet);
    case 0x1b: return FUN_1413c15b0(packet);
    case 0x22: return FUN_1413c1720(packet);
    case 0x1c: return FUN_1413c1840(packet);
    case 0x1d: return FUN_1413c1960(packet);
    case 0x1e: return FUN_1413c1c50(packet);
    case 0x20: return FUN_1413c1d30(packet);
    case 0x1f: return FUN_1413c1f00(packet);
    case 0x27: return FUN_1413c2860(packet);
    case 0x28: return FUN_1413c28e0(packet);
    case 0x29: return FUN_1413c2c60(packet);
    case 0x2a: return FUN_1413c2e50(packet);
    case 0x2b: return FUN_1413c2fc0(packet);
    case 0x2c: return FUN_1413c3080(packet);
    case 0x6b: return FUN_1413c3110(packet);
    case 0x32: return FUN_1413c4aa0(packet);
    case 0x33: return FUN_1413c4b60(packet);
    case 0x34: return FUN_1413c4bd0(packet);
    case 0x36: return FUN_1413c3170(packet);
    case 0x37: return FUN_1413c3460(packet);
    case 0x38: return FUN_1413c3780(packet);
    case 0x39: return FUN_1413c39e0(packet);
    case 0x3a: return FUN_1413c3c40(packet);
    case 0x6e: return FUN_1413c3e50(packet);
    case 0x3b: return FUN_1413c3ef0(packet);
    case 0x3d: FUN_1413c41b0(packet);
    case 0x3e: FUN_1413c4300(packet);
    case 0x76: return FUN_1413c4420(packet);
    case 0x75: return FUN_1413c4580(packet);
    case 0x77: return FUN_1413c45e0(packet);
    case 0x7a: return FUN_1413c4870(packet);
    case 0x7b: return FUN_1413c48b0(packet);
    case 0x4c: return FUN_1413c4c40(packet);
    case 0x47: return FUN_1413c4dd0(packet);
    case 0x4f: return FUN_1413c4e20(packet);
    case 0x50: return FUN_1413c4ed0(packet);
    case 0x4d: return FUN_1413c7700(packet);
    case 0x4e: return FUN_1413c7810(packet);
    case 0x23: return FUN_1413c2030(packet);
    case 0x26: return FUN_1413c23d0(packet);
    case 0x35: return FUN_1413c2590(packet);
    case 0x4a: return FUN_1413c5000(packet);
    case 0x4b: return FUN_1413c51c0(packet);
    case 0x52: return FUN_1413c5360(packet);
    case 0x53: return FUN_1413c5440(packet);
    case 0x54: return FUN_1413c5520(packet);
    case 0x55: return FUN_1413c5690(packet);
    case 0x56: return FUN_1413c5840(packet);
    case 0x57: return FUN_1413c59e0(packet);
    case 0x6d: return FUN_1413c5c00(packet);
    case 0x70: return FUN_1413c5dc0(packet);
    case 0x30: return FUN_1413c5f90(packet);
    case 0x2f: return FUN_1413c6180(packet);
    case 0x2d: return FUN_1413c6460(packet);
    case 0x2e: return FUN_1413c6580(packet);
    default:
        MS2_ASSERT_AT(0xeb, FALSE);
    }
}
MS2_REPLACE_METHOD(0x1413B6370, CGuildManager, FUN_1413b6370, 1949, 0xBACC3F7D);

// MS2-FUNCTIONAL: pc->vfunc_78() returns the level as unsigned short in the exe (movzx); pcbase.h declares int.
// @0x1413b6d10
bool CGuildManager::FUN_1413b6d10(CStringW name)
{
    if (FUN_1413b6160() == 1) return false;
    if (FUN_1413b61a0() == 1) return false;
    int minLength = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMinLength);
    if (name.GetLength() < minLength) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_invalide_create_name"), 1, 1);
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225720(name, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return false;
    int level = pc->vfunc_78();
    if (level <= *FUN_1402056b0(&FUN_1401d3200()->m_guildCreateMinLevel)) {
        FUN_1413c66f0(1, 0x13, 0);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(1);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B6D10, CGuildManager, FUN_1413b6d10, 763, 0x714A659F);

// @0x1413b7020
bool CGuildManager::FUN_1413b7020()
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    if (!FUN_1413b6160()) return false;
    if (FUN_1404d0020() > 1) {
        FUN_140d73bc0(0x40e, 0, 0, L"");
        return false;
    }
    if (!FUN_1404d01b0(myName)) return false;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(2);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B7020, CGuildManager, FUN_1413b7020, 395, 0x358783A5);

// @0x1413b71c0
bool CGuildManager::FUN_1413b71c0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    CStringW message;
    int result = FUN_141276c80(name, true, message);
    if (result != 0) {
        int id = result == 10 ? 0x38d : 0x38e;
        FUN_141275260(id, 1, 1);
        return false;
    }
    if (!FUN_1413b6160()) return false;
    if (!FUN_1404d0600(myName, 2)) {
        FUN_141275260(0x415, 1, 1);
        return false;
    }
    if (FUN_1404d0020() >= FUN_1404cd1c0()) {
        FUN_140d73bc0(0x40f, 0, 0, L"");
        return false;
    }
    FUN_141276180(s_strPcInviteSuccess, "");
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B71C0, CGuildManager, FUN_1413b71c0, 810, 0x7CD4D2E7);

// @0x1413b74f0
void CGuildManager::FUN_1413b74f0(int accept)
{
    if (FUN_1413b6160() == 1) return;
    if (!FUN_1413b61a0()) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(5);
    m_invite->FUN_1404c9160(packet);
    packet.vfunc_o10_1((unsigned char)accept);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B74F0, CGuildManager, FUN_1413b74f0, 159, 0xF58ACAD6);

// @0x1413b75a0
void CGuildManager::FUN_1413b75a0()
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (FUN_1404d01b0(myName) == 1) {
        FUN_141275260(0x396, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(7);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B75A0, CGuildManager, FUN_1413b75a0, 275, 0x3A516CA2);

// @0x1413b76c0
void CGuildManager::FUN_1413b76c0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (myName.CompareNoCase(name) == 0) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d0600(myName, 4)) return;
    if (FUN_1404d01b0(name)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B76C0, CGuildManager, FUN_1413b76c0, 498, 0xEC38E14E);

// @0x1413b78c0
void CGuildManager::FUN_1413b78c0(CStringW name, int grade)
{
    int length = name.GetLength();
    if (length < 2 || length > 0x18) {
        MS2_ASSERT_AT(0x664, FALSE);
        return;
    }
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (grade <= 0 || grade > FUN_1404d0580()) return;
    if (!FUN_1404d0600(myName, 0x20)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_8(name);
    packet.vfunc_o10_1((unsigned char)grade);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B78C0, CGuildManager, FUN_1413b78c0, 519, 0x9B2C8425);

// @0x1413b7ad0
void CGuildManager::FUN_1413b7ad0(CStringW name)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (myName.CompareNoCase(name) == 0) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(myName)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x3f);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B7AD0, CGuildManager, FUN_1413b7ad0, 398, 0xE3925E98);

// @0x1413b7c70
bool CGuildManager::FUN_1413b7c70(int kind, CStringW text)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return false;
    if (!FUN_1413b6160()) return false;
    if (kind == 0) {
        if (text.GetLength() > 1000) return false;
        if (!FUN_1404d01b0(myName)) return false;
    } else if (kind == 1) {
        if (text.GetLength() > 300) return false;
        if (!FUN_1404d0600(myName, 8)) return false;
        if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
            CStringW message;
            if (banWord->FUN_1402259b0(text, message) != 0) return false;
        }
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225de0(text, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x40);
    packet.vfunc_o10_1((unsigned char)kind);
    packet.vfunc_o10_8(text);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B7C70, CGuildManager, FUN_1413b7c70, 1105, 0xB7681062);

// @0x1413b80d0
bool CGuildManager::FUN_1413b80d0(const CStringW& text)
{
    if (!FUN_1413b6160()) return false;
    if (text.GetLength() > 0x14) return false;
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225de0(text, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0xd);
    packet.vfunc_o10_8(text);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413B80D0, CGuildManager, FUN_1413b80d0, 333, 0x82B4AE83);

// @0x1413b8230
bool CGuildManager::FUN_1413b8230()
{
    if (!FUN_1413b6160()) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fc8) == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_can_next_day"), 1, 1);
        return false;
    }
    if (!FUN_1413b8460()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_attend_already"), 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0xf);
    FUN_1407105c0(&packet, 0xf, 1000);
    return true;
}
MS2_REPLACE_METHOD(0x1413B8230, CGuildManager, FUN_1413b8230, 549, 0x4E99A56C);

// @0x1413b8460
bool CGuildManager::FUN_1413b8460()
{
    if (!FUN_1413b6160()) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fd8) == 0) return false;
    return true;
}
MS2_REPLACE_METHOD(0x1413B8460, CGuildManager, FUN_1413b8460, 211, 0x527B066B);

// @0x1413b8540
bool CGuildManager::FUN_1413b8540(int amount)
{
    if (!FUN_1413b6160()) return false;
    if (amount <= 0) return false;
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(FUN_1413c7c20());
    if (member == 0) return false;
    if (FUN_14086ace0(member->fc8) == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_can_next_day"), 1, 1);
        return false;
    }
    Unk_PayloadPtr<CGuildXmlData::GuildProperty> property = FUN_1404f4530()->FUN_1404d7410(FUN_1404d1ad0());
    if (property == 0) return false;
    if (member->FUN_1404cb3e0() + amount > property->f30) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_donateMax"), 1, 1);
        return false;
    }
    int bonusRate = FUN_140302b00()->FUN_1403eea90()->FUN_140423780();
    __int64 cost = *FUN_1402056b0(&FUN_1401d3200()->m_guildDonationMeso) * amount;
    __int64 fund = cost;
    fund += fund * ((float)bonusRate / 10000.0f);
    __int64 guildFund = FUN_1404d1df0();
    __int64 guildFundMax = FUN_1404d1e90();
    if (guildFund + fund > guildFundMax) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_donate_guildFundMax"), 1, 1);
        return false;
    }
    if (DAT_143ab2898 < cost) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_no_money"), 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x71);
    packet.vfunc_o10_3(amount);
    FUN_1407105c0(&packet, 0x71, 200);
    return true;
}
MS2_REPLACE_METHOD(0x1413B8540, CGuildManager, FUN_1413b8540, 1331, 0xDB077540);

// @0x1413b8a80
void CGuildManager::FUN_1413b8a80(CString text)
{
    if (text.GetLength() > 500) {
        MS2_ASSERT_AT(0x74b, FALSE);
        return;
    }
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x40)) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x41);
    packet.vfunc_o10_6(text);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8A80, CGuildManager, FUN_1413b8a80, 439, 0x2A0F3618);

// @0x1413b8c40
void CGuildManager::FUN_1413b8c40(int index, CGuildGrade grade)
{
    if (!grade.FUN_1404c72b0()) return;
    if (grade.grade != index) return;
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(myName)) return;
    if (index < 0 || index >= 6) return;
    if (index > FUN_1404d0580() + 1) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x43);
    packet.vfunc_o10_1((unsigned char)index);
    grade.FUN_1404c7160(packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8C40, CGuildManager, FUN_1413b8c40, 537, 0x9A76DCD2);

// @0x1413b8e60
void CGuildManager::FUN_1413b8e60(int focus, int value)
{
    CStringW myName = FUN_1413c7c20();
    if (myName.IsEmpty()) return;
    if (!FUN_1413b6160()) return;
    if (f154 == focus && f158 == value) return;
    if (!FUN_1404d0600(myName, 2)) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x44);
    packet.vfunc_o10_1((unsigned char)focus);
    packet.vfunc_o10_3(value);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8E60, CGuildManager, FUN_1413b8e60, 364, 0x80447355);

// @0x1413b8fe0
void CGuildManager::FUN_1413b8fe0(int skillId)
{
    if (!FUN_1413b6160()) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_141275260(0x416, 1, 1);
        return;
    }
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return;
    int requiredLevel = FUN_1404f4530()->FUN_1404d7130(FUN_1404d1a80());
    if (requiredLevel < skillData->f20) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_level"), 1, 1);
        return;
    }
    int fund = skillData->FUN_1404d4e80() ? FUN_1404d1e40() : FUN_1404d1df0();
    CStringW fundError(skillData->FUN_1404d4e80() ? FUN_14028b8e0(L"s_guild_err_not_enough_guild_event_fund")
                                                   : FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"));
    if (fund < FUN_1403ed290()->FUN_1413bd050(skillId, skillLevel)) {
        FUN_1412751f0(fundError, 1, 1);
        return;
    }
    MS2Ptr<CGuildSkill> skill = FUN_1404d2640(skillId);
    if (skill == 0) return;
    if (!skill->FUN_1404cbcd0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_use_skill"), 1, 1);
        return;
    }
    if (FUN_140841300(skillData->f40, "recall")) {
        ATL::CAtlMap<__int64, __int64> members;
        int memberCount = FUN_1404d3400(&members);
        int count = memberCount - 1;
        if (count <= 0) {
            FUN_140d73bc0(0xb5c, 0, 0, L"");
            return;
        }
        if (FUN_140d294c0()->FUN_140b040a0(count) == 0) return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5a);
    packet.vfunc_o10_3(skillId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B8FE0, CGuildManager, FUN_1413b8fe0, 1783, 0x5D88B8E5);

// @0x1413b96e0
void CGuildManager::FUN_1413b96e0(int skillId)
{
    if (!FUN_1413b6160()) return;
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skillData = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (skillData == 0) return;
    if (!skillData->FUN_1404d4e40()) return;
    int requiredLevel = FUN_1404f4530()->FUN_1404d7130(FUN_1404d1a80());
    if (requiredLevel < skillData->f20) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_level"), 1, 1);
        return;
    }
    if (DAT_143ab2898 < FUN_1413bd1a0(skillId, skillLevel)) {
        FUN_1412751f0(FUN_14028b8e0(L"s_err_lack_meso"), 1, 1);
        return;
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    Unk_GuildBuffRef buff = pc->FUN_1416749a0()->FUN_14096fe60(skillData->f34, skillData->f38, 0, true, 1);
    if (buff.FUN_140975b90() != 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_use_skill"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5b);
    packet.vfunc_o10_3(skillId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413B96E0, CGuildManager, FUN_1413b96e0, 981, 0xCE9A471E);

// @0x1413b9ac0
void CGuildManager::FUN_1413b9ac0(int skillId)
{
    if (!FUN_1413b6160()) return;
    int skillLevel = FUN_1404d26f0(skillId);
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> current = FUN_1404f4530()->FUN_1404d74e0(skillId, skillLevel);
    if (current == 0) return;
    int nextLevel = skillLevel + 1;
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> next = FUN_1404f4530()->FUN_1404d74e0(skillId, nextLevel);
    if (next == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_max_level"), 1, 1);
        return;
    }
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (next->f20 > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &next->f20), 1, 1);
        return;
    }
    int fund = current->FUN_1404d4e80() ? FUN_1404d1e40() : FUN_1404d1df0();
    CStringW fundError(current->FUN_1404d4e80() ? FUN_14028b8e0(L"s_guild_err_not_enough_guild_event_fund")
                                                : FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"));
    if (next->f24 > fund) {
        FUN_1412751f0(fundError, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x5c);
    packet.vfunc_o10_3(skillId);
    FUN_1407105c0(&packet, 0x5c, 1000);
}
MS2_REPLACE_METHOD(0x1413B9AC0, CGuildManager, FUN_1413b9ac0, 1453, 0xDA842B83);

// @0x1413ba080
void CGuildManager::FUN_1413ba080(int eventId)
{
    if (!FUN_1413b6160()) return;
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(eventId);
    if (eventData == 0) return;
    __int64 now = FUN_140869440();
    if (FUN_1404ccec0() + FUN_140869470(1) > now) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_cannot_open_event_create_date"), 1, 1);
        return;
    }
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x400)) {
        FUN_141275260(0x415, 1, 1);
        return;
    }
    MS2Ptr<CGuildCustomEvent> customEvent = FUN_1404d27b0(eventId);
    if (customEvent == 0) return;
    if (customEvent->FUN_1404cbee0() == true) return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(99);
    packet.vfunc_o10_3(eventId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA080, CGuildManager, FUN_1413ba080, 636, 0x9FB82CA0);

// @0x1413ba310
void CGuildManager::FUN_1413ba310(int eventId)
{
    if (!FUN_1413b6160()) return;
    Unk_PayloadPtr<CGuildXmlData::GuildEvent> eventData = FUN_1404f4530()->FUN_1404d7830(eventId);
    if (eventData == 0) return;
    MS2Ptr<CGuildCustomEvent> customEvent = FUN_1404d27b0(eventId);
    if (customEvent == 0) return;
    if (!customEvent->FUN_1404cbee0()) return;
    if (DAT_143ab2870 == eventData->f1c) {
        FUN_141275260(0x27b, 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(100);
    packet.vfunc_o10_3(eventId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA310, CGuildManager, FUN_1413ba310, 403, 0xD386C619);

// @0x1413ba4b0
void CGuildManager::FUN_1413ba4b0()
{
    if (!FUN_1413b6160()) return;
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    if (pc->FUN_14166ce30() == 1) {
        FUN_141275260(0x279, 1, 1);
        return;
    }
    if (pc->vfunc_65() == 1) {
        FUN_141275260(0x27a, 1, 1);
        return;
    }
    int houseLevel = FUN_1404d1f90();
    int houseTheme = FUN_1404d2030();
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(houseLevel, houseTheme);
    if (house == 0) return;
    if (FUN_1403ed2d0()->FUN_141bd3060() == house->f50) {
        FUN_1412751f0(FUN_14028b8e0(L"s_common_cant_move_from_here"), 1, 1);
        return;
    }
    if (FUN_1403ed2d0()->FUN_141bd30a0()->m_5c == 0) {
        Unk_GuildHousingSvcPtr housing(FUN_1401cd040(&DAT_143b059e8));
        if ((housing.FUN_140885310() ? true : false) && housing.FUN_1401cd1a0()->FUN_1410d2f10()) {
        } else {
            FUN_1412751f0(FUN_14028b8e0(L"s_common_cant_move_from_here"), 1, 1);
            return;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x67);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BA4B0, CGuildManager, FUN_1413ba4b0, 860, 0x926C7D25);

// @0x1413ba820
void CGuildManager::FUN_1413ba820(int level, int theme)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    if (!FUN_1413b6160()) return;
    int nextLevel = FUN_1404d1f90() + 1;
    if (level != nextLevel) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_need_pre_house_level"), 1, 1);
        return;
    }
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(nextLevel, theme);
    if (house == 0) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (house->f2c > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &house->f2c), 1, 1);
        return;
    }
    if (house->f28 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x65);
    packet.vfunc_o10_3(theme);
    FUN_1407105c0(&packet, 0x65, 1000);
}
MS2_REPLACE_METHOD(0x1413BA820, CGuildManager, FUN_1413ba820, 956, 0x590A86BA);

// @0x1413babf0
void CGuildManager::FUN_1413babf0(int theme)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    if (!FUN_1413b6160()) return;
    int level = FUN_1404d1f90();
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house = FUN_1404f4530()->FUN_1404d79b0(level, theme);
    if (house == 0) return;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    int currentTheme = FUN_1404d2030();
    if (currentTheme == theme) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_same_guild_house_theme"), 1, 1);
        return;
    }
    if (house->f30 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x66);
    packet.vfunc_o10_3(theme);
    FUN_1407105c0(&packet, 0x66, 1000);
}
MS2_REPLACE_METHOD(0x1413BABF0, CGuildManager, FUN_1413babf0, 754, 0x4477F79B);

// @0x1413baef0
void CGuildManager::FUN_1413baef0(int posterId, unsigned char show)
{
    if (!FUN_140166410()->FUN_14036d570(0x5b)) return;
    ATL::CAtlArray<MS2Ptr<CInteractObject>> objects;
    FUN_1403ed2d0()->FUN_141bc5fb0(&objects, 7);
    for (size_t i = 0; i < objects.GetCount(); i++) {
        CInteractGuildPosterObject* poster = dynamic_cast<CInteractGuildPosterObject*>(objects[i].get());
        if (poster == 0) continue;
        if (poster->FUN_141402e60() != posterId) continue;
        poster->FUN_141402eb0(show);
    }
}
MS2_REPLACE_METHOD(0x1413BAEF0, CGuildManager, FUN_1413baef0, 262, 0x193C7769);

// @0x1413bb000
void CGuildManager::FUN_1413bb000(Unk_GuildNpcKind kind)
{
    if (!FUN_1413b6160()) return;
    int level = FUN_1404d2990(kind);
    int nextLevel = level + 1;
    Unk_PayloadPtr<CGuildXmlData::GuildNpc> npc = FUN_1404f4530()->FUN_1404d7b40(kind, nextLevel);
    if (npc == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_max_level"), 1, 1);
        return;
    }
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return;
    }
    if (npc->f28 > FUN_1404d1ad0()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &npc->f28), 1, 1);
        return;
    }
    if (npc->f2c > FUN_1404d1f90()) {
        FUN_1412751f0(FUN_14062b4f0(CStringW(L"s_guild_err_need_guild_level"), &npc->f2c), 1, 1);
        return;
    }
    if (npc->f20 > FUN_1404d1df0()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_not_enough_guild_fund"), 1, 1);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x72);
    packet.vfunc_o10_3(kind);
    FUN_1407105c0(&packet, 0x72, 1000);
}
MS2_REPLACE_METHOD(0x1413BB000, CGuildManager, FUN_1413bb000, 1152, 0xB931FFA8);

// @0x1413bb490
bool CGuildManager::FUN_1413bb490(ItemEntity& item, const CStringW& receiver)
{
    if (!FUN_1413b6160()) return false;
    if (!FUN_1404d01b0(FUN_1413c7c20())) {
        FUN_1412751f0(FUN_14028de60(0x416), 1, 1);
        return false;
    }
    if (receiver.IsEmpty()) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_empty_member"), 1, 1);
        return false;
    }
    MS2Ptr<CGuildMember> member = FUN_1404cf9f0(receiver);
    if (member == 0) {
        FUN_1412751f0(FUN_14028de60(0x40d), 1, 1);
        return false;
    }
    if (item.m_count == 0) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_empty_count"), 1, 1);
        return false;
    }
    int stored = FUN_1404d2db0(item.vfunc_o18_0(), item.vfunc_o18_1());
    if (stored < 0) stored = 0;
    MS2Ptr<CItemData> itemData = FUN_14053f870(item.vfunc_o18_0());
    if (itemData == 0) return false;
    if ((unsigned)itemData->FUN_14053de60() < item.m_count) {
        int maxCount = itemData->FUN_14053de60();
        FUN_1412751f0(FUN_140938ae0(CStringW(L"s_guild_err_storage_over_slot_max_count"), maxCount), 1, 1);
        return false;
    }
    if ((unsigned)stored < item.m_count) {
        FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_storage_not_enough_count"), 1, 1);
        return false;
    }
    if (itemData->FUN_14053c6b0(0xd7)) {
        if (receiver == FUN_1413c7c20()) {
            FUN_1412751f0(FUN_14028b8e0(L"s_guild_err_storage_send_only_to_me"), 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x6d);
    item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(static_cast<COutputStream&>(packet)));   // itemgift.h types the stream as Unk_GiftOutput
    packet.vfunc_o10_8(receiver);
    FUN_1407105c0(&packet, 0x6d, 1000);
    return true;
}
MS2_REPLACE_METHOD(0x1413BB490, CGuildManager, FUN_1413bb490, 1766, 0x29FDE838);

// @0x1413bbb80
void CGuildManager::FUN_1413bbb80()
{
    if (!m_400) {
        COutPacket packet(0x4b, 0);
        packet.vfunc_o10_1(0x70);
        FUN_140710590(packet);
    } else {
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_1419729d0();
    }
}
MS2_REPLACE_METHOD(0x1413BBB80, CGuildManager, FUN_1413bbb80, 129, 0x0AB11C34);

// @0x1413bbc10
bool CGuildManager::FUN_1413bbc10(const CStringW& title, const CStringW& body)
{
    if (title.GetLength() > 100) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (body.GetLength() > 2000) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (body.GetLength() < 1 || title.GetLength() < 1) {
        FUN_141275260(0x244, 1, 1);
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225c90(title, message) || banWord->FUN_140225de0(body, message)) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    if (!FUN_1404d0600(FUN_1413c7c20(), 0x80)) {
        FUN_141275260(0x415, 1, 1);
        return false;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x47);
    packet.vfunc_o10_8(title);
    packet.vfunc_o10_8(body);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413BBC10, CGuildManager, FUN_1413bbc10, 609, 0xBC0EAAEE);

// @0x1413bbe80
void CGuildManager::FUN_1413bbe80()
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x4a);
    packet.vfunc_o10_4(m_lastPvpHistoryId);
    FUN_140710590(packet);
    if (!m_3e0) {
        COutPacket seasonPacket(0x4b, 0);
        seasonPacket.vfunc_o10_1(0x4b);
        FUN_140710590(seasonPacket);
        m_3e0 = true;
    } else {
        if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
            dialog->FUN_141974640();
    }
}
MS2_REPLACE_METHOD(0x1413BBE80, CGuildManager, FUN_1413bbe80, 226, 0xCC07F015);

// @0x1413bbf70
void CGuildManager::FUN_1413bbf70(ATL::CAtlArray<MS2Ptr<CGuildPVPHistoryData>>& out)
{
    for (int i = (int)m_pvpHistory.size() - 1; i >= 0; i--)
        out.Add(m_pvpHistory[i]);
}
MS2_REPLACE_METHOD(0x1413BBF70, CGuildManager, FUN_1413bbf70, 103, 0x37334414);

// @0x1413bbfe0
void CGuildManager::FUN_1413bbfe0(ATL::CAtlArray<MS2Ptr<CGuildPVPSeasonHistoryData>>& out)
{
    for (int i = (int)m_pvpSeasonHistory.size() - 1; i >= 0; i--)
        out.Add(m_pvpSeasonHistory[i]);
}
MS2_REPLACE_METHOD(0x1413BBFE0, CGuildManager, FUN_1413bbfe0, 103, 0xB4A0F13B);

// @0x1413bc050
void CGuildManager::FUN_1413bc050()
{
    if (FUN_1404d10d0() != 2) {
        CStringW message = FUN_14028de60(0x3c5);
        FUN_1412751f0(message, 1, 1);
        return;
    }
    if (FUN_1404ccbd0() != m_targetGuildId) {
        CStringW message = FUN_14028de60(0x3c7);
        FUN_1412751f0(message, 1, 1);
        return;
    }
    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pc == 0) return;
    if (pc->FUN_14166ce30() == 1) {
        FUN_141275260(0x279, 1, 1);
        return;
    }
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC050, CGuildManager, FUN_1413bc050, 314, 0x235DE993);

// @0x1413bc190
void CGuildManager::FUN_1413bc190()
{
    COutPacket packet(0x61, 0);
    packet.vfunc_o10_1(4);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC190, CGuildManager, FUN_1413bc190, 75, 0x5F2CD8B4);

// @0x1413bc1f0
void CGuildManager::FUN_1413bc1f0(__int64 guildId, CStringW guildName)
{
    m_targetGuildId = guildId;
    m_targetGuildName = guildName;
}
MS2_REPLACE_METHOD(0x1413BC1F0, CGuildManager, FUN_1413bc1f0, 87, 0xF179820B);

// @0x1413bc250
void CGuildManager::FUN_1413bc250(Unk_GuildTarget* target)
{
    __int64 guildId = target->vfunc_4();
    CStringW guildName = target->vfunc_8();
    m_targetGuildId = guildId;
    m_targetGuildName = guildName;
    FUN_140d73aa0(FUN_14028de60(0x3c8), 0, 0, CStringW(L""));
    if (Unk_GuildDialog4e4f* dialog = FUN_14136f480(0x4e4f))
        dialog->FUN_14196cf80();
}
MS2_REPLACE_METHOD(0x1413BC250, CGuildManager, FUN_1413bc250, 314, 0xDB1C9312);

// @0x1413bc390
int CGuildManager::FUN_1413bc390()
{
    int count = 0;
    if (Unk_LockGuard guard = lock) {} else {
        for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
            MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
            if ((member.get() ? true : false) && member->f158 == 0)
                count++;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1413BC390, CGuildManager, FUN_1413bc390, 263, 0xCC512A9E);

// @0x1413bc4a0
void CGuildManager::FUN_1413bc4a0(__int64 guildId)
{
    if (m_joinRequestsForChar.GetCount() >= 10) {
        FUN_1413c66f0(0x52, 0x25, 0);
        return;
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x52);
    packet.vfunc_o10_4(guildId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC4A0, CGuildManager, FUN_1413bc4a0, 146, 0x3573EDB9);

// @0x1413bc540
void CGuildManager::FUN_1413bc540(__int64 guildId)
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x53);
    packet.vfunc_o10_4(guildId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC540, CGuildManager, FUN_1413bc540, 95, 0x24398D36);

// @0x1413bc5b0
void CGuildManager::FUN_1413bc5b0(__int64 characterId, int accept)
{
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x54);
    packet.vfunc_o10_4(characterId);
    packet.vfunc_o10_1((unsigned char)accept);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC5B0, CGuildManager, FUN_1413bc5b0, 118, 0x2ED3EDDE);

// @0x1413bc630
void CGuildManager::FUN_1413bc630()
{
    if (!FUN_1413b6160())
        return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x55);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC630, CGuildManager, FUN_1413bc630, 91, 0xF18B1323);

// @0x1413bc6a0
void CGuildManager::FUN_1413bc6a0()
{
    if (FUN_1413b6160())
        return;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x56);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC6A0, CGuildManager, FUN_1413bc6a0, 91, 0xD33A197F);

// @0x1413bc710
void CGuildManager::FUN_1413bc710(bool anyFocus)
{
    if (FUN_1413b6160())
        return;
    int focus = m_468;
    if (focus == 0) {
        if (!anyFocus) {
            FUN_140d73aa0(FUN_14028de60(0x3c9), 0, 0, CStringW(L""));
            return;
        }
        focus = 0x7fffffff;
    }
    CGuildJoinRequestSchCond cond;
    cond.f18 = focus;
    cond.f1c = 1;
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x57);
    cond.FUN_1404c84e0(&packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1413BC710, CGuildManager, FUN_1413bc710, 321, 0xF2C69BB4);

// @0x1413bc860
bool CGuildManager::FUN_1413bc860(CStringW name)
{
    if (FUN_1413b6160())
        return false;
    if (name.GetLength() < 2) {
        {
            CStringW key(L"s_guild_err_too_short_to_search");
            FUN_1412751f0(FUN_14028b8e0(key), 1, 1);
        }
        return false;
    }
    if (Unk_GuildBanWord* banWord = FUN_14025e7d0()->FUN_140229a50().FUN_14025cea0()) {
        CStringW message;
        if (banWord->FUN_140225720(name, message) != 0) {
            FUN_1412751f0(message, 1, 1);
            return false;
        }
    }
    COutPacket packet(0x4b, 0);
    packet.vfunc_o10_1(0x58);
    packet.vfunc_o10_8(name);
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1413BC860, CGuildManager, FUN_1413bc860, 516, 0x09853FD9);

// @0x1413bca70
int CGuildManager::FUN_1413bca70(std::map<__int64, PCBase*>& out)
{
    if (FUN_1413b6160()) {
        if (Unk_LockGuard guard = lock) {} else {
            for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
                MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
                if (member.get() != 0) {
                    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd1530(member->data.f08);
                    if (pc != 0)
                        out[member->data.f08] = pc;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413BCA70, CGuildManager, FUN_1413bca70, 315, 0x9513FE17);

// @0x1413bcbc0
int CGuildManager::FUN_1413bcbc0(std::map<__int64, PCBase*>& out)
{
    if (FUN_1413b6160()) {
        if (Unk_LockGuard guard = lock) {} else {
            for (void* pos = FUN_1404f4510(&f320); pos != 0; FUN_1404f4700(&f320, &pos)) {
                MS2Ptr<CGuildMember> member = FUN_1404f4f70(&f320, pos);
                if (member.get() != 0) {
                    PCBase* pc = (PCBase*)FUN_1403ed2d0()->FUN_141bd1530(member->data.f08);
                    if (pc != 0 && FUN_1409613d0(pc) == 0)
                        out[member->data.f08] = pc;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1413BCBC0, CGuildManager, FUN_1413bcbc0, 330, 0x3572C05E);
