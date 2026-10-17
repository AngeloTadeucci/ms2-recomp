// cugcdownloaddown.h - PLACEHOLDER for CUgcDownloadDown (RTTI .?AVCUgcDownloadDown@@, 0xf8 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CUgcDownloadDown> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Recovered in client\ms2\ugcmanager.cpp#2
// (src/ms2/client/ms2/ugcmanager_2.cpp): Push files one CUgcDownloadCtrl per URL (later requests for the same URL only
// add their proxy); the worker thread starts up to 10 downloads at a time and Finish (called by the download thread
// or by CUgcDownloadLoad once the file is loaded) hands the result to CUgcManager.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cthread.h"

class CUgcDownloadCtrl;
class CUgcDownloadParam;
class IUgcProxy;

class CUgcDownloadDown : public CThread, public TSingleton<CUgcDownloadDown>
{
public:
    typedef CRBMap<CString, MS2Ptr<CUgcDownloadCtrl>, CStringElementTraitsI<CString> > CCtrlMap;

    CUgcDownloadDown();                                     // 0x141874a40
    virtual ~CUgcDownloadDown();                            // 0x141874b40
    virtual unsigned int vfunc_1(void* pParam, Unk_140659080& start);   // 0x141874c20 the worker
    void Stop();                                            // 0x141875140
    int Push(CUgcDownloadParam* pParam, IUgcProxy* pProxy); // 0x141875210
    void Finish(CString strName, int nResult);              // 0x1418760a0 0 ok, 0x1f download failed, 0x20 load failed
    int IsIdle();                                           // 0x141876290 no download thread is running
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x20
    CCtrlMap m_mapWait;                                     // +0x50 queued, not started
    CCtrlMap m_mapActive;                                   // +0x80 started
    CCtrlMap m_mapAll;                                      // +0xb0 every unfinished download
    HANDLE m_hEvent;                                        // +0xe0
    HANDLE m_hSemaphore;                                    // +0xe8 one count per queued download
    int m_bStop;                                            // +0xf0
};
MS2_CHECK_SIZE(CUgcDownloadDown, 0xf8);
MS2_CHECK_OFFSET(CUgcDownloadDown, m_mapWait, 0x50);
MS2_CHECK_OFFSET(CUgcDownloadDown, m_hEvent, 0xe0);
