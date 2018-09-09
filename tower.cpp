#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        std::vector<std::string> v;
        for(int i = 0; i <= nFloors; i++){
          std::stringstream ss;
          ss << std::setw(nFloors)<< std::string(i, '*');
          v.emplace_back(ss.str());
          std::cout << ss.str() << '\n';
        }
        return v;
    }
};

int main(){
  Kata k;
  std::vector<std::string> v = k.towerBuilder(6);
}