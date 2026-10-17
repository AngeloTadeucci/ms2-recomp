// zlib125.h - PLACEHOLDER. NOT an original header. The exe statically links zlib 1.2.5 (deflateInit_/inflateInit_ get
// the version string "1.2.5" and sizeof(z_stream) 0x58); the engine tree only has the 1.2.3 header, whose API and
// z_stream layout are the same. The functions come from the exe (progress/symbols-manual.tsv rows).
#pragma once

#include "../../../engine/gamebryo/3rdParty/ZLib/Package/zlib.h"

#undef ZLIB_VERSION
#define ZLIB_VERSION "1.2.5"
