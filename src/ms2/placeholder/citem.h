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
class CInPacket;
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
  void FUN_140526c10(int);
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
  class CUgcItemLook* FUN_140528380();    // 0x140528380 the UGC look of the item (ugccubepalette.cpp)
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
  int FUN_1405258b0();                    // 0x1405258b0 nonzero: no sell confirm by price (uimessagebox.cpp)
  __int64 FUN_140527670();                // 0x140527670 unit sell price (uimessagebox.cpp)
  void FUN_140526b30(int);                // 0x140526b30 set the owner object id (uibeautyshopstyledialog.cpp)
  void FUN_140528ab0(__int64);            // 0x140528ab0 set the creation time (saved beauty styles)
  __int64 FUN_140528ae0();                // 0x140528ae0 the creation time
  void FUN_1405255e0(CInPacket&);         // 0x1405255e0 read the item body (saved beauty styles)
  // Scalar accessors (item.cpp, w87): plain field getters/setters; names are by offset.
  int FUN_14052a020();
  void FUN_14052a040(int);
  int FUN_14052a150();
  void FUN_14052a130(int);
  void FUN_1405268d0(int);
  unsigned char FUN_140526930();
  void FUN_140526910(unsigned char);
  int FUN_140526a10();
  void FUN_140526a30(int);
  int FUN_140526970();
  int FUN_1405269b0();
  void FUN_140526990(int);
  __int64 FUN_140526a90();
  void FUN_140526ab0(__int64);
  __int64 FUN_140526ad0();
  void FUN_140526af0(__int64);
  int FUN_140526b10();
  int FUN_140526b90();
  void FUN_140526bf0(int);
  int FUN_140526c30();
  int FUN_140526e40();
  __int64 FUN_140528a90();
  void FUN_140528a60(__int64);
  int FUN_140529260();
  int FUN_140527300();
  void FUN_1405272e0(int);
  int FUN_140527340();
  void FUN_140527320(int);
  int FUN_140528ca0();
  void FUN_140528c80(int);
  __int64 FUN_140528e00();
  void FUN_140528dd0(__int64);
  int FUN_140529070();
  int FUN_140529090();
  __int64 FUN_140528b90();
  void FUN_140528b60(__int64);
  int FUN_140528bd0();
  void FUN_140528bb0(int);
  unsigned short FUN_140528c20();
  void FUN_140528bf0(unsigned short);
  int FUN_140528c60();
  void FUN_140528c40(int);
  unsigned char FUN_140529620();
  int FUN_1405292a0();
  void FUN_140529280(int);
  int FUN_140529640();
  void FUN_140529660(int);
  unsigned char FUN_1405269f0();
  void FUN_1405269d0(unsigned char);
  int FUN_1405291f0();
private:
  void *m_18;
  int m_20;
  int m_24;
  unsigned m_28;
  int m_2c;
  unsigned char m_30;
  char m_pad_31[3];
  int m_34;
  int m_38;
  int m_3c;
  __int64 m_40;
  __int64 m_48;
  __int64 m_50;
  int m_58;
  int m_5c;
  int m_60;
  int m_64;
  int m_68;
  int m_6c;
  int m_70;
  char m_pad_74[12];
  __int64 m_80;
  __int64 m_88;
  __int64 m_90;
  int m_98;
  int m_9c;
  int m_a0;
  int m_a4;
  __int64 m_a8;
  int m_b0;
  int m_b4;
  void *m_b8;
  __int64 m_c0;
  int m_c8;
  unsigned short m_cc;
  char m_pad_ce[2];
  int m_d0;
  unsigned char m_d4;
  char m_pad_d5[3];
  int m_d8;
  int m_dc;
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
  unsigned char m_198;
  char m_pad_199[3];
  int m_19c;
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
