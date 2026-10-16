// cxmldata.h - PLACEHOLDER for CXmlData (RTTI .?AVCXmlData@@, 0x60 bytes, base CPtred, vftable 0x142daa300).
// NOT an original header. Code owner: ?\xmldata.cpp (dtor 0x14092c2a0, deleting dtor 0x14092c780). Only its
// destructor is called by recovered code so far (CItemData's <function> block holds one at +0x90).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class CXmlData : public CPtred
{
public:
    CXmlData();
    virtual ~CXmlData();                // 0x14092c2a0
private:
    unsigned char m_unknown18[0x48];    // +0x18
};
MS2_CHECK_SIZE(CXmlData, 0x60);
