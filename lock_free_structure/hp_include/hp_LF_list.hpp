#pragma once
#include <memory>

template <typename T> class LF_List {
  template <typename> struct node {
    std::shared_ptr<T> val;
    node *front = nullptr;
    node *back = nullptr;
  };

  node<T> *head;
  node<T> *tail;
  size_t size = 0;

public:
  LF_List() = default;
  ~LF_List() {}
  void push(const T &&that) {
    // auto tmp=front;
  }
};
