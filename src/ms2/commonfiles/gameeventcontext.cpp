// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GameEvent subclasses GameEventAttendGift / CashAttend /
// DTReward, the *Context types the event XML loaders fill, and the CAtlArray / std:: glue over them.
// MS2-UNIT: commonfiles\gameeventcontext.cpp
// MS2-RANGE: 0x1400b8480-0x1400b8700 .text$di
// MS2-RANGE: 0x1403f4e10-0x14041b140 .text$mn
// MS2-PIN: ??1GameEventAttendGift@@UEAA@XZ 0x1403fc070
// MS2-PIN: ??1GameEventCashAttend@@UEAA@XZ 0x1403fc0d0
// MS2-PIN: ??_GGameEventAttendGift@@UEAAPEAXI@Z 0x1403fc190
// MS2-PIN: ??_GGameEventCashAttend@@UEAAPEAXI@Z 0x1403fc1d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventcontext.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <vector>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "gameeventcontext.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit helpers.
// Constructor at 0x140316aa0: registers the factory under the name (the by-value CString is destroyed by the callee).
struct Unk_GEFactoryRegistry {
    Unk_GEFactoryRegistry(CStringW name, GameEvent* (*create)());
    char m_pad;
};
int FUN_140718200(CStringW* text);
// Stream helpers (CInputStream / COutputStream operator<< / >> overloads).
Unk_GEOut* FUN_14070f9a0(Unk_GEOut* out, int value);
Unk_GEOut* FUN_14070fa20(Unk_GEOut* out, __int64 value);
Unk_GEOut* FUN_14070f820(Unk_GEOut* out, bool value);
Unk_GEOut* FUN_14070fb70(Unk_GEOut* out, const Unk_GE16* date);
Unk_GEOut* FUN_14070fae0(Unk_GEOut* out, const CStringW* text);
Unk_GEOut* FUN_14070faa0(Unk_GEOut* out, const CStringA* text);
Unk_GEReader* FUN_14070f480(Unk_GEReader* in, int* value);
Unk_GEReader* FUN_14070f500(Unk_GEReader* in, __int64* value);
Unk_GEReader* FUN_14070f300(Unk_GEReader* in, bool* value);
Unk_GEReader* FUN_14070f6b0(Unk_GEReader* in, Unk_GE16* date);
Unk_GEReader* FUN_14070f5f0(Unk_GEReader* in, CStringW* text);
Unk_GEReader* FUN_14070f580(Unk_GEReader* in, CStringA* text);
Unk_AttendGiftDataGroup* FUN_1403fc330();
// Typed stream operators (packet.cpp).
COutputStream& FUN_14070f860(COutputStream& out, unsigned char value);
COutputStream& FUN_14070f960(COutputStream& out, long value);
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned int value);
COutputStream& FUN_14070fa60(COutputStream& out, float value);
CInputStream& FUN_14070f440(CInputStream& in, long& value);
CInputStream& FUN_14070f480(CInputStream& in, int& value);
CInputStream& FUN_14070f480(CInputStream& in, unsigned& value);
CInputStream& FUN_14070f540(CInputStream& in, float& value);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, long& nOut);
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);   // the document's first child element   // tinyxmlhelper int attribute, long overload
// Enum name parsers (commonenum.cpp).
Unk_BlueMarbleSlotType FUN_140218100(const CStringA& name);
Unk_DungeonCooldownType FUN_1402199e0(const CStringA& name);

// tinyxmlhelper.h: enum attribute given by name (the parser is the enum's string converter).
template <class E, E (*Parse)(const CStringA&)>
int XmlEnumName(Unk_140165cf0* pElem, const char* pszName, E& eOut)
{
    if (0) {
        (void)((!!(0)) || (_wassert(L"FALSE", L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\tinyxmlhelper.h", 250), 0));
        return 2;
    }
    CStringA str;
    int nResult = FUN_1408733e0(pElem, pszName, str);
    if (nResult != 0)
        return nResult;
    eOut = Parse(str);
    return nResult;
}

// Count-prefixed vector streaming.
template <class T> COutputStream& operator<<(COutputStream& out, const std::vector<T>& vec)
{
    out.vfunc_o10_3(vec.size());
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
        FUN_14070f9a0(out, *it);
    return out;
}
template <class T> CInputStream& operator>>(CInputStream& in, std::vector<T>& vec)
{
    unsigned count = in.vfunc_o8_3();
    vec.reserve(count);
    for (unsigned i = 0; i < count; i++) {
        T value;
        FUN_14070f480(in, value);
        vec.push_back(value);
    }
    return in;
}
GameEvent* FUN_1403fb400();
GameEvent* FUN_1403fb9a0();
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts);

extern Unk_AttendGiftDataGroup* DAT_143aac2a8;

// Sort-key names (header static shared with several units).
static CStringA s_sortNames8[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CStringA s_sortNames7[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

#ifndef MS2_HOOK_DLL
// Registration of the event factories by name (dynamic initializers).
static Unk_GEFactoryRegistry s_regAttendGift(L"GameEventAttendGift", FUN_1403fb400);     // 0x143aaee24
static Unk_GEFactoryRegistry s_regCashAttend(L"GameEventCashAttend", FUN_1403fb9a0);     // 0x143aaee25
#endif

// @0x1403fb400
GameEvent* FUN_1403fb400() { return new GameEventAttendGift; }

// @0x1403fb460
CStringW GameEventAttendGift::vfunc_1() { return CStringW(L"GameEventAttendGift"); }

// @0x1403fb4b0
GameEventAttendGift::GameEventAttendGift()
    : m_i100(0), m_i104(0), m_i108(0), m_i110(0), m_i114(0), m_i118(0), m_i11c(0), m_i120(0), m_b124(false), m_b125(true)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fb5e0
void GameEventAttendGift::vfunc_2() {}

// @0x1403fb5f0
void GameEventAttendGift::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070fae0(out, &m_strName);
    FUN_14070faa0(out, &m_strDesc);
    FUN_14070f820(out, m_b124);
    FUN_14070f820(out, m_b125);
    FUN_14070f9a0(out, m_i120);
    out->WriteByte(m_i114);
    FUN_14070f9a0(out, m_i118);
    out->WriteByte(m_i100);
    if (m_i100 != 0) {
        FUN_14070f9a0(out, m_i104);
        FUN_14070fa20(out, m_i108);
        FUN_14070f9a0(out, m_i110);
    }
    FUN_1403fbf30(out, &m_gifts);
}

// @0x1403fb770
void GameEventAttendGift::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f5f0(&in->reader, &m_strName);
    FUN_14070f580(&in->reader, &m_strDesc);
    FUN_14070f300(&in->reader, &m_b124);
    FUN_14070f300(&in->reader, &m_b125);
    FUN_14070f480(&in->reader, &m_i120);
    m_i114 = MS2_GE_READ_BYTE(&in->reader);
    FUN_14070f480(&in->reader, &m_i118);
    m_i100 = MS2_GE_READ_BYTE(&in->reader);
    if (m_i100 != 0) {
        FUN_14070f480(&in->reader, &m_i104);
        FUN_14070f500(&in->reader, &m_i108);
        FUN_14070f480(&in->reader, &m_i110);
    }
    FUN_1403fbe50(&in->reader, &m_gifts);
    vfunc_10();
}

// @0x1403fb970
void GameEventAttendGift::vfunc_5() {}

// @0x1403fb980
void GameEventAttendGift::vfunc_6() {}

// @0x1403fb990
void GameEventAttendGift::vfunc_10() {}

// @0x1403fb9a0
GameEvent* FUN_1403fb9a0() { return new GameEventCashAttend; }

// @0x1403fba00
CStringW GameEventCashAttend::vfunc_1() { return CStringW(L"GameEventCashAttend"); }

// @0x1403fba50
GameEventCashAttend::GameEventCashAttend() : m_i0(0), m_i4(0)
{
    FUN_1402e3480(1);
    FUN_1402e3480(3);
}

// @0x1403fbb00
void GameEventCashAttend::vfunc_2()
{
    m_i0 = FUN_140718200(&m_68);
    m_i4 = FUN_140718200(&m_70);
    m_strDesc = m_78;
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
}

// @0x1403fbbd0
void GameEventCashAttend::vfunc_3(Unk_GEOut* out)
{
    GameEvent::vfunc_3(out);
    FUN_14070fb70(out, &m_28);
    FUN_14070fb70(out, &m_38);
    FUN_14070f9a0(out, m_i0);
    FUN_14070f9a0(out, m_i4);
    FUN_14070fae0(out, &m_strDesc);
}

// @0x1403fbc70
void GameEventCashAttend::vfunc_4(Unk_GEIn* in)
{
    GameEvent::vfunc_4(in);
    FUN_14070f6b0(&in->reader, &m_28);
    FUN_14070f6b0(&in->reader, &m_38);
    FUN_14070f480(&in->reader, &m_i0);
    FUN_14070f480(&in->reader, &m_i4);
    FUN_14070f5f0(&in->reader, &m_strDesc);
    m_entry = FUN_1403fc330()->FUN_1401ae630(m_i0);
    vfunc_10();
}

// @0x1403fbd90
void GameEventCashAttend::vfunc_5() {}

// @0x1403fbda0
void GameEventCashAttend::vfunc_6() {}

// @0x1403fbdb0
void GameEventCashAttend::vfunc_10() {}

// @0x1403fbde0
int FUN_1403fbde0(const CStringA& name)
{
    if (name.CompareNoCase("UserValue") == 0)
        return 1;
    else if (name.CompareNoCase("ItemID") == 0)
        return 2;
    else if (name.CompareNoCase("NotUserValue") == 0)
        return 3;
    return 0;
}

// @0x1403fbe50
void FUN_1403fbe50(Unk_GEReader* in, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    unsigned count = in->ReadInt();
    for (unsigned i = 0; i < count; i++) {
        MS2Ptr<ItemGift> gift(new ItemGift);
        gift->FUN_14026b100(*reinterpret_cast<Unk_GiftInput*>(in));
        gifts->Add(gift);
    }
}

// @0x1403fbf30
void FUN_1403fbf30(Unk_GEOut* out, ATL::CAtlArray<MS2Ptr<ItemGift> >* gifts)
{
    out->WriteInt(gifts->GetCount());
    for (unsigned i = 0; i < gifts->GetCount(); i++) {
        MS2Ptr<ItemGift>& gift = (*gifts)[i];
        gift->FUN_14026b030(*reinterpret_cast<Unk_GiftOutput*>(out));
    }
}

// @0x1403fc330
Unk_AttendGiftDataGroup* FUN_1403fc330() { return DAT_143aac2a8; }

// @0x1403fc640
BonusGameBlueMarbleSlot::BonusGameBlueMarbleSlot() : m_type((Unk_BlueMarbleSlotType)0), m_arg1(0), m_arg2(0) {}

// @0x1403fc6a0
void BonusGameBlueMarbleSlot::Load(Unk_140165cf0* pElem)
{
    XmlEnumName<Unk_BlueMarbleSlotType, FUN_140218100>(pElem, "type", m_type);
    FUN_1408731e0(pElem, "arg1", m_arg1);
    FUN_1408731e0(pElem, "arg2", m_arg2);
}

// @0x1403fc710
BlueMarbleEventContext::BlueMarbleEventContext(int eventId, CMsTime endTime)
    : m_eventId(eventId), m_endTime(endTime), m_consumeItemID(0), m_consumeItemCount(0), m_rewards(10)
{
}

// @0x1403fc7c0
void BlueMarbleEventContext::LoadRewards(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "consumeItemID", m_consumeItemID);
    FUN_1408731e0(pElem, "consumeItemCount", m_consumeItemCount);
    for (Unk_140165cf0* pNode : pElem->FUN_140165cf0("v")) {
        int round = 0;
        FUN_1408731e0(pNode, "round", round);
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        spItem->vfunc_2(pNode);
        AddReward(round, spItem);
    }
}

// @0x1403fc990
void BlueMarbleEventContext::LoadSlots(Unk_140165cf0* pElem)
{
    for (Unk_140165cf0* pNode : pElem->FUN_140165cf0("v")) {
        MS2Ptr<BonusGameBlueMarbleSlot> spSlot(new BonusGameBlueMarbleSlot);
        spSlot->Load(pNode);
        m_slots.push_back(spSlot);
    }
}

// @0x1403fcac0
void BlueMarbleEventContext::AddReward(int round, MS2Ptr<ItemEntity> spItem) { m_rewards.SetAt(round, spItem); }

// @0x1403fcb10
EventTimeLimitDungeonContext::EventTimeLimitDungeonContext() : m_eventId(0), m_dungeonId(0) {}

// @0x1403fcb80
void EventTimeLimitDungeonContext::Write(COutputStream& out)
{
    FUN_14070f9a0(out, m_eventId);
    FUN_14070f9a0(out, m_dungeonId);
    FUN_14070f9a0(out, m_rangeTime.m_start.GetSeconds());
    FUN_14070f9a0(out, m_rangeTime.m_end.GetSeconds());
}

// @0x1403fcc00
void EventTimeLimitDungeonContext::Read(CInputStream& in)
{
    FUN_14070f480(in, m_eventId);
    FUN_14070f480(in, m_dungeonId);
    m_rangeTime.m_start.SetSeconds(in.vfunc_o8_3());
    m_rangeTime.m_end.SetSeconds(in.vfunc_o8_3());
}

// @0x1403fcc90
void StampEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_4(m_endTime);
    out.vfunc_o10_3(m_stamps.GetCount());
    out.vfunc_o10_3(m_98);
    out.vfunc_o10_0(m_b9c);
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        out.vfunc_o10_3(m_stamps[i]->m_id);
        out.vfunc_o10_1(m_stamps[i]->m_bStamped);
        out.vfunc_o10_3(m_stamps[i]->m_20);
        out.vfunc_o10_3(m_stamps[i]->m_24);
    }
    out.vfunc_o10_3(m_rewards.GetCount());
    for (size_t i = 0; i < m_rewards.GetCount(); i++) {
        out.vfunc_o10_3(m_rewards[i]->m_count);
        out.vfunc_o10_1(m_rewards[i]->m_bReceived);
        m_rewards[i]->m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        m_rewards[i]->m_item2.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
}

// @0x1403fd060
void StampEventContext::Read(CInPacket& packet)
{
    m_strTitle = packet.vfunc_o8_8();
    m_endTime = packet.vfunc_o8_4();
    size_t count = (unsigned)packet.vfunc_o8_3();
    m_98 = packet.vfunc_o8_3();
    m_b9c = packet.vfunc_o8_0();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<Stamp> spStamp(new Stamp);
        spStamp->m_id = packet.vfunc_o8_3();
        spStamp->m_bStamped = packet.vfunc_o8_1();
        spStamp->m_20 = packet.vfunc_o8_3();
        spStamp->m_24 = packet.vfunc_o8_3();
        m_stamps.Add(spStamp);
    }
    count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<Reward> spReward(new Reward);
        spReward->m_count = packet.vfunc_o8_3();
        spReward->m_bReceived = packet.vfunc_o8_1();
        spReward->m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        spReward->m_item2.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.Add(spReward);
    }
    m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
}

// @0x1403fd5a0
int StampEventContext::GetStampFlag(int id)
{
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        if (m_stamps[i]->m_id == id)
            return m_stamps[i]->m_bStamped != 0;
    }
    return -1;
}

// @0x1403fd660
BOOL StampEventContext::HasStamp(int id)
{
    for (size_t i = 0; i < m_stamps.GetCount(); i++) {
        if (m_stamps[i]->m_id == id)
            return TRUE;
    }
    return FALSE;
}

// @0x1403fd6e0
DungeonExtraRewardCountCtx::DungeonExtraRewardCountCtx()
    : m_18(0), m_dungeonID(0), m_count(0), m_cooldownType((Unk_DungeonCooldownType)0), m_cooldownValue(0)
{
}

// @0x1403fd750
void DungeonExtraRewardCountCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    FUN_140873220(pElem, "count", m_count);
    XmlEnumName<Unk_DungeonCooldownType, FUN_1402199e0>(pElem, "cooldownType", m_cooldownType);
    FUN_1408731e0(pElem, "cooldownValue", m_cooldownValue);
}

// @0x1403fd7e0
CInputStream& operator>>(CInputStream& in, DungeonExtraRewardCountCtx& ctx)
{
    FUN_14070f480(in, ctx.m_dungeonID);
    FUN_14070f480(in, ctx.m_18);
    FUN_14070f480(in, ctx.m_count);
    return in;
}

// @0x1403fd840
COutputStream& operator<<(COutputStream& out, const DungeonExtraRewardCountCtx& ctx)
{
    FUN_14070f9a0(out, ctx.m_dungeonID);
    FUN_14070f9a0(out, ctx.m_18);
    FUN_14070f9a0(out, ctx.m_count);
    return out;
}

// @0x1403fd8a0
DungeonBonusRewardCtx::DungeonBonusRewardCtx()
    : m_dungeonID(0), m_groupType((Unk_DungeonGroupType)0), m_itemRolls(0), m_mesoRate(0), m_expRate(0)
{
}

// @0x1403fd930
void DungeonBonusRewardCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    XmlValue(pElem, "groupType", m_groupType);
    FUN_140873360(pElem, "mesoRate", m_mesoRate);
    FUN_140873360(pElem, "expRate", m_expRate);
    FUN_1408731e0(pElem, "itemRolls", m_itemRolls);
    XmlTokenList(pElem, "customDropBoxIds", m_customDropBoxIds);
}

// @0x1403fda00
void DungeonBonusRewardCtx::Write(COutputStream& out) const
{
    FUN_14070f9a0(out, m_dungeonID);
    FUN_14070f860(out, (unsigned char)m_groupType);
    FUN_14070fa60(out, m_mesoRate);
    FUN_14070fa60(out, m_expRate);
    FUN_14070f960(out, m_itemRolls);
    out << m_customDropBoxIds;
}

// @0x1403fda90
void DungeonBonusRewardCtx::Read(CInputStream& in)
{
    FUN_14070f480(in, m_dungeonID);
    m_groupType = (Unk_DungeonGroupType)in.vfunc_o8_1();
    FUN_14070f540(in, m_mesoRate);
    FUN_14070f540(in, m_expRate);
    FUN_14070f440(in, m_itemRolls);
    in >> m_customDropBoxIds;
}

// @0x1403fdb40
void DungeonBonusRewardCtx::Merge(const MS2Ptr<DungeonBonusRewardCtx>& other)
{
    if (other == NULL)
        return;
    m_itemRolls += other->m_itemRolls;
    m_mesoRate += other->m_mesoRate;
    m_expRate += other->m_expRate;
    std::copy(other->m_customDropBoxIds.begin(), other->m_customDropBoxIds.end(), std::back_inserter(m_customDropBoxIds));
}

// @0x1403fdc50
__int64 DungeonBonusRewardCtx::ApplyMesoRate(__int64 value)
{
    const double epsilon = 0.001;
    return (__int64)((double)value * m_mesoRate + epsilon);
}

// @0x1403fdca0
__int64 DungeonBonusRewardCtx::ApplyExpRate(__int64 value)
{
    const double epsilon = 0.001;
    return (__int64)((double)value * m_expRate + epsilon);
}

// @0x1403fdcf0
CInputStream& operator>>(CInputStream& in, DungeonBonusRewardCtx& ctx)
{
    ctx.Read(in);
    return in;
}

// @0x1403fdd20
COutputStream& operator<<(COutputStream& out, const DungeonBonusRewardCtx& ctx)
{
    ctx.Write(out);
    return out;
}

// @0x1403fdd50
ItemBoxEventContext::ItemBoxEventContext() : m_fieldID(0), m_boxItemID(0), m_3c(0) {}

// @0x1403fdde0
void ItemBoxEventContext::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "fieldID", m_fieldID);
    FUN_140873220(pElem, "boxItemID", m_boxItemID);
    FUN_140873420(pElem, "bannerPath", m_bannerPath);
    FUN_140873420(pElem, "title", m_title);
    FUN_140873420(pElem, "desc", m_desc);
}

// @0x1403fde90
void ItemBoxEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_fieldID);
    out.vfunc_o10_3(m_boxItemID);
    out.vfunc_o10_8(m_title);
    out.vfunc_o10_8(m_desc);
    out.vfunc_o10_8(m_bannerPath);
    out.vfunc_o10_3(m_3c);
}

// @0x1403fdf70
void ItemBoxEventContext::Read(CInPacket& packet)
{
    m_fieldID = packet.vfunc_o8_3();
    m_boxItemID = packet.vfunc_o8_3();
    m_title = packet.vfunc_o8_8();
    m_desc = packet.vfunc_o8_8();
    m_bannerPath = packet.vfunc_o8_8();
    m_3c = packet.vfunc_o8_3();
}

// @0x1403fe170
TimeRunEventContext::TimeRunEventContext(int eventId) : m_eventId(eventId), m_1c(0), m_value(0), m_endTime(0), m_rewards(10) {}

// @0x1403fe250
void TimeRunEventContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_value);
    out.vfunc_o10_3(m_1c);
    out.vfunc_o10_3(m_quests.GetCount());
    for (POSITION pos = m_quests.GetStartPosition(); pos != NULL; m_quests.GetNext(pos)) {
        MS2Ptr<QuestContext> spQuest = m_quests.GetValueAt(pos);
        out.vfunc_o10_3(spQuest->m_questId);
        out.vfunc_o10_3(spQuest->m_1c);
        out.vfunc_o10_2(spQuest->m_20);
    }
    m_item.FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    out.vfunc_o10_3(m_rewards.GetCount());
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != NULL; m_rewards.GetNext(pos)) {
        unsigned key = m_rewards.GetKeyAt(pos);
        MS2Ptr<ItemEntity> spItem = m_rewards.GetValueAt(pos);
        out.vfunc_o10_3(key);
        spItem->FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
}

// @0x1403fe520
void TimeRunEventContext::Read(CInPacket& packet)
{
    m_quests.RemoveAll();
    m_value = packet.vfunc_o8_3();
    m_1c = packet.vfunc_o8_3();
    size_t count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<QuestContext> spQuest(new QuestContext);
        spQuest->m_questId = packet.vfunc_o8_3();
        spQuest->m_1c = packet.vfunc_o8_3();
        spQuest->m_20 = (unsigned short)packet.vfunc_o8_2();
        m_quests.SetAt(spQuest->m_questId, spQuest);
    }
    m_item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
    count = (unsigned)packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        MS2Ptr<ItemEntity> spItem(new ItemEntity);
        unsigned key = packet.vfunc_o8_3();
        spItem->FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_rewards.SetAt(key, spItem);
    }
}

// @0x1403fe8f0
unsigned TimeRunEventContext::GetNextRewardKey(unsigned value)
{
    for (POSITION pos = m_rewards.GetHeadPosition(); pos != NULL; m_rewards.GetNext(pos)) {
        unsigned key = m_rewards.GetKeyAt(pos);
        if (key > value)
            return key;
    }
    return 0;
}

// @0x1403fe980
QuestAdditionalRewardContext::QuestAdditionalRewardContext() : m_itemRates(17, 0.75f, 0.25f, 2.25f, 10)
{
    memset(m_rates, 0, sizeof(m_rates));
}

// @0x1403fea10
void QuestAdditionalRewardContext::Load(CStringW* pValue)
{
    unsigned rate = FUN_140718200(pValue);
    if (rate != 0) {
        for (size_t i = 0; i < _countof(m_rates); i++)
            m_rates[i] = rate;
    } else {
        TiXmlDocument doc;
        Unk_140165cf0* pRoot;
        if (FUN_140166420()->FUN_140397ab0(&doc, *pValue) != 0 && (pRoot = FUN_140345b40(&doc)) != NULL) {
            FUN_140873220(pRoot, "exp", m_rates[0]);
            FUN_140873220(pRoot, "meso", m_rates[1]);
            FUN_140873220(pRoot, "guild_fund", m_rates[2]);
            FUN_140873220(pRoot, "guild_exp", m_rates[3]);
            FUN_140873220(pRoot, "guild_coin", m_rates[4]);
            FUN_140873220(pRoot, "lu", m_rates[5]);
            FUN_140873220(pRoot, "karma", m_rates[6]);
            FUN_140873220(pRoot, "menteeCoin", m_rates[7]);
            for (Unk_140165cf0* pItem = pRoot->FUN_140165cf0("item"); pItem != NULL;
                 pItem = pItem->FUN_140168650("item")) {
                unsigned id = 0;
                unsigned itemRate = 0;
                FUN_140873220(pItem, "id", id);
                FUN_140873220(pItem, "rate", itemRate);
                m_itemRates.SetAt(id, itemRate);
            }
        }
    }
}

// @0x1403fecc0
void QuestAdditionalRewardContext::Write(COutputStream& out)
{
    for (size_t i = 0; i < _countof(m_rates); i++)
        out.vfunc_o10_3(m_rates[i]);
    unsigned count = (unsigned)m_itemRates.GetCount();
    out.vfunc_o10_3(count);
    for (POSITION pos = m_itemRates.GetStartPosition(); pos != NULL; m_itemRates.GetNext(pos)) {
        out.vfunc_o10_3(m_itemRates.GetKeyAt(pos));
        out.vfunc_o10_3(m_itemRates.GetValueAt(pos));
    }
}

// @0x1403fedf0
void QuestAdditionalRewardContext::Read(CInPacket& packet)
{
    for (size_t i = 0; i < _countof(m_rates); i++)
        m_rates[i] = packet.vfunc_o8_3();
    unsigned count = packet.vfunc_o8_3();
    for (size_t i = 0; i < count; i++) {
        unsigned id = packet.vfunc_o8_3();
        unsigned itemRate = packet.vfunc_o8_3();
        m_itemRates.SetAt(id, itemRate);
    }
}

// @0x1403fef10
void GalleryContext::Write(COutputStream& out)
{
    out.vfunc_o10_2(m_cards.GetCount());
    for (size_t i = 0; i < m_cards.GetCount(); i++)
        out.vfunc_o10_3(m_cards[i]->m_id);
    out.vfunc_o10_2(m_items.GetCount());
    for (size_t i = 0; i < m_items.GetCount(); i++)
        m_items[i].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    out.vfunc_o10_3(m_60);
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_4(m_endTime);
}

// @0x1403ff0a0
void GalleryContext::Read(CInPacket& packet)
{
    int cardCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < cardCount; i++) {
        MS2Ptr<Card> spCard(new Card);
        spCard->m_id = packet.vfunc_o8_3();
        m_cards.Add(spCard);
    }
    int itemCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < itemCount; i++) {
        ItemEntity item;
        item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
        m_items.Add(item);
    }
    m_60 = packet.vfunc_o8_3();
    m_strTitle = packet.vfunc_o8_8();
    m_endTime = packet.vfunc_o8_4();
}

// @0x1403ff360
BOOL GalleryContext::HasCard(int id)
{
    for (size_t i = 0; i < m_cards.GetCount(); i++) {
        if (m_cards[i]->m_id == id)
            return TRUE;
    }
    return FALSE;
}

// @0x1403ff3e0
MS2Ptr<GalleryContext::Card> GalleryContext::GetCard(int index)
{
    int count = (int)m_cards.GetCount();
    if (index < 0 || index >= count) {
        MS2_ASSERT_AT(0x228, 0);
        return 0;
    }
    return m_cards[index];
}

// @0x1403ff4a0
void MentoringContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_18);
    out.vfunc_o10_4(m_20);
    out.vfunc_o10_4(m_28);
    out.vfunc_o10_3(m_ids.GetCount());
    for (size_t i = 0; i < m_ids.GetCount(); i++)
        out.vfunc_o10_3(m_ids[i]);
}

// @0x1403ff5a0
void MentoringContext::Read(CInPacket& packet)
{
    m_18 = packet.vfunc_o8_3();
    m_20 = packet.vfunc_o8_4();
    m_28 = packet.vfunc_o8_4();
    unsigned count = packet.vfunc_o8_3();
    for (unsigned i = 0; i < count; i++)
        m_ids.Add(packet.vfunc_o8_3());
}

// @0x1403ff6c0
DungeonBuffEventCtx::DungeonBuffEventCtx() : m_dungeonID(0), m_isBeginner(false)
{
}

// The GUID list is parsed as unsigned 64-bit decimals (0x1404082e0).
template <> inline unsigned __int64 XmlConvert<unsigned __int64>(const CString& str)
{
    return _strtoui64(str, NULL, 10);
}

// @0x1403ff720
bool DungeonBuffEventCtx::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "dungeonID", m_dungeonID);
    XmlTokenList(pElem, "addifectGUIDs", m_addEffectGUIDs);
    FUN_1408730a0(pElem, "isBeginner", m_isBeginner);
    if (m_addEffectGUIDs.empty())
        return false;
    return true;
}

// @0x1403ff7b0
bool SnowmanContext::Snowman::ReachedGoal(int value)
{
    return value >= m_18;
}

// @0x1403ff7f0
bool SnowmanContext::Snowman::BelowLimit(int value)
{
    return value < m_1c;
}

// @0x1403ff830
bool SnowmanContext::Snowman::ReachedBonus(int value)
{
    return value >= m_20;
}

// @0x1403ff870
bool SnowmanContext::Snowman::CanProceed(int goalValue, int limitValue)
{
    bool bReached = ReachedGoal(goalValue);
    if (bReached)
        return false;
    bool bOver = !BelowLimit(limitValue) ? true : false;
    if (bOver)
        return false;
    return true;
}

// @0x1403ff8f0
void SnowmanContext::Write(COutputStream& out)
{
    out.vfunc_o10_3(m_eventId);
    out.vfunc_o10_8(m_strTitle);
    out.vfunc_o10_2(m_snowmen.GetCount());
    for (size_t i = 0; i < m_snowmen.GetCount(); i++) {
        MS2Ptr<Snowman>& spSnowman = m_snowmen[i];
        if (!spSnowman) {
            MS2_ASSERT_AT(0x282, "snowman" && 0);
            return;
        }
        out.vfunc_o10_3(spSnowman->m_18);
        out.vfunc_o10_3(spSnowman->m_1c);
        out.vfunc_o10_3(spSnowman->m_20);
        ATL::CAtlArray<ItemEntity>& items = spSnowman->m_items;
        out.vfunc_o10_2(items.GetCount());
        for (size_t j = 0; j < items.GetCount(); j++)
            items[j].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
        ATL::CAtlArray<ItemEntity>& bonusItems = spSnowman->m_bonusItems;
        out.vfunc_o10_2(bonusItems.GetCount());
        for (size_t j = 0; j < bonusItems.GetCount(); j++)
            bonusItems[j].FUN_14026b030(reinterpret_cast<Unk_GiftOutput&>(out));
    }
    out.vfunc_o10_4(m_endTime);
}

// @0x1403ffc00
void SnowmanContext::Read(CInPacket& packet)
{
    m_eventId = packet.vfunc_o8_3();
    m_strTitle = packet.vfunc_o8_8();
    int snowmanCount = (unsigned short)packet.vfunc_o8_2();
    for (int i = 0; i < snowmanCount; i++) {
        MS2Ptr<Snowman> spSnowman(new Snowman);
        spSnowman->m_18 = packet.vfunc_o8_3();
        spSnowman->m_1c = packet.vfunc_o8_3();
        spSnowman->m_20 = packet.vfunc_o8_3();
        int itemCount = (unsigned short)packet.vfunc_o8_2();
        for (int j = 0; j < itemCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            spSnowman->m_items.Add(item);
        }
        int bonusCount = (unsigned short)packet.vfunc_o8_2();
        for (int j = 0; j < bonusCount; j++) {
            ItemEntity item;
            item.FUN_14026b100(reinterpret_cast<Unk_GiftInput&>(static_cast<CInputStream&>(packet)));
            spSnowman->m_bonusItems.Add(item);
        }
        m_snowmen.Add(spSnowman);
    }
    m_endTime = packet.vfunc_o8_4();
}

// @0x140400000
MS2Ptr<SnowmanContext::Snowman> SnowmanContext::GetSnowman(int index)
{
    int count = (int)m_snowmen.GetCount();
    if (index < 0 || index >= count) {
        MS2_ASSERT_AT(0x2cc, 0);
        return 0;
    }
    return m_snowmen[index];
}
