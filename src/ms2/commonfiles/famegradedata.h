// famegradedata.h - CFameTable and its row classes (RTTI names): the fame (reputation) tables read from
// Table/fame.xml, fameLog.xml, fameLimit.xml, famePickMethod.xml and fameDef.xml.
// Header name assumed from the unit path; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loaders are)

// One <fame> row of fame.xml (a grade of one alliance), 0x30 bytes.
class CFameGradeData : public CPtred
{
public:
    CFameGradeData();                   // 0x1403588d0
    virtual ~CFameGradeData();          // 0x140358940

    int Read(Unk_140165cf0* pElem);     // 0x140358970 (name invented)

    int m_nGrade;                       // +0x18 "grade"
    int m_nAlliance;                    // +0x1c "alliance" (1..9)
    int m_nRequirePoint;                // +0x20 "requirePoint"
    unsigned m_nAdditionalEffectId;     // +0x24 "additionalEffectID"
    unsigned short m_nAdditionalEffectLevel;    // +0x28 "additionalEffectLevel"
};
MS2_CHECK_SIZE(CFameGradeData, 0x30);
MS2_CHECK_OFFSET(CFameGradeData, m_nRequirePoint, 0x20);
MS2_CHECK_OFFSET(CFameGradeData, m_nAdditionalEffectLevel, 0x28);

// One row of fameLog.xml, 0x28 bytes.
class CFameLogData : public CPtred
{
public:
    CFameLogData();                     // 0x140358a40
    virtual ~CFameLogData();            // 0x140358aa0

    int Read(Unk_140165cf0* pElem);     // 0x140358ad0 (name invented)

    int m_nGrade;                       // +0x18 "grade"
    unsigned m_nId;                     // +0x1c "id"
    int m_nAlliance;                    // +0x20 "alliance" (1..9)
};
MS2_CHECK_SIZE(CFameLogData, 0x28);
MS2_CHECK_OFFSET(CFameLogData, m_nAlliance, 0x20);

// One row of fameLimit.xml, 0x68 bytes: the grade an alliance needs for something.
class CFameLimitData : public CPtred
{
public:
    CFameLimitData();                   // 0x140358b60
    virtual ~CFameLimitData();          // 0x140358bd0

    int Read(Unk_140165cf0* pElem);     // 0x140358c10 (name invented)

    int m_nAlliance;                    // +0x18 "alliance"
    ATL::CAtlMap<int, int> m_mapGrade;  // +0x20 requireAlliance -> requireGrade
};
MS2_CHECK_SIZE(CFameLimitData, 0x68);
MS2_CHECK_OFFSET(CFameLimitData, m_mapGrade, 0x20);

// A <alliance> child of a pick method, 0x20 bytes.
class CFamePickAlliance : public CPtred
{
public:
    CFamePickAlliance();                // 0x140358de0
    virtual ~CFamePickAlliance();       // 0x140358e30

    int Read(Unk_140165cf0* pElem);     // 0x140358e60 (name invented)

    int m_nAlliance;                    // +0x18 "id"
    int m_nMaxCount;                    // +0x1c "maxCount"
};
MS2_CHECK_SIZE(CFamePickAlliance, 0x20);

// One <method> of famePickMethod.xml, 0x78 bytes.
class CFamePickMethod : public CPtred
{
public:
    typedef MS2Ptr<CFamePickAlliance> AlliancePtr;

    CFamePickMethod();                  // 0x140358ee0
    virtual ~CFamePickMethod();         // 0x140358f90

    int Read(Unk_140165cf0* pElem);     // 0x140358ff0 (name invented)
    bool HasAlliance(int nAlliance);    // 0x1403591e0 (name invented)

    int m_nType;                        // +0x18 "type": 1 rankalliancecombination, 2 fixedcountperalliance
    int m_nRepeatType;                  // +0x1c "repeatType" (default 2)
    unsigned m_nReloadOnAccept;         // +0x20
    unsigned m_nReloadOnComplete;       // +0x24
    ATL::CAtlArray<int> m_aPickCountByRank;     // +0x28
    ATL::CAtlArray<AlliancePtr> m_aAlliances;   // +0x48
    std::set<int> m_setAlliance;        // +0x68
};
MS2_CHECK_SIZE(CFamePickMethod, 0x78);
MS2_CHECK_OFFSET(CFamePickMethod, m_aAlliances, 0x48);
MS2_CHECK_OFFSET(CFamePickMethod, m_setAlliance, 0x68);

// One <season> of fameDef.xml, 0x30 bytes.
class CFameSeasonDef : public CPtred
{
public:
    CFameSeasonDef();                   // 0x1403593d0
    virtual ~CFameSeasonDef();          // 0x140359420

    int Read(Unk_140165cf0* pElem);     // 0x140359460 (name invented)

    int m_nSeason;                      // +0x18 "name"
    unsigned m_nRequireQuest;           // +0x1c "requireQuest"
    unsigned short m_nRequireLv;        // +0x20 "requireLv"
    CStringA m_strLimitNpcScriptTag;    // +0x28 "limitNpcScriptTag"
};
MS2_CHECK_SIZE(CFameSeasonDef, 0x30);
MS2_CHECK_OFFSET(CFameSeasonDef, m_strLimitNpcScriptTag, 0x28);

// One <fame> of a season in fameDef.xml, 0x38 bytes.
class CFameDef : public CPtred
{
public:
    CFameDef();                         // 0x140359240
    virtual ~CFameDef();                // 0x1403592b0

    int Read(Unk_140165cf0* pElem);     // 0x1403592f0 (name invented)

    int m_nAlliance;                    // +0x18 "alliance" (1..9)
    CStringA m_strSymbol;               // +0x20 "symbol"
    int m_nOfficerNpcKind;              // +0x28 "officerNpcKind"
    int m_nIsExped;                     // +0x2c "isExped"
    int m_nSeason;                      // +0x30 "season"
};
MS2_CHECK_SIZE(CFameDef, 0x38);
MS2_CHECK_OFFSET(CFameDef, m_strSymbol, 0x20);
MS2_CHECK_OFFSET(CFameDef, m_nSeason, 0x30);

// RTTI CFameTable (TSingleton at +0, CValidData at +8), 0x390 bytes.
class CFameTable : public TSingleton<CFameTable>, public CValidData<CFameTable>
{
public:
    typedef MS2Ptr<CFameGradeData> GradePtr;
    typedef MS2Ptr<CFameLogData> LogPtr;
    typedef MS2Ptr<CFameLimitData> LimitPtr;
    typedef MS2Ptr<CFamePickMethod> PickPtr;
    typedef MS2Ptr<CFameDef> DefPtr;
    typedef MS2Ptr<CFameSeasonDef> SeasonPtr;

    CFameTable();                       // 0x140359500
    virtual ~CFameTable();              // 0x1403596e0

    int Load();                         // 0x140359840 sets the init flag, then loads the five files
    int LoadFame();                     // 0x1403598c0 fame.xml
    int LoadFameLog();                  // 0x140359bd0 fameLog.xml
    int LoadFameLimit();                // 0x140359e60 fameLimit.xml
    int LoadPickMethod();               // 0x14035a0f0 famePickMethod.xml
    int LoadFameDef();                  // 0x14035a460 fameDef.xml

private:
    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<int, GradePtr> m_aGrades[10];       // +0x10 per alliance (1..9): grade -> row
    ATL::CRBMap<int, LogPtr> m_mapLog;              // +0x1f0 id -> row
    ATL::CAtlMap<int, LimitPtr> m_mapLimit;         // +0x220
    ATL::CAtlArray<PickPtr> m_aPick;                // +0x268
    ATL::CAtlArray<int> m_aAllianceId;              // +0x288 the alliances that have grades
    ATL::CAtlMap<int, DefPtr> m_mapDef;             // +0x2a8 alliance -> def
    ATL::CAtlMap<int, SeasonPtr> m_mapSeason;       // +0x2f0 season -> def
    std::set<int> m_setOfficerNpc;                  // +0x338
    ATL::CAtlMap<int, int> m_mapReload;             // +0x348 pick method reload flags
};
MS2_CHECK_SIZE(CFameTable, 0x390);
MS2_CHECK_OFFSET(CFameTable, m_aGrades, 0x10);
MS2_CHECK_OFFSET(CFameTable, m_mapLog, 0x1f0);
MS2_CHECK_OFFSET(CFameTable, m_mapLimit, 0x220);
MS2_CHECK_OFFSET(CFameTable, m_aPick, 0x268);
MS2_CHECK_OFFSET(CFameTable, m_mapDef, 0x2a8);
MS2_CHECK_OFFSET(CFameTable, m_mapSeason, 0x2f0);
MS2_CHECK_OFFSET(CFameTable, m_setOfficerNpc, 0x338);
MS2_CHECK_OFFSET(CFameTable, m_mapReload, 0x348);
