// statepvpwinlose.h - StatePvPWinLose (type 0x28): the actor state that plays the PvP win/lose motion. The state is
// entered with a sub-type 0x73 (win) or 0x74 (lose) in the base State's +0x10; the motion name is built from the
// player's team-info value and the matching animation slot (0x41 for 0x73, 0x40 for 0x74), and the state leaves when
// that animation's sequence ends. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\statepvpwinlose.cpp` (0x141282440-0x141282a50 .text$mn, dir client\ms2). Header name assumed.
#pragma once
#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

// 0x40. No members beyond the base State (the sub-type lives in State::m_n10).
class StatePvPWinLose : public State
{
public:
    StatePvPWinLose(PCBase* pOwner);                        // 0x141282440
    virtual ~StatePvPWinLose();                             // 0x141282490
    virtual int vfunc_1();                                  // 1  0x1412827d0: 0x28
    virtual void vfunc_3(double fTime);                     // 3  0x141282670 (update tick)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1412824c0 (enter)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1412826f0
    virtual int vfunc_15();                                 // 15 0x1412827c0: 1
};
MS2_CHECK_SIZE(StatePvPWinLose, 0x40);
