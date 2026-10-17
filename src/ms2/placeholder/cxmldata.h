// cxmldata.h - PLACEHOLDER for CXmlData (RTTI .?AVCXmlData@@, 0x60 bytes, base CPtred, vftable 0x142daa300).
// NOT an original header. Code owner: ?\xmldata.cpp (dtor 0x14092c2a0, deleting dtor 0x14092c780). Only its
// destructor is called by recovered code so far (CItemData's <function> block holds one at +0x90).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

int FUN_1407181a0(const CStringW& str);    // a wide string as an int

class CXmlData : public CPtred
{
public:
    CXmlData();                         // 0x14092c230
    virtual ~CXmlData();                // 0x14092c2a0
    bool FUN_14092c370(CXmlData* pOther);           // differs from pOther (additionalactionadditional.cpp)
    void FUN_14092c590();                           // clears the parsed values
    void FUN_14092c400(const CStringW& strValues);  // parses "key=value" text
    CString FUN_1409e8560(const CStringW& strKey, const CString& strDefault);     // value as an ansi string (scenestategame.cpp)
    CStringW FUN_14042cad0(const CStringW& strKey, const CStringW& strDefault);   // value as a wide string
    bool FUN_14092c5c0();                           // no values parsed
    typedef ATL::CAtlMap<CStringW, CStringW, ATL::CStringElementTraits<CStringW> > Values;
    // The value as an int, nDefault when the key is missing. An inline (COMDAT copies 0x1403d8110 in gameevent.cpp
    // and 0x14054c530 in itemdatastruct.cpp).
    int GetInt(const CStringW& strKey, const int& nDefault)
    {
        CStringW strValue;
        if (!reinterpret_cast<Values*>(m_unknown18)->Lookup(strKey, strValue))
            return nDefault;
        return FUN_1407181a0(strValue);
    }
private:
    unsigned char m_unknown18[0x48];    // +0x18 the parsed key/values (a Values, kept as raw storage here)
};
MS2_CHECK_SIZE(CXmlData, 0x60);
