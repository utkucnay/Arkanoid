#ifndef __STATE_H__
#define __STATE_H__

#include "state/StateMachine.h"
#include "cocos2d.h"
#include "ArkanoidCore.h"

namespace Arkanoid::State {
  class StateMachine;

  class IState {
  public:
    IState(Ref<StateMachine> stateMachine) { _stateMachine = stateMachine; }
    inline virtual std::string getName() const  = 0;
    virtual void onEnter()                      = 0;
    virtual void update()                       = 0;
    virtual void onExit()                       = 0;
  protected:
    WeakRef<StateMachine> _stateMachine;
  };
}

#endif // !__STATE_H__
