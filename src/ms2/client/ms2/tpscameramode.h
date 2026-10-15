// tpscameramode.h - CTPSCameraMode (RTTI .?AVCTPSCameraMode@@): the third-person (shoulder) camera (mode id 9) derived
// from CFPSCameraMode; it reuses the FPS camera's update with a "TPS_Dummy" node and an alpha fade of the followed
// actor. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\tpscameramode.cpp`
// (0x14185aa10-0x14185b1b0). Header name assumed.
#pragma once

#include "fpscameramode.h"

// 0x148 bytes (no members of its own). vftable 0x142f87370.
class CTPSCameraMode : public CFPSCameraMode
{
public:
    CTPSCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);    // 0x14185aa10
    virtual ~CTPSCameraMode();                                          // 0x14185aa90

    virtual int vfunc_1() { return 9; }                                 // @0x14185aff0
    virtual bool vfunc_2() { return false; }                            // @0x14185b000
    virtual void vfunc_8(double fTime);                                 // 0x14185aac0
    virtual void vfunc_24(Unk_CameraTargetEntity* p, int n);            // 0x14185aaf0
    virtual BOOL vfunc_31();                                            // 0x14185af80
};
MS2_CHECK_SIZE(CTPSCameraMode, 0x148);
