// CQuest subclasses created by CQuestManager's quest factory (0x1416ca9d0). Owner unit unrecovered
// (CEpicQuest ctor 0x14180fda0 ...); only the sizes (0x80 quests / 0x78 missions) and the constructors are proven.
#pragma once
#include "ms2/client/ms2/questmanager_1.h"

// The common base of the story quests (ctor 0x14180f030 sets m_78 = 1, m_7c = 0; dtor 0x14180f090; both in the
// ?\stringtable.cpp range). CEpicQuest (ctor 0x14180fda0) and CAllianceQuest (ctor 0x1416dba50) call its ctor.
class CStoryQuest : public CQuest
{
public:
    CStoryQuest();
    virtual ~CStoryQuest();
    void FUN_140d73960() override;                      // 0x14180f5c0
    void FUN_140d73950() override;                      // 0x14180fa50
    int FUN_140d73970() override;                       // 0x14180fa70
    void FUN_140d738e0() override;                      // 0x14180fbb0
    int FUN_140d738c0() override;                       // 0x14180fbe0
    int FUN_140d738d0() override;                       // 0x14180fc30
    void DecodeProgress(CInPacket& packet) override;    // 0x14180f290
    int m_78, m_7c;
};
MS2_CHECK_SIZE(CStoryQuest, 0x80);

class CEpicQuest : public CStoryQuest
{
public:
    CEpicQuest();
    int GetQuestType() override;
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

// The inline members (ctor, GetQuestType, destructors) and the vftables are emitted by questmanager.cpp (the quest
// factory); the other overrides are out of line in the ?\stringtable.cpp range.
class CAllianceQuest : public CStoryQuest
{
public:
    CAllianceQuest();
    virtual ~CAllianceQuest() {}                        // 0x1416dc040 (resets the vfptrs: user-declared)
    unsigned char GetFlag() override;                   // 0x141810350
    int GetQuestType() override;
    void DecodeStart(CInPacket& packet) override;       // 0x141810210
    void Complete(CInPacket& packet) override;         // 0x1418102b0
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
