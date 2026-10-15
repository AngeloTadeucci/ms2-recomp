// Party UI types used only for RTTI lookup. Constructors establish the bases and sizes.
#pragma once
#include "ms2/placeholder/uidialog.h"
class UIChaosDPSDialog : public UIDialog {
    unsigned char unrecovered[0x28];
};
class UIPartyDPSDialog : public UIDialog {
    unsigned char unrecovered[0x28];
};
// UIPartySearchRegisterDialog ctor 141320660 calls UIModalDialog's ctor.
class UIModalDialog : public UIDialog {
    unsigned char unrecovered[8];
};
class UIPartySearchRegisterDialog : public UIModalDialog {
    unsigned char unrecovered[0xa8];
};
MS2_CHECK_SIZE(UIChaosDPSDialog, 0x1a0);
MS2_CHECK_SIZE(UIPartyDPSDialog, 0x1a0);
MS2_CHECK_SIZE(UIModalDialog, 0x180);
MS2_CHECK_SIZE(UIPartySearchRegisterDialog, 0x228);
