#ifndef __ENERGY_BALL_H__
#define __ENERGY_BALL_H__

#include "cocos2d.h"
#include "component/MoveComponent.h"
#include "diContainer/DIContainer.h"
#include "manager/LevelManager.h"
#include "manager/SceneManager.h"
#include "manager/TagManager.h"

namespace Arkanoid {
class EnergyBall : public cocos2d::Node {
public:
  bool init() override;
  CREATE_FUNC(EnergyBall);

public:
  void onEnter() override;
  void update(float delta) override;
  bool onContactBegin(cocos2d::PhysicsContact &contact);
  void onContact(cocos2d::PhysicsContact &contact, cocos2d::Node &node);
  void inject(const DI::DIContainer &diContainer);

private:
  cocos2d::Vec2 bounce(cocos2d::PhysicsContact &contact);
  cocos2d::Vec2 hitVaus(cocos2d::Node &vaus);

private:
  std::shared_ptr<Components::MoveComponent> _moveComponent;
  cocos2d::Sprite* _sprite;
  Manager::TagManager* _tagManager;
  Manager::LevelManager* _levelManager;
  Manager::SceneManager* _sceneManager;
};
} // namespace Arkanoid

#endif
