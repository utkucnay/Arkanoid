#ifndef __TITLE_SCENE_CONFIG_H__
#define __TITLE_SCENE_CONFIG_H__

#define Background 0
#define Front 1
#define UI 2

#include "cocos2d.h"
#include "resource/Resource.h"
#include "config/Cocos2dConfig.h"

struct TitleSceneConfig {
  NodeConfig title;
  NodeConfig taito;


  LabelConfig infoLabel;
};


static std::shared_ptr<TitleSceneConfig> getTitleSceneConfig() {
  std::shared_ptr<TitleSceneConfig> titleSceneConfig;
  titleSceneConfig = std::make_shared<TitleSceneConfig>();

  titleSceneConfig->title.pos = cocos2d::Vec2(42, 286);
  titleSceneConfig->title.anchorPoint = cocos2d::Vec2(0, 1);
  titleSceneConfig->title.positionZ = UI;

  titleSceneConfig->taito.pos = cocos2d::Vec2(8, 126);
  titleSceneConfig->taito.anchorPoint = cocos2d::Vec2(0, 1);
  titleSceneConfig->taito.positionZ = UI;

  titleSceneConfig->infoLabel.pos = cocos2d::Vec2(57, 204);
  titleSceneConfig->infoLabel.anchorPoint = cocos2d::Vec2(0, 1);
  titleSceneConfig->infoLabel.positionZ = UI;
  titleSceneConfig->infoLabel.text = "Tap The Screen";
  titleSceneConfig->infoLabel.size = 10;
  titleSceneConfig->infoLabel.fontFile = Arkanoid::Resource::getTTFFontFileName();


  return titleSceneConfig;
}

#endif
