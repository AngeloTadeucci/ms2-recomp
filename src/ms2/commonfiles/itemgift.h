// Recovered item gift types. Field names inferred; class/base names from RTTI.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
struct Unk_GiftOutput { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(unsigned int); void FUN_14070f9a0(unsigned int); };
struct Unk_GiftInput { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual unsigned int vfunc_3(); void FUN_14070f480(unsigned int&); };
struct ItemAble {
    virtual unsigned int vfunc_o18_0() = 0;
    virtual int vfunc_o18_1() = 0;
    virtual unsigned int vfunc_o18_2() = 0;
    virtual bool vfunc_o18_3() = 0;
};
struct ItemEntity : CPtred, ItemAble {
    ItemEntity();
    virtual ~ItemEntity();
    virtual void vfunc_1(CStringW);
    virtual void vfunc_2(void*);
    virtual unsigned int vfunc_o18_0();
    virtual int vfunc_o18_1();
    virtual unsigned int vfunc_o18_2();
    virtual bool vfunc_o18_3();
    void FUN_14026b030(Unk_GiftOutput&);
    void FUN_14026b100(Unk_GiftInput&);
    unsigned int m_itemId;
    unsigned int m_count;
    bool m_28,m_29,m_2a,m_2b;
    int m_rank;
};
struct ItemGift : ItemEntity {
    ItemGift();
    virtual ~ItemGift(); // Existing shared destructor, outside this unit's function map.
    virtual int vfunc_3(CString&);
    virtual int vfunc_o18_1();
};
struct ItemGiftPcBang : ItemGift {
    ItemGiftPcBang();
    virtual void vfunc_4(void*);
    virtual void vfunc_5(Unk_GiftOutput&);
    virtual void vfunc_6(Unk_GiftInput&);
    unsigned int m_giftId;
};
struct PlayBonusItemGift : ItemGiftPcBang {
    PlayBonusItemGift();
    virtual void vfunc_4(void*);
    virtual void vfunc_5(Unk_GiftOutput&);
    virtual void vfunc_6(Unk_GiftInput&);
    unsigned int GetHours();
    unsigned int GetMinutes();
    unsigned int m_requiredTime;
    unsigned int m_3c;
    unsigned int m_systemMailId;
};
MS2_CHECK_SIZE(ItemAble,8);
MS2_CHECK_SIZE(ItemEntity,0x30);
MS2_CHECK_OFFSET(ItemEntity,m_itemId,0x20);
MS2_CHECK_OFFSET(ItemEntity,m_count,0x24);
MS2_CHECK_SIZE(ItemGift,0x30);
MS2_CHECK_SIZE(ItemGiftPcBang,0x38);
MS2_CHECK_OFFSET(ItemGiftPcBang,m_giftId,0x30);
MS2_CHECK_SIZE(PlayBonusItemGift,0x48);
MS2_CHECK_OFFSET(PlayBonusItemGift,m_requiredTime,0x38);
MS2_CHECK_OFFSET(PlayBonusItemGift,m_systemMailId,0x40);
