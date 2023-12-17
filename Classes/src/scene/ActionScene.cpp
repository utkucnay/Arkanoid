#include "scene/ActionScene.h"
#include "GameInstall.h"
#include "actor/Brick.h"
#include "actor/Vaus.h"
#include "actor/EnergyBall.h"
#include "actor/Column.h"
#include "component/HealthComponent.h"
#include "manager/LevelManager.h"
#include "prefab/BrickPrefab.h"
#include "resource/Resource.h"
#include "config/sceneConfig/ActionSceneConfig.h"

bool
Arkanoid::ActionScene::init() {

  if(!Scene::init()) {
    return false;
  }
  if(!initWithPhysics()) {
    cocos2d::log("Not init Physics!");
    return false;
  }

 // getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);
  auto config = getActionSceneConfig();

  Vaus* vaus = Vaus::create();
  vaus->inject(config->vaus.diContainer);
  vaus->inject(gameDIContainer);

  setNodeConfig(vaus, config->vaus.nodeConfig);
  setPhysicConfig(vaus, config->vaus.physicConfig);

  auto* energyBall = Arkanoid::EnergyBall::create();
  energyBall->inject(config->energyBall.diContainer);
  energyBall->inject(gameDIContainer);
  setNodeConfig(energyBall, config->energyBall.nodeConfig);
  setPhysicConfig(energyBall, config->energyBall.physicConfig);

  Column* columnLeft = Column::create();
  columnLeft->inject(config->columnLeft.diContainer);
  columnLeft->inject(gameDIContainer);

  columnLeft->setSpriteAndAnim(
      *Resource::createColumnLeft(),
      Resource::createColumnLeftHitAnim());

  setNodeConfig(columnLeft, config->columnLeft.nodeConfig);
  setPhysicConfig(columnLeft, config->columnLeft.physicConfig);

  cocos2d::Node* sColumnLeft = cocos2d::Node::create();
  setPhysicConfig(sColumnLeft, config->columnLeft.physicConfig);
  sColumnLeft->setPosition(columnLeft->getPosition());
  sColumnLeft->setPositionX(
      columnLeft->getPositionX() -
      config->columnLeft.physicConfig.sizeBox.width);
  setPhysicConfig(sColumnLeft, config->columnLeft.physicConfig);

  Column* columnUp = Column::create();
  columnUp->inject(config->columnUp.diContainer);
  columnUp->inject(gameDIContainer);

  columnUp->setSpriteAndAnim(
      *Resource::createColumnUp(),
      Resource::createColumnUpHitAnim());

  setNodeConfig(columnUp, config->columnUp.nodeConfig);
  setPhysicConfig(columnUp, config->columnUp.physicConfig);

  Column* columnRight = Column::create();
  columnRight->inject(config->columnRight.diContainer);
  columnRight->inject(gameDIContainer);
  columnRight->setSpriteAndAnim(
      *Resource::createColumnRight(),
      Resource::createColumnRightHitAnim());

  setNodeConfig(columnRight, config->columnRight.nodeConfig);
  setPhysicConfig(columnRight, config->columnRight.physicConfig);

  cocos2d::Node* sColumnRight = cocos2d::Node::create();
  setPhysicConfig(sColumnRight, config->columnLeft.physicConfig);
  sColumnRight->setPosition(columnLeft->getPosition());
  sColumnRight->setPositionX(
      columnRight->getPositionX() +
      config->columnRight.physicConfig.sizeBox.width);
  setPhysicConfig(sColumnRight, config->columnLeft.physicConfig);

  auto endArea = cocos2d::Node::create();
  setNodeConfig(endArea, config->endArea.nodeConfig);
  setPhysicConfig(endArea, config->endArea.physicConfig);

  cocos2d::Label* highScoreLabel = cocos2d::Label::create();
  setLabelConfig(highScoreLabel, config->highScoreLabel);

  cocos2d::Label* levelLabel = cocos2d::Label::create();
  setLabelConfig(levelLabel, config->levelLabel);

  cocos2d::Label* scoreLabel = cocos2d::Label::create();
  setLabelConfig(scoreLabel, config->scoreLabel);

  this->addChild(vaus);
  this->addChild(energyBall);
  this->addChild(columnUp);
  this->addChild(columnLeft);
  this->addChild(sColumnLeft);
  this->addChild(columnRight);
  this->addChild(sColumnRight);
  this->addChild(highScoreLabel);
  this->addChild(levelLabel);
  this->addChild(scoreLabel);
  this->addChild(endArea);

  syncLevel();

  return true;
}

void
Arkanoid::ActionScene::syncLevel() {
  auto levelManager = gameDIContainer.getSingle<Manager::LevelManager>();

  levelManager->createLevel(this);
}

cocos2d::Scene*
Arkanoid::ActionScene::createScene() {
  return ActionScene::create();
}
