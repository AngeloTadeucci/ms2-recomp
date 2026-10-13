// Loader: proxy dinput8.dll placed next to MapleStory2.exe (x64/). The exe statically imports DINPUT8.dll
// (only DirectInput8Create), so this DLL is mapped and its DllMain runs during process initialization, before the
// exe's entry point and CRT init, i.e. before any game code. Hooks are installed right here.
// DirectInput8Create is forwarded lazily to the system dinput8.dll (loaded by full path from the system
// directory, so the proxy never loads itself). Under Wine the launcher sets WINEDLLOVERRIDES dinput8=n,b.
#include <windows.h>

#include "hook_runtime.h"
#include "ms2hook.h"

namespace {
using DirectInput8CreateFn = HRESULT(WINAPI*)(HINSTANCE, DWORD, REFIID, LPVOID*, LPVOID);
DirectInput8CreateFn g_realCreate = nullptr;

DirectInput8CreateFn RealCreate() {
    if (g_realCreate) return g_realCreate;
    wchar_t path[MAX_PATH];
    UINT n = GetSystemDirectoryW(path, MAX_PATH);
    if (n == 0 || n > MAX_PATH - 16) return nullptr;
    wcscat_s(path, L"\\dinput8.dll");
    HMODULE h = LoadLibraryW(path);
    if (!h) {
        ms2::hook::Log("dinput8 proxy: LoadLibrary(system dinput8.dll) failed, error %lu", GetLastError());
        return nullptr;
    }
    g_realCreate = reinterpret_cast<DirectInput8CreateFn>(GetProcAddress(h, "DirectInput8Create"));
    ms2::hook::Log("dinput8 proxy: forwarding DirectInput8Create to system dinput8.dll (%p)", g_realCreate);
    return g_realCreate;
}
}  // namespace

extern "C" __declspec(dllexport) HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riid,
                                                                   LPVOID* ppvOut, LPVOID punkOuter) {
    DirectInput8CreateFn real = RealCreate();
    if (!real) return E_FAIL;
    return real(hinst, dwVersion, riid, ppvOut, punkOuter);
}

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinst);
        ms2::hook::OpenLog();
        ms2::hook::Log("ms2hook dinput8 proxy loaded (built " __DATE__ " " __TIME__ ", %s)",
#if defined(__clang__)
                       "clang-cl"
#else
                       "cl"
#endif
        );
        ms2::hook::InstallAll();
        ms2::difftest::RunAll();
        ms2::hook::StartStatsThread();
    } else if (reason == DLL_PROCESS_DETACH) {
        (void)reserved;
        ms2::hook::LogFinalStats();  // not reached when the process is killed (wineserver -k): see "calls:" lines
    }
    return TRUE;
}
