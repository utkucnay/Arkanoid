#include "scene/TitleScene.h"
#include "GameInstall.h"
#include "component/InputHandleComponent.h"
#include "diContainer/DIContainer.h"
#include "resource/Resource.h"
#include "scene/ActionScene.h"
#include "component/MouseInputHandleComponent.h"
#include "component/MobileInputHandleComponent.h"
#include "config/sceneConfig/TitleSceneConfig.h"
#include <iostream>

bool
Arkanoid::TitleScene::init() {

  if(!Scene::init()) {
    return false;
  }

  auto config = getTitleSceneConfig();

  auto titleSprite = Resource::createTitleSprite();
  setNodeConfig(titleSprite, config->title);

  auto taitoSprite = Resource::createTaitoSprite();
  setNodeConfig(taitoSprite, config->taito);

  auto infoText = cocos2d::Label::create();
  setLabelConfig(infoText, config->infoLabel);

  DI::DIContainer diContainer;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
  diContainer.addFactory<Components::InputHandleComponent, Components::MouseInputHandleComponent>();
#else
  diContainer.addFactory<Components::InputHandleComponent, Components::MobileInputHandleComponent>();
#endif

  _inputHandleComponent = diContainer.getFactory<Components::InputHandleComponent>();
  _inputHandleComponent->setOwner(*this);

  _gameManager = gameDIContainer.getSingle<Manager::GameManager>();
  this->addChild(titleSprite);
  this->addChild(taitoSprite);
  this->addChild(infoText);
  return true;
};

void
Arkanoid::TitleScene::onEnter() {
  Scene::onEnter();
  _inputHandleComponent->onBegan = CC_CALLBACK_1(Arkanoid::TitleScene::onTap, this);
  _inputHandleComponent->onEnter();
}

void
Arkanoid::TitleScene::onTap(const Components::InputHandle& handle) {
  if(!bIsFirstTap) {
    return;
  }
  bIsFirstTap = false;

  _gameManager->startSession();
}

cocos2d::Scene*
Arkanoid::TitleScene::createScene() {
  return TitleScene::create();
}
