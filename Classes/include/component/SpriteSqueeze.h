#ifndef __SPRITE_SQUEEZE_H__
#define __SPRITE_SQUEEZE_H__

#include "cocos2d.h"
#include "component/Component.h"

namespace Arkanoid::Components {
  class SpriteSqueeze : public Component{
  public:
    inline void setScale(float scale) {
      _owner->setScale(
          cocos2d::MathUtil::lerp(
            1,
            _squeeze.x,
            scale),
          cocos2d::MathUtil::lerp(
            1,
            _squeeze.y,
            scale));
    }

    inline void setSqueeze(const cocos2d::Vec2& squeeze) { _squeeze = squeeze; }

  private:
    cocos2d::Vec2 _squeeze;
  };
}

#endif
