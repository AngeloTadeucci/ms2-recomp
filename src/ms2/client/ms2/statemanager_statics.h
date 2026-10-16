// statemanager_statics.h - the null pointer handle that sits between the shared header statics ("stun") and the
// condition object in statemanager.cpp (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

class Unk_1401cd100 { public: Unk_1401cd100(void*); private: void* m_p; };     // ctor 0x1401cd100
static Unk_1401cd100 s_pointer(NULL);
