#include <iostream>
#include <vector>
#include <any>

int main(){
  auto x = [](int a, int b){return a+b;};

  std::vector<std::any> v{1,2.3};

  std::invoke(x, 1,3);
}