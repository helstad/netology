#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

template <std::memory_order order = std::memory_order_seq_cst>
void threadFunc() {
  std::atomic<unsigned int> clientCount = 0;
  std::mutex m;
  const int maxClients = 10;
  bool allClientServed = false;

  auto start = std::chrono::high_resolution_clock::now();

  std::jthread clientThread([&]() {
    while (!allClientServed) {
      std::this_thread::sleep_for(std::chrono::microseconds(100));
      if (clientCount < maxClients) {
        clientCount.store(clientCount.load(order) + 1, order);
        std::scoped_lock lock(m);
        std::cout << "[IN]. Total: " << clientCount.load(order) << "\n";

      } else {
        allClientServed = true;
      }
    }
  });

  std::jthread managerThread([&]() {
    while (clientCount > 0 || !allClientServed) {
      std::this_thread::sleep_for(std::chrono::microseconds(200));
      clientCount.store(clientCount.load(order) - 1, order);
      std::scoped_lock lock(m);
      std::cout << "[OUT]. Total: " << clientCount.load(order) << "\n";

      if (clientCount == 0 && allClientServed) {
        break;
      }
    }
    std::cout << "All clients served\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto elapse = end - start;
    std::cout << "Elapsed: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(elapse)
              << "\n";
  });
  std::cout << "\n";
}

int main() {
  threadFunc<std::memory_order_seq_cst>();
  threadFunc<std::memory_order_acquire>();
  threadFunc<std::memory_order_relaxed>();
  return 0;
}