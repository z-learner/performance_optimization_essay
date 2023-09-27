#include <chrono>
#include <iostream>

int main(int argc, char** argv) {
  char buffer[1024];
  constexpr int loop_count = 1024;

  auto start = std::chrono::high_resolution_clock::now();

  for (int loop_index = 0; loop_index < loop_count; ++loop_index) {
    for (int array_index = 0; array_index < 1024; ++array_index) {
      buffer[array_index] = loop_index;
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> diff = end - start;

  std::cout << "elapse time = " << diff.count() << "us" << std::endl;
  return 0;
}