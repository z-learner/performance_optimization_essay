#include <chrono>
#include <cstring>
#include <iostream>
int main(int argc, char** argv) {
  char buffer[1024];
  constexpr int loop_count = 1024;

  auto start = std::chrono::high_resolution_clock::now();

  for (int loop_index = 0; loop_index < loop_count; ++loop_index) {
    memset(buffer, loop_index, 1024);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::micro> diff = end - start;

  std::cout << "elapse time = " << diff.count() << "us" << std::endl;
  return 0;
}