// camera_statics.h - the static of camera.cpp that sits between the shared header statics ("stun") and the condition
// (see ms2/placeholder/header_statics_a.h, MS2_STATICS_A_BEFORE_CONDITION).
#pragma once

#include <egf/EntityID.h>

// @0x1400c6710
static egf::EntityID s_invalidCameraEntity(0ull);
