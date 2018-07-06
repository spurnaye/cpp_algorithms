#include <vector>
#include <numeric>
#include <functional>
#include <cmath>
#include <iostream>

using namespace std; 


bool is_prime(int x){
  int xsqrt =  sqrt(x);
  for(int i = 2; i <= xsqrt; i++){
    if (x % i == 0){
      return false;
    }
  }
  return true;
}

int minimumNumber (vector <int> numbers )
{
  int sum = std::accumulate(numbers.begin(), numbers.end(), 0, std::plus<int>());
  bool prime = is_prime(sum);
  int next_prime = sum;
  
  while(true){
    prime = is_prime(next_prime);
    if(prime){
      break;
    }
    next_prime++;
  }
  return next_prime - sum;
}


int main(){
  std::cout << minimumNumber({3,1,2}) << '\n';
}