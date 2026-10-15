// cmailtypes.h - PLACEHOLDER for the mail object classes defined in ?\mailattachitem.cpp (0x14068f630-0x140693e60):
// CMailAttachItem, CMailSendKeep and CMailInfo (RTTI names), all CPtred-derived. Only the layout pieces and the
// out-of-line members that commonfiles\usermail.cpp touches are declared; the bodies live in the exe. Member names
// are FUN_<va>. NOT original headers.
//   CMailAttachItem 0x40: +0x18 ptr, +0x20 int, +0x28 ptr, +0x30 MS2Ptr<CItem>      (ctor 0x14068f630 (int, MS2Ptr<CItem>))
//   CMailSendKeep   0x40: +0x18 int kind, +0x20 attach pointer, +0x30 MS2Ptr<CItem>  (ctors 0x14068fce0 / 0x14068fc30)
//   CMailInfo      0x138: id +0x18, kind +0x20, the strings/arrays up to +0x138      (ctor 0x14068ff50 (int))
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CMailAttachItem;

// Attachment-list pointer (member +0x20 of CMailSendKeep, element of CMailInfo's +0x70 array). Same 16-byte shape as
// MS2Ptr<T>; the copy/ctor/dtor/assign bodies are in mailattachitem.cpp. Only operator=(T*) is inline: its COMDAT
// (0x1408e4f40) is in usermail.cpp.
class Unk_MailAttachPtr {
public:
    Unk_MailAttachPtr(int);                                   // 0x140692990
    Unk_MailAttachPtr(CMailAttachItem*);                      // 0x1406929b0
    Unk_MailAttachPtr(const Unk_MailAttachPtr&);              // 0x140692950
    ~Unk_MailAttachPtr();                                     // 0x140692bc0
    Unk_MailAttachPtr& operator=(const Unk_MailAttachPtr&);   // 0x140692d40
    Unk_MailAttachPtr& operator=(CMailAttachItem* value) {
        Unk_MailAttachPtr temp(value);
        CMailAttachItem* old = p;
        p = temp.p;
        temp.p = old;
        return *this;
    }
private:
    friend class CMailSendKeep;
    void* pad_00; CMailAttachItem* p;
};
MS2_CHECK_SIZE(Unk_MailAttachPtr, 0x10);

class CMailAttachItem : public CPtred {
public:
    CMailAttachItem(int index, MS2Ptr<CItem> item);           // 0x14068f630
    virtual ~CMailAttachItem();
    MS2_LAYOUT_FRIEND;
    void* m_pad_18; int m_pad_20; int m_pad_24; void* m_pad_28;
    MS2Ptr<CItem> m_item;                                      // +0x30
};
MS2_CHECK_SIZE(CMailAttachItem, 0x40);
MS2_CHECK_OFFSET(CMailAttachItem, m_item, 0x30);

class CMailSendKeep : public CPtred {
public:
    CMailSendKeep(MS2Ptr<CItem> item);                         // 0x14068fc30 (kind 1)
    CMailSendKeep(Unk_MailAttachPtr attach);                   // 0x14068fce0 (kind 0)
    virtual ~CMailSendKeep();
    __int64 FUN_14068fe20(int slot);
    MS2_LAYOUT_FRIEND;
    int m_kind; int m_pad_1c;                                  // +0x18
    Unk_MailAttachPtr m_attach;                                // +0x20
    MS2Ptr<CItem> m_item;                                      // +0x30
};
MS2_CHECK_SIZE(CMailSendKeep, 0x40);
MS2_CHECK_OFFSET(CMailSendKeep, m_kind, 0x18);
MS2_CHECK_OFFSET(CMailSendKeep, m_attach, 0x20);
MS2_CHECK_OFFSET(CMailSendKeep, m_item, 0x30);

class CMailInfo : public CPtred {
public:
    CMailInfo(int kind);                                       // 0x14068ff50
    virtual ~CMailInfo();
    void FUN_140690330(__int64 id);
    __int64 FUN_140690350();
    int FUN_140690370();
    void FUN_140690390(__int64 value, CStringW text);
    void FUN_140690460(__int64 value);
    void FUN_140690540(CStringW a, CStringW b);
    void FUN_140690650(int slot, Unk_MailAttachPtr attach);
    void FUN_140690d20(__int64 a, __int64 b);
    void FUN_1406910e0(__int64 value);
    bool FUN_140691130();
    int FUN_140691220();
    MS2_LAYOUT_FRIEND;
    void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38; void* m_pad_40;
    void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68; void* m_pad_70;
    void* m_pad_78; void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0;
    void* m_pad_a8; void* m_pad_b0; void* m_pad_b8; void* m_pad_c0; void* m_pad_c8; void* m_pad_d0;
    void* m_pad_d8; void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8; void* m_pad_100;
    void* m_pad_108; void* m_pad_110; void* m_pad_118; void* m_pad_120; void* m_pad_128; void* m_pad_130;
};
MS2_CHECK_SIZE(CMailInfo, 0x138);
