// termtagcontext.h - PLACEHOLDER for TermTagContext (?\termtagcontext.cpp, ctor 0x1408665e0). NOT an original header.
// A named, timed tag of the game events (CGameRule keeps them by name at +0x650). Only what gamerule.cpp uses.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"

class TermTagContext : public CPtred
{
public:
    CStringW FUN_140866690();                               // the name (m_20)

    int m_18;
    CStringW m_20;                                          // +0x20 name
    CMsTime m_28;
    CMsTime m_38;
    bool m_48;
};
