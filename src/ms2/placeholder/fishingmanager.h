// fishingmanager.h - PLACEHOLDER for CFishingManager (RTTI .?AVCFishingManager@@: TSingleton<CFishingManager> +0,
// ICastingEventListener +8; 0x1c0 bytes; ctor 0x140cd9400, s_instance 0x143ab3848). NOT an original header: only the
// members other units touch. Owning unit: ?\fishingmanager.cpp.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/icastingeventlistener.h"

class CFishingManager : public TSingleton<CFishingManager>, public ICastingEventListener
{
public:
    void OnCastingFinished() override;                      // 0x140cdab60
    void FUN_140cdb1e0();                                   // leave the fishing spot (packet 0x73 mode 9)
    int FUN_140cdb250();                                    // start fishing at the current spot
    int FUN_140954150() { return m_bFishing; }              // @0x140954150 (actionkeyobject.cpp)

private:
    MS2_LAYOUT_FRIEND;
    int m_bFishing;                                         // +0x10 the player is in fishing mode
    char m_pad_14[0x1c0 - 0x14];                            // unrecovered members
};
MS2_CHECK_OFFSET(CFishingManager, m_bFishing, 0x10);
MS2_CHECK_SIZE(CFishingManager, 0x1c0);
