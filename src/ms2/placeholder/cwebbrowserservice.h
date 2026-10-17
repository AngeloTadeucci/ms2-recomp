// cwebbrowserservice.h - PLACEHOLDER for CWebBrowserService (RTTI .?AVCWebBrowserService@@, 0x120 bytes). NOT an
// original header. Bases: efd::ISystemService at +0x0, TSingleton<CWebBrowserService> at +0x18. The in-game web
// browser efd system service (class id 0x06100018). Owning unit client\ms2\webbrowserservice.cpp; only the members
// ms2.cpp uses are declared.
#pragma once

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CWebBrowserService : public efd::ISystemService, public TSingleton<CWebBrowserService>
{
    EE_DECLARE_CLASS1(CWebBrowserService, 0x06100018, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    explicit CWebBrowserService(HINSTANCE hInstance);               // 0x141b77810
    virtual ~CWebBrowserService();
    virtual const char* GetDisplayName() const;
    void FUN_141b77e10();                                           // starts the browser host unless it already runs
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_24[0x120 - 0x24];
};
MS2_CHECK_SIZE(CWebBrowserService, 0x120);
