// cvaliddata.h - CValidData<T> (RTTI .?AV?$CValidData@V<T>@@, 8 bytes: a vftable with the virtual dtor only).
// NOT an original header. A secondary base of the game's table data classes (CAchieveData at +0x28, ...); its
// ctor/dtor/deleting dtor are per-T COMDATs (T = CAchieveData: 0x1401636d0 / 0x140164330 / 0x140165030).
#pragma once

template <class T>
class CValidData
{
public:
    CValidData() {}
    virtual ~CValidData() {}
};
