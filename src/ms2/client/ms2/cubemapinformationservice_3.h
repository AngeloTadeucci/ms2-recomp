#pragma once
#include <atlcoll.h>
#include <efd/Point3.h>
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/ascript.h"

// RTTI name; layout from 1410b68a0, storage size 0x70.
class FittingDollData : public CPtred {
public:
    FittingDollData();
    virtual ~FittingDollData();
    int kind;
    unsigned __int64 instanceId;
    int field28;
    efd::Point3 position;
    efd::Point3 rotation;
    int field44,field48;
    ATL::CAtlArray<MS2Ptr<CItem>> items;
};
MS2_CHECK_SIZE(FittingDollData,0x70);
MS2_CHECK_OFFSET(FittingDollData,instanceId,0x20);
MS2_CHECK_OFFSET(FittingDollData,position,0x2c);
MS2_CHECK_OFFSET(FittingDollData,rotation,0x38);
MS2_CHECK_OFFSET(FittingDollData,items,0x50);
