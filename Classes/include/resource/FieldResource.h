#ifndef __FIELD_RESOURCE_H__
#define __FIELD_RESOURCE_H__

#include "cocos2d.h"
#include "cocos2dx-extansion/PixelSprite.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  static cocos2d::Sprite*
  createBlueField() {
    return createPixelSprite("Field/Blue.png");
  }

  static cocos2d::Sprite*
  createCyanField() {
    return createPixelSprite("Field/Cyan.png");
  }

  static cocos2d::Sprite*
  createGreenField() {
    return createPixelSprite("Field/Green.png");
  }

  static cocos2d::Sprite*
  createOrangeField() {
    return createPixelSprite("Field/Orange.png");
  }

  static cocos2d::Sprite*
  createColumnLeft() {
    return createPixelSprite("Field/Column-Left.png");
  }

  static cocos2d::Sprite*
  createColumnRight() {
    return createPixelSprite("Field/Column-Right.png");
  }

  static cocos2d::Sprite*
  createColumnUp() {
    return createPixelSprite("Field/Column-Up.png");
  }

  static cocos2d::Animation*
  createDoorOpenAnim() {
    return createAnimation("Field/Door-Anim.plist", "Door-%d.png", 1, 4);
  }

  static cocos2d::Animation*
  createDoorBreakAnim() {
    return createAnimation("Field/Door-Break.plist", "DoorDoor-%d.png", 1, 3);
  }

  static cocos2d::Animation*
  createColumnLeftHitAnim() {
    return createAnimation("Field/Column-Left-Hit.plist", "Column-Left-%d.png", 1, 5);
  }

  static cocos2d::Animation*
  createColumnRightHitAnim() {
    return createAnimation("Field/Column-Right-Hit.plist", "Column-Right-%d.png", 1, 5);
  }

  static cocos2d::Animation*
  createColumnUpHitAnim() {
    return createAnimation("Field/Column-Up-Hit.plist", "Column-Up-%d.png", 1, 5);
  }
}

#endif
