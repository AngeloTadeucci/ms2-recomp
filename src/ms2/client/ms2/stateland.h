// stateland.h - StateLand (type 4): the actor state of a player touching the ground after a fall or jump (plays the
// landing animation, then returns to idle / walk). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit
// is `?\stateland.cpp` (0x1417d9c70-0x1417da7a0 .text$mn, dir client\ms2). Header name assumed.
// m_n10 is the landing kind: 0x86 normal, 0x87 when the actor is on the ground of a ridee.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/client/ms2/statedata.h"           // StateLandData

// 0x50.
class StateLand : public State
{
public:
    StateLand(PCBase* pOwner);                              // 0x1417d9c70
    virtual ~StateLand();                                   // 0x1417d9ce0 (??_G 0x1417da740)
    virtual int vfunc_1();                                  // 1  0x1417da790: 4
    virtual void vfunc_3(double fTime);                     // 3  0x1417da070
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d9d20 (enter)
    virtual void vfunc_8(double fTime);                     // 8  0x1417da0f0
    virtual void vfunc_9(double fTime);                     // 9  0x1417da290 (pick and play the landing animation)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417da580
    virtual int vfunc_15();                                 // 15 0x1417da780: 1

    MS2Ptr<StateLandData> m_spLand;                         // +0x40 the requested animation name
};
MS2_CHECK_SIZE(StateLand, 0x50);
MS2_CHECK_OFFSET(StateLand, m_spLand, 0x40);
