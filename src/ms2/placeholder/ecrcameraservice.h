// ecrcameraservice.h - PLACEHOLDER for the Gamebryo GameFramework camera service (ecr::CameraService, system service
// id kCLASSID_CameraService 0x07002002) and the game's service-manager access. NOT an original header; the ecr headers
// are not on the game include path and MS2's efd::ServiceManager has a different vftable from the SDK's
// (GetSystemService is slot 14 here), so the manager is a stand-in (Unk_ServiceManager).
//
// Usage (CCameraMode, 0x140afe4b0):
//     efd::SmartPointer<ecr::CameraService> spCamera = g_143b059e8.GetSystemServiceAs<ecr::CameraService>();
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
#include <efd/IBase.h>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"

class Unk_CameraObject;     // camera object owned by the service (methods FUN_142008xxx)
class Unk_CameraTarget;     // what FUN_1413f98d0 returns (the active camera entity)

namespace ecr
{
class CameraService : public efd::ISystemService
{
public:
    static const efd::ClassID CLASS_ID = 0x07002002;

    Unk_CameraObject* FUN_14200aae0(Unk_CameraTarget* pTarget);    // camera object of the target (or 0)
    void FUN_1414af480(Unk_CameraObject* pCamera);                  // applies / refreshes it
};
} // namespace ecr

class Unk_CameraObject
{
public:
    void FUN_142008e90(float f);
};

// MS2's efd::ServiceManager (only the slot used here is declared).
class Unk_ServiceManager
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13();
    virtual efd::ISystemService* GetSystemService(efd::UInt32 idSysSer) const;     // slot 14

    // efd::ServiceManager::GetSystemServiceAs<T>() (ServiceManager.inl)
    template <typename T> T* GetSystemServiceAs() const
    {
        efd::ISystemService* pService = GetSystemService(T::CLASS_ID);
        T* pResult = EE_DYNAMIC_CAST(T, pService);
        return pResult;
    }
};

// The global at 0x143b059e8: the game framework object; its first member is a smart pointer to the service manager
// (efd::SmartPointer<ServiceManager>::operator-> is 0x1401cd190, a COMDAT of another obj).
class Unk_AppFramework
{
public:
    template <typename T> T* GetSystemServiceAs()
    {
        return m_spServiceManager->GetSystemServiceAs<T>();
    }

    efd::SmartPointer<Unk_ServiceManager> m_spServiceManager;   // +0x00
};
extern Unk_AppFramework g_143b059e8;
