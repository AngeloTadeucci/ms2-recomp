// itemdata.h - the item table row (CItemData, see ms2/placeholder/citemdata.h) and the types that share its unit:
// CItemChangeBeautyTable / CChangeBeautyData (Table/ItemChangeBeauty.xml), DropNifData, ItemDropEffect, ItemColorEx.
// Header name assumed; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include <efd/Point3.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // game TinyXML element (declared where the loaders are)
class Unk_ModelHandle;
class Unk_ModelResource;

// One <beauty> row of ItemChangeBeauty.xml (0x50 bytes; vftable has the deleting dtor only).
class CChangeBeautyData : public CPtred
{
public:
    CChangeBeautyData();                // 0x140539f90
    virtual ~CChangeBeautyData();       // 0x14053a130

    bool FUN_14053a7c0(Unk_140165cf0*); // row reader (always true; the <item> children are only validated by the loader)

    int m_nId;                          // +0x18 "id"
    int m_nUnk1c;                       // +0x1c
    std::vector<unsigned> m_lists[2];   // +0x20
};
MS2_CHECK_SIZE(CChangeBeautyData, 0x50);
MS2_CHECK_OFFSET(CChangeBeautyData, m_lists, 0x20);

// RTTI CItemChangeBeautyTable, 0xa8 bytes: TSingleton at +0, CValidData at +8.
class CItemChangeBeautyTable : public TSingleton<CItemChangeBeautyTable>, public CValidData<CItemChangeBeautyTable>
{
public:
    typedef MS2Ptr<CChangeBeautyData> DataPtr;
    typedef MS2Ptr<CCacheData> CachePtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;

    CItemChangeBeautyTable();           // 0x140539370
    virtual ~CItemChangeBeautyTable();  // 0x140539430

    bool Load();                        // 0x1405394c0 Table/ItemChangeBeauty.xml
    DataPtr Get(int nId);               // 0x140539b70 reloads first when the file changed
    bool Reload();                      // 0x140539c70

    static void CheckInit();            // 0x14053a3f0
    static void SetInit(bool b);        // 0x14053b310

    static bool s_bInit;                // 0x143aaf3c0

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;        // +0x10
    ATL::CAtlArray<CachePtr> m_caches;  // +0x40
    DataMap m_data;                     // +0x60
};
MS2_CHECK_SIZE(CItemChangeBeautyTable, 0xa8);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_caches, 0x40);
MS2_CHECK_OFFSET(CItemChangeBeautyTable, m_data, 0x60);

// ---- The model block of an item row (RTTI ItemModelData, 0xe0 bytes; its constructor and accessors are in
// commonfiles\itemdatastruct.cpp, the destructor and the destructors of its element types here).
// Names of the element types are invented; only the members the destructors reach are typed.
struct Unk_1401e4e10 { ~Unk_1401e4e10(); unsigned char m_raw[0x30]; };     // dtor 0x1401e4e10 (a map; layout not recovered)

struct ModelNameEntry               // 0x38 bytes: two names at +0x08 / +0x10
{
    ~ModelNameEntry();              // 0x140540bc0
    unsigned char unknown00[8];
    CString nameA;                  // +0x08
    CString nameB;                  // +0x10
    unsigned char unknown18[0x20];
};
MS2_CHECK_SIZE(ModelNameEntry, 0x38);

struct ModelFloatList               // 0x28 bytes
{
    ~ModelFloatList();              // 0x140541080
    unsigned char unknown00[0x10];
    std::vector<float> values;      // +0x10
};
MS2_CHECK_SIZE(ModelFloatList, 0x28);

struct ModelNamedColor              // 0x18 bytes, four of them in a ModelPart
{
    ~ModelNamedColor();             // 0x140541060
    CString name;
    unsigned char unknown08[0x10];
};
MS2_CHECK_SIZE(ModelNamedColor, 0x18);

struct ModelPart                    // 0x158 bytes
{
    ~ModelPart();                   // 0x140540f60
    int FUN_140544aa0(int nGender, int nB);
    CString name0;                  // +0x00
    CString name8;                  // +0x08
    CString name10;                 // +0x10
    CString name18;                 // +0x18
    unsigned char unknown20[0x38];
    Unk_1401e4e10 attach;           // +0x58
    std::vector<efd::Point3> points;    // +0x88
    std::vector<CString> names;     // +0xa0
    ModelNamedColor colors[4];      // +0xb8
    std::map<CString, CString> properties;  // +0x118
    std::vector<ModelNameEntry> entries[2]; // +0x128
};
MS2_CHECK_SIZE(ModelPart, 0x158);
MS2_CHECK_OFFSET(ModelPart, attach, 0x58);
MS2_CHECK_OFFSET(ModelPart, points, 0x88);
MS2_CHECK_OFFSET(ModelPart, colors, 0xb8);
MS2_CHECK_OFFSET(ModelPart, properties, 0x118);
MS2_CHECK_OFFSET(ModelPart, entries, 0x128);

struct ModelGroup                   // 0x38 bytes (also the unit's third static, 0x143aaf568)
{
    ModelGroup();                   // 0x140544ca0
    ~ModelGroup();                  // 0x140540f30
    unsigned FUN_1405450c0();       // number of parts
    ModelPart* FUN_140544fe0(unsigned nIndex);
    int FUN_1405451a0();
    std::vector<ModelPart> parts;   // +0x00
    std::vector<ModelFloatList> floats; // +0x18
    int type;                       // +0x30
};
MS2_CHECK_SIZE(ModelGroup, 0x38);

class Unk_ModelHandle : public CPtred { public: virtual ~Unk_ModelHandle(); };    // pointee of ItemModelHead::handle
class Unk_ModelResource : public CPtred { public: virtual ~Unk_ModelResource(); }; // pointee of ItemModelData::resource

struct ItemModelHead                // 0x50 bytes at ItemModelData +0x48
{
    ItemModelHead();                // 0x140546a00
    ~ItemModelHead();               // 0x140540c70
    bool FUN_140547190();           // flag at +0x10
    bool FUN_1405471d0();           // any of three flags
    int FUN_140547250();            // +0x14
    int FUN_140547270(int nIndex);  // the nIndex-th entry of the id list, -1 when out of range
    size_t FUN_140547330();         // size of the id list
    MS2Ptr<Unk_ModelHandle> handle; // +0x00
    bool flag10;                    // +0x10
    bool flag11;                    // +0x11
    int unknown14;                  // +0x14
    std::vector<int> ids;           // +0x18
    std::vector<int> unknown30;     // +0x30
    unsigned char unknown48[8];
};
MS2_CHECK_SIZE(ItemModelHead, 0x50);

class ItemModelData : public CCacheData
{
public:
    ItemModelData();                // 0x14054ae00
    virtual ~ItemModelData();       // 0x140540e20
    ModelGroup* FUN_14054b2f0(size_t nIndex);       // the nIndex-th group (a static empty one when out of range)
    size_t FUN_14054b3d0();         // number of groups
    ItemModelHead* FUN_14054b690(); // &head
    bool FUN_14054b520();
    int FUN_14054b550();
    int FUN_14054b580();
    int FUN_14054b5b0(int nIndex);
    int FUN_14054b400();
    bool FUN_14054b450(int nFlag);
    int FUN_14054b5e0(int nIndex);
    int FUN_14054b640();
    size_t FUN_14054b610();
    int m_nUnk28;                   // +0x28
    std::vector<ModelGroup> groups; // +0x30
    ItemModelHead head;             // +0x48
    std::vector<CString> names98;   // +0x98
    std::vector<CString> namesB0;   // +0xb0
    MS2Ptr<Unk_ModelResource> resource;     // +0xc8
    CStringW name;                  // +0xd8
};
MS2_CHECK_SIZE(ItemModelData, 0xe0);
MS2_CHECK_OFFSET(ItemModelData, groups, 0x30);
MS2_CHECK_OFFSET(ItemModelData, head, 0x48);
MS2_CHECK_OFFSET(ItemModelData, resource, 0xc8);

// <drop> rows of the item drop table: three small CPtred-derived records (destructors in itemdatastruct.cpp).
class DropNifData : public CPtred   // 0x20 bytes
{
public:
    DropNifData();                  // 0x1405434a0
    virtual ~DropNifData();         // 0x140552480
    void FUN_1405434f0(Unk_140165cf0* pElem);   // XML read
    bool FUN_140543550(unsigned n); // m_nUnk1c <= n
    int FUN_140543590();            // type id
    int m_nTypeId;                  // +0x18 "typeID"
    unsigned m_nUnk1c;              // +0x1c
};
MS2_CHECK_SIZE(DropNifData, 0x20);

class ItemDropEffect : public CPtred    // 0x88 bytes
{
public:
    ItemDropEffect();               // 0x1405435b0
    virtual ~ItemDropEffect();      // 0x1405524c0
    void FUN_140543730(Unk_140165cf0* pElem);   // XML read
    int typeID;                     // +0x18
    float unknown1c;                // +0x1c (default 50.0)
    float scale;                    // +0x20
    float getAniSpeed;              // +0x24
    float dropAniSpeed;             // +0x28
    float beAniSpeed;               // +0x2c
    float shadowBias;               // +0x30
    float shadowScale;              // +0x34
    float bounceHeight;             // +0x38 (default 30.0)
    float bouncePeriod;             // +0x3c
    efd::Point3 getAni;             // +0x40
    efd::Point3 dropAni;            // +0x4c
    efd::Point3 beAni;              // +0x58
    int unknown64;
    CString beEffect;               // +0x68
    CString assetName;              // +0x70
    CString dropSoundID;            // +0x78
    CString getSoundID;             // +0x80
};
MS2_CHECK_SIZE(ItemDropEffect, 0x88);

class ItemColorEx : public CPtred   // 0x48 bytes
{
public:
    ItemColorEx(const int& nId);    // 0x140543940
    virtual ~ItemColorEx();         // 0x1405524a0
    int m_nId;                      // +0x18
    int m_nColor;                   // +0x1c (default -1)
    bool m_bFlag;                   // +0x20
    int m_n24, m_n28, m_n2c, m_n30, m_n34, m_n38;
    int m_aValues[3];               // +0x3c
};
MS2_CHECK_SIZE(ItemColorEx, 0x48);
