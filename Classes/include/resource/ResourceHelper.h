#ifndef __RESORCE_HELPER_H__
#define __RESORCE_HELPER_H__

#include "cocos2d.h"
#include "cocos2dx-extension/PixelSprite.h"

namespace Arkanoid::Resource {
  static cocos2d::Animation*
  createAnimation(
      const std::string& plist,
      const std::string& format,
      int bIndex, int eIndex)
  {
    static auto spriteFrameInstance = cocos2d::SpriteFrameCache::getInstance();

    if(!spriteFrameInstance->isSpriteFramesWithFileLoaded(plist)) {
      spriteFrameInstance->addSpriteFramesWithFile(plist);
      cocos2d::log("Added plist: %s", plist.c_str());
    }
    else {
      cocos2d::log("Already Added plist: %s", plist.c_str());
    }

    auto anim = cocos2d::Animation::create();
    for(int i = bIndex; i <= eIndex; i++) {
      std::string str = cocos2d::StringUtils::format(format.c_str(), i);
      auto spriteFrame = spriteFrameInstance->getSpriteFrameByName(str);
      assert(nullptr != spriteFrame);
      anim->addSpriteFrame(spriteFrame);
    }
    return anim;
  }

  static cocos2d::Sprite*
  createPixelSprite(const std::string& filename) {
    auto sprite = cocos2d::PixelSprite::create(filename);
    assert(nullptr != sprite);
    return sprite;
  }

  static cocos2d::Sprite*
  createSprite(const std::string& filename) {
    auto sprite = cocos2d::Sprite::create(filename);
    assert(nullptr != sprite);
    return sprite;
  }
}

#endif
