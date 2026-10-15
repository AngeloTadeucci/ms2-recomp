// scenestatebase.h - CSceneStateBase (efd RTTI name "CSceneStateBase", class id 0x06200008): the base of the client's
// scene states (CSceneStateGame and the login/select/loading states). Header name assumed. The virtual names are
// invented from their use in CSceneStateGame (vfunc_N = vftable slot N of 0x142f5c268).
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <efd/IBase.h>
#include <efd/RefCount.h>

#include "ms2/ms2layout.h"

class CInPacket;

// 0x10 bytes. vftable 0x142f5c268 (16 slots): DeleteThis, IncRefCount, DecRefCount, GetRefCount, TypeCast x2,
// GetClassDesc, GetClassID (efd::IBase), the deleting dtor, then the 7 scene-state hooks below.
class CSceneStateBase : public efd::IBase
{
    EE_DECLARE_CLASS1(CSceneStateBase, 0x06200008, efd::IBase);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;

public:
    CSceneStateBase();                                      // 0x14170b850
    virtual ~CSceneStateBase();                             // 0x14170b8b0

    virtual void OnEnter(int nPrevState);                   // slot 9, 0x14170b8e0
    virtual void OnLeave(int nNextState);                   // slot 10, 0x14170b930
    virtual void OnUpdate(double fTime);                    // slot 11, 0x14170b940
    virtual void OnPacket(CInPacket& packet);               // slot 12, 0x14170b960 (CSceneStateGame: opcode switch)
    virtual void OnWndMessage(unsigned int nMsg, int wParam, int lParam);  // slot 13, 0x14170b980
    virtual int vfunc_14();                                 // slot 14, 0x14170b9a0: 0 (CSceneStateGame: 1)
    virtual int vfunc_15();                                 // slot 15, 0x14170b9b0: 1

    unsigned int m_nEnterTime;                              // +0x0c tick count at OnEnter
};
MS2_CHECK_SIZE(CSceneStateBase, 0x10);
MS2_CHECK_OFFSET(CSceneStateBase, m_nEnterTime, 0x0c);
