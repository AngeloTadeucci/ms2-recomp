// statespawn.h - StateSpawn: the actor state that plays the spawn animation / effect of an actor that has just appeared
// (the StateSpawnData payload names the animation). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit
// is `?\statespawn.cpp` (0x1417f6050-0x1417f67b0 .text$mn, dir client\ms2). Header name assumed; member names invented
// from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"                  // State / StateData
#include "ms2/placeholder/timer.h"                  // Timer
#include "ms2/client/ms2/statedata.h"               // StateSpawnData

// 0x90. m_timer is armed with a random 100..399 ms delay on entry; when it fires the spawn animation starts, the
// mount's spawn effect is preloaded and m_fDuration (the animation length) is read; once m_fElapsed reaches it the
// owner leaves for state 1.
class StateSpawn : public State
{
public:
    StateSpawn(PCBase* pOwner);                                                         // 0x1417f6050
    ~StateSpawn();                                                                      // 0x1417f60e0
    int vfunc_1();                                                                      // 0x1417f67a0: 0x11
    void vfunc_3(double fTime);                                                         // 0x1417f62f0
    void vfunc_4(StateData* pData);                                                     // 0x1417f6140
    void vfunc_5(int n);                                                                // 0x1417f6260
    void vfunc_9(double fTime);                                                         // 0x1417f6680
    int vfunc_15();                                                                     // 0x1417f6790: 1

    float m_fElapsed;                                                                   // +0x40
    float m_fDuration;                                                                  // +0x44 spawn animation length
    Timer m_timer;                                                                      // +0x48
    MS2Ptr<StateSpawnData> m_spSpawn;                                                   // +0x80
};
MS2_CHECK_SIZE(StateSpawn, 0x90);
