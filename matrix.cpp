#include <vector>
#include <iostream>

int main(){
  size_t size = 8;
  std::vector<std::vector<int>> v(size, std::vector<int>(size, 0));
  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      v[i][j] = i*j + 1;
      std::cout << i*j + 1<< '\t';
    }
    std::cout << '\n';
  }
}