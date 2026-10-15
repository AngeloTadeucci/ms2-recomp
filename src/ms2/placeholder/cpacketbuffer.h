// CPacketBuffer: RTTI and packet.cpp layout; names inferred.
#pragma once
#include "ms2/placeholder/cptred.h"
class CPacketBuffer : public CPtred {
public:
    virtual ~CPacketBuffer();
    int FUN_140714fa0() const;
    char* FUN_140713530();
    CPacketBuffer* FUN_140715390(unsigned,int);
private: int m_size; void* m_data; void* m_parent; int m_30;
};
MS2_CHECK_SIZE(CPacketBuffer,0x38);
