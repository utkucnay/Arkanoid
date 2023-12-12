#include "component/MoveComponent.h"

void
Arkanoid::Components::MoveComponent::move(float delta) {
  _owner->setPosition(_owner->getPosition() + getVelocity() * delta);
}

void
Arkanoid::Components::MoveComponent::setSpeed(float speed) {
  _speed = speed;
}

void
Arkanoid::Components::MoveComponent::setDir(
    const cocos2d::Vec2& dir)
{
  _dir = dir.getNormalized();
}

void
Arkanoid::Components::MoveComponent::setVelocity(
    const cocos2d::Vec2& vel)
{
  _dir = vel.getNormalized();
  _speed = vel.length();
}

void
Arkanoid::Components::MoveComponent::onEnter() {

}

void
Arkanoid::Components::MoveComponent::update(float delta) {
  move(delta);
}

void
Arkanoid::Components::MoveComponent::onExit() {

}
