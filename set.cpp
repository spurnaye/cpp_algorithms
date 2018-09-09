#include <set>
#include <iostream>
#include <vector>

static long small(std::vector<long> list, long n){
  std::set<long> s(list.begin(), list.end());
  if(n < s.size()){
    return *std::next(s.begin(), n);
  }
  else{
    return -1;
  }
}


int main(){
std::vector<long> list = {14, 12 ,46 ,34 ,334};
  std::cout << small(list, 3) << '\n';
}