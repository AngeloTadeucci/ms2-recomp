// csoapclient.h - PLACEHOLDER for CSoapClient (RTTI .?AVCSoapClient@@, 0xa0 bytes). NOT an original header.
// Bases: TSingleton<CSoapClient> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Members proved from the ctor 0x14176fbb0 / dtor
// 0x14176fc60 (array, lock, list, two strings, mode). Owner: sh1 (shared layout).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class CUgcUploadCtrl;
class CGameRankingParam;
class CGameRankingWebResult;

class CSoapClient : public TSingleton<CSoapClient>
{
public:
    CSoapClient();                                          // 0x14176fbb0
    virtual ~CSoapClient();
    MS2Ptr<CGameRankingWebResult> FUN_141770670(MS2Ptr<CGameRankingParam> spParam);   // the game ranking request
private:
    MS2_LAYOUT_FRIEND;
    typedef MS2Ptr<CUgcUploadCtrl> UploadPtr;               // 16 bytes (0x140c39310 copy, 0x140c394b0 dtor)
    ATL::CAtlArray<UploadPtr> m_uploads;                    // +0x08 (0x20): the file nodes of an upload (calloc'd, 0x10 per element)
    CLockCriticalSection m_lock;                            // +0x28 (0x30)
    ATL::CAtlList<UploadPtr> m_queue;                       // +0x58 (0x30): block size 10 (0x141772580)
    CString m_strError;                                     // +0x88: last "[E] soap" message (0x14176fe30)
    CString m_strPath;                                      // +0x90: service path, set with the mode (0x14176fcf0)
    int m_nMode;                                            // +0x98: 1 = plain, 2 = soap (0x14176fcf0)
};
MS2_CHECK_SIZE(CSoapClient, 0xa0);
