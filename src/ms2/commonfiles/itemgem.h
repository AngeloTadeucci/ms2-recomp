// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: commonfiles\itemgem.h (name assumed from the
// unit path commonfiles\itemgem.cpp; the exe's other name for this unit was gembase.cpp).
//
// An item can carry one "gem": a CGemBase-derived effect record (transparency of equip slots, chat balloon / name tag
// skin, tomb stone / swim model, damage font, fishing, character effect, auto mastery, equip effect, pet skin, meta).
// CItemGem is the holder that serializes the gem (flag, type byte, gem id, then the gem's own payload) and forwards
// the apply / remove calls to it. The 12 gem types are created by CItemGem::FUN_1405a7020 from the type byte.
// Names: virtuals are vfunc_<slot>, non-virtual members are FUN_<va>; fields are invented.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CItem;
class COutputStream;
class CInputStream;
class PC;
class ClonePC;

// The gem tables' rows (other units: ?\itemgempropertytable.cpp / ?\itemgemstonedata.cpp). Only the RTTI base and the
// members the gems touch are declared here; the layouts behind the pads are not recovered.
class CGemDataBase : public CPtred
{
public:
    virtual ~CGemDataBase();                                        //  0 0x1405af840 (??_G)
    char m_pad_18[8];
};
MS2_CHECK_SIZE(CGemDataBase, 0x20);

// A sub-record of the tomb stone data (RTTI CGemTombStoneData::TModelAttr): reset by FUN_1405ac670.
struct Unk_GemModelAttr
{
    void FUN_1405ac670();                                           // 0x1405ac670
    char m_pad[0x40];
};

class CGemTombStoneData : public CGemDataBase
{
public:
    char m_pad_20[0x10];
    Unk_GemModelAttr m_attrA;                                       // +0x30
    Unk_GemModelAttr m_attrB;                                       // +0x70
};

class CGemSwimData : public CGemDataBase
{
public:
    void FUN_1405ac9e0();                                           // 0x1405ac9e0
};

class CGemCharEffectData : public CGemDataBase
{
public:
    CString FUN_1405acbd0(int nPartnerGem);                         // 0x1405acbd0 the effect name of the partner gem
};

class CGemEffectData : public CGemDataBase
{
public:
    CString m_strEffect;                                            // +0x20 the equip effect name
};

// The gem table: FUN_1405ac160 looks a gem row up by id.
class Unk_GemTable
{
public:
    MS2Ptr<CGemDataBase> FUN_1405ac160(int nGemId);                 // 0x1405ac160
};
Unk_GemTable* FUN_1405a96f0();                                      // 0x1405a96f0 the table singleton (DAT_143aafd08)

enum GemType
{
    GEM_TRANSPARENCY = 1,
    GEM_DAMAGEFONT = 2,
    GEM_CHATBALLOON = 3,
    GEM_NAMETAG = 4,
    GEM_TOMBSTONE = 5,
    GEM_SWIM = 6,
    GEM_CHAREFFECT = 7,
    GEM_FISHING = 8,
    GEM_AUTOMASTERY = 9,
    GEM_EFFECT = 10,
    GEM_PETSKIN = 11,
    GEM_META = 12,
};

// RTTI .?AVCGemBase@@, 0x20 bytes, vftable 0x142d62a28 (12 slots).
class CGemBase : public CPtred
{
public:
    CGemBase(int nType, int nGemId);                                // 0x1405a3940
    virtual ~CGemBase();                                            //  0 0x1405a39a0 (??_G 0x1405a8fa0)
    virtual int vfunc_1();                                          //  1 0x1405a39d0 the gem type
    int FUN_1405a39f0();                                            // 0x1405a39f0 the gem id
    virtual void vfunc_2(COutputStream& stream);                    //  2 0x1405a3a10 write the payload
    virtual void vfunc_3(CInputStream& stream);                     //  3 0x1405a3a30 read the payload
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a3a50 clone
    virtual int vfunc_5(PC* pPC, MS2Ptr<CItem> spItem);             //  5 0x1405a3a90
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a3ad0 apply
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a3b10 remove
    virtual void vfunc_8();                                         //  8 0x1405a3b50
    virtual int vfunc_9();                                          //  9 0x1405a3b60
    virtual CString vfunc_10();                                     // 10 0x1405a3b70
    virtual CStringW vfunc_11();                                    // 11 0x1405a3bc0

    int m_nType;                                                    // +0x18
    int m_nGemId;                                                   // +0x1c
};
MS2_CHECK_SIZE(CGemBase, 0x20);

// Transparency of up to 10 equip slots. vftable 0x142d62a90.
class CGemTransparency : public CGemBase
{
public:
    CGemTransparency(int nType, int nGemId);                        // 0x1405a3c10
    CGemTransparency(const CGemTransparency& o);                    // 0x1405a3e90
    virtual ~CGemTransparency();                                    //  0 0x1405a3ee0 (??_G 0x1405a9260)
    virtual int vfunc_1() { return 1; }                             //  1 0x1405a9aa0
    virtual void vfunc_2(COutputStream& stream);                    //  2 0x1405a3f10
    virtual void vfunc_3(CInputStream& stream);                     //  3 0x1405a3f90
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a4000
    virtual int vfunc_5(PC* pPC, MS2Ptr<CItem> spItem);             //  5 0x1405a4170
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a41f0
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a4520
    void FUN_1405a4100(int nSlot, int nHidden);                     // 0x1405a4100
    int FUN_1405a4140(int nSlot);                                   // 0x1405a4140

    int m_aHidden[10];                                              // +0x20 per slot: 1 = the slot is hidden
};
MS2_CHECK_SIZE(CGemTransparency, 0x48);

class CGemChatBalloon : public CGemBase
{
public:
    CGemChatBalloon(int nType, int nGemId);                         // 0x1405a4770
    CGemChatBalloon(const CGemChatBalloon& o);                      // 0x1405a47c0
    virtual ~CGemChatBalloon();                                     //  0 0x1405a4810 (??_G 0x1405a9020)
    virtual int vfunc_1() { return 3; }                             //  1 0x1405a9a70
    virtual void vfunc_2(COutputStream& stream);                    //  2 0x1405a4840
    virtual void vfunc_3(CInputStream& stream);                     //  3 0x1405a4870
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a48a0
    virtual int vfunc_5(PC* pPC, MS2Ptr<CItem> spItem);             //  5 0x1405a4950
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a49d0
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a4b60
};
MS2_CHECK_SIZE(CGemChatBalloon, 0x20);

class CGemNametag : public CGemBase
{
public:
    CGemNametag(int nType, int nGemId);                             // 0x1405a4cd0
    CGemNametag(const CGemNametag& o);                              // 0x1405a4d20
    virtual ~CGemNametag();                                         //  0 0x1405a4d70 (??_G 0x1405a9160)
    virtual int vfunc_1() { return 4; }                             //  1 0x1405a9a90
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a4da0
    virtual int vfunc_5(PC* pPC, MS2Ptr<CItem> spItem);             //  5 0x1405a4e50
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a4ed0
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a5060
};
MS2_CHECK_SIZE(CGemNametag, 0x20);

class CGemTombStone : public CGemBase
{
public:
    CGemTombStone(int nType, int nGemId);                           // 0x1405a51d0
    CGemTombStone(const CGemTombStone& o);                          // 0x1405a5240
    virtual ~CGemTombStone();                                       //  0 0x1405a52d0 (??_G 0x1405a9220)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a5310
    virtual void vfunc_8();                                         //  8 0x1405a54c0
    MS2Ptr<CGemTombStoneData> FUN_1405a53c0();                      // 0x1405a53c0 the data row (loaded on demand)

    int m_nDataId;                                                  // +0x20
    MS2Ptr<CGemTombStoneData> m_spData;                             // +0x28
};
MS2_CHECK_SIZE(CGemTombStone, 0x38);

class CGemSwim : public CGemBase
{
public:
    CGemSwim(int nType, int nGemId);                                // 0x1405a5530
    CGemSwim(const CGemSwim& o);                                    // 0x1405a55a0
    virtual ~CGemSwim();                                            //  0 0x1405a5630 (??_G 0x1405a91e0)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a5670
    virtual void vfunc_8();                                         //  8 0x1405a5820
    MS2Ptr<CGemSwimData> FUN_1405a5720();                           // 0x1405a5720 the data row (loaded on demand)

    int m_nDataId;                                                  // +0x20
    MS2Ptr<CGemSwimData> m_spData;                                  // +0x28
};
MS2_CHECK_SIZE(CGemSwim, 0x38);

class CGemDamageFont : public CGemBase
{
public:
    CGemDamageFont(int nType, int nGemId);                          // 0x1405a5870
    CGemDamageFont(const CGemDamageFont& o);                        // 0x1405a58c0
    virtual ~CGemDamageFont();                                      //  0 0x1405a5910 (??_G 0x1405a9060)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a5940
    virtual void vfunc_8();                                         //  8 0x1405a59f0
};
MS2_CHECK_SIZE(CGemDamageFont, 0x20);

class CGemFishing : public CGemBase
{
public:
    CGemFishing(int nType, int nGemId);                             // 0x1405a5a50
    CGemFishing(const CGemFishing& o);                              // 0x1405a5aa0
    virtual ~CGemFishing();                                         //  0 0x1405a5b00 (??_G 0x1405a90e0)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a5b30
    int FUN_1405a5be0();                                            // 0x1405a5be0 the data id

    int m_nDataId;                                                  // +0x20
};
MS2_CHECK_SIZE(CGemFishing, 0x28);

class CGemCharEffect : public CGemBase
{
public:
    CGemCharEffect(int nType, int nGemId);                          // 0x1405a5c00
    CGemCharEffect(const CGemCharEffect& o);                        // 0x1405a5c90
    virtual ~CGemCharEffect();                                      //  0 0x1405a5d20 (??_G 0x1405a8fe0)
    virtual int vfunc_1() { return 7; }                             //  1 0x1405a9a60
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a5d70
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a5e20
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a6080
    MS2Ptr<CGemCharEffectData> FUN_1405a61f0();                     // 0x1405a61f0 the data row (loaded on demand)

    int m_nDataId;                                                  // +0x20
    ATL::CAtlList<unsigned int> m_listEffects;                      // +0x28 the effects started on the actor
    MS2Ptr<CGemCharEffectData> m_spData;                            // +0x58
};
MS2_CHECK_SIZE(CGemCharEffect, 0x68);

class CGemAutoMastery : public CGemBase
{
public:
    CGemAutoMastery(int nType, int nGemId);                         // 0x1405a62f0
    CGemAutoMastery(const CGemAutoMastery& o);                      // 0x1405a6340
    virtual ~CGemAutoMastery();                                     //  0 0x1405a6390 (??_G 0x1405a8f60)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a63c0
};
MS2_CHECK_SIZE(CGemAutoMastery, 0x20);

class CGemEffect : public CGemBase
{
public:
    CGemEffect(int nType, int nGemId);                              // 0x1405a6470
    CGemEffect(const CGemEffect& o);                                // 0x1405a64e0
    virtual ~CGemEffect();                                          //  0 0x1405a6560 (??_G 0x1405a90a0)
    virtual int vfunc_1() { return 10; }                            //  1 0x1405a9a80
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a65a0
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a6650
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a67e0
    MS2Ptr<CGemEffectData> FUN_1405a68d0();                         // 0x1405a68d0 the data row (loaded on demand)

    int m_nDataId;                                                  // +0x20
    MS2Ptr<CGemEffectData> m_spData;                                // +0x28
};
MS2_CHECK_SIZE(CGemEffect, 0x38);

class CGemPetSkin : public CGemBase
{
public:
    CGemPetSkin(int nType, int nGemId);                             // 0x1405a69d0
    CGemPetSkin(const CGemPetSkin& o);                              // 0x1405a6a40
    virtual ~CGemPetSkin();                                         //  0 0x1405a6ab0 (??_G 0x1405a91a0)
    virtual void vfunc_2(COutputStream& stream);                    //  2 0x1405a6b90
    virtual void vfunc_3(CInputStream& stream);                     //  3 0x1405a6bd0
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a6ae0
    virtual int vfunc_9() { return 1; }                             //  9 0x1405a9b20
    virtual CString vfunc_10();                                     // 10 0x1405a6c10
    virtual CStringW vfunc_11();                                    // 11 0x1405a6d50

    int m_nDataId;                                                  // +0x20
    int m_nPetId;                                                   // +0x24
};
MS2_CHECK_SIZE(CGemPetSkin, 0x28);

class CGemMeta : public CGemBase
{
public:
    CGemMeta(int nType, int nGemId);                                // 0x1405a6db0
    CGemMeta(const CGemMeta& o);                                    // 0x1405a6e00
    virtual ~CGemMeta();                                            //  0 0x1405a6e50 (??_G 0x1405a9120)
    virtual MS2Ptr<CGemBase> vfunc_4();                             //  4 0x1405a6e80
    virtual void vfunc_8();                                         //  8 0x1405a6f30
};
MS2_CHECK_SIZE(CGemMeta, 0x20);

// RTTI .?AVCItemGem@@, 0x28 bytes, vftable 0x142d62f70 (9 slots): the gem an item carries.
class CItemGem : public CPtred
{
public:
    CItemGem();                                                     // 0x1405a6f90
    virtual ~CItemGem();                                            //  0 0x1405a6fe0 (??_G 0x1405a92a0)
    virtual int vfunc_1();                                          //  1 0x1405a7680 the gem type, 0 without a gem
    virtual MS2Ptr<CItemGem> vfunc_2();                             //  2 0x1405a76e0 clone
    virtual void vfunc_3(COutputStream& stream);                    //  3 0x1405a7810 write
    virtual void vfunc_4(CInputStream& stream);                     //  4 0x1405a7920 read
    virtual int vfunc_5(PC* pPC, MS2Ptr<CItem> spItem);             //  5 0x1405a79d0
    virtual int vfunc_6(PC* pPC, MS2Ptr<CItem> spItem);             //  6 0x1405a7a90 apply
    virtual int vfunc_7(PC* pPC, MS2Ptr<CItem> spItem);             //  7 0x1405a7b50 remove
    virtual void vfunc_8();                                         //  8 0x1405a7c10
    void FUN_1405aa540(MS2Ptr<CGemBase> spGem);                     // 0x1405aa540 take over a gem
    bool FUN_1405a7020(int nType, int nGemId);                      // 0x1405a7020 create the gem of a type
    int FUN_1405a7c60();                                            // 0x1405a7c60
    CString FUN_1405a7cc0();                                        // 0x1405a7cc0
    CStringW FUN_1405a7d60();                                       // 0x1405a7d60
    MS2Ptr<CGemBase> FUN_140d41400();                               // 0x140d41400 the gem (copy of +0x18)

    MS2Ptr<CGemBase> m_spGem;                                       // +0x18
};
MS2_CHECK_SIZE(CItemGem, 0x28);
