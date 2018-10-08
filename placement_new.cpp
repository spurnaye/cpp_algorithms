#include <iostream>

struct Node{
  std::string name;
  std::string symbol;
  int value;
};

int main(){
  Node n;
  std::string s = "test string";
  std::cout << sizeof(s) << '\n';
  std::cout << s.size() << '\n';
  // Node * nodes = (Node *)malloc(sizeof(Node)*100);
  // std::cout << sizeof(nodes) << '\n';
}