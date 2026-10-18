// statedead.h - StateDead (type 0xc: a player's death), StateDeadNPC (type 0xc for an npc: death motion, corpse effect,
// exp reward) and StateRevival (type 0x18: the stand-up motion). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\statedead.cpp` (0x1417c24a0-0x1417c3780 .text$mn, dir client\ms2). NOT an original
// header (names assumed from the RTTI). All three derive State (ms2/placeholder/state.h); the npc payload is
// StateDeadNPCData (statedata.h).
// MS2-UNIT: ?\statedead.cpp
// MS2-RANGE: 0x1417c24a0-0x1417c3780 .text$mn
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

// 0x48. m_nEffect is the effect-manager handle of the death effect (0 = none).
class StateDead : public State
{
public:
    StateDead(PCBase* pOwner);                              // 0x1417c24a0
    virtual ~StateDead();                                   // 0  0x1417c2500 (??_G 0x1417c3440)
    virtual int vfunc_1();                                  // 1  0x1417c3520: 0xc
    virtual void vfunc_3(double fTime);                     // 3  0x1417c2a40
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c2530 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417c29b0 (leave)
    virtual void vfunc_23();                                // 23 0x1417c2ac0

    int m_nEffect;                                          // +0x40
    int m_n44;                                              // +0x44 (padding)
};
MS2_CHECK_SIZE(StateDead, 0x48);
MS2_CHECK_OFFSET(StateDead, m_nEffect, 0x40);

// 0x50. m_strAnim is the death motion that is playing.
class StateDeadNPC : public State
{
public:
    StateDeadNPC(PCBase* pOwner);                           // 0x1417c2b30
    virtual ~StateDeadNPC();                                // 0  0x1417c2bb0 (??_G 0x1417c3480)
    virtual int vfunc_1();                                  // 1  0x1417c3530: 0xc
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c2c30 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417c2f50 (leave)
    virtual void vfunc_6();                                 // 6  0x1417c2fa0 (hit while dead)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c3140
    virtual int vfunc_15();                                 // 15 0x1417c3500: 1

    CString m_strAnim;                                      // +0x40
    int m_nEffect;                                          // +0x48 corpse effect handle
    int m_bFinished;                                        // +0x4c the death motion has ended
};
MS2_CHECK_SIZE(StateDeadNPC, 0x50);
MS2_CHECK_OFFSET(StateDeadNPC, m_strAnim, 0x40);
MS2_CHECK_OFFSET(StateDeadNPC, m_nEffect, 0x48);
MS2_CHECK_OFFSET(StateDeadNPC, m_bFinished, 0x4c);

// 0x40.
class StateRevival : public State
{
public:
    StateRevival(PCBase* pOwner);                           // 0x1417c3220
    virtual ~StateRevival();                                // 0  0x1417c3270 (??_G 0x1417c34c0)
    virtual int vfunc_1();                                  // 1  0x1417c3540: 0x18
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417c32a0 (enter)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417c3350
    virtual int vfunc_15();                                 // 15 0x1417c3510: 1
};
MS2_CHECK_SIZE(StateRevival, 0x40);
