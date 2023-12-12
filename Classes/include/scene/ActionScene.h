#ifndef __ACTION_SCENE_H__
#define __ACTION_SCENE_H__

#include "cocos2d.h"
#include "scene/Scene.h"

namespace Arkanoid {
  class ActionScene : public Arkanoid::Scene {
  public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(ActionScene);
  };
}

#endif
