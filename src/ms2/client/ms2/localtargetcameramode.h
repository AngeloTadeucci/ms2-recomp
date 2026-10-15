// localtargetcameramode.h - CLocalTargetCameraMode (RTTI .?AVCLocalTargetCameraMode@@): the camera mode that follows
// the local player's target (mode id 0x10) and blends between camera setups (derived from CTargetCameraMode).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\localtargetcameramode.cpp`
// (0x140d4dce0-0x140d4fcd0). Header name assumed; vfunc_N are vftable slots and the member names are invented from
// their use.
#pragma once

#include "targetcameramode.h"

// A camera setup (0x70 bytes, the camera manager's "setup" row): the base setting plus the blend parameters. The
// ctor (0x140ae8aa0) and the copy assignment (0x140af6fc0) belong to another obj.
struct Unk_CameraSetup : public Unk_CameraSetting
{
    Unk_CameraSetup();                                          // 0x140ae8aa0
    Unk_CameraSetup& operator=(const Unk_CameraSetup& o);       // 0x140af6fc0

    int m_28;                           // +0x28 kind (1: follow, 3: ...)
    int m_2c;
    float m_30;                         // +0x30 abort distance
    int m_34;                           // +0x34 map id
    float m_38;                         // +0x38 camera distance
    float m_3c;                         // +0x3c blend time
    Unk_StreamPoint m_40;               // +0x40 offset
    Unk_StreamPoint m_4c;               // +0x4c player rotation
    bool m_58;                          // +0x58 turn the player
    bool m_59;                          // +0x59
    int m_5c;                           // +0x5c easing types
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
};
MS2_CHECK_SIZE(Unk_CameraSetup, 0x70);

// 0x1f8 bytes. vftable (40 slots) is the one written by the ctor.
class CLocalTargetCameraMode : public CTargetCameraMode
{
public:
    CLocalTargetCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x140d4dce0
    virtual ~CLocalTargetCameraMode();                                          // 0x140d4e2b0

    // @0x140d4fc80
    virtual int vfunc_1() { return 0x10; }
    // @0x140a4e620 (COMDAT of another obj)
    virtual bool vfunc_2() { return false; }
    virtual void vfunc_6(int n);
    virtual void vfunc_7();
    virtual void vfunc_8(double fTime);
    virtual void vfunc_10();
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);
    // @0x140d4f9f0
    virtual bool vfunc_34() { return m_108.m_59; }
    virtual void vfunc_37();
    // @0x140d4f9d0
    virtual BOOL vfunc_38(Unk_StreamPoint ptPos, Unk_StreamPoint ptRot) { return 0; }

    void FUN_140d4f680(const Unk_CameraSetup& setup);   // start blending to a setup
    void FUN_140d4f830();                               // abort the blend (return to the previous setup)
    void FUN_140d4fa10(float f);                        // set the wanted, previous and start fov
    bool FUN_140d4fa60(const Unk_CameraSetup& setup);   // jump to a setup unless a blend is running

    Unk_CameraSetup m_108;              // +0x108 the wanted setup
    int m_178;                          // +0x178 blending
    int m_17c;                          // +0x17c follow-type setup
    int m_180;
    int m_184;                          // +0x184 aborting
    float m_188;                        // +0x188 blend time
    float m_18c;                        // +0x18c
    float m_190;                        // +0x190
    Unk_StreamPoint m_194;              // +0x194
    Unk_StreamPoint m_1a0;              // +0x1a0
    Unk_StreamPoint m_1ac;              // +0x1ac
    float m_1b8;
    float m_1bc;
    float m_1c0;
    Unk_CameraSetting m_1c4;            // +0x1c4 the previous setting
    int m_1ec;                          // +0x1ec previous mode id
    int m_1f0;
};
MS2_CHECK_SIZE(CLocalTargetCameraMode, 0x1f8);
MS2_CHECK_OFFSET(CLocalTargetCameraMode, m_108, 0x108);
MS2_CHECK_OFFSET(CLocalTargetCameraMode, m_1c4, 0x1c4);
