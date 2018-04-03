#include <iostream>
#include <string>
#include <sstream>

//# first element: 1, difference: 2, how many: 5
std::string arithmeticSequenceElements(int a, int r, int n)
{
  std::stringstream ss;
  ss << std::to_string(a);
  for(int i = 1; i < n; i++){
    ss << ", ";
    a += r;
    ss << a;
  }
  return ss.str();
}


int main(){
    
  std::cout << arithmeticSequenceElements(1,2,5) << std::endl;
  return 0;
}


HR@Amaz0n