// heademotionaction.h - CHeadEmotionAction (RTTI .?AVCHeadEmotionAction@@, vftable 0x142f0c438, 0x38 bytes, base
// CPtred). NOT an original header (name from the exe's RTTI, layout from the scalar deleting dtor size 0x38). A head
// action that looks up a PC by object id and releases its +0xd88 pointer. Owning unit: ?\heademotionaction.cpp
// (0x1413f9290-0x1413f9810). The virtual destructor is the key function, so the vftable is emitted in the including unit.
#pragma once
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class Unk_PCD88;

class CHeadEmotionAction : public CPtred
{
public:
    CHeadEmotionAction(MS2Ptr<Unk_PCD88> spD88);        // 0x1413f9290
    virtual ~CHeadEmotionAction();                      // 0x1413f9300
    virtual bool vfunc_1(int nA, int nB, int nC);       // 0x1413f9340
    virtual void vfunc_2();                             // 0x1413f93b0
    virtual bool vfunc_3();                             // 0x1413f93c0
    virtual bool vfunc_4();                             // 0x1413f93d0
    virtual bool vfunc_5();                             // 0x1413f93e0
    virtual void vfunc_6(double f);                     // 0x1413f93f0 (float homed at entry)

    MS2_LAYOUT_FRIEND;
    int m_n18;                            // +0x18
    int m_n1c;                            // +0x1c
    int m_n20;                            // +0x20
    MS2Ptr<Unk_PCD88> m_spD88;            // +0x28
};
MS2_CHECK_SIZE(CHeadEmotionAction, 0x38);
MS2_CHECK_OFFSET(CHeadEmotionAction, m_n18, 0x18);
MS2_CHECK_OFFSET(CHeadEmotionAction, m_n1c, 0x1c);
MS2_CHECK_OFFSET(CHeadEmotionAction, m_n20, 0x20);
MS2_CHECK_OFFSET(CHeadEmotionAction, m_spD88, 0x28);
