// cfieldmaidmanager.h - PLACEHOLDER for CFieldMaidManager (RTTI .?AVCFieldMaidManager@@, 0x38 bytes). NOT an
// original header.
// Bases: TSingleton<CFieldMaidManager> at +0x0.
// Keeps the maids of the current field, keyed by their id (the key is CMaid +0x20); CGameApp::InitInstance
// (?\ms2.cpp) creates it. Implemented in ?\maidmanager.cpp (0x14127e190).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cmaid.h"

class CFieldMaidManager : public TSingleton<CFieldMaidManager>
{
public:
    CFieldMaidManager();                                    // 0x14127e190
    virtual ~CFieldMaidManager();
    void RemoveAllMaids();                                  // 0x14127e220
    void OnPacket(CInPacket* pPacket);                      // 0x14127e250: mode 0 adds a maid, 1 removes one
    MS2Ptr<CMaid> GetMaid(unsigned __int64 nId);            // 0x14127e400
private:
    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<unsigned __int64, MS2Ptr<CMaid>> m_mapMaid; // +0x8
};
MS2_CHECK_SIZE(CFieldMaidManager, 0x38);
MS2_CHECK_OFFSET(CFieldMaidManager, m_mapMaid, 8);
