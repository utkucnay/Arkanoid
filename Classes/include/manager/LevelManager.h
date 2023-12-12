#ifndef __LEVEL_MANAGER_H__
#define __LEVEL_MANAGER_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid::Manager {
  class LevelManager {
  public:
    void nextLevel() {
      _level++;
      _eventDispatcher->dispatchCustomEvent("NextLevel");
    };

    void resetLevel() {
      _level = 0;
      _eventDispatcher->dispatchCustomEvent("ResetLevel");
    };

    void inject(const DI::DIContainer& diContainer) {
      _eventDispatcher = diContainer.getCocosSingle<cocos2d::Director>()->getEventDispatcher();
    }

  private:
    uint8_t _level{0};
    cocos2d::EventDispatcher* _eventDispatcher;
  };
}
#endif
