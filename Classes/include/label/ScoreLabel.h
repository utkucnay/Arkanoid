#ifndef __SCORE_LABEL_H__
#define __SCORE_LABEL_H__

#include "cocos2d.h"
#include "diContainer/DIContainer.h"
#include "manager/ScoreManager.h"

namespace Arkanoid::Label {
  class ScoreLabel : public cocos2d::Node {
  public:
    bool init() override;
    CREATE_FUNC(ScoreLabel);

  public:
    void inject(const DI::DIContainer& diContainer);
    void addScoreEvent(cocos2d::EventCustom* eventCustom);
    void syncText();
    void onEnter() override;

  private:
    cocos2d::Label* _scoreLabel;
    cocos2d::Label* _highScoreLabel;
    Manager::ScoreManager* _scoreManager;
  };
}

#endif
