#ifndef __LEVEL_MANAGER_H__
#define __LEVEL_MANAGER_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"
#include "level/Level.h"
#include <cstdint>

namespace Arkanoid::Manager {
  class LevelManager {
  public:
    inline void nextLevel() {
      _level++;
    };

    inline void resetLevel() {
      _level = 0;
    };

    void inject(const DI::DIContainer& diContainer);
    inline void addLevel(const Level& level) { _levels.push_back(level); }
    void createLevel(cocos2d::Scene* scene);
    inline uint8_t getLevel() { return _level; }
  private:
    Brick* createBrick(BrickInfo brickInfo);
    cocos2d::Sprite* createField();

  private:
    uint8_t _level{0};
    cocos2d::EventDispatcher* _eventDispatcher;
    std::vector<Level> _levels;
  };
}
#endif
