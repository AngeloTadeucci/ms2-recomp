// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The story quest kinds' overrides and CStringTable (the
// string.xml tables, the lookups every UI uses), plus the ATL glue of its caches.
// MS2-UNIT: client\ms2\stringtable.cpp
// MS2-RANGE: 0x14180f030-0x14181cf50 .text$mn
// MS2-RANGE: 0x14010cf80-0x14010d120 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\stringtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/questkinds.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/chapterbooktable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static UICommon::CMyPCKeyInputController s_keyController;

// ---- the quest kinds ----------------------------------------------------------------------------------------------

// Services of the exe, bound by their FUN_<va> names.
CStringTable* FUN_1401a9d70();
bool FUN_14064d4e0(const MS2Ptr<CQuestData>&);
void* FUN_140166410();
bool FUN_14036d570(void*, int);
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
int FUN_14074b030(CQuestData*);
int FUN_14074b840(int);
int FUN_14074b950(int);
int FUN_1418fd280();
CStringW FUN_1416e4df0(int);
CStringW FUN_1416e7fb0(int);
CStringW FUN_1405c2690(CStringW, const CStringW&);
CStringW FUN_1401e8510(const wchar_t*, const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
CStringW FUN_14028b8e0(const CStringW&);
CQuestManager* FUN_140764020();
UIRewardNotify* FUN_140938cd0(int);
UIFameContentsNotify* FUN_140e77d80(int);
CChapterBookTable* FUN_140e0a9f0();
WorldService* FUN_1403ed2d0();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);

class Unk_StTextFilter { public: void FUN_1416fb340(CStringW& strText); };
Unk_StTextFilter* FUN_1403b4750();

class Unk_QmTalkScript;
class Unk_QmTalkScriptPtr {
public:
    Unk_QmTalkScriptPtr(const Unk_QmTalkScriptPtr& o);  // 0x140859bc0
    ~Unk_QmTalkScriptPtr();                             // 0x14078f140
    bool IsNull() const;                                // 0x14085a420
    Unk_QmTalkScript* FUN_14078f3a0() const;            // get
private:
    void* m_0;
    Unk_QmTalkScript* m_p;
};
Unk_QmTalkScriptPtr FUN_1408564b0(int questId, int n);
class Unk_StTalkManager { public: int FUN_141b213f0(Unk_QmTalkScriptPtr script, int npcId, int mode, int n); };
Unk_StTalkManager* FUN_140967100();

class Unk_StRewardOtherDialog : public UIDialog { public: void FUN_1419f6a70(int nType, CStringW strText, int nTime); };
Unk_StRewardOtherDialog* FUN_140e01890(int nUiId);

// The UI manager and the dialog getter (GetDialog<T> instantiations of this unit).
class Unk_StUiManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_StUiManager* FUN_1403ed2b0();

class UIChapterBook : public UIDialog
{
public:
    void FUN_140e0a850(int nChapter);
    void FUN_140e0a890(int nChapter);
};
class UIAllianceQuestDialog : public UIDialog
{
public:
    int FUN_140bf94e0(int nQuestId);
    int FUN_140bf9530(int nQuestId);
};

// @0x141810510
UIAllianceQuestDialog* FUN_141810510(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIAllianceQuestDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x1418105b0
UIChapterBook* FUN_1418105b0(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<UIChapterBook*>((UIObject*)p);
    }
    return 0;
}

// @0x14180f030
CStoryQuest::CStoryQuest()
{
    m_78 = 1;
    m_7c = 0;
}

// @0x14180f090
CStoryQuest::~CStoryQuest()
{
}

// @0x14180f0d0
void CStoryQuest::DecodeStart(CInPacket& packet)
{
    if (FUN_14036d570(FUN_140166410(), 100))
    {
        int nChapter = FUN_140e0a9f0()->FindIdByPrologue(FUN_140bfc580());
        if (nChapter != 0)
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify)
                pNotify->FUN_141abf1f0();
            UIChapterBook* pBook = FUN_1418105b0(0x4f37);
            if (pBook)
                pBook->FUN_140e0a850(nChapter);
        }
    }
    if (FUN_14074b840(FUN_140bfc580()) != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031)
        {
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_quest_redirect_accept"), FUN_1416e4df0(FUN_140bfc580()));
            FUN_1412751f0(strMsg, 3, 0);
        }
    }
    if (m_data->m_2f0.m_0 == 3)
        m_7c = 3;
    CQuest::DecodeStart(packet);
}

// @0x14180f290
void CStoryQuest::DecodeProgress(CInPacket& packet)
{
    CQuest::DecodeProgress(packet);
}

// @0x14180f2c0
void CStoryQuest::Complete(CInPacket& packet)
{
    if (m_data->m_2d0.m_id != -1)
    {
        Unk_StRewardOtherDialog* pDlg = FUN_140e01890(0x4e4c);
        if (pDlg)
        {
            CStringW strText = FUN_1405c2690(CStringW(L"s_quest_complete_ui_effect"), FUN_1416e7fb0(m_data->m_28));
            pDlg->FUN_1419f6a70(m_data->m_2d0.m_id, strText, 3000);
        }
    }
    if (FUN_14036d570(FUN_140166410(), 100))
    {
        int nChapter = FUN_140764020()->FUN_1416d0f60(FUN_140bfc580());
        if (nChapter != 0)
        {
            UIRewardNotify* pNotify = FUN_140938cd0(0x4e5d);
            if (pNotify)
                pNotify->FUN_141abf1f0();
            UIChapterBook* pBook = FUN_1418105b0(0x4f37);
            if (pBook)
                pBook->FUN_140e0a890(nChapter);
        }
    }
    if (FUN_14074b950(FUN_140bfc580()) != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x6200031)
        {
            CStringW strMsg = FUN_1405c2690(CStringW(L"s_quest_redirect_complete"), FUN_1416e4df0(FUN_140bfc580()));
            FUN_1412751f0(strMsg, 3, 0);
        }
    }
    if (m_data->m_2f0.m_0 == 4)
        m_7c = 4;
    CQuest::Complete(packet);
}

// The dispatch confirmation the story quest raises when it is accepted from another channel.
// MS2-FUNCTIONAL: the exe allocates the dispatch box argument strings in a different frame order (EH state map differs).
// @0x14180f5c0
void CStoryQuest::FUN_140d73960()
{
    CQuest::FUN_140d73960();
    if (m_7c != 0)
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d)
        {
            CStringW strWho = FUN_1401a9d70()->FUN_141811980(0x47, m_data->m_2f0.m_c);
            CStringW strText = FUN_1401e8510((const wchar_t*)strWho, FUN_1401a9d70()->FUN_141811980(3, m_data->m_2f0.m_4));
            FUN_1403b4750()->FUN_1416fb340(strText);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x28, CStringW(L""), 0, CStringW(strText));
            if (spBox.get() != 0)
            {
                spBox->FUN_140534050(FUN_14074b030(m_data.operator->()));
                spBox->FUN_140533ff0(m_7c);
                spBox->FUN_141a015d0(FUN_1403ed2d0()->FUN_141bd0d30());
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(FUN_140764020(), &CQuestManager::FUN_1416d0ea0));
                spBox->FUN_141a01690(FUN_14028b8e0(CStringW(L"s_quest_dispatch_yes")), FUN_14028b8e0(CStringW(L"s_quest_dispatch_no")), CStringW(L""));
                FUN_140d73c60(spBox);
            }
            m_7c = 0;
        }
    }
}

// @0x14180fa50
void CStoryQuest::FUN_140d73950()
{
    m_78 = 1;
}

// @0x14180fa70
int CStoryQuest::FUN_140d73970()
{
    if (m_78 == 0)
        return 0;
    if (FUN_140d738c0() == 0)
        return 0;
    Unk_QmTalkScriptPtr script = FUN_1408564b0(FUN_140bfc580(), 300);
    if (script.IsNull())
        return 0;
    m_78 = 0;
    FUN_140967100()->FUN_141b213f0(script, m_data->m_2ec, 4, 0);
    return 1;
}

// @0x14180fbb0
void CStoryQuest::FUN_140d738e0()
{
    m_78 = 1;
    FUN_140d73970();
}

// @0x14180fbe0
int CStoryQuest::FUN_140d738c0()
{
    if (FUN_14180fc80() == 0)
        return 0;
    if (m_data->m_32c.m_0 != 1)
        return 0;
    return 1;
}

// @0x14180fc30
int CStoryQuest::FUN_140d738d0()
{
    if (FUN_14180fc80() == 0)
        return 0;
    if (m_data->m_32c.m_0 != 2)
        return 0;
    return 1;
}

// @0x14180fc80
int CStoryQuest::FUN_14180fc80()
{
    if (FUN_14064d4e0(m_data))
        return 0;
    if (m_data->m_32c.m_0 == 0)
        return 0;
    if (FUN_1407476d0() != 1)
        return 0;
    if (IsComplete() == 0)
        return 0;
    int nMap = m_data->m_32c.m_4;
    if (nMap != 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd3060() != nMap)
            return 0;
        if (nMap == 62000000 && FUN_1418fd280() == 0)
            return 0;
    }
    if (m_data->m_32c.m_8 != 0)
    {
        if (FUN_140764020()->FUN_1416d0760() == 0)
            return 0;
    }
    return 1;
}

// @0x14180fda0
CEpicQuest::CEpicQuest() {}
// @0x14180fdf0
CEpicQuest::~CEpicQuest() {}
// @0x14180fe30
CWorldQuest::CWorldQuest() {}
// @0x14180fe80
CWorldQuest::~CWorldQuest() {}
// @0x14180fec0
CEventQuest::CEventQuest() {}
// @0x14180ff10
CEventQuest::~CEventQuest() {}
// @0x14180ff50
CGuildQuest::CGuildQuest() {}
// @0x14180ffa0
CGuildQuest::~CGuildQuest() {}
// @0x14180ffe0
CFieldQuest::CFieldQuest() {}
// @0x141810030
CFieldQuest::~CFieldQuest() {}

// @0x141810070
int CFieldQuest::GetTrackingState()
{
    return FUN_140744b90(FUN_1403ed2d0()->FUN_141bd3060());
}

// @0x1418100c0
unsigned char CFieldQuest::GetFlag()
{
    if (!CQuest::GetFlag())
        return 0;
    if (IsActive() == 0)
        return 0;
    if (IsComplete() != 0)
        return 0;
    return 1;
}

// @0x141810140
void CFieldQuest::Complete(CInPacket& packet)
{
    CStoryQuest::Complete(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac26a0(FUN_140bfc580());
}

// @0x1418101a0
int CFieldQuest::FUN_140d738d0()
{
    if (IsActive() == 0)
        return 0;
    if (IsComplete() == 0)
        return 0;
    return 1;
}

// @0x141810210
void CAllianceQuest::DecodeStart(CInPacket& packet)
{
    CStoryQuest::DecodeStart(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac25b0(FUN_140bfc580());
    UIAllianceQuestDialog* pDlg = FUN_141810510(0x4f50);
    if (pDlg)
    {
        if (pDlg->FUN_140bf94e0(FUN_140bfc580()) != 0 && m_7c == 3)
            m_7c = 0;
    }
}

// @0x1418102b0
void CAllianceQuest::Complete(CInPacket& packet)
{
    CStoryQuest::Complete(packet);
    UIFameContentsNotify* pNotify = FUN_140e77d80(0x4f5a);
    if (pNotify)
        pNotify->FUN_141ac26a0(FUN_140bfc580());
    UIAllianceQuestDialog* pDlg = FUN_141810510(0x4f50);
    if (pDlg)
    {
        if (pDlg->FUN_140bf9530(FUN_140bfc580()) != 0 && m_7c == 4)
            m_7c = 0;
    }
}

// @0x141810350
unsigned char CAllianceQuest::GetFlag()
{
    if (!CQuest::GetFlag())
        return 0;
    if (IsActive() == 0)
        return 0;
    if (IsComplete() != 0)
        return 0;
    return 1;
}

// @0x141810970
int CStoryQuest::GetQuestType() { return 0xb; }
// @0x141810930
int CEpicQuest::GetQuestType() { return 0; }
// @0x141810980
int CWorldQuest::GetQuestType() { return 1; }
// @0x141810940
int CEventQuest::GetQuestType() { return 2; }
// @0x141810960
int CGuildQuest::GetQuestType() { return 6; }
// @0x141810950
int CFieldQuest::GetQuestType() { return 8; }
