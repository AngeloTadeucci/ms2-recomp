// cnpcshopbuyperiod.h - PLACEHOLDER for CNpcShopBuyPeriod (RTTI .?AVCNpcShopBuyPeriod@@, CPtred-derived, 0x90 bytes:
// `operator new(0x90)` at 0x140db61a0, ctor 0x1406dc5a0, dtor 0x1406ef650 (??_G 0x1406f1000)): the period (dates, daily
// time ranges, week days) in which an NPC shop product can be bought. NOT an original header; the real class belongs to
// commonfiles\npcshopdata.cpp (unrecovered). Only the members the client product code reads are named.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"

class CInPacket;

// A time-of-day value (4 bytes; the two accessors are 0x14086a4b0 / 0x14086a490).
struct Unk_ShopClock
{
    int FUN_14086a4b0() const;
    int FUN_14086a490() const;
    unsigned m_nValue;
};
MS2_CHECK_SIZE(Unk_ShopClock, 4);
// A pair of time-of-day values: the start and the end of a daily buy window.
struct Unk_ShopClockPair
{
    Unk_ShopClock m_from;
    Unk_ShopClock m_to;
};
MS2_CHECK_SIZE(Unk_ShopClockPair, 8);

class CNpcShopBuyPeriod : public CPtred
{
public:
    CNpcShopBuyPeriod();                                    // 0x1406dc5a0
    virtual ~CNpcShopBuyPeriod();                           // 0x1406ef650
    void FUN_1406dcb40(CInPacket& in);                      // read the period from a packet
    bool FUN_1406dc810();                                   // after reading: normalize
    bool FUN_1406dda70() const;                             // the period has a day / time-of-day restriction
    bool FUN_1406ddc90(const CMsTime& tmNow);               // tmNow is inside the period

    CMsTime m_tmSourceStart;                                // +0x18
    CMsTime m_tmSourceEnd;                                  // +0x28
    CMsTime m_tmStart;                                      // +0x38 first buyable moment (0: open)
    CMsTime m_tmEnd;                                        // +0x48 last buyable moment (0: open)
    ATL::CAtlArray<Unk_ShopClockPair> m_aPartTimes;         // +0x58
    std::set<unsigned> m_setDays;                           // +0x78 week days
    bool m_bVisible;                                        // +0x88
};
MS2_CHECK_SIZE(CNpcShopBuyPeriod, 0x90);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_tmStart, 0x38);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_aPartTimes, 0x58);
MS2_CHECK_OFFSET(CNpcShopBuyPeriod, m_setDays, 0x78);
