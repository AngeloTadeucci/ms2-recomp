// cmainsystem.h - PLACEHOLDER for CMainSystem (RTTI .?AVCMainSystem@@, 0xd0 bytes). NOT an original header.
// Bases: TSingleton<CMainSystem> at +0x0, efd::ISystemService at +0x8. The game's main efd system service (class id
// 0x06100006): MS2::RegisterServices creates it first, hands it the main thread id and the config manager (it reads
// the data path into +0xa8). Owning unit ?\mainsystem.cpp (blocked); only the members ms2.cpp uses are declared.
#pragma once

#include <efd/ISystemService.h>
#include <efd/IConfigManager.h>
#include <efd/ReferenceCounting.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMainSystem : public TSingleton<CMainSystem>, public efd::ISystemService
{
    EE_DECLARE_CLASS1(CMainSystem, 0x06100006, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CMainSystem();                                                  // 0x141472be0
    virtual ~CMainSystem();                                         // 0x141472dd0
    virtual const char* GetDisplayName() const;                     // 0x141472e90
    void FUN_141472eb0(efd::IConfigManagerPtr spConfig);            // reads the data path into m_strDataPath
    void FUN_141473920(DWORD dwThreadId);                           // +0xb0
    CString FUN_1414736e0();                                        // m_strDataPath (+0xa8)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_24[0xd0 - 0x24];
};
MS2_CHECK_SIZE(CMainSystem, 0xd0);
