// cptred.h - PLACEHOLDER for CPtred (RTTI .?AVCPtred@@, vftable 0x142ce54a0, 1 slot). NOT an original header.
// Layout from UISwfEntity (IMessageListener base at +0x18). Ctor 0x140159740, dtor 0x140159840.
#pragma once

#include "ms2/ms2layout.h"

class CPtred
{
public:
    CPtred();
    virtual ~CPtred();                  // slot 0 (??_G 0x140159b30)

private:
    void* m_pad_08;                     // +0x08 unknown (reference counting?); not an array (see ms2layout.h)
    void* m_pad_10;
};
MS2_CHECK_SIZE(CPtred, 0x18);
