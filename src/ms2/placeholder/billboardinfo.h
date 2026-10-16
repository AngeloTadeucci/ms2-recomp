// BillBoardInfo: RTTI name; field names inferred from its wire representation.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
struct Unk_CommonPosition {
    Unk_CommonPosition(); // 0x140203800, empty default constructor
    Unk_CommonPosition(float,float,float);
    float x,y,z;
};
MS2_CHECK_SIZE(Unk_CommonPosition,0xc);
class BillBoardInfo : public CPtred {
public:
    BillBoardInfo();
    virtual ~BillBoardInfo() = default;
    void Write(COutputStream&);
    void Read(CInputStream&);
    void Clear();
    __int64 owner,firstId,secondId;
    CStringW firstName,secondName;
    unsigned short type;
    int value,localValue;
    CStringW title,text;
    bool enabled;
    int localState,localIndex;
    Unk_CommonPosition position;
    __int64 start,end;
};
MS2_CHECK_SIZE(BillBoardInfo,0x88);
MS2_CHECK_OFFSET(BillBoardInfo,owner,0x18);
MS2_CHECK_OFFSET(BillBoardInfo,firstName,0x30);
MS2_CHECK_OFFSET(BillBoardInfo,type,0x40);
MS2_CHECK_OFFSET(BillBoardInfo,title,0x50);
MS2_CHECK_OFFSET(BillBoardInfo,position,0x6c);
MS2_CHECK_OFFSET(BillBoardInfo,start,0x78);
