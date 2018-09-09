#include <iostream>

// int multiply(int x, int y){
//   x
// }

int main(){
  int x = 23;
  int y = 55;

  // 23 * 55 = 1265
  std::cout << x*y << '\n';

  // int shift_by = y/2;

  // x <<= shift_by;
  // if (y%2 != 0){
  //   x += y;   
  // } 
  std::cout << (x>>1) << '\n';
  return 0;
}