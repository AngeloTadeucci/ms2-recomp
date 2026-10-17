// packethandlermanager.h - PLACEHOLDER for PacketHandlerManager (RTTI .?AVPacketHandlerManager@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<PacketHandlerManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class PacketHandlerManager : public TSingleton<PacketHandlerManager>
{
public:
    PacketHandlerManager();                                 // 0x140da50e0
    virtual ~PacketHandlerManager();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x18 - 0x8];
};
MS2_CHECK_SIZE(PacketHandlerManager, 0x18);
