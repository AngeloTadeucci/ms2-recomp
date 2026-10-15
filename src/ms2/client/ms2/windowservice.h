// CWindowService (RTTI name): the game's Win32 window service. It derives from the engine's efd::Win32PlatformService and
// a TSingleton<CWindowService> (second base at +0xb8), embeds an MFC CMenu for the window menu and installs its own window
// procedure. Member names are invented from their use.
// Owning unit: ?\windowservice.cpp (0x141b90cd0-0x141b93fd0, dir client\ms2).
#pragma once
#include <afxwin.h>
#include <efd/Win32/Win32PlatformService.h>

#include "ms2/ms2layout.h"

class CWindowService;
template <class T> class TSingleton;
template <> class TSingleton<CWindowService>
{
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CWindowService* s_instance;      // 0x143ab8a98
};

class CWindowService : public efd::Win32PlatformService, public TSingleton<CWindowService>
{
public:
    CWindowService(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);   // 0x141b90cd0
    virtual ~CWindowService();                                  // 0x141b90d90, ??_G 0x141b93d50
    virtual efd::AsyncResult OnTick();                          // 0x141b93470
    virtual BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);   // 0x141b934f0
    virtual ATOM RegisterClass(HINSTANCE hInstance);            // 0x141b93740

    void SetTitleText(const char* pszText);                    // 0x141b90e00
    int GetCursorClientPos(float* pfX, float* pfY);            // 0x141b90e30
    void MoveCursor(int nDeltaX, int nDeltaY);                  // 0x141b90ec0
    void PostMouseMove(UINT nMessage);                          // 0x141b90f20
    bool RecreateRenderer(bool bFullscreen, unsigned nWidth, unsigned nHeight);    // 0x141b91010
    void ApplyWindowMode(bool bFullscreen, unsigned nWidth, unsigned nHeight);     // 0x141b91290
    void ShowGameWindow();                                      // 0x141b91ba0
    void OnRendererChanged(void* pDevice);                      // 0x141b938d0

    CMenu m_menu;                                               // +0xc0
    bool m_bMaximize;                                           // +0xd0
};
MS2_CHECK_SIZE(CWindowService, 0xd8);
MS2_CHECK_OFFSET(CWindowService, m_menu, 0xc0);
MS2_CHECK_OFFSET(CWindowService, m_bMaximize, 0xd0);
