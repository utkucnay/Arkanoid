#ifndef __LIMITED__TARGET_MOVE_COMPONENT_H__
#define __LIMITED__TARGET_MOVE_COMPONENT_H__

#include "cocos2d.h"
#include "component/TargetMoveComponent.h"

namespace Arkanoid::Components {
  class LimitedTargetMoveComponent : public TargetMoveComponent {
  public:
    virtual void onEnter() override;
    virtual void update(float delta) override;
    virtual void setTarget(const cocos2d::Vec2& target) override;
    virtual inline void setLimit(
        const cocos2d::Vec2& beginSpace,
        const cocos2d::Vec2& endSpace)
    {
      _beginSpace = beginSpace;
      _endSpace = endSpace;
    }
  protected:
    cocos2d::Vec2 _beginSpace;
    cocos2d::Vec2 _endSpace;
  };
}
#endif
