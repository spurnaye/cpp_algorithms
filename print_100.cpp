#include <iostream>
template <int T>
class Print{
public:
  static void print(){
    Print<T-1>::print();
    std::cout << T << '\n';
  }
};

template <>
class Print<1>{
  public:
  static void print(){
    std::cout << 1 << '\n';
  }
};

int main(){
    const int N = 100;
    Print<N>::print();
}