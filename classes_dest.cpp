#include <iostream>
#include <atomic>
class X{
  int * a;

public:
  X(){
    a = new int(1);
  };
  virtual ~X(){
    std::cout << *a << '\n';
  }
};

int main(){
  X x;
}
