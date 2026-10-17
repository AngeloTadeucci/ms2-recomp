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

    CUgcBannerReserveMap m_reserves;                        // +0x20
};
