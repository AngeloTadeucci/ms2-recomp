// worldservice.h - WorldService (RTTI .?AVWorldService@@), the game's field/world system service: loads the xblock world
// (urn:emergent-world:<name>), owns the field's entity/actor/prop bookkeeping and forwards field events to the scene
// state through IWorldServiceCallback. Shared header of the four sub-units ?\worldservice.cpp#1..#4 (owner: w3o2).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); NOT an original header (the exe has no __FILE__ for it).
//
// Proven facts (all from the exe):
// - bases (RTTI CHD of vftable 0x142ffeb98): efd::ISystemService +0x00, TSingleton<WorldService> +0x18,
//   IMessageListener +0x20. sizeof = 0xaf0 (the TSingleton thunk 0x141bf99b8 adjusts by -0x18 into the deleting dtor,
//   Ghidra prints it as this[-1].field_0xad8).
// - EE_DECLARE_CLASS1(WorldService, 0x06100002, efd::ISystemService) (class id in the ClassInfo setup 0x141c1cac0),
//   ClassInfo static 0x143af8360 (initializer 0x140120240), TSingleton<WorldService>::s_instance 0x143aaee10.
// - vftable 0x142ffeb98 (16 slots, same shape as CNetworkService):
//     0 DeleteThis 0x141bfb5b0, 1 IncRefCount 0x141c03190, 2 DecRefCount 0x141bfb570, 3 TypeCast 0x141bffe20,
//     4/5 TypeCast 0x141c1eab0/0x141c1ea60, 6 GetClassDesc 0x141bfe670, 7 GetClassID 0x1409f2f80 (efd, shared),
//     8 scalar deleting dtor 0x141bfaad0, 9 OnServiceRegistered 0x14209cf70 (efd), 10 OnPreInit() 0x14209cf50 (efd),
//     11 OnPreInit(IDependencyRegistrar*) 0x141bcb2a0, 12 OnInit 0x141bcb370, 13 OnTick 0x141bcb830,
//     14 OnShutdown 0x141bcd5a0, 15 GetDisplayName 0x141bbae20.
//   vftable 0x142ffec20 (TSingleton part): { 0x141bf99b8 = thunk to the deleting dtor }.
//   vftable 0x142ffec30 (IMessageListener part): { 0x141bc8230 = OnMessage }.
//   Slots 0-6 and the deleting dtor lie past 0x141bf7060: the CU's COMDAT tail runs on to about 0x141c30000 (beyond
//   units.tsv's ?\worldservice.cpp range); see NOTES.md "w3o2".
// - Member offsets and constructors: ctor 0x141bb9720, dtor 0x141bba870 (member dtors in reverse order). Each member
//   below lists its ctor / dtor COMDAT. Container element types marked "TYPE?" are best guesses (layout-correct, element
//   identity unproven); a #2-#4 worker who proves one may change that member's element type here (owner's permission),
//   but never an offset or a size.
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <efd/ISystemService.h>
#include <efd/Category.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T> (16-byte game smart pointer)
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/nipoint3.h"           // Unk_StreamPoint (NiPoint3 / efd::Point3)

class WorldService;
template <class T> class TSingleton;
template <> class TSingleton<WorldService>
{
public:
    TSingleton();                                       // 0x141bf1a00 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }           // 0x141bf56f0
    static WorldService* s_instance;                    // 0x143aaee10
};

namespace efd { class ServiceManager; class MessageService; }
class CGlobalKeyTextCallback                            // RTTI name; 8 bytes (vftable only); ctor/dtor not inline here
{
public:
    CGlobalKeyTextCallback();
    virtual ~CGlobalKeyTextCallback();
};
class TextureLayerManager;                              // NiObject subclass (0x20 bytes, ctor 0x141bf48f0 COMDAT)
class ChaosLightEffectLayerManager;                     // 0x28 bytes
class CWireframeManager;                                // 0x48 bytes

// Gamebryo NiPointer<T> stand-in (8 bytes). The real NiPointer is in CoreRuntime (not on the game include path); the
// per-T COMDATs (e.g. ctor 0x141bf1020, dtor 0x141bf54e0, operator= 0x141bf6ad0 for m_340) all have this shape.
void FUN_140980460(void* obj);                          // NiRefObject::IncRefCount
void FUN_1405a93d0(void* obj);                          // NiRefObject::DecRefCount
template <class T> class Unk_WsNiPtr
{
public:
    Unk_WsNiPtr(T* p = 0) : m_p(p) { if (m_p) FUN_140980460(m_p); }
    ~Unk_WsNiPtr() { if (m_p) FUN_1405a93d0(m_p); }
    Unk_WsNiPtr& operator=(T* p)
    {
        if (m_p != p) { if (m_p) FUN_1405a93d0(m_p); m_p = p; if (m_p) FUN_140980460(m_p); }
        return *this;
    }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
    operator T*() const { return m_p; }
    T* m_p;
};

// boost::optional<T>-like (8 bytes for float: bool at +0, value at +4; the get() COMDAT 0x1410a71d0 asserts at line 0x55).
template <class T> struct Unk_WsOptional
{
    Unk_WsOptional() : m_init(false) {}                 // 0x141bf0e70
    void reset() { m_init = false; }                    // 0x141c2ed00
    Unk_WsOptional& operator=(const T& v) { m_value = v; m_init = true; return *this; }   // 0x141bf68b0
    bool operator!() const { return !m_init; }          // 0x1417f6020
    T& get() { return m_value; }                        // 0x1410a71d0 (asserts m_init)
    bool m_init;
    T m_value;
};

// Opaque element types of the containers (TYPE?). Sizes are not proven; they only name distinct instantiations.
struct Unk_WsElem { void* p; };
// Target of the MS2Ptr members (some CPtred subclass; TYPE? per member).
class Unk_WsPtred : public CPtred {};

class WorldService : public efd::ISystemService, public TSingleton<WorldService>, public IMessageListener
{
    EE_DECLARE_CLASS1(WorldService, 0x06100002, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
    MS2_LAYOUT_FRIEND;
public:
    WorldService();                                     // 0x141bb9720
    virtual ~WorldService();                            // 0x141bba870
    const char* GetDisplayName() const override;        // 0x141bbae20
    efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar) override;   // 0x141bcb2a0
    efd::AsyncResult OnInit() override;                 // 0x141bcb370
    efd::AsyncResult OnTick() override;                 // 0x141bcb830
    efd::AsyncResult OnShutdown() override;             // 0x141bcd5a0
    int OnMessage(UISwfEntity* pSender, UIMsg* pMsg) override;   // 0x141bc8230 (IMessageListener, this = +0x20)

    static WorldService* GetInstance() { return TSingleton<WorldService>::s_instance; }

    // ---- non-virtual methods (Ghidra names; rename freely when proven, the hook binds by VA) ----
    void FUN_141bbae40(void* p);                        // m_048.insert(p)
    void FUN_141bbae80(void* p);                        // m_048.erase(p) if present
    int FUN_141bc32b0();                                // return m_398
    void FUN_141bc1640();                               // m_148 COMDAT 0x141bfe6b0
    void FUN_141bc1670();                               // m_118 COMDAT 0x141bfe6c0
    void FUN_141bc16a0();                               // m_348 COMDAT 0x141bf7c40
    void FUN_141bc6f60(int a804, int a800, int a808);
    void FUN_141bc70f0();                               // empty
    void FUN_141bc72f0();
    void FUN_141bc73e0(bool b);                         // m_91c = b; FUN_141bc72f0()
    bool FUN_141bc7420();                               // return m_91c
    void FUN_141bc7910();                               // empty
    int FUN_141bc9a80();                                // return m_928
    void* FUN_141bc9fb0();                              // return &m_930
    void FUN_141bca220();                               // m_2bc = 1
    void FUN_141bcad60(void* p, int n);                 // m_2c8 = p, m_2d0 = n
    int FUN_141bcaf60();                                // return m_2d0
    void* FUN_141bcaf80();                              // return m_2c8
    int FUN_141bcfbd0();                                // m_state == 4 && m_2b4 != 0

    // ---- non-virtual members, exe order (names invented unless noted). Append; do not reorder. ----

public:
    efd::Category m_category;                           // +0x030 own globally unique category (OnInit)
    efd::Category m_038;                                // +0x038
    int m_040;                                          // +0x040
    std::set<void*> m_048;                              // +0x048 ctor 0x141bf32d0 / dtor 0x141bf5ed0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_058;                    // +0x058 0x141bef200 / 0x141bf4960 TYPE?
    std::list<Unk_WsElem> m_088;                        // +0x088 0x141bf2fa0 / 0x141bf5c60 TYPE?
    std::list<Unk_WsElem> m_098;                        // +0x098 same type as m_088
    Unk_StreamPoint m_0a8;                              // +0x0a8 copy of DAT_143b01a60 (a point constant)
    float m_0b4;                                        // +0x0b4 3000.0f
    ATL::CAtlList<Unk_WsElem> m_0b8;                    // +0x0b8 0x141beff50 / 0x141bf4d50 TYPE?
    ATL::CAtlList<Unk_WsElem> m_0e8;                    // +0x0e8 0x141befd10 / 0x141bf4bd0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_118;                    // +0x118 0x141befd40 / 0x141bf4bf0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_148;                    // +0x148 0x141befce0 / 0x141bf4bb0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_178;                    // +0x178 0x140963ae0 / 0x1409647c0 (shared) TYPE?
    ATL::CAtlList<Unk_WsElem> m_1a8;                    // +0x1a8 0x141befcb0 / 0x141bf4b90 TYPE?
    std::set<void*> m_1d8;                              // +0x1d8 0x141bf30e0 / 0x141bf5d50 TYPE?
    std::set<void*> m_1e8;                              // +0x1e8 0x141bf2ff0 / 0x141bf5cb0 TYPE?
    std::set<void*> m_1f8;                              // +0x1f8 0x141bf2fc0 / 0x141bf5c90 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_208;           // +0x208 0x141bef530 / 0x141bf4a10 TYPE?
    CString m_250;                                      // +0x250
    CString m_258;                                      // +0x258
    int m_state;                                        // +0x260 = 7
    int m_prevState;                                    // +0x264 = 7
    efd::SmartPointer<efd::ISystemService> m_268;       // +0x268 service (OnInit: 0x140ae1200) TYPE?
    efd::SmartPointer<efd::MessageService> m_spMessageService;   // +0x270
    void* m_278;                                        // +0x278 service (0x140d86bf0)
    bool m_280;                                         // +0x280
    int m_284;                                          // +0x284
    int m_288;                                          // +0x288
    int m_28c;                                          // +0x28c = 1
    CStringW m_290;                                     // +0x290
    MS2Ptr<Unk_WsPtred> m_298;                           // +0x298 0x141bf14b0(0) / 0x1408850f0 TYPE?
    int m_2a8;                                          // +0x2a8 = 1
    int m_2ac;                                          // +0x2ac
    int m_2b0;                                          // +0x2b0
    int m_2b4;                                          // +0x2b4
    int m_2b8;                                          // +0x2b8
    int m_2bc;                                          // +0x2bc
    int m_2c0;                                          // +0x2c0
    void* m_2c8;                                        // +0x2c8
    int m_2d0;                                          // +0x2d0
    efd::SmartPointer<efd::ISystemService> m_2d8;       // +0x2d8 dtor 0x140dc13f0 TYPE?
    bool m_2e0;                                         // +0x2e0
    std::set<void*> m_2e8;                              // +0x2e8 0x141bf30b0 / 0x141bf5d30 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_2f8;           // +0x2f8 0x141befad0 / 0x141bf4b30 TYPE?
    Unk_WsNiPtr<CWireframeManager> m_340;               // +0x340 0x141bf1020 / 0x141bf54e0 (OnInit: new CWireframeManager)
    Unk_WsNiPtr<Unk_WsElem> m_348;                      // +0x348 0x141bf0f90 / 0x141bf5470 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_350;           // +0x350 0x141bef260 / 0x141bf4980 TYPE?
    int m_398;                                          // +0x398
    ATL::CAtlMap<unsigned, Unk_WsElem> m_3a0;           // +0x3a0 0x141bef710 / 0x141bf4a70 TYPE?
    CGlobalKeyTextCallback m_3e8;                       // +0x3e8
    ATL::CAtlList<Unk_WsElem> m_3f0;                    // +0x3f0 0x141234580 / 0x141234d30 (shared) TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_420;           // +0x420 0x141bef9e0 / 0x141bf4b00 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_468;           // +0x468 0x141befbc0 / 0x141bf4b60 TYPE?
    ATL::CAtlList<Unk_WsElem> m_4b0;                    // +0x4b0 0x141befe60 / 0x141bf4cb0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_4e0;                    // +0x4e0 0x141befdd0 / 0x141bf4c50 TYPE?
    ATL::CAtlList<Unk_WsElem> m_510;                    // +0x510 0x141befec0 / 0x141bf4cf0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_540;                    // +0x540 0x141beff80 / 0x141bf4d70 TYPE?
    ATL::CAtlList<Unk_WsElem> m_570;                    // +0x570 0x141beffb0 / 0x141bf4d90 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_5a0;           // +0x5a0 0x141bef8f0 / 0x141bf4ad0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_5e8;                    // +0x5e8 0x141befe30 / 0x141bf4c90 TYPE?
    ATL::CAtlList<Unk_WsElem> m_618;                    // +0x618 same type as m_5e8
    ATL::CAtlList<Unk_WsElem> m_648;                    // +0x648 0x140cb6ab0 / 0x140cb6cd0 (shared) TYPE?
    ATL::CAtlList<Unk_WsElem> m_678;                    // +0x678 0x141befe90 / 0x141bf4cd0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_6a8;                    // +0x6a8 0x141befef0 / 0x141bf4d10 TYPE?
    ATL::CAtlList<Unk_WsElem> m_6d8;                    // +0x6d8 0x141befda0 / 0x141bf4c30 TYPE?
    ATL::CAtlList<Unk_WsElem> m_708;                    // +0x708 0x141befd70 / 0x141bf4c10 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_738;           // +0x738 0x141bef350 / 0x141bf49b0 TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_780;           // +0x780 0x141bef800 / 0x141bf4aa0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_7c8;                    // +0x7c8 0x141befe00 / 0x141bf4c70 TYPE?
    __int64 m_7f8;                                      // +0x7f8 never touched by the CU (padding or unused)
    int m_800;                                          // +0x800
    int m_804;                                          // +0x804
    int m_808;                                          // +0x808
    Unk_WsNiPtr<TextureLayerManager> m_spTextureLayerManager;               // +0x810 0x141bf1130 / 0x141bf5540
    Unk_WsNiPtr<ChaosLightEffectLayerManager> m_spChaosLightEffectLayerManager;   // +0x818 0x141bf1060 / 0x141bf5510
    Unk_StreamPoint m_boundsMin;                           // +0x820 (FLT_MAX x3)
    Unk_StreamPoint m_boundsMax;                           // +0x82c (-FLT_MAX x3)
    std::set<void*> m_838;                              // +0x838 0x140a15e30 / 0x140a16650 (shared) TYPE?
    ATL::CAtlMap<unsigned, Unk_WsElem> m_848;           // +0x848 0x141bef440 / 0x141bf49e0 TYPE?
    ATL::CAtlList<Unk_WsElem> m_890;                    // +0x890 0x1416c3150 / 0x1416c3190 (shared: CAtlList + int) TYPE?
    int m_8c0;                                          // +0x8c0 (part of the m_890 class)
    void* m_8c8;                                        // +0x8c8
    void* m_8d0;                                        // +0x8d0
    Unk_StreamPoint m_8d8;                                 // +0x8d8 (0,0,0)
    Unk_StreamPoint m_8e4;                                 // +0x8e4 (0,0,0)
    bool m_8f0;                                         // +0x8f0 = true
    int m_8f4;                                          // +0x8f4
    int m_8f8;                                          // +0x8f8
    std::set<void*> m_900;                              // +0x900 0x1413e86d0 / 0x1413e91c0 (shared) TYPE?
    int m_910;                                          // +0x910
    bool m_914;                                         // +0x914
    bool m_915;                                         // +0x915
    int m_918;                                          // +0x918
    bool m_91c;                                         // +0x91c = true
    CString m_920;                                      // +0x920
    int m_928;                                          // +0x928
    ATL::CAtlMap<unsigned, Unk_WsElem> m_930;           // +0x930 0x141bef620 / 0x141bf4a40 TYPE?
    int m_978;                                          // +0x978
    int m_97c;                                          // +0x97c
    std::set<void*> m_980;                              // +0x980 0x141bf3080 / 0x141bf5d10 TYPE?
    std::set<void*> m_990;                              // +0x990 0x141bf3050 / 0x141bf5cf0 TYPE?
    std::vector<Unk_WsElem> m_9a0;                      // +0x9a0 0x141bf3390 / 0x141bf5f80 TYPE?
    int m_9b8;                                          // +0x9b8
    int m_9bc;                                          // +0x9bc
    float m_9c0;                                        // +0x9c0 = 1.0f
    float m_9c4;                                        // +0x9c4 = 1.0f
    int m_9c8;                                          // +0x9c8
    ATL::CAtlList<Unk_WsElem> m_9d0;                    // +0x9d0 0x141beff20 / 0x141bf4d30 TYPE?
    std::vector<Unk_WsElem> m_a00;                      // +0xa00 0x141bf3330 / 0x141bf5f20 TYPE?
    std::vector<Unk_WsElem> m_a18;                      // +0xa18 0x141bf3360 / 0x141bf5f50 TYPE?
    CLockCriticalSection m_lock;                        // +0xa30
    CString m_a60;                                      // +0xa60 = ""
    CString m_a68;                                      // +0xa68
    int m_a70;                                          // +0xa70 interval (ms) for the 0xa5 packet toggle
    int m_a74;                                          // +0xa74 next tick
    bool m_a78;                                         // +0xa78
    MS2Ptr<Unk_WsPtred> m_a80;                           // +0xa80 0x141bf1750 / 0x141bf5600 TYPE?
    Unk_WsOptional<float> m_a90;                        // +0xa90 ctor 0x141bf0e70, reset 0x141c2ed00, set 0x141bf68b0
    bool m_a98;                                         // +0xa98
    MS2Ptr<Unk_WsPtred> m_aa0;                           // +0xaa0 0x141bf1650(0) / 0x141bf55d0 TYPE?
    std::set<void*> m_ab0;                              // +0xab0 0x141bf3110 / 0x141bf5d70 TYPE?
    std::set<void*> m_ac0;                              // +0xac0 0x141bf3020 / 0x141bf5cd0 TYPE?
    std::set<void*> m_ad0;                              // +0xad0 0x141bf3140 / 0x141bf5d90 TYPE?
    int m_ae0;                                          // +0xae0
    int m_ae4;                                          // +0xae4
    int m_ae8;                                          // +0xae8
    int m_aec;                                          // +0xaec
};
MS2_CHECK_SIZE(WorldService, 0xaf0);
MS2_CHECK_OFFSET(WorldService, m_category, 0x30);   // +0x28 = efd::AtomicRefCount (EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT, ctor 0x140ae79e0)
MS2_CHECK_OFFSET(WorldService, m_048, 0x48);
MS2_CHECK_OFFSET(WorldService, m_208, 0x208);
MS2_CHECK_OFFSET(WorldService, m_298, 0x298);
MS2_CHECK_OFFSET(WorldService, m_3e8, 0x3e8);
MS2_CHECK_OFFSET(WorldService, m_7c8, 0x7c8);
MS2_CHECK_OFFSET(WorldService, m_800, 0x800);
MS2_CHECK_OFFSET(WorldService, m_890, 0x890);
MS2_CHECK_OFFSET(WorldService, m_900, 0x900);
MS2_CHECK_OFFSET(WorldService, m_930, 0x930);
MS2_CHECK_OFFSET(WorldService, m_9a0, 0x9a0);
MS2_CHECK_OFFSET(WorldService, m_lock, 0xa30);
MS2_CHECK_OFFSET(WorldService, m_a80, 0xa80);
MS2_CHECK_OFFSET(WorldService, m_ad0, 0xad0);

inline TSingleton<WorldService>::TSingleton() { s_instance = static_cast<WorldService*>(this); }
