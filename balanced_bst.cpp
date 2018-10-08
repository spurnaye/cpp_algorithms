#include <memory>
#include <iostream>
#include <vector>

template<typename T>struct Tree; // Need to define the tree ptr;

// define Node structure with 3 pointers.
// first points to tree it belongs and left & right pointerss.
template<typename T>
struct Node{
  T _value;
  std::shared_ptr<Tree<T>> tree_ptr;
  std::shared_ptr<Node<T>> left;
  std::shared_ptr<Node<T>> right;

  Node(T value):_value(value){};

  static std::shared_ptr<Node<T>> make_node(T val){
    return std::make_shared<Node<int>>(val);
  }
};

// Tree structure
template<typename T>
struct Tree{
  std::shared_ptr<Node<T>> root_node;

  void print_in_order(std::shared_ptr<Node<T>> node){
    if(node == nullptr){
      return;
    }

    print_in_order(node->left);
    std::cout << node->_value << ' ';
    print_in_order(node->right);
  }

  void print_pre_order(std::shared_ptr<Node<T>> node){
   if(node == nullptr){
      return;
    }

    std::cout << node->_value << ' ';
    print_pre_order(node->left);
    print_pre_order(node->right); 
  }

  void print_post_order(std::shared_ptr<Node<T>> node){
   if(node == nullptr){
      return;
    }

    print_post_order(node->left);
    print_post_order(node->right); 
    std::cout << node->_value << ' ';
  }
};

template<typename T>
std::shared_ptr<Node<T>> 
create_balanced_bst(typename std::vector<T>::iterator start,
                      typename std::vector<T>::iterator finish){

  std::shared_ptr<Tree<T>> t_ptr = std::make_shared<Tree<T>>();
  if(start < finish){
    typename std::vector<T>::iterator mid = start;
    std::advance(mid, std::distance(start,finish)/2);
    t_ptr->root_node = Node<T>::make_node(*mid);
    t_ptr->root_node->tree_ptr = t_ptr;
    t_ptr->root_node->left = create_balanced_bst<T>(start, mid);
    t_ptr->root_node->right = create_balanced_bst<T>(mid+1, finish);
  }
  return t_ptr->root_node;
}

void print_sizes(){
  std::cout << "size of node structure because of shared_ptrs\n";
  std::cout << sizeof(Node<int>) << '\n';
}


int main(){
  int x;
  Tree<decltype(x)> t;
  t.root_node = Node<decltype(x)>::make_node(10);
  t.root_node->left = Node<decltype(x)>::make_node(5);
  t.root_node->right = Node<decltype(x)>::make_node(15);

  t.root_node->left->left = Node<decltype(x)>::make_node(3);
  t.root_node->left->right = Node<decltype(x)>::make_node(7);

  t.root_node->right->left = Node<decltype(x)>::make_node(12);
  t.root_node->right->right = Node<decltype(x)>::make_node(17);

  std::cout << "Printing in order \n";
  t.print_in_order(t.root_node);
  std::cout << '\n';

  std::cout << "Printing pre order \n";
  t.print_pre_order(t.root_node);
  std::cout << '\n';


  std::cout << "Printing post order \n";
  t.print_post_order(t.root_node);
  std::cout << '\n';

  std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
  std::cout << "create balanced bst from sorted vector\n";
  std::shared_ptr<Node<int>> bst_root_node = create_balanced_bst<int>(v.begin(), v.end());
  std::shared_ptr<Tree<int>> tree = bst_root_node->tree_ptr;
  tree->print_in_order(tree->root_node);
  std::cout << '\n';

  print_sizes();
}