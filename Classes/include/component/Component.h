#ifndef __COMPONET_H__
#define __COMPONET_H__

#include "cocos2d.h"

namespace Arkanoid {
  class Component {
  public:
    void tick(float delta) {
      if(getEnabled())
        update(delta);
    }

    virtual void onEnter()            {};
    virtual void update(float delta)  {};
    virtual void onExit()             {};

    inline void setEnabled(bool enabled)  { _enabled = enabled; }
    inline bool getEnabled() const        { return _enabled; }

    inline void setOwner(cocos2d::Node& owner) { _owner = &owner; }
  protected:
    bool            _enabled{true};
    cocos2d::Node*  _owner;
  };
};

#endif
