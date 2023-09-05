#pragma once
#include <atomic>
#include <memory>

template <typename T> class LF_stack {
  struct node {
    T value;
    node *next;
  };

  std::atomic_flag flag{false};
  node *head{nullptr};

public:
  LF_stack() = default;
  LF_stack(const LF_stack &) = delete;
  LF_stack(LF_stack &&) = default;
  LF_stack &operator=(const LF_stack &) = delete;
  LF_stack &operator=(LF_stack &&) = default;
  void push(const T &val);
  void push(const T &&val);
  std::shared_ptr<T> top();
  std::shared_ptr<T> pop();
  ~LF_stack();
};
