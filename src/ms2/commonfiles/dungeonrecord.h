// dungeonrecord.h - a character's record of one dungeon room (DungeonRecord) and a dungeon rank reward entry
// (DungeonRankReward), both sent in packets. Owning unit: commonfiles\dungeonrecord.cpp (0x14031b800-0x14031c510; the
// unit name is assumed from the class names, no assert names it). Field and method names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/partybits.h"

class CInputStream;
class COutputStream;
class DungeonRoom;

// A value that counts until an expiry time (0 once expired).
template <class T>
struct Unk_DungeonTimedValue
{
    Unk_DungeonTimedValue() : value(0), expire(0) {}            // 0x14031c070 (unsigned char)
    Unk_DungeonTimedValue(T v) : value(v), expire(0) {}         // 0x14031c090 (unsigned short)
    // @0x14031c2b0 (unsigned char)
    T Get(__int64 tNow)
    {
        if (tNow >= expire)
            return 0;
        return value;
    }

    T value;                            // +0
    __int64 expire;                     // +8
};

// RTTI DungeonRecord, 0x88 bytes.
class DungeonRecord : public CPtred
{
public:
    DungeonRecord();                                // 0x14031b800
    unsigned GetDungeonRoomID();                    // 0x14031b8e0
    bool IsSeasonRankRoom();                        // 0x14031b900
    bool TestFlag(int nBit);                        // 0x14031b940
    unsigned char IsAccountReward();                // 0x14031b970
    int GetBonusRewardCount(__int64 tNow);    // 0x14031b9a0
    int GetClearCount(__int64 tNow);                // 0x14031b9d0
    unsigned GetSubRewardCount();                   // 0x14031ba10
    int GetExtraCount(__int64 tNow);                // 0x14031ba30
    int GetRewardCount(__int64 tNow);               // 0x14031ba70
    int GetUsedBonusCount(__int64 tNow);  // 0x14031bad0
    int GetBonusCount(__int64 tNow);      // 0x14031bb00
    MS2Ptr<DungeonRoom> GetRoom();                  // 0x14031bb30
    void ResolveRoom();                             // 0x14031bb80

    unsigned m_dungeonRoomID;                       // +0x18
    __int64 m_expire;                               // +0x20 the counts at +0x28/+0x40/+0x58 reset then
    unsigned char m_bonusRewardCount;               // +0x28
    Unk_DungeonTimedValue<unsigned char> m_clearCount;  // +0x30
    unsigned char m_bonusCount;                     // +0x40
    Unk_DungeonTimedValue<unsigned char> m_extraCount;  // +0x48
    unsigned char m_usedBonusCount;                 // +0x58 not serialised
    long m_5c;                                      // +0x5c
    short m_60;                                     // +0x60 -1 when unset
    Unk_DungeonTimedValue<unsigned short> m_68;     // +0x68
    Unk_PartyBits m_flags;                          // +0x78
    DungeonRoom* m_pRoom;                           // +0x80 resolved from the room table
};
MS2_CHECK_SIZE(DungeonRecord, 0x88);
MS2_CHECK_OFFSET(DungeonRecord, m_clearCount, 0x30);
MS2_CHECK_OFFSET(DungeonRecord, m_68, 0x68);
MS2_CHECK_OFFSET(DungeonRecord, m_flags, 0x78);
MS2_CHECK_OFFSET(DungeonRecord, m_pRoom, 0x80);

CInputStream& operator>>(CInputStream& in, DungeonRecord& record);         // 0x14031bc00
COutputStream& operator<<(COutputStream& out, DungeonRecord& record);      // 0x14031bd10

// RTTI DungeonRankReward, 0x28 bytes.
class DungeonRankReward : public CPtred
{
public:
    DungeonRankReward();                            // 0x14031be00

    unsigned m_18;                                  // +0x18
    long m_1c;                                      // +0x1c
    __int64 m_20;                                   // +0x20
};
MS2_CHECK_SIZE(DungeonRankReward, 0x28);

CInputStream& operator>>(CInputStream& in, DungeonRankReward& reward);     // 0x14031be60
COutputStream& operator<<(COutputStream& out, DungeonRankReward& reward);  // 0x14031bec0
