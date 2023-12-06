#ifndef __ACTION_SCENE_CONFIG_H__
#define __ACTION_SCENE_CONFIG_H__

#define Background 0
#define Front 1
#define UI 2

#include "cocos2d.h"
#include "resource/Resource.h"
#include "config/Cocos2dConfig.h"

struct ActionSceneConfig {
  NodeConfig vaus;
  NodeConfig energyBall;

  NodeConfig columnLeft;
  NodeConfig columnUp;
  NodeConfig columnRight;

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
  actionSceneConfig->vaus.positionZ = Front;

  actionSceneConfig->columnLeft.pos = cocos2d::Vec2(8, 306);
  actionSceneConfig->columnLeft.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnLeft.positionZ = Background;

  actionSceneConfig->columnUp.pos = cocos2d::Vec2(16, 306);
  actionSceneConfig->columnUp.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnUp.positionZ = Background;

  actionSceneConfig->columnRight.pos = cocos2d::Vec2(192, 306);
  actionSceneConfig->columnRight.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->columnRight.positionZ = Background;

  actionSceneConfig->field.pos = cocos2d::Vec2(16, 298);
  actionSceneConfig->field.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->field.positionZ = Background;

  actionSceneConfig->highScoreLabel.pos = cocos2d::Vec2(120, 352);
  actionSceneConfig->highScoreLabel.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->highScoreLabel.positionZ = UI;
  actionSceneConfig->highScoreLabel.text = "High Score";
  actionSceneConfig->highScoreLabel.size = 10;
  actionSceneConfig->highScoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  actionSceneConfig->levelLabel.pos = cocos2d::Vec2(66, 352);
  actionSceneConfig->levelLabel.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->levelLabel.positionZ = UI;
  actionSceneConfig->levelLabel.text = "Level";
  actionSceneConfig->levelLabel.size = 10;
  actionSceneConfig->levelLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  actionSceneConfig->scoreLabel.pos = cocos2d::Vec2(8, 352);
  actionSceneConfig->scoreLabel.anchorPoint = cocos2d::Vec2(0, 1);
  actionSceneConfig->scoreLabel.positionZ = UI;
  actionSceneConfig->scoreLabel.text = "Score";
  actionSceneConfig->scoreLabel.size = 10;
  actionSceneConfig->scoreLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();

  return actionSceneConfig;
}

#endif
