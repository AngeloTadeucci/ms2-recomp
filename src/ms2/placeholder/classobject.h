// classobject.h - PLACEHOLDER for ClassObject (RTTI .?AVClassObject@@): the CPtred-derived base of the client's
// XML-loaded script objects (TriggerActionCli, TriggerConditionCli, ...). The owning unit ?\classobject.cpp
// (ctor 0x1401f7ee0, dtor 0x1401f7f20, vftable 0x142cf1398: slot 0 deleting dtor 0x1401f8220, slot 1 0x1401f8450 =
// CStringW class name) is not recovered yet; this declares only what derived units need. NOT an original header.
#pragma once

#include <atlstr.h>
#include "ms2/placeholder/cptred.h"

class ClassObject : public CPtred
{
public:
    ClassObject();                          // 0x1401f7ee0
    virtual ~ClassObject();                 // 0x1401f7f20 (slot 0)
    virtual CStringW vfunc_1();             // slot 1 0x1401f8450: the class name
};
MS2_CHECK_SIZE(ClassObject, 0x18);
