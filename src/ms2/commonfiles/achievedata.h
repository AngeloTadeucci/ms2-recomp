// achievedata.h - CAchieveData / CAchieveGradeData (RTTI names; achievement table rows). Header name assumed. The
// code is the second obj of the old `?\achievecondition.cpp` range (0x14015b490-0x14016da90, here ?\achievedata.cpp).
// Member names are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// The reward block of a grade (0x60 bytes, ctor 0x140164110; m_nType 0 = no reward).
struct Unk_AchieveReward
{
    Unk_AchieveReward();                // 0x140164110
    int m_nType;                        // +0x00
    int m_pad_04;
    void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38;
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
};
MS2_CHECK_SIZE(Unk_AchieveReward, 0x60);

// One grade (step) of an achievement. RTTI .?AVCAchieveGradeData@@, 0x90 bytes, vftable 0x142ce68a0.
class CAchieveGradeData : public CPtred
{
public:
    CAchieveGradeData();                // 0x14015b490
    virtual ~CAchieveGradeData();       // 0x14015b540

    int m_nGrade;                       // +0x18
    int m_pad_1c;
    Unk_AchieveReward m_reward;         // +0x20
    MS2Ptr<CConditionCommonData> m_pCondition;  // +0x80
};
MS2_CHECK_SIZE(CAchieveGradeData, 0x90);
MS2_CHECK_OFFSET(CAchieveGradeData, m_reward, 0x20);
MS2_CHECK_OFFSET(CAchieveGradeData, m_pCondition, 0x80);


// One achievement. RTTI .?AVCAchieveData@@, 0xf8 bytes; bases CObjectCount<CAchieveData> (empty, +0x30),
// CCacheData (+0), CValidData<CAchieveData> (+0x28).
class CAchieveData : public CObjectCount<CAchieveData>, public CCacheData, public CValidData<CAchieveData>
{
public:
    CAchieveData();                     // 0x14015b640
    virtual ~CAchieveData();            // 0x14015b7d0

    MS2Ptr<CAchieveGradeData> GetGrade(int nGrade);     // 0x14015bc40
    CString GetName();                  // 0x14015bcd0

    int m_30;                           // +0x30
    int m_34;
    int m_nType;                        // +0x38
    int m_nMaxGrade;                    // +0x3c
    int m_nFirstGrade;                  // +0x40 (ctor: 0x7fffffff)
    int m_pad_44;
    CString m_strName;                  // +0x48
    int m_50;
    int m_pad_54;
    CStringW m_strW_58;                 // +0x58
    CString m_str_60;                   // +0x60
    int m_68;                           // +0x68
    int m_6c;
    int m_nCategory;                    // +0x70
    int m_pad_74;
    CString m_str_78;                   // +0x78
    CString m_str_80;                   // +0x80
    int m_nRequireType;                 // +0x88 (1: event name, 2: event id)
    int m_pad_8c;
    ATL::CAtlArray<CStringW> m_aRequire;                        // +0x90
    ATL::CAtlMap<int, MS2Ptr<CAchieveGradeData> > m_mapGrade;   // +0xb0
};
MS2_CHECK_SIZE(CAchieveData, 0xf8);
MS2_CHECK_OFFSET(CAchieveData, m_nFirstGrade, 0x40);
MS2_CHECK_OFFSET(CAchieveData, m_strName, 0x48);
MS2_CHECK_OFFSET(CAchieveData, m_nRequireType, 0x88);
MS2_CHECK_OFFSET(CAchieveData, m_aRequire, 0x90);

// Looks the achievement up in the table cache (0x14015d9e0; non-member or static, name invented).
MS2Ptr<CAchieveData> GetAchieveData(int nId);
