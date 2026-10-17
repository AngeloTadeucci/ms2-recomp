// exptable.h - CExpTable (commonfiles\exptable.cpp, RTTI .?AVCExpTable@@, 0x2450 bytes). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13). The member names are invented where the exe has none.
//
// CExpTable is a TSingleton created by CGameApp::InitInstance. It loads the level / experience tables:
// nextExp.xml (experience to the next level), ExpBaseTable.xml + RewardContentExpStaticTable.xml (the per-id
// curves), commonExpTable.xml (the exp type -> curve id), petExp.xml and petEvolution.xml.
#pragma once

#include <atlcoll.h>
#include <atlstr.h>
#include <map>
#include <vector>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/blackmarketitemoption.h"

// A curve of values by level: the values of level 1..n and the value of level 0 (0x20 bytes).
class Unk_ExpCurve
{
public:
    Unk_ExpCurve();                                         // 0x140352350
    void SetValue(unsigned short nLevel, __int64 nValue);   // 0x140352390
    __int64 GetValue(unsigned short nLevel) const;          // 0x140352430
    void Scale(const Unk_ExpCurve& src, double fFactor);    // 0x1403524b0 values of src * factor (at least 1)
    bool IsValid() const;                                   // 0x1403525a0

    std::vector<__int64> m_values;                          // +0x00 the values of level 1..n
    __int64 m_nBase;                                        // +0x18 the value of level 0
};
MS2_CHECK_SIZE(Unk_ExpCurve, 0x20);

// The five values of one level of the experience-type table, by exp type (0x28 bytes).
struct Unk_ExpBase
{
    Unk_ExpBase()
    {
        m_n1 = 0;
        m_n3 = 0;
        m_n7 = 0;
        m_n4 = 0;
        m_n6 = 0;
    }
    __int64 m_n1;
    __int64 m_n3;
    __int64 m_n7;
    __int64 m_n4;
    __int64 m_n6;
};
MS2_CHECK_SIZE(Unk_ExpBase, 0x28);

// The pet evolution grades (4 grades and the required item level) by id.
typedef ATL::CAtlArray<unsigned> Unk_PetGradeArray;
typedef ATL::CAtlMap<unsigned, Unk_BmBoxPtr<Unk_PetGradeArray> > Unk_PetEvolutionMap;

class CExpTable : public TSingleton<CExpTable>, public CValidData<CExpTable>
{
public:
    CExpTable();                                            // 0x1403525e0
    virtual ~CExpTable();                                   // 0x1403526f0

    bool Load();                                            // 0x1403527a0 reads every table
    bool Reserved();                                        // 0x140352ab0 (always true)
    bool LoadNextExp();                                     // 0x140352840 nextExp.xml
    bool LoadReward();                                      // 0x140352ac0 ExpBaseTable.xml, RewardContentExpStaticTable.xml
    bool LoadCommonExp();                                   // 0x140352ba0 commonExpTable.xml
    bool LoadPetExp();                                      // 0x140352e90 petExp.xml
    bool LoadPetEvolution();                                // 0x1403532d0 petEvolution.xml
    bool ReadExpTable(const CString& strFile);              // 0x140353ae0

    __int64 GetNextExp(unsigned short nLevel);              // 0x140353610
    __int64 GetBaseValue(unsigned short nLevel, int nType); // 0x140353660
    __int64 GetTypeValue(unsigned short nLevel, int nType); // 0x140353720
    __int64 GetScaledValue(unsigned short nLevel, int nId, double fFactor);     // 0x1403537a0
    __int64 GetPetValue(unsigned short nLevel, int nGrade); // 0x140353840
    __int64 GetPetExp(unsigned short nLevel, int nRow, unsigned short nArg);    // 0x140353930
    int GetPetEvolution(unsigned short nId, int nGrade);    // 0x1403539d0

    // @0x140356ca0
    static void CheckInit();
    // @0x140356d90
    static void SetInit(bool bInit) { s_bInit = bInit; }

    static bool s_bInit;                                    // DAT_143aaeb08

    __int64 m_nextExp[100];                                 // +0x010 by level (1..99)
    Unk_ExpBase m_base[100];                                // +0x330 by level
    std::map<unsigned, Unk_ExpCurve> m_curves;                   // +0x12d0 by exp table id
    Unk_ExpCurve m_typeCurves[0x30];                        // +0x12e0 by exp type
    __int64 m_petExp[7][51];                                // +0x18e0
    Unk_PetEvolutionMap m_petEvolution;                     // +0x2408
};
MS2_CHECK_SIZE(CExpTable, 0x2450);
MS2_CHECK_OFFSET(CExpTable, m_nextExp, 0x10);
MS2_CHECK_OFFSET(CExpTable, m_base, 0x330);
MS2_CHECK_OFFSET(CExpTable, m_curves, 0x12d0);
MS2_CHECK_OFFSET(CExpTable, m_typeCurves, 0x12e0);
MS2_CHECK_OFFSET(CExpTable, m_petExp, 0x18e0);
MS2_CHECK_OFFSET(CExpTable, m_petEvolution, 0x2408);
