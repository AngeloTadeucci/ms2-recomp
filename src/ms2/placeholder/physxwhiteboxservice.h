// physxwhiteboxservice.h - PLACEHOLDER for egmPhysXWhitebox::PhysXWhiteboxService (RTTI .?AVPhysXWhiteboxService@
// egmPhysXWhitebox@@, 0x178 bytes, class id efd::kCLASSID_PhysXWhiteboxService). NOT the SDK header: egmPhysXWhitebox
// (and its base egmWhitebox::WhiteboxService, itself an efd::ISystemService at +0) is not on the engine include path.
// Only the ctor MS2::RegisterServices uses is declared; the layout below the ISystemService base is opaque.
#pragma once

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>
#include <ecr/ecrSystemServiceIDs.h>

#include "ms2/ms2layout.h"

namespace egmPhysXWhitebox
{
class PhysXWhiteboxService : public efd::ISystemService
{
    EE_DECLARE_CLASS1(PhysXWhiteboxService, efd::kCLASSID_PhysXWhiteboxService, efd::ISystemService);
    EE_DECLARE_CONCRETE_REFCOUNT;
public:
    PhysXWhiteboxService();
    virtual const char* GetDisplayName() const;
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_1c[0x178 - 0x1c];
};
}
MS2_CHECK_SIZE(egmPhysXWhitebox::PhysXWhiteboxService, 0x178);
