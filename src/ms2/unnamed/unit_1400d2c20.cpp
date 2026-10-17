// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The .text$di tail of ?\itemscrollslot.cpp: the dynamic
// initializer of ItemScrollSlot::ms_ClassInfo, the efd RTTI descriptor a MS2DragSlot-derived slot registers itself
// with (id 0x6200034, parent MS2DragSlot - its SetupClassInfo is 0x140d43060 and sits in the TU's own code unit at
// 0x140d42540).
// MS2-UNIT: ?\itemscrollslot.cpp
// MS2-RANGE: 0x1400d2c20-0x1400d2c40 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemscrollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/ms2dragslot.h"

// 0x6200034, parent MS2DragSlot (its SetupClassInfo 0x140a36a10 is called with offset 0).
class ItemScrollSlot : public MS2DragSlot
{
public:
    EE_DECLARE_CLASS1(ItemScrollSlot, 0x06200034, MS2DragSlot);
};

EE_IMPLEMENT_CONCRETE_CLASS_INFO(ItemScrollSlot);
