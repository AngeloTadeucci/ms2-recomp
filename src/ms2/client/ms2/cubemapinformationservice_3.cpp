// MS2-UNIT: client\ms2\cubemapinformationservice.cpp#3
// MS2-RANGE: 0x1410b68a0-0x1410d5bc0 .text$mn
// MS2-RANGE: 0x1400e6230-0x1400e6420 .text$di
// MS2-PIN: ??0Unk_CMISFlags3@@QEAA@XZ 0x140b68e60
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VCube@@@@QEAAAEAV1@PEAVCube@@@Z 0x140965090 ; unique
// MS2-PIN: ??0Unk_CMISIntList@@QEAA@XZ 0x1411229d0
// MS2-PIN: ??1Unk_CMISIntList@@QEAA@XZ 0x141125b70
// MS2-PIN: ??0Unk_CMISPt3@@QEAA@AEBUUnk_StreamPoint@@@Z 0x14027dcf0
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
#include "ms2/placeholder/citemdata.h"
#include <efd/MessageService.h>
#include <efd/ISystemService.h>
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/hardwareinstancingservice.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/uihomeinfodialog.h"
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
void FUN_14115ab30(Unk_CMISTree<260>*);
void FUN_1409fabe0(void*);
unsigned char* FUN_141128310(Unk_CMISTree<280>*, const int*);
int* FUN_141128290(Unk_CMISTree<281>*, const int*);
int* FUN_1411280d0(Unk_CMISTree<270>*, const int*);
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
CubeMapInformationService::CubeMapInformationService() : f158(0), s1c8(L""), s1d0(L""), f2d8(reinterpret_cast<const Unk_CMISEntityRef&>(s_cubeMapNone))
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


// ---- callees outside the unit ----
struct Unk_CMISPartyPtr { void* m_p; };                                                     // MS2Ptr<party info>
struct Unk_CMISParty { char m_pad[0x20]; int m_map; int m_key; };
class Unk_CMISRoster { public: int FUN_141527920(__int64 nId); int FUN_141527e00(); void* FUN_141523c50(); void* FUN_141530290(); };
class Unk_CMISWorld
{
public:
    Unk_CMISRoster* FUN_141bd0cc0();                            // the party/roster manager
    int FUN_141bd3060();                                        // the current map id
    int FUN_141bcfd10();                                        // the world state (4 = in field, 6 = loading)
    Unk_PayloadPtr<Unk_CMISObj208> FUN_141bd30a0();             // the current field data
};
Unk_CMISWorld* FUN_1403ed2d0();
class Unk_CMISActor
{
public:
    Unk_StreamPoint FUN_141676880();                            // PCBase member: the facing point
    Unk_StreamPoint FUN_1416767d0();                            // PCBase member: the position
};
void FUN_140a01250(Unk_StreamPoint ptDir, Unk_StreamPoint* pForward, Unk_StreamPoint* pRight);
Unk_Int3 FUN_1408a1430(Unk_StreamPoint pt);                     // the cube cell of a world point
int FUN_1408a13d0(Unk_StreamPoint pt);                          // the cell key of a world point
int FUN_1408a0370(int x, int y, int z);                         // the cell key of a cube point
template <unsigned __int64 N> struct Unk_CMISIter { void* node; };
Unk_CMISIter<281>* FUN_141152210(Unk_CMISTree<281>*, Unk_CMISIter<281>*);
Unk_CMISIter<281>* FUN_141158460(Unk_CMISTree<281>*, Unk_CMISIter<281>*, const int*);
bool FUN_1408b7170(Unk_CMISIter<281>*, Unk_CMISIter<281>*);
Unk_CMISIter<270>* FUN_141151fd0(Unk_CMISTree<270>*, Unk_CMISIter<270>*);
Unk_CMISIter<270>* FUN_141158000(Unk_CMISTree<270>*, Unk_CMISIter<270>*, const int*);
bool FUN_141127740(Unk_CMISIter<270>*, Unk_CMISIter<270>*);
Unk_CMISIter<260>* FUN_141151af0(Unk_CMISTree<260>*, Unk_CMISIter<260>*);
Unk_CMISIter<260>* FUN_141157580(Unk_CMISTree<260>*, Unk_CMISIter<260>*, const int*);
bool FUN_141126d90(Unk_CMISIter<260>*, Unk_CMISIter<260>*);
Unk_CMISIter<272>* FUN_141151d90(Unk_CMISTree<272>*, Unk_CMISIter<272>*);
Unk_CMISIter<272>* FUN_141157ba0(Unk_CMISTree<272>*, Unk_CMISIter<272>*, const int*);
bool FUN_141127680(Unk_CMISIter<272>*, Unk_CMISIter<272>*);
Unk_CMISIter<265>* FUN_141151d30(Unk_CMISTree<265>*, Unk_CMISIter<265>*);
Unk_CMISIter<265>* FUN_141157ac0(Unk_CMISTree<265>*, Unk_CMISIter<265>*, const int*);
bool FUN_141127640(Unk_CMISIter<265>*, Unk_CMISIter<265>*);
__int64 FUN_14115ad10(Unk_CMISTree<259>*);                      // the element count
Unk_CMISIter<261>* FUN_141151c10(Unk_CMISTree<261>*, Unk_CMISIter<261>*);
Unk_CMISIter<261>* FUN_141157820(Unk_CMISTree<261>*, Unk_CMISIter<261>*, const int*);
bool FUN_141126e50(Unk_CMISIter<261>*, Unk_CMISIter<261>*);
Unk_CMISTree<287>* FUN_141127d90(Unk_CMISTree<261>*, const int*);        // operator[]: the column of cubes
Unk_CMISTree<287>* FUN_141127dd0(Unk_CMISTree<261>*, const int*);        // operator[] (const flavour, pair.second)
__int64 FUN_14115adb0(Unk_CMISTree<287>*);                      // the element count
Unk_CMISIter<287>* FUN_140885c40(Unk_CMISTree<287>*, Unk_CMISIter<287>*);
Unk_CMISIter<287>* FUN_140885ca0(Unk_CMISTree<287>*, Unk_CMISIter<287>*, const int*);
bool FUN_140885290(Unk_CMISIter<287>*, Unk_CMISIter<287>*);
MS2Ptr<Cube>* FUN_141128350(Unk_CMISTree<287>*, const int*);
int FUN_1408a03c0(Unk_Int3 pt);                                 // the cell key of a cube point
Unk_Int3 FUN_1408a0400(int nKey);                               // the cube point of a cell key
Unk_CMISIter<278>* FUN_14114db40(Unk_CMISTree<278>*, Unk_CMISIter<278>*);   // begin
Unk_CMISIter<278>* FUN_141151910(Unk_CMISTree<278>*, Unk_CMISIter<278>*);   // end
unsigned char FUN_141127380(Unk_CMISIter<278>*, Unk_CMISIter<278>*);                 // operator!=
int* FUN_141128540(Unk_CMISIter<278>*);                                     // operator*
void FUN_141129a60(Unk_CMISIter<278>*);                                     // operator++
Unk_CMISIter<269>* FUN_14096ad60(Unk_CMISTree<269>*, Unk_CMISIter<269>*);                           // end
Unk_CMISIter<269>* FUN_14096ae20(Unk_CMISTree<269>*, Unk_CMISIter<269>*, const __int64*);            // find
bool FUN_140965380(Unk_CMISIter<269>*, Unk_CMISIter<269>*);
bool FUN_1409654d0(Unk_CMISIter<269>*, Unk_CMISIter<269>*);
Unk_CubeOwnerPtr* FUN_1409656d0(Unk_CMISTree<269>*, const __int64*);                                 // operator[]
void FUN_141156310(Unk_CMISTree<269>*, const __int64*);                                              // erase
void FUN_1411552b0(Unk_CMISTree<270>*, const int*);                                   // erase
void FUN_14114f0e0(Unk_CMISTree<260>*);
void FUN_14114fa40(Unk_CMISTree<259>*);
void FUN_1410b2760(Unk_CMISTree<277>*);
void FUN_14114f360(Unk_CMISTree<262>*);
void FUN_14114f2c0(Unk_CMISTree<261>*);
void FUN_1402237c0(ATL::CAtlArray<Unk_CMISElem458*>*);
struct Unk_CMISPt2 { float x, y; };
Unk_CubeOwnerPtr FUN_1408a0fa0(Unk_CubeOwners& owners, int nGroup, int nBlock);
struct Unk_CMISRes16 { Unk_CMISRes16(const Unk_CMISRes16&); __int64 m_a, m_b; };
Unk_CMISRes16 FUN_1408a15b0(Unk_StreamPoint, Unk_StreamPoint);
Unk_CMISIter<257>* FUN_141152030(Unk_CMISTree<257>*, Unk_CMISIter<257>*);
Unk_CMISIter<257>* FUN_1411580e0(Unk_CMISTree<257>*, Unk_CMISIter<257>*, const Unk_CMISEntityRef*);
bool FUN_141127050(Unk_CMISIter<257>*, Unk_CMISIter<257>*);
void** FUN_141128110(Unk_CMISTree<257>*, const Unk_CMISEntityRef*);
bool FUN_140965240(Unk_PayloadPtr<Unk_CMISObj208>*, void*);
Unk_CMISIter<265>* FUN_14114e010(Unk_CMISTree<265>*, Unk_CMISIter<265>*);       // begin
struct Unk_CMISRefElem { int m_key, m_pad; Unk_CMISEntityRef m_ref; };
Unk_CMISRefElem* FUN_1411286a0(Unk_CMISIter<265>*);                           // operator*
void FUN_141129bd0(Unk_CMISIter<265>*);                                       // operator++
unsigned FUN_140869420();
void FUN_1408a06a0(int, int);
struct Unk_CMISIntPair { int m_key, m_val; };
struct Unk_CMISInsRes { void* m_it; bool m_ok; };
Unk_CMISIter<286>* FUN_140340ff0(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // begin
Unk_CMISIter<286>* FUN_140341f40(Unk_CMISTree<286>*, Unk_CMISIter<286>*);                    // end
Unk_CMISIter<286>* FUN_1404c0270(Unk_CMISTree<286>*, Unk_CMISIter<286>*, const unsigned __int64*);   // find
unsigned char FUN_1403344a0(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
unsigned char FUN_140334210(Unk_CMISIter<286>*, Unk_CMISIter<286>*);
Unk_CMISInsRes* FUN_1404422b0(Unk_CMISTree<286>*, Unk_CMISInsRes*, const unsigned __int64*);   // insert
void FUN_1404bfb40(Unk_CMISTree<286>*, const unsigned __int64*);                               // erase
unsigned __int64* FUN_1408f2950(Unk_CMISIter<286>*);                                           // operator*
void FUN_140334ef0(Unk_CMISIter<286>*);                                                        // operator++
Unk_CMISIter<282>* FUN_1411582a0(Unk_CMISTree<282>*, Unk_CMISIter<282>*, const int*);
Unk_CMISIter<282>* FUN_141152150(Unk_CMISTree<282>*, Unk_CMISIter<282>*);
bool FUN_141127110(Unk_CMISIter<282>*, Unk_CMISIter<282>*);
Unk_CMISIntPair* FUN_1411284e0(Unk_CMISIter<282>*);
bool FUN_141151720(Unk_CMISTree<260>*);
CFieldData* FUN_140885340(Unk_PayloadPtr<Unk_CMISObj208>*);
bool FUN_140374410(int);
unsigned FUN_141bd3060(Unk_CMISWorld*);
Unk_CMISIter<278>* FUN_141157040(Unk_CMISTree<278>*, Unk_CMISIter<278>*, const int*);
const Unk_CMISEntityRef* FUN_1408b76f0(egf::Entity*);                   // &entity id
egf::Entity* FUN_1408a9280(const void* pSp);
void FUN_1409618c0(egf::Entity*, unsigned, Unk_StreamPoint*);   // GetProperty(Point3)
struct Unk_CMISPt3 { float x, y, z; Unk_CMISPt3(const Unk_StreamPoint&); };   // efd::Point3 copy (0x14027dcf0)
struct Unk_CMISRayHit { __int64 m_q0, m_q1, m_q2, m_q3, m_q4, m_q5; egf::Entity* m_pEntity; __int64 m_q7, m_q8, m_q9, m_q10, m_q11, m_q12; };
void FUN_140ad4440(Unk_CMISRayHit*);
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
int FUN_14168a310(CPhysXHelper*, Unk_CMISPt3*, Unk_StreamPoint*, Unk_CMISRayHit*, float, __int64, int);
class Unk_CMISPhysScene
{
public:
    virtual void vf0() = 0; virtual void vf1() = 0; virtual void vf2() = 0; virtual void vf3() = 0;
    virtual void vf4() = 0; virtual void vf5() = 0; virtual void vf6() = 0; virtual void vf7() = 0;
    virtual void RemoveActor(void* pActor) = 0;             // +0x40
};
Unk_CMISPhysScene* FUN_14168a1c0(CPhysXHelper*);
void FUN_14168a540(CPhysXHelper*, int);
void FUN_14168a570(CPhysXHelper*);
void FUN_141bc8e00(Unk_CMISWorld*);
void FUN_1411554c0(Unk_CMISTree<257>*, const Unk_CMISEntityRef*);
void FUN_1411556d0(Unk_CMISTree<258>*, const Unk_CMISEntityRef*);
Unk_CMISEntityRef* FUN_141127ed0(Unk_CMISTree<265>*, const int*);
void FUN_1411547a0(Unk_CMISTree<265>*, const int*);
bool FUN_14028d470(float, float);
extern Unk_StreamPoint DAT_143a08cf8;                                       // up vector
extern Unk_StreamPoint DAT_143b01a60;                                       // zero / fall-through direction
struct Unk_CMISCubeByKey { int first; MS2Ptr<Cube> second; };                // the node value of the cubes by key
void FUN_14114dd70(Unk_CMISTree<260>*, Unk_CMISIter<260>*);                 // begin
bool FUN_1411274c0(Unk_CMISIter<260>*, Unk_CMISIter<260>*);                 // operator!=
Unk_CMISCubeByKey* FUN_1411285e0(Unk_CMISIter<260>*);                       // operator*
void FUN_141129b50(Unk_CMISIter<260>*);                                     // operator++
Unk_CMISIter<260>* FUN_141129b00(Unk_CMISIter<260>*, Unk_CMISIter<260>*, int);        // operator++(int)
int FUN_1408b4f20(Cube*);                                                   // the item id of a cube
__int64 FUN_1408b4f50(Cube*);
int FUN_14053fc10(int);                                                     // the item category
struct Unk_CMISCubeOwner { char m_pad[0x18]; __int64 m_nId; };
Unk_CMISCubeOwner* FUN_1408b4f80(Cube*);                                    // the owner record of a cube
struct Unk_CMISIntList { Unk_CMISIntList(); ~Unk_CMISIntList(); void* m_pFirst; void* m_pLast; void* m_pEnd; };   // 0x18 bytes: the cube keys of a column
Unk_CMISIter<262>* FUN_141151c70(Unk_CMISTree<262>*, Unk_CMISIter<262>*);   // end
Unk_CMISIter<262>* FUN_141157900(Unk_CMISTree<262>*, Unk_CMISIter<262>*, const int*);   // find
bool FUN_1411275c0(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator!=
bool FUN_141126e90(Unk_CMISIter<262>*, Unk_CMISIter<262>*);                 // operator==
Unk_CMISIntList* FUN_141127e10(Unk_CMISTree<262>*, const int*);             // operator[]
void FUN_141126700(Unk_CMISIntList*, Unk_CMISIntList*);                     // operator=
struct Unk_CMISListIter { void* m_p; };
Unk_CMISListIter* FUN_14114e630(Unk_CMISIntList*, Unk_CMISListIter*);                    // begin
struct Unk_CMISListEnd { void* m_p; void* m_a; };
Unk_CMISListEnd* FUN_1411522d0(Unk_CMISIntList*, Unk_CMISListEnd*);         // end
bool FUN_14035ea60(Unk_CMISListIter*, Unk_CMISListEnd*);                   // operator!=
int* FUN_1403e8d70(Unk_CMISListIter*);                                      // operator*
void FUN_14035ebf0(Unk_CMISListIter*);                                      // operator++
struct Unk_CMISHouseInfo;
struct Unk_CMISHousePtr { void* m_p; };                                     // MS2Ptr<house info>
struct Unk_CMISHouseNode { int first; Unk_CMISHousePtr second; };
class Unk_CMISHouseMark { public: void FUN_14198cb00(const Unk_CMISHouseInfo& info); void FUN_14198cf50(); };
Unk_CMISHouseMark* FUN_1410dc020();
bool FUN_1411516e0(Unk_CMISTree<274>*);                                     // empty
void FUN_14114dc90(Unk_CMISTree<274>*, Unk_CMISIter<274>*);                 // begin
Unk_CMISIter<274>* FUN_141151a30(Unk_CMISTree<274>*, Unk_CMISIter<274>*);   // end
bool FUN_141127440(Unk_CMISIter<274>*, Unk_CMISIter<274>*);                 // operator!=
Unk_CMISHouseNode* FUN_1411285a0(Unk_CMISIter<274>*);                       // operator*
void FUN_141129ac0(Unk_CMISIter<274>*);                                     // operator++
Unk_CMISIter<274>* FUN_1411573c0(Unk_CMISTree<274>*, Unk_CMISIter<274>*, const int*);   // find
Unk_CMISHousePtr* FUN_141127c50(Unk_CMISTree<274>*, const int*);             // operator[]
char* FUN_141128470(Unk_CMISHousePtr*);                                      // the house info bytes
int FUN_1408b5620(int);
bool FUN_141151760(Unk_CMISTree<259>*);
bool FUN_141126b10(Unk_CMISHousePtr*, int);                                 // operator==(0)
Unk_CMISHouseInfo* FUN_141128800(Unk_CMISHousePtr*);                        // operator*
class Unk_CMISPolyObj { public: virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); };
struct Unk_CMISPolyNode { int first; Unk_CMISHousePtr second; };
void FUN_14114dde0(Unk_CMISTree<273>*, Unk_CMISIter<273>*);                 // begin
Unk_CMISIter<273>* FUN_141151b50(Unk_CMISTree<273>*, Unk_CMISIter<273>*);   // end
bool FUN_141127500(Unk_CMISIter<273>*, Unk_CMISIter<273>*);                 // operator!=
Unk_CMISPolyNode* FUN_141128600(Unk_CMISIter<273>*);                        // operator*
void FUN_141129b70(Unk_CMISIter<273>*);                                     // operator++
Unk_CMISPolyObj* FUN_1411284c0(Unk_CMISHousePtr*);                          // operator->
struct Unk_CMISPair { int m_a, m_b; };
extern Unk_CMISPair DAT_143b02320;                                          // initial cursor pair
float FUN_14029d220(float f);                                               // fabsf
Unk_Int3* FUN_14112ca20(Unk_Int3* pA, Unk_Int3* pOut, Unk_Int3* pB);   // point add
const int* FUN_1402fbd20(const int*, const int*);               // std::min
const int* FUN_1404eb7e0(const int*, const int*);               // std::max
MS2Ptr<Cube>* FUN_141127cd0(Unk_CMISTree<260>*, const int*);             // operator[]: the cube of a key
struct Unk_CMISCubeById { Unk_CMISEntityRef key; MS2Ptr<Cube> second; };  // the node value of the cubes by entity
Unk_CMISIter<259>* FUN_1411581c0(Unk_CMISTree<259>*, Unk_CMISIter<259>*, const Unk_CMISEntityRef*);   // find
Unk_CMISIter<259>* FUN_1411520f0(Unk_CMISTree<259>*, Unk_CMISIter<259>*);                             // end
bool FUN_141127800(Unk_CMISIter<259>*, Unk_CMISIter<259>*);                                          // operator!=
Unk_CMISCubeById* FUN_141128780(Unk_CMISIter<259>*);                                                 // operator*
bool FUN_1408a07b0(int nMapId, int a, __int64 b);
extern int DAT_1439f4a7c;
extern __int64 DAT_143ab2820;

// @0x1410b76a0
int CubeMapInformationService::FUN_1410b76a0()
{
    FUN_1410c68e0();
    FUN_1410d0310();
    return 1;
}
// @0x1410b76d0
void CubeMapInformationService::FUN_1410b76d0()
{
    f158 = 0;
    f160 = false;
    t168.FUN_140868750(1000);
    t250.FUN_140868750(200);
    f208 = FUN_1403ed2d0()->FUN_141bd30a0();
    f218 = FUN_1408ad3f0(FUN_1403ed2d0()->FUN_141bd3060());
}
// @0x1410b7a20
Unk_StreamPoint CubeMapInformationService::FUN_1410b7a20(Unk_StreamPoint pt, Unk_StreamPoint* pOut)
{
    Unk_Int3 cell = FUN_1408a1430(pt);
    pOut->x = (float)cell.x * 150.0f;
    pOut->y = (float)cell.y * 150.0f;
    pOut->z = (float)cell.z * 150.0f;
    return *pOut;
}
// @0x1410b7ad0
Unk_StreamPoint CubeMapInformationService::FUN_1410b7ad0(PCBase* pActor, float fDist, Unk_StreamPoint* pOut, int bSnap)
{
    return FUN_1410b7ba0(reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_1416767d0(), reinterpret_cast<Unk_CMISActor*>(pActor)->FUN_141676880(), fDist, pOut, bSnap);
}
// @0x1410b7ba0
Unk_StreamPoint CubeMapInformationService::FUN_1410b7ba0(Unk_StreamPoint ptFrom, Unk_StreamPoint ptTo, float fDist, Unk_StreamPoint* pOut, int bSnap)
{
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptTo, &kForward, &kRight);
    *pOut = ptFrom.FUN_14097fd50(kForward.FUN_14097fc90((float)bSnap).FUN_14097fc90(150.0f));
    pOut->x = pOut->x + 75.0f;
    pOut->y = pOut->y + 75.0f;
    pOut->z = pOut->z + fDist;
    if (pOut->x < 0.0f)
        pOut->x = pOut->x - 150.0f;
    if (pOut->y < 0.0f)
        pOut->y = pOut->y - 150.0f;
    return *pOut;
}
// @0x1410b7d50
bool CubeMapInformationService::FUN_1410b7d50()
{
    return FUN_14115ad10(&f78) == 0;
}
// @0x1410b7da0
bool CubeMapInformationService::FUN_1410b7da0(Unk_StreamPoint pt)
{
    if (!FUN_1410b7e80(pt))
        return false;
    int nKey = FUN_1408a13d0(pt);
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141127640(FUN_141157ac0(&f2e0, &itFind, &nKey), FUN_141151d30(&f2e0, &itEnd)))
        return true;
    return false;
}
// @0x1410b7e80
bool CubeMapInformationService::FUN_1410b7e80(Unk_StreamPoint pt)
{
    return FUN_1410b7ed0(FUN_1408a13d0(pt));
}
// @0x1410b7ed0
bool CubeMapInformationService::FUN_1410b7ed0(int nKey)
{
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
        return false;
    Unk_CMISIter<272> itEnd2, itFind2;
    if (FUN_141127680(FUN_141157ba0(&f1f8, &itFind2, &nKey), FUN_141151d90(&f1f8, &itEnd2)))
        return false;
    return true;
}
// @0x1410b7f90
bool CubeMapInformationService::FUN_1410b7f90(Unk_Int3 cell)
{
    return FUN_1410b7ed0(FUN_1408a0370(cell.x, cell.y, cell.z));
}

// @0x1410b7fe0
Unk_CMISTree<287>* CubeMapInformationService::FUN_1410b7fe0(int nKey)
{
    static Unk_CMISTree<287> s_empty;
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return &s_empty;
    return FUN_141127dd0(&fc8, &nKey);
}
// @0x1410b80d0
Cube* CubeMapInformationService::FUN_1410b80d0(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return 0;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return 0;
    Unk_CMISIter<287> itColEnd, itColFind;
    if (FUN_140885290(FUN_140885ca0(pColumn, &itColFind, &nZ), FUN_140885c40(pColumn, &itColEnd)))
        return 0;
    return FUN_141128350(pColumn, &nZ)->get();
}
// @0x1410b82c0
bool CubeMapInformationService::FUN_1410b82c0(MS2Ptr<Cube> spCube)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return false;
    return true;
}
// @0x1410b8420
bool CubeMapInformationService::FUN_1410b8420(MS2Ptr<Cube> spCube, int nZ)
{
    int nKey = FUN_1408a03c0(spCube->position);
    Unk_CMISIter<261> itEnd, itFind;
    if (FUN_141126e50(FUN_141157820(&fc8, &itFind, &nKey), FUN_141151c10(&fc8, &itEnd)))
        return false;
    int nColumn = FUN_1408a03c0(spCube->position);
    Unk_CMISTree<287>* pColumn = FUN_141127d90(&fc8, &nColumn);
    if (FUN_14115adb0(pColumn) == 0)
        return false;
    Unk_CMISIter<287> itColEnd, itColFind;
    if (FUN_140885290(FUN_140885ca0(pColumn, &itColFind, &nZ), FUN_140885c40(pColumn, &itColEnd)))
        return false;
    return true;
}
// @0x1410b85f0
void CubeMapInformationService::FUN_1410b85f0(Unk_Int3* pMin, Unk_Int3* pMax)
{
    pMin->x = 0x7fffffff;
    pMin->y = 0x7fffffff;
    pMin->z = 0x7fffffff;
    pMax->x = 0x80000000;
    pMax->y = 0x80000000;
    pMax->z = 0x80000000;
    Unk_CMISIter<278> it, itEnd;
    for (FUN_14114db40(&f2b8, &it); FUN_141127380(&it, FUN_141151910(&f2b8, &itEnd)); FUN_141129a60(&it)) {
        int nKey = *FUN_141128540(&it);
        Unk_Int3 cell = FUN_1408a0400(nKey);
        pMin->x = *FUN_1402fbd20(&pMin->x, &cell.x);
        pMin->y = *FUN_1402fbd20(&pMin->y, &cell.y);
        pMin->z = *FUN_1402fbd20(&pMin->z, &cell.z);
        pMax->x = *FUN_1404eb7e0(&pMax->x, &cell.x);
        pMax->y = *FUN_1404eb7e0(&pMax->y, &cell.y);
        pMax->z = *FUN_1404eb7e0(&pMax->z, &cell.z);
    }
}

// @0x1410b8790
Cube* CubeMapInformationService::FUN_1410b8790(Unk_Int3 pt)
{
    int nMaxDrop = 0;
    if (FUN_1410c3180() != 0)
        nMaxDrop = f2fc;
    else
        nMaxDrop = 20;
    Unk_Int3 ptHit = pt;
    int nDrop = 0;
    while (nDrop++ <= nMaxDrop) {
        int nKey = FUN_1408a03c0(pt);
        if (FUN_1410d2f40(nKey) != 0) {
            MS2Ptr<Cube> spCube(FUN_1410b8b00(nKey));
            if (spCube.get() != 0) {
                if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820)) {
                    ptHit = pt;
                    break;
                } else if (spCube->field50 != 0) {
                    ptHit = pt;
                    break;
                }
            }
        }
        pt.z = pt.z - 1;
    }
    return FUN_1410b8a60(ptHit);
}
// @0x1410b8980
Cube* CubeMapInformationService::FUN_1410b8980(Unk_Int3 pt)
{
    Cube* pBase = FUN_1410b8a60(pt);
    if (pBase != 0 && pBase->field44 == 0)
        return 0;
    while (pBase != 0) {
        pt.z = pt.z - 1;
        Cube* pNext = FUN_1410b8a60(pt);
        if (pNext == 0 || pNext->field50 != pBase->field50 || pNext->field44 == 0)
            return pBase;
        pBase = pNext;
    }
    return pBase;
}
// @0x1410b8a60
Cube* CubeMapInformationService::FUN_1410b8a60(Unk_Int3 pt)
{
    return FUN_1410b8b00(FUN_1408a0370(pt.x, pt.y, pt.z));
}
// @0x1410b8ab0
Cube* CubeMapInformationService::FUN_1410b8ab0(Unk_StreamPoint pt)
{
    return FUN_1410b8b00(FUN_1408a13d0(pt));
}
// @0x1410b8b00
Cube* CubeMapInformationService::FUN_1410b8b00(int nKey)
{
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
        return 0;
    Unk_CMISIter<272> itEnd2, itFind2;
    if (FUN_141127680(FUN_141157ba0(&f1f8, &itFind2, &nKey), FUN_141151d90(&f1f8, &itEnd2)))
        return 0;
    return FUN_141127cd0(&f98, &nKey)->get();
}
// @0x1410b8be0
Cube* CubeMapInformationService::FUN_1410b8be0(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (ref.FUN_140965410(none))
        return 0;
    Unk_CMISIter<259> itFind, itEnd;
    FUN_1411581c0(&fa8, &itFind, &ref);
    if (FUN_141127800(&itFind, FUN_1411520f0(&fa8, &itEnd)))
        return FUN_141128780(&itFind)->second.get();
    return 0;
}

// @0x1410b8c90
Cube* CubeMapInformationService::FUN_1410b8c90(const Unk_CMISEntityRef& ref)
{
    Unk_1401cd100 none(0);
    if (ref.FUN_140965410(none))
        return 0;
    Unk_CMISIter<259> itFind, itEnd;
    FUN_1411581c0(&fa8, &itFind, &ref);
    if (FUN_141127800(&itFind, FUN_1411520f0(&fa8, &itEnd))) {
        MS2Ptr<Cube> spCube(FUN_141128780(&itFind)->second);
        if (spCube->field48 == 0)
            return 0;
        return spCube.get();
    }
    return 0;
}
// @0x1410b8d90
Cube* CubeMapInformationService::FUN_1410b8d90(Cube* pBase, int nOffset, int nField44)
{
    Cube* pCube = 0;
    if (pBase != 0 && nOffset != 0) {
        Unk_Int3 off = FUN_1408a0400(nOffset);
        Unk_Int3 tmp;
        pCube = FUN_1410b8a60(*FUN_14112ca20(&off, &tmp, &pBase->position));
        if (pCube != 0 && pCube->field44 == nField44)
            return pCube;
        else
            return 0;
    }
    return pCube;
}
// @0x1410b9080
Cube* CubeMapInformationService::FUN_1410b9080(Cube* pBase, int nOffset)
{
    Cube* pCube = 0;
    if (pBase != 0 && nOffset != 0) {
        Unk_Int3 off = FUN_1408a0400(nOffset);
        Unk_Int3 tmp;
        pCube = FUN_1410b8a60(*FUN_14112ca20(&off, &tmp, &pBase->position));
        if (pCube != 0 && pCube->field70 != 0)
            return pCube;
        else
            return 0;
    }
    return pCube;
}

// @0x1410b8e60
Cube* CubeMapInformationService::FUN_1410b8e60(egf::Entity* pEntity)
{
    if (pEntity != 0) {
        Unk_StreamPoint pt;
        FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
        Cube* pCube = FUN_1410b8ab0(pt);
        if (pCube != 0 && pCube->field70 != 0) {
            if (FUN_1408b76f0(FUN_1408a9280(&pCube->entity))->FUN_140965410(*reinterpret_cast<const Unk_1401cd100*>(FUN_1408b76f0(pEntity))))
                return pCube;
        }
    }
    return 0;
}

// @0x1410b8f30
Cube* CubeMapInformationService::FUN_1410b8f30(Unk_StreamPoint ptFrom, Unk_StreamPoint* pHit, float fRange)
{
    static Unk_StreamPoint s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptFrom.FUN_14097fd50(s_kDown));
    if (FUN_14028d470(fRange, 0.0f))
        fRange = 150.0f;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    if (FUN_14168a310(FUN_1409f7ca0(), &ptStart, pHit, &hit, fRange, 0, 0) != 0)
        return FUN_1410b8e60(hit.m_pEntity);
    return 0;
}

// @0x1410b9150
Unk_StreamPoint CubeMapInformationService::FUN_1410b9150(Unk_StreamPoint ptIn)
{
    static Unk_StreamPoint s_kDown = DAT_143a08cf8.FUN_14097fc90(20.0f);
    Unk_CMISPt3 ptStart(ptIn.FUN_14097fd50(s_kDown));
    Unk_StreamPoint ptDir = DAT_143b01a60;
    Unk_CMISRayHit hit;
    FUN_140ad4440(&hit);
    Cube* pCube;
    if (FUN_14168a310(FUN_1409f7ca0(), &ptStart, &ptDir, &hit, 750.0f, 0, 0) != 0 && (pCube = FUN_1410b8e60(hit.m_pEntity)) != 0 && pCube->field70 != 0) {
        Unk_StreamPoint ptRes;
        FUN_1409618c0(FUN_1408a9280(&pCube->entity), 0xfd95ca52, &ptRes);
        ptRes.z = ptIn.z;
        return ptRes;
    }
    return ptIn;
}

// @0x1410b9330
// MS2-FUNCTIONAL: frame 0x10 larger than the exe (the operator+ temp is allocated before the by-value copies); same calls and control flow
bool CubeMapInformationService::FUN_1410b9330(void* pArg, Unk_StreamPoint pt, float fStep, Unk_StreamPoint* pOutPos, Unk_StreamPoint* pOutRot, int* pnResult, void** ppHit)
{
    float fLimit = 75.0f;
    void* pFound = 0;
    float fRadius = fStep;
    Unk_StreamPoint ptCur;
    Unk_StreamPoint ptOffset = DAT_143b01a60;
    Unk_CMISPair kCursor = DAT_143b02320;
    *pnResult = FUN_1410d1320(pArg, pt, fStep, &ptCur);
    if (*pnResult == 9)
        return false;
    float fDx = pt.x - ptCur.x;
    float fDy = pt.y - ptCur.y;
    *pOutRot = DAT_143b01a60;
    if (FUN_14029d220(fDx) > fLimit - fRadius)
        fDx = (fDx / FUN_14029d220(fDx)) * (fLimit - fRadius);
    if (FUN_14029d220(fDy) > fLimit - fRadius)
        fDy = (fDy / FUN_14029d220(fDy)) * (fLimit - fRadius);
    *pnResult = FUN_1410d1820(pArg, *pnResult, pt, ptCur, &pFound);
    if (pFound == 0 || FUN_1410d2130(pFound, *pnResult, fRadius, pOutPos, pOutRot) == 0) {
        int nDir = *pnResult;
        switch (nDir) {
        case 0:
            return false;
        case 1:
            pOutRot->z = 225.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = fRadius;
            break;
        case 2:
            pOutRot->z = 180.0f;
            ptOffset.x = fDx;
            ptOffset.y = fRadius;
            break;
        case 3:
            pOutRot->z = 135.0f;
            ptOffset.x = fRadius;
            ptOffset.y = fRadius;
            break;
        case 4:
            pOutRot->z = 90.0f;
            ptOffset.x = fRadius;
            ptOffset.y = fDy;
            break;
        case 5:
            pOutRot->z = 45.0f;
            ptOffset.x = fRadius;
            ptOffset.y = -fRadius;
            break;
        case 6:
            pOutRot->z = 0.0f;
            ptOffset.x = fDx;
            ptOffset.y = -fRadius;
            break;
        case 7:
            pOutRot->z = 315.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = -fRadius;
            break;
        case 8:
            pOutRot->z = 270.0f;
            ptOffset.x = -fRadius;
            ptOffset.y = fDy;
            break;
        }
        ptCur.z = pt.z;
        *pOutPos = ptCur.FUN_14097fd50(ptOffset);
        return true;
    }
    pOutPos->z = pt.z;
    if (ppHit != 0)
        *ppHit = pFound;
    return true;
}

// @0x1410b9850
Cube* CubeMapInformationService::FUN_1410b9850(int nItemId)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        {
            if (FUN_1408b4f20(spCube.operator->()) == nItemId)
                return spCube.get();
        }
    }
    return 0;
}
// @0x1410b9950
int CubeMapInformationService::FUN_1410b9950(int nCategory)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_14053fc10(FUN_1408b4f20(spCube.operator->())) == nCategory)
            return 1;
    }
    return 0;
}
// @0x1410b9a50
int CubeMapInformationService::FUN_1410b9a50()
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9b20
int CubeMapInformationService::FUN_1410b9b20(int nItemId)
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f20(spCube.operator->()) != nItemId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410b9d80
int CubeMapInformationService::FUN_1410b9d80(__int64 nId)
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f50(spCube.operator->()) == nId)
            return 1;
    }
    return 0;
}
// @0x1410b9e70
Unk_CMISTree<277>* CubeMapInformationService::FUN_1410b9e70()
{
    return &f2a8;
}

// @0x1410b9c20
int CubeMapInformationService::FUN_1410b9c20(int nItemId, __int64 nOwnerId)
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 == 0)
            continue;
        if (FUN_1408b4f20(spCube.operator->()) != nItemId)
            continue;
        __int64 nOwner = 0;
        Unk_CMISCubeOwner* pOwner = FUN_1408b4f80(spCube.operator->());
        if (pOwner != 0)
            nOwner = pOwner->m_nId;
        if (nOwner != nOwnerId)
            continue;
        nCount++;
    }
    return nCount;
}
// @0x1410ba440
float CubeMapInformationService::FUN_1410ba440(int nDir)
{
    switch (nDir) {
    case 1:
        return 270.0f;
    case 2:
        return 180.0f;
    case 3:
        return 90.0f;
    case 4:
        return 0.0f;
    default:
        return 0.0f;
    }
}
// @0x1410ba4a0
int CubeMapInformationService::FUN_1410ba4a0(Unk_StreamPoint ptDir)
{
    Unk_StreamPoint kWest(-1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kNorth(0.0f, 1.0f, 0.0f);
    Unk_StreamPoint kEast(1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kSouth(0.0f, -1.0f, 0.0f);
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptDir, &kForward, &kRight);
    if (kWest.FUN_140a00f20(kForward) == 1.0f)
        return 1;
    else if (kNorth.FUN_140a00f20(kForward) == 1.0f)
        return 2;
    else if (kEast.FUN_140a00f20(kForward) == 1.0f)
        return 3;
    else if (kSouth.FUN_140a00f20(kForward) == 1.0f)
        return 4;
    return 0;
}
// @0x1410bab50
Unk_Int3 CubeMapInformationService::FUN_1410bab50(Unk_Int3 pt, int nDir)
{
    switch (nDir) {
    case 1:
        pt.x = pt.x - 1;
        break;
    case 2:
        pt.y = pt.y + 1;
        break;
    case 3:
        pt.x = pt.x + 1;
        break;
    case 4:
        pt.y = pt.y - 1;
        break;
    }
    return pt;
}
// @0x1410bac00
Unk_Int3 CubeMapInformationService::FUN_1410bac00(Unk_StreamPoint ptDir)
{
    Unk_StreamPoint kWest(-1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kNorth(0.0f, 1.0f, 0.0f);
    Unk_StreamPoint kEast(1.0f, 0.0f, 0.0f);
    Unk_StreamPoint kSouth(0.0f, -1.0f, 0.0f);
    Unk_StreamPoint kForward, kRight;
    FUN_140a01250(ptDir, &kForward, &kRight);
    if (kWest.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(-1, 0, 0);
    else if (kNorth.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(0, 1, 0);
    else if (kEast.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(1, 0, 0);
    else if (kSouth.FUN_140a00f20(kForward) == 1.0f)
        return Unk_Int3(0, -1, 0);
    return Unk_Int3(0, 0, 0);
}

// @0x1410bb950
int CubeMapInformationService::FUN_1410bb950(Unk_Int3 pt)
{
    MS2Ptr<Cube> spCube(FUN_1410b8a60(pt));
    while (spCube.get() != 0) {
        if (spCube->field50 != 0)
            return spCube->field50;
        pt.z = pt.z - 1;
        spCube.AssignRaw(FUN_1410b8a60(pt));
    }
    return 0;
}
// @0x1410bba60
void CubeMapInformationService::FUN_1410bba60(int nKey)
{
    Unk_Int3 pt = FUN_1408a0400(nKey);
    FUN_1410bb950(pt);
}

// @0x1410bbab0
// MS2-FUNCTIONAL: behaviour-equivalent; frame layout / local order differs from the exe (0x10 of temporaries placed differently)
bool CubeMapInformationService::FUN_1410bbab0(int nKey)
{
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_1411275c0(FUN_141157900(&fd8, &itFind, &nKey), FUN_141151c70(&fd8, &itEnd))) {
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nKey);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            Unk_Int3 pt = FUN_1408a0400(*FUN_1403e8d70(&it));
            pt.z = pt.z + 1;
            if (FUN_1410b7f90(pt))
                return true;
        }
    }
    return false;
}
// @0x1410bbc00
// MS2-FUNCTIONAL: identical code and slot layout, but the frame is 0x10 larger than the exe (unreferenced temporary)
void CubeMapInformationService::FUN_1410bbc00(int nKey, int nUnused)
{
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind, &nKey), FUN_141151c70(&fd8, &itEnd))) {
        Unk_CMISIntList kEmpty;
        FUN_141126700(FUN_141127e10(&fd8, &nKey), &kEmpty);
    }
    FUN_1410bbcd0(nKey, 0);
}

// @0x1410bc1c0
void CubeMapInformationService::FUN_1410bc1c0()
{
    if (!FUN_1411516e0(&f238)) {
        Unk_CMISHouseMark* pHouse = FUN_1410dc020();
        if (pHouse != 0) {
            Unk_CMISIter<274> it, itEnd;
            for (FUN_14114dc90(&f238, &it); FUN_141127440(&it, FUN_141151a30(&f238, &itEnd)); FUN_141129ac0(&it)) {
                if (FUN_141126b10(&FUN_1411285a0(&it)->second, 0))
                    continue;
                pHouse->FUN_14198cb00(*FUN_141128800(&FUN_1411285a0(&it)->second));
            }
        }
    }
    Unk_CMISIter<273> itMark, itMarkEnd;
    for (FUN_14114dde0(&f228, &itMark); FUN_141127500(&itMark, FUN_141151b50(&f228, &itMarkEnd)); FUN_141129b70(&itMark)) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(&itMark)->second);
        pObj->vfunc_2();
    }
}
// @0x1410bc320
void CubeMapInformationService::FUN_1410bc320()
{
    Unk_CMISHouseMark* pHouse = FUN_1410dc020();
    if (pHouse != 0)
        pHouse->FUN_14198cf50();
    Unk_CMISIter<273> itMark, itMarkEnd;
    for (FUN_14114dde0(&f228, &itMark); FUN_141127500(&itMark, FUN_141151b50(&f228, &itMarkEnd)); FUN_141129b70(&itMark)) {
        Unk_CMISPolyObj* pObj = FUN_1411284c0(&FUN_141128600(&itMark)->second);
        pObj->vfunc_3();
    }
}

// @0x1410bf250
// MS2-FUNCTIONAL: exe local slot/branch layout differs by 2 bytes
void CubeMapInformationService::FUN_1410bf250(const int* pKey)
{
    int n;
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        n = *FUN_1411280d0(&f358, pKey);
        *FUN_1411280d0(&f358, pKey) = n + 1;
    } else {
        *FUN_1411280d0(&f358, pKey) = 1;
    }
}
// @0x1410bf320
void CubeMapInformationService::FUN_1410bf320(const int* pKey)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        int n = *FUN_1411280d0(&f358, pKey);
        if (0 < n)
            n = n - 1;
        *FUN_1411280d0(&f358, pKey) = n;
    }
}
// @0x1410bf3e0
int CubeMapInformationService::FUN_1410bf3e0(const int* pKey)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f358, &itFind, pKey), FUN_141151fd0(&f358, &itEnd))) {
        int nVal = *FUN_1411280d0(&f358, pKey);
        return nVal;
    }
    return 0;
}
// @0x1410c3e00
unsigned char CubeMapInformationService::FUN_1410c3e00(int nKey) { return *FUN_141128310(&f368, &nKey); }
// @0x1410c3e40
void CubeMapInformationService::FUN_1410c3e40(int nKey, unsigned char v) { *FUN_141128310(&f368, &nKey) = v; }
// @0x1410c3e80
int CubeMapInformationService::FUN_1410c3e80(int nKey)
{
    Unk_CMISIter<281> itEnd, itFind;
    if (FUN_1408b7170(FUN_141158460(&f378, &itFind, &nKey), FUN_141152210(&f378, &itEnd)))
        return 0;
    return *FUN_141128290(&f378, &nKey);
}
// @0x1410c3f10
void CubeMapInformationService::FUN_1410c3f10(int nKey, int v) { *FUN_141128290(&f378, &nKey) = v; }
// @0x1410c3f50
void CubeMapInformationService::FUN_1410c3f50(int n)
{
    if (f1dc == n)
        return;
    f1dc = n;
    GenerateFloorPhysX();
}
// @0x1410c3fa0
int CubeMapInformationService::FUN_1410c3fa0() { return f1dc; }
// @0x1410c2fe0
void CubeMapInformationService::FUN_1410c2fe0(void*) {}
// @0x1410cb900
bool CubeMapInformationService::FUN_1410cb900() { return f248; }
// @0x1410ce7e0
Unk_CMISTree<260>* CubeMapInformationService::FUN_1410ce7e0() { return &f98; }
// @0x1410cef40
efd::AsyncResult CubeMapInformationService::OnShutdown()
{
    FUN_1410d0310();
    return efd::AsyncResult_Complete;
}
// @0x1410cf130
void CubeMapInformationService::FUN_1410cf130(void*, void* p) { FUN_1409fabe0(p); }
// @0x1410d3360
Unk_CMISTree<268>* CubeMapInformationService::FUN_1410d3360() { return &f138; }
// @0x1410d3380
Unk_CMISTree<269>* CubeMapInformationService::FUN_1410d3380() { return &f148; }
// @0x1410d4660
ATL::CAtlArray<Unk_CMISElem388*>* CubeMapInformationService::FUN_1410d4660() { return &a388; }
// @0x1410d4920
ATL::CAtlArray<Unk_CMISElem3a8*>* CubeMapInformationService::FUN_1410d4920() { return &a3a8; }
// @0x1410d5530
bool CubeMapInformationService::FUN_1410d5530() { return f3dc; }
// @0x1410d5700
void CubeMapInformationService::FUN_1410d5700(unsigned __int64 v) { f420 = v; }
// @0x1410d5730
unsigned __int64 CubeMapInformationService::FUN_1410d5730() { return f420; }
// @0x1410d5750
void CubeMapInformationService::FUN_1410d5750(unsigned __int64 v) { f428 = v; }
// @0x1410d5780
unsigned __int64 CubeMapInformationService::FUN_1410d5780() { return f428; }
// @0x1410d5ab0
void CubeMapInformationService::FUN_1410d5ab0() { FUN_14115ab30(&f98); }
// @0x1410d5ae0
void CubeMapInformationService::FUN_1410d5ae0(int v) { f450 = v; }
// @0x1410d5b00
int CubeMapInformationService::FUN_1410d5b00() { return f450; }
// @0x1410cb8b0
void CubeMapInformationService::FUN_1410cb8b0(bool b)
{
    f248 = b;
    if (f248)
        f24c = FUN_140869420();
}
// @0x1410cb920
bool CubeMapInformationService::FUN_1410cb920(int n)
{
    if (!f248)
        return false;
    return FUN_140869420() > (unsigned)(f24c + n);
}
// @0x1410d2ee0
int CubeMapInformationService::FUN_1410d2ee0() { return FUN_141151720(&fb8); }
// @0x1410d2f10
int CubeMapInformationService::FUN_1410d2f10() { return FUN_140374410(FUN_141bd3060(FUN_1403ed2d0())); }
// @0x1410d2f40
int CubeMapInformationService::FUN_1410d2f40(int nKey)
{
    Unk_CMISIter<278> itEnd, itFind;
    if (FUN_141127380(FUN_141157040(&f2b8, &itFind, &nKey), FUN_141151910(&f2b8, &itEnd)))
        return 1;
    return 0;
}
// @0x1410d54f0
void CubeMapInformationService::FUN_1410d54f0(bool b)
{
    if (DAT_143ab2820 != FUN_1410c3180())
        return;
    f3dc = b;
}
// @0x1410d5550
int CubeMapInformationService::FUN_1410d5550(int nKey)
{
    Unk_CMISIter<282> itTmp, itEnd;
    Unk_CMISIter<282> it = *FUN_1411582a0(&f3c8, &itTmp, &nKey);
    if (FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)))
        return 0;
    return FUN_1411284e0(&it)->m_val;
}
// @0x1410d55d0
void CubeMapInformationService::FUN_1410d55d0(int a, int b)
{
    if (FUN_140885340(&f208)->FUN_140375130()) {
        FUN_1408a06a0(f1b8, f1b4);
        return;
    } else {
        FUN_1408a06a0(a, b);
    }
}
// @0x1410d5640
bool CubeMapInformationService::FUN_1410d5640()
{
    if (FUN_1410d2f10() == 0)
        return false;
    if (FUN_1410c35c0())
        return false;
    if (FUN_1410c3180() != DAT_143ab2820)
        return false;
    return true;
}
// @0x1410d56a0
bool CubeMapInformationService::FUN_1410d56a0()
{
    if (FUN_1410d2f10() == 0)
        return false;
    if (!FUN_1410c35c0())
        return false;
    if (FUN_1410c3180() != DAT_143ab2820)
        return false;
    return true;
}
// @0x1410d57a0
void CubeMapInformationService::FUN_1410d57a0(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    Unk_CMISInsRes res;
    if (FUN_1403344a0(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return;
    FUN_1404422b0(&f430, &res, &key);
}
// @0x1410d5830
void CubeMapInformationService::FUN_1410d5830(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    if (FUN_140334210(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return;
    FUN_1404bfb40(&f430, &key);
}
// @0x1410d58c0
bool CubeMapInformationService::FUN_1410d58c0(unsigned __int64 key)
{
    Unk_CMISIter<286> itEnd, itFind;
    if (FUN_1403344a0(FUN_1404c0270(&f430, &itFind, &key), FUN_140341f40(&f430, &itEnd)))
        return true;
    return false;
}
// @0x1410d5930
void CubeMapInformationService::FUN_1410d5930(Unk_CMISTree<286>* pOut)
{
    Unk_CMISIter<286> it, itEnd;
    Unk_CMISInsRes res;
    for (FUN_140340ff0(&f430, &it); FUN_1403344a0(&it, FUN_140341f40(&f430, &itEnd)); FUN_140334ef0(&it))
        FUN_1404422b0(pOut, &res, FUN_1408f2950(&it));
}
// @0x1410c5420
void* CubeMapInformationService::FUN_1410c5420(Unk_CMISEntityRef key)
{
    Unk_CMISIter<257> itEnd, itFind;
    if (FUN_141127050(FUN_1411580e0(&f48, &itFind, &key), FUN_141152030(&f48, &itEnd)))
        return 0;
    return *FUN_141128110(&f48, &key);
}
// @0x1410cb420
int CubeMapInformationService::FUN_1410cb420(const Unk_CMISEntityRef* pRef)
{
    Unk_CMISIter<265> it, itEnd;
    for (FUN_14114e010(&f108, &it); FUN_141127640(&it, FUN_141151d30(&f108, &itEnd)); FUN_141129bd0(&it)) {
        if (pRef->FUN_140965410(reinterpret_cast<const Unk_1401cd100&>(FUN_1411286a0(&it)->m_ref)))
            return 1;
    }
    return 0;
}
// @0x1410d2730
int CubeMapInformationService::FUN_1410d2730(const Unk_Int3* pPt)
{
    if (FUN_1410c3180() != 0) {
        if (pPt->x < p300.x || pPt->y < p300.y)
            return 0;
        if (pPt->x > p30c.x || pPt->y > p30c.y)
            return 0;
    }
    return 1;
}
// @0x1410d4340
int CubeMapInformationService::FUN_1410d4340(Unk_CubePoint* pOut)
{
    if (FUN_140965240(&f208, 0))
        return 0;
    if (FUN_140885340(&f208)->FUN_140375130() == 0)
        return 0;
    memcpy(pOut, &p300, 12);
    return 1;
}
// @0x1410c4d80
void CubeMapInformationService::FUN_1410c4d80(const Unk_StreamPoint& pt, float fDist)
{
    FUN_1408a15b0(pt, DAT_143b01a60);
    FUN_1410c2840(pt, fDist);
}
// @0x1410c68e0
bool CubeMapInformationService::FUN_1410c68e0()
{
    FUN_14114f0e0(&f98);
    FUN_14114fa40(&fa8);
    FUN_14114f0e0(&fb8);
    FUN_1410b2760(&f2a8);
    FUN_14114f360(&fd8);
    FUN_14114f2c0(&fc8);
    FUN_1402237c0(&a458);
    return true;
}
// @0x1410d2340
// MS2-FUNCTIONAL: the exe materialises both compare results in int temps (locals layout differs)
bool CubeMapInformationService::FUN_1410d2340(const Unk_CMISPt2* a, const Unk_CMISPt2* b, float fLimX, float fLimY)
{
    return FUN_14029d220(a->x - b->x) <= fLimX && FUN_14029d220(a->y - b->y) <= fLimY;
}
// @0x1410caa60
void CubeMapInformationService::FUN_1410caa60(const int* pKey, int v)
{
    Unk_CMISIter<270> itEnd, itFind;
    if (FUN_141127740(FUN_141158000(&f1a0, &itFind, pKey), FUN_141151fd0(&f1a0, &itEnd)))
        FUN_1411552b0(&f1a0, pKey);
    *FUN_1411280d0(&f1a0, pKey) = v;
}
// @0x1410c51d0
void CubeMapInformationService::FUN_1410c51d0(int nA, int nB, CStringW strName)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return;
    spOwner->ownerName = strName;
}
// @0x1410c8030
__int64 CubeMapInformationService::FUN_1410c8030(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return 0;
    return spOwner->ownerID;
}
// @0x1410cba80
int CubeMapInformationService::FUN_1410cba80(int nDir, int nField50, Unk_Int3* pCell, Unk_CMISPt3* pPos)
{
    Cube* pCube = FUN_1410b8a60(*pCell);
    if (pCube == 0 || pCube->field50 != nField50 || pCube->field44 == 0) {
        if (nDir != 1) {
            pPos->z -= 150.0f;
            pCell->z -= 1;
        }
        return 1;
    }
    return 0;
}
// @0x1410ce3f0
void CubeMapInformationService::FUN_1410ce3f0(Unk_CubeOwnerPtr spOwner)
{
    Unk_CMISIter<269> itEnd, itFind;
    if (FUN_140965380(FUN_14096ae20(&f148, &itFind, &spOwner->ownerID), FUN_14096ad60(&f148, &itEnd)))
        *FUN_1409656d0(&f148, &spOwner->ownerID) = spOwner;
}
// @0x1410ce4b0
void CubeMapInformationService::FUN_1410ce4b0(Unk_CubeOwnerPtr spOwner)
{
    Unk_CMISIter<269> itEnd, itFind;
    if (FUN_1409654d0(FUN_14096ae20(&f148, &itFind, &spOwner->ownerID), FUN_14096ad60(&f148, &itEnd)))
        FUN_141156310(&f148, &spOwner->ownerID);
}
// @0x1410c5280
void CubeMapInformationService::FUN_1410c5280(int nKey)
{
    Unk_CMISIter<265> itEnd, itFind;
    if (FUN_141127640(FUN_141157ac0(&f2c8, &itFind, &nKey), FUN_141151d30(&f2c8, &itEnd))) {
        FUN_1410c5340(*FUN_141127ed0(&f2c8, &nKey));
        FUN_1411547a0(&f2c8, &nKey);
    }
}
// @0x1410c5340
void CubeMapInformationService::FUN_1410c5340(Unk_CMISEntityRef ref)
{
    void* pObj = FUN_1410c5420(ref);
    if (pObj != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(pObj);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
            FUN_1411554c0(&f48, &ref);
            FUN_1411556d0(&f58, &ref);
        }
    }
}
// @0x1410c6070
void CubeMapInformationService::FUN_1410c6070()
{
    if (f40 != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(f40);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
        }
        f40 = 0;
    }
}
// @0x1410c6820
void CubeMapInformationService::FUN_1410c6820(int nIdx)
{
    if (f318[nIdx] != 0) {
        Unk_CMISPhysScene* pScene = FUN_14168a1c0(FUN_1409f7ca0());
        if (pScene != 0) {
            FUN_14168a540(FUN_1409f7ca0(), 0);
            pScene->RemoveActor(f318[nIdx]);
            FUN_141bc8e00(FUN_1403ed2d0());
            FUN_14168a570(FUN_1409f7ca0());
        }
        f318[nIdx] = 0;
    }
}
// @0x1410c3020
void CubeMapInformationService::FUN_1410c3020(int nField)
{
    f1b0 = nField;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube->field48 != 0)
            continue;
        spCube->field54 = nField;
    }
}
// @0x1410c54a0
Unk_StreamPoint CubeMapInformationService::FUN_1410c54a0(Unk_EntRef spEnt)
{
    Unk_StreamPoint ptRes(150.0f, 150.0f, 150.0f);
    Unk_StreamPoint ptProp;
    FUN_1409618c0(FUN_1408a9280(&spEnt), 0xcb086a2d, &ptProp);
    if (ptProp.FUN_140552700(DAT_143b01a60))
        ptRes = ptProp;
    return ptRes;
}
// @0x1410ce560
void CubeMapInformationService::FUN_1410ce560()
{
    Unk_CMISIter<260> it, itEnd, itOld;
    for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd)); FUN_141129b00(&it, &itOld, 0))
        FUN_1410c1910(FUN_1408a0400(FUN_1411285e0(&it)->first), 1);
}
// @0x1410ce310
int CubeMapInformationService::FUN_1410ce310()
{
    int nCount = 0;
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube.get() != 0) {
            if (FUN_1408b5620(FUN_1408b4f20(spCube.operator->())) != 0)
                nCount = nCount + 1;
        }
    }
    return nCount;
}
// @0x1410d33a0
int CubeMapInformationService::FUN_1410d33a0(int nKey, Unk_StreamPoint* pOut)
{
    Unk_CMISIter<274> itEnd, itFind;
    if (FUN_141127440(FUN_1411573c0(&f238, &itFind, &nKey), FUN_141151a30(&f238, &itEnd))) {
        *pOut = *reinterpret_cast<Unk_StreamPoint*>(FUN_141128470(FUN_141127c50(&f238, &nKey)) + 0x1c);
        return 1;
    }
    return 0;
}
// @0x1410c7f60
CStringW CubeMapInformationService::FUN_1410c7f60(int nA, int nB)
{
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB);
    if (spOwner == 0)
        return CStringW(L"");
    return CStringW(spOwner->ownerName);
}
// @0x1410d5b20
void CubeMapInformationService::FUN_1410d5b20(__int64 nId)
{
    if (FUN_141151760(&f78)) {
        COutPacket packet(0x37, 0);
        packet.vfunc_o10_1(0x44);
        packet.vfunc_o10_4(nId);
        FUN_140710590(packet);
        f478 = 0;
    } else {
        f478 = nId;
    }
}
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

// ---- w138 callees (unit-local, names invented) ----
class Unk_CMISLog { public: unsigned __int64 FUN_1410db4f0(int nLevel, int nCategory, const wchar_t* pFormat, const int& a, const int& b, const int& c); unsigned __int64 FUN_1401859c0(int nLevel, int nCategory, const wchar_t* pMsg); };
Unk_CMISLog* FUN_140166440();
struct Unk_CMISEntId { Unk_CMISEntId(const Unk_CMISEntId&); __int64 m_id; };
void FUN_14115b260(CCubeMotionManager* pMgr, const Unk_CMISEntityRef* pId, float fFrom, float fTo, unsigned nMs);   // AddRotate
CCubeMotionManager* FUN_1410af790();
class Unk_CMISMagicCube { public: void FUN_141232330(int nKey, float fRot); };
Unk_CMISMagicCube* FUN_1409670b0();
bool FUN_14034eee0(const CStringW& s, const wchar_t* pSz);                 // operator==
CStringW* FUN_141bd3080(Unk_CMISWorld*);                                   // the current map name
CStringW* FUN_140efe330(CStringW* pOut, const wchar_t* pSz, int n);
struct Unk_CMISPairRes { Unk_CMISPairRes(const Unk_CMISPairRes&); int m_a, m_b; };
Unk_CMISPairRes FUN_14111d460(const int& a, const int& b);                                          // make_pair
Unk_CMISIter<263>* FUN_141151f70(Unk_CMISTree<263>*, Unk_CMISIter<263>*);                            // end
Unk_CMISIter<263>* FUN_141157f20(Unk_CMISTree<263>*, Unk_CMISIter<263>*, const Unk_CMISPairRes&);    // find
bool FUN_141126fd0(Unk_CMISIter<263>*, Unk_CMISIter<263>*);                                          // operator==
void FUN_1411550a0(Unk_CMISTree<263>*, const Unk_CMISPairRes&);                                      // erase
void** FUN_141128090(Unk_CMISTree<263>*, const Unk_CMISPairRes&);                                    // operator[]
void* FUN_141128410(void** pSecond);                                                                 // the raw pointer of the value
Unk_CMISIter<276>* FUN_141151df0(Unk_CMISTree<276>*, Unk_CMISIter<276>*);                            // end
Unk_CMISIter<276>* FUN_141157c80(Unk_CMISTree<276>*, Unk_CMISIter<276>*, const int*);                // find
unsigned char FUN_140d7b400(Unk_CMISIter<276>*, Unk_CMISIter<276>*);                                          // operator!=
struct Unk_CMISObj498;
template <> struct Unk_CMISIter<284> { void* node; };
void FUN_141120750(Unk_CMISIter<284>*);                                                              // default ctor
Unk_CMISIter<284>* FUN_14114e7f0(Unk_CMISTree<284>*, Unk_CMISIter<284>*);                            // begin
Unk_CMISIter<284>* FUN_141152450(Unk_CMISTree<284>*, Unk_CMISIter<284>*);                            // end
bool FUN_141127900(Unk_CMISIter<284>*, Unk_CMISIter<284>*);                                          // operator!=
void* FUN_141128b30(Unk_CMISIter<284>*);                                                             // operator*
Unk_CMISObj498* FUN_1409658e0(void* pSlot);                                                          // the object of a slot
int FUN_14112e110(Unk_CMISObj498*);                                                                  // the object id
void FUN_141227780(Unk_CMISObj498*);                                                                 // release the object's link
Unk_CMISIter<284>* FUN_141129990(Unk_CMISIter<284>*, Unk_CMISIter<284>*, int);                       // operator++(int)
void FUN_141156b50(Unk_CMISTree<284>*, Unk_CMISIter<284>*, Unk_CMISIter<284>);                       // erase
Unk_CMISEntityRef* FUN_141127e90(Unk_CMISTree<265>*, const int*);                                    // operator[]
void FUN_140899bd0(Unk_CMISEntityRef* pDst, const Unk_CMISEntityRef& src);                           // operator=
struct Unk_CMISHandle388 { void* m_a; void* m_p; void* m_c; };
struct Unk_CMISHandle3a8 { void* m_a; void* m_p; void* m_c; };
unsigned __int64 FUN_140fac790(ATL::CAtlArray<Unk_CMISHandle3a8>*);                                  // GetCount
Unk_CMISHandle3a8* FUN_14112dfe0(ATL::CAtlArray<Unk_CMISHandle3a8>*, unsigned __int64);              // operator[]
void FUN_140fac570(Unk_CMISHandle3a8* pDst, const Unk_CMISHandle3a8* pSrc);                          // copy ctor
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISHandle3a8*);                    // Add
void FUN_140fac610(Unk_CMISHandle3a8* p);                                                            // dtor
unsigned __int64 FUN_140fac7a0(ATL::CAtlArray<Unk_CMISHandle388>*);                                  // GetCount
Unk_CMISHandle388* FUN_14112e020(ATL::CAtlArray<Unk_CMISHandle388>*, unsigned __int64);              // operator[]
void FUN_140fac5b0(Unk_CMISHandle388* pDst, const Unk_CMISHandle388* pSrc);                          // copy ctor
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISHandle388*);                    // Add
void FUN_140fac640(Unk_CMISHandle388* p);                                                            // dtor
unsigned __int64 FUN_140186260(ATL::CAtlArray<Unk_CMISElem458*>*);                                   // GetCount
int* FUN_1401844d0(ATL::CAtlArray<Unk_CMISElem458*>*, unsigned __int64);                             // operator[]
void FUN_14112d900(ATL::CAtlArray<MS2Ptr<Cube>>*, const MS2Ptr<Cube>*);                              // Add

// @0x1410c2840
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
bool CubeMapInformationService::FUN_1410c2840(Unk_StreamPoint pt, float fDist)
{
    Unk_Int3 cell;
    memcpy(&cell, &pt, sizeof(cell));
    int nKey = FUN_1408a03c0(cell);
    Unk_CMISIter<260> itEnd, itFind;
    if (FUN_141126d90(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)) == 0) {
        MS2Ptr<Cube> spCube(*FUN_141127cd0(&f98, &nKey));
        Unk_StreamPoint kRot;
        FUN_1409618c0(FUN_1408a9280(&spCube->entity), 0x68c7c29d, &kRot);
        spCube->fieldD4 = (int)fDist;
        Unk_CMISEntityRef kId(*FUN_1408b76f0(FUN_1408a9280(&spCube->entity)));
        FUN_14115b260((CCubeMotionManager*)FUN_1410af790(), &kId, kRot.z, fDist, 200);
        FUN_1409670b0()->FUN_141232330(nKey, fDist);
        return true;
    }
    FUN_140166440()->FUN_1410db4f0(1, 0x13, L"[ERROR] No cube on that position = {0}, {1}, {2}", cell.x, cell.y, cell.z);
    return false;
}
// @0x1410c3330
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410c3330(CStringW* pOut)
{
    CStringW s = FUN_1410c31d0();
    if (!FUN_14034eee0(s, L"")) {
        CStringW sMap;
        *pOut = *FUN_140efe330(&sMap, (const wchar_t*)*FUN_141bd3080(FUN_1403ed2d0()), 0);
    } else {
        *pOut = s;
    }
}
// @0x1410c79a0
void CubeMapInformationService::FUN_1410c79a0(int nA, int nB)
{
    Unk_CMISIter<263> itEnd, itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0)
        return;
    FUN_1411550a0(&fe8, FUN_14111d460(nA, nB));
}
// @0x1410c7c20
void* CubeMapInformationService::FUN_1410c7c20(int nA, int nB)
{
    Unk_CMISIter<263> itEnd, itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0)
        return 0;
    return FUN_141128410(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
}
// @0x1410cdf60
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
bool CubeMapInformationService::FUN_1410cdf60(Unk_Int3* pA, Unk_Int3* pB)
{
    Unk_Int3 kSum;
    int nKey = FUN_1408a03c0(*FUN_14112ca20(pA, &kSum, pB));
    Unk_CMISIter<276> itEnd, itFind;
    return FUN_140d7b400(FUN_141157c80(&f298, &itFind, &nKey), FUN_141151df0(&f298, &itEnd)) != 0;
}
// @0x1410c92e0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410c92e0(int nId)
{
    Unk_CMISIter<284> it, itTmp, itOut, itEnd;
    FUN_141120750(&it);
    it = *FUN_14114e7f0(&f498, &itTmp);
    while (FUN_141127900(&it, FUN_141152450(&f498, &itEnd))) {
        if (FUN_14112e110(FUN_1409658e0(FUN_141128b30(&it))) == nId) {
            FUN_141227780(FUN_1409658e0(FUN_141128b30(&it)));
            FUN_141156b50(&f498, &itOut, it);
            return;
        }
        FUN_141129990(&it, &itTmp, 0);
    }
}
// @0x1410cb380
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410cb380(Unk_Int3 pt, const Unk_CMISEntityRef& ref)
{
    Unk_CMISEntityRef kRef(ref);
    if (FUN_1410cb420(&kRef) == 0) {
        int nKey = FUN_1408a13d0(*reinterpret_cast<Unk_StreamPoint*>(&pt));
        FUN_140899bd0(FUN_141127e90(&f108, &nKey), ref);
    }
}
// @0x1410d4680
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410d4680(ATL::CAtlArray<Unk_CMISHandle3a8>* pSrc)
{
    for (unsigned __int64 i = 0; i < FUN_140fac790(pSrc); i++) {
        Unk_CMISHandle3a8 h;
        FUN_140fac570(&h, FUN_14112dfe0(pSrc, i));
        FUN_14112d9b0(&a3a8, &h);
        FUN_140fac610(&h);
    }
}
// @0x1410d43c0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410d43c0(ATL::CAtlArray<Unk_CMISHandle388>* pSrc)
{
    for (unsigned __int64 i = 0; i < FUN_140fac7a0(pSrc); i++) {
        Unk_CMISHandle388 h;
        FUN_140fac5b0(&h, FUN_14112e020(pSrc, i));
        FUN_14112da60(&a388, &h);
        FUN_140fac640(&h);
    }
}
// @0x1410d59c0
// MS2-FUNCTIONAL: behaviour-equivalent; the exe frame has extra by-value temporaries / a different local order that no source form reproduced
void CubeMapInformationService::FUN_1410d59c0(ATL::CAtlArray<MS2Ptr<Cube>>* pOut)
{
    for (unsigned __int64 i = 0; i < FUN_140186260(&a458); i++) {
        int nKey = *FUN_1401844d0(&a458, i);
        Unk_CMISIter<260> itEnd, itFind;
        if (FUN_1411274c0(FUN_141157580(&f98, &itFind, &nKey), FUN_141151af0(&f98, &itEnd)))
            FUN_14112d900(pOut, FUN_141127cd0(&f98, &nKey));
    }
}

// ---- w138 batch 2 ----
struct Unk_CMISStr { __int64 m_a, m_b, m_c, m_d; };                                          // efd::utf8string (0x20)
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1407071e0(unsigned nObjCode);                                                        // the object code has a scenegraph
int FUN_140707260(unsigned nObjCode);                                                        // the object code has an animation
Unk_CMISStr* FUN_140ae18f0(Unk_CMISStr* pStr, const char* pSz);                              // operator=
Unk_CMISStr* FUN_14112cdc0(Unk_CMISStr* pStr, const char* pSz);                              // operator+=
Unk_CMISStr* FUN_14112cd90(Unk_CMISStr* pStr, Unk_CMISStr* pAdd);                            // operator+=
Unk_CMISStr* FUN_1409989e0(Unk_CMISStr* pStr, const char* pSz);                              // ctor
unsigned __int64 FUN_141158af0(Unk_CMISStr* pStr, const char* pFind, unsigned __int64 nPos); // rfind
Unk_CMISStr* FUN_14115afa0(Unk_CMISStr* pStr, Unk_CMISStr* pOut, unsigned __int64 nPos, unsigned __int64 nLen);   // substr
unsigned __int64 FUN_14208c9b0(Unk_CMISStr* pStr);                                           // length
void FUN_1408a8900(Unk_CMISStr* pStr);                                                       // dtor
void FUN_1408a20a0(egf::Entity* pEntity, unsigned nId, bool* pOut);                          // GetProperty(bool)

// @0x1410b77e0
// MS2-FUNCTIONAL: branch layout of the nested if/else and the MS2Ptr temporaries differ from the exe; same calls
int CubeMapInformationService::FUN_1410b77e0(int nItemId, Unk_CMISStr* pOut)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return 0;
    if (FUN_1407071e0(spItem->install.objCode) == 0) {
        FUN_140ae18f0(pOut, "urn:gamebryo-scenegraph:");
    } else {
        if (FUN_140707260(spItem->install.objCode) == 0)
            FUN_140ae18f0(pOut, "urn:gamebryo-scenegraph:");
        else
            FUN_140ae18f0(pOut, "urn:gamebryo-animation:");
    }
    if (FUN_1410cb980(nItemId) == 0) {
        if (spItem.get() != 0) {
            Unk_CMISStr sPath, sName;
            FUN_1409989e0(&sPath, (const char*)spItem->install.asset);
            __int64 nSlash = FUN_141158af0(&sPath, "/", (unsigned __int64)-1);
            __int64 nDot = FUN_141158af0(&sPath, ".", (unsigned __int64)-1);
            FUN_14115afa0(&sPath, &sName, nSlash + 1, (nDot - nSlash) - 1);
            if (FUN_14208c9b0(&sName) == 0)
                FUN_14112cdc0(pOut, "Empty");
            else
                FUN_14112cd90(pOut, &sName);
            FUN_1408a8900(&sName);
            FUN_1408a8900(&sPath);
        }
    } else {
        FUN_14112cdc0(pOut, "Empty");
    }
    return 1;
}
// @0x1410c5570
void CubeMapInformationService::FUN_1410c5570(Unk_EntRef spEnt)
{
    bool bFlag = false;
    FUN_1408a20a0((egf::Entity*)spEnt.FUN_1408a9280(), 0x38141815, &bFlag);
    if (bFlag == false)
        return;
    Unk_StreamPoint pt = FUN_1410c54a0(spEnt);
    GeneratePhysX(spEnt, pt);
}
// ---- w138 batch 3 ----
struct Unk_CMISCell56 { Unk_CMISCell56(const Unk_CMISCell56&); ~Unk_CMISCell56(); char m_pad[56]; };   // the 56-byte value of the cell tree (copy 0x141123050, dtor 0x141125ec0)
Unk_CMISCell56* FUN_141127b10(Unk_CMISTree<278>*, const int*);                              // operator[]
// @0x1410c2610
// MS2-FUNCTIONAL: exe keeps a constructed-flag around the 56-byte value copy (extra state)
bool CubeMapInformationService::FUN_1410c2610(Unk_Int3 pt)
{
    Unk_CMISIter<278> itEnd, itFind;
    int nKey = FUN_1408a03c0(pt);
    if (FUN_141127380(FUN_141157040(&f2b8, &itFind, &nKey), FUN_141151910(&f2b8, &itEnd)) != 0) {
        int nGroup = 0, nFloor = 0;
        Cube* pCube = FUN_1410b8a60(pt);
        if (pCube != 0) {
            nGroup = pCube->field50;
            nFloor = pCube->field54;
        }
        FUN_1410c1910(pt, 1);
        int nKey2 = FUN_1408a03c0(pt);
        Unk_CMISCell56 val(*FUN_141127b10(&f2b8, &nKey2));
        FUN_1410be0c0(pt, nGroup, nFloor, &val);
        return true;
    }
    FUN_1410c1910(pt, 0);
    return false;
}
struct Unk_CMISKeySet { Unk_CMISKeySet(); ~Unk_CMISKeySet(); void* m_a; void* m_b; void* m_c; };   // 0x18 bytes: set<int> (ctor 0x141122d00, dtor 0x141125cb0)
struct Unk_CMISSetIter { void* m_p; };
Unk_CMISIter<264>* FUN_141151970(Unk_CMISTree<264>*, Unk_CMISIter<264>*);                   // end
Unk_CMISIter<264>* FUN_141157200(Unk_CMISTree<264>*, Unk_CMISIter<264>*, const int*);       // find
bool FUN_141126c90(Unk_CMISIter<264>*, Unk_CMISIter<264>*);                                 // operator!=
void FUN_14115a8a0(Unk_CMISKeySet*, Unk_CMISCubeByKey*);                                    // insert
Unk_CMISSetIter* FUN_141152510(Unk_CMISKeySet*, Unk_CMISSetIter*);                          // end
Unk_CMISSetIter* FUN_14114e8d0(Unk_CMISKeySet*, Unk_CMISSetIter*);                          // begin
bool FUN_14076cf90(Unk_CMISSetIter*, Unk_CMISSetIter*);                                     // operator!=
int* FUN_14076d030(Unk_CMISSetIter*);                                                       // operator*
void FUN_14076d080(Unk_CMISSetIter*);                                                       // operator++
// @0x1410c2a90
// MS2-FUNCTIONAL: frame layout / EH state count differ in the cube loop
void CubeMapInformationService::FUN_1410c2a90(int nGroup)
{
    Unk_CMISIter<264> itEnd, itFind;
    if (FUN_141126c90(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd)) == 0) {
        Unk_CMISKeySet set;
        Unk_CMISIter<260> it, itEnd2;
        for (FUN_14114dd70(&f98, &it); FUN_1411274c0(&it, FUN_141151af0(&f98, &itEnd2)); FUN_141129b50(&it)) {
            MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
            if (spCube->field48 != 0) {
                if (spCube->field50 == nGroup)
                    FUN_14115a8a0(&set, FUN_1411285e0(&it));
            }
        }
        Unk_CMISKeySet* pSet = &set;
        Unk_CMISSetIter itSetEnd = *FUN_141152510(pSet, &itSetEnd);
        Unk_CMISSetIter itSet = *FUN_14114e8d0(pSet, &itSet);
        for (; FUN_14076cf90(&itSet, &itSetEnd); FUN_14076d080(&itSet))
            FUN_1410c2610(FUN_1408a0400(*FUN_14076d030(&itSet)));
    } else {
        FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] SalePost entity doesn't exist");
    }
}
struct Unk_CMISEntSet { __int64 m_a, m_b, m_c, m_d, m_e; };                                                 // set<entity id> (ctor 0x141122da0, dtor 0x141125d50)
void* FUN_1409657a0(Unk_PayloadPtr<Unk_CMISObj208>*);                                        // operator bool
void FUN_141122da0(Unk_CMISEntSet*);
void FUN_141125d50(Unk_CMISEntSet*);
void FUN_141126870(Unk_CMISEntSet*, Unk_CMISEntSet*);                                       // assign
void FUN_14115a990(Unk_CMISEntSet*, const Unk_CMISEntityRef*);                              // insert
Unk_CMISIter<271>* FUN_141151cd0(Unk_CMISTree<271>*, Unk_CMISIter<271>*);                   // end
Unk_CMISIter<271>* FUN_1411579e0(Unk_CMISTree<271>*, Unk_CMISIter<271>*, const int*);       // find
unsigned char FUN_141126ed0(Unk_CMISIter<271>*, Unk_CMISIter<271>*);                        // operator!=
Unk_CMISEntSet* FUN_141127e50(Unk_CMISTree<271>*, const int*);                              // operator[]
void FUN_14098c6e0(egf::Entity*, unsigned, bool*);                                          // SetProperty(bool)
// @0x1410c2ce0
// MS2-FUNCTIONAL: std::map floors + EH state of the entity set differ from the exe's inlined tree helpers
void CubeMapInformationService::FUN_1410c2ce0(egf::Entity* pEntity)
{
    if (f218 != 0 && FUN_1409657a0(&f208) != 0) {
        if (FUN_140885340(&f208)->FUN_140375100() != 0)
            return;
        Unk_StreamPoint pt = DAT_143b01a60;
        FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
        int nFound = 0;
        for (unsigned __int64 nFloor = 1; nFloor <= f218->floors.size(); ++nFloor) {
            int nKey = (int)nFloor;
            std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
            if (f218->floors.find(nKey) != itEnd) {
                if (f218->floors[nKey].startHeight <= pt.z)
                    nFound = (int)nFloor;
            }
        }
        if (nFound != 0) {
            Unk_CMISIter<271> itTmp, itTmp2;
            Unk_CMISIter<271>* pEnd = FUN_141151cd0(&f1e8, &itTmp);
            if (FUN_141126ed0(FUN_1411579e0(&f1e8, &itTmp2, &nFound), pEnd) != 0) {
                Unk_CMISEntSet setNew;
                FUN_141122da0(&setNew);
                FUN_141126870(FUN_141127e50(&f1e8, &nFound), &setNew);
                FUN_141125d50(&setNew);
            }
            Unk_CMISEntSet* pSet = FUN_141127e50(&f1e8, &nFound);
            FUN_14115a990(pSet, FUN_1408b76f0(pEntity));
            if (f1e0 != nFound) {
                bool bFlag = false;
                FUN_14098c6e0(pEntity, 0xa0b6b179, &bFlag);
            }
        }
    }
}
Unk_CMISIter<280>* FUN_141152270(Unk_CMISTree<280>*, Unk_CMISIter<280>*);                   // end
Unk_CMISIter<280>* FUN_141158540(Unk_CMISTree<280>*, Unk_CMISIter<280>*, const int*);       // find
unsigned char FUN_1408b71b0(Unk_CMISIter<280>*, Unk_CMISIter<280>*);                        // operator!=
// @0x1410c3cd0
bool CubeMapInformationService::FUN_1410c3cd0(int nKey)
{
    Unk_CMISIter<280> itEnd, itFind;
    if (FUN_1408b71b0(FUN_141158540(&f368, &itFind, &nKey), FUN_141152270(&f368, &itEnd)) != 0)
        return false;
    if (*FUN_141128310(&f368, &nKey) == 0)
        return false;
    int nState = FUN_1410c3e80(nKey);
    if (nState != 0) {
        if (FUN_1410c3180() == DAT_143ab2820 && nState == 1)
            return false;
        if (nState == 2) {
            if (FUN_1410c3180() == DAT_143ab2820)
                return false;
            Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pRoster == 0)
                return true;
            if (pRoster->FUN_141527920(FUN_1410c3180()) != 0)
                return false;
        }
    }
    return true;
}
struct Unk_CMISHouseRec { __int64 m_q0, m_q1, m_q2; int m_state, m_pad; __int64 m_value; };   // the house record (state at 0x18, value at 0x20)
void FUN_1408a0890(int, int, int*);
struct Unk_CMISHouseRef                                                                     // MS2Ptr<house record>
{
    Unk_CMISHouseRef(void* p);                                                              // 0x14111ea00
    Unk_CMISHouseRef(void** pSlot);                                                         // 0x14111e9c0 (copy of a map slot)
    ~Unk_CMISHouseRef();                                                                    // 0x141123820
    void* m_p;
    void* FUN_141128410();                                                                  // operator bool
    Unk_CMISHouseRec* FUN_1411284b0();                                                      // operator->
};
// @0x1410c8470
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
bool CubeMapInformationService::FUN_1410c8470(int nA, int nB, int* pState, __int64* pValue)
{
    int nFlag = 0;
    FUN_1408a0890(nB, nA, &nFlag);
    int nIsOne = 0;
    if (nFlag == 1)
        nIsOne = 1;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nIsOne));
    if (spHouse.FUN_141128410() == 0 || (spHouse.FUN_1411284b0()->m_state != 4 && spHouse.FUN_1411284b0()->m_state != 1))
        return false;
    *pState = spHouse.FUN_1411284b0()->m_state;
    *pValue = spHouse.FUN_1411284b0()->m_value;
    return true;
}
struct Unk_CMISPartyRef                                                                     // MS2Ptr<party info>
{
    Unk_CMISPartyRef(void* p);                                                              // 0x14050dd40
    ~Unk_CMISPartyRef();                                                                    // 0x14050de40
    void* m_p;
    void* FUN_140fa9d30();                                                                  // operator bool
    Unk_CMISParty* FUN_14050dee0();                                                         // operator->
};
struct Unk_CMISSalable { Unk_CMISSalable(); ~Unk_CMISSalable(); void* m[25]; };               // ctor 0x1408ad110, dtor 0x14050de70
int FUN_1408a0d30(int, Unk_CMISSalable*, int);
// @0x1410c80d0
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
bool CubeMapInformationService::FUN_1410c80d0(int nGroup)
{
    Unk_CMISSalable salable;
    if (FUN_1408a0d30(nGroup, &salable, FUN_1403ed2d0()->FUN_141bd3060()) == 0)
        return false;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, 0);
    if (spOwner == 0)
        return false;
    return true;
}
// @0x1410c8580
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
int CubeMapInformationService::FUN_1410c8580(int nGroup)
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster->FUN_141527e00() == 0) {
        Unk_CMISPartyRef spParty(pRoster->FUN_141523c50());
        if (spParty.FUN_140fa9d30() != 0) {
            if (spParty.FUN_14050dee0()->m_map == FUN_1403ed2d0()->FUN_141bd3060() && spParty.FUN_14050dee0()->m_key == nGroup)
                return 0x31;
        }
    }
    if (FUN_1410c80d0(nGroup) == 0)
        return 0x2f;
    return 0;
}
// @0x1410c78b0
// MS2-FUNCTIONAL: unwind-state locals of the exe's result temporaries differ
Unk_CubeOwnerMap* CubeMapInformationService::FUN_1410c78b0(int nGroup)
{
    static Unk_CubeOwnerMap s_empty;
    Unk_CubeOwners& owners = reinterpret_cast<Unk_CubeOwners&>(f138);
    Unk_CubeOwners::iterator itEnd = owners.end();
    if (owners.find(nGroup) != itEnd)
        return &owners[nGroup];
    return &s_empty;
}
int FUN_1407072e0(int);
// @0x1410cb980
int CubeMapInformationService::FUN_1410cb980(int nItemId)
{
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem.IsNull())
        return 0;
    if (spItem->install.asset.IsEmpty() && spItem->install.preset.IsEmpty())
        return 1;
    if (FUN_1407072e0(spItem->install.objCode) != 0)
        return 1;
    return 0;
}
// ---- w138 batch 4 ----
struct Unk_CMISInvEntry { __int64 m_q0, m_q1, m_q2; unsigned m_count; unsigned m_need; };    // inventory slot (count at 0x18, need at 0x1c)
struct Unk_CMISInvKey { int m_item; unsigned m_need; };
struct Unk_CMISInvPtr                                                                       // MS2Ptr<inventory slot>
{
    Unk_CMISInvPtr(int);                                                                    // 0x1408882c0
    Unk_CMISInvPtr(void* pNode);                                                            // 0x140eba830
    ~Unk_CMISInvPtr();                                                                      // 0x140888a90
    void* m_a; Unk_CMISInvEntry* m_p;
    bool FUN_141126ad0(int);                                                                // operator==
    Unk_CMISInvEntry* FUN_140889010();                                                      // operator->
};
class Unk_CMISInv
{
public:
    __int64 FUN_140ebb080();                                                                // first position
    void* FUN_140ebb100(__int64 pos);                                                       // the node at a position
    void FUN_140ebb030(__int64* pPos);                                                      // next position
    bool FUN_14088acd0(Unk_CMISInvKey* pKey, Unk_CMISInvPtr* pOut);                         // find by item and need
};
class Unk_CMISInvMgr;
Unk_CMISInvMgr* FUN_1409eed80();
Unk_CMISInv* FUN_140886640(Unk_CMISInvMgr*);
Unk_CMISIter<282>* FUN_14114e470(Unk_CMISTree<282>*, Unk_CMISIter<282>*);                   // begin
Unk_CMISIntPair* FUN_1411287a0(Unk_CMISIter<282>*);                                         // operator*
void FUN_141129cd0(Unk_CMISIter<282>*);                                                     // operator++
// @0x1410d50c0
unsigned __int64 CubeMapInformationService::FUN_1410d50c0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    for (__int64 pos = pInv->FUN_140ebb080(); pos != 0; pInv->FUN_140ebb030(&pos)) {
        Unk_CMISInvPtr spSlot(pInv->FUN_140ebb100(pos));
        if (spSlot.FUN_141126ad0(0) != 0)
            continue;
        nTotal += spSlot.FUN_140889010()->m_count;
    }
    return nTotal;
}
// @0x1410d4fa0
// MS2-FUNCTIONAL: iterator/key stack slots swapped vs the exe (same calls and order)
unsigned __int64 CubeMapInformationService::FUN_1410d4fa0()
{
    unsigned __int64 nTotal = 0;
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISIter<282> it, itEnd;
    Unk_CMISInvKey key;
    for (FUN_14114e470(&f3c8, &it); FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)); FUN_141129cd0(&it)) {
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&key, &spSlot) != 0) {
            if (key.m_need >= spSlot.FUN_140889010()->m_need)
                nTotal += spSlot.FUN_140889010()->m_count;
        }
    }
    return nTotal;
}
// @0x1410d5190
// MS2-FUNCTIONAL: iterator/key stack slots swapped vs the exe (same calls and order)
void CubeMapInformationService::FUN_1410d5190(unsigned __int64* pCubes, unsigned __int64* pOthers)
{
    Unk_CMISInv* pInv = FUN_140886640(FUN_1409eed80());
    Unk_CMISIter<282> it, itEnd;
    Unk_CMISInvKey key;
    for (FUN_14114e470(&f3c8, &it); FUN_141127110(&it, FUN_141152150(&f3c8, &itEnd)); FUN_141129cd0(&it)) {
        key.m_item = FUN_1411287a0(&it)->m_key;
        key.m_need = FUN_1411287a0(&it)->m_val;
        Unk_CMISInvPtr spSlot(0);
        if (pInv->FUN_14088acd0(&key, &spSlot) != 0) {
            if (key.m_need >= spSlot.FUN_140889010()->m_need)
                *pCubes += spSlot.FUN_140889010()->m_count;
        }
    }
    for (__int64 pos = pInv->FUN_140ebb080(); pos != 0; pInv->FUN_140ebb030(&pos)) {
        Unk_CMISInvPtr spSlot(pInv->FUN_140ebb100(pos));
        if (spSlot.FUN_141126ad0(0) != 0)
            continue;
        *pOthers += spSlot.FUN_140889010()->m_count;
    }
}
// @0x1410d5350
void CubeMapInformationService::FUN_1410d5350()
{
    Unk_CMISIter<260> it, itEnd;
    for (FUN_14114dd70(&fb8, &it); FUN_1411274c0(&it, FUN_141151af0(&fb8, &itEnd)); FUN_141129b50(&it)) {
        MS2Ptr<Cube> spCube(FUN_1411285e0(&it)->second);
        if (spCube.get() != 0) {
            Unk_Int3 pos = spCube->position;
            if (pos.x < p300.x || pos.x > p30c.x || pos.y < p300.y || pos.y > p30c.y || pos.z < p300.z || pos.z > f2fc) {
                COutPacket packet(0x37, 0);
                packet.vfunc_o10_1(0x1f);
                FUN_140710590(packet);
                return;
            }
        }
    }
}
// ---- w138 batch 5 ----
struct Unk_CMISDesignInfo { __int64 m_q0, m_q1, m_q2; int m_id; int m_pad; CStringA m_name; __int64 m_value; };   // UGCMapDesignInfo (0x30)
struct Unk_CMISDesignPtr                                                                     // MS2Ptr<UGCMapDesignInfo>
{
    Unk_CMISDesignPtr(const Unk_CMISHandle388& src);                                     // 140fac5b0
    Unk_CMISDesignPtr(Unk_CMISDesignInfo* p);                                               // 14111eaa0
    ~Unk_CMISDesignPtr();                                                                   // 140fac640
    void* m_a; Unk_CMISDesignInfo* m_p;
    void* FUN_141128430();                                                                  // operator bool
    Unk_CMISDesignInfo* FUN_140fac700();                                                   // operator->
};
Unk_CMISDesignInfo* FUN_140898780(void* pMem);                                              // UGCMapDesignInfo::UGCMapDesignInfo
void FUN_14112da60(ATL::CAtlArray<Unk_CMISElem388*>*, const Unk_CMISDesignPtr*);          // Add
// @0x1410d4450
// MS2-FUNCTIONAL: exe keeps one more EH state around the new-expression result; same calls
void CubeMapInformationService::FUN_1410d4450(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < FUN_140fac7a0(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388)); i++) {
        Unk_CMISDesignPtr spInfo(*FUN_14112e020(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle388>*>(&a388), i));
        if (spInfo.FUN_141128430() != 0 && spInfo.FUN_140fac700()->m_id == nIdx) {
            spInfo.FUN_140fac700()->m_name = strName;
            spInfo.FUN_140fac700()->m_value = nValue;
            return;
        }
    }
    void* pMem = ::operator new(0x30);
    Unk_CMISDesignInfo* pNew = 0;
    if (pMem != 0)
        pNew = FUN_140898780(pMem);
    Unk_CMISDesignPtr spNew(pNew);
    spNew.FUN_140fac700()->m_id = nIdx;
    spNew.FUN_140fac700()->m_name = strName;
    spNew.FUN_140fac700()->m_value = nValue;
    FUN_14112da60(&a388, &spNew);
}
struct Unk_CMISBlueprintInfo { __int64 m_q0, m_q1, m_q2; int m_id; int m_pad; CStringA m_name; __int64 m_value; };   // UGCMapBlueprintInfo (0x30)
struct Unk_CMISBlueprintPtr                                                                     // MS2Ptr<UGCMapBlueprintInfo>
{
    Unk_CMISBlueprintPtr(const Unk_CMISHandle3a8& src);                                     // 140fac570
    Unk_CMISBlueprintPtr(Unk_CMISBlueprintInfo* p);                                               // 14111ea50
    ~Unk_CMISBlueprintPtr();                                                                   // 140fac610
    void* m_a; Unk_CMISBlueprintInfo* m_p;
    void* FUN_141128420();                                                                  // operator bool
    Unk_CMISBlueprintInfo* FUN_140fac6f0();                                                   // operator->
};
Unk_CMISBlueprintInfo* FUN_1408987f0(void* pMem);                                              // UGCMapBlueprintInfo::UGCMapBlueprintInfo
void FUN_14112d9b0(ATL::CAtlArray<Unk_CMISElem3a8*>*, const Unk_CMISBlueprintPtr*);          // Add
// @0x1410d4710
// MS2-FUNCTIONAL: exe keeps one more EH state around the new-expression result; same calls
void CubeMapInformationService::FUN_1410d4710(__int64 nId, int nIdx, CStringA strName, __int64 nValue)
{
    if (FUN_1410c3180() != nId)
        return;
    for (unsigned __int64 i = 0; i < FUN_140fac790(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8)); i++) {
        Unk_CMISBlueprintPtr spInfo(*FUN_14112dfe0(reinterpret_cast<ATL::CAtlArray<Unk_CMISHandle3a8>*>(&a3a8), i));
        if (spInfo.FUN_141128420() != 0 && spInfo.FUN_140fac6f0()->m_id == nIdx) {
            spInfo.FUN_140fac6f0()->m_name = strName;
            spInfo.FUN_140fac6f0()->m_value = nValue;
            return;
        }
    }
    void* pMem = ::operator new(0x30);
    Unk_CMISBlueprintInfo* pNew = 0;
    if (pMem != 0)
        pNew = FUN_1408987f0(pMem);
    Unk_CMISBlueprintPtr spNew(pNew);
    spNew.FUN_140fac6f0()->m_id = nIdx;
    spNew.FUN_140fac6f0()->m_name = strName;
    spNew.FUN_140fac6f0()->m_value = nValue;
    FUN_14112d9b0(&a3a8, &spNew);
}
// ---- w138 batch 6 ----
bool FUN_1411272b0(const Unk_Int3*, const Unk_Int3*);
Unk_CMISRes16 FUN_1408a15b0(Unk_Int3, const Unk_StreamPoint&);                              // the world point of a cell (writes the xy centre)                                        // operator==
// @0x1410d2da0
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
bool CubeMapInformationService::FUN_1410d2da0(int nKey, Unk_Int3 pt)
{
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind, &nKey), FUN_141151c70(&fd8, &itEnd)) == 0) {
        Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nKey);
        Unk_CMISListIter it;
        Unk_CMISListEnd itListEnd;
        for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
            Unk_Int3 cell = FUN_1408a0400(*FUN_1403e8d70(&it));
            cell.z = cell.z + 1;
            if (FUN_1411272b0(&cell, &pt))
                return true;
        }
    }
    return false;
}
// @0x1410d23f0
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
int CubeMapInformationService::FUN_1410d23f0(int nGroup, int nBlock)
{
    int nHeight = 0;
    Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
    bool bNoOwner = spOwner == 0;
    spOwner = 0;
    if (!bNoOwner) {
        if (FUN_140885340(&f208)->FUN_140375130() == 0) {
            if (f218 != 0) {
                std::map<int, Unk_UGCGroup>::iterator itEnd = f218->groups.end();
                if (f218->groups.find(nGroup) != itEnd)
                    nHeight = f218->groups[nGroup].heightLimit;
            }
        } else {
            nHeight = f2fc;
        }
    }
    return nHeight;
}
// @0x1410d2130
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
bool CubeMapInformationService::FUN_1410d2130(Cube* pCube, int nDir, float fSize, float* pOutXY, Unk_StreamPoint* pOutPt)
{
    Unk_StreamPoint ptCenter;
    FUN_1408a15b0(pCube->position, ptCenter);
    float fHalf = 75.0f + fSize * 0.5f;
    *pOutPt = DAT_143b01a60;
    if (nDir == 1) {
        pOutPt->z = 225.0f;
        pOutXY[0] = ptCenter.x - fHalf;
        pOutXY[1] = ptCenter.y + fHalf;
        return true;
    } else if (nDir == 3) {
        pOutPt->z = 135.0f;
        pOutXY[0] = ptCenter.x + fHalf;
        pOutXY[1] = ptCenter.y + fHalf;
        return true;
    } else if (nDir == 5) {
        pOutPt->z = 45.0f;
        pOutXY[0] = ptCenter.x + fHalf;
        pOutXY[1] = ptCenter.y - fHalf;
        return true;
    } else if (nDir == 7) {
        pOutPt->z = 315.0f;
        pOutXY[0] = ptCenter.x - fHalf;
        pOutXY[1] = ptCenter.y - fHalf;
        return true;
    }
    return false;
}
int FUN_1410a8a90(void*);
// @0x1410d2590
// MS2-FUNCTIONAL: branch/return layout of the result differs from the exe; same calls and compares
int CubeMapInformationService::FUN_1410d2590(Unk_Int3 pt, int nGroup, int nBlock)
{
    Unk_Int3 cell = pt;
    cell.z = cell.z - 1;
    int nHeight = FUN_1410d23f0(nGroup, nBlock);
    if (nHeight == 0)
        return 1;
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster == 0)
        return 0;
    if (pRoster->FUN_141530290() == 0)
        return 0;
    Cube* pCube = 0;
    if (FUN_1410a8a90(pRoster->FUN_141530290()) != 2)
        pCube = FUN_1410b8790(cell);
    else
        pCube = FUN_1410b8980(cell);
    if (pCube == 0)
        return 0;
    cell = pCube->position;
    if (pCube->field44 != 1)
        cell.z = cell.z - 1;
    if (cell.z > pt.z)
        return 0;
    else if (cell.z + nHeight < pt.z)
        return 0;
    else
        return 1;
}
// @0x1410c3fc0
// MS2-FUNCTIONAL: std::map floors vs the exe's inlined tree helpers; stack frame differs
void CubeMapInformationService::FUN_1410c3fc0(PCBase* pActor, float* pOutLo, float* pOutHi)
{
    if (f218 == 0) {
        *pOutLo = 0.0f;
        *pOutHi = 0.0f;
        return;
    }
    Unk_StreamPoint ptFront;
    FUN_1410b7ad0(pActor, 0, &ptFront, 0);
    Unk_StreamPoint ptCell;
    FUN_1410b7a20(ptFront, &ptCell);
    int nFound = 0;
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
        if (f218->floors.find(nKey) != itEnd) {
            if (f218->floors[nKey].startHeight <= ptCell.z)
                nFound = (int)nFloor;
        }
    }
    if (nFound != 0) {
        Unk_UGCFloor& floor = f218->floors[nFound];
        *pOutLo = floor.startHeight;
        *pOutHi = floor.startHeight + (float)floor.field4 * 150.0f;
    }
}
// ---- w138 batch 4 ----
struct Unk_CMISItemData { char pad[0x1c4]; int field1c4; };
class Unk_CMISItemRef                                                                       // item ptr passed by value (the callee destroys it)
{
public:
    ~Unk_CMISItemRef();                                                                     // 0x1401b50d0
    Unk_CMISItemData* FUN_1401b52a0();
    void* FUN_140203c60();
    bool IsSet() { return FUN_140203c60() ? true : false; }
    void* m_unknown;
    void* m_pObject;
};
bool FUN_140930c90(__int64 nOwner);
bool FUN_140930d20(__int64 nOwner);
extern int DAT_143ae0fb4;
// @0x1410c6980
// MS2-FUNCTIONAL: item-ptr bool test is an inlined operator bool with a byte temporary in the exe; frame 0x4 larger
int CubeMapInformationService::FUN_1410c6980(Cube* pCube, int nKind, Unk_CMISItemRef rItem, __int64 nOwner, int nMode)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    switch (nMode) {
    case 3: {
        if (rItem.IsSet() && rItem.FUN_1401b52a0()->field1c4 != 0)
            return 0;
        __int64 nCur = FUN_1410c8030(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    case 4: {
        __int64 nCur = FUN_1410c8030(pCube->field50, pCube->field54);
        if (nCur != nOwner && !FUN_140930c90(nCur) && !FUN_140930d20(nCur))
            return 0;
        break;
    }
    }
    return 1;
}
struct Unk_CMISSaleState { Unk_CMISSaleState(); char m_pad[0x28]; };                        // ctor 0x141123290
void FUN_141126340(void** pSlot, Unk_CMISHouseRef& rRef);                                   // assign into a map slot
// @0x1410c7a50
// MS2-FUNCTIONAL: exe keeps the iterators and make_pair results in unwind-state temporaries
void CubeMapInformationService::FUN_1410c7a50(int nA, int nB, int nState, __int64 nValue)
{
    Unk_CMISIter<263> itEnd;
    Unk_CMISIter<263> itFind;
    if (FUN_141126fd0(FUN_141157f20(&fe8, &itFind, FUN_14111d460(nA, nB)), FUN_141151f70(&fe8, &itEnd)) != 0) {
        Unk_CMISHouseRef spNew(new Unk_CMISSaleState());
        FUN_141126340(FUN_141128090(&fe8, FUN_14111d460(nA, nB)), spNew);
    }
    Unk_CMISHouseRef spHouse(FUN_141128090(&fe8, FUN_14111d460(nA, nB)));
    spHouse.FUN_1411284b0()->m_state = nState;
    spHouse.FUN_1411284b0()->m_value = nValue;
    FUN_1410bbcd0(nA, nB);
}
// @0x1410c81c0
// MS2-FUNCTIONAL: exe spills the iterator and list temporaries; frame is larger
int CubeMapInformationService::FUN_1410c81c0(int nGroup, int* pnWidth, int* pnHeight, int* pnDepth)
{
    *pnWidth = 0;
    *pnHeight = 0;
    *pnDepth = 0;
    if (FUN_140965240(&f208, 0))
        return 0;
    if (FUN_140885340(&f208)->FUN_140375130())
        nGroup = 1;
    Unk_CMISIter<262> itEnd, itFind;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind, &nGroup), FUN_141151c70(&fd8, &itEnd)))
        return 0;
    int nMinX = 0x7fffffff, nMaxX = -0x7fffffff - 1;
    int nMinY = 0x7fffffff, nMaxY = -0x7fffffff - 1;
    Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
    Unk_CMISListIter it;
    Unk_CMISListEnd itListEnd;
    for (FUN_14114e630(pList, &it); FUN_14035ea60(&it, FUN_1411522d0(pList, &itListEnd)); FUN_14035ebf0(&it)) {
        Unk_Int3 pt = FUN_1408a0400(*FUN_1403e8d70(&it));
        if (FUN_1410b8980(pt) != 0) {
            if (pt.x < nMinX)
                nMinX = pt.x;
            if (nMaxX < pt.x)
                nMaxX = pt.x;
            if (pt.y < nMinY)
                nMinY = pt.y;
            if (nMaxY < pt.y)
                nMaxY = pt.y;
        }
    }
    *pnWidth = nMaxX - nMinX + 1;
    *pnHeight = f218->groups[nGroup].heightLimit + 1;
    *pnDepth = nMaxY - nMinY + 1;
    return 1;
}
// @0x1410c88b0
// MS2-FUNCTIONAL: std::map floors vs the exe's inlined tree helpers; stack frame differs
int CubeMapInformationService::FUN_1410c88b0(PCBase* pActor)
{
    int nFound = 0;
    if (f218 == 0)
        return 0;
    Unk_StreamPoint ptFront;
    FUN_1410b7ad0(pActor, 0, &ptFront, 0);
    Unk_StreamPoint ptCell;
    FUN_1410b7a20(ptFront, &ptCell);
    for (unsigned __int64 nFloor = 1; nFloor <= (unsigned __int64)(__int64)f1dc; ++nFloor) {
        int nKey = (int)nFloor;
        std::map<int, Unk_UGCFloor>::iterator itEnd = f218->floors.end();
        if (f218->floors.find(nKey) == itEnd)
            continue;
        if (f218->floors[nKey].startHeight <= ptCell.z)
            nFound = (int)nFloor;
    }
    return nFound;
}
__int64 FUN_141656ad0(Unk_CMISRoster*);
// @0x1410ca900
int CubeMapInformationService::FUN_1410ca900(int nGroup)
{
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster != 0) {
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, f1b0);
        if (!(spOwner == 0)) {
            if (spOwner->ownerID == FUN_141656ad0(pRoster)) {
                Unk_CMISListIter it;
                Unk_CMISListEnd itListEnd;
                Unk_CMISIntList* pList = FUN_141127e10(&fd8, &nGroup);
                if (FUN_14035ea60(FUN_14114e630(pList, &it), FUN_1411522d0(pList, &itListEnd)))
                    return 1;
            }
        }
    }
    return 0;
}
// @0x1410cdd80
int CubeMapInformationService::FUN_1410cdd80(Unk_StreamPoint* pFrom, Unk_StreamPoint* pTo, float fDist, Unk_Int3* pOffset)
{
    if (DAT_143ae0fb4 != 0)
        return 1;
    if (FUN_1408a07b0(FUN_1403ed2d0()->FUN_141bd3060(), DAT_1439f4a7c, DAT_143ab2820))
        return 1;
    Unk_StreamPoint ptHit;
    FUN_1410b7ba0(*pFrom, *pTo, -fDist, &ptHit, 0);
    Unk_Int3 kCell = FUN_1408a1430(ptHit);
    Unk_Int3 kSum;
    kCell = *FUN_14112ca20(&kCell, &kSum, pOffset);
    int nKey = FUN_1408a03c0(kCell);
    Unk_CMISIter<276> itEnd, itFind;
    return FUN_140d7b400(FUN_141157c80(&f298, &itFind, &nKey), FUN_141151df0(&f298, &itEnd)) ? 1 : 0;
}
struct Unk_EntityAppFramework;
extern Unk_EntityAppFramework DAT_143b059e8;
HardwareInstancingService* FUN_14098c5b0(Unk_EntityAppFramework*);
int FUN_1413d6890(HardwareInstancingService*, egf::Entity*);
egf::Entity* FUN_14112e0d0(const egf::EntityChangeMessage*);
void FUN_1408b4fd0(Cube* pCube, egf::Entity* pEntity);                                      // Cube::SetEntity
class Unk_CMISSvcPtr                                                                        // smart pointer to a framework service
{
public:
    Unk_CMISSvcPtr(HardwareInstancingService* p);                                           // 0x14098c7d0
    ~Unk_CMISSvcPtr();                                                                      // 0x14098cc60
    HardwareInstancingService* FUN_14098d0e0() const;                                       // operator->
    void* FUN_14098d090() const;                                                            // operator bool (returns the pointer)
private:
    void* m_p;
};
// @0x1410cef70
// MS2-FUNCTIONAL: the exe's service-pointer truth test is an inlined bool conversion with a byte temporary; frame differs
void CubeMapInformationService::FUN_1410cef70(const egf::EntityChangeMessage* pMsg, efd::Category)
{
    if (FUN_1403ed2d0()->FUN_141bcfd10() == 6)
        return;
    egf::Entity* pEntity = FUN_14112e0d0(pMsg);
    Unk_CMISSvcPtr spInst(FUN_14098c5b0(&DAT_143b059e8));
    if (spInst.FUN_14098d090() != 0 && FUN_1413d6890(spInst.FUN_14098d0e0(), pEntity) != 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bcfd10() == 4)
        FUN_1410cf5c0(pEntity);
    else
        FUN_1410cf160(pEntity);
    Unk_StreamPoint pt = DAT_143b01a60;
    FUN_1409618c0(pEntity, 0xfd95ca52, &pt);
    int nKey = FUN_1408a13d0(pt);
    Cube* pCube = FUN_1410b8b00(nKey);
    if (pCube != 0)
        FUN_1408b4fd0(pCube, pEntity);
    FUN_1410c5280(nKey);
}
class UIMainPlayerInfo;
__int64 FUN_140931900(int nUiId);
UIHomeInfoDialog* FUN_140bbea00(int nId);
class Unk_CMISNotifyMgr { public: void FUN_140da4fe0(MS2Ptr<NotifyObject> spNotify); };
Unk_CMISNotifyMgr* FUN_140939a10();
class Unk_CMISNotifyBuilding : public NotifyObject                                          // NotifyChangeUIBuildingCount (0x20 bytes, ctor 0x141123250)
{
public:
    Unk_CMISNotifyBuilding(const int* pCount);
    int m_nCount;
};
// @0x1410ce1e0
void CubeMapInformationService::FUN_1410ce1e0(int nNotify, const int* pCount)
{
    __int64 nInfo = FUN_140931900(0x4e5f);
    if (nInfo == 0)
        return;
    if (nNotify != 0) {
        Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pRoster == 0)
            return;
        UIHomeInfoDialog* pDlg = FUN_140bbea00(0x4ed8);
        if (pDlg != 0 && pDlg->vfunc_9() != 0)
            pDlg->FUN_1412c5690();
        FUN_140939a10()->FUN_140da4fe0(MS2Ptr<NotifyObject>(new Unk_CMISNotifyBuilding(pCount)));
    }
}
int FUN_1408b56c0(MS2Ptr<CItemData> spItem);
int FUN_1408b58c0(MS2Ptr<CItemData> spItem);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
int FUN_1408b4f20(Cube* pCube);
// @0x1410ce020
// MS2-FUNCTIONAL: the exe's by-value item-ptr copies carry fewer unwind states (10 vs 13); symbol pairing of the MS2Ptr helpers differs
void CubeMapInformationService::FUN_1410ce020(MS2Ptr<Cube> spCube)
{
    if (spCube.IsNull())
        return;
    int nItemId = FUN_1408b4f20(spCube.operator->());
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (spItem == 0)
        return;
    if (!spItem->FUN_14053d940()) {
        if (FUN_1408b56c0(spItem) == 0 && FUN_1408b58c0(spItem) == 0)
            return;
    }
    Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pRoster != 0) {
        __int64 nMe = FUN_141656ad0(pRoster);
        Cube* pCube = spCube.operator->();
        __int64 nOwner = FUN_1410c8030(spCube->field50, pCube->field54);
        if (nMe == nOwner)
            FUN_1410ce1e0(1, &nItemId);
    }
}
CStringW FUN_14028de60(int nStringId);
// @0x1410c7ce0
// MS2-FUNCTIONAL: exe spills the owner-temporary pointer through two extra locals; frame 0x10 larger
CStringW CubeMapInformationService::FUN_1410c7ce0(int nA, int nB)
{
    CStringW strText;
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nA, nB) != 0;
    if (bHasOwner)
        return strText;
    strText = FUN_14028de60(0x7e7);
    int nState = 2;
    Unk_CMISHouseRef spHouse(FUN_1410c7c20(nA, nB));
    if (spHouse.FUN_141128410() != 0)
        nState = spHouse.FUN_1411284b0()->m_state;
    if (nState == 4)
        strText = FUN_14028de60(0x7e8);
    if (FUN_1410c80d0(nB) == 0)
        strText = FUN_14028de60(0x7e9);
    return strText;
}
class Unk_CMISOwnerSvc { public: int FUN_140ae52d0(int nMapId, int nGroup); };
Unk_CMISOwnerSvc* FUN_14097a780();
// @0x1410c8670
// MS2-FUNCTIONAL: exe's unwind-state / temporaries layout differs (frame 0x10 larger)
int CubeMapInformationService::FUN_1410c8670(int nGroup, int* pnFlag)
{
    int nResult = 0;
    Unk_CMISRoster* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0) {
        nResult = 0;
    } else {
        int nMapId = FUN_1403ed2d0()->FUN_141bd3060();
        *pnFlag = 0;
        FUN_1408a0890(nMapId, nGroup, pnFlag);
        int nFlag = *pnFlag;
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nFlag == 1);
        if (spOwner.get() == 0) {
            if (pPC->FUN_141527e00() == 0) {
                Unk_CMISPartyRef spParty(pPC->FUN_141523c50());
                if (spParty.FUN_14050dee0()->m_key == nGroup) {
                    if (spParty.FUN_14050dee0()->m_map == FUN_1403ed2d0()->FUN_141bd3060())
                        nResult = 2;
                }
            }
            int nState = 2;
            Unk_CMISHouseRef spHouse(FUN_1410c7c20(nGroup, nFlag == 1));
            if (spHouse.FUN_141128410() != 0)
                nState = spHouse.FUN_1411284b0()->m_state;
            if (nState == 4)
                nResult = 1;
        } else {
            if (spOwner->ownerID == FUN_141656ad0(pPC)) {
                nResult = 2;
            } else {
                if (FUN_14097a780()->FUN_140ae52d0(nMapId, nGroup) == 0)
                    nResult = 3;
                else
                    nResult = 3;
            }
        }
    }
    return nResult;
}
// ---- sale-post effect request (shared by c4240 / c44b0) ----
void FUN_1408a10e0(Unk_CubeOwners& owners, int nGroup, int nBlock, const CStringW& strName, __int64 nOwnerId);
void FUN_1408a0eb0(Unk_CubeOwners& owners, int nGroup, int nBlock);
struct Unk_CMISEffReq                                                                       // an effect play request (0x78 bytes; ctor 0x140a52ef0, dtor 0x1405a89e0)
{
    CString m_strName;                                                                      // +0
    int m_nOwnerId;                                                                         // +8
    int m_pad_0c;
    void* m_pSlot10;                                                                        // +0x10 (the attach node)
    char m_pad_18[0x60];
};
MS2_CHECK_SIZE(Unk_CMISEffReq, 0x78);
void FUN_140a52ef0(Unk_CMISEffReq* p);
void FUN_1405a89e0(Unk_CMISEffReq* p);
struct Unk_CMISConsts { char m_pad_00[0x300]; CString m_strSaleEffect; };                   // game-wide constants (the sale-post effect name at +0x300)
Unk_CMISConsts* FUN_1401d31f0();
class Unk_CMISEffMgr { public: void FUN_1411a4a00(Unk_CMISEffReq* pRequest); };
Unk_CMISEffMgr* FUN_1403ed280();
bool FUN_1411273c0(Unk_CMISIter<264>*, Unk_CMISIter<264>*);                                 // operator!=
Unk_CMISEntityRef* FUN_141127b90(Unk_CMISTree<264>*, const int*);                           // operator[]
egf::Entity* FUN_1408a9090(Unk_CMISEntityRef*);                                             // the entity of a ref
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                            // the scene root of an entity
NiObject* FUN_14098d8d0(const NiRTTI* pRTTI, NiObject* pObject);                            // NiNode-checked dynamic cast
extern NiRTTI DAT_143afa4d8;
void FUN_1409fabf0(void** pSlot, NiObject* pNode);                                          // assign the attach node
// @0x1410c4240
// MS2-FUNCTIONAL: owner-ptr / iterator temporaries and the effect-request unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410c4240(int nGroup, int nBlock, const CStringW& strName, __int64 nUnused, __int64 nOwnerId)
{
    bool bHasOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock).get() != 0;
    if (!bHasOwner) {
        FUN_1408a10e0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock, strName, nOwnerId);
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
        if (spOwner.get() != 0)
            FUN_1410ce3f0(spOwner);
        Unk_CMISIter<264> itEnd, itFind;
        if (FUN_1411273c0(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd))) {
            Unk_CMISEffReq request;
            FUN_140a52ef0(&request);
            request.m_strName = FUN_1401d31f0()->m_strSaleEffect;
            request.m_nOwnerId = 7;
            FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(FUN_141127b90(&ff8, &nGroup)))));
            FUN_1403ed280()->FUN_1411a4a00(&request);
            FUN_1405a89e0(&request);
        }
    }
}
// @0x1410c44b0
// MS2-FUNCTIONAL: owner-ptr / iterator temporaries and the effect-request unwind states are laid out differently from the exe
void CubeMapInformationService::FUN_1410c44b0(int nGroup, int nBlock, int bFlag)
{
    Unk_CMISIter<262> itEnd262, itFind262;
    if (FUN_141126e90(FUN_141157900(&fd8, &itFind262, &nGroup), FUN_141151c70(&fd8, &itEnd262)) == 0) {
        Unk_CubeOwnerPtr spOwner = FUN_1408a0fa0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
        if (spOwner == 0) {
            FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Can't find salable group to sell");
        } else {
            Unk_CMISIter<264> itEnd, itFind;
            if (FUN_141126c90(FUN_141157200(&ff8, &itFind, &nGroup), FUN_141151970(&ff8, &itEnd)) == 0) {
                if (bFlag != 0)
                    FUN_1410c2a90(nGroup);
                Unk_CMISRoster* pRoster = FUN_1403ed2d0()->FUN_141bd0cc0();
                if (pRoster != 0) {
                    __int64 nMe = FUN_141656ad0(pRoster);
                    if (nMe == spOwner->ownerID)
                        FUN_1410ccc00(nGroup, 0, 0);
                }
                FUN_1408a0eb0(reinterpret_cast<Unk_CubeOwners&>(f138), nGroup, nBlock);
                FUN_1410ce4b0(spOwner);
                FUN_1410cd440();
                Unk_CMISIter<264> itEnd2, itFind2;
                if (FUN_1411273c0(FUN_141157200(&ff8, &itFind2, &nGroup), FUN_141151970(&ff8, &itEnd2))) {
                    Unk_CMISEffReq request;
                    FUN_140a52ef0(&request);
                    request.m_strName = FUN_1401d31f0()->m_strSaleEffect;
                    request.m_nOwnerId = 7;
                    FUN_1409fabf0(&request.m_pSlot10, FUN_14098d8d0(&DAT_143afa4d8, FUN_141b6efc0(FUN_1408a9090(FUN_141127b90(&ff8, &nGroup)))));
                    FUN_1403ed280()->FUN_1411a4a00(&request);
                    FUN_1405a89e0(&request);
                }
            } else {
                FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Can't find salable group to sell");
            }
        }
    } else {
        FUN_140166440()->FUN_1401859c0(1, 0x13, L"[ERROR] Cant' find salable group to sell");
    }
}
