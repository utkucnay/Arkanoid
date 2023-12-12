#ifndef __TAG_MANAGER_H__
#define __TAG_MANAGER_H__

#include "cocos2d.h"

namespace Arkanoid::Manager {
  class TagManager {
  public:
    TagManager() {
      setTag("Default");
    };
  public:
    inline int getTag(const std::string& tagName) const {
      return _tagMap.at(tagName);
    };

    inline void setTag(const std::string& tagName) {
      _tagMap[tagName] = ++index;
    };

  private:
    std::unordered_map<std::string, uint8_t> _tagMap;
    int index{0};
  };
}

#endif
