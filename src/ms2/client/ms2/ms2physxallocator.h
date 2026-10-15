// MS2PhysXAllocator (RTTI .?AVMS2PhysXAllocator@@): the game's NxUserAllocator that forwards to the CRT heap. Header name
// assumed; 8 bytes (the NxUserAllocator vptr; efd::MemObject is an empty second base that only supplies operator delete).
#pragma once

#include "ms2/ms2layout.h"
#include <stddef.h>
#include <efd/MemObject.h>
#include <NxUserAllocator.h>

class MS2PhysXAllocator : public NxUserAllocator, public efd::MemObject
{
public:
    MS2PhysXAllocator();
    virtual ~MS2PhysXAllocator();
    virtual void* mallocDEBUG(size_t size, const char* fileName, int line);
    virtual void* mallocDEBUG(size_t size, const char* fileName, int line, const char* className, NxMemoryType type);
    virtual void* malloc(size_t size);
    virtual void* malloc(size_t size, NxMemoryType type);
    virtual void* realloc(void* memory, size_t size);
    virtual void free(void* memory);
};
MS2_CHECK_SIZE(MS2PhysXAllocator, 8);
