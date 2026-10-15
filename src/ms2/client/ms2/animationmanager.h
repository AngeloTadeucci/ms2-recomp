// animationmanager.h - CAnimationManager (RTTI "CAnimationManager", 0xa0 bytes, base CPtred, vftable 0x142db53e0 with
// the single deleting-dtor slot 0x1409a15e0): per-actor animation helper held by GameObject at +0x48 (MS2Ptr).
// Owning unit: ?\animationmanager.cpp (ctor 0x14099dbe0). Header name assumed. PARTIAL: only the members that other
// units (effectobject) touch are typed; the rest are scalar pads of the right size. Whoever recovers the owning unit may
// replace pads (keep every offset and the size; MS2_CHECK_* below).
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class GameObject;

// 8-byte intrusive handle (default ctor 0x1408a8700, dtor 0x1408a8720; same shape as cubespawnobject's Unk_EntRef).
struct Unk_AnimRef
{
    void* m_p;
};
MS2_CHECK_SIZE(Unk_AnimRef, 8);

class CAnimationManager : public CPtred
{
public:
    CAnimationManager(GameObject* pOwner);                  // 0x14099dbe0
    // Blends/copies the pose of kSrc into this manager at weight fScale (nFlags = 0 from effectobject).
    void FUN_14099e050(Unk_AnimRef& kSrc, float fScale, int nFlags);   // 0x14099e050
    // @0x140a53f90
    Unk_AnimRef& FUN_140a53f90() { return m_78; }           // accessor COMDAT (effectobject.cpp)

public:
    MS2_LAYOUT_FRIEND;
    GameObject* m_pOwner;                                   // +0x18
    void* m_pad_20[6];                                      // +0x20 (init 0x140996b20, 0x50 bytes)
    void* m_pad_50[4];                                      // +0x50
    void* m_pModelCache;                                    // +0x70 = FUN_141b6f910()
    Unk_AnimRef m_78;                                       // +0x78
    void* m_pad_80[2];                                      // +0x80
    void* m_pad_90;                                         // +0x90
    float m_fScale98;                                       // +0x98 = 1.0
    int m_pad_9c;                                           // +0x9c
};
MS2_CHECK_SIZE(CAnimationManager, 0xa0);
MS2_CHECK_OFFSET(CAnimationManager, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CAnimationManager, m_pModelCache, 0x70);
MS2_CHECK_OFFSET(CAnimationManager, m_78, 0x78);
MS2_CHECK_OFFSET(CAnimationManager, m_fScale98, 0x98);
