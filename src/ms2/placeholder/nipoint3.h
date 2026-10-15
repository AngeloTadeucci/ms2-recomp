// nipoint3.h - PLACEHOLDER for the game's 12-byte float point and 3x3 matrix (Gamebryo NiPoint3 : efd::Point3 and
// NiMatrix3 : efd::Matrix3; NiMain headers are not on the game include path). NOT an original header.
//
// Unk_StreamPoint (first named in commonfiles/stream.h, moved here unchanged) plays both roles: the NiPoint3 default
// ctor and the efd::Point3 (x, y, z) ctor are recorded under its name in the symbol harvest. The efd::Point3 operators
// are inline COMDATs owned by other objs; they are declared as FUN_<va> members so that call sites byte-match and the
// hook DLL binds them to the exe.
#pragma once

#include "ms2/ms2layout.h"

struct Unk_StreamPoint
{
    Unk_StreamPoint();                                              // 0x1402bd040 (NiPoint3())
    Unk_StreamPoint(float, float, float);                           // 0x14027dda0 (efd::Point3(x, y, z))
    Unk_StreamPoint& operator=(const Unk_StreamPoint&);             // 0x140194470
    Unk_StreamPoint FUN_140965c40(const Unk_StreamPoint& pt) const; // efd::Point3::operator-
    Unk_StreamPoint FUN_14097fd50(const Unk_StreamPoint& pt) const; // efd::Point3::operator+
    Unk_StreamPoint FUN_140a00e10(const Unk_StreamPoint& pt) const; // efd::Point3::Cross
    float FUN_140968990();                                          // efd::Point3::Unitize (returns the old length)
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_StreamPoint, 12);

// efd::Point3 operator*(float, const Point3&) (friend, 0x1409ab5c0).
Unk_StreamPoint FUN_1409ab5c0(float fScalar, const Unk_StreamPoint& pt);

// NiPoint3 as a matrix-ctor argument: NiPoint3(const efd::Point3&) (0x14027dcf0) makes the conversion temporaries.
// Defined inline here (the exe copy belongs to another obj).
struct Unk_NiPoint3
{
    Unk_NiPoint3(const Unk_StreamPoint& pt) : x(pt.x), y(pt.y), z(pt.z) {}
    float x, y, z;
};
MS2_CHECK_SIZE(Unk_NiPoint3, 12);

// NiMatrix3 (0x24 bytes, rows of 3 floats). The ctors are inline COMDATs of other objs (defined here so that the DLL
// has them); the efd::Matrix3 functions are external.
struct Unk_NiMatrix3
{
    // 0x1409f7320 (calls the empty efd::Matrix3() 0x1409f72e0)
    Unk_NiMatrix3() {}
    // 0x140a0a480 -> efd::Matrix3::Matrix3(col0, col1, col2) 0x142083420
    Unk_NiMatrix3(const Unk_NiPoint3& col0, const Unk_NiPoint3& col1, const Unk_NiPoint3& col2)
    {
        FUN_142083420(col0, col1, col2);
    }
    void FUN_142083420(const Unk_NiPoint3& col0, const Unk_NiPoint3& col1, const Unk_NiPoint3& col2);
    void FUN_142083d40(float fX, float fY, float fZ);               // efd::Matrix3::FromEulerAnglesXYZ (radians)
    bool FUN_142085840(float& fX, float& fY, float& fZ) const;      // efd::Matrix3::ToEulerAnglesXYZ
    void FUN_140a01190(unsigned int uiCol, Unk_StreamPoint& pt) const;  // GetCol (inline, 0x140a01190)
    float m_afEntry[3][3];
};
MS2_CHECK_SIZE(Unk_NiMatrix3, 0x24);
