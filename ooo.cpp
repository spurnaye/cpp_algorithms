#include <iostream>

class X{
  public:
    virtual void print(){
      std::cout << "in the print function of X\n";
    }
};

class Y: public X{
  public:
    void print(){
      std::cout << "in the print function of Y\n";
    }

    void printy(){
      std::cout << "in the printy function of Y\n";
    }
};


int main(){
  X * x =  new Y();
  x->print();
  x->printy();
}