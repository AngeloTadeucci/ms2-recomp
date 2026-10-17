// jobsystem.h - JobSkill and JobSystem: a character's job skill tree state (skill levels, learnt flags, spent skill
// points), serialised to the server. Recovered with commonfiles\jobtable.cpp (the jobsystem.cpp TU at the start of
// its range); method and member names are invented except the RTTI class names. JobSystemCli (client) derives from
// JobSystem.
//
// JobSkill  (RTTI .?AVJobSkill@@, 0x48): one skill of the tree.
// JobSystem (RTTI .?AVJobSystem@@, 0x80, 8 vftable slots).
#pragma once

#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/skilldata.h"

class JobSkill : public CPtred
{
public:
    JobSkill(unsigned nId);                             // 0x140637b00
    bool Init(JobData* pJob);                           // 0x140637ba0 binds the job and skill table rows
    unsigned GetID();                                   // 0x140637cc0
    int GetUsedPoint();                                 // 0x140637ce0 skill points spent on this skill
    int GetJobLevel();                                  // 0x140637e00 the job rank that unlocks it
    bool IsSubSkill();                                  // 0x140637e50
    bool IsLearn();                                     // 0x140637ec0 learnt with the job rank (JobSkillData::isLearn)
    unsigned GetQuickSlotPriority();                    // 0x140637f10
    JobSkillData* GetData();                            // 0x140637f60
    void Write(COutputStream& os);                      // 0x140637f90
    void Read(CByteBuffer& buf);                        // 0x140638020

    unsigned m_nId;                                     // +0x18
    unsigned short m_nLevel;                            // +0x1c
    bool m_bChanged;                                    // +0x1e
    bool m_bLearned;                                    // +0x1f
    bool m_bExtra;                                      // +0x20 granted outside the job tree (JobSystem::vfunc_3)
    JobSkillDataPtr m_spData;                           // +0x28
    MS2Ptr<SkillData> m_spSkill;                        // +0x38
};
MS2_CHECK_SIZE(JobSkill, 0x48);
MS2_CHECK_OFFSET(JobSkill, m_nLevel, 0x1c);
MS2_CHECK_OFFSET(JobSkill, m_bExtra, 0x20);
MS2_CHECK_OFFSET(JobSkill, m_spData, 0x28);
MS2_CHECK_OFFSET(JobSkill, m_spSkill, 0x38);

typedef MS2Ptr<JobSkill> JobSkillPtr;

class JobSystem : public CPtred
{
public:
    typedef std::map<unsigned, JobSkillPtr> SkillMap;

    JobSystem();                                        // 0x1406380e0
    virtual ~JobSystem();                               // 0x140638180
    void SetJob(Unk_JobGroupID nJobGroup, int nJobCode);    // 0x140638200
    bool ChangeJob(Unk_JobGroupID nJobGroup, int nRank, unsigned short nLevel);   // 0x1406382e0 keeps learnt levels
    virtual MS2Ptr<SkillLevelData> vfunc_1(unsigned nSkillId);    // 0x140638690 the current level data (+ bonus)
    virtual bool vfunc_2(unsigned nSkillId);            // 0x140638980 learnt
    virtual void vfunc_3(int nJobGroup, unsigned nSkillId, unsigned short nLevel);    // 0x140638a30 grant a skill
    virtual void vfunc_4();                             // 0x140638c70
    virtual unsigned short vfunc_5(unsigned nSkillId);  // 0x140638c90 bonus levels
    virtual void vfunc_6(COutputStream& os);            // 0x140638cb0 write
    virtual void vfunc_7(CByteBuffer& buf);             // 0x140638f10 read
    static MS2Ptr<SkillData> GetSkillData(unsigned nSkillId);    // 0x140639210
    static int GetLevelSkillPoint(unsigned short nLevel, int nType);  // 0x140639260
    Unk_JobGroupID GetJobGroupID();                     // 0x140639340
    Unk_JobCode GetSubJob();                            // 0x1406393f0
    int GetRank();                                      // 0x1406394b0
    JobSkillPtr FindSkill(unsigned nSkillId);           // 0x1406394d0
    void GetSkills(std::vector<JobSkillPtr>& vOut, int bLearnedOnly, bool bNoSubSkills);   // 0x1406395c0
    void SetSkill(unsigned nSkillId, unsigned short nLevel, bool bLearned);    // 0x140639710
    void ClearChanged();                                // 0x140639840
    void SetRank(unsigned short nLevel, int nJobCode);  // 0x140639920
    void RecalcPoints();                                // 0x140639970
    int GetTotalPoint();                                // 0x140639b20
    int GetUsedPoint(int nJobLevel);                    // 0x140639b40
    JobDataPtr GetJobData();                            // 0x140639bb0
    void InitSkills(Unk_JobGroupID nJobGroup, int nRank);   // 0x140639c00
    void UpdateLearnable(unsigned short nLevel);        // 0x140639d90
    void AddSkill(JobSkillDataPtr spData);              // 0x140639f70 the skill and its sub skills
    void SyncSubSkills(JobSkillPtr spSkill);            // 0x14063a330

    CLockCriticalSection m_lock;                        // +0x18
    std::map<int, int> m_usedPoints;                    // +0x48 by job level
    int m_nTotalPoint;                                  // +0x58
    int m_nRank;                                        // +0x5c
    JobDataPtr m_spJob;                                 // +0x60
    SkillMap m_skills;                                  // +0x70
};
MS2_CHECK_SIZE(JobSystem, 0x80);
MS2_CHECK_OFFSET(JobSystem, m_usedPoints, 0x48);
MS2_CHECK_OFFSET(JobSystem, m_spJob, 0x60);
MS2_CHECK_OFFSET(JobSystem, m_skills, 0x70);
