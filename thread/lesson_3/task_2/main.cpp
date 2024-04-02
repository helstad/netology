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
  const size_t max_threads = (data_size + min_per_thread - 1) / min_per_thread;

  const size_t hardware_threads = std::thread::hardware_concurrency();
  const size_t num_threads =
      std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
  const size_t block_size = data_size / num_threads;

  std::vector<std::future<void>> futures(num_threads - 1);

  Iterator block_start = first;
  for (size_t i = 0; i < (num_threads - 1); ++i) {
    Iterator block_end = block_start;
    std::advance(block_end, block_size);
    futures[i] = std::async(std::launch::async, [=]() {
      std::for_each(block_start, block_end, func);
    });
    block_start = block_end;
  }
  std::for_each(block_start, last, func);
  for (auto &future : futures) {
    future.get();
  }
}

int main() {
  std::vector<int> vec(10, 0);

  std::mt19937 gen(time(nullptr));
  std::uniform_int_distribution<int> dis(-9, 9);
  auto rand_num([=]() mutable { return dis(gen); });
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