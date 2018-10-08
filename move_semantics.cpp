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