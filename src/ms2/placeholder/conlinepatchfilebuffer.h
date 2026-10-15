// COnlinePatchFileBuffer: RTTI and allocation at 14038bf20; fields from ctor 14038e1b0.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
class COnlinePatchFileBuffer : public CPtred {
public:
    COnlinePatchFileBuffer(); virtual ~COnlinePatchFileBuffer();
    CString name;void* data;unsigned __int64 size;CString digest;
};
MS2_CHECK_SIZE(COnlinePatchFileBuffer,0x38);
MS2_CHECK_OFFSET(COnlinePatchFileBuffer,name,0x18);
MS2_CHECK_OFFSET(COnlinePatchFileBuffer,size,0x28);
