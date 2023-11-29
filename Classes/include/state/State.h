#ifndef __STATE_H__
#define __STATE_H__

#include "cocos2d.h"
#include "ArkanoidCore.h"

#define CREATE_STATE(_TYPE_) = static int kHashName = std::hash<std::string>{}(#_TYPE_)

namespace Arkanoid::State {
  class IState {
  public:
    inline virtual std::string getName() const  = 0;
    virtual void onEnter()                      = 0;
    virtual void update()                       = 0;
    virtual void onExit()                       = 0;
  };
}

#endif // !__STATE_H__
