#include "actor/Brick.h"
#include "2d/CCActionInterval.h"
#include "CCEventListenerCustom.h"
#include "manager/EventManager.h"

bool
Arkanoid::Brick::init() {
  auto energyBL = cocos2d::EventListenerCustom::create(
      EventHelper::getEnergyBallHit(),
      CC_CALLBACK_1(Brick::energyBallHitSomething, this));
  _eventDispatcher->addEventListenerWithSceneGraphPriority(energyBL, this);
  return true;
}

void
Arkanoid::Brick::hit(const cocos2d::Node& node) {
  _healthComponent->decraseHealth(1);
  if(_healthComponent->isDeath()) {
      this->removeFromParentAndCleanup(true);
  }
}

void
Arkanoid::Brick::inject(
    const DI::DIContainer& diContainer)
{
  if(diContainer.hasFactory<Components::HealthComponent>()) {
    _healthComponent = diContainer.getFactory<
      Components::HealthComponent>();

    _healthComponent->setOwner(*this);
  }
}


void
Arkanoid::Brick::setSprite(
    cocos2d::Sprite& sprite)
{
  _sprite = &sprite;
  this->addChild(_sprite);
}

void
Arkanoid::Brick::energyBallHitSomething(
    cocos2d::EventCustom* event)
{
  stopActionByTag(22);

  auto seq = cocos2d::Sequence::create(
      cocos2d::ScaleTo::create(.1, .75, .75),
      cocos2d::ScaleTo::create(.1, 1, 1),
      NULL);
  seq->setTag(22);

  runAction(seq);
}
