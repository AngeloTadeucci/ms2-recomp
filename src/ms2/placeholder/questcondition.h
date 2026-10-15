// Condition contexts and checker: RTTI names, layout from conditionutil.cpp and
// the CQuest local constructions at 0x1416c67e0. Context names are structs in RTTI.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/cconditioncommon.h"

struct ConditionContext
{
    ConditionContext();
    virtual int FUN_1402a90e0() = 0;
};
struct ConditionUserFindContext : public ConditionContext
{
    ConditionUserFindContext();
    ~ConditionUserFindContext();
    int FUN_1402a90e0() override;
    void* m_user;
    unsigned short m_level;
    int m_targetKind, m_myKind, m_job, m_gender, m_24;
    ATL::CAtlArray<unsigned> m_skills;
};
MS2_CHECK_SIZE(ConditionContext, 8);
MS2_CHECK_SIZE(ConditionUserFindContext, 0x48);
MS2_CHECK_OFFSET(ConditionUserFindContext, m_level, 0x10);
MS2_CHECK_OFFSET(ConditionUserFindContext, m_skills, 0x28);

class CQuestConditionChecker : public CPtred
{
public:
    CQuestConditionChecker();
    virtual ~CQuestConditionChecker();
    virtual bool Check(CConditionCommonData*, ConditionContext*) = 0;
};
class CQuestConditionCheckerUserFind : public CQuestConditionChecker
{
public:
    CQuestConditionCheckerUserFind();
    virtual ~CQuestConditionCheckerUserFind();
    bool Check(CConditionCommonData*, ConditionContext*) override;
private:
    // The 0x48-byte delegate map is constructed by conditionutil, never here.
    void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
    void* m_40; void* m_48; void* m_50; void* m_58;
};
MS2_CHECK_SIZE(CQuestConditionChecker, 0x18);
MS2_CHECK_SIZE(CQuestConditionCheckerUserFind, 0x60);
