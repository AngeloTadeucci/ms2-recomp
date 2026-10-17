// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The shop/mail "price" value (currency kind, sub kind, amount;
// 16 bytes) with its stream (de)serialisation and xml loader, the list of prices (CAtlArray at +0) and the record
// validity test. Class and member names are invented (the range belongs to the commonstruct family, no __FILE__).
// MS2-UNIT: unit_140269c30
// MS2-RANGE: 0x140269c30-0x14026a1b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_140184310(const CString& str, const char* psz);   // str == psz

// One currency amount: kind 0 = meso, 2 = merat (sub kind 0 = merat_c, 1 = merat/merat_f, 2 = merat_m, 3 = merat_e).
class Unk_CommonPrice
{
public:
    Unk_CommonPrice() : m_type(0), m_subType(0), m_amount(0) {}                                 // 0x14027d940
    Unk_CommonPrice(int type, int subType, __int64 amount) : m_type(type), m_subType(subType), m_amount(amount) {}   // 0x14027d900
    void Write(COutputStream* pOut);                                // 0x140269c30
    void Read(CInputStream* pIn);                                   // 0x140269ca0
    void ClearAmount();                                             // 0x140269d10
    bool LoadXml(Unk_140165cf0* pNode);                             // 0x140269d30

    int m_type;                                                     // +0x00 (one byte on the wire)
    int m_subType;                                                  // +0x04 (one byte on the wire)
    __int64 m_amount;                                               // +0x08
};
MS2_CHECK_SIZE(Unk_CommonPrice, 0x10);

// The array of prices (the object is the CAtlArray itself).
class Unk_CommonPriceList
{
public:
    void AddPrice(const Unk_CommonPrice& price);                    // 0x140269f30
    void AddAmount(int type, int subType, __int64 amount);          // 0x140269f60
    void Write(COutputStream* pOut);                                // 0x14026a030
    void Read(CInputStream* pIn);                                   // 0x14026a0c0
    void Clear();                                                   // 0x14026a140

    ATL::CAtlArray<Unk_CommonPrice> m_prices;
};
MS2_CHECK_SIZE(Unk_CommonPriceList, 0x20);

// A price plus the time it was used.
class Unk_CommonPriceRecord
{
public:
    unsigned char IsUsed();                                               // 0x14026a170

    Unk_CommonPrice m_price;                                        // +0x00
    __int64 m_usedTime;                                             // +0x10
};
MS2_CHECK_SIZE(Unk_CommonPriceRecord, 0x18);

// @0x140269c30
void Unk_CommonPrice::Write(COutputStream* pOut)
{
    pOut->vfunc_o10_1((unsigned char)m_type);
    pOut->vfunc_o10_1((unsigned char)m_subType);
    pOut->vfunc_o10_4(m_amount);
}
MS2_REPLACE_METHOD(0x140269C30, Unk_CommonPrice, Write, 93, 0x2ED870DB);

// @0x140269ca0
void Unk_CommonPrice::Read(CInputStream* pIn)
{
    m_type = pIn->vfunc_o8_1();
    m_subType = pIn->vfunc_o8_1();
    m_amount = pIn->vfunc_o8_4();
}
MS2_REPLACE_METHOD(0x140269CA0, Unk_CommonPrice, Read, 97, 0xE26F4BDD);

// @0x140269d10
void Unk_CommonPrice::ClearAmount()
{
    m_amount = 0;
}
MS2_REPLACE_METHOD(0x140269D10, Unk_CommonPrice, ClearAmount, 19, 0x8111F705);

// @0x140269d30
bool Unk_CommonPrice::LoadXml(Unk_140165cf0* pNode)
{
    CStringA strType;
    FUN_1408733e0(pNode, "type", strType);
    FUN_1408732e0(pNode, "amount", m_amount);
    if (FUN_140184310(strType, "meso"))
    {
        m_type = 0;
        return true;
    }
    else if (FUN_140184310(strType, "merat_f") || FUN_140184310(strType, "merat"))
    {
        m_type = 2;
        m_subType = 1;
        return true;
    }
    else if (FUN_140184310(strType, "merat_c"))
    {
        m_type = 2;
        m_subType = 0;
        return true;
    }
    else if (FUN_140184310(strType, "merat_m"))
    {
        m_type = 2;
        m_subType = 2;
        return true;
    }
    else if (FUN_140184310(strType, "merat_e"))
    {
        m_type = 2;
        m_subType = 3;
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140269D30, Unk_CommonPrice, LoadXml, 483, 0xF7A084D2);

// @0x140269f30
void Unk_CommonPriceList::AddPrice(const Unk_CommonPrice& price)
{
    m_prices.Add(price);
}
MS2_REPLACE_METHOD(0x140269F30, Unk_CommonPriceList, AddPrice, 37, 0x22625142);

// @0x140269f60
void Unk_CommonPriceList::AddAmount(int type, int subType, __int64 amount)
{
    int nCount = (int)m_prices.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        Unk_CommonPrice& price = m_prices[i];
        if (price.m_type == type && price.m_subType == subType)
        {
            price.m_amount += amount;
            return;
        }
    }
    AddPrice(Unk_CommonPrice(type, subType, amount));
}
MS2_REPLACE_METHOD(0x140269F60, Unk_CommonPriceList, AddAmount, 189, 0x650EFAA4);

// @0x14026a030
void Unk_CommonPriceList::Write(COutputStream* pOut)
{
    unsigned char nCount = (unsigned char)m_prices.GetCount();
    pOut->vfunc_o10_1(nCount);
    for (int i = 0; i < (int)nCount; i++)
    {
        Unk_CommonPrice* pPrice = &m_prices.GetAt(i);
        pPrice->Write(pOut);
    }
}
MS2_REPLACE_METHOD(0x14026A030, Unk_CommonPriceList, Write, 128, 0x06B8811A);

// @0x14026a0c0
void Unk_CommonPriceList::Read(CInputStream* pIn)
{
    unsigned char nCount = pIn->vfunc_o8_1();
    for (int i = 0; i < (int)nCount; i++)
    {
        Unk_CommonPrice price;
        price.Read(pIn);
        m_prices.Add(price);
    }
}
MS2_REPLACE_METHOD(0x14026A0C0, Unk_CommonPriceList, Read, 115, 0xC302B45E);

// @0x14026a140
void Unk_CommonPriceList::Clear()
{
    m_prices.RemoveAll();
}
MS2_REPLACE_METHOD(0x14026A140, Unk_CommonPriceList, Clear, 27, 0xBF716CEA);

// @0x14026a170
unsigned char Unk_CommonPriceRecord::IsUsed()
{
    int nUsed;
    if (m_price.m_amount > 0 && m_usedTime != 0)
    {
        nUsed = 1;
    }
    else
    {
        nUsed = 0;
    }
    return nUsed;
}
MS2_REPLACE_METHOD(0x14026A170, Unk_CommonPriceRecord, IsUsed, 58, 0xD046B5DF);
