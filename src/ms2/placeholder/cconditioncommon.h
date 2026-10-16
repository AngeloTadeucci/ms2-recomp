// cconditioncommon.h - PLACEHOLDER for CConditionCommon (RTTI .?AVCConditionCommon@@, 0x28 bytes, base CPtred,
// vftable 0x142d192a8, 8 slots) and CConditionCommonData (RTTI, 0x130 bytes, base CPtred, vftable 0x142d19288).
// NOT an original header. Owner of the code: commonfiles\conditionutil.cpp (ctor 0x14029efb0, dtor 0x14029f000,
// slots 0x14029f040..0x14029f1f0; CConditionCommonData ctor 0x14029e840, dtor 0x14029e8e0).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <bitset>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/fieldmetatable.h"
#include "ms2/placeholder/cptred.h"

// The key/value dictionary a condition parameter may carry ("dict:" parameters): shared through the boxed smart pointer.
typedef ATL::CAtlMap<CString, CString, ATL::CStringElementTraitsI<CString> > CConditionDict;
typedef Unk_FieldPtr<CConditionDict> CConditionDictPtr;

// One parameter of a condition ("code" or "target" attribute). RTTI .?AVCConditionParam@@ (0x80 bytes, vftable with the
// deleting dtor only). The text is parsed into one of four shapes, selected by a bit of m_flags: 0 = list of "a-b"
// ranges, 1 = list of ids ("a,b,c"), 2 = one "a:b" pair (m_nMin/m_nMax), 3 = "dict:" dictionary. Member names are invented.
class CConditionParam : public CPtred
{
public:
    CConditionParam();                                  // 0x14029dff0
    virtual ~CConditionParam();                         // 0x14029e0a0

    bool IsTextDifferent(const CConditionParam& other) const;   // 0x14029e120
    int Parse(CString strText);                         // 0x14029e160: 1 = parsed
    int Matches(__int64 nValue);                       // 0x14029e600
    int IsSet();                                       // 0x14029e6f0: any shape selected
    size_t GetIdCount();                                // 0x14029e720
    __int64 GetFirstValue();                            // 0x14029e770
    CString* GetText();                                 // 0x14029e820

    std::bitset<4> m_flags;                             // +0x18
    int m_nMin;                                         // +0x1c
    int m_nMax;                                         // +0x20
    CString m_strText;                                  // +0x28
    ATL::CAtlArray<__int64> m_ids;                      // +0x30
    ATL::CAtlArray<Unk_FieldTimeSpan> m_ranges;         // +0x50
    CConditionDictPtr m_dict;                           // +0x70
};
MS2_CHECK_SIZE(CConditionParam, 0x80);
MS2_CHECK_OFFSET(CConditionParam, m_strText, 0x28);
MS2_CHECK_OFFSET(CConditionParam, m_ids, 0x30);
MS2_CHECK_OFFSET(CConditionParam, m_ranges, 0x50);
MS2_CHECK_OFFSET(CConditionParam, m_dict, 0x70);

class Unk_ConditionXml;     // the xml element reader of conditionutil.cpp (opaque here)

// The condition data of an achievement / quest condition (RTTI, 0x130 bytes, base CPtred, vftable 0x142d19288).
class CConditionCommonData : public CPtred
{
public:
    CConditionCommonData();             // 0x14029e840
    virtual ~CConditionCommonData();    // 0x14029e8e0

    bool IsDifferent(CConditionCommonData* pOther);                         // 0x14029e940
    int Load(Unk_ConditionXml* pNode, CStringW strTag, unsigned nId);           // 0x14029ea20
    int Validate(CStringW* pError);                                         // 0x14029edc0

    int m_nType;                        // +0x18 (0 = no condition)
    int m_pad_1c;
    __int64 m_nGoal;                    // +0x20 count needed to complete
    CConditionParam m_code;             // +0x28
    CConditionParam m_target;           // +0xa8
    int m_nPartyCount;                  // +0x128
    int m_nGuildPartyCount;             // +0x12c
};
MS2_CHECK_SIZE(CConditionCommonData, 0x130);
MS2_CHECK_OFFSET(CConditionCommonData, m_nGoal, 0x20);
MS2_CHECK_OFFSET(CConditionCommonData, m_code, 0x28);
MS2_CHECK_OFFSET(CConditionCommonData, m_target, 0xa8);
MS2_CHECK_OFFSET(CConditionCommonData, m_nPartyCount, 0x128);

class CConditionCommon : public CPtred
{
public:
    // A named condition type of the table (RTTI .?AVCConditionDef@CConditionCommon@@, 0x30 bytes).
    class CConditionDef : public CPtred
    {
    public:
        CConditionDef();                // 0x1402a5630
        virtual ~CConditionDef() = default;     // 0x1402a5950 (no vptr store)

        int m_nId;                      // +0x18 condition type id
        int m_nKind;                    // +0x1c group of the type
        CString m_strName;              // +0x20 xml name
        int m_nTarget;                  // +0x28 1 when the type has a "target" parameter
    };

    CConditionCommon();                 // 0x14029efb0
    virtual ~CConditionCommon();        // slot 0, dtor 0x14029f000
    virtual int vfunc_1();              // 0x14029f040: m_pData ? m_pData->m_nType : 0
    virtual __int64 vfunc_2();          // 0x14029f070: m_nCount
    virtual int vfunc_3(CConditionCommonData* pData);   // 0x14029f090: binds the data (0 if none / type 0)
    virtual int vfunc_4();             // 0x14029f0d0: m_pData->m_nGoal <= m_nCount
    virtual int vfunc_5(__int64 nValue);    // 0x14029f110: the "code" parameter accepts the value
    virtual int vfunc_6(__int64 nValue);    // 0x14029f180: the "target" parameter accepts the value
    virtual int vfunc_7(__int64 nValue);              // 0x14029f1f0: returns 1

    __int64 m_nCount;                   // +0x18
    CConditionCommonData* m_pData;      // +0x20
};
MS2_CHECK_SIZE(CConditionCommon::CConditionDef, 0x30);
MS2_CHECK_SIZE(CConditionCommon, 0x28);
MS2_CHECK_OFFSET(CConditionCommon, m_nCount, 0x18);
