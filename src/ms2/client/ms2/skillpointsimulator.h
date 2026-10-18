// skillpointsimulator.h - CSkillPointSimulator (RTTI .?AVCSkillPointSimulator@@, 0x150 bytes, CPtred base): the skill
// point reset/distribution preview of the skill window. It keeps two copies of the player's JobSkill tree (the
// snapshot and the one being edited), the skill points the rank grants and what the edit spends. Recovered with
// ?\skillpointsimulator.cpp; method and member names are invented except the RTTI class name.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/commonfiles/jobsystem.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CSkillPointSimulator : public CPtred
{
public:
    typedef ATL::CAtlMap<unsigned, JobSkillPtr> SkillMap;
    typedef std::map<int, long> PointMap;

    CSkillPointSimulator();                             // 0x140abc2b0
    virtual ~CSkillPointSimulator();                    // 0x140abc450
    void Reset(unsigned short nLevel, int nJobCode, std::vector<JobSkillPtr>& skills, PointMap& extra, int nBonus);  // 0x140abc500
    void SetLevel(unsigned short nLevel);               // 0x140abc7a0
    void SetExtraPoints(PointMap& extra);               // 0x140abc7e0
    int GetTotalPoints(int nType);                      // 0x140abc820 points the rank grants (type 1 / 2)
    int GetRemainPoints(int nType);                     // 0x140abc860
    int GetSpentPoints(int nType);                      // 0x140abc8a0
    SkillMap& GetEditSkills();                          // 0x140abc8e0
    JobSkillPtr GetSnapshotSkill(unsigned nSkillId);    // 0x140abc900
    JobSkillPtr GetEditSkill(unsigned nSkillId);        // 0x140abc980
    void Recalc();                                      // 0x140abca00
    int Validate(unsigned* pnBadSkill);                 // 0x140abcd70
    int LevelUp(unsigned nSkillId);                     // 0x140abcfe0
    int LevelDown(unsigned nSkillId, unsigned* pnBadSkill);     // 0x140abd1b0
    int CanLevelUp(unsigned nSkillId);                  // 0x140abd3b0
    int CanLevelDown(unsigned nSkillId);                // 0x140abd5f0
    int CheckRequirements(unsigned nSkillId, unsigned short nLevel);    // 0x140abd760
    void GetChanged(std::vector<JobSkillPtr>& out, int nRank);          // 0x140abdac0
    void GetMerged(std::vector<JobSkillPtr>& out, int nRank);           // 0x140abdc90
    void GetSnapshot(std::vector<JobSkillPtr>& out, int nRank);         // 0x140abddf0
    int IsChanged();                                    // 0x140abdef0
    void ResetRank(int nRank);                          // 0x140abe0a0
    int AutoDistribute(ATL::CAtlArray<unsigned>& order, ATL::CAtlArray<unsigned>& counts);   // 0x140abe1e0
    void GetUsedPoints(ATL::CAtlArray<unsigned>& ids, ATL::CAtlArray<unsigned>& points, int nRank);  // 0x140abe4a0
    void Commit(int nRank);                             // 0x140abe620 the edit becomes the snapshot (other ranks keep theirs)
private:
    MS2_LAYOUT_FRIEND;
    unsigned short m_nLevel;                            // +0x18 character level
    int m_nJobCode;                                     // +0x1c
    int m_nJobRank;                                     // +0x20
    SkillMap m_mapSnapshot;                             // +0x28 skill id -> JobSkill
    SkillMap m_mapEdit;                                 // +0x70
    Unk_FieldIdListMap m_mapUnused;                     // +0xb8 (only constructed)
    int m_nSpent;                                       // +0x100 points spent on the learnt skills
    int m_nRemain;                                      // +0x104
    int m_nBonus;                                       // +0x108
    PointMap m_mapTotal;                                // +0x110 rank -> points granted
    PointMap m_mapRemain;                               // +0x120
    PointMap m_mapSpent;                                // +0x130
    PointMap m_mapExtra;                                // +0x140
};
MS2_CHECK_SIZE(CSkillPointSimulator, 0x150);
MS2_CHECK_OFFSET(CSkillPointSimulator, m_mapEdit, 0x70);
MS2_CHECK_OFFSET(CSkillPointSimulator, m_mapExtra, 0x140);
