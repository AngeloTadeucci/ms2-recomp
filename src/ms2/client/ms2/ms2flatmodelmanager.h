// ms2flatmodelmanager.h - MS2FlatModelManager: egf::FlatModelManager subclass (0x208) that registers the flat-model
// asset factory with the AssetFactoryManager (hooking in the script factory) or falls back to a "urn:emergent-flat-model"
// asset-locate request, pausing the scheduler meanwhile.
// Owning unit: ?\ms2flatmodelmanager.cpp (0x140d86560-0x140d878b0, dir client\ms2).
#pragma once
#include "ms2/ms2layout.h"
#include <egf/FlatModelManager.h>

class MS2FlatModelManager : public egf::FlatModelManager
{
public:
    MS2FlatModelManager();                  // 0x140d86560
    virtual ~MS2FlatModelManager();         // 0x140d865a0, ??_G 0x140d87010
    virtual efd::AsyncResult OnInit();      // 0x140d865d0
};
MS2_CHECK_SIZE(MS2FlatModelManager, 0x208);
