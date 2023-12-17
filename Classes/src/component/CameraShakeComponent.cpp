#include "component/CameraShakeComponent.h"
#include "2d/CCActionEase.h"
#include "2d/CCTweenFunction.h"

void
Arkanoid::Components::CameraShakeComponent::inject(
    const DI::DIContainer& diContainer)
{
  _director = diContainer.getCocosSingle<cocos2d::Director>();
}

void
Arkanoid::Components::CameraShakeComponent::shake(
    const cocos2d::Vec2& dir,
    float power)
{
  auto camera = _director->getRunningScene()->getDefaultCamera();
  if(camera->getNumberOfRunningActionsByTag(11) != 0) {
    camera->stopActionByTag(11);
    camera->setPosition(cocos2d::Vec2());
  }
  auto l1 = cocos2d::MoveTo::create(.2f, dir * power * 20);
  auto l2 = cocos2d::MoveTo::create(.6f, cocos2d::Vec2());
  auto bounceL2 = cocos2d::EaseBounceOut::create(l2);
  _sequance = cocos2d::Sequence::create(l1, bounceL2, NULL);
  _sequance->setTag(11);
  camera->runAction(_sequance);
}
