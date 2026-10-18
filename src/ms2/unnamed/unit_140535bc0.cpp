// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CostumeSet / CostumeSetTable: Table/CostumeSet.xml, the
// costume sets (by set id and gender) with their slot items and transparency slots.
// MS2-UNIT: unit_140535bc0
// MS2-RANGE: 0x1400b9690-0x1400b97a0 .text$di
// MS2-RANGE: 0x140535bc0-0x140539370 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_mapSlotType@@YAXXZ 0x1400b9690 ; unique
// MS2-PIN: ?Read@?$Value@H@Constants@Common@@QEAAHXZ 0x140536a30 ; unique
// MS2-PIN: ??0?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@IMMMI@Z 0x140536be0 ; unique
// MS2-PIN: ??1?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA@XZ 0x140536f00 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x1405373f0 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140537430 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@@Z 0x140537550 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x140537690 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEBAIXZ 0x140537700 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAA_NI_N@Z 0x140537a20 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBA_NXZ 0x140537b70 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEBAI_K@Z 0x1405381c0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXI@Z 0x1405384e0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXXZ 0x140538820 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140538a20 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140538bd0 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@QEAAXMMM_N@Z 0x140538e80 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@HHV?$CElementTraits@H@ATL@@V12@@ATL@@AEAAXXZ 0x140539020 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7CostumeSetTable@@6B?$TSingleton@VCostumeSetTable@@@@@ 0x142d589d0
// MS2-PIN: ??_7CostumeSetTable@@6B?$CValidData@VCostumeSetTable@@@@@ 0x142d589e0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/costumesettable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Header statics of this unit: the slot-type -> Transparency constant map (filled by the first CostumeSetTable),
// constructed before the sort names.
static ATL::CAtlMap<int, int> s_mapSlotType(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* psz, int n);                           // undecorated class name
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);   // split into strings
int FUN_1405451c0(const CString& str);                                   // text -> number
CString FUN_1405451e0(unsigned n);                                       // number -> text
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
extern unsigned FUN_14054b400(ItemModelData*);
unsigned char FUN_1401d1320(CCacheData*);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
CostumeSetTable* TSingleton<CostumeSetTable>::s_instance;
bool CostumeSetTable::s_bInit;
#endif

// @0x140535bc0
CostumeSet::CostumeSet()
    : m_nSetId(0)
{
}

// @0x140535c80
CostumeSet::~CostumeSet()
{
}

// @0x140535cd0
CostumeSetTable::CostumeSetTable()
{
    if (s_mapSlotType.GetCount() == 0)
    {
        s_mapSlotType.SetAt(6, FUN_1401d3200()->TransparencyCP.Read());
        s_mapSlotType.SetAt(0xd, FUN_1401d3200()->TransparencyEY.Read());
        s_mapSlotType.SetAt(8, FUN_1401d3200()->TransparencyCL.Read());
        s_mapSlotType.SetAt(9, FUN_1401d3200()->TransparencyPA.Read());
        s_mapSlotType.SetAt(7, FUN_1401d3200()->TransparencyMT.Read());
        s_mapSlotType.SetAt(0xe, FUN_1401d3200()->TransparencyEA.Read());
        s_mapSlotType.SetAt(0xc, FUN_1401d3200()->TransparencyFH.Read());
        s_mapSlotType.SetAt(10, FUN_1401d3200()->TransparencyGL.Read());
        s_mapSlotType.SetAt(0x10, FUN_1401d3200()->TransparencyRI.Read());
        s_mapSlotType.SetAt(0xb, FUN_1401d3200()->TransparencySH.Read());
    }
    Load();
}

// @0x140535f80
CostumeSetTable::~CostumeSetTable()
{
}

// @0x140536030
int CostumeSetTable::Load()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (LoadXml() == 0)
            return 0;
    }
    SetInit(true);
    return 1;
}

// @0x1405360b0
CostumeSetPtr CostumeSetTable::GetSet(unsigned nSetId, int nGender)
{
    if (nGender < 0 && 2 < nGender)
        return CostumeSetPtr(0);
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
        return CostumeSetPtr(0);
    }
    if (FUN_1401d1320(m_cache.get()) != 0)
        Load();
    CostumeSetPtr spSet(0);
    m_sets[nGender].Lookup(nSetId, spSet);
    return spSet;
}

// @0x1405361e0
int CostumeSetTable::LoadXml()
{
    for (unsigned i = 0; i < 2; i++)
        m_sets[i].RemoveAll();
    CString strPath = FUN_14071a5b0(CString("Table"), CString("CostumeSet.xml"));
    m_cache.AssignRaw(new CCacheData);
    m_cache.get()->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pSet = pRoot->FUN_140165cf0("costumeSet"); pSet != 0; pSet = pSet->FUN_140168650("costumeSet"))
    {
        if (!FUN_14028f710(pSet))
            continue;
        unsigned nSetId = 0;
        FUN_140873220(pSet, "id", nSetId);
        for (Unk_140165cf0* pNode = pSet->FUN_140165cf0("set"); pNode != 0; pNode = pNode->FUN_140168650("set"))
        {
            CostumeSetPtr spSet(new CostumeSet);
            spSet->m_nSetId = nSetId;
            int nGender = 0;
            FUN_1408731e0(pNode, "gender", nGender);
            if (nGender < 0 && 2 < nGender)
                continue;
            CString strSlots;
            ATL::CAtlArray<CString> arrSlots;
            FUN_1408733e0(pNode, "transparencySlots", strSlots);
            FUN_14015f050(strSlots, arrSlots, ",");
            for (unsigned i = 0; i < arrSlots.GetCount(); i++)
            {
                int nSlot = FUN_1405451c0(arrSlots[i]);
                if (nSlot != 0)
                {
                    int nValue = 0;
                    if (s_mapSlotType.Lookup(nSlot, nValue))
                        spSet->m_mapTransparency.SetAt(nSlot, nValue);
                }
            }
            for (unsigned nIndex = 0; nIndex < 0x14; nIndex++)
            {
                unsigned nKey = nIndex;
                if (spSet->m_mapTransparency.Lookup(nKey) == 0)
                {
                    CString strNumber = FUN_1405451e0(nKey);
                    CString strAttr = Unk_SocketFormat("slot_{0}", strNumber);
                    unsigned nItemId = 0;
                    FUN_140873220(pNode, strAttr, nItemId);
                    if (nItemId != 0)
                    {
                        if (!FUN_1406af060(FUN_1406aeee0()))
                        {
                            MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
                            if (item == 0)
                            {
                                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
                                return 0;
                            }
                            if (FUN_14054b400(item->FUN_14053eba0()) != nKey)
                            {
                                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
                                return 0;
                            }
                        }
                        spSet->m_mapSlotItems.SetAt(nKey, nItemId);
                    }
                }
            }
            m_sets[nGender].SetAt(spSet->m_nSetId, spSet);
        }
    }
    return 1;
}

// @0x1405371d0
void CostumeSetTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CostumeSetTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
