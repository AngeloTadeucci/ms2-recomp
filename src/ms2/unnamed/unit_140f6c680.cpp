// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item socket UI page family.
// MS2-UNIT: unit_140f6c680
// MS2-RANGE: 0x140f6c680-0x140f7d060 .text$mn
// MS2-RANGE: 0x1400e04c0-0x1400e09d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VSaleParam@ItemSocketSystemPageBase@@@@QEBAPEAVSaleParam@ItemSocketSystemPageBase@@XZ 0x140f6ed00 ; unique
// MS2-PIN: ??_G?$MS2Ptr@VCItem@@@@QEAAPEAXI@Z 0x140f739c0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VCItem@@@@@Z 0x140f73a40 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@CAXPEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140f73b70 ; unique
// MS2-PIN: ?GetAt@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCItem@@@@_K@Z 0x140f73bd0 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x140f73c20 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCreateParam@ItemSlotBag@@@@QEAA@AEBV0@@Z 0x140f7af30 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@PEAVCItem@@@Z 0x140f7af70 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@$$QEAV0@@Z 0x140f7afa0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCItem@@@@QEAA@H@Z 0x140f7b010 ; unique
// MS2-PIN: ??0?$MS2Ptr@VASMovieClip@@@@QEAA@XZ 0x140f7b060 ; unique
// MS2-PIN: ??1SaleParam@ItemSocketSystemPageBase@@UEAA@XZ 0x140f7b480 ; prop
// MS2-PIN: ??4?$MS2Ptr@VCItem@@@@QEAAAEAV0@AEBV0@@Z 0x140f7b5e0 ; unique
// MS2-PIN: ??_GSaleParam@ItemSocketSystemPageBase@@UEAAPEAXI@Z 0x140f7b810 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEBA_NXZ 0x140f7bd40 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VTSocketGemStoneBind@@@@AEBAXXZ 0x140f7c920 ; prop
// MS2-PIN: ?Reference@?$MS2Ptr@VTSocketGemStoneInfo@@@@CAXPEAVTSocketGemStoneInfo@@@Z 0x140f7c950 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCreateParam@ItemSlotBag@@@@AEBAXPEAX@Z 0x140f7c970 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagebase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagebase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/client/ms2/itemsocketsystempagecontrols.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/asobj.h"

// The result is formatted through fmt's enum customization, rather than an integer argument.
enum class Unk_SocketPageResult : int {};
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
void FUN_1412751f0(const CStringW&, int, int);
void FUN_1412752d0(const CStringW&, int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);

class CItemGemStoneUpgradeTable;
class Unk_SocketPageWorld;
class Unk_SocketPagePlayer;
class Unk_SocketPageInventory;
class Unk_SocketPageDialog;
class Unk_SocketPageFeatures;
Unk_SocketPageWorld* FUN_1403ed2d0();
Unk_SocketPagePlayer* FUN_141bd0cc0(Unk_SocketPageWorld*);
Unk_SocketPageInventory* FUN_1416561a0(Unk_SocketPagePlayer*);
void FUN_1411e7660(Unk_SocketPageInventory*);
Unk_SocketPageDialog* FUN_140938c30(int);
void FUN_141a5a5c0(Unk_SocketPageDialog*);
CItemGemStoneUpgradeTable* FUN_14062c280();
void FUN_1405b1b50(CItemGemStoneUpgradeTable*);
void FUN_1412761e0(MS2Ptr<AScript>, int);
Unk_SocketPageFeatures* FUN_140166410();
bool FUN_14036d570(Unk_SocketPageFeatures*, int);
int FUN_14053feb0(int);
__int64 FUN_14028d0e0();
NotifyContext::BindData* FUN_1422c8e90(const CString&);
ItemInfoSlot* FUN_140c69ab0(NotifyContext::BindData*);
ItemInfoSlot* FUN_140f6e830(const CString&);
void FUN_141415af0(ItemInfoSlot*, MS2Ptr<CItem>);
MS2Ptr<CItem> FUN_141425750(__int64, bool*);
class Unk_SocketPageInventoryCount;
extern char DAT_143ab2a90;
int FUN_140a5f180(Unk_SocketPageInventoryCount*, int, int);
int FUN_140a5f780(Unk_SocketPageInventoryCount*, int, int);
int FUN_14053c6f0(Unk_ItemEquipData*);
int FUN_140627b80(int, int);
CString FUN_1422cc860(const CString&, int);
void FUN_141416740(ItemInfoSlot*, int, int);
void FUN_14141f970(const CString&);
void FUN_14141f770(const CString&, int, void*, ItemSlotBag::CreateParam::GetItemFn, int, int);
MS2Ptr<CItem> FUN_141420330(void*, int);
void FUN_141415600(const CString&);
void FUN_141415450(const CString&, MS2Ptr<CItem>, int, int, int);
CStringW FUN_1419021b0(unsigned, unsigned);
Scaleform::GFx::Value FUN_140f356e0(AScript*, const char*, int, bool);
void FUN_14141f860(const CString&, int, void*, MS2Ptr<ItemSlotBag::CreateParam>);
DragSlotBag* FUN_140c54570(const CString&);
void FUN_1422cc9e0(DragSlotBag*);
void FUN_14141ff80(ItemSlotBag*, int);
void FUN_1422cf860(Unk_SocketPageBag*);
void FUN_1422ccb50(DragSlotBag*, int);
void FUN_1422cf7e0(Unk_SocketPageBag*, int);
int FUN_1422dd150(Unk_SocketPageBag*);
void FUN_1422dcca0(Unk_SocketPageBag*, int);

// @0x140f6c680
ItemSocketSystemPageBase::ItemSocketSystemPageBase() : m_restoreInventory(false) {}

// @0x140f6c6e0
ItemSocketSystemPageBase::~ItemSocketSystemPageBase() {}

// @0x140f6c720
void ItemSocketSystemPageBase::vfunc_1()
{
    if (m_root.get() != 0)
        m_root->vfunc_3(0);
}

// @0x140f6c780
void ItemSocketSystemPageBase::vfunc_2()
{
    m_root = 0;
    if (m_restoreInventory) {
        Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0)
            FUN_1411e7660(FUN_1416561a0(player));
        Unk_SocketPageDialog* dialog = FUN_140938c30(10001);
        if (dialog != 0)
            FUN_141a5a5c0(dialog);
    }
    m_restoreInventory = false;
}

// @0x140f6c810
void ItemSocketSystemPageBase::vfunc_4(MS2Ptr<AScript> root)
{
    FUN_1405b1b50(FUN_14062c280());
    vfunc_7(root);
    if (m_root.get() != 0)
        m_root->vfunc_3(1);
}

// @0x140f6c8c0
void ItemSocketSystemPageBase::vfunc_6() {}

// @0x140f6c8d0
void ItemSocketSystemPageBase::vfunc_7(MS2Ptr<AScript> root)
{
    if (m_root.get() != 0)
        FUN_140f6d620(1);
}

// @0x140f6c930
// MS2-FUNCTIONAL: equivalent packet decoding and localized errors; formatter and temporary layout differ.
void ItemSocketSystemPageBase::vfunc_8(CInPacket* packet)
{
    unsigned operation = packet->vfunc_o8_1();
    Unk_SocketPageResult result = static_cast<Unk_SocketPageResult>(packet->vfunc_o8_3());
    int code = static_cast<int>(result);
    if (code < 5 || code > 12) {
        CStringW key;
        switch (code) {
        case 1: key = L"s_itemsocketsystem_error_invalid_target"; break;
        case 2: key = L"s_itemsocketsystem_error_invalid_target_gemstone"; break;
        case 3: key = L"s_itemsocketsystem_error_invalid_target_ingredient"; break;
        case 4: key = L"s_itemsocketsystem_error_invalid_target_ingredient_count"; break;
        case 15: key = L"s_itemsocketsystem_error_socket_lock"; break;
        case 16: key = L"s_itemsocketsystem_error_socket_used"; break;
        case 17: key = L"s_itemsocketsystem_error_socket_empty"; break;
        case 18: key = L"s_itemsocketsystem_error_socket_unlock_all"; break;
        case 20: key = L"s_itemsocketsystem_error_gemstone_maxlevel"; break;
        case 21: key = L"s_itemsocketsystem_error_lack_price"; break;
        case 22: break;
        case 23: key = L"s_itemsocketsystem_error_bind_owner"; break;
        default:
            FUN_1412751f0(FUN_14028dfa0(CStringW(L"s_itemsocketsystem_error_server_default"), operation, result), 1, 1);
            break;
        }
        if (!key.IsEmpty())
            FUN_1412752d0(key, 1);
    } else {
        FUN_140d73aa0(FUN_14028dfa0(CStringW(L"s_itemsocketsystem_error_server_default_msgbox"), operation, result), 0, 0, CStringW(L""));
    }
}

// @0x140f6cce0
// MS2-FUNCTIONAL: smart-pointer return and exception-cleanup layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6cce0(int itemId, int grade)
{
    MS2Ptr<CItem> item(new CItem);
    if (item.get() != 0) {
        if (item->FUN_140523c40(itemId, grade, 0))
            return item;
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6ce00
// MS2-FUNCTIONAL: smart-pointer return and local temporary layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6ce00(int itemId, int grade, bool bindOwner, MS2Ptr<CItem> source)
{
    if (grade == 0)
        grade = FUN_14053feb0(itemId);
    MS2Ptr<CItem> item(new CItem);
    if (item.get() != 0) {
        if (item->FUN_14052b130(itemId, grade, 0) != 0) {
            item->FUN_14052b340(1);
            if (bindOwner)
                item->FUN_140526a70(FUN_14028d0e0());
            if (source.get() != 0) {
                unsigned value = source->FUN_1405273a0();
                item->FUN_1405273f0(value);
                __int64 option = source->FUN_140528e00();
                unsigned type = source->FUN_140528ca0();
                item->FUN_14052b710(&type, &option);
            }
            return item;
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d050
// MS2-FUNCTIONAL: typed gemstone binding and lock copies preserve behavior; cleanup layout differs.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d050(MS2Ptr<TSocketGemStoneInfo> info, int grade, bool bindOwner)
{
    if (!(info == 0) && info->m_nGemId != 0) {
        MS2Ptr<CItem> item = FUN_140f6ce00(info->m_nGemId, grade, bindOwner, MS2Ptr<CItem>(0));
        if (item.get() != 0) {
            {
                MS2Ptr<TSocketGemStoneBind> binding(info->m_spBind);
                if (binding.get() != 0)
                    item->FUN_14052b5e0(&binding->m_nCharacterId, &binding->m_strName);
            }
            {
                MS2Ptr<TSocketGemStoneLock> lock(info->m_spLock);
                if (lock.get() != 0)
                    item->FUN_14052b710(reinterpret_cast<unsigned*>(&lock->m_nState), &lock->m_nExpireTime);
            }
            return item;
        }
        return MS2Ptr<CItem>(0);
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d300
// MS2-FUNCTIONAL: equivalent null-slot return control flow.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d300(const CString& name)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    return slot;
}

// @0x140f6d340
// MS2-FUNCTIONAL: equivalent null-slot return control flow and item cleanup.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d340(const CString& name, MS2Ptr<CItem> item)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    FUN_141415af0(slot, item);
    slot->vfunc_10();
    return slot;
}

// @0x140f6d400
// MS2-FUNCTIONAL: equivalent null-slot return control flow.
ItemInfoSlot* ItemSocketSystemPageBase::FUN_140f6d400(const CString& name)
{
    ItemInfoSlot* slot = FUN_140f6e830(name);
    if (slot == 0)
        return 0;
    slot->vfunc_10();
    return slot;
}

// @0x140f6d450
// MS2-FUNCTIONAL: typed callback and container-count temporaries differ.
void ItemSocketSystemPageBase::FUN_140f6d450(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, int icon, int flags)
{
    FUN_14141f970(name);
    FUN_14141f770(name, static_cast<int>(items.GetCount()), &items, FUN_141420330, icon, flags);
}

// @0x140f6d4c0
// MS2-FUNCTIONAL: typed callback and smart-pointer cleanup temporaries differ.
void ItemSocketSystemPageBase::FUN_140f6d4c0(const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<ItemSlotBag::CreateParam> param)
{
    FUN_14141f970(name);
    if (param.get() != 0 && param->m_pfnGetItem == 0)
        param->m_pfnGetItem = FUN_141420330;
    FUN_14141f860(name, static_cast<int>(items.GetCount()), &items, param);
}

// @0x140f6d590
void ItemSocketSystemPageBase::FUN_140f6d590(const CString& name, MS2Ptr<CItem> item, int icon, int flags)
{
    FUN_141415600(name);
    FUN_141415450(name, item, 0, icon, flags);
}

// @0x140f6d620
void ItemSocketSystemPageBase::FUN_140f6d620(int enabled)
{
    FUN_1412761e0(MS2Ptr<AScript>(m_root), enabled);
}

// @0x140f6d670
int ItemSocketSystemPageBase::FUN_140f6d670()
{
    if (!FUN_14036d570(FUN_140166410(), 46))
        return 7;
    return 6;
}

// @0x140f6d6b0
// MS2-FUNCTIONAL: equivalent UID search; return and cleanup layout differ.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d6b0(__int64 uid, CAtlArray<MS2Ptr<CItem>>& items, int* index)
{
    *index = -1;
    if (uid == 0)
        return MS2Ptr<CItem>(0);
    if (items.IsEmpty() == true)
        return MS2Ptr<CItem>(0);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            if (item->FUN_140526a50() == uid) {
                *index = static_cast<int>(i);
                return item;
            }
        }
    }
    return MS2Ptr<CItem>(0);
}

// @0x140f6d840
// MS2-FUNCTIONAL: equivalent checked item lookup; return layout differs.
MS2Ptr<CItem> ItemSocketSystemPageBase::FUN_140f6d840(CAtlArray<MS2Ptr<CItem>>& items, unsigned index)
{
    if (!items.IsEmpty() && index < items.GetCount())
        return items.GetAt(index);
    return MS2Ptr<CItem>(0);
}

// @0x140f6d8f0
void ItemSocketSystemPageBase::FUN_140f6d8f0(CAtlArray<MS2Ptr<CItem>>& items, int first, int second)
{
    MS2Ptr<CItem> firstItem(items.GetAt(first));
    MS2Ptr<CItem> secondItem(items.GetAt(second));
    items.SetAt(second, firstItem);
    items.SetAt(first, secondItem);
}

// @0x140f6d9a0
// MS2-FUNCTIONAL: typed list erase and bag refresh preserve calls and branches.
bool ItemSocketSystemPageBase::FUN_140f6d9a0(int index, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control)
{
    if (index >= 0 && index < static_cast<int>(items.GetCount())) {
        items.RemoveAt(index, 1);
        int count = static_cast<int>(items.GetCount());
        DragSlotBag* bag = FUN_140c54570(name);
        if (bag == 0)
            return false;
        ItemSlotBag* itemBag = dynamic_cast<ItemSlotBag*>(bag);
        if (itemBag == 0) {
            FUN_1422cc9e0(bag);
            bag->vfunc_10(count);
        } else {
            FUN_14141ff80(itemBag, count);
        }
        if (control.get() != 0)
            FUN_1422cf860(control.operator->());
        return true;
    }
    return false;
}

// @0x140f6db00
// MS2-FUNCTIONAL: typed append and bag refresh; local cleanup layout differs.
bool ItemSocketSystemPageBase::FUN_140f6db00(MS2Ptr<CItem> item, const CString& name, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<Unk_SocketPageBag> control)
{
    DragSlotBag* bag = FUN_140c54570(name);
    if (bag != 0) {
        int index = static_cast<int>(items.GetCount());
        items.Add(item);
        FUN_1422ccb50(bag, index);
        FUN_1422cf7e0(control.operator->(), index);
        bag->vfunc_14(index);
    }
    return bag != 0;
}

// @0x140f6dbe0
// MS2-FUNCTIONAL: equivalent selected-index reset; unused result local omitted.
void ItemSocketSystemPageBase::FUN_140f6dbe0(MS2Ptr<Unk_SocketPageBag> control)
{
    if (control.get() != 0) {
        // The original queries the selected index for its side effects before clearing it.
        FUN_1422dd150(control.operator->());
        FUN_1422dcca0(control.operator->(), -1);
        control->vfunc_24(false);
    }
}

// @0x140f6dc70
// MS2-FUNCTIONAL: typed ingredient list and Scaleform data construction; local/cleanup layout differs.
void ItemSocketSystemPageBase::FUN_140f6dc70(const CString& name, CIngredientContainer& ingredients, ASObj& data, CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale)
{
    *price = 0;
    Unk_IngVec* entries = ingredients.FUN_14026c230();
    size_t count = entries->FUN_14028b500();
    for (size_t i = 0; i < count; ++i) {
        Unk_IngRef ingredient(*entries->FUN_14028a0f0(i));
        if (!(ingredient == 0)) {
            if (!ingredient->FUN_14026b350()) {
                int itemId = ingredient->FUN_14026b500();
                int grade = FUN_14053feb0(itemId);
                int amount = ingredient->m_c;
                MS2Ptr<CItem> item(new CItem);
                if (item->FUN_14052b2e0(itemId, grade, 0, amount) != 0)
                    items.Add(item);
            }
        }
    }
    FUN_14141f770(name, static_cast<int>(count), &items, FUN_141420330, 0x405, FUN_140f6e6e0());
    int rate = 0;
    int enabled = 0;
    if (sale.get() != 0) {
        rate = sale->rate;
        enabled = sale->enabled;
    }
    ASArray rows(2);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            CString binding = FUN_1422cc860(name, static_cast<int>(i));
            ASObj row(2);
            row.FUN_1407cba60("binding", binding);
            unsigned owned = FUN_140f6e580(item, excluded);
            unsigned needed = item->FUN_140526c50();
            if (enabled != 0)
                needed = FUN_140627b80(needed, rate);
            row.FUN_1407cbb20("countText", FUN_1419021b0(owned, needed));
            rows.FUN_1422bc050(row.FUN_1422bb870());
            if (owned < needed) {
                if (item->FUN_140526320() != 0)
                    *price += static_cast<unsigned __int64>((needed - owned) * 1000);
            }
        }
    }
    data.FUN_1409adbe0("ingredient", rows.FUN_1422bb870());
}

// @0x140f6e250
// MS2-FUNCTIONAL: equivalent slot-count and ingredient-price calculation with typed temporaries.
void ItemSocketSystemPageBase::FUN_140f6e250(const CString& name, const CAtlArray<MS2Ptr<CItem>>& items, MS2Ptr<CItem> excluded, __int64* price, MS2Ptr<SaleParam> sale)
{
    *price = 0;
    int rate = 0;
    int enabled = 0;
    if (sale.get() != 0) {
        rate = sale->rate;
        enabled = sale->enabled;
    }
    size_t count = items.GetCount();
    for (size_t i = 0; i < count; ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!(item == 0)) {
            CString slotName = FUN_1422cc860(name, static_cast<int>(i));
            ItemInfoSlot* slot = FUN_140f6d300(slotName);
            if (slot == 0)
                continue;
            int owned = FUN_140f6e580(item, excluded);
            int needed = item->FUN_140526c50();
            if (enabled != 0)
                needed = FUN_140627b80(needed, rate);
            FUN_141416740(slot, owned, needed);
            if (owned < needed) {
                if (item->FUN_140526320() != 0)
                    *price += static_cast<__int64>((needed - owned) * 1000);
            }
        }
    }
}

// @0x140f6e500
// MS2-FUNCTIONAL: Scaleform return-value temporary layout differs.
void ItemSocketSystemPageBase::FUN_140f6e500(int index, bool isNew)
{
    if (!(m_root == 0))
        FUN_140f356e0(m_root.operator->(), "setNew", index, isNew);
}

// @0x140f6e580
// MS2-FUNCTIONAL: inventory count uses typed external declarations; cleanup layout differs.
int ItemSocketSystemPageBase::FUN_140f6e580(MS2Ptr<CItem> item, MS2Ptr<CItem> excluded)
{
    if (!(item == 0)) {
        if (item->FUN_140527840() != 0) {
            if (excluded.get() != 0)
                excluded->FUN_1405269d0(1);
            int count = FUN_140a5f180(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), item->FUN_1405276c0(), item->FUN_140526bd0());
            int group = FUN_14053c6f0(item->FUN_140527840());
            if (group != 0)
                count = FUN_140a5f780(reinterpret_cast<Unk_SocketPageInventoryCount*>(&DAT_143ab2a90), group, 0);
            if (excluded.get() != 0)
                excluded->FUN_1405269d0(0);
            return count;
        }
    }
    return 0;
}

// @0x140f6e6e0
int ItemSocketSystemPageBase::FUN_140f6e6e0() { return 0x2020; }

// @0x140f6e700
// MS2-FUNCTIONAL: smart-pointer initialization temporary layout differs.
void ItemSocketSystemPageBase::FUN_140f6e700(__int64 uid)
{
    Unk_SocketPagePlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0) {
        bool restore = false;
        MS2Ptr<CItem> item = FUN_141425750(uid, &restore);
        if (restore == true)
            FUN_140f6e780();
    }
}

// @0x140f6e780
void ItemSocketSystemPageBase::FUN_140f6e780() { m_restoreInventory = true; }

// @0x140f6e830
ItemInfoSlot* FUN_140f6e830(const CString& name)
{
    return FUN_140c69ab0(FUN_1422c8e90(name));
}

// @0x140f7b1f0
ItemSocketSystemPageBase::SaleParam::SaleParam() : enabled(0), value1c(0), rate(0), value24(7) {}
