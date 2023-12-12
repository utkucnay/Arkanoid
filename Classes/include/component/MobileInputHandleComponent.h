#ifndef __MOBILE_INPUT_HANDLE_COMPONENT_H__
#define __MOBILE_INPUT_HANDLE_COMPONENT_H__

#include "cocos2d.h"
#include "component/InputHandleComponent.h"

namespace Arkanoid::Components {
  class MobileInputHandleComponent : public InputHandleComponent {
  public:
    void onEnter() override;
    void update(float delta) override {}
    void onExit() override {}

  public:
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
  private:
    void syncInputHandle(cocos2d::Touch* touch);
  };
}

#endif
