// nirefobject.h - the real Gamebryo NiRefObject (engine/gamebryo/CoreRuntime/EngineLibs/NiMain/NiRefObject.h), now that the
// engine include dirs are on the game include path (cmake/ms2-engine-flags.cmake; docs/RECOVERY.md section 3). Kept as a
// forwarding header so the existing includes keep working; new code includes <NiRefObject.h> directly. Layout: 0x10 bytes,
// vftable 0x142db3f08 (slot 0 deleting dtor, slot 1 DeleteThis), ctor 0x14098cbd0, dtor 0x14098cf20, DeleteThis 0x141d16bf0.
// NiMemObject is efd::MemObject in this Gamebryo.
#pragma once
#include <NiRefObject.h>

#include "ms2/ms2layout.h"

MS2_CHECK_SIZE(NiRefObject, 0x10);
