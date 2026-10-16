// CItemData, RTTI and 0x390 allocation/layout from itemdata.cpp.
// Heap-only placeholder: inventory reads stack limit and function metadata.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/cobjectcount.h"
#include "ms2/ms2layout.h"
#include <efd/Point3.h>

// <install> element of an item XML (commonfiles\itemdatastruct.cpp): default ctor 0x1405481f0,
// XML read 0x140548320, XML write 0x1405485b0 (skipped when equal to a static default), operator!= 0x140548aa0
// (operator== 0x140548a50). Field names are the XML attribute names; the struct name is invented.
struct ItemInstallData {
    CString asset;            // +0x00 "asset"
    CString preset;           // +0x08 "preset"
    int space;                // +0x10 "space": placement mask, tested as (space & CFieldData indoor mask) == mask
    int placeable;            // +0x14 "placeable"
    int stackable;            // +0x18 "stackable"
    int attachable;           // +0x1c "attachable"
    int wall;                 // +0x20 "wall"
    int cubeProp;             // +0x24 "cubeProp"
    int animatable;           // +0x28 "animatable"
    int generatePhysX;        // +0x2c "generatePhysX"
    int unchangeable;         // +0x30 "unchangeable"
    int cannotStackAttach;    // +0x34 "cannotStackAttach"
    unsigned objCode;         // +0x38 "objCode" (read as unsigned, 0x140873220)
    float staticAngle;        // +0x3c "staticAngle"
    efd::Point3 physXdimension; // +0x40 "physXdimension" "%.6f, %.6f, %.6f"
    int unknown4c;            // +0x4c alignment
    CString mapAttribute;     // +0x50 "mapAttribute"
    int propCollisionGroup;   // +0x58 "propCollisionGroup"
    bool useInstancing;       // +0x5c "useInstancing" (default true)
    bool FUN_140548d10();     // 0x140548d10 (ugccubepalette.cpp)
    bool FUN_140548cd0();     // 0x140548cd0
};
MS2_CHECK_SIZE(ItemInstallData, 0x60);
MS2_CHECK_OFFSET(ItemInstallData, space, 0x10);
MS2_CHECK_OFFSET(ItemInstallData, cubeProp, 0x24);
MS2_CHECK_OFFSET(ItemInstallData, animatable, 0x28);
MS2_CHECK_OFFSET(ItemInstallData, objCode, 0x38);
MS2_CHECK_OFFSET(ItemInstallData, physXdimension, 0x40);
MS2_CHECK_OFFSET(ItemInstallData, mapAttribute, 0x50);
MS2_CHECK_OFFSET(ItemInstallData, useInstancing, 0x5c);

class CItemData : public CPtred, public CValidData<CItemData>, public CObjectCount<CItemData> {
public:
    virtual ~CItemData();
    int FUN_14053c560();     // 0x14053c560 (uiitemenchantdialog.cpp)
    bool FUN_14053d510();    // 0x14053d510
    int FUN_14053c6f0();     // 0x14053c6f0
    int FUN_14053c510();     // 0x14053c510 return the item id (+0x20; sb4, clonecube)
    int FUN_14053fdb0();     // 0x14053fdb0 (ugccubepalette.cpp) required level, 0 when none
    bool FUN_14053cde0();    // 0x14053cde0 unique (non-stacking) item
    int FUN_14053dd30();     // 0x14053dd30 the id of the npc the item summons
    bool FUN_14053d6f0();    // 0x14053d6f0 UGC item
    bool FUN_14053cb80();    // 0x14053cb80
    CString FUN_14053fdd0(); // 0x14053fdd0 the item's display name
    unsigned char unknown20[0x68];
    unsigned stackLimit;
    unsigned char unknown8c[0x11c];
    ItemInstallData install;  // +0x1a8 <install> (CItemData operator!= 0x14053c170 compares it with 0x140548aa0)
    CString cubeTextureName; // +0x208, read by CNifCubeGuide::FUN_1410b0680
    unsigned char unknown210[0x80];
    CStringW functionName;
    CStringW functionName2;
    int functionArg0, functionArg1, functionArg2;
    int unknown2ac;
    CStringW functionParameter;
    unsigned char unknown2b8[0xd8];
};
MS2_CHECK_SIZE(CItemData, 0x390);
MS2_CHECK_OFFSET(CItemData, stackLimit, 0x88);
MS2_CHECK_OFFSET(CItemData, install, 0x1a8);
MS2_CHECK_OFFSET(CItemData, cubeTextureName, 0x208);
MS2_CHECK_OFFSET(CItemData, functionName, 0x290);
MS2_CHECK_OFFSET(CItemData, functionParameter, 0x2b0);
