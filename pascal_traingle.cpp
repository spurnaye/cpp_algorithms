#include <vector>
#include <iostream>
#include <cstdio>
// A O(n^2) time and O(1) extra space function for Pascal's Triangle
void pascal_traingle(int n)
{
 for(int line = 1; line <= n; line++){
  int c = 1;
  for(int i = 1; i <= line; i++){
    std::cout << c << ' ';
    c = c * (line - i)/i;
  }
  std::cout << '\n';
 }
}

int main(){
  pascal_traingle(3);
}