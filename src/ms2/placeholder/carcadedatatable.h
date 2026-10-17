// carcadedatatable.h - PLACEHOLDER for CArcadeDataTable (RTTI .?AVCArcadeDataTable@@, 0xe8 bytes). NOT an original header.
// Bases: TSingleton<CArcadeDataTable> at +0x0, CValidData<CArcadeDataTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include <atlcoll.h>
#include <vector>
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

// The arcade entries (?\arcademaindata.cpp); not recovered.
class Unk_ArcadeData : public CPtred
{
};

class CArcadeDataTable : public TSingleton<CArcadeDataTable>, public CValidData<CArcadeDataTable>
{
public:
    // @0x141495e10
    CArcadeDataTable() {}
    // @0x1414973c0
    virtual ~CArcadeDataTable() {}
private:
    MS2_LAYOUT_FRIEND;
    // The value types are assumed from the node sizes of the RemoveAll instances (?\arcademaindata.cpp): a 0x10
    // value for the first map, a 0x18 value with non-trivial elements for the other two.
    ATL::CAtlMap<int, MS2Ptr<Unk_ArcadeData> > m_map10;                  // +0x10
    ATL::CAtlMap<int, std::vector<MS2Ptr<Unk_ArcadeData> > > m_map58;    // +0x58
    ATL::CAtlMap<int, std::vector<CString> > m_mapA0;                     // +0xa0
};
MS2_CHECK_SIZE(CArcadeDataTable, 0xe8);
