// ScreenMaskingRenderStep (RTTI name): draws the screen-mask texture (title_make_ch.tga). 0xa0 bytes (PostProcessEffect + nothing).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"

class ScreenMaskingRenderStep : public PostProcessEffect {
public:
    ScreenMaskingRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416ba110
    virtual ~ScreenMaskingRenderStep();                            // 0x1416ba190
    virtual const NiRTTI* GetRTTI() const;                         // 0x1416ba7c0
    virtual bool vfunc_13();                                       // 0x1416ba7e0
    virtual bool vfunc_14();                                       // 0x1416ba7d0
    virtual bool vfunc_15(unsigned int a, void* b);                // 0x1416ba1c0
    virtual void vfunc_16();                                       // 0x1416ba5d0
    virtual void vfunc_22();                                       // 0x1416ba750

    static const NiRTTI ms_RTTI;                                   // 0x143ae5060
};
MS2_CHECK_SIZE(ScreenMaskingRenderStep, 0xa0);
