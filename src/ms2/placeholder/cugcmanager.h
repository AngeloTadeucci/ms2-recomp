// cugcmanager.h - PLACEHOLDER for CUgcManager (RTTI .?AVCUgcManager@@, 0x1c0 bytes). NOT an original header.
// Bases: TSingleton<CUgcManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates (client\ms2\ugcmanager.cpp#4); the members are not
// recovered yet. The methods are the ones the download code (ugcmanager.cpp#2) calls.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"

class CUgcDownloadCtrl;
class CUgcItemCube;
class CUgcItemRidee;
class CUgcRegistBanner;

class CUgcManager : public TSingleton<CUgcManager>
{
public:
    CUgcManager();                                          // 0x14187ed30
    virtual ~CUgcManager();
    void FUN_141886190(CString strName, MS2Ptr<CUgcDownloadCtrl> spCtrl, int nResult);   // a download finished
    void FUN_141886cc0(CUgcItemCube* pItem, CString strPath, unsigned __int64 uid);        // a cube image not placed yet
    void FUN_141887040(CUgcItemRidee* pItem, CString strPath, unsigned __int64 uid);       // a mount image not spawned yet
    void FUN_141887dc0(int nBannerId, MS2Ptr<CUgcRegistBanner> spBanner);                  // a banner image arrived
    void FUN_141888420(int nBannerId, CString strPath);                                    // a rolling banner image arrived
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x1c0 - 0x8];
};
MS2_CHECK_SIZE(CUgcManager, 0x1c0);
