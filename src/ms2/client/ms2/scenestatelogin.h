// scenestatelogin.h - CSceneStateLogin (efd RTTI name "CSceneStateLogin", class id 0x06200009): the login scene state.
// Header name assumed. Secondary base IWorldServiceCallback at +0x10 (vftable 0x142f5fee0).
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"

class CSceneStateLogin : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateLogin, 0x06200009, efd::IBase);

public:
    CSceneStateLogin();                                     // 0x14174c000
    virtual ~CSceneStateLogin();                            // 0x14174c060

    void OnEnter(int nPrevState) override;                  // 0x14174c0a0
    void OnLeave(int nNextState) override;                  // 0x14174c170
    void OnUpdate(double fTime) override;                   // 0x14174c1d0
    void OnPacket(CInPacket& packet) override;              // 0x14174c200
    void vfunc_1(int) override;                             // 0x14174c4a0 (IWorldServiceCallback slot 1)
};
MS2_CHECK_SIZE(CSceneStateLogin, 0x18);
