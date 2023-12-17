#ifndef __MOUSE_INPUT_HANDLE_COMPONENT_H__
#define __MOUSE_INPUT_HANDLE_COMPONENT_H__

#include "cocos2d.h"
#include "component/InputHandleComponent.h"

namespace Arkanoid::Components {
  class MouseInputHandleComponent : public InputHandleComponent {
  public:
    void onEnter() override;
    void update(float delta) override {}
    void onExit() override {}

  public:
    void onMouseUp  (cocos2d::Event* event);
    void onMouseMove(cocos2d::Event* event);
    void onMouseDown(cocos2d::Event* event);
  private:
    void syncInputHandle(cocos2d::EventMouse* eventMouse);

  private:
    bool bIsMouseDown {false};
  };
}

#endif
