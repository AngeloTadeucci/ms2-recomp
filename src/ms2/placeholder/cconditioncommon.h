// cconditioncommon.h - PLACEHOLDER for CConditionCommon (RTTI .?AVCConditionCommon@@, 0x28 bytes, base CPtred,
// vftable 0x142d192a8, 8 slots) and CConditionCommonData (RTTI, 0x130 bytes, base CPtred, vftable 0x142d19288).
// NOT an original header. Owner of the code: commonfiles\conditionutil.cpp (ctor 0x14029efb0, dtor 0x14029f000,
// slots 0x14029f040..0x14029f1f0; CConditionCommonData ctor 0x14029e840, dtor 0x14029e8e0).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CConditionCommonData : public CPtred
{
public:
    CConditionCommonData();             // 0x14029e840
    virtual ~CConditionCommonData();    // 0x14029e8e0

    int m_nType;                        // +0x18 (0 = no condition)
    int m_pad_1c;
    __int64 m_nGoal;                    // +0x20 count needed to complete
    void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
    void* m_pad_60; void* m_pad_68; void* m_pad_70; void* m_pad_78; void* m_pad_80; void* m_pad_88; void* m_pad_90;
    void* m_pad_98; void* m_pad_a0; void* m_pad_a8; void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8;
    void* m_pad_d0; void* m_pad_d8; void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100;
    void* m_pad_108; void* m_pad_110; void* m_pad_118; void* m_pad_120; void* m_pad_128;
};
MS2_CHECK_SIZE(CConditionCommonData, 0x130);
MS2_CHECK_OFFSET(CConditionCommonData, m_nGoal, 0x20);

class CConditionCommon : public CPtred
{
public:
    CConditionCommon();                 // 0x14029efb0
    virtual ~CConditionCommon();        // slot 0, dtor 0x14029f000
    virtual int vfunc_1();              // 0x14029f040: m_pData ? m_pData->m_nType : 0
    virtual __int64 vfunc_2();          // 0x14029f070: m_nCount
    virtual int vfunc_3(CConditionCommonData* pData);   // 0x14029f090: binds the data (0 if none / type 0)
    virtual bool vfunc_4();             // 0x14029f0d0: m_pData->m_nGoal <= m_nCount
    virtual int vfunc_5(void* p);       // 0x14029f110
    virtual int vfunc_6(void* p);       // 0x14029f180
    virtual int vfunc_7();              // 0x14029f1f0: returns 1

    __int64 m_nCount;                   // +0x18
    CConditionCommonData* m_pData;      // +0x20
};
MS2_CHECK_SIZE(CConditionCommon, 0x28);
MS2_CHECK_OFFSET(CConditionCommon, m_nCount, 0x18);
