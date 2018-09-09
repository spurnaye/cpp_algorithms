#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <algorithm>
#include <numeric>

int random_num() { return (std::rand()%20); }

int main(){
  std::srand ( unsigned ( std::time(0) ) );

  std::vector<int> nums(20);
  std::generate(nums.begin(), nums.end(), random_num);

  int target_sum = 35;

  std::vector<int>::iterator current_idx = nums.begin();

  int current_sum;
  for(;current_sum <= target_sum && current_idx != nums.end(); current_sum += *(current_idx++)){};

  std::vector<int>::iterator begin_idx;
  for(begin_idx = nums.begin(); begin_idx <= current_idx; begin_idx++){
    int total = std::accumulate(begin_idx, current_idx, 0, std::plus<int>());
    if (total < target_sum){
      break;
    }
  }
  
  if(begin_idx == current_idx){

  }

  for(; begin_idx <= current_idx; begin_idx++){
    std::cout << *begin_idx << ' ';
  }

  return 0;
}