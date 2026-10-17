// ugcmanager.h - types shared by the four client\ms2\ugcmanager.cpp translation units (#1..#4). NOT an original header.
// #1 ugcmanager_1.cpp: CUgcCompress (zlib .m2u packages), the D3DX image converter, the upload/thumbnail file helpers
//    and the CUgcDownloadLoad worker.
#pragma once

#include <afx.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

namespace efd { class File; }
class NiTexture;

// A local file queued for upload (ugcmanager.cpp#4; members not recovered yet).
class CUploadFile : public CPtred
{
public:
    CStringW FUN_14187e9f0();                               // the local file path
};

// zlib packer for UGC files: Compress writes "<convert dir>\upload.m2u" from a file, Decompress inflates a downloaded
// .m2u into memory. Name from the log text "CUgcCompress::Decompress".
class CUgcCompress
{
public:
    CUgcCompress();                                         // 0x1418694d0
    ~CUgcCompress();                                        // 0x1418695a0
    int Compress(const CStringW& strOrgFile, void* pUnused);
    int Decompress(const CStringW& strZipFile, unsigned __int64 userData);
    CStringW GetOrgFile();
    CStringW GetZipFile();
    efd::File* CreateMemFile();
    BYTE* GetBuffer();
    int GetDataSize();
    void Close();
    int DoCompress();
    int DoDecompress();
private:
    MS2_LAYOUT_FRIEND;
    FILE* m_pOrgFile;                                       // +0x00
    FILE* m_pZipFile;                                       // +0x08
    int m_bCompress;                                        // +0x10
    CStringW m_strOrgFile;                                  // +0x18
    CStringW m_strZipFile;                                  // +0x20
    BYTE* m_pBuffer;                                        // +0x28 inflated data (efd allocator)
    int m_nBufferSize;                                      // +0x30
    int m_nDataSize;                                        // +0x34
};
MS2_CHECK_SIZE(CUgcCompress, 0x38);

// Loads an image through D3DX and re-saves it in the format/size an upload kind needs. The name is invented.
class CUgcImageConverter
{
public:
    CUgcImageConverter();                                   // 0x14186a430
    ~CUgcImageConverter();                                  // 0x14186a4a0
    CStringW GetSrcFile();
    CStringW GetDstFile();
    int GetState();
    int ConvertTexture(const CStringW& strSrc, int nSize, bool bPng);
    int ConvertIcon(const CStringW& strSrc);
    int ConvertThumbnail(const CStringW& strSrc);
    int ConvertMemory(const CStringW& strSrc, const void* pData, int nSize);
    int ConvertBanner(const CStringW& strSrc);
    void Clear();
    int LoadFile();
    int LoadMemory(const void* pData, int nSize);
    int Convert(D3DFORMAT eFormat, int nWidth, int nHeight, int nMipSize);
    int GetMipLevels(int nWidth, int nHeight);
    HRESULT CopySurfaces(int nUnused, IDirect3DTexture9* pDst);
    int Save(D3DXIMAGE_FILEFORMAT eFormat);
private:
    MS2_LAYOUT_FRIEND;
    CStringW m_strSrcFile;                                  // +0x00
    CStringW m_strDstFile;                                  // +0x08
    int m_nState;                                           // +0x10 1 once a destination is chosen
    IDirect3DTexture9* m_pSrcTexture;                       // +0x18
    IDirect3DTexture9* m_pDstTexture;                       // +0x20
    int m_nWidth;                                           // +0x28
    int m_nHeight;                                          // +0x2c
    int m_nDepth;                                           // +0x30
    int m_nMipLevels;                                       // +0x34
};
MS2_CHECK_SIZE(CUgcImageConverter, 0x38);

// Result of the file helpers (also used by UIItemBlueprintCreateDialog as Unk_BpImageResult). The name is invented.
struct Unk_UgcFileResult
{
    Unk_UgcFileResult() { Reset(); }                        // 0x14186e3a0
    void Reset()                                            // 0x14186e790
    {
        m_nResult = 1;
        m_strName = L"";
        m_strPath = L"";
        m_bTemporary = 0;
    }
    int m_nResult;                                          // +0x00 0 = success, else an error code
    CStringW m_strName;                                     // +0x08
    CStringW m_strPath;                                     // +0x10
    int m_bTemporary;                                       // +0x18
};
MS2_CHECK_SIZE(Unk_UgcFileResult, 0x20);

Unk_UgcFileResult ChangeFormat(int nType, MS2Ptr<CUploadFile> pUploadFile, int nSize, bool bPng);
efd::SmartPointer<NiTexture> LoadUgcTexture(const CStringW& strPath, int nSize, bool bPng);
efd::SmartPointer<NiTexture> LoadCachedTexture(const CStringW& strPath);
int ConvertIconFile(const CStringW& strPath);
