#include <iostream>

int multiply(int a, int b){
  return a * b;
}

int add(int a, int b){
  return a + b;
}

int operate(std::function<int(int, int)> name, int first, int second){
  return name(first, second);
}

int operate_1(int(*name)(int, int), int first, int second){
  return name(first, second);
}

int operate_ary(int(*name)[5]){
  int sum = 0;
  for(const auto & x:*name){
    sum += x;
  }
  return sum;
}

auto auto_add(int x, int y){
  return x + y;
}

template <typename T, size_t size>
struct S{
  S(std::initializer_list<T> args){
    int n = 0;
    for (T x : args) {buffer[n++]=x;}
  }
  
  void print(){
    for(int i = 0; i < size; ++i){
      std::cout << buffer[i] << ' ';
    }
    std::cout << '\n';
  }
private:
  T buffer[size];
};

template <typename... T>

int main(){
  std::cout << operate_1(add, 4, 5) << '\n';
  std::cout << operate_1(multiply, 4, 5) << '\n';
  int ary[5]= {1,2,3,4,5};
  std::cout << operate_ary(&ary) << '\n';

  auto x5 = { 1, 2, 3 };
  std::cout << typeid(x5).name() << '\n';

  auto x = auto_add(5, 10);
  std::cout << x << '\n';

  std::cout << typeid(decltype(x)).name() << '\n';

  S<int, 10> s {1,2,3,4,5,6,7,8,9,10};
  s.print();
}