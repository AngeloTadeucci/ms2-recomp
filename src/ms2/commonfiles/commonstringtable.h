// commonstringtable.h - CBanTextChecker (the chat / name text filter: banned, reserved and prefix word tries loaded from
// Table/banWord.xml & co, length / charset rules, error string ids) and its helpers. Header name and member names are
// assumed; types are the RTTI names. Recovered from the KMS2_DEV x64 exe (0x140223c60-0x140266860 .text$mn).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

// One node of a character trie (0x78 bytes): the children by lower-cased character, the character itself, the depth
// (number of characters from the root) and, when a word ends here, its replacement text.
class TextFilterUnit : public CPtred
{
public:
    TextFilterUnit();                                       // 0x140223c60
    TextFilterUnit(wchar_t ch, int nDepth);                 // 0x140223d10
    // virtual ~TextFilterUnit() is implicit (0x14025caa0)

    wchar_t GetChar() const;                                // 0x140223dc0
    void Insert(const CStringW& str, int nIndex, CStringW replacement);                         // 0x140223de0
    bool Find(const CStringW& str, int nStart, bool bSkipTags, int* pnPos, int* pnLen, CStringW* pReplacement);   // 0x140223fe0
    void Clear();                                           // 0x140224170
    int GetChildCount() const;                              // 0x1402241a0
    bool Match(const CStringW& str, int nIndex, int* pnLen, CStringW* pReplacement);            // 0x1402241d0
    bool IsTagStart(wchar_t ch);                     // 0x140224340
    void SkipTag(const CStringW& str, int* pnIndex); // 0x140224380

    ATL::CAtlMap<wchar_t, MS2Ptr<TextFilterUnit> > m_children;      // +0x18 keyed by the lower-cased character
    wchar_t m_ch;                                           // +0x60
    int m_nDepth;                                           // +0x64
    int m_bWordEnd;                                         // +0x68
    CStringW m_replacement;                                 // +0x70
};
MS2_CHECK_SIZE(TextFilterUnit, 0x78);
MS2_CHECK_OFFSET(TextFilterUnit, m_children, 0x18);
MS2_CHECK_OFFSET(TextFilterUnit, m_replacement, 0x70);

enum EBanErrKind { };       // error kind (1..8); an enum so that the ATL map takes it by reference
enum EBanStringId { };      // string table id

// The error string ids a check can answer with, by error kind (CBanTextChecker::CheckerErrStringPackage, 0x60 bytes).
class CBanTextChecker
{
public:
    class CheckerErrStringPackage : public CPtred
    {
    public:
        CheckerErrStringPackage();                          // 0x140224430
        virtual ~CheckerErrStringPackage();                 // 0x1402244a0

        bool IsEmpty() const;                               // 0x140224500
        void Add(EBanErrKind nKind, EBanStringId nStringId);       // 0x140224530
        CStringW GetErrString(EBanErrKind nKind);              // 0x140224570

        ATL::CAtlMap<EBanErrKind, EBanStringId> m_ids;             // +0x18 error kind -> string id
    };
};
MS2_CHECK_SIZE(CBanTextChecker::CheckerErrStringPackage, 0x60);
