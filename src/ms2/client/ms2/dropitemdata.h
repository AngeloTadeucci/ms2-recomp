// dropitemdata.h - CDropItemData (RTTI .?AVCDropItemData@@, 0x28 bytes, base CPtred, only the deleting destructor virtual): one
// row of Table/DropIcon.xml, the shadow of a dropped item (<dropitem id shadowscale shadowbias/>). The rows are cached in an
// id -> row ATL::CAtlMap that the loader fills on the first miss.
// Header name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>

// The shadow parameters of a row (ctor 0x141193010).
struct Unk_DropShadow
{
    Unk_DropShadow() : m_fScale(100.0f), m_fBias(5.0f) {}
    float m_fScale;
    float m_fBias;
};

class CDropItemData : public CPtred
{
public:
    CDropItemData();                            // 0x141192960
    virtual ~CDropItemData();                   // 0x1411929b0

    // 0x1411929e0: the row of an item id (null when the table has none); loads DropIcon.xml when the cache misses.
    static MS2Ptr<CDropItemData> Get(int nId);

    int m_nId;                                  // +0x18 "id"
    Unk_DropShadow m_shadow;                    // +0x1c "shadowscale" (100.0 by default), +0x20 "shadowbias" (5.0)
};
MS2_CHECK_SIZE(CDropItemData, 0x28);
MS2_CHECK_OFFSET(CDropItemData, m_shadow, 0x1c);
