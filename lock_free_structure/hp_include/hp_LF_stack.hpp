#pragma once
#include <atomic>
#include <memory>
#include <type_traits>

template <typename T> class LF_stack {
  using _lf_share_ptr = std::atomic<std::shared_ptr<T>>;
  static constexpr bool _lock_free_pointer = _lf_share_ptr::is_lock_free();

  struct node {
    T value;
    node *next;
  };

  std::conditional_t<_lock_free_pointer, _lf_share_ptr, T *> head;

public:
  LF_stack() = default;
  LF_stack(const LF_stack &) = delete;
  LF_stack(LF_stack &&) = default;
  LF_stack &operator=(const LF_stack &) = delete;
  LF_stack &operator=(LF_stack &&) = default;
  void push(const T &val) {
    auto newNode = new node{val, head};
    while (!head.compare_exchange_weak(newNode->next, newNode))
      ;
  }
  void push(T &&val);
  std::shared_ptr<T> top();
  std::shared_ptr<T> pop();
  ~LF_stack();
};
