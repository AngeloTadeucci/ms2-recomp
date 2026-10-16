// astooltip.h - PLACEHOLDER for ASTooltip (RTTI .?AVASTooltip@@, base AScript, 0x60 bytes). NOT an original header.
// Ctors 0x1409c63d0 (int, int) and an (owner, int, int) variant, dtor 0x1409b4af0. Units must include this header
// instead of redefining the class.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class CItem;
template <class T> class Unk_GalleryPtr;     // unit-local smart pointer of uigalleryeventdialog.h
class Unk_GalleryItem;

class ASTooltip : public AScript
{
public:
    explicit ASTooltip(int nMovieId);                // 0x1409c62e0 (aseffect.cpp)
    ASTooltip(int a1, int a2);
    ASTooltip(void* pOwner, int a1, int a2);
    ASTooltip(const Scaleform::GFx::Value& root, int nMovieId);     // 0x1409c6350 (uiadventureleveldialog.cpp)
    virtual ~ASTooltip();
    void FUN_1409c6dc0(int n);
    void FUN_1409c6d70(const CString& strClass);                         // set the AS class name
    void FUN_1409c6e00(int n);
    void FUN_1409c6e60(int n);
    void FUN_1409c6cb0(const CStringW& strText);                         // set the text
    void FUN_1409c6e90(int n);
    int FUN_1409e26b0(const CStringW& strText);
    int FUN_1409e1770(int a1, int a2);
    int FUN_1409e0d40(CItem* pItem);
    int FUN_1409e2750(void* pSkillAttr, int a1, int a2);                   // skill record tooltip (uiadventureleveldialog.cpp)
    void FUN_1409db870(Unk_GalleryPtr<Unk_GalleryItem> item);
    void FUN_1409c69b0(const CStringW& strTitle);                        // set the tooltip title line
    void FUN_1409c65f0(const CStringW& strText);                         // set the tooltip text line
    int FUN_1409e13f0(CItem* pCompare, CItem* pItem, int a1, int a2);   // item tooltip with a comparison item (ItemInfoSlot)
    void FUN_1409c6a20(const CStringW& strA, const CStringW& strB);     // set a tooltip text pair (ItemInfoSlot exchange scroll)
    void FUN_1409c7060(const CStringW& strKey, const CStringW& strB);   // set a keyed tooltip text pair (ItemInfoSlot exchange scroll)
    void FUN_1409db7b0(MS2Ptr<CItem> spItem);                            // compare against this item (by value: callee destroys)

private:
    void* m_pad_40; void* m_pad_48; CStringW m_50; void* m_pad_58;   // m_50: text (destroyed by ~ASTooltip, aseffect.cpp)
};
MS2_CHECK_SIZE(ASTooltip, 0x60);
