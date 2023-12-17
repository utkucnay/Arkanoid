#include "scene/ShowLevelScene.h"
#include "2d/CCActionInstant.h"
#include "2d/CCActionInterval.h"
#include "GameInstall.h"
#include "ccUTF8.h"
#include "manager/LevelManager.h"
#include "manager/SceneManager.h"
#include "resource/Resource.h"
#include "scene/ActionScene.h"

bool
Arkanoid::ShowLevelScene::init() {
  auto levelManager = gameDIContainer.getSingle<Manager::LevelManager>();
  auto sceneManager = gameDIContainer.getSingle<Manager::SceneManager>();

  auto levelstr = cocos2d::StringUtils::format("Level: %d", levelManager->getLevel() + 1);
  auto levelLabel = cocos2d::Label::createWithTTF(
      Resource::getTTFFontFileName(), levelstr);
  levelLabel->setPosition(cocos2d::Vec2(80, 186));

  auto dt = cocos2d::DelayTime::create(2);
  auto cb = cocos2d::CallFunc::create([=] () {
        sceneManager->changeScene<ActionScene>();
      });

  runAction(cocos2d::Sequence::create(dt, cb, NULL));
  this->addChild(levelLabel);
  return true;
}

cocos2d::Scene*
Arkanoid::ShowLevelScene::createScene() {
  return ShowLevelScene::create();
}
