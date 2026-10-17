// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item socket UI page family.
// MS2-UNIT: unit_140f6c680
// MS2-RANGE: 0x140f6c680-0x140f7d060 .text$mn
// MS2-RANGE: 0x1400e04c0-0x1400e09d0 .text$di
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagebase.h"
#include "ms2/placeholder/ms2ptr_impl.h"

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
