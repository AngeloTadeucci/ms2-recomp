// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The Nexon Messenger (nm) object hierarchy's destructor
// batch: eight classes whose destructor is a bare chain to the base destructor, plus CNMVirtualFriendInfoChangedEvent,
// which destroys the CNMVirtualFriendInfo subobject at +0x30 before running its CNMEvent base destructor.
// MS2-UNIT: unit_1415eef30
// MS2-RANGE: 0x1415eef30-0x1415ef060 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Base objects of the hierarchy. Their destructors are defined with the units that own their key functions, so the
// classes are only declared (with the virtual destructor each one carries in the exe) and are called qualified below
// - a qualified call is a direct call, which is what the exe emits (no vtable dispatch).
class CNMSerializable
{
public:
    virtual ~CNMSerializable();                                 // 0x1415eec70
};

class CNMEvent : public CNMSerializable
{
public:
    virtual ~CNMEvent();                                        // 0x1415ed280
};

class CNMFunc : public CNMSerializable
{
public:
    virtual ~CNMFunc();                                         // 0x1415ed640
};

class CNMVirtualFriendInfo : public CNMSerializable
{
public:
    virtual ~CNMVirtualFriendInfo();
};

class CNMVirtualUserInfo : public CNMSerializable
{
public:
    virtual ~CNMVirtualUserInfo();
};

class CNMWSAssocSerialKeyEvent : public CNMEvent
{
public:
    virtual ~CNMWSAssocSerialKeyEvent();
};

class CNMWSGetAssocSerialKeyFunc : public CNMFunc
{
public:
    virtual ~CNMWSGetAssocSerialKeyFunc();
};

class CNMWSSendWBMessageFunc : public CNMFunc
{
public:
    virtual ~CNMWSSendWBMessageFunc();
};

class CNMWSWhiteBoardAckReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMWSWhiteBoardAckReceivedEvent();
};

class CNMWSWhiteBoardMsgReceivedEvent : public CNMEvent
{
public:
    virtual ~CNMWSWhiteBoardMsgReceivedEvent();
};

class CNMWriteToWiselogFunc : public CNMFunc
{
public:
    virtual ~CNMWriteToWiselogFunc();
};

// The payload between the CNMEvent base and the embedded CNMVirtualFriendInfo starts at +0x30.
class CNMVirtualFriendInfoChangedEvent : public CNMEvent
{
public:
    char m_reserved[0x30 - sizeof(CNMEvent)];
    CNMVirtualFriendInfo m_friendInfo;                          // +0x30
};

// @0x1415eef30  CNMVirtualFriendInfo::~CNMVirtualFriendInfo
void FUN_1415eef30(CNMVirtualFriendInfo* p)
{
    p->CNMVirtualFriendInfo::~CNMVirtualFriendInfo();
}

// @0x1415eef50  CNMVirtualFriendInfoChangedEvent::~CNMVirtualFriendInfoChangedEvent
void FUN_1415eef50(CNMVirtualFriendInfoChangedEvent* p)
{
    p->m_friendInfo.CNMVirtualFriendInfo::~CNMVirtualFriendInfo();
    p->CNMEvent::~CNMEvent();
}

// @0x1415eef80  CNMVirtualUserInfo::~CNMVirtualUserInfo
void FUN_1415eef80(CNMVirtualUserInfo* p)
{
    p->CNMVirtualUserInfo::~CNMVirtualUserInfo();
}

// @0x1415eefa0  CNMWSAssocSerialKeyEvent::~CNMWSAssocSerialKeyEvent
void FUN_1415eefa0(CNMWSAssocSerialKeyEvent* p)
{
    p->CNMEvent::~CNMEvent();
}

// @0x1415eefc0  CNMWSGetAssocSerialKeyFunc::~CNMWSGetAssocSerialKeyFunc
void FUN_1415eefc0(CNMWSGetAssocSerialKeyFunc* p)
{
    p->CNMFunc::~CNMFunc();
}

// @0x1415eefe0  CNMWSSendWBMessageFunc::~CNMWSSendWBMessageFunc
void FUN_1415eefe0(CNMWSSendWBMessageFunc* p)
{
    p->CNMFunc::~CNMFunc();
}

// @0x1415ef000  CNMWSWhiteBoardAckReceivedEvent::~CNMWSWhiteBoardAckReceivedEvent
void FUN_1415ef000(CNMWSWhiteBoardAckReceivedEvent* p)
{
    p->CNMEvent::~CNMEvent();
}

// @0x1415ef020  CNMWSWhiteBoardMsgReceivedEvent::~CNMWSWhiteBoardMsgReceivedEvent
void FUN_1415ef020(CNMWSWhiteBoardMsgReceivedEvent* p)
{
    p->CNMEvent::~CNMEvent();
}

// @0x1415ef040  CNMWriteToWiselogFunc::~CNMWriteToWiselogFunc
void FUN_1415ef040(CNMWriteToWiselogFunc* p)
{
    p->CNMFunc::~CNMFunc();
}
