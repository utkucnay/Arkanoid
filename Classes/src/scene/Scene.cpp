#include "scene/Scene.h"

void
Arkanoid::Scene::setNodeConfig(
    cocos2d::Node* node,
    const NodeConfig& nodeConfig)
{
  node->setPosition(nodeConfig.pos);
  node->setAnchorPoint(nodeConfig.anchorPoint);
  node->setPositionZ(nodeConfig.positionZ);
}

void
Arkanoid::Scene::setLabelConfig(
    cocos2d::Label* label,
    const LabelConfig& labelConfig)
{
  label->initWithTTF(
      labelConfig.text,
      labelConfig.fontFile,
      labelConfig.size);

  setNodeConfig(label, labelConfig.nodeConfig);
}
