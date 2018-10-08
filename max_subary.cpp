#include <iostream>
#include <vector>


int main(){
  std::vector<int> ary {-2,1};
  
  int sum = ary[0];
  int max_sum = sum;
  int start_idx, end_idx;

  for(int i = 1; i < ary.size(); ++i){
    sum += ary[i];
    std::cout << sum << '\n';

    if(max_sum < sum){
      max_sum = sum;

      if(start_idx == 0){
        start_idx = i;
      }
      end_idx = i;
    }

    if(sum < 0){
      sum = 0;
    }
  }
  if(start_idx == end_idx){
    std::cout << "start_idx : " << start_idx << '\n';
    std::cout << ary[start_idx] << '\n'; 
  }
  return max_sum;
}