#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
// int bits(int num){
//   int count = 0;
//   while(num){
//       count += num & 1;
//       num >>= 1 ;
//   }
//   return count;
// }

// std::string num_to_bin(int num){
//   std::string s;
//   int start = 0;
//   while(num){
//     s += (num % 2) + '0';
//     num /= 2;
//   }
//   std::reverse(begin(s), end(s));
//   return s;
// }

template <typename iterator, typename T>
void my_iota(iterator b, iterator e, T value, T step){
  while(b!=e){
    value += step;
    *b += value;
    b++; 
  }
}

int main(){
  std::vector<int> v;
  v.resize(15);
  my_iota(v.begin(), v.end(), 100, 1);
  for(auto & i: v){
    std::cout << i << '\n';
  }
  //std::cout << num_to_bin(num) << '\n';
  return 0;
}