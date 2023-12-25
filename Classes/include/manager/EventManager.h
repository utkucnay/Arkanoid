#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "cocos2d.h"

class EventHelper {
public:
  static std::string getEnergyBallHit() { return "EnergyBallHit";}
  static std::string getAddScore() { return "AddScore";}
};

#endif
