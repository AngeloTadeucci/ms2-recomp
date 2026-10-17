// roomstagedungeoncli.h - PLACEHOLDER for RoomStageDungeonCli (RTTI name; its unit client\ms2\roomstagedungeoncli.cpp is
// not recovered). A CPtred-derived client dungeon room stage state (0x48 bytes, ctor out of line). Only what
// ?\notifydebugstate.cpp (CMyCharacter) touches is declared. NOT an original header.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class RoomStageDungeonCli : public CPtred
{
public:
    RoomStageDungeonCli(int nA, int nB);            // 0x140c9cc60
    void FUN_140c9ce60(bool bFlag);                 // 0x140c9ce60

private:
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0x30];
};
MS2_CHECK_SIZE(RoomStageDungeonCli, 0x48);
