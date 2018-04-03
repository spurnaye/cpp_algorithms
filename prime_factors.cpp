#include <map>
#include <sstream>
#include <iostream>


class PrimeDecomp
{
public:
    static std::string factors(int lst){
      std::map<int, int> prime_factors;
      int factor = 2;
      while (lst > 1){
        while (lst % factor == 0){
            ++prime_factors[factor];
          lst /= factor;
        }
        ++factor;
      }
    std::stringstream ss;
    for(auto & e : prime_factors){
      if (e.second == 1){
       ss << "(" << e.first << ")"; 
      }
      else
      {
        ss << "(" << e.first << "**" << e.second << ")";
      }
    }
    return ss.str();
    }
};



int main(){
  std::cout << PrimeDecomp::factors(7775460) << std::endl;
  return 0;
}