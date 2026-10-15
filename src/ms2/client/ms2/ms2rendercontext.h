// ms2rendercontext.h - MS2RenderContext (RTTI .?AVMS2RenderContext@@): the game's subclass of the engine's ecr::RenderContext.
// Draw() is the engine's loop plus a per-frame back-buffer capture ("recode") into a shared-memory ring of two frames
// (file mapping "MS2SurfaceInfo" holds the header + text, the second mapping the two raw X8R8G8B8 frames).
// Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2rendercontext.cpp` (0x1414dab70-0x1414dbf30, dir client\ms2).
#pragma once

#include "ms2/ms2layout.h"
#include <atlstr.h>
#include <d3d9.h>
#include <ecr/RenderContext.h>

// Win32 file-mapping wrapper (ctor 0x140223990, dtor 0x140223a90, IsValid 0x140223b00 live in unit_1402226b0).
class Unk_SharedMemory
{
public:
    Unk_SharedMemory(const char* pszName, unsigned long nSize);   // 0x140223990
    ~Unk_SharedMemory();                                          // 0x140223a90
    bool IsValid() const;                                         // 0x140223b00
public:
    void* m_hMapping;      // +0x00
    char m_szName[0x20];   // +0x08
    void* m_pView;         // +0x28
};
MS2_CHECK_SIZE(Unk_SharedMemory, 0x30);

// Header at the start of the "MS2SurfaceInfo" mapping (0x444 bytes).
struct Unk_RecodeSurfaceInfo
{
    int m_nWidth;            // +0x00 back buffer width
    int m_nHeight;           // +0x04 back buffer height
    int m_nFrameSize;        // +0x08 width * height * 4
    int m_nOutWidth;         // +0x0c 0x500
    int m_nOutHeight;        // +0x10 0x2d0
    int m_bFrameReady[2];    // +0x14 per-frame "filled" flags
    char m_szFrameName[0x20];// +0x1c name of the pixel mapping
    int m_bActive;           // +0x3c
    char m_szText[0x400];    // +0x40
    char m_bTextValid;       // +0x440
};
MS2_CHECK_SIZE(Unk_RecodeSurfaceInfo, 0x444);

class MS2RenderContext : public ecr::RenderContext
{
public:
    MS2RenderContext(ecr::RenderService* pRenderService, Ni3DRenderView* pRenderView);   // 0x1414dabb0
    virtual ~MS2RenderContext();                                                         // 0x1414dac50, ??_G 0x1414dbb80
    virtual void Draw(efd::Float32 currentTime);                                         // 0x1414daca0

    int CreateRecodeSurface();                    // 0x1414dafa0
    void ReleaseRecodeSurface();                   // 0x1414db5c0
    void EnableRecode();                           // 0x1414db710
    void SetRecodeText(CString text);              // 0x1414db730
    bool IsRecodeFrameFree(int index);             // 0x1414db7e0
    void MarkRecodeFrameReady(int index);          // 0x1414db850
    void CaptureRecodeFrame();                     // 0x1414db8a0

public:
    int m_bRecode;                       // +0x78
    Unk_SharedMemory* m_pInfoMemory;     // +0x80
    Unk_SharedMemory* m_pFrameMemory;    // +0x88
    int m_nSerial;                       // +0x90
    IDirect3DSurface9* m_pCopySurface;   // +0x98
};
MS2_CHECK_SIZE(MS2RenderContext, 0xa0);
MS2_CHECK_OFFSET(MS2RenderContext, m_bRecode, 0x78);
MS2_CHECK_OFFSET(MS2RenderContext, m_pCopySurface, 0x98);
