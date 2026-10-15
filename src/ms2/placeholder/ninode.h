// ninode.h - the real Gamebryo NiNode (engine/gamebryo/CoreRuntime/EngineLibs/NiMain/NiNode.h; NiNode : NiAVObject :
// NiObjectNET : NiObject : NiRefObject), now that the engine include dirs are on the game include path
// (cmake/ms2-engine-flags.cmake; docs/RECOVERY.md section 3). Kept as a forwarding header so the existing includes keep
// working; new code includes <NiNode.h> directly. MS2's engine has Nexon's NiAVObject changes (+1 virtual, +8 bytes), already
// applied to engine/gamebryo: sizeof(NiNode) 0x130, 42 vftable slots (slot 31 UpdateEffectsDownward, 0x141d1c3f0), ctor
// 0x141d19760, dtor 0x141d19930, CopyMembers 0x141d1a1e0, ms_RTTI 0x143afa4d8.
#pragma once
#include <NiNode.h>

#include "ms2/ms2layout.h"

MS2_CHECK_SIZE(NiAVObject, 0xe8);
MS2_CHECK_SIZE(NiNode, 0x130);
