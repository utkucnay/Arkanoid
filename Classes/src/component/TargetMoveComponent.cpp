#include "component/TargetMoveComponent.h"
#include "math/MathUtil.h"

void
Arkanoid::Components::TargetMoveComponent::onEnter() {
  setTarget(_owner->getPosition());
}

void
Arkanoid::Components::TargetMoveComponent::update(float delta) {
  cocos2d::Vec2 dist = _target - _owner->getPosition();
  setDir(dist);

  float maxVelocity = _maxSpeed * delta;
  float maxSpeed = dist.getLength() / delta;

  float speed = maxVelocity < dist.getLength() ? _maxSpeed : maxSpeed;
  setSpeed(speed);

  MoveComponent::update(delta);
}
