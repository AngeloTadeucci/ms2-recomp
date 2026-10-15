// Recovered CServerListTable (RTTI name): the login server list read from Table/serverList.xml. Header name assumed.
// Member and helper names are invented from use (the exe has no names for them).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

class CServerListTable;


class CServerListTable : public TSingleton<CServerListTable>, public CValidData<CServerListTable>
{
public:
    // One <server> row of serverList.xml. RTTI CServerListTable::ServerInfo, 0x38 bytes.
    class ServerInfo : public CPtred
    {
    public:
        ServerInfo() {}

        int m_nId;                      // +0x18 attribute "id"
        int m_pad_1c;
        CStringW m_strName;             // +0x20 attribute "name"
        CString m_strIcon;              // +0x28 attribute "icon"
        CString m_strDisIcon;           // +0x30 attribute "dis_icon"
    };

    typedef MS2SvrPtr<ServerInfo> InfoPtr;
    typedef ATL::CAtlMap<DWORD, InfoPtr> Map;

    CServerListTable();                 // 0x1417516d0
    virtual ~CServerListTable();        // 0x141751780

    void Load();                        // 0x1417517e0 (name invented)
    void Clear();                       // 0x141751bc0
    InfoPtr GetServer(DWORD nId);       // 0x141751bf0
    InfoPtr GetFirstServer();           // 0x141751cb0

    static void CheckInit();            // 0x141752370 (a CValidData<T> static in the original, probably)
    static void SetInit(bool b);        // 0x141753350

    static bool s_bInit;                // 0x143ae95b8

private:
    MS2_LAYOUT_FRIEND;
    Map m_map;                          // +0x10
};
MS2_CHECK_SIZE(CServerListTable::ServerInfo, 0x38);
MS2_CHECK_OFFSET(CServerListTable::ServerInfo, m_nId, 0x18);
MS2_CHECK_OFFSET(CServerListTable::ServerInfo, m_strName, 0x20);
MS2_CHECK_OFFSET(CServerListTable::ServerInfo, m_strDisIcon, 0x30);
MS2_CHECK_SIZE(CServerListTable, 0x58);
MS2_CHECK_OFFSET(CServerListTable, m_map, 0x10);
