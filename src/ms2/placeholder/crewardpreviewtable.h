// crewardpreviewtable.h - PLACEHOLDER for CRewardPreviewTable (RTTI .?AVCRewardPreviewTable@@, 0x88 bytes). NOT an original header.
// Bases: TSingleton<CRewardPreviewTable> at +0x0, CValidData<CRewardPreviewTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CRewardPreviewTable : public TSingleton<CRewardPreviewTable>, public CValidData<CRewardPreviewTable>
{
public:
    CRewardPreviewTable();                                  // 0x140dc3b70
    virtual ~CRewardPreviewTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x88 - 0x10];
};
MS2_CHECK_SIZE(CRewardPreviewTable, 0x88);
