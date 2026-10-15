// CItem: external constructor 0x140523790, allocation size 0x1a0.
#pragma once
#include "ms2/placeholder/cptred.h"
class Unk_UserProxyItemData;
class COutputStream;
class CInputStream;
class CItem : public CPtred {
public:
  CItem();
  virtual ~CItem();
  bool FUN_140523c40(int, int, int);
  Unk_UserProxyItemData *FUN_140527870();

  // Packet serialization declarations appended by a4 (unit_1401f9eb0).
  void FUN_140524ad0(COutputStream&);
  void FUN_140524eb0(CInputStream&);
  __int64 FUN_140526a50();
  void FUN_140526a70(__int64);
  int FUN_140526b50();
  void FUN_140526b70(int);
  void FUN_140526c70(int);
  int FUN_140526bd0();
  int FUN_1405276c0();
private:
  void *m_18;
  void *m_20;
  void *m_28;
  void *m_30;
  void *m_38;
  void *m_40;
  void *m_48;
  void *m_50;
  void *m_58;
  void *m_60;
  void *m_68;
  void *m_70;
  void *m_78;
  void *m_80;
  void *m_88;
  void *m_90;
  void *m_98;
  void *m_a0;
  void *m_a8;
  void *m_b0;
  void *m_b8;
  void *m_c0;
  void *m_c8;
  void *m_d0;
  void *m_d8;
  void *m_e0;
  void *m_e8;
  void *m_f0;
  void *m_f8;
  void *m_100;
  void *m_108;
  void *m_110;
  void *m_118;
  void *m_120;
  void *m_128;
  void *m_130;
  void *m_138;
  void *m_140;
  void *m_148;
  void *m_150;
  void *m_158;
  void *m_160;
  void *m_168;
  void *m_170;
  void *m_178;
  void *m_180;
  void *m_188;
  void *m_190;
  void *m_198;
};
MS2_CHECK_SIZE(CItem, 0x1a0);
