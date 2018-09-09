#include <iostream>
#include <vector>
#include <ctime>


int main(){
  std::srand(std::time(nullptr));
  for(int i = 0; i < 100; i++){
    int random_variable = std::rand()%10;
  }
  return 0;
}