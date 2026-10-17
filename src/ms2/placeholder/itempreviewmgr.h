// itempreviewmgr.h - PLACEHOLDER for ItemPreviewMgr (RTTI .?AVItemPreviewMgr@@, 0x28 bytes). NOT an original header.
// Bases: TSingleton<ItemPreviewMgr> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class ItemPreviewMgr : public TSingleton<ItemPreviewMgr>
{
public:
    ItemPreviewMgr();                                       // 0x140d3fff0
    virtual ~ItemPreviewMgr();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x28 - 0x8];
};
MS2_CHECK_SIZE(ItemPreviewMgr, 0x28);
