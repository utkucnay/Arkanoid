#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "actor/Brick.h"
#include "cocos2d.h"
#include <sstream>
#include <string>
#include <unordered_map>

namespace Arkanoid {
  enum class BrickInfo {
    Blue    = 1,
    Gold    = 2,
    Green   = 3,
    Orange  = 4,
    Red     = 5,
    Silver  = 6,
    Violet  = 7,
    White   = 8,
    Yellow  = 9,
    Cyan    = 10,
  };
  enum class FieldInfo {
    Blue,
    Cyan,
    Green,
    Orange,
  };
  struct Level {
    Level(
        const std::string& level,
        FieldInfo fieldInfo) :
          _level(level),
          _fieldInfo(fieldInfo)
    {}

    std::string _level;
    FieldInfo _fieldInfo;

  std::vector<std::tuple<BrickInfo, cocos2d::Vec2>> getBricks();
  FieldInfo getFieldInfo() { return _fieldInfo; }

  private:
  std::vector<std::string> SplitString(
      const std::string& inputs,
      char token = '\n');
  };
}

#endif
