// statetransform.h - StateTransform (type 0x22) and StateTransformDoll (type 0x22 as well): the actor states of a
// player being fitted / transformed (plays the mantle change animation and the "Eff_FittingDoll" effect). Recovered
// from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statetransform.cpp` (0x1417fe410-0x1417fea70
// .text$mn, dir client\ms2). Header name assumed; names invented from use.
//   StateTransform: ends (back to idle) when the animation ends. StateTransformDoll: ends after one second.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

class NiActorManager;
class NiControllerSequence;

// 0x48.
class StateTransform : public State
{
public:
    StateTransform(PCBase* pOwner);                         // 0x1417fe410
    virtual ~StateTransform();                              // 0x1417fe460 (??_G 0x1417fe9d0)
    virtual int vfunc_1();                                  // 1  0x1417fea50: 0x22
    virtual void vfunc_3(double fTime);                     // 3  0x1417fe640
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417fe4d0 (enter: effect + animation)
    virtual void vfunc_5(int n);                            // 5  0x1417fe610
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417fe670 (stop the effect, back to idle)

    int m_nEffect;                                          // +0x40 effect id (0 = none)
    int m_nPad44;                                           // +0x44
};
MS2_CHECK_SIZE(StateTransform, 0x48);
MS2_CHECK_OFFSET(StateTransform, m_nEffect, 0x40);

// 0x48.
class StateTransformDoll : public State
{
public:
    StateTransformDoll(PCBase* pOwner);                     // 0x1417fe710
    virtual ~StateTransformDoll();                          // 0x1417fe770 (??_G 0x1417fea10)
    virtual int vfunc_1();                                  // 1  0x1417fea60: 0x22
    virtual void vfunc_3(double fTime);                     // 3  0x1417fe970 (ends when the end time passed)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417fe7e0 (enter: end time = now + 1 s)
    virtual void vfunc_5(int n);                            // 5  0x1417fe930 (stop the effect)

    int m_nEffect;                                          // +0x40 effect id
    unsigned m_nEndTime;                                    // +0x44 millisecond clock at which the state ends
};
MS2_CHECK_SIZE(StateTransformDoll, 0x48);
MS2_CHECK_OFFSET(StateTransformDoll, m_nEndTime, 0x44);
