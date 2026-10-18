// weaponactiontable.h - CWeaponActionTable (RTTI name): the weapon action tables read from Table/weaponAction.xml. A
// static pair of lists: the <weapon> rows (CWeaponAction: right/left hand weapon type -> action prefix) and the
// <allowWeapon> rows (CWeaponAllow: right hand weapon type -> the left hand types it can be combined with). Header name
// assumed from the unit path; member and method names are invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One <weapon> row (0x30 bytes): the action prefix of a right/left hand weapon pair.
class CWeaponAction : public CPtred
{
public:
    CWeaponAction() {}                  // 0x141b74f50
    // implicit dtor 0x141b750d0 (??_G 0x141b75280)

    int m_nRightHand;                   // +0x18 "rh"
    int m_nLeftHand;                    // +0x1c "lh"
    int m_nNormalAttack;                // +0x20 "normalAttack"
    CString m_strPrefix;                // +0x28 "actionprefix"
};
MS2_CHECK_SIZE(CWeaponAction, 0x30);
MS2_CHECK_OFFSET(CWeaponAction, m_strPrefix, 0x28);

// One <allowWeapon> row (0x38 bytes): the left hand weapon types allowed with a right hand type.
class CWeaponAllow : public CPtred
{
public:
    CWeaponAllow() {}                   // 0x141b74f90
    // implicit dtor 0x141b75100 (??_G 0x141b75300)

    int Allows(int nLeftHand);          // 0x141b74600

    ATL::CAtlArray<int> m_leftHands;    // +0x18 "lh" (comma separated)
};
MS2_CHECK_SIZE(CWeaponAllow, 0x38);
MS2_CHECK_OFFSET(CWeaponAllow, m_leftHands, 0x18);

class CWeaponActionTable : public CValidData<CWeaponActionTable>
{
public:
    typedef MS2Ptr<CWeaponAction> ActionPtr;
    typedef MS2Ptr<CWeaponAllow> AllowPtr;
    typedef ATL::CAtlArray<ActionPtr> ActionList;
    typedef ATL::CAtlMap<int, AllowPtr> AllowMap;

    CWeaponActionTable();               // 0x141b74680
    virtual ~CWeaponActionTable();      // 0x141b746c0 (??_G 0x141b752c0)

    static void ClearAll();             // 0x141b746f0 (name invented)
    static int Load();                  // 0x141b74720 weaponAction.xml
    static ActionPtr FindAction(int nRightHand, int nLeftHand);     // 0x141b74b50 (name invented)
    static int IsAllowed(int nRightHand, int nLeftHand);            // 0x141b74c30 (name invented)
    static void CheckInit();            // 0x141b754d0
    static void SetInit(bool b);        // 0x141b76740

    static bool s_bInit;                // 0x143af7730
    static ActionList s_actions;        // 0x143af7740
    static AllowMap s_allows;           // 0x143af7760
};
MS2_CHECK_SIZE(CWeaponActionTable, 8);
