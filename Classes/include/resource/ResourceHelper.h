#ifndef __RESORCE_HELPER_H__
#define __RESORCE_HELPER_H__

#include "2d/CCSpriteFrame.h"
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

    if(!spriteFrameInstance->isSpriteFramesWithFileLoaded(plist))
      spriteFrameInstance->addSpriteFramesWithFile(plist);

    cocos2d::Vector<cocos2d::SpriteFrame*> spriteFrames;
    for(int i = bIndex; i <= eIndex; i++) {
      std::string str = cocos2d::StringUtils::format(format.c_str(), i);
      auto spriteFrame = spriteFrameInstance->getSpriteFrameByName(str);
      spriteFrames.pushBack(spriteFrame);
    }
    auto anim = cocos2d::Animation::createWithSpriteFrames(spriteFrames);
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
