#ifndef __TARGET_MOVE_COMPONENT_H__
#define __TARGET_MOVE_COMPONENT_H__

#include "cocos2d.h"
#include "component/MoveComponent.h"

namespace Arkanoid::Components {
  class TargetMoveComponent : public MoveComponent {
  public:
    virtual void onEnter() override;
    virtual void update(float delta) override;

  public:
    virtual inline void setTarget(const cocos2d::Vec2& target) { _target = target; }
    inline void setMaxSpeed(float maxSpeed) { _maxSpeed = maxSpeed; }

  protected:
    cocos2d::Vec2 _target;
    float         _maxSpeed{1};
  };
}
#endif
