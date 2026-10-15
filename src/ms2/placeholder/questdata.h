// CQuestData: heap-only quest table row. Names inferred from client quest use.
// Layout proved by ctor 0x140748cf0 and the 0x3f0 allocation in questdata.cpp.
#pragma once
#include <vector>
#include <atlcoll.h>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cconditioncommon.h"

class CQuestData : public CPtred
{
public:
    class QuestRewardItem : public CPtred
    {
    public:
        QuestRewardItem();
        virtual ~QuestRewardItem();
        int m_itemId, m_count, m_job;
    };
    CQuestData();
    virtual ~CQuestData();
    int m_id, m_type, m_20, m_level, m_28;
    unsigned char m_2c, m_2d, m_2e, m_2f, m_30, m_31, m_flag, m_33, m_34;
    int m_durationMinutes, m_resetType;
    CStringW m_schedule;
    // <require> block, CQuestData+0x58 (0x1f0). ctor 0x140747910, dtor 0x140758c80,
    // operator== 0x140747b10; XML loader in questdata.cpp. A = CAtlArray<unsigned>
    // (ctor 0x140181d30/dtor 0x140183460), B = CAtlArray<int> (0x140181cf0/0x140183420).
    struct Require
    {
        Require();
        ~Require();
        short m_level;                      // +0x00 (+0x58)
        short m_maxLevel;                   // +0x02
        unsigned m_achievement;             // +0x04
        int m_achievementGrade;             // +0x08
        int m_unreqAchievement;             // +0x0c "unreqAchievement" id,grade pair
        int m_unreqAchievementGrade;        // +0x10
        int m_groupId;                      // +0x14
        unsigned m_gearScore;               // +0x18
        int m_guildLevel;                   // +0x1c ctor -1
        short m_guildNpcLevel;              // +0x20
        unsigned m_dungeon;                 // +0x24
        unsigned m_unrequireDungeon;        // +0x28
        unsigned m_enterDungeon;            // +0x2c
        ATL::CAtlArray<unsigned> m_dungeonBeginner;   // +0x30 (+0x88)
        int m_mentor;                       // +0x50 (+0xa8)
        int m_mentee;                       // +0x54
        int m_vip;                          // +0x58
        int m_alliance;                     // +0x5c reader 0x14035bc20
        int m_fameGrade;                    // +0x60
        int m_masteryType;                  // +0x64 enum, reader 0x14051fd20
        int m_masteryGrade;                 // +0x68
        ATL::CAtlArray<int> m_job;          // +0x70 (+0xc8)
        ATL::CAtlArray<int> m_subJob;       // +0x90
        ATL::CAtlArray<unsigned> m_quest;   // +0xb0 (+0x108)
        ATL::CAtlArray<unsigned> m_selectableQuest;   // +0xd0
        ATL::CAtlArray<unsigned> m_unrequire;         // +0xf0
        ATL::CAtlArray<unsigned> m_progressQuest;     // +0x110
        ATL::CAtlArray<int> m_unrequireGroup;         // +0x130
        ATL::CAtlArray<unsigned> m_equipment;         // +0x150 (+0x1a8)
        ATL::CAtlArray<int> m_dayOfWeek;              // +0x170
        ATL::CAtlArray<unsigned> m_followingQuests;   // +0x190 reverse links, filled after load
        ATL::CAtlArray<unsigned> m_requiredBy;        // +0x1b0 quests listing this in "quest"
        ATL::CAtlArray<unsigned> m_selectableBy;      // +0x1d0 quests listing this in "selectableQuest"
    };
    // <completeReward> block, CQuestData+0x248 (0x70). ctor 0x140748100, dtor 0x140758d90,
    // compare 0x140748210. Reward item array ctor 0x140757730, dtor 0x140758680.
    struct CompleteReward
    {
        CompleteReward();
        ~CompleteReward();
        int m_money;                        // +0x00 (+0x248)
        int m_karma;                        // +0x04
        int m_lu;                           // +0x08
        int m_exp;                          // +0x0c
        int m_guildFund;                    // +0x10
        int m_guildExp;                     // +0x14
        int m_guildCoin;                    // +0x18
        int m_menteeCoin;                   // +0x1c
        int m_missionPoint;                 // +0x20
        int m_useMainFamePoint;             // +0x24
        unsigned m_fameLog;                 // +0x28
        __int64 m_weddingExp;               // +0x30 (+0x278) reader 0x1408732e0
        float m_38;                         // +0x38 ctor 1.0f
        int m_relativeExp;                  // +0x3c ctor -1, reader 0x140354050
        float m_40;                         // +0x40 ctor 1.0f
        int m_relativeMeso;                 // +0x44 reader 0x140752270
        int m_rewardExpExtra;               // +0x48
        ATL::CAtlArray<QuestRewardItem> m_choiceRewards;   // +0x50 (+0x298)
    };
    int m_48, m_4c, m_50, m_54;
    Require m_require;
    CompleteReward m_complete;
    std::vector<QuestRewardItem> m_rewards;
    void* m_2d0;
    CString m_acceptSound, m_rewardSound;
    int m_2e8, m_2ec;
    void* m_2f0; void* m_2f8;
    int m_300, m_304, m_308, m_30c;
    int m_roomId, m_fieldId;
    unsigned char m_318[0x50];
    ATL::CAtlArray<int> m_fields;
    ATL::CAtlArray<MS2Ptr<CConditionCommonData>> m_conditions;
    unsigned char m_3a8[0x48];
};
MS2_CHECK_SIZE(CQuestData::QuestRewardItem, 0x28);
MS2_CHECK_SIZE(CQuestData, 0x3f0);
MS2_CHECK_OFFSET(CQuestData, m_flag, 0x32);
MS2_CHECK_SIZE(CQuestData::Require, 0x1f0);
MS2_CHECK_OFFSET(CQuestData::Require, m_guildNpcLevel, 0x20);
MS2_CHECK_OFFSET(CQuestData::Require, m_dungeonBeginner, 0x30);
MS2_CHECK_OFFSET(CQuestData::Require, m_mentor, 0x50);
MS2_CHECK_OFFSET(CQuestData::Require, m_job, 0x70);
MS2_CHECK_OFFSET(CQuestData::Require, m_equipment, 0x150);
MS2_CHECK_OFFSET(CQuestData::Require, m_selectableBy, 0x1d0);
MS2_CHECK_SIZE(CQuestData::CompleteReward, 0x70);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_fameLog, 0x28);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_weddingExp, 0x30);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_rewardExpExtra, 0x48);
MS2_CHECK_OFFSET(CQuestData::CompleteReward, m_choiceRewards, 0x50);
MS2_CHECK_OFFSET(CQuestData, m_require, 0x58);
MS2_CHECK_OFFSET(CQuestData, m_complete, 0x248);
MS2_CHECK_OFFSET(CQuestData, m_rewards, 0x2b8);
MS2_CHECK_OFFSET(CQuestData, m_acceptSound, 0x2d8);
MS2_CHECK_OFFSET(CQuestData, m_roomId, 0x310);
MS2_CHECK_OFFSET(CQuestData, m_conditions, 0x388);
