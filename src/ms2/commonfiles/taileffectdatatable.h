// taileffectdatatable.h - TailEffectData / CTailEffectDataTable (RTTI names): the tail effect table read from
// Table/tailEffect.xml (<tailEffect id effectPath endEffectPath distance speed/>). Header name assumed; member
// names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One <tailEffect> row, 0x38 bytes; vftable holds the deleting destructor only.
class TailEffectData : public CPtred
{
public:
    TailEffectData();                   // 0x140853ad0 (the numeric members are left uninitialised)
    // ~TailEffectData (0x140853be0)

    int m_nId;                          // +0x18 "id"
    float m_fDistance;                  // +0x1c "distance"
    float m_fSpeed;                     // +0x20 "speed"
    CString m_strEffectPath;            // +0x28 "effectPath"
    CString m_strEndEffectPath;         // +0x30 "endEffectPath"
};
MS2_CHECK_SIZE(TailEffectData, 0x38);
MS2_CHECK_OFFSET(TailEffectData, m_strEffectPath, 0x28);
MS2_CHECK_OFFSET(TailEffectData, m_strEndEffectPath, 0x30);

// RTTI CTailEffectDataTable, 0x78 bytes (TSingleton at +0).
class CTailEffectDataTable : public TSingleton<CTailEffectDataTable>
{
public:
    typedef MS2SvrPtr<TailEffectData> DataPtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;

    CTailEffectDataTable();             // 0x1408533a0
    virtual ~CTailEffectDataTable();    // 0x140853430

    bool Reload();                      // 0x140853480
    bool Load();                        // 0x1408534b0 tailEffect.xml
    DataPtr GetData(int nId);           // 0x1408537c0 reloads first when the cache is stale

private:
    MS2_LAYOUT_FRIEND;
    DataMap m_map;                      // +0x08
    CCacheData m_cache;                 // +0x50
};
MS2_CHECK_SIZE(CTailEffectDataTable, 0x78);
MS2_CHECK_OFFSET(CTailEffectDataTable, m_map, 0x08);
MS2_CHECK_OFFSET(CTailEffectDataTable, m_cache, 0x50);
