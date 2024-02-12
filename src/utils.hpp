#pragma once
#include <iostream>

template <typename T> void printArray(T arr[], int N) {
  for (int i = 0; i < N; ++i) {
    std::cout << arr[i] << ",";
  }
  std::cout << "\n";
}
