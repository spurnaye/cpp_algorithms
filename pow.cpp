#include <iostream>
#include <ctime>
#include <cmath>


int main(){
  // srand(time(0)); 
  // for(int i = 0; i < 25; i++){
  //   int n = rand()%10;
  //   int x = rand()%10;
  //   int power;
  //   if(n %2 == 0){
  //     power = (x << n);
  //   }
  //   else{
  //    power = (x << (n-1))*x; 
  //   }
  //   std::cout << "x ^ n :" << x << ' ' << n << '=' << power << '\n';
  // }

  int x = 5;
  int y = 4;
  std::cout << pow(x,y) << '\n';
  x <<= 7;
  std::cout << x << '\n';
  return 0;
}