// nitexturingproperty.h - the real Gamebryo NiTexturingProperty (engine/gamebryo/CoreRuntime/EngineLibs/NiMain/
// NiTexturingProperty.h), now that the engine include dirs are on the game include path (cmake/ms2-engine-flags.cmake;
// docs/RECOVERY.md section 3). Kept as a forwarding header; new code includes <NiTexturingProperty.h> directly. Exe facts
// (KMS2_DEV x64): NiTexturingProperty 88 bytes, 20 slots; ShaderMap 0x28 bytes (ctor 0x140c8f5d0), SetShaderMap 0x141d20b10.
#pragma once
#include <NiTexturingProperty.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"

MS2_CHECK_SIZE(NiTexturingProperty, 88);
MS2_CHECK_SIZE(NiTexturingProperty::ShaderMap, 0x28);
