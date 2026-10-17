// statefalldamage.h - StateFallDamage (type 0x1f): the actor state after taking fall damage (plays the hurt landing
// animation, then returns to idle). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\statefalldamage.cpp` (0x1417c7be0-0x1417c8240 .text$mn, dir client\ms2). Header name assumed.
#pragma once
#include <efd/utf8string.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

// 0x60. m_strAnim is the hurt animation (owner slot 123 name 0x3f), optionally prefixed by the ridee's record string.
class StateFallDamage : public State
{
public:
    StateFallDamage(PCBase* pOwner);                        // 0x1417c7be0
    virtual ~StateFallDamage();                             // 0x1417c7c50 (??_G 0x1417c81f0)
    virtual int vfunc_1();                                  // 1  0x1417c8230: 0x1f
    virtual void vfunc_3(double fTime);                     // 3  0x1417c7fb0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c7c90 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417c7f30 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417c8030
    virtual void vfunc_9(double fTime);                     // 9  0x1417c81c0 (base only)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c8150

    efd::utf8string m_strAnim;                              // +0x40
};
MS2_CHECK_SIZE(StateFallDamage, 0x60);
MS2_CHECK_OFFSET(StateFallDamage, m_strAnim, 0x40);
