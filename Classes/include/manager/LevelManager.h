#ifndef __LEVEL_MANAGER_H__
#define __LEVEL_MANAGER_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"
#include "level/Level.h"

namespace Arkanoid::Manager {
  class LevelManager {
  public:
    inline bool nextLevel() {
      _level++;
      bUseBrickSnapshot = false;
      return _level < _levels.size();
    };

    inline void resumeLevel() {
      bUseBrickSnapshot = true;
    }

    inline void resetLevel() {
      _level = 0;
      bUseBrickSnapshot = false;
    };

    void inject(const DI::DIContainer& diContainer);
    inline void addLevel(const Level& level) { _levels.push_back(level); }
    void createLevel(cocos2d::Node* node);
    inline uint8_t getLevel() { return _level; }

    inline void setSnapshot(
        cocos2d::RefPtr<cocos2d::Node> brick)
    {
      _brickSnapshot = brick;
    }

  private:
    Brick* createBrick(BrickInfo brickInfo);
    cocos2d::Sprite* createField();

  private:
    uint8_t _level{0};
    bool bUseBrickSnapshot{false};
    cocos2d::EventDispatcher* _eventDispatcher;
    std::vector<Level> _levels;
    cocos2d::RefPtr<cocos2d::Node> _brickSnapshot{nullptr};
  };
}
#endif
