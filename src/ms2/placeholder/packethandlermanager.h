// packethandlermanager.h - PLACEHOLDER for PacketHandlerManager (RTTI .?AVPacketHandlerManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<PacketHandlerManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates: opcode -> handler delegates. Recovered in
// unnamed\unit_140da50e0.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/delegate.h"
#include <map>
#include <vector>
class CInPacket;

class PacketHandlerManager : public TSingleton<PacketHandlerManager>
{
public:
    PacketHandlerManager();                                 // 0x140da50e0
    virtual ~PacketHandlerManager();
    void RegisterHandler(int nOpcode, Delegate<void(CInPacket&)> handler);     // 0x140da5180
    void UnregisterHandler(int nOpcode, Delegate<void(CInPacket&)> handler);   // 0x140da51e0
    void Dispatch(int nOpcode, CInPacket& iPacket);                            // 0x140da52f0
private:
    MS2_LAYOUT_FRIEND;
    std::map<int, std::vector<Delegate<void(CInPacket&)> > > m_handlers;       // +0x08
};
MS2_CHECK_SIZE(PacketHandlerManager, 0x18);
