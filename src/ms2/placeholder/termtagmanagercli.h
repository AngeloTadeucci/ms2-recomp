// termtagmanagercli.h - PLACEHOLDER for TermTagManagerCli (RTTI .?AVTermTagManagerCli@@, 0x108 bytes). NOT an original header.
// Bases: TSingleton<TermTagManagerCli> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include <string>
#include <unordered_map>

class TermTagManagerCli : public TSingleton<TermTagManagerCli>
{
public:
    // @0x141496330
    TermTagManagerCli() {}
    // @0x1414976f0
    virtual ~TermTagManagerCli() {}
private:
    MS2_LAYOUT_FRIEND;
    // Two pairs of hash maps; the key/value types are assumed (the second type's ctor/dtor live in unit_1404979e0).
    std::unordered_map<int, CStringW> m_map08;                   // +0x08
    std::unordered_map<int, CStringW> m_map48;                   // +0x48
    std::unordered_map<std::wstring, int> m_map88;               // +0x88
    std::unordered_map<std::wstring, int> m_mapC8;               // +0xc8
};
MS2_CHECK_SIZE(TermTagManagerCli, 0x108);
