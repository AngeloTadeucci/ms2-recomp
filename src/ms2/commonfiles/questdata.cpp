// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest table row (CQuestData) and the quest table (QuestDataTable).
// MS2-UNIT: commonfiles\questdata.cpp
// MS2-RANGE: 0x140744670-0x140761a40 .text$mn
// MS2-RANGE: 0x1400bc1a0-0x1400bc3d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\questdata.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cguildxmldata.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/commonfiles/fielddata.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Header statics (the same list as header_statics_a.h, twice: the sort names of two enums).
#ifndef MS2_HOOK_DLL
static CStringA s_sortNamesA[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400bc1a0
static CStringA s_sortNamesB[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // @0x1400bc260
static CString s_strSkill = "skill";                                                                      // @0x1400bc320
static CString s_strStun = "stun";                                                                        // @0x1400bc350
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);                                         // @0x1400bc380
#endif

__int64 FUN_140869440();                                    // server time
__int64 FUN_14086b190(int nWeekday, __int64 tFrom);         // NextWeekdayStart
int FUN_140869470(int nDays);                               // DaysToSeconds
__int64 FUN_14086b590(int nYear, int nMonth, int nDay);
const __int64& FUN_1402e49a0(const __int64& a, const __int64& b);   // the smaller of the two
CFieldMetaTable* FUN_140700390();
CGuildXmlData* FUN_1404f4530();

// A scheduled game event (the <eventTag> lookup), handed out as an intrusive pointer.
class Unk_EventEntry;
bool FUN_140866880(Unk_EventEntry* pEntry, __int64* pTime);          // the time falls into the event
CMsTime FUN_140866720(Unk_EventEntry* pEntry);                       // the event's start
CMsTime FUN_1408666e0(Unk_EventEntry* pEntry);                       // the event's end
bool FUN_140866820(Unk_EventEntry* pEntry, const CMsTime& time);
bool FUN_140866760(Unk_EventEntry* pEntry);
class Unk_GEManagerA { public: Unk_PayloadPtr<Unk_EventEntry> FUN_140479410(CStringW* pTag); };
Unk_GEManagerA* FUN_1401c0d90();

// One <questCondition> pair of the quest manager query (0x1407470f0): the quests whose state is checked.
struct Unk_E16 { int m_questA, m_questB, m_stateA, m_stateB; };
struct Unk_Arr16 { void* m_p; unsigned __int64 m_n; };
Unk_E16* FUN_14027f040(Unk_Arr16* pArr, unsigned __int64 n);
unsigned __int64 FUN_1402815b0(Unk_Arr16* pArr);
class Unk_QuestCondition
{
public:
    int FUN_140266970();
    char m_pad[0x18];
    unsigned m_result;
    Unk_Arr16 m_list;
};
int FUN_140764480(Unk_PayloadPtr<CQuest> pQuest, int nState);

MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
bool FUN_14074b090(CQuestData* pData);
int FUN_14074b330(CQuestData* pData);
int FUN_14074b030(CQuestData* pData);
int FUN_14074b050(CQuestData* pData);
int FUN_14074b070(CQuestData* pData);
int FUN_140408410(ATL::CAtlArray<unsigned>* pArr, const unsigned* pValue);
int FUN_1402bacf0(ATL::CAtlArray<int>& arr, const int& value);
int FUN_1407474d0(const ATL::CAtlArray<int>* pArr, const int* pValue);
int FUN_140747460(const ATL::CAtlArray<int>* pArr, const int* pValue);

// @0x140744670
int CQuestCommon::FUN_140744670(int field)
{
    if (!FUN_140744cd0(field))
        return 0;
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    if (!data->m_34)
        return 0;
    if (!IsActive())
        return 0;
    int nField = FUN_14074b330(data.operator->());
    if (nField == 0)
        return 0;
    if (nField == field)
        return 0;
    return 1;
}

// @0x1407447c0
int CQuestCommon::FUN_1407447c0()
{
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return false;
    if (!FUN_14074b090(data.operator->()))
        return false;
    __int64 tEnd = FUN_1407448a0();
    return FUN_140869440() >= tEnd;
}

// MS2-FUNCTIONAL: extra result temporary in the exe (early-return slots).
// @0x1407448a0
__int64 CQuestCommon::FUN_1407448a0()
{
    MS2Ptr<CQuestData> data = GetData();
    if (!data)
        return 0;
    __int64 tPeriod = 0;
    __int64 tEvent = 0;
    if (data->m_resetType != 0)
    {
        __int64 tStart = GetStartTime();
        if (tStart == 0)
            tStart = FUN_140869440();
        tPeriod = FUN_14086b190(data->m_resetType, tStart);
    }
    else if (data->m_durationMinutes != 0)
    {
        __int64 tStart = GetStartTime();
        if (tStart == 0)
            tStart = FUN_140869440();
        tPeriod = tStart + data->m_durationMinutes * 60;
    }
    if (data->m_schedule.GetLength() != 0)
    {
        Unk_PayloadPtr<Unk_EventEntry> event = FUN_1401c0d90()->FUN_140479410(&data->m_schedule);
        if (event == 0)
            return 0;
        __int64 tStart = GetStartTime();
        if (tStart != 0)
        {
            if (!FUN_140866880(event.operator->(), &tStart))
                return 0;
        }
        tEvent = FUN_140866720(event.operator->()).Get();
    }
    if (tPeriod != 0 && tEvent != 0)
        return FUN_1402e49a0(tPeriod, tEvent);
    if (tPeriod == 0)
        return tEvent;
    return tPeriod;
}
MS2_REPLACE_METHOD(0x1407448A0, CQuestCommon, FUN_1407448a0, 732, 0x32941A8A);

// @0x140744b90
int CQuestCommon::FUN_140744b90(int field)
{
    MS2Ptr<CQuestData> data = GetData();
    if (data.operator==(0))
        return 0;
    if (data->m_fields.IsEmpty())
        return 0;
    int nWant = data->m_fields[0];
    if (nWant != field)
    {
        unsigned nHave = 0;
        if (FUN_140700390()->FUN_1406fc110(field, &nHave) == 0)
            return 0;
        if (nWant != (int)nHave)
            return 0;
    }
    return 1;
}

// @0x140744cd0
int CQuestCommon::FUN_140744cd0(int field)
{
    MS2Ptr<CFieldData> data = CFieldData::FUN_140374140(field);
    if (!data)
        return 0;
    return 1;
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140744d40
int CQuestManagerCommon::vfunc_o10_21(int questId, int npcId, int flag)
{
    if (FUN_140745820(questId, flag) == 0)
        return 0;
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.operator==(0))
        return 0;
    if (npcId != 0 && data->m_2e8 != npcId)
        return 0;
    CMsTime now(FUN_140869440());
    if (data->m_require.m_groupId != 0)
    {
        int nSeed = FUN_140747000(questId);
        ATL::CAtlArray<unsigned> picked;
        QuestDataTable::GetInstance()->FUN_14074e6c0(data->m_require.m_groupId, m_selector, nSeed, picked);
        unsigned nId = FUN_14074b030(data.operator->());
        if (FUN_140408410(&picked, &nId) == -1)
            return 0;
    }
    if (data->m_require.m_dayOfWeek.GetCount() != 0)
    {
        int nDay = now.GetDayOfWeek();
        if (FUN_1402bacf0(data->m_require.m_dayOfWeek, nDay) == -1)
            return 0;
    }
    __int64 tStart = 0;
    int nState = 4;
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.get() != 0)
    {
        tStart = quest->GetStartTime();
        nState = quest->FUN_1407476d0();
    }
    if (data->m_schedule.GetLength() != 0)
    {
        Unk_PayloadPtr<Unk_EventEntry> event = FUN_1401c0d90()->FUN_140479410(&data->m_schedule);
        if (event.IsNull())
            return 0;
        if (!FUN_140866820(event.operator->(), now))
            return 0;
        if (FUN_140866760(event.operator->()))
        {
            __int64 tNow = vfunc_o10_8();
            if (tNow < FUN_1408666e0(event.operator->()).Get())
                return 0;
        }
        if (tStart != 0)
        {
            if (!FUN_140866880(event.operator->(), &tStart))
                return 1;
        }
    }
    if (nState == 1)
        return 0;
    int nRepeat = FUN_14074b070(data.operator->());
    if (nRepeat == 0)
    {
        if (nState == 2)
            return 0;
    }
    else if (nRepeat == 2)
    {
        if (nState == 2)
        {
            CMsTime last(tStart);
            if (last.GetYear() == now.GetYear() && last.GetMonth() == now.GetMonth() && last.GetDay() == now.GetDay())
                return 0;
        }
    }
    else if (nRepeat == 3 && nState == 2)
    {
        CMsTime reset(FUN_14086b190(data->m_resetType, tStart));
        if (now.Get() < reset.Get())
            return 0;
    }
    if (FUN_14074b050(data.operator->()) == 6)
    {
        if (FUN_14074b070(data.operator->()) == 2)
        {
            __int64 tUntil = vfunc_o10_12() + FUN_140869470(1);
            if (now.Get() < tUntil)
                return 0;
        }
        else if (FUN_14074b070(data.operator->()) == 3)
        {
            __int64 tUntil = vfunc_o10_12() + FUN_140869470(7);
            if (now.Get() < tUntil)
                return 0;
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140744D40, CQuestManagerCommon, vfunc_o10_21, 2115, 0x2D2D1A6E);

// @0x140745590
int CQuestManagerCommon::FUN_140745590(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsRewarded();
}

// @0x140745630
int CQuestManagerCommon::FUN_140745630(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsActive();
}

// @0x1407456d0
int CQuestManagerCommon::FUN_1407456d0(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    return quest->IsComplete();
}

// @0x140745770
bool CQuestManagerCommon::FUN_140745770(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return false;
    return (bool)quest->FUN_1407447c0();
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140745820
int CQuestManagerCommon::FUN_140745820(int questId, int flag)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.get() == 0)
        return 0;
    CQuestData::Require& req = data->m_require;
    if (data->m_30)
        return 0;
    if (vfunc_o10_4() < req.m_level)
        return 0;
    if (req.m_maxLevel != 0 && req.m_maxLevel < vfunc_o10_4())
        return 0;
    if (req.m_gearScore != 0 && vfunc_o10_5() < (int)req.m_gearScore)
        return 0;
    if (req.m_job.GetCount() != 0)
    {
        int nJob = vfunc_o10_6();
        if (FUN_1407474d0(&req.m_job, &nJob) == -1)
            return 0;
    }
    if (req.m_subJob.GetCount() != 0)
    {
        int nSubJob = vfunc_o10_7();
        if (FUN_140747460(&req.m_subJob, &nSubJob) == -1)
            return 0;
    }
    for (size_t i = 0; i < req.m_quest.GetCount(); ++i)
    {
        if (req.m_quest[i] != 0 && FUN_140745590(req.m_quest[i]) == 0)
            return 0;
    }
    if (req.m_selectableQuest.GetCount() != 0)
    {
        int bAny = 0;
        for (size_t i = 0; i < req.m_selectableQuest.GetCount(); ++i)
        {
            if (req.m_selectableQuest[i] != 0 && FUN_140745590(req.m_selectableQuest[i]) != 0)
                bAny = 1;
        }
        if (bAny == 0)
            return 0;
    }
    for (size_t i = 0; i < req.m_progressQuest.GetCount(); ++i)
    {
        if (req.m_progressQuest[i] != 0 && FUN_140745630(req.m_progressQuest[i]) == 0)
            return 0;
    }
    for (size_t i = 0; i < req.m_unrequire.GetCount(); ++i)
    {
        if (req.m_unrequire[i] != 0)
        {
            if (FUN_140745590(req.m_unrequire[i]) != 0)
                return 0;
            if (FUN_140745630(req.m_unrequire[i]) != 0)
                return 0;
        }
    }
    if (flag == 0)
    {
        for (size_t i = 0; i < req.m_unrequireGroup.GetCount(); ++i)
        {
            int nSeed = FUN_140747000(questId);
            ATL::CAtlArray<unsigned> picked;
            QuestDataTable::GetInstance()->FUN_14074e6c0(req.m_unrequireGroup[i], m_selector, nSeed, picked);
            for (size_t j = 0; j < picked.GetCount(); ++j)
            {
                if (FUN_140745630(picked[j]) != 0)
                    return 0;
                if (FUN_140745590(picked[j]) != 0)
                {
                    if (vfunc_o10_21(picked[j], 0, 1) == 0)
                        return 0;
                }
            }
        }
    }
    if (req.m_achievement != 0)
    {
        if (req.m_achievementGrade == 0)
        {
            if (vfunc_o10_1(req.m_achievement) == 0)
                return 0;
        }
        else if (vfunc_o10_0(req.m_achievement, req.m_achievementGrade) == 0)
            return 0;
    }
    if (req.m_unreqAchievement != 0 && req.m_unreqAchievementGrade != 0)
    {
        if (vfunc_o10_0(req.m_unreqAchievement, req.m_unreqAchievementGrade) != 0)
            return 0;
    }
    if (req.m_guildLevel != -1)
    {
        if (req.m_guildLevel == 0)
        {
            if (vfunc_o10_9() != 0)
                return 0;
        }
        else
        {
            if (vfunc_o10_9() == 0)
                return 0;
            int nGuildExp = vfunc_o10_10();
            if ((int)FUN_1404f4530()->FUN_1404d7130(nGuildExp) < req.m_guildLevel)
                return 0;
        }
    }
    if (req.m_guildNpcLevel != 0)
    {
        if (vfunc_o10_9() == 0)
            return 0;
        if ((unsigned short)vfunc_o10_11() != req.m_guildNpcLevel)
            return 0;
    }
    if (req.m_alliance != 0 && req.m_fameGrade != 0)
    {
        if (vfunc_o10_13(req.m_alliance) < req.m_fameGrade)
            return 0;
    }
    if (req.m_masteryType != 0 && req.m_masteryGrade != 0)
    {
        if (vfunc_o10_14(req.m_masteryType) < req.m_masteryGrade)
            return 0;
    }
    if (req.m_dungeon != 0 && vfunc_o10_15(req.m_dungeon) < 1)
        return 0;
    if (req.m_unrequireDungeon != 0 && vfunc_o10_15(req.m_unrequireDungeon) != 0)
        return 0;
    if (req.m_enterDungeon != 0 && vfunc_o10_16(req.m_enterDungeon) > 9)
        return 0;
    if (req.m_dungeonBeginner.GetCount() != 0)
    {
        int bAny = 0;
        for (size_t i = 0; i < req.m_dungeonBeginner.GetCount(); ++i)
        {
            if (vfunc_o10_17(req.m_dungeonBeginner[i]) == 0)
            {
                bAny = 1;
                break;
            }
        }
        if (bAny == 0)
            return 0;
    }
    if (req.m_mentor == 0 || vfunc_o10_18() == 5)
    {
        if (req.m_mentee == 0 || vfunc_o10_18() == 2)
        {
            if (req.m_vip == 0 || vfunc_o10_19() != 0)
            {
                if (req.m_equipment.GetCount() != 0 && vfunc_o10_20(req.m_equipment) == 0)
                    return 0;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140745820, CQuestManagerCommon, FUN_140745820, 4129, 0xBBD4D435);

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140746850
int CQuestManagerCommon::FUN_140746850(int questId, int npcId, int bStart)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 0;
    if (quest->FUN_1407447c0() != 0)
        return 0;
    if (quest->FUN_1407476d0() != 1)
        return 0;
    if (bStart == 0)
    {
        if (quest->IsComplete() != 0)
            return 0;
        if (quest->GetData()->m_2ec != npcId)
            return 0;
    }
    else if (quest->GetData()->m_2e8 != npcId)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140746850, CQuestManagerCommon, FUN_140746850, 827, 0xB2C4964A);

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140746ba0
int CQuestManagerCommon::FUN_140746ba0(int questId, int npcId, int bSkip)
{
    bool bHaveData = false;
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest.IsNull())
        return 6;
    if (bSkip == 0 && quest->FUN_1407447c0() != 0)
        return 4;
    if (quest->GetData().operator==(0))
        return 6;
    if (bSkip == 0 && quest->FUN_1407476d0() != 1)
        return 6;
    int bWrongNpc = 0;
    if (bSkip == 0 && npcId != 0)
    {
        MS2Ptr<CQuestData> data = quest->GetData();
        bHaveData = true;
        if (data->m_2ec != npcId)
            bWrongNpc = 1;
    }
    (void)bHaveData;
    if (bWrongNpc)
        return 6;
    if (bSkip == 0 && FUN_1407456d0(questId) == 0)
        return 6;
    return 0;
}
MS2_REPLACE_METHOD(0x140746BA0, CQuestManagerCommon, FUN_140746ba0, 694, 0x244F7842);

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x140746e60
int CQuestManagerCommon::FUN_140746e60(int questId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (data.operator==(0))
        return 0;
    if (!data->m_2d)
        return 0;
    int nType = FUN_14074b050(data.operator->());
    if (nType == 3)
        return FUN_140747400(questId, data->m_338.m_value);
    if (nType == 5)
        return FUN_140747440(questId, data->m_350);
    if (nType == 8 || nType == 10)
        return 0;
    return FUN_140747350(questId);
}
MS2_REPLACE_METHOD(0x140746E60, CQuestManagerCommon, FUN_140746e60, 358, 0xB747E45D);

// @0x140746fe0
void FUN_140746fe0(CQuestManagerCommon* pMgr, int nSelector)
{
    pMgr->m_selector = nSelector;
}

// @0x140747000
int CQuestManagerCommon::FUN_140747000(int questId)
{
    MS2Ptr<CQuestData> data = FUN_14074bc40(questId);
    if (!data)
        return 0;
    int nSeed = 0;
    switch (QuestDataTable::GetInstance()->FUN_14074e390(data->m_require.m_groupId))
    {
    case 0:
        nSeed = 0;
        break;
    case 1:
        nSeed = (int)((unsigned __int64)vfunc_o10_22() >> 32);
        break;
    case 2:
        nSeed = 0;
        break;
    }
    return nSeed;
}

// MS2-FUNCTIONAL: statement order and result temporaries differ from the exe.
// @0x1407470f0
unsigned CQuestManagerCommon::vfunc_o10_23(const Unk_QuestCondition& condition)
{
    Unk_QuestCondition& cond = const_cast<Unk_QuestCondition&>(condition);
    if (cond.FUN_140266970() == 0)
        return 1;
    for (unsigned __int64 i = 0; i < FUN_1402815b0(&cond.m_list); ++i)
    {
        Unk_PayloadPtr<CQuest> questA = vfunc_o10_3(FUN_14027f040(&cond.m_list, i)->m_questA);
        Unk_PayloadPtr<CQuest> questB = vfunc_o10_3(FUN_14027f040(&cond.m_list, i)->m_questB);
        int nA = FUN_140764480(questA, FUN_14027f040(&cond.m_list, i)->m_stateA);
        int nB = FUN_140764480(questB, FUN_14027f040(&cond.m_list, i)->m_stateB);
        if (nA == 2)
            continue;
        if (nB != 1)
            return cond.m_result;
    }
    return cond.m_result == 0;
}
MS2_REPLACE_METHOD(0x1407470F0, CQuestManagerCommon, vfunc_o10_23, 584, 0xAEEEA57A);

// @0x140747350
bool CQuestManagerCommon::FUN_140747350(int questId)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(questId);
    if (quest == 0)
        return true;
    if (quest->FUN_1407476d0() == 0)
        return true;
    return false;
}

// @0x140747400
bool CQuestManagerCommon::FUN_140747400(int questId, int nKind)
{
    if (nKind != 1)
        return false;
    return FUN_140747350(questId);
}

// @0x140747440
bool CQuestManagerCommon::FUN_140747440(int, int)
{
    return true;
}

// @0x140747460
int FUN_140747460(const ATL::CAtlArray<int>* pArr, const int* pValue)
{
    for (int i = 0; i < (int)pArr->GetCount(); ++i)
    {
        if ((*pArr)[i] == *pValue)
            return i;
    }
    return -1;
}

// @0x1407474d0
int FUN_1407474d0(const ATL::CAtlArray<int>* pArr, const int* pValue)
{
    for (int i = 0; i < (int)pArr->GetCount(); ++i)
    {
        if ((*pArr)[i] == *pValue)
            return i;
    }
    return -1;
}

// @0x1407476d0
int CQuest::FUN_1407476d0() const
{
    return m_state;
}
