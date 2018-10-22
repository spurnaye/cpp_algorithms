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
    auto current_head_idx = head_idx.load(std::memory_order_acquire);
    auto next_idx = (current_head_idx + 1) % max_size;
    while(work[next_idx].processed()){
      if(head_idx.compare_exchange_strong(current_head_idx, next_idx)){
         work[next_idx].set_work(fn);
         work[next_idx].set_args(args);
        work[next_idx].reset();
        break;
      }
    }
  return true;
}

  bool process(){
    auto current_tail_idx = tail_idx.load(std::memory_order_acquire);
    auto next_idx = (current_tail_idx + 1) % max_size;
    while(work[next_idx].unprocessed()){
      if(tail_idx.compare_exchange_strong(current_tail_idx, next_idx)){
        if(work[next_idx].valid()){
          int output = work[next_idx].process();
          std::cout << output << '\n';
          work[next_idx].set_processed();
          break;
        }
      }
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
    bool unprocessed(){
     return is_processed == false;
    }
    
    int process(){
      return _work(_args[0], _args[1]);
    }
    
    bool invalid(){
      return _work == nullptr;
    }
    bool valid(){
      return _work != nullptr;
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

  auto adder = [](int a, int b){ std::cout << "Adding \t\t" << a << '\t'<< b << '\t'; return a+b;};
  auto subtractor = [](int a, int b){ std::cout << "Subtracting \t" << a << '\t'<< b << '\t'; return a-b;};
  auto multiplicator = [](int a, int b){std::cout << "Multiplying \t" << a << '\t'<< b << '\t'; return a*b;};

  std::thread producer1([&](){
    while(true){
      tp.enqueue(adder, args_ary{random_num(),random_num()});
    } 
  });

  std::thread producer2([&](){
    while(true){
      tp.enqueue(subtractor, args_ary{random_num(),random_num()}); 
    } 
  });

  // std::thread producer3([&](){
  //   while(true){
  //     tp.enqueue(multiplicator, args_ary{random_num(),random_num()}); 
  //   } 
  // });

  std::thread consumer1([&](){
    while(true){
      tp.process();
    }
  });

  // std::thread consumer2([&](){
  //   while(true){
  //     tp.process();
  //   }
  // });

  // std::thread consumer3([&](){
  //   while(true){
  //     tp.process();
  //   }
  // });


  if(producer1.joinable()){
    producer1.join();
  }

  if(producer2.joinable()){
    producer2.join();
  }

  // if(producer3.joinable()){
  //   producer3.join();
  // }

  if(consumer1.joinable()){
    consumer1.join();
  }

  // if(consumer2.joinable()){
  //   consumer2.join();
  // }
  // if(consumer3.joinable()){
  //   consumer3.join();
  // }

  return 0;
}