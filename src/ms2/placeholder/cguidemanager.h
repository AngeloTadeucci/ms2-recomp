// cguidemanager.h - PLACEHOLDER for CGuideManager (RTTI .?AVCGuideManager@@, 0x1d0 bytes). NOT an original header.
// Bases: TSingleton<CGuideManager> at +0x0, UIItemEventListener at +0x8, UIUGCEventListener at +0x10, UIStatusEventListener at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Members proven from the ctor 0x14138a4d0 / dtor 0x14138ab80
// and the std/ATL glue of client\ms2\guideentity.cpp (the max_size constants and node sizes pick the element types).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/guideoccurcontainer.h"

#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>

class CGuideEntity;
class NotifyObject;
class GuideTriggerEventGroup;

class CGuideManager : public TSingleton<CGuideManager>,
                      public UIItemEventListener,
                      public UIUGCEventListener,
                      public UIStatusEventListener
{
public:
    enum Occurrence { OccurrenceNone = 0 };                 // the guide event kinds (key of m_byOccur, element of the sets)
    enum TriggerType { TriggerNone = 0 };                   // key of m_triggers

    CGuideManager();                                        // 0x14138a4d0
    virtual ~CGuideManager();

    // The notify callbacks the ctor registers (names invented).
    void OnLearnEmotion(NotifyObject* pNotify);             // 0x14138eb90 NotifyLearnEmotion
    void OnUseSkill(NotifyObject* pNotify);                 // 0x14138ebd0 NotifyUseSKill
    void OnChangeMyLevel(NotifyObject* pNotify);            // 0x14138ec10 NotifyChangeMyLevel
    void OnDungeonEnterState(NotifyObject* pNotify);        // 0x14138ec40 NotifyDungeonEnterState

    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_nDebug;                                           // +0x28: nonzero logs every trigger
    char m_pad_2c;                                          // +0x2c
    char m_bitset2d[3];                                     // +0x2d (a 1-byte bitset initialised by 0x1402e49d0)
    ATL::CRBMap<int, MS2Ptr<CGuideEntity> > m_entities;     // +0x30 guide id -> entity
    ATL::CRBMap<int, int> m_map60;                          // +0x60
    ATL::CRBMap<int, int> m_map90;                          // +0x90
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_caches;           // +0xc0 the loaded guide xml files
    ATL::CAtlMap<TriggerType, MS2Ptr<GuideTriggerEventGroup> > m_triggers;   // +0xe0
    ATL::CAtlArray<CStringW> m_names;                       // +0x128
    std::set<Occurrence> m_setPending;                      // +0x148 occurrences raised since the last update
    std::set<Occurrence> m_setPlain;                        // +0x158 raised without a sub value
    std::set<Occurrence> m_setIndexed;                      // +0x168 occurrences with a sub-value index
    std::vector<std::pair<Occurrence, int> > m_vecSub;      // +0x178 raised (occurrence, sub value) pairs
    std::map<Occurrence, GuideOccurContainer> m_byOccur;    // +0x190
    std::set<int> m_setQueued;                              // +0x1a0 ids of the queued entities
    std::list<MS2Ptr<CGuideEntity> > m_listQueued;          // +0x1b0
    std::map<CStringA, int> m_mapNames;                     // +0x1c0 interned occurrence names
};
MS2_CHECK_SIZE(CGuideManager, 0x1d0);
MS2_CHECK_OFFSET(CGuideManager, m_entities, 0x30);
MS2_CHECK_OFFSET(CGuideManager, m_n20, 0x20);
MS2_CHECK_OFFSET(CGuideManager, m_nDebug, 0x28);
MS2_CHECK_OFFSET(CGuideManager, m_bitset2d, 0x2d);
MS2_CHECK_OFFSET(CGuideManager, m_map60, 0x60);
MS2_CHECK_OFFSET(CGuideManager, m_map90, 0x90);
MS2_CHECK_OFFSET(CGuideManager, m_caches, 0xc0);
MS2_CHECK_OFFSET(CGuideManager, m_triggers, 0xe0);
MS2_CHECK_OFFSET(CGuideManager, m_names, 0x128);
MS2_CHECK_OFFSET(CGuideManager, m_setPending, 0x148);
MS2_CHECK_OFFSET(CGuideManager, m_setPlain, 0x158);
MS2_CHECK_OFFSET(CGuideManager, m_setIndexed, 0x168);
MS2_CHECK_OFFSET(CGuideManager, m_vecSub, 0x178);
MS2_CHECK_OFFSET(CGuideManager, m_byOccur, 0x190);
MS2_CHECK_OFFSET(CGuideManager, m_setQueued, 0x1a0);
MS2_CHECK_OFFSET(CGuideManager, m_listQueued, 0x1b0);
MS2_CHECK_OFFSET(CGuideManager, m_mapNames, 0x1c0);
