// notifysystem.h - PLACEHOLDER for NotifySystem (RTTI .?AVNotifySystem@@, 0x18 bytes). NOT an original header.
// Bases: TSingleton<NotifySystem> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates: notice name -> handler delegates. Recovered in
// unnamed\unit_140da50e0.cpp (the same obj as PacketHandlerManager / GameEventUserValueManager).
#pragma once

#include <map>
#include <vector>
#include <atlstr.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/delegate.h"

class NotifyObject;
template <class T> class MS2Ptr;

class NotifySystem : public TSingleton<NotifySystem>
{
public:
    NotifySystem();                                         // 0x140da4da0
    virtual ~NotifySystem();
    void RegisterNotify(CStringW strName, Delegate<void(NotifyObject*)> handler);      // 0x140da4e40
    void UnregisterNotify(CStringW strName, Delegate<void(NotifyObject*)> handler);    // 0x140da4eb0
    void Post(MS2Ptr<NotifyObject> spNotify);                                          // 0x140da4fe0
private:
    MS2_LAYOUT_FRIEND;
    std::map<CStringW, std::vector<Delegate<void(NotifyObject*)> > > m_handlers;       // +0x08
};
MS2_CHECK_SIZE(NotifySystem, 0x18);
