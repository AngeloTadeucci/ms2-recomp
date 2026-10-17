// dungeonroomshutdowncontext.h - PLACEHOLDER for DungeonRoomShutdownContext (RTTI .?AVDungeonRoomShutdownContext@@,
// 0x38 bytes). NOT an original header.
// Bases: CPtred at +0x0.
// The context GameEventDungeonRoomShutdown (gameevent.cpp) builds from its two XML values; its unit
// ?\dungeonroomshutdowncontext.cpp (0x140343e50..) is not recovered, so only the members gameevent.cpp calls are
// declared and the two id sets stay opaque.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class DungeonRoomShutdownContext : public CPtred
{
public:
    DungeonRoomShutdownContext();                           // 0x140343e50
    virtual ~DungeonRoomShutdownContext();
    void FUN_140343eb0(const CStringW& strXml);             // <dungeonRoom id=..> elements into the room id set (+0x18)
    void FUN_140343fc0(const CStringW& strXml);             // <dungeonGroup type=..> elements into the group set (+0x28)
    bool FUN_1403441a0();                                   // true if either set is non-empty
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_18[0x20];
};
MS2_CHECK_SIZE(DungeonRoomShutdownContext, 0x38);
