#include "manager/LevelManager.h"
#include "prefab/BrickPrefab.h"
#include "resource/BlockResource.h"
#include "resource/FieldResource.h"

void
Arkanoid::Manager::LevelManager::inject(
    const DI::DIContainer& diContainer)
{
  _eventDispatcher = diContainer.getCocosSingle<
    cocos2d::Director>()->
      getEventDispatcher();
};

void
Arkanoid::Manager::LevelManager::createLevel(
    cocos2d::Node* node)
{
  if(bUseBrickSnapshot) {
    for(auto child : _brickSnapshot->getChildren()) {
      node->addChild(child);
    }
    _brickSnapshot->cleanup();
    return;
  }
  auto bricks = _levels.at(_level).getBricks();

  for(auto& brick : bricks) {
    auto pbrick = createBrick(std::get<0>(brick));
    auto pos = std::get<1>(brick);
    pbrick->setPosition(std::get<1>(brick));
    node->addChild(pbrick);
  }

  auto field = createField();
  field->setPosition(cocos2d::Vec2(16, 298));
  field->setAnchorPoint(cocos2d::Vec2(0, 1));
  field->setGlobalZOrder(-1);
  node->addChild(field);
  if(nullptr != _brickSnapshot) {
      _brickSnapshot->cleanup();
      _brickSnapshot = nullptr;
  }
}

Arkanoid::Brick*
Arkanoid::Manager::LevelManager::createBrick (
    BrickInfo brickInfo)
{
  Brick* brick = nullptr;

  switch(brickInfo) {
    case BrickInfo::Green:{
        brick = Prefab::GreenBrickPrefab::create();
      } break;
    case BrickInfo::Blue: {
        brick = Prefab::BlueBrickPrefab::create();
      } break;
    case BrickInfo::Red: {
        brick = Prefab::RedBrickPrefab::create();
      } break;
    case BrickInfo::Cyan:{
        brick = Prefab::CyanBrickPrefab::create();
      } break;
    case BrickInfo::Gold: {
        brick = Prefab::GoldBrickPrefab::create();
      } break;
    case BrickInfo::White: {
        brick = Prefab::WhiteBrickPrefab::create();
      } break;
    case BrickInfo::Orange:{
        brick = Prefab::OrangeBrickPrefab::create();
      } break;
    case BrickInfo::Silver: {
        brick = Prefab::SilverBrickPrefab::create();
        brick->setHealth(2 + _level % 7);
      } break;
    case BrickInfo::Violet: {
        brick = Prefab::VioletBrickPrefab::create();
      } break;
    case BrickInfo::Yellow: {
        brick = Prefab::YellowBrickPrefab::create();
      } break;
    default:{
        cocos2d::log("Undifend Brick!");
      } break;
  }

  return brick;
}


cocos2d::Sprite*
Arkanoid::Manager::LevelManager::createField() {
  auto fInfo = _levels.at(_level).getFieldInfo();

  cocos2d::Sprite* ret;
  switch (fInfo) {
    case FieldInfo::Orange:
      ret = Resource::createOrangeField();
      break;
    case FieldInfo::Cyan:
      ret = Resource::createCyanField();
      break;
    case FieldInfo::Blue:
      ret = Resource::createBlueField();
      break;
    case FieldInfo::Green:
      ret = Resource::createGreenField();
      break;
  }
  return ret;
}
