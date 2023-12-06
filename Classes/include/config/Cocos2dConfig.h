#ifndef __COCOS_CONFIG_H__
#define __COCOS_CONFIG_H__

#include "cocos2d.h"

struct NodeConfig {
  cocos2d::Vec2 pos;
  cocos2d::Vec2 anchorPoint;
  float         positionZ;
};

struct LabelConfig : NodeConfig {
  std::string text;
  std::string fontFile;
  float size;
};

#endif
