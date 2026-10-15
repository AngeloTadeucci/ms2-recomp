// CQuestManager object (questmanager.cpp#2). Field names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/cquestmanagercommon.h"
class CInPacket;
class NotifyObject;
// Original counter constructor 0x140517b00; zeroes both 32-bit fields.
struct Unk_QuestCounter { Unk_QuestCounter(); int first, second; };
MS2_CHECK_SIZE(Unk_QuestCounter, 8);
// The +260 tree is constructed/destroyed here but no recovered method accesses
// its elements yet. Keep its representation explicit until its key/value types
// are established from the remaining COMDATs.
struct Unk_QuestTree260 {
    Unk_QuestTree260();
    ~Unk_QuestTree260();
    void* root;
    size_t count;
};
MS2_CHECK_SIZE(Unk_QuestTree260, 0x10);
class CQuestManager : public TSingleton<CQuestManager>, public UIItemEventListener,
                      public CQuestManagerCommon {
public:
    CQuestManager();
    virtual ~CQuestManager();
    virtual int vfunc_1(int, int);
    void vfunc_2(void*) override;
    void vfunc_3(void*, bool) override;
    void vfunc_4(void*, int) override;
    void vfunc_21(void*) override;
    void vfunc_22(void*) override;
    void vfunc_33(int, int) override;
    void vfunc_o10_0(int, int) override;
    int vfunc_o10_1(int) override;
    int vfunc_o10_2(int) override;
    Unk_PayloadPtr<CQuest> vfunc_o10_3(int) override;
    int vfunc_o10_4() override;
    int vfunc_o10_5() override;
    int vfunc_o10_6() override;
    int vfunc_o10_7() override;
    __int64 vfunc_o10_8() override;
    int vfunc_o10_9() override;
    int vfunc_o10_10() override;
    int vfunc_o10_11() override;
    __int64 vfunc_o10_12() override;
    int vfunc_o10_13(int) override;
    int vfunc_o10_14(int) override;
    int vfunc_o10_15(int) override;
    int vfunc_o10_16(int) override;
    int vfunc_o10_17(int) override;
    int vfunc_o10_18() override;
    int vfunc_o10_19() override;
    int vfunc_o10_20(const ATL::CAtlArray<unsigned>&) override;
    __int64 vfunc_o10_22() override;
    unsigned vfunc_o10_23(const Unk_QuestCondition&) override;

    void FUN_1416ca2f0();
    void FUN_1416ca730(NotifyObject*);
    void FUN_1416ca760(NotifyObject*);
    void FUN_1416ca780(NotifyObject*);
    void FUN_1416ca7a0(NotifyObject*);
    void FUN_1416ca7c0(NotifyObject*);
    void FUN_1416ca830(CInPacket&);
    void FUN_1416ca850(NotifyObject*);
    int FUN_1416cae20(int);
    void FUN_1416caec0(Unk_PayloadPtr<CQuest>);
    void FUN_1416cb260(ATL::CAtlArray<unsigned>&, int, int, int);
    void FUN_1416ce140(int, int);
    int FUN_1416ce340(int);
    int FUN_1416cfc10(int);
    void FUN_1416cfc60(int);
    int FUN_1416d00c0();
    int FUN_1416d0100();
    int FUN_1416d0150();
    int FUN_1416d0210();
    void FUN_1416d0740();
    int FUN_1416d0760();
    int FUN_1416d0780(int);
    int FUN_1416d07c0(int);
    int FUN_1416d0800(int);
    int FUN_1416d0e60(int);
    bool FUN_1416d0ea0(int, const class CMsgBoxData&);
    void FUN_1416d1060(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>&);
    void FUN_1416d3220();
    int FUN_1416d3430();
    int FUN_1416d3510();
    int FUN_1416d3af0(const ATL::CAtlArray<unsigned>&);
    void FUN_1416d3d50(Unk_PayloadPtr<CQuest>);

    using QuestMap = ATL::CRBMap<unsigned, Unk_PayloadPtr<CQuest>>;
    QuestMap m_quests20, m_quests50, m_quests80, m_questsb0;
    QuestMap m_questse0, m_quests110, m_quests140;
    int m_levelDirty;          // +170
    int m_availableDirty;      // +174
    int m_field178;
    int m_itemsDirty;          // +17c
    int m_field180;
    int m_group;               // +184
    int m_refreshCount;        // +188
    int m_targetObject;        // +18c
    int m_field190;
    unsigned m_requestTick;    // +194
    Unk_QuestCounter m_counter198;
    ATL::CAtlArray<unsigned> m_pinnedQuests; // +1a0
    ATL::CAtlMap<int, int> m_dailyCounts; // +1c0
    ATL::CAtlMap<int, int> m_weeklyCounts; // +208
    std::map<int, std::set<__int64>> m_targets250;
    Unk_QuestTree260 m_tree260;
};
MS2_CHECK_SIZE(CQuestManager, 0x270);
MS2_CHECK_OFFSET(CQuestManager, m_quests20, 0x20);
MS2_CHECK_OFFSET(CQuestManager, m_quests140, 0x140);
MS2_CHECK_OFFSET(CQuestManager, m_levelDirty, 0x170);
MS2_CHECK_OFFSET(CQuestManager, m_requestTick, 0x194);
MS2_CHECK_OFFSET(CQuestManager, m_pinnedQuests, 0x1a0);
MS2_CHECK_OFFSET(CQuestManager, m_dailyCounts, 0x1c0);
MS2_CHECK_OFFSET(CQuestManager, m_weeklyCounts, 0x208);
MS2_CHECK_OFFSET(CQuestManager, m_targets250, 0x250);
MS2_CHECK_OFFSET(CQuestManager, m_tree260, 0x260);
