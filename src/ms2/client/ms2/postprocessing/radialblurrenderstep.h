// RadialBlurRenderStep (RTTI name): radial blur post-process step. 0xa0 bytes (PostProcessEffect + nothing), 23 vftable slots.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"

class RadialBlurRenderStep : public PostProcessEffect {
public:
    RadialBlurRenderStep(unsigned __int64 a, unsigned int b);   // 0x1416b9e50
    virtual ~RadialBlurRenderStep();                            // 0x1416b9ed0
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416ba0e0
    virtual bool vfunc_13();                                    // 0x1416ba100
    virtual bool vfunc_14();                                    // 0x1416ba0f0
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416b9f00

    static const NiRTTI ms_RTTI;                                // 0x143ae5048
};
MS2_CHECK_SIZE(RadialBlurRenderStep, 0xa0);
