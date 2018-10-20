#include <iostream>

class A{
  int & _a;
public:
  A(int & a):_a{a}{};
  A(const A& rhs):_a{rhs._a}{};
  A& operator=(const A& rhs){
    _a = rhs._a;
    return *this;
  };
};

class B{
public:
  int * _b;
  B(int * b):_b{b}{};
};


class C{
public:
  const int _c;

  C(const int c):_c{c}{};
};

struct S{
  const int i = 10;
  S(const int _i):i{_i}{};

  int add(int x){
    return x+i;
  }
};

class P{
private:
  P() = default;
  int _a;
  friend class S1;
};

class S1{
public:
  static void fun(){
    P p;
    P p1 = p;
  }
};


int main(){
  int x = 1;
  A a(x);

  B b(&x);
  B b1 = b;

  std::cout << *b1._b << '\n' ;

  C c(10);

  S s(11);
  S s1 = s;
  std::cout << s1.i << '\n';

  auto fptr = &S::add;
  std::cout << (s.*fptr)(11) << '\n';

  //P p;
  S1::fun();
}