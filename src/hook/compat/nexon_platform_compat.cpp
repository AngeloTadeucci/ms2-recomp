// Compatibility fix for the KMS2_DEV client as distributed - NOT recovered game code (behaviour deliberately differs
// from the original). Lives in src/hook/compat/, built only with MS2HOOK_WITH_COMPAT=ON (default); disable at run
// time with MS2HOOK_DISABLE=NexonKorea_GetServiceIndex,NexonKorea_ShutdownNX. See NOTES.md "Field-entry crash".
//
// Problem: FUN_1406c34b0 (the "Nexon platform enabled" predicate behind FUN_1406c34c0) is the only function in the
// exe encoded as `mov eax,0; ret` (B8 00 00 00 00 C3; cl /Od emits `xor eax,eax` for `return 0`, 80 such functions,
// and `mov eax,1` 14 times) - i.e. it was byte-patched 1 -> 0 to run without the Nexon launcher. WinMain therefore
// never calls CClientPlatformNexonKorea vslot 14 (0x140c78150), which is the only creator of the CNXMan singleton
// (TSingleton<CNXMan>::ms_pInstance, 0x143ABF528). CSceneStateGame vslot 9 (OnEnter, 0x14170beb0) unconditionally
// calls FUN_140db8eb0 -> platform vslot 75 (0x140c78d30) -> vslot 74 (0x140c78cf0), which dereferences the null
// CNXMan: access violation at 0x14160e608 on every field entry (~98 % loading), then the blank error dialog.
// Same for vslot 15 (0x140c78180, NX shutdown at exit).
#include "hook/ms2hook.h"

namespace {

struct CNXMan;  // 0xC8 bytes, vtable 0x142F43E70 (TSingleton<CNXMan>); +0x14 = Nexon game code

MS2_EXTERN(0x140C7A260, CNXMan*(), TSingleton_CNXMan_GetInstance);       // returns ms_pInstance (may be null)
MS2_EXTERN(0x140C7A040, void(), TSingleton_CNXMan_DestroyInstance);      // null-safe
MS2_EXTERN(0x14160E5F0, int(CNXMan* self), CNXMan_IsGameCode);           // this->m_nGameCode == 0x1A002
MS2_EXTERN(0x14160DA80, void(CNXMan* self), CNXMan_Finalize);

// CClientPlatformNexonKorea vslot 74. Original: `return CNXMan_IsGameCode(GetInstance()) ? 5 : 4;` (no null check).
// The result indexes the platform's game-code string table (FUN_140c78d30); 4 = the value for a CNXMan whose game
// code does not match, the natural "no NX" answer.
int NexonKorea_GetServiceIndex(void* /*self*/)
{
    CNXMan* nx = TSingleton_CNXMan_GetInstance();
    if (nx == nullptr)
        return 4;
    return CNXMan_IsGameCode(nx) ? 5 : 4;
}

// CClientPlatformNexonKorea vslot 15 (NX shutdown). Original calls CNXMan_Finalize(GetInstance()) unconditionally.
void NexonKorea_ShutdownNX(void* /*self*/)
{
    if (CNXMan* nx = TSingleton_CNXMan_GetInstance())
        CNXMan_Finalize(nx);
    TSingleton_CNXMan_DestroyInstance();
}

}  // namespace

MS2_REPLACE(0x140C78CF0, NexonKorea_GetServiceIndex, 43, 0x0AF4CFE5);
MS2_REPLACE(0x140C78180, NexonKorea_ShutdownNX, 32, 0xA65668CE);
