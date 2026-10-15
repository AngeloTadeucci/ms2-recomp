// mapmetamanager.h - CMapMetaManager: lazily caches one egf property map (property 0x25000038, utf8string key ->
// EntityID value) of a map-meta entity. Owning unit: ?\mapmetamanager.cpp (0x141478090-0x14147a2a0, dir client\ms2).
// Ref-counted (NiRefObject) with its own NiRTTI (0x143add980). Field names inferred.
#pragma once
#include "ms2/ms2layout.h"
#include <NiRefObject.h>
#include <NiRTTI.h>
#include <atlcoll.h>
#include <efd/utf8string.h>
#include <egf/EntityID.h>

class CMapMetaManager : public NiRefObject
{
public:
    static const NiRTTI ms_RTTI;                                // 0x143add980

    CMapMetaManager(egf::EntityID entityID);                    // 0x141478090
    virtual ~CMapMetaManager();                                 // 0x141478130, ??_G 0x141478b80
    virtual const NiRTTI* GetRTTI() const;                      // slot 2, 0x141478ea0

    // Value of the meta property for `key`; loads every key from the entity on first use. Returns EntityID(0) if absent.
    egf::EntityID FUN_141478180(efd::utf8string key);

public:
    egf::EntityID m_entityID;                                   // +0x10
    ATL::CRBMap<efd::utf8string, egf::EntityID> m_values;       // +0x18
};
MS2_CHECK_SIZE(CMapMetaManager, 0x48);
MS2_CHECK_OFFSET(CMapMetaManager, m_values, 0x18);
