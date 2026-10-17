// MS2-UNIT: commonfiles\itemoptiondata.cpp#2
// MS2-RANGE: 0x1405ce250-0x1405f4140 .text$mn
// MS2-RANGE: 0x1400ba650-0x1400ba710 .text$di
// MS2-RANGE: 0x142c9b220-0x142c9b250 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemoptiondata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <ppl.h>
#include <math.h>
#include <algorithm>
#include "itemoption.h"
#include "itemoptiondata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/randomeffectparam.h"
#include "ms2/placeholder/citemoptiontable.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

static CString s_sortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

MS2Ptr<CItemData> FUN_14053f870(int nItemId);          // the item data of an item id
int FUN_14082ee80(const CStringA& strName);             // stat name -> id (-1 when none)
int FUN_14081d260(const CStringA& strName);             // special option name -> id (0 when none)
const CString& FUN_14082efb0(int nStat);                // the xml name of a stat
const CString& FUN_14081d380(int nStat);                // the xml name of a special stat
bool FUN_14082f1d0(int nStat);
bool FUN_14081dc50(int nStat);
int FUN_14081d830(int nStat);                           // the special stat is a special ability
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_14015f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);
void FUN_14028f5d0(Unk_140165cf0* pParent, const char* pszChild, std::vector<Unk_140165cf0*>& arrOut);
extern "C" double (__cdecl* __imp_floor)(double);
CItemOptionTable* FUN_140166430();                      // the option table singleton
CLogString* FUN_140166440();                            // the log
// The log's two-argument call (FMT_VARIADIC instantiation outside this unit).
void FUN_1401e0850(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszFormat, const CString& first,
                   const int& second);
int FUN_14081d650(MS2Ptr<CItemOption> spOption, int nGroup, unsigned nSpecial);   // the special stat is blocked
int FUN_140768010(int nRange, int nBase);               // random number in [nBase, nBase + nRange)
// probability.cpp: the roll logs
bool FUN_14073ede0(int nProbVer, int nStatId, int nValue, Unk_ProbabilityLog* pLogs);
void FUN_14073e750(int nProbVer, int nCode, const Unk_ItemOptionValuePicker& picker,
                   const std::vector<ItemOptionValueRandom*>& vPicked,
                   const std::vector<MS2Ptr<ItemOptionValueRandom> >& vLocked,
                   std::pair<ItemOptionValueRandom*, double>* pArmor, std::pair<ItemOptionValueRandom*, double>* pSpecial,
                   Unk_ProbabilityLog* pLogs);
template <class E> int XmlValueByName(Unk_140165cf0* pElem, const char* pszName, E& eOut);   // additionalactionadditional.cpp   // the IAT floor (<math.h> declares it static-CRT)

// @0x1405ce250
ItemOptionValue::ItemOptionValue()
{
    m_nValue = 0;
    m_nStat = -1;
    m_nSpecial = 0;
}

// @0x1405ce2b0
ItemOptionValue::ItemOptionValue(int nStat)
{
    m_nValue = 0;
    m_nStat = nStat;
    m_nSpecial = 0;
}

// @0x1405ce310
ItemOptionValue::ItemOptionValue(unsigned nSpecial)
{
    m_nValue = 0;
    m_nStat = -1;
    m_nSpecial = nSpecial;
}

// @0x1405ce370
int ItemOptionValue::FUN_1405ce370()
{
    return m_nStat;
}

// @0x1405ce390
unsigned ItemOptionValue::FUN_1405ce390()
{
    return m_nSpecial;
}

// @0x1405ce3b0
bool ItemOptionValue::FUN_1405ce3b0()
{
    return m_nValue != 0;
}

// @0x1405ce3f0
bool ItemOptionValue::FUN_1405ce3f0()
{
    if (FUN_1405ce370() != -1)
        return FUN_14082f1d0(FUN_1405ce370());
    else if (FUN_1405ce390() != 0)
        return FUN_14081dc50(FUN_1405ce390());
    MS2_ASSERT_AT(0x3b, 0);
    return true;
}

// @0x1405ce470
BOOL ItemOptionValue::FUN_1405ce470()
{
    if (FUN_1405ce370() != -1)
        return FALSE;
    return TRUE;
}

// @0x1405ce4a0
CString ItemOptionValue::FUN_1405ce4a0()
{
    int nStat = FUN_1405ce370();
    if (nStat != -1)
        return FUN_14082efb0(nStat);
    return FUN_14081d380(FUN_1405ce390());
}

// @0x1405ce530
int ItemOptionValue::FUN_1405ce530()
{
    return m_nValue;
}

// @0x1405ce550
void ItemOptionValue::FUN_1405ce550(int nValue)
{
    m_nValue = nValue;
}

// @0x1405ce570
int ItemOptionValue::vfunc_1(unsigned nItemId, int nRank)
{
    return m_nValue;
}

// @0x1405ce590
ItemOptionValueRef::ItemOptionValueRef()
{
    m_nLuaIndex = 0;
}

// @0x1405ce5d0
ItemOptionValueRef::ItemOptionValueRef(int nStat) : ItemOptionValue(nStat)
{
    m_nLuaIndex = 0;
}

// @0x1405ce620
ItemOptionValueRef::ItemOptionValueRef(unsigned nSpecial) : ItemOptionValue(nSpecial)
{
    m_nLuaIndex = 0;
}

// @0x1405ce670
// MS2-FUNCTIONAL: stack frame 0x10 smaller (one exe temp not reproduced)
int ItemOptionValueRef::FUN_1405ce670(unsigned nItemId, int nRank)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (m_nLuaIndex == 0)
        return 0;
    int nLevel = spItem->FUN_14053f0a0();
    int nStat = spItem->FUN_14053c620();
    int nJob = FUN_1405d2410(spItem);
    switch (FUN_1405ce370())
    {
    case 0:
        return FUN_1405cfd50(nStat, nJob, spItem->FUN_14053f080());
    case 1:
        return FUN_1405cfec0(nStat, nJob, spItem->FUN_14053f080());
    case 2:
        return FUN_1405d0030(nStat, nJob, spItem->FUN_14053f080(), spItem->limit.recommendJobs.size() > 1);
    case 3:
        return FUN_1405d01e0(nStat, nJob, spItem->FUN_14053f080());
    case 4:
        if (m_nLuaIndex == 1)
            return FUN_1405cf6e0(nStat, nLevel, nRank, spItem->FUN_14053f080());
        else if (m_nLuaIndex == 3)
            return FUN_1405cfb10(nStat, nLevel);
        else if (m_nLuaIndex == 4)
            return FUN_1405cf6e0(nStat, nLevel, nRank, spItem->FUN_14053f080()) + FUN_1405cfb10(nStat, nLevel);
        break;
    case 0x11:
        return FUN_1405d0340(nStat, nRank);
    case 0x14:
        if (m_nLuaIndex == 1)
            return FUN_1405d04a0(nStat, nJob, nLevel, nRank, spItem->FUN_14053f080());
        else if (m_nLuaIndex == 3)
            return FUN_1405d0780(nStat, nJob, nLevel, nRank, spItem->FUN_14053f080());
        else if (m_nLuaIndex == 4)
            return FUN_1405d04a0(nStat, nJob, nLevel, nRank, spItem->FUN_14053f080())
                + FUN_1405d0780(nStat, nJob, nLevel, nRank, spItem->FUN_14053f080());
        break;
    case 0x15:
        return FUN_1405cfd10(nLevel);
    case 0x17:
        return FUN_1405cf650(nStat, nLevel);
    case 0x18:
        if (m_nLuaIndex == 1)
            return FUN_1405cf510(nLevel, nRank);
        else if (m_nLuaIndex == 3)
            return FUN_1405cf650(nStat, nLevel);
        else if (m_nLuaIndex == 4)
            return FUN_1405cf510(nLevel, nRank) + FUN_1405cf650(nStat, nLevel);
        break;
    case 0x19:
        return FUN_1405cf260(nStat, nLevel, nRank);
    case 0x1a:
        if (m_nLuaIndex == 1)
            return FUN_1405cf350(nStat, nLevel, nRank);
        else if (m_nLuaIndex == 3)
            return FUN_1405cf430(nStat, nLevel, nRank);
        else if (m_nLuaIndex == 4)
            return FUN_1405cf350(nStat, nLevel, nRank) + FUN_1405cf430(nStat, nLevel, nRank);
        break;
    case 0x1b:
        return FUN_1405d0c10(m_nLuaIndex, nStat, nLevel, nRank, spItem->FUN_14053f080(), true);
    case 0x1c:
        if (m_nLuaIndex == 1 || m_nLuaIndex == 2)
            return FUN_1405d0c10(m_nLuaIndex, nStat, nLevel, nRank, spItem->FUN_14053f080(), false);
        else if (m_nLuaIndex == 4)
            return FUN_1405d0c10(1, nStat, nLevel, nRank, spItem->FUN_14053f080(), false)
                + FUN_1405d0dd0(m_nLuaIndex, nStat, nLevel, nRank, spItem->FUN_14053f080());
        else if (m_nLuaIndex == 5)
            return FUN_1405d0c10(2, nStat, nLevel, nRank, spItem->FUN_14053f080(), false)
                + FUN_1405d0dd0(m_nLuaIndex, nStat, nLevel, nRank, spItem->FUN_14053f080());
        break;
    }
    MS2_ASSERT_AT(0xd2, 0);
    return 0;
}

// @0x1405cf1e0
int ItemOptionValueRef::vfunc_1(unsigned nItemId, int nRank)
{
    int nRef = FUN_1405ce670(nItemId, nRank);
    int nValue = 0;
    if (m_nValue != 0)
        nValue += m_nValue;
    if (nRef > 0)
        nValue += nRef;
    return nValue;
}

// @0x1405cf260
int ItemOptionValueRef::FUN_1405cf260(int nStat, int nLevel, int nRank)
{
    switch (nStat)
    {
    case 0x12:
        return (int)FUN_1405d1850(nLevel, 3.0, 1.0, FUN_1405d19f0(nRank));
    case 0x13:
        return (int)FUN_1405d1850(nLevel, 3.0, 1.5, FUN_1405d19f0(nRank));
    case 0x28:
        return FUN_1405d1960(nRank);
    case 0x15:
        return FUN_1405d17c0(nLevel, 1.0);
    }
    return 0;
}

// @0x1405cf350
int ItemOptionValueRef::FUN_1405cf350(int nStat, int nLevel, int nRank)
{
    switch (nStat)
    {
    case 0xc:
        return (int)FUN_1405d18a0(nLevel, 4.5, 1.0, FUN_1405d19f0(nRank));
    case 0x14:
        return (int)FUN_1405d18a0(nLevel, 4.0, 1.5, FUN_1405d19f0(nRank));
    case 0x28:
    case 0x29:
        return FUN_1405d1960(nRank);
    }
    return 0;
}

// @0x1405cf430
int ItemOptionValueRef::FUN_1405cf430(int nStat, int nLevel, int nRank)
{
    switch (nStat)
    {
    case 0x28:
        return FUN_1405d17c0(nLevel, 1.0);
    default:
        {
            double dScale = 1.0;
            switch (nRank)
            {
            case 1: dScale = 0.4; break;
            case 2: dScale = 0.55; break;
            case 3: dScale = 0.7; break;
            case 4: dScale = 0.85; break;
            }
            return FUN_1405d17c0(nLevel, dScale);
        }
    }
}

// @0x1405cf510
int ItemOptionValueRef::FUN_1405cf510(int nLevel, int nRank)
{
    double dScale = 1.0;
    switch (nRank)
    {
    case 1: dScale = 0.925; break;
    case 2: dScale = 1.0175; break;
    case 3: dScale = 1.11; break;
    case 4: dScale = 1.2025; break;
    case 5:
    case 6: dScale = 1.2825; break;
    }
    if (nLevel < 58)
        return (int)round(round(nLevel * 0.5502 + 0.1806) * dScale);
    nLevel -= nLevel % 2;
    return (int)round((nLevel * 0.2751 + 16.136) * dScale);
}

// @0x1405cf650
int ItemOptionValueRef::FUN_1405cf650(int nStat, int nLevel)
{
    double dValue = FUN_1405d18f0(nLevel, -3.8e-06, 0.0009, 0.0294);
    if (nStat >= 50 && nStat <= 56)
        dValue *= 1.8;
    return (int)(3.0 + round(dValue));
}

// @0x1405cf6e0
// MS2-FUNCTIONAL: the pow(1.0 + dGrowth, n) argument is built in xmm1 in the exe
int ItemOptionValueRef::FUN_1405cf6e0(int nStat, int nLevel, int nRank, int nOptionLevel)
{
    switch (nStat)
    {
    case 0xc:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
        if (nLevel <= 50)
            return 0;
        if (nOptionLevel < 60 && nRank >= 5 && nLevel >= 53)
        {
            double dBase = 600.0;
            double dScale = 0.6;
            double dGrowth = 0.06;
            double dStart = dBase * dScale;
            return (int)round(dStart * std::pow(1.0 + dGrowth, nLevel - 53));
        }
        else if (nOptionLevel >= 60 && nRank >= 4)
        {
            double dBase = 600.0;
            double dScale = 0.6;
            double dGrowth = 0.06;
            if (nRank == 4)
                dBase *= 0.6;
            else if (nRank == 6)
                dBase *= 1.2624;
            double dStart = dBase * dScale;
            return (int)round(dStart * std::pow(1.0 + dGrowth, nLevel - ((nLevel / 10 - 6) * 6 + 53)));
        }
        else
            return (int)round((nLevel - 50) * 6.5);
        break;
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        if (nLevel <= 5)
            return 0;
        {
            double dRank = 0.3;
            switch (nRank)
            {
            case 1: dRank = 0.3; break;
            case 2: dRank = 0.4; break;
            case 3: dRank = 0.5; break;
            case 4: dRank = 0.6; break;
            case 5: dRank = 0.7; break;
            case 6: dRank = 0.8; break;
            }
            double dStat = 0.1;
            switch (nStat)
            {
            case 0x1f:
            case 0x22:
                dStat = 0.3;
                break;
            case 0x20:
                dStat = 0.04;
                break;
            case 0x33:
            case 0x34:
            case 0x36:
            case 0x37:
                dStat = 0.2;
                break;
            case 0x32:
            case 0x35:
            case 0x38:
                dStat = 0.4;
                break;
            }
            return (int)round(nLevel * 1.2884 - dRank * dStat * 6.56);
        }
    }
    return 0;
}

// @0x1405cfb10
int ItemOptionValueRef::FUN_1405cfb10(int nStat, int nLevel)
{
    double dValue = FUN_1405d18f0(nLevel, -7e-05, 0.0162, 0.1656) - 0.5098;
    if (nStat == 0x16)
        dValue *= 1.8;
    int nValue = (int)round(dValue);
    if (nValue <= 6)
        nValue += 4;
    else if (nValue <= 8)
        nValue += 5;
    else if (nValue <= 10)
        nValue += 6;
    else if (nValue <= 13)
        nValue += 7;
    else if (nValue <= 15)
        nValue += 8;
    else if (nValue <= 19)
        nValue += 9;
    else if (nValue <= 21)
        nValue += 10;
    else if (nValue <= 24)
        nValue += 11;
    else if (nValue <= 27)
        nValue += 12;
    else if (nValue <= 31)
        nValue += 13;
    else if (nValue <= 36)
        nValue += 14;
    else if (nValue <= 41)
        nValue += 15;
    else if (nValue <= 45)
        nValue += 16;
    else if (nValue <= 52)
        nValue += 17;
    else if (nValue <= 62)
        nValue += 18;
    else if (nValue <= 74)
        nValue += 19;
    else if (nValue >= 75)
        nValue += 20;
    return nValue;
}

// @0x1405cfd10
int ItemOptionValueRef::FUN_1405cfd10(int nLevel)
{
    return (int)round(1.6 * nLevel + 75.4);
}

// @0x1405cfd50
int ItemOptionValueRef::FUN_1405cfd50(int nStat, int nJob, int nOptionLevel)
{
    double dJob = 0.0;
    double dLevel = 0.0;
    double dStat = 1.0;
    if (nOptionLevel <= 50)
    {
        if (nStat == 0x16)
            dStat = 1.8;
        dLevel = nOptionLevel - 20;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 10:
        case 20:
        case 90:
            dJob = 2.0;
            break;
        }
    }
    else
    {
        if (nStat == 0x16)
            dStat = 1.8;
        else
            dStat = 2.0;
        dLevel = nOptionLevel * 2 - 90;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 10:
        case 20:
        case 90:
            dJob = 3.0;
            break;
        }
    }
    if (dJob == 0.0)
        return 0;
    return (int)round(dLevel / 6.0 * dJob * dStat);
}

// @0x1405cfec0
int ItemOptionValueRef::FUN_1405cfec0(int nStat, int nJob, int nOptionLevel)
{
    double dJob = 0.0;
    double dLevel = 0.0;
    double dStat = 1.0;
    if (nOptionLevel <= 50)
    {
        if (nStat == 0x16)
            dStat = 1.8;
        dLevel = nOptionLevel - 20;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 50:
        case 60:
        case 100:
            dJob = 2.0;
            break;
        }
    }
    else
    {
        if (nStat == 0x16)
            dStat = 1.8;
        else
            dStat = 2.0;
        dLevel = nOptionLevel * 2 - 90;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 50:
        case 60:
        case 100:
            dJob = 3.0;
            break;
        }
    }
    if (dJob == 0.0)
        return 0;
    return (int)round(dLevel / 6.0 * dJob * dStat);
}

// @0x1405d0030
int ItemOptionValueRef::FUN_1405d0030(int nStat, int nJob, int nOptionLevel, bool bMultiJob)
{
    double dJob = 0.0;
    double dLevel = 0.0;
    double dStat = 1.0;
    if (nOptionLevel <= 50)
    {
        if (nStat == 0x16)
            dStat = 1.8;
        dLevel = nOptionLevel - 20;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 30:
        case 40:
        case 110:
            dJob = 2.0;
            break;
        }
        if (bMultiJob && nJob == 100)
            dJob = 2.0;
    }
    else
    {
        if (nStat == 0x16)
            dStat = 1.8;
        else
            dStat = 2.0;
        dLevel = nOptionLevel * 2 - 90;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 30:
        case 40:
        case 110:
            dJob = 3.0;
            break;
        }
        if (bMultiJob && nJob == 100)
            dJob = 3.0;
    }
    if (dJob == 0.0)
        return 0;
    return (int)round(dLevel / 6.0 * dJob * dStat);
}

// @0x1405d01e0
int ItemOptionValueRef::FUN_1405d01e0(int nStat, int nJob, int nOptionLevel)
{
    double dJob = 0.0;
    double dLevel = 0.0;
    double dStat = 1.0;
    if (nOptionLevel <= 50)
    {
        if (nStat == 0x16)
            dStat = 1.8;
        dLevel = nOptionLevel - 20;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 70:
        case 80:
            dJob = 2.0;
            break;
        }
    }
    else
    {
        if (nStat == 0x16)
            dStat = 1.8;
        else
            dStat = 2.0;
        dLevel = nOptionLevel * 2 - 90;
        switch (nJob)
        {
        case 0:
            dJob = 1.0;
            break;
        case 70:
        case 80:
            dJob = 3.0;
            break;
        }
    }
    if (dJob == 0.0)
        return 0;
    return (int)round(dLevel / 6.0 * dJob * dStat);
}

// @0x1405d0340
int ItemOptionValueRef::FUN_1405d0340(int nStat, int nRank)
{
    switch (nStat)
    {
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
        switch (nRank)
        {
        case 1: return 6;
        case 2: return 7;
        case 3: return 8;
        case 4: return 9;
        case 5:
        case 6: return 10;
        }
        break;
    case 0x28:
    case 0x29:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
        switch (nRank)
        {
        case 1: return 12;
        case 2: return 14;
        case 3: return 16;
        case 4: return 18;
        case 5:
        case 6: return 20;
        }
        break;
    }
    return 0;
}

// @0x1405d04a0
// MS2-FUNCTIONAL: exe frame 0x10 larger (temporaries of the rounded terms)
int ItemOptionValueRef::FUN_1405d04a0(int nStat, int nJob, int nLevel, int nRank, int nOptionLevel)
{
    double dBase = 9.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 10.0 * 4.0 + 1.0;
    }
    int nExtra = 0;
    if (nOptionLevel >= 50 && nRank >= 4)
    {
        double dRankScale = FUN_1405d1c40(nRank, nOptionLevel);
        double dBaseScale = FUN_1405d1c40(4, nOptionLevel);
        nExtra = (int)round(round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1aa0(nRank)) * dRankScale
            + round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1aa0(4)) * dBaseScale * (nRank - 4));
    }
    return (int)(round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1aa0(nRank)) + nExtra);
}

// @0x1405d0780
// MS2-FUNCTIONAL: exe temporaries of the rounded terms differ
int ItemOptionValueRef::FUN_1405d0780(int nStat, int nJob, int nLevel, int nRank, int nOptionLevel)
{
    double dBase = 9.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 10.0 * 4.0 + 1.0;
    }
    int nExtra = 0;
    if (nOptionLevel >= 50 && nRank >= 4)
    {
        double dRankScale = FUN_1405d1c40(nRank, nOptionLevel);
        double dBaseScale = FUN_1405d1c40(4, nOptionLevel);
        double dRankValue = 0.0;
        double dBaseValue = 0.0;
        if (nStat == 0xc || (nStat > 17 && nStat < 21))
        {
            dRankValue = round(dBase * FUN_1405d1d70(nStat) * FUN_1405d2020(nRank)) * dRankScale;
            dBaseValue = round(dBase * FUN_1405d1d70(nStat) * FUN_1405d2020(4)) * dBaseScale;
        }
        else
        {
            dRankValue = round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1b70(nRank)) * dRankScale;
            dBaseValue = round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1b70(4)) * dBaseScale;
        }
        nExtra = (int)round(dRankValue + dBaseValue * (nRank - 4));
    }
    if (nStat == 0xc || (nStat > 17 && nStat < 21))
        return (int)(round(dBase * FUN_1405d1d70(nStat) * FUN_1405d2020(nRank)) + nExtra);
    int nMin = 4;
    return (std::max)((int)(round(dBase * FUN_1405d1d70(nStat) * FUN_1405d1e70(nJob) * FUN_1405d1b70(nRank)) + nExtra), nMin);
}

// @0x1405d0c10
// MS2-FUNCTIONAL: exe temporaries of the scaled terms differ
int ItemOptionValueRef::FUN_1405d0c10(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel, bool bNegate)
{
    double dBase = 5.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 30.0 * 20.0 - 0.8;
    }
    double dValue = FUN_1405d23b0(dBase * FUN_1405d20f0(nStat));
    double dScale = FUN_1405d2250(nStat) * nLuaIndex;
    if (bNegate)
        dScale *= -1.0;
    int nExtra = FUN_1405d0f90(nLuaIndex, nStat, nLevel, nRank, nOptionLevel);
    if (nOptionLevel > 59)
        nExtra = (int)round(nExtra * (dScale + 1.0));
    return (int)(round(dValue * FUN_1405d1aa0(nRank) * (dScale + 1.0)) + nExtra);
}

// @0x1405d0dd0
int ItemOptionValueRef::FUN_1405d0dd0(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel)
{
    double dBase = 5.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 30.0 * 20.0 - 0.8;
    }
    if (nStat == 0x36)
        dBase = FUN_1405d23b0(dBase * FUN_1405d20f0(0x34));
    else
        dBase = FUN_1405d23b0(dBase * FUN_1405d20f0(nStat));
    double dScale = FUN_1405d2250(nStat);
    int nExtra = FUN_1405d1440(nLuaIndex, nStat, nLevel, nRank, nOptionLevel);
    int nMin = 2;
    int nValue = (int)(dBase * FUN_1405d1b70(nRank) * (1.0 + dScale) + nExtra);
    return (std::max)(nValue, nMin);
}

// @0x1405d0f90
// MS2-FUNCTIONAL: exe temporaries of the rounded terms differ
int ItemOptionValueRef::FUN_1405d0f90(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel)
{
    double dRankScale = 0.0;
    double dBaseScale = 0.0;
    if (nOptionLevel < 60)
    {
        dBaseScale = 0.9828;
        if (nRank == 4)
            dRankScale = 0.9828;
        else if (nRank == 5)
            dRankScale = 2.0589;
        else if (nRank == 6)
            dRankScale = 2.0589;
    }
    else if (nOptionLevel < 70)
    {
        dBaseScale = 1.531;
        if (nRank == 4)
            dRankScale = 1.531;
        else if (nRank == 5)
            dRankScale = 1.8285;
        else if (nRank == 6)
            dRankScale = 2.118;
    }
    else if (nOptionLevel < 80)
    {
        dBaseScale = 2.4979;
        if (nRank == 4)
            dRankScale = 2.4979;
        else if (nRank == 5)
            dRankScale = 2.5491;
        else if (nRank == 6)
            dRankScale = 2.6866;
    }
    double dBase = 5.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 30.0 * 20.0 - 0.8;
    }
    double dValue = FUN_1405d23b0(dBase * FUN_1405d20f0(nStat));
    double dRankLow = round(dValue * FUN_1405d1aa0(nRank) * (1.0 - FUN_1405d2250(nStat) * nLuaIndex));
    double dRankHigh = round(dValue * FUN_1405d1aa0(nRank) * (FUN_1405d2250(nStat) * nLuaIndex + 1.0));
    double dBaseLow = round(dValue * FUN_1405d1aa0(4) * (1.0 - FUN_1405d2250(nStat) * nLuaIndex));
    double dBaseHigh = round(dValue * FUN_1405d1aa0(4) * (FUN_1405d2250(nStat) * nLuaIndex + 1.0));
    if (nOptionLevel < 50 || nRank < 4)
        return 0;
    return (int)round((dRankLow + dRankHigh) / 2.0 * dRankScale + (dBaseLow + dBaseHigh) / 2.0 * dBaseScale * (nRank - 4));
}

// @0x1405d1440
// MS2-FUNCTIONAL: exe temporaries of the scaled terms differ
int ItemOptionValueRef::FUN_1405d1440(unsigned nLuaIndex, int nStat, int nLevel, int nRank, int nOptionLevel)
{
    double dBase = 5.0;
    for (int i = 2; i <= nLevel; i++)
    {
        if (i >= 50)
            dBase += dBase * 0.06;
        else
            dBase += i / 30.0 * 20.0 - 0.8;
    }
    if (nStat == 0x36)
        dBase = FUN_1405d23b0(dBase * FUN_1405d20f0(0x34));
    else
        dBase = FUN_1405d23b0(dBase * FUN_1405d20f0(nStat));
    double dRank = FUN_1405d1b70(nRank);
    double dRankStat = FUN_1405d2250(nStat);
    double dBaseRank = FUN_1405d1b70(4);
    double dBaseStat = FUN_1405d2250(nStat);
    if (nOptionLevel < 50 || nRank < 4)
        return 0;
    return (int)round(dBase * dRank * (dRankStat + 1.0) + dBase * dBaseRank * (dBaseStat + 1.0) * (nRank - 4));
}

// @0x1405d17c0
int ItemOptionValueRef::FUN_1405d17c0(int nLevel, double dScale)
{
    int nValue = (int)round((FUN_1405d18f0(nLevel, 1e-05, -0.003, 0.367) + 4.8841) * dScale);
    if (nValue < 5)
        return nValue + 3;
    else if (nValue == 5)
        return nValue + 4;
    return nValue + 5;
}

// @0x1405d1850
double ItemOptionValueRef::FUN_1405d1850(int nLevel, double dBase, double dStep, double dScale)
{
    return round((nLevel - 12) * dStep / 1.5 * dScale + dBase);
}

// @0x1405d18a0
double ItemOptionValueRef::FUN_1405d18a0(int nLevel, double dBase, double dStep, double dScale)
{
    return round(((nLevel - 12) * dStep + dBase) / 1.5 * dScale);
}

// @0x1405d18f0
double ItemOptionValueRef::FUN_1405d18f0(int nLevel, double dA, double dB, double dC)
{
    return std::pow(nLevel, 3) * dA + std::pow(nLevel, 2) * dB + nLevel * dC;
}

// @0x1405d1960
int ItemOptionValueRef::FUN_1405d1960(int nRank)
{
    switch (nRank)
    {
    case 1: return 2;
    case 2: return 4;
    case 3: return 7;
    case 4: return 9;
    case 5:
    case 6: return 12;
    }
    return 0;
}

// @0x1405d19f0
double ItemOptionValueRef::FUN_1405d19f0(int nRank)
{
    double dScale = 1.0;
    switch (nRank)
    {
    case 2: dScale = 1.1; break;
    case 3: dScale = 1.2; break;
    case 4: dScale = 1.3; break;
    case 5: dScale = 1.4; break;
    case 6: dScale = 1.4; break;
    }
    return dScale;
}

// @0x1405d1aa0
double ItemOptionValueRef::FUN_1405d1aa0(int nRank)
{
    switch (nRank)
    {
    case 1: return 0.9;
    case 2: return 0.98;
    case 3: return 1.06;
    case 4: return 1.14;
    case 5: return 1.21;
    case 6: return 1.4;
    }
    MS2_ASSERT_AT(0x48b, 0);
    return 0.0;
}

// @0x1405d1b70
double ItemOptionValueRef::FUN_1405d1b70(int nRank)
{
    switch (nRank)
    {
    case 1: return 0.1;
    case 2: return 0.12;
    case 3: return 0.14;
    case 4: return 0.16;
    case 5: return 0.18;
    case 6: return 0.2;
    }
    MS2_ASSERT_AT(0x4a1, 0);
    return 0.0;
}

// @0x1405d1c40
double ItemOptionValueRef::FUN_1405d1c40(int nRank, int nOptionLevel)
{
    double dScale = 0.0;
    if (nOptionLevel < 60)
    {
        switch (nRank)
        {
        case 4: dScale = 0.9846; break;
        case 5: dScale = 2.061; break;
        case 6: dScale = 2.061; break;
        }
    }
    else if (nOptionLevel < 70)
    {
        switch (nRank)
        {
        case 4: dScale = 1.531; break;
        case 5: dScale = 1.833; break;
        case 6: dScale = 2.132; break;
        }
    }
    else
    {
        switch (nRank)
        {
        case 4: dScale = 3.248; break;
        case 5: dScale = 3.105; break;
        case 6: dScale = 3.127; break;
        }
    }
    return dScale;
}

// @0x1405d1d70
// MS2-FUNCTIONAL: jump-table entry order of the 0x16/0x29 bodies differs
double ItemOptionValueRef::FUN_1405d1d70(int nStat)
{
    switch (nStat)
    {
    case 0xc:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
        return 0.05;
    case 0xd:
        return 0.21;
    case 0xe:
        return 0.32;
    case 0xf:
        return 0.3;
    case 0x10:
    case 0x11:
        return 0.06;
    case 0x16:
        return 0.62;
    case 0x29:
        return 0.15;
    }
    MS2_ASSERT_AT(0x451, 0);
    return 0.0;
}

// @0x1405d1e70
double ItemOptionValueRef::FUN_1405d1e70(int nJob)
{
    switch (nJob)
    {
    case 0: return 0.8;
    case 1: return 0.9;
    case 10: return 1.1;
    case 20: return 1.0;
    case 30: return 0.9;
    case 40: return 0.88;
    case 50: return 0.93;
    case 60: return 0.95;
    case 70: return 0.95;
    case 80: return 0.9;
    case 90: return 0.97;
    case 100: return 1.0;
    case 110: return 0.9;
    }
    MS2_ASSERT_AT(0x475, 0);
    return 0.0;
}

// @0x1405d2020
double ItemOptionValueRef::FUN_1405d2020(int nRank)
{
    switch (nRank)
    {
    case 1: return 0.4;
    case 2: return 0.55;
    case 3: return 0.7;
    case 4: return 0.85;
    case 5: return 1.0;
    case 6: return 1.0;
    }
    MS2_ASSERT_AT(0x4b7, 0);
    return 0.0;
}

// @0x1405d20f0
double ItemOptionValueRef::FUN_1405d20f0(int nStat)
{
    switch (nStat)
    {
    case 0x1e: return 1.0526315789473684;
    case 0x1f: return 0.9809523809523809;
    case 0x20: return 0.95;
    case 0x21: return 0.8363636363636363;
    case 0x22: return 0.95;
    case 0x32: return 1.1578947368421053;
    case 0x33: return 0.9809523809523809;
    case 0x34: return 1.2;
    case 0x35: return 1.1666666666666667;
    case 0x36: return 1.0717948717948718;
    case 0x37: return 1.0761904761904761;
    case 0x38: return 1.0105263157894737;
    }
    MS2_ASSERT_AT(0x4da, 0);
    return 0.0;
}

// @0x1405d2250
double ItemOptionValueRef::FUN_1405d2250(int nStat)
{
    switch (nStat)
    {
    case 0x1e: return 0.05;
    case 0x1f: return 0.15;
    case 0x20: return 0.02;
    case 0x21: return 0.05;
    case 0x22: return 0.15;
    case 0x32: return 0.1;
    case 0x33: return 0.05;
    case 0x34: return 0.05;
    case 0x35: return 0.1;
    case 0x36: return 0.1;
    case 0x37: return 0.05;
    case 0x38: return 0.1;
    }
    MS2_ASSERT_AT(0x4fd, 0);
    return 0.0;
}

// @0x1405d23b0
double ItemOptionValueRef::FUN_1405d23b0(double dValue)
{
    const double dEpsilon = 1e-06;
    return __imp_floor(dValue * 10.0 + 0.5 + dEpsilon) / 10.0;
}

// @0x1405d2410
int ItemOptionValueRef::FUN_1405d2410(MS2Ptr<CItemData> spItem)
{
    if (spItem == 0)
        return 0;
    for (std::set<int>::iterator it = spItem->limit.recommendJobs.begin(); it != spItem->limit.recommendJobs.end(); ++it)
    {
        if (*it == 1 || *it == 0)
            continue;
        return *it;
    }
    return 0;
}

// @0x1405d2520
ItemOptionValueRandom::ItemOptionValueRandom()
{
    m_nStat = -1;
    m_nSpecial = 0;
    m_nStatId = 0;
    m_nWeight = 1;
}

// @0x1405d2590
bool ItemOptionValueRandom::FUN_1405d2590(Unk_140165cf0* pElem)
{
    CString strName;
    FUN_1408733e0(pElem, "name", strName);
    FUN_140873220(pElem, "weight", m_nWeight);
    FUN_140873220(pElem, "statID", m_nStatId);
    if (strName.IsEmpty())
        return false;
    int nStat = FUN_14082ee80(strName);
    if (nStat != -1)
    {
        m_nStat = nStat;
        return true;
    }
    int nSpecial = FUN_14081d260(strName);
    if (nSpecial != 0)
    {
        m_nSpecial = nSpecial;
        return true;
    }
    return false;
}

// @0x1405d26c0
CString ItemOptionValueRandom::FUN_1405d26c0()
{
    int nStat = FUN_1405d2750();
    if (nStat != -1)
        return FUN_14082efb0(nStat);
    return FUN_14081d380(FUN_1405d2770());
}

// @0x1405d2750
int ItemOptionValueRandom::FUN_1405d2750()
{
    return m_nStat;
}

// @0x1405d2770
unsigned ItemOptionValueRandom::FUN_1405d2770()
{
    return m_nSpecial;
}

// @0x1405d2790
BOOL ItemOptionValueRandom::FUN_1405d2790()
{
    if (FUN_1405d2750() != -1)
        return FALSE;
    return TRUE;
}

// @0x1405d27c0
int ItemOptionValueRandom::FUN_1405d27c0()
{
    return m_nStatId;
}

// @0x1405d27e0
int ItemOptionValueRandom::FUN_1405d27e0()
{
    return m_nWeight;
}

// @0x1405d2800
int ItemOptionValueRandom::FUN_1405d2800(MS2Ptr<ItemOptionRandomContext> spContext)
{
    switch (spContext->m_nType)
    {
    case 1:
        return spContext->FUN_1405d9b80(m_nStatId);
    case 2:
        return spContext->FUN_1405d9bb0(m_nStatId);
    }
    return spContext->FUN_1405d9b10(m_nStatId);
}

// @0x1405d28d0
int ItemOptionValueRandom::FUN_1405d28d0(MS2Ptr<ItemOptionRandomContext> spContext, Unk_Random* pRandom)
{
    switch (spContext->m_nType)
    {
    case 1:
        return spContext->FUN_1405d9b80(m_nStatId);
    case 2:
        return spContext->FUN_1405d9bb0(m_nStatId);
    }
    return spContext->FUN_1405d9b40(m_nStatId, pRandom);
}

// @0x1405d29b0
bool ItemOptionValueRandom::FUN_1405d29b0()
{
    return FUN_14081d830(m_nSpecial) ? true : false;
}

// @0x1405d29f0
ItemOptionConstant::ItemOptionConstant()
    : m_n18(0), m_nGrade(0)
{
}

// @0x1405d2a50
void ItemOptionConstant::FUN_1405d2a50(int nValue)
{
    m_n18 = nValue;
}

// @0x1405d2a70
int ItemOptionConstant::FUN_1405d2a70()
{
    return m_nGrade;
}

// @0x1405d2a90
bool ItemOptionConstant::FUN_1405d2a90(Unk_140165cf0* pElem)
{
    FUN_14015f500(pElem, "grade", &m_nGrade);
    int nCreateType = 0;
    FUN_140873220(pElem, "createType", nCreateType);
    if (nCreateType == 3)
    {
        FUN_1405d3490(pElem);
        return true;
    }
    std::vector<Unk_140165cf0*> arrChildren;
    FUN_14028f5d0(pElem, "v", arrChildren);
    for (auto& pChild : arrChildren)
    {
        CString strName;
        FUN_1408733e0(pChild, "name", strName);
        if (strName.IsEmpty())
            continue;
        int nStat = FUN_14082ee80(strName);
        if (nStat != -1)
        {
            MS2Ptr<ItemOptionValue> spValue(new ItemOptionValue(nStat));
            int nValue = 0;
            FUN_1408731e0(pChild, "value", nValue);
            spValue->FUN_1405ce550(nValue);
            if (spValue->FUN_1405ce3b0())
                m_vValues.push_back(spValue.get());
            continue;
        }
        unsigned nSpecial = FUN_14081d260(strName);
        if (nSpecial != 0)
        {
            MS2Ptr<ItemOptionValue> spValue(new ItemOptionValue(nSpecial));
            int nValue = 0;
            FUN_1408731e0(pChild, "value", nValue);
            spValue->FUN_1405ce550(nValue);
            if (spValue->FUN_1405ce3b0())
                m_vValues.push_back(spValue.get());
        }
    }
    return true;
}

// @0x1405d2e70
void ItemOptionConstant::FUN_1405d2e70(MS2Ptr<CItemOption> spOption, int nRank)
{
    for (auto& spValue : m_vValues)
    {
        if (spValue->FUN_1405ce370() != -1)
        {
            Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
            spBase->FUN_140266e90(spValue->vfunc_1(spOption->FUN_1405cb340(), nRank));
            if (spBase->FUN_140266e30() > 0)
                spOption->FUN_1405cb200(0, spValue->FUN_1405ce370(), spBase);
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
            spBase->FUN_140266e90(spValue->vfunc_1(spOption->FUN_1405cb340(), nRank));
            if (spBase->FUN_140266e30() > 0)
                spOption->FUN_1405cb2a0(0, spValue->FUN_1405ce390(), spBase);
        }
    }
}

// @0x1405d31f0
size_t ItemOptionConstant::FUN_1405d31f0()
{
    return m_vValues.size();
}

// @0x1405d3220
MS2Ptr<ItemOptionValue> ItemOptionConstant::FUN_1405d3220(int nStat)
{
    for (size_t i = 0; i < m_vValues.size(); ++i)
    {
        if (m_vValues[i]->FUN_1405ce370() == nStat)
            return m_vValues[i];
    }
    return MS2Ptr<ItemOptionValue>(0);
}

// @0x1405d3300
MS2Ptr<ItemOptionValue> ItemOptionConstant::FUN_1405d3300(unsigned nSpecial)
{
    for (size_t i = 0; i < m_vValues.size(); ++i)
    {
        if (m_vValues[i]->FUN_1405ce390() == nSpecial)
            return m_vValues[i];
    }
    return MS2Ptr<ItemOptionValue>(0);
}

// @0x1405d33e0
void ItemOptionConstant::FUN_1405d33e0(std::function<void(ItemOptionValue*)> fnVisit)
{
    for (auto spValue : m_vValues)
        fnVisit(spValue);
}

// @0x1405d3490
void ItemOptionConstant::FUN_1405d3490(Unk_140165cf0* pElem)
{
    std::vector<Unk_140165cf0*> arrChildren;
    FUN_14028f5d0(pElem, "v", arrChildren);
    for (auto& pChild : arrChildren)
    {
        CString strName;
        FUN_1408733e0(pChild, "name", strName);
        int nStat = FUN_14082ee80(strName);
        if (nStat != -1)
        {
            MS2Ptr<ItemOptionValueRef> spValue(new ItemOptionValueRef(nStat));
            FUN_140873220(pChild, "luaIndex", spValue->m_nLuaIndex);
            int nValue = 0;
            FUN_1408731e0(pChild, "value", nValue);
            spValue->FUN_1405ce550(nValue);
            m_vValues.push_back(spValue.get());
            continue;
        }
        unsigned nSpecial = FUN_14081d260(strName);
        if (nSpecial != 0)
        {
            MS2Ptr<ItemOptionValue> spValue(new ItemOptionValue(nSpecial));
            int nValue = 0;
            FUN_1408731e0(pChild, "value", nValue);
            spValue->FUN_1405ce550(nValue);
            if (spValue->FUN_1405ce3b0())
                m_vValues.push_back(spValue.get());
        }
    }
}

// @0x1405d37e0
ItemOptionVariationData::ItemOptionVariationData()
    : m_nId(0), m_nProbVer(1), m_eName((SAType)0), m_nHighStat(0)
{
}

// @0x1405d3870
void ItemOptionVariationData::FUN_1405d3870(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "id", m_nId);
    FUN_140873220(pElem, "probVer", m_nProbVer);
    XmlValueByName(pElem, "name", m_eName);
    FUN_1408731e0(pElem, "highStat", m_nHighStat);
    for (Unk_140165cf0* pChild : pElem->FUN_140165cf0("v"))
    {
        int stat = 0;
        unsigned weight = 1;
        FUN_1408731e0(pChild, "stat", stat);
        FUN_140873220(pChild, "weight", weight);
        MS2_ASSERT_AT(0x642, stat && weight);
        m_vStats.push_back(std::make_pair(stat, weight));
        m_picker.Register(weight, stat);
    }
}

// @0x1405d3a20
int ItemOptionVariationData::FUN_1405d3a20()
{
    return m_nId;
}

// @0x1405d3a40
int ItemOptionVariationData::FUN_1405d3a40()
{
    int nStat = 0;
    if (m_picker.Pick(nStat))
        return nStat;
    return 0;
}

// @0x1405d3a90
int ItemOptionVariationData::FUN_1405d3a90(Unk_Random* pRandom)
{
    int nStat = 0;
    if (m_picker.Pick(pRandom, nStat))
        return nStat;
    return 0;
}

// @0x1405d3ae0
int ItemOptionVariationData::FUN_1405d3ae0()
{
    if (m_vStats.empty())
        return 0;
    return m_vStats.begin()->first;
}

// @0x1405d3b30
int ItemOptionVariationData::FUN_1405d3b30()
{
    if (m_vStats.empty())
        return 0;
    return m_vStats.rbegin()->first;
}

// @0x1405d3b80
int ItemOptionVariationData::FUN_1405d3b80()
{
    return m_nHighStat;
}

// @0x1405d3ba0
bool ItemOptionVariationData::FUN_1405d3ba0(int nStat)
{
    if (m_nHighStat == 0)
        return false;
    return nStat >= m_nHighStat;
}

// @0x1405d3bf0
ItemOptionRandom::ItemOptionRandom()
    : m_nCode(0), m_nProbVer(1), m_eStatGroup((ItemOptionStatGroup)0), m_nLevelGroupId(0), m_bRarePickOne(false),
      m_nPickCount(0)
{
}

// @0x1405d3c80
int ItemOptionRandom::FUN_1405d3c80()
{
    return m_nCode;
}

// @0x1405d3ca0
ItemOptionStatGroup ItemOptionRandom::FUN_1405d3ca0()
{
    return m_eStatGroup;
}

// @0x1405d3cc0
int ItemOptionRandom::FUN_1405d3cc0()
{
    return m_nProbVer;
}

// @0x1405d3ce0
int ItemOptionRandom::FUN_1405d3ce0()
{
    return m_nLevelGroupId;
}

// @0x1405d3d00
bool ItemOptionRandom::FUN_1405d3d00(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "code", m_nCode);
    if (m_nCode == 0)
        return false;
    FUN_140873220(pElem, "probVer", m_nProbVer);
    XmlValue(pElem, "statGroup", m_eStatGroup);
    FUN_1408731e0(pElem, "levelGroupID", m_nLevelGroupId);
    FUN_140873220(pElem, "pickCount", m_nPickCount);
    FUN_1408730a0(pElem, "isRarePickOne", m_bRarePickOne);
    std::vector<Unk_140165cf0*> arrChildren;
    FUN_14028f5d0(pElem, "v", arrChildren);
    for (auto& pChild : arrChildren)
    {
        MS2Ptr<ItemOptionValueRandom> spValue(new ItemOptionValueRandom);
        if (!spValue->FUN_1405d2590(pChild))
            continue;
        m_vValues.push_back(spValue.get());
    }
    return true;
}

// @0x1405d3f70
void ItemOptionRandom::FUN_1405d3f70(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom)
{
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spOption, nRank, MS2Ptr<ItemOptionRandom>(this)));
    std::vector<std::pair<int, int> > vLocked;
    int nCount = 0;
    std::vector<ItemOptionValueRandom*> vValues;
    if (FUN_1405d7bf0(vValues, nCount, pRandom, FALSE, spContext, vLocked, NULL))
    {
        for (auto& pValue : vValues)
        {
            spContext->FUN_1405d9ea0(MS2Ptr<ItemOptionValueRandom>(pValue), pRandom, &nCount, NULL);
            if (nCount == 0)
                break;
        }
    }
}

// @0x1405d4270
bool ItemOptionRandom::FUN_1405d4270(MS2Ptr<Unk_ItemOptionPreset> spPreset, MS2Ptr<CItemOption> spOption, int nRank,
                                     Unk_Random* pRandom)
{
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spOption, nRank, MS2Ptr<ItemOptionRandom>(this)));
    spContext->m_nType = spPreset->m_nType;
    int nCount = FUN_1405d5fe0(nRank);
    if (nCount == 0)
        return false;
    std::vector<ItemOptionValueRandom*> vValues;
    FUN_1405d8880(spPreset, vValues, spContext);
    if (vValues.empty())
        return false;
    // the preset's stats first, in order
    for (unsigned i = 0; i < spPreset->m_names.GetCount(); i++)
    {
        CString strName = spPreset->m_names[i];
        for (std::vector<ItemOptionValueRandom*>::iterator it = vValues.begin(); it != vValues.end(); ++it)
        {
            ItemOptionValueRandom* pValue = *it;
            if (pValue == NULL)
                continue;
            if (pValue->FUN_1405d26c0().CompareNoCase(strName) != 0)
                continue;
            spContext->FUN_1405d9ea0(MS2Ptr<ItemOptionValueRandom>(pValue), pRandom, &nCount, NULL);
            if (nCount == 0)
                return true;
            vValues.erase(it);
            break;
        }
    }
    for (auto& pValue : vValues)
    {
        spContext->FUN_1405d9ea0(MS2Ptr<ItemOptionValueRandom>(pValue), pRandom, &nCount, NULL);
        if (nCount == 0)
            return true;
    }
    return true;
}

// @0x1405d48d0
void ItemOptionRandom::FUN_1405d48d0(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom,
                                     const std::vector<std::pair<int, int> >& vLocked, int nCount,
                                     Unk_ProbabilityLog* pLogs)
{
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spOption, nRank, MS2Ptr<ItemOptionRandom>(this)));
    BOOL bFixedCount = nCount != 0;
    int nIndex = 0;
    std::vector<ItemOptionValueRandom*> vValues;
    if (FUN_1405d7bf0(vValues, nCount, pRandom, bFixedCount, spContext, vLocked, pLogs))
    {
        for (auto& pValue : vValues)
        {
            spContext->FUN_1405da4b0(MS2Ptr<ItemOptionValueRandom>(pValue), &nCount, nIndex, pLogs);
            nIndex++;
            if (nCount == 0)
                break;
        }
    }
}

// @0x1405d4bb0
bool ItemOptionRandom::FUN_1405d4bb0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom)
{
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spTarget->m_spSource, spTarget->m_nRank, MS2Ptr<ItemOptionRandom>(this)));
    spContext->FUN_1405d9be0(spTarget);
    const int kMaxTry = 20;
    for (int nTry = 0; nTry < kMaxTry; nTry++)
    {
        std::vector<ItemOptionValueRandom*> vValues;
        int nCount = spTarget->m_spSource->FUN_1405cbbb0(2);
        if (spTarget->m_nMode == 0)
        {
            if (FUN_1405d7940(vValues, spTarget->m_spSource.get()) == 0)
                return false;
        }
        else if (spTarget->m_nMode == 1)
        {
            if (!FUN_1405d7bf0(vValues, nCount, pRandom, TRUE, spContext, spTarget->m_vLocked, &spTarget->m_vLogs))
                return false;
        }
        spTarget->m_spResult.AssignRaw(new CItemOption(spTarget->m_nItemId));
        size_t nLocked = spTarget->m_vLocked.size();
        for (ItemOptionValueRandom* pValue : vValues)
        {
            if (pValue == NULL)
                continue;
            bool bLocked = false;
            if (nLocked != 0)
            {
                if (pValue->FUN_1405d2790() == 0)
                {
                    int nStat = pValue->FUN_1405d2750();
                    BOOL bSpecial = pValue->FUN_1405d2790();
                    bLocked = std::find(spTarget->m_vLocked.begin(), spTarget->m_vLocked.end(),
                                        std::make_pair(bSpecial, nStat)) != spTarget->m_vLocked.end();
                    if (bLocked)
                        nLocked--;
                }
                else
                {
                    int nSpecial = pValue->FUN_1405d2770();
                    BOOL bSpecial = pValue->FUN_1405d2790();
                    if (std::find(spTarget->m_vLocked.begin(), spTarget->m_vLocked.end(),
                                  std::make_pair(bSpecial, nSpecial)) != spTarget->m_vLocked.end())
                    {
                        bLocked = true;
                        nLocked--;
                    }
                }
            }
            if (bLocked)
            {
                // a kept stat: copied from the source
                if (pValue->FUN_1405d2790() == 0)
                {
                    int nStat = pValue->FUN_1405d2750();
                    Unk_EnchantPtr<BaseOption> spBase = spTarget->m_spSource->FUN_1405cb760(2, nStat);
                    if (spBase == 0)
                        continue;
                    spTarget->m_spResult->FUN_1405cb200(2, nStat, spBase);
                }
                else
                {
                    unsigned nSpecial = pValue->FUN_1405d2770();
                    Unk_EnchantPtr<BaseOption> spBase = spTarget->m_spSource->FUN_1405cb800(2, nSpecial);
                    if (spBase == 0)
                        continue;
                    spTarget->m_spResult->FUN_1405cb2a0(2, nSpecial, spBase);
                }
                nCount--;
            }
            else
                spContext->FUN_1405daad0(MS2Ptr<ItemOptionValueRandom>(pValue), &nCount, &spTarget->m_vLogs);
            if (nCount == 0)
                break;
        }
        if (!spTarget->m_spSource->FUN_1405cc640(2, spTarget->m_spResult.get()))
            return true;
    }
    return false;
}

// @0x1405d55e0
bool ItemOptionRandom::FUN_1405d55e0(MS2Ptr<Unk_1405e74c0> spTarget, Unk_Random* pRandom)
{
    std::vector<ItemOptionValueRandom*> vValues;
    int nCount = spTarget->m_spSource->FUN_1405cbbb0(2);
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spTarget->m_spSource, spTarget->m_nRank, MS2Ptr<ItemOptionRandom>(this)));
    spContext->FUN_1405d9be0(spTarget);
    if (spTarget->m_nMode == 0)
    {
        if (FUN_1405d7940(vValues, spTarget->m_spSource.get()) == 0)
            return false;
    }
    else if (spTarget->m_nMode == 1)
    {
        if (!FUN_1405d7bf0(vValues, nCount, pRandom, TRUE, spContext, spTarget->m_vLocked, NULL))
            return false;
    }
    spTarget->m_spResult.AssignRaw(new CItemOption(spTarget->m_nItemId));
    if (spTarget->m_nRoll == 0)
        spTarget->m_spResult = spTarget->m_spSource->FUN_1405caf90();
    else
    {
        MS2Ptr<CItemOption> spResult = spTarget->m_spResult;
        MS2Ptr<CItemOption> spSource = spTarget->m_spSource;
        int nLocked = (int)spTarget->m_vLocked.size();
        int nSize = (int)vValues.size();
        int nLeft = nLocked;
        int nRolled = 0;
        for (int i = 0; i < nSize; i++)
        {
            ItemOptionValueRandom* pValue = vValues[i];
            if (pValue == NULL)
                continue;
            bool bLocked = false;
            if (nLeft > 0)
            {
                if (pValue->FUN_1405d2790() == 0)
                {
                    int nStat = pValue->FUN_1405d2750();
                    BOOL bSpecial = pValue->FUN_1405d2790();
                    bLocked = std::find(spTarget->m_vLocked.begin(), spTarget->m_vLocked.end(),
                                        std::make_pair(bSpecial, nStat)) != spTarget->m_vLocked.end();
                    if (bLocked)
                        nLeft--;
                }
                else
                {
                    int nSpecial = pValue->FUN_1405d2770();
                    BOOL bSpecial = pValue->FUN_1405d2790();
                    if (std::find(spTarget->m_vLocked.begin(), spTarget->m_vLocked.end(),
                                  std::make_pair(bSpecial, nSpecial)) != spTarget->m_vLocked.end())
                    {
                        bLocked = true;
                        nLeft--;
                    }
                }
            }
            if (bLocked)
            {
                if (pValue->FUN_1405d2790() == 0)
                {
                    int nStat = pValue->FUN_1405d2750();
                    Unk_EnchantPtr<BaseOption> spBase = spSource->FUN_1405cb760(2, nStat);
                    if (spBase == 0)
                        continue;
                    spResult->FUN_1405cb200(2, nStat, spBase);
                }
                else
                {
                    unsigned nSpecial = pValue->FUN_1405d2770();
                    Unk_EnchantPtr<BaseOption> spBase = spSource->FUN_1405cb800(2, nSpecial);
                    if (spBase == 0)
                        continue;
                    spResult->FUN_1405cb2a0(2, nSpecial, spBase);
                }
                nCount--;
            }
            else
            {
                spContext->FUN_1405daad0(MS2Ptr<ItemOptionValueRandom>(pValue), &nCount, &spTarget->m_vLogs);
                nRolled++;
            }
            if (nCount == 0)
                break;
        }
    }
    return true;
}

// @0x1405d5fe0
int ItemOptionRandom::FUN_1405d5fe0(int nRank)
{
    if (m_bRarePickOne)
    {
        if (nRank == 2)
            return 1;
        if (nRank == 1)
            return 0;
    }
    return m_nPickCount;
}

// @0x1405d6020
bool ItemOptionRandom::FUN_1405d6020(MS2Ptr<CItemOption> spOption, int nRank, Unk_Random* pRandom)
{
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spOption, nRank, MS2Ptr<ItemOptionRandom>(this)));
    MS2Ptr<ItemOptionValueRandom> spValue = FUN_1405d8f30(spContext, pRandom);
    if (spValue == 0)
        return false;
    if (spValue->FUN_1405d2750() == -1)
    {
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d28d0(spContext, pRandom));
        if (!spOption->FUN_1405cb2a0(2, spValue->FUN_1405d2770(), spBase))
            return false;
    }
    else
    {
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d28d0(spContext, pRandom));
        if (!spOption->FUN_1405cb200(2, spValue->FUN_1405d2750(), spBase))
            return false;
    }
    return true;
}

// @0x1405d6560
// The roll statistics of nTrials parallel rolls: one "Option name:count" line per row (also logged).
void ItemOptionRandom::FUN_1405d6560(MS2Ptr<CItemOption> spOption, int nRank, int nTrials,
                                     const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut)
{
    CLockCriticalSection lock;
    Unk_Random random;
    int nCount = 0;
    std::map<CString, int> mapCounts;
    std::vector<unsigned char> vTrials(nTrials);
    MS2Ptr<ItemOptionRandomContext> spContext(
        new ItemOptionRandomContext(spOption, nRank, MS2Ptr<ItemOptionRandom>(this)));
    Concurrency::parallel_for_each(vTrials.begin(), vTrials.end(),
        [this, &nCount, &random, &spContext, &vLocked, &lock, &mapCounts](unsigned char)
        {
            std::vector<ItemOptionValueRandom*> vValues;
            if (FUN_1405d7bf0(vValues, nCount, &random, FALSE, spContext, vLocked, NULL))
            {
                Unk_CriticalSectionLock guard(lock, 1);
                for (auto& pValue : vValues)
                    mapCounts[pValue->FUN_1405d26c0()]++;
            }
        });
    for (auto& kCount : mapCounts)
    {
        pOut->push_back(StringFormat(L"Option {0}:{1}", kCount.first, kCount.second));
        FUN_1401e0850(FUN_140166440(), 2, 0x13, L"Option {0}:{1}", kCount.first, kCount.second);
    }
}

// @0x1405d68f0
// The pick chance of every row for nPick picks (the rank's pick count when 0); the exclusive (armor) rows and the
// special abilities count as one entry each, split by weight.
void ItemOptionRandom::FUN_1405d68f0(unsigned nItemId, int nRank, unsigned& nPick, std::vector<CStringW>* pOut)
{
    if (nPick == 0)
        nPick = FUN_1405d5fe0(nRank);
    MS2Ptr<ItemOptionRandomContext> spContext(new ItemOptionRandomContext(
        MS2Ptr<CItemOption>(new CItemOption(nItemId)), nRank, MS2Ptr<ItemOptionRandom>(this)));
    unsigned nArmor = 0;
    unsigned nSpecial = 0;
    std::vector<std::pair<CStringW, unsigned> > vArmor;
    std::vector<std::pair<CStringW, unsigned> > vSpecial;
    std::vector<unsigned> vWeights;
    std::vector<CStringW> vLines;
    std::vector<std::pair<CString, std::pair<unsigned, int> > > vInfo;
    for (auto& spValue : m_vValues)
    {
        CString strName = spValue->FUN_1405d26c0();
        unsigned nWeight = spValue->FUN_1405d27e0();
        std::pair<unsigned, int> kInfo;
        kInfo.first = nWeight;
        kInfo.second = spValue->FUN_1405d27c0();
        vInfo.push_back(std::make_pair(strName, kInfo));
        bool bArmor = spContext->FUN_1405d9e00() == 2 &&
                      FUN_140166430()->FUN_1405f6e40(spValue->FUN_1405d26c0()).get() != 0;
        if (!bArmor)
        {
            if (!spValue->FUN_1405d29b0())
            {
                vWeights.push_back(nWeight);
                int nStatId = spValue->FUN_1405d27c0();
                vLines.push_back(StringFormat(L"OptionName : {0}, Weight : {1}, statID : {2}", strName, nWeight, nStatId));
            }
            else
            {
                nSpecial += nWeight;
                int nStatId = spValue->FUN_1405d27c0();
                vSpecial.push_back(std::make_pair(
                    StringFormat(L"OptionName: {0}, Weight : {1}, statID: {2}", strName, nWeight, nStatId), nWeight));
            }
        }
        else
        {
            nArmor += nWeight;
            int nStatId = spValue->FUN_1405d27c0();
            vArmor.push_back(std::make_pair(
                StringFormat(L"OptionName: {0}, Weight : {1}, statID: {2}", strName, nWeight, nStatId), nWeight));
        }
    }
    if (nArmor != 0)
        vWeights.push_back(nArmor);
    if (nSpecial != 0)
        vWeights.push_back(nSpecial);
    size_t nCount = vWeights.size();
    std::vector<double> vProb(nCount, 0.0);
    for (unsigned i = 1; i <= nPick; i++)
    {
        for (size_t j = 0; j < nCount; j++)
            vProb[j] += FUN_1405d9660(vWeights, i, j);
    }
    size_t nLine = 0;
    for (; nLine < vLines.size(); nLine++)
        pOut->push_back(StringFormat(L"{0} Prob {1}", vLines[nLine], vProb[nLine]));
    if (nArmor != 0)
    {
        pOut->push_back(StringFormat(L"[Armor Prob {0}]", vProb[nLine]));
        for (size_t j = 0; j < vArmor.size(); j++)
        {
            double dProb = vProb[nLine] * (double)vArmor[j].second / (double)nArmor;
            CStringW strLine = StringFormat(L"{0} Prob {1}", vArmor[j].first, dProb);
            pOut->push_back(strLine);
        }
        nLine++;
    }
    if (nSpecial != 0)
    {
        pOut->push_back(StringFormat(L"[Special Ability Prob {0}]", vProb[nLine]));
        for (size_t j = 0; j < vSpecial.size(); j++)
        {
            double dProb = vProb[nLine] * (double)vSpecial[j].second / (double)nSpecial;
            CStringW strLine = StringFormat(L"{0} Prob {1}", vSpecial[j].first, dProb);
            pOut->push_back(strLine);
        }
        nLine++;
    }
}


// @0x1405d74d0
bool ItemOptionRandom::FUN_1405d74d0(int nStat)
{
    return FUN_1405d77a0(nStat).get() != 0;
}

// @0x1405d7550
bool ItemOptionRandom::FUN_1405d7550(unsigned nSpecial)
{
    return FUN_1405d7870(nSpecial).get() != 0;
}

// @0x1405d75d0
void ItemOptionRandom::FUN_1405d75d0(std::function<void(ItemOptionValueRandom*)> fnVisit)
{
    for (MS2Ptr<ItemOptionValueRandom> spValue : m_vValues)
        fnVisit(spValue.get());
}

// @0x1405d7680
int ItemOptionRandom::FUN_1405d7680(int nStat)
{
    MS2Ptr<ItemOptionValueRandom> spValue = FUN_1405d77a0(nStat);
    if (spValue == 0)
        return 0;
    return spValue->FUN_1405d27c0();
}

// @0x1405d7710
int ItemOptionRandom::FUN_1405d7710(unsigned nSpecial)
{
    MS2Ptr<ItemOptionValueRandom> spValue = FUN_1405d7870(nSpecial);
    if (spValue == 0)
        return 0;
    return spValue->FUN_1405d27c0();
}

// @0x1405d77a0
MS2Ptr<ItemOptionValueRandom> ItemOptionRandom::FUN_1405d77a0(int nStat)
{
    for (auto& spValue : m_vValues)
    {
        if (spValue->FUN_1405d2750() == nStat)
            return spValue;
    }
    return nullptr;
}

// @0x1405d7870
MS2Ptr<ItemOptionValueRandom> ItemOptionRandom::FUN_1405d7870(unsigned nSpecial)
{
    for (auto& spValue : m_vValues)
    {
        if (spValue->FUN_1405d2770() == nSpecial)
            return spValue;
    }
    return nullptr;
}

// @0x1405d7940
int ItemOptionRandom::FUN_1405d7940(std::vector<ItemOptionValueRandom*>& vOut, CItemOption* pSource)
{
    Unk_EnchantMap& kStats = pSource->FUN_1405cb8a0(2);
    if (!kStats.IsEmpty())
    {
        size_t nTotal = kStats.GetCount();
        size_t nFound = 0;
        for (size_t i = 0; i < m_vValues.size(); i++)
        {
            if (m_vValues[i]->FUN_1405d2750() != -1)
            {
                int nStat = m_vValues[i]->FUN_1405d2750();
                if (kStats.Lookup(nStat) != NULL)
                {
                    vOut.push_back(m_vValues[i].get());
                    nFound++;
                }
                if (nTotal == nFound)
                    break;
            }
        }
    }
    Unk_SocketSpecialMap& kSpecials = pSource->FUN_1405cb8d0(2);
    if (!kSpecials.IsEmpty())
    {
        size_t nTotal = kSpecials.GetCount();
        size_t nFound = 0;
        for (size_t i = 0; i < m_vValues.size(); i++)
        {
            if (m_vValues[i]->FUN_1405d2770() != 0)
            {
                Unk_SocketSpecialStat eSpecial = (Unk_SocketSpecialStat)m_vValues[i]->FUN_1405d2770();
                if (kSpecials.Lookup(eSpecial) != NULL)
                {
                    vOut.push_back(m_vValues[i].get());
                    nFound++;
                }
                if (nTotal == nFound)
                    return 1;
            }
        }
    }
    return 1;
}

// @0x1405d7bf0
// The weighted pick of nCount rows: the locked stats first, then one of the exclusive (armor) group and one special
// ability (each counts as one weighted entry of the main pick when not locked), then the rest by weight.
bool ItemOptionRandom::FUN_1405d7bf0(std::vector<ItemOptionValueRandom*>& vOut, int& nCount, Unk_Random* pRandom,
                                     BOOL bFixedCount, MS2Ptr<ItemOptionRandomContext> spContext,
                                     const std::vector<std::pair<int, int> >& vLocked, Unk_ProbabilityLog* pLogs)
{
    Unk_ItemOptionValuePicker picker;
    Unk_ItemOptionValuePicker pickerArmor;
    Unk_ItemOptionValuePicker pickerSpecial;
    MS2Ptr<ItemOptionValueRandom> spLockedArmor;
    MS2Ptr<ItemOptionValueRandom> spLockedSpecial;
    std::vector<MS2Ptr<ItemOptionValueRandom> > vLockedValues;
    for (auto& kLocked : vLocked)
    {
        MS2Ptr<ItemOptionValueRandom> spValue;
        int nKey = kLocked.second;
        if (kLocked.first == 0)
            spValue = FUN_1405d77a0(nKey);
        else
            spValue = FUN_1405d7870(nKey);
        if (spValue == 0)
            continue;
        if (spContext->FUN_1405d9e00() == 2 &&
            FUN_140166430()->FUN_1405f6e40(spValue->FUN_1405d26c0()).get() != 0)
            spLockedArmor = spValue;
        else if (spValue->FUN_1405d29b0())
            spLockedSpecial = spValue;
        else
            vLockedValues.push_back(spValue);
    }
    for (auto& spValue : m_vValues)
    {
        CString strName = spValue->FUN_1405d26c0();
        int nWeight = spValue->FUN_1405d27e0();
        if (spContext->FUN_1405d9e00() == 2 && FUN_140166430()->FUN_1405f6e40(strName).get() != 0)
            pickerArmor.Register(nWeight, spValue.get());
        else if (spValue->FUN_1405d29b0())
            pickerSpecial.Register(nWeight, spValue.get());
        else
        {
            if (!vLockedValues.empty() &&
                std::find(vLockedValues.begin(), vLockedValues.end(), spValue) != vLockedValues.end())
                continue;
            picker.Register(nWeight, spValue.get());
        }
    }
    if (!bFixedCount)
        nCount = FUN_1405d5fe0(spContext->FUN_1405d9e30());
    if (nCount == 0)
        return false;
    vOut.clear();
    std::pair<ItemOptionValueRandom*, double> kArmor;
    std::pair<ItemOptionValueRandom*, double> kSpecial;
    if (pickerArmor.IsValid() == true)
    {
        ItemOptionValueRandom* pValue = spLockedArmor.get();
        if (pValue == NULL)
        {
            pickerArmor.Pick(pRandom, pValue);
            picker.Register(pickerArmor.m_total, pValue);
            int nWeight = pValue->FUN_1405d27e0();
            kArmor.first = pValue;
            kArmor.second = (double)nWeight / (double)pickerArmor.m_total;
        }
        else
            vOut.push_back(spLockedArmor.get());
    }
    if (pickerSpecial.IsValid() == true)
    {
        ItemOptionValueRandom* pValue = spLockedSpecial.get();
        if (pValue == NULL)
        {
            pickerSpecial.Pick(pRandom, pValue);
            picker.Register(pickerSpecial.m_total, pValue);
            int nWeight = pValue->FUN_1405d27e0();
            kSpecial.first = pValue;
            kSpecial.second = (double)nWeight / (double)pickerSpecial.m_total;
        }
        else
            vOut.push_back(spLockedSpecial.get());
    }
    if (!vLockedValues.empty())
        vOut.insert(vOut.end(), vLockedValues.begin(), vLockedValues.end());
    std::vector<ItemOptionValueRandom*> vPicked;
    int nPick = nCount;
    if (!vLocked.empty())
        nPick -= (int)vLocked.size();
    int nLeft = nPick < 0 ? 0 : nPick;
    if (!picker.PickN(vPicked, nLeft, pRandom))
        return false;
    vOut.insert(vOut.end(), vPicked.begin(), vPicked.end());
    if (vOut.empty())
        return false;
    if (pLogs != NULL)
        FUN_14073e750(m_nProbVer, m_nCode, picker, vPicked, vLockedValues, &kArmor, &kSpecial, pLogs);
    return true;
}

// @0x1405d8880
// The rows to roll for a preset: the plain rows, plus one exclusive (armor) row and one special ability - the
// preset's when it names one, a random one otherwise.
void ItemOptionRandom::FUN_1405d8880(MS2Ptr<Unk_ItemOptionPreset> spPreset, std::vector<ItemOptionValueRandom*>& vOut,
                                     MS2Ptr<ItemOptionRandomContext> spContext)
{
    ATL::CAtlArray<ItemOptionValueRandom*> arrArmor;
    ATL::CAtlArray<ItemOptionValueRandom*> arrSpecial;
    for (auto& spValue : m_vValues)
    {
        CString strName = spValue->FUN_1405d26c0();
        if (spContext->FUN_1405d9e00() == 2 && FUN_140166430()->FUN_1405f6e40(strName).get() != 0)
            arrArmor.Add(spValue.get());
        else if (spValue->FUN_1405d29b0())
            arrSpecial.Add(spValue.get());
        else
            vOut.push_back(spValue.get());
    }
    if (!arrArmor.IsEmpty())
    {
        bool bFound = false;
        for (unsigned i = 0; i < spPreset->m_names.GetCount(); i++)
        {
            CString strName = spPreset->m_names[i];
            for (unsigned j = 0; j < arrArmor.GetCount(); j++)
            {
                ItemOptionValueRandom* pValue = arrArmor[j];
                if (pValue->FUN_1405d26c0().CompareNoCase(strName) == 0)
                {
                    vOut.push_back(pValue);
                    bFound = true;
                    break;
                }
            }
            if (bFound)
                break;
        }
        if (!bFound)
            vOut.push_back(arrArmor[FUN_140768010((int)arrArmor.GetCount(), 0)]);
    }
    if (!arrSpecial.IsEmpty())
    {
        bool bFound = false;
        for (unsigned i = 0; i < spPreset->m_names.GetCount(); i++)
        {
            CString strName = spPreset->m_names[i];
            for (unsigned j = 0; j < arrSpecial.GetCount(); j++)
            {
                ItemOptionValueRandom* pValue = arrSpecial[j];
                if (pValue->FUN_1405d26c0().CompareNoCase(strName) == 0)
                {
                    vOut.push_back(pValue);
                    bFound = true;
                    break;
                }
            }
            if (bFound)
                break;
        }
        if (!bFound)
            vOut.push_back(arrSpecial[FUN_140768010((int)arrSpecial.GetCount(), 0)]);
    }
}

// @0x1405d8f30
// One more row for an option: the rows it already holds are skipped; an exclusive (armor) row or special ability
// it holds stands in for its group in the weighted pick.
MS2Ptr<ItemOptionValueRandom> ItemOptionRandom::FUN_1405d8f30(MS2Ptr<ItemOptionRandomContext> spContext,
                                                              Unk_Random* pRandom)
{
    Unk_ItemOptionValuePicker picker;
    Unk_ItemOptionValuePicker pickerArmor;
    Unk_ItemOptionValuePicker pickerSpecial;
    std::vector<ItemOptionValueRandom*> vHeld;
    FUN_1405d7940(vHeld, spContext->FUN_1405d9e50().get());
    ItemOptionValueRandom* pPicked = NULL;
    MS2Ptr<ItemOptionValueRandom> spHeldArmor(0);
    MS2Ptr<ItemOptionValueRandom> spHeldSpecial(0);
    if (!vHeld.empty())
    {
        for (auto& pValue : vHeld)
        {
            CString strName = pValue->FUN_1405d26c0();
            if (spContext->FUN_1405d9e00() == 2 && FUN_140166430()->FUN_1405f6e40(strName).get() != 0)
                spHeldArmor.AssignRaw(pValue);
            else if (pValue->FUN_1405d29b0())
                spHeldSpecial.AssignRaw(pValue);
        }
    }
    for (auto& spValue : m_vValues)
    {
        CString strName = spValue->FUN_1405d26c0();
        int nWeight = spValue->FUN_1405d27e0();
        if (!vHeld.empty() && std::find(vHeld.begin(), vHeld.end(), spValue) != vHeld.end())
            continue;
        if (spContext->FUN_1405d9e00() == 2 && FUN_140166430()->FUN_1405f6e40(strName).get() != 0)
            pickerArmor.Register(nWeight, spValue.get());
        else if (spValue->FUN_1405d29b0())
            pickerSpecial.Register(nWeight, spValue.get());
        else
            picker.Register(nWeight, spValue.get());
    }
    if (pickerArmor.IsValid() == true)
    {
        ItemOptionValueRandom* pValue = spHeldArmor.get();
        if (pValue == NULL)
        {
            pickerArmor.Pick(pRandom, pValue);
            picker.Register(pickerArmor.m_total, pValue);
        }
    }
    if (pickerSpecial.IsValid() == true)
    {
        ItemOptionValueRandom* pValue = spHeldSpecial.get();
        if (pValue == NULL)
        {
            pickerSpecial.Pick(pRandom, pValue);
            picker.Register(pickerSpecial.m_total, pValue);
        }
    }
    if (!picker.Pick(pRandom, pPicked))
        return MS2Ptr<ItemOptionValueRandom>(0);
    return MS2Ptr<ItemOptionValueRandom>(pPicked);
}

// @0x1405d9660
// The chance that entry nIndex is among nPick weighted picks without replacement: the sum over every ordered choice
// of nPick - 1 other entries picked before it.
double ItemOptionRandom::FUN_1405d9660(std::vector<unsigned>& vWeights, size_t nPick, size_t nIndex)
{
    unsigned nTotal = 0;
    for (size_t i = 0; i < vWeights.size(); i++)
        nTotal += vWeights[i];
    if (nPick == 1)
        return (double)vWeights[nIndex] / (double)nTotal;
    double dSum = 0.0;
    std::vector<size_t> vOthers;
    for (size_t i = 0; i < vWeights.size(); i++)
    {
        if (i != nIndex)
            vOthers.push_back(i);
    }
    std::sort(vOthers.begin(), vOthers.end());
    size_t nDepth = nPick - 1;
    do
    {
        double dProb = 1.0;
        for (size_t i = 0; i < nDepth; i++)
        {
            double dWeight = (double)vWeights[vOthers[i]];
            unsigned nUsed = 0;
            for (size_t j = 0; j < i; j++)
                nUsed += vWeights[vOthers[j]];
            dProb *= dWeight / (double)(nTotal - nUsed);
        }
        unsigned nUsed = 0;
        for (size_t i = 0; i < nDepth; i++)
            nUsed += vWeights[vOthers[i]];
        dProb *= (double)vWeights[nIndex] / (double)(nTotal - nUsed);
        dSum += dProb;
        std::reverse(vOthers.begin() + nDepth, vOthers.end());
    } while (std::next_permutation(vOthers.begin(), vOthers.end()));
    return dSum;
}

// @0x1405d9a50
ItemOptionRandomContext::ItemOptionRandomContext(MS2Ptr<CItemOption> spOption, int n,
                                                 MS2Ptr<ItemOptionRandom> spRandom)
    : m_nType(0), m_spOption(spOption), m_spTarget(), m_spRandom(spRandom), m_n50(n)
{
}

// @0x1405d9b10
int ItemOptionRandomContext::FUN_1405d9b10(int nStatId)
{
    return FUN_140166430()->FUN_1405f6100(nStatId);
}

// @0x1405d9b40
int ItemOptionRandomContext::FUN_1405d9b40(int nStatId, Unk_Random* pRandom)
{
    return FUN_140166430()->FUN_1405f6190(nStatId, pRandom);
}

// @0x1405d9b80
int ItemOptionRandomContext::FUN_1405d9b80(int nStatId)
{
    return FUN_140166430()->FUN_1405f6230(nStatId);
}

// @0x1405d9bb0
int ItemOptionRandomContext::FUN_1405d9bb0(int nStatId)
{
    return FUN_140166430()->FUN_1405f62c0(nStatId);
}

// @0x1405d9be0
void ItemOptionRandomContext::FUN_1405d9be0(MS2Ptr<Unk_1405e74c0> spTarget)
{
    m_spTarget = spTarget;
}

// @0x1405d9c30
BOOL ItemOptionRandomContext::FUN_1405d9c30(CString strName)
{
    if (FUN_1405d9e00() == 2 && FUN_1405db0b0(m_spOption, strName))
        return 1;
    return 0;
}

// @0x1405d9d10
BOOL ItemOptionRandomContext::FUN_1405d9d10(CString strName)
{
    if (FUN_1405d9e00() == 2 && FUN_1405db0b0(m_spTarget->m_spResult, strName))
        return 1;
    return 0;
}

// @0x1405d9e00
ItemOptionStatGroup ItemOptionRandomContext::FUN_1405d9e00()
{
    return m_spRandom->FUN_1405d3ca0();
}

// @0x1405d9e30
int ItemOptionRandomContext::FUN_1405d9e30()
{
    return m_n50;
}

// @0x1405d9e50
MS2Ptr<CItemOption> ItemOptionRandomContext::FUN_1405d9e50()
{
    return m_spOption;
}

// @0x1405d9ea0
// Adds a rolled row to the option (one of nCount); a special stat the option already has, or a second stat of an
// exclusive group, is refused.
int ItemOptionRandomContext::FUN_1405d9ea0(MS2Ptr<ItemOptionValueRandom> spValue, Unk_Random* pRandom, int* pCount,
                                           Unk_ProbabilityLog* pLogs)
{
    if (*pCount == 0)
        return 0;
    auto log = [this, spValue, pLogs](int nValue) -> bool
    {
        if (!pLogs)
            return true;
        return FUN_14073ede0(m_spRandom->FUN_1405d3cc0(), spValue->FUN_1405d27c0(), nValue, pLogs);
    };
    if (spValue->FUN_1405d2750() == -1)
    {
        if (FUN_14081d650(m_spOption, 2, spValue->FUN_1405d2770()) != 0)
            return 0;
        if (FUN_1405d9c30(spValue->FUN_1405d26c0()))
            return 0;
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d28d0(MS2Ptr<ItemOptionRandomContext>(this), pRandom));
        if (m_spOption->FUN_1405cb2a0(2, spValue->FUN_1405d2770(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    else
    {
        if (FUN_1405d9c30(spValue->FUN_1405d26c0()))
            return 0;
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d28d0(MS2Ptr<ItemOptionRandomContext>(this), pRandom));
        if (m_spOption->FUN_1405cb200(2, spValue->FUN_1405d2750(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    return 0;
}

// @0x1405da4b0
// The same with the table's fixed value of the row (FUN_1405d2800) and the roll order kept on the option.
int ItemOptionRandomContext::FUN_1405da4b0(MS2Ptr<ItemOptionValueRandom> spValue, int* pCount, int nIndex,
                                           Unk_ProbabilityLog* pLogs)
{
    if (*pCount == 0)
        return 0;
    auto log = [this, spValue, pLogs](int nValue) -> bool
    {
        if (!pLogs)
            return true;
        return FUN_14073ede0(m_spRandom->FUN_1405d3cc0(), spValue->FUN_1405d27c0(), nValue, pLogs);
    };
    if (spValue->FUN_1405d2750() == -1)
    {
        if (FUN_14081d650(m_spOption, 2, spValue->FUN_1405d2770()) != 0)
            return 0;
        if (FUN_1405d9c30(spValue->FUN_1405d26c0()))
            return 0;
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->m_nIndex = nIndex;
        spBase->FUN_140266e90(spValue->FUN_1405d2800(MS2Ptr<ItemOptionRandomContext>(this)));
        if (m_spOption->FUN_1405cb2a0(2, spValue->FUN_1405d2770(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    else
    {
        if (FUN_1405d9c30(spValue->FUN_1405d26c0()))
            return 0;
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->m_nIndex = nIndex;
        spBase->FUN_140266e90(spValue->FUN_1405d2800(MS2Ptr<ItemOptionRandomContext>(this)));
        if (m_spOption->FUN_1405cb200(2, spValue->FUN_1405d2750(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    return 0;
}

// @0x1405daad0
// The reroll variant: adds to the request's result.
int ItemOptionRandomContext::FUN_1405daad0(MS2Ptr<ItemOptionValueRandom> spValue, int* pCount,
                                           Unk_ProbabilityLog* pLogs)
{
    if (*pCount == 0)
        return 0;
    if (FUN_1405d9d10(spValue->FUN_1405d26c0()))
        return 0;
    auto log = [this, spValue, pLogs](int nValue) -> bool
    {
        if (!pLogs)
            return true;
        return FUN_14073ede0(m_spRandom->FUN_1405d3cc0(), spValue->FUN_1405d27c0(), nValue, pLogs);
    };
    if (spValue->FUN_1405d2750() == -1)
    {
        if (m_spTarget->m_nRoll == 0)
            return 1;
        if (FUN_14081d650(m_spTarget->m_spResult, 2, spValue->FUN_1405d2770()) != 0)
            return 0;
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d2800(MS2Ptr<ItemOptionRandomContext>(this)));
        if (m_spTarget->m_spResult->FUN_1405cb2a0(2, spValue->FUN_1405d2770(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    else
    {
        Unk_EnchantPtr<BaseOption> spBase(new BaseOption);
        spBase->FUN_140266e90(spValue->FUN_1405d2800(MS2Ptr<ItemOptionRandomContext>(this)));
        if (m_spTarget->m_spResult->FUN_1405cb200(2, spValue->FUN_1405d2750(), spBase))
        {
            log(spBase->FUN_140266e30());
            (*pCount)--;
            return 1;
        }
    }
    return 0;
}

// @0x1405db0b0
// The option holds a stat of the name's exclusive group.
BOOL ItemOptionRandomContext::FUN_1405db0b0(MS2Ptr<CItemOption> spOption, CString strName)
{
    Unk_OptionNameListPtr spNames = FUN_140166430()->FUN_1405f6e40(strName);
    if (spNames.get() == 0)
        return 0;
    POSITION pos = spNames->GetHeadPosition();
    while (pos != NULL)
    {
        const CString& strOther = spNames->GetNext(pos);
        int nSpecial = FUN_14081d260(strOther);
        if (nSpecial != 0)
        {
            if (spOption->FUN_1405cb800(2, nSpecial).get() != 0)
                return 1;
        }
        int nStat = FUN_14082ee80(strOther);
        if (nStat != -1)
        {
            if (spOption->FUN_1405cb760(2, nStat).get() != 0)
                return 1;
        }
    }
    return 0;
}

template <class T>
inline bool Unk_ItemOptionPicker<T>::Pick(Unk_Random* pRandom, T& out) const
{
    if (m_total == 0)
        return false;
    unsigned roll = pRandom->FUN_1407684c0() % m_total + 1;
    typename std::map<unsigned, Entry>::const_iterator it = m_entries.lower_bound(roll);
    if (it == m_entries.end())
        return false;
    out = it->second.value;
    return true;
}

template <class T>
inline bool Unk_ItemOptionPicker<T>::PickN(std::vector<T>& out, unsigned n, Unk_Random* pRandom) const
{
    if (m_total == 0)
        return false;
    if (m_entries.size() < n)
        return false;
    std::map<unsigned, Entry> remain(m_entries);
    unsigned total = m_total;
    while (n != 0 && total != 0)
    {
        unsigned roll = pRandom->FUN_1407684c0() % total + 1;
        std::map<unsigned, Entry> cur(remain);
        typename std::map<unsigned, Entry>::iterator it = cur.lower_bound(roll);
        if (it == cur.end())
            return false;
        out.push_back(it->second.value);
        cur.erase(it);
        total = 0;
        remain.clear();
        for (typename std::map<unsigned, Entry>::iterator it2 = cur.begin(); it2 != cur.end(); ++it2)
        {
            total += it2->second.weight;
            remain.insert(std::make_pair(total, it2->second));
        }
        --n;
    }
    return true;
}
