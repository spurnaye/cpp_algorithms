#include <iostream>
#include <array>

int main(){
  size_t ary_size = 10;
  std::array<int, 10> v;
  for(int i = 0; i < 10; i++){
    v[i] = i;
  }

  auto back = v.begin();
  int back_distance;
  for(int i = 0; i < 10; i++){
    back_distance = (std::distance(v.begin(), back))%ary_size;
    std::cout << back_distance << '\n';
    back_distance++;
    std::advance(back, back_distance);
    
  }
  return 0;
}