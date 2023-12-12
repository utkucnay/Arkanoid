#include "actor/Vaus.h"
#include "component/HealthComponent.h"
#include "diContainer/DIContainer.h"
#include "resource/Resource.h"

bool
Arkanoid::Vaus::init() {
  _vausParts[0] = Resource::createVausLeftSprite();
  _vausParts[1] = Resource::createVausMidSprite();
  _vausParts[2] = Resource::createVausMidSprite();
  _vausParts[3] = Resource::createVausMidSprite();
  _vausParts[4] = Resource::createVausMidSprite();
  _vausParts[5] = Resource::createVausRightSprite();

  _vausAttackParts[0] = Resource::createVausAttackLeftSprite();

  _vausParts[0]->setPosition(cocos2d::Vec2(-12, 0));
  _vausParts[1]->setPosition(cocos2d::Vec2(-4, 0));
  _vausParts[2]->setPosition(cocos2d::Vec2(-4, 0));
  _vausParts[3]->setPosition(cocos2d::Vec2(4, 0));
  _vausParts[4]->setPosition(cocos2d::Vec2(4, 0));
  _vausParts[5]->setPosition(cocos2d::Vec2(12, 0));

  for (size_t i = 0; i < 6; i++) {
      this->addChild(_vausParts[i]);
  }

  this->scheduleUpdate();

  return true;
}

void
Arkanoid::Vaus::inject(
    const DI::DIContainer& diContainer)
{
  _targetMoveComponent = diContainer.getFactory<Components::TargetMoveComponent>();
  _inputHandleComponent = diContainer.getFactory<Components::InputHandleComponent>();
  _targetMoveComponent->setOwner(*this);
  _inputHandleComponent->setOwner(*this);
}

void
Arkanoid::Vaus::onEnter() {

  _inputHandleComponent->onBegan = CC_CALLBACK_1(
      Arkanoid::Vaus::onMove, this);

  _inputHandleComponent->onMoved = CC_CALLBACK_1(
      Arkanoid::Vaus::onMove, this);

  Node::onEnter();

  _targetMoveComponent->setMaxSpeed(500);
  _targetMoveComponent->onEnter();
  _inputHandleComponent->onEnter();
}

void
Arkanoid::Vaus::update(float delta) {
  _targetMoveComponent->update(delta);
}

void
Arkanoid::Vaus::onMove(
    const Arkanoid::Components::InputHandle& inputHandle)
{
  cocos2d::Vec2 target;
  target.x = inputHandle.location.x;
  target.y = this->getPositionY();
  _targetMoveComponent->setTarget(target);
}
