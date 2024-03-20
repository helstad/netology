#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <numeric>
#include <format>
#include <cmath>

void calculateSum(const std::vector<int>& data, int start, int end, int& result) {
  result = std::accumulate(data.begin() + start, data.begin() + end, 0);
}

int main() {
  int countThreadAvailable = std::thread::hardware_concurrency();
  std::cout << std::format("Available thread count: {}\n\n", countThreadAvailable);

  std::vector<int> sizes = {1000, 10000, 100000, 1000000};
  std::vector<int> numThreads = {2, 4, 8, 16};
  
  std::cout << std::setw(10) << "Threads";
  for(int size : sizes) {      
    std::cout << std::setw(10) << size;
  }
  std::cout << std::endl;

  for(int thread : numThreads) {
    std::cout << std::setw(10) << thread;
    for(int size : sizes) {
       std::vector<int> data(size, 1);

      auto startTime = std::chrono::steady_clock::now();

      std::vector<std::thread> threads;
      threads.reserve(thread);

      int chunkSize = std::ceil(static_cast<double>(size) / thread);

      std::vector<int> results(thread);
      for(int i = 0; i < thread; ++i) {
        int start = i * chunkSize;
        int end = std::min((i + 1) * chunkSize, size);
        threads.emplace_back(calculateSum, std::ref(data), start, end, std::ref(results[i]));
      }

      for (auto& thread : threads) {
        thread.join();
      }

      int totalSum = std::accumulate(results.begin(), results.end(), 0);

      auto endTime = std::chrono::steady_clock::now();

      std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
      std::cout << std::setw(10) << std::fixed << std::setprecision(3) << elapsed.count();
    }
    std::cout << std::endl;
  }

  return 0;
}