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
    friend struct Unk_TePtrAccess;      // taileffectobject.cpp: ResetNew on the tail info list element

public:
    MS2Ptr();
    MS2Ptr(decltype(nullptr)) { m_p = 0; } // fielddata: distinct nullptr overload
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
    MS2Ptr& operator=(const MS2Ptr& o); // 0x1409b9ad0 for AScript (mentoring reward page)
    T& operator*() const;              // 0x140c353d0 for AScript
    bool IsNull() const;                // `p.get() == 0` as a bool
    bool operator==(T* p) const;
    // `MS2Ptr tmp(p); swap(m_p, tmp.m_p);` - assignment from a raw pointer (0x140a4fd30 for T = CStateManager).
    // A named member, not operator=(T*), so that existing `p = q` / `p = 0` call sites keep their overloads.
    MS2Ptr& AssignRaw(T* p);

private:
    void AddRef() const;                // if (m_p) <add a reference> (0x140d03270 for T = ASDisplayObject)
    void Release();                     // if (m_p) { <drop the reference>; m_p = NULL; } (0x1409b9e00 for T = AScript)
    void ReleaseImpl(void*);            // explicit specializations only (Unk_DropEntry, uiitemdropinfodialog.cpp)
    static void Reference(T*);
public:
    bool operator!() const;             // `m_p == 0` (w3o1: generic bodies of all members in ms2ptr_impl.h)
    MS2Ptr(MS2Ptr&& o) { m_p = o.m_p; o.m_p = 0; }   // merge3: inline (the out-of-line ms2ptr_impl.h body was unresolved in units that do not include it); a3: move at 140e08d80 / 141633bb0 transfers +8 and clears the source
private:
    void AddRefImpl(void*) const;       // Reference(m_p) (rdx homed as a pointer)

    void* m_unk_00;
    T* m_p;                             // +0x08
};

class ASMovieClip;
class ASTextField;
class ASArgList;                        // the argument list of the Invoke back end (defined by the units using it)

class AScript : public CPtred
{
public:
    AScript(const Scaleform::GFx::Value& v, int nMovieId);                                   // 0x1422ba780 (ASCommonDepth)
    AScript(int nMovieId);                                                                   // 0x1422ba6e0 creates a fresh AS object (asequipicon.cpp)
    AScript(Scaleform::GFx::Value& v, int nMovieId);                                         // 0x1422ba7f0 same body as the const& form (asequipicon.cpp)
    Scaleform::GFx::Value FUN_1422baa20(const char* szMember);                               // child member by name
    bool FUN_1422ba9a0();                                                                    // value is undefined
    Scaleform::GFx::Value& FUN_1422bb870();                                                  // m_value
    Scaleform::GFx::Value Invoke(const char* szMethod);                                     // 0x1422bb330
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2);                      // 0x140acd070
    Scaleform::GFx::Value Invoke(const char* szMethod, CString a1);                          // 0x1409b46e0
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1, CStringW a2);            // 0x140e78470
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1);            // 0x1409b13b0 (a1 by value: callee destroys)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, int a2);   // 0x1409b1490 (ascommondepth.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, const AScript& obj);                  // 0x140ba4cc0 (passes obj's value)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1, float a2);          // 0x140ba4c00 (inline COMDAT, defined in uiadventureleveldialog.cpp)
    template <class T> MS2Ptr<T> FUN_140accef0(const CString& strName);                      // child control by name (the adventure level lists)
    template <class T> MS2Ptr<T> FUN_140acce30(const CString& strName);                      // same, one COMDAT per wrapper class (w47: pet evolution)
    template <class T> MS2Ptr<T> FUN_140accfb0(const CString& strName);
    AScript(const AScript& o);                                                               // 0x1409bb7b0 (inline COMDAT)
    Scaleform::GFx::Value Invoke(const char* szMethod, CStringW a1);                         // 0x140acd130 (inline COMDAT, tabcontentspetevolution.cpp)
    Scaleform::GFx::Value FUN_140acd1f0(const char* szMethod, AScript a1);                   // 0x140acd1f0 (Invoke with the AS object by value: the callee destroys it)
    Scaleform::GFx::Value FUN_1422bb8f0(const char* szMethod, ASArgList& args);              // the Invoke back end
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, CStringW a2, int a3, CStringW a4);   // 0x141b4da00 (inline COMDAT, defined in uiupperhpbar.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, bool a1);                             // 0x140bfe360 (inline COMDAT, defined in uicoupledanceeventdialog.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, MS2Ptr<AScript> a1);                 // 0x141ac34b0 (inline COMDAT, defined in uirewardnotify.cpp; a1 by value: the callee destroys it)

    Scaleform::GFx::Value Invoke(const char* szMethod, int a1); // 0x1409ba030 (couple dance HUD)
    Scaleform::GFx::Value Invoke(const char* szMethod, __int64 a1, __int64 a2, int a3); // 0x140e98700 (UITamingBar, w4s10)
    Scaleform::GFx::Value Invoke(const char* szMethod, int a1, int a2, int a3, int a4); // 0x140e64f60 (couple dance HUD COMDAT)

    // Binds the AS child `strName` to `out` and returns a copy of it (0x140bbe640 for T = Unk_ASExitButton).
    template <class T> MS2Ptr<T> FUN_140bbe640(const CString& strName, MS2Ptr<T>& out);

    template<class T> MS2Ptr<T> FUN_140beaf20(const CString&, MS2Ptr<T>&); // bind text (mentoring reward)
    template<class T> MS2Ptr<T> FUN_140bc71c0(const CString&, MS2Ptr<T>&); // bind display object
    template<class T> MS2Ptr<T> FUN_140bbe7c0(const CString&, MS2Ptr<T>&); // bind combo box (party search register)
    template<class T> MS2Ptr<T> FUN_140bbe940(const CString&, MS2Ptr<T>&); // bind input box (party search register)
    template<class T> MS2Ptr<T> FUN_140c12010(const CString&, MS2Ptr<T>&); // bind check box (party search register)
    template<class T> MS2Ptr<T> FUN_140bc7100(const CString&, MS2Ptr<T>&); // bind icon (DT attendance)
    template<class F> void FUN_1422c2a70(const F&, int); // click callback (DT attendance)
    Scaleform::GFx::Value& FUN_1422bb890(); // root value forwarding accessor
    MS2Ptr<ASMovieClip> FUN_1409b4560(const CString& strName); // bind a movie clip child (w4s10; units may hide it)
    MS2Ptr<ASTextField> FUN_1409b4620(const CString& strName); // bind a text field child (aseffect.cpp)
    Scaleform::GFx::Value Invoke(const char*, CString, int); // setTabCount, 0x140a46640
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1);                    // 0x140ba26d0 (UIStanceBar; Value = UInt)
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned long a1);                   // 0x140ba2770
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned long a1, unsigned long a2); // 0x140ba2810
    Scaleform::GFx::Value Invoke(const char* szMethod, unsigned int a1, Scaleform::GFx::Value a2);   // 0x140e2b2d0 (inline COMDAT, defined in uiequipiconcontainer.cpp)
    Scaleform::GFx::Value Invoke(const char* szMethod, Scaleform::GFx::Value a1, CString a2, Scaleform::GFx::Value a3);   // 0x140e2b3d0 (inline COMDAT, defined in uiequipiconcontainer.cpp)

protected:   // cr4: was private; derived AS helpers (ASCommonDepth) read the movie id and the value
    union {
        void* m_pad_18;                 // not char[8]: an array member makes every local AS object a /GS buffer
        int m_nMovieId;                 // +0x18 movie id given to the ctor (ASCommonDepth reads it)
    };
    Scaleform::GFx::Value m_value;      // +0x20
};
MS2_CHECK_SIZE(AScript, 0x40);
