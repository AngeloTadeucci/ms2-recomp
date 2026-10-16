// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Chat / name text filter (CBanTextChecker) and CommonString.
// MS2-UNIT: commonfiles\commonstringtable.cpp
// MS2-RANGE: 0x140223c60-0x140266860 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstringtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CStringW FUN_14028de60(EBanStringId nStringId);

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // returns its hidden pointer in rax
CString FUN_14071ae20(const CString& strFile);                          // path of a Table file
CStringW FUN_1401bf530(Unk_140165cf0*, const char*, CStringW strDefault);   // string attribute with default (callee destroys the default)
unsigned FUN_14025ed00(const wchar_t* psz);                             // string hash
void FUN_14025d6f0();                                                   // "CBanTextChecker is not initialized" check
void* FUN_140166410();
bool FUN_14036e560(void* pService);
void FUN_140263710(bool bInitialized);
CStringW FUN_1401e8510(const wchar_t* pszFormat, const CStringW& strArg);   // formats one text argument into the message
CStringW FUN_1401ceea0(const wchar_t* pszFormat, const int& nArg);          // formats one number argument into the message
void FUN_14025fab0(CStringW& str);                                          // MakeLower
extern int DAT_143ab2914;                                                   // client build / region level (below 50: checks active)
extern int DAT_143ab0248;                                                   // client country (0..3)

// The game constants table (FUN_1401d3200()): only the 0x58-byte slots read here.
class Unk_ConstVal { char m_pad_00[0x58]; };
struct Unk_BanConstTable
{
    char m_pad_0000[0x9cb0];
    Unk_ConstVal m_nameMin;                                 // +0x9cb0
    Unk_ConstVal m_nameMax;                                 // +0x9d08
    Unk_ConstVal m_guildNameMin;                            // +0x9d60
    Unk_ConstVal m_guildNameMax;                            // +0x9db8
    char m_pad_9e10[0x9ec0 - 0x9e10];
    Unk_ConstVal m_cNameMin;                                // +0x9ec0
    Unk_ConstVal m_cNameMax;                                // +0x9f18
    Unk_ConstVal m_wideTextMax;                             // +0x9f70
    char m_pad_9fc8[0xa0c0 - 0x9fc8];
    Unk_ConstVal m_dNameMin;                                // +0xa0c0
    Unk_ConstVal m_dNameMax;                                // +0xa118
    Unk_ConstVal m_eNameMin;                                // +0xa170
    Unk_ConstVal m_eNameMax;                                // +0xa1c8
};
MS2_CHECK_OFFSET(Unk_BanConstTable, m_nameMin, 0x9cb0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_cNameMin, 0x9ec0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_wideTextMax, 0x9f70);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_dNameMin, 0xa0c0);
MS2_CHECK_OFFSET(Unk_BanConstTable, m_eNameMax, 0xa1c8);
Unk_BanConstTable* FUN_1401d3200();
int* FUN_1402056b0(Unk_ConstVal* slot);
// @0x14025a620
int FUN_14025a620(Unk_ConstVal* slot) { return *FUN_1402056b0(slot); }

// @0x140223c60
TextFilterUnit::TextFilterUnit() : m_children(17, 0.75f, 0.25f, 2.25f, 10), m_ch(0), m_nDepth(0), m_bWordEnd(0)
{
}

// @0x140223d10
TextFilterUnit::TextFilterUnit(wchar_t ch, int nDepth) : m_children(17, 0.75f, 0.25f, 2.25f, 10), m_ch(ch), m_nDepth(nDepth), m_bWordEnd(0)
{
}

// @0x140223dc0
wchar_t TextFilterUnit::GetChar() const
{
    return m_ch;
}

// @0x140223de0
void TextFilterUnit::Insert(const CStringW& str, int nIndex, CStringW replacement)
{
    if (str.GetLength() == nIndex)
    {
        m_bWordEnd = 1;
        m_replacement = replacement;
        return;
    }
    MS2Ptr<TextFilterUnit> child;
    if (!m_children.Lookup(str[nIndex], child))
    {
        child.AssignRaw(new TextFilterUnit(str[nIndex], m_nDepth + 1));
        m_children.SetAt(str[nIndex], child);
    }
    child->Insert(str, ++nIndex, replacement);
}

// @0x140223fe0
bool TextFilterUnit::Find(const CStringW& str, int nStart, bool bSkipTags, int* pnPos, int* pnLen, CStringW* pReplacement)
{
    if (m_children.IsEmpty())
        return false;
    int nLen = str.GetLength();
    for (int i = nStart; i < nLen; ++i)
    {
        if (bSkipTags && IsTagStart(str[i]) && i < nLen)
        {
            SkipTag(str, &i);
            continue;
        }
        MS2Ptr<TextFilterUnit> child;
        if (m_children.Lookup(towlower(str[i]), child))
        {
            if (child->Match(str, i, pnLen, pReplacement))
            {
                if (pnPos)
                    *pnPos = i;
                return true;
            }
        }
    }
    return false;
}

// @0x140224170
void TextFilterUnit::Clear()
{
    m_children.RemoveAll();
}

// @0x1402241a0
int TextFilterUnit::GetChildCount() const
{
    return (int)m_children.GetCount();
}

// @0x1402241d0
bool TextFilterUnit::Match(const CStringW& str, int nIndex, int* pnLen, CStringW* pReplacement)
{
    if (towlower(str[nIndex]) != m_ch)
        return false;
    if (!m_children.IsEmpty())
    {
        ++nIndex;
        MS2Ptr<TextFilterUnit> child;
        if (m_children.Lookup(towlower(str[nIndex]), child))
        {
            if (child->Match(str, nIndex, pnLen, pReplacement))
                return true;
        }
    }
    if (m_bWordEnd != 0)
    {
        if (pReplacement)
            *pReplacement = m_replacement;
        if (pnLen)
            *pnLen = m_nDepth;
        return true;
    }
    return false;
}

// @0x140224340
bool TextFilterUnit::IsTagStart(wchar_t ch)
{
    return ch == L'<';
}

// @0x140224380
void TextFilterUnit::SkipTag(const CStringW& str, int* pnIndex)
{
    if (str[*pnIndex + 1] == L'A')
    {
        int nEnd = str.Find(L"</A>", *pnIndex);
        if (0 < nEnd)
            *pnIndex = nEnd - 1 + lstrlenW(L"</A>");
    }
    else
    {
        int nEnd = str.Find(L'>', *pnIndex);
        if (0 < nEnd)
            *pnIndex = nEnd;
    }
}

// @0x140224430
CBanTextChecker::CheckerErrStringPackage::CheckerErrStringPackage() : m_ids(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x1402244a0
CBanTextChecker::CheckerErrStringPackage::~CheckerErrStringPackage()
{
    m_ids.RemoveAll();
}

// @0x140224500
bool CBanTextChecker::CheckerErrStringPackage::IsEmpty() const
{
    return m_ids.IsEmpty();
}

// @0x140224530
void CBanTextChecker::CheckerErrStringPackage::Add(EBanErrKind nKind, EBanStringId nStringId)
{
    m_ids.SetAt(nKind, nStringId);
}

// @0x140224570
CStringW CBanTextChecker::CheckerErrStringPackage::GetErrString(EBanErrKind nKind)
{
    EBanStringId nId = (EBanStringId)0;
    if (m_ids.Lookup(nKind, nId))
        return FUN_14028de60(nId);
    return GetDefaultErrString(nKind);
}

static ATL::CAtlMap<EBanErrKind, EBanStringId> s_mapDefaultErr;   // 0x143aacca0

// The default error kind -> string id table, filled on first use. @0x140224600
static void FUN_140224600()
{
    if (s_mapDefaultErr.IsEmpty())
    {
        s_mapDefaultErr.SetAt((EBanErrKind)1, (EBanStringId)0x8b8);
        s_mapDefaultErr.SetAt((EBanErrKind)2, (EBanStringId)0x8b7);
        s_mapDefaultErr.SetAt((EBanErrKind)3, (EBanStringId)0x8b9);
        s_mapDefaultErr.SetAt((EBanErrKind)4, (EBanStringId)0x8ba);
        s_mapDefaultErr.SetAt((EBanErrKind)5, (EBanStringId)0x8b3);
        s_mapDefaultErr.SetAt((EBanErrKind)6, (EBanStringId)0x8b4);
        s_mapDefaultErr.SetAt((EBanErrKind)7, (EBanStringId)0x8b5);
        s_mapDefaultErr.SetAt((EBanErrKind)8, (EBanStringId)0x8b6);
    }
}

// @0x140224760
CStringW CBanTextChecker::GetDefaultErrString(EBanErrKind nKind)
{
    EBanStringId nId = (EBanStringId)0;
    FUN_140224600();
    if (s_mapDefaultErr.Lookup(nKind, nId))
        return FUN_14028de60(nId);
    return CStringW(L"");
}

// @0x1402247f0
CStringW CBanTextChecker::GetErrString(EBanErrKind nKind, MS2Ptr<CheckerErrStringPackage> pkg)
{
    if (pkg.IsNull())
        return GetDefaultErrString(nKind);
    return pkg->GetErrString(nKind);
}

// @0x14025c350
CBanTextChecker::CheckerOption::CheckerOption(unsigned nTypes, bool bFlag) : m_bFlag(bFlag), m_nTypes(nTypes), m_errs(0)
{
}

// @0x14025c2e0
CBanTextChecker::CheckerOption::CheckerOption(MS2Ptr<CheckerErrStringPackage> errs, unsigned nTypes, bool bFlag) : m_bFlag(bFlag), m_nTypes(nTypes), m_errs(errs)
{
}

// @0x14025c9d0
CBanTextChecker::CheckerOption::~CheckerOption()
{
    m_errs = 0;
}

// @0x14025c3a0
CBanTextChecker::CheckerLimit::CheckerLimit(int nMin, int nMax, bool bAllowSpace, bool bSkipTrimCheck, bool bNoCharCheck, bool bWideCountsTwice, bool bAllowPunct)
    : m_nMin(nMin), m_nMax(nMax), m_bAllowSpace(bAllowSpace), m_bSkipTrimCheck(bSkipTrimCheck), m_bNoCharCheck(bNoCharCheck),
      m_bWideCountsTwice(bWideCountsTwice), m_bAllowPunct(bAllowPunct), m_errs(0)
{
}

// @0x14025ca10
CBanTextChecker::CheckerLimit::~CheckerLimit()
{
    m_errs = 0;
}

// @0x140229220
void CBanTextChecker::FUN_140229220()
{
}

// @0x140224890
CBanTextChecker::CBanTextChecker() : m_mapUrlHash(10), m_mapBanWords(10)
{
    FUN_140229220();
}

// @0x1402249e0
CBanTextChecker::~CBanTextChecker()
{
    ClearTries();
}

// @0x140227890
void CBanTextChecker::ClearTries()
{
    m_trieBanUrl.Clear();
    m_trieBanWord.Clear();
    m_trieReserveWord.Clear();
    m_trieReserveIdAny.Clear();
    m_setReserveIdAll.clear();
    m_mapUrlHash.RemoveAll();
    m_mapBanWords.RemoveAll();
}

// @0x140224f80
int CBanTextChecker::HasStartWithWords(unsigned nTypes)
{
    if (nTypes & 0x40) return (unsigned)m_trieStartWith.GetChildCount() > 0;
    return 0;
}

// @0x140224fe0
bool CBanTextChecker::IsAlnumName(const CStringW& str, void*)
{
    CStringW s(str);
    if (s.GetLength() > 0x20) return false;
    int nLen = s.GetLength();
    if (nLen < 1 || 0x20 < nLen) return false;
    for (int i = 0; i < nLen; ++i) {
        wchar_t ch = s.GetAt(i);
        if (ch >= L'0' && ch <= L'9') continue;
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z')) continue;
        return false;
    }
    return true;
}

// @0x140259fe0
CStringW CBanTextChecker::GetLimitErrString(CheckerLimit& limit, unsigned nKind)
{
    EBanErrKind eKind = static_cast<EBanErrKind>(0);
    switch (nKind) {
    case 1: {
        eKind = static_cast<EBanErrKind>(5);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        int nCount = limit.m_nMin < 1 ? 1 : limit.m_nMin;
        return FUN_1401ceea0(format, nCount);
    }
    case 2: {
        eKind = static_cast<EBanErrKind>(6);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        int nCount = limit.m_nMax > 1 ? limit.m_nMax : 1;
        return FUN_1401ceea0(format, nCount);
    }
    case 3: {
        eKind = static_cast<EBanErrKind>(limit.m_bAllowSpace ? 7 : 8);
        CStringW format = CBanTextChecker::GetErrString(eKind, limit.m_errs);
        return format;
    }
    }
    return CStringW(L"");
}

// @0x14025a290
CStringW CBanTextChecker::GetOptionErrString(CheckerOption& opt, EBanErrKind nKind, const CStringW& strMatched, unsigned char bFlag)
{
    EBanErrKind eKind = static_cast<EBanErrKind>(0);
    switch (nKind) {
    case 5:
    case 9: {
        eKind = static_cast<EBanErrKind>(bFlag ? 1 : 2);
        CStringW format = CBanTextChecker::GetErrString(eKind, opt.m_errs);
        return FUN_1401e8510(format, strMatched);
    }
    case 6:
    case 7:
    case 8: {
        eKind = static_cast<EBanErrKind>(opt.m_bFlag ? 3 : 4);
        CStringW format = CBanTextChecker::GetErrString(eKind, opt.m_errs);
        return FUN_1401e8510(format, strMatched);
    }
    }
    return CStringW(L"");
}

// @0x140228c50
bool CBanTextChecker::FindBanWord(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieBanWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228d60
bool CBanTextChecker::FindUgcBanWord(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieUgcBanWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228e70
bool CBanTextChecker::FindReserveWord(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    int nPos = 0;
    int nLen = 0;
    CStringW s(str);
    if (m_trieReserveWord.Find(s, 0, true, &nPos, &nLen, NULL)) {
        matched = s.Mid(nPos, nLen);
        return true;
    }
    return false;
}

// @0x140228a60
bool CBanTextChecker::FindReserveIdAll(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    CStringW s(str);
    FUN_14025fab0(s);
    std::set<CStringW>::iterator it = m_setReserveIdAll.find(s);
    if (it != m_setReserveIdAll.end()) {
        matched = *it;
        return true;
    }
    return false;
}

// @0x140228f80
bool CBanTextChecker::FindStartWithWord(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    int nStart = 0;
    int nPos = 0;
    int nLen = 0;
    while (m_trieStartWith.Find(str, nStart, true, &nPos, &nLen, NULL)) {
        if (nPos == nStart) {
            matched = str.Mid(nPos, nLen);
            return true;
        } else {
            nStart = str.Find(L' ', nPos);
            if (nStart < 0) break;
            nStart = nStart + 1;
        }
    }
    return false;
}

// @0x1402290b0
bool CBanTextChecker::FindBanWordAll(const CStringW& str, CStringW& matched)
{
    FUN_14025d6f0();
    int nTotal = str.GetLength();
    int nStart = 0;
    int nPos = 0;
    int nLen = 0;
    while (m_trieBanWordAll.Find(str, nStart, true, &nPos, &nLen, NULL)) {
        int nSpace = str.Find(L' ', nPos);
        bool bWhole = true;
        if (nStart == nPos) {
            if (nSpace == -1 && nPos + nLen != nTotal) bWhole = false;
            else if (nSpace != -1 && nPos + nLen != nSpace) bWhole = false;
        } else {
            int nPrevSpace = str.Find(L' ', nStart);
            if (nSpace - nPrevSpace - 1 != nLen) bWhole = false;
        }
        if (bWhole) return true;
        nStart = str.Find(L' ', nPos);
        if (nStart < 0) break;
        nStart = nStart + 1;
    }
    return false;
}

// @0x140227930
int CBanTextChecker::CheckTextOption(const CStringW& str, CheckerOption& opt, CStringW& message)
{
    if (DAT_143ab2914 >= 0x32) return 0;
    {
        unsigned nTypes = opt.m_nTypes;
        unsigned char bFlag = nTypes & 1;
        if ((nTypes & 2) != 0) {
            CStringW matched;
            if (FindReserveIdAll(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(5);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 4) != 0) {
            CStringW matched;
            if (FindReserveIdAny(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(6);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 8) != 0) {
            CStringW matched;
            if (FindReserveWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(7);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x10) != 0) {
            CStringW matched;
            if (FindBanWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x20) != 0) {
            CStringW matched;
            if (FindUgcBanWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x40) != 0) {
            CStringW matched;
            if (FindStartWithWord(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(8);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
        if ((nTypes & 0x80) != 0) {
            CStringW matched;
            if (FindBanWordAll(str, matched)) {
                EBanErrKind eKind = static_cast<EBanErrKind>(9);
                message = GetOptionErrString(opt, eKind, matched, bFlag);
                return eKind;
            }
        }
    }
    return 0;
}

// @0x140228110
unsigned CBanTextChecker::ScanLimit(const CStringW& str, CheckerLimit& limit)
{
    return 0;
}
// @0x140225120
int CBanTextChecker::FUN_140225120(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_nameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_nameMax);
    CheckerOption opt(0x91, true);
    CheckerLimit limit(nMin, nMax, true, false, false, true, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225210
int CBanTextChecker::FUN_140225210(const CStringW& str, CStringW& message, int bShort)
{
    int nMax = bShort ? 0xc : 0x18;
    CheckerOption opt(0xdf, true);
    CheckerLimit limit(2, nMax, false, false, false, true, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402252f0
int CBanTextChecker::FUN_1402252f0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(1, 0x10, true, false, false, true, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402253b0
int CBanTextChecker::FUN_1402253b0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(0, 100, true, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225470
int CBanTextChecker::FUN_140225470(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(FUN_14025a620(&FUN_1401d3200()->m_dNameMin), FUN_14025a620(&FUN_1401d3200()->m_dNameMax), true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225550
int CBanTextChecker::FUN_140225550(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(FUN_14025a620(&FUN_1401d3200()->m_eNameMin), FUN_14025a620(&FUN_1401d3200()->m_eNameMax), true, false, true, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225630
int CBanTextChecker::FUN_140225630(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_cNameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_cNameMax);
    CheckerOption opt(0xf9, true);
    CheckerLimit limit(nMin, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225720
int CBanTextChecker::FUN_140225720(const CStringW& str, CStringW& message)
{
    int nMin = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMin);
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_guildNameMax);
    CheckerOption opt(0xd9, true);
    CheckerLimit limit(nMin, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225810
int CBanTextChecker::FUN_140225810(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd9, true);
    int nMax = 7;
    if (FUN_14036e560(FUN_140166410())) nMax = 0xf;
    CheckerLimit limit(1, nMax, true, false, false, false, true);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402258f0
int CBanTextChecker::FUN_1402258f0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd8, true);
    CheckerLimit limit(1, 1000, false, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x1402259b0
int CBanTextChecker::FUN_1402259b0(const CStringW& str, CStringW& message)
{
    CheckerOption opt(0xd8, true);
    CheckerLimit limit(1, 300, false, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140225c90
int CBanTextChecker::FUN_140225c90(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c1));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c2));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140225de0
int CBanTextChecker::FUN_140225de0(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140225f70
int CBanTextChecker::FUN_140225f70(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8bb));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8bc));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140226440
int CBanTextChecker::FUN_140226440(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c1));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c2));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140226590
int CBanTextChecker::FUN_140226590(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x1402266e0
int CBanTextChecker::FUN_1402266e0(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140226830
int CBanTextChecker::FUN_140226830(const CStringW& str, CStringW& message)
{
    MS2Ptr<CheckerErrStringPackage> pkg(new CheckerErrStringPackage);
    if (pkg.get()) {
        pkg->Add(static_cast<EBanErrKind>(3), static_cast<EBanStringId>(0x8c3));
        pkg->Add(static_cast<EBanErrKind>(4), static_cast<EBanStringId>(0x8c4));
    }
    return CheckTextOption(str, CheckerOption(pkg, 0xd8, true), message);
}

// @0x140225f30
int CBanTextChecker::FUN_140225f30(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd0, true, message);
}

// @0x1402260c0
int CBanTextChecker::FUN_1402260c0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x1402261e0
int CBanTextChecker::FUN_1402261e0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226220
int CBanTextChecker::FUN_140226220(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226260
int CBanTextChecker::FUN_140226260(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x1402262a0
int CBanTextChecker::FUN_1402262a0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd0, true, message);
}

// @0x1402262e0
int CBanTextChecker::FUN_1402262e0(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226400
int CBanTextChecker::FUN_140226400(const CStringW& str, CStringW& message)
{
    return CheckTypes(str, 0xd8, true, message);
}

// @0x140226100
int CBanTextChecker::FUN_140226100(const CStringW& str, CStringW& message)
{
    int nMax = 200;
    if (str.GetLength() > nMax) return 2;
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226160
int CBanTextChecker::FUN_140226160(const CStringW& str, CStringW& message)
{
    int nMax = *FUN_1402056b0(&FUN_1401d3200()->m_wideTextMax) * 3 + 10;
    if (str.GetLength() > nMax) return 2;
    return CheckTypes(str, 0xf8, true, message);
}

// @0x140226320
int CBanTextChecker::FUN_140226320(const CStringW& str, CStringW& message)
{
    if (str.IsEmpty()) return 0;
    CheckerOption opt(0xdf, true);
    CheckerLimit limit(1, 200, true, false, false, false, false);
    return CheckTextWithLimit(str, opt, limit, message);
}

// @0x140227fb0
int CBanTextChecker::CheckTextWithLimit(const CStringW& str, CheckerOption& opt, CheckerLimit& limit, CStringW& message)
{
    unsigned nTypes = opt.m_nTypes;
    unsigned char bCheckLimit = nTypes & 1;
    unsigned nResult;
    if (bCheckLimit && (nResult = ScanLimit(str, limit)) != 0) {
        message = GetLimitErrString(limit, nResult);
        return nResult;
    }
    return CheckTextOption(str, opt, message);
}

// @0x140228080
int CBanTextChecker::CheckTypes(const CStringW& str, unsigned nTypes, bool bFlag, CStringW& message)
{
    return CheckTextOption(str, CheckerOption(nTypes, bFlag), message);
}
