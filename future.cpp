#include <future>
#include <iostream>

int factorial(int x){
  if(x < 2) return x;
  return (x)*factorial(x-1);
}

int fact(std::future<int> f){

}

int main(){
  int result;
  std::future<int> fu = std::async(factorial, 5);
  result = fu.get();
  std::cout << result << '\n';

  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::future<int> fu = std::async(factorial, std::ref(f));
  
}