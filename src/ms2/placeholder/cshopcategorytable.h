// cshopcategorytable.h - PLACEHOLDER for CShopCategoryTable (RTTI, 0xa0 bytes; vftables at +0 TSingleton, +8
// CValidData<CShopCategoryTable>, +0x10). NOT an original header. Code owner: ?\shopcategorytable.cpp (ctor 0x1407ca7a0).
// Only what the merat market (meratmarketbasketinfo.cpp) reads is modelled; the bases at +8/+0x10 are folded into the
// opaque tail, so the class must not be constructed or destroyed by value outside its owner unit.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// TPtr<T> to a boxed value (TPtredDummy<T>: a CPtred header 0x18 bytes before the pointee): only the reading side.
template <class T>
class Unk_ShopCategoryBoxPtr
{
public:
    ~Unk_ShopCategoryBoxPtr();
    T* get() const;
    T* operator->() const;

private:
    void Release();
    static TPtredDummy<T>* Owner(T* p);
    static void Ref(CPtred* p);
    void ReleaseImpl(void*);
    void* m_00;
    T* m_p;
};

template <class T> Unk_ShopCategoryBoxPtr<T>::~Unk_ShopCategoryBoxPtr() { Release(); }
template <class T> T* Unk_ShopCategoryBoxPtr<T>::get() const { return m_p; }
template <class T> T* Unk_ShopCategoryBoxPtr<T>::operator->() const { return m_p; }
template <class T> void Unk_ShopCategoryBoxPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> TPtredDummy<T>* Unk_ShopCategoryBoxPtr<T>::Owner(T* p)
{
    return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value));
}
template <class T> void Unk_ShopCategoryBoxPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_ShopCategoryBoxPtr<T>::ReleaseImpl(void*)
{
    CPtred* owner = Owner(m_p);
    if (CPtred::ReleasePtred(owner) == 0) { Ref(owner); CPtred::DeletePtred(owner); }
}

class CShopCategoryTable : public TSingleton<CShopCategoryTable>
{
public:
    // A shop tab (RTTI struct CShopCategoryTable::TabInfo, vftable 0x142d8e710, 3 slots); only the fields read here.
    struct TabInfo : public CPtred
    {
        char m_pad18[0x18];
        CStringA m_strCategories;           // +0x30 comma-separated item categories
        int m_n38;
        int m_nId;                          // +0x3c tab id
        CAtlList<MS2Ptr<TabInfo> > m_subTabs;   // +0x40
    };
    typedef CAtlList<MS2Ptr<TabInfo> > TabList;

    CShopCategoryTable();                   // 0x1407ca7a0
    // @0x1406a9940
    static CShopCategoryTable* CreateInstance() { return s_instance ? GetInstance() : new CShopCategoryTable; }

    Unk_ShopCategoryBoxPtr<TabList> FUN_1407cb490(int nShopType);   // the tabs of one shop (by currency/shop id)

private:
    MS2_LAYOUT_FRIEND;
    char m_pad08[0x98];
};
MS2_CHECK_SIZE(CShopCategoryTable, 0xa0);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_strCategories, 0x30);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_nId, 0x3c);
MS2_CHECK_OFFSET(CShopCategoryTable::TabInfo, m_subTabs, 0x40);
