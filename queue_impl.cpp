#include <iostream>
#include <array>

template<typename T>
class Queue{
  static constexpr unsigned long size = 5;
  std::array<T, size> _queue;
  typename std::array<T, size>::iterator front = _queue.begin();
  typename std::array<T, size>::iterator back = _queue.begin();
public:
  bool is_full(){
      int back_distance = (std::distance(_queue.begin(), back) + 1)%size;
      int front_distance = std::distance(_queue.begin(), front);

      std::cout << "back_distance " << back_distance << '\n';
      std::cout << "front_distance " << front_distance << '\n';
      if(back_distance < front_distance){
      return true;
    }
    return false;
  }

  bool is_empty(){
    // if(front == back){
    //   return true;
    // }
    return false;
  }

  void enqueue(T value){
    if(is_full()) return;
    // if(back == _queue.end()){
    //   back = _queue.begin();
    // }
    int back_distance = (std::distance(_queue.begin(), back) + 1)%size;
    std::advance(back, back_distance);
    *back = value;
    back++;
  }

  std::shared_ptr<T> dequeue(){
    if(is_empty()) return nullptr;
    std::cout << "in the deque\n";
    auto element = std::make_shared<T>(*front);
    if (front == _queue.end()){
      front = _queue.begin();
    }
    front++;
    return element;
  }

  void print(){
    for(int i = 0; i < size; i++){
      std::cout << i << " is " << _queue[i] << '\n';
    }
    // for(auto i = front; i!=back;std::advance(i, std::distance(_queue.begin(), i)%5)){
    //   std::cout << *i << '\n';
    // }
  }

};

int main(){
  Queue<int> cq;
  cq.enqueue(10);
  cq.enqueue(20);
  cq.enqueue(30);
  cq.enqueue(40);
  cq.enqueue(50);
  cq.enqueue(60);
  cq.enqueue(70);
  cq.enqueue(80);
  cq.print();
  std::shared_ptr<int> p = cq.dequeue();
  p = cq.dequeue();
  p = cq.dequeue();
  p = cq.dequeue();
  p = cq.dequeue();
  cq.print();
  cq.enqueue(100);
  return 0;
}

