#include <iostream>

//#include "template_macros.hpp"
//#include "template_class.hpp"
#include "tempplate_with_int_value.hpp"
//#include "stack.hpp"

#include "log.hpp"

int main(int argc, char const *argv[]) {
  Stack<int, 255> st;
  st.push(20);
  // st.push(20.25);
  st.push<int>(100);
  LogDebug<const char* >(st.pop().msg);
  LogDebug<const char* >(st.pop().msg);
  LogError(st.pop().msg);

  int a = 90;
  LogDebug(&a);

  float f = 90;
  LogDebug(&f);
  std::cout << st.GetMaxStackSize() << std::endl;

  Stack<int *, 1000> st_heap;

  std::cout << convert<float, int>(100) << std::endl;
  std::cout << convert<int>(100.30) << std::endl;
  // std::cout << convert<>(200.30) << std::endl;
  return 0;
}
