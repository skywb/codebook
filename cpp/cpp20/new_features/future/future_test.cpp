#include <iostream>
#include <thread>
#include <future>

int main() {
  std::mutex m;
  auto re = std::async(std::launch::deferred, [&m]() -> void {
      std::lock_guard<std::mutex> lk(m);
      std::cout << "async thread " <<  std::this_thread::get_id() << std::endl;
      return;
  });
  {
  std::lock_guard<std::mutex> lk(m);
  std::cout <<  "main thread " << std::this_thread::get_id() << std::endl;
  }
  re.wait();
  re.get();
}
