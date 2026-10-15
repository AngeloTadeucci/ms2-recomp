// ms2pickservice.h - MS2PickService (RTTI .?AVMS2PickService@@): the game's subclass of the engine's ecr::PickService.
// Second base IWorldServiceCallback at +0x80; its slot 3 clears the picker's targets when the world is torn down.
// Recovered from MapleStory2.exe KMS2_DEV x64; ctor in `?\ms2.cpp` (0x141496240), the rest in
// `?\ms2renderservice.cpp` (0x1414ee750-0x1414ee84a).
#pragma once

#include "ms2/ms2layout.h"
#include <ecr/PickService.h>
#include "ms2/placeholder/iworldservicecallback.h"

class MS2PickService : public ecr::PickService, public IWorldServiceCallback
{
public:
    MS2PickService();                                                   // 0x141496240
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);     // 0x1414ee750
    virtual efd::AsyncResult OnInit();                                  // 0x1414ee7b0
    virtual void vfunc_3(int);                                          // 0x1414ee810 (IWorldServiceCallback slot 3)
};
MS2_CHECK_SIZE(MS2PickService, 0x88);
