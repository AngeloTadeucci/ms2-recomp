// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The post-processing render steps (anti-alias, bloom, colour
// perspective, depth of field, fades, blurs, shimmer, overdraw), their PostProcessEffect / ReloadablePostProcess bases and
// the PostProcessingService that owns them.
// MS2-UNIT: client\ms2\postprocessing\postprocessingservice.cpp
// MS2-RANGE: 0x14169d920-0x1416b5320 .text$mn
// MS2-RANGE: 0x1400fc2a0-0x1400fc960 .text$di
// MS2-RANGE: 0x142cb45d0-0x142cb4715 .text$yd
// MS2-PIN: ??4Unk_ShaderColor@@QEAAAEAV0@$$QEAV0@@Z 0x14169f1d0
// MS2-PIN: ??4Unk_ShaderColor@@QEAAAEAV0@AEBV0@@Z 0x14169f200
// MS2-PIN: ??4Unk_ShaderVec4@@QEAAAEAV0@AEBV0@@Z 0x14169f230
// MS2-PIN: ??0?$SmartPointer@VNiRenderClick@@@efd@@QEAA@AEBV01@@Z 0x14169f660
// MS2-PIN: ?RemoveHead@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@XZ 0x14169f990
// MS2-PIN: ?RemovePos@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@AEAPEAX@Z 0x14169fa70
// MS2-PIN: ?RemoveTail@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@V?$SmartPointer@VNiRenderClick@@@efd@@@@QEAA?AV?$SmartPointer@VNiRenderClick@@@efd@@XZ 0x14169fc50
// MS2-PIN: ??1OverdrawRenderStep@@UEAA@XZ 0x1416a27f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\postprocessingservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "postprocessingservice.h"
#include <NiClickRenderStep.h>
#include <NiPoint2.h>
#include <NiRenderClick.h>
#include <NiRenderedTexture.h>
#include <NiRenderTargetGroup.h>
#include <NiShaderFactory.h>
#include <NiShaderLibrary.h>
#include <NiDepthStencilBuffer.h>
#include <NiViewRenderClick.h>
#include <NiScreenFillingRenderView.h>
#include <NiTexturingProperty.h>
#include <NiRenderObject.h>
#include "hook/ms2hook.h"

extern NiFixedString DAT_143ae53e0;                         // "gakNormalSampleOffsets" (global shader constant name)
void FUN_1411781e0(const NiFixedString& kName, const NiPoint2* pkValues, int nCount);   // set a global shader constant array
extern NiFixedString DAT_143ae53e8;                         // "gakSampleOffsets"
extern NiFixedString DAT_143ae53f0;                         // "gakSampleWeights"

// The 16-byte shader constant (four floats), as in uiupperhuddialog.cpp / meshuvpicker.h.
class Unk_ShaderVec4
{
public:
    Unk_ShaderVec4();                                       // 0x141480230
    void Assign(float a, float b, float c, float d);        // 0x14135e000
    Unk_ShaderVec4& operator=(const Unk_ShaderVec4& rhs)    // 0x14169f230 (user-declared, so the derived copy/move both call it)
    {
        m_af[0] = rhs.m_af[0];
        m_af[1] = rhs.m_af[1];
        m_af[2] = rhs.m_af[2];
        m_af[3] = rhs.m_af[3];
        return *this;
    }
private:
    float m_af[4];
};
MS2_CHECK_SIZE(Unk_ShaderVec4, 0x10);

class Unk_ShaderColor : public Unk_ShaderVec4
{
public:
    Unk_ShaderColor() {}                                    // 0x141480210
    Unk_ShaderColor(float a, float b, float c, float d);    // 0x14135dc80
    void SetZero() { Assign(0.0f, 0.0f, 0.0f, 0.0f); }
};
MS2_CHECK_SIZE(Unk_ShaderColor, 0x10);

void FUN_14135db70(const NiFixedString& kName, const Unk_ShaderColor* pkValues, int nCount);   // set a global shader constant array
unsigned long GetTickCountMs2();
void FUN_1409a5770(const NiFixedString& kName, const float* pfValues, int nCount);   // set a global float shader constant
extern "C" float (__cdecl* __imp_sqrtf)(float);
extern "C" float (__cdecl* __imp_expf)(float);

bool FUN_14169ea50(NiRenderClick* pkClick, void* pvData);
bool FUN_14169eb00(NiRenderClick* pkClick, void* pvData);
bool FUN_14169ec70(NiRenderClick* pkClick, void* pvData);
void FUN_14169ede0(const NiPoint2* akOffsets, const Unk_ShaderColor* akWeights);
void FUN_14169ee30(unsigned int uiWidth, unsigned int uiHeight, NiPoint2* akOffsets);
float FUN_14169ef20(float x, float y, float fRho);
void FUN_14169efd0(unsigned int uiTexSize, float* afTexCoordOffset, Unk_ShaderColor* akColorWeight, float fDeviation,
    float fMultiplier);

// ---- AntiAliasRenderStep

// @0x1400fc2a0
const NiRTTI AntiAliasRenderStep::ms_RTTI("AntiAliasRenderStep", &NiRenderStep::ms_RTTI);

// @0x14169d920
AntiAliasRenderStep::AntiAliasRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("AntiAliasRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169d9a0
AntiAliasRenderStep::~AntiAliasRenderStep()
{
}

// @0x14169d9d0
bool AntiAliasRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "SmoothEdge", FUN_14169dbb0, m_80->GetBuffer(), m_80, 0, 0, 0, "MRT_SmoothEdge",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169d9d0, AntiAliasRenderStep, vfunc_15, 462, 0x3EB2DD5D);

// @0x14169dbb0
bool AntiAliasRenderStep::FUN_14169dbb0(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[8];
    float fX = 1.0f / (float)pkBuffer->GetWidth();
    float fY = 1.0f / (float)pkBuffer->GetHeight();
    akOffsets[0] = NiPoint2(-fX, fY);
    akOffsets[1] = NiPoint2(fX, -fY);
    akOffsets[2] = NiPoint2(-fX, -fY);
    akOffsets[3] = NiPoint2(fX, fY);
    akOffsets[4] = NiPoint2(-fX, 0.0f);
    akOffsets[5] = NiPoint2(fX, 0.0f);
    akOffsets[6] = NiPoint2(0.0f, -fY);
    akOffsets[7] = NiPoint2(0.0f, fY);
    FUN_1411781e0(DAT_143ae53e0, akOffsets, 8);
    return true;
}

// @0x14169de50
const NiRTTI* AntiAliasRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x14169de70
bool AntiAliasRenderStep::vfunc_14() { return false; }

// @0x14169de80
bool AntiAliasRenderStep::vfunc_13() { return true; }

// ---- BloomRenderStep (the DirectX SDK HDRLighting bloom passes)

// @0x1400fc2d0
const NiRTTI BloomRenderStep::ms_RTTI("BloomRenderStep", &PostProcessEffect::ms_RTTI);

// @0x14169de90
BloomRenderStep::BloomRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a8(0), m_b0(0)
{
    NiFixedString name("BloomRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169df70
BloomRenderStep::~BloomRenderStep()
{
}

// @0x14169e000
// MS2-FUNCTIONAL: argument temporaries of the five render-click calls are spilled in a different order; behaviour equivalent
bool BloomRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    m_a0 = GetTickCountMs2();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_a8 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_a8)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_b0 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b0)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    for (int i = 0; i < 2; i++)
    {
        m_b8[i] = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
        if (!m_b8[i])
        {
            vfunc_16();
            return false;
        }
    }
    efd::SmartPointer<NiRenderedTexture>* pkTargets = static_cast<efd::SmartPointer<NiRenderedTexture>*>(b);
    if (FUN_140c8f690(FUN_1416b4990(this, "Scene_To_Scene_Scaled", FUN_14169ea50, m_80->GetBuffer(), m_80, 0, 0, m_a8,
        "HDRRenderStep_DownScale4x4", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "SceneScaled_To_BrightPass", 0, 0, m_a8, 0, 0, m_b0,
        "HDRRenderStep_BrightPassFilter", pkTargets[8], 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Bloom1", FUN_14169eb00, m_b0->GetBuffer(), m_b0, 0, 0, m_b8[1],
        "HDRRenderStep_Bloom", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Bloom0", FUN_14169ec70, m_b0->GetBuffer(), m_b8[1], 0, 0, m_b8[0],
        "HDRRenderStep_Bloom", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "FinalScenePass", 0, 0, m_80, 1, 0, 0,
        "HDRRenderStep_FinalScenePass", m_b8[0], 0, pkTargets[6])) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169e000, BloomRenderStep, vfunc_15, 2474, 0x98BA3515);

// @0x14169e9b0
void BloomRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a8 = 0;
    m_b0 = 0;
    for (int i = 0; i < 2; i++)
        m_b8[i] = 0;
}
MS2_REPLACE_METHOD(0x14169e9b0, BloomRenderStep, vfunc_16, 123, 0x7EDDE2F9);

// @0x14169ea40
void BloomRenderStep::vfunc_21()
{
}

// @0x14169ea50
bool FUN_14169ea50(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    FUN_14169ee30(pkBuffer->GetWidth(), pkBuffer->GetHeight(), akOffsets);
    FUN_14169ede0(akOffsets, 0);
    return true;
}

// @0x14169eb00
bool FUN_14169eb00(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    Unk_ShaderColor akWeights[16];
    float afOffsets[16] = {};
    for (int i = 0; i < 16; i++)
        akWeights[i].SetZero();
    FUN_14169efd0(pkBuffer->GetWidth(), afOffsets, akWeights, 3.0f, 2.0f);
    for (int i = 0; i < 16; i++)
        akOffsets[i] = NiPoint2(afOffsets[i], 0.0f);
    FUN_14169ede0(akOffsets, akWeights);
    return true;
}

// @0x14169ec70
bool FUN_14169ec70(NiRenderClick* pkClick, void* pvData)
{
    Ni2DBuffer* pkBuffer = static_cast<Ni2DBuffer*>(pvData);
    NiPoint2 akOffsets[16];
    Unk_ShaderColor akWeights[16];
    float afOffsets[16] = {};
    for (int i = 0; i < 16; i++)
        akWeights[i].SetZero();
    FUN_14169efd0(pkBuffer->GetWidth(), afOffsets, akWeights, 3.0f, 2.0f);
    for (int i = 0; i < 16; i++)
        akOffsets[i] = NiPoint2(0.0f, afOffsets[i]);
    FUN_14169ede0(akOffsets, akWeights);
    return true;
}

// @0x14169ede0
void FUN_14169ede0(const NiPoint2* akOffsets, const Unk_ShaderColor* akWeights)
{
    FUN_1411781e0(DAT_143ae53e8, akOffsets, 16);
    if (akWeights != 0)
        FUN_14135db70(DAT_143ae53f0, akWeights, 16);
}

// @0x14169ee30
void FUN_14169ee30(unsigned int uiWidth, unsigned int uiHeight, NiPoint2* akOffsets)   // GetSampleOffsets_DownScale4x4
{
    float tU = 1.0f / (float)uiWidth;
    float tV = 1.0f / (float)uiHeight;
    int iIndex = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            akOffsets[iIndex].x = ((float)x - 1.5f) * tU;
            akOffsets[iIndex].y = ((float)y - 1.5f) * tV;
            iIndex++;
        }
    }
}

// @0x14169ef20
float FUN_14169ef20(float x, float y, float fRho)   // GaussianDistribution
{
    float g = 1.0f / __imp_sqrtf(2.0f * 3.14159265f * fRho * fRho);
    g *= __imp_expf(-(x * x + y * y) / (2.0f * fRho * fRho));
    return g;
}

// @0x14169efd0
// MS2-FUNCTIONAL: our build adds a /GS cookie for the Unk_ShaderColor temporaries (the exe has none); behaviour equivalent
void FUN_14169efd0(unsigned int uiTexSize, float* afTexCoordOffset, Unk_ShaderColor* akColorWeight, float fDeviation,
    float fMultiplier)   // GetSampleOffsets_Bloom
{
    float tu = 1.0f / (float)uiTexSize;
    float fWeight = fMultiplier * FUN_14169ef20(0.0f, 0.0f, fDeviation);
    akColorWeight[0] = Unk_ShaderColor(fWeight, fWeight, fWeight, 1.0f);
    afTexCoordOffset[0] = 0.0f;
    for (int i = 1; i < 8; i++)
    {
        fWeight = fMultiplier * FUN_14169ef20((float)i, 0.0f, fDeviation);
        afTexCoordOffset[i] = (float)i * tu;
        akColorWeight[i] = Unk_ShaderColor(fWeight, fWeight, fWeight, 1.0f);
    }
    for (int i = 8; i < 15; i++)
    {
        akColorWeight[i] = akColorWeight[i - 7];
        afTexCoordOffset[i] = -afTexCoordOffset[i - 7];
    }
}

// @0x14169f340
const NiRTTI* BloomRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x14169f350
bool BloomRenderStep::vfunc_14() { return false; }

// @0x14169f360
bool BloomRenderStep::vfunc_13() { return false; }

// ---- ColorPerspectiveRenderStep

// @0x1400fc300
const NiRTTI ColorPerspectiveRenderStep::ms_RTTI("ColorPerspectiveRenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x14169f3a0
ColorPerspectiveRenderStep::ColorPerspectiveRenderStep(unsigned __int64 a, unsigned int b)
    : ReloadablePostProcess(a, "ColorPerspective", 1, b), m_b8(0)
{
    NiFixedString name("ColorPerspectiveRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169f460
bool ColorPerspectiveRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    m_b8 = static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1];
    if (!vfunc_23())
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169f460, ColorPerspectiveRenderStep, vfunc_15, 142, 0x1D07049C);

// @0x14169f500
// MS2-FUNCTIONAL: one extra 8-byte stack slot in our frame shifts the spill offsets; behaviour equivalent
bool ColorPerspectiveRenderStep::vfunc_23()
{
    NiRenderClick* pkClick = GetRenderClickByName("ColorPerspectiveRenderClick");
    if (pkClick != 0)
        RemoveRenderClick(pkClick);
    return FUN_140c8f690(FUN_1416b4990(this, "ColorPerspectiveRenderClick", 0, 0, m_80, 0, 3, 0, "ColorPerspective", m_b8, 0, 0)) != 0;
}
MS2_REPLACE_METHOD(0x14169f500, ColorPerspectiveRenderStep, vfunc_23, 341, 0x047DD5E6);

// @0x14169f6a0 (implicit destructor: no vptr store, unlike the user-declared ones)

// @0x14169f850
const NiRTTI* ColorPerspectiveRenderStep::GetRTTI() const { return &ms_RTTI; }

// ---- DepthOfFieldRenderStep

// @0x1400fc330
const NiRTTI DepthOfFieldRenderStep::ms_RTTI("DepthOfFieldRenderStep", &NiRenderStep::ms_RTTI);

// @0x14169fd30
DepthOfFieldRenderStep::DepthOfFieldRenderStep(unsigned __int64 a, unsigned int b)
    : PostProcessEffect(a, b), m_a0(0), m_a8(0), m_b0(0), m_b8(0)
{
    NiFixedString name("DepthOfFieldRenderStep");
    FUN_140c8f950(this, name);
}

// @0x14169fe10
DepthOfFieldRenderStep::~DepthOfFieldRenderStep()
{
}

// @0x14169fe90
// MS2-FUNCTIONAL: argument temporaries of the seven render-click calls are spilled in a different order; behaviour equivalent
bool DepthOfFieldRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(2);
    m_a0 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a0)
    {
        vfunc_16();
        return false;
    }
    m_a8 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a8)
    {
        vfunc_16();
        return false;
    }
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_b0 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b0)
    {
        vfunc_16();
        return false;
    }
    m_b8 = NiRenderedTexture::Create(uiWidth / 4, uiHeight / 4, pkRenderer, kPrefs, 0x100);
    if (!m_b8)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DownSample", 0, 0, m_80, 0, 0, m_b0, "Dof_DownSample", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_HorzBlur", 0, 0, m_b0, 0, 0, m_b8, "Dof_HorzBlur", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_VertBlur", 0, 0, m_b8, 0, 0, m_b0, "Dof_VertBlur", 0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurMask", 0, 0, m_b0, 0, 0, m_a0, "Dof_DepthBlurMask",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurHorzFore", 0, 0, m_a0, 0, 0, m_a8, "Dof_DepthBlurHorzFore", m_a0, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthBlurVertFore", 0, 0, m_a8, 0, 0, m_a0, "Dof_DepthBlurVertFore", m_a8, 0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "Dof_DepthOfField", 0, 0, m_b0, 1, 0, 0, "Dof_DepthOfField", m_80, m_a0, 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x14169fe90, DepthOfFieldRenderStep, vfunc_15, 2710, 0x510CFB83);

// @0x1416a0930
void DepthOfFieldRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a0 = 0;
    m_a8 = 0;
    m_b0 = 0;
    m_b8 = 0;
}
MS2_REPLACE_METHOD(0x1416a0930, DepthOfFieldRenderStep, vfunc_16, 108, 0x0051C425);

// @0x1416a0a00
const NiRTTI* DepthOfFieldRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a0a10
bool DepthOfFieldRenderStep::vfunc_14() { return false; }

// @0x1416a0a20
bool DepthOfFieldRenderStep::vfunc_13() { return false; }

// ---- FadeInOutRenderStep

extern int DAT_1439f823c;           // default fade-out time (ms)
extern int DAT_1439f8240;           // default fade-in time (ms)
extern float DAT_1439f8248;         // fade constant scale
extern NiFixedString DAT_143ae5320; // the fade shader constant name

// @0x1400fc380
const NiRTTI FadeInOutRenderStep::ms_RTTI("FadeInOutRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
float FadeInOutRenderStep::ms_fAlpha;
unsigned int FadeInOutRenderStep::ms_uiStartTime;
int FadeInOutRenderStep::ms_iState;
// @0x1400fc370
int FadeInOutRenderStep::ms_iFadeOutTime = DAT_1439f823c;
// @0x1400fc360
int FadeInOutRenderStep::ms_iFadeInTime = DAT_1439f8240;

// @0x1416a0a30
FadeInOutRenderStep::FadeInOutRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("FadeInOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a0ab0
FadeInOutRenderStep::~FadeInOutRenderStep()
{
    NiFixedString name("FadeInOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a0b20
bool FadeInOutRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    ms_iState = 0;
    ms_uiStartTime = GetTickCountMs2();
    NiRenderClick* pkClick = static_cast<NiRenderClick*>(FUN_140c8f690(FUN_1416b4990(this, "FadeInOut", FUN_1416a0cd0, this, m_80,
        0, 0, 0, "FadeInOut", static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2],
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    pkClick->SetClearAllBuffers(true);
    return true;
}

// @0x1416a0cd0
// MS2-FUNCTIONAL: the exe spills the elapsed time and converts the duration first (16 bytes more frame); behaviour equivalent
bool FadeInOutRenderStep::FUN_1416a0cd0(NiRenderClick* pkClick, void* pvData)
{
    if (ms_iState == 2)
        return true;
    int iDuration = (ms_iState == 1) ? ms_iFadeOutTime : ms_iFadeInTime;
    if (iDuration != 0)
        ms_fAlpha = ((float)GetTickCountMs2() - (float)ms_uiStartTime) / (float)iDuration;
    else
        ms_fAlpha = 1.0f;
    if (ms_iState == 1)
    {
        ms_fAlpha = 1.0f - ms_fAlpha;
        if (ms_fAlpha <= 0.0f)
        {
            ms_fAlpha = 0.0f;
            ms_iFadeOutTime = DAT_1439f823c;
            ms_iState = 2;
        }
    }
    else if (ms_fAlpha >= 1.0f)
    {
        FadeInOutRenderStep* pkStep = static_cast<FadeInOutRenderStep*>(pvData);
        reinterpret_cast<Unk_PPOwner*>(pkStep->m_70)->FUN_1416a0fb0(13);
        ms_fAlpha = 1.0f;
        ms_iFadeInTime = DAT_1439f8240;
        ms_iState = 0;
    }
    ms_fAlpha = ms_fAlpha * (ms_fAlpha * DAT_1439f8248);
    FUN_1409a5770(DAT_143ae5320, &ms_fAlpha, 1);
    return true;
}

// @0x1416a0fb0
void Unk_PPOwner::FUN_1416a0fb0(int nEvent)
{
    m_kEvents.AddTail(nEvent);
}

// @0x1416a0fe0
const NiRTTI* FadeInOutRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a0ff0
bool FadeInOutRenderStep::vfunc_14() { return false; }

// @0x1416a1000
bool FadeInOutRenderStep::vfunc_13() { return false; }

// ---- FadeInRenderStep

// @0x1400fc3b0
const NiRTTI FadeInRenderStep::ms_RTTI("FadeInRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
float FadeInRenderStep::ms_fAlpha;
unsigned int FadeInRenderStep::ms_uiStartTime;

// @0x1416a1010
FadeInRenderStep::FadeInRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("FadeInRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1090
FadeInRenderStep::~FadeInRenderStep()
{
}

// @0x1416a10c0
bool FadeInRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    ms_uiStartTime = GetTickCountMs2();
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "FadeIn", FUN_1416a1260, this, m_80, 0, 0, 0, "FadeInOut",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}

// @0x1416a1260
bool FadeInRenderStep::FUN_1416a1260(NiRenderClick* pkClick, void* pvData)
{
    ms_fAlpha = ((float)GetTickCount() - (float)ms_uiStartTime) / (float)DAT_1439f8240;
    if (ms_fAlpha >= 1.0f)
    {
        FadeInRenderStep* pkStep = static_cast<FadeInRenderStep*>(pvData);
        reinterpret_cast<Unk_PPOwner*>(pkStep->m_70)->FUN_1416a0fb0(14);
        ms_fAlpha = 1.0f;
    }
    ms_fAlpha = ms_fAlpha * ms_fAlpha;
    FUN_1409a5770(DAT_143ae5320, &ms_fAlpha, 1);
    return true;
}

// @0x1416a1380
const NiRTTI* FadeInRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1390
bool FadeInRenderStep::vfunc_14() { return false; }

// @0x1416a13a0
bool FadeInRenderStep::vfunc_13() { return false; }

// ---- GaussianBlurRenderStep

extern NiFixedString DAT_143ae5460;     // outer blur shader constants, reset by vfunc_22
extern NiFixedString DAT_143ae5468;

// @0x1400fc3e0
const NiRTTI GaussianBlurRenderStep::ms_RTTI("GaussianBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a13b0
GaussianBlurRenderStep::GaussianBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a0(0)
{
    NiFixedString name("GaussianBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1450
GaussianBlurRenderStep::~GaussianBlurRenderStep()
{
}

// @0x1416a1490
// MS2-FUNCTIONAL: argument temporaries of the two render-click calls are spilled in a different order; behaviour equivalent
bool GaussianBlurRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
    unsigned int uiWidth = pkRTG->GetWidth(0);
    unsigned int uiHeight = pkRTG->GetHeight(0);
    NiTexture::FormatPrefs kPrefs;
    kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
    m_a0 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, 0x100);
    if (!m_a0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_H", 0, 0, m_80, 0, 0, m_a0, "OuterGaussianBlur_H",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    if (FUN_140c8f690(FUN_1416b4990(this, "OuterBlur_V", 0, 0, m_a0, 0, 0, 0, "OuterGaussianBlur_V",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)) == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1490, GaussianBlurRenderStep, vfunc_15, 973, 0xA5640F8D);

// @0x1416a1870
void GaussianBlurRenderStep::vfunc_16()
{
    PostProcessEffect::vfunc_16();
    m_a0 = 0;
}
MS2_REPLACE_METHOD(0x1416a1870, GaussianBlurRenderStep, vfunc_16, 45, 0x99C977BC);

// @0x1416a18b0
void GaussianBlurRenderStep::vfunc_22()
{
    float fZero = 0.0f;
    FUN_1409a5770(DAT_143ae5460, &fZero, 1);
    FUN_1409a5770(DAT_143ae5468, &fZero, 1);
}
MS2_REPLACE_METHOD(0x1416a18b0, GaussianBlurRenderStep, vfunc_22, 69, 0x94FA78C6);

// @0x1416a1960
const NiRTTI* GaussianBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1970
bool GaussianBlurRenderStep::vfunc_14() { return false; }

// @0x1416a1980
bool GaussianBlurRenderStep::vfunc_13() { return false; }

// ---- HeatShimmerRenderStep

// @0x1400fc410
const NiRTTI HeatShimmerRenderStep::ms_RTTI("HeatShimmerRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a1990
HeatShimmerRenderStep::HeatShimmerRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("HeatShimmerRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1a10
HeatShimmerRenderStep::~HeatShimmerRenderStep()
{
}

// @0x1416a1a40
bool HeatShimmerRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "HeatShimmer", 0, this, m_80, 0, 0, 0, "HeatShimmer",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1a40, HeatShimmerRenderStep, vfunc_15, 382, 0xF8E30FF5);

// @0x1416a1c20
const NiRTTI* HeatShimmerRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1c30
bool HeatShimmerRenderStep::vfunc_14() { return false; }

// @0x1416a1c40
bool HeatShimmerRenderStep::vfunc_13() { return false; }

// ---- MonochromeRenderStep

// @0x1400fc440
const NiRTTI MonochromeRenderStep::ms_RTTI("MonochromeRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a1c50
MonochromeRenderStep::MonochromeRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("MonochromeRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1cd0
MonochromeRenderStep::~MonochromeRenderStep()
{
    PostProcessEffect::vfunc_16();
}

// @0x1416a1d20
bool MonochromeRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* pkClick = FUN_140c8f690(FUN_1416b4990(this, "Monochrome", 0, 0, m_80, 0, 0, 0, "Monochrome",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2], static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x1416a1d20, MonochromeRenderStep, vfunc_15, 378, 0xC021FB8F);

// @0x1416a1f00
const NiRTTI* MonochromeRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a1f10
bool MonochromeRenderStep::vfunc_14() { return false; }

// @0x1416a1f20
bool MonochromeRenderStep::vfunc_13() { return false; }

// ---- OuterBlurRenderStep

// @0x1400fc4a0
const NiRTTI OuterBlurRenderStep::ms_RTTI("OuterBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);

// @0x1416a2440
OuterBlurRenderStep::OuterBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("OuterBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a24c0
OuterBlurRenderStep::~OuterBlurRenderStep()
{
    PostProcessEffect::vfunc_16();
}

// @0x1416a2560
const NiRTTI* OuterBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2570
bool OuterBlurRenderStep::vfunc_14() { return false; }

// @0x1416a2580
bool OuterBlurRenderStep::vfunc_13() { return false; }

// ---- OverdrawRenderStep

// @0x1400fc4d0
const NiRTTI OverdrawRenderStep::ms_RTTI("OverdrawRenderStep", &ReloadablePostProcess::ms_RTTI);

// @0x1416a2590
OverdrawRenderStep::OverdrawRenderStep(unsigned __int64 a, unsigned int b) : ReloadablePostProcess(a, "OverdrawColorize", 0, b)
{
    NiFixedString name("OverdrawRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a2640
bool OverdrawRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, b))
        return false;
    vfunc_23();
    return true;
}
MS2_REPLACE_METHOD(0x1416a2640, OverdrawRenderStep, vfunc_15, 74, 0x483F2540);

// @0x1416a2690
// MS2-FUNCTIONAL: one extra 8-byte stack slot in our frame shifts the spill offsets; behaviour equivalent
bool OverdrawRenderStep::vfunc_23()
{
    NiRenderClick* pkClick = GetRenderClickByName("Overdraw");
    if (pkClick != 0)
        RemoveRenderClick(pkClick);
    return FUN_140c8f690(FUN_1416b4990(this, "Overdraw", 0, 0, m_80, 0, 3, 0, "OverdrawColorize",
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(m_98)[9], 0, 0)) != 0;
}
MS2_REPLACE_METHOD(0x1416a2690, OverdrawRenderStep, vfunc_23, 351, 0xA9CC357A);

// @0x1416a2870
const NiRTTI* OverdrawRenderStep::GetRTTI() const { return &ms_RTTI; }

// ---- PostProcessEffect / ReloadablePostProcess

void FUN_1427b7820(NiShaderLibrary* pkLibrary, void** ppvOut, const char* pcName);   // NiD3DXEffect library: load the named effect

// @0x1400fc500
const NiRTTI PostProcessEffect::ms_RTTI("PostProcessEffect", &NiDefaultClickRenderStep::ms_RTTI);
// @0x1400fc530
const NiRTTI ReloadablePostProcess::ms_RTTI("ReloadablePostProcess", &PostProcessEffect::ms_RTTI);

// @0x1416a2880
PostProcessEffect::PostProcessEffect(unsigned __int64 a, unsigned int b) : m_70(a), m_80(0), m_88(0)
{
    m_90 = 0;
}

// @0x1416a2910
PostProcessEffect::~PostProcessEffect()
{
    m_80 = 0;
}

// @0x1416a2990
// MS2-FUNCTIONAL: locals sit one slot higher and m_90 (unsigned char in the shared header, bool in the exe) is returned via a compare
bool PostProcessEffect::vfunc_15(unsigned int a, void* b)
{
    RemoveAllRenderClicks();
    m_98 = b;
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    if (pkRenderer != 0)
    {
        NiRenderTargetGroup* pkRTG = pkRenderer->GetDefaultRenderTargetGroup();
        if (pkRTG != 0)
        {
            unsigned int uiWidth = pkRTG->GetWidth(0);
            unsigned int uiHeight = pkRTG->GetHeight(0);
            unsigned short usMSAA = pkRTG->GetBuffer(0)->GetMSAAPref();
            NiTexture::FormatPrefs kPrefs;
            kPrefs.m_ePixelLayout = static_cast<NiTexture::FormatPrefs::PixelLayout>(a);
            if (m_80 = NiRenderedTexture::Create(uiWidth, uiHeight, pkRenderer, kPrefs, usMSAA))
                m_88 = NiRenderTargetGroup::Create(m_80->GetBuffer(), pkRenderer, true, true);
        }
    }
    m_90 = m_80 != 0;
    return m_90;
}
MS2_REPLACE_METHOD(0x1416a2990, PostProcessEffect, vfunc_15, 432, 0x140FA897);

// @0x1416a2b50
void PostProcessEffect::vfunc_16()
{
    m_98 = 0;
    m_80 = 0;
    m_88 = 0;
    m_90 = 0;
}
MS2_REPLACE_METHOD(0x1416a2b50, PostProcessEffect, vfunc_16, 84, 0x7F856485);

// @0x1416a2bb0
ReloadablePostProcess::ReloadablePostProcess(unsigned __int64 a, const NiFixedString& name, unsigned char flag, unsigned int b)
    : PostProcessEffect(a, b)
{
    m_b0 = 0;
    m_a8 = flag;
    m_a0 = name;
}

// @0x1416a2c60
// MS2-FUNCTIONAL: the exe keeps the factory/library in different stack slots (frame 0x48 vs 0x38); behaviour equivalent
void ReloadablePostProcess::vfunc_21()
{
    if (!m_a8)
        return;
    NiShaderFactory* pkFactory = NiShaderFactory::GetInstance();
    NiShaderLibrary* pkLibrary = pkFactory->GetFirstLibrary();
    while (true)
    {
        if (strcmp(pkLibrary->GetName(), "NiD3DXEffectShaderLib") == 0)
        {
            FUN_1427b7820(pkLibrary, &m_b0, m_a0);
            if (m_b0 != 0)
                pkLibrary->SetShaderLibraryDesc(static_cast<NiShaderLibraryDesc*>(m_b0));
            if (!vfunc_23())
                vfunc_16();
            return;
        }
        pkLibrary = pkFactory->GetNextLibrary();
    }
}
MS2_REPLACE_METHOD(0x1416a2c60, ReloadablePostProcess, vfunc_21, 288, 0xF934429C);

// @0x1416a2e90
const NiRTTI* PostProcessEffect::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2ea0
const NiRTTI* ReloadablePostProcess::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2eb0
bool PostProcessEffect::vfunc_14() { return false; }

// @0x1416a2ec0
bool PostProcessEffect::vfunc_13() { return false; }

// ---- MotionBlurRenderStep

// @0x1400fc470
const NiRTTI MotionBlurRenderStep::ms_RTTI("MotionBlurRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
NiTexturingProperty* MotionBlurRenderStep::ms_pkTexProp;

// @0x1416a1f30
MotionBlurRenderStep::MotionBlurRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b)
{
    NiFixedString name("MotionBlurRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416a1fb0
MotionBlurRenderStep::~MotionBlurRenderStep()
{
}

// @0x1416a1fe0
bool MotionBlurRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    NiViewRenderClick* pkClick = static_cast<NiViewRenderClick*>(FUN_140c8f690(FUN_1416b4990(this, "MotionBlur", FUN_1416a21c0, this,
        m_80, 0, 0, 0, "MotionBlur", static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[2],
        static_cast<efd::SmartPointer<NiRenderedTexture>*>(b)[1], 0)));
    if (pkClick == 0)
    {
        vfunc_16();
        return false;
    }
    NiScreenFillingRenderView* pkView = NiDynamicCast(NiScreenFillingRenderView, pkClick->GetRenderViews().GetHead());
    ms_pkTexProp = static_cast<NiTexturingProperty*>(pkView->GetScreenFillingQuad().GetProperty(NiProperty::TEXTURING));
    return true;
}

// @0x1416a21c0
// MS2-FUNCTIONAL: our NiNew expansion keeps the MemHint differently (exe spills its address); behaviour equivalent
bool MotionBlurRenderStep::FUN_1416a21c0(NiRenderClick* pkClick, void* pvData)
{
    int iFrame = reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->m_iFrame;
    NiTexturingProperty::ShaderMap* pkMap0 = NiNew NiTexturingProperty::ShaderMap(
        reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->FUN_1416a23f0(iFrame + 3), 1);
    int iPrev = (reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->m_iFrame + 1) % 2;
    NiTexturingProperty::ShaderMap* pkMap1 = NiNew NiTexturingProperty::ShaderMap(
        reinterpret_cast<Unk_PPOwner*>(static_cast<MotionBlurRenderStep*>(pvData)->m_70)->FUN_1416a23f0(iPrev + 3), 0);
    ms_pkTexProp->SetShaderMap(0, pkMap0);
    ms_pkTexProp->SetShaderMap(1, pkMap1);
    return true;
}

// @0x1416a23f0
NiRenderedTexture* Unk_PPOwner::FUN_1416a23f0(int nIndex)
{
    return m_aspTextures[nIndex];
}

// @0x1416a23e0
const NiRTTI* MotionBlurRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416a2420
bool MotionBlurRenderStep::vfunc_14() { return false; }

// @0x1416a2430
bool MotionBlurRenderStep::vfunc_13() { return false; }
