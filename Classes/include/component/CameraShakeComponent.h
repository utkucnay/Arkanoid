#ifndef __CAMERA_SHAKE_COMPONENT_H__
#define __CAMERA_SHAKE_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid::Components {
  class CameraShakeComponent : public Component {
  public:
    virtual void inject(const DI::DIContainer& diContainer);
    virtual void shake(const cocos2d::Vec2& dir, float power);
  private:
    cocos2d::Sequence* _sequance;
    cocos2d::Director* _director;
  };
}

#endif
