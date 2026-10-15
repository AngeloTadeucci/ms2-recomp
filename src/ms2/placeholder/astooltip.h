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
    ASTooltip(int a1, int a2);
    ASTooltip(void* pOwner, int a1, int a2);
    virtual ~ASTooltip();
    void FUN_1409c6dc0(int n);
    void FUN_1409c6e90(int n);
    int FUN_1409e26b0(const CStringW& strText);
    int FUN_1409e1770(int a1, int a2);
    int FUN_1409e0d40(CItem* pItem);
    void FUN_1409db870(Unk_GalleryPtr<Unk_GalleryItem> item);

private:
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58;
};
MS2_CHECK_SIZE(ASTooltip, 0x60);
