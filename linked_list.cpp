#include <iostream>
#include <memory>

template <typename T>
struct Node{
  T value;
  bool head = false;
  std::shared_ptr<Node<T>> next;

  Node(): head(true), value(-1){};
  Node(T value): head(false), value(value){};

  std::shared_ptr<Node<T>> add_next(T value){
    next = std::make_shared<Node<T>>(value);
    return next;
  }
};

template<typename T>
struct List{
  std::shared_ptr<Node<T>> head;
  std::shared_ptr<Node<T>> tail;

  List(){
    head = std::make_shared<Node<T>>();
    tail = head;
  }

  void add_node(T value){
    tail->add_next(value);
    tail = tail->next; 
  }

  void print(){
    std::cout << std::string(100, '-') << '\n';
    auto current = head;
    while(current != nullptr){
      std::cout << current->value << '\t';
      current = current->next;
    }
    std::cout  << '\n' << std::string(100, '-') << '\n';
  }

  void reverse(){
    auto current = head;
    std::shared_ptr<Node<T>> next, prev;
    while(current != nullptr){
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
  }

  void insert_after(T after_value, T value){
    auto current = head;
    while(current != nullptr){
      if(current->value == after_value){
        auto temp_next = current->next;
        auto node = create_node(value);
        current->next = node;
        node->next = temp_next;
        break;
      }
      current = current->next;
    }
  }

  void insert_before(T before_value, T value){
    auto current = head;
    std::shared_ptr<Node<T>> prev;
    while(current != nullptr){
      if(current->value == before_value){
        auto node = create_node(value);
        node->next = current;
        prev->next = node;
      }
      prev = current;
      current = current->next;
    }
  }

  std::shared_ptr<Node<T>> create_node(T value){
    return std::make_shared<Node<T>>(value); 
  }
};

int main(){
  
  List<int> l;

  for(int i = 1; i <= 10; i++){
    l.add_node(i);
  }
  l.print();
  l.reverse();
  l.print();
  l.reverse();
  l.insert_after(1, 2);
  l.print();  
  l.insert_before(8, 18);
  l.print();  
  return 0;
}