// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). JobTable (Table/job.xml: per job group the start field,
// items and the job skill tree) and, in the first part of the range, the jobsystem.cpp TU: JobSkill / JobSystem, a
// character's skill tree state. The range spans two original TUs (jobsystem.cpp ends with its own memmove_s copy at
// 0x140643530; jobtable.cpp starts at 0x140643650 with its __FILE__ asserts), so the template COMDATs the two share
// exist twice in the exe.
// MS2-UNIT: commonfiles\jobtable.cpp
// MS2-RANGE: 0x140637b00-0x14064c590 .text$mn
// MS2-RANGE: 0x1400bae70-0x1400baec0 .text$di
// MS2-RANGE: 0x142c9b490-0x142c9b4b0 .text$yd
// MS2-PIN: ??_7JobTable@@6B?$TSingleton@VJobTable@@@@@ 0x142d6e0a8
// MS2-PIN: ??_7JobTable@@6B?$CValidData@VJobTable@@@@@ 0x142d6e0b8
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\jobtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "jobtable.h"
#include "jobsystem.h"
#include "logstring.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include <vector>
#include "hook/ms2hook.h"

// Out-of-unit callees.
JobTable* FUN_1401d7a50();                              // the JobTable singleton
CStringTable* FUN_1401a9d70();                          // the string table singleton
class Unk_JobSkillTable { public: MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId); };
Unk_JobSkillTable* FUN_1401958b0();                     // the skill table
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);    // Table/<file>
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton, init flag and max level map (symbols-manual.tsv)
JobTable* TSingleton<JobTable>::s_instance;
bool JobTable::s_bInit;
ATL::CAtlMap<unsigned, unsigned short> JobData::s_skillMaxLevel;
#endif

// ---- jobsystem.cpp ----------------------------------------------------------------------------------------------

// @0x140637b00
JobSkill::JobSkill(unsigned nId)
    : m_nId(nId), m_nLevel(1), m_bChanged(false), m_bLearned(false), m_bExtra(false)
{
}

// @0x140637ba0
bool JobSkill::Init(JobData* pJob)
{
    m_spData = pJob->GetSkillData(GetID());
    if (!m_bExtra && m_spData == 0)
        return false;
    m_spSkill = JobSystem::GetSkillData(GetID());
    if (m_spSkill == 0)
        return false;
    return true;
}

// @0x140637cc0
unsigned JobSkill::GetID()
{
    return m_nId;
}

// @0x140637ce0
int JobSkill::GetUsedPoint()
{
    MS2Ptr<SkillData> spSkill = JobSystem::GetSkillData(m_nId);
    if (spSkill == 0)
        return 0;
    if (IsSubSkill())
        return 0;
    if (IsLearn() || m_bExtra)
    {
        return m_nLevel - 1;
    }
    else
    {
        if (!m_bLearned)
            return 0;
        return m_nLevel;
    }
}

// @0x140637e00
int JobSkill::GetJobLevel()
{
    if (m_spData == 0)
        return 0;
    return m_spData->m_jobLevel;
}

// @0x140637e50
bool JobSkill::IsSubSkill()
{
    if (m_spData == 0)
        return false;
    return GetID() != m_spData->m_skillID;
}

// @0x140637ec0
bool JobSkill::IsLearn()
{
    if (m_spData == 0)
        return false;
    return m_spData->m_isLearn;
}

// @0x140637f10
unsigned JobSkill::GetQuickSlotPriority()
{
    if (m_spData == 0)
        return 0xffffffff;
    return m_spData->m_quickSlotPriority;
}

// @0x140637f60
JobSkillData* JobSkill::GetData()
{
    return m_spData.get();
}

// @0x140637f90
void JobSkill::Write(COutputStream& os)
{
    os.vfunc_o10_3(m_nLevel);
    os.vfunc_o10_0(m_bChanged);
    os.vfunc_o10_0(m_bLearned);
    os.vfunc_o10_0(m_bExtra);
}

// @0x140638020
void JobSkill::Read(CByteBuffer& buf)
{
    m_nLevel = buf.vfunc_o8_3();
    m_bChanged = buf.vfunc_o8_0();
    m_bLearned = buf.vfunc_o8_0();
    m_bExtra = buf.vfunc_o8_0();
}

// @0x1406380e0
JobSystem::JobSystem()
    : m_nTotalPoint(0), m_nRank(0)
{
}

// @0x140638180
JobSystem::~JobSystem()
{
}

// @0x140638200
void JobSystem::SetJob(int nJobGroup, int nJobCode, unsigned short nLevel)
{
    if (!FUN_1401d7a50()->GetJobData(nJobGroup))
        return;
    int nRank = FUN_1401d7a50()->GetJobRank(nJobCode);
    Unk_CriticalSectionLock lock(m_lock, 1);
    InitSkills(nJobGroup, nRank);
    RecalcPoints();
}

// @0x1406382e0
// MS2-FUNCTIONAL: the exe frame is 0x10 larger (the lock at rsp+0x70 instead of 0x60; temporaries ordered differently)
bool JobSystem::ChangeJob(int nJobGroup, int nRank, unsigned short nLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!FUN_1401d7a50()->GetJobData(nJobGroup))
        return false;
    ATL::CAtlMap<unsigned, unsigned short> learned;
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (spSkill->m_bLearned)
        {
            if (spSkill->m_nLevel > 1)
                learned.SetAt(spSkill->GetID(), spSkill->m_nLevel);
        }
    }
    InitSkills(nJobGroup, nRank);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (spSkill->m_bLearned)
            spSkill->m_bChanged = true;
    }
    POSITION pos = learned.GetStartPosition();
    while (pos != 0)
    {
        unsigned nSkillId = learned.GetKeyAt(pos);
        if (vfunc_2(nSkillId))
            SetSkill(nSkillId, learned.GetValueAt(pos), true);
        learned.GetNext(pos);
    }
    RecalcPoints();
    return true;
}

// @0x140638690
// MS2-FUNCTIONAL: the exe frame has one more 4-byte slot below the locals (every local 4 bytes higher)
MS2Ptr<SkillLevelData> JobSystem::vfunc_1(unsigned nSkillId)
{
    unsigned short nBonus = vfunc_5(nSkillId);
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
    {
        MS2Ptr<SkillData> spData = GetSkillData(spSkill->GetID());
        if (spData == 0)
            return 0;
        unsigned short nLevel = spSkill->m_bLearned ? spSkill->m_nLevel : 0;
        unsigned short nCur = spData->FUN_1407e9b10() < nLevel + nBonus ? spData->FUN_1407e9b10() : nLevel + nBonus;
        return spData->FUN_1407e90a0(nCur);
    }
    MS2Ptr<SkillData> spData = GetSkillData(nSkillId);
    if (spData.get() != 0 && !spData->FUN_1407e9f30())
        return spData->FUN_1407e90a0(1);
    return 0;
}

// @0x140638980
bool JobSystem::vfunc_2(unsigned nSkillId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
        return spSkill->m_bLearned;
    return false;
}

// @0x140638a30
void JobSystem::vfunc_3(int nJobGroup, unsigned nSkillId, unsigned short nLevel)
{
    if (GetJobGroupID() != nJobGroup)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!FindSkill(nSkillId))
    {
        JobSkillPtr spSkill(new JobSkill(nSkillId));
        spSkill->m_nLevel = nLevel;
        spSkill->m_bChanged = true;
        spSkill->m_bLearned = true;
        spSkill->m_bExtra = true;
        if (!spSkill->Init(m_spJob.get()))
            return;
        m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    }
    RecalcPoints();
}

// @0x140638c70
void JobSystem::vfunc_4(unsigned short nLevel)
{
}

// @0x140638c90
unsigned short JobSystem::vfunc_5(unsigned nSkillId)
{
    return 0;
}

// @0x140638cb0
void JobSystem::vfunc_6(COutputStream& os)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    os.vfunc_o10_3(m_nRank);
    if (GetJobData().get())
    {
        os.vfunc_o10_3(GetJobData()->GetJobGroupID());
        os.vfunc_o10_1((unsigned char)m_skills.size());
        for (auto& kv : m_skills)
        {
            JobSkillPtr spSkill = kv.second;
            os.vfunc_o10_3(spSkill->GetID());
            spSkill->Write(os);
        }
    }
    RecalcPoints();
}

// @0x140638f10
void JobSystem::vfunc_7(CByteBuffer& buf)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nRank = buf.vfunc_o8_3();
    int nJobGroup = buf.vfunc_o8_3();
    m_spJob = FUN_1401d7a50()->GetJobData(nJobGroup);
    m_skills.clear();
    int nCount = buf.vfunc_o8_1();
    for (int i = 0; i < nCount; i++)
    {
        unsigned nSkillId = buf.vfunc_o8_3();
        JobSkillPtr spSkill(new JobSkill(nSkillId));
        spSkill->Read(buf);
        if (!spSkill->Init(m_spJob.get()))
            continue;
        m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    }
    RecalcPoints();
}

// @0x140639210
MS2Ptr<SkillData> JobSystem::GetSkillData(unsigned nSkillId)
{
    return FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
}

// @0x140639260
int JobSystem::GetLevelSkillPoint(unsigned short nLevel, int nType)
{
    if (nLevel < 10)
        return 0;
    if (nType == 1)
    {
        return (nLevel < FUN_1401d3200()->SkillPointLimitLevel1 ? nLevel : FUN_1401d3200()->SkillPointLimitLevel1) - 9;
    }
    else if (nType == 2)
    {
        if (nLevel < 60)
            return 0;
        return (nLevel < FUN_1401d3200()->SkillPointLimitLevel2 ? nLevel : FUN_1401d3200()->SkillPointLimitLevel2) - 59;
    }
    return 0;
}

// @0x140639340
Unk_JobGroupID JobSystem::GetJobGroupID()
{
    if (!GetJobData())
        return Unk_JobGroupID_None;
    return GetJobData()->GetJobGroupID();
}

// @0x1406393f0
Unk_JobCode JobSystem::GetSubJob()
{
    if (GetJobData() == 0)
        return Unk_JobCode_None;
    return GetJobData()->GetSubJob(m_nRank);
}

// @0x1406394b0
int JobSystem::GetRank()
{
    return m_nRank;
}

// @0x1406394d0
JobSkillPtr JobSystem::FindSkill(unsigned nSkillId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    SkillMap::iterator it = m_skills.find(nSkillId);
    if (it != m_skills.end())
        return it->second;
    return 0;
}

// @0x1406395c0
void JobSystem::GetSkills(std::vector<JobSkillPtr>& vOut, int bLearnedOnly, bool bNoSubSkills)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (bLearnedOnly != 0 && !spSkill->m_bLearned)
            continue;
        if (bNoSubSkills && spSkill->IsSubSkill())
            continue;
        vOut.push_back(spSkill);
    }
}

// @0x140639710
void JobSystem::SetSkill(unsigned nSkillId, unsigned short nLevel, bool bLearned)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    JobSkillPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
    {
        spSkill->m_nLevel = nLevel;
        spSkill->m_bChanged = false;
        if (spSkill->m_bLearned != bLearned && bLearned)
            spSkill->m_bChanged = true;
        spSkill->m_bLearned = bLearned;
        SyncSubSkills(spSkill);
    }
}

// @0x140639840
void JobSystem::ClearChanged()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        spSkill->m_bChanged = false;
    }
}

// @0x140639920
void JobSystem::SetRank(unsigned short nLevel, int nJobCode)
{
    m_nRank = FUN_1401d7a50()->GetJobRank(nJobCode);
    UpdateLearnable(nLevel);
}

// @0x140639970
void JobSystem::RecalcPoints()
{
    std::vector<JobSkillPtr> skills;
    GetSkills(skills, 1, false);
    if (skills.empty())
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_nTotalPoint = 0;
    m_usedPoints.clear();
    for (auto& spSkill : skills)
    {
        if (spSkill == 0)
            continue;
        int nJobLevel = spSkill->GetJobLevel();
        int nPoint = spSkill->GetUsedPoint();
        m_usedPoints[nJobLevel] += nPoint;
        m_nTotalPoint += nPoint;
    }
}

// @0x140639b20
int JobSystem::GetTotalPoint()
{
    return m_nTotalPoint;
}

// @0x140639b40
int JobSystem::GetUsedPoint(int nJobLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_usedPoints[nJobLevel];
}

// @0x140639bb0
JobDataPtr JobSystem::GetJobData()
{
    return m_spJob;
}

// @0x140639c00
void JobSystem::InitSkills(int nJobGroup, int nRank)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spJob = FUN_1401d7a50()->GetJobData(nJobGroup);
    m_nRank = nRank;
    m_skills.clear();
    std::vector<JobSkillDataPtr> skills;
    m_spJob->GetSkills(skills);
    for (auto& spData : skills)
        AddSkill(spData);
}

// @0x140639d90
void JobSystem::UpdateLearnable(unsigned short nLevel)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (auto& kv : m_skills)
    {
        JobSkillPtr spSkill = kv.second;
        if (!spSkill->IsLearn())
            continue;
        bool bWasLearned = spSkill->m_bLearned;
        spSkill->m_bLearned = m_nRank >= spSkill->GetJobLevel();
        spSkill->m_bChanged = !bWasLearned && spSkill->m_bLearned;
        SyncSubSkills(spSkill);
    }
    RecalcPoints();
}

// @0x140639f70
void JobSystem::AddSkill(JobSkillDataPtr spData)
{
    if (spData == 0)
        return;
    JobSkillPtr spSkill(new JobSkill(spData->m_skillID));
    if (!spSkill->Init(m_spJob.get()))
        return;
    if (spSkill->IsLearn())
        spSkill->m_bLearned = m_nRank >= spSkill->GetJobLevel();
    m_skills.insert(std::make_pair(spSkill->GetID(), spSkill));
    for (auto& nSubId : spData->m_subSkillIDs)
    {
        JobSkillPtr spSub(new JobSkill(nSubId));
        if (!spSub->Init(m_spJob.get()))
            continue;
        spSub->m_bLearned = spSkill->m_bLearned;
        m_skills.insert(std::make_pair(spSub->GetID(), spSub));
    }
}

// @0x14063a330
void JobSystem::SyncSubSkills(JobSkillPtr spSkill)
{
    if (spSkill == 0)
        return;
    JobSkillDataPtr spData = m_spJob->FindSkill(spSkill->GetID());
    if (spData == 0)
        return;
    for (unsigned nSubId : spData->m_subSkillIDs)
    {
        JobSkillPtr spSub = FindSkill(nSubId);
        if (spSub == 0)
            continue;
        MS2Ptr<SkillData> spSubData = GetSkillData(nSubId);
        if (spSubData == 0)
            continue;
        spSub->m_bLearned = spSkill->m_bLearned;
        spSub->m_nLevel = spSubData->FUN_1407e9ac0() < spSkill->m_nLevel ? spSubData->FUN_1407e9ac0() : spSkill->m_nLevel;
    }
}

// @0x140643530
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);

// ---- jobtable.cpp -----------------------------------------------------------------------------------------------

// @0x140643650
JobSkillData::JobSkillData()
    : m_skillID(0), m_uiHighlight(false), m_quickSlotPriority(0x7fffffff), m_jobLevel(0), m_isLearn(false),
      m_requireQuestID(0)
{
}

// @0x140643720
bool JobSkillData::Load(Unk_140165cf0* pElem)
{
    FUN_140873220(pElem, "skillID", m_skillID);
    XmlValue(pElem, "uiPosition", m_uiPosition);
    FUN_1408730a0(pElem, "uiHighlight", m_uiHighlight);
    FUN_140873220(pElem, "quickSlotPriority", m_quickSlotPriority);
    FUN_1408731e0(pElem, "jobLevel", m_jobLevel);
    XmlTokenList(pElem, "subSkillIDs", m_subSkillIDs);
    FUN_1408730a0(pElem, "isLearn", m_isLearn);
    XmlTokenList(pElem, "requireLevel", m_requireLevel);
    XmlTokenList(pElem, "requireSkillIDs", m_requireSkillIDs);
    XmlTokenList(pElem, "requireSkillLevels", m_requireSkillLevels);
    FUN_140873220(pElem, "requireQuestID", m_requireQuestID);
    return true;
}

// @0x140643880
bool JobSkillData::HasRequirement()
{
    if (!m_requireLevel.empty())
        return true;
    if (!m_requireSkillIDs.IsEmpty())
        return true;
    if (m_requireQuestID != 0)
        return true;
    return false;
}

// @0x1406438e0
unsigned short JobSkillData::GetRequireLevel(unsigned short skillLevel)
{
    MS2_ASSERT_AT(55, skillLevel > 0);
    if (m_requireLevel.empty() || skillLevel <= 0)
        return 0;
    if (m_requireLevel.size() < skillLevel)
        return *m_requireLevel.rbegin();
    return m_requireLevel[skillLevel - 1];
}

// @0x1406439a0
JobData::JobData()
    : m_defaultWeaponSlot(1), m_jobGroupID(Unk_JobGroupID_None), m_characterBGM(0), m_startField(2000001)
{
}

// @0x140643a60
void JobData::Load(Unk_140165cf0* pElem)
{
    XmlValue(pElem, "jobGroupID", m_jobGroupID);
    FUN_140873220(pElem, "characterBGM", m_characterBGM);
    FUN_1408731e0(pElem, "defaultWeaponSlot", m_defaultWeaponSlot);
    FUN_140873220(pElem, "startField", m_startField);
    FUN_1408733e0(pElem, "characterVoice", m_characterVoice);
    XmlTokenList(pElem, "startItems", m_startItems);
    XmlValue(pElem, "subJob1", m_subJob1);
    XmlValue(pElem, "subJob2", m_subJob2);
    Unk_140165cf0* pSkills = pElem->FUN_140165cf0("skills");
    if (pSkills != 0)
    {
    for (Unk_140165cf0* pSkill : pSkills->FUN_140165cf0("v"))
    {
        JobSkillDataPtr spSkill(new JobSkillData);
        if (spSkill->Load(pSkill))
        {
            m_skills.insert(std::make_pair(spSkill->m_skillID, spSkill));
            for (unsigned nSubId : spSkill->m_subSkillIDs)
                m_subSkills.insert(std::make_pair(nSubId, spSkill));
        }
        unsigned short nMaxLevel = 0;
        FUN_1408731a0(pSkill, "maxLevel", nMaxLevel);
        s_skillMaxLevel.SetAt(spSkill->m_skillID, nMaxLevel);
    }
    }
}

// @0x140643e40
Unk_JobGroupID JobData::GetJobGroupID()
{
    return m_jobGroupID;
}

// @0x140643e60
Unk_JobCode JobData::GetSubJob(int nIndex)
{
    switch (nIndex)
    {
    case 1:
        return m_subJob1;
    case 2:
        return m_subJob2;
    default:
        MS2_ASSERT_AT(131, 0);
        return Unk_JobCode_None;
    }
}

// @0x140643ed0
Unk_JobCode JobData::GetSubJob1()
{
    return m_subJob1;
}

// @0x140643ef0
Unk_JobCode JobData::GetSubJob2()
{
    return m_subJob2;
}

// @0x140643f10
unsigned JobData::GetCharacterBGM()
{
    return m_characterBGM;
}

// @0x140643f30
CStringW JobData::GetName()
{
    if (FUN_1401a9d70() != 0)
        return FUN_1401a9d70()->FUN_141811980(6, m_jobGroupID);
    return L"";
}

// @0x140643fb0
unsigned JobData::GetStartField()
{
    return m_startField;
}

// @0x140643fd0
bool JobData::HasSkill(unsigned nSkillId)
{
    return GetSkillData(nSkillId).get() != 0;
}

// @0x140644050
bool JobData::HasSubSkill(unsigned nSkillId)
{
    return FindSubSkill(nSkillId).get() != 0;
}

// @0x1406440d0
unsigned JobData::GetSubSkillParent(unsigned nSkillId)
{
    JobSkillDataPtr spSkill = FindSubSkill(nSkillId);
    if (spSkill == 0)
        return 0;
    return spSkill->m_skillID;
}

// @0x140644150
JobSkillDataPtr JobData::FindSkill(unsigned nSkillId)
{
    SkillMap::iterator it = m_skills.find(nSkillId);
    if (it == m_skills.end())
        return 0;
    return it->second;
}

// @0x140644210
JobSkillDataPtr JobData::FindSubSkill(unsigned nSkillId)
{
    SkillMap::iterator it = m_subSkills.find(nSkillId);
    if (it == m_subSkills.end())
        return 0;
    return it->second;
}

// @0x1406442d0
JobSkillDataPtr JobData::GetSkillData(unsigned nSkillId)
{
    JobSkillDataPtr spSkill = FindSkill(nSkillId);
    if (spSkill.get() != 0)
        return spSkill;
    return FindSubSkill(nSkillId);
}

// @0x140644380
void JobData::GetSkills(std::vector<JobSkillDataPtr>& vOut)
{
    for (auto kv : m_skills)
        vOut.push_back(kv.second);
}

// @0x140644430
unsigned short JobData::GetSkillMaxLevel(unsigned nSkillId)
{
    unsigned short nMaxLevel = 0;
    s_skillMaxLevel.Lookup(nSkillId, nMaxLevel);
    return nMaxLevel;
}

// @0x140644470
JobTable::JobTable()
{
}

// @0x1406444e0
JobTable::~JobTable()
{
}

// @0x140644540
int JobTable::Load()
{
    m_jobs.clear();
    CString strPath = FUN_14071a5b0("Table", "job.xml");
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "job", "jobGroupID", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        if (pNode == 0)
            continue;
        JobDataPtr spJob(new JobData);
        spJob->Load(pNode);
        int nJobGroup = spJob->GetJobGroupID();
        m_jobs.insert(std::make_pair(nJobGroup, spJob));
    }
    SetInit(true);
    return 1;
}

// @0x140644880
JobDataPtr JobTable::GetJobData(int nJobGroup)
{
    CheckInit();
    JobMap::iterator it = m_jobs.find(nJobGroup);
    if (it != m_jobs.end())
        return it->second;
    return 0;
}

// @0x140644940
unsigned JobTable::GetStartField(int nJobGroup)
{
    if (JobDataPtr spJob = GetJobData(nJobGroup))
        return spJob->GetStartField();
    return 0x400001;
}

// @0x1406449c0
Unk_JobGroupID JobTable::GetJobGroupBySkill(unsigned nSkillId)
{
    CheckInit();
    for (auto& kv : m_jobs)
    {
        JobData* pJob = kv.second.get();
        if (pJob->HasSkill(nSkillId))
            return pJob->GetJobGroupID();
    }
    return Unk_JobGroupID_None;
}

// @0x140644a80
Unk_JobGroupID JobTable::GetJobGroupBySubJob(Unk_JobCode nJobCode)
{
    CheckInit();
    for (auto kv : m_jobs)
    {
        if (kv.second->GetSubJob1() == nJobCode || kv.second->GetSubJob2() == nJobCode)
            return kv.second->GetJobGroupID();
    }
    return Unk_JobGroupID_None;
}

// @0x140644b80
int JobTable::GetJobRank(int nJobCode)
{
    int nRank = nJobCode % 10;
    return nRank + 1;
}

// @0x140644bb0
Unk_JobCode JobTable::GetSubJob1(int nJobGroup)
{
    JobDataPtr spJob = GetJobData(nJobGroup);
    if (spJob == 0)
        return Unk_JobCode_None;
    return spJob->GetSubJob1();
}
