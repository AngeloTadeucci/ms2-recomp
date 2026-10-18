// paybacktable.h - PLACEHOLDER for PaybackTable (RTTI .?AVPaybackTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<PaybackTable> at +0x0, CValidData<PaybackTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; it reads Table/PaybackTable.xml (<payback
// adventure_level payback_percent/>, the merat payback share per adventure level) and answers the payback amount and
// period queries (?\paybacktable.cpp). Member names are invented from use.
#pragma once

#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class PaybackTable : public TSingleton<PaybackTable>, public CValidData<PaybackTable>
{
public:
    struct LevelEntry                                       // 8 bytes
    {
        LevelEntry();                                       // 0x14071af20
        unsigned m_nLevel;                                  // +0x00 adventure level
        unsigned m_nWeight;                                 // +0x04 payback_percent
    };

    PaybackTable();                                         // 0x14071af50
    bool Load();                                            // 0x14071aff0 (ms2.cpp calls it as FUN_14071aff0)
    std::vector<LevelEntry>& GetLevels(unsigned __int64 nContext);   // 0x14071b4c0
    float GetLevelPercent(const LevelEntry* pEntry, unsigned __int64 nContext);  // 0x14071b4e0
    float GetPercentUpTo(unsigned nLevel, unsigned __int64 nContext);            // 0x14071b540
    __int64 GetMeratUpTo(unsigned nLevel, __int64 nAmount, unsigned __int64 nContext);   // 0x14071b630
    __int64 GetMeratTotal(__int64 nAmount, unsigned __int64 nContext);           // 0x14071b730
    bool InPeriod(__int64 nTime);                           // 0x14071b7c0
    bool IsPaybackDay(__int64 nTime);                       // 0x14071b860
    bool InMonthPeriod(__int64 nTime);                      // 0x14071b8d0
    bool IsResetWindow();                                   // 0x14071b9c0
    __int64 GetStartTime();                                 // 0x14071baa0
    unsigned GetTotalWeight(unsigned __int64 nContext);     // 0x14071bac0
    __int64 GetLevelMerat(const LevelEntry* pEntry, __int64 nAmount, unsigned __int64 nContext);   // 0x14071bae0
    bool IsLocaleEnabled();                                 // 0x14071bc00
    __int64 GetWeightedMerat(const LevelEntry* pEntry, __int64 nAmount, unsigned __int64 nContext);  // 0x14071bc20

    // @0x14071d7e0
    static void SetInit(bool bInit) { s_bInit = bInit; }
    static bool s_bInit;

    __int64 m_nStart;                                       // +0x10 PaybackStartDate 00:00:00
    __int64 m_nEnd;                                         // +0x18 PaybackEndDate 23:59:59
    std::vector<LevelEntry> m_levels;                       // +0x20 sorted by level
    int m_nTotalWeight;                                     // +0x38
    bool m_bLocale;                                         // +0x3c
};
MS2_CHECK_SIZE(PaybackTable, 0x40);
MS2_CHECK_OFFSET(PaybackTable, m_nStart, 0x10);
MS2_CHECK_OFFSET(PaybackTable, m_levels, 0x20);
MS2_CHECK_OFFSET(PaybackTable, m_nTotalWeight, 0x38);
MS2_CHECK_OFFSET(PaybackTable, m_bLocale, 0x3c);
