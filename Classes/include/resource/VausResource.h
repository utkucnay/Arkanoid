#ifndef __VAUS_RESOURCE_H__
#define __VAUS_RESOURCE_H__

#include "cocos2d.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  //Vaus Sprite
  inline static cocos2d::Sprite*
  createVausSprite() {
    return createPixelSprite("Vaus/Vaus.png");
  }

  inline static cocos2d::Animation*
  createVausExlodeAnim() {
    auto anim = createAnimation("Vaus/Vaus-Explode.plist", "Vaus-Explode-%d.png", 1, 3);
    anim->setDelayPerUnit(.2f);
    anim->setRestoreOriginalFrame(true);
    return anim;
  }
}

#endif
