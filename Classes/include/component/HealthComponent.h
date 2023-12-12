#ifndef __HEALTH_COMPONENT_H__
#define __HEALTH_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"

namespace Arkanoid::Components {
  class HealthComponent : public Arkanoid::Component {
  public:
    virtual void onEnter()            override;
    virtual void update(float delta)  override;
    virtual void onExit()             override;


    inline bool isDeath() const { return m_health <= 0; };
    inline void incrementHealth(int num) { m_health += num; }
    inline void reciveDamage(int num) { m_health -= num; }
    inline int getHealth() const { return m_health; }

    void Reset();
  private:
    int m_health;
    int m_maxHealth;
  };
};

#endif
