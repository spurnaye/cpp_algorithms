#include <iostream>

template <typename T>
struct Node{
  T value;
  std::shared_ptr<Node<T>> next;

  Node(T val):value(val){};
};

template <typename T>
struct List{
  std::shared_ptr<Node<T>> root_node;

  void print(){
    
  }
};

int main(){
  List<int> l;
  l.root_node = std::make_shared<Node<int>>(10);

  std::shared_ptr<Node<int>> current_ptr = l.root_node;
  for(int i = l.root_node->value; i <= 20; ++i){
    current_ptr->next = std::make_shared<Node<int>>(i+1);
    current_ptr = current_ptr->next;
  }
}