#ifndef __VAUS_RESOURCE_H__
#define __VAUS_RESOURCE_H__

#include "cocos2d.h"
#include "cocos2dx-extansion/PixelSprite.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  //Vaus Sprite
  inline static cocos2d::Sprite*
  createVausLeftSprite() {
    return createPixelSprite("Vaus/Vaus-Left.png");
  }

  inline static cocos2d::Sprite*
  createVausMidSprite() {
    return createPixelSprite("Vaus/Vaus-Mid.png");
  }

  inline static cocos2d::Sprite*
  createVausRightSprite() {
    return createPixelSprite("Vaus/Vaus-Right.png");
  }

  inline static cocos2d::Sprite*
  createVausAttackLeftSprite() {
    return createPixelSprite("Vaus/Vaus-Attack-Left.png");
  }

  inline static cocos2d::Sprite*
  createVausAttackMidLeftSprite() {
    return createPixelSprite("Vaus/Vaus-Attack-Mid-Left.png");
  }

  inline static cocos2d::Sprite*
  createVausAttackMidRightSprite() {
    return createPixelSprite("Vaus/Vaus-Attack-Mid-Right.png");
  }

  inline static cocos2d::Sprite*
  createVausAttackRightSprite() {
    return createPixelSprite("Vaus/Vaus-Attack-Right.png");
  }

  inline static cocos2d::Animation*
  createVausExlodeAnim() {
    return createAnimation("Vaus/Vaus-Explode.plist", "Vaus-Explode-%d.png", 1, 3);
  }
}

#endif
