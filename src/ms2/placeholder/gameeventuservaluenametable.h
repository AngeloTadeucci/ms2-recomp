// gameeventuservaluenametable.h - PLACEHOLDER for GameEventUserValueNameTable (RTTI .?AVGameEventUserValueNameTable@@,
// 0x50 bytes: ??_G 0x140421bc0 frees 0x50). NOT an original header.
// Bases: TSingleton<GameEventUserValueNameTable> at +0x0 (s_instance 0x143aaedf8), vftable 0x142d45e70.
// The member at +0x8 is a CAtlMap (ctor args 17, 0.75, 0.25, 2.25, 10) whose key/value types are not recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class GameEventUserValueNameTable : public TSingleton<GameEventUserValueNameTable>
{
public:
    GameEventUserValueNameTable();                          // 0x140421740
    virtual ~GameEventUserValueNameTable();                 // 0x1404217d0
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x50 - 0x8];
};
MS2_CHECK_SIZE(GameEventUserValueNameTable, 0x50);
