#ifndef __BLOCK_RESOURCE_H__
#define __BLOCK_RESOURCE_H__

#include "cocos2d.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  static cocos2d::Sprite*
  createBlueBlock() {
    return createPixelSprite("Block/Blue.png");
  }

  static cocos2d::Sprite*
  createGoldBlock() {
    return createPixelSprite("Block/Gold.png");
  }

  static cocos2d::Sprite*
  createGreenBlock() {
    return createPixelSprite("Block/Green.png");
  }

  static cocos2d::Sprite*
  createOrangeBlock() {
    return createPixelSprite("Block/Orange.png");
  }

  static cocos2d::Sprite*
  createRedBlock() {
    return createPixelSprite("Block/Red.png");
  }

  static cocos2d::Sprite*
  createSilverBlock() {
    return createPixelSprite("Block/Silver.png");
  }

  static cocos2d::Sprite*
  createVioletBlock() {
    return createPixelSprite("Block/Violet.png");
  }

  static cocos2d::Sprite*
  createWhiteBlock() {
    return createPixelSprite("Block/White.png");
  }

  static cocos2d::Sprite*
  createYellowBlock() {
    return createPixelSprite("Block/Yellow.png");
  }

  static cocos2d::Animation*
  createGoldHitAnim() {
    return createAnimation("Block/Gold-Hit.plist", "Block-Gold-%d.png", 2, 6);
  }

  static cocos2d::Animation*
  createSilverHitAnim() {
    return createAnimation("Block/Silver-Hit.plist", "Block-Silver-%d.png", 2, 6);
  }
}

#endif
