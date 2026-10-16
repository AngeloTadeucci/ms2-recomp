// uidialogeventlistener.h - PLACEHOLDER for UIDialogEventListener (RTTI .?AVUIDialogEventListener@@), the 8-byte
// (vftable only) listener base that UI dialogs list as a secondary base at +0x178 (UIGameMenuDialog, UIFittingDollDialog,
// UITradeDialogEx, UIManufactureDialog, UITencentAas2Dialog, ...). NOT an original header. Owning unit
// ?\uidialogeventlistener.cpp (0x141927f70-0x141928c80, unrecovered; it also holds UIDialogEventDispatcher): ctor
// 0x141927f70, dtor 0x141927f90 (virtual). 5 slots: slots 1 and 2 are the empty stubs at 0x140e99b00 / 0x140e99af0
// (they home one 32-bit argument), slots 3 and 4 the ones at 0x140e99b20 / 0x140e99b10 (they home one pointer).
// Derived classes bind the base ctor/dtor through progress/symbols-manual.tsv. Slot names are vfunc_dl_<slot> (not the Ghidra
// vfunc_o178_<slot>: those collide with UIQuestEventListener).
#pragma once

#include "ms2/ms2layout.h"

class UIDialogEventListener
{
public:
    UIDialogEventListener();                        // 0x141927f70
    virtual ~UIDialogEventListener();               // 0x141927f90
    virtual void vfunc_dl_1(int) {}               // 1 0x140e99b00
    virtual void vfunc_dl_2(int) {}               // 2 0x140e99af0
    virtual void vfunc_dl_3(void*) {}             // 3 0x140e99b20
    virtual void vfunc_dl_4(void*) {}             // 4 0x140e99b10
};
MS2_CHECK_SIZE(UIDialogEventListener, 8);
