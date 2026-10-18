// statpointmanager.h - CStatPointManager (RTTI name, 0xc0 bytes): the character's stat point bookkeeping (total points,
// points already spent, points left, the spent points per stat and a second per-key table) fed by the server's stat
// point packet (mode 0 / 1) and the add / reset requests. Header name assumed from the unit path; member and method
// names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CInPacket;

class CStatPointManager : public CPtred
{
public:
    // The keys are enums in the exe (the map takes them by const reference).
    enum Unk_StatKey { STAT_KEY_NONE };
    enum Unk_ExtraKey { EXTRA_KEY_NONE };
    typedef ATL::CAtlMap<Unk_StatKey, int> StatMap;
    typedef ATL::CAtlMap<Unk_ExtraKey, unsigned> ExtraMap;

    CStatPointManager(void* pOwner);        // 0x140ca9d50
    virtual ~CStatPointManager();           // 0x140ca9e40 (??_G 0x140caa710)

    void OnPacket(CInPacket& packet);       // 0x140ca9e90 mode byte 0 / 1
    void LoadExtra(CInPacket& packet);      // 0x140ca9f10 mode 0: total points + the per-key table
    void LoadStats(CInPacket& packet);      // 0x140caa040 mode 1: total points + the spent points per stat
    int GetRemaining();                     // 0x140caa1a0 points left to spend
    int GetUsed();                          // 0x140caa1c0 points spent
    int GetStatPoints(Unk_StatKey nStat);        // 0x140caa1e0 points spent on one stat (0 when none)
    unsigned GetExtra(Unk_ExtraKey nKey);   // 0x140caa220 value of the per-key table (0 when none)
    int GetTotal();                         // 0x140caa260
    void RequestAdd(int nStat, int nAmount);   // 0x140caa280 sends opcode 0x99 mode 2 unless the stat limit is reached
    void RequestReset();                    // 0x140caa3b0 sends opcode 0x99 mode 3 when points were spent

private:
    MS2_LAYOUT_FRIEND;
    void* m_pOwner;                         // +0x18
    int m_nTotal;                           // +0x20
    int m_nUsed;                            // +0x24
    int m_nRemaining;                       // +0x28
    StatMap m_stats;                        // +0x30 stat -> spent points
    ExtraMap m_extra;                       // +0x78
};
MS2_CHECK_SIZE(CStatPointManager, 0xc0);
MS2_CHECK_OFFSET(CStatPointManager, m_nTotal, 0x20);
MS2_CHECK_OFFSET(CStatPointManager, m_stats, 0x30);
MS2_CHECK_OFFSET(CStatPointManager, m_extra, 0x78);
