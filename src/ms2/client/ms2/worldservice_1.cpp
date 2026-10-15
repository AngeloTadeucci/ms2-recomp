// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService, part 1 of 4 (owner w3o2).
// MS2-UNIT: ?\worldservice.cpp#1
// MS2-RANGE: 0x141bb9720-0x141bdbd10 .text$mn
// MS2-RANGE: 0x140120210-0x1401208d0 .text$di
// MS2-PIN: ??_7WorldService@@6BISystemService@efd@@@ 0x142ffeb98
// MS2-PIN: ??_7WorldService@@6B?$TSingleton@VWorldService@@@@@ 0x142ffec20
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/MessageService.h>

EE_IMPLEMENT_CONCRETE_CLASS_INFO(WorldService);
WorldService* TSingleton<WorldService>::s_instance = 0;

// ---- callees owned by other objs / not recovered yet (bound by VA) ----
void* FUN_140876480(void* out, int cat);                // efd memory hint helper, returns int*
void* FUN_14208a860(size_t cb, int hint);               // efd::MemObject operator new
TextureLayerManager* FUN_141bf48f0(void* p);            // TextureLayerManager::TextureLayerManager (COMDAT, #4)
ChaosLightEffectLayerManager* FUN_141046850(void* p);   // ChaosLightEffectLayerManager::ChaosLightEffectLayerManager (other obj)
extern Unk_StreamPoint DAT_143b01a60;

// The 32 hashes pre-registered in m_208 (each with an empty new-tag pointer).
struct Unk_WsHashList
{
    void FUN_140203150(int nBlockSize);                 // CAtlList<unsigned>::CAtlList
    void FUN_140203f00(unsigned v);                     // AddTail
    void* FUN_1405a96e0();                              // GetHeadPosition
    unsigned* FUN_1405a9650(void* pos);                 // GetAt(pos)
    void FUN_1405a9770(void** pos);                     // GetNext(pos) (advances)
    void FUN_1402038f0();                               // dtor
    unsigned char raw[0x30];
};
struct Unk_WsTagPtr { unsigned char raw[0x10]; };
void* FUN_1401b7b90(void* out, int n);                  // new-tag construct (Unk_CommonNew)
void FUN_141bf1270(Unk_WsTagPtr* self, void* tag);      // tag pointer from a new-tag
void FUN_1409f20e0(Unk_WsTagPtr* self);                 // tag pointer dtor
void FUN_141c1af10(void* map, unsigned key, Unk_WsTagPtr* value);   // m_208.SetAt(key, value)

// MS2-FUNCTIONAL: the members are constructed by their C++ types (layout-exact, element types unproven); new
// TextureLayerManager / ChaosLightEffectLayerManager go through the exe's ctors by VA.
// @0x141bb9720
WorldService::WorldService()
    : m_040(0), m_0a8(DAT_143b01a60), m_0b4(3000.0f), m_state(7), m_prevState(7), m_278(0), m_280(false), m_284(0),
      m_288(0), m_28c(1), m_298(0), m_2a8(1), m_2ac(0), m_2b0(0), m_2b4(0), m_2b8(0), m_2bc(0), m_2c0(0), m_2c8(0),
      m_2d0(0), m_2e0(false), m_398(0), m_800(0), m_804(0), m_808(0),
      m_boundsMin(3.402823466e+38f, 3.402823466e+38f, 3.402823466e+38f),
      m_boundsMax(-3.402823466e+38f, -3.402823466e+38f, -3.402823466e+38f), m_8d8(0, 0, 0), m_8e4(0, 0, 0),
      m_8f0(true), m_8f4(0), m_8f8(0), m_910(0), m_914(false), m_915(false), m_918(0), m_91c(true), m_928(0),
      m_978(0), m_97c(0), m_9b8(0), m_9bc(0), m_9c0(1.0f), m_9c4(1.0f), m_9c8(0), m_a60(""), m_a70(0), m_a74(0),
      m_a78(false), m_a98(false), m_aa0(0), m_ae0(0), m_ae4(0), m_ae8(0), m_aec(0)
// @0x141bb9720
{
    int hint;
    void* p = FUN_14208a860(0x20, *(int*)FUN_140876480(&hint, 0));
    TextureLayerManager* pTex = 0;
    if (p) { memset(p, 0, 0x20); pTex = FUN_141bf48f0(p); }
    m_spTextureLayerManager = pTex;
    p = FUN_14208a860(0x28, *(int*)FUN_140876480(&hint, 0));
    m_spChaosLightEffectLayerManager = p ? FUN_141046850(p) : 0;

    m_340 = 0;
    m_8c8 = 0;
    m_8d0 = 0;

    Unk_WsHashList list;
    list.FUN_140203150(10);
    static const unsigned s_hashes[] = {
        0xbadf0a13, 0xc13e30c8, 0xd116ab46, 0x1c68270c, 0x012cd8b5, 0xe4fc9d5d, 0xf9867c37, 0x397175d9,
        0xbcf2d8da, 0x2f96eeb2, 0x02a95a20, 0xd3b04f05, 0x7996c3af, 0x1d20c1b3, 0xc7f9dd65, 0x47e523f0,
        0xb02ee70d, 0x032767dd, 0x319a1ee4, 0x14e880f6, 0x83d1a30e, 0x62f7a42c, 0xe9d08217, 0x72f49865,
        0x85359406, 0x74b363a7, 0x79197a62, 0x4714f9ea, 0xb9c85df1, 0x169ea355, 0x628f2cf9, 0x6fb4d420,
    };
    for (int i = 0; i < 32; ++i)
        list.FUN_140203f00(s_hashes[i]);
    for (void* pos = list.FUN_1405a96e0(); pos; list.FUN_1405a9770(&pos))
    {
        unsigned key = *list.FUN_1405a9650(pos);
        char tag[8];
        Unk_WsTagPtr value;
        FUN_141bf1270(&value, FUN_1401b7b90(tag, 0));
        FUN_141c1af10(&m_208, key, &value);
        FUN_1409f20e0(&value);
    }
    list.FUN_1402038f0();
}

// @0x141bba870
WorldService::~WorldService()
{
}

// @0x141bbae20
const char* WorldService::GetDisplayName() const
{
    return "WorldService";
}

// @0x141bbae40
void WorldService::FUN_141bbae40(void* p)
{
    m_048.insert(p);
}

// @0x141bbae80
void WorldService::FUN_141bbae80(void* p)
{
    std::set<void*>::iterator it = m_048.find(p);
    if (it != m_048.end())
        m_048.erase(it);
}

// @0x141bc1640
void FUN_141bfe6b0(void*);
void WorldService::FUN_141bc1640() { FUN_141bfe6b0(&m_148); }
// @0x141bc1670
void FUN_141bfe6c0(void*);
void WorldService::FUN_141bc1670() { FUN_141bfe6c0(&m_118); }
// @0x141bc16a0
void FUN_141bf7c40(void*);
void WorldService::FUN_141bc16a0() { FUN_141bf7c40(&m_348); }

// @0x141bc32b0
int WorldService::FUN_141bc32b0() { return m_398; }

// @0x141bc6f60
void WorldService::FUN_141bc6f60(int a804, int a800, int a808)
{
    m_804 = a804;
    m_800 = a800;
    m_808 = a808;
}

// @0x141bc70f0
void WorldService::FUN_141bc70f0() {}

// @0x141bc73e0
void WorldService::FUN_141bc73e0(bool b)
{
    m_91c = b;
    FUN_141bc72f0();
}

// @0x141bc7420
bool WorldService::FUN_141bc7420() { return m_91c; }

// @0x141bc7910
void WorldService::FUN_141bc7910() {}

// @0x141bc9a80
int WorldService::FUN_141bc9a80() { return m_928; }

// @0x141bc9fb0
void* WorldService::FUN_141bc9fb0() { return &m_930; }

// @0x141bca220
void WorldService::FUN_141bca220() { m_2bc = 1; }

// @0x141bcad60
void WorldService::FUN_141bcad60(void* p, int n)
{
    m_2c8 = p;
    m_2d0 = n;
}

// @0x141bcaf60
int WorldService::FUN_141bcaf60() { return m_2d0; }

// @0x141bcaf80
void* WorldService::FUN_141bcaf80() { return m_2c8; }

// @0x141bcfbd0
int WorldService::FUN_141bcfbd0()
{
    if (m_state == 4 && m_2b4 != 0)
        return 1;
    else
        return 0;
}

// @0x141bcb2a0
// The exe calls one IDependencyRegistrar::AddDependency<T> COMDAT per service (other objs own them; T by class id).
void FUN_1411ab6e0(efd::IDependencyRegistrar*, unsigned);   // <egf::EntityManager>       0x07001000
void FUN_1410db4c0(efd::IDependencyRegistrar*, unsigned);   // <efd::MessageService>      0x07000003
void FUN_141bdd1e0(efd::IDependencyRegistrar*, unsigned);   // <egf::EntityLoaderService> 0x07001004 (#2)
void FUN_141474630(efd::IDependencyRegistrar*, unsigned);   // <egf::Scheduler>           0x07001002
void FUN_1410db490(efd::IDependencyRegistrar*, unsigned);   // <egf::FlatModelManager>    0x07001001
void FUN_1413d9b80(efd::IDependencyRegistrar*, unsigned);   // <ecr::ShaderService>       0x07002006
void FUN_141bdd1b0(efd::IDependencyRegistrar*, unsigned);   // <ecr::CameraService>       0x07002002 (#2)
void FUN_141bdd210(efd::IDependencyRegistrar*, unsigned);   // <ecrPhysX::PropService>    0x07002020 (#2)
void FUN_1411ab7d0(efd::IDependencyRegistrar*, unsigned);   // <ecr::SceneGraphService>   0x07001008
void FUN_1411ab770(efd::IDependencyRegistrar*, unsigned);   // <ecr::RenderService>       0x07002001
void FUN_1410db460(efd::IDependencyRegistrar*, unsigned);   // <MS2 service>              0x0610001a
efd::SyncResult WorldService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    FUN_1411ab6e0(pDependencyRegistrar, 1);
    FUN_1410db4c0(pDependencyRegistrar, 1);
    FUN_141bdd1e0(pDependencyRegistrar, 1);
    FUN_141474630(pDependencyRegistrar, 1);
    FUN_1410db490(pDependencyRegistrar, 1);
    FUN_1413d9b80(pDependencyRegistrar, 1);
    FUN_141bdd1b0(pDependencyRegistrar, 1);
    FUN_141bdd210(pDependencyRegistrar, 1);
    FUN_1411ab7d0(pDependencyRegistrar, 1);
    FUN_1411ab770(pDependencyRegistrar, 1);
    FUN_1410db460(pDependencyRegistrar, 1);
    return efd::SyncResult_Success;
}
