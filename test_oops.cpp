#include <iostream>
class B{
public:
  void f(){
    g();
  }

  virtual void g(){
    std::cout << "in B::g()\n";
  }
};

class A : public B{
public:
  void f(){
    g();
  }

  void g(){
    std::cout << "in A::g()\n";
  }
};



int main(){
  A a;
  a.f();
  a.g();

  A * a_ptr = new A();
  a_ptr->f();

  B * b_ptr = new A();
  b_ptr->f();

  B & bref = *b_ptr;
  bref.f();


  A * a_ptr1 = new B();
}