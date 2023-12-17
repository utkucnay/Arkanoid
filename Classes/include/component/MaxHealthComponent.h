#ifndef __MAX_HEALTH_COMPONENT_H__
#define __MAX_HEALTH_COMPONENT_H__

#include "cocos2d.h"
#include "component/HealthComponent.h"

namespace Arkanoid::Components {
  class MaxHealthComponent : public HealthComponent {
  public:
    inline virtual void incrementHealth(int num) override {
      m_health += num;
      lerpMaxHealth();
    }

    inline virtual void decraseHealth(int num) override {
      m_health -= num;
      lerpMaxHealth();
    }

    inline void lerpMaxHealth() {
      m_health = m_health < _maxHealth ? m_health : _maxHealth;
    }

    inline void setMAxHealth(int maxHealth) { _maxHealth = maxHealth; }

  private:
    int _maxHealth{0};
  };
}

#endif
