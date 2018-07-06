#include <iostream>
#include <vector>
#include <string>
#include <sstream>
void multiply_vector(std::vector<int> & v, int multiply_num){
  int carry = 0;
  for(size_t i = 0; i < v.size(); i++){
    int prod = v[i] * multiply_num + carry;
    v[i] = prod % 10;
    carry = prod / 10;
  }

  while (carry)
  {
      int current_carry = carry % 10;
      v.push_back(current_carry);
      carry = carry / 10;
  }
}

std::string factorial(int num){
  std::vector<int> factorial_digits;
  factorial_digits.push_back(1);
  for(int i = 2; i <= num; i++){
    multiply_vector(factorial_digits, i);
  }

  std::stringstream ss;
  for(int i = factorial_digits.size()-1; i >= 0; i--){
    ss << factorial_digits[i];
  }
  return ss.str();
}

int main(){
    std::cout << factorial(1000) << '\n';
    return 0;
}