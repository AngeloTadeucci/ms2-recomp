// multisceneupdater.h - MultiSceneUpdater (RTTI .?AVMultiSceneUpdater@@): a pool of worker threads that each run an
// UpdateSceneTProc, which batch-updates scene graphs through a private NiBatchedUpdateProcess and then reports to a
// global callback. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `client\ms2\multisceneupdater.cpp` (0x140d9e530-0x140d9ee70, dir client\ms2). Header name assumed; member names are
// invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <efd/LoopedThreadProcedure.h>
#include <efd/LoopedThread.h>
#include <NiSPWorkflowManager.h>
#include <NiBatchedUpdateProcess.h>

// One worker's procedure: updates its share of the scene graphs in a loop (size 0x78).
class UpdateSceneTProc : public efd::LoopedThreadProcedure
{
public:
    UpdateSceneTProc();                                 // 0x140d9e530
    virtual ~UpdateSceneTProc();                        // 0x140d9ec30 (scalar/vector deleting)
    virtual bool LoopedProcedure(efd::Thread* pArg);    // 0x140d9e650

    unsigned int m_nFirst;                              // +0x08
    unsigned int m_nCount;                              // +0x0c
    int m_eOrder;                                       // +0x10, eSU_Max (6) until assigned
    NiSPWorkflowManager m_kWorkflow;                    // +0x18
    NiBatchedUpdateProcess m_kProcess;                  // +0x50
};
MS2_CHECK_SIZE(UpdateSceneTProc, 0x78);
MS2_CHECK_OFFSET(UpdateSceneTProc, m_eOrder, 0x10);
MS2_CHECK_OFFSET(UpdateSceneTProc, m_kWorkflow, 0x18);
MS2_CHECK_OFFSET(UpdateSceneTProc, m_kProcess, 0x50);

typedef void (*SceneUpdateCallback)(void* pContext, int eOrder, unsigned int nFirst, unsigned int nCount,
                                    NiBatchedUpdateProcess* pProcess);

class MultiSceneUpdater : public TSingleton<MultiSceneUpdater>
{
public:
    MultiSceneUpdater();                                // 0x140d9e710
    virtual ~MultiSceneUpdater();                       // 0x140d9e770

    void Create(unsigned int nThreads);                 // 0x140d9e7c0
    void Destroy();                                     // 0x140d9ea20

    static float s_fTime;                               // 0x143ac3d08
    static SceneUpdateCallback s_pfnCallback;           // 0x143ac3d10
    static void* s_pCallbackContext;                    // 0x143ac3d18

private:
    MS2_LAYOUT_FRIEND;
    UpdateSceneTProc* m_pProcs;                         // +0x08, array of m_nThreads (count stored in front)
    efd::LoopedThread** m_ppThreads;                    // +0x10
    unsigned int m_nThreads;                            // +0x18
};
MS2_CHECK_SIZE(MultiSceneUpdater, 0x20);
MS2_CHECK_OFFSET(MultiSceneUpdater, m_pProcs, 0x08);
MS2_CHECK_OFFSET(MultiSceneUpdater, m_ppThreads, 0x10);
MS2_CHECK_OFFSET(MultiSceneUpdater, m_nThreads, 0x18);
