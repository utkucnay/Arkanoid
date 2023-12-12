#include "scene/ActionScene.h"
#include "GameInstall.h"
#include "actor/Vaus.h"
#include "component/Component.h"
#include "component/HealthComponent.h"
#include "component/InputHandleComponent.h"
#include "component/MobileInputHandleComponent.h"
#include "component/MouseInputHandleComponent.h"
#include "component/MoveComponent.h"
#include "component/TargetMoveComponent.h"
#include "diContainer/DIContainer.h"
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsShape.h"
#include "physics/CCPhysicsWorld.h"
#include "resource/Resource.h"
#include "config/sceneConfig/ActionSceneConfig.h"
#include "scene/TitleScene.h"
#include "actor/EnergyBall.h"

bool
Arkanoid::ActionScene::init() {

  if(!Scene::init()) {
    return false;
  }
  if(!initWithPhysics()) {
    cocos2d::log("Not init Physics!");
    return false;
  }
  DI::DIContainer diContainer;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
  diContainer.addFactory<Components::InputHandleComponent, Components::MouseInputHandleComponent>();
#else
  diContainer.addFactory<Components::InputHandleComponent, Components::MobileInputHandleComponent>();
#endif
  diContainer.addFactory<Components::TargetMoveComponent, Components::TargetMoveComponent>();
  diContainer.addFactory<Components::MoveComponent, Components::MoveComponent>();
  auto config = getActionSceneConfig();


  getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);
  auto tagManager = gameDIContainer.getSingle<Manager::TagManager>();

  Vaus* vaus = Vaus::create();
  vaus->inject(diContainer);
  vaus->setTag(tagManager->getTag("Vaus"));
  vaus->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(32, 8)));
  vaus->getPhysicsBody()->setDynamic(false);
  vaus->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
  setNodeConfig(vaus, config->vaus);

  auto* energyBall = Arkanoid::EnergyBall::create();
  energyBall->inject(diContainer);
  energyBall->setTag(tagManager->getTag("EnergyBall"));
  setNodeConfig(energyBall, config->energyBall);
  energyBall->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(8, 4)));
  energyBall->getPhysicsBody()->setDynamic(false);
  energyBall->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);

  cocos2d::Node* columnLeft = Resource::createColumnLeft();
  columnLeft->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(8, 232)));
  columnLeft->getPhysicsBody()->setDynamic(false);
  columnLeft->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
  setNodeConfig(columnLeft, config->columnLeft.nodeConfig);

  cocos2d::Node* columnUp = Resource::createColumnUp();
  columnUp->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(176, 8)));
  columnUp->getPhysicsBody()->setDynamic(false);
  columnUp->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
  setNodeConfig(columnUp, config->columnUp.nodeConfig);

  cocos2d::Node* columnRight = Resource::createColumnRight();
  columnRight->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(8, 232)));
  columnRight->getPhysicsBody()->setDynamic(false);
  columnRight->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);
  setNodeConfig(columnRight, config->columnRight.nodeConfig);

  auto endArea = cocos2d::Node::create();
  endArea->setPosition(cocos2d:: Vec2(104, 70));
  endArea->setTag(tagManager->getTag("EndArea"));
  endArea->setPhysicsBody(cocos2d::PhysicsBody::createBox(cocos2d::Size(192,8)));
  endArea->getPhysicsBody()->setDynamic(false);
  endArea->getPhysicsBody()->setContactTestBitmask(0xFFFFFFFF);

  cocos2d::Node* field = Resource::createOrangeField();
  setNodeConfig(field, config->field);

  cocos2d::Label* highScoreLabel = cocos2d::Label::create();
  setLabelConfig(highScoreLabel, config->highScoreLabel);

  cocos2d::Label* levelLabel = cocos2d::Label::create();
  setLabelConfig(levelLabel, config->levelLabel);

  cocos2d::Label* scoreLabel = cocos2d::Label::create();
  setLabelConfig(scoreLabel, config->scoreLabel);


  this->addChild(columnUp);
  this->addChild(columnLeft);
  this->addChild(columnRight);
  this->addChild(field);
  this->addChild(vaus);
  this->addChild(highScoreLabel);
  this->addChild(levelLabel);
  this->addChild(scoreLabel);
  this->addChild(energyBall);
  this->addChild(endArea);

  return true;
}

cocos2d::Scene*
Arkanoid::ActionScene::createScene() {
  return ActionScene::create();
}
