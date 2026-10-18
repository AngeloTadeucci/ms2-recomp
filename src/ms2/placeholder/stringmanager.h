// stringmanager.h - PLACEHOLDER for StringManager (RTTI .?AVStringManager@@, 0x38 bytes). NOT an original header.
// Bases: TSingleton<StringManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. +8 holds the string tables by category
// (StringXmlProc<...> objects, see stringxmlproc.h); GetText<T> is defined by client\ms2\string\stringidinterface.cpp.
#pragma once

#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/stringxmlproc.h"

enum StringXmlCategory { StringXmlCategoryEmpty = 0 };

class StringManager : public TSingleton<StringManager>
{
public:
    StringManager();                                        // 0x14084f680
    virtual ~StringManager();
    template <class T> CStringW GetText(StringXmlCategory category, T id);   // 0x141025250 (PVPStringId)
    CStringW FUN_14084f9c0(StringXmlCategory category, int id);               // 0x14084f9c0
private:
    MS2_LAYOUT_FRIEND;
    ATL::CRBMap<StringXmlCategory, MS2Ptr<StringXmlProcBase> > m_tables;   // +0x08
};
MS2_CHECK_SIZE(StringManager, 0x38);
