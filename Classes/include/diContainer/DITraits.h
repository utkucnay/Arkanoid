#ifndef __DI_TRAITS_H__
#define __DI_TRAITS_H__

#include "cocos2d.h"

namespace DI::Traits {
  template <typename Bind, typename To>
  class DISingle {
  public:
      static void* get() {
        return static_cast<void*>(_bind);
      }
      static void clean() {
        delete static_cast<To*>(_bind);
      }

      inline static Bind* _bind = new To();
    };

  template <typename Bind, typename To>
    class DIFactory {
    public:
      static std::shared_ptr<void> get() {
        return std::static_pointer_cast<void>(std::make_shared<To>());
      }
    };
}

#endif
