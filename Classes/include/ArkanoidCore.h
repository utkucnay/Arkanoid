#ifndef __CORE_H__
#define __CORE_H__

#include <iostream>
#include <fstream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <deque>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Arkanoid
{
	template<typename T>
	class Ref : public std::shared_ptr<T> {
  public:
    template<typename... Args>
    static Ref<T> create(Args... args) {
      return std::make_shared<T>(args...);
    }
  };

	template<typename T>
	class Scope : public std::unique_ptr<T> {
  public:
    template<typename... Args>
    static Scope<T> create(Args... args) {
      return std::make_unique<T>(args...);
    }
  };

  template<typename T>
  using WeakRef = std::weak_ptr<T>;
};

#endif // !__CORE_H__
