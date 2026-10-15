// lockcameramode.h - CLockCameraMode (RTTI .?AVCLockCameraMode@@): a camera mode (id 4) that keeps the pose it was
// given and ignores updates. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\lockcameramode.cpp` (0x14144fd30-0x14144fe90). Header name assumed; vfunc_N are vftable slots.
#pragma once

#include "cameramode.h"

// 0x78 bytes (no members of its own). vftable 0x142f14da8, 37 slots.
class CLockCameraMode : public CCameraMode
{
public:
    CLockCameraMode(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev);   // 0x14144fd30
    virtual ~CLockCameraMode();                                         // 0x14144fdb0

    // @0x14144fe70
    virtual int vfunc_1() { return 4; }
    // @0x14144fe80
    virtual bool vfunc_2() { return true; }
    virtual void vfunc_8(double fTime);                                 // 0x14144fde0
    virtual void vfunc_9();                                             // 0x14144fe00
    virtual float vfunc_22();                                           // 0x14144fe20
};
MS2_CHECK_SIZE(CLockCameraMode, 0x78);
