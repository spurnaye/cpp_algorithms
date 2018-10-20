#include <iostream>
#include <vector>
void print(int & x){
  std::cout << "in print(int & x) : x " << x << '\n';
}

void print(int && x){
  std::cout << "in print(int && x) : x " << x << '\n';
}

int main(){
  print(5);
  int x = 4;
  print(x);


  std::vector<int> v{1,2,3,4,5};
  auto v1 = v;
  v1[0] = 2;
  std::cout << *v.begin() << '\n';  
  std::cout << *v1.begin() << '\n';  
}

// lvalues appear on the left side of the expression
// You can take the reference of lvalue
// they have identity.

// R-values appear on the right side of the expression
// they do not have identity
// They can not be bound to a lvalue reference.
// rvalue references represents an object that has no identity and
// it is ready to give its ownership.

// std::move its expressing an intent to move.
// 
