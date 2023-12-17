#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "actor/Brick.h"
#include "cocos2d.h"
#include "pool/Pool.h"

namespace Arkanoid {
  template<typename T, int count>
  class Factory {
    Factory() {
      _pool = new Pool::Pool<T>(count);
    }

    T get() {
      _pool.getObject();
    }
    void set(T object) {
      _pool.getObject(object);
    }
  private:
    Pool::Pool<T> _pool;
  };

  using BrickFactory = Factory<Brick, 50>;
}

#endif
