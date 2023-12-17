#ifndef __ANIMATED_BRICK_H__
#define __ANIMATED_BRICK_H__

#include "actor/Brick.h"
#include "cocos2d.h"
#include "component/AnimationComponent.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid {
  class AnimatedBrick : public Brick {
  public:
    CREATE_FUNC(AnimatedBrick)
  public:
    virtual void inject(const DI::DIContainer& diContainer) override;
    virtual void hit(const cocos2d::Node& node) override;
    void setAnimAndSprite(cocos2d::Animation& animation, cocos2d::Sprite& sprite);
  private:
    std::shared_ptr<Components::AnimationComponent> _hitAnimComponent;
  };
}

#endif
