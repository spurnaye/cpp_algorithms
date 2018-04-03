#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

class Kata
{
public:
  static std::string Decode(std::vector<int> code, int n)
  {
    std::vector<int> key_vector;
    while(n > 10){
      int reminder = n%10;
      key_vector.push_back(reminder);
      n /= 10;
    }
    key_vector.push_back(n);
    std::reverse(key_vector.begin(), key_vector.end());
    std::stringstream codestring;
    int key_length = key_vector.size();
    for(size_t i = 0; i < code.size(); ++i){
      int codeValue = code.at(i);
      int deleteValue = key_vector.at(i % key_length);
      int alphabetValue = codeValue - deleteValue + 96;
      std::cout << (char)alphabetValue << std::endl;
      codestring << (char)alphabetValue;
    }
    return codestring.str();
  }
};
 
int main(){
  std::vector<int> codeVector {20, 12, 18, 30, 21};
  int key = 1939;
  std::cout << Kata::Decode(codeVector, key) << std::endl;
  return 0;
}


