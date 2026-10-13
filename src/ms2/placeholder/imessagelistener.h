// imessagelistener.h - PLACEHOLDER for IMessageListener and UIMsg. NOT an original header.
// IMessageListener: RTTI .?AVIMessageListener@@, vftable 0x142ea6a48 = { _purecall }: an interface with one pure
// virtual and no virtual destructor. UISwfEntity has it at +0x18; the slot is overridden by UISwfEntity
// (0x1422dc790) and UICutSceneMovie (0x14190f980). The name OnMessage is invented (the only slot of a listener).
// UIMsg: RTTI .?AVUIMsg@@ (80 bytes, bases ASData, CPtred, vftable 0x1431152e0, ddtor 0x1422e4530).
#pragma once

class UISwfEntity;

class UIMsg
{
public:
    int FUN_1422e4520();                // nonzero: handled/cancelled? (UICutSceneMovie::OnMessage returns 0)
    int FUN_1422b8a10();                // result code; 0 = OK/yes button (switched on)
};

class IMessageListener
{
public:
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg) = 0;   // slot 0
};
