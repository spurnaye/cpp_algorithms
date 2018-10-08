#include <iostream>

class A{
  public:
  A(){
    std::cout << "A()" << '\n';
  }
};

class B{
  public:
  B(){
    std::cout << "B()" << '\n';
  }
};

class C: public A{
  B * ptr;
  public:
  C():ptr{new B()}{
    std::cout << "C()" << '\n';
  }
};

class D: public B{
  C * ptr;

  public:
  D():ptr{new C()}{
    std::cout << "D()" << '\n';
  }
};


int main(){
  D d;
   // printf("%x" ,-1<<4); Technically leftshifting negative value is a undefined behavior

  volatile const int x = 0;

  
  return 0;
}