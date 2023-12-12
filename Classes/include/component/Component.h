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

    virtual void onEnter()            = 0;
    virtual void update(float delta)  = 0;
    virtual void onExit()             = 0;

    inline void setEnabled(bool enabled)  { _enabled = enabled; }
    inline bool getEnabled() const        { return _enabled; }

    inline void setOwner(cocos2d::Node& owner) { _owner = &owner; }
  protected:
    bool            _enabled;
    cocos2d::Node*  _owner;
  };
};

#endif
