#ifndef __A_SCENE_H__
#define __A_SCENE_H__

#include "cocos2d.h"
#include "config/Cocos2dConfig.h"

namespace Arkanoid {
  class Scene : public cocos2d::Scene {
  public:
    static void setNodeConfig(cocos2d::Node* node, const NodeConfig& nodeConfig);
    static void setLabelConfig(cocos2d::Label* node, const LabelConfig& nodeConfig);
    static void setPhysicConfig(cocos2d::Node* node, const PhysicConfig& physicsConfig);
  };
}


#endif
