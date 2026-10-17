// cquesttable.h - CQuestTable (RTTI .?AVCQuestTable@@, 0x58 bytes): the quest -> field list table read from
// Table/questToFieldTable.xml (<quest id fields="1,2,3"/>). Header name assumed (the unit is client\ms2\questtable.cpp);
// member and method names are invented from use.
// Bases: TSingleton<CQuestTable> at +0x0, CValidData<CQuestTable> at +0x8. Created by CGameApp::InitInstance (?\ms2.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/ugccubecategorytable.h"
#include "ms2/placeholder/cvaliddata.h"

class CQuestTable : public TSingleton<CQuestTable>, public CValidData<CQuestTable>
{
public:
    typedef Unk_CubeBoxPtr<ATL::CAtlList<unsigned int> > FieldListPtr;
    typedef ATL::CAtlMap<DWORD, FieldListPtr> FieldMap;

    CQuestTable();                                          // 0x1416e3800
    virtual ~CQuestTable();                                 // 0x1416e38b0

    void LoadQuestToField();                                // 0x1416e3910 (name invented)
    void GetFields(DWORD nQuestId, ATL::CAtlList<unsigned int>* pOut); // 0x1416e3c10 (name invented): appends the quest's field ids

    static void CheckInit();                                // 0x1416e3e30
    static void SetInit(bool b);                            // 0x1416e3ee0

    static bool s_bInit;                                    // 0x143ae65dc

private:
    MS2_LAYOUT_FRIEND;
    FieldMap m_mapFields;                                   // +0x10
};
MS2_CHECK_SIZE(CQuestTable, 0x58);
MS2_CHECK_OFFSET(CQuestTable, m_mapFields, 0x10);
