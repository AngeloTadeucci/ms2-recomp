// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Shared game utilities: host/IP lookups, string splitting
// and parsing helpers, easing calculators and the common STL/ATL instantiations they pull in.
// MS2-UNIT: commonfiles\commonutil.cpp
// MS2-RANGE: 0x14028b820-0x14029dff0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0$$V@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAA@U_Zero_then_variadic_args_t@1@@Z 0x140292390 ; unique
// MS2-PIN: ??$_Destroy_range@V?$allocator@H@std@@@std@@YAXPEAH0AEAV?$allocator@H@0@@Z 0x140293110 ; unique
// MS2-PIN: ??0?$_Vector_val@U?$_Simple_types@H@std@@@std@@QEAA@XZ 0x140296da0 ; unique
// MS2-PIN: ??0?$allocator@H@std@@QEAA@XZ 0x140296e00 ; prop
// MS2-PIN: ??0?$vector@HV?$allocator@H@std@@@std@@QEAA@XZ 0x140297080 ; unique
// MS2-PIN: ??A?$vector@HV?$allocator@H@std@@@std@@QEAAAEAH_K@Z 0x140297cb0 ; unique
// MS2-PIN: ?_Destroy@?$vector@HV?$allocator@H@std@@@std@@AEAAXPEAH0@Z 0x14029a860 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14029b840 ; prop
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14029b860 ; prop
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$allocator@H@2@XZ 0x14029b910 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14029b9b0 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@H@std@@V?$_Vector_val@U?$_Simple_types@H@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@H@std@@@2@XZ 0x14029b9c0 ; prop
// MS2-PIN: ?_Getal@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAV?$allocator@H@2@XZ 0x14029bab0 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x14029bf90 ; prop
// MS2-PIN: ?_Myend@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x14029bfb0 ; prop
// MS2-PIN: ?_Myfirst@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x14029bfd0 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAAEAPEAHXZ 0x14029c010 ; prop
// MS2-PIN: ?_Mylast@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEBAAEBQEAHXZ 0x14029c030 ; prop
// MS2-PIN: ?_Orphan_all@?$_Vector_alloc@U?$_Vec_base_types@HV?$allocator@H@std@@@std@@@std@@QEAAXXZ 0x14029c050 ; prop
// MS2-PIN: ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@AEAAXXZ 0x14029c440 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonutil.cpp"
#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <atltime.h>
#include <time.h>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/mstime.h"
#include "hook/ms2hook.h"

int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax);

struct Unk_CommonVec3 { float x, y, z; };

extern long g_lUniqueSeq;
void FUN_1402929a0(const CStringW& strText, std::vector<int>& arrOut, const wchar_t* pszDelim);
bool FUN_14028d470(float fValue, float fTolerance);
float FUN_14029d220(float fValue);                              // fabs
float FUN_14029d430(float fValue, float fDivisor);              // fmod

// Unrecovered helpers.
CString FUN_140188f50(const char* psz, int n);                  // CString from a C string
CString FUN_14016a5c0(const char* psz, int n);
long FUN_140298fd0(long* plValue);                              // interlocked increment
__int64 FUN_140869440();                                        // current server time
CString FUN_140298360(const char* pszPrefix, const CString& str);

class Unk_StringMgr                                             // localized string table
{
public:
    CString FUN_140229600(int nId);                             // narrow text of a string id
    CString FUN_140229690(const CString& strKey);               // narrow text of a key
    CStringW FUN_140229760(int nId);                            // wide text of a string id
    CStringW FUN_140229820(const CStringW& strKey);
    CStringW FUN_140229940(const CString& strKey);              // wide text of a "$..." key
};

// Date printed with a strftime format (the format text lives at +8).
class Unk_TimeFormat
{
public:
    Unk_TimeFormat();                                           // 0x14028da50
    void SetFormat(CString strFormat);                          // 0x14028dac0
    CString Format() const;                                     // 0x14028db10
    ~Unk_TimeFormat() { }                                       // 0x140297910

    ATL::CTime m_time;
    CString m_strFormat;
};
MS2_CHECK_SIZE(Unk_TimeFormat, 0x10);

// Easing distance calculators: base interface and its three implementations.
class IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance) = 0;
};

class LinearCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
};

class EaseOutCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
};

class EaseInCalculator : public IDistanceCalculator
{
public:
    virtual float vfunc_0(float fDelta, float fTime, float fDuration, float fDistance);
};

void FUN_14015f050(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim);
bool FUN_14036e510(void* pFeatures);
void* FUN_140166410();
int FUN_1406516b0();
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
CStringW FUN_140298ea0(CStringW strKey);
CStringW FUN_14016a730(const char* psz, int n);                 // narrow -> wide
CString FUN_14016a600(const wchar_t* pwsz, int n);              // wide -> narrow
Unk_StringMgr* FUN_14025e7d0();
void FUN_14029dd60(const char* pszText, const char* pszFormat, int* pnA, int* pnB, int* pnC, int* pnD, int* pnE, int* pnF);
void FUN_1401d3700(CString& strPath);
bool FUN_140184310(const CString& strText, const char* pszPrefix);
std::string FUN_140291f90(const std::string& strToken, int nWhich);

bool FUN_140299100(const CAtlArray<CString>& arr);              // IsEmpty

// @0x14028b820
tm* FUN_14028b820(const __time64_t* pTime)
{
    return _localtime64(pTime);
}

// Overflow-checked add (HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW) on wrap).
// @0x14028b840
HRESULT FUN_14028b840(int nA, unsigned uB, int* pnOut)
{
    if (nA + uB < uB)
        return 0x80070216;
    *pnOut = nA + uB;
    return 0;
}

// Overflow-checked 32-bit multiply.
// @0x14028b890
HRESULT FUN_14028b890(unsigned uA, unsigned uB, unsigned* puOut)
{
    unsigned long long ull64Result = (unsigned long long)uA * uB;
    if (ull64Result <= 0xffffffffull)
    {
        *puOut = (unsigned)ull64Result;
        return 0;
    }
    return 0x80070216;
}

// Looks a key up in the localized string table; empty when the table is not up yet.
// @0x14028b8e0
CStringW FUN_14028b8e0(const CStringW& strKey)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->FUN_140229820(strKey);
}

// First IPv4 address of this host as a big-endian-packed value (a.b.c.d -> 0xaabbccdd).
// @0x14028b960
unsigned FUN_14028b960()
{
    char szHost[256];
    unsigned uAddr = 0;
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (pHost == 0)
            return 0;
        unsigned char* pbAddr = (unsigned char*)pHost->h_addr_list[0];
        uAddr |= (unsigned)*pbAddr++ << 24;
        uAddr |= (unsigned)*pbAddr++ << 16;
        uAddr |= (unsigned)*pbAddr++ << 8;
        uAddr |= (unsigned)*pbAddr++;
        return uAddr;
    }
    return 0;
}

// Same lookup, little-endian packed.
// @0x14028ba90
unsigned FUN_14028ba90()
{
    char szHost[256];
    unsigned uAddr = 0;
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (pHost == 0)
            return 0;
        unsigned char* pbAddr = (unsigned char*)pHost->h_addr_list[0];
        uAddr |= (unsigned)*pbAddr++;
        uAddr |= (unsigned)*pbAddr++ << 8;
        uAddr |= (unsigned)*pbAddr++ << 16;
        uAddr |= (unsigned)*pbAddr++ << 24;
        return uAddr;
    }
    return 0;
}

// This host's first IPv4 address as dotted text.
// @0x14028bbc0
CString FUN_14028bbc0()
{
    CString strAddr;
    char szHost[256];
    if (gethostname(szHost, 256) == 0)
    {
        hostent* pHost = gethostbyname(szHost);
        if (!pHost)
            return "";
        in_addr* pAddr = (in_addr*)pHost->h_addr_list[0];
        strAddr.Format("%d.%d.%d.%d", pAddr->S_un.S_un_b.s_b1, pAddr->S_un.S_un_b.s_b2, pAddr->S_un.S_un_b.s_b3, pAddr->S_un.S_un_b.s_b4);
    }
    return strAddr;
}

// Dotted text of a packed IPv4 address.
// MS2-FUNCTIONAL: exe frame carries a /GS cookie for an unrecovered local (in_addr copy); ours does not
// @0x14028bd10
CString FUN_14028bd10(int nAddr)
{
    in_addr kAddr;
    kAddr.s_addr = nAddr;
    CString strAddr = FUN_140188f50(inet_ntoa(kAddr), 0);
    return strAddr;
}

// ---- string splitting and parsing helpers ----

// "r,g,b" -> 0xffRRGGBB.
// MS2-FUNCTIONAL: stack slot order of return temp vs r/g/b locals differs
// @0x14028c0d0
unsigned FUN_14028c0d0(const char* pszText)
{
    CString strText(pszText);
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3) == 0)
        return 0;
    unsigned uRed = atoi(arrParts[0]);
    unsigned uGreen = atoi(arrParts[1]);
    unsigned uBlue = atoi(arrParts[2]);
    uRed = (uRed & 0xff) << 16 | 0xff000000 | (uGreen & 0xff) << 8 | uBlue & 0xff;
    return uRed;
}

// 0xffRRGGBB -> "r,g,b".
// @0x14028c210
CString FUN_14028c210(unsigned uColor)
{
    unsigned uRed = uColor >> 16 & 0xff;
    unsigned uGreen = uColor >> 8 & 0xff;
    unsigned uBlue = uColor & 0xff;
    CString strColor;
    strColor.Format("%d,%d,%d", uRed, uGreen, uBlue);
    return strColor;
}

// "x,y,z" -> three floats; left untouched when the text does not split into three parts.
// @0x14028c2d0
void FUN_14028c2d0(CString strText, Unk_CommonVec3* pOut)
{
    CAtlArray<CString> arrParts;
    if (FUN_14028c3e0(strText, arrParts, ",", 3) == 0)
        return;
    pOut->x = (float)atof(arrParts[0]);
    pOut->y = (float)atof(arrParts[1]);
    pOut->z = (float)atof(arrParts[2]);
}

// Tokenizes by any character of pszDelim, at most nMax parts (the last one keeps the remaining text).
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c3e0
int FUN_14028c3e0(const CString& strText, CAtlArray<CString>& arrOut, const char* pszDelim, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
        return 1;
    }
    int nPos = 0;
    CString strToken = strText.Tokenize(pszDelim, nPos);
    while (!strToken.IsEmpty())
    {
        arrOut.Add(strToken);
        if ((size_t)(nMax - 1) < arrOut.GetCount())
        {
            arrOut.Add(strText.Mid(nPos));
            return 1;
        }
        strToken = strText.Tokenize(pszDelim, nPos);
    }
    return 0;
}

// Splits on pszSep, returns whether exactly nExpected parts came out.
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c570
int FUN_14028c570(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep, int nExpected)
{
    CString strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
    if (arrOut.GetCount() == nExpected)
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c700
void FUN_14028c700(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep)
{
    CString strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
}

// Splits on pszSep into at most nMax parts (the last one keeps the remaining text).
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028c850
void FUN_14028c850(const CString& strText, CAtlArray<CString>& arrOut, const char* pszSep, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
    }
    else
    {
        CString strPart;
        int nPos = 0;
        for (int i = 0; i < nMax; ++i)
        {
            int nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (nMax - 1 <= i)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            nPos = nFound + 1;
        }
    }
}

// Collects the text between each pair of strOpen/strClose markers.
// MS2-FUNCTIONAL: stack-slot layout of the compiler temps differs from the exe
// @0x14028ca50
void FUN_14028ca50(const CString& strText, CAtlArray<CString>& arrOut, const CString& strOpen, const CString& strClose)
{
    if (strText.IsEmpty())
        return;
    int nPos = 0;
    while (true)
    {
        int nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            break;
        nPos = strText.Find(strClose, nPos);
        if (nPos == -1)
            return;
        CString strInner = strText.Mid(nOpen);
        if (0 < strInner.GetLength())
            arrOut.Add(strInner);
        nPos = nPos + 1;
    }
}

// @0x14028cb70
int FUN_14028cb70(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nExpected)
{
    CStringW strPart;
    int nPos = 0;
    int nFound;
    while ((nFound = strText.Find(pszSep, nPos)) != -1)
    {
        strPart = strText.Mid(nPos);
        arrOut.Add(strPart);
        nPos = nFound + 1;
    }
    strPart = strText.Mid(nPos);
    arrOut.Add(strPart);
    if (arrOut.GetCount() == nExpected)
        return 1;
    return 0;
}

// @0x14028cd00
void FUN_14028cd00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const wchar_t* pszSep, int nMax)
{
    if (nMax < 2)
    {
        arrOut.Add(strText);
    }
    else
    {
        CStringW strPart;
        int nPos = 0;
        for (int i = 0; i < nMax; ++i)
        {
            int nFound = strText.Find(pszSep, nPos);
            if (nFound == -1)
            {
                strPart = strText.Mid(nPos);
                arrOut.Add(strPart);
                break;
            }
            if (nMax - 1 <= i)
            {
                arrOut.Add(strText.Mid(nPos));
                return;
            }
            strPart = strText.Mid(nPos);
            arrOut.Add(strPart);
            nPos = nFound + 1;
        }
    }
}

// @0x14028cf00
void FUN_14028cf00(const CStringW& strText, CAtlArray<CStringW>& arrOut, const CStringW& strOpen, const CStringW& strClose)
{
    if (strText.IsEmpty())
        return;
    int nPos = 0;
    while (true)
    {
        int nOpen = strText.Find(strOpen, nPos);
        if (nOpen == -1)
            break;
        nPos = strText.Find(strClose, nPos);
        if (nPos == -1)
            return;
        CStringW strInner = strText.Mid(nOpen);
        if (0 < strInner.GetLength())
            arrOut.Add(strInner);
        nPos = nPos + 1;
    }
}

// Sums 1 << (n - 1) over a comma separated list of numbers (a bit mask from 1-based indices).
// MS2-FUNCTIONAL: stack-slot layout differs
// @0x14028d020
int FUN_14028d020(const CStringW& strList)
{
    int nMask = 0;
    std::vector<int> arrValues;
    FUN_1402929a0(strList, arrValues, L",");
    for (size_t i = 0; i < arrValues.size(); ++i)
        nMask = nMask + (1 << ((char)arrValues[i] - 1U & 0x1f));
    return nMask;
}

// Unique 64-bit id: server time (offset by 1e9) followed by five digits of a process-wide counter.
// MS2-FUNCTIONAL: stack-slot layout differs
// @0x14028d0e0
__int64 FUN_14028d0e0()
{
    __int64 nId = 0;
    int nSeq = FUN_140298fd0(&g_lUniqueSeq);
    __int64 nTime = FUN_140869440();
    CString strId;
    strId.Format("%09I64d%05d", nTime - 1000000000, nSeq % 100000);
    nId = _atoi64(strId);
    return nId;
}

// @0x14028d1a0
void FUN_14028d1a0(const CString& strText, int* pnOut)
{
    *pnOut = 0;
    if (strText.CompareNoCase("true") == 0)
        *pnOut = 1;
}

// @0x14028d1f0
CString FUN_14028d1f0(const char* psz)
{
    if (psz == 0)
        return "";
    return FUN_140188f50(psz, 0);
}

// Seconds <-> milliseconds helpers.
// @0x14028d260
__int64 FUN_14028d260(float fSeconds)
{
    return (__int64)(fSeconds * 1000.0f);
}

// @0x14028d280
float FUN_14028d280(unsigned uMilliseconds)
{
    return (float)uMilliseconds * 0.001f;
}

// Random float in [-1, 1].
// @0x14028d2a0
float FUN_14028d2a0()
{
    return -1.0f + (2.0f * (float)rand()) / 32767.0f;
}

// Random float in [0, 1].
// @0x14028d2e0
float FUN_14028d2e0()
{
    return (float)rand() / 32767.0f;
}

// Rolls a probability: never for (nearly) zero, always for exactly 1.
// MS2-FUNCTIONAL: result is a 32-bit int slot in the exe; branch shape differs
// @0x14028d310
BOOL FUN_14028d310(float fChance)
{
    if (FUN_14028d470(fChance, 0.0f))
        return FALSE;
    if (fChance == 1.0f)
        return TRUE;
    BOOL bResult = FUN_14028d2e0() <= fChance;
    return bResult;
}

// @0x14028d380
float FUN_14028d380(float fValue)
{
    return fValue * 100.0f;
}

// @0x14028d3a0
float FUN_14028d3a0(float fValue)
{
    return fValue * 0.01f;
}

// Directory part of a path.
// @0x14028d3c0
CString FUN_14028d3c0(CString strPath)
{
    char szDir[256];
    _splitpath(strPath, 0, 0, szDir, 0);
    return CString(szDir);
}

// Whether two floats are closer than 1e-6.
// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d470
bool FUN_14028d470(float fA, float fB)
{
    return FUN_14029d220(fA - fB) < 1e-06f ? true : false;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d4b0
int FUN_14028d4b0(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return 1;
    return 0;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d530
int FUN_14028d530(const Unk_CommonVec3* pA, const Unk_CommonVec3* pB)
{
    if (FUN_14028d470(pA->x, pB->x) && FUN_14028d470(pA->y, pB->y) && FUN_14028d470(pA->z, pB->z))
        return 1;
    return 0;
}

// Wraps an angle in degrees into [-180, 180].
// @0x14028d5b0
float FUN_14028d5b0(float fDegrees)
{
    fDegrees = FUN_14029d430(fDegrees, 360.0f);
    if (180.0f < fDegrees)
        fDegrees = fDegrees - 360.0f;
    if (fDegrees < -180.0f)
        fDegrees = fDegrees + 360.0f;
    return fDegrees;
}

// Appends the first nCount (or nLen when nCount is 0) bytes as upper-case hex.
// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d6d0
void FUN_14028d6d0(const unsigned char* pData, int nLen, CString& strOut, int nCount)
{
    if (nCount == 0)
        nCount = nLen;
    for (int i = 0; i < nLen && i < nCount; ++i)
        strOut.AppendFormat("%02X", pData[i]);
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d760
bool FUN_14028d760(char c)
{
    return c ? true : false;
}

// MS2-FUNCTIONAL: bool/branch lowering and stack slots differ from the exe
// @0x14028d780
bool FUN_14028d780(char c)
{
    return c ? true : false;
}

// ---- file/path name helpers and localized text ----

// Last "/"-separated component of a path.
// @0x14028d7a0
CString FUN_14028d7a0(const CString& strPath)
{
    CAtlArray<CString> arrParts;
    FUN_14015f050(strPath, arrParts, "/");
    if (arrParts.GetCount() == 0)
        return "";
    int nLast = (int)arrParts.GetCount() - 1;
    CString strName = arrParts[nLast];
    return strName;
}

// Second-to-last "/"-separated component of a path (the parent folder name).
// @0x14028d890
CString FUN_14028d890(const CString& strPath)
{
    CAtlArray<CString> arrParts;
    FUN_14015f050(strPath, arrParts, "/");
    if (arrParts.GetCount() < 2)
        return "";
    int nLast = (int)arrParts.GetCount() - 2;
    CString strName = arrParts[nLast];
    return strName;
}

// @0x14028d990
CString FUN_14028d990(const CString& strPath)
{
    if (FUN_14036e510(FUN_140166410()))
        return FUN_14028d890(strPath);
    return FUN_14028d7a0(strPath);
}

// @0x14028da10
unsigned char FUN_14028da10()
{
    int nType = FUN_1406516b0();
    unsigned char ucResult = 0;
    if (nType == 3)
        ucResult = 4;
    else
        ucResult = 1;
    return ucResult;
}

// Current server time plus the format used to print it.
// @0x14028da50
Unk_TimeFormat::Unk_TimeFormat() : m_time(FUN_140869440())
{
    m_strFormat = L"%A, %B %d, %Y, %H:%M";
}

// @0x14028dac0
void Unk_TimeFormat::SetFormat(CString strFormat)
{
    m_strFormat = strFormat;
}

// @0x14028db10
CString Unk_TimeFormat::Format() const
{
    return m_time.Format(m_strFormat);
}

// @0x14028db70
CString FUN_14028db70()
{
    Unk_TimeFormat kTime;
    return kTime.Format();
}

// "Mon DD YYYY HH:MM:SS" of the build.
// @0x14028dbd0
CString FUN_14028dbd0()
{
    CString strBuild;
    strBuild.Format("%s %s", "Apr 13 2022", "17:36:52");
    return FUN_140188f50(strBuild, 0);
}

// @0x14028dc60
void* FUN_14028dc60(void* p)
{
    return p;
}

// String table lookups: narrow text of an id / of a key, wide text with {n} arguments.
// @0x14028dc80
CString FUN_14028dc80(int nId)
{
    return FUN_14025e7d0()->FUN_140229600(nId);
}

// @0x14028dcd0
CString FUN_14028dcd0(const CString& strKey)
{
    return FUN_14025e7d0()->FUN_140229690(strKey);
}

// @0x14028dd20
CString FUN_14028dd20(int nId, const fmt::ArgList& args)
{
    return FUN_14016a600(FUN_14028dee0(nId, args), 0);
}

// @0x14028ddb0
CString FUN_14028ddb0(const CString& strKey, const fmt::ArgList& args)
{
    return FUN_14016a600(FUN_140298ea0(FUN_14016a730(strKey, 0)), 0);
}

// @0x14028de60
CStringW FUN_14028de60(int nId)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    return FUN_14025e7d0()->FUN_140229760(nId);
}

// @0x14028dee0
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args)
{
    CStringW strText = FUN_14028de60(nId);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// @0x14028dfa0
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args)
{
    CStringW strText = FUN_14028b8e0(strKey);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// @0x14028e060
CStringW FUN_14028e060(const CString& strKey, const fmt::ArgList& args)
{
    if (FUN_14025e7d0() == 0)
        return L"";
    CStringW strText = FUN_14025e7d0()->FUN_140229940(strKey);
    if (strText.IsEmpty())
        return L"";
    return StringFormat(strText, args);
}

// Day-of-week number (1 = Sun .. 7 = Sat) of a three-letter abbreviation, 0 when unknown.
// @0x14028e160
int FUN_14028e160(CString& strDay)
{
    if (strDay.IsEmpty())
        return 0;
    if (strDay.CompareNoCase("sun") == 0)
        return 1;
    else if (strDay.CompareNoCase("mon") == 0)
        return 2;
    else if (strDay.CompareNoCase("tue") == 0)
        return 3;
    else if (strDay.CompareNoCase("wed") == 0)
        return 4;
    else if (strDay.CompareNoCase("thu") == 0)
        return 5;
    else if (strDay.CompareNoCase("fri") == 0)
        return 6;
    else if (strDay.CompareNoCase("sat") == 0)
        return 7;
    return 0;
}

// Parses a date/time text with a scanf-style format into a CMsTime; false when out of range.
// MS2-FUNCTIONAL: compiler temp-copy spill layout and EH state count differ
// @0x14028e280
int FUN_14028e280(CMsTime& kOut, const CString& strFormat, const CString& strText)
{
    int nYear = 0;
    int nMonth = 0;
    int nDay = 0;
    int nHour = 0;
    int nMinute = 0;
    int nSecond = 0;
    FUN_14029dd60((LPCSTR)CString(strText), (LPCSTR)CString(strFormat), &nYear, &nMonth, &nDay, &nHour, &nMinute, &nSecond);
    if (!(nYear < 1900 || nMonth < 1 || nMonth > 12 || nDay < 1 || nDay > 31 || nHour < 0 || nHour > 23 || nMinute < 0
          || nMinute > 59 || nSecond < 0 || nSecond > 59))
    {
        kOut = CMsTime(nYear, nMonth, nDay, nHour, nMinute, nSecond);
        return 1;
    }
    return 0;
}

// @0x14028e440
CString FUN_14028e440(const ATL::CTime& kTime, const CString& strFormat)
{
    CString strResult;
    strResult.Format(strFormat, kTime.GetYear(), kTime.GetMonth(), kTime.GetDay(), kTime.GetHour(), kTime.GetMinute(),
                     kTime.GetSecond());
    return strResult;
}

// Replaces every "(token)" in the text with its translation; true when anything was found.
// MS2-FUNCTIONAL: std::string temp/EH layout differs
// @0x14028e560
bool FUN_14028e560(std::string& strText, int nWhich)
{
    bool bFound = false;
    const wchar_t* pwszDelim = L"()";
    while (true)
    {
        size_t nOpen = strText.find((char)pwszDelim[0], 0);
        if (nOpen == (size_t)-1)
            return bFound;
        size_t nClose = strText.find((char)pwszDelim[1], nOpen);
        if (nClose == (size_t)-1)
            break;
        std::string strToken;
        strToken = strText.substr(nOpen + 1, nClose - nOpen - 1);
        if (strToken.size() == 0)
            return bFound;
        bFound = true;
        std::string strTranslated = FUN_140291f90(strToken, nWhich);
        strText.replace(strText.begin() + nOpen, strText.begin() + nClose + 1, strTranslated.c_str());
    }
    return bFound;
}

// Normalizes a data path to "./data/..." with forward slashes.
// @0x14028e7c0
void FUN_14028e7c0(CString& strPath)
{
    FUN_1401d3700(strPath);
    CString strHead = strPath.Left(4);
    if (FUN_140184310(strHead, "data"))
        strPath = FUN_140298360("./", strPath);
    else if (FUN_140184310(strHead, "/data"))
        strPath = FUN_140298360(".", strPath);
    strPath.Replace('\\', '/');
}

// @0x14028e900
int FUN_14028e900(CString strPath)
{
    int nResult = 0;
    try
    {
        CFile::Remove(strPath, 0);
        nResult = 1;
    }
    catch (CFileException* pException)
    {
        pException->Delete();
    }
    return nResult;
}

// Easing calculator factory: 0 linear, 1 ease out, 2 ease in.
// @0x14028e960
IDistanceCalculator* FUN_14028e960(int nType)
{
    if (nType == 0)
        return new LinearCalculator();
    else if (nType == 1)
        return new EaseOutCalculator();
    else if (nType == 2)
        return new EaseInCalculator();
    else
        return 0;
}
