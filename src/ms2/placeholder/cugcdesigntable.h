// cugcdesigntable.h - PLACEHOLDER for CUGCDesignTable (RTTI .?AVCUGCDesignTable@@, 0xb0 bytes). NOT an original header.
// Bases: TSingleton<CUGCDesignTable> at +0x0, CCacheData at +0x8, CValidData<CUGCDesignTable> at +0x30.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class CUGCDesignTable : public TSingleton<CUGCDesignTable>,
                        public CCacheData,
                        public CValidData<CUGCDesignTable>
{
public:
    CUGCDesignTable();                                      // 0x14089e400
    virtual ~CUGCDesignTable();
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_38[0xb0 - 0x38];
};
MS2_CHECK_SIZE(CUGCDesignTable, 0xb0);
