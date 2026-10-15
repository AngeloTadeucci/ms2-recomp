// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rendering glue: ShadowCullingProcess (NiTerrainCullingProcess subclass that culls shadow casters).
// MS2-UNIT: ?\shadowcullingprocess.cpp
// MS2-RANGE: 0x141753550-0x141753c90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\shadowcullingprocess.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <new>

// ---- Gamebryo bits, unit-local (engine headers are not on the include path; layouts pinned below) -----------------
class NiPlane;
class NiBound { public: float m_center[3]; float m_fRadius; };
class NiProperty; class NiMeshCullingProcess;
class Unk_ShadowMgr { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual int vfunc_18(void* camera, class NiAVObject* o); };       // slot 0x90
// NiAVObject: only the Cull slot (0x110) is used here.
class NiAVObject { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13();
    virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20();
    virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
    virtual void Cull(NiMeshCullingProcess* p); };

// NiFrustumPlanes: 6 planes (0x60 bytes) + active-plane bit mask.
class NiFrustumPlanes {
public:
    float m_planes[24];
    unsigned m_uiActive;
    // @0x141753b00
    void Deactivate(unsigned i) { int s = i; m_uiActive &= ~(1 << (unsigned char)s); }
    // @0x141753b40
    unsigned GetActivePlaneState() const { return m_uiActive; }
    // @0x141753bc0
    bool IsAnyActive() const { return m_uiActive != 0 ? true : false; }
    // @0x141753bf0
    void SetActivePlaneState(unsigned s) { m_uiActive = s; }
    bool IsActive(unsigned i) const;                    // 0x140af8670
    const NiPlane* GetPlane(unsigned i) const;          // 0x140af81f0
};

class NiMeshCullingProcess {
public:
    virtual ~NiMeshCullingProcess();                    // 0x141e2eb80
    virtual void vfunc_1();                             // 0x141d16bf0
    virtual const void* GetRTTI() const;
    virtual void Process(NiAVObject* obj);
    virtual void vfunc_4();                             // 0x141e2ed50
    virtual void vfunc_5();                             // 0x141e2ed60
    virtual void vfunc_6();                             // 0x141e2ed40
    virtual void vfunc_7();                             // 0x141e2ed20
    virtual void vfunc_8();                             // 0x140d96620
    static void* operator new(size_t, unsigned) throw();       // efd::MemObject::operator new 0x14208a860
    static void operator delete(void*, size_t);         // efd::MemObject::operator delete 0x14208a8f0
    void* m_pad_08;  int m_pad_10; int m_pad_14; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    void* m_pad_38;  void* m_pad_40; void* m_pad_48; int m_pad_50;
    NiFrustumPlanes m_kPlanes;                          // +0x54
    // @0x141753b50
    void* GetCamera() const { if (m_pad_30 == 0) return m_pad_28; return m_pad_30; }
    void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0;
};
MS2_CHECK_OFFSET(NiMeshCullingProcess, m_kPlanes, 0x54);
MS2_CHECK_SIZE(NiMeshCullingProcess, 0xd8);

class NiTerrainCullingProcess : public NiMeshCullingProcess {
public:
    NiTerrainCullingProcess(void* visibleArray, void* workflowMgr);   // 0x141f44a30
    virtual ~NiTerrainCullingProcess();                               // body = FUN_141753a50 (no vptr store in the exe)
};

class ShadowCullingProcess : public NiTerrainCullingProcess {
public:
    ShadowCullingProcess();
    virtual ~ShadowCullingProcess();
    virtual const void* GetRTTI() const;
    virtual void Process(NiAVObject* obj);
};

// ---- unrecovered neighbours -----------------------------------------------------------------------------------------
extern char DAT_143afa4d8;   extern char DAT_143afb348;   extern char DAT_143ae5190;   extern char DAT_143afa7d0;
extern char DAT_143afd5c8;   extern int DAT_143ae2b34;    extern int DAT_1439fc854;
void* FUN_1409478c0();                                  // singleton accessor
bool FUN_140aed0b0(void* mgr);                          // feature enabled?
void* FUN_140a0b000(NiAVObject* o);                     // parent / key of node
void* FUN_14098d8d0(void* table, void* key);            // table lookup
NiProperty* FUN_141d14f90(NiAVObject* o, int type);     // NiAVObject::GetProperty
bool FUN_14098dab0(NiProperty* p);                      // property active?
void* FUN_140994490(NiAVObject* o);                     // GetWorldBound
float FUN_140a00ef0(const NiPlane* p, const NiBound* b);// plane distance to bound centre
bool FUN_14109a9a0(void* table, NiAVObject* o);         // contained in set
int FUN_14098daf0(NiAVObject* o);                       // child count
void* FUN_14098db40(NiAVObject* o, int i);              // child at
bool FUN_1411c9940(void* child);                        // child visible?
int FUN_140ad02f0(int a, int b);                        // combine
int FUN_141568f60(void* o);                             // lookup result id
void* FUN_141d17b40(NiAVObject* o, void* key);          // NiObject::GetExtraData-style lookup
void* FUN_140876480(void* out, int cat);                // memory category helper, returns int*
float FUN_14098daa0(NiProperty* p);                     // alpha test ref
bool FUN_14028d470(float a, float b);                   // approx equal                                   // material has alpha test?

// @0x141753550
ShadowCullingProcess::ShadowCullingProcess() : NiTerrainCullingProcess(0, 0) {}

bool FUN_141753a00(NiAVObject* o);
int FUN_141753c20(const NiBound* b, const NiPlane& pl);
void FUN_141753c10(int v);
void* FUN_141753b80(char* o);

// MS2-FUNCTIONAL: Process 3-byte frame/arg-order diffs; Deactivate shift-count temp; factory EH state; ~Shadow vptr store (exe omits it)
// @0x141753590
void ShadowCullingProcess::Process(NiAVObject* obj)
{
    unsigned saved;
    unsigned i;
    int k;
    void* node;
    if (FUN_140aed0b0(FUN_1409478c0()) && obj != 0) {
        node = FUN_14098d8d0(&DAT_143afa4d8, FUN_140a0b000(obj));
        while (node != 0) {
            NiProperty* p = FUN_141d14f90((NiAVObject*)node, 0);
            if (p != 0 && FUN_14098dab0(p) && !FUN_141753a00((NiAVObject*)node))
                return;
            node = FUN_14098d8d0(&DAT_143afa4d8, FUN_140a0b000((NiAVObject*)node));
        }
    }
    if (!m_kPlanes.IsAnyActive()) {
        obj->Cull(this);
        return;
    }
    saved = m_kPlanes.GetActivePlaneState();
    for (i = 0; i < 6; ++i) {
        if (m_kPlanes.IsActive(i)) {
            const NiPlane* pl = m_kPlanes.GetPlane(i);
            int r = FUN_141753c20((const NiBound*)FUN_140994490(obj), *pl);
            if (r == 2) break;
            if (r == 1) m_kPlanes.Deactivate(i);
        }
    }
    if (i == 6) {
        NiProperty* p = FUN_141d14f90(obj, 0);
        if (p == 0 || !FUN_14098dab0(p) || FUN_141753a00(obj)) {
            if (FUN_14109a9a0(&DAT_143afb348, obj)) {
                NiAVObject* o2 = obj;
                for (k = 0; k < FUN_14098daf0(o2); ++k) {
                    void* c = FUN_14098db40(o2, k);
                    if (c != 0 && !FUN_1411c9940(c)) break;
                }
                Unk_ShadowMgr* mgr = (Unk_ShadowMgr*)FUN_141753b80((char*)o2);
                int v = mgr->vfunc_18(GetCamera(), o2);
                k = FUN_140ad02f0(k, v);
                FUN_141753c10(k);
                obj->Cull(this);
                FUN_141753c10(-1);
            } else {
                obj->Cull(this);
            }
        } else if (DAT_143ae2b34 != 0) {
            void* x = FUN_14098d8d0(&DAT_143afa7d0, obj);
            if (x != 0 && FUN_141568f60(x) != 0)
                obj->Cull(this);
        } else {
            if (FUN_141d17b40(obj, &DAT_143ae5190) != 0)
                obj->Cull(this);
        }
    }
    m_kPlanes.SetActivePlaneState(saved);
}

// @0x141753990   factory: EE_NEW(category) ShadowCullingProcess
ShadowCullingProcess* FUN_141753990()
{
    void* tmp;
    int* cat = (int*)FUN_140876480(&tmp, 0);
    ShadowCullingProcess* r = new (*cat) ShadowCullingProcess();
    return r;
}

// @0x141753a00
bool FUN_141753a00(NiAVObject* o)
{
    NiProperty* p = FUN_141d14f90(o, 3);
    if (p != 0) {
        if (FUN_14028d470(FUN_14098daa0(p), 1.0f)) return true;
    }
    return false;
}

// @0x141753a50   exe's ~NiTerrainCullingProcess body: only forwards to the mesh base dtor
void FUN_141753a50(NiMeshCullingProcess* p) { p->NiMeshCullingProcess::~NiMeshCullingProcess(); }

// @0x141753a70
ShadowCullingProcess::~ShadowCullingProcess() {}

// @0x141753a90
void* FUN_141753a90(void** p) { return *p; }

// @0x141753b80
void* FUN_141753b80(char* o) { return FUN_141753a90((void**)(o + 0x138)); }

// @0x141753bb0
const void* ShadowCullingProcess::GetRTTI() const { return &DAT_143afd5c8; }

// @0x141753c10
void FUN_141753c10(int v) { DAT_1439fc854 = v; }

// @0x141753c20
int FUN_141753c20(const NiBound* b, const NiPlane& pl)
{
    float d = FUN_140a00ef0(&pl, b);
    if (d <= -b->m_fRadius) { return 2; }
    else if (d >= b->m_fRadius) { return 1; }
    else { return 0; }
}
