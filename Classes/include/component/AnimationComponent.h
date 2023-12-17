#ifndef __ANIMATION_COMPONENT_H__
#define __ANIMATION_COMPONENT_H__

#include "cocos2d.h"
#include "component/Component.h"

namespace Arkanoid::Components {
  class AnimationComponent : public Component {
  public:
    AnimationComponent() {}
    ~AnimationComponent() {
    }

  public:
    virtual void onEnter()           override {};
    virtual void update(float delta) override {};
    virtual void onExit()            override {};

  public:
    virtual void animate();
    virtual inline void stopAnimate() {
    }

    void setAnim(cocos2d::Animation& animation, cocos2d::Sprite& sprite) {
      _animation = &animation;
      _animation->retain();
      _ownerSprite = &sprite;
    }

    void subsEndAnim(std::function<void(void)> endAnim) { _endAnim = endAnim; }

    inline bool hasAnim() {return nullptr != _animation; }

  private:
    std::function<void(void)> _endAnim;
    cocos2d::Sprite* _ownerSprite{nullptr};
    cocos2d::Animation* _animation{nullptr};
    cocos2d::ActionInterval* _animationAction{nullptr};
  };
}

#endif
