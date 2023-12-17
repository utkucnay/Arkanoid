#include "level/Level.h"

std::vector<std::tuple<Arkanoid::BrickInfo, cocos2d::Vec2>>
Arkanoid::Level::getBricks() {

std::vector<std::tuple<Arkanoid::BrickInfo, cocos2d::Vec2>> ret;

  auto lines = SplitString(_level, '\n');

  for(size_t y = 0; y < lines.size(); y++) {
    auto nums = SplitString(lines[y], ',');

    for(size_t x = 0; x < nums.size(); x++) {
      int brickType = std::stoi(nums[x]);
      if(brickType == 0) continue;
      std::tuple<BrickInfo, cocos2d::Vec2> tmp;
      std::get<0>(tmp) = (BrickInfo)brickType;
      std::get<1>(tmp) = cocos2d::Vec2(24 + x * 16, 293 - y * 8);
      ret.push_back(tmp);
    }

  }
  return ret;
}

std::vector<std::string>
Arkanoid::Level::SplitString(const std::string& inputs, char token)
{
    std::vector<std::string> result;
    std::stringstream ss;

    for(char input : inputs)
    {
        if(input != token)
            ss << input;
        else
        {
            result.push_back(ss.str());
            ss.str("");
        }
    }
    if(ss.str() != "")
        result.push_back(ss.str());
    return result;
  }
