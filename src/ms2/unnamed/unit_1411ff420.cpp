// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A two-function character helper island: FUN_1411ff420
// writes one character at the head of a buffer and, unless that character is NUL, runs the six-bit normaliser
// FUN_1411ff480 over it. The write is laid out as a count-down for loop started at 0, so it runs exactly once.
// MS2-UNIT: unit_1411ff420
// MS2-RANGE: 0x1411ff420-0x1411ff4c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void FUN_1411ff480(unsigned char* pszData);

// @0x1411ff420
void FUN_1411ff420(unsigned char* pszData, unsigned char ch)
{
    int i = 0;
    for (; i >= 0; i--)
    {
        pszData[i] = ch;
    }
    if (ch != 0)
    {
        FUN_1411ff480(pszData);
    }
}

// @0x1411ff480
// MS2-FUNCTIONAL: the normaliser is raised by a constant-false condition, so the exe keeps the mask as unreachable
// code: xor eax,eax / cmp eax,6 / je <mask> / jmp <ret>. The constant compare below reproduces that layout exactly -
// only the compared constant differs, because every equivalent source shape here folds the zero operand to the
// boolean 1 while the exe's copy carries the 6 the condition was written with.
void FUN_1411ff480(unsigned char* pszData)
{
    if (0 != 6)
    {
    }
    else
    {
        pszData[1 * 0] = (unsigned char)(pszData[1 * 0] & 0x3f);
    }
}
