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
    int m_48, m_4c, m_50, m_54;
    // Not instantiated on the stack; these unrecovered table subrecords are opaque.
    unsigned char m_58[0x240];
    ATL::CAtlArray<QuestRewardItem> m_choiceRewards;
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
MS2_CHECK_OFFSET(CQuestData, m_choiceRewards, 0x298);
MS2_CHECK_OFFSET(CQuestData, m_rewards, 0x2b8);
MS2_CHECK_OFFSET(CQuestData, m_acceptSound, 0x2d8);
MS2_CHECK_OFFSET(CQuestData, m_roomId, 0x310);
MS2_CHECK_OFFSET(CQuestData, m_conditions, 0x388);
