#include <cmath>
#include <iostream>

bool is_prime(int num){
  if(num %2 == 0 || num % 3 == 0){
    return false;
  }
  for(int i = 6; i*i <= num; i+= 6){
    if(num %i == 0) return false;
  }
  return true;
}

int main(){
  std::cout << is_prime(7) << std::endl;
}