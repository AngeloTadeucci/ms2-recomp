// citemoptiontable.h - CItemOptionTable (commonfiles\itemoptiondata.cpp#3). NOT an original header: names invented
// except the RTTI ones (CItemOptionTable, CItemOptionTable::ProbabilityFromRank). The layout-only placeholder used by
// other units is ms2/placeholder/citemoptiontable.h; this is the recovered form for the unit itself.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/unk_optionnamelist.h"
#include <map>
#include <unordered_map>
#include <atlcoll.h>

class Unk_Random;
class CItemData;
class CItemOption;
class ItemOptionConstant;
class ItemOptionRandom;
class ItemOptionVariationData;

// RTTI CItemOptionTable (TSingleton at +0, CValidData at +8), 0x118 bytes: the item option xml tables.
class CItemOptionTable : public TSingleton<CItemOptionTable>, public CValidData<CItemOptionTable>
{
public:
    // The rank weights of an item level band (RTTI CItemOptionTable::ProbabilityFromRank, a CPtred, 0x30 bytes).
    class ProbabilityFromRank : public CPtred
    {
    public:
        ProbabilityFromRank(float f18, float f1c, float f20, float f24, float f28);    // 0x140604020
        virtual ~ProbabilityFromRank() {}                                               // 0x140604b70
        float m_f18;                    // +0x18
        float m_f1c;                    // +0x1c
        float m_f20;                    // +0x20
        float m_f24;                    // +0x24
        float m_f28;                    // +0x28
    };

    CItemOptionTable();                                     // 0x1405f4140
    virtual ~CItemOptionTable();                            // 0x1405f4640

    bool FUN_1405f4720();                                   // loads every table
    bool FUN_1405f5d90(int nItemId);                        // the item has constant options
    MS2Ptr<ItemOptionConstant> FUN_1405f5ee0(int nId, int nGrade);  // the best constant row up to a grade
    MS2Ptr<ItemOptionRandom> FUN_1405f6010(int nId);
    int FUN_1405f6100(int nStatId);
    int FUN_1405f6190(int nStatId, Unk_Random* pRandom);
    int FUN_1405f6230(int nStatId);
    int FUN_1405f62c0(int nStatId);
    int FUN_1405f6350(int nStatId);
    std::pair<int, int> FUN_1405f63e0(int nStatId);         // the first and last stat of a variation row
    std::pair<int, int> FUN_1405f64e0(int nItemId, int nRank, int nStat);
    std::pair<int, int> FUN_1405f6650(int nItemId, int nRank, unsigned nSpecial);
    int FUN_1405f6d40(MS2Ptr<CItemData> spItem, int nRank, unsigned nSpecial);
    Unk_OptionNameListPtr FUN_1405f6e40(const CString& strName);    // the exclusive group of a stat name (null: none)
    int FUN_1405f6ed0(int nKey);
    void FUN_1405f6f50(MS2Ptr<CItemData> spItem, int nRank, unsigned nTrials,
                       const std::vector<std::pair<int, int> >& vLocked, std::vector<CStringW>* pOut);
    bool FUN_1405f78f0();                                   // the exclusive option groups
    bool FUN_1405f8310();
    bool FUN_1405f8540();
    bool FUN_1405f8770();
    bool FUN_1405f8780();                                   // the variation rows

    static void CheckInit();                                // 0x140608280
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x140609530
    static bool s_bInit;                                    // DAT_143aafe98

    CLockCriticalSection m_lock;                                                        // +0x10
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> > m_rankProbs;            // +0x40
    std::map<std::pair<int, int>, MS2Ptr<ProbabilityFromRank> > m_rankProbs2;           // +0x50
    std::multimap<unsigned, MS2Ptr<ItemOptionConstant> > m_constants;                     // +0x60
    std::unordered_map<int, MS2Ptr<ItemOptionRandom> > m_randoms;                       // +0x70
    ATL::CAtlMap<CString, Unk_OptionNameListPtr, ATL::CStringElementTraits<CString> > m_names;  // +0xb0
    std::map<int, int> m_f8;                                                            // +0xf8
    std::map<unsigned, MS2Ptr<ItemOptionVariationData> > m_variations;                    // +0x108
};
MS2_CHECK_SIZE(CItemOptionTable, 0x118);
MS2_CHECK_OFFSET(CItemOptionTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CItemOptionTable, m_constants, 0x60);
MS2_CHECK_OFFSET(CItemOptionTable, m_randoms, 0x70);
MS2_CHECK_OFFSET(CItemOptionTable, m_names, 0xb0);
MS2_CHECK_OFFSET(CItemOptionTable, m_f8, 0xf8);
MS2_CHECK_OFFSET(CItemOptionTable, m_variations, 0x108);
