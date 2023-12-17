#include "component/MobileInputHandleComponent.h"
#include "component/InputHandleComponent.h"

void
Arkanoid::Components::MobileInputHandleComponent::onEnter() {
  auto eventDispatcher = _owner->getEventDispatcher();

  auto listener = cocos2d::EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(
      Arkanoid::Components::MobileInputHandleComponent::onTouchBegan,
      this);

  listener->onTouchMoved = CC_CALLBACK_2(
      Arkanoid::Components::MobileInputHandleComponent::onTouchMoved,
      this);

  listener->onTouchEnded = CC_CALLBACK_2(
      Arkanoid::Components::MobileInputHandleComponent::onTouchEnded,
      this);

  eventDispatcher->addEventListenerWithSceneGraphPriority(listener, _owner);
}

void
Arkanoid::Components::MobileInputHandleComponent::syncInputHandle(
    cocos2d::Touch* touch)
{
  _inputHandle.delta          = touch->getDelta();
  _inputHandle.location       = touch->getLocation();
  _inputHandle.prevLocation   = touch->getPreviousLocation();
  _inputHandle.startLocation  = touch->getStartLocation();
}

bool
Arkanoid::Components::MobileInputHandleComponent::onTouchBegan(
    cocos2d::Touch* touch,
    cocos2d::Event* event)
{
  syncInputHandle(touch);
  if(onBegan)
    onBegan(_inputHandle);
  return true;
}

void
Arkanoid::Components::MobileInputHandleComponent::onTouchMoved(
    cocos2d::Touch* touch,
    cocos2d::Event* event)
{
  syncInputHandle(touch);
  if(onMoved)
    onMoved(_inputHandle);
}

void
Arkanoid::Components::MobileInputHandleComponent::onTouchEnded(
    cocos2d::Touch* touch,
    cocos2d::Event* event)
{
  syncInputHandle(touch);
  if(onEnded)
    onEnded(_inputHandle);
}
