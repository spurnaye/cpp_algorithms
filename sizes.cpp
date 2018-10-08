#include <iostream>
#include <atomic>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <forward_list>
#include <memory>

class EmptyClass{};

class X{
  int a;
};

class Y{
  int a;
  double b;
};

class StaticMember{
  static int a;
};


class __attribute__((packed)) YPacked{
  int a;
  double b;
};

class __attribute__((packed)) LargeStruct {
  int a;
  double b;
  float c;
  char d;
  double l;
  double m;
  int n;
  int o;
  double p;
  double q;
  double t;
  double u;
  double v;
  double w;
  char  s;
  double x;
  float y;
  int z;
};

class VFunClass{
public:
  virtual void fun(){std::cout << "class with virtual function\n";};
};


class VDesttructorClass{
public:
  virtual ~VDesttructorClass(){
    std::cout << "in the virtual destructor\n";
  }
};

class Base{};

class Derieved: public Base{

};

class Derieved1: public Base{
};

class Derieved2: public Base{
};

class MostDerieved: public Derieved, public Derieved1, public Derieved2{

};

class VBase{};

class VDerieved: public virtual VBase{

};

class VDerieved1: public virtual VBase{
};


class VMostDerieved: public VDerieved, public VDerieved1{

};

struct Node1{
  char c;
  int x;
};

struct Node2{
  Node1 n;
  char y;
};

class StaticConst{
  static print() const {
    std::cout << "inside static const function \n";
  }
};


int main(){
  std::string s = "test string";
  std::cout << "sizeof(s) "<< sizeof(s) << '\n'; // 24
  std::cout << "s.size() " << s.size() << '\n';  // 11


  std::vector<int> v{1,2,3,4,5};
  std::cout << "sizeof(v) "<< sizeof(v) << '\n'; // 24
  std::cout << "v.size() " << v.size() << '\n';  // 5

  std::set<int> set{1,2,3,4,5};
  std::cout << "sizeof(set) "<< sizeof(set) << '\n'; // 24
  std::cout << "set.size() " << set.size() << '\n'; // 5

  std::queue<int> queue;
  for(int i = 0; i < 5; ++i) queue.push(i);
  std::cout << "sizeof(queue) "<< sizeof(queue) << '\n'; // 48
  std::cout << "queue.size() " << queue.size() << '\n'; // 5

  std::forward_list<int> fl;
  auto it = fl.before_begin();

  it = fl.emplace_after ( it, 100 );
  it = fl.emplace_after ( it, 200 );
  it = fl.emplace_after ( it, 300 );
  std::cout << "sizeof(fl) "<< sizeof(fl) << '\n'; // 8

  // Size of X is 4 because there is a single data member in the class/struct
  std::cout << "sizeof(X) "<< sizeof(X) << '\n'; // 4

  // Size of Y should be 12 i.e. addition of int (4) + double (8)= 12
  // but its size if 16 because the compiler aligns the class/struct
  // by multiples of its max member.
  std::cout << "sizeof(Y) "<< sizeof(Y) << '\n'; // 16

  std::cout << "sizeof(Node1) "<< sizeof(Node1) << '\n'; // 8
  // Even though Node2 has Node1 as data member, the memory for Node 2 
  // is allocated as addition of Node1 data members + Node2 data members.
  std::cout << "sizeof(Node2) "<< sizeof(Node2) << '\n'; // 12
  
  // Size of a packed structure = sum of sizes of member variables
  std::cout << "sizeof(YPacked) "<< sizeof(YPacked) << '\n'; // 12

  std::unique_ptr<int> uniq_ptr = std::make_unique<int>(10);
  std::cout << "sizeof(uniq_ptr) " << sizeof(uniq_ptr) << '\n'; // 8

  std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
  std::cout << "sizeof(sh_ptr) " << sizeof(sh_ptr) << '\n'; // 16

  std::weak_ptr<int> w_ptr = std::make_shared<int>(10);
  std::cout << "sizeof(w_ptr) " << sizeof(w_ptr) << '\n'; // 16

  std::cout << "sizeof(EmptyClass) "<< sizeof(EmptyClass) << '\n'; // 1 
  std::cout << "sizeof(VFunClass) " << sizeof(VFunClass) << '\n'; // 8
  std::cout << "sizeof(VDesttructorClass) " << sizeof(VDesttructorClass) << '\n'; // 8

  std::cout << "sizeof(MostDerieved) " << sizeof(MostDerieved) << '\n'; // 2
  std::cout << "sizeof(VMostDerieved) " << sizeof(VMostDerieved) << '\n'; // 2
  // Size of class with only static variable is 1 i.e.
  // it does not include size of static in the size of class.
  std::cout << "sizeof(StaticMember) " << sizeof(StaticMember) << '\n'; // 1

  std::atomic<int> i = 10;
  std::cout << "sizeof(std::atomic<int>) " << sizeof(i) << '\n'; // 4

  //size of packed atomic structure is 16
  std::atomic<double> d;
  std::cout << "sizeof(std::atomic<double>) " << sizeof(std::atomic<double>) << '\n'; // 16

  //size of packed atomic structure is 16
  std::atomic<YPacked> yp;
  std::cout << "sizeof(std::atomic<YPacked>) " << sizeof(std::atomic<YPacked>) << '\n'; // 16

  StaticConst::print();
}