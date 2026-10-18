// uiservereventdispatcher.cpp - UIServerEventDispatcher (see uiservereventdispatcher.h): the listener list of the
// TSingleton every server event is dispatched to. The tail of the range is the CAtlArray<void*> block (Add /
// RemoveAt / GrowBuffer / CallDestructors / RelocateElements / GetAt / GetCount) the link took from this file.
// MS2-UNIT: ?\uiservereventdispatcher.cpp
// MS2-RANGE: 0x141347260-0x141347b10 .text$mn
// MS2-PIN: ??_7UIServerEventDispatcher@@6B@ 0x142ef0cc0
// MS2-PIN: ??_7?$TSingleton@VUIServerEventDispatcher@@@@6B@ 0x142eedcb0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiservereventdispatcher.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiservereventdispatcher.h"
#include "ms2/ms2recover.h"

MS2_EMIT_CRT_MEMMOVE_S();

// @0x141347260
UIServerEventDispatcher::UIServerEventDispatcher() : m_listeners()
{
}

// @0x1413472b0
UIServerEventDispatcher::~UIServerEventDispatcher()
{
}

// @0x1413472f0
void UIServerEventDispatcher::AddListener(UIServerEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners.GetAt(i))
            return;
    }
    m_listeners.Add(pListener);
}

// @0x141347380
void UIServerEventDispatcher::RemoveListener(UIServerEventListener* pListener)
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        if (pListener == m_listeners.GetAt(i))
        {
            m_listeners.RemoveAt(i, 1);
            return;
        }
    }
}

// @0x141347410
void UIServerEventDispatcher::vfunc_1()
{
    for (size_t i = 0; i < m_listeners.GetCount(); i++)
    {
        UIServerEventListener* pListener = m_listeners.GetAt(i);
        if (pListener != 0)
            pListener->Notify();
    }
}
