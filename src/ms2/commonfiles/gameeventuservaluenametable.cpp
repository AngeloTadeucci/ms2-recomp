// gameeventuservaluenametable.cpp - GameEventUserValueNameTable: the name -> id table of the game event user values.
//
// MS2-UNIT: commonfiles\gameeventuservaluenametable.cpp
// MS2-RANGE: 0x140421740-0x140422c00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventuservaluenametable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/gameeventuservaluenametable.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140421740
GameEventUserValueNameTable::GameEventUserValueNameTable()
{
    Init();
}
// @0x1404217d0
GameEventUserValueNameTable::~GameEventUserValueNameTable() {}
// @0x140421810
int GameEventUserValueNameTable::GetId(CStringW strName)
{
    Unk_GameEventUserValueType id = eGameEventUserValue_None;
    if (strName.IsEmpty())
        return 0;
    if (m_ids.Lookup(strName, id))
        return id;
    MS2_ASSERT_AT(0x18, 0);
    return 0;
}
MS2_REPLACE_METHOD(0x140421810, GameEventUserValueNameTable, GetId, 201, 0x0A5184B2);
// @0x1404218e0
void GameEventUserValueNameTable::Init()
{
    m_ids.SetAt(L"IsReturnUser", eGameEventUserValue_IsReturnUser);
}

MS2_EMIT_CRT_MEMMOVE_S();
