// Cube (RTTI), heap-only declaration from ctor1408b4a00/dtor1408b4da0.
// Allocation 0x110 at1410bc260's call path. Unnamed scalar fields retain their offsets.
#pragma once
#include <afx.h>
#include <efd/SmartPointer.h>
#include <egf/Entity.h>
#include <NiPoint3.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
class CubeItemInfo;
class ObjectWeaponInfo;
class NoticeCubeInfo;
struct Unk_CubeTextRecord {
    int field0;
    CStringW text8;
    int field10,field14;
    CStringW text18;
};
MS2_CHECK_SIZE(Unk_CubeTextRecord,0x20);
class Cube : public CPtred {
public:
    Cube();
    virtual ~Cube();
    unsigned __int64 field18;
    efd::SmartPointer<egf::Entity> entity;
    Unk_PayloadPtr<CubeItemInfo> item;
    Unk_Int3 position;
    int field44,field48,field4c,field50,field54,field58,field5c;
    int field60,field64,field68,field6c,field70,field74,field78,field7c;
    Unk_PayloadPtr<ObjectWeaponInfo> weapon;
    NiPoint3 offset;
    CString textA0;
    int fieldA8,fieldAc,fieldB0,fieldB4,fieldB8;
    NiPoint3 pointBc;
    int fieldC8,fieldCc;
    bool fieldD0;
    int fieldD4,fieldD8;
    Unk_CubeTextRecord record;
    Unk_PayloadPtr<NoticeCubeInfo> notice;
    struct Unk_StreamPoint FUN_1408b5370();                 // the world position of the cube
};
MS2_CHECK_SIZE(Cube,0x110);
MS2_CHECK_OFFSET(Cube,entity,0x20);
MS2_CHECK_OFFSET(Cube,item,0x28);
MS2_CHECK_OFFSET(Cube,position,0x38);
MS2_CHECK_OFFSET(Cube,weapon,0x80);
MS2_CHECK_OFFSET(Cube,offset,0x90);
MS2_CHECK_OFFSET(Cube,textA0,0xa0);
MS2_CHECK_OFFSET(Cube,pointBc,0xbc);
MS2_CHECK_OFFSET(Cube,record,0xe0);
MS2_CHECK_OFFSET(Cube,notice,0x100);
