// weddinghallticket.h - PLACEHOLDER for WeddingHallTicket (RTTI-less value class of weddingproxy.cpp, 0xa0 bytes: the
// value of the character's wedding hall ticket map, `std::map<unsigned __int64, WeddingHallTicket>`; the tree node is
// 0xc8 = 0x20 header + the 8-byte key + this). NOT an original header. Only the fields that recovered code reads are
// named; the destructor is the exe's out-of-line one (0x1408ffa10), declared only.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"

class WeddingHallTicket
{
public:
    ~WeddingHallTicket();                           // 0x1408ffa10
    __int64 m_unk00; __int64 m_unk08; __int64 m_unk10; __int64 m_unk18;
    int m_nPackageId;                               // +0x20
    int m_nHallId;                                  // +0x24
    __int64 m_unk28; __int64 m_unk30; __int64 m_unk38;
    __int64 m_nTime;                                // +0x40 the wedding time
    CStringW m_strGroom;                            // +0x48
    CStringW m_strBride;                            // +0x50
    __int64 m_unk58; __int64 m_unk60; __int64 m_unk68; __int64 m_unk70;
    __int64 m_unk78; __int64 m_unk80; __int64 m_unk88; __int64 m_unk90; __int64 m_unk98;
};
MS2_CHECK_SIZE(WeddingHallTicket, 0xa0);
