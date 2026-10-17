// datatable.h - PLACEHOLDER for DataTable<T> (RTTI .?AV?$DataTable@VPCActionGroup@@@@: PCActionDataTable's base at
// +0x8, after its TSingleton; at most 0x58 bytes for T = PCActionGroup, the rest of the 0x60-byte PCActionDataTable).
// NOT an original header; the members are not recovered (the size is only known for T = PCActionGroup).
#pragma once

#include "ms2/ms2layout.h"

template <class T>
class DataTable
{
public:
    virtual ~DataTable();
private:
    char m_pad_8[0x58 - 0x8];
};

class PCActionGroup;
