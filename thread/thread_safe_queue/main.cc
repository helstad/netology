#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

template <typename T> class safe_queue {
public:
  void push(T new_value) {
    std::lock_guard<std::mutex> lock(mtx_);
    data_queue_.push(std::move(new_value));
    cv_.notify_one();
  }

  T pop() {
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [this] { return !data_queue_.empty(); });

    T value = std::move(data_queue_.front());
    data_queue_.pop();
    return value;
  }

  bool empty() const {
    std::lock_guard<std::mutex> lock(mtx_);
    return data_queue_.empty();
  }

private:
  std::queue<T> data_queue_;
  mutable std::mutex mtx_;
  std::condition_variable cv_;
};

class ThreadPool {
public:
  ThreadPool(size_t num_threads = std::thread::hardware_concurrency()) {
    for (size_t i = 0; i < num_threads; ++i) {
      threads_.emplace_back([this] {
        while (true) {
          std::function<void()> task;
          {
            std::unique_lock<std::mutex> lock(queue_mutex_);

            cv_.wait(lock, [this] { return !tasks_.empty() || stop_; });

            if (stop_ && tasks_.empty()) {
              return;
            }

            task = std::move(tasks_.pop());
          }

          task();
        }
      });
    }
  }

  ~ThreadPool() {
    {
      std::lock_guard<std::mutex> lock(queue_mutex_);
      stop_ = true;
    }

    cv_.notify_all();

    for (auto &thread : threads_) {
      thread.join();
    }
  }

  void submit(std::function<void()> task) {
    {
      std::lock_guard<std::mutex> lock(queue_mutex_);
      tasks_.push(std::move(task));
    }
    cv_.notify_one();
  }

private:
  std::vector<std::thread> threads_;
  safe_queue<std::function<void()>> tasks_;
  std::mutex queue_mutex_;
  std::condition_variable cv_;
  bool stop_ = false;
};

int main() {
  ThreadPool pool;

  for (int i = 0; i < 5; ++i) {
    pool.submit([] {
      std::cout << "Test function 1 is running on thread "
                << std::this_thread::get_id() << std::endl;
    });

    pool.submit([] {
      std::cout << "Test function 2 is running on thread "
                << std::this_thread::get_id() << std::endl;
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  std::cout << "Completed!\n";

  return 0;
}
