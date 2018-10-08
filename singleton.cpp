#include <iostream>

class Singleton{
  int x;

  Singleton(){
    x = 123;
  }

public:
  static Singleton * getInstance(){
    static Singleton st;
    return &st;
  }

  void print(){
    std::cout << x << '\n';
  }
};

int main(){
  Singleton::getInstance()->print();
  Singleton::getInstance()->print();
  Singleton::getInstance()->print();
  Singleton::getInstance()->print();
  Singleton::getInstance()->print();
  
}