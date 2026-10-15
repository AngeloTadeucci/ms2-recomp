// ms2fragmentshader.h - MS2FragmentShader (RTTI .?AVMS2FragmentShader@@): the game's NiDX9FragmentShader subclass (0xd8
// bytes, vftable 0x143271880, ms_RTTI 0x143ac2ff8). It is a copy of the stock NiD3DShader pipeline overrides with a
// private Do_RenderMeshes and PrepareTextureStage (the last, game-added virtual slot 38 of NiDX9FragmentShader).
// Recovered from MapleStory2.exe KMS2_DEV x64; owning unit `?\ms2fragmentshader.cpp` (0x140d878b0-0x140d8a570).
#pragma once

#include "ms2/ms2layout.h"
#include <NiDX9FragmentShader.h>

class MS2FragmentShader : public NiDX9FragmentShader
{
    NiDeclareRTTI;

public:
    MS2FragmentShader(NiMaterialDescriptor* pkDesc);                                       // 0x140d878b0
    virtual ~MS2FragmentShader();                                                           // 0x140d878f0, ??_G 0x140d89390

    virtual unsigned int PreProcessPipeline(const NiRenderCallContext& kRCC);               // 6  0x140d88560
    virtual unsigned int UpdatePipeline(const NiRenderCallContext& kRCC);                   // 7  0x140d88660
    virtual unsigned int FirstPass();                                                       // 8  0x140d88180
    virtual unsigned int SetupRenderingPass(const NiRenderCallContext& kRCC);               // 9  0x140d882d0
    virtual unsigned int SetupTransformations(const NiRenderCallContext& kRCC);             // 10 0x140d88330
    virtual unsigned int SetupShaderPrograms(const NiRenderCallContext& kRCC);              // 11 0x140d88390
    virtual unsigned int NextPass();                                                        // 15 0x140d881e0

protected:
    virtual void Do_RenderMeshes(NiVisibleArray* pkVisibleArray);                           // 27 0x140d87920
    virtual void PrepareTextureStage(NiD3DTextureStage* pkStage, const NiRenderCallContext& kRCC);   // 38 0x140d88750
};
MS2_CHECK_SIZE(MS2FragmentShader, 0xd8);
