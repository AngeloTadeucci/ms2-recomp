// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\worldfadeoutrenderstep.cpp
// MS2-RANGE: 0x1400fca70-0x1400fcaa0 .text$di
// MS2-RANGE: 0x1416bad00-0x1416bb2e0 .text$mn
// NOTE: the units.tsv guess for this unit also lists the 36 NiFixedString name statics' initializers (0x1400fcaa0-0x1400fd100)
// and the three name-table functions 0x1416bb2e0/0x1416bb5f0/0x1416bc0f0; those belong to a header-defined name table
// (COMDAT .text$di sorted alphabetically), not to this source file, and are not recovered here.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\postprocessing\\worldfadeoutrenderstep.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldfadeoutrenderstep.h"
#include <NiRenderer.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>
#include "hook/ms2hook.h"

// Unrecovered callees (real types unknown).
unsigned char FUN_1412642d0(void* step);
NiRenderedTexture* FUN_1416a23f0(unsigned __int64 p, int n);   // the step's input texture n
void FUN_1416a0fb0(unsigned __int64 p, int n);
// MS2: unit-local interface; only slot 17 is proven (the class behind FUN_1416a3ec0 is unrecovered). Never instantiated.
struct Unk_WFTarget
{
    virtual ~Unk_WFTarget();
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual __int64 vfunc_17();                 // slot 17 (+0x88): non-zero when the target is usable
};
Unk_WFTarget* FUN_1416a3ec0(unsigned __int64 p);
char* FUN_1409a8b20();
void* FUN_140af8310(char* p);
void* FUN_1411d15b0(void* p);
NiRenderer* FUN_140994450();   // NiRenderer::GetRenderer()
NiRenderer* FUN_1414fd170(void* p);
void FUN_1409a5770(void* obj, float* value, int n);
extern char DAT_143ae5320;
extern int DAT_1439f823c;
struct Unk_WFApp { void FUN_141473020(int a); };
Unk_WFApp* FUN_14086d260();
struct Unk_WFRect {
    Unk_WFRect(int a, int b, int c, int d);     // 0x140a5a400
    int a, b, c, d;
};
bool FUN_1416bafb0(void* a, void* step);

// @0x143ae5088 / @0x143ae508c (zero-initialised)
static float s_fade;
static unsigned long s_fadeStartTick;

// @0x1400fca70
#ifdef __clang__
// MS2: clang folds this to a constant initializer holding the address of an exe global (ADDR64 in .rdata), which the
// DLL post-link check rejects; a base-pointer getter reading a mutable zero forces dynamic initialization (MSVC build unaffected).
static volatile unsigned __int64 s_wfZero;
static const NiRTTI* wfBaseRTTI() { return (const NiRTTI*)((unsigned __int64)&NiDefaultClickRenderStep::ms_RTTI + s_wfZero); }
const NiRTTI WorldFadeOutRenderStep::ms_RTTI("WorldFadeOutRenderStep", wfBaseRTTI());
#else
const NiRTTI WorldFadeOutRenderStep::ms_RTTI("WorldFadeOutRenderStep", &NiDefaultClickRenderStep::ms_RTTI);
#endif

// @0x1416bad00
WorldFadeOutRenderStep::WorldFadeOutRenderStep(unsigned __int64 a, unsigned int b) : PostProcessEffect(a, b), m_a0(0)
{
    NiFixedString name("WorldFadeOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416bada0
WorldFadeOutRenderStep::~WorldFadeOutRenderStep()
{
    NiFixedString name("FadeOutRenderStep");
    FUN_140c8f950(this, name);
}

// @0x1416bae20
bool WorldFadeOutRenderStep::vfunc_15(unsigned int a, void* b)
{
    if (!PostProcessEffect::vfunc_15(a, 0))
        return false;
    void* p;
    p = FUN_140c8f690(FUN_1416b4990(this, "FadeOut", (void*)FUN_1416bafb0, this, FUN_1416a23f0(m_70, 5), 0, 0, 0, "FadeInOut", FUN_140c8f680(&((void**)b)[2]), FUN_140c8f680(&((void**)b)[1]), 0));
    if (p == 0) {
        vfunc_16();
        return false;
    }
    return true;
}

MS2_REPLACE_METHOD(0x1416BAE20, WorldFadeOutRenderStep, vfunc_15, 388, 0xF523D75F);

// @0x1416bafb0
bool FUN_1416bafb0(void* a, void* step)
{
    void* s = step;
    s_fade = 1.0f - ((float)GetTickCount() - (float)s_fadeStartTick) / (float)DAT_1439f823c;
    if (s_fade <= 0.0f) {
        if (FUN_1412642d0(s) == 1) {
            FUN_1416a0fb0(((PostProcessEffect*)s)->m_70, 0xf);
            s_fade = 0.0f;
            FUN_14086d260()->FUN_141473020(0);
        }
    }
    s_fade = s_fade * s_fade;
    FUN_1409a5770(&DAT_143ae5320, &s_fade, 1);
    return true;
}

// @0x1416bb0a0
// MS2-FUNCTIONAL: stack-slot layout of temps differs (frame 0x98 matches, slot order does not)
void WorldFadeOutRenderStep::vfunc_19()
{
    if (FUN_1412642d0(this) == 1) {
        Unk_WFTarget* a = FUN_1416a3ec0(m_70);
        if (a->vfunc_17() != 0) {
            void* h = FUN_1411d15b0(FUN_140af8310(FUN_1409a8b20() + 8));
            NiRenderer* p = FUN_140994450();
            NiRenderTargetGroup* q = p->GetDefaultRenderTargetGroup();
            int w = q->GetWidth(0);
            int ht = q->GetHeight(0);
            Unk_WFRect rect(0, w, 0, ht);
            NiRenderedTexture* pp = FUN_1416a23f0(m_70, 5);
            NiRenderer* rn = FUN_1414fd170(h);
            Ni2DBuffer* r = rn->GetDefaultRenderTargetGroup()->GetBuffer(0);
            Ni2DBuffer* arg = pp->GetBuffer();
            r->Copy(arg, reinterpret_cast<const NiRect<unsigned int>*>(&rect), reinterpret_cast<const NiRect<unsigned int>*>(&rect), (Ni2DBuffer::CopyFilterPreference)0);
            s_fadeStartTick = GetTickCount();
        }
    }
}

// @0x1416bb2b0
const NiRTTI* WorldFadeOutRenderStep::GetRTTI() const { return &ms_RTTI; }

// @0x1416bb2c0
bool WorldFadeOutRenderStep::vfunc_14() { return false; }

// @0x1416bb2d0
bool WorldFadeOutRenderStep::vfunc_13() { return false; }
