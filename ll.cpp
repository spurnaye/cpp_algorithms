#include <iostream>
#include <atomic>
#include <memory>

template <typename T>
class Node{
  T x;
  std::shared_ptr<T> next;
};

int main(){
  int x = 0;
  std::shared_ptr<int> sp;
//  auto y = std::move(sp);

  std::cout << sp.use_count() << '\n';
}