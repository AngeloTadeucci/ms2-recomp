// adventureleveltablehelper.h - CAdventureLevelTableHelper / CAdventureLevelTable / CAdventureLevelMissionData (RTTI names).
// Header name assumed. Member and helper names are invented from use; the table's containers (std::map / list glue
// at +0x10..+0x88) are not recovered yet and are kept as opaque storage.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

// One adventure-level mission row. 0x28 bytes (CPtred 0x18 + three fields).
class CAdventureLevelMissionData : public CPtred
{
public:
    CAdventureLevelMissionData();               // 0x140195660
    virtual ~CAdventureLevelMissionData();      // 0x140195700

    int m_nId;                                  // +0x18 (name invented)
    bool m_b1c;                                 // +0x1c
    void* m_p20;                                // +0x20
};
MS2_CHECK_SIZE(CAdventureLevelMissionData, 0x28);
MS2_CHECK_OFFSET(CAdventureLevelMissionData, m_p20, 0x20);

// Singleton wrapper over the table; +8 caches a pointer to the current level row.
class CAdventureLevelTableHelper : public TSingleton<CAdventureLevelTableHelper>
{
public:
    CAdventureLevelTableHelper();               // 0x140195470
    virtual ~CAdventureLevelTableHelper();      // 0x1401954b0

    void* m_pCurrent;                           // +0x08
};
MS2_CHECK_SIZE(CAdventureLevelTableHelper, 0x10);
MS2_CHECK_OFFSET(CAdventureLevelTableHelper, m_pCurrent, 0x08);

class CAdventureLevelTable : public TSingleton<CAdventureLevelTable>, public CValidData<CAdventureLevelTable>
{
public:
    CAdventureLevelTable();                     // 0x140195b80
    virtual ~CAdventureLevelTable();            // 0x140195c60

    char m_c10[0x10];                           // +0x10 container (FUN_14019bd90 / dtor FUN_14019c7d0)
    char m_c20[0x10];                           // +0x20 container (FUN_14019bd60 / dtor FUN_14019c7b0)
    char m_c30[0x18];                           // +0x30 container (FUN_140182830 / dtor FUN_14018ddf0)
    char m_c48[0x10];                           // +0x48 container (FUN_14019bd30 / dtor FUN_14019c5d0)
    char m_c58[0x18];                           // +0x58 container (FUN_140182830 / dtor FUN_14018ddf0)
    char m_c70[0x10];                           // +0x70 container (FUN_14019bcd0 / dtor FUN_14019c570)
    char m_c80[0x10];                           // +0x80 container (FUN_14019bd00 / dtor FUN_14019c5a0)
};
MS2_CHECK_SIZE(CAdventureLevelTable, 0x90);
MS2_CHECK_OFFSET(CAdventureLevelTable, m_c80, 0x80);
