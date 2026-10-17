// cugcdownloadload.h - PLACEHOLDER for CUgcDownloadLoad (RTTI .?AVCUgcDownloadLoad@@, 0x98 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CUgcDownloadLoad> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. The worker thread turns downloaded UGC files (.m2u
// zlib packages or plain images) into textures for the scene-graph texture cache and reports each file back to
// CUgcDownloadDown. Recovered in client\ms2\ugcmanager.cpp#1 (src/ms2/client/ms2/ugcmanager_1.cpp).
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cthread.h"

class CUgcDownloadLoad : public CThread, public TSingleton<CUgcDownloadLoad>
{
public:
    // One downloaded file waiting to be loaded (RTTI .?AVCUgcLoadData@CUgcDownloadLoad@@, 0x38 bytes).
    class CUgcLoadData : public CPtred
    {
    public:
        CUgcLoadData();                                     // 0x14186e3f0
        CString m_strName;                                  // +0x18 the UGC file name reported back
        CString m_strPath;                                  // +0x20 the downloaded file
        int m_bPackage;                                     // +0x28 the name contains ".m2u"
        unsigned __int64 m_userData;                        // +0x30
    };

    CUgcDownloadLoad();                                     // 0x14186d1c0
    virtual ~CUgcDownloadLoad();
    virtual unsigned int vfunc_1(void* pParam, Unk_140659080& start);
    void Stop();                                            // 0x14186df80
    void Push(CString strName, CString strPath, int nType, unsigned __int64 userData);
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x20
    CAtlList<MS2Ptr<CUgcLoadData> > m_list;                 // +0x50
    HANDLE m_hEvent;                                        // +0x80
    HANDLE m_hSemaphore;                                    // +0x88 one count per queued file
    int m_bStop;                                            // +0x90
};
MS2_CHECK_SIZE(CUgcDownloadLoad::CUgcLoadData, 0x38);
MS2_CHECK_SIZE(CUgcDownloadLoad, 0x98);
MS2_CHECK_OFFSET(CUgcDownloadLoad, m_list, 0x50);
MS2_CHECK_OFFSET(CUgcDownloadLoad, m_bStop, 0x90);
