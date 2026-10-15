// asdata.h - PLACEHOLDER for ASData and ASArgList, the ActionScript call argument containers. NOT an original header.
//
// ASData: RTTI .?AVASData@@, vftable 0x143109b30, base CPtred, ctor 0x1422b7f20, dtor 0x1406147b0. 0x48 bytes: an
// array of GFx values at +0x18 (ctor 0x1422b96a0: 5 pointers + an int, padded to 0x30). UIMsg (0x50) derives and adds an
// int at +0x48. The size is load-bearing: /Od orders the frame slots by size and use count, so a 0x50 ASData swaps the
// slots of the by-value MS2Ptr copies in the dialogs' vfunc_28 (RECOVERY.md section 8, "Frame slots in the wrong order").
//
// ASArgList: the argument list of AScript::Invoke (a PodArray<Value>, 32 bytes; ctor 0x1409b1e80, dtor 0x1409b1f20).
//
// Declared: the union of the FUN_ methods the units use. Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

class ASData : public CPtred
{
public:
    ASData();
    virtual ~ASData();
    int FUN_1422b9620(const Scaleform::GFx::Value* pArgs, unsigned int nArgs);    // copy the arguments in
    int FUN_1422b8b10();                                                            // first argument as int
    int FUN_1422b8a10();                                                            // result code (first argument as int)
    CString FUN_1422b8d30();                                                        // first argument as a string
    CStringW FUN_1422b8f40();                                                       // first argument as a wide string
    void FUN_1422b8310(const wchar_t* sz);
    void FUN_1422b8370(size_t n);
    Scaleform::GFx::Value FUN_1422b9260();

private:
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40;
};
MS2_CHECK_SIZE(ASData, 0x48);

class ASArgList
{
public:
    ASArgList();
    ~ASArgList();
    void FUN_1409b2800(int nCount);                                      // resize
    Scaleform::GFx::Value* FUN_1409b1f70(int nIndex);                    // operator[]

private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18;
};
MS2_CHECK_SIZE(ASArgList, 0x20);
