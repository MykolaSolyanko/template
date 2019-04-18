#pragma once
#include "common_type.hpp"

template <class /*typename*/ T, unsigned SIZE>
class Stack {
 public:
  Pair push(T value) {
    Pair res {false, ""};
    if (nullptr == array) {
      res.msg = "Stack is not allocated";
      return res;
    }

    if (current_position == SIZE) {
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
    return SIZE;
  }

  int GetCurrentPosition() const {
    return current_position;
  }
 private:
  T array[SIZE];
  int current_position = -1;
};

/*
Template specialization
*/
#pragma once
#include "common_type.hpp"

template <class /*typename*/ T, unsigned SIZE>
class Stack <T*, SIZE> {
 public:
  Pair push(T value) {
    Pair res {false, ""};
    if (nullptr == array) {
      res.msg = "Stack is not allocated";
      return res;
    }

    if (current_position == SIZE) {
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
    return SIZE;
  }

  int GetCurrentPosition() const {
    return current_position;
  }

  Stack() {
    std::cout << "Heap version" << std::endl;
    if (SIZE > 0) {
      array = new T [SIZE]{};
    }
  }

  Stack(const Stack& st) = delete;

  ~Stack() {
    if (array != nullptr) {
      delete [] array;
    }
  }

  Stack& operator=(const Stack& st) = delete;
 private:
  T* array = nullptr;
  int current_position = -1;
};

