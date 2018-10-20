#include <iostream>

// class A{
// public:
//   A(){
//     std::cout << "A constructor\n";
//   }
// };

// class B: public A{
//   public:
//   B(){
//     std::cout << "B constructor\n";
//   }

//   class C{
//   public:
//     C(){
//       std::cout << "C constructor\n";
//     }
//   };

//   C   c;
// };

class Base{
public:
  Base(int a, float b){
    std::cout << "in Base a: " << a << " b: " << b << '\n'; 
  }

  Base(const Base& rhs){
    if(this == &rhs){
      return;
    }
    a = rhs.a;
    b = rhs.b;
  }
    Base(Base&& rhs){

      std::cout << "move constructor is called\n";
    if(this == &rhs){
      return;
    }
    a = std::move(rhs.a);
    b = std::move(rhs.b);
  }

  Base & operator=(const Base& rhs){
    if(this == &rhs){
      return *this;
    }
    a = rhs.a;
    b = rhs.b;
    return *this;
  }

   Base & operator=(Base&& rhs){
    std::cout << "Move operator is called...\n";
    if(this == &rhs){
      return *this;
    }
    a = std::move(rhs.a);
    b = std::move(rhs.b);
    return *this;
  }

  int a = 0;
  float b = 0.0;
};

int main(){
  Base b(1,2);
  Base b1(b);
  Base b2(b);
  b2 = std::move(b);

  Base b3 = std::move(b2);

  Base b4 = b3;
}

// if a parameterized constructor is defined, copy constructor, move constructor,
//copy assignment and move assignment operators are provided by compiler...

// if a copy constructor is provided no default constructor is generated. 
// But the move constructor, copy assignment and move assignment operators are provided by compiler...

// same for copy assignment op is provided constructor is generated.

// Move constructor:
// if defined, copy constructor is deleted but copy assignment operator and 
// move assignment operator are provided.



