// physxerror.h - PLACEHOLDER for CPhysXError (RTTI .?AVCPhysXError@@, base NxUserOutputStream): the game's PhysX
// error / print sink handed to efdPhysX::PhysXSDKManager::Initialize. NOT an original header; owning unit ?\physxerror.cpp
// (ctor 0x1416889f0). Only the ctor is called by recovered code; the overrides are declared so the class is concrete.
#pragma once

#include "ms2/ms2layout.h"
#include <NxUserOutputStream.h>

class CPhysXError : public NxUserOutputStream
{
public:
    CPhysXError();                                                                  // 0x1416889f0
    virtual void reportError(NxErrorCode code, const char* message, const char* file, int line);
    virtual NxAssertResponse reportAssertViolation(const char* message, const char* file, int line);
    virtual void print(const char* message);
};
MS2_CHECK_SIZE(CPhysXError, 8);
