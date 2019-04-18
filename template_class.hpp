#pragma once
#include "common_type.hpp"

template <class /*typename*/ T = int>
class Stack {
 public:
  Pair push(T value) {
    Pair res {false, ""};
    if (nullptr == array) {
      res.msg = "Stack is not allocated";
      return res;
    }

    if (current_position == SIZE_STACK) {
      res.msg = "Satck is full";
      return res;
    }
    array[++current_position] = value;
    res.status = true;
    res.msg = "Success add to stack";
    return res;
  }

  Pair pop() {
    Pair res {false, "Stack empty"};
    if (nullptr == array) {
      res.msg = "Stack is not allocated";
      return res;
    }
    if (current_position == -1) {
      return res;
    }
    --current_position;
    res = {true, "Success"};
    return res;
  }

  Value top() const {
    Value res {false, 0};
    if (nullptr == array) {
      return res;
    }

    if (current_position == -1) {
      return res;
    }
    res = {true, array[current_position]};
    return res;
  }
  int GetMaxStackSize() {
    return SIZE_STACK;
  }

  int GetCurrentPosition() const {
    return current_position;
  }

  Stack(int size)
     : SIZE_STACK(size) {
    if (SIZE_STACK > 0) {
      array = new T [SIZE_STACK]{};
    }
  }

  Stack(const Stack& st)
    : Stack(st.SIZE_STACK) {
  }

  Stack() = delete;

  ~Stack() {
    if (array != nullptr) {
      delete [] array;
    }
  }

  Stack& operator=(const Stack& st) {
    if (this == &st) {
      return *this;
    }
 
    if (array != nullptr) {
      delete [] array;
    }
    current_position = st.current_position;
    SIZE_STACK = st.SIZE_STACK;
    array = new T[SIZE_STACK] {};

    for (decltype(SIZE_STACK) i = 0; i < SIZE_STACK; ++i) {
      array[i] = array[i + 1];
    }
    return *this;
  }
 private:
  T* array = nullptr;
  int current_position = -1;
  int SIZE_STACK = 5;
};
