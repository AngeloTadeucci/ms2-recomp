// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDialogEventListener / UIDialogEventDispatcher: the dialog event broadcast.
// MS2-UNIT: ?\uidialogeventlistener.cpp
// MS2-RANGE: 0x141927f70-0x141928c80 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x1419283a0 ; unique
// MS2-PIN: ??1?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA@XZ 0x141928410 ; unique
// MS2-PIN: ?CallDestructors@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@CAXPEAPEAX_K@Z 0x141928650 ; unique
// MS2-PIN: ??A?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAAEAPEAX_K@Z 0x141928690 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@AEAA_N_K@Z 0x1419286e0 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@PEAX@ATL@@SAXPEAPEAX0_K@Z 0x141928880 ; unique
// MS2-PIN: ?RemoveAt@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAAX_K0@Z 0x1419288e0 ; unique
// MS2-PIN: ?SetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_N_KH@Z 0x1419289d0 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?GetCount@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEBA_KXZ 0x1419286d0
// MS2-PIN: ?Add@?$CAtlArray@PEAXV?$CElementTraits@PEAX@ATL@@@ATL@@QEAA_KPEAX@Z 0x141928530
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidialogeventlistener.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/uidialogeventlistener.h"
#include "ms2/placeholder/uidialogeventdispatcher.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x141927f70
UIDialogEventListener::UIDialogEventListener()
{
}

// @0x141927f90
UIDialogEventListener::~UIDialogEventListener()
{
}

// @0x141927fb0
UIDialogEventDispatcher::UIDialogEventDispatcher()
{
}

// @0x141928000
UIDialogEventDispatcher::~UIDialogEventDispatcher()
{
    m_8.RemoveAll();
}

// MS2-FUNCTIONAL: the exe's CAtlArray<void*>::Add takes the element by reference (older ATL); ours takes it by value
// @0x141928050
void UIDialogEventDispatcher::FUN_141928050(void* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
            return;
    }
    m_8.Add(pListener);
}

// @0x1419280e0
void UIDialogEventDispatcher::FUN_1419280e0(void* pListener)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        if (pListener == m_8[i])
        {
            m_8.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x141928170
void UIDialogEventDispatcher::vfunc_1(int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIDialogEventListener* pListener = static_cast<UIDialogEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_dl_1(n);
    }
}

// @0x141928200
void UIDialogEventDispatcher::vfunc_2(int n)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIDialogEventListener* pListener = static_cast<UIDialogEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_dl_2(n);
    }
}

// @0x141928290
void UIDialogEventDispatcher::vfunc_3(void* p)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIDialogEventListener* pListener = static_cast<UIDialogEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_dl_3(p);
    }
}

// @0x141928320
void UIDialogEventDispatcher::vfunc_4(void* p)
{
    for (size_t i = 0; i < m_8.GetCount(); i++)
    {
        UIDialogEventListener* pListener = static_cast<UIDialogEventListener*>(m_8[i]);
        if (pListener)
            pListener->vfunc_dl_4(p);
    }
}
