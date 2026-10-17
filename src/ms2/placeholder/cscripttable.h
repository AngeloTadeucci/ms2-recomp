// cscripttable.h - CScriptTable (RTTI .?AVCScriptTable@@, 0x58 bytes): the NPC script strings read from the script*.xml files
// of the localised String folder (<key id name/>). Header name assumed (the unit is client\ms2\scripttable.cpp); member and
// method names are invented from use.
// Bases: TSingleton<CScriptTable> at +0x0, CValidData<CScriptTable> at +0x8. Created by CGameApp::InitInstance (?\ms2.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class CScriptTable : public TSingleton<CScriptTable>, public CValidData<CScriptTable>
{
public:
    typedef ATL::CAtlMap<unsigned __int64, CStringW> ScriptMap;

    CScriptTable();                                         // 0x141020bd0
    virtual ~CScriptTable();                                // 0x141020c80

    void Load();                                            // 0x141020ce0 (name invented)
    void Reload();                                          // 0x141021140 (name invented)
    CStringW GetScript(unsigned __int64 nId);               // 0x141021170 (name invented)

    static void CheckInit();                                // 0x1410218b0
    static void SetInit(bool b);                            // 0x1410227c0

    static bool s_bInit;                                    // 0x143acce40

private:
    MS2_LAYOUT_FRIEND;
    ScriptMap m_mapScripts;                                 // +0x10
};
MS2_CHECK_SIZE(CScriptTable, 0x58);
MS2_CHECK_OFFSET(CScriptTable, m_mapScripts, 0x10);
