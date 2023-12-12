#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid::Manager {
  class SceneManager {
  public:
    template<class T>
    void addScene() {
      if(initScene.empty())
          initScene = typeid(T).name();
      _sceneMap[typeid(T).name()] = T::createScene;
    };

    void setScene() {
      _director->runWithScene(_sceneMap[initScene]());
    }

    template<class T>
    void changeScene() {
      _director->replaceScene(_sceneMap[typeid(T).name()]());
    };

    void inject(const DI::DIContainer& diContainer) {
      _director = diContainer.getCocosSingle<cocos2d::Director>();
    }
  private:
    std::unordered_map<std::string, std::function<cocos2d::Scene*(void)>> _sceneMap;
    std::string initScene;
    cocos2d::Director* _director;
  };
}

#endif
