// ms2memfile.h - PLACEHOLDER for MS2MemFile (RTTI .?AVMS2MemFile@@, 0x40 bytes). NOT an original header.
// An efd::File over a memory buffer (unit_141626c30, ?\ms2memfile.cpp, not recovered): the (data, size) ctor copies
// the bytes into a CFileBuffer held at +0x30. Only what other units call is declared.
#pragma once

#include <efd/FileCommon.h>

#include "ms2/ms2layout.h"

class MS2MemFile : public efd::FileCommon
{
public:
    MS2MemFile(const void* pData, int nSize);               // 0x141626f30
    MS2MemFile(const char* pszPath);                        // 0x141626e40: loads the file's bytes
    virtual ~MS2MemFile();                                  // 0x141627050
    unsigned int FUN_141627270(void* pDest, unsigned int nBytes);   // read (non-virtual here); returns the bytes copied
    virtual bool Flush();
    virtual bool Seek(int iOffset, SeekOrigin eSeekFrom);
    virtual unsigned int GetFileSize() const;
    virtual void SetEndianSwap(bool bDoSwap);
private:
    MS2_LAYOUT_FRIEND;
    int m_28;
    void* m_30[2];                                          // the shared CFileBuffer handle
};
MS2_CHECK_SIZE(MS2MemFile, 0x40);
