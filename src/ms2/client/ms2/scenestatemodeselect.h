// scenestatemodeselect.h - CSceneStateModeSelect (efd RTTI name "CSceneStateModeSelect", class id 0x06200085): the
// mode-select scene state. Header name assumed. Secondary base IWorldServiceCallback at +0x10.
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"

class CSceneStateModeSelect : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateModeSelect, 0x06200085, efd::IBase);

public:
    CSceneStateModeSelect();                                // 0x140aadff0
    virtual ~CSceneStateModeSelect();                       // 0x140aae050

    void OnEnter(int nPrevState) override;                  // 0x140aae090
    void OnLeave(int nNextState) override;                  // 0x140aae160
    void OnUpdate(double fTime) override;                   // 0x140aae1d0
    void OnPacket(CInPacket& packet) override;              // 0x140aae200
    void vfunc_1(int) override;                             // 0x140aae230 (IWorldServiceCallback slot 1)
};
MS2_CHECK_SIZE(CSceneStateModeSelect, 0x18);
