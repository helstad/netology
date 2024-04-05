#include <algorithm>
#include <cstddef>
#include <future>
#include <iostream>
#include <iterator>
#include <random>
#include <thread>
#include <vector>

template <typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func func) {
  const size_t data_size = std::distance(first, last);
  const size_t min_per_thread = 25;

  if (data_size < min_per_thread) {
    std::for_each(first, last, func);
  } else {
    Iterator mid = first + data_size / 2;
    std::future<void> first_half = std::async(
        std::launch::async, [=]() { parallel_for_each(first, mid, func); });
    parallel_for_each(mid, last, func);
    first_half.get();
  }
}

int main() {
  std::vector<int> vec(10, 0);

  std::mt19937 gen(time(nullptr));
  std::uniform_int_distribution<int> dis(-9, 9);
  auto rand_num = [&gen, &dis]() { return dis(gen); };
  std::generate(vec.begin(), vec.end(), rand_num);

  std::cout << "Original Vector:\t";
  for (const auto &num : vec) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;

  parallel_for_each(vec.begin(), vec.end(), [](int &n) { n *= 2; });

  std::cout << "ForEach vector:\t\t";
  for (const auto &num : vec) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;

  return 0;
}
