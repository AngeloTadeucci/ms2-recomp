// worldservice_inst.inl - the container operations of WorldService, as the original worldservice.cpp used them. In the
// exe the std::map/CAtlMap/CRBMap member functions (and their helper templates) are COMDATs emitted by the CU, sorted by
// mangled name, and cut by the 4-way unit split into ?\worldservice.cpp#2..#4. Each part's obj instantiates them through
// this driver (the real callers live in the methods of parts 1 and 5+); pairing with the exe is done by the
// MS2-PIN lines in the part files. Included with WS_INST_FN defined to a per-part function name.
#include "worldservice.h"

template <class K> static K WsKey(int n) { return (K)n; }
template <> static CString WsKey<CString>(int) { return CString(); }
template <class T> static void WsConstruct(T& m) { new (&m) T(); }
template <class T> static void WsDestroy(T& m) { m.~T(); }
template <class K, class V, class KT, class VT> static void WsDriveAtl(ATL::CAtlMap<K, V, KT, VT>& m, int n)
{
    K k = WsKey<K>(n);
    V v = V();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.RemoveKey(k);
    m.RemoveAll();
    POSITION pos = m.GetStartPosition();
    while (pos)
        m.GetNextAssoc(pos, k, v);
}
template <class K, class V, class KT, class VT> static void WsDriveRB(ATL::CRBMap<K, V, KT, VT>& m, int n)
{
    K k = WsKey<K>(n);
    V v = V();
    m.SetAt(k, v);
    m.Lookup(k, v);
    m.RemoveKey(k);
    m.RemoveAll();
    POSITION pos = m.GetHeadPosition();
    while (pos)
        m.GetNextAssoc(pos, k, v);
}
template <class M> static void WsDriveStd(M& m, typename M::key_type k)
{
    typename M::mapped_type v = typename M::mapped_type();
    m[k] = v;
    m.insert(std::make_pair(k, v));
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    m.erase(k);
    m.clear();
    for (it = m.begin(); it != m.end(); ++it) {}
}
void WS_INST_FN(WorldService* w)
{
    WsDriveStd(w->m_1d8, 1);
    WsDriveStd(w->m_2e8, 1);
    WsDriveStd(w->m_ac0, 1);
    WsDriveStd(w->m_ad0, 1);
    WsDriveStd(w->m_1f8, 1);
    WsDriveStd(w->m_980, 1);
    WsDriveStd(w->m_990, 1);
    WsDriveStd(w->m_ab0, 1);
    WsDriveAtl(w->m_208, 1);
    WsDriveAtl(w->m_350, 1);
    WsDriveAtl(w->m_3a0, 1);
    WsDriveAtl(w->m_780, 1);
    WsDriveAtl(w->m_848, 1);
    WsDriveAtl(w->m_930, 1);
    WsDriveAtl(w->m_738, 1);
    WsDriveAtl(w->m_2f8, 1);
    WsDriveAtl(w->m_420, 1);
    WsDriveAtl(w->m_468, 1);
    WsDriveAtl(w->m_5a0, 1);
    WsDriveRB(w->m_0b8, 1);
    WsDriveRB(w->m_0e8, 1);
    WsDriveRB(w->m_118, 1);
    WsDriveRB(w->m_148, 1);
    WsDriveRB(w->m_1a8, 1);
    WsDriveRB(w->m_4e0, 1);
    WsDriveRB(w->m_540, 1);
    WsDriveRB(w->m_570, 1);
    WsDriveRB(w->m_6a8, 1);
    WsDriveRB(w->m_6d8, 1);
    WsDriveRB(w->m_708, 1);
    WsDriveRB(w->m_4b0, 1);
    WsDriveRB(w->m_510, 1);
    WsDriveRB(w->m_678, 1);
    WsDriveRB(w->m_5e8, 1);
    WsDriveRB(w->m_618, 1);
    WsDriveRB(w->m_7c8, 1);
    w->m_1e8[1].insert(2);
    WsConstruct(w->m_1d8);
    WsDestroy(w->m_1d8);
    WsConstruct(w->m_2e8);
    WsDestroy(w->m_2e8);
    WsConstruct(w->m_ac0);
    WsDestroy(w->m_ac0);
    WsConstruct(w->m_ad0);
    WsDestroy(w->m_ad0);
    WsConstruct(w->m_1f8);
    WsDestroy(w->m_1f8);
    WsConstruct(w->m_980);
    WsDestroy(w->m_980);
    WsConstruct(w->m_990);
    WsDestroy(w->m_990);
    WsConstruct(w->m_ab0);
    WsDestroy(w->m_ab0);
    WsConstruct(w->m_208);
    WsDestroy(w->m_208);
    WsConstruct(w->m_350);
    WsDestroy(w->m_350);
    WsConstruct(w->m_3a0);
    WsDestroy(w->m_3a0);
    WsConstruct(w->m_780);
    WsDestroy(w->m_780);
    WsConstruct(w->m_848);
    WsDestroy(w->m_848);
    WsConstruct(w->m_930);
    WsDestroy(w->m_930);
    WsConstruct(w->m_738);
    WsDestroy(w->m_738);
    WsConstruct(w->m_2f8);
    WsDestroy(w->m_2f8);
    WsConstruct(w->m_420);
    WsDestroy(w->m_420);
    WsConstruct(w->m_468);
    WsDestroy(w->m_468);
    WsConstruct(w->m_5a0);
    WsDestroy(w->m_5a0);
    WsConstruct(w->m_0b8);
    WsDestroy(w->m_0b8);
    WsConstruct(w->m_0e8);
    WsDestroy(w->m_0e8);
    WsConstruct(w->m_118);
    WsDestroy(w->m_118);
    WsConstruct(w->m_148);
    WsDestroy(w->m_148);
    WsConstruct(w->m_1a8);
    WsDestroy(w->m_1a8);
    WsConstruct(w->m_4e0);
    WsDestroy(w->m_4e0);
    WsConstruct(w->m_540);
    WsDestroy(w->m_540);
    WsConstruct(w->m_570);
    WsDestroy(w->m_570);
    WsConstruct(w->m_6a8);
    WsDestroy(w->m_6a8);
    WsConstruct(w->m_6d8);
    WsDestroy(w->m_6d8);
    WsConstruct(w->m_708);
    WsDestroy(w->m_708);
    WsConstruct(w->m_4b0);
    WsDestroy(w->m_4b0);
    WsConstruct(w->m_510);
    WsDestroy(w->m_510);
    WsConstruct(w->m_678);
    WsDestroy(w->m_678);
    WsConstruct(w->m_5e8);
    WsDestroy(w->m_5e8);
    WsConstruct(w->m_618);
    WsDestroy(w->m_618);
    WsConstruct(w->m_7c8);
    WsDestroy(w->m_7c8);
    WsConstruct(w->m_1e8);
    WsDestroy(w->m_1e8);
    WsConstruct(w->m_058);
    WsDestroy(w->m_058);
    WsConstruct(w->m_9a0);
    WsDestroy(w->m_9a0);
    WsConstruct(w->m_a00);
    WsDestroy(w->m_a00);
    WsConstruct(w->m_a18);
    WsDestroy(w->m_a18);
}
