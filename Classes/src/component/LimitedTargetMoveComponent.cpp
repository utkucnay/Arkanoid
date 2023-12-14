#include "component/LimitedTargetMoveComponent.h"

void
Arkanoid::Components::LimitedTargetMoveComponent::onEnter() {
  TargetMoveComponent::onEnter();
}

void
Arkanoid::Components::LimitedTargetMoveComponent::update(
    float delta)
{
  TargetMoveComponent::update(delta);
}

void
Arkanoid::Components::LimitedTargetMoveComponent::setTarget(
    const cocos2d::Vec2& target)
{
  cocos2d::Vec2 nTarget = target;
  nTarget.clamp(_beginSpace, _endSpace);
  TargetMoveComponent::setTarget(nTarget);
}
