#include "scene/ActionScene.h"
#include "actor/Vaus.h"
#include "resource/Resource.h"
#include "config/sceneConfig/ActionSceneConfig.h"

bool
Arkanoid::ActionScene::init() {

  if(!Scene::init()) {
    return false;
  }

  auto config = getActionSceneConfig();

  cocos2d::Node* vaus = Vaus::create();
  setNodeConfig(vaus,config->vaus);

  cocos2d::Node* columnLeft = Resource::createColumnLeft();
  setNodeConfig(columnLeft, config->columnLeft);

  cocos2d::Node* columnUp = Resource::createColumnUp();
  setNodeConfig(columnUp, config->columnUp);

  cocos2d::Node* columnRight = Resource::createColumnRight();
  setNodeConfig(columnRight, config->columnRight);

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
  return true;
}

cocos2d::Scene*
Arkanoid::ActionScene::createScene() {
  return ActionScene::create();
}
