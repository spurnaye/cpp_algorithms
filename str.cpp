#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
int main(){

  std::string s  = "12345";
  std::for_each(begin(s), end(s), [](char & c) {char * ch = & c;
              std::cout << "***" << c - '0' <<"***" << std::endl;
            });
  return 0;
}