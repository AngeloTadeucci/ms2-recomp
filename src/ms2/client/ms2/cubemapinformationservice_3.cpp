// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#3
// MS2-RANGE: 0x1410b68a0-0x1410d5bc0 .text$mn
// MS2-RANGE: 0x1400e6230-0x1400e6420 .text$di
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister"
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
// @0x1410b68a0
FittingDollData::FittingDollData() {
    kind=0;instanceId=0;field28=0;
    position=efd::Point3::ZERO;
    rotation=efd::Point3::ZERO;
    field44=0;field48=0;items.RemoveAll();
}
// @0x1410b6990
FittingDollData::~FittingDollData() { items.RemoveAll(); }
// Main service recovery awaits shared CItemData cube/model fields and the
// typed cube-service container families in the deferred 141122xxx tail.
// Constructors/destructors are not hooked.
