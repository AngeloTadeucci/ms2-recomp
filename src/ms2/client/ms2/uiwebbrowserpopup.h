// uiwebbrowserpopup.h - UIWebBrowserPopup (RTTI .?AVUIWebBrowserPopup@@, 0x220 bytes, UIWebBrowser, UI id 0x4f40): the
// pop-up flavour of the in-game browser (browser id 5, its own size constants, title "$s_webbrowserpopup_title2").
// No members of its own. Owning unit: ?\uiwebbrowserpopup.cpp. Header name assumed from the unit path.
#pragma once
#include "ms2/client/ms2/uiwebbrowser.h"

class UIWebBrowserPopup : public UIWebBrowser
{
public:
    UIWebBrowserPopup();                                        // 0x140fc1e20
    virtual ~UIWebBrowserPopup();                               //  0 0x140fc1e90 (??_G 0x140fc2040)
    virtual void OnLoadInit();                                  // 20 0x140fc1ee0 read the sizes from the pop-up constants
    virtual void OnLoadComplete();                              // 22 0x140fc1fd0 set the pop-up title
    virtual int vfunc_48() { return 0x4f40; }                   // 48 0x140fc2080
};
MS2_CHECK_SIZE(UIWebBrowserPopup, 0x220);
