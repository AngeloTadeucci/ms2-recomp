// ms2actormanager.h - MS2ActorManager: Nexon's NiActorManager subclass (sizeof 0x158, no members of its own).
// Owning unit: ?\ms2actormanager.cpp (0x140d81400-0x140d86270 .text$mn, 0x1400d39e0-0x1400d3aa0 .text$di).
//
// The exe-layout NiActorManager itself is the engine header (engine/gamebryo/.../NiAnimation/NiActorManager.h,
// `// MS2:` edits): NiDeclareRTTI (slot 2), virtual Clone / Update / CloneOnlyAnimation(NiAVObject*, bool)
// (slots 3-5), m_kMS2PendingSeqDataMap at +0x100 (SDK tail shifted by 0x20), sizeof 0x158, and the MS2
// SetTargetAnimation(SequenceID, float, bool) inline (exe 0x1409a20a0). Use NiActorManager directly for actor managers;
// this header adds the subclass and pins the shared layout (it is included by ?\animationmanager.cpp so progress.py
// compiles the checks).
//
// Proof:
// - vftable 0x142e32278 (RTTI MS2ActorManager), 6 slots: 0 ??_G 0x140d83f60 (dtor 0x140d81400, frees 0x158),
//   1 NiRefObject::DeleteThis 0x141d16bf0, 2 GetRTTI 0x140d850f0 (-> ms_RTTI 0x143ac2fc0), 3 Clone 0x140d81930,
//   4 NiActorManager::Update 0x141c45340 (inherited), 5 CloneOnlyAnimation 0x140d81d00 (rcx, rdx, r8b).
//   Secondary vftables: 0x142e322b0 (+0x10 ActivationCallback: dtor thunk 0x140d8397c, inherited ActivationChanged
//   0x141c3e780) and 0x142e322c8 (+0x18 TextKeyCallback: dtor thunk 0x140d83988, inherited TextKeyEvent 0x141c44bd0).
// - ctor 0x140d82310 = NiActorManager ctor 0x141c3d300 + the three vftable stores; dtor 0x140d81400 = vftable stores
//   + ~NiActorManager 0x141c3d920 (no own members). All three `new` sites (0x140d816b0, 0x140d81aa0, 0x140d81eb0)
//   allocate 0x158 = sizeof(NiActorManager) in the exe.
// - .text$di 0x1400d39e0: NiRTTI(&ms_RTTI 0x143ac2fc0, "MS2ActorManager", &NiActorManager::ms_RTTI 0x143af8988)
//   = NiImplementRTTI(MS2ActorManager, NiActorManager).
// Engine symbols the subclass needs (progress/symbols-manual.tsv; none are FID-named): ??0NiActorManager 0x141c3d300,
// ??1NiActorManager 0x141c3d920, Clone 0x141c3f950, CloneOnlyAnimation(.., bool) 0x141c3ff70, Update 0x141c45340,
// NiActorManager::ms_RTTI 0x143af8988, NiControllerManager::AddSequenceData 0x141c39310.
#pragma once
#include "ms2/ms2layout.h"
#include <NiActorManager.h>

class MS2ActorManager : public NiActorManager
{
    NiDeclareRTTI;                                                          // slot 2 0x140d850f0, ms_RTTI 0x143ac2fc0
public:
    MS2ActorManager(NiKFMTool* pkKFMTool, bool bCumulativeAnimations);     // 0x140d82310
    virtual ~MS2ActorManager();                                             // 0x140d81400, ??_G 0x140d83f60

    virtual NiActorManager* Clone(NiCloningProcess* pkCloningProcess = NULL);                  // slot 3 0x140d81930
    virtual NiActorManager* CloneOnlyAnimation(NiAVObject* pkAVObject, bool bCumulativeAnimation); // slot 5 0x140d81d00
    using NiActorManager::CloneOnlyAnimation;                               // keep the non-virtual (NiAVObject*) one

    MS2_LAYOUT_FRIEND;
};

// The exe NiActorManager layout (engine header with the MS2 edits), pinned through the subclass.
MS2_CHECK_SIZE(NiActorManager, 0x158);
MS2_CHECK_SIZE(MS2ActorManager, 0x158);
MS2_CHECK_OFFSET(MS2ActorManager, m_spKFMTool, 0x20);
MS2_CHECK_OFFSET(MS2ActorManager, m_spManager, 0x30);
MS2_CHECK_OFFSET(MS2ActorManager, m_eTargetID, 0x40);
MS2_CHECK_OFFSET(MS2ActorManager, m_kChainIDs, 0x98);
MS2_CHECK_OFFSET(MS2ActorManager, m_kChainDurations, 0xb8);
MS2_CHECK_OFFSET(MS2ActorManager, m_bChainActive, 0xd8);
MS2_CHECK_OFFSET(MS2ActorManager, m_bCumulativeAnimationsRequested, 0xd9);
MS2_CHECK_OFFSET(MS2ActorManager, m_kSeqDataMap, 0xe0);
MS2_CHECK_OFFSET(MS2ActorManager, m_kMS2PendingSeqDataMap, 0x100);
MS2_CHECK_OFFSET(MS2ActorManager, m_kCallbacks, 0x120);
MS2_CHECK_OFFSET(MS2ActorManager, m_kExtraSequenceMap, 0x138);
