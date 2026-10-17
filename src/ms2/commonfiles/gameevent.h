// Minimal GameEvent base (RTTI .?AVGameEvent@@; name assumed), recovered from the subclasses in gameeventlobbymap.cpp.
// NOT a full recovery: the base class unit (0x1402e1b80.., 0x1403bb510..) is not done yet. Only what the derived classes
// need is declared: vftable slots 0..9 (base vftable 0x142d22178), the id at +0x18, the CString at +0x68, size 0xd0.
// Members of the base are opaque padding until the base unit is recovered.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include <set>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/mstime.h"
class Unk_140165cf0;
class CInPacket;
class CInputStream;
class COutputStream;

// Output / input stream stand-ins: only the virtual slot used by GameEvent subclasses (slot 3) is exact.
class Unk_GEOut {
public:
    virtual void vfunc_0();
    virtual void WriteByte(unsigned char value);   // slot 1
    virtual void vfunc_2();
    virtual void WriteInt(int value);   // slot 3
};
class Unk_GEReader {
public:
    virtual void vfunc_0();
    virtual unsigned char ReadByte();   // slot 1
    virtual void vfunc_2();
    virtual int ReadInt();              // slot 3
};
// The input packet: the reader object is embedded at +8.
struct Unk_GEIn {
    char m_pad[8];
    Unk_GEReader reader;    // embedded at +8
};
// clang-cl devirtualizes a call on an embedded member object into a direct call to an undefined function; go through
// an opaque pointer there (the byte-matched cl build keeps the member call).
#ifdef __clang__
#define MS2_GE_READ_INT(in) (reinterpret_cast<Unk_GEReader*>(reinterpret_cast<char*>(in) + 8)->ReadInt())
#else
#define MS2_GE_READ_INT(in) ((in)->reader.ReadInt())
#endif
struct Unk_GE16 { char b[16]; };

class GameEvent : public CPtred {
public:
    GameEvent();                                // 0x1402e1b80
    virtual ~GameEvent();                       // slot 0 (body 0x1402e4cf0)
    virtual CStringW vfunc_1();                 // event name (0x1401f8450: GameEventSale inherits it)
    virtual void vfunc_2() = 0;                 // parse the CString at +0x68
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1402e2190: out->WriteInt(m_id)
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1402e21d0
    virtual void vfunc_5() = 0;                 // event start
    virtual void vfunc_6() = 0;                 // event end
    virtual void vfunc_7(void* other);          // 0x1402e2220
    virtual void vfunc_8();                     // 0x1402e5510 (empty)
    virtual bool vfunc_9(void* other);          // 0x1402e2580
    void FUN_1402e3480(int kind);               // sets the flag `kind` in the set at +0x8c

protected:
    MS2_LAYOUT_FRIEND;
    int m_id;               // +0x18
    char m_pad_1c[4];
    char m_pad_20[8];
    Unk_GE16 m_28;          // +0x28 (written/read as a date by the subclasses)
    Unk_GE16 m_38;          // +0x38
    char m_pad_48[0x20];
    CStringW m_68;          // +0x68
    CStringW m_70;          // +0x70
    CStringW m_78;          // +0x78
    char m_pad_80[0x50];
};
MS2_CHECK_SIZE(GameEvent, 0xd0);
MS2_CHECK_OFFSET(GameEvent, m_id, 0x18);
MS2_CHECK_OFFSET(GameEvent, m_38, 0x38);
MS2_CHECK_OFFSET(GameEvent, m_68, 0x68);
MS2_CHECK_OFFSET(GameEvent, m_28, 0x28);
MS2_CHECK_OFFSET(GameEvent, m_78, 0x78);

// ---- GameEvent subclasses and the CPtred-derived *Context element types of commonfiles/gameevent.cpp (w116) ----------
// Generated from the exe RTTI: vftable slot lists (overridden slots declared, VAs in the comments) and the sizes of the
// sized deletes in the ??_G deleting dtors (unit_1403e9650, the COMDAT tail of gameevent.cpp). The dtors are implicit
// (COMDATs 0x1403e4a90..0x1403e8230, unit ?\gameeventadventurelevelbonusexprate.cpp); the ctors are out of line in
// gameevent.cpp. Members are NOT recovered yet: opaque padding (the exe dtors destroy MS2Ptr<*Context>, CAtlArray<>,
// std::set<> and ItemEntity members at the padded offsets; see work/w116/dtors.txt for the per-class callee lists).
// Members recovered by gameeventcontext.cpp (stream Write 0x140404440 / Read 0x140404920; names from the
// GameEventBurningLevelup::vfunc_2 XML loader 0x1403d1ad0).
class BurningLevelupContext : public CPtred {
public:
    BurningLevelupContext();                        // 0x1403e39b0 (gameevent.cpp)
    void Write(COutputStream& out);                 // 0x140404440
    void Read(CInPacket& packet);                   // 0x140404920
    bool IsBurningLevel(unsigned short level);      // 0x140405130
    int GetBonusLevel(unsigned short level);        // 0x140405190
    bool HasTarget(int id);                         // 0x140405230
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    __int64 m_endTime;                              // +0x20
    std::set<int> m_28;                             // +0x28 the comma list of the event's m_78
    unsigned short m_beginLevel;                    // +0x38 "beginLevel"
    unsigned short m_endLevel;                      // +0x3a "endLevel"
    unsigned m_burningBonus;                        // +0x3c "burningBonus"
    int m_additionalEffectId;                       // +0x40 "additionalEffectId"
    int m_pad_44;
    CStringW m_setCharacterPopupStringKey;          // +0x48 "setCharacterPopupStringKey"
    CStringW m_setCharacterPopupBottomStringKey;    // +0x50 "setCharacterPopupBottomStringKey"
    CStringW m_descPopupStringKey;                  // +0x58 "descPopupStringKey"
    CStringW m_rewardUiTitleStringKey;              // +0x60 "rewardUiTitleStringKey"
    short m_equipNametagSymbolId;                   // +0x68 "equipNametagSymbolID"
    short m_pad_6a[3];
    std::vector<ItemEntity> m_rewardItems;          // +0x70 the items of the m_70 xml
    int m_tutorialEndFieldId;                       // +0x88 jumpingOption "tutorialEndFieldId"
    unsigned short m_8c;                            // +0x8c set from the jumping item
    short m_pad_8e;
    MS2Ptr<ItemEntity> m_spJumpingItem;             // +0x90 the jumpingOption item (a LevelPotion)
    CStringW m_jumpingItemDescPopupStringKey;       // +0xa0 "jumpingItemDescPopupStringKey"
    CStringW m_jumpingItemNotifyStringKey;          // +0xa8 "jumpingItemNotifyStringKey"
    CStringW m_jumpingCompleteStringKey;            // +0xb0 "jumpingCompleteStringKey"
};  // vftable 0x142d41600, ??_G 0x1403e9850, dtor 0x1403e58e0
MS2_CHECK_SIZE(BurningLevelupContext, 0xb8);
// Members recovered by gameeventcontext.cpp (LoadReward 0x140400c00 / LoadDance 0x140401070, stream Write
// 0x1404015c0 / Read 0x140401a80).
class CoupleDanceContext : public CPtred {
public:
    struct Step {
        CStringW m_action;                          // +0x00 <action anim>
        CStringW m_message;                         // +0x08 <message value>
    };
    bool LoadReward(Unk_140165cf0* pElem);          // 0x140400c00
    bool LoadDance(Unk_140165cf0* pElem);           // 0x140401070
    void Write(COutputStream& out);                 // 0x1404015c0
    void Read(CInPacket& packet);                   // 0x140401a80
    const Step& GetStep(int index) const;           // 0x140402080
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    __int64 m_beginTime;                            // +0x20
    __int64 m_endTime;                              // +0x28
    unsigned m_goodEndCount;                        // +0x30 goodEndBonus count (a short on the wire)
    unsigned m_maxRound;                            // +0x34 play maxRound (a byte on the wire)
    std::vector<std::vector<ItemEntity> > m_dailyItems;  // +0x38 daily items, by order
    std::vector<ItemEntity> m_goodEndItems;         // +0x50
    std::vector<Step> m_steps;                      // +0x68 one per CoupleDanceStepName
    std::vector<CStringW> m_dances;                 // +0x80 dances anim
    unsigned m_fieldId;                             // +0x98 start fieldID
    int m_pad_9c;
};  // vftable 0x142d415a0, ??_G 0x1403e9a10, dtor 0x1403e5b40
MS2_CHECK_SIZE(CoupleDanceContext, 0xa0);
class EnchantRateEventContext : public CPtred {
    char m_pad_18[0x10];
};  // vftable 0x142d41508, ??_G 0x1403e9a50, dtor 0x1403e5ba0
MS2_CHECK_SIZE(EnchantRateEventContext, 0x28);
class EventQuestContext : public CPtred {
    char m_pad_18[0x20];
};  // vftable 0x142d414c8, ??_G 0x1403e9a90, dtor 0x1403e5bc0
MS2_CHECK_SIZE(EventQuestContext, 0x38);
// Members recovered by gameeventcontext.cpp (stream Write 0x1403fef10 / Read 0x1403ff0a0); the Card ctor is in
// gameevent.cpp.
class GalleryContext : public CPtred {
public:
    struct Card : public CPtred {
        Card();
        int m_id;                       // +0x18
        int m_pad_1c;
    };  // vftable 0x142d41528, ??_G 0x1403e99d0, dtor 0x1403e5b00
    void Write(COutputStream& out);                 // 0x1403fef10
    void Read(CInPacket& packet);                   // 0x1403ff0a0
    BOOL HasCard(int id);                           // 0x1403ff360
    MS2Ptr<Card> GetCard(int index);                // 0x1403ff3e0
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    ATL::CAtlArray<MS2Ptr<Card> > m_cards;          // +0x20
    ATL::CAtlArray<ItemEntity> m_items;             // +0x40
    int m_60;
    __int64 m_endTime;                              // +0x68
    CStringW m_strTitle;                            // +0x70
};  // vftable 0x142d41538, ??_G 0x1403e9ad0, dtor 0x1403e5bf0
MS2_CHECK_SIZE(GalleryContext, 0x78);
class GameEventAdventureLevelBonusExpRate : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d1750
    virtual void vfunc_2();                     // 0x1403d1810
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d1840
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d1890
    virtual void vfunc_5();                     // 0x1403d18f0
    virtual void vfunc_6();                     // 0x1403d1930
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40ef8, ??_G 0x1403e9b10, dtor 0x1403e5c40
MS2_CHECK_SIZE(GameEventAdventureLevelBonusExpRate, 0xd8);
class GameEventArcadeOpen : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d53b0
    virtual void vfunc_2();                     // 0x1403d5490
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d56e0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d5740
    virtual void vfunc_5();                     // 0x1403d57f0
    virtual void vfunc_6();                     // 0x1403d5870
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d41268, ??_G 0x1403e9b50, dtor 0x1403e5c60
MS2_CHECK_SIZE(GameEventArcadeOpen, 0xe8);
class GameEventBattlePetSpawn : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cc720
    virtual void vfunc_2();                     // 0x1403cc7f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cc9c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cca30
    virtual void vfunc_5();                     // 0x1403cc840
    virtual void vfunc_6();                     // 0x1403cc900
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d409d0, ??_G 0x1403e9b90, dtor 0x1403e5c90
MS2_CHECK_SIZE(GameEventBattlePetSpawn, 0xe0);
class GameEventBingoEvent : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d5960
    virtual void vfunc_2();                     // 0x1403d5a20
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d5d10
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d5d80
    virtual void vfunc_5();                     // 0x1403d5e30
    virtual void vfunc_6();                     // 0x1403d5ea0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d412c0, ??_G 0x1403e9bd0, dtor 0x1403e5cc0
MS2_CHECK_SIZE(GameEventBingoEvent, 0xe0);
class GameEventBlackMarketFeeDiscount : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403be690
    virtual void vfunc_2();                     // 0x1403be750
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403be780
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403be7f0
    virtual void vfunc_5();                     // 0x1403be880
    virtual void vfunc_6();                     // 0x1403be990
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f530, ??_G 0x1403e9c10, dtor 0x1403e5cf0
MS2_CHECK_SIZE(GameEventBlackMarketFeeDiscount, 0xd8);
class GameEventBlueMarble : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c22c0
    virtual void vfunc_2();                     // 0x1403c23a0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c25b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c27c0
    virtual void vfunc_5();                     // 0x1403c2ab0
    virtual void vfunc_6();                     // 0x1403c2b20
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3fb08, ??_G 0x1403e9c50, dtor 0x1403e5d10
MS2_CHECK_SIZE(GameEventBlueMarble, 0xe0);
class GameEventBurningLevelup : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d19c0
    virtual void vfunc_2();                     // 0x1403d1ad0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d27b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d2800
    virtual void vfunc_5();                     // 0x1403d2850
    virtual void vfunc_6();                     // 0x1403d28c0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40f50, ??_G 0x1403e9c90, dtor 0x1403e5d40
MS2_CHECK_SIZE(GameEventBurningLevelup, 0xe0);
class GameEventChatFiltering : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cc310
    virtual void vfunc_2();                     // 0x1403cc3f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cc430
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cc4e0
    virtual void vfunc_5();                     // 0x1403cc5b0
    virtual void vfunc_6();                     // 0x1403cc640
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d40978, ??_G 0x1403e9cd0, dtor 0x1403e5d70
MS2_CHECK_SIZE(GameEventChatFiltering, 0xf0);
class GameEventCollectItemGroup : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d4850
    virtual void vfunc_2();                     // 0x1403d4930
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d4c40
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d4ca0
    virtual void vfunc_5();                     // 0x1403d4d50
    virtual void vfunc_6();                     // 0x1403d4dc0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d41160, ??_G 0x1403e9d10, dtor 0x1403e5da0
MS2_CHECK_SIZE(GameEventCollectItemGroup, 0xe0);
class GameEventConstructShowItem : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c8ba0
    virtual void vfunc_2();                     // 0x1403c8cb0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c8d80
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8ea0
    virtual void vfunc_5();                     // 0x1403c9050
    virtual void vfunc_6();                     // 0x1403c9160
private:
    char m_pad_d0[0x40];
};  // vftable 0x142d40450, ??_G 0x1403e9d50, dtor 0x1403e5dd0
MS2_CHECK_SIZE(GameEventConstructShowItem, 0x110);
class GameEventCoupleDance : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d3070
    virtual void vfunc_2();                     // 0x1403d3170
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d34d0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d3520
    virtual void vfunc_5();                     // 0x1403d3400
    virtual void vfunc_6();                     // 0x1403d3470
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d41000, ??_G 0x1403e9d90, dtor 0x1403e5e10
MS2_CHECK_SIZE(GameEventCoupleDance, 0xe0);
class GameEventCustomTriggerString : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d00f0
    virtual void vfunc_2();                     // 0x1403d01c0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d0360
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d03a0
    virtual void vfunc_5();                     // 0x1403d0340
    virtual void vfunc_6();                     // 0x1403d0350
private:
    char m_pad_d0[0x30];
};  // vftable 0x142d40d40, ??_G 0x1403e9dd0, dtor 0x1403e5e40
MS2_CHECK_SIZE(GameEventCustomTriggerString, 0x100);
class GameEventDeleteUrlCache : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c9b80
    virtual void vfunc_2();                     // 0x1403c9c50
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c9c80
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c9cd0
    virtual void vfunc_5();                     // 0x1403c9d30
    virtual void vfunc_6();                     // 0x1403c9d60
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d405b0, ??_G 0x1403e9e10, dtor 0x1403e5e70
MS2_CHECK_SIZE(GameEventDeleteUrlCache, 0xd8);
class GameEventDungeonBonusReward : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bd000
    virtual void vfunc_2();                     // 0x1403bd120
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bd230
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bd270
    virtual void vfunc_5();                     // 0x1403bd2c0
    virtual void vfunc_6();                     // 0x1403bd330
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f378, ??_G 0x1403e9e50, dtor 0x1403e5e90
MS2_CHECK_SIZE(GameEventDungeonBonusReward, 0xe0);
class GameEventDungeonEnterTimeLimit : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c2fc0
    virtual void vfunc_2();                     // 0x1403c3080
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c3130
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c3170
    virtual void vfunc_5();                     // 0x1403c30b0
    virtual void vfunc_6();                     // 0x1403c30f0
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d3fc10, ??_G 0x1403e9e90, dtor 0x1403e5ec0
MS2_CHECK_SIZE(GameEventDungeonEnterTimeLimit, 0xe8);
class GameEventDungeonExtraReward : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c09f0
    virtual void vfunc_2();                     // 0x1403c0ae0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c0ca0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c0ce0
    virtual void vfunc_5();                     // 0x1403c0d30
    virtual void vfunc_6();                     // 0x1403c0ea0
private:
    char m_pad_d0[0x48];
};  // vftable 0x142d3f8f8, ??_G 0x1403e9ed0, dtor 0x1403e5ef0
MS2_CHECK_SIZE(GameEventDungeonExtraReward, 0x118);
class GameEventDungeonOpenPeriod : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c02f0
    virtual void vfunc_2();                     // 0x1403c03b0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c03f0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c0460
    virtual void vfunc_5();                     // 0x1403c04e0
    virtual void vfunc_6();                     // 0x1403c0600
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f848, ??_G 0x1403e9f10, dtor 0x1403e5f20
MS2_CHECK_SIZE(GameEventDungeonOpenPeriod, 0xd8);
class GameEventDungeonRoomShutdown : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bffd0
    virtual void vfunc_2();                     // 0x1403c0090
    virtual void vfunc_5();                     // 0x1403c01a0
    virtual void vfunc_6();                     // 0x1403c0210
    virtual bool vfunc_9(void* other);          // 0x1403c0270
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f7f0, ??_G 0x1403e9f50, dtor 0x1403e5f50
MS2_CHECK_SIZE(GameEventDungeonRoomShutdown, 0xe0);
class GameEventEnchantRate : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c6170
    virtual void vfunc_2();                     // 0x1403c6230
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c6410
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c64a0
    virtual void vfunc_5();                     // 0x1403c6320
    virtual void vfunc_6();                     // 0x1403c6390
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3ff28, ??_G 0x1403e9f90, dtor 0x1403e5f80
MS2_CHECK_SIZE(GameEventEnchantRate, 0xe0);
class GameEventEpicRestart : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c3c00
    virtual void vfunc_2();                     // 0x1403c3cf0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c3e60
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c3f30
    virtual void vfunc_5();                     // 0x1403c3d80
    virtual void vfunc_6();                     // 0x1403c3e30
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d3fcc0, ??_G 0x1403e9fd0, dtor 0x1403e5fb0
MS2_CHECK_SIZE(GameEventEpicRestart, 0xe8);
class GameEventEventFieldPopup : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bf500
    virtual void vfunc_2();                     // 0x1403bf5b0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bf5e0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bf630
    virtual void vfunc_5();                     // 0x1403bf690
    virtual void vfunc_6();                     // 0x1403bf6c0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f690, ??_G 0x1403ea010, dtor 0x1403e6010
MS2_CHECK_SIZE(GameEventEventFieldPopup, 0xd8);
class GameEventExchangeScrollSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d3b40
    virtual void vfunc_2();                     // 0x1403d3c00
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d3d80
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d3e60
    virtual void vfunc_5();                     // 0x1403d3c60
    virtual void vfunc_6();                     // 0x1403d3cf0
private:
    char m_pad_d0[0x28];
};  // vftable 0x142d410b0, ??_G 0x1403ea050, dtor 0x1403e6030
MS2_CHECK_SIZE(GameEventExchangeScrollSale, 0xf8);
class GameEventFestival : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d2990
    virtual void vfunc_2();                     // 0x1403d2a90
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d2cd0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d2d40
    virtual void vfunc_5();                     // 0x1403d2e00
    virtual void vfunc_6();                     // 0x1403d2e80
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40fa8, ??_G 0x1403ea090, dtor 0x1403e6060
MS2_CHECK_SIZE(GameEventFestival, 0xe0);
class GameEventFieldEffect : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d35d0
    virtual void vfunc_2();                     // 0x1403d36d0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d39b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d3a20
    virtual void vfunc_5();                     // 0x1403d37f0
    virtual void vfunc_6();                     // 0x1403d3920
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d41058, ??_G 0x1403ea0d0, dtor 0x1403e6090
MS2_CHECK_SIZE(GameEventFieldEffect, 0xe0);
class GameEventFieldShutdown : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c06f0
    virtual void vfunc_2();                     // 0x1403c07b0
    virtual void vfunc_5();                     // 0x1403c08d0
    virtual void vfunc_6();                     // 0x1403c0940
    virtual bool vfunc_9(void* other);          // 0x1403c0970
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f8a0, ??_G 0x1403ea110, dtor 0x1403e60c0
MS2_CHECK_SIZE(GameEventFieldShutdown, 0xe0);
class GameEventFindDungeonHelperBonus : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cbf30
    virtual void vfunc_2();                     // 0x1403cbff0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cc0a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cc0e0
    virtual void vfunc_5();                     // 0x1403cc020
    virtual void vfunc_6();                     // 0x1403cc060
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d408c8, ??_G 0x1403ea150, dtor 0x1403e60f0
MS2_CHECK_SIZE(GameEventFindDungeonHelperBonus, 0xd8);
class GameEventFinishPayback : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d5f70
    virtual void vfunc_2();                     // 0x1403d6020
    virtual void vfunc_5();                     // 0x1403d6030
    virtual void vfunc_6();                     // 0x1403d6040
};  // vftable 0x142d41318, ??_G 0x1403ea190, dtor 0x1403e6110
MS2_CHECK_SIZE(GameEventFinishPayback, 0xd0);
class GameEventFreeAirTaxi : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bd400
    virtual void vfunc_2();                     // 0x1403bd4b0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bd4c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bd4f0
    virtual void vfunc_5();                     // 0x1403bd520
    virtual void vfunc_6();                     // 0x1403bd560
};  // vftable 0x142d3f3d0, ??_G 0x1403ea1d0, dtor 0x1403e6130
MS2_CHECK_SIZE(GameEventFreeAirTaxi, 0xd0);
class GameEventGallery : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403ccb50
    virtual void vfunc_2();                     // 0x1403ccc30
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ccfa0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cd010
    virtual void vfunc_5();                     // 0x1403cced0
    virtual void vfunc_6();                     // 0x1403ccf40
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40a28, ??_G 0x1403ea210, dtor 0x1403e6150
MS2_CHECK_SIZE(GameEventGallery, 0xe0);
class GameEventGameMenuPopup : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bf240
    virtual void vfunc_2();                     // 0x1403bf300
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bf350
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bf3c0
    virtual void vfunc_5();                     // 0x1403bf480
    virtual void vfunc_6();                     // 0x1403bf490
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f638, ??_G 0x1403ea250, dtor 0x1403e6180
MS2_CHECK_SIZE(GameEventGameMenuPopup, 0xe0);
class GameEventGuildChampionship : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c6900
    virtual void vfunc_2();                     // 0x1403c69c0
    virtual void vfunc_5();                     // 0x1403c6a10
    virtual void vfunc_6();                     // 0x1403c6a50
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3ffd8, ??_G 0x1403ea290, dtor 0x1403e61b0
MS2_CHECK_SIZE(GameEventGuildChampionship, 0xd8);
class GameEventGuildCoin : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c7910
    virtual void vfunc_2();                     // 0x1403c79d0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c7a70
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c7ac0
    virtual void vfunc_5();                     // 0x1403c7a00
    virtual void vfunc_6();                     // 0x1403c7a40
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d401e8, ??_G 0x1403ea2d0, dtor 0x1403e61d0
MS2_CHECK_SIZE(GameEventGuildCoin, 0xd8);
class GameEventGuildEventFund : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d6b40
    virtual void vfunc_2();                     // 0x1403d6c00
    virtual void vfunc_5();                     // 0x1403d6c10
    virtual void vfunc_6();                     // 0x1403d6c20
};  // vftable 0x142d41420, ??_G 0x1403ea310, dtor 0x1403e61f0
MS2_CHECK_SIZE(GameEventGuildEventFund, 0xd0);
class GameEventGuildExp : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c73c0
    virtual void vfunc_2();                     // 0x1403c7480
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c7590
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c75e0
    virtual void vfunc_5();                     // 0x1403c74b0
    virtual void vfunc_6();                     // 0x1403c7520
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40138, ??_G 0x1403ea350, dtor 0x1403e6210
MS2_CHECK_SIZE(GameEventGuildExp, 0xd8);
class GameEventGuildFund : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c76a0
    virtual void vfunc_2();                     // 0x1403c7760
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c7800
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c7850
    virtual void vfunc_5();                     // 0x1403c7790
    virtual void vfunc_6();                     // 0x1403c77d0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40190, ??_G 0x1403ea390, dtor 0x1403e6230
MS2_CHECK_SIZE(GameEventGuildFund, 0xd8);
class GameEventGuildPersonalSkillSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c7150
    virtual void vfunc_2();                     // 0x1403c7210
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c72b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c7300
    virtual void vfunc_5();                     // 0x1403c7240
    virtual void vfunc_6();                     // 0x1403c7280
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d400e0, ??_G 0x1403ea3d0, dtor 0x1403e6250
MS2_CHECK_SIZE(GameEventGuildPersonalSkillSale, 0xd8);
class GameEventGuildSkillSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c6ee0
    virtual void vfunc_2();                     // 0x1403c6fa0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c7040
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c7090
    virtual void vfunc_5();                     // 0x1403c6fd0
    virtual void vfunc_6();                     // 0x1403c7010
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40088, ??_G 0x1403ea410, dtor 0x1403e6270
MS2_CHECK_SIZE(GameEventGuildSkillSale, 0xd8);
class GameEventGuildVsGameOpen : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cc190
    virtual void vfunc_2();                     // 0x1403cc240
    virtual void vfunc_5();                     // 0x1403cc250
    virtual void vfunc_6();                     // 0x1403cc280
};  // vftable 0x142d40920, ??_G 0x1403ea450, dtor 0x1403e6290
MS2_CHECK_SIZE(GameEventGuildVsGameOpen, 0xd0);
class GameEventIgnoreConstructionLockEvent : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cd640
    virtual void vfunc_2();                     // 0x1403cd720
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cd760
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cd810
    virtual void vfunc_5();                     // 0x1403cd8c0
    virtual void vfunc_6();                     // 0x1403cd940
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d40a80, ??_G 0x1403ea490, dtor 0x1403e62b0
MS2_CHECK_SIZE(GameEventIgnoreConstructionLockEvent, 0xf0);
class GameEventItemBox : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403ca740
    virtual void vfunc_2();                     // 0x1403ca810
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ca960
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403caa20
    virtual void vfunc_5();                     // 0x1403caad0
    virtual void vfunc_6();                     // 0x1403cab70
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d40710, ??_G 0x1403ea4d0, dtor 0x1403e62e0
MS2_CHECK_SIZE(GameEventItemBox, 0xe8);
class GameEventItemBuff : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bccb0
    virtual void vfunc_2();                     // 0x1403bcd70
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bce90
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bcee0
    virtual void vfunc_5();                     // 0x1403bcf40
    virtual void vfunc_6();                     // 0x1403bcf70
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f320, ??_G 0x1403ea510, dtor 0x1403e6310
MS2_CHECK_SIZE(GameEventItemBuff, 0xd8);
class GameEventItemTradeRestriction : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d3fb0
    virtual void vfunc_2();                     // 0x1403d40a0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d44c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d4620
    virtual void vfunc_5();                     // 0x1403d4120
    virtual void vfunc_6();                     // 0x1403d4480
private:
    char m_pad_d0[0x48];
};  // vftable 0x142d41108, ??_G 0x1403ea550, dtor 0x1403e6330
MS2_CHECK_SIZE(GameEventItemTradeRestriction, 0x118);
class GameEventLevelUpPackage : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c4150
    virtual void vfunc_2();                     // 0x1403c4210
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c42e0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c4350
    virtual void vfunc_5();                     // 0x1403c4260
    virtual void vfunc_6();                     // 0x1403c42b0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3fd18, ??_G 0x1403ea590, dtor 0x1403e6370
MS2_CHECK_SIZE(GameEventLevelUpPackage, 0xe0);
class GameEventLongTermAttendGift : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d60b0
    virtual void vfunc_2();                     // 0x1403d6190
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d6860
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d68d0
    virtual void vfunc_5();                     // 0x1403d6780
    virtual void vfunc_6();                     // 0x1403d67f0
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d41370, ??_G 0x1403ea5d0, dtor 0x1403e63a0
MS2_CHECK_SIZE(GameEventLongTermAttendGift, 0xe8);
class GameEventMassiveConstructionEvent : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c5ba0
    virtual void vfunc_2();                     // 0x1403c5cb0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c5d30
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c5e80
    virtual void vfunc_5();                     // 0x1403c5fe0
    virtual void vfunc_6();                     // 0x1403c60e0
private:
    char m_pad_d0[0x48];
};  // vftable 0x142d3fed0, ??_G 0x1403ea610, dtor 0x1403e63d0
MS2_CHECK_SIZE(GameEventMassiveConstructionEvent, 0x118);
class GameEventMasteryReduce : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c8460
    virtual void vfunc_2();                     // 0x1403c8510
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c85b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8600
    virtual void vfunc_5();                     // 0x1403c8540
    virtual void vfunc_6();                     // 0x1403c8580
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40348, ??_G 0x1403ea650, dtor 0x1403e6410
MS2_CHECK_SIZE(GameEventMasteryReduce, 0xd8);
class GameEventMasteryReward : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c7b80
    virtual void vfunc_2();                     // 0x1403c7c50
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c7d50
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c7dc0
    virtual void vfunc_5();                     // 0x1403c7ca0
    virtual void vfunc_6();                     // 0x1403c7d10
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40240, ??_G 0x1403ea690, dtor 0x1403e6430
MS2_CHECK_SIZE(GameEventMasteryReward, 0xe0);
class GameEventMeratMarketNotice : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c2d60
    virtual void vfunc_2();                     // 0x1403c2e30
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c2e70
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c2ec0
    virtual void vfunc_5();                     // 0x1403c2f40
    virtual void vfunc_6();                     // 0x1403c2f50
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3fbb8, ??_G 0x1403ea6d0, dtor 0x1403e6460
MS2_CHECK_SIZE(GameEventMeratMarketNotice, 0xd8);
class GameEventMeratMarketOpenTab : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c7ee0
    virtual void vfunc_2();                     // 0x1403c7fa0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c8010
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8060
    virtual void vfunc_5();                     // 0x1403c80f0
    virtual void vfunc_6();                     // 0x1403c8140
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40298, ??_G 0x1403ea710, dtor 0x1403e6490
MS2_CHECK_SIZE(GameEventMeratMarketOpenTab, 0xd8);
class GameEventMesoRevival : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bc980
    virtual void vfunc_2();                     // 0x1403bca40
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bca70
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bcac0
    virtual void vfunc_5();                     // 0x1403bcb20
    virtual void vfunc_6();                     // 0x1403bcc10
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f2c8, ??_G 0x1403ea750, dtor 0x1403e64c0
MS2_CHECK_SIZE(GameEventMesoRevival, 0xd8);
class GameEventNpcEventDrop : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c1e60
    virtual void vfunc_2();                     // 0x1403c1f30
    virtual void vfunc_5();                     // 0x1403c2190
    virtual void vfunc_6();                     // 0x1403c2220
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3fab0, ??_G 0x1403ea790, dtor 0x1403e64e0
MS2_CHECK_SIZE(GameEventNpcEventDrop, 0xe0);
class GameEventNpcShopGivePoint : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cf460
    virtual void vfunc_2();                     // 0x1403cf540
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cf6a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cf730
    virtual void vfunc_5();                     // 0x1403cf5b0
    virtual void vfunc_6();                     // 0x1403cf660
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40c38, ??_G 0x1403ea7d0, dtor 0x1403e6510
MS2_CHECK_SIZE(GameEventNpcShopGivePoint, 0xe0);
class GameEventNpcShopResetPriceSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cf880
    virtual void vfunc_2();                     // 0x1403cf950
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cf9a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cfa00
    virtual void vfunc_5();                     // 0x1403cfa90
    virtual void vfunc_6();                     // 0x1403cfad0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40c90, ??_G 0x1403ea810, dtor 0x1403e6540
MS2_CHECK_SIZE(GameEventNpcShopResetPriceSale, 0xd8);
class GameEventNpcShopTalk : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cf190
    virtual void vfunc_2();                     // 0x1403cf240
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cf310
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cf370
    virtual void vfunc_5();                     // 0x1403cf290
    virtual void vfunc_6();                     // 0x1403cf2d0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40be0, ??_G 0x1403ea850, dtor 0x1403e6560
MS2_CHECK_SIZE(GameEventNpcShopTalk, 0xd8);
class GameEventOntime : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bd600
    virtual void vfunc_2();                     // 0x1403bd6c0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bdb80
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bdbe0
    virtual void vfunc_5();                     // 0x1403bdc50
    virtual void vfunc_6();                     // 0x1403bdd00
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f428, ??_G 0x1403ea890, dtor 0x1403e6580
MS2_CHECK_SIZE(GameEventOntime, 0xe0);
class GameEventSAHotTime : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bb960
    virtual void vfunc_2();                     // 0x1403bba50
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bbc60
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bbd30
    virtual void vfunc_5();                     // 0x1403bbf30
    virtual void vfunc_6();                     // 0x1403bc0c0
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d3f168, ??_G 0x1403eab90, dtor 0x1403e6770
MS2_CHECK_SIZE(GameEventSAHotTime, 0xf0);
class GameEventPCBangSAHotTime : public GameEventSAHotTime {
public:
    virtual CStringW vfunc_1();                 // 0x1403bc180
};  // vftable 0x142d3f1c0, ??_G 0x1403ea8d0, dtor 0x1403e65b0
MS2_CHECK_SIZE(GameEventPCBangSAHotTime, 0xf0);
class GameEventPetBattleExp : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403ca260
    virtual void vfunc_2();                     // 0x1403ca320
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ca350
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403ca3a0
    virtual void vfunc_5();                     // 0x1403ca400
    virtual void vfunc_6();                     // 0x1403ca440
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40660, ??_G 0x1403ea910, dtor 0x1403e65d0
MS2_CHECK_SIZE(GameEventPetBattleExp, 0xd8);
class GameEventPetComposeSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403ca4d0
    virtual void vfunc_2();                     // 0x1403ca590
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ca5c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403ca610
    virtual void vfunc_5();                     // 0x1403ca670
    virtual void vfunc_6();                     // 0x1403ca6b0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d406b8, ??_G 0x1403ea950, dtor 0x1403e65f0
MS2_CHECK_SIZE(GameEventPetComposeSale, 0xd8);
class GameEventPetMastery : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c9df0
    virtual void vfunc_2();                     // 0x1403c9ec0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ca070
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403ca0d0
    virtual void vfunc_5();                     // 0x1403ca160
    virtual void vfunc_6();                     // 0x1403ca1c0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40608, ??_G 0x1403ea990, dtor 0x1403e6610
MS2_CHECK_SIZE(GameEventPetMastery, 0xd8);
class GameEventPremiumMarketSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bec80
    virtual void vfunc_2();                     // 0x1403bed60
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bedd0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403beee0
    virtual void vfunc_5();                     // 0x1403bf000
    virtual void vfunc_6();                     // 0x1403bf1a0
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d3f5e0, ??_G 0x1403ea9d0, dtor 0x1403e6630
MS2_CHECK_SIZE(GameEventPremiumMarketSale, 0xf0);
class GameEventPublicTest : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d15e0
    virtual void vfunc_2();                     // 0x1403d16a0
    virtual void vfunc_5();                     // 0x1403d16b0
    virtual void vfunc_6();                     // 0x1403d16e0
};  // vftable 0x142d40ea0, ??_G 0x1403eaa10, dtor 0x1403e6660
MS2_CHECK_SIZE(GameEventPublicTest, 0xd0);
class GameEventQuestAdditionalReward : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c6ae0
    virtual void vfunc_2();                     // 0x1403c6c10
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c6d50
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c6dd0
    virtual void vfunc_5();                     // 0x1403c6c90
    virtual void vfunc_6();                     // 0x1403c6d10
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d40030, ??_G 0x1403eaa50, dtor 0x1403e6680
MS2_CHECK_SIZE(GameEventQuestAdditionalReward, 0xe8);
class GameEventQuestTag : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403be010
    virtual void vfunc_2();                     // 0x1403be0e0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403be200
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403be2b0
    virtual void vfunc_5();                     // 0x1403be3f0
    virtual void vfunc_6();                     // 0x1403be5c0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f4d8, ??_G 0x1403eaa90, dtor 0x1403e66b0
MS2_CHECK_SIZE(GameEventQuestTag, 0xe0);
class GameEventRankDuel : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c6620
    virtual void vfunc_2();                     // 0x1403c66f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c67c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c6810
    virtual void vfunc_5();                     // 0x1403c6760
    virtual void vfunc_6();                     // 0x1403c6790
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3ff80, ??_G 0x1403eaad0, dtor 0x1403e66e0
MS2_CHECK_SIZE(GameEventRankDuel, 0xe0);
class GameEventReactor : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cfb70
    virtual void vfunc_2();                     // 0x1403cfc50
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cfea0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cff10
    virtual void vfunc_5();                     // 0x1403cfdd0
    virtual void vfunc_6();                     // 0x1403cfe40
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40ce8, ??_G 0x1403eab10, dtor 0x1403e6710
MS2_CHECK_SIZE(GameEventReactor, 0xe0);
class GameEventRps : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403ce820
    virtual void vfunc_2();                     // 0x1403ce900
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403ceb70
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cebe0
    virtual void vfunc_5();                     // 0x1403ceaa0
    virtual void vfunc_6();                     // 0x1403ceb10
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40b88, ??_G 0x1403eab50, dtor 0x1403e6740
MS2_CHECK_SIZE(GameEventRps, 0xe0);
class GameEventSale : public GameEvent {
public:
    virtual void vfunc_2();                     // 0x1403c1000
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c1030
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c1080
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f950, ??_G 0x1403eabd0, dtor 0x1403e67b0
MS2_CHECK_SIZE(GameEventSale, 0xd8);
class GameEventSaleAutoFishing : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bf750
    virtual void vfunc_2();                     // 0x1403bf810
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bf860
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bf8d0
    virtual void vfunc_5();                     // 0x1403bf990
    virtual void vfunc_6();                     // 0x1403bfa10
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f6e8, ??_G 0x1403eac10, dtor 0x1403e67d0
MS2_CHECK_SIZE(GameEventSaleAutoFishing, 0xe0);
class GameEventSaleAutoPlayInstrument : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bfae0
    virtual void vfunc_2();                     // 0x1403bfba0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bfbf0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bfc60
    virtual void vfunc_5();                     // 0x1403bfd20
    virtual void vfunc_6();                     // 0x1403bfda0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f740, ??_G 0x1403eac50, dtor 0x1403e6800
MS2_CHECK_SIZE(GameEventSaleAutoPlayInstrument, 0xe0);
class GameEventSaleBeautyShop : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bc280
    virtual void vfunc_2();                     // 0x1403bc340
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bc3b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bc430
    virtual void vfunc_5();                     // 0x1403bc4f0
    virtual void vfunc_6();                     // 0x1403bc560
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f218, ??_G 0x1403eac90, dtor 0x1403e6830
MS2_CHECK_SIZE(GameEventSaleBeautyShop, 0xe0);
class GameEventSaleChat : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bb570
    virtual void vfunc_2();                     // 0x1403bb650
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bb6a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bb700
    virtual void vfunc_5();                     // 0x1403bb790
    virtual void vfunc_6();                     // 0x1403bb7e0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f110, ??_G 0x1403eacd0, dtor 0x1403e6850
MS2_CHECK_SIZE(GameEventSaleChat, 0xe0);
class GameEventSaleEnchant : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bdda0
    virtual void vfunc_2();                     // 0x1403bde60
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bde90
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bdee0
    virtual void vfunc_5();                     // 0x1403bdf40
    virtual void vfunc_6();                     // 0x1403bdf80
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f480, ??_G 0x1403ead10, dtor 0x1403e6870
MS2_CHECK_SIZE(GameEventSaleEnchant, 0xd8);
class GameEventSaleGemStoneUpgrade : public GameEventSale {
public:
    virtual CStringW vfunc_1();                 // 0x1403c1440
    virtual void vfunc_5();                     // 0x1403c14f0
    virtual void vfunc_6();                     // 0x1403c1530
};  // vftable 0x142d3fa00, ??_G 0x1403ead50, dtor 0x1403e6890
MS2_CHECK_SIZE(GameEventSaleGemStoneUpgrade, 0xd8);
class GameEventSaleHousing : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c3450
    virtual void vfunc_2();                     // 0x1403c3520
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c3880
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c39d0
    virtual void vfunc_5();                     // 0x1403c3800
    virtual void vfunc_6();                     // 0x1403c3850
private:
    char m_pad_d0[0x30];
};  // vftable 0x142d3fc68, ??_G 0x1403ead90, dtor 0x1403e68b0
MS2_CHECK_SIZE(GameEventSaleHousing, 0x100);
class GameEventSaleItemsRestricted : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c9490
    virtual void vfunc_2();                     // 0x1403c9550
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c95f0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c9630
    virtual void vfunc_5();                     // 0x1403c9690
    virtual void vfunc_6();                     // 0x1403c96f0
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d40500, ??_G 0x1403eadd0, dtor 0x1403e68e0
MS2_CHECK_SIZE(GameEventSaleItemsRestricted, 0xf0);
class GameEventSaleLapenshardUpgradeRGB : public GameEventSale {
public:
    virtual CStringW vfunc_1();                 // 0x1403d69e0
    virtual void vfunc_5();                     // 0x1403d6a70
    virtual void vfunc_6();                     // 0x1403d6ab0
};  // vftable 0x142d413c8, ??_G 0x1403eae10, dtor 0x1403e6910
MS2_CHECK_SIZE(GameEventSaleLapenshardUpgradeRGB, 0xd8);
class GameEventSalePetCrystal : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d5140
    virtual void vfunc_2();                     // 0x1403d5200
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d5230
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d5280
    virtual void vfunc_5();                     // 0x1403d52e0
    virtual void vfunc_6();                     // 0x1403d5320
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d41210, ??_G 0x1403eae50, dtor 0x1403e6930
MS2_CHECK_SIZE(GameEventSalePetCrystal, 0xd8);
class GameEventSaleRemake : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c1140
    virtual void vfunc_2();                     // 0x1403c1210
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c1260
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c12c0
    virtual void vfunc_5();                     // 0x1403c1350
    virtual void vfunc_6();                     // 0x1403c13a0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f9a8, ??_G 0x1403eae90, dtor 0x1403e6950
MS2_CHECK_SIZE(GameEventSaleRemake, 0xd8);
class GameEventSaleSkillUpgrade : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c15c0
    virtual void vfunc_2();                     // 0x1403c16c0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c1770
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c1840
    virtual void vfunc_5();                     // 0x1403c1a30
    virtual void vfunc_6();                     // 0x1403c1d50
private:
    char m_pad_d0[0x20];
};  // vftable 0x142d3fa58, ??_G 0x1403eaed0, dtor 0x1403e6970
MS2_CHECK_SIZE(GameEventSaleSkillUpgrade, 0xf0);
class GameEventSaleUGCDesign : public GameEventSale {
public:
    virtual CStringW vfunc_1();                 // 0x1403c2be0
    virtual void vfunc_5();                     // 0x1403c2c90
    virtual void vfunc_6();                     // 0x1403c2cd0
};  // vftable 0x142d3fb60, ??_G 0x1403eaf10, dtor 0x1403e69e0
MS2_CHECK_SIZE(GameEventSaleUGCDesign, 0xd8);
class GameEventShutdownBillboard : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d12a0
    virtual void vfunc_2();                     // 0x1403d1350
    virtual void vfunc_5();                     // 0x1403d1360
    virtual void vfunc_6();                     // 0x1403d13a0
};  // vftable 0x142d40df0, ??_G 0x1403eaf50, dtor 0x1403e6a00
MS2_CHECK_SIZE(GameEventShutdownBillboard, 0xd0);
class GameEventShutdownDummy : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d4e90
    virtual void vfunc_2();                     // 0x1403d4f60
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d4f90
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d4fe0
    virtual void vfunc_5();                     // 0x1403d5040
    virtual void vfunc_6();                     // 0x1403d5050
    virtual void vfunc_7(void* other);          // 0x1403d5080
    virtual bool vfunc_9(void* other);          // 0x1403d5060
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d411b8, ??_G 0x1403eaf90, dtor 0x1403e6a20
MS2_CHECK_SIZE(GameEventShutdownDummy, 0xd8);
class GameEventShutdownFunctionItem : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cb220
    virtual void vfunc_2();                     // 0x1403cb2e0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cb400
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cb4e0
    virtual void vfunc_5();                     // 0x1403cb5b0
    virtual void vfunc_6();                     // 0x1403cb650
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d407c0, ??_G 0x1403eafd0, dtor 0x1403e6a40
MS2_CHECK_SIZE(GameEventShutdownFunctionItem, 0xe0);
class GameEventShutdownInteractObjectId : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cac50
    virtual void vfunc_2();                     // 0x1403cad10
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cae60
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403caf60
    virtual void vfunc_5();                     // 0x1403cb060
    virtual void vfunc_6();                     // 0x1403cb110
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40768, ??_G 0x1403eb010, dtor 0x1403e6a70
MS2_CHECK_SIZE(GameEventShutdownInteractObjectId, 0xe0);
class GameEventShutdownSkillItem : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cb750
    virtual void vfunc_2();                     // 0x1403cb810
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cb930
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cba00
    virtual void vfunc_5();                     // 0x1403cbad0
    virtual void vfunc_6();                     // 0x1403cbb60
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d40818, ??_G 0x1403eb050, dtor 0x1403e6aa0
MS2_CHECK_SIZE(GameEventShutdownSkillItem, 0xe0);
class GameEventShutdownUGCBanner : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d1440
    virtual void vfunc_2();                     // 0x1403d14f0
    virtual void vfunc_5();                     // 0x1403d1500
    virtual void vfunc_6();                     // 0x1403d1540
};  // vftable 0x142d40e48, ??_G 0x1403eb090, dtor 0x1403e6ad0
MS2_CHECK_SIZE(GameEventShutdownUGCBanner, 0xd0);
class GameEventShutdownUGCUpload : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cbc50
    virtual void vfunc_2();                     // 0x1403cbd20
    virtual void vfunc_5();                     // 0x1403cbdb0
    virtual void vfunc_6();                     // 0x1403cbe90
private:
    char m_pad_d0[0x28];
};  // vftable 0x142d40870, ??_G 0x1403eb0d0, dtor 0x1403e6af0
MS2_CHECK_SIZE(GameEventShutdownUGCUpload, 0xf8);
class GameEventSnowman : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cdc40
    virtual void vfunc_2();                     // 0x1403cdd50
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cdfe0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403ce070
    virtual void vfunc_5();                     // 0x1403cdf10
    virtual void vfunc_6();                     // 0x1403cdf80
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d40b30, ??_G 0x1403eb110, dtor 0x1403e6b20
MS2_CHECK_SIZE(GameEventSnowman, 0xe8);
class GameEventStampEvent : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c46e0
    virtual void vfunc_2();                     // 0x1403c47c0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c4fa0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c5010
    virtual void vfunc_5();                     // 0x1403c4eb0
    virtual void vfunc_6();                     // 0x1403c4f20
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d3fdc8, ??_G 0x1403eb150, dtor 0x1403e6b60
MS2_CHECK_SIZE(GameEventStampEvent, 0xe8);
class GameEventStampEventChar : public GameEventStampEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c5120
};  // vftable 0x142d3fe20, ??_G 0x1403eb190, dtor 0x1403e6b90
MS2_CHECK_SIZE(GameEventStampEventChar, 0xe8);
class GameEventStarShop : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403cd9d0
    virtual void vfunc_2();                     // 0x1403cda90
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403cdac0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403cdb10
    virtual void vfunc_5();                     // 0x1403cdb70
    virtual void vfunc_6();                     // 0x1403cdbb0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d40ad8, ??_G 0x1403eb1d0, dtor 0x1403e6bb0
MS2_CHECK_SIZE(GameEventStarShop, 0xd8);
class GameEventTimeRunEvent : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c5210
    virtual void vfunc_2();                     // 0x1403c52f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c5550
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c55c0
    virtual void vfunc_5();                     // 0x1403c5480
    virtual void vfunc_6();                     // 0x1403c54f0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3fe78, ??_G 0x1403eb210, dtor 0x1403e6bd0
MS2_CHECK_SIZE(GameEventTimeRunEvent, 0xe0);
class GameEventTrafficOptimizer : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bfe70
    virtual void vfunc_2();                     // 0x1403bff20
    virtual void vfunc_5();                     // 0x1403bff30
    virtual void vfunc_6();                     // 0x1403bff40
    virtual bool vfunc_9(void* other);          // 0x1403bff50
};  // vftable 0x142d3f798, ??_G 0x1403eb250, dtor 0x1403e6c00
MS2_CHECK_SIZE(GameEventTrafficOptimizer, 0xd0);
class GameEventTransferItemBound : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c91f0
    virtual void vfunc_2();                     // 0x1403c92b0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c9300
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c9350
    virtual void vfunc_5();                     // 0x1403c93b0
    virtual void vfunc_6();                     // 0x1403c93e0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d404a8, ??_G 0x1403eb290, dtor 0x1403e6c20
MS2_CHECK_SIZE(GameEventTransferItemBound, 0xd8);
class GameEventTreeWatering : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403d0450
    virtual void vfunc_2();                     // 0x1403d0550
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403d07a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403d0810
    virtual void vfunc_5();                     // 0x1403d06a0
    virtual void vfunc_6();                     // 0x1403d0720
    virtual void vfunc_8();                     // 0x1403d08c0
private:
    char m_pad_d0[0x28];
};  // vftable 0x142d40d98, ??_G 0x1403eb2d0, dtor 0x1403e6c40
MS2_CHECK_SIZE(GameEventTreeWatering, 0xf8);
class GameEventUGCMapContractSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c86c0
    virtual void vfunc_2();                     // 0x1403c8780
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c87b0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8800
    virtual void vfunc_5();                     // 0x1403c8860
    virtual void vfunc_6();                     // 0x1403c88a0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d403a0, ??_G 0x1403eb310, dtor 0x1403e6c80
MS2_CHECK_SIZE(GameEventUGCMapContractSale, 0xd8);
class GameEventUGCMapExtensionSale : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c8930
    virtual void vfunc_2();                     // 0x1403c89f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c8a20
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8a70
    virtual void vfunc_5();                     // 0x1403c8ad0
    virtual void vfunc_6();                     // 0x1403c8b10
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d403f8, ??_G 0x1403eb350, dtor 0x1403e6ca0
MS2_CHECK_SIZE(GameEventUGCMapExtensionSale, 0xd8);
class GameEventUGCMapSaleCoupon : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bea20
    virtual void vfunc_2();                     // 0x1403beae0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403beb10
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403beb60
    virtual void vfunc_5();                     // 0x1403bebc0
    virtual void vfunc_6();                     // 0x1403bebf0
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3f588, ??_G 0x1403eb390, dtor 0x1403e6cc0
MS2_CHECK_SIZE(GameEventUGCMapSaleCoupon, 0xd8);
class GameEventUgcMapCommendationGM : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c9780
    virtual void vfunc_2();                     // 0x1403c9880
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c98f0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c9980
    virtual void vfunc_5();                     // 0x1403c9a70
    virtual void vfunc_6();                     // 0x1403c9af0
private:
    char m_pad_d0[0x18];
};  // vftable 0x142d40558, ??_G 0x1403eb3d0, dtor 0x1403e6ce0
MS2_CHECK_SIZE(GameEventUgcMapCommendationGM, 0xe8);
class GameEventUpdateString : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c4470
    virtual void vfunc_2();                     // 0x1403c4540
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c45a0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c45f0
    virtual void vfunc_5();                     // 0x1403c4580
    virtual void vfunc_6();                     // 0x1403c4590
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d3fd70, ??_G 0x1403eb410, dtor 0x1403e6d10
MS2_CHECK_SIZE(GameEventUpdateString, 0xd8);
class GameEventUserCondition : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403bc620
    virtual void vfunc_2();                     // 0x1403bc6f0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403bc740
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403bc7b0
    virtual void vfunc_5();                     // 0x1403bc870
    virtual void vfunc_6();                     // 0x1403bc8f0
private:
    char m_pad_d0[0x10];
};  // vftable 0x142d3f270, ??_G 0x1403eb450, dtor 0x1403e6d40
MS2_CHECK_SIZE(GameEventUserCondition, 0xe0);
class GameEventWorldmapIcon : public GameEvent {
public:
    virtual CStringW vfunc_1();                 // 0x1403c8200
    virtual void vfunc_2();                     // 0x1403c82c0
    virtual void vfunc_3(Unk_GEOut* out);       // 0x1403c8320
    virtual void vfunc_4(Unk_GEIn* in);         // 0x1403c8370
    virtual void vfunc_5();                     // 0x1403c8300
    virtual void vfunc_6();                     // 0x1403c8310
private:
    char m_pad_d0[0x8];
};  // vftable 0x142d402f0, ??_G 0x1403eb490, dtor 0x1403e6d70
MS2_CHECK_SIZE(GameEventWorldmapIcon, 0xd8);
struct MesoRevivalEventContext : public CPtred {
    char m_pad_18[0x8];
};  // vftable 0x142d41488, ??_G 0x1403eb510, dtor 0x1403e6dd0
MS2_CHECK_SIZE(MesoRevivalEventContext, 0x20);
struct NpcEventDropEventContext : public CPtred {
    char m_pad_18[0x48];
};  // vftable 0x142d414b8, ??_G 0x1403eb550, dtor 0x1403e6df0
MS2_CHECK_SIZE(NpcEventDropEventContext, 0x60);
struct OntimeEventContext : public CPtred {
    // One of the two 7-value comma lists GameEventOntime::vfunc_2 (0x1403bd6c0) reads. Field meanings unknown.
    struct Condition {
        Condition();                                // 0x1403e40d0: Clear()
        // @0x1403ec470
        void Clear() { m_0 = 0; m_4 = 0; m_8 = 0; m_c = 0; m_10 = false; m_14 = 0; m_18 = 0; }
        int m_0;
        int m_4;
        int m_8;
        int m_c;
        bool m_10;
        int m_14;
        int m_18;
    };
    OntimeEventContext();                           // 0x1403e41d0: Clear()
    // @0x1403ec4d0
    void Clear() { m_18 = 0; m_1c = false; m_20 = 0; m_24.Clear(); m_40.Clear(); }
    int m_18;
    bool m_1c;
    int m_20;
    Condition m_24;
    Condition m_40;
};  // vftable 0x142d41498, ??_G 0x1403eb590, dtor 0x1403e6e30
MS2_CHECK_SIZE(OntimeEventContext, 0x60);
MS2_CHECK_OFFSET(OntimeEventContext, m_40, 0x40);
struct PreminmMarketSaleEventContext : public CPtred {
    char m_pad_18[0x20];
};  // vftable 0x142d41620, ??_G 0x1403eb5d0, dtor 0x1403e6e50
MS2_CHECK_SIZE(PreminmMarketSaleEventContext, 0x38);
struct Unk_VftableEmitTag {};   // not exe code: selects the header-only ctors below
// Members recovered by gameeventcontext.cpp (stream Write 0x140402560 / Read 0x140402640); the ctor is in
// gameevent.cpp.
class ReactorContext : public CPtred {
public:
    explicit ReactorContext(int eventId);
    // Not exe code: lets the COMDAT tail unit emit the vftable (and its ??_G) without the gameevent.cpp ctor.
    explicit ReactorContext(Unk_VftableEmitTag) {}
    void Write(COutputStream& out);                 // 0x140402560
    void Read(CInPacket& packet);                   // 0x140402640
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    __int64 m_endTime;                              // +0x20
    int m_28;
    int m_pad_2c;
    ATL::CAtlArray<unsigned> m_30;                  // +0x30
};  // vftable 0x142d415b0, ??_G 0x1403eb650, dtor 0x1403e6ea0
MS2_CHECK_SIZE(ReactorContext, 0x50);
// The rock-paper-scissors texts (gameeventcontext.cpp Load 0x1404000c0); value-initialized by the client
// (`new RpsGameData()`, implicit ctor 0x140ce9290).
class RpsGameData : public CPtred {
public:
    struct Result {
        ATL::CAtlArray<CStringW> m_actions;         // +0x00 <actions><v value>
        ATL::CAtlArray<CStringW> m_messages;        // +0x20 <messages><v value>
    };
    bool Load(Unk_140165cf0* pElem);                // 0x1404000c0
    CStringW m_actionNames[3];                      // +0x18 play/actions rock, paper, scissors
    ATL::CAtlArray<CStringW> m_messages;            // +0x30 play/messages
    Result m_results[3];                            // +0x50 result/draw, win, lose
};
MS2_CHECK_SIZE(RpsGameData, 0x110);
// Members recovered by gameeventcontext.cpp (stream Write 0x1404006c0 / Read 0x1404008c0); the RewardData ctor is
// in gameevent.cpp.
class RpsContext : public CPtred {
public:
    struct RewardData : public CPtred {
        RewardData();
        // Not exe code: lets the COMDAT tail unit emit the vftable (and its ??_G) without the gameevent.cpp ctor.
        explicit RewardData(Unk_VftableEmitTag) {}
        int m_count;                                // +0x18
        int m_pad_1c;
        ATL::CAtlArray<ItemEntity> m_items;         // +0x20
    };  // vftable 0x142d41580, ??_G 0x1403eb710, dtor 0x1403e6f50
    void Write(COutputStream& out);                 // 0x1404006c0
    void Read(CInPacket& packet);                   // 0x1404008c0
    CStringW m_strTitle;                            // +0x18
    int m_20;
    int m_pad_24;
    ATL::CAtlArray<MS2Ptr<RewardData> > m_rewards;  // +0x28
    int m_48;
    int m_pad_4c;
    __int64 m_endTime;                              // +0x50
    MS2Ptr<RpsGameData> m_spGameData;               // +0x58
};  // vftable 0x142d41590, ??_G 0x1403eb750, dtor 0x1403e6f80
MS2_CHECK_SIZE(RpsContext, 0x68);
struct SAHotTimeEventContext : public CPtred {
    char m_pad_18[0x20];
};  // vftable 0x142d41478, ??_G 0x1403eb790, dtor 0x1403e6fd0
MS2_CHECK_SIZE(SAHotTimeEventContext, 0x38);
class SaleCube : public CPtred {
    char m_pad_18[0x10];
};  // vftable 0x142d3f098, ??_G 0x1403eb7d0, dtor 0x1403e7010
MS2_CHECK_SIZE(SaleCube, 0x28);
struct SkillUpgradeSaleEventContext : public CPtred {
    char m_pad_18[0x10];
};  // vftable 0x142d414a8, ??_G 0x1403eb810, dtor 0x1403e7030
MS2_CHECK_SIZE(SkillUpgradeSaleEventContext, 0x28);
// Members recovered by gameeventcontext.cpp (stream Write 0x1403ff8f0 / Read 0x1403ffc00); the Snowman ctor
// 0x1403e4650 is in gameevent.cpp.
class SnowmanContext : public CPtred {
public:
    struct Snowman : public CPtred {
        Snowman();                                  // 0x1403e4650: zeroes the three ints
        // Not exe code: lets the COMDAT tail unit emit the vftable (and its ??_G) without the gameevent.cpp ctor.
        explicit Snowman(Unk_VftableEmitTag) {}
        bool ReachedGoal(int value);                // 0x1403ff7b0: m_18 <= value
        bool BelowLimit(int value);                 // 0x1403ff7f0: value < m_1c
        bool ReachedBonus(int value);               // 0x1403ff830: m_20 <= value
        bool CanProceed(int goalValue, int limitValue);     // 0x1403ff870
        int m_18;
        int m_1c;
        int m_20;
        int m_pad_24;
        ATL::CAtlArray<ItemEntity> m_items;         // +0x28
        ATL::CAtlArray<ItemEntity> m_bonusItems;    // +0x48
    };  // vftable 0x142d41548, ??_G 0x1403eb850, dtor 0x1403e7050
    void Write(COutputStream& out);                 // 0x1403ff8f0
    void Read(CInPacket& packet);                   // 0x1403ffc00
    MS2Ptr<Snowman> GetSnowman(int index);          // 0x140400000
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    ATL::CAtlArray<MS2Ptr<Snowman> > m_snowmen;     // +0x20
    CStringW m_strTitle;                            // +0x40
    __int64 m_endTime;                              // +0x48
};  // vftable 0x142d41558, ??_G 0x1403eb890, dtor 0x1403e7090
MS2_CHECK_SIZE(SnowmanContext, 0x50);
// Members recovered by gameeventcontext.cpp (stream Write 0x1403fcc90 / Read 0x1403fd060). The ctors are in
// gameevent.cpp (not recovered).
class StampEventContext : public CPtred {
public:
    struct Reward : public CPtred {
        Reward();
        int m_count;                    // +0x18 stamps needed
        int m_bReceived;                // +0x1c (a byte on the wire)
        ItemEntity m_item;              // +0x20
        ItemEntity m_item2;             // +0x50
    };  // vftable 0x142d414e8, ??_G 0x1403eb6d0, dtor 0x1403e6f10
    struct Stamp : public CPtred {
        Stamp();
        int m_id;                       // +0x18
        int m_bStamped;                 // +0x1c (a byte on the wire)
        int m_20;
        int m_24;
    };  // vftable 0x142d414d8, ??_G 0x1403eb8d0, dtor 0x1403e70d0
    void Write(COutputStream& out);                 // 0x1403fcc90
    void Read(CInPacket& packet);                   // 0x1403fd060
    int GetStampFlag(int id);                       // 0x1403fd5a0: 1/0 stamped, -1 unknown stamp
    BOOL HasStamp(int id);                          // 0x1403fd660
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    ATL::CAtlArray<MS2Ptr<Stamp> > m_stamps;        // +0x20
    ATL::CAtlArray<MS2Ptr<Reward> > m_rewards;      // +0x40
    ItemEntity m_item;                              // +0x60
    __int64 m_endTime;                              // +0x90
    int m_98;
    bool m_b9c;
    CStringW m_strTitle;                            // +0xa0
};  // vftable 0x142d414f8, ??_G 0x1403eb910, dtor 0x1403e70f0
MS2_CHECK_SIZE(StampEventContext, 0xa8);
// The TreeWateringContext tables (gameeventcontext.cpp Write 0x140402770 / Read 0x140402d20); the ctors
// (0x1403e4990 / 0x1403e49f0 / 0x1403e4a30) are in gameevent.cpp.
class TreeWatering_EmotionDay : public CPtred {
public:
    TreeWatering_EmotionDay();
    CMsTime m_beginTime;            // +0x18
    CMsTime m_endTime;              // +0x28
};  // vftable 0x142d415d0, ??_G 0x1403eb990, dtor 0x1403e71f0
MS2_CHECK_SIZE(TreeWatering_EmotionDay, 0x38);
class TreeWatering_TreeResource : public CPtred {
public:
    TreeWatering_TreeResource();
    int m_id;                       // +0x18 key in TreeWateringContext::m_resources
    int m_pad_1c;
    CString m_20;                   // +0x20
};  // vftable 0x142d415e0, ??_G 0x1403eb9d0, dtor 0x1403e7210
MS2_CHECK_SIZE(TreeWatering_TreeResource, 0x28);
class TreeWatering_TreeStep : public CPtred {
public:
    TreeWatering_TreeStep();
    int m_step;                     // +0x18 key in TreeWateringContext::m_steps
    int m_pad_1c;
    CMsTime m_beginTime;            // +0x20
    CMsTime m_endTime;              // +0x30
};  // vftable 0x142d415c0, ??_G 0x1403eba10, dtor 0x1403e7240
MS2_CHECK_SIZE(TreeWatering_TreeStep, 0x40);
// Members proven by the dtor 0x1403e7150 (CString dtors at +0x118/+0x110/+0x108/+0xf8, then the CAtlMap/CAtlArray
// members at +0xa8, +0x68, +0x20), by TreeWateringAction::vfunc_1/2/6 (0x1409602c0 / 0x1409606a0 / 0x140960a10) and
// by gameeventcontext.cpp (stream Write 0x140402770 / Read 0x140402d20). The ctor is in gameevent.cpp.
class TreeWateringContext : public CPtred {
public:
    explicit TreeWateringContext(int eventId);
    // Not exe code: lets the COMDAT tail unit emit the vftable (and its ??_G) without the gameevent.cpp ctor.
    explicit TreeWateringContext(Unk_VftableEmitTag) {}
    void Write(COutputStream& out);                 // 0x140402770
    void Read(CInPacket& packet);                   // 0x140402d20
    MS2Ptr<TreeWatering_TreeStep> GetStep(const CMsTime& time);     // 0x140403710 the step whose span holds the time
    MS2Ptr<TreeWatering_TreeResource> GetResource(int id);          // 0x140403810
    bool FUN_1404038c0(const CMsTime& now);     // 0x1404038c0 some emotion day (array at +0x68) covers the time
    int m_nEventId;                 // +0x18 key of the attend table rows
    int m_pad_1c;
    ATL::CAtlMap<int, MS2Ptr<TreeWatering_TreeStep> > m_steps;              // +0x20
    ATL::CAtlArray<MS2Ptr<TreeWatering_EmotionDay> > m_emotionDays;         // +0x68
    int m_nDailyLimit;              // +0x88 waterings a day (attend row 0x777)
    int m_8c;
    int m_90;                       // +0x90 (a byte on the wire)
    int m_94;
    int m_nBonusLimit;              // +0x98 bonus waterings a day (attend row 0x778)
    int m_9c;
    int m_a0;                       // +0xa0 (a byte on the wire)
    int m_a4;
    ATL::CAtlMap<int, MS2Ptr<TreeWatering_TreeResource> > m_resources;      // +0xa8
    int m_f0;
    int m_pad_f4;
    CString m_strTreeName;          // +0xf8 the tree's world entity name
    int m_nWaterItemId;             // +0x100 item id looked up in the inventory
    int m_pad_104;
    CString m_strStateWater;        // +0x108 state data name of the water action
    CString m_strStateBonus;        // +0x110 state data name of the bonus action
    CString m_str118;               // +0x118
};  // vftable 0x142d415f0, ??_G 0x1403eb950, dtor 0x1403e7150
MS2_CHECK_SIZE(TreeWateringContext, 0x120);
MS2_CHECK_OFFSET(TreeWateringContext, m_nEventId, 0x18);
MS2_CHECK_OFFSET(TreeWateringContext, m_nDailyLimit, 0x88);
MS2_CHECK_OFFSET(TreeWateringContext, m_nBonusLimit, 0x98);
MS2_CHECK_OFFSET(TreeWateringContext, m_resources, 0xa8);
MS2_CHECK_OFFSET(TreeWateringContext, m_strTreeName, 0xf8);
MS2_CHECK_OFFSET(TreeWateringContext, m_nWaterItemId, 0x100);
MS2_CHECK_OFFSET(TreeWateringContext, m_strStateWater, 0x108);
MS2_CHECK_OFFSET(TreeWateringContext, m_strStateBonus, 0x110);
MS2_CHECK_OFFSET(TreeWateringContext, m_str118, 0x118);
// TimeRunEventContext: outer class recovered by gameeventcontext.cpp (ctor 0x1403fe170, Write / Read); the nested
// QuestContext ctor 0x1403e42a0 is in gameevent.cpp.
class TimeRunEventContext : public CPtred {
public:
    struct QuestContext : public CPtred {
        QuestContext();
        unsigned m_questId;             // +0x18
        int m_1c;
        int m_20;                       // +0x20 (a short on the wire)
    };  // vftable 0x142d41518, ??_G 0x1403eb610, dtor 0x1403e6e80
    TimeRunEventContext(int eventId);               // 0x1403fe170
    void Write(COutputStream& out);                 // 0x1403fe250
    void Read(CInPacket& packet);                   // 0x1403fe520
    unsigned GetNextRewardKey(unsigned value);      // 0x1403fe8f0: first reward key above `value`, 0 if none
    int m_eventId;                                  // +0x18
    int m_1c;
    int m_value;                                    // +0x20
    __int64 m_endTime;                              // +0x28
    ATL::CAtlMap<unsigned, MS2Ptr<QuestContext> > m_quests;     // +0x30
    ItemEntity m_item;                                          // +0x78
    ATL::CRBMap<unsigned, MS2Ptr<ItemEntity> > m_rewards;       // +0xa8
};
MS2_CHECK_SIZE(TimeRunEventContext, 0xd8);
MS2_CHECK_OFFSET(TimeRunEventContext, m_rewards, 0xa8);
// Members recovered by gameeventcontext.cpp (ctor 0x140407210, stream Write 0x140407300 / Read 0x140407580).
class LongTermAttendGiftContext : public CPtred {
public:
    struct Reward : public CPtred {
        Reward();                                   // 0x1403e4360 (gameevent.cpp)
        int m_count;                                // +0x18 "count"
        bool m_1c;
        ItemEntity m_item01;                        // +0x20
        ItemEntity m_item02;                        // +0x50
    };  // vftable 0x142d41610, ??_G 0x1403eb690, dtor 0x1403e6ed0
    LongTermAttendGiftContext(int eventId);         // 0x140407210
    void Write(COutputStream& out);                 // 0x140407300
    void Read(CInPacket& packet);                   // 0x140407580
    int m_eventId;                                  // +0x18
    int m_pad_1c;
    ATL::CAtlArray<MS2Ptr<Reward> > m_rewards;      // +0x20
    __int64 m_40;
    int m_48;
    bool m_4c;
    CMsTime m_beginTime;                            // +0x50
    CMsTime m_endTime;                              // +0x60
    CStringW m_eventTag;                            // +0x70
    CStringW m_title;                               // +0x78
    int m_maxAttendance;                            // +0x80
    int m_merat;                                    // +0x84
};  // vftable 0x142d44250, ??_G 0x140411e80 (gameeventcontext.cpp)
MS2_CHECK_SIZE(LongTermAttendGiftContext, 0x88);
MS2_CHECK_SIZE(GalleryContext::Card, 0x20);
MS2_CHECK_SIZE(TimeRunEventContext::QuestContext, 0x28);
MS2_CHECK_SIZE(LongTermAttendGiftContext::Reward, 0x80);
MS2_CHECK_SIZE(StampEventContext::Reward, 0x80);
MS2_CHECK_SIZE(RpsContext::RewardData, 0x40);
MS2_CHECK_SIZE(SnowmanContext::Snowman, 0x68);
MS2_CHECK_SIZE(StampEventContext::Stamp, 0x28);

// gameeventcontext.cpp element types that gameevent.cpp holds through MS2Ptr<> (layouts not recovered).
// Start / end second of the day (two Unk_DayTime; inline ctor 0x1402e4a60).
struct Unk_DayTimeRange {
    Unk_DayTimeRange() : m_start(0), m_end(0) {}
    Unk_DayTime m_start;
    Unk_DayTime m_end;
};
class EventTimeLimitDungeonContext : public CPtred {   // operator new(0x28) in the 0x1403c31c0 xml loader
public:
    EventTimeLimitDungeonContext();                 // 0x1403fcb10
    void Write(COutputStream& out);                 // 0x1403fcb80
    void Read(CInputStream& in);                    // 0x1403fcc00
    int m_eventId;                                  // +0x18
    unsigned m_dungeonId;                           // +0x1c "dungeonID"
    Unk_DayTimeRange m_rangeTime;                   // +0x20 "rangeTime"
};
MS2_CHECK_SIZE(EventTimeLimitDungeonContext, 0x28);
// The CRBMap<unsigned int, MS2Ptr<.>> value of BlueMarbleEventContext (+0x38); vftable 0x142d44130, ??_G 0x140411ac0
// (operator delete 0x28, dtor 0x1404105a0), both in gameeventcontext.cpp.
enum Unk_BlueMarbleSlotType {};
class BonusGameBlueMarbleSlot : public CPtred {
public:
    BonusGameBlueMarbleSlot();                      // 0x1403fc640
    void Load(Unk_140165cf0* pElem);                // 0x1403fc6a0
    Unk_BlueMarbleSlotType m_type;                  // +0x18 "type"
    int m_arg1;                                     // +0x1c "arg1"
    int m_arg2;                                     // +0x20 "arg2"
};
MS2_CHECK_SIZE(BonusGameBlueMarbleSlot, 0x28);
// Two CStrings (dtor 0x1403e6da0); a std:: container element of gameevent.cpp. Name unknown.
struct Unk_GameEventStrPair {
    CStringW m_0;
    CStringW m_8;
};
MS2_CHECK_SIZE(Unk_GameEventStrPair, 0x10);
// An inclusive int range (name invented): read from an "a,b" pair by 0x1403d8240; GameEventBlackMarketFeeDiscount
// checks against a static (0, 10000) one.
struct Unk_GameEventIntRange {
    Unk_GameEventIntRange(int nMin, int nMax);      // 0x1403e19f0
    // @0x1403eeaf0
    void Init(int nMin, int nMax) { m_min = nMin; m_max = nMax; }
    // @0x1403ef200
    bool IsInRange(int n)
    {
        if (m_min > n)
            return false;
        if (m_max < n)
            return false;
        return true;
    }
    int m_min;
    int m_max;
};
MS2_CHECK_SIZE(Unk_GameEventIntRange, 8);
