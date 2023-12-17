#include "component/AnimationComponent.h"
#include "2d/CCActionInterval.h"

void
Arkanoid::Components::
AnimationComponent::animate() {
  if(nullptr != _animationAction) return;
  auto animate = cocos2d::Animate::create(_animation);

  auto endAction = cocos2d::CallFunc::create([=] () {
        if(_endAnim)
          _endAnim();
        _animationAction = nullptr;
      });

  _animationAction = cocos2d::Sequence::create(animate, endAction, NULL);
  _ownerSprite->runAction(_animationAction);
}
