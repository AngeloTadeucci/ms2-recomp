// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). JobSkill / JobSystem: a character's job skill tree state
// (learned skills and levels, skill points by rank). The TU right before commonfiles\jobtable.cpp, ending with its
// own memmove_s copy at 0x140643530; it has no __FILE__ string, so the name is a guess from the classes.
// WIP (w177, 2026-10-17): 125 stubs. The exe emplace under the byte-identical map<unsigned, JobSkillPtr>::insert
// (0x14063db70 -> 0x14063d860) is not the 14.16 xtree emplace (_Buynode + _Insert_nohint): it calls 0x14063d950(this+8,
// val), 0x140642050, 0x140643000(this+8) and then 0x14063b4f0 (754 B); most stubs hang off that chain (tools: work/w177/stubgraph.py).
// MS2-UNIT: ?\jobsystem.cpp
// MS2-RANGE: 0x140637b00-0x140643650 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEBH$$Z$$V@?$pair@$$CBHH@std@@QEAA@Upiecewise_construct_t@1@V?$tuple@AEBH@1@V?$tuple@$$V@1@@Z 0x14063a670 ; unique
// MS2-PIN: ??$forward_as_tuple@AEBH@std@@YA?AV?$tuple@AEBH@0@AEBH@Z 0x14063a7b0 ; unique
// MS2-PIN: ??$_Buynode@AEBUpiecewise_construct_t@std@@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14063aa60 ; unique
// MS2-PIN: ??$_Insert_hint@AEAU?$pair@$$CBHH@std@@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@1@AEAU?$pair@$$CBHH@1@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@@Z 0x14063bbd0 ; unique
// MS2-PIN: ??$_Kfn@$$CBHH@?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@SAAEBHAEBU?$pair@$$CBHH@1@@Z 0x14063cc20 ; unique
// MS2-PIN: ?SetManager@CNilStringData@ATL@@QEAAXPEAUIAtlStringMgr@2@@Z 0x14063cd80 ; unique
// MS2-PIN: ??$_Try_emplace@AEBH$$V@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14063cda0 ; unique
// MS2-PIN: ??$addressof@U?$pair@$$CBHH@std@@@std@@YAPEAU?$pair@$$CBHH@0@AEAU10@@Z 0x14063d460 ; prop
// MS2-PIN: ??$construct@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@AEAPEAU12@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@AEAPEAU31@@Z 0x14063d4a0 ; unique
// MS2-PIN: ??$construct@U?$pair@$$CBHH@std@@AEBUpiecewise_construct_t@2@V?$tuple@AEBH@2@V?$tuple@$$V@2@@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@1@QEAU?$pair@$$CBHH@1@AEBUpiecewise_construct_t@1@$$QEAV?$tuple@AEBH@1@$$QEAV?$tuple@$$V@1@@Z 0x14063d540 ; unique
// MS2-PIN: ??$forward@AEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@YAAEAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@0@AEAPEAU10@@Z 0x14063da80 ; prop
// MS2-PIN: ??$try_emplace@$$V@?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA?AU?$pair@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@_N@1@AEBH@Z 0x14063dc30 ; prop
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x14063ded0 ; prop
// MS2-PIN: ??0?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x14063df10 ; prop
// MS2-PIN: ??0?$_Tree_unchecked_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@U_Iterator_base0@2@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@1@@Z 0x14063df50 ; unique
// MS2-PIN: ??0?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@std@@QEAA@PEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@1@PEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@1@@Z 0x14063dfb0 ; prop
// MS2-PIN: ??0?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@QEAA@XZ 0x14063e010 ; unique
// MS2-PIN: ??0?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA@XZ 0x14063e0f0 ; prop
// MS2-PIN: ??0?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@AEBU?$less@H@1@@Z 0x14063e3e0 ; unique
// MS2-PIN: ??1?$_Tree_comp_alloc@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x14063e620 ; unique
// MS2-PIN: ??1?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA@XZ 0x14063e670 ; prop
// MS2-PIN: ??1?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAA@XZ 0x14063e780 ; unique
// MS2-PIN: ??1?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEAA@XZ 0x14063e860 ; unique
// MS2-PIN: ??8?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14063eb70 ; unique
// MS2-PIN: ??9?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x14063ec30 ; unique
// MS2-PIN: ??A?$map@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@@std@@QEAAAEAHAEBH@Z 0x14063ec70 ; unique
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBHH@1@XZ 0x14063ed80 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHH@1@XZ 0x14063ee20 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHH@1@XZ 0x14063ee40 ; prop
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14063ee60 ; prop
// MS2-PIN: ??E?$_Tree_unchecked_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14063eef0 ; unique
// MS2-PIN: ??E?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@std@@@std@@QEAA?AV01@H@Z 0x14063ef10 ; prop
// MS2-PIN: ??F?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEAAAEAV01@XZ 0x14063f070 ; prop
// MS2-PIN: ?FindNextNode@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x14063f2a0 ; unique
// MS2-PIN: ?GetKeyAt@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBAAEBIPEAU__POSITION@@@Z 0x14063f360 ; unique
// MS2-PIN: ?GetNext@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14063f3d0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14063f420 ; unique
// MS2-PIN: ?GetValueAt@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEAAAEAGPEAU__POSITION@@@Z 0x14063f490 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlMap@IGV?$CElementTraits@I@ATL@@V?$CElementTraits@G@2@@ATL@@QEBA_NXZ 0x14063f500 ; unique
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x140640060 ; unique
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@@Z 0x140640150 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@2@$00@2@XZ 0x140640bf0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@2@$00@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@@std@@@2@XZ 0x140640c30 ; unique
// MS2-PIN: ?_Unchecked_begin@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIXZ 0x1406420c0 ; unique
// MS2-PIN: ?_Unchecked_end@?$vector@IV?$allocator@I@std@@@std@@QEAAPEAIXZ 0x140642190 ; unique
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHH@std@@PEAX@2@_K@Z 0x1406423d0 ; prop
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIV?$MS2Ptr@VJobSkill@@@@@std@@PEAX@2@_K@Z 0x140642400 ; unique
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@HHU?$less@H@std@@V?$allocator@U?$pair@$$CBHH@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@2@@Z 0x140642ea0 ; unique
// MS2-PIN: ?pointer_to@?$pointer_traits@PEAU?$pair@$$CBHH@std@@@std@@SAPEAU?$pair@$$CBHH@2@AEAU32@@Z 0x140643390 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\jobsystem.cpp"   // guessed (no asserts)
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/commonfiles/jobsystem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Out-of-unit callees.
JobTable* FUN_1401d7a50();                              // the JobTable singleton
class Unk_JobSkillTable { public: MS2Ptr<SkillData> FUN_1407ee1d0(int nSkillId); };
Unk_JobSkillTable* FUN_1401958b0();                     // the skill table


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

