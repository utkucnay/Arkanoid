#ifndef __VAUS_H__
#define __VAUS_H__

#include "cocos2d.h"
#include "component/Component.h"
#include "component/TargetMoveComponent.h"
#include "diContainer/DIContainer.h"
#include "state/StateMachine.h"
#include "component/InputHandleComponent.h"
#include "component/HealthComponent.h"

namespace Arkanoid {
  class Vaus : public cocos2d::Node {
  public:
    bool init() override;
    CREATE_FUNC(Vaus);

  public:
    void onEnter() override;
    void update(float delta) override;

  public:
    void inject(const DI::DIContainer& diContainer);

  private:
    void onMove(const Components::InputHandle& inputHandle);

  private:
    std::array<cocos2d::RefPtr<cocos2d::Sprite>, 6> _vausParts;
    std::array<cocos2d::RefPtr<cocos2d::Sprite>, 4> _vausAttackParts;
    std::unique_ptr<StateMachine> _stateMachine;

  private:
    std::shared_ptr<Components::HealthComponent>        _healthComponent;
    std::shared_ptr<Components::InputHandleComponent>   _inputHandleComponent;
    std::shared_ptr<Components::TargetMoveComponent>    _targetMoveComponent;
  };
}

#endif
