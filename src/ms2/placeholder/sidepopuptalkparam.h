// sidepopuptalkparam.h - PLACEHOLDER for SidePopupTalkParam (RTTI .?AVSidePopupTalkParam@@, vftable 0x142e5b3a0,
// 0xd0 bytes, CPtred-derived): the parameter block of a side-popup talk balloon (NPC speech shown in the corner).
// Owning unit is ?\uisidepopuptalk.cpp (ctor 0x140e90ce0, dtor 0x140e910b0, ??_G 0x140e91870), not recovered yet; this
// declares only what the trigger service needs. Field names are invented from their use. NOT an original header.
#pragma once

#include <atlstr.h>
#include "ms2/placeholder/cptred.h"

class SidePopupTalkParam : public CPtred
{
public:
    SidePopupTalkParam();                   // 0x140e90ce0
    virtual ~SidePopupTalkParam();          // 0x140e910b0 (slot 0)

    int m_nKind;                            // +0x18
    char m_pad_1c[0x38 - 0x1c];
    CStringW m_strText;                     // +0x38
    CStringA m_strIcon;                     // +0x40
    CStringA m_strName;                     // +0x48
    int m_nNpcId;                           // +0x50
    int m_pad_54;
    CStringA m_strSound;                    // +0x58
    CStringA m_strScript;                   // +0x60
    CStringA m_str68;                       // +0x68 image path (scenestategame 0x11f)
    CStringW m_str70;                       // +0x70 display name
    CStringA m_str78;                       // +0x78
    char m_pad_80[0xd0 - 0x80];
};
MS2_CHECK_SIZE(SidePopupTalkParam, 0xd0);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_strText, 0x38);
MS2_CHECK_OFFSET(SidePopupTalkParam, m_strScript, 0x60);
