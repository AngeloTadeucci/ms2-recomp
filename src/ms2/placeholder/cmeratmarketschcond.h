// cmeratmarketschcond.h - PLACEHOLDER for CMeratMarketSchCond (RTTI name; its unit ?\meratmarketbasketinfo.cpp is not
// recovered). A CPtred-derived market search condition (0x50 bytes, vftable with the dtor only). Only what
// commonfiles\ugcdef.cpp touches is declared (the UGC item icon callback owns one through MS2Ptr). NOT an original
// header; member names are invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CMeratMarketSchCond : public CPtred
{
public:
    CMeratMarketSchCond();                                      // 0x1406a34b0
    virtual ~CMeratMarketSchCond();                             // 0x1406a3580

    void FUN_1406a3720(const CMeratMarketSchCond* pOther);      // reset, then copy `pOther` (when not NULL)

    int m_18;                                                   // +0x18
    int m_1c;                                                   // +0x1c
    int m_20;                                                   // +0x20
    int m_24;                                                   // +0x24
    CStringW m_str;                                             // +0x28
    int m_30;                                                   // +0x30
    int m_34;                                                   // +0x34
    int m_38;                                                   // +0x38
    int m_3c;                                                   // +0x3c
    int m_40;                                                   // +0x40
    int m_44;                                                   // +0x44
    int m_48;                                                   // +0x48
    int m_pad_4c;                                               // +0x4c
};
MS2_CHECK_SIZE(CMeratMarketSchCond, 0x50);
