#include "actor/AnimatedBrick.h"
#include "component/AnimationComponent.h"

void
Arkanoid::AnimatedBrick::hit(
    const cocos2d::Node& node)
{
  _healthComponent->decraseHealth(1);
  if(_healthComponent->isDeath()) {
    this->removeFromParent();
  } else {
    _hitAnimComponent->animate();
  }
}


void
Arkanoid::AnimatedBrick::inject(
    const DI::DIContainer& diContainer)
{
  Brick::inject(diContainer);

  if(diContainer.hasFactory<Components::AnimationComponent>()) {
    _hitAnimComponent = diContainer.getFactory<
      Components::AnimationComponent>();
    _hitAnimComponent->setOwner(*this);
  }
}


void
Arkanoid::AnimatedBrick::setAnimAndSprite(
    cocos2d::Animation& animation,
    cocos2d::Sprite& sprite)
{
  setSprite(sprite);
  _hitAnimComponent->setAnim(animation, *_sprite);
}
