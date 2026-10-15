// Heap-only declaration from RTTI, ctor1406a2580 and factory141215500 allocation.
// Container members are not accessed here; their layouts await the owning unit.
#pragma once
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
class CMeratMarketPremium : public TSingleton<CMeratMarketPremium>,public CCacheData {
public:
    CMeratMarketPremium();
    virtual ~CMeratMarketPremium();
private:
    void* unknown30[32];
};
MS2_CHECK_SIZE(CMeratMarketPremium,0x130);
