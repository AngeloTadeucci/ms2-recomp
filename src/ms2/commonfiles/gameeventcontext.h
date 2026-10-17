// GameEvent subclasses and *Context types of commonfiles\gameeventcontext.cpp (names from the exe's RTTI / registration
// strings; member names inferred from the XML loaders and the stream readers). w141 partial recovery.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/itemgift.h"
#include <vector>
#include "ms2/placeholder/mstime.h"

// clang-cl devirtualizes a call on an embedded member object into a direct call to an undefined function; go through
// an opaque pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
#define MS2_GE_READ_BYTE(r) (reinterpret_cast<Unk_GEReader*>(r)->ReadByte())
#else
#define MS2_GE_READ_BYTE(r) ((r)->ReadByte())
#endif

// The attend reward entry of the cash attend table (looked up by id through the table group singleton; the table lives
// in attendgiftdatagroup.cpp). Name unknown.
class Unk_CashAttendEntry : public CPtred {
};
class Unk_AttendGiftDataGroup {
public:
    MS2Ptr<Unk_CashAttendEntry> FUN_1401ae630(int id);      // 0x1401ae630
};

class GameEventAttendGift : public GameEvent {
public:
    GameEventAttendGift();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<ItemGift> > m_gifts;  // +0xd0
    CStringW m_strName;                         // +0xf0
    CStringA m_strDesc;                         // +0xf8
    int m_i100;
    int m_i104;
    __int64 m_i108;
    int m_i110;
    int m_i114;
    int m_i118;
    int m_i11c;
    int m_i120;
    bool m_b124;
    bool m_b125;
};
MS2_CHECK_SIZE(GameEventAttendGift, 0x128);
MS2_CHECK_OFFSET(GameEventAttendGift, m_gifts, 0xd0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_strName, 0xf0);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i108, 0x108);
MS2_CHECK_OFFSET(GameEventAttendGift, m_i120, 0x120);
MS2_CHECK_OFFSET(GameEventAttendGift, m_b125, 0x125);

class GameEventCashAttend : public GameEvent {
public:
    GameEventCashAttend();
    virtual CStringW vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Unk_GEOut* out);
    virtual void vfunc_4(Unk_GEIn* in);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_10();
    int FUN_1403fbdc0() { return m_i4; }        // 0x1403fbdc0
private:
    MS2_LAYOUT_FRIEND;
    int m_i0;                                   // +0xd0 table id
    int m_i4;                                   // +0xd4
    CStringW m_strDesc;                         // +0xd8
    MS2Ptr<Unk_CashAttendEntry> m_entry;        // +0xe0
};
MS2_CHECK_SIZE(GameEventCashAttend, 0xf0);
MS2_CHECK_OFFSET(GameEventCashAttend, m_i4, 0xd4);
MS2_CHECK_OFFSET(GameEventCashAttend, m_entry, 0xe0);

// ---- *Context types of gameeventcontext.cpp (w149) ---------------------------------------------------------------------
// CPtred-derived value objects that the GameEvent subclasses of gameevent.cpp fill from their XML (Load*) and stream to
// the client (Write / Read). Their vftables hold only the scalar deleting dtor; the dtors are implicit.

class BlueMarbleEventContext : public CPtred {
public:
    BlueMarbleEventContext(int eventId, CMsTime endTime);   // 0x1403fc710
    void LoadRewards(Unk_140165cf0* pElem);                 // 0x1403fc7c0
    void LoadSlots(Unk_140165cf0* pElem);                   // 0x1403fc990
    void AddReward(int round, MS2Ptr<ItemEntity> spItem);   // 0x1403fcac0
    int m_eventId;                                          // +0x18
    CMsTime m_endTime;                                      // +0x20
    unsigned m_consumeItemID;                               // +0x30 "consumeItemID"
    int m_consumeItemCount;                                 // +0x34 "consumeItemCount"
    ATL::CRBMap<int, MS2Ptr<ItemEntity> > m_rewards;        // +0x38 by "round"
    std::vector<MS2Ptr<BonusGameBlueMarbleSlot> > m_slots;  // +0x68
};  // vftable 0x142d44140
MS2_CHECK_SIZE(BlueMarbleEventContext, 0x80);
MS2_CHECK_OFFSET(BlueMarbleEventContext, m_rewards, 0x38);

enum Unk_DungeonCooldownType {};
class DungeonExtraRewardCountCtx : public CPtred {
public:
    DungeonExtraRewardCountCtx();                           // 0x1403fd6e0
    void Load(Unk_140165cf0* pElem);                        // 0x1403fd750
    int m_18;
    unsigned m_dungeonID;                                   // +0x1c "dungeonID"
    unsigned m_count;                                       // +0x20 "count"
    Unk_DungeonCooldownType m_cooldownType;                 // +0x24 "cooldownType"
    int m_cooldownValue;                                    // +0x28 "cooldownValue"
};  // vftable 0x142d44160
MS2_CHECK_SIZE(DungeonExtraRewardCountCtx, 0x30);
CInputStream& operator>>(CInputStream& in, DungeonExtraRewardCountCtx& ctx);         // 0x1403fd7e0
COutputStream& operator<<(COutputStream& out, const DungeonExtraRewardCountCtx& ctx); // 0x1403fd840

enum Unk_DungeonGroupType {};
class DungeonBonusRewardCtx : public CPtred {
public:
    DungeonBonusRewardCtx();                                // 0x1403fd8a0
    void Load(Unk_140165cf0* pElem);                        // 0x1403fd930
    void Write(COutputStream& out) const;                   // 0x1403fda00
    void Read(CInputStream& in);                            // 0x1403fda90
    void Merge(const MS2Ptr<DungeonBonusRewardCtx>& other); // 0x1403fdb40
    __int64 ApplyMesoRate(__int64 value);                   // 0x1403fdc50
    __int64 ApplyExpRate(__int64 value);                    // 0x1403fdca0
    unsigned m_dungeonID;                                   // +0x18 "dungeonID"
    Unk_DungeonGroupType m_groupType;                       // +0x1c "groupType" (a byte on the wire)
    long m_itemRolls;                                       // +0x20 "itemRolls"
    std::vector<unsigned> m_customDropBoxIds;               // +0x28 "customDropBoxIds"
    float m_mesoRate;                                       // +0x40 "mesoRate"
    float m_expRate;                                        // +0x44 "expRate"
};  // vftable 0x142d44170
MS2_CHECK_SIZE(DungeonBonusRewardCtx, 0x48);
CInputStream& operator>>(CInputStream& in, DungeonBonusRewardCtx& ctx);              // 0x1403fdcf0
COutputStream& operator<<(COutputStream& out, const DungeonBonusRewardCtx& ctx);     // 0x1403fdd20

class ItemBoxEventContext : public CPtred {
public:
    ItemBoxEventContext();                                  // 0x1403fdd50
    void Load(Unk_140165cf0* pElem);                        // 0x1403fdde0
    void Write(COutputStream& out);                         // 0x1403fde90
    void Read(CInPacket& packet);                           // 0x1403fdf70
    unsigned m_fieldID;                                     // +0x18 "fieldID"
    CStringW m_title;                                       // +0x20 "title"
    CStringW m_desc;                                        // +0x28 "desc"
    CStringW m_bannerPath;                                  // +0x30 "bannerPath"
    unsigned m_boxItemID;                                   // +0x38 "boxItemID"
    int m_3c;
};  // vftable 0x142d44180
MS2_CHECK_SIZE(ItemBoxEventContext, 0x40);

// The quest reward rates of GameEventQuestAdditionalReward: the event value is either one rate for every kind or an
// xml document with one attribute per kind plus <item id rate> rows.
class QuestAdditionalRewardContext : public CPtred {
public:
    QuestAdditionalRewardContext();                         // 0x1403fe980
    void Load(CStringW* pValue);                            // 0x1403fea10
    void Write(COutputStream& out);                         // 0x1403fecc0
    void Read(CInPacket& packet);                           // 0x1403fedf0
    unsigned m_rates[8];        // +0x18 exp, meso, guild_fund, guild_exp, guild_coin, lu, karma, menteeCoin
    ATL::CAtlMap<unsigned, unsigned> m_itemRates;           // +0x38 item id -> rate
};  // vftable 0x142d441a0
MS2_CHECK_SIZE(QuestAdditionalRewardContext, 0x80);

// GameEventReturnUser's context (the event holds it as an MS2Ptr; the ctor 0x14041cf20 is in the next unit).
class MentoringContext : public CPtred {
public:
    MentoringContext();
    void Write(COutputStream& out);                         // 0x1403ff4a0
    void Read(CInPacket& packet);                           // 0x1403ff5a0
    int m_18;
    int m_pad_1c;
    __int64 m_20;
    __int64 m_28;
    ATL::CAtlArray<unsigned> m_ids;                         // +0x30
};  // vftable 0x142d44a70
MS2_CHECK_SIZE(MentoringContext, 0x50);

class DungeonBuffEventCtx : public CPtred {
public:
    DungeonBuffEventCtx();                                  // 0x1403ff6c0
    bool Load(Unk_140165cf0* pElem);                        // 0x1403ff720: false without effect GUIDs
    unsigned m_dungeonID;                                   // +0x18 "dungeonID"
    int m_pad_1c;
    std::vector<unsigned __int64> m_addEffectGUIDs;         // +0x20 "addifectGUIDs"
    bool m_isBeginner;                                      // +0x38 "isBeginner"
};  // vftable 0x142d441b0
MS2_CHECK_SIZE(DungeonBuffEventCtx, 0x40);

// The NPC shop give-point event settings (GameEventNpcShopGivePoint::vfunc_5 loads them with Create).
class CNpcShopProductBase;
class CNpcShopGivePointContextBase : public CPtred {
public:
    CNpcShopGivePointContextBase() : m_type(0), m_giveItemId(0) {}      // 0x14040fcf0
    int GetType() { return m_type; }                                    // 0x140413360
    static MS2Ptr<CNpcShopGivePointContextBase> Create(int type, const CStringW& strPath);    // 0x140402150
    static __int64 GetGivePoint(MS2Ptr<CNpcShopGivePointContextBase> spContext,
                                MS2Ptr<CNpcShopProductBase> spProduct);                     // 0x140402390
    int m_type;                     // +0x18 1: CNpcShopGivePointContextCNSpring
    unsigned m_giveItemId;          // +0x1c "giveItemID"
};  // vftable 0x142d441c0
MS2_CHECK_SIZE(CNpcShopGivePointContextBase, 0x20);
class CNpcShopGivePointContextCNSpring : public CNpcShopGivePointContextBase {
public:
    CNpcShopGivePointContextCNSpring() : m_normalPercent(0), m_specialPercent(0) {}   // 0x14040fd40
    __int64 GetGivePoint(__int64 price, int currencyType, int label);  // 0x1404020b0
    unsigned m_normalPercent;       // +0x20 "normalPercent", in 1/10000
    unsigned m_specialPercent;      // +0x24 "specialPercent"
};  // vftable 0x142d441d0
MS2_CHECK_SIZE(CNpcShopGivePointContextCNSpring, 0x28);
