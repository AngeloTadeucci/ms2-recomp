// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition base class CGuideCondition and the conditions
// False / Trigger / Timeout (part 9 of client\ms2\guideentity.cpp, the class tail). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: client\ms2\guideentity.cpp#9
// MS2-RANGE: 0x1413a54e0-0x1413a6010 .text$mn
// MS2-RANGE: 0x1413b4200-0x1413b4240 .text$mn
// MS2-RANGE: 0x1413b5380-0x1413b53c0 .text$mn
// MS2-RANGE: 0x1413b5400-0x1413b5440 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/xmlattr.h"
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
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a1, const int& a2);   // StringFormat<int, int>

// The [min, max] pair of the trigger range: valid when max >= min and not both 0.
struct Unk_GeRange { int m_nMin; int m_nMax; };
Unk_GeRange* FUN_1405c38a0(Unk_GeRange* pRange);                        // zero
char FUN_1405c7ba0(const Unk_GeRange* pRange);                          // is set
int FUN_1413b1d60(Unk_140165cf0* pElem, const char* pszName, Unk_GeRange* pOut);
char FUN_140d1a9d0(const Unk_GcOptInt* pOpt);                           // Nullable<int>::HasValue
const int* FUN_1413989f0(const Unk_GcOptInt* pOpt);                     // Nullable<int>::GetValue
Unk_GcOptInt* FUN_140d11940(Unk_GcOptInt* pOpt);                        // Nullable<int>()

// The guide manager: the trigger events that were raised.
class Unk_GeMgr
{
public:
    char FUN_14138c0d0(int nTrigger, Unk_GcOptInt oValue, Unk_GcOptInt oSubValue);
    char FUN_14138c210(int nTrigger, Unk_GeRange range);
};
Unk_GeMgr* FUN_1409331e0();

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
