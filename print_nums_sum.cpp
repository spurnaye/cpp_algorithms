#include <iostream>

template <int T>
struct num{
  static constexpr int value = num<T-1>::value + num<T-2>::value;
};

template <>
struct num<1>{
  static constexpr int value = 1;
};

template <>
struct num<0>{
  static constexpr int value = 0;
};


int main(){
  int x = num<10>::value;
  std::cout << x<< '\n';
  return 0;
}