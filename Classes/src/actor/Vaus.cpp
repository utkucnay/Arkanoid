#include "actor/Vaus.h"
#include "component/AnimationComponent.h"
#include "component/HealthComponent.h"
#include "component/LimitedTargetMoveComponent.h"
#include "component/SpriteSqueeze.h"
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
  if(diContainer.hasFactory<Components::LimitedTargetMoveComponent>()) {
    _targetMoveComponent = diContainer.getFactory
      <Components::LimitedTargetMoveComponent>();

    _targetMoveComponent->setOwner(*this);
  }
  if(diContainer.hasFactory<Components::InputHandleComponent>()){
    _inputHandleComponent = diContainer.getFactory
      <Components::InputHandleComponent>();

    _inputHandleComponent->setOwner(*this);
  }
  if(diContainer.hasFactory<Components::SpriteSqueeze>()){
    _spriteSqueeze = diContainer.getFactory
      <Components::SpriteSqueeze>();

    _spriteSqueeze->setOwner(*this);
  }
  if(diContainer.hasFactory<Components::AnimationComponent>()){
    _destroyAnimComponent = diContainer.getFactory
      <Components::AnimationComponent>();

    _destroyAnimComponent->setOwner(*this);
    _destroyAnimComponent->setAnim(
        *Resource::createVausExlodeAnim(),
        *this);
  }
  if(diContainer.hasFactory<Components::HealthComponent>()) {
    _healthComponent = diContainer.getFactory<Components::HealthComponent>();
    _healthComponent->setOwner(*this);
  }
  if(diContainer.hasSingle<Manager::GameManager>())
    _gameManager = diContainer.getSingle<Manager::GameManager>();

}

void
Arkanoid::Vaus::onEnter() {

  _inputHandleComponent->onBegan = CC_CALLBACK_1(
      Arkanoid::Vaus::onMove, this);

  _inputHandleComponent->onMoved = CC_CALLBACK_1(
      Arkanoid::Vaus::onMove, this);

  _gameManager->setVaus(this);
  Node::onEnter();

  _targetMoveComponent->setLimit(
      cocos2d::Vec2(32, 0),
      cocos2d::Vec2(176, std::numeric_limits<float>::max()));

  _destroyAnimComponent->subsEndAnim(
      CC_CALLBACK_0(
        Arkanoid::Vaus::endDestroyVaus, this)
      );
  _spriteSqueeze->setSqueeze(cocos2d::Vec2(1.25f, .75f));
  _targetMoveComponent->setMaxSpeed(500);
  _targetMoveComponent->onEnter();
  _inputHandleComponent->onEnter();
}

void
Arkanoid::Vaus::update(float delta) {
  _targetMoveComponent->tick(delta);
  _spriteSqueeze->setScale(_targetMoveComponent->getSpeed() / 500);
}

void
Arkanoid::Vaus::onExit() {
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

void
Arkanoid::Vaus::hit(
    const cocos2d::Node& node)
{
}

void
Arkanoid::Vaus::startDestroyVaus() {
  if(_destroyAnimComponent->hasAnim())
    _destroyAnimComponent->animate();
  _targetMoveComponent->setEnabled(false);
}

void
Arkanoid::Vaus::endDestroyVaus() {
  _healthComponent->incrementHealth(-1);
  _gameManager->endDestroyVaus(_healthComponent->isDeath());
}
