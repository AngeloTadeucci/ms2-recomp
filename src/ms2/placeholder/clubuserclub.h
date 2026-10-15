// Club types: RTTI names and layouts proved by clubcommon.cpp constructors and userproxy.cpp.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/stream.h"
namespace Club {
class NameInfo : public CPtred {
public:
  NameInfo();
  virtual ~NameInfo();
  __int64 m_18;
  CStringW m_20;
};
MS2_CHECK_SIZE(NameInfo, 0x28);
class UserClub : public CPtred {
public:
  UserClub();
  virtual ~UserClub();
  void FUN_14020c9e0();
  MS2Ptr<NameInfo> FUN_14020ca10(__int64);
  size_t FUN_14020ca90();
  int FUN_14020cac0();
  int FUN_14020cb00(__int64, CStringW);
  int FUN_14020cc00(MS2Ptr<NameInfo>);
  void FUN_14020ccb0(__int64);
  void FUN_14020cce0(ATL::CAtlArray<MS2Ptr<NameInfo>> &);
  void FUN_14020cda0(const ATL::CAtlArray<MS2Ptr<NameInfo>> &);
  void FUN_14020ce50(COutputStream &);
  void FUN_14020cfc0(CInputStream &);

private:
  void *m_18;
  void *m_20;
  void *m_28;
  void *m_30;
  void *m_38;
  void *m_40;
};
MS2_CHECK_SIZE(UserClub, 0x48);
} // namespace Club
