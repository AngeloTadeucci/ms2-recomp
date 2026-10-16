// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#3
// MS2-RANGE: 0x1410b68a0-0x1410d5bc0 .text$mn
// MS2-RANGE: 0x1400e6230-0x1400e6420 .text$di
// MS2-PIN: ??0Unk_CMISFlags3@@QEAA@XZ 0x140b68e60
// MS2-PIN: ??_7CubeMapInformationService@@6BISystemService@efd@@@ 0x142eb3960
// MS2-PIN: ??_7CubeMapInformationService@@6B?$TSingleton@VCubeMapInformationService@@@@@ 0x142eb39e8
// MS2-PIN: ??_7?$TSingleton@VCubeMapInformationService@@@@6B@ 0x142eb3950
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wregister"
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cubemapinformationservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "cubemapinformationservice_3.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <efd/MessageService.h>
#include <efd/ISystemService.h>
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#define MS2_STATICS_A_BEFORE_CONDITION "cubemapinformationservice_statics.h"
#include "ms2/placeholder/header_statics_a.h"
#undef MS2_STATICS_A_BEFORE_CONDITION
static UICommon::CMyPCKeyInputController s_keyInput;                // @0x1400e63f0

class CCubeMotionManager;
void FUN_14112ded0();                                                // CCubeMotionManager::DestroyInstance
CCubeMotionManager* FUN_14112dd30();                                 // CCubeMotionManager::CreateInstance
efd::MessageService* FUN_1413f9830();
void FUN_1410db490(efd::IDependencyRegistrar*, unsigned);
void FUN_1410db4c0(efd::IDependencyRegistrar*, unsigned);
void FUN_1410db460(efd::IDependencyRegistrar*, unsigned);
unsigned char* FUN_1411282d0(Unk_CMISTree<280>*, const int*);
int* FUN_141128250(Unk_CMISTree<281>*, const int*);
void FUN_14114fae0(Unk_CMISTree<282>*);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(CubeMapInformationService);
CubeMapInformationService* TSingleton<CubeMapInformationService>::s_instance = 0;
inline TSingleton<CubeMapInformationService>::TSingleton() { s_instance = static_cast<CubeMapInformationService*>(this); }

template <unsigned __int64 N> Unk_CMISTree<N>::Unk_CMISTree() : head(0), count(0) {}
template <unsigned __int64 N> Unk_CMISTree<N>::~Unk_CMISTree() {}
Unk_CMISFlags3::Unk_CMISFlags3() : a(false), b(false), c(false) {}

// @0x1410b68a0
FittingDollData::FittingDollData() {
    kind=0;instanceId=0;field28=0;
    position=efd::Point3::ZERO;
    rotation=efd::Point3::ZERO;
    field44=0;field48=0;items.RemoveAll();
}
// @0x1410b6990
FittingDollData::~FittingDollData() { items.RemoveAll(); }

// @0x1410b69e0
CubeMapInformationService::CubeMapInformationService() : f158(0), s1c8(L""), s1d0(L""), f2d8(s_cubeMapNone)
{
    FUN_14112dd30();
    for (int i = 0; i < 3; i++)
        f318[i] = 0;
    static_cast<Unk_Int3&>(p300) = Unk_Int3(0, 0, 0);
    static_cast<Unk_Int3&>(p30c) = Unk_Int3(0, 0, 0);
    for (int i = 0; i < 9; i++) {
        int k = i;
        *FUN_1411282d0(&f368, &k) = 0;
    }
    for (int j = 0; j < 9; j++) {
        int k = j;
        *FUN_141128250(&f378, &k) = 0;
    }
    a388.RemoveAll();
    a3a8.RemoveAll();
    FUN_14114fae0(&f3c8);
    t3e0.FUN_1408687f0();
}
// @0x1410b7240
CubeMapInformationService::~CubeMapInformationService()
{
    FUN_14112ded0();
}
// @0x1410b7680
const char* CubeMapInformationService::GetDisplayName() const { return "CubeMapInformationService"; }

// @0x1410ce800
efd::SyncResult CubeMapInformationService::OnPreInit(efd::IDependencyRegistrar* pRegistrar)
{
    FUN_1410db490(pRegistrar, 1);
    FUN_1410db4c0(pRegistrar, 1);
    FUN_1410db460(pRegistrar, 1);
    return efd::SyncResult_Success;
}
// @0x1410ce850
efd::AsyncResult CubeMapInformationService::OnInit()
{
    FUN_1413f9830()->Subscribe(this, s_cubeMapCategory, 0, false);
    return efd::AsyncResult_Complete;
}

// @0x1410c3000
int CubeMapInformationService::FUN_1410c3000() { return f1b0; }
// @0x1410c3100
int CubeMapInformationService::FUN_1410c3100() { return f1b4; }
// @0x1410c3120
void CubeMapInformationService::FUN_1410c3120(int v) { f1b4 = v; }
// @0x1410c3140
int CubeMapInformationService::FUN_1410c3140() { return f1b8; }
// @0x1410c3160
void CubeMapInformationService::FUN_1410c3160(int v) { f1b8 = v; }
// @0x1410c3180
__int64 CubeMapInformationService::FUN_1410c3180() { return f1c0; }
// @0x1410c31a0
void CubeMapInformationService::FUN_1410c31a0(__int64 v) { f1c0 = v; }
// @0x1410c31d0
CStringW CubeMapInformationService::FUN_1410c31d0() { return s1c8; }
// @0x1410c3220
void CubeMapInformationService::FUN_1410c3220(const CStringW& s) { s1c8 = s; }
// @0x1410c3260
CStringW CubeMapInformationService::FUN_1410c3260() { return s1d0; }
// @0x1410c32b0
void CubeMapInformationService::FUN_1410c32b0(const CStringW& s) { s1d0 = s; }
// @0x1410c32f0
int CubeMapInformationService::FUN_1410c32f0() { return f1d8; }
// @0x1410c3310
void CubeMapInformationService::FUN_1410c3310(int v) { f1d8 = v; }
// @0x1410c33f0
int CubeMapInformationService::FUN_1410c33f0() { return f2f0; }
// @0x1410c3410
void CubeMapInformationService::FUN_1410c3410(int v) { f2f0 = v; }
// @0x1410c3430
int CubeMapInformationService::FUN_1410c3430() { return f2f4; }
// @0x1410c3450
void CubeMapInformationService::FUN_1410c3450(int v) { f2f4 = v; }
// @0x1410c3470
int CubeMapInformationService::FUN_1410c3470() { return f2f8; }
// @0x1410c3490
void CubeMapInformationService::FUN_1410c3490(int v) { f2f8 = v; }
// @0x1410c34b0
int CubeMapInformationService::FUN_1410c34b0() { return f2fc; }
// @0x1410c34d0
void CubeMapInformationService::FUN_1410c34d0(int v) { f2fc = v; }
// @0x1410c34f0
Unk_CMISFlags3 CubeMapInformationService::FUN_1410c34f0() { return f418; }
// @0x1410c3530
void CubeMapInformationService::FUN_1410c3530(Unk_CMISFlags3 v) { f418 = v; }
// @0x1410c3560
void CubeMapInformationService::FUN_1410c3560(bool v) { f418.a = v; }
// @0x1410c3580
void CubeMapInformationService::FUN_1410c3580(bool v) { f418.b = v; }
// @0x1410c35a0
void CubeMapInformationService::FUN_1410c35a0(bool v) { f418.c = v; }
// @0x1410c35c0
bool CubeMapInformationService::FUN_1410c35c0() { return f330 == 1; }
// @0x1410c3600
bool CubeMapInformationService::FUN_1410c3600(int v)
{
    if (f330 == v)
        return true;
    return false;
}
// @0x1410c3630
void CubeMapInformationService::FUN_1410c3630(int v) { f330 = v; }
// @0x1410c3650
int CubeMapInformationService::FUN_1410c3650() { return f330; }
