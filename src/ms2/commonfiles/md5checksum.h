// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: e:\build\kr\22_04\ms2code\commonfiles\md5checksum.h
// (name assumed: the .cpp's __FILE__ string is in the exe, the header's is not).
//
// CMD5Checksum is the public-domain CodeProject class by Langfine Ltd (2001), unchanged apart from Nexon's three
// trailing free functions in the .cpp. The game never calls it: only MD5Unknown0 (an empty function called from the
// main loop) is referenced; the rest survives because the exe was linked with /OPT:NOREF.
#pragma once

#include <afx.h>

#include <string>
#include <vector>

// vftable 0x142d76ba0 (1 slot: scalar deleting dtor), size 0x60 (RTTI + ??_G).
class CMD5Checksum
{
public:
    static CString GetMD5(BYTE* pBuf, UINT nLength);        // 0x140696e00 (unreferenced)
    static CString GetMD5(CFile& File);                     // 0x140696ed0
    static CString GetMD5(const CString& strFilePath);      // 0x140696fd0 (unreferenced)

protected:
    CMD5Checksum();                                         // 0x140697050
    // @0x140699260
    virtual ~CMD5Checksum() {};

    void Transform(BYTE Block[64]);                         // 0x140697110
    void Update(BYTE* Input, ULONG nInputLen);              // 0x1406983d0
    CString Final();                                        // 0x140698580
    inline DWORD RotateLeft(DWORD x, int n);                // 0x140699cc0 (COMDAT: inline, defined in the .cpp)
    inline void FF(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  // 0x1406993b0
    inline void GG(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  // 0x140699590
    inline void HH(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  // 0x140699630
    inline void II(DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);  // 0x1406996b0

    void DWordToByte(BYTE* Output, DWORD* Input, UINT nLength);  // 0x140698820
    void ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength);  // 0x1406989b0

private:
    BYTE  m_lpszBuffer[64];     // +0x08 input buffer
    ULONG m_nCount[2];          // +0x48 number of bits, modulo 2^64 (lsb first)
    ULONG m_lMD5[4];            // +0x50 MD5 checksum
};

// Nexon additions at the end of md5checksum.cpp (names invented; no symbols or strings name them).
void MD5Unknown0();                                         // 0x140698b10, empty, called from the main loop 0x14148f360
void MD5Unknown1(void* p);                                  // 0x140698b20, empty, unreferenced
// Collect the files under strPath (recursively, while the path has fewer than nDepth + nMaxDepth backslashes)
// whose name contains strExt; names are lowercased. Skips ".", ".." and ".svn". 0x140698b30, unreferenced.
void FindFilesRecursive(std::string strExt, std::string strPath, std::vector<std::string>& vecFiles, int nDepth,
                        int nMaxDepth);
