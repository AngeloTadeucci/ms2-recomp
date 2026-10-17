// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item socket UI page family.
// MS2-UNIT: unit_140f6c680
// MS2-RANGE: 0x140f6c680-0x140f7d060 .text$mn
// MS2-RANGE: 0x1400e04c0-0x1400e09d0 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagebase.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagebase.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/ms2format.h"

// The result is formatted through fmt's enum customization, rather than an integer argument.
enum class Unk_SocketPageResult : int {};
CStringW FUN_14028dfa0(CStringW key, const fmt::ArgList& args);
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
