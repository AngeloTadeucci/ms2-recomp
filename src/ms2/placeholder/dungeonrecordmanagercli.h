// dungeonrecordmanagercli.h - PLACEHOLDER for DungeonRecordManagerCli (RTTI name; its unit client\ms2\dungeonrecordcli.cpp
// is not recovered). A CPtred-derived client record manager (0xa8 bytes, ctor out of line). Only what
// ?\notifydebugstate.cpp (CMyCharacter) touches is declared. NOT an original header.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class DungeonRecordManagerCli : public CPtred
{
public:
    DungeonRecordManagerCli();                      // out of line (dungeonrecordcli.cpp)
    void FUN_140b20ba0();                           // 0x140b20ba0, reset

private:
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0x90];
};
MS2_CHECK_SIZE(DungeonRecordManagerCli, 0xa8);
