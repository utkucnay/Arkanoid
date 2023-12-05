#ifndef __PILL_RESOURCE_H__
#define __PILL_RESOURCE_H__

#include "cocos2d.h"
#include "resource/ResourceHelper.h"

namespace Arkanoid::Resource {
  static cocos2d::Animation*
  createBreakPillAnim() {
    return createAnimation("Pill/Break.plist", "Break-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createCatchPillAnim() {
    return createAnimation("Pill/Catch.plist", "Catch-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createDisruptPillAnim() {
    return createAnimation("Pill/Disrupt.plist", "Disrupt-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createExpandPillAnim() {
    return createAnimation("Pill/Expand.plist", "Expand-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createLaserPillAnim() {
    return createAnimation("Pill/Laser.plist", "Laser-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createPlayerPillAnim() {
    return createAnimation("Pill/Player.plist", "Player-%d.png", 1, 6);
  }

  static cocos2d::Animation*
  createSlowPillAnim() {
    return createAnimation("Pill/Slow.plist", "Slow-%d.png", 1, 6);
  }
}

#endif
