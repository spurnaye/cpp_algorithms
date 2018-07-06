#include <iostream>

// int parity(int x){
//   int count = 0;
//   while(x){
//     count ^= 1;
//     x &= (x -1);
//   }
//   return count;
// }

int parity(int x){
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}
int main(){
  std::cout << parity(100) << '\n';
}