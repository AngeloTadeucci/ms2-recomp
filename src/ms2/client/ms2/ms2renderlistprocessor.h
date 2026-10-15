// ms2renderlistprocessor.h - MS2RenderListProcessor: the game's NiShaderSortProcessor subclass (0xe8 bytes; vftable
// 0x142f22e78: dtor, DeleteThis, GetRTTI 0x1414e6700, PreRenderProcessList 0x1414dc0d0, slot 4 0x141d28230,
// ReleaseCaches). Base of MS2OverdrawProcessor. NOT yet recovered as a unit (?\ms2renderlistprocessor.cpp, 0x1414dbf30..);
// this header declares only what the derived classes need. Fields +0xb0..+0xe8 are unrecovered (ctor 0x1414dbf30).
#pragma once
#include "ms2/ms2layout.h"
#include <NiShaderSortProcessor.h>

class MS2RenderListProcessor : public NiShaderSortProcessor
{
    NiDeclareRTTI;

public:
    MS2RenderListProcessor();                               // 0x1414dbf30
    virtual ~MS2RenderListProcessor();                      // 0x1414dc020, ??_G 0x1414e5d30
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414dc0d0

protected:
    char m_pad_b0[0x38];
};
MS2_CHECK_SIZE(MS2RenderListProcessor, 0xe8);
