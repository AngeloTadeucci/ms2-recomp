#include "difftest.h"

#include "hook_runtime.h"

#include <windows.h>

#include <cstdarg>
#include <cstdio>

namespace ms2::difftest {
namespace {
struct Test {
    const char* name;
    TestFn fn;
    const char* file;
    int line;
    Test* next;
};
Test* g_tests = nullptr;  // constant-initialized
}  // namespace

bool Register(const char* name, TestFn fn, const char* file, int line) {
    // Leaked on purpose: lives for the whole process.
    g_tests = new Test{name, fn, file, line, g_tests};
    return true;
}

void Context::Fail(const char* fmt, ...) {
    ++failures;
    if (failures > 10) return;  // keep the log readable
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    hook::Log("DIFFTEST   %s: mismatch: %s", name, buf);
}

bool Context::ExpectBytes(const void* orig, const void* repl, size_t n, const char* what) {
    ++checks;
    auto* a = static_cast<const uint8_t*>(orig);
    auto* b = static_cast<const uint8_t*>(repl);
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            Fail("%s: first difference at byte %zu of %zu (orig %02x, repl %02x)", what, i, n, a[i], b[i]);
            return false;
        }
    }
    return true;
}

void RunAll() {
    char env[8];
    DWORD n = GetEnvironmentVariableA("MS2HOOK_DIFFTEST", env, sizeof(env));
    if (n > 0 && n < sizeof(env) && env[0] == '0') {
        hook::Log("difftests disabled (MS2HOOK_DIFFTEST=0)");
        return;
    }
    unsigned pass = 0, fail = 0, skip = 0;
    for (Test* t = g_tests; t; t = t->next) {
        Context ctx;
        ctx.name = t->name;
        uint64_t seed = 0xcbf29ce484222325ull;  // FNV-1a-64 of the test name: deterministic inputs
        for (const char* c = t->name; *c; ++c) seed = (seed ^ static_cast<uint8_t>(*c)) * 0x100000001b3ull;
        ctx.rng.s = seed ? seed : 1;
        t->fn(ctx);
        // SKIP only if nothing was compared; a test that skipped some parts but compared others is PASS/FAIL.
        const bool isSkip = ctx.skipped && ctx.checks == 0;
        const char* res = ctx.failures ? "FAIL" : isSkip ? "SKIP" : "PASS";
        (ctx.failures ? fail : isSkip ? skip : pass)++;
        hook::Log("DIFFTEST %s %s: checks=%u failures=%u%s%s", res, t->name, ctx.checks, ctx.failures,
                  ctx.skipped ? (isSkip ? " - " : " - partially skipped: ") : "", ctx.skipped ? ctx.skipped : "");
    }
    hook::Log("difftests: %u pass, %u fail, %u skip", pass, fail, skip);
}

}  // namespace ms2::difftest
