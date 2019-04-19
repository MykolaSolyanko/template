#pragma once
#include <iostream>

template <typename T>
void LogError(T value) {
  std::cerr << "Error: " << value << std::endl;
}

template <typename T>
void LogInfo(T value) {
  std::cerr << "Info: " << value << std::endl;
}

template <typename T>
void LogDebug(T value) {
  std::cerr << "Debug: " << value << std::endl;
}

/*specialization for pointers*/
/*template <typename T>
void LogDebug<T*>(T value) {
  std::cerr << "Debug: " << value << std::endl;
}*/

template<>
void LogDebug<const char *>(const char* value) {
  std::cerr << "Debug with const char* : " << value << std::endl;
}

template<typename T>
void LogDebug(T* value) {
  if (value != nullptr) {
    std::cerr << "Debug with T* : " << *value << std::endl;
  }
}