// dropitem.h - PLACEHOLDER for client\ms2\dropitem.cpp's CDropItem (a field drop, GameObject-derived, 0x2a0 bytes;
// vftable 0x142eb89c8). NOT an original header: only what scenestategame.cpp's drop packet needs (w109).
#pragma once
#include <atlcoll.h>
#include "ms2/client/ms2/gameobject.h"

class CItem;

class CDropItem : public GameObject
{
public:
    CDropItem(int nType, int nRarity);                                      // 0x14118c730
    // init from the drop packet: object id, item id, amount, owner kind, owner id, owner character uids
    int FUN_14118d1c0(int nObjectId, int nItemId, int nAmount, int nA, int nB, const ATL::CAtlList<__int64>& kOwners);
    void FUN_14118fe60(int bValue);                                         // 0x14118fe60
    void FUN_14118fe80(int bValue);                                         // 0x14118fe80
    CItem* FUN_140b12380();                                                 // the dropped item (m_spItem at +0x1a0)

    char m_pad_140[0x2a0 - 0x140];
};
MS2_CHECK_SIZE(CDropItem, 0x2a0);
