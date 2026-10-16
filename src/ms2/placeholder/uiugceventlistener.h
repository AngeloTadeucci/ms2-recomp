// uiugceventlistener.h - UIUGCEventListener: the 8-byte (vftable only) interface that UI classes derive from to receive
// UGC (user generated content) events (UIBlueprintMarketDialog, UIMyInfoDialog, UIRealEstateDialog, CGuideManager, SkillSlotBag, ...).
// RTTI .?AVUIUGCEventListener@@, vftable 0x142fecdd0, ctor 0x141b38b00, dtor 0x141b38b20 (virtual, scalar deleting 0x141b39290),
// 8 slots. Slots 1-7 are the empty inline stubs at 0x140bc0a70-0x140bc0b00 / 0x1413391e0 (signatures from the /Od parameter
// homing: slots 1 and 2 take a pointer-sized value plus a CString by value, which the stub destroys).
// Derived classes bind the base ctor/dtor through progress/symbols.tsv.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"

class UIUGCEventListener
{
public:
    UIUGCEventListener();                           // 0x141b38b00
    virtual ~UIUGCEventListener();                  // 0x141b38b20 (scalar deleting 0x141b39290)

    virtual void vfunc_ugc_1(void*, CString) {}         // 1  0x140bc0ab0
    virtual void vfunc_ugc_2(void*, CString) {}         // 2  0x140bc0a80
    virtual void vfunc_ugc_3(void*, void*) {}           // 3  0x1413391e0
    virtual void vfunc_ugc_4(int) {}                    // 4  0x140bc0ae0
    virtual void vfunc_ugc_5() {}                       // 5  0x140bc0a70
    virtual void vfunc_ugc_6() {}                       // 6  0x140bc0af0
    virtual void vfunc_ugc_7(int) {}                    // 7  0x140bc0b00
};
MS2_CHECK_SIZE(UIUGCEventListener, 0x8);
