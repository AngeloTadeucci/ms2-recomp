// gfxexception.h - PLACEHOLDER for GfxException / GfxExceptionSwfLoad (RTTI, 0x18 bytes each = std::exception,
// vftables 0x1431143c8 / 0x1431143e0). NOT an original header.
// Thrown by pointer (`throw new GfxExceptionSwfLoad(...)`, ThrowInfo 0x1439df990 = GfxExceptionSwfLoad*,
// GfxException*, std::exception*, void*). The constructor takes the message by reference to a const char*.
#pragma once

#include <exception>

#include "ms2/ms2layout.h"

class GfxException : public std::exception
{
public:
    explicit GfxException(const char* const& szMessage);
};
MS2_CHECK_SIZE(GfxException, 0x18);

class GfxExceptionSwfLoad : public GfxException
{
public:
    explicit GfxExceptionSwfLoad(const char* const& szMessage);     // 0x1422e1620
};
MS2_CHECK_SIZE(GfxExceptionSwfLoad, 0x18);
