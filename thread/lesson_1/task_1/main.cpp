#include <chrono>
#include <format>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int clientCount = 0;
int maxClient = 10;
bool allClientsServed = false;

void clientThread() {
  while (!allClientsServed) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx.lock();
    if (clientCount < maxClient) {
      clientCount++;
      std::cout << std::format("New client! There are {} people in the queue.\n", clientCount);
    } else {
      allClientsServed = true;
    }
    mtx.unlock();
  }
}

void managerThread() {
  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    mtx.lock();
    if (clientCount > 0) {
      clientCount--;
      std::cout << std::format("Client left! There are {} people in the queue.\n", clientCount);
    }
    mtx.unlock();
    if (clientCount == 0 && allClientsServed) {
      break;
    }
  }
}

int main() {
  std::thread client(clientThread);
  std::thread manager(managerThread);

  client.join();
  manager.join();

  std::cout << "All clients are served.\n";

  return 0;
}