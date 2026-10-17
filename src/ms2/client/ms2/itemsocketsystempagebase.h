// ItemSocketSystemPageBase: RTTI 9-slot CPtred-derived interface.
// Member names are inferred. Constructor 0x140f6c680; deleting destructor proves 0x30 bytes.
#pragma once
#include "ms2/placeholder/asdisplayobject.h"
#include <atlcoll.h>
class CItem;
class ItemInfoSlot;
class CInPacket;

class ItemSocketSystemPageBase : public CPtred
{
public:
    ItemSocketSystemPageBase();
    virtual ~ItemSocketSystemPageBase();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count) { return 0; }
    virtual void vfunc_4(MS2Ptr<AScript> root);
    virtual void vfunc_5(CInPacket* packet) {}
    virtual void vfunc_6();
    virtual void vfunc_7(MS2Ptr<AScript> root);
    virtual void vfunc_8(CInPacket* packet);

    void FUN_140f6d620(int enabled);
    int FUN_140f6d670();
    MS2Ptr<CItem> FUN_140f6cce0(int itemId, int grade);
    MS2Ptr<CItem> FUN_140f6ce00(int itemId, int grade, bool bindOwner, MS2Ptr<CItem> source);
    ItemInfoSlot* FUN_140f6d300(const CString& name);
    ItemInfoSlot* FUN_140f6d340(const CString& name, MS2Ptr<CItem> item);
    ItemInfoSlot* FUN_140f6d400(const CString& name);
    MS2Ptr<CItem> FUN_140f6d6b0(__int64 uid, CAtlArray<MS2Ptr<CItem>>& items, int* index);
    MS2Ptr<CItem> FUN_140f6d840(CAtlArray<MS2Ptr<CItem>>& items, unsigned index);
    void FUN_140f6d8f0(CAtlArray<MS2Ptr<CItem>>& items, int first, int second);
    int FUN_140f6e6e0();
    void FUN_140f6e700(__int64 uid);
    void FUN_140f6e780();
protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_root;
    bool m_restoreInventory;
};
MS2_CHECK_SIZE(ItemSocketSystemPageBase, 0x30);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_root, 0x18);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_restoreInventory, 0x28);
