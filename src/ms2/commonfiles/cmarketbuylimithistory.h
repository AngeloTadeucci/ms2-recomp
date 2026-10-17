// cmarketbuylimithistory.h - CMarketBuyLimitHistory (RTTI; vftable 0x142d15a78, dtor 0x14027e640, ??_G 0x14027fc30 are
// defined in the commonstruct range), the in-memory market buy limit row: the same account/character/type/product/count
// as CDBMarketBuyLimitHistory plus the list of item uids bought. Member names are invented.
// NOT an original header (name assumed). Recovered with unit_140268b20.
#pragma once

#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/ms2layout.h"

class COutputStream;
class CInPacket;

// RTTI CDBMarketBuyLimitHistory: the DB row (members/ctor/stream methods are defined in unit_140268010.cpp; this
// declaration repeats its layout so the in-memory row can merge one).
class CDBMarketBuyLimitHistory : public CPtred
{
public:
    CDBMarketBuyLimitHistory();                                 // 0x1402688d0
    void Write(COutputStream* pOut);                            // 0x140268950
    void Read(CInPacket& packet);                               // 0x140268a00

    __int64 m_n18;                                              // +0x18
    __int64 m_n20;                                              // +0x20
    int m_nFlag;                                                // +0x28 (one byte on the wire)
    int m_n2c;                                                  // +0x2c
    int m_n30;                                                  // +0x30
    int m_pad_34;
    __int64 m_n38;                                              // +0x38
};
MS2_CHECK_SIZE(CDBMarketBuyLimitHistory, 0x40);

class CMarketBuyLimitHistory : public CPtred
{
public:
    CMarketBuyLimitHistory();                                   // 0x140268b20
    CMarketBuyLimitHistory(CDBMarketBuyLimitHistory* pRow);     // 0x140268b80
    void Reset();                                               // 0x140268c30
    void Merge(CDBMarketBuyLimitHistory* pRow);                 // 0x140268ca0
    void Write(COutputStream* pOut);                            // 0x140268d60
    void Read(CInPacket& packet);                               // 0x140268e70

    __int64 m_n18;                                              // +0x18 account id
    __int64 m_n20;                                              // +0x20 character id (compared only for type 2)
    int m_nType;                                                // +0x28 (one byte on the wire)
    int m_n2c;                                                  // +0x2c product id
    int m_n30;                                                  // +0x30 count
    int m_pad_34;
    ATL::CAtlArray<__int64> m_itemUids;                         // +0x38
};
MS2_CHECK_SIZE(CMarketBuyLimitHistory, 0x58);
