// gameeventvalue.cpp - the event values of CGameEventValueManager (see gameeventvalue.h): each a lock and the state
// the GameEvent* handlers write and the game reads.
//
// MS2-UNIT: commonfiles\gameeventvalue.cpp
// MS2-RANGE: 0x140422c10-0x140446320 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\gameeventvalue.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <afx.h>
#include <atlcoll.h>
#include <limits.h>
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/cxmldata.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

void FUN_140274fc0(const CStringW& text, ATL::CAtlArray<unsigned>& ids, const wchar_t* delims);  // split into ids
unsigned FUN_140197390(Unk_140165cf0* pElem, const char* pszName, unsigned nDefault);           // unsigned attribute
Unk_140165cf0* FUN_140345b40(TiXmlDocument* pDoc);  // the document's first child element
__int64 FUN_14028d0e0();                            // the current server time
CStringW FUN_140718600(const CStringW& value);      // copy

// The engine log lock (0x140203610 ctor) the sale item restriction takes.
struct Unk_EngineLogLock {
    Unk_EngineLogLock(CLockCriticalSection& cs, int n);
    ~Unk_EngineLogLock();
    void* p;
};

// The index of value in arr, -1 when missing (the gameeventcontext.cpp template; the exe folds this instance into it).
template <class T>
int Unk_ArrayFind(const ATL::CAtlArray<T>& arr, const T& value)
{
    for (size_t i = 0; i < arr.GetCount(); i++) {
        if (arr[i] == value)
            return (int)i;
    }
    return -1;
}

// CXmlData's wide value (a COMDAT of this unit).
inline CStringW CXmlData::FUN_14042cad0(const CStringW& strKey, const CStringW& strDefault)
{
    CStringW strValue;
    if (!reinterpret_cast<Values*>(m_unknown18)->Lookup(strKey, strValue))
        return strDefault;
    return FUN_140718600(strValue);
}

// @0x140422c10
Unk_GameEventValue8::Unk_GameEventValue8() : m_value(0) {}
// @0x140422c50
Unk_GameEventValue8::~Unk_GameEventValue8() {}
// @0x140422c80
int Unk_GameEventValue8::GetValue()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_value;
}
// @0x140422cd0
void Unk_GameEventValue8::SetValue(int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_value = value;
}

// @0x140422d20
Unk_GameEventValueSum::Unk_GameEventValueSum() : m_sum(0) {}
// @0x140422d70
Unk_GameEventValueSum::~Unk_GameEventValueSum() {}
// @0x140422db0
int Unk_GameEventValueSum::GetSum()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_sum;
}
// @0x140422e00
void Unk_GameEventValueSum::SetValue(unsigned long eventId, int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (value == 0)
        m_values.erase(eventId);
    else
        m_values[eventId] = value;
    m_sum = 0;
    std::map<unsigned long, unsigned long>::const_iterator it = m_values.begin();
    std::map<unsigned long, unsigned long>::const_iterator itEnd = m_values.end();
    for (; it != itEnd; ++it)
        m_sum += it->second;
}

// @0x140422f10
Unk_GameEventValueDungeonGroup::Unk_GameEventValueDungeonGroup() {}
// @0x140422f60
Unk_GameEventValueDungeonGroup::~Unk_GameEventValueDungeonGroup() {}
// @0x140422fa0
int Unk_GameEventValueDungeonGroup::GetFirst(Unk_DungeonGroupType type)
{
    if (m_groups.empty())
        return 0;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_groups.find(type) == m_groups.end())
        return 0;
    return m_groups[type].first;
}
// @0x140423090
int Unk_GameEventValueDungeonGroup::GetSecond(Unk_DungeonGroupType type, int nDefault)
{
    if (m_groups.empty())
        return INT_MAX;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_groups.find(type) == m_groups.end())
        return INT_MAX;
    std::pair<int, int>& group = m_groups[type];
    return group.second == 0 ? nDefault : group.second;
}
// @0x1404231b0
void Unk_GameEventValueDungeonGroup::Set(Unk_DungeonGroupType type, unsigned first, unsigned second)
{
    if (type == 0 || type >= 15)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (first == 0) {
        m_groups.erase(type);
        return;
    }
    if (m_groups.find(type) != m_groups.end())
        return;
    m_groups[type] = std::pair<unsigned, unsigned>(first, second);
}

// @0x1404232d0
Unk_GameEventValue88::Unk_GameEventValue88() : m_value(0) {}
// @0x140423310
Unk_GameEventValue88::~Unk_GameEventValue88() {}
// @0x140423340
int Unk_GameEventValue88::GetValue()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_value;
}
// @0x140423390
void Unk_GameEventValue88::SetValue(int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_value = value;
}

// @0x1404233e0
CGameEventValueGuildSkillSale::CGameEventValueGuildSkillSale() : m_rate(0) {}
// @0x140423420
CGameEventValueGuildSkillSale::~CGameEventValueGuildSkillSale() {}
// @0x140423450
int CGameEventValueGuildSkillSale::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
// @0x1404234a0
void CGameEventValueGuildSkillSale::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
// @0x1404234f0
CGameEventValueGuildPersonalSkillSale::CGameEventValueGuildPersonalSkillSale() : m_rate(0) {}
// @0x140423530
CGameEventValueGuildPersonalSkillSale::~CGameEventValueGuildPersonalSkillSale() {}
// @0x140423560
int CGameEventValueGuildPersonalSkillSale::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
// @0x1404235b0
void CGameEventValueGuildPersonalSkillSale::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
// @0x140423600
CGameEventValueGuildExp::CGameEventValueGuildExp() : m_rate(0) {}
// @0x140423640
CGameEventValueGuildExp::~CGameEventValueGuildExp() {}
// @0x140423670
int CGameEventValueGuildExp::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
// @0x1404236c0
void CGameEventValueGuildExp::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
// @0x140423710
CGameEventValueGuildFund::CGameEventValueGuildFund() : m_rate(0) {}
// @0x140423750
CGameEventValueGuildFund::~CGameEventValueGuildFund() {}
// @0x140423780
int CGameEventValueGuildFund::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
// @0x1404237d0
void CGameEventValueGuildFund::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}
// @0x140423820
CGameEventValueGuildCoin::CGameEventValueGuildCoin() : m_rate(0) {}
// @0x140423860
CGameEventValueGuildCoin::~CGameEventValueGuildCoin() {}
// @0x140423890
int CGameEventValueGuildCoin::GetRate()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_rate;
}
// @0x1404238e0
void CGameEventValueGuildCoin::SetRate(int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rate = rate;
}

// @0x140423930
CGameEventValueMasteryReward::CGameEventValueMasteryReward() {}
// @0x140423980
CGameEventValueMasteryReward::~CGameEventValueMasteryReward() {}
// @0x1404239c0
int CGameEventValueMasteryReward::GetRate(int type, unsigned long fieldId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int nRate = 0;
    for (std::map<unsigned long, Rates>::iterator it = m_events.begin(); it != m_events.end(); ++it) {
        Rates& rates = it->second;
        std::pair<int, unsigned long> key(type, fieldId);
        if (rates.find(key) == rates.end())
            continue;
        nRate += rates[key];
    }
    return nRate;
}
// @0x140423b10
void CGameEventValueMasteryReward::Load(unsigned long eventId, int type, const CStringW& strPath)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_140397ab0(&doc, strPath) == 0)
        return;
    Unk_140165cf0* pRoot = FUN_140345b40(&doc);
    if (pRoot == NULL)
        return;
    if (m_events.find(eventId) != m_events.end())
        return;
    Rates rates;
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("v"); pNode != NULL; pNode = pNode->FUN_140168650("v")) {
        unsigned long fieldId = FUN_140197390(pNode, "fieldID", 0);
        int rate = FUN_140197390(pNode, "rate", 0);
        if (fieldId == 0 || rate == 0)
            continue;
        std::pair<int, unsigned long> key(type, fieldId);
        if (rates.find(key) != rates.end())
            continue;
        rates[key] = rate;
    }
    m_events[eventId] = rates;
}
// @0x140423da0
void CGameEventValueMasteryReward::Remove(unsigned long eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_events.find(eventId) == m_events.end())
        return;
    m_events.erase(eventId);
}

// @0x140423e60
Unk_GameEventValue258::Unk_GameEventValue258() : m_value(0) {}
// @0x140423ea0
Unk_GameEventValue258::~Unk_GameEventValue258() {}
// @0x140423ed0
#pragma warning(push)
#pragma warning(disable : 4715)
int Unk_GameEventValue258::GetValue()
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        return m_value;
    }
}
#pragma warning(pop)
// @0x140423f40
void Unk_GameEventValue258::SetValue(int value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_value = value;
    }
}

// @0x140423fa0
CGameEventValueMeratMarketOpenTab::CGameEventValueMeratMarketOpenTab() {}
// @0x140423fe0
CGameEventValueMeratMarketOpenTab::~CGameEventValueMeratMarketOpenTab() {}
// @0x140424020
const CStringW& CGameEventValueMeratMarketOpenTab::GetTab() { return m_tab; }
// @0x140424040
void CGameEventValueMeratMarketOpenTab::SetTab(const CStringW& strTab)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_tab = strTab;
    }
}

// @0x1404240b0
CGameEventValueMasteryReduce::CGameEventValueMasteryReduce() : m_rate(0) {}
// @0x1404240d0
CGameEventValueMasteryReduce::~CGameEventValueMasteryReduce() {}
// @0x1404240e0
unsigned CGameEventValueMasteryReduce::Apply(unsigned value)
{
    if (m_rate == 0)
        return value;
    return (unsigned)((float)value / ((float)(unsigned)m_rate / 10000.0));
}
// @0x140424130
void CGameEventValueMasteryReduce::SetRate(int rate) { m_rate = rate; }
// @0x140424150
CStringW CGameEventValueMasteryReduce::GetText()
{
    if (m_rate == 0)
        return CStringW(L"");
    float fRate = (float)(unsigned)m_rate / 10000.0;
    return FUN_14028dfa0(CStringW(L"s_mastery_reduce_event"), fRate);
}

// @0x140424200
Unk_GameEventValueIdLists::Unk_GameEventValueIdLists() {}
// @0x140424270
Unk_GameEventValueIdLists::~Unk_GameEventValueIdLists() {}
// @0x1404242b0
void Unk_GameEventValueIdLists::Add(unsigned key, unsigned id)
{
    Unk_FieldIdListPtr spList(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (!m_lists.Lookup(key, spList)) {
            spList = Unk_FieldIdListPtr(Unk_FieldNewTag(0));
            m_lists.SetAt(key, spList);
        }
        if (spList.get() != NULL)
            spList->AddTail(id);
    }
}
// @0x1404243c0
bool Unk_GameEventValueIdLists::Remove(unsigned key, unsigned id)
{
    Unk_FieldIdListPtr spList(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (m_lists.Lookup(key, spList)) {
            POSITION pos = spList->Find(id);
            if (pos != NULL)
                spList->RemoveAt(pos);
            if (spList->IsEmpty())
                m_lists.RemoveKey(key);
            return true;
        }
    }
    return false;
}

// @0x1404244f0
CGameEventValueItemBox::CGameEventValueItemBox() {}
// @0x140424540
CGameEventValueItemBox::~CGameEventValueItemBox() {}
// @0x140424580
MS2Ptr<ItemBoxEventContext> CGameEventValueItemBox::Get(unsigned fieldId)
{
    if (m_contexts.empty())
        return MS2Ptr<ItemBoxEventContext>(0);
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<ItemBoxEventContext> >::iterator it = m_contexts.find(fieldId);
    if (it == m_contexts.end())
        return MS2Ptr<ItemBoxEventContext>(0);
    return it->second;
}
// @0x1404246b0
bool CGameEventValueItemBox::Add(MS2Ptr<ItemBoxEventContext> spContext)
{
    if (spContext == NULL)
        return false;
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(spContext->m_fieldID) != m_contexts.end())
        return false;
    m_contexts[spContext->m_fieldID] = spContext;
    return true;
}
// @0x1404247e0
void CGameEventValueItemBox::Remove(MS2Ptr<ItemBoxEventContext> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_fieldID);
}

// @0x140424870
CGameEventValueSaleItemsRestricted::CGameEventValueSaleItemsRestricted() : m_active(false) {}
// @0x1404248e0
CGameEventValueSaleItemsRestricted::~CGameEventValueSaleItemsRestricted() {}
// @0x140424920
bool CGameEventValueSaleItemsRestricted::IsActive() { return m_active; }
// @0x140424940
bool CGameEventValueSaleItemsRestricted::IsRestricted(unsigned itemId)
{
    Unk_EngineLogLock lock(m_lock, 1);
    if (m_items.IsEmpty())
        return false;
    if (m_items.Lookup(itemId) == NULL)
        return false;
    return true;
}
// @0x1404249f0
void CGameEventValueSaleItemsRestricted::SetItems(ATL::CAtlArray<unsigned>& items)
{
    Unk_EngineLogLock lock(m_lock, 1);
    m_items.RemoveAll();
    m_active = false;
    for (size_t i = 0; i < items.GetCount(); i++) {
        const unsigned& itemId = items.GetAt(i);
        if (itemId != 0)
            m_items.SetAt(itemId, 0);
    }
    if (m_items.GetCount() != 0)
        m_active = true;
}
// @0x140424ae0
void CGameEventValueSaleItemsRestricted::Clear()
{
    Unk_EngineLogLock lock(m_lock, 1);
    m_items.RemoveAll();
    m_active = false;
}

// @0x140424b40
Unk_GameEventValue408::Unk_GameEventValue408() : m_set(false), m_value(0) {}
// @0x140424b70
Unk_GameEventValue408::~Unk_GameEventValue408() {}
// @0x140424b80
bool Unk_GameEventValue408::IsSet() { return m_set; }
// @0x140424ba0
int Unk_GameEventValue408::GetValue() { return m_value; }
// @0x140424bc0
void Unk_GameEventValue408::SetValue(int value)
{
    m_value = value;
    if (m_value != 0)
        m_set = true;
}
// @0x140424bf0
void Unk_GameEventValue408::Reset()
{
    m_value = 0;
    m_set = false;
}

// @0x140424c10
CGameEventValueDungeonHelperBonus::CGameEventValueDungeonHelperBonus() : m_bonus(0) {}
// @0x140424c50
CGameEventValueDungeonHelperBonus::~CGameEventValueDungeonHelperBonus() {}
// @0x140424c80
void CGameEventValueDungeonHelperBonus::Add(int bonus)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_bonus += bonus;
}
// @0x140424cd0
void CGameEventValueDungeonHelperBonus::Sub(int bonus)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_bonus -= bonus;
}
// @0x140424d20
int CGameEventValueDungeonHelperBonus::GetBonus()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_bonus;
}

// @0x140424d70
CGameEventValueMentoring::CGameEventValueMentoring() : m_spContext(0) {}
// @0x140424da0
void CGameEventValueMentoring::Set(MS2Ptr<MentoringContext> spContext) { m_spContext = spContext; }
// @0x140424de0
int CGameEventValueMentoring::GetId()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_18;
}
// @0x140424e20
__int64 CGameEventValueMentoring::GetEndTime()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_28;
}
// @0x140424e60
__int64 CGameEventValueMentoring::GetBeginTime()
{
    if (m_spContext == NULL)
        return 0;
    return m_spContext->m_20;
}
// @0x140424ea0
void CGameEventValueMentoring::Reset() { m_spContext = 0; }
// @0x140424ed0
void CGameEventValueMentoring::GetIds(ATL::CAtlArray<unsigned>& ids)
{
    if (m_spContext == NULL)
        return;
    ids.Copy(m_spContext->m_ids);
}
// @0x140424f20
bool CGameEventValueMentoring::HasId(unsigned id)
{
    if (m_spContext == NULL)
        return false;
    return Unk_ArrayFind(m_spContext->m_ids, id) != -1;
}

// @0x140424f90
CGameEventValueDungeonBuff::CGameEventValueDungeonBuff() {}
// @0x140424ff0
void CGameEventValueDungeonBuff::Add(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts* pCounts;
    if (spContext->m_isBeginner)
        pCounts = &m_beginnerBuffs[dungeonId];
    else
        pCounts = &m_buffs[dungeonId];
    if (pCounts == NULL)
        return;
    DungeonBuffEventCtx* pContext = spContext.get();
    for (size_t i = 0; i < pContext->m_addEffectGUIDs.size(); i++)
        (*pCounts)[pContext->m_addEffectGUIDs[i]]++;
}
// @0x140425150
void CGameEventValueDungeonBuff::Remove(unsigned long dungeonId, MS2Ptr<DungeonBuffEventCtx> spContext)
{
    if (spContext == NULL)
        return;
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts* pCounts;
    if (spContext->m_isBeginner)
        pCounts = &m_beginnerBuffs[dungeonId];
    else
        pCounts = &m_buffs[dungeonId];
    if (pCounts == NULL)
        return;
    std::vector<unsigned __int64>& guids = spContext.get()->m_addEffectGUIDs;
    for (size_t i = 0; i < guids.size(); i++) {
        unsigned __int64 guid = guids[i];
        if ((*pCounts)[guid] < 2)
            pCounts->erase(guid);
        else
            (*pCounts)[guid]--;
    }
}
// @0x1404252f0
void CGameEventValueDungeonBuff::GetBuffs(unsigned long dungeonId, std::set<unsigned __int64>& buffs)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts& counts = m_buffs[dungeonId];
    for (Counts::iterator it = counts.begin(), itEnd = counts.end(); it != itEnd; it++)
        buffs.insert(it->first);
}
// @0x1404253c0
void CGameEventValueDungeonBuff::GetBeginnerBuffs(unsigned long dungeonId, std::vector<unsigned __int64>& buffs)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Counts& counts = m_beginnerBuffs[dungeonId];
    buffs.reserve(counts.size());
    for (Counts::iterator it = counts.begin(), itEnd = counts.end(); it != itEnd; it++)
        buffs.push_back(it->first);
}

// @0x1404254a0
CGameEventValueBattlePetSpawn::CGameEventValueBattlePetSpawn() : m_time(0) {}
// @0x1404255b0
void CGameEventValueBattlePetSpawn::AddSpawn(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    if (strFields.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    CStringW strProbabilities = spXml->FUN_14042cad0(L"spawnProbabilities", L"");
    if (strProbabilities.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> probabilities;
    FUN_140274fc0(strProbabilities, probabilities, L",");
    if (probabilities.IsEmpty())
        return;
    if (fields.GetCount() != probabilities.GetCount())
        return;
    CStringW strCounts = spXml->FUN_14042cad0(L"spawnCounts", L"");
    if (strCounts.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> counts;
    FUN_140274fc0(strCounts, counts, L",");
    if (counts.IsEmpty())
        return;
    if (fields.GetCount() != counts.GetCount())
        return;
    CStringW strPets = spXml->FUN_14042cad0(L"spawnPetIDs", L"");
    if (strPets.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> pets;
    FUN_140274fc0(strPets, pets, L",");
    if (pets.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            unsigned fieldId = fields[i];
            MS2Ptr<SpawnContext> spSpawn(new SpawnContext);
            spSpawn->m_eventId = eventId;
            spSpawn->m_probability = probabilities[i];
            spSpawn->m_count = counts[i];
            spSpawn->m_petIds.Copy(pets);
            for (unsigned j = 0; j < pets.GetCount(); j++)
                m_petFields.Insert(pets[j], fieldId);
            m_spawns.SetAt(fieldId, spSpawn);
        }
        m_time = FUN_14028d0e0();
    }
}
// @0x140425f40
void CGameEventValueBattlePetSpawn::RemoveSpawn(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    if (strFields.IsEmpty())
        return;
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            int fieldId = fields[i];
            MS2Ptr<SpawnContext> spSpawn(0);
            if (!m_spawns.Lookup(fieldId, spSpawn))
                continue;
            if (spSpawn->m_eventId != eventId)
                continue;
            for (unsigned j = 0; j < spSpawn->m_petIds.GetCount(); j++) {
                unsigned petId = spSpawn->m_petIds[j];
                POSITION pos = m_petFields.FindFirstWithKey(petId);
                while (pos != NULL) {
                    POSITION posCur = pos;
                    m_petFields.GetNextWithKey(pos, petId);
                    int nField = m_petFields.GetValueAt(posCur);
                    if (nField == fieldId)
                        m_petFields.RemoveAt(posCur);
                }
            }
            m_spawns.RemoveKey(fieldId);
            m_endTimes.SetAt(fieldId, FUN_14028d0e0());
        }
    }
}
// @0x140426380
void CGameEventValueBattlePetSpawn::AddImprove(unsigned eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    CStringW strProbabilities = spXml->FUN_14042cad0(L"improveProbabilities", L"");
    ATL::CAtlArray<unsigned> probabilities;
    FUN_140274fc0(strProbabilities, probabilities, L",");
    if (fields.GetCount() != probabilities.GetCount())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++)
            m_improves.SetAt(fields[i], std::pair<unsigned, unsigned>(eventId, probabilities[i]));
    }
}
// @0x1404266f0
void CGameEventValueBattlePetSpawn::RemoveImprove(int eventId, const CStringW& strValues)
{
    MS2Ptr<CXmlData> spXml(new CXmlData(strValues));
    if (spXml == NULL)
        return;
    CStringW strFields = spXml->FUN_14042cad0(L"targetFieldIDs", L"");
    ATL::CAtlArray<unsigned> fields;
    FUN_140274fc0(strFields, fields, L",");
    if (fields.IsEmpty())
        return;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        for (unsigned i = 0; i < fields.GetCount(); i++) {
            std::pair<unsigned, unsigned> improve;
            if (m_improves.Lookup(fields[i], improve) && improve.first == (unsigned)eventId)
                m_improves.RemoveKey(fields[i]);
        }
    }
}
// @0x140426960
#pragma warning(push)
#pragma warning(disable : 4715)
__int64 CGameEventValueBattlePetSpawn::GetTime(unsigned fieldId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        if (m_spawns.Lookup(fieldId) != NULL)
            return m_time;
        __int64 endTime = 0;
        if (!m_endTimes.Lookup(fieldId, endTime))
            return 0;
        return endTime;
    }
}
#pragma warning(pop)
// @0x140426a50
unsigned CGameEventValueBattlePetSpawn::GetImproveProbability(unsigned fieldId)
{
    unsigned probability = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        std::pair<unsigned, unsigned> improve;
        if (!m_improves.Lookup(fieldId, improve)) {
            if (m_improves.Lookup(0, improve))
                probability = improve.second;
        } else {
            probability = improve.second;
        }
    }
    return probability;
}
// @0x140426b10
MS2Ptr<CGameEventValueBattlePetSpawn::SpawnContext> CGameEventValueBattlePetSpawn::GetSpawn(unsigned fieldId)
{
    MS2Ptr<SpawnContext> spSpawn(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_spawns.Lookup(fieldId, spSpawn);
    }
    return spSpawn;
}
// @0x140426bc0
void CGameEventValueBattlePetSpawn::GetFields(unsigned petId, ATL::CAtlArray<unsigned>& fields)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        POSITION pos = m_petFields.FindFirstWithKey(petId);
        while (pos != NULL) {
            fields.Add(m_petFields.GetValueAt(pos));
            m_petFields.GetNextWithKey(pos, petId);
        }
    }
}

// @0x140426c90
CGameEventValueIDIPEvent::CGameEventValueIDIPEvent() {}
// @0x140426d00
void CGameEventValueIDIPEvent::Add(unsigned id, int type, const CMsTime& time)
{
    MS2Ptr<IDIPEventContext> spContext(new IDIPEventContext(type, time));
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.SetAt(id, spContext);
    }
}
// @0x140426e00
void CGameEventValueIDIPEvent::Remove(unsigned id)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.RemoveKey(id);
    }
}
// @0x140426e70
MS2Ptr<CGameEventValueIDIPEvent::IDIPEventContext> CGameEventValueIDIPEvent::Find(int type)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        POSITION pos = m_events.GetStartPosition();
        while (pos != NULL) {
            const MS2Ptr<IDIPEventContext>& pCtx = m_events.GetValueAt(pos);
            MS2_ASSERT_AT(0x43a, pCtx != NULL);
            if (pCtx->m_type == type)
                return pCtx;
            m_events.GetNext(pos);
        }
    }
    return MS2Ptr<IDIPEventContext>(0);
}

// @0x140426fb0
CGameEventValueStarShop::CGameEventValueStarShop() : m_value(0) {}
// @0x140426ff0
void CGameEventValueStarShop::SetValue(int value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_value = value;
    }
}
// @0x140427050
int CGameEventValueStarShop::GetValue() { return m_value; }

// @0x140427070
CGameEventValueNpcShopTalk::CGameEventValueNpcShopTalk() {}
// @0x1404270e0
void CGameEventValueNpcShopTalk::Set(unsigned npcId, unsigned value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.SetAt(npcId, value);
    }
}
// @0x140427150
void CGameEventValueNpcShopTalk::Remove(unsigned npcId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.RemoveKey(npcId);
    }
}
// @0x1404271c0
unsigned CGameEventValueNpcShopTalk::Get(unsigned npcId)
{
    unsigned value = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.Lookup(npcId, value);
    }
    return value;
}

// @0x140427240
CGameEventValueNpcShopGivePoint::CGameEventValueNpcShopGivePoint() {}
// @0x1404272b0
void CGameEventValueNpcShopGivePoint::Set(unsigned id, MS2Ptr<CNpcShopGivePointContextBase> spContext)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.SetAt(id, spContext);
    }
}
// @0x140427330
void CGameEventValueNpcShopGivePoint::Remove(unsigned id)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.RemoveKey(id);
    }
}
// @0x1404273a0
MS2Ptr<CNpcShopGivePointContextBase> CGameEventValueNpcShopGivePoint::Get(unsigned id)
{
    MS2Ptr<CNpcShopGivePointContextBase> spContext(0);
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_contexts.Lookup(id, spContext);
    }
    return spContext;
}

// @0x140427450
CGameEventValueNpcShopResetPriceSale::CGameEventValueNpcShopResetPriceSale() {}
// @0x1404274c0
void CGameEventValueNpcShopResetPriceSale::Set(unsigned npcId, unsigned value)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.SetAt(npcId, value);
    }
}
// @0x140427530
void CGameEventValueNpcShopResetPriceSale::Remove(unsigned npcId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.RemoveKey(npcId);
    }
}
// @0x1404275a0
unsigned CGameEventValueNpcShopResetPriceSale::Get(unsigned npcId)
{
    unsigned value = 0;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_values.Lookup(npcId, value);
    }
    return value;
}

// @0x140427620
CGameEventValueDungeonOpenPeriod::CGameEventValueDungeonOpenPeriod() {}
// @0x140427690
bool CGameEventValueDungeonOpenPeriod::Add(CStringW strTag, __int64 beginTime, __int64 endTime)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_periods.Lookup(strTag) != NULL)
        return false;
    m_periods.SetAt(strTag, Unk_FieldTimeSpan(beginTime, endTime));
    return true;
}
// @0x140427780
void CGameEventValueDungeonOpenPeriod::Remove(CStringW strTag)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_periods.RemoveKey(strTag);
}
// @0x1404277f0
bool CGameEventValueDungeonOpenPeriod::IsOpen(CStringW strTag, __int64 time)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    Unk_FieldTimeSpan period;
    if (m_periods.Lookup(strTag, period) && period.Contains(time))
        return true;
    return false;
}
// @0x1404278c0
bool CGameEventValueDungeonOpenPeriod::GetPeriod(CStringW strTag, Unk_FieldTimeSpan& period)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!m_periods.Lookup(strTag, period))
        return false;
    return true;
}

// @0x140427970
Unk_GameEventValueIdSet::Unk_GameEventValueIdSet() {}
// @0x1404279c0
void Unk_GameEventValueIdSet::Add(int id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_ids.insert(id);
}
// @0x140427a20
void Unk_GameEventValueIdSet::Remove(int id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_ids.erase(id);
}
// @0x140427a80
bool Unk_GameEventValueIdSet::IsActive()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return !m_ids.empty();
}

// @0x140427af0
Unk_GameEventValueDayItem::Unk_GameEventValueDayItem() {}
// @0x140427b60
void Unk_GameEventValueDayItem::Add(unsigned id, Unk_DayItemContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.SetAt(id, MS2Ptr<Unk_DayItemContext>(pContext));
}
// @0x140427be0
void Unk_GameEventValueDayItem::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
// @0x140427c30
void Unk_GameEventValueDayItem::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_DayItemContext> >& contexts, bool bAll)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    POSITION pos = m_contexts.GetStartPosition();
    while (pos != NULL) {
        Unk_DayItemContext* pContext = m_contexts.GetValueAt(pos);
        if (pContext->IsActive() || bAll)
            contexts.Add(MS2Ptr<Unk_DayItemContext>(pContext));
        m_contexts.GetNext(pos);
    }
}

// @0x140427d20
Unk_GameEventValueFieldObjectDrop::Unk_GameEventValueFieldObjectDrop() {}
// @0x140427d90
void Unk_GameEventValueFieldObjectDrop::Add(unsigned id, Unk_FieldObjectDropContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.SetAt(id, MS2Ptr<Unk_FieldObjectDropContext>(pContext));
}
// @0x140427e10
void Unk_GameEventValueFieldObjectDrop::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
// @0x140427e60
void Unk_GameEventValueFieldObjectDrop::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    POSITION pos = m_contexts.GetStartPosition();
    while (pos != NULL) {
        Unk_FieldObjectDropContext* pContext = m_contexts.GetValueAt(pos);
        contexts.Add(MS2Ptr<Unk_FieldObjectDropContext>(pContext));
        m_contexts.GetNext(pos);
    }
}

// @0x140427f30
Unk_GameEventValueFieldObjectDropList::Unk_GameEventValueFieldObjectDropList() {}
// @0x140427fa0
void Unk_GameEventValueFieldObjectDropList::Add(unsigned id, Unk_FieldObjectDropListContext* pContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.SetAt(id, MS2Ptr<Unk_FieldObjectDropListContext>(pContext));
}
// @0x140428020
void Unk_GameEventValueFieldObjectDropList::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}
// @0x140428070
void Unk_GameEventValueFieldObjectDropList::GetContexts(ATL::CAtlArray<MS2Ptr<Unk_FieldObjectDropListContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    POSITION pos = m_contexts.GetStartPosition();
    while (pos != NULL) {
        Unk_FieldObjectDropListContext* pContext = m_contexts.GetValueAt(pos);
        contexts.Add(MS2Ptr<Unk_FieldObjectDropListContext>(pContext));
        m_contexts.GetNext(pos);
    }
}
// @0x140428140
Unk_GameEventValueFieldObjectDropList2::Unk_GameEventValueFieldObjectDropList2() {}

// @0x140428170
CGameEventValueBurningLevelup::CGameEventValueBurningLevelup() {}
// @0x1404281c0
CGameEventValueBurningLevelup::~CGameEventValueBurningLevelup() {}
// @0x140428200
MS2Ptr<BurningLevelupContext> CGameEventValueBurningLevelup::Get(unsigned eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.find(eventId);
    if (it == m_contexts.end())
        return MS2Ptr<BurningLevelupContext>(0);
    return it->second;
}
// @0x140428300
void CGameEventValueBurningLevelup::GetAll(std::vector<MS2Ptr<BurningLevelupContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.empty())
        return;
    for (std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it)
        contexts.push_back(it->second);
}
// @0x1404283e0
void CGameEventValueBurningLevelup::Add(MS2Ptr<BurningLevelupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.insert(std::pair<const unsigned, MS2Ptr<BurningLevelupContext> >(spContext->m_eventId, spContext));
}
// @0x1404284a0
void CGameEventValueBurningLevelup::Remove(MS2Ptr<BurningLevelupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_eventId);
}
// @0x140428510
MS2Ptr<BurningLevelupContext> CGameEventValueBurningLevelup::FindByTarget(int id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    for (std::map<unsigned, MS2Ptr<BurningLevelupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it) {
        if (it->second == NULL)
            continue;
        if (it->second->HasTarget(id))
            return it->second;
    }
    return MS2Ptr<BurningLevelupContext>(0);
}

// @0x140428670
CGameEventValueCoupleDance::CGameEventValueCoupleDance() : m_spContext(0) {}
// @0x1404286c0
CGameEventValueCoupleDance::~CGameEventValueCoupleDance() {}
// @0x140428700
MS2Ptr<CoupleDanceContext> CGameEventValueCoupleDance::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
// @0x140428780
void CGameEventValueCoupleDance::Set(MS2Ptr<CoupleDanceContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spContext = spContext;
}

// @0x1404287f0
CGameEventValuePublicTest::CGameEventValuePublicTest() : m_value(0) {}
// @0x140428810
void CGameEventValuePublicTest::SetValue(int value) { m_value = value; }
// @0x140428830
int CGameEventValuePublicTest::GetValue() { return m_value; }

// @0x140428850
CGameEventValueFestival::CGameEventValueFestival() { m_contexts.RemoveAll(); }
// @0x1404288d0
void CGameEventValueFestival::GetAll(ATL::CAtlArray<MS2Ptr<FestivalContext> >& contexts)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        POSITION pos = m_contexts.GetStartPosition();
        while (pos != NULL) {
            contexts.Add(m_contexts.GetValueAt(pos));
            m_contexts.GetNext(pos);
        }
    }
}
// @0x140428980
void CGameEventValueFestival::Add(unsigned id, MS2Ptr<FestivalContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.SetAt(id, spContext);
}
// @0x1404289f0
void CGameEventValueFestival::Remove(unsigned id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.RemoveKey(id);
}

// @0x140428a40
CGameEventValueFieldEffect::CGameEventValueFieldEffect() : m_spContext(0) {}
// @0x140428a90
MS2Ptr<FieldEffectContext> CGameEventValueFieldEffect::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
// @0x140428b10
void CGameEventValueFieldEffect::Set(MS2Ptr<FieldEffectContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_spContext = spContext;
}

// @0x140428b80
CGameEventValueExchangeScrollSale::CGameEventValueExchangeScrollSale() {}
// @0x140428bf0
void CGameEventValueExchangeScrollSale::Set(unsigned long itemId, int rate)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rates.SetAt(itemId, rate);
}
// @0x140428c60
void CGameEventValueExchangeScrollSale::Remove(unsigned long itemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_rates.RemoveKey(itemId);
}
// @0x140428cb0
int CGameEventValueExchangeScrollSale::Get(unsigned long itemId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    int rate = 0;
    m_rates.Lookup(itemId, rate);
    return rate;
}

// @0x140428d30
Unk_GameEventValueC50::Unk_GameEventValueC50() : m_beginTime(0), m_endTime(0), m_value(0) {}
// @0x140428d80
void Unk_GameEventValueC50::Set(__int64 beginTime, __int64 endTime, int value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_beginTime = beginTime;
    m_endTime = endTime;
    m_value = value;
}
// @0x140428df0
void Unk_GameEventValueC50::Clear()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_beginTime = 0;
    m_endTime = 0;
    m_value = 0;
}
// @0x140428e50
bool Unk_GameEventValueC50::Get(__int64& beginTime, __int64& endTime, int& value)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_beginTime == 0 && m_value == 0)
        return false;
    beginTime = m_beginTime;
    endTime = m_endTime;
    value = m_value;
    return true;
}

// @0x140428f00
CGameEventValueItemTradeRestriction::RestrictionData::RestrictionData() {}
// @0x1404290b0
void CGameEventValueItemTradeRestriction::RestrictionData::SetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId,
                                                                    unsigned short limit)
{
    switch (eType) {
    case eItemTradeRestriction_BlackMarketSell:
        m_blackMarketSell.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_BlackMarketBuy:
        m_blackMarketBuy.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_TradeSend:
        m_tradeSend.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_TradeRecv:
        m_tradeRecv.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_DropItem:
        m_dropItem.SetAt(itemId, limit);
        break;
    case eItemTradeRestriction_PickupItem:
        m_pickupItem.SetAt(itemId, limit);
        break;
    }
}
// @0x1404291d0
unsigned short CGameEventValueItemTradeRestriction::RestrictionData::GetLimit(Unk_ItemTradeRestrictionType eType,
                                                                              unsigned itemId)
{
    unsigned short limit = 0;
    switch (eType) {
    case eItemTradeRestriction_BlackMarketSell:
        m_blackMarketSell.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_BlackMarketBuy:
        m_blackMarketBuy.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_TradeSend:
        m_tradeSend.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_TradeRecv:
        m_tradeRecv.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_DropItem:
        m_dropItem.Lookup(itemId, limit);
        break;
    case eItemTradeRestriction_PickupItem:
        m_pickupItem.Lookup(itemId, limit);
        break;
    }
    return limit;
}
// @0x1404292f0
CGameEventValueItemTradeRestriction::CGameEventValueItemTradeRestriction() {}
// @0x140429330
void CGameEventValueItemTradeRestriction::Add(unsigned eventId, const MS2Ptr<RestrictionData>& spData)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.SetAt(eventId, spData);
    }
}
// @0x1404293a0
void CGameEventValueItemTradeRestriction::Remove(unsigned eventId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_events.RemoveKey(eventId);
    }
}
// @0x140429410
unsigned short CGameEventValueItemTradeRestriction::GetLimit(Unk_ItemTradeRestrictionType eType, unsigned itemId)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        POSITION pos = m_events.GetHeadPosition();
        while (pos != NULL) {
            const MS2Ptr<RestrictionData>& spData = m_events.GetValueAt(pos);
            unsigned short limit = spData->GetLimit(eType, itemId);
            if (limit != 0)
                return limit;
            m_events.GetNext(pos);
        }
    }
    return 0;
}

// @0x140429500
CGameEventValueCollectItemGroup::CGameEventValueCollectItemGroup() {}
// @0x140429550
CGameEventValueCollectItemGroup::~CGameEventValueCollectItemGroup() {}
// @0x140429590
MS2Ptr<CollectItemGroupContext> CGameEventValueCollectItemGroup::Get(int eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<int, MS2Ptr<CollectItemGroupContext> >::const_iterator it = m_contexts.find(eventId);
    if (it == m_contexts.end())
        return MS2Ptr<CollectItemGroupContext>(0);
    return it->second;
}
// @0x140429690
void CGameEventValueCollectItemGroup::GetAll(std::vector<MS2Ptr<CollectItemGroupContext> >& contexts)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.empty())
        return;
    for (std::map<int, MS2Ptr<CollectItemGroupContext> >::const_iterator it = m_contexts.begin();
         it != m_contexts.end(); ++it)
        contexts.push_back(it->second);
}
// @0x140429770
void CGameEventValueCollectItemGroup::Add(MS2Ptr<CollectItemGroupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.insert(std::pair<const int, MS2Ptr<CollectItemGroupContext> >(spContext->m_eventId, spContext));
}
// @0x140429830
void CGameEventValueCollectItemGroup::Remove(MS2Ptr<CollectItemGroupContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_eventId);
}

// @0x1404298a0
CGameEventValueArcadeOpen::CGameEventValueArcadeOpen() {}
// @0x1404298f0
CGameEventValueArcadeOpen::~CGameEventValueArcadeOpen() {}
// @0x140429930
MS2Ptr<ArcadeOpenContext> CGameEventValueArcadeOpen::Get(int arcadeId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<int, MS2Ptr<ArcadeOpenContext> >::const_iterator it = m_contexts.find(arcadeId);
    if (it == m_contexts.end())
        return MS2Ptr<ArcadeOpenContext>(0);
    return it->second;
}
// @0x140429a30
bool CGameEventValueArcadeOpen::Add(MS2Ptr<ArcadeOpenContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(spContext->m_arcadeId) != m_contexts.end())
        return false;
    m_contexts.insert(std::pair<const int, MS2Ptr<ArcadeOpenContext> >(spContext->m_arcadeId, spContext));
    return true;
}
// @0x140429b80
void CGameEventValueArcadeOpen::Remove(MS2Ptr<ArcadeOpenContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts.erase(spContext->m_arcadeId);
}

// @0x140429bf0
CGameEventValueBingo::CGameEventValueBingo() {}
// @0x140429c40
CGameEventValueBingo::~CGameEventValueBingo() {}
// @0x140429c80
MS2Ptr<BingoContext> CGameEventValueBingo::Get()
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    return m_spContext;
}
// @0x140429d00
void CGameEventValueBingo::Set(MS2Ptr<BingoContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    m_spContext = spContext;
}
// @0x140429d90
void CGameEventValueBingo::Clear(MS2Ptr<BingoContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_spContext == spContext.get())
        m_spContext = 0;
}

// @0x140429e20
CGameEventValueLimitedQuantity::CGameEventValueLimitedQuantity() {}
// @0x140429e80
CGameEventValueLimitedQuantity::~CGameEventValueLimitedQuantity() {}
// @0x140429ed0
MS2Ptr<LimitedQuantityContext> CGameEventValueLimitedQuantity::Get(int eventId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_contexts.find(eventId) == m_contexts.end())
        return MS2Ptr<LimitedQuantityContext>(0);
    return m_contexts[eventId];
}
// @0x140429fd0
MS2Ptr<LimitedQuantityContext> CGameEventValueLimitedQuantity::GetByKey(int key)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (m_keys.find(key) == m_keys.end())
        return MS2Ptr<LimitedQuantityContext>(0);
    return Get(m_keys[key]);
}
// @0x14042a0e0
void CGameEventValueLimitedQuantity::Add(MS2Ptr<LimitedQuantityContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    if (spContext->m_1c == 0 || spContext->m_eventId == 0)
        return;
    std::map<int, int>::iterator it = m_keys.find(spContext->m_1c);
    if (it != m_keys.end())
        return;
    m_keys[spContext->m_1c] = spContext->m_eventId;
    m_contexts[spContext->m_eventId] = spContext;
}
// @0x14042a260
void CGameEventValueLimitedQuantity::Remove(MS2Ptr<LimitedQuantityContext> spContext)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    if (!spContext)
        return;
    if (spContext->m_1c == 0 || spContext->m_eventId == 0)
        return;
    m_keys.erase(spContext->m_1c);
    m_contexts.erase(spContext->m_eventId);
}

// @0x14042a360
CGameEventValueEventShopNpc::CGameEventValueEventShopNpc() {}
// @0x14042a3c0
void CGameEventValueEventShopNpc::Add(MS2Ptr<EventShopNpcContext> pContext)
{
    MS2_ASSERT_AT(0x863, pContext != NULL);
    Unk_CriticalSectionLock lock(m_lock, 1);
    m_contexts[pContext->Get18()] = pContext;
    std::map<unsigned long, Contexts>::iterator it = m_groups.find(pContext->Get20());
    if (it == m_groups.end()) {
        Contexts contexts;
        contexts.push_back(pContext);
        m_groups.insert(std::pair<const unsigned long, Contexts>(pContext->Get20(), contexts));
    } else {
        it->second.push_back(pContext);
    }
}
// @0x14042a5b0
void CGameEventValueEventShopNpc::Remove(int id)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned long, MS2Ptr<EventShopNpcContext> >::iterator it = m_contexts.find(id);
    if (it == m_contexts.end())
        return;
    int group = it->second->Get20();
    m_contexts.erase(it);
    std::map<unsigned long, Contexts>::iterator itGroup = m_groups.find(group);
    if (itGroup == m_groups.end()) {
        MS2_ASSERT_AT(0x889, FALSE);
    } else {
        Contexts& contexts = itGroup->second;
        for (Contexts::iterator itList = contexts.begin(); itList != contexts.end();) {
            if ((*itList)->Get18() == id)
                contexts.erase(itList++);
            else
                ++itList;
        }
    }
}
// @0x14042a7d0
MS2Ptr<EventShopNpcContext> CGameEventValueEventShopNpc::Find(unsigned long group, int npcId)
{
    Unk_CriticalSectionLock lock(m_lock, 1);
    std::map<unsigned long, Contexts>::iterator it = m_groups.find(group);
    if (it == m_groups.end())
        return MS2Ptr<EventShopNpcContext>(0);
    Contexts& contexts = it->second;
    for (Contexts::iterator itList = contexts.begin(); itList != contexts.end(); ++itList) {
        if ((*itList)->Get1c() == npcId)
            return *itList;
    }
    return MS2Ptr<EventShopNpcContext>(0);
}
