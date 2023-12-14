#include "scene/ActionScene.h"
#include "GameInstall.h"
#include "resource/Resource.h"
#include "config/sceneConfig/ActionSceneConfig.h"
#include "actor/Vaus.h"
#include "actor/EnergyBall.h"
#include "actor/Column.h"

bool
Arkanoid::ActionScene::init() {

  if(!Scene::init()) {
    return false;
  }
  if(!initWithPhysics()) {
    cocos2d::log("Not init Physics!");
    return false;
  }

  getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_SHAPE);
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

  auto endArea = cocos2d::Node::create();
  setNodeConfig(endArea, config->endArea.nodeConfig);
  setPhysicConfig(endArea, config->endArea.physicConfig);

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
