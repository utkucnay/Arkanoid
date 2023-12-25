#ifndef __PILL_H__
#define __PILL_H__

#include "cocos2d.h"
#include "cocos2dx-extension/PixelSprite.h"

namespace Arkanoid {
  class IPill {
  public:
    virtual void getPill();
  };
}

#endif
