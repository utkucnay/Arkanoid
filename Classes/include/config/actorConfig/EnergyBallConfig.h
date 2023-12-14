#ifndef __ENERGY_BALL_CONFIG_H__
#define __ENERGY_BALL_CONFIG_H__

#include "config/Cocos2dConfig.h"
#include "diContainer/DIContainer.h"

struct EnergyBallConfig {
  NodeConfig nodeConfig;
  PhysicConfig physicConfig;

  DI::DIContainer diContainer;
};

#endif
