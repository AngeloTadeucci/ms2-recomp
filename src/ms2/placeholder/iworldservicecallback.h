// iworldservicecallback.h - PLACEHOLDER for IWorldServiceCallback (RTTI name; vftable 0x142dc3a78, 8 slots, ctor
// 0x140a15fc0, empty virtuals 0x140a184c0..0x140a18550). NOT an original header. All slot bodies are empty in the
// exe; the parameter lists are inferred from the stack homes the empty bodies spill (slot 2 takes a CString by value).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"

class IWorldServiceCallback
{
public:
    IWorldServiceCallback() noexcept {}                            // 0x140a15fc0
    virtual void vfunc_0(int) {}                            // 0x140a184c0
    virtual void vfunc_1(int) {}                            // 0x140a184d0
    virtual void vfunc_2(int, CString) {}                   // 0x140a184f0
    virtual void vfunc_3(int) {}                            // 0x140a18530
    virtual void vfunc_4(int) {}                            // 0x140a18540
    virtual void vfunc_5(int) {}                            // 0x140a184e0
    virtual void vfunc_6(int) {}                            // 0x140a18550
    virtual void vfunc_7(int) {}                            // 0x140a18520
};
MS2_CHECK_SIZE(IWorldServiceCallback, 0x8);
