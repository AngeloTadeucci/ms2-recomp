// CProxyGameObject, ctor 1416c1cc0, destructor 1416c1f00. Layout only; all instances remain exe-owned.
#pragma once
#include "ms2/placeholder/cptred.h"
class CProxyGameObject : public CPtred {
public:
    unsigned char unrecovered18[0x50];
    int kind; // initialized to zero at +68; party member count tests it
    unsigned char unrecovered6c[0x7c];
};
MS2_CHECK_OFFSET(CProxyGameObject, kind, 0x68);
MS2_CHECK_SIZE(CProxyGameObject, 0xe8);
