// statestun.h - StateStun (type 0x12): the actor state of a stunned / knocked-down / frozen actor. m_n10 is the stun
// phase (0x3d..0x46: lying down, lie-keep, standing up, 0x40 frozen-ish, 0x41 stuck/riding, 0x42 snare, 0x43 vomit,
// 0x44 frozen, 0x45 stuck, 0x46 custom); the animation of a phase comes from one of three name tables (m_40, picked at
// random between the "A" and "B" lie animations) indexed by FUN_1417f7140. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); the unit is `?\statestun.cpp` (0x1417f67b0-0x1417f7550 .text$mn, 0x140104310-0x140104390 .text$di,
// dir client\ms2). Header name assumed; names invented from use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"

class NiActorManager;
class NiControllerSequence;

// 0x50.
class StateStun : public State
{
public:
    StateStun(PCBase* pOwner);                              // 0x1417f67b0
    virtual ~StateStun();                                   // 0  0x1417f6840 (??_G 0x1417f72b0)
    virtual int vfunc_1() { return 0x12; }                  // 1  0x1417f7300 (inline)
    virtual void vfunc_2(int n);                            // 2  0x1417f70c0 (change the phase)
    virtual void vfunc_3(double fTime);                     // 3  0x1417f6bd0
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417f6870 (enter)
    virtual void vfunc_5(int n);                            // 5  0x1417f6b70 (leave)
    virtual void vfunc_8(double fTime);                     // 8  0x1417f70a0 (empty)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417f6e60
    virtual bool vfunc_32() { return false; }               // 32 0x1417f7310 (inline)

    int FUN_1417f7140();                                    // the animation index of the phase
    static void FUN_1417f72f0(bool b) {}                    // 0x1417f72f0 (empty inline)

    const char** m_pAnims;              // +0x40 the animation name table (10 entries) of this stun
    int m_nKind;                        // +0x48 the stun kind (6 = the long one)
};
MS2_CHECK_SIZE(StateStun, 0x50);
MS2_CHECK_OFFSET(StateStun, m_pAnims, 0x40);
MS2_CHECK_OFFSET(StateStun, m_nKind, 0x48);
