#include "actor/Column.h"
#include "component/AnimationComponent.h"

bool
Arkanoid::Column::init()
{
  return true;
}

void
Arkanoid::Column::inject(const DI::DIContainer& diContainer) {
  if(diContainer.hasFactory<Components::AnimationComponent>()){
    _hitAnimation = diContainer.getFactory<Components::AnimationComponent>();
    _hitAnimation->setOwner(*this);
  }
}

void
Arkanoid::Column::setSpriteAndAnim(
    cocos2d::Sprite& sprite,
    cocos2d::Animation* animation)
{
  if(nullptr != animation)
    _hitAnimation->setAnim(*animation, sprite);
  _sprite = &sprite;
  this->addChild(_sprite);
}
