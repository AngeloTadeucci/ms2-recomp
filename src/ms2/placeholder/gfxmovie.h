// gfxmovie.h - PLACEHOLDER for GFxMovie and GFxMovieEventHandler, the bases of the Scaleform movie wrappers
// (GFxMovieBackground/Damage/Ugc/Main/Tooltip/MouseCursor/HeadUpDisplay/PostDisplay). NOT an original header; the
// out-of-line members live in the GFx UI library (0x1422b0000-0x142304000, no unit recovered yet) and are bound through
// progress/symbols-manual.tsv. Slot names are Ghidra's (vfunc_<slot>); signatures from the /Od prologues
// (work/uibase/slotsig.py) and the base bodies' decompiles.
//
// GFxMovie : NiRefObject, 0x80 bytes. RTTI .?AVGFxMovie@@, vftable 0x14310aa60 (16 slots), ctor 0x1422bced0, dtor 0x1422bcfe0
// (scalar deleting 0x1422bf490). Wraps a loaded GFx movie: the Ptr<GFx::Movie> at +0x60 is what the slots call through
// (vtable +0x58 SetViewport, +0x100 SetVisible?, +0x110 HandleEvent, ...).
// GFxMovieEventHandler : GFxMovie, 0x90 bytes. vftable 0x143112638 (40 slots: the Win32 input messages -> GFx events),
// ctor 0x1422d8dc0, dtor 0x1422d8e20 (scalar deleting 0x1422db0b0).
// Derived classes start at 0x90.
#pragma once

#include <afx.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"

class GFxMovie : public NiRefObject
{
public:
    GFxMovie();                                                     // 0x1422bced0
    virtual ~GFxMovie();                                            //  0 0x1422bcfe0 (scalar deleting 0x1422bf490)
    // 1 = NiRefObject::DeleteThis (0x141d16bf0)
    virtual void* vfunc_2();                                        //  2 0x1422bf590 returns &DAT_143b0ae40 (a static descriptor)
    virtual void vfunc_3(void*, void*, int);                        //  3 0x1422bd350 (empty)
    virtual void vfunc_4(void*, void*, void*);                      //  4 0x1422bd370 (empty)
    virtual void vfunc_5(bool);                                     //  5 0x1422bd390 movie slot +0x40(!b)
    virtual int vfunc_6(void*, void*, int);                         //  6 0x1422bd3f0
    virtual int vfunc_7(int x, int y);                              //  7 0x1422bd880 returns 1; sends a mouse-move event
    virtual void vfunc_8(float fTime);                              //  8 0x1422bda00 advance
    virtual void vfunc_9(void*, void*);                             //  9 0x1422bdb90
    virtual void vfunc_10(void*, void*);                            // 10 0x1422bdc50
    virtual void vfunc_11();                                        // 11 0x1422bdd20 release the movie handles
    virtual void vfunc_12();                                        // 12 0x1422bddd0 (empty)
    virtual bool vfunc_13();                                        // 13 0x1422bdde0 returns true
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422bddf0 returns 0
    virtual bool vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);  // 15 0x1422bde10 returns 0

    // 0x10..0x80, ctor 0x1422bced0 (the handle types are unrecovered: ctor/dtor wrappers FUN_1422b31e0/b31a0/b31c0/bea60/beaa0)
    int m_10;                                                       // +0x10 ctor 0
    float m_14;                                                     // +0x14 ctor 1.0f
    int m_18;                                                       // +0x18 not set by the ctor (derived classes store 4)
    int m_pad_1c;
    void* m_20[2];                                                  // +0x20 16-byte handle
    void* m_30[2];                                                  // +0x30 16-byte handle
    void* m_40[2];                                                  // +0x40 16-byte handle
    int m_50;                                                       // +0x50 ctor 0
    int m_54;                                                       // +0x54 (ctor FUN_14127c3b0)
    void* m_58;                                                     // +0x58 ctor 0
    void* m_60;                                                     // +0x60 Ptr<GFx::Movie> (accessor FUN_14127c960 / FUN_14127c910 = non-null)
    void* m_68;                                                     // +0x68 handle
    void* m_70;                                                     // +0x70 ctor 0
    void* m_78;                                                     // +0x78 ctor 0
};
MS2_CHECK_SIZE(GFxMovie, 0x80);
MS2_CHECK_OFFSET(GFxMovie, m_20, 0x20);
MS2_CHECK_OFFSET(GFxMovie, m_60, 0x60);
MS2_CHECK_OFFSET(GFxMovie, m_78, 0x78);

class GFxMovieEventHandler : public GFxMovie
{
public:
    GFxMovieEventHandler();                                         // 0x1422d8dc0
    virtual ~GFxMovieEventHandler();                                //  0 0x1422d8e20 (scalar deleting 0x1422db0b0)
    virtual void* vfunc_2();                                        //  2 0x1422db110 returns &DAT_143b0d2e0
    virtual void vfunc_11();                                        // 11 0x1422d9f50 GFxMovie::vfunc_11 + FUN_1422d8f90(this, m_88)
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422d9040 the WM_ switch
    virtual bool vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);  // 15 0x1422d9c30
    virtual void vfunc_16();                                        // 16 0x1422d9db0
    virtual void vfunc_17();                                        // 17 0x1422d9e60
    virtual void vfunc_18();                                        // 18 0x1422d9ef0
    virtual void vfunc_19(void*);                                   // 19 0x1422d9f90 (empty)
    virtual void vfunc_20(void*);                                   // 20 0x1422d9fb0 (empty)
    virtual void vfunc_21(void*);                                   // 21 0x1422d9fd0 vfunc_19; m_80 = GetTickCount()
    virtual void vfunc_22(void*);                                   // 22 0x1422da020 vfunc_20
    virtual void vfunc_23(void*);                                   // 23 0x1422da060 vfunc_20
    virtual void vfunc_24(void* hwnd);                              // 24 0x1422da0a0 paste from the clipboard
    virtual void vfunc_25(void* hwnd, unsigned __int64 wParam, __int64 lParam);   // 25 0x1422da150 WM_DRAWCLIPBOARD chain
    virtual void vfunc_26(void* hwnd, float x, float y);            // 26 0x1422da1e0 mouse move (TrackMouseEvent)
    virtual void vfunc_27(void* hwnd, float x, float y);            // 27 0x1422da2e0 (empty)
    virtual void vfunc_28(void* hwnd, float x, float y);            // 28 0x1422da300 vfunc_20
    virtual void vfunc_29(void* hwnd, float x, float y);            // 29 0x1422da340 (empty)
    virtual void vfunc_30(void* hwnd, float x, float y, int n);     // 30 0x1422da360 mouse wheel
    virtual void vfunc_31(void* hwnd, float x, float y);            // 31 0x1422da420
    virtual void vfunc_32(void* hwnd, float x, float y);            // 32 0x1422da4e0
    virtual void vfunc_33(void* hwnd, float x, float y);            // 33 0x1422da5a0
    virtual void vfunc_34(void* hwnd, float x, float y);            // 34 0x1422da660
    virtual void vfunc_35(void* hwnd, float x, float y);            // 35 0x1422da720
    virtual void vfunc_36(void* hwnd, float x, float y);            // 36 0x1422da7e0
    virtual bool vfunc_37(void* hwnd, int n, void* a, void* b);     // 37 0x1422da8a0 key event
    virtual int vfunc_38(void* hwnd, int n, unsigned __int64 a, unsigned __int64 b);   // 38 0x1422da960
    virtual void vfunc_39(int a, int b, int c, bool d, bool e);     // 39 0x1422daa40

    unsigned m_80;                                                  // +0x80 tick count of the last input
    int m_84;                                                       // +0x84 mouse-tracking flag
    void* m_88;                                                     // +0x88 an HWND
};
MS2_CHECK_SIZE(GFxMovieEventHandler, 0x90);
MS2_CHECK_OFFSET(GFxMovieEventHandler, m_88, 0x88);
