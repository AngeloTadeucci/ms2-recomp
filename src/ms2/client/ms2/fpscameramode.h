// fpscameramode.h - CFPSCameraMode (RTTI .?AVCFPSCameraMode@@): the first-person camera (mode id 10) derived from
// CConsoleCameraMode; base of CTPSCameraMode. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\fpscameramode.cpp` (0x141221290-0x1412221e0). Header name assumed; vfunc_N are vftable slots and the member names
// are invented from their use.
#pragma once

#include "consolecameramode.h"

class NiAVObject;
class Unk_RpgActor;

// 0x148 bytes.
class CFPSCameraMode : public CConsoleCameraMode
{
public:
    CFPSCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);    // 0x141221290
    virtual ~CFPSCameraMode();                                          // 0x141221350

    virtual int vfunc_1() { return 10; }                                // @0x1412221c0
    virtual bool vfunc_2() { return false; }                            // @0x1412221d0
    virtual void vfunc_6(int n);                                        // 0x141221380
    virtual void vfunc_7();                                             // 0x141221480
    virtual void vfunc_8(double fTime);                                 // 0x141221650
    virtual void vfunc_9();                                             // 0x1412214e0
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);            // 0x141221c20
    virtual float vfunc_27() { return 0.0f; }                           // @0x141222170 eye height above the head node
    virtual BOOL vfunc_31();                                            // 0x1412220a0

    Unk_RpgActor* m_130;                                                // +0x130 the followed actor
    NiAVObject* m_138;                                                  // +0x138 its "FPS_Dummy" node (or root)
    int m_140;                                                          // +0x140 FPS_HidePC (ctor 1)
    int m_144;                                                          // +0x144 FPS_MouseDownMove (ctor 0)
};
MS2_CHECK_SIZE(CFPSCameraMode, 0x148);
