#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "cocos2d.h"
#include "ArkanoidCore.h"
#include "state/State.h"

namespace Arkanoid::State{
  class StateMachine {
  public:
    StateMachine();
    ~StateMachine();

  public:
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

  private:
    std::unordered_map<std::string, Ref<IState>> m_stateMap;
    WeakRef<IState> currentState;
  };
}

#endif
