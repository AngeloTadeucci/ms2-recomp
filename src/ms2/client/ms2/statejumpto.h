// statejumpto.h - StateJumpTo (type 7): the actor state of a scripted jump to a target position. It plays a ballistic
// arc (CArcController) from the actor's position to StateJumpToData::m_pos, turns the actor toward the target and, on
// landing, enters the landing state (StateLand with "Jump_Land_A") or falls back to the jump animations. Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\statejumpto.cpp` (0x1417d6c00-0x1417d79e0 .text$mn, dir
// client\ms2). Header name assumed; member names invented from their use.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/state.h"
#include "ms2/placeholder/ascript.h"
#include <NiSmartPointer.h>

class CArcController;
class StateJumpToData;

// 0x68.
class StateJumpTo : public State
{
public:
    StateJumpTo(PCBase* pOwner);                            // 0x1417d6c00
    virtual ~StateJumpTo();                                 // 0x1417d6cb0 (??_G 0x1417d7770)
    virtual int vfunc_1();                                  // 1  0x1417d77b0: 7
    virtual void vfunc_3(double fTime);                     // 3  0x1417d7090 (advance the arc, move the actor)
    virtual void vfunc_4(StateData* pData);                 // 4  0x1417d6d00 (enter: start the arc)
    virtual void vfunc_5(int n);                            // 5  0x1417d6f80 (leave)
    virtual void vfunc_9(double fTime);                     // 9  0x1417d7230 (play the jump / land animation)
    virtual void EndOfSequence(NiActorManager* pkManager, unsigned int eSequenceID,
        NiControllerSequence* pkSeq, float fEventTime);     // 13 0x1417d74a0

    NiPointer<CArcController> m_spArc;                      // +0x40
    int m_n48;                                              // +0x48 the rising animation has ended
    int m_nRiseAnim;                                        // +0x4c animation slot of the jump (4 or 0x2a)
    int m_nFallAnim;                                        // +0x50 animation slot of the fall (2 or 0x2b)
    int m_nPad54;                                           // +0x54
    MS2Ptr<StateJumpToData> m_spJump;                       // +0x58
};
MS2_CHECK_SIZE(StateJumpTo, 0x68);
MS2_CHECK_OFFSET(StateJumpTo, m_spArc, 0x40);
MS2_CHECK_OFFSET(StateJumpTo, m_spJump, 0x58);
