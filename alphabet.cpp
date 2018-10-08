#include <iostream>

class X{
  int y;
public:
  X(){std::cout << "in the X constructor\n";}
  X(int a):y{a}{std::cout << "in the X param constructor\n";}
};

class Y: public X{
  int x;
  public:
  Y(){std::cout << "in the Y constructor\n";}
  virtual int vx(){std::cout << "this is method x\n"; return x;}
  Y(int b): x{b}{std::cout << "in the Y params constructor\n";}
};


int main(){
    Y y(10);
  std::cout << sizeof(Y) << std::endl;
  return 0; 
}
