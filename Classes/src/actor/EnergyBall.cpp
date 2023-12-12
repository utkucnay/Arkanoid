#include "actor/EnergyBall.h"
#include "GameInstall.h"
#include "component/MoveComponent.h"
#include "manager/SceneManager.h"
#include "manager/TagManager.h"
#include "math/Vec2.h"
#include "resource/Resource.h"
#include "scene/TitleScene.h"

bool
Arkanoid::EnergyBall::init() {
  auto contactListener = cocos2d::EventListenerPhysicsContact::create();
  contactListener->onContactBegin =
    CC_CALLBACK_1(EnergyBall::onContactBegin, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(
      contactListener, this);


  _sprite = Resource::createEnergyBall();
  this->addChild(_sprite);

  this->scheduleUpdate();
  return true;
}

void
Arkanoid::EnergyBall::inject(
    const DI::DIContainer& diContainer)
{
  _moveComponent = diContainer.getFactory<Components::MoveComponent>();
  _moveComponent->setOwner(*this);
  _tagManager = gameDIContainer.getSingle<Manager::TagManager>();
  _sceneManager = gameDIContainer.getSingle<Manager::SceneManager>();
}

void
Arkanoid::EnergyBall::onEnter() {
  Node::onEnter();
  _moveComponent->onEnter();
  _moveComponent->setVelocity(cocos2d::Vec2(5, 10));
  _moveComponent->setSpeed(100);
  setPositionZ(4);
}

void
Arkanoid::EnergyBall::update(float delta) {
  Node::update(delta);
  _moveComponent->update(delta);
}

bool
Arkanoid::EnergyBall::onContactBegin(
    cocos2d::PhysicsContact& contact)
{
  auto nodeA = contact.getShapeA()->getBody()->getNode();
  auto nodeB = contact.getShapeB()->getBody()->getNode();
  if(nodeA->getTag() == this->getTag())
    onContact(contact, *nodeB);
  if(nodeB->getTag() == this->getTag())
    onContact(contact, *nodeA);

  return false;
}

void
Arkanoid::EnergyBall::onContact (
    cocos2d::PhysicsContact& contact,
    cocos2d::Node& node)
{
  cocos2d::Vec2 dir;
  if(node.getTag() == _tagManager->getTag("Vaus")) {
    dir = hitVaus(node);
    _moveComponent->setDir(dir.getNormalized());
    return;
  }
  if(node.getTag() == _tagManager->getTag("EndArea")) {
    _moveComponent->setSpeed(0);
    _sceneManager->changeScene<TitleScene>();
    return;
  }

  dir = bounce(contact);
  _moveComponent->setDir(dir.getNormalized());
}

cocos2d::Vec2
Arkanoid::EnergyBall::bounce(
    cocos2d::PhysicsContact& contact)
{
  cocos2d::Vec2 dir;
  auto normal = contact.getContactData()->normal;
  dir = _moveComponent->getDir();

  float dotp = dir.dot(normal);
  normal.scale(2 * dotp);
  dir.subtract(normal);
  return dir;
}

cocos2d::Vec2
Arkanoid::EnergyBall::hitVaus(cocos2d::Node& vaus) {
  cocos2d::Vec2 dir;
  dir = getPosition() - vaus.getPosition();
  dir.y = dir.y > 0 ? dir.y : dir.y * -1;
  return dir;
}
