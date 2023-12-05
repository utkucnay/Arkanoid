#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "state/State.h"
#include "cocos2d.h"
#include <memory>


namespace Arkanoid{
  class IState;

  class StateMachine {
  public:
    StateMachine();
    ~StateMachine();

  public:
    void addFirstState(std::shared_ptr<IState> state);

    void addState(std::shared_ptr<IState> state);

    void removeState(std::shared_ptr<IState> state);

    void changeState(std::shared_ptr<IState> state);

    inline void update() {
      currentState.lock()->update();
    }

    inline std::weak_ptr<IState> getCurrentState() const {
      return currentState;
    };

  protected:
    std::unordered_map<std::string, std::shared_ptr<IState>> m_stateMap;
    std::weak_ptr<IState> currentState;
  };
}

#endif
