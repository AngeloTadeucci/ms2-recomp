// ascript.h - PLACEHOLDER for AScript (RTTI .?AVAScript@@, 64 bytes, base CPtred, vftable 0x142db7e28) and the
// game's 16-byte smart pointer template. NOT an original header.
//
// AScript wraps an ActionScript object (Scaleform::GFx::Value at +0x20). Its Invoke helpers call an AS method by
// name and return the GFx result by value (callers destroy it at once). Only the overloads that recovered code
// calls are declared; the originals are probably variadic templates (one COMDAT per argument list), so each
// declared overload stands for one instantiation.
//
// MS2Ptr<T>: 16 bytes, the pointer at +0x08 (+0x00 unknown, probably a vftable or the owner). Its members are
// COMDAT instantiations per T (e.g. T = AScript: get 0x1409ee240, operator-> 0x1409ee290); the real template name
// is unknown. Declared without bodies: callers' bytes do not depend on them and the copies live in other units.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/gfxvalue.h"

template <class T>
class MS2Ptr
{
    template <class U> friend class MS2Ptr;

public:
    MS2Ptr();
    MS2Ptr(int nNull);                  // `MS2Ptr<T> p(0)`: m_p = NULL (0x140c74e10 for T = AScript)
    MS2Ptr(T* p);                       // m_p = p; AddRef() (0x140f9c100 for T = UISwfEntity)
    MS2Ptr(const MS2Ptr& o);            // 0x1409b9940 for T = AScript
    ~MS2Ptr();                          // 0x1409b9a00 for T = AScript
    // Converting assignment (U derives from T). Inline: its COMDAT is in the first unit that assigns (0x1422dca80 for
    // T = AScript, U = ASDisplayObject, in uiswfentity.cpp).
    template <class U> MS2Ptr& operator=(const MS2Ptr<U>& o)
    {
        o.AddRef();
        Release();
        m_p = o.m_p;
        return *this;
    }
    MS2Ptr& operator=(int nNull);       // `p = NULL` (int parameter: the callee homes edx as a dword)
    T* get() const;                     // tested for null: `if (p)` is written `if (p.get())` (0x1409ee240 for AScript)
    operator T*() const;                // `if (MS2Ptr<T> p = ...)`, `dynamic_cast<X*>((T*)p)` (AScript: 0x140ba7c60)
    T* operator->() const;
    bool IsNull() const;                // `p.get() == 0` as a bool
    bool operator==(T* p) const;

private:
    void AddRef() const;                // if (m_p) <add a reference> (0x140d03270 for T = ASDisplayObject)
    void Release();                     // if (m_p) { <drop the reference>; m_p = NULL; } (0x1409b9e00 for T = AScript)

    void* m_unk_00;
    T* m_p;                             // +0x08
};

class AScript : public CPtred
{
public:
    Scaleform::GFx::Value& FUN_1422bb870();                                                  // m_value
    Scaleform::GFx::Value Invoke(const char* szMethod);                                     // 0x1422bb330
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2);                      // 0x140acd070
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1);                          // 0x1409b46e0
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2);            // 0x140e78470

    // Binds the AS child `strName` to `out` and returns a copy of it (0x140bbe640 for T = Unk_ASExitButton).
    template <class T> MS2Ptr<T> FUN_140bbe640(const CString& strName, MS2Ptr<T>& out);

private:
    char m_pad_18[0x8];
    Scaleform::GFx::Value m_value;      // +0x20
};
MS2_CHECK_SIZE(AScript, 0x40);
