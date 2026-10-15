// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See multisceneupdater.h.
// MS2-UNIT: client\ms2\multisceneupdater.cpp
// MS2-RANGE: 0x140d9e530-0x140d9ee70 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\multisceneupdater.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "multisceneupdater.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140d9e530
UpdateSceneTProc::UpdateSceneTProc()
    : m_nFirst(0), m_nCount(0), m_eOrder(6), m_kWorkflow(0x40, NiStreamProcessor::MEDIUM, 3), m_kProcess(&m_kWorkflow)
{
    m_kProcess.SetSubmitModifiers(true);
    m_kProcess.SetUpdateControllers(true);
}

// @0x140d9e600
UpdateSceneTProc::~UpdateSceneTProc()
{
}

// @0x140d9e650
bool UpdateSceneTProc::LoopedProcedure(efd::Thread*)
{
    // ASSERT(eOrder != eSU_Max) with the enum names the original expression used
    (void)((m_eOrder != 6) || (_wassert(L"eOrder != eSU_Max", _CRT_WIDE(MS2_THIS_FILE), 0x1d), 0));
    m_kProcess.SetTime(MultiSceneUpdater::s_fTime);
    if (MultiSceneUpdater::s_pfnCallback != NULL && MultiSceneUpdater::s_pCallbackContext != NULL)
        MultiSceneUpdater::s_pfnCallback(MultiSceneUpdater::s_pCallbackContext, m_eOrder, m_nFirst, m_nCount,
                                         &m_kProcess);
    m_kProcess.Flush();
    return true;
}

MS2_REPLACE_METHOD(0x140d9e650, UpdateSceneTProc, LoopedProcedure, 175, 0xDA43D3CA);

// @0x140d9e710
MultiSceneUpdater::MultiSceneUpdater()
{
    m_pProcs = NULL;
    m_ppThreads = NULL;
    m_nThreads = 0;
}

// @0x140d9e770
MultiSceneUpdater::~MultiSceneUpdater()
{
    Destroy();
}

// @0x140d9e7c0
void MultiSceneUpdater::Create(unsigned int nThreads)
{
    m_nThreads = nThreads;
    if (nThreads != 0)
    {
        m_pProcs = EE_NEW UpdateSceneTProc[nThreads];
        m_ppThreads = new efd::LoopedThread*[nThreads];
        for (unsigned int i = 0; i < nThreads; i++)
        {
            char szName[64];
            efd::Sprintf(szName, 64, "UpdateThread%u", i + 1);
            m_ppThreads[i] = efd::LoopedThread::Create(&m_pProcs[i], 0xffffffff, szName);
            m_ppThreads[i]->SetPriority((efd::Thread::Priority)5);
            m_ppThreads[i]->Resume();
        }
    }
}

MS2_REPLACE_METHOD(0x140d9e7c0, MultiSceneUpdater, Create, 599, 0x62F3E7A6);

// @0x140d9ea20
void MultiSceneUpdater::Destroy()
{
    if (m_ppThreads != NULL)
    {
        for (unsigned int i = 0; i < m_nThreads; i++)
            delete m_ppThreads[i];
        delete m_ppThreads;
        m_ppThreads = NULL;
    }
    if (m_pProcs != NULL)
    {
        delete[] m_pProcs;
        m_pProcs = NULL;
    }
}
MS2_REPLACE_METHOD(0x140d9ea20, MultiSceneUpdater, Destroy, 365, 0xEE22EFAC);
