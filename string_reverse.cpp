#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
void reverse_rotate(T first, T last){
 if((first == last) || std::next(first) == last) return;
 T middle = first;
 std::advance(middle, std::distance(first, last)/2);
 reverse_rotate(first, middle);
 reverse_rotate(middle, last);
 std::rotate(first, middle, last);
}

int main(){
 std::vector<int> v ={1,2,3,4,5,6,7,8,9,10};
 reverse_rotate(v.begin(), v.end());
 for(const auto & el:v) std::cout << el << ' ';
std::cout << '\n';
  std::string s = "Geeks for Geeks";
  reverse_rotate(s.begin(), s.end());
  std::cout << s << '\n';

}