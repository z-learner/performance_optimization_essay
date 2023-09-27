
#include <chrono>
#include <iostream>
#include <list>
#include <vector>

int main(int argc, char** argv) {
  constexpr int loop_count = 1024;
  std::chrono::duration<double, std::micro> diff = std::chrono::microseconds(0);

  for (int loop_index = 0; loop_index < loop_count; ++loop_index) {
    std::vector<char> buff;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1024; ++i) {
      buff.insert(buff.begin(), loop_index);
    }
    auto end = std::chrono::high_resolution_clock::now();
    diff += end - start;
  }

  std::cout << "elapse time = " << diff.count() / 1e3 << "ms" << std::endl;
  return 0;
}