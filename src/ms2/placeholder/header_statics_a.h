// header_statics_a.h - PLACEHOLDER for an unidentified game header that defines namespace-scope statics.
// NOT an original header. 85 client units run the same dynamic initializers in this order (e.g. .text$di of
// uicutscenemovie.cpp 0x140111d60.. and of the unit after it 0x140111f00..), so the statics come from one header
// that all of them include. Every including unit gets its own copies (internal linkage), constructed in this order.
// The names are invented; Unk_1402a9d70 is a class whose ctor/dtor live in commonfiles\conditionutil.cpp
// (maybe conditionutil.h is the header).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/unk_1402a9d70.h"


static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
// A unit whose own header sits between the skill/stun statics and the condition (uinametag: the gos name table) names
// that header in MS2_STATICS_A_BEFORE_CONDITION before including this one.
#ifdef MS2_STATICS_A_BEFORE_CONDITION
#include MS2_STATICS_A_BEFORE_CONDITION
#endif
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
