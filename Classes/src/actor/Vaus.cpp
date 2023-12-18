#include "actor/Vaus.h"
#include "manager/EventManager.h"
#include "resource/Resource.h"

bool
Arkanoid::Vaus::init() {
  _sprite = Resource::createVausSprite();
  this->addChild(_sprite);

  auto energyBL = cocos2d::EventListenerCustom::create(
      EventHelper::getEnergyBallHit(),
      CC_CALLBACK_1(Vaus::energyBallHitSomething, this));
  _eventDispatcher->addEventListenerWithSceneGraphPriority(energyBL, this);

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
        *_sprite);
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
  _gameManager->setVaus(nullptr);
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
  _gameManager->onEndDestroyVaus(_healthComponent->isDeath());
}


void
Arkanoid::Vaus::energyBallHitSomething(
    cocos2d::EventCustom* event)
{
  stopActionByTag(22);

  auto seq = cocos2d::Sequence::create(
      cocos2d::ScaleTo::create(1.25, 1.25, .75),
      cocos2d::ScaleTo::create(.1, 1, 1),
      NULL);
  seq->setTag(22);

  runAction(seq);
}
