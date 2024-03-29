#include <atomic>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

template <typename T> class AtomicVector {
public:
  explicit AtomicVector(size_t size) : data_(size) {}

  std::atomic<T> &operator[](size_t index) { return data_[index]; }

  const std::atomic<T> &operator[](size_t index) const { return data_[index]; }

  size_t size() const { return data_.size(); }

private:
  std::vector<std::atomic<T>> data_;
};

class ProgressBar {
public:
  ProgressBar(int numThreads, int calculationLength);
  void start();

private:
  void startCalculationThreads();
  void startProgressBarThread();
  void joinCalculationThreads();
  void stop();
  void calculationThread(int threadNumber);
  void progressBarThread();
  void printProgress();

  int numThreads_;
  int length_;
  AtomicVector<int> threadProgresses_;
  std::vector<std::thread> calculationThreads_;
  std::vector<std::thread::id> threadIds_;
  std::vector<std::chrono::time_point<std::chrono::steady_clock>>
      threadStartTimes_;
  std::vector<std::chrono::time_point<std::chrono::steady_clock>>
      threadEndTimes_;
  std::atomic<bool> isRunning_;
  std::atomic<bool> isProgressBarRunning_;
  std::mutex mtx_;
};