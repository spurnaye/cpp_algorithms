#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(){
  std::vector<int> v(100);
  std::srand(std::time(nullptr)); // use current time as seed for random generator

  for(int i = 0; i < 1000; i++){
    int random_variable = std::rand()%100;
    v.push_back(random_variable);
    std::cout << random_variable << ' ';
  }

  std::sort(v.begin(), v.end());

  std::vector<int>::iterator start = v.begin();
  std::vector<int>::iterator end = v.end();
  
  auto i = start+1;
  while(i != end-1){
    if(*start == *i){
      i++;
    }else{
      start++;
      *start = *i;
    }
  }

  v.erase(start+1, end);
  for(const auto & i:v) std::cout << i << ' ';
}