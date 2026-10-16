// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item socket tables (Table/itemSocket.xml), see
// itemsocketsystemutil.h. The unit also holds CItemStatus / CItemUgc / CItemTransfer and the template glue of its
// containers (not recovered yet).
// MS2-UNIT: ?\itemsocketsystemutil.cpp
// MS2-RANGE: 0x1400baa10-0x1400bae70 .text$di
// MS2-RANGE: 0x140626a20-0x140635ec0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GEnableSocketUnlockFunction@CItemSocketSystemUtil@@UEAAPEAXI@Z 0x14062c240 ; unique
// MS2-PIN: memmove_s 0x14062c690 ; unique
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCItemSocketDataContainer@@@@QEAAAEAV1@PEAVCItemSocketDataContainer@@@Z 0x14062e0b0 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCItemSocketData@@@@QEBAPEAVCItemSocketData@@XZ 0x14062e160 ; prop
// MS2-PIN: ??C?$MS2Ptr@VCItemSocketDataContainer@@@@QEBAPEAVCItemSocketDataContainer@@XZ 0x14062e170 ; prop
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCItemSocketData@@@@V?$CElementTraits@V?$MS2Ptr@VCItemSocketData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItemSocketData@@@@_K@Z 0x14062e6b0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCItemSocketData@@@@AEBAXPEAX@Z 0x14062f880 ; unique
// MS2-PIN: ??0?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140633100 ; unique
// MS2-PIN: ??1?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAA@XZ 0x140633210 ; unique
// MS2-PIN: ??A?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@QEAAAEAH_K@Z 0x1406333e0 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCItemData@@@@CAXPEAVCItemData@@@Z 0x140633620 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItemTransfer@@@@QEAA@$$QEAV0@@Z 0x140635bf0 ; unique
// MS2-PIN: ??D?$MS2Ptr@VCItemBinding@CItemTransfer@@@@QEBAAEAVCItemBinding@CItemTransfer@@XZ 0x140635e60 ; unique
// MS2-PIN: ??D?$MS2Ptr@VCItemTransfer@@@@QEBAAEAVCItemTransfer@@XZ 0x140635e70 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CItemSocketTable@@6B?$TSingleton@VCItemSocketTable@@@@@ 0x142d6bd60
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemsocketsystemutil.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "itemsocketsystemutil.h"
#include "ms2/commonfiles/item.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/client/ms2/randomeffectparam.h"

// The statics of the common header.
#include "ms2/placeholder/header_statics_a.h"

// Unrecovered helpers (the same xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char*);                      // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char*);                      // NextSiblingElement
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
bool FUN_14028f710(Unk_140165cf0*);                                 // the element is usable
void FUN_1408731e0(Unk_140165cf0*, const char*, int&);
void FUN_140873220(Unk_140165cf0*, const char*, unsigned int&);
int FUN_14015f500(Unk_140165cf0*, const char*, int*);
int FUN_140178670(Unk_140165cf0*, const char*, ATL::CAtlArray<int>&);

// Item accessors (the CItem members are declared in citem.h; the rest are unrecovered members taken as free functions).
int FUN_14053c560(void* pData);             // kind of the item data record
void* FUN_140527840(CItem* pItem);          // the item's data record
void* FUN_1405279c0(CItem* pItem);          // the item's enhance record (null for none)
int FUN_140620a20(void* pEnhance);          // enhance level
int FUN_140620a50(void* pEnhance);
unsigned char FUN_1406211f0(void* pEnhance);
unsigned char FUN_140528980(CItem* pItem);
int FUN_140525ca0(CItem* pItem);
int FUN_140525db0(CItem* pItem);
unsigned char FUN_140528e20(CItem* pItem);

// @0x140626aa0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Init(MS2Ptr<CItem> pItem, int nSocketMode, int nUnlockMode)
{
    if (pItem == (CItem*)0 || FUN_1405279c0(pItem.get()) == 0)
        return false;
    m_n18 = FUN_14053c560(FUN_140527840(pItem.get()));
    m_n1C = pItem.get()->FUN_140526bd0();
    m_n20 = pItem.get()->FUN_140526a50();
    m_n28 = FUN_140620a20(FUN_1405279c0(pItem.get()));
    m_nSocketMode = nSocketMode;
    m_nUnlockMode = nUnlockMode;
    return true;
}

// @0x140626bc0
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::Matches(MS2Ptr<CItem> pItem)
{
    if (pItem == (CItem*)0)
        return false;
    if (m_n20 == (unsigned __int64)pItem.get()->FUN_140526a50())
        return false;
    if (m_n18 != FUN_14053c560(FUN_140527840(pItem.get())) || m_n1C != pItem.get()->FUN_140526bd0())
        return false;
    void* pEnhance = FUN_1405279c0(pItem.get());
    if (pEnhance == 0 || FUN_140620a50(pEnhance) == 0)
        return false;
    if (m_n28 != FUN_140620a20(pEnhance))
        return false;
    if (FUN_140528980(pItem.get()) == 0)
        return false;
    if (FUN_140525ca0(pItem.get()) != 0 && m_nSocketMode == 0)
        return false;
    if (FUN_140525db0(pItem.get()) != 0 && m_nUnlockMode == 0)
        return false;
    if (FUN_140528e20(pItem.get()) != 0)
        return false;
    if (FUN_1406211f0(pEnhance) != 0)
        return false;
    return true;
}

// @0x140626e20
// MS2-FUNCTIONAL: written from the decompile; not byte-compared yet
bool CItemSocketSystemUtil::EnableSocketUnlockFunction::InitPair(MS2Ptr<CItem> pItem, MS2Ptr<CItem> pOther, int nSocketMode, int nUnlockMode)
{
    if (!Init(pItem, nSocketMode, nUnlockMode))
        return false;
    return Matches(pOther);
}

// @0x14062c7b0
CItemSocketData::CItemSocketData() : m_nGrade(0), m_nMaxCount(0), m_nOpenType(0)
{
}

// @0x14062c830
CItemSocketData::~CItemSocketData()
{
}

// @0x14062c860
CItemSocketDataContainer::CItemSocketDataContainer()
{
}

// @0x14062c8b0
CItemSocketDataContainer::~CItemSocketDataContainer()
{
    m_rows.RemoveAll();
}

// @0x14062c900
// MS2-FUNCTIONAL: Ptr temp order differs
MS2Ptr<CItemSocketData> CItemSocketDataContainer::Find(int nGrade)
{
    if (m_rows.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    size_t nRows = m_rows.GetCount();
    MS2Ptr<CItemSocketData> spDefault(0);
    for (size_t i = 0; i < nRows; i++)
    {
        MS2Ptr<CItemSocketData> spRow = m_rows[i];
        if (spRow == (CItemSocketData*)0)
            continue;
        if (spRow->m_nGrade == nGrade)
            return spRow;
        if (spRow->m_nGrade == 0)
            spDefault = spRow;
    }
    return spDefault;
}

// @0x14062caa0
CItemSocketTable::CItemSocketTable() : m_items(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x14062cb50
CItemSocketTable::~CItemSocketTable()
{
}

// @0x14062cbc0
// MS2-FUNCTIONAL: first-pass source; temp order and the CString locals are not byte-compared
int CItemSocketTable::Load()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("itemSocket.xml"));
    FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 1;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 1;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("itemSocket"); pNode != 0; pNode = pNode->FUN_140168650("itemSocket"))
    {
        if (!FUN_14028f710(pNode))
            continue;
        int nItemId = 0;
        FUN_1408731e0(pNode, "id", nItemId);
        if (nItemId == 0)
            continue;
        ContainerPtr spContainer(0);
        if (!m_items.Lookup(nItemId, spContainer))
            spContainer.AssignRaw(new CItemSocketDataContainer);
        MS2Ptr<CItemSocketData> spData(new CItemSocketData);
        if (spData.IsNull())
            continue;
        FUN_14015f500(pNode, "grade", &spData->m_nGrade);
        FUN_140873220(pNode, "maxCount", spData->m_nMaxCount);
        int nOpenType = 0;
        FUN_1408731e0(pNode, "openType", nOpenType);
        spData->m_nOpenType = nOpenType;
        if (nOpenType == 1)
        {
            ATL::CAtlArray<int> range;
            FUN_140178670(pNode, "randomOpenRange", range);
            if (range.GetCount() == 2)
            {
                spData->m_range.m_nMin = range[0];
                spData->m_range.m_nMax = range[1];
            }
        }
        else if (nOpenType == 0)
        {
            unsigned nCount = 0;
            FUN_140873220(pNode, "fixOpenCount", nCount);
            spData->m_range.m_nMin = nCount;
            spData->m_range.m_nMax = nCount;
        }
        spContainer->m_rows.Add(spData);
        Unk_LockGuard guard(m_lock);
        if (guard == 0)
            m_items.SetAt(nItemId, spContainer);
    }
    return 1;
}

// @0x14062d330
// MS2-FUNCTIONAL: exe branches 'if (guard) skip' as je+jmp (not jne); rest identical
MS2Ptr<CItemSocketData> CItemSocketTable::Find(unsigned nItemId, int nGrade)
{
    if (m_items.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    MS2Ptr<CItemSocketData> spResult(0);
    ContainerPtr spContainer(0);
    {
        Unk_LockGuard guard(m_lock);
        if (guard == 0 && m_items.Lookup(nItemId, spContainer))
            spResult = spContainer->Find(nGrade);
    }
    return spResult;
}

// @0x140626a20
CItemSocketSystemUtil::EnableSocketUnlockFunction::EnableSocketUnlockFunction()
    : m_n18(0), m_n1C(0), m_n20(0), m_n28(0), m_nSocketMode(0), m_nUnlockMode(0)
{
}

// @0x14062c160
// ---- CItemTransfer / CItemTransfer::CItemBinding ----------------------------------------------------------------
CItemSocketTable* FUN_14052d200();
void* FUN_140166410();
bool FUN_14036d570(void* pThis, int nId);      // item.cpp: the socket table singleton (TSingleton<CItemSocketTable>::s_instance)

// ---- CItemStatus ------------------------------------------------------------------------------------------------
// Unrecovered helpers of the option / stat text code.
class Unk_SaInfo { };
struct Unk_SaTable { };                                 // the special ability table (0x20 byte rows, DAT_143ab1a40)
extern Unk_SaTable DAT_143ab1a40;
struct Unk_SaRow
{
    void* m_00;
    int m_nValueType;                                   // +0x08 eOptionValue (0 none, 2 percent)
    int m_0c;
    CStringW m_strFormat;                               // +0x10
    CStringW m_strName;                                 // +0x18
};
Unk_SaRow* FUN_140184750(Unk_SaTable* pTable, __int64 nIndex);
bool FUN_14081dcd0(int nSaType);                        // the SA value is a percent
int FUN_14081d9e0(int nSaType);                         // the SA is a skill level up tier (0x4d - 0x5a)
int FUN_14081da20(int nSaType);                         // the tier of it
bool FUN_14082f250(int nStat);                          // the stat value is a percent
CStringW FUN_14082f000(unsigned nStat);                 // the stat name
CStringW FUN_1409e0900(int nValue);
CStringW FUN_1409e0a90(float fValue);
CStringW FUN_1409e0970(int nStat, int nValue);
CStringW FUN_1409e0bf0(int nStat, int nValue);
bool FUN_14080c370(unsigned nTier, unsigned nJob, ATL::CAtlArray<unsigned>& aSa);   // the SA types a tier grants a job
void FUN_140222be0(ATL::CAtlArray<int>& aJobs);         // the job ids
bool FUN_140187930(ATL::CAtlArray<unsigned>& a);        // IsEmpty
unsigned __int64 FUN_140186270(ATL::CAtlArray<unsigned>& a);   // GetCount
unsigned* FUN_140184510(ATL::CAtlArray<unsigned>& a, unsigned __int64 n);   // operator[]
class Unk_ObjTable { };
Unk_ObjTable* FUN_1403ed2d0();
class Unk_Actor { };
Unk_Actor* FUN_141bd0cc0(Unk_ObjTable*);                // the player's actor
int FUN_141654700(Unk_Actor*);                          // its job
class Unk_JobTable { };
Unk_JobTable* FUN_1401d7a50();
int FUN_140644bb0(Unk_JobTable*, int nJob);             // the job's name id
class Unk_CmnStrings
{
public:
    CStringW FUN_141811980(int nTable, int nIndex);
    CStringW FUN_141812290(int nBuffId, unsigned short nLevel, CString strKey);
};
Unk_CmnStrings* FUN_1401a9d70();
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FormatStringId(int nId, const fmt::ArgList& args);                 // 0x14028dee0
FMT_VARIADIC_W(CStringW, FormatStringId, int)
CStringW FUN_14028dfa0(const CStringW& strKey, const fmt::ArgList& args);        // the localized formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, const CStringW&)
class Unk_OptionFactory
{
public:
    MS2Ptr<CItemOption> FUN_1405f4ff0(MS2Ptr<CItemData> spData, int nRank, Unk_Random& kRandom);
};
Unk_OptionFactory* FUN_140166430();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData);
CStringW FUN_140630ea0(int nSaType, unsigned short nValue, CItemData* pData);
__int64 FUN_140632990(__int64 nValue, float fRate);
void FUN_1406334d0(CStringW& str);

// @0x14062fa00
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CItemStatus::CItemStatus(unsigned nItemId, unsigned nRarity, unsigned nArg)
{
    m_spOption.AssignRaw(new CItemOption(nItemId));
    m_spEnchant.AssignRaw(new CItemEnchantInfo(nItemId, nRarity));
    m_spUnlimited.AssignRaw(new UnlimitedEnchantInfo(nItemId, nRarity));
}

// @0x140631ce0
CItemStatus::CItemStatus(CItemOption* pOption, CItemEnchantInfo* pEnchant, UnlimitedEnchantInfo* pUnlimited)
    : m_spOption(pOption), m_spEnchant(pEnchant), m_spUnlimited(pUnlimited)
{
}

// @0x140633280
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CItemStatus::~CItemStatus()
{
}

// @0x14062fbc0
MS2Ptr<CItemStatus> CItemStatus::FUN_14062fbc0()
{
    return MS2Ptr<CItemStatus>(new CItemStatus(m_spOption->FUN_1405caf90(), m_spEnchant->FUN_14058c3b0(), m_spUnlimited->FUN_1408bba60()));
}
MS2_REPLACE_METHOD(0x14062FBC0, CItemStatus, FUN_14062fbc0, 473, 0x2DCD2F3E);

// @0x14062fda0
void CItemStatus::FUN_14062fda0(COutputStream& out)
{
    m_spOption->FUN_1405cbeb0(out);
    m_spEnchant->FUN_14058c9c0(reinterpret_cast<Unk_EnchantWrite&>(out));
    m_spUnlimited->FUN_1408bbd30(out);
}
MS2_REPLACE_METHOD(0x14062FDA0, CItemStatus, FUN_14062fda0, 109, 0x4F2E960D);

// @0x14062fe20
void CItemStatus::FUN_14062fe20(CInputStream& in)
{
    m_spOption->FUN_1405cc190(in);
    m_spEnchant->FUN_14058cb20(reinterpret_cast<Unk_EnchantRead&>(in));
    m_spUnlimited->FUN_1408bbef0(in);
}
MS2_REPLACE_METHOD(0x14062FE20, CItemStatus, FUN_14062fe20, 109, 0xBA262CEC);

// @0x14062fea0
int CItemStatus::FUN_14062fea0(unsigned nType)
{
    int nValue = m_spOption->FUN_1405cb3a0(nType);
    if (FUN_140630dc0(nType))
    {
        int nEnchant = FUN_14062ffb0(nType, 1, 5);
        int nExtra = nEnchant + FUN_14062ffb0(nType, 2, 5);
        if (nType == 0x14)
            nExtra = (int)((float)nExtra * 0.159f);
        nValue += nExtra;
    }
    return nValue;
}
MS2_REPLACE_METHOD(0x14062FEA0, CItemStatus, FUN_14062fea0, 189, 0x47444B3B);

// @0x14062ff70
void CItemStatus::FUN_14062ff70(unsigned nType)
{
    m_spOption->FUN_1405cb440(nType);
}
MS2_REPLACE_METHOD(0x14062FF70, CItemStatus, FUN_14062ff70, 47, 0x04A83391);

// @0x14062ffb0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
int CItemStatus::FUN_14062ffb0(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult = m_spOption->FUN_1405cb3a0(nType);
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb760(nSub, nType);
            if (spBase.get() != 0)
                nResult = spBase->FUN_140266e30();
        }
    }
    if (nWhich == 3 || nWhich == 1)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spEnchant->FUN_14058cde0(nType);
        if (spBase.get() != 0)
        {
            if (!FUN_140630dc0(nType))
            {
                nResult += spBase->FUN_140266e30();
            }
            else
            {
                __int64 nBase = FUN_14062ffb0(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += (int)nScaled;
            }
        }
    }
    if (nWhich == 3 || nWhich == 2)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spUnlimited->FUN_1408bc210(nType);
        if (spBase.get() != 0)
        {
            if (!FUN_140630dc0(nType))
            {
                nResult += spBase->FUN_140266e30();
            }
            else
            {
                __int64 nBase = FUN_14062ffb0(nType, 0, 0);
                __int64 nScaled = FUN_140632990(nBase, spBase->FUN_140266e10());
                nResult += (int)nScaled;
            }
        }
    }
    return nResult;
}

// @0x140630290
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
int CItemStatus::FUN_140630290(unsigned nType, int nWhich, int nSub)
{
    int nResult = 0;
    if (nWhich == 3 || nWhich == 0)
    {
        if (nSub == 5)
        {
            nResult = m_spOption->FUN_1405cb440(nType);
        }
        else
        {
            Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb800(nSub, nType);
            if (spBase.get() != 0)
                nResult = spBase->FUN_140266e30();
        }
    }
    if ((nWhich == 3 || nWhich == 2) && nSub == 5)
    {
        Unk_EnchantPtr<BaseOption> spBase = m_spUnlimited->FUN_1408bc2f0(nType);
        if (spBase.get() != 0)
            nResult += spBase->FUN_140266e30();
    }
    return nResult;
}

// @0x1406303e0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
float CItemStatus::FUN_1406303e0(unsigned nType)
{
    Unk_EnchantPtr<BaseOption> spBase = m_spEnchant->FUN_14058cde0(nType);
    if (spBase == 0)
    {
        if (FUN_140630dc0(nType))
            return spBase->FUN_140266e10();
    }
    return 0;
}

// @0x1406304b0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
bool CItemStatus::FUN_1406304b0(int nSub, int nWhich, unsigned nType)
{
    if (nSub != 5)
    {
        if (nWhich == 0)
        {
            BaseOption* pBase = m_spOption->FUN_1405cb760(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
        else if (nWhich == 1)
        {
            BaseOption* pBase = m_spOption->FUN_1405cb800(nSub, nType).get();
            if (pBase != 0)
                return true;
        }
    }
    return false;
}

// @0x1406305e0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW CItemStatus::FUN_1406305e0(int nSub, unsigned nType, void* pData)
{
    CStringW str;
    Unk_EnchantPtr<BaseOption> spBase = m_spOption->FUN_1405cb800(nSub, nType);
    if (spBase.get() != 0)
    {
        int nValue = spBase->FUN_140266e30();
        str = FUN_140631830(nType, nValue, reinterpret_cast<CItemData*>(pData));
    }
    return str;
}

// @0x1406306f0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
void CItemStatus::FUN_1406306f0(int nItemId, int nRank, int nSeed)
{
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData.get() == 0)
        return;
    Unk_Random kRandom(nSeed);
    m_spOption = FUN_140166430()->FUN_1405f4ff0(spData, nRank, kRandom);
}

// @0x140630810
bool CItemStatus::FUN_140630810()
{
    return m_spOption->FUN_1405cc410();
}
MS2_REPLACE_METHOD(0x140630810, CItemStatus, FUN_140630810, 39, 0xEC3C6A18);

// @0x140630840
void CItemStatus::FUN_140630840()
{
    if (FUN_140630810())
    {
        m_spOption->FUN_1405cb190(4);
        m_spOption->FUN_1405cb360(0);
    }
}
MS2_REPLACE_METHOD(0x140630840, CItemStatus, FUN_140630840, 88, 0x4E3181F8);

// @0x140630d00
unsigned short CItemStatus::FUN_140630d00()
{
    return m_spEnchant->FUN_14058c5f0();
}
MS2_REPLACE_METHOD(0x140630D00, CItemStatus, FUN_140630d00, 39, 0x3E09AE77);

// @0x140630d30
CItemOption* CItemStatus::FUN_140630d30()
{
    return m_spOption;
}
MS2_REPLACE_METHOD(0x140630D30, CItemStatus, FUN_140630d30, 31, 0xF8C26528);

// @0x140630d60
CItemEnchantInfo* CItemStatus::FUN_140630d60()
{
    return m_spEnchant;
}
MS2_REPLACE_METHOD(0x140630D60, CItemStatus, FUN_140630d60, 31, 0xA4FF07D8);

// @0x140630d90
Unk_ItemPlusInfo* CItemStatus::FUN_140630d90()
{
    return reinterpret_cast<Unk_ItemPlusInfo*>(static_cast<UnlimitedEnchantInfo*>(m_spUnlimited));
}
MS2_REPLACE_METHOD(0x140630D90, CItemStatus, FUN_140630d90, 31, 0x7F01B568);

// @0x140630dc0
bool CItemStatus::FUN_140630dc0(int nType)
{
    return nType == 0x1b || nType == 0x1c || nType == 0x14;
}
MS2_REPLACE_METHOD(0x140630DC0, CItemStatus, FUN_140630dc0, 59, 0x69FAA13A);

// @0x140630e10
CStringW FUN_140630e10(int nSaType)
{
    CStringW str;
    str = FUN_140184750(&DAT_143ab1a40, nSaType)->m_strName;
    return str;
}
MS2_REPLACE(0x140630E10, FUN_140630e10, 128, 0x6BB2121D);

// @0x140630ea0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140630ea0(int nSaType, unsigned short nValue, CItemData* pData)
{
    CStringW strResult;
    Unk_Actor* pActor = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pActor != 0)
    {
        if (FUN_14081d9e0(nSaType) != 0)
        {
            ATL::CAtlArray<int> aJobs;
            FUN_140222be0(aJobs);
            for (unsigned i = 0; i < aJobs.GetCount(); i++)
            {
                int nJob = aJobs[i];
                bool bMyJob = FUN_141654700(pActor) == nJob;
                if (pData == 0 || pData->FUN_14053c8e0(nJob) != 0)
                {
                    ATL::CAtlArray<unsigned> aSa;
                    FUN_14080c370(FUN_14081da20(nSaType), nJob, aSa);
                    if (!FUN_140187930(aSa))
                    {
                        int nJobName = FUN_140644bb0(FUN_1401d7a50(), nJob);
                        CStringW strJob = FUN_1401a9d70()->FUN_141811980(6, nJobName);
                        CStringW strList;
                        for (unsigned k = 0; k < FUN_140186270(aSa); k++)
                        {
                            unsigned* pSa = FUN_140184510(aSa, k);
                            strList.Append(StringFormat(L", {0}", FUN_1401a9d70()->FUN_141811980(4, *pSa)));
                        }
                        FUN_1406334d0(strList);
                        if (strResult.IsEmpty())
                            strResult.Append(FUN_140630e10(nSaType));
                        CStringW strLine;
                        if (!strResult.IsEmpty())
                            strLine.Append(L"\n   -");
                        unsigned short nTier = nValue;
                        strLine.Append(FUN_14028dfa0(CStringW(L"s_item_opt_sa_skill_levelup_tier_v"), strJob, strList, nTier));
                        if (bMyJob)
                            strLine = FUN_1405c2690(CStringW(L"s_item_opt_sa_skill_levelup_tier_v_active"), strLine);
                        strResult.Append(strLine);
                    }
                }
            }
        }
    }
    return strResult;
}

// @0x1406313f0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_1406313f0(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (!FUN_14082f250(nStat))
        str = FormatStringId(0x48b, FUN_14082f000(nStat), FUN_1409e0900(pBase->FUN_140266e30()));
    else
        str = FormatStringId(0x48b, FUN_14082f000(nStat), FUN_1409e0a90(pBase->FUN_140266e10()));
    return str;
}

// @0x140631600
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140631600(int nStat, BaseOption* pBase)
{
    CStringW str;
    if (!FUN_14082f250(nStat))
        str = FUN_1409e0970(nStat, pBase->FUN_140266e30());
    else
        str = FUN_1409e0bf0(nStat, pBase->FUN_140266e30());
    return str;
}

// @0x140631720
CStringW FUN_140631720(int nStat, int nValue, bool bPercent)
{
    CStringW str;
    if (bPercent)
        str = FUN_1409e0bf0(nStat, nValue);
    else
        str = FUN_1409e0970(nStat, nValue);
    return str;
}
MS2_REPLACE(0x140631720, FUN_140631720, 256, 0x7787FE96);

// @0x140631830
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140631830(int nStat, int nValue, CItemData* pData)
{
    CStringW str;
    if (!FUN_14081dcd0(nStat))
    {
        if (FUN_14081d9e0(nStat) != 0)
            return FUN_140630ea0(nStat, nValue, pData);
        str = StringFormat(FUN_140184750(&DAT_143ab1a40, nStat)->m_strFormat, nValue);
    }
    else
    {
        float fValue = (float)nValue / 10.0f;
        str = StringFormat(FUN_140184750(&DAT_143ab1a40, nStat)->m_strFormat, fValue);
    }
    return str;
}

// @0x1406319f0
CStringW FUN_1406319f0(int nBuffId, unsigned short nLevel)
{
    CStringW str;
    str = FUN_1401a9d70()->FUN_141812290(nBuffId, nLevel, CString("name"));
    return str;
}
MS2_REPLACE(0x1406319F0, FUN_1406319f0, 240, 0xFB0E0A77);

// @0x140631af0
// MS2-FUNCTIONAL: not byte-identical yet (temp/frame layout differs from the exe)
CStringW FUN_140631af0(int nStat, Unk_EnchantPtr<BaseOption> spBase, CItemStatus* pStatus)
{
    CStringW strResult;
    if (spBase->FUN_140266ce0())
    {
        __int64 nBase = pStatus->FUN_14062ffb0(nStat, 0, 0);
        float fBase = (float)nBase;
        unsigned __int64 nExtra = (unsigned __int64)(fBase * spBase->FUN_140266e10());
        CStringW strUnused;
        if (nExtra == 0)
            strResult = FormatStringId(0x48c, FUN_14082f000(nStat));
        else
            strResult = FUN_1409e0970(nStat, (int)nExtra);
    }
    return strResult;
}

// @0x1406334d0
void FUN_1406334d0(CStringW& str)
{
    if (str.IsEmpty())
        return;
    if (str[0] == L',')
        str = str.Mid(1);
    if (str.IsEmpty())
        return;
    if (str[str.GetLength() - 1] == L',')
        str = str.Mid(0, str.GetLength() - 1);
}
MS2_REPLACE(0x1406334D0, FUN_1406334d0, 264, 0x8473584E);

// @0x140632990
__int64 FUN_140632990(__int64 nValue, float fRate)
{
    return (__int64)((double)nValue * (double)fRate + 0.5);
}
MS2_REPLACE(0x140632990, FUN_140632990, 42, 0xC9ADCF11);

// @0x1406346a0
void CItemTransfer::CItemBinding::FUN_1406346a0(COutputStream& out)
{
    out.vfunc_o10_4(m_n18);
    out.vfunc_o10_8(m_str20);
}

// @0x140634700
void CItemTransfer::CItemBinding::FUN_140634700(CInputStream& in)
{
    m_n18 = in.vfunc_o8_4();
    m_str20 = in.vfunc_o8_8();
}

// @0x140634790
bool CItemTransfer::CItemBinding::FUN_140634790(void* pId)
{
    return reinterpret_cast<void*>(m_n18) == pId;
}

// @0x1406347d0
bool CItemTransfer::CItemBinding::FUN_1406347d0(const __int64& nId, const CStringW& strName)
{
    m_n18 = nId;
    m_str20 = strName;
    return true;
}

// @0x140635c90
CItemTransfer::CItemBinding& CItemTransfer::CItemBinding::operator=(const CItemBinding& o)
{
    CPtred::operator=(o);
    m_n18 = o.m_n18;
    m_str20 = o.m_str20;
    return *this;
}

// @0x140634820
CItemTransfer::CItemTransfer()
    : m_pItem(0), m_nRule(0), m_n24(0), m_nType(0), m_b2C(0), m_nCount(0), m_nMax(0), m_b38(0), m_b39(0), m_b3A(0),
      m_b3B(0), m_b3C(0), m_b3D(0), m_b3E(0), m_b3F(0), m_b40(0), m_b41(0), m_b42(0)
{
}

// @0x140634930
CItemTransfer::~CItemTransfer()
{
}

// @0x140634970
void CItemTransfer::FUN_140634970(CItem* pItem)
{
    m_pItem = pItem;
}
MS2_REPLACE_METHOD(0x140634970, CItemTransfer, FUN_140634970, 25, 0xAB8BF0FB);

// @0x140634990
// MS2-FUNCTIONAL: MS2Ptr temp and extra local layout differ from the exe
void CItemTransfer::FUN_140634990(CItem* pItem)
{
    m_pItem = pItem;
    if (m_pItem != 0)
    {
        CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
        if (pData != 0)
        {
            m_nType = pData->limit.transferType;
            m_b39 = (unsigned char)pData->limit.shopSell;
            if (pData->limit.enableBreak == 0)
                m_b3E = 1;
            m_b3A = pData->FUN_14053db80() ? true : false;
            m_nCount = pData->FUN_14053d800() ? 1 : 0;
            int nId = pItem->FUN_140526bd0();
            m_b41 = FUN_14052d200()->FUN_14062d980(MS2Ptr<CItemData>(reinterpret_cast<CItemData*>(pItem->FUN_140527840())), nId);
            m_b42 = m_b41;
            FUN_140635a60();
        }
    }
}

// @0x140634b30
// MS2-FUNCTIONAL: clone temp layout differs from the exe
MS2Ptr<CItemTransfer> CItemTransfer::FUN_140634b30()
{
    MS2Ptr<CItemTransfer> spNew(new CItemTransfer);
    *spNew = *this;
    if (m_spBinding.get() != 0)
    {
        MS2Ptr<CItemBinding> spBinding(new CItemBinding);
        *spBinding = *m_spBinding;
        (*spNew).m_spBinding = spBinding;
    }
    return spNew;
}

// @0x140634cc0
int CItemTransfer::FUN_140634cc0()
{
    if (m_pItem == 0)
        return 0;
    if (m_pItem->FUN_140527030() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140634CC0, CItemTransfer, FUN_140634cc0, 57, 0xF1D55D66);

// @0x140634d00
// MS2-FUNCTIONAL: stack frame differs (flag temp)
void CItemTransfer::vfunc_1(COutputStream& out)
{
    out.vfunc_o10_3(m_nRule);
    out.vfunc_o10_0(m_b38);
    out.vfunc_o10_3(m_nCount);
    out.vfunc_o10_3(m_nMax);
    out.vfunc_o10_1(m_b3F);
    out.vfunc_o10_1(m_b42);
    if (m_spBinding.get() == 0 || FUN_140635100() == 0)
    {
        out.vfunc_o10_0(false);
    }
    else
    {
        out.vfunc_o10_0(true);
        m_spBinding->FUN_1406346a0(out);
    }
}

// @0x140634e30
// MS2-FUNCTIONAL: CInputStream::vfunc_o8_1 is declared unsigned char (stream.h); the exe tests the byte without widening
void CItemTransfer::vfunc_2(CInputStream& in)
{
    m_nRule = in.vfunc_o8_3();
    m_b38 = in.vfunc_o8_0();
    m_nCount = in.vfunc_o8_3();
    m_nMax = in.vfunc_o8_3();
    m_b3F = in.vfunc_o8_1() != 0;
    m_b42 = in.vfunc_o8_1() != 0;
    if (in.vfunc_o8_0())
    {
        m_spBinding.AssignRaw(new CItemBinding);
        m_spBinding->FUN_140634700(in);
    }
}

// @0x140634fa0
int CItemTransfer::FUN_140634fa0()
{
    return m_nCount;
}

// @0x140634fc0
void CItemTransfer::FUN_140634fc0(unsigned n)
{
    m_nCount = n;
}
MS2_REPLACE_METHOD(0x140634FC0, CItemTransfer, FUN_140634fc0, 22, 0x16BC4503);

// @0x140634fe0
int CItemTransfer::FUN_140634fe0()
{
    return m_nMax;
}

// @0x140635000
void CItemTransfer::FUN_140635000(unsigned n)
{
    m_nMax = n;
}
MS2_REPLACE_METHOD(0x140635000, CItemTransfer, FUN_140635000, 22, 0xFEAFFEDF);

// @0x140635020
int CItemTransfer::FUN_140635020()
{
    if ((m_nRule & 0x10) != 0 && m_nCount > 0)
    {
        --m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635020, CItemTransfer, FUN_140635020, 59, 0x48337623);

// @0x140635070
int CItemTransfer::FUN_140635070()
{
    if (m_pItem == 0)
        return 0;
    if ((m_nRule & 0x10) != 0)
    {
        if (m_nCount > 0)
            return 0;
        if (m_nMax >= (int)m_pItem->FUN_1405274e0())
            return 0;
        ++m_nMax;
        ++m_nCount;
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140635070, CItemTransfer, FUN_140635070, 133, 0x995E53BE);

// @0x140635100
unsigned CItemTransfer::FUN_140635100()
{
    return m_nRule & 8;
}
MS2_REPLACE_METHOD(0x140635100, CItemTransfer, FUN_140635100, 17, 0xB9EB22D4);

// @0x140635120
int CItemTransfer::FUN_140635120()
{
    return m_spBinding.get() != 0 ? 1 : 0;
}
MS2_REPLACE_METHOD(0x140635120, CItemTransfer, FUN_140635120, 58, 0x06ED1646);

// @0x140635160
CItemTransfer::CItemBinding* CItemTransfer::FUN_140635160()
{
    return m_spBinding.get();
}
MS2_REPLACE_METHOD(0x140635160, CItemTransfer, FUN_140635160, 31, 0x379A5C2F);

// @0x140635190
int CItemTransfer::FUN_140635190()
{
    return m_nType;
}
MS2_REPLACE_METHOD(0x140635190, CItemTransfer, FUN_140635190, 14, 0xD26D6807);

// @0x1406351b0
bool CItemTransfer::FUN_1406351b0()
{
    switch (m_nType)
    {
    case 3:
    case 4:
        return true;
    default:
        return false;
    }
}
MS2_REPLACE_METHOD(0x1406351B0, CItemTransfer, FUN_1406351b0, 45, 0x9C2A80F2);

// @0x1406351f0
unsigned char CItemTransfer::FUN_1406351f0(void* pId, void* pName)
{
    m_spBinding.AssignRaw(new CItemBinding);
    if (m_spBinding.get() != 0)
        return m_spBinding->FUN_1406347d0(*static_cast<const __int64*>(pId), *static_cast<const CStringW*>(pName));
    return 0;
}
MS2_REPLACE_METHOD(0x1406351F0, CItemTransfer, FUN_1406351f0, 175, 0x3EF4D3CA);

// @0x1406352b0
unsigned char CItemTransfer::FUN_1406352b0()
{
    m_pItem->vfunc_5(true);
    m_spBinding = 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1406352B0, CItemTransfer, FUN_1406352b0, 61, 0x61774D6B);

// @0x140635300
void CItemTransfer::FUN_140635300()
{
    m_b3F = 1;
}
MS2_REPLACE_METHOD(0x140635300, CItemTransfer, FUN_140635300, 15, 0x03EFC008);

// @0x140635320
void CItemTransfer::FUN_140635320(bool b)
{
    m_b40 = 1;
    m_b42 = b;
}
MS2_REPLACE_METHOD(0x140635320, CItemTransfer, FUN_140635320, 32, 0xB7D9EF8D);

// @0x140635470
bool CItemTransfer::FUN_140635470(const __int64* pId)
{
    if (m_spBinding.get() != 0)
    {
        if (!m_spBinding->FUN_140634790(reinterpret_cast<void*>(*pId)))
            return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140635470, CItemTransfer, FUN_140635470, 87, 0x4FDB0514);

// @0x140635420
bool FUN_140635420(CItemTransfer* pTransfer, PCBase* pPc)
{
    if (pPc != 0)
    {
        __int64 nId = pPc->FUN_141656a80();
        return pTransfer->FUN_140635470(&nId);
    }
    return true;
}

// @0x1406354d0
int CItemTransfer::FUN_1406354d0()
{
    if (m_pItem == 0)
        return false;
    if (m_b39 == 0)
        return false;
    if (FUN_140635870() == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406354D0, CItemTransfer, FUN_1406354d0, 70, 0x2CA2E2B6);

// @0x140635520
unsigned CItemTransfer::FUN_140635520()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    return m_nRule & 4;
}
MS2_REPLACE_METHOD(0x140635520, CItemTransfer, FUN_140635520, 79, 0x47E3BE8B);

// @0x140635580
int CItemTransfer::FUN_140635580()
{
    return 0;
}
MS2_REPLACE_METHOD(0x140635580, CItemTransfer, FUN_140635580, 8, 0x7F371472);

// @0x140635590
unsigned CItemTransfer::FUN_140635590()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    unsigned nResult = 0;
    if ((m_nRule & 0x10) != 0)
        nResult = 0 < m_nCount ? 1 : 0;
    if (nResult == 0)
        nResult = m_nRule & 4;
    return nResult;
}
MS2_REPLACE_METHOD(0x140635590, CItemTransfer, FUN_140635590, 154, 0xE947292A);

// @0x140635630
int CItemTransfer::FUN_140635630()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if ((m_nRule & 0x10) == 0)
        return 0;
    if (m_nCount == 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140635630, CItemTransfer, FUN_140635630, 89, 0xAC2D2E1A);

// @0x140635690
unsigned CItemTransfer::FUN_140635690()
{
    if (FUN_140635120() != 0)
        return 0;
    if (FUN_140634cc0() == 0)
        return 0;
    if (m_pItem == 0)
        return 0;
    if (m_pItem->FUN_140525790())
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    unsigned nResult = 0;
    if ((m_nRule & 0x10) != 0)
        nResult = 0 < m_nCount ? 1 : 0;
    if (nResult == 0)
        nResult = m_nRule & 4;
    return nResult;
}
MS2_REPLACE_METHOD(0x140635690, CItemTransfer, FUN_140635690, 204, 0x23D70D12);

// @0x140635770
int CItemTransfer::FUN_140635770()
{
    if (m_pItem == 0)
        return 0;
    if (m_b3F != 0)
        return 0;
    if (m_b3E != 0)
        return 0;
    if (m_pItem->FUN_140525ca0() != 0)
        return 0;
    if (FUN_140635870() == 0)
        return 0;
    if (m_pItem->FUN_1405258b0() != 0)
    {
        if (!FUN_14036d570(FUN_140166410(), 0x3a))
            return 0;
        if (m_pItem->FUN_140525f10() != 0 && m_pItem->FUN_1405279c0() != 0)
        {
            if (FUN_140620a20(m_pItem->FUN_1405279c0()) == 0)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140635770, CItemTransfer, FUN_140635770, 235, 0xAE1E60FC);

// @0x140635870
int CItemTransfer::FUN_140635870()
{
    if (m_pItem == 0)
        return false;
    if (m_pItem->FUN_140528e20() == true)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140635870, CItemTransfer, FUN_140635870, 61, 0xD0B35AF7);

// @0x1406358c0
int CItemTransfer::FUN_1406358c0()
{
    if (FUN_140634cc0() == 0)
        return false;
    if (m_b3A == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x1406358C0, CItemTransfer, FUN_1406358c0, 54, 0x431A3034);

// @0x140635900
int CItemTransfer::FUN_140635900()
{
    if (m_b42 == 0)
        return false;
    if (m_b41 == 0)
        return false;
    return true;
}
MS2_REPLACE_METHOD(0x140635900, CItemTransfer, FUN_140635900, 45, 0xF1A2447C);

// @0x140635940
bool CItemTransfer::FUN_140635940()
{
    return FUN_140635120() == 1;
}
MS2_REPLACE_METHOD(0x140635940, CItemTransfer, FUN_140635940, 52, 0xE032FB84);

// @0x140635980
bool CItemTransfer::FUN_140635980(const __int64* pId)
{
    if (FUN_140635470(pId))
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140635980, CItemTransfer, FUN_140635980, 47, 0xDBE87C5F);

// @0x1406359c0
void CItemTransfer::FUN_1406359c0(__int64* pId, CStringW* pName)
{
    if (m_spBinding.get() != 0)
    {
        *pId = m_spBinding->FUN_14052d1c0();
        *pName = m_spBinding->FUN_14052d1b0();
    }
    else
    {
        *pId = 0;
        pName->Empty();
    }
}
MS2_REPLACE_METHOD(0x1406359C0, CItemTransfer, FUN_1406359c0, 143, 0x27AF4741);

// @0x140635a60
void CItemTransfer::FUN_140635a60()
{
    if (m_pItem == 0)
        return;
    if (m_pItem->FUN_140527840() == 0)
        return;
    CItemData* pData = reinterpret_cast<CItemData*>(m_pItem->FUN_140527840());
    m_nRule = FUN_140635ae0(m_nType, pData, m_pItem->FUN_140526bd0());
}
MS2_REPLACE_METHOD(0x140635A60, CItemTransfer, FUN_140635a60, 111, 0xE6CA5D84);

// @0x140635ae0
unsigned CItemTransfer::FUN_140635ae0(int nType, CItemData* pData, int nId)
{
    if (pData == 0)
        return 0;
    unsigned nRule = 0;
    switch (nType)
    {
    case 0:
        nRule = 4;
        break;
    case 1:
        nRule = 0;
        break;
    case 5:
        nRule = 0x10;
        break;
    case 2:
        nRule = 8;
        break;
    case 4:
        nRule = 8;
        break;
    case 3:
        nRule = 0x18;
    }
    return nRule;
}

// @0x140635b90
bool FUN_140635b90(unsigned a, unsigned b)
{
    return (a & b) == b;
}

// @0x140635cf0
CItemTransfer& CItemTransfer::operator=(const CItemTransfer& o)
{
    CPtred::operator=(o);
    m_pItem = o.m_pItem;
    m_nRule = o.m_nRule;
    m_n24 = o.m_n24;
    m_nType = o.m_nType;
    m_b2C = o.m_b2C;
    m_nCount = o.m_nCount;
    m_nMax = o.m_nMax;
    m_b38 = o.m_b38;
    m_b39 = o.m_b39;
    m_b3A = o.m_b3A;
    m_b3B = o.m_b3B;
    m_b3C = o.m_b3C;
    m_b3D = o.m_b3D;
    m_b3E = o.m_b3E;
    m_b3F = o.m_b3F;
    m_b40 = o.m_b40;
    m_b41 = o.m_b41;
    m_b42 = o.m_b42;
    m_spBinding = o.m_spBinding;
    return *this;
}

template class MS2Ptr<CItemTransfer>;
