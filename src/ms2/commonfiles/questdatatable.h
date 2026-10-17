// questdatatable.h - QuestDataTable (RTTI name): the quest table read from Table/QuestData.xml; one CQuestData row per
// quest id plus the lookup indices built while loading. Header name assumed. Member names are invented from use.
// Singleton instance: DAT_143ab0c70 (FUN_1407476c0).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/questdata.h"

class QuestDataTable : public TSingleton<QuestDataTable>, public CValidData<QuestDataTable>
{
public:
    QuestDataTable();                                       // 0x14074bd90
    virtual ~QuestDataTable();                              // 0x14074c130

    // queries used by CQuestManagerCommon (questdata.cpp)
    int FUN_14074e390(int nGroupId);                        // the group's pick kind (0 none, 1 per-selector, 2 per-day)
    void FUN_14074e6c0(int nGroupId, int nSelector, int nSeed, ATL::CAtlArray<unsigned>& out);   // the group's quest pick
    int FUN_14074e450(int nGroupId);                        // how many quests a group hands out (1 when unknown)

    char m_pad[0x440 - 0x10];
};
