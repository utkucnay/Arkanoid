#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include "resource/VausResource.h"
#include "resource/PillResource.h"
#include "resource/BlockResource.h"
#include "resource/FieldResource.h"
#include "resource/TitleResource.h"

namespace Arkanoid::Resource {
  static cocos2d::Sprite*
  createEnergyBall() {
    return cocos2d::PixelSprite::create("Energy-Ball.png");
  }

  static std::string getTTFFontFileName() { return "fonts/Pixel-Nes.ttf"; }
}

#endif
