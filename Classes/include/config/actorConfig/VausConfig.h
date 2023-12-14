#ifndef __VAUS_CONFIG_H__
#define __VAUS_CONFIG_H__

#include "cocos2d.h"
#include "config/Cocos2dConfig.h"
#include "diContainer/DIContainer.h"

struct VausConfig {
  NodeConfig nodeConfig;
  PhysicConfig physicConfig;

  DI::DIContainer diContainer;
};

#endif
