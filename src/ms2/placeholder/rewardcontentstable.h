// rewardcontentstable.h - PLACEHOLDER for RewardContentsTable (RTTI .?AVRewardContentsTable@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<RewardContentsTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class RewardContentsTable : public TSingleton<RewardContentsTable>
{
public:
    RewardContentsTable();                                  // 0x140770c50
    virtual ~RewardContentsTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x38 - 0x8];
};
MS2_CHECK_SIZE(RewardContentsTable, 0x38);
