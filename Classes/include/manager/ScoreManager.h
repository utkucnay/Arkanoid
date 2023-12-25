#ifndef __SCORE_MANAGER_H__
#define __SCORE_MANAGER_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"

namespace Arkanoid::Manager {
  class ScoreManager {
  public:
    void inject(const DI::DIContainer& diContainer) {}
    inline void addScore(int num) {
      _score += num;
      _highScore = std::max(_score, _highScore);
    }
    inline void resetScore() { _score = 0; }
    inline int getScore() { return _score; }
    inline void setHighScore(int highScore) { _highScore = highScore; }
    inline int getHighScore() { return _highScore; }

  private:
    int _score;
    int _highScore;
  };
}

#endif
