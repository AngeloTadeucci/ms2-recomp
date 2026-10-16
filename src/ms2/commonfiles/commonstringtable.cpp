// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Chat / name text filter (CBanTextChecker) and CommonString.
// MS2-UNIT: commonfiles\commonstringtable.cpp
// MS2-RANGE: 0x140223c60-0x140266860 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstringtable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

CStringW FUN_14028de60(int nStringId);

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
