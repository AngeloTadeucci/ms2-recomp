// cmasteryinteriortable.h - PLACEHOLDER for CMasteryInteriorTable (RTTI .?AVCMasteryInteriorTable@@, 0xe0 bytes). NOT an original header.
// Bases: TSingleton<CMasteryInteriorTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CMasteryInteriorTable : public TSingleton<CMasteryInteriorTable>
{
public:
    CMasteryInteriorTable();                                // 0x140661c00
    virtual ~CMasteryInteriorTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_8[0xe0 - 0x8];
};
MS2_CHECK_SIZE(CMasteryInteriorTable, 0xe0);
