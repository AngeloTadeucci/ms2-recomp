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
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/famealliance.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include <map>
#include <set>
#include <vector>

class QuestDataTable : public TSingleton<QuestDataTable>, public CValidData<QuestDataTable>
{
public:
    QuestDataTable();                                       // 0x14074bd90
    virtual ~QuestDataTable();                              // 0x14074c130

    // queries used by CQuestManagerCommon (questdata.cpp)
    int FUN_14074e390(int nGroupId);                        // the group's pick kind (0 none, 1 per-selector, 2 per-day)
    void FUN_14074e6c0(int nGroupId, int nSelector, int nSeed, ATL::CAtlArray<unsigned>& out);   // the group's quest pick
    int FUN_14074e450(int nGroupId);                        // how many quests a group hands out (1 when unknown)

    MS2Ptr<CQuestData> FUN_14074c9d0(int nQuestId);                         // by id (null when missing)

    typedef Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > IdsPtr;

    CLockCriticalSection m_lock;                                            // +0x10
    std::map<int, MS2Ptr<CQuestData> > m_quests;                            // +0x40 by quest id
    ATL::CAtlMap<int, IdsPtr> m_chapter;                                    // +0x50 chapter -> quest ids
    ATL::CAtlMap<int, int> m_98;                                            // +0x98 chapter -> value
    ATL::CAtlMap<int, int> m_e0;                                            // +0xe0 chapter -> value
    ATL::CAtlArray<unsigned> m_128;                                         // +0x128 auto-start quests
    ATL::CAtlMap<unsigned, IdsPtr> m_148[2];                                // +0x148 item id -> quest ids (0 accept, 1 complete)
    ATL::CAtlArray<unsigned> m_1d8;                                         // +0x1d8
    ATL::CAtlMap<unsigned, IdsPtr> m_1f8;                                   // +0x1f8
    ATL::CAtlMap<unsigned, IdsPtr> m_240;                                   // +0x240
    ATL::CAtlMap<unsigned, unsigned> m_288;                                 // +0x288
    ATL::CAtlMap<int, int> m_2d0;                                           // +0x2d0 quest id -> 0/1 (finished-dependency cache)
    ATL::CAtlMap<Unk_FameAlliance, IdsPtr> m_318;                           // +0x318 alliance -> quest ids
    std::vector<unsigned> m_360;                                            // +0x360
    std::vector<MS2Ptr<CQuestData> > m_378;                                 // +0x378 sorted by level
    ATL::CAtlMap<int, IdsPtr> m_390;                                        // +0x390 group id -> quest ids
    ATL::CAtlMap<int, Unk_SocketPtr<CQuestData::GroupPickData> > m_3d8;     // +0x3d8 group id -> pick data
    std::map<int, int> m_420;                                               // +0x420
    std::map<int, std::set<unsigned> > m_430;                               // +0x430 npc id -> quest ids
};
MS2_CHECK_SIZE(QuestDataTable, 0x440);
