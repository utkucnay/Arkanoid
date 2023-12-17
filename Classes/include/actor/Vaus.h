#ifndef __VAUS_H__
#define __VAUS_H__

#include "cocos2d.h"
#include "actor/IHit.h"
#include "diContainer/DIContainer.h"
#include "manager/GameManager.h"
#include "state/StateMachine.h"
#include "component/AnimationComponent.h"
#include "component/Component.h"
#include "component/LimitedTargetMoveComponent.h"
#include "component/SpriteSqueezeComponent.h"
#include "component/TargetMoveComponent.h"
#include "component/InputHandleComponent.h"
#include "component/HealthComponent.h"

namespace Arkanoid::Manager {
  class GameManager;
}

namespace Arkanoid {
  class Vaus : public cocos2d::Node, public IHit {
  public:
    bool init() override;
    CREATE_FUNC(Vaus);
    ~Vaus() {
    }

  public:
    void onEnter() override;
    void update(float delta) override;
    void onExit() override;
  public:
    void inject(const DI::DIContainer& diContainer);
    void hit(const cocos2d::Node& node) override;
    void startDestroyVaus();
    void endDestroyVaus();
    void energyBallHitSomething(cocos2d::EventCustom* event);
  private:
    void onMove(const Components::InputHandle& inputHandle);

  private:
    cocos2d::Sprite* _sprite;
    std::unique_ptr<StateMachine> _stateMachine;
    Manager::GameManager* _gameManager;

  private:
    std::shared_ptr<Components::HealthComponent>            _healthComponent;
    std::shared_ptr<Components::InputHandleComponent>       _inputHandleComponent;
    std::shared_ptr<Components::LimitedTargetMoveComponent> _targetMoveComponent;
    std::shared_ptr<Components::AnimationComponent>         _destroyAnimComponent;
    std::shared_ptr<Components::SpriteSqueeze>              _spriteSqueeze;
  };
}

#endif
