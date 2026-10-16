// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Adventure level table, its singleton helper and mission rows.
// MS2-UNIT: ?\adventureleveltablehelper.cpp
// MS2-RANGE: 0x140195470-0x1401a2e40 .text$mn
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$TSingleton@VCAdventureLevelTable@@@@@ 0x142ceb9b8
// MS2-PIN: ??_7CAdventureLevelTable@@6B?$CValidData@VCAdventureLevelTable@@@@@ 0x142ceb9e8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\adventureleveltablehelper.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "adventureleveltablehelper.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Container glue of CAdventureLevelTable (element types unrecovered): each takes the member address and returns it.
void* FUN_14019c500(void* p);
void* FUN_14019c4d0(void* p);
void* FUN_140182ed0(void* p);
void* FUN_14019c4a0(void* p);
void* FUN_14019c440(void* p);
void* FUN_14019c470(void* p);
void FUN_14019c770(void* p);
void FUN_14019c750(void* p);
void FUN_140183b90(void* p);
void FUN_14019c790(void* p);
void FUN_14019c7b0(void* p);
void FUN_14019c7d0(void* p);

// @0x140195470
CAdventureLevelTableHelper::CAdventureLevelTableHelper()
{
    m_pCurrent = 0;
}

// @0x1401954b0
CAdventureLevelTableHelper::~CAdventureLevelTableHelper()
{
}

// @0x140195660
CAdventureLevelMissionData::CAdventureLevelMissionData()
{
    m_nId = 0;
    m_b1c = false;
    m_p20 = 0;
}

// @0x140195700
// MS2-FUNCTIONAL: exe calls CPtred::~CPtred directly without storing the vptr; implicit dtor stores it
CAdventureLevelMissionData::~CAdventureLevelMissionData()
{
}

// @0x140195b80
// MS2-FUNCTIONAL: members are real containers in the exe (EH unwind states 8); here opaque storage + FUN_ glue
CAdventureLevelTable::CAdventureLevelTable()
{
    FUN_14019c500(m_c10);
    FUN_14019c4d0(m_c20);
    FUN_140182ed0(m_c30);
    FUN_14019c4a0(m_c48);
    FUN_140182ed0(m_c58);
    FUN_14019c440(m_c70);
    FUN_14019c470(m_c80);
}

// @0x140195c60
// MS2-FUNCTIONAL: members are real containers in the exe (EH unwind states 8); here opaque storage + FUN_ glue
CAdventureLevelTable::~CAdventureLevelTable()
{
    FUN_14019c770(m_c80);
    FUN_14019c750(m_c70);
    FUN_140183b90(m_c58);
    FUN_14019c790(m_c48);
    FUN_140183b90(m_c30);
    FUN_14019c7b0(m_c20);
    FUN_14019c7d0(m_c10);
}

MS2_EMIT_CRT_MEMMOVE_S();
