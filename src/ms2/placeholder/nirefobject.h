// nirefobject.h - PLACEHOLDER for Gamebryo's NiRefObject (engine/gamebryo/CoreRuntime/EngineLibs/NiMain/NiRefObject.h),
// because the CoreRuntime include dirs are not on the ms2game / progress.py path. NOT an original header. Same layout and
// mangled names as the engine class: 0x10 bytes, vftable 0x142db3f08 (slot 0 deleting dtor, slot 1 DeleteThis),
// ctor 0x14098cbd0, dtor 0x14098cf20, DeleteThis 0x141d16bf0. NiMemObject is efd::MemObject in this Gamebryo.
#pragma once
#ifndef EE_EFD_CONFIG_RELEASE
#define EE_EFD_CONFIG_RELEASE
#endif
#ifndef EE_EFD_NO_IMPORT
#define EE_EFD_NO_IMPORT
#endif
#ifndef EE_USE_NATIVE_STL
#define EE_USE_NATIVE_STL
#endif
#include <efd/MemObject.h>

#include "ms2/ms2layout.h"

class NiRefObject : public efd::MemObject
{
public:
    NiRefObject();
    virtual ~NiRefObject();

protected:
    virtual void DeleteThis();

private:
    unsigned int m_uiRefCount;          // +0x08
};
MS2_CHECK_SIZE(NiRefObject, 0x10);
