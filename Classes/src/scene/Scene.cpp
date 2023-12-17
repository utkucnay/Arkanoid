#include "scene/Scene.h"

void
Arkanoid::Scene::setNodeConfig(
    cocos2d::Node* node,
    const NodeConfig& nodeConfig)
{
  node->setPosition(nodeConfig.pos);
  node->setAnchorPoint(nodeConfig.anchorPoint);
  node->setGlobalZOrder(nodeConfig.positionZ);
  node->setTag(nodeConfig.tag);
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

void
Arkanoid::Scene::setPhysicConfig(
    cocos2d::Node* node,
    const PhysicConfig& physicsConfig)
{
  auto body = cocos2d::PhysicsBody::createBox(physicsConfig.sizeBox);
  body->setContactTestBitmask(physicsConfig.bitmask);
  body->setDynamic(physicsConfig.isDynamic);
  node->addComponent(body);
}
