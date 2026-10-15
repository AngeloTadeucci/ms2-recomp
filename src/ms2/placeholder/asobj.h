// asobj.h - PLACEHOLDER for ASObj and ASArray. NOT an original header.
// ASObj: an AS object created on the C++ side (AScript itself with type 2; ctor 0x1422ba6e0, dtor 0x1422ba860), 0x40 bytes.
// ASArray: the AS array derived from it (ctor 0x1422bbb50, dtor 0x1422bbc30). The Set helpers are COMDAT template
// instances (one per value type). Units must include this header instead of redefining the classes.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class ASObj : public AScript
{
public:
    ASObj(int nType);
    virtual ~ASObj();
    void FUN_1407cbbe0(const char* szName, bool b);                      // set a bool member
    void FUN_1407cba60(const char* szName, CString str);                 // set a string member
    void FUN_1407cbb20(const char* szName, CStringW str);                // set a wide string member
    void FUN_1407cb9c0(const char* szName, int n);                       // set an int member
    void FUN_1409c0d20(const char* szName, unsigned int n);              // set an unsigned member
    void FUN_1409adbe0(const char* szName, Scaleform::GFx::Value v);     // set a member to a value
};
MS2_CHECK_SIZE(ASObj, 0x40);

class ASArray : public ASObj
{
public:
    ASArray(int nType);
    virtual ~ASArray();
    bool FUN_1422bc050(Scaleform::GFx::Value v);                         // push
};
