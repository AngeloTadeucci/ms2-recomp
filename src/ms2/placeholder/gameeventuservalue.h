// GameEventUserValue: CPtred plus a 0x30-byte map, proved by 0x14041f550 and 0x140420050.
#pragma once
#include "ms2/placeholder/cptred.h"
class GameEventUserValue : public CPtred {
public:
  GameEventUserValue();
  virtual ~GameEventUserValue();

private:
  void *m_18;
  void *m_20;
  void *m_28;
  void *m_30;
  void *m_38;
  void *m_40;
};
MS2_CHECK_SIZE(GameEventUserValue, 0x48);
