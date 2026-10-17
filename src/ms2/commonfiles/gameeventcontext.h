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
