#include "ProgressBar.hpp"
#include <thread>

int main() {
  const int numThreads = std::thread::hardware_concurrency() - 1;
  const int length = 10;

  ProgressBar progressBar(numThreads, length);
  progressBar.start();

  return 0;
}