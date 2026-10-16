// tptr.h - PLACEHOLDER for TPtr<T> (real name from RTTI template arguments, e.g. TPtr<struct TMarketBillDataParam>).
// NOT an original header. An 8-byte intrusive pointer: ~TPtr() is `if (m_p) m_p->vfunc_2()` (release through the
// pointee's slot 2), e.g. 0x140a5a8c0. Passed by value in virtual slots (the callee destroys it). Declarations only.
#pragma once

#include "ms2/ms2layout.h"

template <class T>
class TPtr
{
public:
    TPtr(const TPtr& o);
    ~TPtr();
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;        // 0x140c206b0 for T = PCBase (inline COMDAT, uihideandseekresultdialog.cpp)

private:
    T* m_p;                             // +0x00
};
