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
