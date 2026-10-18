// gameoptioninputdefault.h - CGameOptionInputDefault (RTTI .?AVCGameOptionInputDefault@@, bases CBaseOption + IMessageListener
// at +0x30, 0xe0 bytes): the key-binding tabs. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in
// unit `?\gameoptioninputdefault.cpp`. Header and member names are assumed. UIGameOptionDialog builds it five times as tab ids
// 9, 10, 11, 12 (gamepad feature 0xb5) and 13; the ctor and the dialog agree on (nId, nType).
// Ctor 0x141250a80 sets +0x38 = 1, +0x40 = 0, +0x58 = 0 and runs FUN_141253d40 (+0x48), Timer::Timer (+0x60) and
// FUN_141253b40 (+0x98 = a CAtlMap(17, .75f, .25f, 2.25f, 10) whose key/value types are not recovered yet).
#pragma once
#include "ms2/client/ms2/baseoption.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/imessagelistener.h"

struct Unk_KeyList
{
    void* m_p00;                                                    // +0x00 (not touched by FUN_141253d40)
    void* m_p08;                                                    // +0x08 (cleared)
    void* m_p10;                                                    // +0x10
};
MS2_CHECK_SIZE(Unk_KeyList, 0x18);

class CGameOptionInputDefault : public CBaseOption, public IMessageListener
{
public:
    CGameOptionInputDefault(int nId, int nType);                    // 0x141250a80
    virtual ~CGameOptionInputDefault();                             // 0x141250b90
    virtual CString vfunc_1();                                     // 0x1412521b0
    virtual void vfunc_3(int n);                                   // 0x141250c10
    virtual void vfunc_4(int n);                                   // 0x141250c80
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x141251a30
    virtual void vfunc_6();                                        // 0x1412514e0
    virtual void vfunc_7();                                        // 0x141251510
    virtual int vfunc_8();                                         // 0x141251540
    virtual void vfunc_9();                                        // 0x141251db0
    virtual void vfunc_10();                                       // 0x141251df0
    virtual void vfunc_12();                                       // 0x141251e90
    virtual void vfunc_13();                                       // 0x141251490
    virtual bool vfunc_14();                                       // 0x141251d90
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // 0x141252f20 (vfunc_o30_0)

    int m_n38;                                                      // +0x38 (1)
    int m_n40;                                                      // +0x40 (0)
    Unk_KeyList m_keys;                                             // +0x48
    int m_n58;                                                      // +0x58 (0)
    Timer m_timer;                                                  // +0x60
    char m_mapBinds[0x48];                                          // +0x98 CAtlMap<?, ?> (ctor FUN_141253b40, dtor FUN_141253e90)
};
MS2_CHECK_SIZE(CGameOptionInputDefault, 0xe0);
