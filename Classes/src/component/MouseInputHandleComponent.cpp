#include "component/MouseInputHandleComponent.h"

void
Arkanoid::Components::MouseInputHandleComponent::onEnter() {

  auto mouseListener = cocos2d::EventListenerMouse::create();

  mouseListener->onMouseUp = CC_CALLBACK_1(
      Arkanoid::Components::MouseInputHandleComponent::onMouseUp,
      this);
  mouseListener->onMouseMove = CC_CALLBACK_1(
      Arkanoid::Components::MouseInputHandleComponent::onMouseMove,
      this);
  mouseListener->onMouseDown = CC_CALLBACK_1(
      Arkanoid::Components::MouseInputHandleComponent::onMouseDown,
      this);

  _owner->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
      mouseListener, _owner);
}

void
Arkanoid::Components::MouseInputHandleComponent::syncInputHandle(
    cocos2d::EventMouse* eventMouse)
{
  _inputHandle.delta          = eventMouse->getDelta();
  _inputHandle.location       = eventMouse->getLocation();
  _inputHandle.prevLocation   = eventMouse->getPreviousLocation();
  _inputHandle.startLocation  = eventMouse->getStartLocation();
}

void
Arkanoid::Components::MouseInputHandleComponent::onMouseUp(
    cocos2d::Event* event)
{
  syncInputHandle(static_cast<cocos2d::EventMouse*>(event));
  if(onEnded)
    onEnded(_inputHandle);
  bIsMouseDown = false;
}

void
Arkanoid::Components::MouseInputHandleComponent::onMouseMove(
    cocos2d::Event* event)
{
  syncInputHandle(static_cast<cocos2d::EventMouse*>(event));
  if(bIsMouseDown && onMoved)
    onMoved(_inputHandle);
}

void
Arkanoid::Components::MouseInputHandleComponent::onMouseDown(
    cocos2d::Event* event)
{
  syncInputHandle(static_cast<cocos2d::EventMouse*>(event));
  if(onBegan)
    onBegan(_inputHandle);
  bIsMouseDown = true;
}
