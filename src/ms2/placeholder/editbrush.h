// editbrush.h - PLACEHOLDER for the deco-edit brush classes (RTTI EditBrush / PaintBrush / NoiseBrush). NOT an
// original header. Owning unit: ?\editbrush.cpp (0x141197280-0x141198810, not recovered yet); DecoEditService
// (decoeditservice.cpp) only creates the two concrete brushes, keeps them in a CAtlMap<int, MS2Ptr<EditBrush>> and
// drives them through the virtual slots below. Slot names are invented from that use.
//
// vftables: EditBrush 0x142eb9100, PaintBrush 0x142eb9158, NoiseBrush 0x142eb91b0 (10 slots each; slot 0 is the
// deleting dtor). Sizes: EditBrush 0x78 (ctor 0x141197280; Timer at +0x40), PaintBrush 0x88 (ctor 0x141197500),
// NoiseBrush 0x98 (ctor 0x141197a50). The two concrete ctors are out of line in the owning unit.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/nipoint3.h"

class EditBrush : public CPtred
{
public:
    virtual ~EditBrush();                   // 0
    virtual void vfunc_1();                 // 1  brush deselected
    virtual void vfunc_2();                 // 2  apply at the current point
    virtual void vfunc_3();                 // 3  brush selected
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    void FUN_1411974a0(Unk_StreamPoint pt);          // 0x1411974a0 sets the brush point (+0x28)
    char m_pad_18[0x78 - 0x18];
};
MS2_CHECK_SIZE(EditBrush, 0x78);

class PaintBrush : public EditBrush
{
public:
    PaintBrush();                           // 0x141197500
    char m_pad_78[0x88 - 0x78];
};
MS2_CHECK_SIZE(PaintBrush, 0x88);

class NoiseBrush : public EditBrush
{
public:
    NoiseBrush();                           // 0x141197a50
    char m_pad_78[0x98 - 0x78];
};
MS2_CHECK_SIZE(NoiseBrush, 0x98);
