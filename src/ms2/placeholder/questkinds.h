// CQuest subclasses created by CQuestManager's quest factory (0x1416ca9d0). Owner unit unrecovered
// (CEpicQuest ctor 0x14180fda0 ...); only the sizes (0x80 quests / 0x78 missions) and the constructors are proven.
#pragma once
#include "ms2/client/ms2/questmanager_1.h"

class CEpicQuest : public CQuest
{
public:
    CEpicQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CEpicQuest, 0x80);

class CWorldQuest : public CQuest
{
public:
    CWorldQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CWorldQuest, 0x80);

class CEventQuest : public CQuest
{
public:
    CEventQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CEventQuest, 0x80);

class CGuildQuest : public CQuest
{
public:
    CGuildQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CGuildQuest, 0x80);

class CFieldQuest : public CQuest
{
public:
    CFieldQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CFieldQuest, 0x80);

class CAllianceQuest : public CQuest
{
public:
    CAllianceQuest();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CAllianceQuest, 0x80);

class CDailyMission : public CQuest
{
public:
    CDailyMission();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CDailyMission, 0x78);

class CFieldMission : public CQuest
{
public:
    CFieldMission();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CFieldMission, 0x78);

class CEventMission : public CQuest
{
public:
    CEventMission();
    int GetQuestType() override;
    __int64 m_78;
};
MS2_CHECK_SIZE(CEventMission, 0x80);

class CMentoringMission : public CQuest
{
public:
    CMentoringMission();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CMentoringMission, 0x78);

class CWeddingMission : public CQuest
{
public:
    CWeddingMission();
    int GetQuestType() override;
};
MS2_CHECK_SIZE(CWeddingMission, 0x78);
