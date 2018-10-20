#include <any>
#include <iostream>
#include <vector>

int main(){
std::any a = 1;
  std::vector<std::any> v{1,2,3,4.5,6.7,"some string"};

  auto x = std::any_cast<float>(v[0]);
}