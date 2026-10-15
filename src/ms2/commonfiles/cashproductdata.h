// cashproductdata.h - CCashProductData / CCashSaleProduct / CCashInventoryProduct (RTTI names): the cash shop product
// record and its two wrappers, with their packet (de)serialisers. Header name assumed; member names are invented
// from use (offsets in the names where the meaning is unknown).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"

// Reader wrapper: CIOBuffer at +0, CInputStream at +8 (the packet the product is read from).
class Unk_CashReader : public CIOBuffer, public CInputStream {};

// One product record, 0x80 bytes; vftable holds the deleting destructor only.
class CCashProductData : public CPtred
{
public:
    CCashProductData();                         // 0x1401d4a00
    virtual ~CCashProductData();                // 0x1401d4b50

    int IsFlag70();                             // 0x1401d4b90 m_n70 != 0
    void Assign(const CCashProductData* pSrc);  // 0x1401d4bb0 copies every field (NULL: nothing)
    void Write(COutputStream& out);             // 0x1401d4d20
    void Read(Unk_CashReader& in);              // 0x1401d4f40

    int m_n18;
    CString m_str20;
    int m_n28;
    int m_n2c;                                  // written as a byte
    int m_n30;                                  // written as a 64-bit value
    int m_n34;                                  // written as a 64-bit value
    int m_n38;                                  // byte
    int m_n3c;                                  // byte
    int m_n40;                                  // byte
    int m_n44;
    int m_n48;
    int m_n4c;                                  // byte
    int m_n50;                                  // byte
    __int64 m_n58;
    __int64 m_n60;
    __int64 m_n68;
    int m_n70;                                  // byte
    int m_n74;
    int m_n78;
};
MS2_CHECK_SIZE(CCashProductData, 0x80);
MS2_CHECK_OFFSET(CCashProductData, m_str20, 0x20);
MS2_CHECK_OFFSET(CCashProductData, m_n58, 0x58);
MS2_CHECK_OFFSET(CCashProductData, m_n78, 0x78);

// RTTI CCashSaleProduct, 0xa0 bytes.
class CCashSaleProduct : public CPtred
{
public:
    CCashSaleProduct();                         // 0x1401d5470
    virtual ~CCashSaleProduct();                // 0x1401d54e0

    void Write(COutputStream& out);             // 0x1401d5520
    void Read(Unk_CashReader& in);              // 0x1401d5580

    int m_n18;
    int m_n1c;
    CCashProductData m_data;                    // +0x20
};
MS2_CHECK_SIZE(CCashSaleProduct, 0xa0);
MS2_CHECK_OFFSET(CCashSaleProduct, m_data, 0x20);

// RTTI CCashInventoryProduct, 0xc0 bytes.
class CCashInventoryProduct : public CPtred
{
public:
    CCashInventoryProduct();                    // 0x1401d5610
    virtual ~CCashInventoryProduct();           // 0x1401d56d0

    void Write(COutputStream& out);             // 0x1401d5740
    void Read(Unk_CashReader& in);              // 0x1401d5840

    int m_n18;
    int m_n1c;
    int m_n20;
    int m_n24;
    CCashProductData m_data;                    // +0x28
    CStringW m_strA8;
    CStringW m_strB0;
    int m_nB8;                                  // byte
};
MS2_CHECK_SIZE(CCashInventoryProduct, 0xc0);
MS2_CHECK_OFFSET(CCashInventoryProduct, m_data, 0x28);
MS2_CHECK_OFFSET(CCashInventoryProduct, m_strA8, 0xa8);
MS2_CHECK_OFFSET(CCashInventoryProduct, m_nB8, 0xb8);
