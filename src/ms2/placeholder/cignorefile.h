// cignorefile.h - PLACEHOLDER for CIgnoreFile (RTTI .?AVCIgnoreFile@@, 0x30 bytes). NOT an original header.
// Bases: TSingleton<CIgnoreFile> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CIgnoreFile : public TSingleton<CIgnoreFile>
{
public:
    CIgnoreFile();                                          // 0x14050e140
    virtual ~CIgnoreFile();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0x30 - 0x8];
};
MS2_CHECK_SIZE(CIgnoreFile, 0x30);
