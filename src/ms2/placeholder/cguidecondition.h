// cguidecondition.h - PLACEHOLDER for the guide-quest condition classes (RTTI .?AVCGuideCondition@@ and subclasses): the
// ClassObject-derived predicates the CGuideManager evaluates (a name factory per class, an XML loader in vfunc_2,
// the check in vfunc_3). The base lives in ?\guideentity.cpp (ctor 0x1413a54e0, dtor 0x1413a5540, vftable 0x142f05b80,
// slots 2..8 at 0x1413a5670..0x1413a5810, helper 0x1413a5600 / 0x1413a5820); the subclasses are spread over
// unit_1413a8370 / unit_1413a9a50 / unit_1413a9df0 (ctors 0x1413b2b30.., vftables, deleting dtors). NOT an original
// header; member names invented from their use. Append new subclasses here (layout proven from their ctors / operator new).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"

class Unk_140165cf0;

// 0x28. m_n18 is the condition kind (the subclass ctor/loader sets it), m_b1c negates the check, m_n20 is the XML "value".
class CGuideCondition : public ClassObject
{
public:
    CGuideCondition();                                      // 0x1413a54e0
    virtual ~CGuideCondition();                             // 0 0x1413a5540
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a5670: "value" / negate attributes
    virtual int vfunc_3();                                  // 3 0x1413a56d0: 0
    virtual void vfunc_4();                                 // 4 0x1413a56e0
    virtual void vfunc_5();                                 // 5 0x1413a56f0: logs "Nothing TestCase"
    virtual bool vfunc_6();                                 // 6 0x1413a5740: false
    virtual CStringW vfunc_7();                       // 7 0x1413a5760: description
    virtual int vfunc_8();                                  // 8 0x1413a5810: 0

    int FUN_1413a5600(bool bResult);
    int FUN_1413a55a0(int nResult);                         // 0x1413a55a0 like FUN_1413a5600 for an int result (negated when m_b1c)
    CStringW FUN_1413a5820();                                // 0x1413a5820    // 0x1413a5820 the base description text                        // 0x1413a5600 applies m_b1c (negation) to a check result

    int m_n18;                                              // +0x18
    bool m_b1c;                                             // +0x1c
    int m_n20;                                              // +0x20
};
MS2_CHECK_SIZE(CGuideCondition, 0x28);

// 0x30. Passes while the current map id equals m_n20 or lies in [m_nRangeBeg, m_nRangeEnd].
class CGuideConditionFieldId : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a9bc0
    CGuideConditionFieldId();                               // 0x1413b2cf0
    virtual CStringW vfunc_1();                             // 1 0x1413a9c20
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a9c70
    virtual int vfunc_3();                                  // 3 0x1413a9d40

    int m_nRangeBeg;                                        // +0x28
    int m_nRangeEnd;                                        // +0x2c
};
MS2_CHECK_SIZE(CGuideConditionFieldId, 0x30);

// 0x38. Counts the inventory items of one type (m_nItemType) against [m_nMin, m_nMax] (-1 = unbounded).
class CGuideConditionCountItem : public CGuideCondition
{
public:
    CGuideConditionCountItem();                             // 0x1413b2b60

    int m_nItemType;                                        // +0x28
    int m_nMin;                                             // +0x2c
    int m_nMax;                                             // +0x30
    int m_pad_34;
};
MS2_CHECK_SIZE(CGuideConditionCountItem, 0x38);

// 0x38. CountItem over the placeable (indoor-install) items of the cube tab.
class CGuideConditionCountInDoorInstallItem : public CGuideConditionCountItem
{
public:
    CGuideConditionCountInDoorInstallItem();                // 0x1413b2b30
    virtual CStringW vfunc_1();                             // 1 0x1413a9960
    virtual int vfunc_3();                                  // 3 0x1413a99b0
    virtual void vfunc_5();                                 // 5 0x1413a9a50

    int FUN_1413a9ac0();                                    // 0x1413a9ac0 the number of placeable items in the inventory tab 4
};
MS2_CHECK_SIZE(CGuideConditionCountInDoorInstallItem, 0x38);

// 0x30. Passes after the key/condition m_n20 has been held for m_nTick ms (0 = immediately).
class CGuideConditionInput : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6580
    CGuideConditionInput();                                 // 0x1413a6630
    virtual CStringW vfunc_1();                             // 1 0x1413a65e0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a6670
    virtual int vfunc_3();                                  // 3 0x1413a66c0
    virtual void vfunc_4();                                 // 4 0x1413a67d0
    virtual CStringW vfunc_7();                       // 7 0x1413a6800

    unsigned m_nTick;                                           // +0x28
    int m_nDeadline;                                        // +0x2c
};
MS2_CHECK_SIZE(CGuideConditionInput, 0x30);

// 0x28. Passes when any of the key bindings of action m_n20 is pressed.
class CGuideConditionActionInput : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a68b0
    CGuideConditionActionInput();
    virtual CStringW vfunc_1();                             // 1 0x1413a6910
    virtual int vfunc_3();                                  // 3 0x1413a6960
};
MS2_CHECK_SIZE(CGuideConditionActionInput, 0x28);

// 0x28. Passes while a field object of type 6 exists.
class CGuideConditionReturnPortal : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6bc0
    CGuideConditionReturnPortal();
    virtual CStringW vfunc_1();                             // 1 0x1413a6c20
    virtual int vfunc_3();                                  // 3 0x1413a6c70
};
MS2_CHECK_SIZE(CGuideConditionReturnPortal, 0x28);

// 0x28. Passes while a field portal contains the local player's position.
class CGuideConditionPortalEnable : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6ca0
    CGuideConditionPortalEnable();
    virtual CStringW vfunc_1();                             // 1 0x1413a6d00
    virtual int vfunc_3();                                  // 3 0x1413a6d50
};
MS2_CHECK_SIZE(CGuideConditionPortalEnable, 0x28);
