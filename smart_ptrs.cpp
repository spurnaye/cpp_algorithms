#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
  std::vector<std::string> v;
  std::copy(std::istream_iterator<std::string>(std::cin), 
    std::istream_iterator<std::string>(), std::ostream_iterator<std::string>(std::cout, " "));
  return 0;
}