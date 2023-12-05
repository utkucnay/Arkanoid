#ifndef __PIXEL_SPRITE_H__
#define __PIXEL_SPRITE_H__

#include "cocos2d.h"
#include "renderer/CCTexture2D.h"

namespace cocos2d {
  class PixelSprite : public cocos2d::Sprite {
    bool initWithTexture (
        cocos2d::Texture2D* texture,
        const cocos2d::Rect& rect,
        bool rotated)
    {
      bool r = cocos2d::Sprite::initWithTexture(texture, rect, rotated);
      getTexture()->setAliasTexParameters();
      return r;
    }
  };
}
#endif
