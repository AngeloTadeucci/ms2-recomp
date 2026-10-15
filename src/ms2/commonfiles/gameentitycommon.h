// Recovered game-entity/currency conversions; function and pointer type names are unknown.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
class Unk_14053c510 {
public:
    int FUN_14053c510(); int FUN_14053c5c0();
    bool FUN_14053ce80(); bool FUN_14053cf90();
};
template<class T> class Unk_1403bb3b0 {
public:
    Unk_1403bb3b0(const Unk_1403bb3b0& other) : p(other.p) { AddRef(); }
    ~Unk_1403bb3b0();
    bool operator==(T*) const;
    T* operator->() const;
private:
    void AddRef();
    void* pad; T* p;
};
MS2_CHECK_SIZE(Unk_1403bb3b0<Unk_14053c510>, 0x10);
int FUN_1403ba180(int value);
int FUN_1403ba270(int value);
int FUN_1403ba2a0(const CStringW& name);
bool FUN_1403ba480(int value);
bool FUN_1403ba4c0(const int& value);
int FUN_1403ba4f0(int value);
bool FUN_1403ba540(int value, int& currency);
bool FUN_1403ba590(int value, int& currency, int& color);
int FUN_1403ba790(unsigned int value);
int FUN_1403ba8c0(int id);
int FUN_1403ba950(Unk_1403bb3b0<Unk_14053c510> item);
int FUN_1403bad30(int value);
bool FUN_1403badc0(int value);
int FUN_1403bae00(int value);
int FUN_1403baee0(int value);
int FUN_1403bafd0(int id);
int FUN_1403bb010(int value, int color);
int FUN_1403bb120(int value);
int FUN_1403bb210(int color, bool all);
int FUN_1403bb2b0(int color);
int FUN_1403bb320(int currency, unsigned int mask);
