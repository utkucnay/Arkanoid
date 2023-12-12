#ifndef __INPUT_HANDLE_COMPONENT_H__
#define __INPUT_HANDLE_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"


namespace Arkanoid::Components {
  struct InputHandle {
    cocos2d::Vec2 location;
    cocos2d::Vec2 startLocation;
    cocos2d::Vec2 prevLocation;
    cocos2d::Vec2 delta;
  };

  class InputHandleComponent : public Component {
  public:
    std::function<void(const InputHandle&)> onBegan;
    std::function<void(const InputHandle&)> onMoved;
    std::function<void(const InputHandle&)> onEnded;

  protected:
    InputHandle _inputHandle;
  };
}

#endif
