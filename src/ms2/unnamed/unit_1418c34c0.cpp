// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item proxy summary extraction.
// MS2-UNIT: unit_1418c34c0
// MS2-RANGE: 0x1418c34c0-0x1418c3630 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"

struct Unk_ItemProxySummary
{
    int m_itemId;
    int m_values[3];
    void* m_itemUid;
};
MS2_CHECK_SIZE(Unk_ItemProxySummary, 0x18);

extern void* FUN_14052cd70(void*);
extern void* FUN_1401c0180(void*);
extern int FUN_1405276c0(void*);
extern void* FUN_140526a50(void*);
extern void* FUN_140527870(void*);
extern int FUN_140599fd0(void*, int);
extern void FUN_1401bfde0(void*);
void FUN_1418c35d0(Unk_ItemProxySummary*);

// @0x1418c34c0
void FUN_1418c34c0(Unk_ItemProxySummary* result, void* node)
{
    void* item = FUN_14052cd70(node);
    if (item == nullptr) {
        FUN_1418c35d0(result);
    } else {
        result->m_itemId = FUN_1405276c0(FUN_1401c0180(item));
        result->m_itemUid = FUN_140526a50(FUN_1401c0180(item));
        void* proxy = FUN_140527870(FUN_1401c0180(item));
        if (proxy == nullptr) {
            for (int i = 0; i < 3; ++i)
                result->m_values[i] = 0;
        } else {
            for (int i = 0; i < 3; ++i)
                result->m_values[i] = FUN_140599fd0(proxy, i);
        }
    }
    FUN_1401bfde0(node);
}

// @0x1418c35d0
void FUN_1418c35d0(Unk_ItemProxySummary* result)
{
    result->m_itemId = 0;
    result->m_itemUid = nullptr;
    for (int i = 0; i < 3; ++i)
        result->m_values[i] = 0;
}
