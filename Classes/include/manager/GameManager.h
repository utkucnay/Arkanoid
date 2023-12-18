#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "actor/Vaus.h"
#include "cocos2d.h"
#include "diContainer/DIContainer.h"
#include "manager/LevelManager.h"
#include "manager/SceneManager.h"

namespace Arkanoid {
  class Vaus;
}

namespace Arkanoid::Manager {
  class GameManager {
  public:
    void inject(const DI::DIContainer& diContainer);

    void startSession();
    void endSession();
    void onBallOutField();
    void onEndDestroyVaus(bool isDeath);
    void checkVausHealth(bool isDeath);
    void requestNextLevel();

    inline void setVaus(Vaus* vaus) { _vaus = vaus; }

  private:
    Vaus* _vaus;
    int _vausHealth{0};
    cocos2d::Director* _director;
    SceneManager* _sceneManager;
    LevelManager* _levelManager;
  };
}
#endif
