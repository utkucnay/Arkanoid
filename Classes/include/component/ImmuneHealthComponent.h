#ifndef __IMMUNE_HEALTH_COMPONENT_H__
#define __IMMUNE_HEALTH_COMPONENT_H__

#include "cocos2d.h"
#include "component/HealthComponent.h"

namespace Arkanoid::Components {
  class ImmuneHealthComponent : public HealthComponent {
  public:
    inline bool isDeath() const override { return false; }
    inline void incrementHealth(int num) override { }
    inline void decraseHealth(int num) override { }
    inline int getHealth() const override { return std::numeric_limits<int>::max(); }
  };
}

#endif
