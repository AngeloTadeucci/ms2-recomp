// ccachedata.h - PLACEHOLDER for CCacheData (RTTI .?AVCCacheData@@, 0x28 bytes, base CPtred, vftable 0x142ceee48,
// 1 slot). NOT an original header. Code owner: ?\cachedata.cpp (ctors 0x1401d1020 / 0x1401d1070 / 0x1401d2670,
// dtor 0x1401d1100, deleting dtor 0x1401d2d10).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CCacheData : public CPtred
{
public:
    CCacheData();                       // 0x1401d1020
    virtual ~CCacheData();              // 0x1401d1100

    void FUN_1401d1160(CString); // records the loaded cache path, by value

private:
    void* m_pad_18;                     // +0x18 unknown (not set by the default ctor)
    CString m_str_20;                   // +0x20
};
MS2_CHECK_SIZE(CCacheData, 0x28);
