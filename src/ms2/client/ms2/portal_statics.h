// portal_statics.h - the static of portal.cpp that sits between the shared header statics ("stun") and the condition (see
// ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION): the null entity id the CPortal constructor copies.
#pragma once

#include <egf/EntityID.h>

static egf::EntityID s_idPortalNone((efd::UInt64)0);           // @0x1400fc230
