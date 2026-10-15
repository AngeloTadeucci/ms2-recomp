// StringIdInterfaceBase/Interface: layout from 14084ee20 and 141024e60.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
class CInPacket;
class StringIdInterfaceBase {
public:
    virtual ~StringIdInterfaceBase();
    int kind, id;
    ATL::CAtlArray<CStringW> arguments;
    bool formatted;
    CStringW text;
};
class StringIdInterface : public StringIdInterfaceBase {
public:
    explicit StringIdInterface(CInPacket&); // 141024e00
    virtual ~StringIdInterface(); // 1407ab030
    CStringW FUN_141024e60();
};
MS2_CHECK_SIZE(StringIdInterfaceBase, 0x40);
MS2_CHECK_SIZE(StringIdInterface, 0x40);
MS2_CHECK_OFFSET(StringIdInterfaceBase, arguments, 0x10);
MS2_CHECK_OFFSET(StringIdInterfaceBase, text, 0x38);
