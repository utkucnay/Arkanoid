#ifndef __DI_STRUCT_H__
#define __DI_STRUCT_H__

#include "cocos2d.h"

namespace DI {
  struct typeSingle{
    void* (*get) ();
    void (*del) ();
  };
  struct typeFactory {
    std::shared_ptr<void> (*shrdCtor) ();
  };
}

#endif
