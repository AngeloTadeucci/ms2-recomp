// cguidecondition.h - PLACEHOLDER for the guide-quest condition classes (RTTI .?AVCGuideCondition@@ and subclasses): the
// ClassObject-derived predicates the CGuideManager evaluates (a name factory per class, an XML loader in vfunc_2,
// the check in vfunc_3). The base lives in ?\guideentity.cpp (ctor 0x1413a54e0, dtor 0x1413a5540, vftable 0x142f05b80,
// slots 2..8 at 0x1413a5670..0x1413a5810, helper 0x1413a5600 / 0x1413a5820); the subclasses are spread over
// unit_1413a8370 / unit_1413a9a50 / unit_1413a9df0 (ctors 0x1413b2b30.., vftables, deleting dtors). NOT an original
// header; member names invented from their use. Append new subclasses here (layout proven from their ctors / operator new).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/nipoint3.h"

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

// 0x38. Passes once the local player has walked m_n20 units (the summed distance between successive checks).
class CGuideConditionMovement : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a76f0
    CGuideConditionMovement();                              // 0x1413a77a0
    virtual CStringW vfunc_1();                             // 1 0x1413a7750
    virtual int vfunc_3();                                  // 3 0x1413a7820
    virtual void vfunc_4();                                 // 4 0x1413a7950

    Unk_StreamPoint m_vLastPos;                             // +0x28 the player position at the previous check
    float m_fMoved;                                         // +0x34 the distance walked so far
};
MS2_CHECK_SIZE(CGuideConditionMovement, 0x38);

// 0x28. Passes while the inventory dialog shows the tab m_n20.
class CGuideConditionInventoryTab : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a79a0
    CGuideConditionInventoryTab();
    virtual CStringW vfunc_1();                             // 1 0x1413a7a00
    virtual int vfunc_3();                                  // 3 0x1413a7a50
};
MS2_CHECK_SIZE(CGuideConditionInventoryTab, 0x28);

// 0x28. Passes while the game scene (id 0x620001d) is the current one.
class CGuideConditionGameScene : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7ad0
    CGuideConditionGameScene();
    virtual CStringW vfunc_1();                             // 1 0x1413a7b30
    virtual int vfunc_3();                                  // 3 0x1413a7b80
};
MS2_CHECK_SIZE(CGuideConditionGameScene, 0x28);

// 0x30. Passes once m_n20 ms have elapsed since the first check, or when the UI is idle and the key-binding query 0x493e2 holds.
class CGuideConditionNext : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7bc0
    CGuideConditionNext();                                  // 0x1413a7c70
    virtual CStringW vfunc_1();                             // 1 0x1413a7c20
    virtual int vfunc_3();                                  // 3 0x1413a7cb0
    virtual void vfunc_4();                                 // 4 0x1413a7d40

    unsigned m_nStart;                                      // +0x28 the clock at the first check (0 = not started)
    int m_pad_2c;
};
MS2_CHECK_SIZE(CGuideConditionNext, 0x30);

// 0x28. Passes while the quest m_n20 is satisfied (all objectives done).
class CGuideConditionQuestSatisfied : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7d70
    CGuideConditionQuestSatisfied();                        // 0x1413b3310
    virtual CStringW vfunc_1();                             // 1 0x1413a7dd0
    virtual int vfunc_3();                                  // 3 0x1413a7e20
};
MS2_CHECK_SIZE(CGuideConditionQuestSatisfied, 0x28);

// 0x28. Passes while the quest m_n20 is complete.
class CGuideConditionQuestComplete : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7e60
    CGuideConditionQuestComplete();                         // 0x1413b32b0
    virtual CStringW vfunc_1();                             // 1 0x1413a7ec0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a7f10
    virtual int vfunc_3();                                  // 3 0x1413a7f50
    virtual int vfunc_8();                                  // 8 0x1413a7f90
};
MS2_CHECK_SIZE(CGuideConditionQuestComplete, 0x28);

// 0x28. Passes while the quest m_n20 is in progress.
class CGuideConditionQuestProgress : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a7fc0
    CGuideConditionQuestProgress();                         // 0x1413b32e0
    virtual CStringW vfunc_1();                             // 1 0x1413a8020
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a8070
    virtual int vfunc_3();                                  // 3 0x1413a80b0
    virtual int vfunc_8();                                  // 8 0x1413a80f0
};
MS2_CHECK_SIZE(CGuideConditionQuestProgress, 0x28);

// 0x28. Passes while the local player is dead.
class CGuideConditionDead : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8120
    CGuideConditionDead();                                  // 0x1413b2bc0
    virtual CStringW vfunc_1();                             // 1 0x1413a8180
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a81d0
    virtual int vfunc_3();                                  // 3 0x1413a8210
    virtual int vfunc_8();                                  // 8 0x1413a8260
};
MS2_CHECK_SIZE(CGuideConditionDead, 0x28);

// 0x28. Passes while the local player is in construct (cube build) mode.
class CGuideConditionConstructMode : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a8270
    CGuideConditionConstructMode();                         // 0x1413b2a70
    virtual CStringW vfunc_1();                             // 1 0x1413a82d0
    virtual int vfunc_3();                                  // 3 0x1413a8320
};
MS2_CHECK_SIZE(CGuideConditionConstructMode, 0x28);

// 0x60. Passes while the dialog (by id m_nDialogID, else by name m_strDialog) is open (m_nIsOpen = 1) or closed (0), every
// "control" child is visible and, when m_nSubIndex >= 0, the dialog shows that sub page.
class CGuideConditionDialog : public CGuideCondition
{
public:
    static ClassObject* CreateObject();                     // 0x1413a6010
    CGuideConditionDialog();                                // 0x1413a60c0
    virtual ~CGuideConditionDialog();                       // 0 0x1413b4700
    virtual CStringW vfunc_1();                             // 1 0x1413a6070
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x1413a6480: dialogName / dialogID / isOpen / subIndex / control
    virtual int vfunc_3();                                  // 3 0x1413a6140
    virtual CStringW vfunc_7();                             // 7 0x1413a6300
    virtual int vfunc_8();                                  // 8 0x1413a6430

    int m_nIsOpen;                                          // +0x28 "isOpen" (1)
    unsigned m_nDialogID;                                   // +0x2c "dialogID"
    CStringA m_strDialog;                                   // +0x30 "dialogName"
    int m_nSubIndex;                                        // +0x38 "subIndex" (-1)
    int m_pad_3c;
    ATL::CAtlArray<CString> m_arrControl;                   // +0x40 "control": the child names that must be visible
};
MS2_CHECK_SIZE(CGuideConditionDialog, 0x60);
