#ifndef __SHOW_LEVEL_SCENE_H__
#define __SHOW_LEVEL_SCENE_H__

#include "cocos2d.h"
#include "scene/Scene.h"

namespace Arkanoid {
  class ShowLevelScene : Scene {
  public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(ShowLevelScene);

  };
}

#endif
