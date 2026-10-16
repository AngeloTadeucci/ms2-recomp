// bgtransparencymgr.h - BGTransparencyMgr: fades background objects (props / walls between camera and player) by
// toggling their transparency. A TSingleton that is also an IWorldServiceCallback (slot 3 clears the tracked
// objects). Layout proved by the constructor 0x140a0cd30 and the allocation (0x98) in FUN_141498f10.
// Also holds TransparencyElement (the per-entity fade state, 0x60 bytes) and the TransparencyStandardMaterial
// declaration the unit's code needs (its definition belongs to ?\transparencymaterial.cpp).
#pragma once
#include <list>
#include <map>
#include <set>
#include <vector>
#include <efd/SmartPointer.h>
#include <efd/IBase.h>
#include <efd/customalloc.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <ecr/PickService.h>
#include <ecr/SceneGraphService.h>
#include <NiRefObject.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/client/ms2/gameobject.h"

class NiAVObject;
class NiNode;

// Transparency material attached to a mesh (0x38 bytes); slots 2, 3 and 4 are used here.
class TransparencyStandardMaterial
{
public:
    static void* operator new(size_t nSize, unsigned nCat);     // 0x14208a860
    static void operator delete(void* p, unsigned nCat);        // 0x14097f700
    static void operator delete(void* p);                       // the deleting dtor frees through the heap
    TransparencyStandardMaterial(void* pGeometry);              // 0x140a16050
    virtual ~TransparencyStandardMaterial();
    virtual void vfunc_1();
    virtual void vfunc_2(const void* pBound);                   // MS2: slot 2 (0x10), takes the 16-byte world bound
    virtual void vfunc_3();                                     // MS2: slot 3 (0x18) restore the mesh
    virtual void vfunc_4(float fAlpha);                         // MS2: slot 4 (0x20) set alpha
    char m_pad_08[0x38 - 8];
};

// Per-entity fade state (vftable 0x142dc3ac0, ctor 0x140a15fe0, dtor 0x140a166f0). m_fAlpha is the entity's
// target alpha (property 0x188f01c1, default 0.3).
class TransparencyElement : public NiRefObject
{
public:
    TransparencyElement();                                          // 0x140a15fe0
    virtual ~TransparencyElement();                                 // 0x140a166f0 (deleting 0x140a17880)

    std::list<TransparencyStandardMaterial*, efd::CustomAllocator<TransparencyStandardMaterial*> > m_materials;   // 0x10
    Timer m_timer;                                                  // 0x20
    float m_fAlpha;                                                 // 0x58
};
MS2_CHECK_SIZE(TransparencyElement, 0x60);
MS2_CHECK_OFFSET(TransparencyElement, m_materials, 0x10);
MS2_CHECK_OFFSET(TransparencyElement, m_timer, 0x20);
MS2_CHECK_OFFSET(TransparencyElement, m_fAlpha, 0x58);

// A tracked scene-graph entity as WorldService::FUN_141bc7920 collects it (same layout as Unk_WsV1d8).
struct Unk_BGTRegion
{
    NiAVObject* m_pNode;                                            // +0x00 scene node
    int m_nKind;                                                    // +0x08 0: always, 1: only with the world flag
    int m_pad_0c;
    egf::EntityID m_id;                                             // +0x10
    int m_nGroup;                                                   // +0x18 key of the linked-entity groups (> 0)
    int m_pad_1c;
    bool operator<(const Unk_BGTRegion& o) const { return m_id < o.m_id; }
};
MS2_CHECK_SIZE(Unk_BGTRegion, 0x20);

typedef efd::SmartPointer<egf::Entity> Unk_BGTEntityPtr;
typedef std::map<Unk_BGTEntityPtr, TransparencyElement*> Unk_BGTElementMap;

class BGTransparencyMgr;
template <class T> class TSingleton;
template <> class TSingleton<BGTransparencyMgr>
{
public:
    TSingleton();                                   // 0x140a15390 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }       // 0x140a17780
    static BGTransparencyMgr* s_instance;
};

class BGTransparencyMgr : public TSingleton<BGTransparencyMgr>, public IWorldServiceCallback
{
public:
    BGTransparencyMgr();                            // 0x140a0cd30
    virtual ~BGTransparencyMgr();                   // 0x140a17800 (deleting) / 0x140a0ce30
    virtual void vfunc_1();                         // 0x140a0db00 scan: pick the objects hiding the players
    virtual void vfunc_3(int);                      // 0x140a0d230 (IWorldServiceCallback slot 3: world torn down)

    int Init();                                     // 0x140a0cee0 register with the world, grab the services
    void Shutdown();                                // 0x140a0cf90
    void Tick();                                    // 0x140a0d000 per frame: fade, rescan every 300 ms
    void SetUserFlags(int nFlags);                  // 0x140a0d0c0
    void AddObject(GameObject* pObject);            // 0x140a0d130
    void RemoveObject(GameObject* pObject);         // 0x140a0d190
    void EraseEntity(egf::Entity* pEntity);         // 0x140a0d450 forget a destroyed entity
    bool IsTarget(egf::Entity* pEntity);            // 0x140a0d670 may this entity be faded
    bool RayHits(efd::Point3 ptOrigin, efd::Point3 ptDir, NiAVObject* pNode);   // 0x140a0d7a0
    bool PickEntities(efd::Point3 ptOrigin, efd::Point3 ptDir, std::vector<egf::Entity*>& kOut, egf::Entity* pSkip);   // 0x140a0d880
    void Apply(std::set<egf::Entity*>& kHit);       // 0x140a0e330 start fading the entities in kHit
    void SortEntities();                            // 0x140a0e860 tag the faded meshes with their camera-distance rank
    void UpdateFadeOut();                           // 0x140a0ebf0
    void UpdateFadeIn();                            // 0x140a0ed80
    void ReleaseMaterials(egf::Entity* pEntity, TransparencyElement* pElement);   // 0x140a0f020
    void MoveAllToFadeIn();                         // 0x140a0f200
    void MoveMissingToFadeIn(std::set<egf::Entity*>& kHit);   // 0x140a0f2d0
    static void DeleteMaterials(TransparencyElement* pElement);   // 0x140a0f140
    static bool CompareDistance(egf::Entity* pA, egf::Entity* pB);   // 0x140a0f460 farther first

    efd::SmartPointer<ecr::PickService> m_spService;                // 0x10
    efd::SmartPointer<ecr::SceneGraphService> m_spSceneGraph;       // 0x18
    std::set<efd::SmartPointer<GameObject> > m_set20;               // 0x20 the players that must stay visible
    Unk_BGTElementMap m_map30;                                      // 0x30 fading out
    Unk_BGTElementMap m_map40;                                      // 0x40 fading back in
    Timer m_timer;                                                  // 0x50
    int m_nFlags;                                                   // 0x88
    int m_nUserFlags;                                               // 0x8c
    int m_nWorldFlags;                                              // 0x90
};
MS2_CHECK_SIZE(BGTransparencyMgr, 0x98);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_spService, 0x10);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_set20, 0x20);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_timer, 0x50);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_nWorldFlags, 0x90);
