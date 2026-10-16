// uiservice.h - CUIService (RTTI name, efd system service class id 0x06100004, display name "CUIService"): the client's
// UI manager. It owns the table of the open/registered dialogs (class id -> dialog, +0x88), the per-dialog help /
// button state ("hot key" tables), the Scaleform movie background / damage overlay helpers and the per-scene
// "which dialogs are open" bookkeeping (+0x138 / +0x180 map a scene id to a 0/1 flag; +0x1c8 / +0x1f8 are the lists
// of the dialogs a scene opens / closes). The big registration function FUN_141adf580 creates every dialog.
// Member and helper names are invented from their use.
// Owning unit: ?\uiservice.cpp (.text$di 0x14011d200-0x14011d540, .text$mn 0x141ad8bc0-0x141af2110).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"

class GFxMovieBackground;

// Opaque exe containers owned by this unit (CAtlMap-shaped, 0x48 bytes; their bodies are unit glue).
struct Unk_UisMap
{
    char m_pad[0x48];
};
MS2_CHECK_SIZE(Unk_UisMap, 0x48);

struct Unk_UisPtr8
{
    char m_pad[8];
};
struct Unk_UisList
{
    char m_pad[0x30];
};

// Scaleform log sink member (class of an unrecovered unit).
struct Unk_UisLogger
{
    char m_pad[0x10];
};

template <class T> class TSingleton;
class CUIService;
template <> class TSingleton<CUIService>
{
public:
    TSingleton();                                   // inline
    virtual ~TSingleton() { s_instance = 0; }       // 0x141aef230
    static CUIService* s_instance;
};

class CUIService : public efd::ISystemService, public TSingleton<CUIService>
{
    EE_DECLARE_CLASS1(CUIService, 0x06100004, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CUIService();                                   // 0x141ad8bc0
    virtual ~CUIService();                          // 0x141ad91c0
    virtual const char* GetDisplayName() const;     // 0x141ad9330
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x141adea90
    virtual efd::AsyncResult OnInit();              // 0x141adeb70
    virtual efd::AsyncResult OnTick();              // 0x141adecf0
    virtual efd::AsyncResult OnShutdown();          // 0x141adeff0

    // ---- scene flags and the dialogs a scene opens ----
    void FUN_141ad9e50(int nScene);                 // 0x141ad9e50 enter a scene: set the flag, open its dialogs
    void FUN_141ada610(int nScene);                 // 0x141ada610 leave a scene: clear the flag
    void FUN_141ada6f0(int nScene);                 // 0x141ada6f0
    void FUN_141adad20(int nScene);                 // 0x141adad20
    void FUN_141adb4c0(int bOn);                    // 0x141adb4c0 enable / disable every hot key slot
    void FUN_141adb7b0(int bOn);                    // 0x141adb7b0
    void FUN_141adbb40();                           // 0x141adbb40 step the cursor mode 0..3
    void FUN_141adbd60(int n);                      // 0x141adbd60
    int FUN_141adbd80();                           // 0x141adbd80
    void FUN_141adbdc0(int n);                      // 0x141adbdc0
    unsigned FUN_141adbd10();                       // 0x141adbd10
    void FUN_141adbea0();                           // 0x141adbea0
    void FUN_141adbf00();                           // 0x141adbf00
    int FUN_141adcb40();                            // 0x141adcb40
    void FUN_141adcb60(int n);                      // 0x141adcb60
    void FUN_141add1b0(int nSlot, bool bOn);        // 0x141add1b0 enable one hot key slot

    // ---- generated member decls ----
    void FUN_141adc050();                                                   // 0x141adc050 close the closable dialogs
    void FUN_141aec8c0(int nMode);                                          // 0x141aec8c0
    void FUN_141ad9350();                                              // 0x141ad9350
    void FUN_141ad9980(char nStage);                                   // 0x141ad9980
    void FUN_141ad9a60(CStringA strBg);                                // 0x141ad9a60
    void FUN_141ad9b30();                                              // 0x141ad9b30
    bool FUN_141ad9b60();                                              // 0x141ad9b60
    void FUN_141ad9c10();                                              // 0x141ad9c10
    bool FUN_141ad9e20();                                              // 0x141ad9e20
    void FUN_141adbca0(int n);                                         // 0x141adbca0
    void FUN_141adbcd0(char b);                                        // 0x141adbcd0
    void FUN_141adbe00(float fValue, int bRaw);                          // 0x141adbe00
    void FUN_141adbe70();                                              // 0x141adbe70
    void FUN_141adbf30();                                              // 0x141adbf30
    void FUN_141adbf70(int n);                                         // 0x141adbf70
    // @@

    void* m_pEntitySvc28;                           // +0x28 (OnInit: FUN_14168ab40(service manager))
    void* m_pWorldSvc30;                            // +0x30 (OnInit: FUN_1411d15b0(service manager))
    Unk_UisPtr8 m_x38;                              // +0x38 ctor 0x1416ae2a0, dtor 0x1416aecf0
    Unk_UisMap m_mapA;                              // +0x40 ctor 0x141aed9e0, clear 0x141af0f00, dtor 0x141aee190
    Unk_UisMap m_mapDlg;                            // +0x88 class id -> dialog, ctor 0x141aed8f0, clear 0x141af0df0
    Unk_UisMap m_mapC;                              // +0xd0 name -> dialog, ctor 0x141aed800, clear 0x141af0ce0
    int m_nMode;                                    // +0x118 initial 0x3ed
    int m_n11c;                                     // +0x11c
    char m_b120;                                    // +0x120
    char m_pad_121[3];
    int m_n124;                                     // +0x124
    int m_n128;                                     // +0x128
    int m_n12c;                                     // +0x12c
    int m_n130;                                     // +0x130
    int m_nCursor;                                  // +0x134 0..3
    Unk_UisMap m_mapOpen;                           // +0x138 scene id -> 0/1 (CAtlMap<int,int>; ctor 0x140163400)
    Unk_UisMap m_mapOpen2;                          // +0x180
    Unk_UisList m_listOpen;                         // +0x1c8 CAtlList<int>, ctor 0x141926ff0
    Unk_UisList m_listClose;                        // +0x1f8
    Unk_UisLogger m_log;                            // +0x228 GFxLogger
    CStringA m_strTable;                            // +0x238
    CCacheData m_cache;                             // +0x240
    Unk_UisPtr8 m_x268;                             // +0x268 ctor 0x141aedd80, dtor 0x141aee240
};
