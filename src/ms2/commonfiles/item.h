// item.h - the small CPtred-derived parts of an item (commonfiles\item.cpp): CItemTransfer::CItemBinding,
// CItemCoupleInfo and CItemCustomMusicScore. Header name assumed from the unit path; the CItem slots that hold them
// are declared in ms2/placeholder/citem.h. Member names are by offset.
#pragma once

#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/itemgem.h"
#include "ms2/placeholder/cubeiteminfo.h"

// Opaque parts defined in their own units; only the allocation sizes and constructors are known here.
// The option block behind CItemStatus +0x18 (alloc 0x2f8; its unit is not recovered): only the checks CItem makes.
class CItemOption : public CPtred
{
public:
    int FUN_1405cbbb0(int nSlot);               // 0x1405cbbb0
    int FUN_1405cbc90();                        // 0x1405cbc90
};
class CItemStatus : public CPtred
{
public:
    CItemStatus(unsigned, unsigned, unsigned);   // 0x14062fa00
    class CItemEnchantInfo* FUN_140630d60();     // the enchant record (null when absent)
    class Unk_ItemPlusInfo* FUN_140630d90();
    void FUN_1406306f0(int, int, int);
    MS2Ptr<CItemOption> m_spOption;             // +0x18
    char m_pad28[0x20];
};
MS2_CHECK_SIZE(CItemStatus, 0x48);
class CItemUgc : public CPtred
{
public:
    CItemUgc();                             // 0x140631d70
    CUgcItemLook m_look;                    // +0x18
    char m_pad80[0x58];
    int FUN_1406321a0();
    CString FUN_140632100();
};
MS2_CHECK_SIZE(CItemUgc, 0xd8);
class CItemSocket : public CPtred
{
public:
    CItemSocket();                          // 0x140620320
    bool FUN_140620de0();
    void FUN_140620840(unsigned, unsigned);
    char m_pad18[0xd8];
};
MS2_CHECK_SIZE(CItemSocket, 0xf0);
class Unk_UserProxyItemData : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(__int64);
    virtual void vfunc_6(CInputStream*);
};

// The music score's note block at +0x50 of CItemCustomMusicScore (ctor 0x14052c230, reset 0x14052d040).
struct Unk_MusicNoteBlock
{
    Unk_MusicNoteBlock();                   // 0x14052c230
    void FUN_14052d040();                   // reset all fields
    int m_n00;
    int m_pad04;
    __int64 m_n08;
    __int64 m_n10;
    CStringW m_str18;
};
MS2_CHECK_OFFSET(Unk_MusicNoteBlock, m_str18, 0x18);

// CItemTransfer::CItemBinding, 0x28 bytes (RTTI CItemTransfer::CItemBinding).
class CItemTransfer::CItemBinding : public CPtred
{
public:
    CItemBinding();                         // 0x14052c0f0
    virtual ~CItemBinding();                // 0x14052c4e0 (??_G 0x14052cf40)

    __int64 m_n18;                          // +0x18
    CStringW m_str20;                       // +0x20
    __int64 FUN_14052d1c0();                // m_n18
    const CStringW& FUN_14052d1b0();        // m_str20
    bool FUN_140634790(void*);              // elsewhere (itemtransfer)
};
MS2_CHECK_SIZE(CItemTransfer::CItemBinding, 0x28);

// CItemCoupleInfo, 0x30 bytes.
class CItemCoupleInfo : public CPtred
{
public:
    CItemCoupleInfo();                      // 0x14052c140
    virtual ~CItemCoupleInfo();             // 0x14052c510 (??_G 0x14052cf80)
    void FUN_14052d000();                   // reset
    CItemCoupleInfo& operator=(const CItemCoupleInfo&);   // 0x14052cae0

    __int64 m_n18;                          // +0x18
    CStringW m_str20;                       // +0x20
    unsigned char m_b28;                    // +0x28
};
MS2_CHECK_SIZE(CItemCoupleInfo, 0x30);

// CItemCustomMusicScore, 0x78 bytes. Its destructor is not in item.cpp.
class CItemCustomMusicScore : public CPtred
{
public:
    CItemCustomMusicScore();                // 0x14052c1a0
    bool FUN_140632780();
    virtual ~CItemCustomMusicScore();       // (??_G 0x14052cfc0)
    void FUN_1406328c0();                   // reset the score (elsewhere)

    int m_n18;                              // +0x18
    int m_n1c;                              // +0x1c a music book id
    CStringW m_str20;                       // +0x20
    CStringW m_str28;                       // +0x28
    CString m_str30;                        // +0x30
    int m_n38;                              // +0x38
    char m_pad3c[0x14];
    Unk_MusicNoteBlock m_note;              // +0x50
    char m_pad70[8];
};
MS2_CHECK_SIZE(CItemCustomMusicScore, 0x78);
