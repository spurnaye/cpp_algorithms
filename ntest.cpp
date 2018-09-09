#include <iostream>

class PrintTest{
  public:
  PrintTest(){
    std::cout << "PrintTest is initialized..\n";
  }

  ~PrintTest(){
    std::cout << "PrintTest is destroyed..\n";
  }
};

static PrintTest printtestObject;

int main(){
std::cout << "main sttarted\n";
{
  PrintTest anotherprintObj;
}
  std::cout << "25 % 3 = " << 25 % 3 << '\n';

  std::cout << "25 / 3 = " << 25 / 3 << '\n';

  auto a = 25 | 3;
  std::cout << "25 | 3 = " << a << '\n';

  auto b = 25 & 3;
  std::cout << "25 & 3 = " << b << '\n';

  auto c = 25 && 3;
  std::cout << "25 && 3 = " << c << '\n';

  auto d = 25 || 3;
  std::cout << "25 || 3 = " << d << '\n';

  auto e = 25 ^ 3;
  std::cout << "25 ^ 3 = " << e << '\n';

  auto f = ~25;
  std::cout << "~25 = " << f << '\n';
  std::cout << "main endinglll\n";


  const int val1 = 100; //  cannot assign to variable 'val1' with const-qualified type 'const int'
  val1 = 101;


  const char *ptr1 = "abc";
  p
  return 0;
}


