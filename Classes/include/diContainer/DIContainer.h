#ifndef __DI_CONTAINER_H__
#define __DI_CONTAINER_H__

#include "cocos2d.h"
#include "diContainer/DITraits.h"
#include "diContainer/DIStruct.h"

namespace DI {
  class DIContainer {
  public:
    ~DIContainer() {
      for(auto& t : typeSInfo) {
        if(t.second.del != nullptr)
          t.second.del();
      }
    }
  public:
    template<typename T>
    T* getCocosSingle() const {
      return static_cast<T*>(T::getInstance());
    }

    template<typename Bind, typename To>
    void addSingle() {
      using diSingle = Traits::DISingle<Bind, To>;
      typeSInfo[typeid(Bind).name()].get = diSingle::get;
      typeSInfo[typeid(Bind).name()].del = diSingle::clean;
    }

    template<typename T>
    T* getSingle() const {
      return static_cast<T*>(typeSInfo.at(typeid(T).name()).get());
    }

    template<typename Bind, typename To>
    void addFactory() {
      using factory = Traits::DIFactory<Bind, To>;
      typeFInfo[typeid(Bind).name()].shrdCtor = factory::get;
    }

    template<typename T>
    std::shared_ptr<T> getFactory() const {
      return std::static_pointer_cast<T>(typeFInfo.at(typeid(T).name()).shrdCtor());
    }

  private:
    std::unordered_map<std::string, typeSingle> typeSInfo;
    std::unordered_map<std::string, typeFactory> typeFInfo;
  };
}


#endif
