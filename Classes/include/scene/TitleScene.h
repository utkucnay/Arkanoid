#ifndef __TITLE_SCENE_H__
#define __TITLE_SCENE_H__

#include "cocos2d.h"
#include "component/InputHandleComponent.h"
#include "scene/Scene.h"

namespace Arkanoid {
  class TitleScene : public Arkanoid::Scene {
  public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(TitleScene);
  public:
    void onEnter() override;
  private:
    void onTap(const Components::InputHandle& handle);

  private:
    std::shared_ptr<Components::InputHandleComponent> _inputHandleComponent;
    bool bIsFirstTap{true};
  };
}

#endif
