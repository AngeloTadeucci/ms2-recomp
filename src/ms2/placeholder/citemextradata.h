// CItemExtraData: RTTI table 0x142d61678, allocation size 0x58 in 0x14053e6c0.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
class ItemColorEx;
class CItemData;
template <class T> class MS2Ptr;
class CItemExtraData:public CPtred {
public:
    CItemExtraData();                                            // 0x140598e60: inits +0x18..+0x28 and the containers from +0x30
                                                                 // (an implicit ctor left them garbage in DLL-allocated objects)
    bool FUN_140599480(const ItemColorEx&, MS2Ptr<CItemData>);   // 0x140599480 (itemugcmesh.cpp: bound into a Delegate)
    virtual ~CItemExtraData();
    virtual int vfunc_1(const CItemExtraData*);
    virtual int vfunc_2(const CItemExtraData*);
    virtual void vfunc_3(const CItemExtraData*);
    virtual void vfunc_4(void*);
    virtual void vfunc_5(COutputStream&);
    virtual void vfunc_6(CInputStream&);
    virtual void vfunc_7(COutputStream&);
    virtual void vfunc_8(CInputStream&);
private:
    void* unknown18;void* unknown20;void* unknown28;void* unknown30;
    void* unknown38;void* unknown40;void* unknown48;void* unknown50;
};
MS2_CHECK_SIZE(CItemExtraData,0x58);

// The extra-data subclasses CItemData::FUN_14053e6c0 allocates per item kind; only their sizes and constructors are known.
class CDecalExtraData : public CItemExtraData {     // decal items, 0x68 bytes
public:
    CDecalExtraData();                              // 0x14059a400
private:
    unsigned char unknown58[0x68 - 0x58];
};
MS2_CHECK_SIZE(CDecalExtraData,0x68);
class CHairExtraData : public CItemExtraData {      // hair items, 0xa0 bytes
public:
    CHairExtraData();                               // 0x14059a8a0
private:
    unsigned char unknown58[0xa0 - 0x58];
};
MS2_CHECK_SIZE(CHairExtraData,0xa0);
class CCapExtraData : public CItemExtraData {       // cap items, 0x90 bytes
public:
    CCapExtraData();                                // 0x14059b350
private:
    unsigned char unknown58[0x90 - 0x58];
};
MS2_CHECK_SIZE(CCapExtraData,0x90);
