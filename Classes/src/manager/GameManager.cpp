#include "manager/GameManager.h"
#include "actor/Vaus.h"
#include "diContainer/DIContainer.h"
#include "manager/SceneManager.h"
#include "scene/ActionScene.h"
#include "scene/ShowLevelScene.h"
#include "scene/TitleScene.h"

void
Arkanoid::Manager::GameManager::inject(
    const DI::DIContainer& diContainer )
{
  _sceneManager = diContainer.getSingle<SceneManager>();
  _levelManager = diContainer.getSingle<LevelManager>();
  _director = diContainer.getCocosSingle<cocos2d::Director>();
}

void
Arkanoid::Manager::GameManager::startSession() {
  auto* delay = cocos2d::DelayTime::create(2);

  auto* changeScene = cocos2d::CallFunc::create([=] () {
          _sceneManager->changeScene<ShowLevelScene>();
        }
      );

  auto* seq = cocos2d::Sequence::create(delay, changeScene, NULL);
  cocos2d::Director::getInstance()->getRunningScene()->runAction(seq);
}

void
Arkanoid::Manager::GameManager::endSession() {

}

void
Arkanoid::Manager::GameManager::winLevel() {
  _levelManager->nextLevel();
}

void
Arkanoid::Manager::GameManager::onBallOutSpace() {
  if(nullptr == _vaus) {
    cocos2d::log("Vaus dont find");
    return;
  }
  _vaus->startDestroyVaus();
}

void
Arkanoid::Manager::GameManager::endDestroyVaus(bool isDeath) {
  _vaus->removeFromParentAndCleanup(true);
  _director->getRunningScene()->runAction(
      cocos2d::Sequence::create(
        cocos2d::DelayTime::create(1),
        cocos2d::CallFunc::create(CC_CALLBACK_0(Arkanoid::Manager::GameManager::sceneLoad, this, isDeath)),
        NULL));
}

void
Arkanoid::Manager::GameManager::sceneLoad(bool isDeath) {
  if(isDeath) {
    _sceneManager->changeScene<TitleScene>();
  } else {
    _sceneManager->changeScene<TitleScene>();
  }
}
