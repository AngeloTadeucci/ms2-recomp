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
bool CubeMapInformationService::FUN_1410b7f90(const Unk_Int3* pCell)
{
    return FUN_1410b7ed0(FUN_1408a0370(pCell->x, pCell->y, pCell->z));
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
