#ifndef __MOVE_COMPONENT_H__
#define __MOVE_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"

namespace Arkanoid::Components {
  class MoveComponent : public Component {
  public:
    virtual void onEnter()            override;
    virtual void update(float delta)  override;
    virtual void onExit()             override;

  public:
    virtual void move(float delta);
    virtual void setVelocity(const cocos2d::Vec2& vel);
    virtual void setSpeed(float speed);
    virtual void setDir(const cocos2d::Vec2& dir);

    inline cocos2d::Vec2  getVelocity()   const { return _dir * _speed; }
    inline float          getSpeed()      const { return _speed; }
    inline cocos2d::Vec2  getDir()        const { return _dir.getNormalized(); }

  protected:
    cocos2d::Vec2 _dir;
    float         _speed;
  };
}

#endif
