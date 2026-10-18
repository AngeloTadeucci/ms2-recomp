// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Avatar item helpers (the file after unit_141420f10's):
// the uid of the item equipped in an avatar slot, the equipped-item handle of a slot, the "can these two worn items be
// combined" test, and the "item has any of the five costume flags" test.
// MS2-UNIT: unit_1414210f0
// MS2-RANGE: 0x1414210f0-0x141421740 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\avatarcustomize.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/pcinfo.h"

class AvatarPC;
class Unk_AvPlayers;

// 16-byte equipped-item handle (the slot's item pointer at +8).
class Unk_AvatarItemHandle
{
public:
    void* m_pad;                                     // +0
    void* m_p;                                       // +8
};
MS2_CHECK_SIZE(Unk_AvatarItemHandle, 0x10);

class Unk_AvPlayers { public: AvatarPC* FUN_141bd0cc0(); };
Unk_AvPlayers* FUN_1403ed2d0();
void* FUN_1414211a0(void* pOut, int nSlot, AvatarPC* pAvatar);
void FUN_141655e10(AvatarPC* pAvatar, void* pOut, int nSlot, int nUnknown, int nZero);   // the slot's handle
void FUN_1411f6690(void* pHandle, int nNull);                    // a null handle

// Unrecovered callees shared with unit_141420f10 (opaque 16-byte handle helpers).
void* FUN_1411dc7a0(void* pEquip, void* pOut);                    // 0x1411dc7a0 CEquipItem::FUN_1411dc7a0 (returns pOut)
void* FUN_1401c0180(void* pSp);                                   // 0x1401c0180 operator-> of that smart pointer
void FUN_1401bfde0(void* pHandle);                                // 0x1401bfde0 release a copied handle
void* FUN_1405a8e70(void* pHandle);                               // 0x1405a8e70 handle.get
void* FUN_1405a8ed0(void* pHandle);                               // 0x1405a8ed0 handle.get
void FUN_1405a85f0(void* pHandle);                                // 0x1405a85f0 release
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);    // pop the system message nTable

// @0x1414210f0
// MS2-FUNCTIONAL: first-pass source; frame layout and temp order not byte-compared.
__int64 FUN_1414210f0(int nSlot, AvatarPC* pAvatar)
{
    Unk_AvatarItemHandle handle;
    FUN_1414211a0(&handle, nSlot, pAvatar);
    if (FUN_1405a8e70(&handle) == 0)
    {
        FUN_1405a85f0(&handle);
        return 0;
    }
    Unk_AvatarItemHandle copy;
    void* pCopy = FUN_1411dc7a0(FUN_1405a8ed0(&handle), &copy);
    CItem* pItem = reinterpret_cast<CItem*>(FUN_1401c0180(pCopy));
    __int64 nUid = pItem->FUN_140526a50();
    FUN_1401bfde0(&copy);
    FUN_1405a85f0(&handle);
    return nUid;
}

// MS2-FUNCTIONAL: the exe returns the handle by value (NRVO flag, ctor 0x1411f6690); kept as an out pointer.
// @0x1414211a0
void* FUN_1414211a0(void* pOut, int nSlot, AvatarPC* pAvatar)
{
    int nUnknown = 0;
    if (pAvatar == 0)
    {
        pAvatar = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pAvatar == 0)
        {
            FUN_1411f6690(pOut, 0);
            return pOut;
        }
    }
    FUN_141655e10(pAvatar, pOut, nSlot, nUnknown, 0);
    return pOut;
}

// @0x141421230
// MS2-FUNCTIONAL: first-pass source; the exe's per-exit release order / temp frame not byte-compared.
int FUN_141421230(MS2Ptr<CItem> spFirst, MS2Ptr<CItem> spSecond, MS2Ptr<PCInfo> spPc)
{
    if (!(spFirst == 0))
    {
        CItemData* pData = reinterpret_cast<CItemData*>(spFirst->FUN_140527840());
        if (!pData->FUN_14053d510())
            return 0;
        MS2Ptr<CItem> spHead = spPc->FUN_140dba790(static_cast<Unk_InventoryEquipSlot>(4));
        MS2Ptr<CItem> spBody = spPc->FUN_140dba790(static_cast<Unk_InventoryEquipSlot>(5));
        if (spHead.get() == 0 || spBody.get() == 0)
        {
            if (!(spHead == 0) || !(spBody == 0))
            {
                FUN_140d73bc0(0xd5, 0, 0, CStringW(L""));
                return 0;
            }
            if (!(spSecond == 0))
            {
                CItemData* pOther = reinterpret_cast<CItemData*>(spSecond->FUN_140527840());
                if (!pOther->FUN_14053d510())
                    return 0;
            }
        }
        else
        {
            CItemData* pHeadData = reinterpret_cast<CItemData*>(spHead->FUN_140527840());
            if (!pHeadData->FUN_14053d510())
                return 0;
            CItemData* pBodyData = reinterpret_cast<CItemData*>(spBody->FUN_140527840());
            if (!pBodyData->FUN_14053d510())
                return 0;
            if (!(spSecond == 0))
            {
                CItemData* pOther = reinterpret_cast<CItemData*>(spSecond->FUN_140527840());
                if (!pOther->FUN_14053d510())
                    return 0;
            }
        }
        return 1;
    }
    return 0;
}

// MS2-FUNCTIONAL: branch layout of the null tests differs.
// @0x141421690
int FUN_141421690(CItem* pItem)
{
    int nResult;
    if (pItem == 0 || pItem->FUN_140527840() == 0)
    {
        nResult = 0;
    }
    else
    {
        CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
        if (!pData->FUN_14053cf00() && !pData->FUN_14053d0c0() && !pData->FUN_14053cfd0() && !pData->FUN_14053d020()
            && !pData->FUN_14053cf40())
            nResult = 0;
        else
            nResult = 1;
    }
    return nResult;
}
