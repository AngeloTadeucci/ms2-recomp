// scenestaterelocateworld.h - CSceneStateRelocateWorld (efd RTTI name "CSceneStateRelocateWorld", class id 0x06200042):
// the scene state used while the client reconnects to a new world/channel address. Header name assumed.
// Secondary base IWorldServiceCallback at +0x10 (vftable 0x142f60ae8).
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"

class CSceneStateRelocateWorld : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateRelocateWorld, 0x06200042, efd::IBase);

public:
    CSceneStateRelocateWorld();                             // 0x141750f00
    virtual ~CSceneStateRelocateWorld();                    // 0x141750f60

    void OnEnter(int nPrevState) override;                  // 0x141750fa0
    void OnLeave(int nNextState) override;                  // 0x141751020
    void OnUpdate(double fTime) override;                   // 0x141751060
    void SetState(int nState);                              // 0x141751100 (1 = armed, OnUpdate then reconnects)

private:
    int m_nState;                                           // +0x18
};
MS2_CHECK_SIZE(CSceneStateRelocateWorld, 0x20);
