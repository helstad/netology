#include <algorithm>
#include <cstddef>
#include <future>
#include <iostream>
#include <iterator>
#include <random>
#include <utility>
#include <vector>

void findMin(const std::vector<int> &vec, size_t start,
             std::promise<int> &&prom) {
  int min = *std::min_element(vec.begin() + start, vec.end());
  prom.set_value(min);
}

std::vector<int> sort(const std::vector<int> &vec) {
  std::vector<int> sortedVec(vec);

  for (size_t i = 0; i < sortedVec.size(); i++) {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    auto task = std::async(std::launch::async, findMin, std::cref(sortedVec), i,
                           std::move(prom));

    int min = fut.get();

    auto minIter = std::find(sortedVec.begin() + i, sortedVec.end(), min);
    size_t minIndex = std::distance(sortedVec.begin(), minIter);

    std::swap(sortedVec[i], sortedVec[minIndex]);
  }

  return sortedVec;
}

int main() {
  std::vector<int> vec(10, 0);

  std::mt19937 gen(time(nullptr));
  std::uniform_int_distribution<int> dis(-9, 9);
  auto rand_num([=]() mutable { return dis(gen); });
  generate(begin(vec), end(vec), rand_num);

  std::cout << "Original vector:\t";
  for (int num : vec) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;

  std::vector<int> sortedVec = sort(vec);

  std::cout << "Sorted vector:\t\t";
  for (int num : sortedVec) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;

  return 0;
}