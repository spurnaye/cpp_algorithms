#include <vector>
#include <iostream>


int main(){
  std::vector<int> v{2,4,5,3,2,5,6,7,8,9,3};
  int min_price = *v.begin();
  int max_profit = 0;
  for(const auto & i: v){
    int todays_profit = i - min_price;
    max_profit = std::max(max_profit, todays_profit);
    min_price = std::min(min_price, i);
  }
  
  std::cout << max_profit << '\n';
  return 0;
}