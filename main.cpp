#include <iostream>

//#include "template_macros.hpp"
//#include "template_class.hpp"
#include "tempplate_with_int_value.hpp"
//#include "stack.hpp"

int main(int argc, char const *argv[]) {
  Stack<int, 255> st;
  std::cout << st.GetMaxStackSize() << std::endl;

  Stack<int *, 1000> st_heap;
  return 0;
}
