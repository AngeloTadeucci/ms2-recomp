// ugcdef.h - the UGC proxy records of commonfiles\ugcdef.cpp (RTTI names; header name assumed). IUgcProxy (vftable
// 0x142d9fc28, 5 slots) is the CPtred base of the small records that describe a piece of user generated content (an
// uploaded image, the item / character / guild it belongs to, a banner, a market listing). Slot 1 resets the record
// (every ctor calls it), slot 2 copies another record of the same kind (returns 0 for NULL), slots 3/4 write / read it.
// Member names are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <egf/EntityID.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cmeratmarketschcond.h"

class COutputStream;
class CInPacket;
class CInputStream;
class CItem;

class IUgcProxy : public CPtred
{
public:
    IUgcProxy();                                            // 0x140899640
                                                            // dtor 0x1408999a0 implicit
    virtual void Clear() = 0;                               // 1
    virtual int CopyFrom(const IUgcProxy* pOther) = 0;      // 2
    virtual void Write(COutputStream& stream) const;        // 3 0x14089abe0
    virtual void Read(CInPacket& packet);                   // 4 0x14089abd0
};
MS2_CHECK_SIZE(IUgcProxy, 0x18);

// The owner of a profile / wedding image (vftable 0x142d9fc58).
class CUgcUserProxy : public IUgcProxy
{
public:
    CUgcUserProxy();                                        // 0x14088e340
    virtual ~CUgcUserProxy();
    virtual void Clear();                                   // 0x14088e410
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088e480
    virtual void Write(COutputStream& stream) const;        // 0x14088e540
    virtual void Read(CInPacket& packet);                   // 0x14088e5f0

    int m_nType;                                            // +0x18
    __int64 m_accountId;                                    // +0x20
    __int64 m_characterId;                                  // +0x28
    CString m_strObjectName;                                // +0x30 the interact object that shows the image
    CStringW m_strName;                                     // +0x38
};
MS2_CHECK_SIZE(CUgcUserProxy, 0x40);

// The uploaded file of a download (its server uid and name).
class CUgcUploadProxy : public IUgcProxy
{
public:
    CUgcUploadProxy();                                      // 0x14088e790
    virtual ~CUgcUploadProxy();
    virtual void Clear();                                   // 0x14088e860
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088e8d0
    virtual void Write(COutputStream& stream) const;        // 0x14088e990
    virtual void Read(CInPacket& packet);                   // 0x14088ea40

    unsigned __int64 m_uid;                                 // +0x18
    CString m_strName;                                      // +0x20
    int m_nType;                                            // +0x28
    int m_nState;                                           // +0x2c
    CString m_strPath;                                      // +0x30
};
MS2_CHECK_SIZE(CUgcUploadProxy, 0x38);

// A UGC item (design shop / mount / cube templates).
class CUgcItemProxy : public IUgcProxy
{
public:
    CUgcItemProxy();                                        // 0x14088ebf0
    explicit CUgcItemProxy(CItem* pItem);                   // 0x14088ec50
    virtual ~CUgcItemProxy();
    virtual void Clear();                                   // 0x14088ed00
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088ed80
    virtual void Write(COutputStream& stream) const;        // 0x14088ee30
    virtual void Read(CInPacket& packet);                   // 0x14088ef20

    void FUN_14088f100(CItem* pItem);                       // takes the UGC uid / name / rarity of the item (or clears)

    __int64 m_itemUid;                                      // +0x18
    int m_nItemId;                                          // +0x20
    int m_nCount;                                           // +0x24
    CStringW m_strName;                                     // +0x28
    int m_nRarity;                                          // +0x30
    __int64 m_uid;                                          // +0x38
    int m_nFlags;                                           // +0x40 1 = written as true
};
MS2_CHECK_SIZE(CUgcItemProxy, 0x48);

// An item equipped by a player (vftable 0x142d9fce8).
class CUgcItemPC : public CUgcItemProxy
{
public:
    CUgcItemPC(CItem* pItem, int nObjectId);                // 0x14088f210
    virtual ~CUgcItemPC();
    virtual void Clear();                                   // 0x14088f330
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088f370

    int FUN_14088f2d0(const CUgcItemProxy* pOther);         // copies the item part only, clears the wearer

    int m_nSlot;                                            // +0x48
    int m_nObjectId;                                        // +0x4c the wearer
};
MS2_CHECK_SIZE(CUgcItemPC, 0x50);

// The icon callback key of an item icon (UgcItemIcon::CallBackData, ctor 0x14088f3f0): a market search condition
// plus two values.
namespace UgcItemIcon
{
class CallBackData : public CPtred
{
public:
    CallBackData();                                         // 0x14088f3f0
    virtual ~CallBackData();                                // 0x14088f450

    void FUN_14088f4b0();                                   // reset
    void FUN_14088f500(int nKind, const CMeratMarketSchCond* pCond, __int64 n30, int n38);
    void FUN_14088f5e0(const CallBackData* pOther);         // copy

    int m_nKind;                                            // +0x18
    MS2Ptr<CMeratMarketSchCond> m_spCond;                   // +0x20
    __int64 m_30;                                           // +0x30
    int m_38;                                               // +0x38
};
MS2_CHECK_SIZE(CallBackData, 0x40);
}

// An item icon: m_nKind 1 = a player's item (m_nObjectId), 2 = by item uid, 3 = by callback key.
class CUgcItemIconPC : public CUgcItemProxy
{
public:
    CUgcItemIconPC();                                       // 0x14088f6f0
    CUgcItemIconPC(CItem* pItem, int n50);                  // 0x14088f750
    explicit CUgcItemIconPC(const UgcItemIcon::CallBackData& callBack);   // 0x14088f830
    virtual ~CUgcItemIconPC();
    virtual void Clear();                                   // 0x14088f9c0
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088fa20

    int FUN_14088f8e0(const CUgcItemProxy* pOther);         // copies the item part only, clears the icon key
    void FUN_14088f960(const UgcItemIcon::CallBackData& callBack);

    int m_nKind;                                            // +0x48
    int m_nObjectId;                                        // +0x4c
    int m_n50;                                              // +0x50
    UgcItemIcon::CallBackData m_callBack;                   // +0x58
};
MS2_CHECK_SIZE(CUgcItemIconPC, 0x98);

// A placed cube of a UGC map.
class CUgcItemCube : public CUgcItemProxy
{
public:
    CUgcItemCube();                                         // 0x14088fad0
    CUgcItemCube(CItem* pItem, const egf::EntityID& id);    // 0x14088fb30
    virtual ~CUgcItemCube();
    virtual void Clear();                                   // 0x14088fc40
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088fc80

    int FUN_14088fbe0(const CUgcItemProxy* pOther);         // copies the item part only, clears the entity

    egf::EntityID m_entityId;                               // +0x48
};
MS2_CHECK_SIZE(CUgcItemCube, 0x50);

// A UGC mount.
class CUgcItemRidee : public CUgcItemProxy
{
public:
    CUgcItemRidee();                                        // 0x14088fd00
    CUgcItemRidee(CItem* pItem, const egf::EntityID& id);   // 0x14088fd60
    virtual ~CUgcItemRidee();
    virtual void Clear();                                   // 0x14088fe70
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088feb0

    int FUN_14088fe10(const CUgcItemProxy* pOther);         // copies the item part only, clears the entity

    egf::EntityID m_entityId;                               // +0x48
};
MS2_CHECK_SIZE(CUgcItemRidee, 0x50);

// The banner id of a banner record (vftable 0x142d9fd78 for CUgcBannerProxy).
class CUgcBannerProxy : public IUgcProxy
{
public:
    CUgcBannerProxy();                                      // 0x14088ff30
    virtual ~CUgcBannerProxy();
    virtual void Clear();                                   // 0x14088ffb0
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x14088ffd0
    virtual void Write(COutputStream& stream) const;        // 0x140890030
    virtual void Read(CInPacket& packet);                   // 0x140890070

    int m_nBannerId;                                        // +0x18
};
MS2_CHECK_SIZE(CUgcBannerProxy, 0x20);

// One reserved banner slot (a CPtred of its own, not an IUgcProxy).
class CUgcBannerReserve : public CPtred
{
public:
    CUgcBannerReserve();                                    // 0x1408900d0
    virtual ~CUgcBannerReserve();

    int FUN_140890180() const;                              // the reserved time lies in the past
    void Write(COutputStream& stream) const;                // 0x1408901e0
    void Read(CInPacket& packet);                           // 0x1408902a0
    unsigned __int64 GetKey() const;                        // 0x1408903c0 the reserved time (map key)

    __int64 m_nBannerUid;                                   // +0x18
    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_nDate;                                            // +0x28
    int m_nHour;                                            // +0x2c
    __int64 m_n30;                                          // +0x30
};
MS2_CHECK_SIZE(CUgcBannerReserve, 0x38);

typedef MS2Ptr<CUgcBannerReserve> CUgcBannerReservePtr;
typedef ATL::CRBMap<unsigned __int64, CUgcBannerReservePtr> CUgcBannerReserveMap;

// The reservations of a banner, keyed by time.
class CUgcPreReserve : public CPtred
{
public:
    CUgcPreReserve();                                       // 0x140890400
    virtual ~CUgcPreReserve();

    void Write(COutputStream& stream) const;                // 0x1408904b0
    void Read(CInPacket& packet);                           // 0x1408905b0

    int m_nCount;                                           // +0x18
    CUgcBannerReserveMap m_reserves;                        // +0x20
};
MS2_CHECK_SIZE(CUgcPreReserve, 0x50);

// A banner post: the banner id and its reservations (vftable 0x142d9fdb0).
class CUgcBannerPost : public CUgcBannerProxy
{
public:
    CUgcBannerPost();                                       // 0x140890700
    virtual ~CUgcBannerPost();
    virtual void Clear();                                   // 0x1408907a0
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x1408907d0
    virtual void Write(COutputStream& stream) const;        // 0x1408908e0
    virtual void Read(CInPacket& packet);                   // 0x1408909f0

    __int64 FUN_140890bd0();                                // the total price of the reservations (hourly price)

    CUgcBannerReserveMap m_reserves;                        // +0x20
};
MS2_CHECK_SIZE(CUgcBannerPost, 0x50);

// The registration of a banner: who, which upload, which post (CPtred with its own vftable).
class CUgcRegistBanner : public CPtred
{
public:
    CUgcRegistBanner();                                     // 0x140890d50
    virtual ~CUgcRegistBanner();                            // 0x140890df0

    void Clear();                                           // 0x140890e80
    void Write(COutputStream& stream) const;                // 0x140890f30
    void Read(CInPacket& packet);                           // 0x140891020
    int FUN_1408911f0(unsigned __int64 nTime);              // all reservations lie after `nTime`

    int m_nType;                                            // +0x18
    CUgcUserProxy m_user;                                   // +0x20
    CUgcUploadProxy m_upload;                               // +0x60
    CUgcBannerPost m_post;                                  // +0x98
    CStringA m_strUrl;                                      // +0xe8
};
MS2_CHECK_SIZE(CUgcRegistBanner, 0xf0);

// A guild mark (vftable 0x142da0050).
class CUgcGuildMarkProxy : public IUgcProxy
{
public:
    CUgcGuildMarkProxy();                                   // 0x140891980
    virtual ~CUgcGuildMarkProxy();
    virtual void Clear();                                   // 0x140891a40
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140891a80
    virtual void Write(COutputStream& stream) const;        // 0x140891b00
    virtual void Read(CInPacket& packet);                   // 0x140891b40

    __int64 m_nGuildId;                                     // +0x18
    CStringA m_strName;                                     // +0x20
};
MS2_CHECK_SIZE(CUgcGuildMarkProxy, 0x28);

// A guild poster.
class CUgcGuildPosterProxy : public IUgcProxy
{
public:
    CUgcGuildPosterProxy();                                 // 0x140891b90
    virtual ~CUgcGuildPosterProxy();
    virtual void Clear();                                   // 0x140891c50
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140891c90
    virtual void Write(COutputStream& stream) const;        // 0x140891d20
    virtual void Read(CInPacket& packet);                   // 0x140891d70

    __int64 m_nGuildId;                                     // +0x18
    int m_nIndex;                                           // +0x20
    CStringA m_strName;                                     // +0x28
};
MS2_CHECK_SIZE(CUgcGuildPosterProxy, 0x30);

// The record of an empty banner: nothing to store.
class CUgcBannerEmptyProxy : public IUgcProxy
{
public:
    CUgcBannerEmptyProxy();                                 // 0x140891de0
    virtual ~CUgcBannerEmptyProxy();
    virtual void Clear();                                   // 0x140891e50
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140891e60
    virtual void Write(COutputStream& stream) const;        // 0x140891e80
    virtual void Read(CInPacket& packet);                   // 0x140891ea0
};
MS2_CHECK_SIZE(CUgcBannerEmptyProxy, 0x18);

// The ids of the images of a rolling banner.
class CUgcBannerRollingImageProxy : public IUgcProxy
{
public:
    CUgcBannerRollingImageProxy();                          // 0x140891ec0
    virtual ~CUgcBannerRollingImageProxy();
    virtual void Clear();                                   // 0x140891f50
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140891f80
    virtual void Write(COutputStream& stream) const;        // 0x140891ff0
    virtual void Read(CInPacket& packet);                   // 0x1408920a0

    std::vector<unsigned int> m_images;                     // +0x18
};
MS2_CHECK_SIZE(CUgcBannerRollingImageProxy, 0x30);


// The two banner key strings of the shop (vftable 0x142da00e8); only the first one is reset.
class CUgcShopBannerProxy : public IUgcProxy
{
public:
    CUgcShopBannerProxy();                                  // 0x140892170
    virtual ~CUgcShopBannerProxy();
    virtual void Clear();                                   // 0x140892250
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140892280
    virtual void Write(COutputStream& stream) const;        // 0x140892310
    virtual void Read(CInPacket& packet);                   // 0x140892350

    CStringA m_strKey;                                      // +0x18
    CStringA m_strEntity;                                   // +0x20
};
MS2_CHECK_SIZE(CUgcShopBannerProxy, 0x28);

// The record of one blueprint item (CPtred with its own vftable; read from a CInputStream).
class CBlueprintItemData : public CPtred
{
public:
    CBlueprintItemData();                                   // 0x1408923d0
    virtual ~CBlueprintItemData();                          // 0x140892430

    void Clear();                                           // 0x140892470
    void CopyFrom(const CBlueprintItemData& other);         // 0x140892510
    void Write(COutputStream& stream) const;                // 0x1408925d0
    void Read(CInputStream& stream);                        // 0x1408926e0

    __int64 m_n18;                                          // +0x18
    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_n28;                                              // +0x28
    __int64 m_n30;                                          // +0x30
    int m_n38;                                              // +0x38
    __int64 m_n40;                                          // +0x40
    __int64 m_n48;                                          // +0x48
    CStringW m_strName;                                     // +0x50
};
MS2_CHECK_SIZE(CBlueprintItemData, 0x58);

// A blueprint image (vftable 0x142da0150); CopyFrom does not reset first.
class CUgcBlueprintImageProxy : public IUgcProxy
{
public:
    CUgcBlueprintImageProxy();                              // 0x140892810
    virtual ~CUgcBlueprintImageProxy();
    virtual void Clear();                                   // 0x1408928d0
    virtual int CopyFrom(const IUgcProxy* pOther);          // 0x140892930
    virtual void Write(COutputStream& stream) const;        // 0x1408929c0
    virtual void Read(CInPacket& packet);                   // 0x140892a50

    __int64 m_n18;                                          // +0x18
    __int64 m_n20;                                          // +0x20
    int m_n28;                                              // +0x28
    CStringW m_strName;                                     // +0x30
};
MS2_CHECK_SIZE(CUgcBlueprintImageProxy, 0x38);

// The look of an uploaded item (a design / blueprint file) with its url.
class CUgcItemLook : public CPtred
{
public:
    CUgcItemLook();                                         // 0x140892b50
    virtual ~CUgcItemLook();                                // 0x140892bf0

    void Clear();                                           // 0x140892c70
    void SetDefault();                                      // 0x140892d40
    void CopyFrom(const CUgcItemLook* pOther);              // 0x140892da0
    CStringA GetLocalPath() const;                          // 0x140892ec0
    void Write(COutputStream& stream) const;                // 0x140893070
    void Read(CInputStream& stream);                        // 0x140893250
    int FUN_1408934f0() const;                              // m_n18 == 1 || m_n60 == 1
    int FUN_140893520() const;                              // m_n60 == 2
    bool FUN_140893540() const;

    __int64 m_n18;                                          // +0x18
    CStringA m_str20;                                       // +0x20
    CStringW m_str28;                                       // +0x28
    int m_n30;                                              // +0x30
    int m_n34;                                              // +0x34
    __int64 m_n38;                                          // +0x38
    __int64 m_n40;                                          // +0x40
    CStringW m_str48;                                       // +0x48
    __int64 m_n50;                                          // +0x50
    CStringA m_strUrl;                                      // +0x58
    int m_n60;                                              // +0x60
};
MS2_CHECK_SIZE(CUgcItemLook, 0x68);

// An upload: the owner and the file.
class CUgcUpload : public CPtred
{
public:
    CUgcUpload();                                           // 0x140893590
    virtual ~CUgcUpload();                                  // 0x140893600

    void Clear();                                           // 0x140893670
    bool CopyFrom(const CUgcUpload* pOther);                // 0x1408936e0
    void Write(COutputStream& stream) const;                // 0x140893780
    void Read(CInPacket& packet);                           // 0x140893820

    int m_nKind;                                            // +0x18
    int m_n1c;                                              // +0x1c
    CUgcUserProxy m_user;                                   // +0x20
    CUgcUploadProxy m_upload;                               // +0x60
};
MS2_CHECK_SIZE(CUgcUpload, 0x98);

// The tail record of a music note (inline ctor 0x1408993b0, dtor 0x1408998d0).
struct Unk_UgcMusicInfo
{
    Unk_UgcMusicInfo() : m_n00(0), m_n08(0), m_n10(0) {}
    int m_n00;                                              // +0x00
    __int64 m_n08;                                          // +0x08
    __int64 m_n10;                                          // +0x10
    CStringW m_str18;                                       // +0x18
};
MS2_CHECK_SIZE(Unk_UgcMusicInfo, 0x20);

// A music score item.
class CUgcItemMusicNote : public CPtred
{
public:
    CUgcItemMusicNote();                                    // 0x1408938d0
    virtual ~CUgcItemMusicNote();                           // 0x140893970

    void Clear();                                           // 0x1408939f0
    void CopyFrom(const CUgcItemMusicNote* pOther);         // 0x140893aa0
    void FUN_140893bb0(const void* pSource, __int64 nId);   // takes the music record of a CItem
    void Write(COutputStream& stream) const;                // 0x140893cc0
    void Read(CInputStream& stream);                        // 0x140893e10
    CStringA FUN_140894060() const;                         // the title of the music book

    __int64 m_n18;                                          // +0x18
    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24 music book id
    CStringW m_str28;                                       // +0x28
    CStringW m_str30;                                       // +0x30
    CStringA m_str38;                                       // +0x38
    Unk_UgcMusicInfo m_info;                                // +0x40
};
MS2_CHECK_SIZE(CUgcItemMusicNote, 0x60);

// A market search condition (this unit's own; CMeratMarketSchCond is the merat market's).
class CUgcMarketSchCond : public CPtred
{
public:
    CUgcMarketSchCond();                                    // 0x140894120
    explicit CUgcMarketSchCond(CInPacket& packet);          // 0x140894180
    virtual ~CUgcMarketSchCond();                           // 0x1408941f0

    void Clear();                                           // 0x140894250
    void CopyFrom(const CUgcMarketSchCond* pOther);         // 0x1408942c0
    void Write(COutputStream& stream) const;                // 0x140894360
    void Read(CInPacket& packet);                           // 0x140894420
    void WriteShort(COutputStream& stream) const;           // 0x1408945c0
    void ReadShort(CInputStream& stream);                   // 0x140894670
    int FUN_140894750() const;                              // page of m_n30 (10 per page), -1 when 0
    int FUN_1408947a0() const;                              // first entry of that page
    int FUN_1408947f0() const;                              // last entry of that page
    int FUN_140894840() const;
    CStringA FUN_1408948a0() const;                         // name of the order kind m_n20 (0..5)
    int FUN_140894960() const;                              // m_n18
    int FUN_140894990() const;                              // m_n18 rounded up to its hundred's last
    int FUN_140894a10(const CUgcMarketSchCond* pOther) const;

    int m_n18;                                              // +0x18
    int m_n1c;                                              // +0x1c
    int m_n20;                                              // +0x20
    CStringW m_str28;                                       // +0x28
    int m_n30;                                              // +0x30
    int m_n34;                                              // +0x34
};
MS2_CHECK_SIZE(CUgcMarketSchCond, 0x38);
