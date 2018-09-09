#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <typeinfo>


template <typename T>
struct S{
  using type = T*;
};

int main(){
  std::cout << S<int>::type << '\n';
  return 0;
}