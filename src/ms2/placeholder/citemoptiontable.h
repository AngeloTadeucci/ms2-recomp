// citemoptiontable.h - PLACEHOLDER for CItemOptionTable (RTTI .?AVCItemOptionTable@@, 0x118 bytes). NOT an original header.
// Bases: TSingleton<CItemOptionTable> at +0x0, CValidData<CItemOptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include <atlcoll.h>
#include "ms2/placeholder/socketptr.h"

class Unk_Random;

// The stat names of one exclusive option group (the box the table's name map points at; a CPtred base, the list at
// +0x18). Owned through Unk_OptionNameListPtr (get 0x1405e9a40, operator-> 0x1405e9a70, dtor 0x1405e89b0).
typedef ATL::CAtlList<CString> Unk_OptionNameList;
template<> struct Unk_SocketRef<Unk_OptionNameList> {
    static CPtred* Base(Unk_OptionNameList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_OptionNameList>, value);
        return result;
    }
    static TPtredDummy<Unk_OptionNameList>* New(void*) { return new TPtredDummy<Unk_OptionNameList>(); }
    static Unk_OptionNameList* Value(CPtred* p) {
        Unk_OptionNameList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_OptionNameList>*>(p)->value;
        return result;
    }
    static Unk_OptionNameList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
typedef Unk_SocketPtr<Unk_OptionNameList> Unk_OptionNameListPtr;

class CItemOptionTable : public TSingleton<CItemOptionTable>, public CValidData<CItemOptionTable>
{
public:
    CItemOptionTable();                                     // 0x1405f4140
    virtual ~CItemOptionTable();
    // commonfiles\itemoptiondata.cpp#3 (declared for the random option rolls of #2)
    int FUN_1405f6100(int nStatId);
    int FUN_1405f6190(int nStatId, Unk_Random* pRandom);
    int FUN_1405f6230(int nStatId);
    int FUN_1405f62c0(int nStatId);
    Unk_OptionNameListPtr FUN_1405f6e40(const CString& strName);     // the exclusive group of a stat name (null: none)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_10[0x118 - 0x10];
};
MS2_CHECK_SIZE(CItemOptionTable, 0x118);
