#ifndef __COCOS_CONFIG_H__
#define __COCOS_CONFIG_H__

#include "cocos2d.h"

struct NodeConfig {
  cocos2d::Vec2 pos;
  cocos2d::Vec2 anchorPoint;
  int           tag;
  float         positionZ;
};

struct LabelConfig {
  std::string text;
  std::string fontFile;
  float size;

  NodeConfig nodeConfig;
};

struct PhysicConfig {
  cocos2d::Size sizeBox;
  bool isDynamic;
  int bitmask;
};

struct PhysicNodeConfig {
  NodeConfig nodeConfig;
  PhysicConfig physicConfig;
};

#endif
