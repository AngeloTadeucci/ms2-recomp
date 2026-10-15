// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Server packet payload (de)serialisers.
// MS2-UNIT: commonfiles\serverpacketdef.cpp
// MS2-RANGE: 0x1407a3380-0x1407a4f20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\serverpacketdef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "serverpacketdef.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x1407a3380
Unk_SPDA::Unk_SPDA() : type(0), value(0) {}

// @0x1407a33e0
Unk_SPDA::Unk_SPDA(const Unk_SPD0& src) {
    type = src.type;
    value = src.value;
    s1 = src.s1;
    s2 = src.s2;
}

// @0x1407a3490
void Unk_SPDA::FUN_1407a3490(COutputStream* out) {
    out->vfunc_o10_1(type);
    switch (type) {
    case 2:
        out->vfunc_o10_8(s1);
        out->vfunc_o10_8(s2);
        break;
    case 3: case 4: case 6: case 7: case 0x11:
        out->vfunc_o10_4(value);
        break;
    case 5: case 10:
        out->vfunc_o10_4(value);
        out->vfunc_o10_8(s1);
        out->vfunc_o10_8(s2);
        break;
    case 0x10:
        out->vfunc_o10_8(s1);
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3490, Unk_SPDA, FUN_1407a3490, 355, 0x8BEDCA45);

// @0x1407a3640
void Unk_SPDA::FUN_1407a3640(Unk_SPDReader& in) {
    Unk_SPDByteRange range;
    type = in.FUN_140202740(*FUN_140203550(&range, 0, 0x14));
    switch (type) {
    case 2:
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 3: case 4: case 6: case 7: case 0x11:
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        break;
    case 5: case 10:
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 0x10:
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3640, Unk_SPDA, FUN_1407a3640, 756, 0x43C6420F);

// @0x1407a3980
void Unk_SPDB::FUN_1407a3980(COutputStream* out) {
    out->vfunc_o10_1(type);
    switch (type) {
    case 2:
        out->vfunc_o10_1(flag);
        out->vfunc_o10_8(s1);
        out->vfunc_o10_8(s2);
        break;
    case 4: case 6: case 0x11:
        out->vfunc_o10_1(flag);
        out->vfunc_o10_4(value);
        break;
    case 3: case 7:
        out->vfunc_o10_1(flag);
        out->vfunc_o10_4(value);
        out->vfunc_o10_4(extra);
        out->vfunc_o10_4(id);
        out->vfunc_o10_8(s1);
        break;
    case 5: case 10:
        out->vfunc_o10_1(flag);
        out->vfunc_o10_4(value);
        out->vfunc_o10_8(s1);
        out->vfunc_o10_8(s2);
        // no break: the exe falls through into case 0xe
    case 0xe:
        out->vfunc_o10_1(kind);
        out->vfunc_o10_4(value);
        out->vfunc_o10_8(s1);
        break;
    case 0xb:
        out->vfunc_o10_4(value);
        break;
    case 0xc:
        out->vfunc_o10_1(flag);
        out->vfunc_o10_8(s1);
        break;
    case 0xf:
        break;
    default:
        MS2_ASSERT_AT(0x86, 0);
    }
}
MS2_REPLACE_METHOD(0x1407A3980, Unk_SPDB, FUN_1407a3980, 752, 0xDE36C697);

// @0x1407a3cc0
void Unk_SPDB::FUN_1407a3cc0(Unk_SPDReader& in) {
    Unk_SPDByteRange range;
    type = in.FUN_140202740(*FUN_140203550(&range, 0, 0x14));
    switch (type) {
    case 0xf:
        break;
    case 2:
        flag = static_cast<CInputStream&>(in).vfunc_o8_1();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 4: case 6: case 0x11:
        flag = static_cast<CInputStream&>(in).vfunc_o8_1();
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        break;
    case 3: case 7:
        flag = static_cast<CInputStream&>(in).vfunc_o8_1();
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        extra = static_cast<CInputStream&>(in).vfunc_o8_4();
        id = static_cast<CInputStream&>(in).vfunc_o8_4();
        s1 = static_cast<CInputStream&>(in).vfunc_o8_8();
        break;
    case 5: case 10:
        flag = static_cast<CInputStream&>(in).vfunc_o8_1();
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        s2 = in.FUN_140202f40(Unk_MaxWide(0x32));
        break;
    case 0xe:
        kind = static_cast<CInputStream&>(in).vfunc_o8_1();
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    case 0xb:
        value = static_cast<CInputStream&>(in).vfunc_o8_4();
        break;
    case 0xc:
        flag = static_cast<CInputStream&>(in).vfunc_o8_1();
        s1 = in.FUN_140202f40(Unk_MaxWide(0x18));
        break;
    }
}
MS2_REPLACE_METHOD(0x1407A3CC0, Unk_SPDB, FUN_1407a3cc0, 1648, 0x14FFD8A2);

// @0x1407a4380
void Unk_SPDC::FUN_1407a4380(COutputStream* out) {
    out->vfunc_o10_3(a);
    out->vfunc_o10_3(b);
    out->vfunc_o10_3(c);
    out->vfunc_o10_3(d);
    out->vfunc_o10_1(e);
}
MS2_REPLACE_METHOD(0x1407A4380, Unk_SPDC, FUN_1407a4380, 139, 0x3A3B4B05);

// @0x1407a4420
void Unk_SPDC::FUN_1407a4420(CInputStream* in) {
    a = in->vfunc_o8_3();
    b = in->vfunc_o8_3();
    c = in->vfunc_o8_3();
    d = in->vfunc_o8_3();
    e = in->vfunc_o8_1();
}
MS2_REPLACE_METHOD(0x1407A4420, Unk_SPDC, FUN_1407a4420, 138, 0xE2ECB42C);

// @0x1407a44b0
void Unk_SPDE::FUN_1407a44b0(COutputStream* out) {
    out->vfunc_o10_1(kind);
    out->vfunc_o10_8(name);
}
MS2_REPLACE_METHOD(0x1407A44B0, Unk_SPDE, FUN_1407a44b0, 81, 0x55FD50B3);

// @0x1407a4510
void Unk_SPDE::FUN_1407a4510(CInputStream* in) {
    kind = in->vfunc_o8_1();
    name = in->vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1407A4510, Unk_SPDE, FUN_1407a4510, 125, 0xB200A850);

// @0x1407a45a0
void Unk_SPDF::FUN_1407a45a0(COutputStream* out) {
    out->vfunc_o10_1(a);
    out->vfunc_o10_3(b);
    out->vfunc_o10_8(name);
    out->vfunc_o10_4(c);
    out->vfunc_o10_4(d);
    out->vfunc_o10_3(e);
    out->vfunc_o10_1(f);
    out->vfunc_o10_1(g);
    out->vfunc_o10_3(l);
    out->vfunc_o10_4(m);
    if (g == 1) {
        out->vfunc_o10_4(h);
    } else if (g == 2) {
        out->vfunc_o10_4(i);
        out->vfunc_o10_4(j);
    }
    out->vfunc_o10_3(k);
}
MS2_REPLACE_METHOD(0x1407A45A0, Unk_SPDF, FUN_1407a45a0, 407, 0x8F5C5A48);

// @0x1407a4740
void Unk_SPDF::FUN_1407a4740(CInputStream* in) {
    a = in->vfunc_o8_1();
    b = in->vfunc_o8_3();
    name = in->vfunc_o8_8();
    c = in->vfunc_o8_4();
    d = in->vfunc_o8_4();
    e = in->vfunc_o8_3();
    f = in->vfunc_o8_1();
    g = in->vfunc_o8_1();
    l = in->vfunc_o8_3();
    m = in->vfunc_o8_4();
    if (g == 1) {
        h = in->vfunc_o8_4();
    } else if (g == 2) {
        i = in->vfunc_o8_4();
        j = in->vfunc_o8_4();
    }
    k = in->vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1407A4740, Unk_SPDF, FUN_1407a4740, 452, 0x5B028907);

// @0x1407a4910
void Unk_SPDG::FUN_1407a4910(COutputStream* out) {
    out->vfunc_o10_3(a);
    out->vfunc_o10_4(b);
    out->vfunc_o10_4(c);
    out->vfunc_o10_8(d);
}
MS2_REPLACE_METHOD(0x1407A4910, Unk_SPDG, FUN_1407a4910, 130, 0x4DAF50D7);

// @0x1407a49a0
void Unk_SPDG::FUN_1407a49a0(CInputStream* in) {
    a = in->vfunc_o8_3();
    b = in->vfunc_o8_4();
    c = in->vfunc_o8_4();
    d = in->vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1407A49A0, Unk_SPDG, FUN_1407a49a0, 172, 0x17B43280);

// @0x1407a4a60
void Unk_SPDH::FUN_1407a4a60(COutputStream* out) {
    out->vfunc_o10_4(a);
    out->vfunc_o10_8(b);
}
MS2_REPLACE_METHOD(0x1407A4A60, Unk_SPDH, FUN_1407a4a60, 81, 0xC84F2203);

// @0x1407a4ac0
void Unk_SPDH::FUN_1407a4ac0(CInputStream* in) {
    a = in->vfunc_o8_4();
    b = in->vfunc_o8_8();
}
MS2_REPLACE_METHOD(0x1407A4AC0, Unk_SPDH, FUN_1407a4ac0, 123, 0x1D80FD34);

// @0x1407a4b50
void Unk_SPDI::FUN_1407a4b50(COutputStream* out) {
    out->vfunc_o10_1(kind);
    if (kind == 0) {
        out->vfunc_o10_3(a);
        out->vfunc_o10_2(b);
        out->vfunc_o10_3(c);
        out->vfunc_o10_3(d);
        out->vfunc_o10_3(e);
    } else {
        out->vfunc_o10_8(s);
    }
    if (kind == '1') {
        out->vfunc_o10_4(x);
    }
}
MS2_REPLACE_METHOD(0x1407A4B50, Unk_SPDI, FUN_1407a4b50, 254, 0x578809F0);

// @0x1407a4c60
void Unk_SPDI::FUN_1407a4c60(CInputStream* in) {
    kind = in->vfunc_o8_1();
    if (kind == 0) {
        a = in->vfunc_o8_3();
        b = in->vfunc_o8_2();
        c = in->vfunc_o8_3();
        d = in->vfunc_o8_3();
        e = in->vfunc_o8_3();
    } else {
        s = in->vfunc_o8_8();
    }
    if (kind == '1') {
        x = in->vfunc_o8_4();
    }
}
MS2_REPLACE_METHOD(0x1407A4C60, Unk_SPDI, FUN_1407a4c60, 295, 0x1CFF92C3);

// @0x1407a4d90
void Unk_SPDJ::FUN_1407a4d90(COutputStream* out) {
    out->vfunc_o10_3(a);
}
MS2_REPLACE_METHOD(0x1407A4D90, Unk_SPDJ, FUN_1407a4d90, 42, 0x198D3D0B);

// @0x1407a4dc0
void Unk_SPDJ::FUN_1407a4dc0(Unk_SPDReader& in) {
    a = static_cast<CInputStream&>(in).vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1407A4DC0, Unk_SPDJ, FUN_1407a4dc0, 60, 0x21DC48C6);

// @0x1407a4e10
void Unk_SPDK::FUN_1407a4e10(COutputStream* out) {
    out->vfunc_o10_1(b);
    out->vfunc_o10_4(a);
    out->vfunc_o10_3(c);
}
MS2_REPLACE_METHOD(0x1407A4E10, Unk_SPDK, FUN_1407a4e10, 92, 0x43E21C6F);

// @0x1407a4e80
void Unk_SPDK::FUN_1407a4e80(Unk_SPDReader& in) {
    b = static_cast<CInputStream&>(in).vfunc_o8_1();
    a = static_cast<CInputStream&>(in).vfunc_o8_4();
    c = static_cast<CInputStream&>(in).vfunc_o8_3();
}
MS2_REPLACE_METHOD(0x1407A4E80, Unk_SPDK, FUN_1407a4e80, 148, 0xEF4965A1);
