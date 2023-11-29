#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "state/State.h"
#include "cocos2d.h"
#include "ArkanoidCore.h"


namespace Arkanoid::State{
  class IState;

  class StateMachine {
  public:
    StateMachine();
    ~StateMachine();

  public:
    void addFirstState(Ref<IState> state);

    void addState(Ref<IState> state);

    void removeState(Ref<IState> state);

    void changeState(Ref<IState> state);

    inline void update() {
      getCurrentState().lock()->update();
    }

    inline WeakRef<IState> getCurrentState() const {
      assert(nullptr != currentState.lock().get());
      return currentState;
    };

  protected:
    std::unordered_map<std::string, Ref<IState>> m_stateMap;
    WeakRef<IState> currentState;
  };
}

#endif
