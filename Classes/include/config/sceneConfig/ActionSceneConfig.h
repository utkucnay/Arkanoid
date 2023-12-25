#ifndef __ACTION_SCENE_CONFIG_H__
#define __ACTION_SCENE_CONFIG_H__

#include "component/MaxHealthComponent.h"
enum class Priorty {
  Background = -1,
  Foreground = 1,
  UI = 2
};

#include "cocos2d.h"
#include "GameInstall.h"
#include "resource/Resource.h"
#include "manager/TagManager.h"
#include "component/CameraShakeComponent.h"
#include "component/HealthComponent.h"
#include "component/AnimationComponent.h"
#include "component/MobileInputHandleComponent.h"
#include "component/InputHandleComponent.h"
#include "component/LimitedTargetMoveComponent.h"
#include "component/MouseInputHandleComponent.h"
#include "component/MoveComponent.h"
#include "component/TargetMoveComponent.h"
#include "config/Cocos2dConfig.h"
#include "config/actorConfig/ColumnConfig.h"
#include "config/actorConfig/EnergyBallConfig.h"
#include "config/actorConfig/VausConfig.h"

struct ActionSceneConfig {
  VausConfig vaus;
  EnergyBallConfig energyBall;

  ColumnConfig columnLeft;
  ColumnConfig columnUp;
  ColumnConfig columnRight;

  PhysicNodeConfig endArea;

  NodeConfig field;

  LabelConfig highScoreLabel;
  LabelConfig levelLabel;
  LabelConfig scoreLabel;
  LabelConfig score;
};


static std::shared_ptr<ActionSceneConfig> getActionSceneConfig() {
  using namespace Arkanoid::Components;
  std::shared_ptr<ActionSceneConfig> cfg;
  cfg = std::make_shared<ActionSceneConfig>();

  auto tagManager = gameDIContainer.
    getSingle<Arkanoid::Manager::TagManager>();

  cfg->vaus.nodeConfig.pos = cocos2d::Vec2(104, 102);
  cfg->vaus.nodeConfig.anchorPoint = cocos2d::Vec2(.5, .5);
  cfg->vaus.nodeConfig.positionZ = (int)Priorty::Foreground;
  cfg->vaus.nodeConfig.tag = tagManager->getTag("Vaus");

  cfg->vaus.physicConfig.sizeBox = cocos2d::Size(32, 8);
  cfg->vaus.physicConfig.isDynamic = false;
  cfg->vaus.physicConfig.bitmask = 0xFFFFFFFF;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || \
    (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)   || \
    (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
  cfg->vaus.diContainer.addFactory<
    InputHandleComponent,
    MouseInputHandleComponent>();
#else
  cfg->vaus.diContainer.addFactory<
    InputHandleComponent,
    MobileInputHandleComponent>();
#endif
  cfg->vaus.diContainer.addFactory<
    LimitedTargetMoveComponent,
    LimitedTargetMoveComponent>();
  cfg->vaus.diContainer.addFactory<
    AnimationComponent,
    AnimationComponent>();
  cfg->vaus.diContainer.addFactory<
    HealthComponent,
    MaxHealthComponent>();
  cfg->vaus.diContainer.addFactory<
    SpriteSqueeze,
    SpriteSqueeze>();

  cfg->energyBall.nodeConfig.pos = cocos2d::Vec2(108, 110);
  cfg->energyBall.nodeConfig.anchorPoint = cocos2d::Vec2(.5, .5);
  cfg->energyBall.nodeConfig.positionZ = (int)Priorty::Foreground;
  cfg->energyBall.nodeConfig.tag = tagManager->getTag("EnergyBall");

  cfg->energyBall.physicConfig.sizeBox = cocos2d::Size(8, 4);
  cfg->energyBall.physicConfig.isDynamic = false;
  cfg->energyBall.physicConfig.bitmask = 0xFFFFFFFF;

  cfg->energyBall.diContainer.addFactory<
    MoveComponent,
    MoveComponent>();
  cfg->energyBall.diContainer.addFactory<
    SpriteSqueeze,
    SpriteSqueeze>();
  cfg->energyBall.diContainer.addFactory<
    CameraShakeComponent,
    CameraShakeComponent>();

  cfg->columnLeft.nodeConfig.pos = cocos2d::Vec2(12, 190);
  cfg->columnLeft.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->columnLeft.nodeConfig.positionZ = (int)Priorty::Foreground;

  cfg->columnLeft.physicConfig.sizeBox = cocos2d::Size(8, 232);
  cfg->columnLeft.physicConfig.isDynamic = false;
  cfg->columnLeft.physicConfig.bitmask = 0xFFFFFFFF;

  cfg->columnLeft.diContainer.addFactory<
    AnimationComponent,
    AnimationComponent>();

  cfg->columnUp.nodeConfig.pos = cocos2d::Vec2(104, 302);
  cfg->columnUp.nodeConfig.anchorPoint = cocos2d::Vec2(0, 0);
  cfg->columnUp.nodeConfig.positionZ = (int)Priorty::Foreground;

  cfg->columnUp.physicConfig.sizeBox = cocos2d::Size(176, 8);
  cfg->columnUp.physicConfig.isDynamic = false;
  cfg->columnUp.physicConfig.bitmask = 0xFFFFFFFF;

  cfg->columnUp.diContainer.addFactory<
    AnimationComponent,
    AnimationComponent>();

  cfg->columnRight.nodeConfig.pos = cocos2d::Vec2(196, 190);
  cfg->columnRight.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->columnRight.nodeConfig.positionZ = (int)Priorty::Foreground;

  cfg->columnRight.physicConfig.sizeBox = cocos2d::Size(8, 232);
  cfg->columnRight.physicConfig.isDynamic = false;
  cfg->columnRight.physicConfig.bitmask = 0xFFFFFFFF;

  cfg->columnRight.diContainer.addFactory<
    AnimationComponent,
    AnimationComponent>();

  cfg->field.pos = cocos2d::Vec2(16, 298);
  cfg->field.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->field.positionZ = (int)Priorty::Background;

  cfg->endArea.nodeConfig.pos = cocos2d::Vec2(104, 70);
  cfg->endArea.nodeConfig.tag = tagManager->getTag("EndArea");

  cfg->endArea.physicConfig.sizeBox = cocos2d::Size(192, 8);
  cfg->endArea.physicConfig.isDynamic = false;
  cfg->endArea.physicConfig.bitmask = 0xFFFFFFFF;

  cfg->highScoreLabel.nodeConfig.pos = cocos2d::Vec2(120, 352);
  cfg->highScoreLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->highScoreLabel.nodeConfig.positionZ = (int)Priorty::UI;

  cfg->highScoreLabel.text = "High Score";
  cfg->highScoreLabel.size = 10;
  cfg->highScoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  cfg->levelLabel.nodeConfig.pos = cocos2d::Vec2(66, 352);
  cfg->levelLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->levelLabel.nodeConfig.positionZ = (int)Priorty::UI;

  cfg->levelLabel.text = "Level";
  cfg->levelLabel.size = 10;
  cfg->levelLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  cfg->scoreLabel.nodeConfig.pos = cocos2d::Vec2(8, 352);
  cfg->scoreLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  cfg->scoreLabel.nodeConfig.positionZ = (int)Priorty::UI;

  cfg->scoreLabel.text = "Score";
  cfg->scoreLabel.size = 10;
  cfg->scoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  cfg->score.nodeConfig.positionZ = (int)Priorty::UI;
  cfg->score.nodeConfig.pos = cocos2d::Vec2(8, 338);
  cfg->score.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);

  return cfg;
}

#endif
