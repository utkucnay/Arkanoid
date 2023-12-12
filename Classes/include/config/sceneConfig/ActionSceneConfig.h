#ifndef __ACTION_SCENE_CONFIG_H__
#define __ACTION_SCENE_CONFIG_H__

enum class Priorty {
  Background,
  Foreground,
  UI
};

#include "cocos2d.h"
#include "resource/Resource.h"
#include "config/Cocos2dConfig.h"
#include "config/actorConfig/ColumnConfig.h"

struct ActionSceneConfig {
  NodeConfig vaus;
  NodeConfig energyBall;

  ColumnConfig columnLeft;
  ColumnConfig columnUp;
  ColumnConfig columnRight;

  NodeConfig field;

  LabelConfig highScoreLabel;
  LabelConfig levelLabel;
  LabelConfig scoreLabel;
};


static std::shared_ptr<ActionSceneConfig> getActionSceneConfig() {
  std::shared_ptr<ActionSceneConfig> actionSceneConfig;
  actionSceneConfig = std::make_shared<ActionSceneConfig>();

  actionSceneConfig->vaus.pos = cocos2d::Vec2(104, 98);
  actionSceneConfig->vaus.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->vaus.positionZ = (int)Priorty::Foreground;

  actionSceneConfig->energyBall.pos = cocos2d::Vec2(104, 110);
  actionSceneConfig->energyBall.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->energyBall.positionZ = (int)Priorty::Foreground;

  actionSceneConfig->columnLeft.nodeConfig.pos = cocos2d::Vec2(8, 306);
  actionSceneConfig->columnLeft.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnLeft.nodeConfig.positionZ = (int)Priorty::Background;
  actionSceneConfig->columnLeft.physicConfig.sizeBox = cocos2d::Size(8, 232);
  actionSceneConfig->columnLeft.physicConfig.isDynamic = false;
  actionSceneConfig->columnLeft.physicConfig.bitmask = 0xFFFFFFFF;

  actionSceneConfig->columnUp.nodeConfig.pos = cocos2d::Vec2(16, 306);
  actionSceneConfig->columnUp.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnUp.nodeConfig.positionZ = (int)Priorty::Background;
  actionSceneConfig->columnUp.physicConfig.sizeBox = cocos2d::Size(176, 8);
  actionSceneConfig->columnUp.physicConfig.isDynamic = false;
  actionSceneConfig->columnUp.physicConfig.bitmask = 0xFFFFFFFF;

  actionSceneConfig->columnRight.nodeConfig.pos = cocos2d::Vec2(192, 306);
  actionSceneConfig->columnRight.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnRight.nodeConfig.positionZ = (int)Priorty::Background;
  actionSceneConfig->columnRight.physicConfig.sizeBox = cocos2d::Size(8, 232);
  actionSceneConfig->columnRight.physicConfig.isDynamic = false;
  actionSceneConfig->columnRight.physicConfig.bitmask = 0xFFFFFFFF;

  actionSceneConfig->field.pos = cocos2d::Vec2(16, 298);
  actionSceneConfig->field.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->field.positionZ = (int)Priorty::Background;

  actionSceneConfig->highScoreLabel.nodeConfig.pos = cocos2d::Vec2(120, 352);
  actionSceneConfig->highScoreLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->highScoreLabel.nodeConfig.positionZ = (int)Priorty::UI;
  actionSceneConfig->highScoreLabel.text = "High Score";
  actionSceneConfig->highScoreLabel.size = 10;
  actionSceneConfig->highScoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  actionSceneConfig->levelLabel.nodeConfig.pos = cocos2d::Vec2(66, 352);
  actionSceneConfig->levelLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->levelLabel.nodeConfig.positionZ = (int)Priorty::UI;
  actionSceneConfig->levelLabel.text = "Level";
  actionSceneConfig->levelLabel.size = 10;
  actionSceneConfig->levelLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  actionSceneConfig->scoreLabel.nodeConfig.pos = cocos2d::Vec2(8, 352);
  actionSceneConfig->scoreLabel.nodeConfig.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->scoreLabel.nodeConfig.positionZ = (int)Priorty::UI;
  actionSceneConfig->scoreLabel.text = "Score";
  actionSceneConfig->scoreLabel.size = 10;
  actionSceneConfig->scoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  return actionSceneConfig;
}

#endif
