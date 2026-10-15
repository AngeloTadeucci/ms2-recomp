// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Quest manager object.
// MS2-UNIT: client\ms2\questmanager.cpp#2
// MS2-RANGE: 0x1416c7fd0-0x1416e3800 .text$mn
// MS2-RANGE: 0x1400fe8a0-0x1400feaa0 .text$di
// MS2-RANGE: 0x142cb5990-0x142cb5aa0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\questmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "questmanager_2.h"
#include "questmanager_1.h"
#include "pcbase.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// These instances belong to earlier objects, not the look-alike destructors
// for other quest pointer types in this object's COMDAT tail.
template<> Unk_PayloadPtr<CQuest>::~Unk_PayloadPtr();
template<> bool Unk_PayloadPtr<CQuest>::IsNull() const;
template<> ATL::CAtlArray<unsigned>::CAtlArray() throw();
template<> ATL::CAtlArray<unsigned>::~CAtlArray() throw();
template<> size_t ATL::CAtlArray<unsigned>::GetCount() const throw();


static UICommon::CMyPCKeyInputController s_keyController;
static CString s_completeSound = "quest_complete";
static CString s_progressSound = "quest_progress";

// External services use declarations until their classes are recovered.
void* FUN_1406c7600();
void FUN_140936640(void*, int, int);
void* FUN_140967100();
void FUN_141b217e0(void*, int);
void* FUN_140d738f0();
int FUN_14037c510(void*, int);
int FUN_14037c610(void*);
int FUN_140408410(const ATL::CAtlArray<unsigned>*, const int&);
void* FUN_1408e57f0();
int FUN_1422b9e00(void*);
void* FUN_1403ed2d0();
void* FUN_141bd0cc0(void*);
int FUN_141654700(PCBase*);
int FUN_141654730(PCBase*);
__int64 FUN_141658eb0(PCBase*);
int FUN_141662de0(PCBase*);
int FUN_140931210(int);
void* FUN_140764010();
int FUN_14035a870(void*, int, int);
unsigned FUN_141662750(PCBase*, int);
void* FUN_1409670c0();
int FUN_14066af60(void*, int, unsigned);
class Unk_QuestDungeonRecord {
public:
    int FUN_140b22890(int);
    bool FUN_140b223d0(int);
};
template<> Unk_PayloadPtr<Unk_QuestDungeonRecord>::~Unk_PayloadPtr();
class Unk_QuestNotifyState {
public:
    Unk_PayloadPtr<Unk_QuestDungeonRecord> FUN_140d9f2c0();
};
Unk_QuestNotifyState* FUN_140931510();
int FUN_140d9f880(void*, int);
void* FUN_140c70240();
int FUN_140b71580(void*);
class CGuildManager;
CGuildManager* FUN_1403ed290();
int FUN_1413b6160(CGuildManager*);
extern __int64 DAT_143ab2828;
class CMsgBoxData;
unsigned FUN_141a02e90(const CMsgBoxData*, int, unsigned);
int FUN_141a02e50(const CMsgBoxData*, int, int);

class Unk_QuestNotices {
public:
    void FUN_140da4e40(CStringW, Delegate<void(NotifyObject*)>);
    void FUN_140da4eb0(CStringW, Delegate<void(NotifyObject*)>);
};
Unk_QuestNotices* FUN_140939a10();
class Unk_QuestPacketHandlers {
public:
    void FUN_140da5180(int, Delegate<void(CInPacket&)>);
    void FUN_140da51e0(int, Delegate<void(CInPacket&)>);
};
Unk_QuestPacketHandlers* FUN_140bccd50();
class Unk_QuestUIListeners {
public:
    void FUN_1419cae20(UIItemEventListener*);
    void FUN_1419caeb0(UIItemEventListener*);
};
Unk_QuestUIListeners* FUN_140a6a840();

// @0x1416c9810
void CQuestManager::vfunc_o10_0(int id, int state)
{
    FUN_140936640(FUN_1406c7600(), id, state);
}
MS2_REPLACE_METHOD_VIA(0x1416c9810, CQuestManager, CQuestManagerCommon, vfunc_o10_0, 45, 0x8953D5C2);

// @0x1416c9850
int CQuestManager::vfunc_o10_2(int id)
{
    return FUN_140408410(&m_pinnedQuests, id) != -1;
}
MS2_REPLACE_METHOD_VIA(0x1416c9850, CQuestManager, CQuestManagerCommon, vfunc_o10_2, 69, 0x2B0D9F09);

// @0x1416c98a0
int CQuestManager::vfunc_o10_4()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return player->vfunc_78();
}
MS2_REPLACE_METHOD_VIA(0x1416c98a0, CQuestManager, CQuestManagerCommon, vfunc_o10_4, 63, 0x739B8DCC);

// @0x1416c99a0
int CQuestManager::vfunc_o10_6()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141654700(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c99a0, CQuestManager, CQuestManagerCommon, vfunc_o10_6, 54, 0x5D718A31);

// @0x1416c99e0
int CQuestManager::vfunc_o10_7()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141654730(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c99e0, CQuestManager, CQuestManagerCommon, vfunc_o10_7, 54, 0x0C542E91);

// @0x1416c9a20
int CQuestManager::vfunc_o10_9()
{
    return FUN_1413b6160(FUN_1403ed290());
}
MS2_REPLACE_METHOD_VIA(0x1416c9a20, CQuestManager, CQuestManagerCommon, vfunc_o10_9, 27, 0x11B98314);

// @0x1416c9b90
__int64 CQuestManager::vfunc_o10_8()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141658eb0(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c9b90, CQuestManager, CQuestManagerCommon, vfunc_o10_8, 54, 0x0EE23A1E);

// @0x1416c9bd0
int CQuestManager::vfunc_o10_13(int id)
{
    int value = FUN_140931210(id);
    return FUN_14035a870(FUN_140764010(), id, value);
}
MS2_REPLACE_METHOD_VIA(0x1416c9bd0, CQuestManager, CQuestManagerCommon, vfunc_o10_13, 53, 0xB7DAED80);

// @0x1416c9c10
int CQuestManager::vfunc_o10_14(int id)
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_14066af60(FUN_1409670c0(), id, FUN_141662750(player, id));
}
MS2_REPLACE_METHOD_VIA(0x1416c9c10, CQuestManager, CQuestManagerCommon, vfunc_o10_14, 90, 0x7C542213);

// @0x1416c9c70
int CQuestManager::vfunc_o10_15(int id)
{
    return FUN_140931510()->FUN_140d9f2c0()->FUN_140b22890(id);
}
MS2_REPLACE_METHOD_VIA(0x1416c9c70, CQuestManager, CQuestManagerCommon, vfunc_o10_15, 100, 0xC93D21FB);

// @0x1416c9ce0
int CQuestManager::vfunc_o10_16(int id)
{
    return FUN_140d9f880(FUN_140931510(), id);
}
MS2_REPLACE_METHOD_VIA(0x1416c9ce0, CQuestManager, CQuestManagerCommon, vfunc_o10_16, 35, 0xF17E0AF2);

// @0x1416c9d10
int CQuestManager::vfunc_o10_17(int id)
{
    return FUN_140931510()->FUN_140d9f2c0()->FUN_140b223d0(id) != 0;
}
MS2_REPLACE_METHOD_VIA(0x1416c9d10, CQuestManager, CQuestManagerCommon, vfunc_o10_17, 129, 0xBEDFE2F6);

// @0x1416c9da0
int CQuestManager::vfunc_o10_18()
{
    return FUN_140b71580(FUN_140c70240());
}
MS2_REPLACE_METHOD_VIA(0x1416c9da0, CQuestManager, CQuestManagerCommon, vfunc_o10_18, 27, 0x8D6AF085);

// @0x1416c9dd0
int CQuestManager::vfunc_o10_19()
{
    PCBase* player = static_cast<PCBase*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (player == 0) return 0;
    return FUN_141662de0(player);
}
MS2_REPLACE_METHOD_VIA(0x1416c9dd0, CQuestManager, CQuestManagerCommon, vfunc_o10_19, 54, 0xA0BC4C64);

// @0x1416ca1c0
Unk_PayloadPtr<CQuest> CQuestManager::vfunc_o10_3(int id)
{
    Unk_PayloadPtr<CQuest> quest(0);
    m_quests140.Lookup(id, quest);
    return quest;
}
MS2_REPLACE_METHOD_VIA(0x1416ca1c0, CQuestManager, CQuestManagerCommon, vfunc_o10_3, 123, 0xADCEE0AD);

// @0x1416ca250
int CQuestManager::vfunc_o10_20(const ATL::CAtlArray<unsigned>& ids)
{
    return FUN_1416d3af0(ids) != 0;
}
MS2_REPLACE_METHOD_VIA(0x1416ca250, CQuestManager, CQuestManagerCommon, vfunc_o10_20, 67, 0x6059D7CE);

// @0x1416ca2a0
__int64 CQuestManager::vfunc_o10_22()
{
    return DAT_143ab2828;
}
MS2_REPLACE_METHOD_VIA(0x1416ca2a0, CQuestManager, CQuestManagerCommon, vfunc_o10_22, 13, 0xBA20E7DE);

// @0x1416ca2c0
unsigned CQuestManager::vfunc_o10_23(const Unk_QuestCondition& condition)
{
    return CQuestManagerCommon::vfunc_o10_23(condition);
}
MS2_REPLACE_METHOD_VIA(0x1416ca2c0, CQuestManager, CQuestManagerCommon, vfunc_o10_23, 37, 0xD2BCEFDD);

// @0x1416ca2f0
void CQuestManager::FUN_1416ca2f0()
{
    m_itemsDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca2f0, CQuestManager, FUN_1416ca2f0, 21, 0x923ABA4D);

// @0x1416ca310
void CQuestManager::vfunc_2(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca310, CQuestManager, UIItemEventListener, vfunc_2, 36, 0xFD0C761F);

// @0x1416ca340
void CQuestManager::vfunc_3(void*, bool)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca340, CQuestManager, UIItemEventListener, vfunc_3, 41, 0x5B133A72);

// @0x1416ca370
void CQuestManager::vfunc_4(void*, int)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca370, CQuestManager, UIItemEventListener, vfunc_4, 41, 0x89D45B7F);

// @0x1416ca3a0
void CQuestManager::vfunc_21(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca3a0, CQuestManager, UIItemEventListener, vfunc_21, 36, 0xAF7DFFEF);

// @0x1416ca3d0
void CQuestManager::vfunc_22(void*)
{
    FUN_1416ca2f0();
}
MS2_REPLACE_METHOD_VIA(0x1416ca3d0, CQuestManager, UIItemEventListener, vfunc_22, 36, 0xB5DE9CDF);

// @0x1416ca400
void CQuestManager::vfunc_33(int type, int)
{
    if (type == 0x6200004) {
        FUN_1416ca2f0();
    }
}
MS2_REPLACE_METHOD_VIA(0x1416ca400, CQuestManager, UIItemEventListener, vfunc_33, 50, 0x790979EE);

// @0x1416ca730
void CQuestManager::FUN_1416ca730(NotifyObject*)
{
    m_levelDirty = 1;
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca730, CQuestManager, FUN_1416ca730, 41, 0x3A2CD5A4);

// @0x1416ca760
void CQuestManager::FUN_1416ca760(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca760, CQuestManager, FUN_1416ca760, 26, 0x3D36B1A4);

// @0x1416ca780
void CQuestManager::FUN_1416ca780(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca780, CQuestManager, FUN_1416ca780, 26, 0x3D36B1A4);

// @0x1416ca7a0
void CQuestManager::FUN_1416ca7a0(NotifyObject*)
{
    m_availableDirty = 1;
}
MS2_REPLACE_METHOD(0x1416ca7a0, CQuestManager, FUN_1416ca7a0, 26, 0x3D36B1A4);

// @0x1416ca830
void CQuestManager::FUN_1416ca830(CInPacket&)
{
    m_refreshCount = 0;
}
MS2_REPLACE_METHOD(0x1416ca830, CQuestManager, FUN_1416ca830, 26, 0x5A297EAB);

// @0x1416cae20
int CQuestManager::FUN_1416cae20(int id)
{
    Unk_PayloadPtr<CQuest> quest = vfunc_o10_3(id);
    if (quest.IsNull()) return 0;
    return quest->FUN_1407476d0();
}
MS2_REPLACE_METHOD(0x1416cae20, CQuestManager, FUN_1416cae20, 149, 0x7D595639);

// @0x1416caec0
void CQuestManager::FUN_1416caec0(Unk_PayloadPtr<CQuest> quest)
{
    if (quest.IsNull()) return;
    int type = quest->GetQuestType();
    switch (type) {
    case 4: m_quests80.SetAt(quest->FUN_140bfc580(), quest); break;
    case 3: m_quests50.SetAt(quest->FUN_140bfc580(), quest); break;
    case 5: m_questsb0.SetAt(quest->FUN_140bfc580(), quest); break;
    case 7: m_questse0.SetAt(quest->FUN_140bfc580(), quest); break;
    case 10: m_quests110.SetAt(quest->FUN_140bfc580(), quest); break;
    default: m_quests20.SetAt(quest->FUN_140bfc580(), quest); break;
    }
    m_quests140.SetAt(quest->FUN_140bfc580(), quest);
    FUN_1416d3d50(quest);
}
MS2_REPLACE_METHOD(0x1416caec0, CQuestManager, FUN_1416caec0, 511, 0x74E17A65);

// MS2-FUNCTIONAL: equivalent short-circuit filters; temporary lifetime differs.
// @0x1416cb260
void CQuestManager::FUN_1416cb260(ATL::CAtlArray<unsigned>& ids, int state, int type, int group)
{
    for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
        if (state != 4 && state != quest->FUN_1407476d0()) continue;
        if (type != 11 && type != quest->GetData()->m_type) continue;
        if (group != -1 && group != quest->GetData()->m_28) continue;
        ids.Add(quest->FUN_140bfc580());
    }
}
MS2_REPLACE_METHOD(0x1416cb260, CQuestManager, FUN_1416cb260, 618, 0x631E6AA7);

// @0x1416ce140
void CQuestManager::FUN_1416ce140(int questId, int)
{
    FUN_141b217e0(FUN_140967100(), questId);
}
MS2_REPLACE_METHOD(0x1416ce140, CQuestManager, FUN_1416ce140, 40, 0x655404CF);

// @0x1416ce340
int CQuestManager::FUN_1416ce340(int value)
{
    ATL::CAtlArray<unsigned> ids;
    FUN_1416cb260(ids, 4, 11, value);
    return ids.GetCount() != 0;
}
MS2_REPLACE_METHOD(0x1416ce340, CQuestManager, FUN_1416ce340, 128, 0xCDCFD910);

// @0x1416cfc10
int CQuestManager::FUN_1416cfc10(int id)
{
    return FUN_140408410(&m_pinnedQuests, id) != -1;
}
MS2_REPLACE_METHOD(0x1416cfc10, CQuestManager, FUN_1416cfc10, 69, 0x04E4AE45);

// @0x1416cfc60
void CQuestManager::FUN_1416cfc60(int)
{
}
MS2_REPLACE_METHOD(0x1416cfc60, CQuestManager, FUN_1416cfc60, 10, 0x96F6F902);

// @0x1416d00c0
int CQuestManager::FUN_1416d00c0()
{
    int count = FUN_14037c510(FUN_140d738f0(), m_group);
    return count;
}
MS2_REPLACE_METHOD(0x1416d00c0, CQuestManager, FUN_1416d00c0, 46, 0x43BD140E);

// @0x1416d0100
int CQuestManager::FUN_1416d0100()
{
    int required = FUN_1416d00c0();
    int completed = FUN_1416d0150();
    return completed >= required;
}
MS2_REPLACE_METHOD(0x1416d0100, CQuestManager, FUN_1416d0100, 74, 0x2A623423);

// @0x1416d0150
int CQuestManager::FUN_1416d0150()
{
    int count = 0;
    for (POSITION pos = m_quests80.GetHeadPosition(); pos != 0; m_quests80.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests80.GetValueAt(pos);
        if (quest->FUN_1407476d0() == 2) {
            count = count + 1;
        }
    }
    return count;
}
MS2_REPLACE_METHOD(0x1416d0150, CQuestManager, FUN_1416d0150, 176, 0xAC60CD7D);

// @0x1416d0210
int CQuestManager::FUN_1416d0210()
{
    return m_group == FUN_14037c610(FUN_140d738f0());
}
MS2_REPLACE_METHOD(0x1416d0210, CQuestManager, FUN_1416d0210, 62, 0xD8B73C66);

// @0x1416d0740
void CQuestManager::FUN_1416d0740()
{
    m_field180 = 1;
}
MS2_REPLACE_METHOD(0x1416d0740, CQuestManager, FUN_1416d0740, 21, 0xDA904E61);

// @0x1416d0760
int CQuestManager::FUN_1416d0760()
{
    return m_field180;
}
MS2_REPLACE_METHOD(0x1416d0760, CQuestManager, FUN_1416d0760, 17, 0xDC2CA4CA);

// @0x1416d0780
int CQuestManager::FUN_1416d0780(int id)
{
    int count;
    m_dailyCounts.Lookup(id, count);
    return count;
}
MS2_REPLACE_METHOD(0x1416d0780, CQuestManager, FUN_1416d0780, 50, 0xD13FF482);

// @0x1416d07c0
int CQuestManager::FUN_1416d07c0(int id)
{
    int count;
    m_weeklyCounts.Lookup(id, count);
    return count;
}
MS2_REPLACE_METHOD(0x1416d07c0, CQuestManager, FUN_1416d07c0, 50, 0x10DEA3FA);

// @0x1416d0e60
int CQuestManager::FUN_1416d0e60(int id)
{
    return FUN_1416d0800(id) != 0;
}
MS2_REPLACE_METHOD(0x1416d0e60, CQuestManager, FUN_1416d0e60, 58, 0xBEE746D6);

// @0x1416d0ea0
bool CQuestManager::FUN_1416d0ea0(int result, const CMsgBoxData& message)
{
    if (result != 0) return true;
    unsigned id = FUN_141a02e90(&message, 0, 0);
    int count = FUN_141a02e50(&message, 1, 0);
    COutPacket packet(0x29, 0);
    packet.vfunc_o10_1(0x14);
    packet.vfunc_o10_3(id);
    packet.vfunc_o10_2(static_cast<short>(count));
    FUN_140710590(packet);
    return true;
}
MS2_REPLACE_METHOD(0x1416d0ea0, CQuestManager, FUN_1416d0ea0, 186, 0x7E1A7D4B);

// @0x1416d1060
void CQuestManager::FUN_1416d1060(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>& out)
{
    for (POSITION pos = m_quests110.GetHeadPosition(); pos != 0; m_quests110.GetNext(pos)) {
        Unk_PayloadPtr<CQuest> quest = m_quests110.GetValueAt(pos);
        out.Add(quest);
    }
}
MS2_REPLACE_METHOD(0x1416d1060, CQuestManager, FUN_1416d1060, 152, 0xCE32F7F4);

// @0x1416d3220
void CQuestManager::FUN_1416d3220()
{
    if (FUN_1416d3430() != 0) return;
    FUN_1416d3510();
}
MS2_REPLACE_METHOD(0x1416d3220, CQuestManager, FUN_1416d3220, 40, 0xAE052B5E);

// @0x1416d3430
int CQuestManager::FUN_1416d3430()
{
    if (FUN_1422b9e00(FUN_1408e57f0()) != 0x620001d) return 0;
    {
        for (POSITION pos = m_quests20.GetHeadPosition(); pos != 0; m_quests20.GetNext(pos)) {
            Unk_PayloadPtr<CQuest> quest = m_quests20.GetValueAt(pos);
            CQuest* current = quest.operator->();
            if (current->FUN_140d73970() != 0) {
                return 1;
            }
            }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1416d3430, CQuestManager, FUN_1416d3430, 216, 0x2CD58E85);

// @0x1416dbb50
CQuestManagerCommon::CQuestManagerCommon() : m_selector(0) {}

MS2_EMIT_CRT_MEMMOVE_S();
