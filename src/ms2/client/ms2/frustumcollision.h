// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFrustumCollision:
// frustum-based collision detection.
// MS2-UNIT: ?\frustumcollision.cpp
// MS2-RANGE: 0x141222df0-0x141225080 .text$mn
#pragma once

#include "ms2/ms2layout.h"
#include <NiFrustum.h>
#include <NiFrustumPlanes.h>

// 0x190 bytes. vftable 0x142ec3fb8, 6 slots.
class CFrustumCollision
{
public:
    CFrustumCollision();                    // 0x141222df0
    virtual ~CFrustumCollision();           // scalar deleting destructor at 0x141224ef0

    virtual void vfunc_3(const NiFrustum& kFrustum);  // 0x141222f50
    virtual void vfunc_4(const NiFrustumPlanes& kPlanes);  // 0x141223bc0
    virtual bool vfunc_5();                 // 0x141224920
    virtual void vfunc_6();                 // 0x141224800

    // Members - actual layout from exe
    NiFrustum m_kFrustum;       // +0x8
    NiFrustumPlanes m_kPlanes;  // +0x28
    void* m_pad_88;
    void* m_pad_90;
    void* m_pad_98;
    void* m_pad_a0;
    void* m_pad_a8;
    void* m_pad_b0;
    void* m_pad_b8;
    void* m_pad_c0;
    void* m_pad_c8;
    void* m_pad_d0;
    void* m_pad_d8;
    void* m_pad_e0;
    void* m_pad_e8;
    void* m_pad_f0;
    void* m_pad_f8;
    void* m_pad_100;
    void* m_pad_108;
    void* m_pad_110;
    void* m_pad_118;
    void* m_pad_120;
    void* m_pad_128;
    void* m_pad_130;
    void* m_pad_138;
    void* m_pad_140;
    void* m_pad_148;
    void* m_pad_150;
    void* m_pad_158;
    void* m_pad_160;
    void* m_pad_168;
    void* m_pad_170;
    void* m_pad_178;
    void* m_pad_180;
    void* m_pad_188;
};
MS2_CHECK_SIZE(CFrustumCollision, 0x190);
