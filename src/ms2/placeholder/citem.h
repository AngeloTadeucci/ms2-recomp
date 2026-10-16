// CItem: external constructor 0x140523790, allocation size 0x1a0.
#pragma once
#include "ms2/placeholder/cptred.h"
class Unk_UserProxyItemData;
class COutputStream;
class CInputStream;
class Unk_ItemUgcInfo;
class Unk_ItemEquipData;
class Unk_ItemEnchantData;
class Unk_ItemOwnerRef;
template <class T> class MS2Ptr;
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
  Unk_ItemEquipData* FUN_140527840();   // 0x140527840 the item's data record (equip flags; uiequipiconcontainer.cpp)
  // Inventory ordering accessors, a1 (inventory.cpp).
  int FUN_140525c60();
  __int64 FUN_140528910();
  // Remaining primary slots verified from CItem's exe vftable by a1.
  virtual void vfunc_1();
  virtual void vfunc_2();
  virtual int vfunc_3(int);
  virtual int vfunc_4();
  virtual void vfunc_5(bool);
  int FUN_1405268f0();
  CString FUN_140528590();                // 0x140528590 the item's name (uirewardnotify.cpp)
  int FUN_14052b130(int, int, int);   // can the item be combined with this one (ItemInfoSlot exchange scroll)
  // sb4 (clonecube.cpp): UGC look of the item. The callee returns a byte; callers test eax (declared int there).
  int FUN_140525f10();                   // 0x140525f10 item data at +0xe8 is a UGC item
  Unk_ItemUgcInfo* FUN_1405278d0();       // 0x1405278d0 operator-> of the MS2Ptr at +0x118 (UGC info)
  unsigned __int64 FUN_1405283d0();       // 0x1405283d0 UGC uid of that info (0 when null; avatarcube.cpp)
  CStringW FUN_140527b10();               // 0x140527b10 (uiugccubepalettedialog.cpp)
  void FUN_1405288e0(__int64);            // 0x1405288e0 set the count (uiugccubepalettedialog.cpp)
  void FUN_140528300(class CUgcItemLook*);   // 0x140528300 set the UGC look (uiugccubepalettedialog.cpp)
  bool FUN_140528cc0();                   // 0x140528cc0 can be item-locked (unit_1406125d0)
  bool FUN_140528da0();                   // 0x140528da0 can be item-unlocked (unit_1406125d0)
  // uiitemenchantdialog.cpp: enchant-related accessors.
  int FUN_140526fc0();                    // 0x140526fc0 enchant level
  int FUN_1405270a0();                    // 0x1405270a0 enchant exp
  void FUN_140527110(int);                // 0x140527110 set enchant exp
  int FUN_140527270();
  int FUN_140527030();
  Unk_ItemEnchantData* FUN_1405278a0();   // 0x1405278a0 the enchant data object (null when absent)
  Unk_ItemOwnerRef* FUN_140527930();      // 0x140527930 binding owner holder
  unsigned FUN_140527710();               // 0x140527710 item level
  int FUN_14052b2e0(int, int, int, int);  // set up from id, rank, 0, count
  MS2Ptr<CItem> FUN_140524250();          // 0x140524250 copy
  bool FUN_1405277e0(int);
  bool FUN_140528e20();
  int FUN_140528f90(int);
  CStringW FUN_140528160();               // 0x140528160 item name
  int FUN_140526c50();                    // 0x140526c50 count
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
// Prefix view of the UGC info behind CItem::FUN_1405278d0 (type name unknown; inventory.cpp views the same +0x30
// field as Unk_InventoryStackIdentity::owner).
class Unk_ItemUgcInfo {
public:
  void *m_pad_00[6];
  __int64 m_nUgcUid;                     // +0x30 compared by CloneCube::vfunc_61
  char m_pad_38[0x38];
  CString m_strName;                     // +0x70 cached UGC file name (avatarcube.cpp)
};
