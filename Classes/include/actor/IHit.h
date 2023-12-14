#ifndef __I_HIT_ANIMATION_H__
#define __I_HIT_ANIMATION_H__

#include "cocos2d.h"

class IHit {
public:
  virtual void hit(const cocos2d::Node& node) = 0;
};

#endif
