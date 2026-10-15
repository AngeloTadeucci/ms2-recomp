// scenestateloading.h - CSceneStateLoading (efd RTTI name "CSceneStateLoading", class id 0x0620000a): the loading scene
// state. Header name assumed. Adds no members to CSceneStateBase.
#pragma once
#include "scenestatebase.h"

class CSceneStateLoading : public CSceneStateBase
{
    EE_DECLARE_CLASS1(CSceneStateLoading, 0x0620000a, efd::IBase);

public:
    CSceneStateLoading();                                   // 0x14174bd70
    virtual ~CSceneStateLoading();                          // 0x14174bdb0

    void OnEnter(int nPrevState) override;                  // 0x14174bde0
    void OnLeave(int nNextState) override;                  // 0x14174be20
    void OnUpdate(double fTime) override;                   // 0x14174be50
    int vfunc_15() override;                                // 0x14174be80
};
MS2_CHECK_SIZE(CSceneStateLoading, 0x10);
