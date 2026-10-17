// webguidetable.h - PLACEHOLDER for WebGuideTable (RTTI .?AVWebGuideTable@@, 0x88 bytes). NOT an original header.
// Bases: DataTableMap<WebGuide, CString, ATL::CStringElementTraits<CString>> at +0x0, TSingleton<WebGuideTable> at +0x80.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/datatablemap.h"

class WebGuideTable : public DataTableMap<WebGuide, CString, ATL::CStringElementTraits<CString>>,
                      public TSingleton<WebGuideTable>
{
public:
    WebGuideTable();                                        // 0x141b81bd0
    virtual ~WebGuideTable();
};
MS2_CHECK_SIZE(WebGuideTable, 0x88);
