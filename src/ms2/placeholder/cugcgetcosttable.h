// cugcgetcosttable.h - PLACEHOLDER for CUgcGetCostTable (RTTI .?AVCUgcGetCostTable@@, 0x68 bytes). NOT an original header.
// Bases: TSingleton<CUgcGetCostTable> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Implemented in commonfiles\ugcdef.cpp: the cost table of
// the UGC banner reservations (a time -> percent step map under a lock). Member names are invented from use.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"

class COutputStream;
class CInPacket;
class TUgcGetCostInfo;

class CUgcGetCostTable : public TSingleton<CUgcGetCostTable>
{
public:
    typedef ATL::CRBMap<__int64, int> CostMap;
    typedef ATL::CAtlList<MS2Ptr<TUgcGetCostInfo> > CostList;

    CUgcGetCostTable();                                     // 0x140898000
    virtual ~CUgcGetCostTable();                            // 0x140898070

    void SetTable(const CostMap& src);                      // 0x1408980d0 replaces the steps (under the lock)
    void GetTable(CostMap& dst);                                // 0x1408981a0
    void Write(COutputStream& stream);                      // 0x140898280
    void Read(CInPacket& packet);                           // 0x140898390
    bool FUN_1408984b0(__int64 nStart, __int64 nLength, CostList& out);     // the cost parts of a time span, newest first

    CLockCriticalSection m_lock;                                 // +0x08
    CostMap m_table;                                        // +0x38
};
MS2_CHECK_SIZE(CUgcGetCostTable, 0x68);
