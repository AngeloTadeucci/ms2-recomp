// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: MS2Renderer (NiDX9Renderer subclass: mesh render hook, clear color, fragment shader factory).
// MS2-UNIT: ?\ms2renderer.cpp
// MS2-RANGE: 0x140d9d370-0x140d9dba0 .text$mn
// MS2-RANGE: 0x1400d3cd0-0x1400d3d00 .text$di
// MS2-PIN: ??_GMS2Renderer@@UEAAPEAXI@Z 0x140d9d5c0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2renderer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local Gamebryo placeholders (NiDX9Renderer is unrecovered; engine headers are not on the include path) --------------
struct Unk_RefObj { void FUN_1405a93d0(); void FUN_140980460(); };      // NiRefObject::DecRefCount / IncRefCount
struct Unk_RefPtr {                                                      // NiPointer<NiRefObject>
    Unk_RefObj* m_p;
    // @0x140d9d540
    Unk_RefPtr& operator=(Unk_RefObj* p)
    {
        if (m_p != p) {
            if (m_p != 0) m_p->FUN_1405a93d0();
            m_p = p;
            if (m_p != 0) m_p->FUN_140980460();
        }
        return *this;
    }
    // @0x140d9d5b0
    Unk_RefObj* Get() const { return m_p; }
};
struct Unk_PtrArray {                                                    // NiTPrimitiveArray<void*>
    void** m_pBase; unsigned m_uiSize; unsigned m_uiMax; unsigned m_uiGrow;
    void FUN_141d54bb0(unsigned newMax);
    // @0x140d9d620
    void Add(void* p)
    {
        if (m_uiSize == m_uiMax) FUN_141d54bb0(m_uiMax + m_uiGrow);
        m_pBase[m_uiSize] = p;
        m_uiSize = m_uiSize + 1;
    }
    // @0x140d9d8d0
    void RemoveAll() { m_uiSize = 0; }
};
struct Unk_MatBindPtr {                                                  // SmartPointer<NiDX9MeshMaterialBinding>
    Unk_MatBindPtr(void* p);                                             // 0x140d89070
    ~Unk_MatBindPtr();                                                   // 0x140d89160
    bool FUN_140d89270(void* p) const;                                   // operator==
    void* FUN_140d89370() const;                                         // Get
    void* m_p;
};
struct Unk_ColorA { float r, g, b, a; };
struct Unk_DevCaps {                                                     // object at MS2Renderer+0xba8 (render state block)
    char m_pad_00[0x98]; float m_f98; char m_pad_9c[0x68]; int m_i104;
    // @0x140d9d800
    bool IsEnabled() const { return m_i104 != 0 ? true : false; }
    // @0x140d9d850
    float GetValue98() const { return m_f98; }
    // @0x140d9dab0
    void SetEnabled(bool b) { int v; if (b) v = 1; else v = 0; m_i104 = v; }
    void FUN_1409a9bf0(float f);
};

class NiDX9Renderer {                                                    // ctor 0x1427c8af0, dtor 0x1427c9810
public:
    NiDX9Renderer();
    virtual ~NiDX9Renderer();
    virtual void vfunc_1();                    // 0x141d16bf0
    virtual const void* GetRTTI() const;                    // slot 2, MS2Renderer 0x140d9d890
    virtual void vfunc_3();                    // 0x141d16f20
    virtual void vfunc_4();                    // 0x141d171c0
    virtual void vfunc_5();                    // 0x141d171b0
    virtual void vfunc_6();                    // 0x141d17310
    virtual void vfunc_7();                    // 0x141d17320
    virtual void vfunc_8();                    // 0x141d17150
    virtual void vfunc_9();                    // 0x141d27870
    virtual void vfunc_10();                    // 0x1409801d0
    virtual void vfunc_11();                    // 0x141d17250
    virtual void vfunc_12();                    // 0x141d17240
    virtual void vfunc_13();                    // 0x141d17340
    virtual void vfunc_14();                    // 0x141d17090
    virtual void vfunc_15();                    // 0x141d17070
    virtual void vfunc_16();                    // 0x141d17080
    virtual void vfunc_17();                    // 0x141d17330
    virtual void vfunc_18();                    // 0x1427cf830
    virtual int vfunc_19();                    // slot 19, MS2Renderer 0x140d9d7e0
    virtual void vfunc_20();                    // 0x1427cfc30
    virtual void vfunc_21(float v);                    // slot 21, MS2Renderer 0x140d9da50
    virtual float vfunc_22();                    // slot 22, MS2Renderer 0x140d9d7a0
    virtual void vfunc_23(const Unk_ColorA* rgba);                    // slot 23, MS2Renderer 0x140d9d990
    virtual void vfunc_24(const Unk_ColorA* rgb);                    // slot 24, MS2Renderer 0x140d9d8f0
    virtual void vfunc_25(Unk_ColorA* rgba);                    // slot 25, MS2Renderer 0x140d9d6b0
    virtual void vfunc_26(int v);                    // slot 26, MS2Renderer 0x140d9db80
    virtual int vfunc_27();                    // slot 27, MS2Renderer 0x140d9d8a0
    virtual void vfunc_28();                    // 0x1427d66b0
    virtual void vfunc_29();                    // 0x1427d2260
    virtual void vfunc_30();                    // 0x1427cf780
    virtual void* vfunc_31();                    // slot 31, MS2Renderer 0x140d9d780
    virtual void vfunc_32();                    // 0x1427cf760
    virtual void vfunc_33();                    // 0x1427cf740
    virtual void vfunc_34();                    // 0x1427ce710
    virtual void vfunc_35();                    // 0x1427ce560
    virtual void vfunc_36();                    // 0x141d27100
    virtual void vfunc_37();                    // 0x1427cfaa0
    virtual void vfunc_38();                    // 0x1427cfa80
    virtual void vfunc_39();                    // 0x1427d6660
    virtual void vfunc_40();                    // 0x141d265b0
    virtual void vfunc_41();                    // 0x1427d2d00
    virtual void vfunc_42();                    // 0x1427d5c50
    virtual void vfunc_43();                    // 0x1427cfab0
    virtual void vfunc_44();                    // 0x1427d2b80
    virtual void vfunc_45();                    // 0x1427d2c80
    virtual void vfunc_46();                    // 0x1427d2930
    virtual void vfunc_47();                    // 0x1427d2ed0
    virtual void vfunc_48();                    // 0x1427d2e60
    virtual void vfunc_49();                    // 0x1427d2f50
    virtual void vfunc_50();                    // 0x1427d2e00
    virtual void vfunc_51();                    // 0x1427d6210
    virtual void vfunc_52();                    // 0x1427d53e0
    virtual void vfunc_53();                    // 0x1427ce330
    virtual void vfunc_54();                    // 0x1427cb3a0
    virtual void vfunc_55();                    // 0x141d26cb0
    virtual bool vfunc_56();                    // slot 56, MS2Renderer 0x140d9d830
    virtual bool vfunc_57(bool b);                    // slot 57, MS2Renderer 0x140d9daf0
    virtual float vfunc_58();                    // slot 58, MS2Renderer 0x140d9d870
    virtual void vfunc_59(float f);                    // slot 59, MS2Renderer 0x140d9db20
    virtual void vfunc_60();                    // 0x1427d5c20
    virtual Unk_RefObj* vfunc_61();                    // slot 61, MS2Renderer 0x140d9d7c0
    virtual void vfunc_62(Unk_RefObj* p);                    // slot 62, MS2Renderer 0x140d9da70
    virtual void vfunc_63();                    // 0x1427d30d0
    virtual void vfunc_64();                    // 0x1427d2b60
    virtual void vfunc_65();                    // 0x1427cc8f0
    virtual void vfunc_66();                    // 0x1427d4740
    virtual void vfunc_67();                    // 0x1427d4c20
    virtual void vfunc_68();                    // 0x1427d0280
    virtual bool vfunc_69(void* p);                    // slot 69, MS2Renderer 0x140d9d8c0
    virtual void vfunc_70();                    // 0x1427cc5f0
    virtual void vfunc_71();                    // 0x1427cc490
    virtual void vfunc_72();                    // 0x1427cc4f0
    virtual void vfunc_73();                    // 0x1427cc430
    virtual void vfunc_74();                    // 0x1427cb8e0
    virtual void vfunc_75();                    // 0x1427cb9f0
    virtual void vfunc_76();                    // 0x1427cb730
    virtual void vfunc_77();                    // 0x141d26d20
    virtual void vfunc_78();                    // 0x1427d2350
    virtual void vfunc_79();                    // 0x1427d6500
    virtual void* vfunc_80(void* arg);                    // slot 80, MS2Renderer 0x140d9d4c0
    virtual void vfunc_81();                    // 0x1427d5960
    virtual void vfunc_82();                    // 0x141d27f60
    virtual void vfunc_83();                    // 0x1427d0050
    virtual void vfunc_84(bool b);                    // slot 84, MS2Renderer 0x140d9db60
    virtual void vfunc_85();                    // 0x141d27ff0
    virtual void vfunc_86();                    // slot 86, MS2Renderer 0x140d9d690
    virtual void vfunc_87();                    // slot 87, MS2Renderer 0x140d9d6a0
    virtual void vfunc_88();                    // 0x1427ccd50
    virtual void vfunc_89();                    // 0x1427cd550
    virtual void vfunc_90();                    // 0x1427cd450
    virtual void vfunc_91();                    // 0x1427cd230
    virtual void vfunc_92();                    // 0x1427cd920
    virtual void vfunc_93();                    // 0x1427cdea0
    virtual void vfunc_94();                    // 0x1427cd780
    virtual void vfunc_95();                    // 0x1427ccf90
    virtual void vfunc_96();                    // 0x1427cd5a0
    virtual void vfunc_97(void* renderObject);                    // slot 97, MS2Renderer 0x140d9d3e0
    virtual void vfunc_98();                    // 0x1427d5200
    virtual void vfunc_99();                    // 0x1427d52c0
    virtual void vfunc_100();                    // 0x1427d5140
    static void operator delete(void*, size_t);                          // efd::MemObject::operator delete 0x14208a8f0
    void* FUN_1427cfc40(void* renderObject, Unk_MatBindPtr* binding);   // GetShaderAndVertexDecl
    char m_pad_08[0x38];
    Unk_RefPtr m_spObj;                  // +0x40
    char m_pad_48[0x6f0];
    unsigned m_uiClearColor;             // +0x738 (ARGB)
    float m_f73c;
    int m_i740;
    int m_i744;
    char m_pad_748[0x108];
    unsigned char m_bSkipMeshRender;              // +0x850
    char m_pad_851[0x317];
    void* m_pVtx;                        // +0xb68
    char m_pad_b70[0x38];
    Unk_DevCaps* m_pDevCaps;             // +0xba8
    char m_pad_bb0[0x1080 - 0xbb0];
};
MS2_CHECK_SIZE(NiDX9Renderer, 0x1080);
MS2_CHECK_OFFSET(NiDX9Renderer, m_spObj, 0x40);
MS2_CHECK_OFFSET(NiDX9Renderer, m_uiClearColor, 0x738);
MS2_CHECK_OFFSET(NiDX9Renderer, m_bSkipMeshRender, 0x850);
MS2_CHECK_OFFSET(NiDX9Renderer, m_pVtx, 0xb68);
MS2_CHECK_OFFSET(NiDX9Renderer, m_pDevCaps, 0xba8);

class MS2Renderer : public NiDX9Renderer {
public:
    MS2Renderer();
    virtual ~MS2Renderer();
    virtual const void* GetRTTI() const;
    virtual int vfunc_19();
    virtual void vfunc_21(float v);
    virtual float vfunc_22();
    virtual void vfunc_23(const Unk_ColorA* rgba);
    virtual void vfunc_24(const Unk_ColorA* rgb);
    virtual void vfunc_25(Unk_ColorA* rgba);
    virtual void vfunc_26(int v);
    virtual int vfunc_27();
    virtual void* vfunc_31();
    virtual bool vfunc_56();
    virtual bool vfunc_57(bool b);
    virtual float vfunc_58();
    virtual void vfunc_59(float f);
    virtual Unk_RefObj* vfunc_61();
    virtual void vfunc_62(Unk_RefObj* p);
    virtual bool vfunc_69(void* p);
    virtual void* vfunc_80(void* arg);
    virtual void vfunc_84(bool b);
    virtual void vfunc_86();
    virtual void vfunc_87();
    virtual void vfunc_97(void* renderObject);
};

// ---- unrecovered neighbours -------------------------------------------------------------------------------------------------
extern char DAT_143ac3ce8; extern char DAT_143d6eb58; extern char DAT_143a4b228;
extern Unk_PtrArray* DAT_143d6eab8;     // per-frame render object list
void FUN_141d16b90(void* rtti, const char* name, void* parent);     // NiRTTI::NiRTTI
void* FUN_1427e4d90(void* binding);
void FUN_141d4d520(void* shader, Unk_PtrArray* list);
void* FUN_140876480(void* out, int cat);   void* FUN_14208a860(unsigned __int64 size, unsigned cat);
void* FUN_140d878b0(void* mem, void* arg);                          // MS2FragmentShader::MS2FragmentShader (0xd8 bytes)

// @0x1400d3cd0   static initializer: MS2Renderer::ms_RTTI
void FUN_1400d3cd0() { FUN_141d16b90(&DAT_143ac3ce8, "MS2Renderer", &DAT_143d6eb58); }

// @0x140d9d370
MS2Renderer::MS2Renderer() {}

// @0x140d9d3b0
MS2Renderer::~MS2Renderer() {}

// @0x140d9d3e0
// MS2-FUNCTIONAL: exe inlines the binding dtor on each exit path (different branch layout)
void MS2Renderer::vfunc_97(void* renderObject)
{
    if (m_bSkipMeshRender == 0) {
        Unk_MatBindPtr binding(0);
        void* shader = FUN_1427cfc40(renderObject, &binding);
        if (shader != 0 && !binding.FUN_140d89270(0) && FUN_1427e4d90(binding.FUN_140d89370()) != 0) {
            DAT_143d6eab8->RemoveAll();
            DAT_143d6eab8->Add(renderObject);
            FUN_141d4d520(shader, DAT_143d6eab8);
        }
    }
}

// @0x140d9d4c0
// MS2-FUNCTIONAL: exe has an EH frame (state -2, 0x58 frame) from an unrecovered temp; behaviour identical
void* MS2Renderer::vfunc_80(void* arg)
{
    int tmp;
    int* cat = (int*)FUN_140876480(&tmp, 0);
    void* mem = FUN_14208a860(0xd8, *cat);
    void* r;
    if (mem == 0) r = 0; else r = FUN_140d878b0(mem, arg);
    return r;
}

// @0x140d9d690
void MS2Renderer::vfunc_86() {}

// @0x140d9d6a0
void MS2Renderer::vfunc_87() {}

// @0x140d9d6b0
void MS2Renderer::vfunc_25(Unk_ColorA* rgba)
{
    const float k = 0.003921569f;
    rgba->a = (float)((m_uiClearColor >> 24) & 0xff) * k;
    rgba->r = (float)((m_uiClearColor >> 16) & 0xff) * k;
    rgba->g = (float)((m_uiClearColor >> 8) & 0xff) * k;
    rgba->b = (float)(m_uiClearColor & 0xff) * k;
}

// @0x140d9d780
void* MS2Renderer::vfunc_31() { return m_pVtx; }

// @0x140d9d7a0
float MS2Renderer::vfunc_22() { return m_f73c; }

// @0x140d9d7c0
Unk_RefObj* MS2Renderer::vfunc_61() { return m_spObj.Get(); }

// @0x140d9d7e0
int MS2Renderer::vfunc_19() { return m_i744; }

// @0x140d9d830
bool MS2Renderer::vfunc_56() { return m_pDevCaps->IsEnabled(); }

// @0x140d9d870
float MS2Renderer::vfunc_58() { return m_pDevCaps->GetValue98(); }

// @0x140d9d890
const void* MS2Renderer::GetRTTI() const { return &DAT_143ac3ce8; }

// @0x140d9d8a0
int MS2Renderer::vfunc_27() { return m_i740; }

// @0x140d9d8c0
bool MS2Renderer::vfunc_69(void* p) { return true; }

// @0x140d9d8f0
void MS2Renderer::vfunc_24(const Unk_ColorA* rgb)
{
    unsigned char r = (unsigned char)(int)(rgb->r * 255.0f);
    unsigned char g = (unsigned char)(int)(rgb->g * 255.0f);
    unsigned char b = (unsigned char)(int)(rgb->b * 255.0f);
    m_uiClearColor = (r & 0xffU) << 16 | 0xff000000 | (g & 0xffU) << 8 | (b & 0xffU);
}

// @0x140d9d990
void MS2Renderer::vfunc_23(const Unk_ColorA* rgba)
{
    unsigned char r = (unsigned char)(int)(rgba->r * 255.0f);
    unsigned char g = (unsigned char)(int)(rgba->g * 255.0f);
    unsigned char b = (unsigned char)(int)(rgba->b * 255.0f);
    unsigned char a = (unsigned char)(int)(rgba->a * 255.0f);
    m_uiClearColor = (a & 0xffU) << 24 | (r & 0xffU) << 16 | (g & 0xffU) << 8 | (b & 0xffU);
}

// @0x140d9da50
void MS2Renderer::vfunc_21(float v) { m_f73c = v; }

// @0x140d9da70
void MS2Renderer::vfunc_62(Unk_RefObj* p)
{
    if (p != 0) m_spObj = p;
}

// @0x140d9daf0
bool MS2Renderer::vfunc_57(bool b)
{
    m_pDevCaps->SetEnabled(b);
    return true;
}

// @0x140d9db20
void MS2Renderer::vfunc_59(float f) { m_pDevCaps->FUN_1409a9bf0(f); }

// @0x140d9db50
void FUN_140d9db50(bool b) { DAT_143a4b228 = b; }

// @0x140d9db60
void MS2Renderer::vfunc_84(bool b) { FUN_140d9db50(b); }

// @0x140d9db80
void MS2Renderer::vfunc_26(int v) { m_i740 = v; }
