// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). WorldService COMDAT tail, sub-unit #5 (owner ws3).
// MS2-UNIT: ?\worldservice.cpp#5
// MS2-RANGE: 0x141bf7060-0x141bfe180 .text$mn
// MS2-PIN: ??8?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_WsV9a0@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141bf7640 ; cf3: calls the empty _Compat 0x141c215b0 (vector iterator, not a tree iterator)
// MS2-PIN: ??9?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_WsV9a0@@@std@@@std@@@std@@QEBA_NAEBV01@@Z 0x141bf7950 ; cf3: calls ??8 0x141bf7640
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\worldservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

template <class M> void Unk_WsTouchTree(M& m, typename M::key_type k)
{
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    for (typename M::iterator i = m.begin(); i != m.end(); ++i)
        ;
    for (typename M::iterator i = m.begin(); i != m.end(); i++)
        ;
    for (typename M::iterator i = m.end(); i != m.begin(); --i)
        ;
    for (typename M::const_iterator i = m.begin(); i != m.end(); ++i)
        ;
}
struct Unk_WsT0 { unsigned char raw[16]; };
struct Unk_WsT2 { void* raw; };
struct Unk_WsT3 { void* raw; };
struct Unk_WsT4 { void* raw; };
struct Unk_WsT5 { void* raw; };
struct Unk_WsT6 { unsigned char raw[32]; };
struct Unk_WsT7 { void* raw; };
void Unk_WsAnchor()
{
    std::map<int, Unk_WsT0> m0; Unk_WsTouchTree(m0, 0);
    std::map<int, std::set<unsigned __int64> > m1; Unk_WsTouchTree(m1, 0);
    std::map<unsigned, Unk_WsT2> m2; Unk_WsTouchTree(m2, 0);
    std::map<unsigned __int64, Unk_WsT3> m3; Unk_WsTouchTree(m3, 0);
    std::map<unsigned __int64, Unk_WsT4> m4; Unk_WsTouchTree(m4, 0);
    std::map<unsigned __int64, Unk_WsT5> m5; Unk_WsTouchTree(m5, 0);
    std::map<unsigned __int64, Unk_WsT6> m6; Unk_WsTouchTree(m6, 0);
    std::map<unsigned __int64, Unk_WsT7> m7; Unk_WsTouchTree(m7, 0);
    std::map<unsigned __int64, MS2Ptr<Unk_WsPtred> > m8; Unk_WsTouchTree(m8, 0);
    std::set<void*> m9; Unk_WsTouchTree(m9, 0);
    // m_9a0's const_iterator ==/!= (0x141bf7640 / 0x141bf7950; == calls the empty _Compat 0x141c215b0). Without these
    // the set<unsigned __int64> tree-iterator ??9 above paired with 0x141bf7950 by masked bytes (cf3, 2026-10-17).
    std::vector<Unk_WsV9a0> v9a0;
    std::vector<Unk_WsV9a0>::const_iterator a = v9a0.begin(), b = v9a0.end();
    if (a == b || a != b)
        ;
}
