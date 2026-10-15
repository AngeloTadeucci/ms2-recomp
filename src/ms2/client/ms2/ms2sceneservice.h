// ms2sceneservice.h - MS2SceneService (vftable 0x142f26d80, IWorldServiceCallback sub-vftable 0x142f26e38 at +0x60):
// the game's egfPhysX::SceneService with per-step timing statistics, cached default/item scene pointers and the
// world-service start/stop callbacks that pause or resume those two scenes. Header name assumed.
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <egfPhysX/SceneService.h>
#include <efd/TimeType.h>
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/ms2layout.h"

class MS2SceneService : public egfPhysX::SceneService, public IWorldServiceCallback
{
public:
    MS2SceneService();                                              // 0x1415033a0
    virtual ~MS2SceneService();                                     // 0x141503470

    virtual efd::AsyncResult OnInit();                              // 0x1415034c0
    virtual void Simulate(const efd::Bool forceSim);                // 0x141503540
    virtual efd::AsyncResult OnShutdown();                          // 0x1415035e0
    virtual efd::Bool AddScene(const efd::utf8string& sceneName, egfPhysX::PhysXSceneData* pSceneData);   // 0x141503600
    virtual efd::Bool RemoveScene(const efd::utf8string& sceneName);                                      // 0x141503a70

    // IWorldServiceCallback slots 1 (resume) and 3 (pause): start/stop simulating the two cached scenes.
    virtual void vfunc_1(int);                                      // 0x141504280
    virtual void vfunc_3(int);                                      // 0x1415041b0

    NxScene* GetCachedNxScene(int index) const;                     // 0x141503cc0
    void PauseSessionScenes(unsigned session);                      // 0x141503d10
    void CacheNamedScenes();                                        // 0x141503ef0
    float TakeAverageSimulateTime();                                // 0x1415040f0
    void ResetSimulateStats();                                      // 0x141504180

protected:
    efd::StepHighPrecisionClock m_clock;                            // +0x68
    egfPhysX::PhysXSceneData* m_pScenes[2];                         // +0x80 (default scene, item scene)
    float m_simulateTotal;                                          // +0x90
    unsigned __int64 m_simulateCount;                               // +0x98
};
MS2_CHECK_SIZE(MS2SceneService, 0xa0);
