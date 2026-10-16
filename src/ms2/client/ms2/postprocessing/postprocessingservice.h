// postprocessingservice.h - the render steps compiled into client\ms2\postprocessing\postprocessingservice.cpp (RTTI names),
// recovered header. The PostProcessEffect / ReloadablePostProcess bases are in ms2/placeholder/postprocesseffect.h; their
// member functions live in this unit too.
// Several steps register their RTTI with NiDefaultClickRenderStep (0x143afa7a8) or AntiAlias/DoF with NiRenderStep (0x143afaa00) as parent,
// as the original NiImplementRTTI lines did.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"
#include <NiTPointerList.h>

class Ni2DBuffer;
class NiRenderClick;
class NiTexturingProperty;

// The owner passed to the steps as PostProcessEffect::m_70 (the PostProcessingService); only the event queue is known.
class Unk_PPOwner
{
public:
    void FUN_1416a0fb0(int nEvent);     // queue an event (13 = fade-in finished)
    NiRenderedTexture* FUN_1416a23f0(int nIndex);   // m_aspTextures[nIndex]

    char m_pad_0[0x88];
    int m_iFrame;                       // +0x88 (motion blur ping-pong frame)
    char m_pad_8c[0x110 - 0x8c];
    efd::SmartPointer<NiRenderedTexture> m_aspTextures[5];  // +0x110 (3/4: motion blur history)
    char m_pad_138[0x198 - 0x138];
    NiTPointerList<int> m_kEvents;      // +0x198
};

// The service's shared targets passed to vfunc_15 as `b`: +8 the scene colour texture, +0x10 the depth texture.
struct Unk_PPTargets
{
    void* m_0;
    efd::SmartPointer<NiRenderedTexture> m_8;
    efd::SmartPointer<NiRenderedTexture> m_10;
};

class AntiAliasRenderStep : public PostProcessEffect {
public:
    AntiAliasRenderStep(unsigned __int64 a, unsigned int b);    // 0x14169d920
    virtual ~AntiAliasRenderStep();                             // 0x14169d9a0
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169de50
    virtual bool vfunc_13();                                    // 0x14169de80
    virtual bool vfunc_14();                                    // 0x14169de70
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169d9d0
    static bool FUN_14169dbb0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: texel offsets of the buffer

    static const NiRTTI ms_RTTI;                                // 0x143ae4558
};
MS2_CHECK_SIZE(AntiAliasRenderStep, 0xa0);

class BloomRenderStep : public PostProcessEffect {
public:
    BloomRenderStep(unsigned __int64 a, unsigned int b);        // 0x14169de90
    virtual ~BloomRenderStep();                                 // 0x14169df70
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169f340
    virtual bool vfunc_13();                                    // 0x14169f360
    virtual bool vfunc_14();                                    // 0x14169f350
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169e000
    virtual void vfunc_16();                                    // 0x14169e9b0
    virtual void vfunc_21();                                    // 0x14169ea40

    static const NiRTTI ms_RTTI;                                // 0x143ae4568

    unsigned int m_a0;      // tick count when the targets were created
    efd::SmartPointer<NiRenderedTexture> m_a8;
    efd::SmartPointer<NiRenderedTexture> m_b0;
    efd::SmartPointer<NiRenderedTexture> m_b8[2];
};
MS2_CHECK_OFFSET(BloomRenderStep, m_b8, 0xb8);

class ColorPerspectiveRenderStep : public ReloadablePostProcess {
public:
    ColorPerspectiveRenderStep(unsigned __int64 a, unsigned int b);    // 0x14169f3a0
    // ~ColorPerspectiveRenderStep() implicit                   // 0x14169f6a0
    virtual const NiRTTI* GetRTTI() const;                      // 0x14169f850
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169f460
    virtual bool vfunc_23();                                    // 0x14169f500

    static const NiRTTI ms_RTTI;                                // 0x143ae4578

    efd::SmartPointer<NiRenderedTexture> m_b8;
};
MS2_CHECK_OFFSET(ColorPerspectiveRenderStep, m_b8, 0xb8);

class DepthOfFieldRenderStep : public PostProcessEffect {
public:
    DepthOfFieldRenderStep(unsigned __int64 a, unsigned int b); // 0x14169fd30
    virtual ~DepthOfFieldRenderStep();                          // 0x14169fe10
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a0a00
    virtual bool vfunc_13();                                    // 0x1416a0a20
    virtual bool vfunc_14();                                    // 0x1416a0a10
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x14169fe90
    virtual void vfunc_16();                                    // 0x1416a0930

    static const NiRTTI ms_RTTI;                                // 0x143ae4588

    efd::SmartPointer<NiRenderedTexture> m_a0;
    efd::SmartPointer<NiRenderedTexture> m_a8;
    efd::SmartPointer<NiRenderedTexture> m_b0;
    efd::SmartPointer<NiRenderedTexture> m_b8;
};
MS2_CHECK_OFFSET(DepthOfFieldRenderStep, m_b8, 0xb8);

class FadeInOutRenderStep : public PostProcessEffect {
public:
    FadeInOutRenderStep(unsigned __int64 a, unsigned int b);    // 0x1416a0a30
    virtual ~FadeInOutRenderStep();                             // 0x1416a0ab0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a0fe0
    virtual bool vfunc_13();                                    // 0x1416a1000
    virtual bool vfunc_14();                                    // 0x1416a0ff0
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a0b20
    static bool FUN_1416a0cd0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: advance the fade, set the constant

    static const NiRTTI ms_RTTI;                                // 0x143ae45a8
    static float ms_fAlpha;                                     // 0x143ae4598
    static unsigned int ms_uiStartTime;                         // 0x143ae459c
    static int ms_iState;                                       // 0x143ae45a0 (0 fading in, 1 fading out, 2 idle)
    static int ms_iFadeOutTime;                                 // 0x143ae45b8 (initialised from DAT_1439f823c)
    static int ms_iFadeInTime;                                  // 0x143ae45bc (initialised from DAT_1439f8240)
};

class FadeInRenderStep : public PostProcessEffect {
public:
    FadeInRenderStep(unsigned __int64 a, unsigned int b);       // 0x1416a1010
    virtual ~FadeInRenderStep();                                // 0x1416a1090
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1380
    virtual bool vfunc_13();                                    // 0x1416a13a0
    virtual bool vfunc_14();                                    // 0x1416a1390
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a10c0
    static bool FUN_1416a1260(NiRenderClick* pkClick, void* pvData);   // pre-render callback: advance the fade-in

    static const NiRTTI ms_RTTI;                                // 0x143ae45c8
    static float ms_fAlpha;                                     // 0x143ae45c0
    static unsigned int ms_uiStartTime;                         // 0x143ae45c4
};

class GaussianBlurRenderStep : public PostProcessEffect {
public:
    GaussianBlurRenderStep(unsigned __int64 a, unsigned int b); // 0x1416a13b0
    virtual ~GaussianBlurRenderStep();                          // 0x1416a1450
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1960
    virtual bool vfunc_13();                                    // 0x1416a1980
    virtual bool vfunc_14();                                    // 0x1416a1970
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1490
    virtual void vfunc_16();                                    // 0x1416a1870
    virtual void vfunc_22();                                    // 0x1416a18b0

    static const NiRTTI ms_RTTI;                                // 0x143ae45d8

    efd::SmartPointer<NiRenderedTexture> m_a0;
};
MS2_CHECK_OFFSET(GaussianBlurRenderStep, m_a0, 0xa0);

class HeatShimmerRenderStep : public PostProcessEffect {
public:
    HeatShimmerRenderStep(unsigned __int64 a, unsigned int b);  // 0x1416a1990
    virtual ~HeatShimmerRenderStep();                           // 0x1416a1a10
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1c20
    virtual bool vfunc_13();                                    // 0x1416a1c40
    virtual bool vfunc_14();                                    // 0x1416a1c30
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1a40

    static const NiRTTI ms_RTTI;                                // 0x143ae45e8
};

class MonochromeRenderStep : public PostProcessEffect {
public:
    MonochromeRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416a1c50
    virtual ~MonochromeRenderStep();                            // 0x1416a1cd0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a1f00
    virtual bool vfunc_13();                                    // 0x1416a1f20
    virtual bool vfunc_14();                                    // 0x1416a1f10
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1d20

    static const NiRTTI ms_RTTI;                                // 0x143ae45f8
};

class MotionBlurRenderStep : public PostProcessEffect {
public:
    MotionBlurRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416a1f30
    virtual ~MotionBlurRenderStep();                            // 0x1416a1fb0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a23e0
    virtual bool vfunc_13();                                    // 0x1416a2430
    virtual bool vfunc_14();                                    // 0x1416a2420
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a1fe0
    static bool FUN_1416a21c0(NiRenderClick* pkClick, void* pvData);   // pre-render callback: bind the history textures

    static const NiRTTI ms_RTTI;                                // 0x143ae4610
    static NiTexturingProperty* ms_pkTexProp;                   // 0x143ae4608 (the screen quad's texturing property)
};

class OuterBlurRenderStep : public PostProcessEffect {
public:
    OuterBlurRenderStep(unsigned __int64 a, unsigned int b);    // 0x1416a2440
    virtual ~OuterBlurRenderStep();                             // 0x1416a24c0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a2560
    virtual bool vfunc_13();                                    // 0x1416a2580
    virtual bool vfunc_14();                                    // 0x1416a2570

    static const NiRTTI ms_RTTI;                                // 0x143ae4620
};

class OverdrawRenderStep : public ReloadablePostProcess {
public:
    OverdrawRenderStep(unsigned __int64 a, unsigned int b);     // 0x1416a2590
    // ~OverdrawRenderStep() implicit                           // 0x1416a27f0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416a2870
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416a2640
    virtual bool vfunc_23();                                    // 0x1416a2690

    static const NiRTTI ms_RTTI;                                // 0x143ae4630
};
