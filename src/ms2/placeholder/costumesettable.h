// costumesettable.h - CostumeSetTable (RTTI .?AVCostumeSetTable@@, 0xe0 bytes): Table/CostumeSet.xml, the costume sets
// by set id and gender. NOT an original header (member names are invented).
// Bases: TSingleton<CostumeSetTable> at +0x0, CValidData<CostumeSetTable> at +0x8. CGameApp::InitInstance (?\ms2.cpp)
// creates it. Code owner: unit_140535bc0.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/costumeset.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ms2svrptr.h"

typedef MS2SvrPtr<CostumeSet> CostumeSetPtr;

class CostumeSetTable : public TSingleton<CostumeSetTable>, public CValidData<CostumeSetTable>
{
public:
    CostumeSetTable();                                      // 0x140535cd0
    virtual ~CostumeSetTable();                             // 0x140535f80

    int Load();                                             // 0x140536030 locks, then LoadXml
    CostumeSetPtr GetSet(unsigned nSetId, int nGender);     // 0x1405360b0 reloads first when the file changed
    int LoadXml();                                          // 0x1405361e0 Table/CostumeSet.xml
    static void CheckInit();                                // 0x1405371d0
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x140538f30
    static bool s_bInit;                                    // DAT_143aaf320

    CLockCriticalSection m_lock;                            // +0x10
    MS2Ptr<CCacheData> m_cache;                             // +0x40
    ATL::CAtlMap<unsigned, CostumeSetPtr> m_sets[2];        // +0x50 by gender (0, 1)
};
MS2_CHECK_SIZE(CostumeSetTable, 0xe0);
MS2_CHECK_OFFSET(CostumeSetTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CostumeSetTable, m_cache, 0x40);
MS2_CHECK_OFFSET(CostumeSetTable, m_sets, 0x50);
