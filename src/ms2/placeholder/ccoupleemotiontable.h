// ccoupleemotiontable.h - PLACEHOLDER for CCoupleEmotionTable (RTTI .?AVCCoupleEmotionTable@@, 0x40 bytes). NOT an original header.
// Bases: TSingleton<CCoupleEmotionTable> at +0x0, CValidData<CCoupleEmotionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CCoupleEmotionTable : public TSingleton<CCoupleEmotionTable>, public CValidData<CCoupleEmotionTable>
{
public:
    CCoupleEmotionTable();                                  // 0x1402c6e60
    virtual ~CCoupleEmotionTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x40 - 0x10];
};
MS2_CHECK_SIZE(CCoupleEmotionTable, 0x40);
