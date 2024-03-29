#include "ProgressBar.hpp"
#include <atomic>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>

ProgressBar::ProgressBar(int numThreads, int length)
    : numThreads_(numThreads), length_(length), threadProgresses_(numThreads),
      isRunning_(true) {

  threadIds_.resize(numThreads_);
  threadStartTimes_.resize(numThreads_);
  threadEndTimes_.resize(numThreads_);
}

void ProgressBar::start() {
  startCalculationThreads();
  startProgressBarThread();
  joinCalculationThreads();
}

void ProgressBar::startCalculationThreads() {
  calculationThreads_.reserve(numThreads_);
  for (int i = 0; i < numThreads_; ++i) {
    calculationThreads_.emplace_back(&ProgressBar::calculationThread, this, i);
  }
}

void ProgressBar::startProgressBarThread() {
  std::thread progressThread(&ProgressBar::progressBarThread, this);
  progressThread.join();
}

void ProgressBar::joinCalculationThreads() {
  for (auto &thread : calculationThreads_) {
    thread.join();
  }
}

void ProgressBar::calculationThread(int threadNumber) {
  int calculationTime = std::rand() % 500 + 5000;
  threadStartTimes_[threadNumber] = std::chrono::steady_clock::now();
  threadIds_[threadNumber] = std::this_thread::get_id();

  for (int i = 0; i < length_; ++i) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(calculationTime / length_));
    ++threadProgresses_[threadNumber];
  }
  threadEndTimes_[threadNumber] = std::chrono::steady_clock::now();
}

void ProgressBar::progressBarThread() {
  while (isRunning_) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    printProgress();
  }
}

void ProgressBar::printProgress() {
  std::scoped_lock<std::mutex> lock(mtx_);
  std::cout << "\033[2J\033[1;1H";
  std::cout << std::format("#{:<10} {:<60} {:<60} time\n", "ID", "progress",
                           "progress");

  bool allComplete = true;

  for (int i = 0; i < numThreads_; ++i) {
    int progress = threadProgresses_[i];
    int progressMax = length_;

    std::chrono::duration<double, std::chrono::seconds::period> elapsed_time =
        threadEndTimes_[i] ==
                std::chrono::time_point<std::chrono::steady_clock>()
            ? std::chrono::steady_clock::now() - threadStartTimes_[i]
            : threadEndTimes_[i] - threadStartTimes_[i];

    std::cout << (i + 1) << "  " << threadIds_[i] << "  [";
    for (int j = 0; j < progress; ++j) {
      std::cout << "■";
    }
    std::cout << std::string(progressMax - progress, ' ') << "] "
              << progress * 100 / length_ << "%"
              << " Elapsed time: " << elapsed_time.count() << "s\n";

    if (progress != length_) {
      allComplete = false;
    }
  }

  if (allComplete) {
    isRunning_ = false;
  }
}
