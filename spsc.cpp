#include <iostream>
#include <thread>
#include <array>
#include <functional>
#include <vector>
#include <random>
#include <chrono>

using func_type = std::function<int(int,int)>;
using args_ary = std::array<int,2>;

struct ThreadPool{
  bool enqueue(func_type fn, args_ary args){
    size_t next_idx = (head_idx + 1) % max_size;
    
    std::unique_lock<std::mutex> lk(mtx);
    cv.wait(lk,[&](){
      return work[next_idx].processed();
    });

   Work w{fn, args};
   work[next_idx] = w;
   head_idx = next_idx;
   cv.notify_all();
   return true;
}

bool process(){
  size_t next_idx = (tail_idx + 1) % max_size;

  std::unique_lock<std::mutex> lk(mtx);
  cv.wait(lk,[&](){
    return !work[next_idx].processed();
  });

  Work w = work[next_idx];
  w.set_processed();

  if(!w.invalid()){
    int output = w.process();
    std::cout << output << '\n';
  }
  tail_idx = next_idx;
  cv.notify_all();
  return true;
  }

private:
  struct Work{
  private:
    func_type _work;
    args_ary _args;
    bool is_processed = false;

  public:
    Work():is_processed(true){};
    Work(func_type work, args_ary args):_work{work},_args{args},is_processed(false){};
    bool processed(){
     return is_processed;
    }
    int process(){
      return _work(_args[0], _args[1]);
    }
    bool invalid(){
      return _work == nullptr;
    }
    void set_processed(){
      is_processed = true;
  }
};

  static const size_t max_size = 1000;
  std::array<Work,max_size> work;
  size_t head_idx = 0, tail_idx = 0;
  std::condition_variable cv;
  std::mutex mtx;
};

int random_num(){
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1,10000); // distribution in range [1,10000]
  return dist(rng);
}

int main(){
  ThreadPool tp;

  std::thread producer1([&](){
    int count = 0;
    while(true){
      std::function<int(int,int)> fn;
        if (count % 3 == 0){
          fn = [](int a, int b){ std::cout << "Adding \t\t" << a << '\t'<< b << '\t'; return a+b;};
        }else if(count % 3 == 1){
          fn = [](int a, int b){ std::cout << "Subtracting \t" << a << '\t'<< b << '\t'; return a-b;};
        }else{
          fn = [](int a, int b){std::cout << "Multiplying \t" << a << '\t'<< b << '\t'; return a*b;};
        }
        tp.enqueue(fn, args_ary{random_num(),random_num()});
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        ++count;
    }
  });

std::thread consumer1([&](){
  while(true){
    tp.process();
  }
});

  if(producer1.joinable()){
    producer1.join();
  }


  if(consumer1.joinable()){
    consumer1.join();
  }

  return 0;
}