// effectdummy.h - CEffectDummy / EffectDummyGroup (RTTI names): one <dummy> row and the <group> that owns them,
// read from Table/defaultEffectDummy.xml. Header name assumed. Only the shape needed by commoneffectdummy.cpp is
// declared here (sizes from operator_new in the exe: CEffectDummy 0x50, EffectDummyGroup 0x30); the rest belongs to
// effectdummy.cpp (unit ?\effectdummy.cpp, not recovered yet). Member names are invented from use.
#pragma once
#include "ms2/ms2layout.h"
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"

class CEffectDummy : public CPtred
{
public:
    CEffectDummy();                         // 0x140a50de0 area (unit ?\effectdummy.cpp)

    char m_unk_18[0x38];                    // +0x18 .. 0x50 (unrecovered)
};
MS2_CHECK_SIZE(CEffectDummy, 0x50);

class TiXmlNode;

class EffectDummyGroup : public CPtred
{
public:
    EffectDummyGroup();

    void FUN_140a514e0(TiXmlNode* pNode);   // builds the dummy list from the <dummy> children
    void FUN_140a515c0();                   // (list size, used as a count)
    MS2SvrPtr<CEffectDummy> FUN_140a515f0(const CString& name);   // lookup by name
    bool FUN_140a516e0(unsigned int idx, void* pOut);

    char m_unk_18[0x18];                    // +0x18 the dummy list (unrecovered)
};
MS2_CHECK_SIZE(EffectDummyGroup, 0x30);
