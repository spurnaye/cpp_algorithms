#include <stack>
#include <vector>
#include <iostream>

using it = std::vector<int>::iterator;

void next_greater(it start, it finish){
  std::stack<int> s;
  for(;start < finish; ++start){
    if(s.empty() || s.top() > *start){
      s.push(*start);
    }else{
      while(!s.empty() && s.top() < *start){
        std::cout << "Next Greater Element of "<< s.top() << " is " << *start << '\n';
        s.pop();
      }
      s.push(*start);
    }
  }
  std::cout << '\n';
}

int main(){
  std::vector<int> v{98, 27, 54, 10, 67, 11, 1, 89, 99, 28, 69, 80,76, 14};
  for(const auto & i:v) std::cout << i << ' ';
    std::cout << '\n';
  next_greater(v.begin(), v.end());
}