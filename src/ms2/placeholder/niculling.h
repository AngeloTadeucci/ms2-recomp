// niculling.h - the real Gamebryo NiCullingProcess / NiSPWorkflowManager (engine/gamebryo/CoreRuntime/EngineLibs/NiMain/
// NiCullingProcess.h, NiFloodgate/NiSPWorkflowManager.h), now that the engine include dirs are on the game include path
// (cmake/ms2-engine-flags.cmake; docs/RECOVERY.md section 3). Kept as a forwarding header so the existing includes keep
// working; new code includes the engine headers directly. Exe facts: NiCullingProcess 0xc0 bytes, 9 vftable slots (MSVC
// reverses same-name overloads, so the exe order is Process(NiAVObject*), Process(list), Process(scene)), ctors 0x141d53c30 /
// 0x141d53d10, dtor 0x141d53df0, ms_RTTI 0x143afaf20; NiSPWorkflowManager 0x38 bytes (ctor 0x141cfbd30, FlushTaskGroup 0x141cfcbf0).
#pragma once
#include <NiCullingProcess.h>
#include <NiSPWorkflowManager.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/ninode.h"

MS2_CHECK_SIZE(NiSPWorkflowManager, 0x38);
MS2_CHECK_SIZE(NiCullingProcess, 0xc0);
