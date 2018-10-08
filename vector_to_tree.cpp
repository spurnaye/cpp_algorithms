#include <iostream>
#include <vector>
#include <memory>

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

  // left, parent, right
  void print_in_order(std::shared_ptr<Node<T>> current_node){
    if(current_node == nullptr){
      return;
    }
    print_in_order(current_node->left);
    std::cout << current_node->value << '\n';
    print_in_order(current_node->right);
  }

  std::shared_ptr<Node<T>> build_tree(std::vector<T> &v, int start_idx, int end_idx){
    if(start_idx > end_idx) return nullptr;
    
    int mid_idx = (start_idx+end_idx)/2;
    std::shared_ptr<Node<T>> mid_node = std::make_shared<Node<T>>(v[mid_idx]);

    if(root_node == nullptr){
      root_node = mid_node;
    }
    
    mid_node->left = build_tree(v, start_idx, mid_idx-1);
    mid_node->right = build_tree(v, mid_idx+1, end_idx);
    return mid_node;
  }
};


int main(){
  Tree<int> tree;
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  tree.build_tree(v, 0, v.size()-1);

  tree.print_in_order(tree.root_node);
}

