// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The item socket tables (Table/itemSocket.xml), see
// itemsocketsystemutil.h. The unit also holds CItemStatus / CItemUgc / CItemTransfer and the template glue of its
// containers (not recovered yet).
// MS2-UNIT: ?\itemsocketsystemutil.cpp
// MS2-RANGE: 0x1400baa10-0x1400bae70 .text$di
// MS2-RANGE: 0x140626a20-0x140635ec0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemsocketsystemutil.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "itemsocketsystemutil.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

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
char FUN_1406211f0(void* pEnhance);
char FUN_140528980(CItem* pItem);
int FUN_140525ca0(CItem* pItem);
int FUN_140525db0(CItem* pItem);
char FUN_140528e20(CItem* pItem);

// @0x140626aa0
// MS2-FUNCTIONAL: written from the decompile; not byte-compared yet
bool EnableSocketUnlockFunction::Init(MS2Ptr<CItem> pItem, int nSocketMode, int nUnlockMode)
{
    if (!(pItem == 0))
    {
        if (FUN_1405279c0(pItem.get()) != 0)
        {
            m_n18 = FUN_14053c560(FUN_140527840(pItem.get()));
            m_n1C = pItem.get()->FUN_140526bd0();
            m_n20 = pItem.get()->FUN_140526a50();
            m_n28 = FUN_140620a20(FUN_1405279c0(pItem.get()));
            m_nSocketMode = nSocketMode;
            m_nUnlockMode = nUnlockMode;
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140626AA0, EnableSocketUnlockFunction, Init, 270, 0xC2E6278E);

// @0x140626bc0
// MS2-FUNCTIONAL: written from the decompile; not byte-compared yet
bool EnableSocketUnlockFunction::Matches(MS2Ptr<CItem> pItem)
{
    if (!(pItem == 0))
    {
        if (m_n20 != (unsigned __int64)pItem.get()->FUN_140526a50())
        {
            if (m_n18 == FUN_14053c560(FUN_140527840(pItem.get())))
            {
                if (m_n1C == pItem.get()->FUN_140526bd0())
                {
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
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140626BC0, EnableSocketUnlockFunction, Matches, 599, 0x3252C071);

// @0x140626e20
// MS2-FUNCTIONAL: written from the decompile; not byte-compared yet
bool EnableSocketUnlockFunction::InitPair(MS2Ptr<CItem> pItem, MS2Ptr<CItem> pOther, int nSocketMode, int nUnlockMode)
{
    if (!Init(pItem, nSocketMode, nUnlockMode))
        return false;
    return Matches(pOther);
}

// @0x14062c7b0
CItemSocketData::CItemSocketData() : m_nGrade(0), m_nMaxCount(0), m_nOpenType(0)
{
    m_range.m_nMin = 0;
    m_range.m_nMax = 0;
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
}

// @0x14062c900
MS2Ptr<CItemSocketData> CItemSocketDataContainer::Find(int nGrade)
{
    if (m_rows.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    MS2Ptr<CItemSocketData> spDefault(0);
    for (size_t i = 0; i < m_rows.GetCount(); i++)
    {
        MS2Ptr<CItemSocketData> spRow = m_rows[i];
        if (!spRow.IsNull())
        {
            if (spRow->m_nGrade == nGrade)
                return spRow;
            if (spRow->m_nGrade == 0)
                spDefault = spRow;
        }
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
MS2Ptr<CItemSocketData> CItemSocketTable::Find(unsigned nItemId, int nGrade)
{
    if (m_items.IsEmpty())
        return MS2Ptr<CItemSocketData>(0);
    MS2Ptr<CItemSocketData> spResult(0);
    ContainerPtr spContainer(0);
    Unk_LockGuard guard(m_lock);
    if (guard == 0 && m_items.Lookup(nItemId, spContainer))
        spResult = spContainer->Find(nGrade);
    return spResult;
}

// @0x140626a20
EnableSocketUnlockFunction::EnableSocketUnlockFunction()
    : m_n18(0), m_n1C(0), m_n20(0), m_n28(0), m_nSocketMode(0), m_nUnlockMode(0)
{
}

// @0x14062c160
// MS2-PIN: ??1EnableSocketUnlockFunction@@UEAA@XZ 0x14062c160
EnableSocketUnlockFunction::~EnableSocketUnlockFunction() = default;
