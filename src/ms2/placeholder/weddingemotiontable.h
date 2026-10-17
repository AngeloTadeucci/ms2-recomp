// weddingemotiontable.h - PLACEHOLDER for WeddingEmotionTable (RTTI .?AVWeddingEmotionTable@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<WeddingEmotionTable> at +0x0, CValidData<WeddingEmotionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class WeddingEmotionTable : public TSingleton<WeddingEmotionTable>, public CValidData<WeddingEmotionTable>
{
public:
    WeddingEmotionTable();                                  // 0x140903170
    virtual ~WeddingEmotionTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x20 - 0x10];
};
MS2_CHECK_SIZE(WeddingEmotionTable, 0x20);
