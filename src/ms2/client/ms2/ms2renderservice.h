// ms2renderservice.h - MS2RenderService (RTTI .?AVMS2RenderService@@): the game's subclass of the engine's ecr::RenderService,
// plus CRenderCallback (the NiRenderer message sink that forwards to the game log). Differences from the engine service:
// the renderer is created from the game options (resolution / fullscreen / vsync) with an own fallback ladder, the shader
// error callback shows a message box, device-lost handling is routed to the game, and OnTick remembers the context it is
// drawing. Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2renderservice.cpp`
// (0x1414ea3d0-0x1414f0b90, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <NiRenderer.h>
#include <NiDX9RendererDesc.h>
#include <ecr/RenderService.h>

// Sink registered with the NiRenderer (vftable 0x142f253a0); every message is trimmed, widened and written to the game log.
class CRenderCallback : public NiRenderer::CallbackObject
{
public:
    CRenderCallback() noexcept {}                                                // 0x1414ef410
    virtual ~CRenderCallback() noexcept {}                                       // 0x1414ef770, ??_G 0x1414eff30
    virtual void Message(const char* pText);                            // 0x1414ea3d0
    virtual void Warning(const char* pText);                            // 0x1414ea490
    virtual void Error(const char* pText);                              // 0x1414ea550
};
MS2_CHECK_SIZE(CRenderCallback, 0x8);

class MS2RenderService : public ecr::RenderService
{
public:
    MS2RenderService(NiWindowRef parentHandle);                         // 0x1414ea640
    virtual ~MS2RenderService();                                        // 0x1414ea6d0, ??_G 0x1414efff0
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);     // 0x1414ea710
    virtual efd::AsyncResult OnInit();                                  // 0x1414ed3a0
    virtual efd::AsyncResult OnTick();                                  // 0x1414ee2b0
    virtual efd::AsyncResult OnShutdown();                              // 0x1414ee3b0
    virtual void AddRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject);            // 0x1414eca50
    virtual void RemoveRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject);          // 0x1414eca90
    // MS2: slot 24, new in the game's class. Same job as RenderService::CreateRenderer but with an explicit window size.
    virtual bool CreateRendererSized(bool bFullscreen, int width, int height);              // 0x1414ecf80

    void CheckRenderState();                                            // 0x1414ea8b0 (logs every tracked D3D render state)
    void SetValidateFrames(bool bValidate);                             // 0x1414ecba0
    void LogState();                                                    // 0x1414ecf20 (debug log hook)

public:
    CRenderCallback m_renderCallback;                                   // +0x78
    bool m_bValidateFrames;                                             // +0x80
    NiDX9RendererDesc* m_pRendererDesc;                                 // +0x88
    ecr::RenderContext* m_pCurrentContext;                              // +0x90 context being drawn by OnTick
    unsigned int m_uiCurrentIndex;                                      // +0x98
};
MS2_CHECK_SIZE(MS2RenderService, 0xa0);
MS2_CHECK_OFFSET(MS2RenderService, m_renderCallback, 0x78);
MS2_CHECK_OFFSET(MS2RenderService, m_pRendererDesc, 0x88);
