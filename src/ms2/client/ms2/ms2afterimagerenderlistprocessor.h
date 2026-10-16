// ms2afterimagerenderlistprocessor.h - MS2AfterImageRenderListProcessor (0xe8 bytes, vftable 0x142f22eb0, no RTTI of its
// own): the render-list processor of the after-image render step; it skips the objects under an EffectNode.
// Owning unit: ?\ms2renderlistprocessor.cpp. (afterimageitem.h currently carries a reduced copy of this declaration.)
#pragma once
#include "ms2/client/ms2/ms2renderlistprocessor.h"

class MS2AfterImageRenderListProcessor : public MS2RenderListProcessor
{
public:
    MS2AfterImageRenderListProcessor();                     // 0x1414dec90
    // implicit virtual dtor 0x1414e5180, ??_G 0x1414e5cd0
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414decd0
};
MS2_CHECK_SIZE(MS2AfterImageRenderListProcessor, 0xe8);
