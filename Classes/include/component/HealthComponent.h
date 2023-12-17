#ifndef __HEALTH_COMPONENT_H__
#define __HEALTH_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"

namespace Arkanoid::Components {
  class HealthComponent : public Arkanoid::Component {
  public:
    virtual void onEnter()            override {}
    virtual void update(float delta)  override {}
    virtual void onExit()             override {}


    inline virtual bool isDeath() const { return m_health <= 0; };
    inline virtual void incrementHealth(int num) { m_health += num; }
    inline virtual void decraseHealth(int num) { m_health -= num; }
    inline virtual int getHealth() const { return m_health; }
    inline virtual void setHealth(int health) { m_health = health; }

  protected:
    int m_health{0};
  };
};

#endif
