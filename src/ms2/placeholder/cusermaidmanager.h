// cusermaidmanager.h - PLACEHOLDER for CUserMaidManager (RTTI .?AVCUserMaidManager@@, 0x38 bytes). NOT an original
// header.
// Bases: TSingleton<CUserMaidManager> at +0x0.
// Keeps the maids of the user (the same map as CFieldMaidManager) and sends the maid requests (opcode 0x62);
// CGameApp::InitInstance (?\ms2.cpp) creates it. Implemented in ?\maidmanager.cpp (0x14127e4b0).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cmaid.h"

class UIObject;

class CUserMaidManager : public TSingleton<CUserMaidManager>
{
public:
    typedef ATL::CRBMap<unsigned __int64, MS2Ptr<CMaid>> MaidMap;

    CUserMaidManager();                                     // 0x14127e4b0
    virtual ~CUserMaidManager();
    void OnPacket(CInPacket* pPacket);                      // 0x14127e550: modes 0 list, 1 add, 2 remove, 3 update, 4 npc
    MS2Ptr<CMaid> GetMaid(unsigned __int64 nId);            // 0x14127ec10
    void SendRequest5(unsigned __int64 nId);                // 0x14127ecc0
    void SendRequest6(unsigned __int64 nId);                // 0x14127ed40
    void SendRequest7(unsigned __int64 nId);                // 0x14127edc0
    void SendRequest8(unsigned __int64 nId);                // 0x14127ee40
    void SendRequest9(unsigned __int64 nId);                // 0x14127eec0
    void SendRequest10(unsigned __int64 nId, unsigned __int64 nValue, int cFlag);   // 0x14127ef40
    MaidMap* GetMaidMap();                                  // 0x14127eff0
    static class UIMaidDialog* GetMaidDialog(int nUiId);    // 0x14127f000
private:
    MS2_LAYOUT_FRIEND;
    MaidMap m_mapMaid;                                      // +0x8
};
MS2_CHECK_SIZE(CUserMaidManager, 0x38);
MS2_CHECK_OFFSET(CUserMaidManager, m_mapMaid, 8);
