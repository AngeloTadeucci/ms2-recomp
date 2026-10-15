// cobjectcount.h - CObjectCount<T> (RTTI .?AV?$CObjectCount@V<T>@@). NOT an original header.
// An empty, non-polymorphic base of many game classes (CAchieve, CAchieveCondition, CAchieveData, ...). It is the
// FIRST base in declaration order (the RTTI base class arrays list it before the CPtred chain), but MSVC lays the
// polymorphic base out first, so it lands at the end of that base (CAchieve: +0x18) and takes no space. The retail
// build calls no ctor/dtor for it: presumably an instance counter compiled only in debug builds.
#pragma once

template <class T>
class CObjectCount
{
};
