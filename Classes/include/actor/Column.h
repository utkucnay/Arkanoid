#ifndef __COLUMN_H__
#define __COLUMN_H__

#include "actor/IHit.h"
#include "cocos2d.h"
#include "component/AnimationComponent.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid {
  class Column : public cocos2d::Node, public IHit {
  public:
    bool init() override;
    CREATE_FUNC(Column);

  public:
    void setSpriteAndAnim(cocos2d::Sprite& sprite,
        cocos2d::Animation* animation /*In*/);

    void inject(const DI::DIContainer& diContainer);

    inline void hit(const cocos2d::Node& node) override {
      if(_hitAnimation->hasAnim())
        _hitAnimation->animate();
    }

  private:
    cocos2d::Sprite* _sprite;
    std::shared_ptr<Components::AnimationComponent> _hitAnimation;
  };
}
#endif
