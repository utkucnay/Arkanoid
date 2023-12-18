#ifndef __ACTION_SCENE_H__
#define __ACTION_SCENE_H__

#include "cocos2d.h"
#include "manager/GameManager.h"
#include "scene/Scene.h"

namespace Arkanoid {
  class ActionScene : public Arkanoid::Scene {
  public:
    static cocos2d::Scene* createScene();
    bool init() override;
    CREATE_FUNC(ActionScene);

    void update(float delta) override;
    void onExit() override;
  private:
    void syncLevel();
    cocos2d::Node* _bricks;
    Manager::GameManager* _gameManager;
  };
}

#endif
