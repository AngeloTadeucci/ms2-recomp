// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: commonfiles\mailtextutil.h (name assumed from the unit
// path commonfiles\mailtextutil.cpp; the exe holds its __FILE__ in the asserts).
//
// The text of a mail (a mail title and body made of values), as stored in a mail's text columns:
//  - MailTextValue (0x18): one value of kind 0 plain text ("str"), 1 string-table key ("key"), 2 item id ("item", resolved
//    to the item name), 3 money ("money"); m_auxiliary is the item's extra text.
//  - MailTextParagraph (0x38): a value with up to five child values; Resolve() feeds the children into the value as
//    {0}..{4} of a format string.
//  - MailText (0x40): code, number, the title value and the paragraphs; Resolve* builds the display text; Load* parse the
//    "<ms2><title/>...<body/>..</ms2>" xml the server stores.
// Layouts from the constructors; names invented from use (the v2525 snapshot's names for the same functions).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"

class MailTextValue
{
public:
    MailTextValue();                                                // 0x14065b160
    MailTextValue(int nKind, const CStringW& strValue, const CStringW& strAuxiliary);   // 0x14065b1d0
    bool Load(void* pElement);                                      // 0x14065b240
    CStringW Write(const CStringW& strTag);                         // 0x14065b560
    CStringW WriteChildren(const CStringW& strTag, const CStringW& strChildTag, const ATL::CAtlArray<MailTextValue>& children);   // 0x14065b6e0
    CStringW Resolve();                                             // 0x14065ba60
    int GetKind();                                                  // 0x14065bc20
    CStringW GetValue();                                            // 0x14065bc40
    static MailTextValue Text(const CStringW& strText);             // 0x14065bc90
    static MailTextValue Key(int nKey);                             // 0x14065bd20
    static MailTextValue Item(int nItem, const CStringW& strAuxiliary);   // 0x14065bdd0
    static MailTextValue Money(__int64 nMoney);                     // 0x14065be70

protected:
    int m_kind;                                                     // +0x00
    CStringW m_value;                                               // +0x08
    CStringW m_auxiliary;                                           // +0x10
};
MS2_CHECK_SIZE(MailTextValue, 0x18);

class MailTextParagraph
{
public:
    MailTextParagraph();                                            // 0x14065bf30
    MailTextParagraph(const MailTextParagraph& value);              // 0x14065bf70
    MailTextParagraph(const MailTextValue& value);                  // 0x14065bfe0
    MailTextParagraph(const MailTextValue& value, const MailTextValue& a);   // 0x14065c030
    MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b);   // 0x14065c0a0
    MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b, const MailTextValue& c);   // 0x14065c130
    MailTextParagraph(const MailTextValue& value, const MailTextValue& a, const MailTextValue& b, const MailTextValue& c, const MailTextValue& d);   // 0x14065c1d0
    MailTextParagraph& operator=(const MailTextParagraph& value);   // 0x14065c280
    void AddText(const CStringW& strText);                          // 0x14065c2d0
    void AddKey(int nKey);                                          // 0x14065c340
    void AddItem(int nItem, const CStringW& strAuxiliary);          // 0x14065c3a0
    bool Load(void* pRoot);                                         // 0x14065c410
    CStringW Write(const CStringW& strTag);                         // 0x14065c4d0
    CStringW Resolve();                                             // 0x14065c560
    bool IsPlain();                                                 // 0x14065cc10
    CStringW ResolveChild(int nIndex);                              // 0x14065cc70
    static MailTextParagraph Text(const CStringW& strText);         // 0x14065cd10
    static MailTextParagraph Key(int nKey);                         // 0x14065cdb0
    static MailTextParagraph Item(int nItem, const CStringW& strAuxiliary);   // 0x14065ce50
    static MailTextParagraph Money(__int64 nMoney);                 // 0x14065cf00

private:
    MailTextValue m_value;                                          // +0x00
    ATL::CAtlArray<MailTextValue> m_children;                       // +0x18
};
MS2_CHECK_SIZE(MailTextParagraph, 0x38);

class MailText
{
public:
    explicit MailText(int nCode);                                   // 0x14065cfa0
    MailText(int nCode, const MailText& value);                     // 0x14065d000
    MailText(int nCode, unsigned int nKey);                         // 0x14065d0a0 title = string-table key
    MailText(int nCode, int nNumber);                               // 0x14065d120
    MailText(int nCode, const CStringW& strText);                   // 0x14065d1a0
    MailText(int nCode, __int64 nMoney);                            // 0x14065d220
    void SetTitleKey(int nKey);                                     // 0x14065d2a0
    void SetNumber(int nNumber);                                    // 0x14065d310
    void SetTitleText(const CStringW& strText);                     // 0x14065d330
    void SetTitleMoney(__int64 nMoney);                             // 0x14065d3a0
    void AddText(const CStringW& strText);                          // 0x14065d410
    void AddKey(int nKey);                                          // 0x14065d480
    void Add(const MailTextParagraph& paragraph);                   // 0x14065d4f0
    void AddMoney(__int64 nMoney);                                  // 0x14065d520
    bool Load(const CStringW& strTitle, const CStringW& strBody);   // 0x14065d590
    bool LoadTitle(const CStringW& strText);                        // 0x14065d600
    bool LoadBody(const CStringW& strText);                         // 0x14065d7b0
    CStringW ResolveTitle();                                        // 0x14065d9d0
    CStringW ResolveParagraph(int nIndex);                          // 0x14065edf0

private:
    int m_code;                                                     // +0x00
    int m_number;                                                   // +0x04
    MailTextValue m_title;                                          // +0x08
    ATL::CAtlArray<MailTextParagraph> m_paragraphs;                 // +0x20
};
MS2_CHECK_SIZE(MailText, 0x40);
