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
  ThreadPool(){
    for(int i = 0; i < max_size; ++i){
      work[i] = Work();
    }
  }

  bool enqueue(func_type fn, args_ary args){
   size_t current_head_idx = head_idx.load(std::memory_order_acquire);
   std::atomic<size_t> next_idx = (current_head_idx + 1) % max_size;

   Work w = work[next_idx];
   if(w.invalid() || w.processed()){
     work[next_idx].set_work(fn);
     work[next_idx].set_args(args);
     work[next_idx].reset();
     head_idx.store(next_idx, std::memory_order_release);
   }
   return true;
}

bool process(){
  size_t current_tail_idx = tail_idx.load(std::memory_order_acquire);
  std::atomic<size_t> next_idx = (current_tail_idx + 1) % max_size;

  if(!work[next_idx].processed()){
    int output = work[next_idx].process();
    std::cout << output << '\n';
    work[next_idx].set_processed();
    tail_idx.store(next_idx);
  }
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
     return is_processed == true;
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

    void set_work(func_type work){
      _work = work;
    }

    void set_args(args_ary args){
      _args = args;
    }
    void reset(){
      is_processed = false;
    }
};

  static const size_t max_size = 1000;
  std::array<Work,max_size> work;
  std::atomic<size_t> head_idx{0}, tail_idx{0};
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
          fn = [](int a, int b){ 
            std::cout << "Adding \t\t" << a << '\t'<< b << '\t'; 
            return a+b;
          };
        }else if(count % 3 == 1){
          fn = [](int a, int b){ 
            std::cout << "Subtracting \t" << a << '\t'<< b << '\t'; 
            return a-b;
          };
        }else{
          fn = [](int a, int b){
            std::cout << "Multiplying \t" << a << '\t'<< b << '\t'; 
            return a*b;};
        }
        tp.enqueue(fn, args_ary{random_num(),random_num()});
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