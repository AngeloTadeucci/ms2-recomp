// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The two out-of-line copy constructors of
// CNMVirtualUserInfo (Nexon Messenger virtual-user record): the reference overload and the pointer overload. Both
// chain to the CNMSerializable copy ctor, store the derived vftable, then blit the key, the three fixed buffers and
// the four trailing ints.
// MS2-UNIT: unit_1415eb200
// MS2-RANGE: 0x1415eb200-0x1415eb400 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/unnamed/unit_1415eb200.h"

// @0x1415eb200
CNMVirtualUserInfo::CNMVirtualUserInfo(const CNMVirtualUserInfo& r)
    : CNMSerializable(r)
{
    m_10 = r.m_10;
    memcpy(m_18, r.m_18, 0x40);
    memcpy(m_58, r.m_58, 0x40);
    memcpy(m_98, r.m_98, 0x3e8);
    m_480 = r.m_480;
    m_484 = r.m_484;
    m_488 = r.m_488;
    m_48c = r.m_48c;
}

// @0x1415eb300
CNMVirtualUserInfo::CNMVirtualUserInfo(const CNMVirtualUserInfo* p)
    : CNMSerializable(*p)
{
    m_10 = p->m_10;
    memcpy(m_18, p->m_18, 0x40);
    memcpy(m_58, p->m_58, 0x40);
    memcpy(m_98, p->m_98, 0x3e8);
    m_480 = p->m_480;
    m_484 = p->m_484;
    m_488 = p->m_488;
    m_48c = p->m_48c;
}
