// ecrlightservice.h - PLACEHOLDER for the MS2 changes to the engine's ecr::LightService (engine/gamebryo/GameFramework/ecr/
// LightService.h). NOT an original header. The exe's ecr::LightService::HandleEntityAddedMessage (0x142027c..) calls a
// global callback with the id of every new light entity when one is set (MS2LightService sets it while a world loads and
// creates the queued lights itself). The SDK header has no such hook, so the callback and its inline setter are free
// declarations here; the setter's COMDAT copy sits in ms2lightservice.cpp (0x1414c9b70).
#pragma once

#include <egf/EntityID.h>

typedef void (*Unk_LightAddedCallback)(const egf::EntityID& entityID);

extern Unk_LightAddedCallback g_pfnLightAdded;                         // 0x143afe760

inline void SetLightAddedCallback(Unk_LightAddedCallback pfnCallback)  // 0x1414c9b70 (COMDAT)
{
    g_pfnLightAdded = pfnCallback;
}
