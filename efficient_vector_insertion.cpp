#include <vector>
#include <iostream>
#include <algorithm>

int main(){

  std::vector<int> v {1,2,3,4,5,6,7,8,9,0};

  v.push_back(10);
  for(const auto & i: v) std::cout << i << ' ';
  std::cout << '\n';
  std::rotate(v.begin()+5, v.begin()+10,v.end());

  for(const auto & i: v) std::cout << i << ' ';
  std::cout << '\n';
  return 0;
}

//TEuER$h&h9u74qch&EAyniX^Qe2Hwdx*