#include <string>
#include <iostream>
#include <vector>
#include <bitset>

// int xor_2(int x, int y){
//   return ((x|y) & (~x | ~y ));
// }

// int my_xor(int x, int y){
//   int s = sizeof(int)*8 - 1;
//   bool a, b, c;
//   int result = 0;
//   std::cout << std::bitset<16>(x) << '\n';
//   for(int i = s; i >= 0; i--){
//     a = x & (1 << i);
//     b = y & (1 << i);
//     c = (a & b) ? 0 : (a|b);
//     result <<= 1;
//     result |= c;
//   }
//   return result;
// }

// int main(){
//   int x = 131;
//   int y = 172;

//   std::cout << (x ^ y) << '\n';
//   std::cout << my_xor(x, y) << '\n';
//   return 0;
// }

//------------------------------------------------------------------------

// struct Y{
//   int add(int x, int y){
//     return x+y;
//   }

//   float add(float x, float y){
//     return x+y;
//   }

//   char add(char x, char  y){
//     return x+y;
//   }
// };

// struct X{
//   template <typename T>
//   T add(T num1, T num2){
//     return num1 + num2;
//   }
// };

// int main(){
//   Y x;
//   int addition = x.add(5, 10);
//   std::cout << addition << '\n';

//   float f_addition = x.add(5.5, 10.1);
//   std::cout << f_addition << '\n';  

//   char c_addition = x.add('A', 'C');
//   std::cout << c_addition << '\n';  
// }
//------------------------------------------------------------------------

// class X{
//   int x;
// public:
//   X(int _x):x{_x}{};
//   operator int() const {return x;}
//   operator float() const {return x*1.0;}
//   void printx(){std::cout << x << '\n';}
// };

// int main(){
//   X x(20);
//   x.printx();
//   int i = x;
//   std::cout << i << '\n';
//   float f = x;
//   std::cout << f << '\n';
//   // x = {30, 20};
//   // x.getx();
// }
//------------------------------------------------------------------------
// int main(){
//   char * c[] = {"this", "is", "test","c++"};
//   int i[] = {1,2,3,4,5,6,7};
//   bool b[] = {true, false, true, false};
//   double d[] = {1.2, 3.4, 5.6, 7.8};

//   std::cout << sizeof(c) << '\n';
//   std::cout << sizeof(b) << '\n';
//   std::cout << sizeof(d) << '\n';
//   return 0;
// }
//------------------------------------------------------------------------

// class M{
// protected:
//   int m;
// public:
//   M():m{0}{
//     std::cout << "M constructor called..\n";
//   }

//   M(int x){
//     m = x;  
//     std::cout << "Mx constructor called..\n";
//   }
  
// };

// class Q: public M{
//   public:
//   Q(int x): M{10}{
//     std::cout << m << " Q constructor called..\n";

//   }
// };

// int main(){
//   //Q q(10);

//   int x = 27; // x is an int
//   const int cx = x; // cx is a const int
//   const int& rx = x;


//   x = 10;

//   std::cout << rx << '\n';
//   return 0;

// }

//------------------------------------------------------------------------

// class MyClass{
//   int i;
//   public:
//     MyClass():i{18}{};
//   friend std::ostream& operator << (std::ostream & o, MyClass & obj){
//     o << obj.i << '\n';
//     return
//   }
// };

// int main(){
//   MyClass m;
//   std::cout << m << '\n';
//   return 0;
// }


//------------------------------------------------------------------------

// class BaseClass{
// public:
//   virtual void vprint(){
//     std::cout << "in the BaseClass\n";
//   }
//   void print(){
//     std::cout << "in the BaseClass\n";
//   }
// };

// class SubClass: public BaseClass{
// public:
//   virtual void vprint(){
//     std::cout << "in the SubClass\n";
//   }
//   void print(){
//     std::cout << "in the SubClass\n";
//   }
// };

// void global_print(BaseClass & b){
//   b.print();
//   b.vprint();
// }

// int main(){
//   BaseClass * b = new SubClass();
//   b->print();
//   b->vprint();

//   global_print(*b);
// }


//------------------------------------------------------------------------

// class Class{
// public:
//   static int count;

//   virtual void print(){
//     std::cout << count << '\n';
//   }

//     virtual void vprint(){
//     std::cout << count << '\n';
//   }
// };

// int Class::count = 10;

// int main(){
//   Class c;
//   c.print();
//   std::cout << sizeof(c)<< '\n';
// }


//------------------------------------------------------------------------

// class X{
//   int i;
// public:
//   X(int i):i(i){}
//   void print(){
//     std::cout << i << '\n';
//   }
// };

// int main(){
//   X x = {20};
//   x.print();
//   return 0;
// }


//------------------------------------------------------------------------

class BaseClass{
public:
  void print(){
    std::cout << "in the BaseClass\n";
  }
};

class SubClass: public BaseClass{
public:
  void print(){
    BaseClass::print();
    std::cout << "in the SubClass\n";
  }
};

void global_print(BaseClass & b){
  b.print();
  b.vprint();
}

int main(){
  BaseClass * b = new SubClass();
}
