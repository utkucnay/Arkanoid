#ifndef __POOL_H__
#define __POOL_H__

#include "cocos2d.h"

namespace Arkanoid::Pool {
  template<typename T>
  class Pool {
  public:
    Pool(const T& prefab, int count) {
      for(int i = 0; i < count; i++) {
        _pool.push(prefab.clone());
      }
    }
    ~Pool() {

    }
  public:
    [[nodiscard]] T getObject() {
      if(_pool.size() == 1) {
        _pool.push(createObject());
      }
      return _pool.pop();
    }
    void setObject(T object) {
      _pool.push(object);
    }

    [[nodiscard]] std::list<T>
    getObjects(int count) {
      std::list<T> ret;
      for(int i = 0; i < count; i++) {
        ret.insert(getObject());
      }
      return ret;
    }
    void setObjects(std::list<T> objects) {
      for(auto& object : objects) {
        setObject(object);
      }
    }

  private:
    void createObject() {
        _pool.push(_pool.top().clone());
    }
  private:
    std::stack<T> _pool;
  };
}

#endif
