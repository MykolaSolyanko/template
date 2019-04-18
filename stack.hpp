#pragma once
#include "common_type.hpp"

class Stack {
 public:
  Pair push(int value);

  Pair push(unsigned int) = delete;
  Pair push(long) = delete;
  Pair push(long long) = delete;
  Pair push(float) = delete;
  Pair push(double) = delete;
  Pair push(long double) = delete;

  Pair pop();
  Value top() const;
  int GetCurrentPosition() const;
  int GetMaxStackSize();

  Stack(int size);
  Stack(const Stack& st);
  Stack() = delete;
  ~Stack();
  Stack& operator=(const Stack& st);
 private:
  int* array = nullptr;
  int current_position = -1;
  int SIZE_STACK = 5;
};

