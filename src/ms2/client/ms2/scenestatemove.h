// scenestatemove.h - CSceneStateMove (efd RTTI name "CSceneStateMove", class id 0x0620003b): the scene state shown while
// the client reconnects to the world/channel server (retries up to 5 times, then terminates the process).
// Header name assumed. Secondary base IWorldServiceCallback at +0x10 (vftable 0x142f602d8).
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/timer.h"

class CSceneStateMove : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateMove, 0x0620003b, efd::IBase);

public:
    CSceneStateMove();                                      // 0x14174c9c0
    virtual ~CSceneStateMove();                             // 0x14174ca50

    void OnEnter(int nPrevState) override;                  // 0x14174caa0
    void OnLeave(int nNextState) override;                  // 0x14174cb40
    void OnUpdate(double fTime) override;                   // 0x14174cb70
    void OnPacket(CInPacket& packet) override;              // 0x14174d0c0

private:
    int m_bConnecting;                                      // +0x18 a reconnect attempt is in flight
    Timer m_timer;                                          // +0x20
    int m_nRetry;                                           // +0x58 attempt number (6 = giving up)
    int m_bFailed;                                          // +0x5c
};
MS2_CHECK_SIZE(CSceneStateMove, 0x60);
