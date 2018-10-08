#include <type_traits>
#include <memory>
#include <iostream>

template<typename T, 
  typename std::enable_if_t<std::is_integral_v<T>,T>* = nullptr>
struct Node{
  std::shared_ptr<Node<T>> left;
  std::shared_ptr<Node<T>> right;
  std::shared_ptr<Node<T>> parent;
  T value;

  // default constructor
  Node(T value):value{value}{};
};

// somehow I would like to have the tree only operate on integral types like ints, float, double etc.
template<typename T, 
  typename std::enable_if_t<std::is_integral_v<T>,T>* = nullptr>
struct Tree{
  std::shared_ptr<Node<T>> root_node;

  // since copy constructor is defined.
  Tree() = default;
  // Making tree move constructable only
  Tree(Tree &&tree) = default; 
  Tree& operator=(Tree &&tree) = default; 
  // deleting copy constructor and copy assignment op.
  Tree(const Tree &tree) = delete; 
  Tree& operator=(const Tree &tree) = delete;

  bool add_node(const T & value){
    auto current_node = root_node;
    bool node_in_place = false;
    while(!node_in_place){
      if(current_node->value == value){
        std::cout << "duplicate values \n";
        break;
      }else if (current_node->value > value){
        auto unplaced_left = std::make_shared<Node<T>>(value);
        if(current_node->left == nullptr){
          current_node->left = unplaced_left;
          unplaced_left->parent = current_node;
          node_in_place = true;
        }else if(current_node->left && (current_node->left->value < value)){
          auto current_left_node = current_node->left;
          current_node->left = unplaced_left;
          unplaced_left->parent = current_node;

          unplaced_left->left = current_left_node;
          current_left_node->parent = unplaced_left;

          node_in_place = true;
        }else if(current_node->left && (current_node->left->value > value)){
          current_node = current_node->left;
        }else{
          std::cout << "duplicate value for " << value << '\n';
          break;
        }
      }else if(current_node->value < value){
        auto unplaced_right = std::make_shared<Node<T>>(value);
        if(current_node->right == nullptr){
          current_node->right = unplaced_right;
          unplaced_right->parent = current_node;
          node_in_place = true;
        }else if(current_node->right && (current_node->right->value > value) ){
          auto current_right_node = current_node->right;
          current_node->right = unplaced_right;
          unplaced_right->parent = current_node;

          unplaced_right->right = current_right_node;
          current_right_node->parent = unplaced_right;
          node_in_place = true;
        } else if(current_node->right && (current_node->right->value < value)){
          current_node = current_node->right;
        }else{
          std::cout << "duplicate value for " << value << '\n';
          break;
        }
      }
    }
    return node_in_place;  
  }

  std::shared_ptr<Node<T>> left_most_node(){
    auto current_node = root_node;
    std::shared_ptr<Node<T>> left_node = current_node;
    while(current_node->left != nullptr){
      current_node = current_node->left;
      if(current_node->left != nullptr){
        left_node = current_node->left;  
      }else{
        left_node = current_node;
        break; 
      }
      
    }
    return left_node;
  }

  // left, parent, right
  void print_in_order(std::shared_ptr<Node<T>> current_node){
    if(current_node == nullptr){
      return;
    }
    print_in_order(current_node->left);
    std::cout << current_node->value << '\n';
    print_in_order(current_node->right);
  }

  // parent, left, right
  void print_pre_order(std::shared_ptr<Node<T>> current_node){
    if(current_node == nullptr){
      return;
    }
    std::cout << current_node->value << '\n';
    print_in_order(current_node->left);
    print_in_order(current_node->right);
  }
};

int main(){
  Tree<int> tree; 

  tree.root_node = std::make_shared<Node<int>>(10);
  for(int i = 10, j = 10; i > 0 && j < 20; --i, ++j){
    tree.add_node(i);
    tree.add_node(j);
  }

  std::cout << "in order printing \n";
  tree.print_in_order(tree.root_node);
  std::cout << "pre order printing \n";
  tree.print_pre_order(tree.root_node);
  std::cout << '\n';

  auto left_most = tree.left_most_node();
  std::cout << left_most->parent->value << '\n';
  std::cout << left_most->parent->parent->value << '\n';
}