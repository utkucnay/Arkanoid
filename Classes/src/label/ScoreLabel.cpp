#include "label/ScoreLabel.h"
#include "manager/EventManager.h"
#include "resource/Resource.h"
#include <string>

bool
Arkanoid::Label::ScoreLabel::init() {
  auto listener = cocos2d::EventListenerCustom::create(
      EventHelper::getAddScore(),
      CC_CALLBACK_1(ScoreLabel::addScoreEvent,
      this));

  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

  _scoreLabel = cocos2d::Label::createWithTTF(
      "Nan",
      Arkanoid::Resource::getTTFFontFileName(),
      10);

  _scoreLabel->setAnchorPoint(cocos2d::Vec2(0, 1));

  _highScoreLabel = cocos2d::Label::createWithTTF(
      "Nan",
      Arkanoid::Resource::getTTFFontFileName(),
      10);

  _highScoreLabel->setAnchorPoint(cocos2d::Vec2(0, 1));
  _highScoreLabel->setPosition(112, 0);

  this->addChild(_scoreLabel);
  this->addChild(_highScoreLabel);
  return true;
}

void
Arkanoid::Label::ScoreLabel::inject(
    const DI::DIContainer& diContainer)
{
  if(diContainer.hasSingle<Manager::ScoreManager>())
    _scoreManager = diContainer.getSingle<Manager::ScoreManager>();
}

void
Arkanoid::Label::ScoreLabel::addScoreEvent(
    cocos2d::EventCustom* eventCustom)
{
  auto iScore = static_cast<int*>(eventCustom->getUserData());
  _scoreManager->addScore(*iScore);
  syncText();
}

void
Arkanoid::Label::ScoreLabel::syncText() {
  _scoreLabel->setString(std::to_string(_scoreManager->getScore()));
  _highScoreLabel->setString(std::to_string(_scoreManager->getHighScore()));
}

void
Arkanoid::Label::ScoreLabel::onEnter() {
  Node::onEnter();
  syncText();
}
