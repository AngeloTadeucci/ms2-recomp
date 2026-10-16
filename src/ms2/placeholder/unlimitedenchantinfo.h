// unlimitedenchantinfo.h - UnlimitedEnchantInfo (RTTI name), the third record of CItemStatus (+0x38): the unlimited
// (plus) enchantment of an item. 0x48 bytes, base CPtred, ctor 0x1408bb9d0 (its unit is not recovered); only the
// members the CItemStatus unit calls are declared. Member names are by address.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/itemenchantinfo.h"
class COutputStream;
class CInputStream;
class UnlimitedEnchantInfo : public CPtred
{
public:
    UnlimitedEnchantInfo(int nItemId, int nRarity);                 // 0x1408bb9d0
    MS2Ptr<UnlimitedEnchantInfo> FUN_1408bba60();                   // 0x1408bba60 copy
    void FUN_1408bbd30(COutputStream& out);                         // 0x1408bbd30 write
    void FUN_1408bbef0(CInputStream& in);                           // 0x1408bbef0 read
    Unk_EnchantPtr<BaseOption> FUN_1408bc210(unsigned nType);       // 0x1408bc210 the option of a stat type
    Unk_EnchantPtr<BaseOption> FUN_1408bc2f0(unsigned nType);       // 0x1408bc2f0
private:
    MS2_LAYOUT_FRIEND;
    char m_unk[0x30];
};
MS2_CHECK_SIZE(UnlimitedEnchantInfo, 0x48);
