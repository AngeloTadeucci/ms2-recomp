// datatablemap.h - PLACEHOLDER for DataTableMap<T, K, KTraits> (RTTI
// .?AV?$DataTableMap@VWebGuide@@V?$CStringT@D...@ATL@@V?$CStringElementTraits@...@3@@@: WebGuideTable's base at +0,
// its TSingleton at +0x80). NOT an original header; the members are not recovered (the size, 0x80, is only known for
// T = WebGuide, K = CString).
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"

template <class T, class K, class KTraits>
class DataTableMap
{
public:
    virtual ~DataTableMap();
private:
    char m_pad_8[0x80 - 0x8];
};

class WebGuide;
