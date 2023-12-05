#ifndef __TITLE_RESOURCE_H__
#define __TITLE_RESOURCE_H__

#include "cocos2d.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  inline static cocos2d::Sprite*
  createTitleSprite() {
    return createPixelSprite("Title/Icon.png");
  }

  inline static cocos2d::Sprite*
  createTaitoSprite() {
    return createPixelSprite("Title/TAITO.png");
  }
}

#endif

