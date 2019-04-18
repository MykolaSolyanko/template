#pragma once
#include "common_type.hpp"

#define STACK(Name, Type) \
class Stack##Name { \
  public: \
   Pair pop() { \
     Pair res {false, "Stack empty"}; \
     if (nullptr == array) { \
       res.msg = "Stack is not allocated"; \
       return res; \
     } \
     if (current_position == -1) { \
       return res; \
     } \
     --current_position; \
     res = {true, "Success"}; \
     return res; \
   } \
   Value top() const { \
     Value res {false, 0}; \
     if (nullptr == array) { \
       return res; \
     } \
     if (current_position == -1) { \
       return res; \
     } \
     res = {true, array[current_position]}; \
     return res; \
   } \
   Pair push(Type value) { \
     Pair res {false, ""}; \
     if (nullptr == array) { \
       res.msg = "Stack is not allocated"; \
       return res; \
     } \
     if (current_position == SIZE_STACK) { \
       res.msg = "Satck is full"; \
       return res; \
     } \
     array[++current_position] = value; \
     res.status = true; \
     res.msg = "Success add to stack"; \
     return res; \
   } \
   Stack##Name(int size) \
      : SIZE_STACK(size) { \
     if (SIZE_STACK > 0) { \
       array = new Type [SIZE_STACK]{}; \
     } \
   } \
  ~Stack##Name() { \
    if (array != nullptr) { \
      delete [] array; \
    } \
  } \
  private: \
   Type* array = nullptr; \
   int current_position = -1; \
   int SIZE_STACK = 5; \
};

