// cmypckeyinputcontroller.h - PLACEHOLDER for UICommon::CMyPCKeyInputController (RTTI, 72 bytes, vftable
// 0x142f9cae8, ctor 0x141900de0, dtor 0x141900e70). NOT an original header.
//
// It tracks which UI layers currently block one input channel of the player character: three sets of layer ids
// (+0x08 movement, +0x18 skills, +0x28 attacks) and, per set, the count of blocking layers (+0x38 / +0x3c / +0x40).
// The members are completed by client\ms2\uicommon.cpp, which owns the ctor, the dtor and the FUN_ helpers.
#pragma once

#include <set>

#include "ms2/ms2layout.h"

namespace UICommon {

class CMyPCKeyInputController
{
public:
    CMyPCKeyInputController();                                  // 0x141900de0
    virtual ~CMyPCKeyInputController();                         // 0x141900e70 (??_G 0x141904a30)

    int FUN_141900ed0(int nRelease, int* pCount, int nDefault); // count the blocking layers; the default while none block
    void FUN_141900f70(int nRelease, int nLayer);               // skill channel
    void FUN_141900ff0(int nRelease, int nLayer);               // attack channel
    void FUN_141901070(int nRelease, int nLayer);               // movement channel
    int FUN_141901170(int nRelease, int nLayer, std::set<int>* pSet);   // add / remove the layer; 1 when the set changed
    void FUN_1419012a0();                                       // forget all layers

private:
    MS2_LAYOUT_FRIEND;
    std::set<int> m_move;                                       // +0x08
    std::set<int> m_skill;                                      // +0x18
    std::set<int> m_attack;                                     // +0x28
    int m_nMove;                                                // +0x38
    int m_nSkill;                                               // +0x3c
    int m_nAttack;                                              // +0x40
};
MS2_CHECK_SIZE(CMyPCKeyInputController, 0x48);

}  // namespace UICommon
