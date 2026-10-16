// Heap-only COptimizer layout: ctor14161b900 and allocation0xa8 in CreateInstance.
#pragma once
#include "ms2/commonfiles/os.h"
class COptimizer : public TSingleton<COptimizer> {
public:
    COptimizer();
    virtual ~COptimizer();
    int FUN_141215630() const;
    int IsModelCullingOn() { return ms_nModelCulling; }     // 0x1414c98a0 (COMDAT, also optimizer.cpp)
    static int ms_nModelCulling;                            // 0x143ae2b44 model node culling enabled
    void* unknown08; void* unknown10;
    void* unknown18; void* unknown20;
    unsigned __int64 field28;
    int field30,field34,preloadMode,field3c,field40,field44,field48;
    void* unknown50; void* unknown58;
    float field60;
    int field64,field68,field6c,field70,field74;
    unsigned __int64 field78;
    void* unknown80; void* unknown88; void* unknown90;
    unsigned __int64 field98;
    int fieldA0;
};
MS2_CHECK_SIZE(COptimizer,0xa8);
MS2_CHECK_OFFSET(COptimizer,preloadMode,0x38);
