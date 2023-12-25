#ifndef __BRICK_H__
#define __BRICK_H__

#include "actor/IHit.h"
#include "cocos2d.h"
#include "component/HealthComponent.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid {
  class Brick : public cocos2d::Node, public IHit {
  public:
    bool init() override;
    CREATE_FUNC(Brick)

  public:
    virtual void inject(const DI::DIContainer& diContainer);
    virtual void hit(const cocos2d::Node& node) override;
    void setSprite(cocos2d::Sprite& sprite);
    inline void setHealth(int health) { _healthComponent->setHealth(health);}
    void energyBallHitSomething(cocos2d::EventCustom* event);
    void onDestroy();

  public:
    inline void setPoints(int points) { _points = points; }

  protected:
    std::shared_ptr<Components::HealthComponent> _healthComponent;
    cocos2d::Sprite* _sprite;
    int _points;
  };
}

#endif
