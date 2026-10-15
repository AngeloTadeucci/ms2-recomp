// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Content shutdown flag serialization.
// MS2-UNIT: commonfiles\contentshutdown.cpp
// MS2-RANGE: 0x1402c4b00-0x1402c5180 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\contentshutdown.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "contentshutdown.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_ShutdownOutput { public: virtual ~Unk_ShutdownOutput(); virtual void Encode1(unsigned char); virtual void Encode2(unsigned short); };
class Unk_ShutdownInput { public: virtual ~Unk_ShutdownInput(); virtual unsigned char Decode1(); virtual unsigned short Decode2(); };
int FUN_140718170(const CString&);
// @0x1402c4b00
void CContentShutdown::Encode(Unk_ShutdownOutput& out) {
    ATL::CAtlArray<Content> entries;
    for(int i=1;i<117;++i) {
        Content content=static_cast<Content>(i);
        if(Get(content)==1) entries.Add(content);
    }
    unsigned short count=static_cast<unsigned short>(entries.GetCount());
    out.Encode2(count);
    for(int i=0;i<count;++i) out.Encode2(static_cast<unsigned short>(entries[i]));
}
MS2_REPLACE_METHOD(0x1402C4B00, CContentShutdown, Encode, 236, 0xC9210DC1);
// @0x1402c4c00
void CContentShutdown::Decode(Unk_ShutdownInput& in) {
    Clear();
    int count=in.Decode2();
    for(int i=0;i<count;++i) { Content content=static_cast<Content>(in.Decode2()); Set(content,1); }
}
MS2_REPLACE_METHOD(0x1402C4C00, CContentShutdown, Decode, 127, 0x83643907);
// @0x1402c4c90
int CContentShutdown::Get(Content content) {
    if(content<=None || content>=End) { MS2_ASSERT_AT(69,FALSE);return 0; }
    return m_flags[content];
}
MS2_REPLACE_METHOD(0x1402C4C90, CContentShutdown, Get, 83, 0xF56BB275);
// @0x1402c4cf0
int CContentShutdown::Set(Content content,int value) {
    if(content<=None || content>=End) { MS2_ASSERT_AT(43,FALSE);return 0; }
    m_flags[content]=value; return 1;
}
MS2_REPLACE_METHOD(0x1402C4CF0, CContentShutdown, Set, 97, 0xD349C14E);
// @0x1402c4d60
int CContentShutdown::SetString(Content content,const CString& value) {
    if(value.IsEmpty()) return 0;
    int state=FUN_140718170(value);
    return Set(content,state);
}
MS2_REPLACE_METHOD(0x1402C4D60, CContentShutdown, SetString, 78, 0xECCC9AC3);
// @0x1402c4dc0
void CContentShutdown::Clear() { memset(m_flags,0,sizeof(m_flags)); }
MS2_REPLACE_METHOD(0x1402C4DC0, CContentShutdown, Clear, 27, 0x8127D2B1);
