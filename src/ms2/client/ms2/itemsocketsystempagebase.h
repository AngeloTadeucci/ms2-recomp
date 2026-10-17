// ItemSocketSystemPageBase: RTTI 9-slot CPtred-derived interface.
// Member names are inferred. Constructor 0x140f6c680; deleting destructor proves 0x30 bytes.
#pragma once
#include "ms2/placeholder/asdisplayobject.h"

class ItemSocketSystemPageBase : public CPtred
{
public:
    ItemSocketSystemPageBase();
    virtual ~ItemSocketSystemPageBase();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count);
    virtual void vfunc_4(MS2Ptr<AScript> root);
    virtual void vfunc_5(void* packet);
    virtual void vfunc_6();
    virtual void vfunc_7(MS2Ptr<AScript> root);
    virtual void vfunc_8(void* packet);

    void FUN_140f6d620(int enabled);
    int FUN_140f6d670();
protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASMovieClip> m_root;
    bool m_restoreInventory;
};
MS2_CHECK_SIZE(ItemSocketSystemPageBase, 0x30);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_root, 0x18);
MS2_CHECK_OFFSET(ItemSocketSystemPageBase, m_restoreInventory, 0x28);
