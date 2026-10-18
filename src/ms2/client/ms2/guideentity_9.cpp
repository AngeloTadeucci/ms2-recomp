// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition base class CGuideCondition and the conditions
// False / Trigger / Timeout (part 9 of client\ms2\guideentity.cpp, the class tail). See ms2/placeholder/cguidecondition.h.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: client\ms2\guideentity.cpp#9
// MS2-RANGE: 0x1413a2c00-0x1413a3c60 .text$mn
// MS2-RANGE: 0x1413a5130-0x1413a54e0 .text$mn
// MS2-RANGE: 0x1413a54e0-0x1413a6010 .text$mn
// MS2-RANGE: 0x1413b4200-0x1413b4240 .text$mn
// MS2-RANGE: 0x1413b5380-0x1413b53c0 .text$mn
// MS2-RANGE: 0x1413b5400-0x1413b5440 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\guideentity.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/client/ms2/guideentity.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_1408730a0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);
const char* FUN_14086f4b0(Unk_140165cf0* pElem, const char* pszName);   // attribute text (null = absent)
int FUN_1413b1d00(Unk_140165cf0* pElem, const char* pszName, Unk_GcOptInt& oOut);
int FUN_1413b1fc0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
void FUN_1412751b0(const CStringW& text, int a);                        // the debug log
unsigned FUN_140869420();                                               // millisecond clock
bool FUN_1413a4b50();                                                   // false (outside the unit range)
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a1, const int& a2);   // StringFormat<int, int>

// The [min, max] pair of the trigger range: valid when max >= min and not both 0.
struct Unk_GeRange { int m_nMin; int m_nMax; };
Unk_GeRange* FUN_1405c38a0(Unk_GeRange* pRange);                        // zero
char FUN_1405c7ba0(const Unk_GeRange* pRange);                          // is set
int FUN_1413b1d60(Unk_140165cf0* pElem, const char* pszName, Unk_GeRange* pOut);
char FUN_140d1a9d0(const Unk_GcOptInt* pOpt);                           // Nullable<int>::HasValue
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);                     // Nullable<int>::GetValue
Unk_GcOptInt* FUN_140d11940(Unk_GcOptInt* pOpt);                        // Nullable<int>()

Unk_140165cf0* FUN_140345b40(Unk_140165cf0* pElem);                     // the first child node
bool FUN_140184310(const CStringA& str, const char* psz);               // equal (case-sensitive)
Unk_GcCondRef FUN_1413a5420(CStringA strTag);                           // the condition class of a tag
CStringW FUN_1402a5170(const wchar_t* szFormat, const CStringA& strArg);   // StringFormat with one string
CStringA FUN_140540050(const char* szFormat, const CStringA& strArg);
void* FUN_1413a4f30(void* pMap);                                        // the node allocator of a map
void* FUN_141395500(void* pNode);
Unk_GeActRef FUN_141382b90(Unk_140165cf0* pElem);                       // builds the action of an <action> element
// The condition / action lists hold 16-byte handles (the shared placeholder declares them as pointer arrays).
#define GE_REFS(list) reinterpret_cast<ATL::CAtlArray<Unk_GcCondRef>&>((list).m_arr)

// The guide manager: the trigger events that were raised.
class Unk_GeMgr
{
public:
    void FUN_14138d7e0(int nId, int nValue);
    char FUN_14138c0d0(int nTrigger, Unk_GcOptInt oValue, Unk_GcOptInt oSubValue);
    char FUN_14138c210(int nTrigger, Unk_GeRange range);
};
Unk_GeMgr* FUN_1409331e0();

// ---- the glue in front of the base class: allocator limit, checked memmove, the condition factory ------------------------------

// @0x1413a5130
unsigned __int64 FUN_1413a5130()
{
    return 0x666666666666666;
}

// @0x1413a5140
unsigned __int64 FUN_1413a5140(void* pMap)
{
    FUN_1413a4f30(pMap);
    return FUN_1413a5130();
}

// @0x1413a5160
void* FUN_1413a5160(void* pNode)
{
    return FUN_141395500(pNode);
}

// @0x1413a5180
errno_t FUN_1413a5180(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount)
{
    return memmove_s(pDst, nDstSize, pSrc, nCount);
}

// @0x1413a52a0
tm* FUN_1413a52a0(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// @0x1413a52c0
Unk_GcCondRef FUN_1413a52c0(Unk_140165cf0* pElem)
{
    CStringA strTag(FUN_14086f4b0(pElem, "type"));
    Unk_GcCondRef ref = FUN_1413a5420(strTag);
    if (ref.FUN_141387b90())
    {
        ref.FUN_141387bb0()->vfunc_2(pElem);
        Unk_GcCondRef out;
        out.FUN_1413b2880(ref);
        ref.FUN_141387660();
        return out;
    }
    throw std::exception(FUN_140540050("Unknown Guide Condition Tag({0})", strTag));
}

// @0x1413a5420
Unk_GcCondRef FUN_1413a5420(CStringA strTag)
{
    Unk_GcCondRef ref;
    ref.FUN_1413b28b0(static_cast<CGuideCondition*>(FUN_1401f7f50(FUN_1402a5170(L"CGuideCondition{0}", strTag))));
    Unk_GcCondRef out;
    out.FUN_1413b2880(ref);
    ref.FUN_141387660();
    return out;
}

// ---- CGuideCondition ------------------------------------------------------------------------------------------------------

// @0x1413a54e0
CGuideCondition::CGuideCondition()
{
    m_n18 = 0;
    m_b1c = false;
    m_n20 = 0;
}

// @0x1413a5540
CGuideCondition::~CGuideCondition()
{
}

// @0x1413a5570
int FUN_1413a5570(CGuideCondition* pCond)
{
    return pCond->vfunc_3();
}

// @0x1413a55a0
int CGuideCondition::FUN_1413a55a0(int nResult)
{
    if (m_b1c)
        nResult = (nResult == 0);
    return nResult;
}

// @0x1413a5600
int CGuideCondition::FUN_1413a5600(bool bResult)
{
    if (m_b1c)
        return !bResult;
    return bResult;
}

// @0x1413a5670
void CGuideCondition::vfunc_2(Unk_140165cf0* pElem)
{
    FUN_1408731e0(pElem, "value", m_n20);
    FUN_1408730a0(pElem, "not", m_b1c);
}

// @0x1413a56d0
int CGuideCondition::vfunc_3()
{
    return 0;
}

// @0x1413a56e0
void CGuideCondition::vfunc_4()
{
}

// @0x1413a56f0
void CGuideCondition::vfunc_5()
{
    FUN_1412751b0(CStringW(L"Nothing TestCase"), 20);
}

// @0x1413a5740
bool CGuideCondition::vfunc_6(Unk_GcCondList* pFailed)
{
    return false;
}

// @0x1413a5760
CStringW CGuideCondition::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"value({0})", m_n20));
    return str;
}

// @0x1413a5810
int CGuideCondition::vfunc_8()
{
    return 0;
}

// @0x1413a5820
CStringW CGuideCondition::FUN_1413a5820()
{
    CStringW str = StringFormat(L"{0}:", vfunc_1());
    if (m_b1c)
        str.Append(L"not ");
    return str;
}

// ---- CGuideConditionFalse -------------------------------------------------------------------------------------------------

// @0x1413a58e0
ClassObject* CGuideConditionFalse::CreateObject()
{
    return new CGuideConditionFalse;
}

// @0x1413a5940
CStringW CGuideConditionFalse::vfunc_1()
{
    return L"CGuideConditionFalse";
}

// @0x1413a5990
int CGuideConditionFalse::vfunc_3()
{
    return 0;
}

// ---- CGuideConditionTrigger -----------------------------------------------------------------------------------------------

// @0x1413a59a0
ClassObject* CGuideConditionTrigger::CreateObject()
{
    return new CGuideConditionTrigger;
}

// @0x1413a5a00
CStringW CGuideConditionTrigger::vfunc_1()
{
    return L"CGuideConditionTrigger";
}

// @0x1413a5a50
CGuideConditionTrigger::CGuideConditionTrigger()
{
    m_n28 = 0;
}

// @0x1413a5ad0
void CGuideConditionTrigger::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_1413b1fc0(pElem, "trigger", m_n28);
    FUN_1413b1d00(pElem, "value", m_a);
    FUN_1413b1d00(pElem, "subValue", m_b);
    if (FUN_14086f4b0(pElem, "range") != 0)
        FUN_1413b1d60(pElem, "range", reinterpret_cast<Unk_GeRange*>(&m_n3c));
    if (m_n28 == 0)
        throw std::exception("Unknown Guide Trigger Tag");
}

// @0x1413a5bb0
int CGuideConditionTrigger::vfunc_3()
{
    if (FUN_1405c7ba0(reinterpret_cast<Unk_GeRange*>(&m_n3c)) == 0)
        return FUN_1413a55a0(FUN_1409331e0()->FUN_14138c0d0(m_n28, m_a, m_b) != 0);
    return FUN_1413a55a0(FUN_1409331e0()->FUN_14138c210(m_n28, *reinterpret_cast<Unk_GeRange*>(&m_n3c)) != 0);
}

// @0x1413a5c80
CStringW CGuideConditionTrigger::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"type({0})", reinterpret_cast<const Unk_GcEnum1&>(m_n28)));
    if (FUN_140d1a9d0(&m_a))
        str.Append(StringFormat(L" ,value({0})", *FUN_1413989f0(&m_a)));
    if (FUN_140d1a9d0(&m_b))
        str.Append(StringFormat(L" ,subValue({0})", *FUN_1413989f0(&m_b)));
    str.Append(FUN_14083dc40(L" ,range({0}-{1})", m_n3c, m_n40));
    return str;
}

// ---- CGuideConditionTimeout -----------------------------------------------------------------------------------------------

// @0x1413a5e90
ClassObject* CGuideConditionTimeout::CreateObject()
{
    return new CGuideConditionTimeout;
}

// @0x1413a5ef0
CStringW CGuideConditionTimeout::vfunc_1()
{
    return L"CGuideConditionTimeout";
}

// @0x1413a5f40
CGuideConditionTimeout::CGuideConditionTimeout()
{
    m_n28 = 0;
}

// @0x1413a5f80
int CGuideConditionTimeout::vfunc_3()
{
    if (m_n28 == 0)
        m_n28 = FUN_140869420() + m_n20;
    return FUN_1413a5600((unsigned)m_n28 <= FUN_140869420());
}

// @0x1413a5fe0
void CGuideConditionTimeout::vfunc_4()
{
    CGuideCondition::vfunc_4();
    m_n28 = 0;
}

// ---- CGuideEntity ---------------------------------------------------------------------------------------------------------

// @0x1413a2c00
unsigned CGuideEntity::GetSaveId() const
{
    return m_nSaveId;
}

// @0x1413a2c20
unsigned CGuideEntity::GetSaveStep() const
{
    return m_nSaveStep;
}

// @0x1413a2c40
int CGuideEntity::GetForce() const
{
    return m_nForce;
}

// @0x1413a2c60
bool CGuideEntity::IsSaveSkipped() const
{
    return m_nSaveId == 0 || m_nNoSave != 0;
}

// @0x1413a2ca0
int CGuideEntity::CheckStart(bool* pbOpen, unsigned* pnFailed)
{
    for (unsigned i = 0; i < m_condTrigger.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condTrigger.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            *pbOpen = true;
            return 0;
        }
    }
    for (unsigned i = 0; i < m_condOpen.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condOpen.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            *pbOpen = false;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2dd0
int CGuideEntity::CheckClose(unsigned* pnFailed)
{
    for (unsigned i = 0; i < m_condClose.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condClose.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2e70
int CGuideEntity::CheckCancel(unsigned* pnFailed)
{
    if (GE_REFS(m_condCancel).IsEmpty())
        return 0;
    for (unsigned i = 0; i < m_condCancel.FUN_1413886d0(); ++i)
    {
        if (FUN_1413a5570(m_condCancel.FUN_141387b40(i).FUN_141387bb0()) == 0)
        {
            if (pnFailed != 0)
                *pnFailed = i;
            return 0;
        }
    }
    return 1;
}

// @0x1413a2f30
void CGuideEntity::GetFailedText(CStringW& strOut, bool bTrigger, unsigned nIdx)
{
    if (!bTrigger)
    {
        if (nIdx < m_condOpen.FUN_1413886d0())
            strOut = m_condOpen.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
    }
    else
    {
        if (nIdx < m_condTrigger.FUN_1413886d0())
            strOut = m_condTrigger.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
    }
}

// @0x1413a30a0
void CGuideEntity::GetCloseText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx < m_condClose.FUN_1413886d0())
        strOut = m_condClose.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
}

// @0x1413a3150
void CGuideEntity::GetCancelText(CStringW& strOut, unsigned nIdx)
{
    if (nIdx < m_condCancel.FUN_1413886d0())
        strOut = m_condCancel.FUN_141387b40(nIdx).FUN_141387bb0()->vfunc_7();
}

// @0x1413a3210
void CGuideEntity::StartActions()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
        m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_3();
}

// @0x1413a32a0
void CGuideEntity::StopActions()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
        m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_4();
}

// @0x1413a3330
int CGuideEntity::AreActionsDone()
{
    for (unsigned i = 0; i < m_actions.FUN_1413886c0(); ++i)
    {
        if (m_actions.FUN_141387b00(i).FUN_141387ba0()->vfunc_5() == 0)
            return 0;
    }
    return 1;
}

// @0x1413a33c0
bool CGuideEntity::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    FUN_140873220(pElem, "saveId", m_nSaveId);
    FUN_140873220(pElem, "saveStep", m_nSaveStep);
    FUN_1408731e0(pElem, "isForce", m_nForce);
    FUN_1408731e0(pElem, "isNoSave", m_nNoSave);
    if (!FUN_1413a4b50())
        FUN_140873420(pElem, "desc", m_strDesc);
    for (Unk_140165cf0* pChild = FUN_140345b40(pElem); pChild != 0; pChild = pChild->NextSiblingElement())
    {
        CStringA strName(pChild->Value());
        if (FUN_140184310(strName, "open"))
            LoadConditions(pChild, m_condOpen);
        else if (FUN_140184310(strName, "close"))
            LoadConditions(pChild, m_condClose);
        else if (FUN_140184310(strName, "cancel"))
            LoadConditions(pChild, m_condCancel);
        else if (FUN_140184310(strName, "openAction"))
            LoadActions(pChild, m_actions);
    }
    return true;
}

// @0x1413a35d0
void CGuideEntity::Clear(bool bNotify)
{
    if (m_nState == 1 || m_nState == 2)
        StopActions();
    if (!bNotify)
        m_nState = 0;
    else
        SetState(0);
    ResetConditions(m_condOpen);
    ResetConditions(m_condClose);
    ResetConditions(m_condCancel);
}

// @0x1413a3670
void CGuideEntity::SetState(int nState)
{
    m_nState = nState;
    FUN_1409331e0()->FUN_14138d7e0(13, 0);
}

// @0x1413a36b0
void CGuideEntity::UpdateConditions()
{
    PruneConditions(m_condOpen);
    PruneConditions(m_condClose);
    PruneConditions(m_condCancel);
}

// @0x1413a3710
void FUN_1413a3710()
{
}

// @0x1413a3720
void CGuideEntity::MoveStartedConditions()
{
    Unk_GcCondList keep;
    for (unsigned i = 0; i < m_condOpen.FUN_1413886d0(); ++i)
    {
        if (m_condOpen.FUN_141387b40(i).FUN_141387bb0()->m_n18 == 0)
            keep.FUN_141388460(m_condOpen.FUN_141387b40(i));
        else
            m_condTrigger.FUN_141388460(m_condOpen.FUN_141387b40(i));
    }
    GE_REFS(m_condOpen).RemoveAll();
    GE_REFS(m_condOpen).Append(GE_REFS(keep));
}

// @0x1413a3820
void CGuideEntity::CollectTriggerValues(std::map<int, int>& mapValues)
{
    for (unsigned i = 0; i < m_condTrigger.FUN_1413886d0(); ++i)
    {
        int nKind = m_condTrigger.FUN_141387b40(i).FUN_141387bb0()->m_n18;
        if (nKind != 0)
        {
            int nValue = m_condTrigger.FUN_141387b40(i).FUN_141387bb0()->vfunc_8();
            std::map<int, int>::iterator it = mapValues.find(nKind);
            if (it != mapValues.end())
                it->second = 0;
            else
                mapValues.insert(std::make_pair(nKind, nValue));
        }
    }
}

// @0x1413a3960
void CGuideEntity::LoadConditions(Unk_140165cf0* pElem, Unk_GcCondList& list)
{
    for (Unk_140165cf0* pCond = pElem->FUN_140165cf0("condition"); pCond != 0; pCond = pCond->FUN_140168650("condition"))
    {
        Unk_GcCondRef ref = FUN_1413a52c0(pCond);
        MS2_ASSERT_AT(200, ref.m_p != 0);
        if (ref.FUN_141387b90())
            list.FUN_141388460(ref);
        ref.FUN_141387660();
    }
}

// @0x1413a3a30
void CGuideEntity::LoadActions(Unk_140165cf0* pElem, Unk_GeActList& list)
{
    for (Unk_140165cf0* pAct = pElem->FUN_140165cf0("action"); pAct != 0; pAct = pAct->FUN_140168650("action"))
    {
        Unk_GeActRef ref = FUN_141382b90(pAct);
        MS2_ASSERT_AT(212, ref.m_p != 0);
        if (ref.FUN_141387ba0() != 0)
            list.FUN_1413883b0(ref);
        ref.FUN_141387630();
    }
}

// @0x1413a3b00
void CGuideEntity::PruneConditions(Unk_GcCondList& list)
{
    Unk_GcCondList keep;
    for (unsigned i = 0; i < list.FUN_1413886d0(); ++i)
    {
        if (!list.FUN_141387b40(i).FUN_141387bb0()->vfunc_6(&keep))
            keep.FUN_141388460(list.FUN_141387b40(i));
    }
    GE_REFS(list).RemoveAll();
    GE_REFS(list).Append(GE_REFS(keep));
}

// @0x1413a3be0
void CGuideEntity::ResetConditions(Unk_GcCondList& list)
{
    for (unsigned i = 0; i < list.FUN_1413886d0(); ++i)
        list.FUN_141387b40(i).FUN_141387bb0()->vfunc_4();
}
