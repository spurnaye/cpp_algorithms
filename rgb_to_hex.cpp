#include <iostream>
#include <sstream>

class RGBToHex
{
  static std::string to_hex(int num){
    if(num == 0) 
      return "00";
    static std::string d = "0123456789ABCDEF";
    std::string res;
 
    while(num > 0)
    {
        res = d[num % 16] + res;
        num /= 16;
    }
    res = (res.size() == 1) ? "0" + res : res;
    return res;
  }

  public:
  static std::string rgb(int r, int g, int b){
   r = (r > 255 ? 255 : r < 0 ? 0 : r);
   g = (g > 255 ? 255 : g < 0 ? 0 : g);
   b = (b > 255 ? 255 : b < 0 ? 0 : b);
   std::stringstream ss;
   ss << to_hex(r) << to_hex(g) << to_hex(b);
   return ss.str();
  }
};


int main(){
 std::cout << RGBToHex::rgb(0,0,0) << std::endl;
 std::cout << RGBToHex::rgb(14, 12, 50) << std::endl;
}
