#ifndef __ENERGY_BALL_H__
#define __ENERGY_BALL_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"
#include "manager/GameManager.h"
#include "manager/TagManager.h"
#include "component/CameraShakeComponent.h"
#include "component/MoveComponent.h"
#include "component/SpriteSqueezeComponent.h"

namespace Arkanoid {
  class EnergyBall : public cocos2d::Node {
  public:
    bool init() override;
    CREATE_FUNC(EnergyBall);

  public:
    virtual void onEnter() override;
    virtual void update(float delta) override;
    bool onContactBegin(cocos2d::PhysicsContact &contact);
    void inject(const DI::DIContainer &diContainer);

  private:
    virtual void onContact(cocos2d::PhysicsContact &contact, cocos2d::Node &node);
    cocos2d::Vec2 onBounce(cocos2d::PhysicsContact &contact);
    cocos2d::Vec2 hitVaus(cocos2d::Node &vaus);
    void callNodeHitFunc(cocos2d::Node& node);
    void onOutArena();
    void calRotate(const cocos2d::Vec2& dir, float delta);
    void createHitSequance();

  private:
    std::shared_ptr<Components::MoveComponent> _moveComponent;
    std::shared_ptr<Components::SpriteSqueeze> _spriteSqueeze;
    std::shared_ptr<Components::CameraShakeComponent> _cameraShakeComponent;
    cocos2d::RefPtr<cocos2d::Sequence> _hitAnimSeq;
    cocos2d::Sprite* _sprite;
    cocos2d::MotionStreak* _streak;
    Manager::TagManager* _tagManager;
    Manager::GameManager* _gameManager;
  };
}

#endif
