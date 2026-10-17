// gameeventuservaluenametable.h - GameEventUserValueNameTable (RTTI .?AVGameEventUserValueNameTable@@, 0x50 bytes:
// ??_G 0x140421bc0 frees 0x50). NOT an original header.
// Bases: TSingleton<GameEventUserValueNameTable> at +0x0 (s_instance 0x143aaedf8), vftable 0x142d45e70.
// Maps the xml user value type names of the game events to their ids (commonfiles\gameeventuservaluenametable.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

// The user value ids (the map's value type is an enum: SetAt takes it by const reference, GetId converts it to int).
enum Unk_GameEventUserValueType
{
    eGameEventUserValue_None = 0,
    eGameEventUserValue_IsReturnUser = 320,
};

class GameEventUserValueNameTable : public TSingleton<GameEventUserValueNameTable>
{
public:
    GameEventUserValueNameTable();                          // 0x140421740
    virtual ~GameEventUserValueNameTable();                 // 0x1404217d0
    int GetId(CStringW strName);                            // 0x140421810: 0 (and an assert) for an unknown name
private:
    void Init();                                            // 0x1404218e0: registers the known names
    MS2_LAYOUT_FRIEND;
    ATL::CAtlMap<CStringW, Unk_GameEventUserValueType, ATL::CStringElementTraitsI<CStringW> > m_ids; // +0x8
};
MS2_CHECK_SIZE(GameEventUserValueNameTable, 0x50);
