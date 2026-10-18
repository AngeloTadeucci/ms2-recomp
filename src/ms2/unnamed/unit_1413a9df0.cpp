// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Part 1 of unit_1413a9df0: the guide-condition classes ContinentCode,
// AnyOne, AllOf, AchieveExistTrophy, GuideOpen/GuideClear, ExistShortcut, UgcCollectMoney, CanObserveMode, MyPlayerLevel, Money,
// PlaceUgcCube/Item/ByIconType, InteractObject, LastClosedTextTip, ConstructSlot, Title, ServerTime, HasManufacture and the
// FieldId description (factories, names, loaders and checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a9df0
// MS2-RANGE: 0x1413a9df0-0x1413acea0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"


// This TU has its own copies of the StringFormat instances (the exe does not fold them), so each is a unit-local wrapper
// pinned to the copy the function calls.
// MS2-PIN: ?GcFmtId@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x140292a70
// MS2-PIN: ?GcFmtMinMax@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH@Z 0x1401ceea0
// MS2-PIN: ?GcFmtIntInt@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBH1@Z 0x1406e7810
// MS2-PIN: ?GcFmtRange@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEBI2@Z 0x1413afe00
// MS2-PIN: ?GcFmtInteract@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEBM1@Z 0x1413b0180
// MS2-PIN: ?GcFmtSlot@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBHAEB_N2@Z 0x1413b0500
// MS2-PIN: ?GcFmtPos@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBM11@Z 0x140719e60
// MS2-PIN: ?GcFmtBool@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_N@Z 0x14136f150
// MS2-PIN: ?GcFmtSize@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEB_K@Z 0x1406c6bd0
// MS2-PIN: ?GcFmtStr@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@PEB_WAEBV12@@Z 0x1401e8510
__declspec(noinline) CStringW GcFmtId(const wchar_t* f, const int& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtMinMax(const wchar_t* f, const int& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtIntInt(const wchar_t* f, const int& a, const int& b) { return StringFormat(f, a, b); }
__declspec(noinline) CStringW GcFmtRange(const wchar_t* f, const int& a, const unsigned& b, const unsigned& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtInteract(const wchar_t* f, const int& a, const float& b, const int& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtSlot(const wchar_t* f, const int& a, const bool& b, const bool& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtPos(const wchar_t* f, const float& a, const float& b, const float& c) { return StringFormat(f, a, b, c); }
__declspec(noinline) CStringW GcFmtBool(const wchar_t* f, const bool& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtSize(const wchar_t* f, const size_t& a) { return StringFormat(f, a); }
__declspec(noinline) CStringW GcFmtStr(const wchar_t* f, const CStringW& a) { return StringFormat(f, a); }

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The local player: only the position getter and the level getter.
class Unk_G9Player
{
public:
    virtual ~Unk_G9Player();
    virtual void Unk_Slot0();
    virtual void Unk_Slot1();
    virtual void Unk_Slot2();
    virtual void Unk_Slot3();
    virtual void Unk_Slot4();
    virtual void Unk_Slot5();
    virtual void Unk_Slot6();
    virtual void Unk_Slot7();
    virtual void Unk_Slot8();
    virtual void Unk_Slot9();
    virtual void Unk_Slot10();
    virtual void Unk_Slot11();
    virtual void Unk_Slot12();
    virtual void Unk_Slot13();
    virtual void Unk_Slot14();
    virtual void Unk_Slot15();
    virtual void Unk_Slot16();
    virtual void Unk_Slot17();
    virtual Unk_StreamPoint vfunc_18();
    virtual void Unk_Slot19();
    virtual void Unk_Slot20();
    virtual void Unk_Slot21();
    virtual void Unk_Slot22();
    virtual void Unk_Slot23();
    virtual void Unk_Slot24();
    virtual void Unk_Slot25();
    virtual void Unk_Slot26();
    virtual void Unk_Slot27();
    virtual void Unk_Slot28();
    virtual void Unk_Slot29();
    virtual void Unk_Slot30();
    virtual void Unk_Slot31();
    virtual void Unk_Slot32();
    virtual void Unk_Slot33();
    virtual void Unk_Slot34();
    virtual void Unk_Slot35();
    virtual void Unk_Slot36();
    virtual void Unk_Slot37();
    virtual void Unk_Slot38();
    virtual void Unk_Slot39();
    virtual void Unk_Slot40();
    virtual void Unk_Slot41();
    virtual void Unk_Slot42();
    virtual void Unk_Slot43();
    virtual void Unk_Slot44();
    virtual void Unk_Slot45();
    virtual void Unk_Slot46();
    virtual void Unk_Slot47();
    virtual void Unk_Slot48();
    virtual void Unk_Slot49();
    virtual void Unk_Slot50();
    virtual void Unk_Slot51();
    virtual void Unk_Slot52();
    virtual void Unk_Slot53();
    virtual void Unk_Slot54();
    virtual void Unk_Slot55();
    virtual void Unk_Slot56();
    virtual void Unk_Slot57();
    virtual void Unk_Slot58();
    virtual void Unk_Slot59();
    virtual void Unk_Slot60();
    virtual void Unk_Slot61();
    virtual void Unk_Slot62();
    virtual void Unk_Slot63();
    virtual void Unk_Slot64();
    virtual void Unk_Slot65();
    virtual void Unk_Slot66();
    virtual void Unk_Slot67();
    virtual void Unk_Slot68();
    virtual void Unk_Slot69();
    virtual void Unk_Slot70();
    virtual void Unk_Slot71();
    virtual void Unk_Slot72();
    virtual void Unk_Slot73();
    virtual void Unk_Slot74();
    virtual void Unk_Slot75();
    virtual void Unk_Slot76();
    virtual void Unk_Slot77();
    virtual unsigned short vfunc_78();
};

// The map info of the player (continent code lookup).
class Unk_G9MapInfo
{
public:
    bool FUN_140965240(int nFlag);
    void* FUN_140885340();
    void* m_p0; void* m_p1; void* m_p2; void* m_p3;
};
MS2_CHECK_SIZE(Unk_G9MapInfo, 0x20);
void FUN_1408850f0(Unk_G9MapInfo* pInfo);
int FUN_140375350(void* pCode);

// An object reference found in the world.
class Unk_G9ObjRef
{
public:
    void* FUN_1409657e0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ObjRef, 0x10);
void FUN_1409649b0(Unk_G9ObjRef* pRef);
class Unk_G9Obj { public: Unk_StreamPoint FUN_1409673c0(); };
int FUN_1413b5600(Unk_G9Obj* pObj);                     // the interact state

class Unk_G9World
{
public:
    Unk_G9Player* FUN_141bd0cc0();                      // the local player
    Unk_G9MapInfo FUN_141bd30a0();
    Unk_G9ObjRef FUN_141bc6510(const Unk_StreamPoint& pos, int nId);
};
Unk_G9World* FUN_1403ed2d0();

// The guide manager and the guide entry reference.
class Unk_G9GuideEntry { public: void* m_p0; void* m_p1; void* m_p2; void* m_p3; };
class Unk_G9GuideRef
{
public:
    Unk_G9GuideEntry* FUN_141398900();
    void* m_p0; Unk_G9GuideEntry* m_pEntry; void* m_p2; void* m_p3;
};
MS2_CHECK_SIZE(Unk_G9GuideRef, 0x20);
void FUN_141397db0(Unk_G9GuideRef* pRef);
class Unk_G9GuideMgr
{
public:
    Unk_G9GuideRef FUN_14138b990(int nGuideId);
    bool FUN_14138caa0(int nGuideId);                   // cleared
};
Unk_G9GuideMgr* FUN_1409331e0();

// The home (the player's ugc house).
class Unk_G9Home
{
public:
    void* FUN_1410b9850(int nItemId);
    int FUN_1410b9a50();
    void* FUN_1410b8ab0(const Unk_StreamPoint& pos);
    int FUN_1410b9950(int nIconType);
};
Unk_G9Home* FUN_1409670e0();
unsigned __int64 FUN_1408b4f20(void* pCubeObj);
class Unk_G9ItemRec { public: void* m_p[0x38]; int m_n1c0; int m_nValue; };                          // +0x1c4
MS2_CHECK_SIZE(Unk_G9ItemRec, 0x1c8);
class Unk_G9ItemRef
{
public:
    Unk_G9ItemRec* FUN_1401b52a0();
    void FUN_1401b50d0();
    void* m_p0; void* m_p1;
};
MS2_CHECK_SIZE(Unk_G9ItemRef, 0x10);
Unk_G9ItemRef FUN_14053f870(unsigned __int64 nId);

void* FUN_1406c7600();                                  // the trophy manager
int FUN_140936740(void* pMgr, unsigned __int64 nPacked);
void* FUN_1409331f0();                                  // the key binds
int FUN_14142dc50(void* pBinds, int nSlot);
void* FUN_140939a00();                                  // the ugc market
__int64 FUN_140d56470(void* pMarket);
void* FUN_1409eed40();                                  // the manufacture book
int FUN_140d513c0(void* pBook);
void* FUN_1413b1c60(const CStringA& strName);           // the dialog of a name
int FUN_141a75840(void* pDialog);
void* FUN_14136f3e0(unsigned nUIId);                    // the dialog of a ui id
int FUN_14195b950(void* pDialog);
CStringA FUN_141388650(const char* psz);

class Unk_G9U32Arr { public: size_t FUN_140186270(); };
extern Unk_G9U32Arr DAT_143ab3268;                      // the owned titles
extern __int64 DAT_143ab2898;                           // the money

Unk_GcCondRef FUN_1413a52c0(Unk_140165cf0* pElem);      // builds the condition of a <condition> element
int FUN_1413a5570(CGuideCondition* pCond);              // runs a nested condition's test

int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
int FUN_140873600(Unk_140165cf0* pElem, const char* pszName, Unk_GcTime& tOut);
int FUN_1413b1d00(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptInt& oOut);
int FUN_1413b1e70(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptVec3& oOut);
int FUN_1413b1ed0(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptBool& oOut);
CStringW FUN_1413b1510(const wchar_t* pszFormat, const void* pArg);      // StringFormat of a trophy type (own formatter)
CStringW FUN_14083bdc0(const Unk_GcTime& t, int nFlag, const CStringW& strDateSep, const CStringW& strTimeSep);
CStringW FUN_140719730(bool b);
unsigned __int64 FUN_140869440();                       // the server time
void FUN_1412751b0(const CStringW& text, int a);


// @0x1413a9df0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionFieldId::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtRange(L"value({0}), range({1}-{2})", m_n20, unsigned(m_nRangeBeg), unsigned(m_nRangeEnd)));
    return str;
}

// @0x1413a9ec0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionFieldId::vfunc_8()
{
    if (!m_b1c && m_n20 != 0 && m_nRangeBeg == 0 && m_nRangeEnd == 0)
        return m_n20;
    return 0;
}

// @0x1413a9f10
ClassObject* CGuideConditionContinentCode::CreateObject()
{
    return new CGuideConditionContinentCode;
}

// @0x1413a9f70
CStringW CGuideConditionContinentCode::vfunc_1()
{
    return L"CGuideConditionContinentCode";
}

// @0x1413a9fc0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionContinentCode::vfunc_3()
{
    Unk_G9MapInfo info = FUN_1403ed2d0()->FUN_141bd30a0();
    if (info.FUN_140965240(0)) {
        FUN_1408850f0(&info);
        return 0;
    }
    int nContinent = FUN_140375350(info.FUN_140885340());
    int nResult = FUN_1413a5600(m_n20 == nContinent);
    FUN_1408850f0(&info);
    return nResult;
}

// @0x1413aa070
ClassObject* CGuideConditionAnyOne::CreateObject()
{
    return new CGuideConditionAnyOne;
}

// @0x1413aa0d0
CStringW CGuideConditionAnyOne::vfunc_1()
{
    return L"CGuideConditionAnyOne";
}

// @0x1413aa120
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAnyOne::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("condition"); pChild != 0; pChild = pChild->FUN_140168650("condition")) {
        Unk_GcCondRef ref = FUN_1413a52c0(pChild);
        if (ref.FUN_141387b90())
            m_conds.FUN_141388460(ref);
        ref.FUN_141387660();
    }
}

// @0x1413aa1d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAnyOne::vfunc_3()
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (FUN_1413a5570(m_conds.FUN_141387b40(i).FUN_141387bb0()) != 0)
            return 1;
    }
    return 0;
}

// @0x1413aa250
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAnyOne::vfunc_4()
{
    CGuideCondition::vfunc_4();
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i)
        m_conds.FUN_141387b40(i).FUN_141387bb0()->vfunc_4();
}

// @0x1413aa2e0
ClassObject* CGuideConditionAllOf::CreateObject()
{
    return new CGuideConditionAllOf;
}

// @0x1413aa340
CStringW CGuideConditionAllOf::vfunc_1()
{
    return L"CGuideConditionAllOf";
}

// @0x1413aa390
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionAllOf::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    for (Unk_140165cf0* pChild = pElem->FUN_140165cf0("condition"); pChild != 0; pChild = pChild->FUN_140168650("condition")) {
        Unk_GcCondRef ref = FUN_1413a52c0(pChild);
        if (ref.FUN_141387b90())
            m_conds.FUN_141388460(ref);
        ref.FUN_141387660();
    }
}

// @0x1413aa440
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
bool CGuideConditionAllOf::vfunc_6(Unk_GcCondList* pFailed)
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (!m_conds.FUN_141387b40(i).FUN_141387bb0()->vfunc_6(pFailed))
            pFailed->FUN_141388460(m_conds.FUN_141387b40(i));
    }
    return true;
}

// @0x1413aa500
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAllOf::vfunc_3()
{
    for (unsigned i = 0; i < m_conds.FUN_1413886d0(); ++i) {
        if (FUN_1413a5570(m_conds.FUN_141387b40(i).FUN_141387bb0()) == 0)
            return 0;
    }
    return 1;
}

// @0x1413aa580
ClassObject* CGuideConditionAchieveExistTrophy::CreateObject()
{
    return new CGuideConditionAchieveExistTrophy;
}

// @0x1413aa5e0
CStringW CGuideConditionAchieveExistTrophy::vfunc_1()
{
    return L"CGuideConditionAchieveExistTrophy";
}

// @0x1413aa630
void CGuideConditionAchieveExistTrophy::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1d00(pElem, "achieveType", m_type);
}

// @0x1413aa680
int CGuideConditionAchieveExistTrophy::vfunc_3()
{
    return FUN_1413a55a0(FUN_140936740(FUN_1406c7600(), *reinterpret_cast<unsigned __int64*>(&m_type)));
}

// @0x1413aa6c0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionAchieveExistTrophy::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (m_type.m_bSet)
        str.Append(FUN_1413b1510(L"achieveType({0})", &m_type.m_nValue));
    else
        str.Append(StringFormat(L"achieveType"));
    return str;
}

// @0x1413aa7e0
ClassObject* CGuideConditionGuideOpen::CreateObject()
{
    return new CGuideConditionGuideOpen;
}

// @0x1413aa840
CStringW CGuideConditionGuideOpen::vfunc_1()
{
    return L"CGuideConditionGuideOpen";
}

// @0x1413aa890
void CGuideConditionGuideOpen::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 13;
    m_nGuideId = 0;
    FUN_140873220(pElem, "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aa8f0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionGuideOpen::vfunc_3()
{
    Unk_G9GuideRef ref = FUN_1409331e0()->FUN_14138b990(m_nGuideId);
    if (ref.m_pEntry == 0) {
        FUN_141397db0(&ref);
        return 0;
    }
    int nResult = FUN_1413a5600(ref.FUN_141398900()->m_p0 != 0);
    FUN_141397db0(&ref);
    return nResult;
}

// @0x1413aa990
CStringW CGuideConditionGuideOpen::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"guideID({0})", m_nGuideId));
    return str;
}

// @0x1413aaa40
int CGuideConditionGuideOpen::vfunc_8()
{
    return 0;
}

// @0x1413aaa50
ClassObject* CGuideConditionGuideClear::CreateObject()
{
    return new CGuideConditionGuideClear;
}

// @0x1413aaab0
CStringW CGuideConditionGuideClear::vfunc_1()
{
    return L"CGuideConditionGuideClear";
}

// @0x1413aab00
void CGuideConditionGuideClear::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 2;
    m_nGuideId = 0;
    FUN_140873220(pElem, "id", reinterpret_cast<unsigned&>(m_nGuideId));
}

// @0x1413aab60
int CGuideConditionGuideClear::vfunc_3()
{
    return FUN_1413a5600(FUN_1409331e0()->FUN_14138caa0(m_nGuideId));
}

// @0x1413aaba0
CStringW CGuideConditionGuideClear::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"guideID({0})", m_nGuideId));
    return str;
}

// @0x1413aac50
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionGuideClear::vfunc_8()
{
    if (!m_b1c)
        return m_nGuideId;
    return 0;
}

// @0x1413aac80
ClassObject* CGuideConditionExistShortcut::CreateObject()
{
    return new CGuideConditionExistShortcut;
}

// @0x1413aace0
CStringW CGuideConditionExistShortcut::vfunc_1()
{
    return L"CGuideConditionExistShortcut";
}

// @0x1413aad30
void CGuideConditionExistShortcut::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIndex = 0;
    m_nSkillId = 0;
    FUN_140873220(pElem, "slotIndex", reinterpret_cast<unsigned&>(m_nSlotIndex));
    FUN_140873220(pElem, "skillID", reinterpret_cast<unsigned&>(m_nSkillId));
}

// @0x1413aadb0
int CGuideConditionExistShortcut::vfunc_3()
{
    int nSkill = FUN_14142dc50(FUN_1409331f0(), m_nSlotIndex);
    return FUN_1413a5600(nSkill == m_nSkillId);
}

// @0x1413aae10
CStringW CGuideConditionExistShortcut::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtIntInt(L"slotIndex({0}), skillID({1})", m_nSlotIndex, m_nSkillId));
    return str;
}

// @0x1413aaed0
ClassObject* CGuideConditionUgcCollectMoney::CreateObject()
{
    return new CGuideConditionUgcCollectMoney;
}

// @0x1413aaf30
CStringW CGuideConditionUgcCollectMoney::vfunc_1()
{
    return L"CGuideConditionUgcCollectMoney";
}

// @0x1413aaf80
int CGuideConditionUgcCollectMoney::vfunc_3()
{
    return 0 < FUN_140d56470(FUN_140939a00());
}

// @0x1413aafc0
ClassObject* CGuideConditionCanObserveMode::CreateObject()
{
    return new CGuideConditionCanObserveMode;
}

// @0x1413ab020
CStringW CGuideConditionCanObserveMode::vfunc_1()
{
    return L"CGuideConditionCanObserveMode";
}

// @0x1413ab070
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionCanObserveMode::vfunc_3()
{
    void* pDialog = FUN_1413b1c60(CStringA("PartyDialog"));
    if (pDialog == 0)
        return 0;
    return FUN_1413a55a0(FUN_141a75840(pDialog));
}

// @0x1413ab0e0
ClassObject* CGuideConditionMyPlayerLevel::CreateObject()
{
    return new CGuideConditionMyPlayerLevel;
}

// @0x1413ab140
CStringW CGuideConditionMyPlayerLevel::vfunc_1()
{
    return L"CGuideConditionMyPlayerLevel";
}

// @0x1413ab190
void CGuideConditionMyPlayerLevel::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 4;
}

// @0x1413ab1d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionMyPlayerLevel::vfunc_3()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    unsigned short nLevel = pPC->vfunc_78();
    return FUN_1413a5600(m_n20 <= (int)(unsigned)nLevel);
}

// @0x1413ab240
int CGuideConditionMyPlayerLevel::vfunc_8()
{
    return 0;
}

// @0x1413ab250
ClassObject* CGuideConditionMoney::CreateObject()
{
    return new CGuideConditionMoney;
}

// @0x1413ab2b0
CStringW CGuideConditionMoney::vfunc_1()
{
    return L"CGuideConditionMoney";
}

// @0x1413ab300
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionMoney::vfunc_3()
{
    return FUN_1413a5600(m_n20 <= DAT_143ab2898);
}

// @0x1413ab350
ClassObject* CGuideConditionPlaceUgcCube::CreateObject()
{
    return new CGuideConditionPlaceUgcCube;
}

// @0x1413ab3b0
CStringW CGuideConditionPlaceUgcCube::vfunc_1()
{
    return L"CGuideConditionPlaceUgcCube";
}

// @0x1413ab400
void CGuideConditionPlaceUgcCube::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nItemId = 0;
    FUN_1408731e0(pElem, "itemId", m_nItemId);
    FUN_1413b1d00(pElem, "minCount", m_min);
    FUN_1413b1d00(pElem, "maxCount", m_max);
}

// @0x1413ab490
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionPlaceUgcCube::vfunc_3()
{
    if (m_nItemId != 0 && FUN_1409670e0()->FUN_1410b9850(m_nItemId) == 0)
        return FUN_1413a55a0(0);
    if (m_min.m_bSet || m_max.m_bSet) {
        int nCount = FUN_1409670e0()->FUN_1410b9a50();
        if (m_min.m_bSet && nCount < m_min.m_nValue)
            return FUN_1413a55a0(0);
        if (m_max.m_bSet && m_max.m_nValue < nCount)
            return FUN_1413a55a0(0);
    }
    return FUN_1413a55a0(1);
}

// @0x1413ab5b0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionPlaceUgcCube::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtId(L"itemID({0})", m_nItemId));
    if (m_min.m_bSet)
        str.Append(GcFmtMinMax(L", minCount({0})", m_min.m_nValue));
    if (m_max.m_bSet)
        str.Append(GcFmtMinMax(L", maxCount({0})", m_max.m_nValue));
    return str;
}

// @0x1413ab750
ClassObject* CGuideConditionPlaceUgcCubeItem::CreateObject()
{
    return new CGuideConditionPlaceUgcCubeItem;
}

// @0x1413ab7b0
CStringW CGuideConditionPlaceUgcCubeItem::vfunc_1()
{
    return L"CGuideConditionPlaceUgcCubeItem";
}

// @0x1413ab800
void CGuideConditionPlaceUgcCubeItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1e70(pElem, "pos", m_pos);
    FUN_1413b1ed0(pElem, "isAttachable", m_attachable);
}

// @0x1413ab870
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionPlaceUgcCubeItem::vfunc_3()
{
    if (!m_pos.m_bSet)
        return 0;
    Unk_StreamPoint pos(m_pos.m_x, m_pos.m_y, m_pos.m_z);
    void* pCube = FUN_1409670e0()->FUN_1410b8ab0(pos);
    if (pCube == 0)
        return FUN_1413a55a0(0);
    if (m_attachable.m_bSet) {
        Unk_G9ItemRef item = FUN_14053f870(FUN_1408b4f20(pCube));
        int nAttach = item.FUN_1401b52a0()->m_nValue;
        if ((nAttach != 0) != m_attachable.m_bValue) {
            int nResult = FUN_1413a55a0(0);
            item.FUN_1401b50d0();
            return nResult;
        }
        item.FUN_1401b50d0();
    }
    return FUN_1413a55a0(1);
}

// @0x1413ab9e0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionPlaceUgcCubeItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    if (m_pos.m_bSet)
        str.Append(GcFmtPos(L"pos({0},{1},{2})", m_pos.m_x, m_pos.m_y, m_pos.m_z));
    if (m_attachable.m_bSet)
        str.Append(GcFmtBool(L"isAttachable({0})", m_attachable.m_bValue));
    return str;
}

// @0x1413abb80
ClassObject* CGuideConditionPlaceUgcCubeByIconType::CreateObject()
{
    return new CGuideConditionPlaceUgcCubeByIconType;
}

// @0x1413abbe0
CStringW CGuideConditionPlaceUgcCubeByIconType::vfunc_1()
{
    return L"CGuideConditionPlaceUgcCubeByIconType";
}

// @0x1413abc30
void CGuideConditionPlaceUgcCubeByIconType::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nIconType = 0;
    FUN_1408731e0(pElem, "iconType", m_nIconType);
}

// @0x1413abc90
int CGuideConditionPlaceUgcCubeByIconType::vfunc_3()
{
    if (FUN_1409670e0()->FUN_1410b9950(m_nIconType) == 0)
        return FUN_1413a55a0(0);
    return FUN_1413a55a0(1);
}

// @0x1413abce0
CStringW CGuideConditionPlaceUgcCubeByIconType::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtMinMax(L"iconType({0})", m_nIconType));
    return str;
}

// @0x1413abd90
ClassObject* CGuideConditionInteractObject::CreateObject()
{
    return new CGuideConditionInteractObject;
}

// @0x1413abdf0
CStringW CGuideConditionInteractObject::vfunc_1()
{
    return L"CGuideConditionInteractObject";
}

// @0x1413abe40
void CGuideConditionInteractObject::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1408731e0(pElem, "interactId", m_nInteractId);
    FUN_140873360(pElem, "distance", m_fDistance);
    FUN_1408731e0(pElem, "state", m_nState);
}

// @0x1413abec0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionInteractObject::vfunc_3()
{
    Unk_G9Player* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    Unk_StreamPoint posPC = pPC->vfunc_18();
    Unk_G9ObjRef ref = FUN_1403ed2d0()->FUN_141bc6510(posPC, m_nInteractId);
    Unk_G9Obj* pObj = static_cast<Unk_G9Obj*>(ref.FUN_1409657e0());
    FUN_1409649b0(&ref);
    if (pObj == 0)
        return 0;
    Unk_StreamPoint posObj = pObj->FUN_1409673c0();
    float fDist = pPC->vfunc_18().FUN_140965c40(posObj).FUN_140967ac0();
    if (fDist <= m_fDistance)
        return FUN_1413a55a0(FUN_1413b5600(pObj) == m_nState);
    return FUN_1413a55a0(0);
}

// @0x1413ac050
CStringW CGuideConditionInteractObject::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtInteract(L"interactID({0}), interactID({1}), interactID({2})", m_nInteractId, m_fDistance, m_nState));
    return str;
}

// @0x1413ac120
ClassObject* CGuideConditionLastClosedTextTip::CreateObject()
{
    return new CGuideConditionLastClosedTextTip;
}

// @0x1413ac180
CStringW CGuideConditionLastClosedTextTip::vfunc_1()
{
    return L"CGuideConditionLastClosedTextTip";
}

// @0x1413ac1d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionLastClosedTextTip::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nEntityId = 0;
    FUN_1408731e0(pElem, "entityId", m_nEntityId);
    if (m_nEntityId == 0) {
        CStringA strMsg = FUN_141388650("lastClosedToolTip entityId == 0");
        throw std::exception((const char*)strMsg);
    }
}

// @0x1413ac290
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionLastClosedTextTip::vfunc_3()
{
    void* pDialog = FUN_14136f3e0(0x4e53);
    if (pDialog == 0)
        return 0;
    return FUN_1413a5600(m_nEntityId == FUN_14195b950(pDialog));
}

// @0x1413ac2f0
CStringW CGuideConditionLastClosedTextTip::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtMinMax(L"entityID({0})", m_nEntityId));
    return str;
}

// @0x1413ac3a0
ClassObject* CGuideConditionConstructSlot::CreateObject()
{
    return new CGuideConditionConstructSlot;
}

// @0x1413ac400
CStringW CGuideConditionConstructSlot::vfunc_1()
{
    return L"CGuideConditionConstructSlot";
}

// @0x1413ac450
void CGuideConditionConstructSlot::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotIdx = 0;
    m_bIndoor = false;
    m_bOutdoor = false;
    FUN_1408731e0(pElem, "slotIdx", m_nSlotIdx);
    FUN_1408736d0(pElem, "isIndoor", m_bIndoor);
    FUN_1408736d0(pElem, "isOutdoor", m_bOutdoor);
}

// @0x1413ac4f0
int CGuideConditionConstructSlot::vfunc_3()
{
    return 1;
}

// @0x1413ac510
void CGuideConditionConstructSlot::vfunc_5()
{
    
}

// @0x1413ac520
CStringW CGuideConditionConstructSlot::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(GcFmtSlot(L"slotIdx({0}), isIndoor({1}), isOutDoor({2})", m_nSlotIdx, m_bIndoor, m_bOutdoor));
    return str;
}

// @0x1413ac5f0
ClassObject* CGuideConditionTitle::CreateObject()
{
    return new CGuideConditionTitle;
}

// @0x1413ac650
CStringW CGuideConditionTitle::vfunc_1()
{
    return L"CGuideConditionTitle";
}

// @0x1413ac6a0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionTitle::vfunc_3()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    return FUN_1413a5600(DAT_143ab3268.FUN_140186270() != 0);
}

// @0x1413ac700
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionTitle::vfunc_5()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0) {
        size_t nCount = DAT_143ab3268.FUN_140186270();
        FUN_1412751b0(GcFmtSize(L"CGuideConditionTitle> titleCount={0}", nCount), 0x14);
    }
}

// @0x1413ac790
ClassObject* CGuideConditionServerTime::CreateObject()
{
    return new CGuideConditionServerTime;
}

// @0x1413ac7f0
CStringW CGuideConditionServerTime::vfunc_1()
{
    return L"CGuideConditionServerTime";
}

// @0x1413ac840
void CGuideConditionServerTime::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_140873600(pElem, "dateTime", m_time);
}

// @0x1413ac890
int CGuideConditionServerTime::vfunc_3()
{
    Unk_GcTime now;
    now.FUN_1406c47a0(FUN_140869440());
    return FUN_1413a5600(m_time.FUN_1406c4cc0(now));
}

// @0x1413ac8e0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
void CGuideConditionServerTime::vfunc_5()
{
    Unk_GcTime now;
    now.FUN_1406c47a0(FUN_140869440());
    Unk_GcTime target;
    target.FUN_1406c47d0(2015, 4, 21, 16, 0, 0);
    m_time.FUN_1406c4930(target);
    CStringW strNow = FUN_14083bdc0(now, 1, CStringW(L"/"), CStringW(L":"));
    CStringW strTarget = FUN_14083bdc0(m_time, 1, CStringW(L"/"), CStringW(L":"));
    FUN_1412751b0(GcFmtStr(L"curTime={0}", strNow), 0x14);
    FUN_1412751b0(GcFmtStr(L"targetTime={0}", strTarget), 0x14);
    bool bPassed = m_time.FUN_1406c4cc0(now);
    FUN_1412751b0(GcFmtStr(L"(passed)={0}", FUN_140719730(bPassed)), 0x14);
}

// @0x1413acbe0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionServerTime::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    Unk_GcTime t;
    t.FUN_1406c47a0(m_time.FUN_140282020());
    CStringW strTime = FUN_14083bdc0(t, 1, CStringW(L"/"), CStringW(L":"));
    str.Append(GcFmtStr(L"dateTime({0})", strTime));
    return str;
}

// @0x1413acd60
ClassObject* CGuideConditionHasManufacture::CreateObject()
{
    return new CGuideConditionHasManufacture;
}

// @0x1413acdc0
CStringW CGuideConditionHasManufacture::vfunc_1()
{
    return L"CGuideConditionHasManufacture";
}

// @0x1413ace10
int CGuideConditionHasManufacture::vfunc_3()
{
    return FUN_140d513c0(FUN_1409eed40());
}

// @0x1413ace40
ClassObject* CGuideConditionHasMoney::CreateObject()
{
    return new CGuideConditionHasMoney;
}
