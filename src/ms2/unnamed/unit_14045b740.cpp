// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The second part of the COMDAT tail of
// commonfiles/gameeventvalue.cpp (sorted by mangled name, the non-template members `?_Buyheadnode` .. `?reserve`): the
// std::map / std::list / std::vector glue behind the event value classes (each one a lock plus the containers of the
// event's context objects). gameeventvalue.cpp's own bodies are not written yet, so the members are emitted through
// explicit instantiations; members the exe never kept stay unpaired.
// MS2-UNIT: unit_14045b740
// MS2-RANGE: 0x14045b740-0x14046c710 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <new>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/ms2recover.h"

// ---- the event value containers (key -> context) -------------------------------------------------------------------
// CGameEventValueManager::GetArcadeOpen(): arcade id (ArcadeOpenContext::m_arcadeId) -> context.
template class std::map<int, MS2Ptr<ArcadeOpenContext> >;
// GameEventUserValueNameTable and others: id -> id.
template class std::map<unsigned long, unsigned long>;
// GetBurningLevelup() / GetCollectItemGroup() / ItemBox(): event id -> context.
template class std::map<unsigned long, MS2Ptr<BurningLevelupContext> >;
template class std::map<unsigned long, MS2Ptr<CollectItemGroupContext> >;
template class std::map<unsigned long, MS2Ptr<EventShopNpcContext> >;
template class std::map<unsigned long, MS2Ptr<ItemBoxEventContext> >;
// The event shop NPC contexts grouped by EventShopNpcContext::Get20().
template class std::list<MS2Ptr<EventShopNpcContext> >;
template class std::map<unsigned long, std::list<MS2Ptr<EventShopNpcContext> > >;
// The limited quantity events: event id -> context, and the context's m_1c -> event id.
template class std::map<unsigned long, MS2Ptr<LimitedQuantityContext> >;
// CGameEventValueManager::MasteryReward(): event id -> ((value, fieldID) -> rate).
template class std::map<std::pair<int, unsigned long>, int>;
template class std::map<unsigned long, std::map<std::pair<int, unsigned long>, int> >;
// The dungeon buff events (DungeonBuffEventCtx, beginner / normal): dungeon id -> (effect GUID -> reference count).
template class std::map<unsigned __int64, unsigned>;
template class std::map<unsigned long, std::map<unsigned __int64, unsigned> >;
// The +0xc0 value of CGameEventValueManager: dungeon group type (1..14) -> two ints.
template class std::map<Unk_DungeonGroupType, std::pair<int, int> >;
// The GetAll outputs of the BurningLevelup / CollectItemGroup values.
template class std::vector<MS2Ptr<BurningLevelupContext> >;
template class std::vector<MS2Ptr<CollectItemGroupContext> >;
