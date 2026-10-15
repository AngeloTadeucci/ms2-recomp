// postprocesseffect.h - PLACEHOLDER for the Gamebryo NiDefaultClickRenderStep base and MS2's PostProcessEffect /
// ReloadablePostProcess render-step bases (the *RenderStep family under client\ms2\postprocessing). NOT original headers.
// Proven from the exe (KMS2_DEV x64):
//   NiDefaultClickRenderStep : NiRefObject, 0x70 bytes, vftable slots 0 dtor, 1 DeleteThis, 2 GetRTTI, 3..12 NiClickRenderStep /
//     NiRenderStep virtuals (ctor 0x141474910, dtor 0x141474dd0).
//   PostProcessEffect : NiDefaultClickRenderStep, 0xa0 bytes (ctor 0x1416a2880, dtor 0x1416a2910, pure virtual dtor), 23 slots;
//     virtuals 13..22 declared below (15 = PostProcessEffect::vfunc_15 0x1416a2990, 16 = 0x1416a2b50).
//   ReloadablePostProcess : PostProcessEffect, 0xb8 bytes (ctor 0x1416a2bb0, dtor 0x141626a00 in outlinerenderstep), overrides 13/14/21,
//     adds pure virtual slot 23 -> 24 slots.
// Members of unknown type are kept as raw pointers; the smart-pointer-like helpers are called through FUN_<va> free functions.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/ninode.h"

// Gamebryo NiFixedString (8 bytes, a pooled string handle).
class NiFixedString {
public:
    NiFixedString();                            // 0x14099c480
    NiFixedString(const char* pcString);        // 0x140984450
    ~NiFixedString();                           // 0x1409845a0
    NiFixedString& operator=(const NiFixedString& kString);   // 0x140984780 (called with a NiFixedString*)
    operator const char*() const;               // 0x142087e50
private:
    char* m_handle;
};
MS2_CHECK_SIZE(NiFixedString, 8);

// Gamebryo NiString (8 bytes); ctor takes the buffer size.
class NiString {
public:
    NiString(unsigned __int64 stSize);          // 0x141d5bfa0
    ~NiString();                                // 0x141d5bfe0
    void FormatPrintf(const char* pcFormat, ...);   // 0x141d5db00
    operator const char*() const;               // 0x141d5c630
private:
    char* m_handle;
};
MS2_CHECK_SIZE(NiString, 8);

// Smart-pointer-like helper objects (8 bytes) used as render-step members; real template types unknown.
class Unk_PPSmartA {
public:
    Unk_PPSmartA(void* p);          // 0x14127c2a0
    ~Unk_PPSmartA();                // 0x14127c650
    void Assign(void* p);           // 0x14127c7f0
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPSmartA, 8);

class Unk_PPSmartC {
public:
    Unk_PPSmartC(void* p);          // 0x14097ed60
    ~Unk_PPSmartC();                // 0x14097f4a0
    void Assign(void* p);           // 0x14097f9b0
    void* Get();                    // 0x14097fbf0
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPSmartC, 8);

class NiDefaultClickRenderStep : public NiRefObject {
public:
    NiDefaultClickRenderStep();                 // 0x141474910
    virtual ~NiDefaultClickRenderStep();        // 0x141474dd0
    virtual const NiRTTI* GetRTTI() const;
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
protected:
    unsigned char m_pad_10[0x60];
};
MS2_CHECK_SIZE(NiDefaultClickRenderStep, 0x70);

class PostProcessEffect : public NiDefaultClickRenderStep {
public:
    PostProcessEffect(unsigned __int64 a, unsigned int b);     // 0x1416a2880
    virtual ~PostProcessEffect() = 0;                          // 0x1416a2910
    virtual const NiRTTI* GetRTTI() const;
    virtual bool vfunc_13();
    virtual bool vfunc_14();
    virtual bool vfunc_15(unsigned int a, void* b);            // 0x1416a2990
    virtual void vfunc_16();                                   // 0x1416a2b50
    virtual void* vfunc_17();
    virtual void* vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();

    static const NiRTTI ms_RTTI;                               // 0x143afa7a8

    unsigned __int64 m_70;
    void* m_78;
    void* m_80;             // smart-pointer-like (ctor 0x14127c2a0)
    void* m_88;             // second helper object (ctor 0x1414748a0)
    unsigned char m_90;
    void* m_98;
};
MS2_CHECK_SIZE(PostProcessEffect, 0xa0);

class ReloadablePostProcess : public PostProcessEffect {
public:
    ReloadablePostProcess(unsigned __int64 a, NiFixedString* name, unsigned char flag, unsigned int b);   // 0x1416a2bb0
    virtual ~ReloadablePostProcess();                          // 0x141626a00
    virtual const NiRTTI* GetRTTI() const;
    virtual bool vfunc_13();                                   // 0x141626ab0
    virtual bool vfunc_14();                                   // 0x141626aa0
    virtual void vfunc_21();                                   // 0x1416a2c60
    virtual bool vfunc_23() = 0;

    static const NiRTTI ms_RTTI;                               // 0x143ae4650

    NiFixedString m_a0;
    unsigned char m_a8;
    void* m_b0;
};
MS2_CHECK_SIZE(ReloadablePostProcess, 0xb8);

// Shared helpers (exe functions called by the *RenderStep family; real types unknown, pointers kept raw).
void FUN_140c8f950(NiDefaultClickRenderStep* step, const NiFixedString& name);                  // SetName
void* FUN_140c8f680(void* smartPtr);                                                      // smart pointer -> raw
void* FUN_1409a8d30(NiDefaultClickRenderStep* step, NiFixedString* name);
void FUN_14169fbf0(NiDefaultClickRenderStep* step, void* p);
// Result handle of the render-click factory FUN_1416b4990 (8 bytes, returned by value, dtor 0x1409a7b30).
class Unk_PPRes {
public:
    ~Unk_PPRes();                   // 0x1409a7b30
private:
    void* m_p;
};
MS2_CHECK_SIZE(Unk_PPRes, 8);
Unk_PPRes FUN_1416b4990(NiDefaultClickRenderStep* step, const char* name, void* cb, void* cbData, void* a, int b, int c, void* d, const char* tech, void* e, void* f, void* g);
void* FUN_140c8f690(const Unk_PPRes& res);
void* FUN_1401d31f0();
extern char DAT_1439fc800;
void* FUN_141d33230(NiFixedString* name, void* a, int b, int c, bool d);
void FUN_14169f6d0(void* smartPtrA, void* p);
