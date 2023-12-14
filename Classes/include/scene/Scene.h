#ifndef __A_SCENE_H__
#define __A_SCENE_H__

#include "cocos2d.h"
#include "config/Cocos2dConfig.h"

namespace Arkanoid {
  class Scene : public cocos2d::Scene {
  protected:
    virtual void setNodeConfig(cocos2d::Node* node, const NodeConfig& nodeConfig);
    virtual void setLabelConfig(cocos2d::Label* node, const LabelConfig& nodeConfig);
    virtual void setPhysicConfig(cocos2d::Node* node, const PhysicConfig& physicsConfig);
  };
}


#endif
