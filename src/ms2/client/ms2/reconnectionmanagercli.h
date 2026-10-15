// CReconnectionManagerCli: client reconnect state machine over the game socket. Names except RTTI inferred.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/reconnectionstructs.h"
#include "ms2/placeholder/cinpacket.h"
class CReconnectionManagerCli;
// This instantiation stores the complete object pointer (same shape as TSingleton<CNetworkService>); DAT_143ab8aa0.
template<> class TSingleton<CReconnectionManagerCli> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CReconnectionManagerCli* s_instance;
};
class UIReconnectTopLayerNotify;
class CReconnectionManagerCli : public TSingleton<CReconnectionManagerCli> {
public:
    CReconnectionManagerCli();                              // 0x140aace60
    virtual ~CReconnectionManagerCli();                     // 0x140aacee0
    bool FUN_140aacf50(int error);
    void FUN_140aad050(const ReconnectionOptions* src);
    ReconnectionOptions* FUN_140aad080();
    int FUN_140aad0a0(int index);
    void FUN_140aad0d0();
    void FUN_140aad120();
    void FUN_140aad140();
    bool FUN_140aad1e0();
    bool FUN_140aad220();
    int FUN_140aad2b0();
    bool FUN_140aad2d0(int code);
    void FUN_140aad340(unsigned code);
    bool FUN_140aad450();
    void FUN_140aad5c0(int ok);
    void FUN_140aad6e0(int error);
    void FUN_140aad7f0();
    void FUN_140aad8f0();
    void FUN_140aad910(int a, int b);
    void FUN_140aad970();
    void FUN_140aad9b0(int seconds);
    void FUN_140aada20(CInPacket* packet);
    void FUN_140aadd70();
private:
    MS2_LAYOUT_FRIEND;
    int m_08;
    ReconnectionOptions m_options;                          // +0x10
    ReconnectionContext m_context;                          // +0x58
    ReconnectionContextCli m_cli;                           // +0x88
};
MS2_CHECK_SIZE(CReconnectionManagerCli, 0xd8);
