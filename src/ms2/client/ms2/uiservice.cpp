// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUIService: the UI manager service. See uiservice.h.
// MS2-UNIT: ?\uiservice.cpp
// MS2-RANGE: 0x14011d200-0x14011d540 .text$di
// MS2-RANGE: 0x141ad8bc0-0x141af2110 .text$mn
// MS2-PIN: ??_7CUIService@@6BISystemService@efd@@@ 0x142fe2580
// MS2-PIN: ??_7CUIService@@6B?$TSingleton@VCUIService@@@@@ 0x142fe2608
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiservice.h"
#include "ms2/client/ms2/gfxmoviebackground.h"
#include "ms2/client/ms2/uidialog.h"
#include <new>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders ----

// The Scaleform movie manager (global at FUN_14025e7a0).
class Unk_UisMovieMgr
{
public:
    void FUN_1422adc90(void* pMovie);                               // add a background movie
    void FUN_1422addb0();
    int FUN_1422ade10(void* pMovie);
    void FUN_1422adf30();
    void* FUN_1422b01a0(int n);                                     // GFxMovie of a layer
    int FUN_1422af2d0(int n);
    void FUN_1422ae960(int n);
    int FUN_1422aeed0(int n);
    void FUN_1422aff10(float f);
    void FUN_1422afec0(int n);
    void FUN_1422aebe0(int nSlot, bool bOn);
};
Unk_UisMovieMgr* FUN_14025e7a0();

// ---- exe helpers the service reaches ----
void* FUN_1403ed2d0();                                              // world service
void* FUN_1403ed2b0();
void* FUN_141bd0cc0(void* pWorld);                                  // the player character of the world
void* FUN_1409670e0();
char FUN_1410c3600(void* p, int n);
void* FUN_1401d3200();
void* FUN_140166410();
char FUN_14036d570(void* p, int n);
void* FUN_140b632f0();
void FUN_1422d4a30(void* p, char b);
void FUN_1422d49f0(void* p);
void* FUN_141540270(int nClass);
void* FUN_141aed500(int nClass);
void* FUN_14151f890();
void FUN_14151f460(int n);
void FUN_141a60d40(int n);
int FUN_1418fd280();
void* FUN_140ef49b0(int nClass);
void FUN_140c296e0(void* p, int n);
int FUN_1412755a0();
void* FUN_141278110(int nClass);
void* FUN_141742c80(int nClass);
void* FUN_140e86a50(int nClass);
void* FUN_140e98660(int nClass);
void* FUN_141994a90(int nClass);
void* FUN_141a62100(int nClass);
void* FUN_141930440(int nClass);
void* FUN_14128f650(int nClass);
void* FUN_1418fc4e0(int nClass);
void* FUN_141a90250(int nClass);
void* FUN_1409614b0(int nClass);
void* FUN_1419949f0(int nClass);
void FUN_1422dbf00(void* p, int a, int b, int c);
void FUN_1422dc080(void* p);
void* FUN_14138fd50(int nClass);
void FUN_14190f180(void* p);
void* FUN_141aed5a0(int nClass);
void FUN_14135afa0(void* p, int n);
void* FUN_14096e340(int nClass);
void FUN_141b4d0a0(void* p);
void* FUN_14136f290(int nClass);
void FUN_141908690(void* p);
void FUN_1419dfa60(void* p, int n);
void FUN_1419dff50(void* p, void* a, int b, int c);
void FUN_1419dfd90(void* p);
void* FUN_140a94350();
float FUN_141276490(float f, float g);
extern unsigned DAT_143af62d4;
extern char DAT_143af62e0;

// ---- the unit's own containers and glue (bodies are unit glue) ----
void FUN_1416ae2a0(void* p, int n);
void FUN_1416aecf0(void* p);
void FUN_141aed9e0(void* p, int nBins, float fOpt, float fLow, float fHigh, int nBlock);
void FUN_141aed8f0(void* p, int nBins, float fOpt, float fLow, float fHigh, int nBlock);
void FUN_141aed800(void* p, int nBins, float fOpt, float fLow, float fHigh, int nBlock);
void FUN_140163400(void* p, int nBins, float fOpt, float fLow, float fHigh, int nBlock);
void FUN_141926ff0(void* p, int nBlock);
void FUN_141927180(void* p);
void FUN_1401642a0(void* p);
void FUN_141aedd80(void* p, int n);
void FUN_141aee240(void* p);
void FUN_141aee130(void* p);
void FUN_141aee160(void* p);
void FUN_141aee190(void* p);
void FUN_141af0f00(void* p);
void FUN_141af0df0(void* p);
void FUN_141af0ce0(void* p);
void FUN_141aee3b0(void* p, int n);
void FUN_141aee9a0();
void FUN_141aeec30();
void FUN_141aeec90();
void FUN_140a5bb80(void* p);
void FUN_140a5bba0(void* p);
char FUN_140361ab0(void* pMap, int nKey, int* pVal);                // CAtlMap<int,int>::Lookup
void FUN_14016a050(void* pMap, int nKey, int nVal);                 // CAtlMap<int,int>::SetAt
void* FUN_141aee850(void* pList, const int* pVal);                  // CAtlList<int>::AddTail
CStringA FUN_14071a5b0(const CStringA& strKey, const CStringA& strFile);

// A weak dialog reference (vptr / pointer pair, 0x20 bytes of storage in the callers).
struct Unk_UisRef
{
    char m_pad[0x20];
};
Unk_UisRef* FUN_141aede30(Unk_UisRef* p, int n);
UIDialog* FUN_1412784d0(Unk_UisRef* p);                        // get (checked)
UIDialog* FUN_1412784f0(Unk_UisRef* p);                        // operator->
void FUN_141278470(Unk_UisRef* p);                                  // release
bool FUN_141aefc70(void* pMap, const int* pKey, Unk_UisRef* pOut);  // Lookup
bool FUN_141aee4a0(Unk_UisRef* p);                                  // is null
void FUN_141aeddf0(Unk_UisRef* pDst, Unk_UisRef* pSrc);             // copy
void* FUN_141aef6d0(void* pMap);                                    // first position
Unk_UisRef* FUN_141aef740(void* pMap, void* pos);                   // value at position
void FUN_141aef370(void* pMap, void** pPos);                        // next position
void FUN_141aed470(void* pLog, int a, int b, const wchar_t* pszFmt, const int* pArg);
void* FUN_140166440();
int FUN_1419244c0(UIDialog* p, int n);
void FUN_141924680(UIDialog* p);
void FUN_1419246f0(UIDialog* p);
int FUN_141924740(UIDialog* p);

// ---------------------------------------------------------------------------------------------------------------
// CUIService
// ---------------------------------------------------------------------------------------------------------------

inline TSingleton<CUIService>::TSingleton() { s_instance = static_cast<CUIService*>(this); }

// @0x141ad8bc0
// MS2-FUNCTIONAL: container glue called through the exe; branch/temporary layout differs
CUIService::CUIService()
    : m_nMode(0x3ed), m_n11c(0), m_b120(0), m_n124(0), m_n128(0), m_n12c(0), m_n130(0), m_nCursor(0)
{
    m_pWorldSvc30 = 0;
    FUN_1416ae2a0(&m_x38, 0);
    FUN_141aed9e0(&m_mapA, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_141aed8f0(&m_mapDlg, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_141aed800(&m_mapC, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_140163400(&m_mapOpen, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_140163400(&m_mapOpen2, 0x11, 0.75f, 0.25f, 2.25f, 10);
    FUN_141926ff0(&m_listOpen, 10);
    FUN_141926ff0(&m_listClose, 10);
    FUN_141aedd80(&m_x268, 0);
    FUN_140a5bb80(&m_log);
    FUN_14016a050(&m_mapOpen, 0x6200018, 0);
    FUN_14016a050(&m_mapOpen, 0x620001d, 0);
    FUN_14016a050(&m_mapOpen, 0x620001f, 0);
    FUN_14016a050(&m_mapOpen, 0x6200031, 0);
    FUN_14016a050(&m_mapOpen, 0x6200041, 0);
    FUN_14016a050(&m_mapOpen, 0x6200022, 0);
    FUN_14016a050(&m_mapOpen, 0x620007f, 0);
    FUN_14016a050(&m_mapOpen2, 0x6200018, 0);
    FUN_14016a050(&m_mapOpen2, 0x620000d, 0);
    FUN_14016a050(&m_mapOpen2, 0x620001d, 0);
    FUN_14016a050(&m_mapOpen2, 0x620001f, 0);
    FUN_14016a050(&m_mapOpen2, 0x6200031, 0);
    FUN_14016a050(&m_mapOpen2, 0x6200041, 0);
    FUN_14016a050(&m_mapOpen2, 0x6200022, 0);
    FUN_14016a050(&m_mapOpen2, 0x620007f, 0);
    FUN_14016a050(&m_mapOpen2, 0x6200086, 0);
    FUN_141aee3b0(&m_x268, 0);
    FUN_141aee9a0();
    m_strTable = FUN_14071a5b0(CStringA("Table"), CStringA("alignWidget.xml"));
    m_cache.FUN_1401d1160(CString(m_strTable));
}

// @0x141ad91c0
// MS2-FUNCTIONAL: container glue called through the exe; branch/temporary layout differs
CUIService::~CUIService()
{
    FUN_140a5bba0(&m_log);
    FUN_141aeec30();
    FUN_141aeec90();
    FUN_141aee240(&m_x268);
    FUN_141927180(&m_listClose);
    FUN_141927180(&m_listOpen);
    FUN_1401642a0(&m_mapOpen2);
    FUN_1401642a0(&m_mapOpen);
    FUN_141aee130(&m_mapC);
    FUN_141aee160(&m_mapDlg);
    FUN_141aee190(&m_mapA);
    FUN_1416aecf0(&m_x38);
}

// @0x141ad9330
const char* CUIService::GetDisplayName() const
{
    return "CUIService";
}
MS2_REPLACE_METHOD(0x141AD9330, CUIService, GetDisplayName, 13, 0xDFB7B125);

// ---- more exe helpers (chunk 2) ----
class Unk_UisBgSvc { public: CStringA FUN_140b67fe0(char nStage); };
Unk_UisBgSvc* FUN_140b6a040();
void* FUN_140876480(void* pOut, int nCat);                          // memory category helper, returns int*
void* FUN_14208a860(unsigned __int64 nSize, unsigned nCat);
// The damage overlay movie (class of an unrecovered unit, ?\gfxmoviedamage.cpp).
class GFxMovieDamage : public GFxMovieEventHandler
{
public:
    void FUN_140b61900(const CStringA& str);
    void FUN_140b61b80(const CStringA& str);
    void FUN_140b61ce0();
    char m_pad_90[0x138 - 0x90];
};
GFxMovieDamage* FUN_140b60ff0(void* pMem);                          // GFxMovieDamage::GFxMovieDamage
void* FUN_1405a8ee0(void* p);
int FUN_1405a39f0(void* p);
CStringA FUN_140719190(int n);
void FUN_1405a8650(void* p);

// @0x141ad9350
// MS2-FUNCTIONAL: call order of the exe containers; branch layout differs
void CUIService::FUN_141ad9350()
{
    FUN_141adc050();
    FUN_141af0f00(&m_mapA);
    FUN_141af0df0(&m_mapDlg);
    FUN_141af0ce0(&m_mapC);
}

// @0x141ad9980
// MS2-FUNCTIONAL: EH frame of the unrecovered temporaries differs
void CUIService::FUN_141ad9980(char nStage)
{
    CStringA strBg = FUN_140b6a040()->FUN_140b67fe0(nStage);
    if (!strBg.IsEmpty())
    {
        int tmp;
        int* cat = (int*)FUN_140876480(&tmp, 0);
        void* mem = FUN_14208a860(0xe8, *cat);
        GFxMovieBackground* pBg = mem ? new (mem) GFxMovieBackground(strBg, 1, 1) : 0;
        FUN_14025e7a0()->FUN_1422adc90(pBg);
    }
}

// @0x141ad9a60
// MS2-FUNCTIONAL: EH frame of the unrecovered temporaries differs
void CUIService::FUN_141ad9a60(CStringA strBg)
{
    if (!strBg.IsEmpty())
    {
        int tmp;
        int* cat = (int*)FUN_140876480(&tmp, 0);
        void* mem = FUN_14208a860(0xe8, *cat);
        GFxMovieBackground* pBg = mem ? new (mem) GFxMovieBackground(strBg, 1, 1) : 0;
        FUN_14025e7a0()->FUN_1422adc90(pBg);
    }
}

// @0x141ad9b30
void CUIService::FUN_141ad9b30()
{
    FUN_14025e7a0()->FUN_1422addb0();
}

// @0x141ad9b60
// MS2-FUNCTIONAL: EH frame of the unrecovered temporaries differs
bool CUIService::FUN_141ad9b60()
{
    int tmp;
    int* cat = (int*)FUN_140876480(&tmp, 0);
    void* mem = FUN_14208a860(0x138, *cat);
    GFxMovieDamage* pDamage = mem ? FUN_140b60ff0(mem) : 0;
    return FUN_14025e7a0()->FUN_1422ade10(pDamage) == 1;
}

// @0x141ad9c10
void CUIService::FUN_141ad9c10()
{
    FUN_14025e7a0()->FUN_1422adf30();
}

// @0x141ad9e20
bool CUIService::FUN_141ad9e20()
{
    if (!FUN_141ad9b60())
        return false;
    return true;
}

// @0x141adbd10
unsigned CUIService::FUN_141adbd10()
{
    return (FUN_14025e7a0()->FUN_1422aeed0(2) == 0 && m_n124 == 0) ? 0 : 1;
}

// @0x141adbd60
void CUIService::FUN_141adbd60(int n)
{
    m_n124 = n;
}

// @0x141adbd80
int CUIService::FUN_141adbd80()
{
    return m_n124 == 0;
}

// @0x141adbdc0
void CUIService::FUN_141adbdc0(int n)
{
    FUN_141adbd60(n == 0);
}

// @0x141adbe00
void CUIService::FUN_141adbe00(float fValue, int bRaw)
{
    float f = fValue;
    if (bRaw == 0)
        f = FUN_141276490((float)DAT_143af62d4, fValue);
    FUN_14025e7a0()->FUN_1422aff10(f);
}

// @0x141adbe70
void CUIService::FUN_141adbe70()
{
    FUN_14025e7a0()->FUN_1422afec0(2);
}

// @0x141adbca0
void CUIService::FUN_141adbca0(int n)
{
    FUN_14025e7a0()->FUN_1422ae960(n);
}

// @0x141adbcd0
void CUIService::FUN_141adbcd0(char b)
{
    if (FUN_140b632f0() != 0)
        FUN_1422d4a30(FUN_140b632f0(), b);
}

// @0x141adbf00
void CUIService::FUN_141adbf00()
{
    if (m_n12c != 0)
        return;
    m_n12c = 1;
}

// @0x141adbf30
void CUIService::FUN_141adbf30()
{
    void* p = FUN_14138fd50(0x4e7e);
    if (p != 0)
        FUN_14190f180(p);
}

// @0x141adbf70
void CUIService::FUN_141adbf70(int n)
{
    void* p = FUN_141aed5a0(0x3ee);
    if (p != 0)
        FUN_14135afa0(p, n);
}

// @0x141adcb40
int CUIService::FUN_141adcb40()
{
    return m_n128;
}

// @0x141add1b0
void CUIService::FUN_141add1b0(int nSlot, bool bOn)
{
    FUN_14025e7a0()->FUN_1422aebe0(nSlot, bOn);
}

// @0x141adb7b0
void CUIService::FUN_141adb7b0(int bOn)
{
    bool b = bOn != 0;
    FUN_141add1b0(0x23, b);
    FUN_141add1b0(0x24, b);
}

// @0x141adbb40
void CUIService::FUN_141adbb40()
{
    m_nCursor = m_nCursor + 1;
    m_nCursor = m_nCursor % 4;
    FUN_141aec8c0(m_nCursor);
}

// @0x141adb4c0
// MS2-FUNCTIONAL: branch layout differs from the exe
void CUIService::FUN_141adb4c0(int bOn)
{
    bool b = bOn != 0;
    FUN_141add1b0(0x19, b);
    FUN_141add1b0(0x11, b);
    FUN_141add1b0(0x13, b);
    FUN_141add1b0(0x1a, b);
    FUN_141add1b0(0xd, b);
    FUN_141add1b0(0xe, b);
    FUN_141add1b0(3, b);
    FUN_141add1b0(0xf, b);
    if (FUN_14036d570(FUN_140166410(), 0xbd) != 0)
        FUN_141add1b0(0x10, b);
    FUN_141add1b0(8, b);
    FUN_141add1b0(0x28, b);
    FUN_141add1b0(0x25, b);
    FUN_141add1b0(0, b);
    FUN_141add1b0(2, b);
    FUN_141add1b0(4, b);
    FUN_141add1b0(5, b);
    FUN_141add1b0(0x14, b);
    FUN_141add1b0(6, b);
    FUN_141add1b0(0x16, b);
    FUN_141add1b0(0x1d, b);
    FUN_141add1b0(0x24, b);
    FUN_141add1b0(0x12, b);
    FUN_141add1b0(10, b);
    FUN_141add1b0(9, b);
    FUN_141add1b0(7, b);
    FUN_141add1b0(1, b);
    FUN_141add1b0(0x1e, b);
    FUN_141add1b0(0x15, b);
    FUN_141add1b0(0x1f, b);
    FUN_141add1b0(0x17, b);
    FUN_141add1b0(0x23, b);
    FUN_141add1b0(0xb, b);
}
