#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::string multiply(std::string a, std::string b) {
  std::vector<int> multiplication(200, 0);

  int place = 0;
  for(int i = a.size() - 1 ; i >= 0; i--){
    int carry = 0;
    std::vector<int>::iterator it = multiplication.begin() + place;
    for(int j = b.size() - 1 ; j >= 0; j--){
      int a_element = a[i] - '0';
      int b_element = b[j] - '0';
      int prod = a_element*b_element + carry + *it;
      *it = prod % 10;
      carry = prod / 10;
      it++;
      while (carry){
        int current_carry = carry + *it;
        *it += current_carry % 10;
        it++;
        carry = current_carry / 10;
      }
      std::cout << carry << '\n';
    }
    place++;
  }

  std::stringstream ss;

  for(int i = multiplication.size(); i >= 0; i--){
    ss << multiplication[i];
  }
    std::cout << ss.str() << '\n';
  return "";
}

//252 201 579 132 747 748

int main(){
  std::string a = "991";
  std::string b = "28";
  8 4 7
  std::string ans = "81129638414606663681390495662081";
  multiply(a, b);
  return 0;
}