// CClientHardwareInfo: RTTI name; layout from ctor 0x14026e470 and accessors.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
class CInputStream;
class COutputStream;
class CClientHardwareInfo : public CPtred {
public:
    CClientHardwareInfo();
    virtual ~CClientHardwareInfo() = default;
    void Write(COutputStream&);
    void Read(CInputStream&);
    CStringW Get();
    void Set(const CStringW&);
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;
    CStringW m_hardware;
};
MS2_CHECK_SIZE(CClientHardwareInfo,0x50);
MS2_CHECK_OFFSET(CClientHardwareInfo,m_lock,0x18);
MS2_CHECK_OFFSET(CClientHardwareInfo,m_hardware,0x48);
