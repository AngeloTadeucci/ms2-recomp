// CItemExtraData: RTTI table 0x142d61678, allocation size 0x58 in 0x14053e6c0.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
class ItemColorEx;
class CItemData;
template <class T> class MS2Ptr;
class CItemExtraData:public CPtred {
public:
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
