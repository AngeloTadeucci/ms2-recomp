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


// ---- callees outside the unit ----
class Unk_CMISWorld
{
public:
    int FUN_141bd3060();                                        // the current map id
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
bool FUN_141127380(Unk_CMISIter<278>*, Unk_CMISIter<278>*);                 // operator!=
int* FUN_141128540(Unk_CMISIter<278>*);                                     // operator*
void FUN_141129a60(Unk_CMISIter<278>*);                                     // operator++
const Unk_CMISEntityRef* FUN_1408b76f0(egf::Entity*);                   // &entity id
egf::Entity* FUN_1408a9280(const void* pSp);
void FUN_1409618c0(egf::Entity*, unsigned, Unk_StreamPoint*);   // GetProperty(Point3)
struct Unk_CMISPt3 { float x, y, z; Unk_CMISPt3(const Unk_StreamPoint&); };   // efd::Point3 copy (0x14027dcf0)
struct Unk_CMISRayHit { __int64 m_q0, m_q1, m_q2, m_q3, m_q4, m_q5; egf::Entity* m_pEntity; __int64 m_q7, m_q8, m_q9, m_q10, m_q11, m_q12; };
void FUN_140ad4440(Unk_CMISRayHit*);
class CPhysXHelper;
CPhysXHelper* FUN_1409f7ca0();
int FUN_14168a310(CPhysXHelper*, Unk_CMISPt3*, Unk_StreamPoint*, Unk_CMISRayHit*, float, __int64, int);
bool FUN_14028d470(float, float);
extern Unk_StreamPoint DAT_143a08cf8;                                       // up vector
extern Unk_StreamPoint DAT_143b01a60;                                       // zero / fall-through direction
struct Unk_CMISCubeByKey { int first; MS2Ptr<Cube> second; };                // the node value of the cubes by key
void FUN_14114dd70(Unk_CMISTree<260>*, Unk_CMISIter<260>*);                 // begin
bool FUN_1411274c0(Unk_CMISIter<260>*, Unk_CMISIter<260>*);                 // operator!=
Unk_CMISCubeByKey* FUN_1411285e0(Unk_CMISIter<260>*);                       // operator*
void FUN_141129b50(Unk_CMISIter<260>*);                                     // operator++
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
void FUN_14114e630(Unk_CMISIntList*, Unk_CMISListIter*);                    // begin
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
