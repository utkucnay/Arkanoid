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
	class Ref {
  public:
    Ref() : sharedPtr(nullptr) { };
    Ref(const std::shared_ptr<T>& sptr) : sharedPtr(sptr) { };
    Ref(std::shared_ptr<T>&& sptr) : sharedPtr(std::move(sptr)) { };
  public:
    template<typename... Args>
    static Ref<T> create(Args&&... args) {
      Ref<T> ref;
      ref.sharedPtr = std::make_shared<T>(std::forward<Args>(args)...);
      return ref;
    }
    void swap(std::shared_ptr<T>&& ptr) { sharedPtr.swap(std::forward(ptr)); }
  public:
    T* get() const { return sharedPtr.get(); }
    T& operator*() const { return *sharedPtr; }
    T* operator->() const { return sharedPtr.get(); }
    explicit operator std::shared_ptr<T>() const
    {
      return sharedPtr;
    }
    template<typename T1>
    operator Ref<T1>() const
    {
      return Ref<T1>(std::static_pointer_cast<T1>(static_cast<std::shared_ptr<T>>(sharedPtr)));
    }
  protected:
    std::shared_ptr<T> sharedPtr;
  };

	template<typename T>
	class Scope {
  public:
    Scope() : uniquePtr(nullptr) {};
    Scope(const std::unique_ptr<T>& ptr) : uniquePtr(ptr) {};
    Scope(std::unique_ptr<T>&& ptr) : uniquePtr(std::move(ptr)) {};
  public:
    template<typename... Args>
    static Scope<T> create(Args&&... args) {
      Scope<T> ref;
      ref.uniquePtr = std::unique_ptr<T>(new T(std::forward(args)...));
      return ref;
    }
    void swap(std::unique_ptr<T>&& ptr) { uniquePtr.swap(std::forward(ptr)); }
  public:
    T* get() const { return uniquePtr.get(); }
    T& operator*() const { return *uniquePtr; }
    T* operator->() const { return uniquePtr.get(); }
    explicit operator std::unique_ptr<T>() const
    {
      return uniquePtr;
    }
    template<typename T1>
    operator Ref<T1>() const
    {
      return Scope<T1>(std::static_pointer_cast<T1>(static_cast<std::unique_ptr<T>>(uniquePtr)));
    }
  private:
    std::unique_ptr<T> uniquePtr;
  };

  template<typename T>
  class WeakRef {
  public:
    void operator=(Ref<T> ptr) {
      weakPtr = static_cast<std::shared_ptr<T>>(ptr);
    }
  public:
    Ref<T> lock() const { return weakPtr.lock(); }
    bool expired() const { return weakPtr.expired(); }
    void swap(std::weak_ptr<T>&& ptr) { weakPtr.swap(std::forward(ptr)); }
  private:
    std::weak_ptr<T> weakPtr;
    friend class Ref<T>;
  };
};

#endif // !__CORE_H__
