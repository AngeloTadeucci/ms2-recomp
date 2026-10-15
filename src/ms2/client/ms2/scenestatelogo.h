// scenestatelogo.h - CSceneStateLogo (efd RTTI name "CSceneStateLogo", class id 0x0620000b): the logo scene state.
// Header name assumed. Secondary base IWorldServiceCallback at +0x10; adds no members to CSceneStateBase.
#pragma once
#include "scenestatebase.h"
#include "ms2/placeholder/iworldservicecallback.h"

class CSceneStateLogo : public CSceneStateBase, public IWorldServiceCallback
{
    EE_DECLARE_CLASS1(CSceneStateLogo, 0x0620000b, efd::IBase);

public:
    CSceneStateLogo();                                      // 0x14174c710
    virtual ~CSceneStateLogo();                             // 0x14174c770

    void OnEnter(int nPrevState) override;                  // 0x14174c7b0
    void OnLeave(int nNextState) override;                  // 0x14174c7e0
    void OnUpdate(double fTime) override;                   // 0x14174c810
    int vfunc_15() override;                                // 0x14174c840
};
MS2_CHECK_SIZE(CSceneStateLogo, 0x18);
