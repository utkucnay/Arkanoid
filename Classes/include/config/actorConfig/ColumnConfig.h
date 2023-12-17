#ifndef __COLUMN_CONFIG_H__
#define __COLUMN_CONFIG_H__

#include "config/Cocos2dConfig.h"
#include "diContainer/DIContainer.h"

struct ColumnConfig {
  NodeConfig nodeConfig;
  PhysicConfig physicConfig;

  DI::DIContainer diContainer;
};

#endif
