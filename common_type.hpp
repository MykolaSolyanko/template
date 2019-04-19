#pragma once

struct Pair {
  bool status;
  const char* msg;
};

struct Value {
  bool status;
  int value;
};

template<typename R, typename T>
R convert(T value) {
  return static_cast<R> (value);
}